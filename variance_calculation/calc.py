import numpy as np

# Read file
with open('points.txt', 'r') as f:
    lines = f.readlines()

# Parse coordinates
coordinates = []
for line in lines:
    x, y, z = line.strip().split()
    coordinates.append([float(x), float(y), float(z)])

# Convert to numpy array
coordinates = np.array(coordinates)

# Calculate deltaZ distances
deltaZ = np.abs(np.diff(coordinates[:,2]))

# Calculate deltaXY distancessdsd
deltaXY = []
for i in range(coordinates.shape[0]-1):
    dx = coordinates[i+1,0] - coordinates[i,0]
    dy = coordinates[i+1,1] - coordinates[i,1]
    deltaXY.append(np.sqrt(dx*dx + dy*dy))

deltaXY = np.array(deltaXY)

# Calculate mean, variance, and range
mean_deltaZ = np.mean(deltaZ)
variance_deltaZ = np.var(deltaZ)
range_deltaZ = np.max(deltaZ) - np.min(deltaZ)

mean_deltaXY = np.mean(deltaXY)
variance_deltaXY = np.var(deltaXY)
range_deltaXY = np.max(deltaXY) - np.min(deltaXY)

# Format output
np.set_printoptions(precision=6, suppress=True)

# Print results
print("DeltaZ distances - Mean:", mean_deltaZ, "Variance:", variance_deltaZ, "Range:", range_deltaZ)
print("DeltaXY distances - Mean:", mean_deltaXY, "Variance:", variance_deltaXY, "Range:", range_deltaXY)
