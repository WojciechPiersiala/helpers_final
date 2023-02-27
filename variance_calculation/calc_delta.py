import numpy as np

# Read file
with open('points.txt', 'r') as f:
    lines = f.readlines()

# Parse numbers
numbers = []
for line in lines:
    numbers.append(float(line.strip()))

# Calculate mean and variance
mean = np.mean(numbers)
variance = np.var(numbers)

# Format output
np.set_printoptions(precision=6, suppress=True)

# Print results
print("Mean:", mean)
print("Variance:", variance)