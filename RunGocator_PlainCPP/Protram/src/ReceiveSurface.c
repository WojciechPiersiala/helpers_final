/*
 * ReceiveSurface.c
 * 
 * Gocator 2000 Sample
 * Copyright (C) 2011-2020 by LMI Technologies Inc.
 * 
 * Licensed under The MIT License.
 * Redistributions of files must retain the above copyright notice.
 *
 * Purpose: Connect to Gocator my_system and receive Surface data and translate to engineering units. Gocator must be in Surface Mmode.
 * Ethernet output for the whole part and/or intensity data must be enabled.
 *
 */
#include <GoSdk/GoSdk.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/wait.h>

#define RECEIVE_TIMEOUT 20000000
#define INVALID_RANGE_16BIT     ((signed short)0x8000)          // gocator transmits range data as 16-bit signed integers. 0x8000 signifies invalid range data. 
#define DOUBLE_MAX              ((k64f)1.7976931348623157e+308) // 64-bit double - largest positive value.  
#define INVALID_RANGE_DOUBLE    ((k64f)-DOUBLE_MAX)             // floating point value to represent invalid range data.
#define SENSOR_IP               "192.168.1.10"  

#define NM_TO_MM(VALUE) (((k64f)(VALUE))/1000000.0)
#define UM_TO_MM(VALUE) (((k64f)(VALUE))/1000.0)


void log_point(const char *filename, float x, float y, float z, float color) {
    FILE *fp;
    fp = fopen(filename, "a");
    if(fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    fprintf(fp, "%.2f %.2f %.2f %.2f\n", x, y, z, color);
    fclose(fp);
}


typedef struct ProfilePoint 
{
    double x;   // x-coordinate in engineering units (mm) - position along laser line
    double y;   // y-coordinate in engineering units (mm) - position along the direction of travel
    double z;   // z-coordinate in engineering units (mm) - height (at the given x position)
    unsigned char intensity;
} ProfilePoint;

void main(int argc, char **argv)
{   
    if(argc !=4){
        printf("\n\nUse 3 arguments <number of tests[N]>, <display [0/1]> <samples gropu[N]> \n\n");
        return -1;
    }
    int RUNS = atoi(argv[1]);
    int DISPLAY = atoi(argv[2]);
    int GROUP = atoi(argv[3]);

    int validCount = 0;
    kAssembly api = kNULL;
    kStatus status;
    GoSystem my_system = kNULL;
    GoSensor sensor = kNULL;
    GoDataSet dataset = kNULL;
    unsigned int i, j;
    kIpAddress ipAddress;   

    // construct Gocator API Library
    if ((status = GoSdk_Construct(&api)) != kOK)
    {
        printf("Error: GoSdk_Construct:%d\n", status);
        return;
    }

    // construct GoSystem object
    if ((status = GoSystem_Construct(&my_system, kNULL)) != kOK)
    {
        printf("Error: GoSystem_Construct:%d\n", status);
        return;
    }
    
    // Parse IP address into address data structure
    kIpAddress_Parse(&ipAddress, SENSOR_IP);

    // obtain GoSensor object by sensor IP address
    if ((status = GoSystem_FindSensorByIpAddress(my_system, &ipAddress, &sensor)) != kOK)
    {           
        printf("Error: GoSystem_FindSensor:%d\n", status);
        return;
    }

    // create connection to GoSensor object
    if ((status = GoSensor_Connect(sensor)) != kOK)
    {
        printf("Error: GoSensor_Connect:%d\n", status);
        return;
    }

    // enable sensor data channel
    if ((status = GoSystem_EnableData(my_system, kTRUE)) != kOK)
    {
        printf("Error: GoSensor_EnableData:%d\n", status);
        return;
    }   

    // start Gocator sensor
const char* base_filename="clouds/cloud_st";
const char* extension_filename=".xyz";
char filename[100];
// const char* extension_filename=".xyz";
for(int ITERATOR = 0; ITERATOR<RUNS; ITERATOR++){
    if ((status = GoSystem_Start(my_system)) != kOK)
    {
        printf("Error: GoSystem_Start:%d\n", status);
        return;
    }

    printf("Waiting for Whole Part data...\n\n");
    
    if (GoSystem_ReceiveData(my_system, &dataset, RECEIVE_TIMEOUT) == kOK)
    {           
        short int* height_map_memory = NULL;
        unsigned char* intensity_image_memory = NULL;
        ProfilePoint **surfaceBuffer = NULL;
        k32u surfaceBufferHeight = 0;
        
        printf("Dataset count: %u\n", (k32u)GoDataSet_Count(dataset));

        // each result can have multiple data items
        // loop through all items in result message
        for (i = 0; i < GoDataSet_Count(dataset); ++i)
        {           
            GoDataMsg dataObj = GoDataSet_At(dataset, i);
            if(GoDataMsg_Type(dataObj) == GO_DATA_MESSAGE_TYPE_UNIFORM_SURFACE){   
                FILE *fp;
                
                sprintf(filename,"%s%d%d%s",base_filename,GROUP,ITERATOR,extension_filename);
                fp = fopen(filename, "w");
                if(fp == NULL) {
                    printf("Failed to create file.\n");
                }

                printf("currnet iterator before printing: %d", ITERATOR);
                printf("filename: %s", filename);
                GoSurfaceMsg surfaceMsg = dataObj;      
                unsigned int rowIdx, colIdx;

                double XResolution = NM_TO_MM(GoSurfaceMsg_XResolution(surfaceMsg));
                double YResolution = NM_TO_MM(GoSurfaceMsg_YResolution(surfaceMsg));
                double ZResolution = NM_TO_MM(GoSurfaceMsg_ZResolution(surfaceMsg));
                double XOffset = UM_TO_MM(GoSurfaceMsg_XOffset(surfaceMsg));
                double YOffset = UM_TO_MM(GoSurfaceMsg_YOffset(surfaceMsg));
                double ZOffset = UM_TO_MM(GoSurfaceMsg_ZOffset(surfaceMsg));                    

                printf("  Surface data width: %lu\n", (k32u)GoSurfaceMsg_Width(surfaceMsg));
                printf("  Surface data length: %lu\n", (k32u)GoSurfaceMsg_Length(surfaceMsg));

                //allocate memory if needed
                if (surfaceBuffer == NULL)
                {   
                    surfaceBuffer = malloc(GoSurfaceMsg_Length(surfaceMsg) * sizeof(ProfilePoint *));

                    for (j=0; j < GoSurfaceMsg_Length(surfaceMsg); j++)
                    {
                        surfaceBuffer[j] = malloc(GoSurfaceMsg_Width(surfaceMsg) * sizeof(ProfilePoint));
                    }

                    surfaceBufferHeight = (k32u)GoSurfaceMsg_Length(surfaceMsg);
                }

                for (rowIdx=0; rowIdx < GoSurfaceMsg_Length(surfaceMsg); rowIdx++)
                {
                    k16s *data = GoSurfaceMsg_RowAt(surfaceMsg, rowIdx);
                    


                    for (colIdx=0; colIdx < GoSurfaceMsg_Width(surfaceMsg); colIdx++)
                    {
                        surfaceBuffer[rowIdx][colIdx].x = XOffset + XResolution * colIdx;
                        surfaceBuffer[rowIdx][colIdx].y = YOffset + YResolution * rowIdx;
                            

                        if (data[colIdx] != INVALID_RANGE_16BIT){
                            surfaceBuffer[rowIdx][colIdx].z = ZOffset + ZResolution * data[colIdx];
                            double x = surfaceBuffer[rowIdx][colIdx].x;
                            double y = surfaceBuffer[rowIdx][colIdx].y;
                            double z = surfaceBuffer[rowIdx][colIdx].z;
                            float color = 0;
                            validCount++;
                            log_point(filename, x, y, z, color);
                            
                        }
                    }
                }    
            }          
        }

        GoDestroy(dataset);
        //free memory arrays
        if (surfaceBuffer) 
        {
            unsigned int i;
            for (i=0; i < surfaceBufferHeight; i++)
            {
                free(surfaceBuffer[i]);
            }
        }
    }
    else
    {
        printf ("Error: No data received during the waiting period\n");
    }

    // stop Gocator sensor
    if ((status = GoSystem_Stop(my_system)) != kOK)
    {
        printf("Error: GoSystem_Stop:%d\n", status);
        return;
    }
    char my_command[100];
    sprintf(my_command,"%s%s","python3 view.py ",filename);

    printf("\n command : %s \n",my_command);

    if(DISPLAY){
        int outRes = system(my_command);
    }

    printf("\nloop: %d \n",ITERATOR);
}
    // destroy handles  
    GoDestroy(my_system);
    GoDestroy(api);
    printf("%i \n",validCount);
    // int outRes = system("python3 view.py");
    // printf("Press any key to continue...\n");
    // getchar();

    return;
}
