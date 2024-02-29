input_file_path = "number8.out.txt"
output_file_path = "main.out"
import time
import numpy as np
# Read input data from the file

start_time = time.time()

with open(input_file_path, 'r') as infile:
    a = np.array(list(map(int, infile.readline().split(" "))))
# Read input data from the file

a.sort()

end_time = time.time()

executing_time = end_time - start_time

# Write output data to the file


with open(output_file_path, 'w') as outfile:
    outfile.write(str(executing_time))
# Write output data to the file