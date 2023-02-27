#include <GoSdk/GoSdk.h>
#include <stdio.h>

kStatus ExampleMain()
{
    const k32u sensorId = 000000;
    kAssembly api = kNULL;
    GoSystem system = kNULL;
    GoSensor sensor = kNULL;

    kCheck(GoSdk_Construct(&api));

    kCheck(GoSystem_Construct(&system, kNULL));

    kCheck(GoSystem_FindSensorById(system, sensorId, &sensor));

    kCheck(GoSensor_Connect(sensor));

    kCheck(kObject_Destroy(system));
    kCheck(kObject_Destroy(api));

    return kOK;
}

int main()
{
    int myVar = 2;
    myVar = kSuccess(ExampleMain()) ? 0 : -1;
    printf("%i", myVar);

    puts("\nPress <enter> to quit:");
    getchar();

    return myVar;
}
