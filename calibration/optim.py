import numpy as np
from scipy.spatial.transform import Rotation as R
from scipy.optimize import minimize
from scipy.optimize import least_squares
import open3d as o3d


Visual=True

def crop_cloud(pcd):
    num_points = len(pcd.points)
    pcd.points = o3d.utility.Vector3dVector(np.asarray(pcd.points)[10:, :])
    num_points = len(pcd.points)
    pcd.points = o3d.utility.Vector3dVector(np.asarray(pcd.points)[:num_points - 10, :])
    return pcd

def cost_function(C_transform,R_transformforms,point_clouds):
    R_N = R_transformforms
    p_N = point_clouds

    c_trn = C_transform[:3]
    c_qtr = R.from_quat(C_transform[3:])#qw,qx,qy,qz

    c_qtr_arr=c_qtr.as_quat()
    c_qtr_norm_arr=c_qtr_arr/np.linalg.norm(c_qtr_arr)

    c_qtr_norm = R.from_quat(c_qtr_norm_arr)
   
    
    C = np.eye(4)
    C[:3, :3] = c_qtr_norm.as_matrix()#qw,qx,qy,qz
    C[:3, 3] = c_trn

    transformed_points = []

    transformed_points_z = []
    
    iterator = 0
    for p_n in p_N:
        points = np.asarray(p_n.points)
        for p_i in points:
            tmp_R = R_N[iterator]
            tmp_C = C
            tmp_point = p_i

            tmp_point_hom= np.append(tmp_point, 1)
            tmp_point_result= np.dot(np.dot(tmp_R,tmp_C),tmp_point_hom )
            tmp_point_transform = tmp_point_result[:3] / tmp_point_result[3]

            transformed_points.append(tmp_point_transform)
        iterator += 1

    for p in transformed_points:
        transformed_points_z.append(p[2])


   
    var = np.var(transformed_points_z)
    
    # print(var)
    if Visual==True:
        print(var)
        transformed_points_arr = np.array(transformed_points)
        new_pcd = o3d.geometry.PointCloud()
        new_pcd.points = o3d.utility.Vector3dVector(transformed_points_arr)
        o3d.visualization.draw_geometries([new_pcd])
    return var




def main():
    file1 = open('dataset/transforms.txt', 'r')
    Lines = file1.readlines()
    count = 0 
    R_transformforms = []
    point_clouds = []
    for line in Lines:
        data = line.split(';')
        # print(data)
        tr_x = data[1]
        tr_y = data[2]
        tr_z = data[3]

        rot_x = data[4]
        rot_y = data[5]
        rot_z = data[6]
        rot_w = data[7]

        pcl_path = data[8].strip()
        point_cloud = o3d.io.read_point_cloud(pcl_path,format='pcd')
        # print(point_cloud)


        rotation = R.from_quat([rot_x, rot_y, rot_z,rot_w])
        translation = [tr_x, tr_y, tr_z]

        R_transform = np.eye(4)
        R_transform[:3, :3] = rotation.as_matrix()
        R_transform[:3, 3] = translation

        R_transformforms.append(R_transform)
        point_clouds.append(crop_cloud(point_cloud))
        

    C_qtr_=[1,0,0,0] 
    C_tr= [0,0,0] #
    C0=[0.1,0.1,0.1,0,0,0,1]#x,y,z,qw,qx,qy,qz
    C1=[0, 0, 0, 0.5, 0.5, 0.5, 0.5]
    # dev = cost_function(C0,R_transformforms,point_clouds)
    # print(dev)
    if Visual ==False:
        ### optimization
        bounds=((-0.2,0.2),(-0.2,0.2),(-0.2,0.2),(-1,1),(-1,1),(-1,1),(-1,1))
        
        print("Start optimization")
        res= minimize(cost_function,C0,args=(R_transformforms,point_clouds),bounds=bounds)
        if res.success:
            print("Optimization successful!")
            print("Solution: ", res.x)
        else:
            print("Optimization failed.")
    if Visual==True:
        o3d.visualization.draw_geometries(point_clouds)
        dev = cost_function(C0,R_transformforms,point_clouds)
        dev = cost_function(C1,R_transformforms,point_clouds)
        # C=[-0.05352679,  0.04084312, -0.04752148,  1.    ,      0.89695966 , 0.89048504,  0.99803872]
        # dev = cost_function(C,R_transformforms,point_clouds)
        
        C=[-0.05352679,  0.04084312, -0.04752148,  1.    ,      0.89695966 , 0.89048504,  0.99803872]
        C_norm= [-0.05352679,  0.04084312, -0.04752148,0.57735027, 0.51773227, 0.51347396, 0.57357154]
        dev = cost_function(C_norm,R_transformforms,point_clouds)

if __name__ == "__main__":
    main()
