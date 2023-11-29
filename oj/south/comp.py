def compare_files(file1_path, file2_path):
    with open(file1_path, 'r') as file1, open(file2_path, 'r') as file2:
        t = 0
        for line1, line2 in zip(file1, file2):
            array1 = line1.strip().split()[2:]
            array2 = line2.strip().split()[0:]
            t = t + 1
            if array1 != array2:
                print(t)
                return False

    return True

# Example usage
file1_path = 'input.txt'
file2_path = 'output.txt'

result = compare_files(file1_path, file2_path)
print(result)