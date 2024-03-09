import numpy as np
import time
import os

def sort_files(directory):
    for i in range(1, 11):
        file_name = os.path.join(directory, 'file' + str(i) + '.txt')
        with open(file_name, 'r') as f:
            numbers = [float(num) for num in f.read().split()]
            start_time = time.time()
            sorted_numbers = np.sort(numbers)
            end_time = time.time()
            print(f'Thời gian sắp xếp dãy số trong file {i} là {round((end_time - start_time)*1000)} milliseconds.')

            sorted_file_name = os.path.join(directory, 'sorted_file' + str(i) + '.txt')
            with open(sorted_file_name, 'w') as sorted_file:
                sorted_file.write(' '.join(map(repr, sorted_numbers)))

directory = r'C:\Users\ASUS\code'

sort_files(directory)
