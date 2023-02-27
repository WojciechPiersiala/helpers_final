import open3d as o3d
import sys
if len(sys.argv) < 2:
     print("give a cloud to be opened")
     sys.exit(1)

filename = sys.argv[1]
pcd = o3d.io.read_point_cloud(filename)

# Visualize point cloud
o3d.visualization.draw_geometries([pcd])