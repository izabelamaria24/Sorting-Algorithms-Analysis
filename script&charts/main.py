
import matplotlib.pyplot as plt
import re

def process_data():
    file = open("benchmarks.txt", "r")
    file_content = file.read()

    # Define a dictionary to store the results
    results_dict = {}

    # Define regex pattern to extract data
    pattern = r'Results for ([\w\s\d<>]+), of size N=\d+:\n(.*?)(?=\n\nResults|$)'

    # Extracting results for each sorting algorithm
    matches = re.findall(pattern, file_content, re.DOTALL)

    # Loop through each match
    for match in matches:
        algorithm_name = match[0]
        results = match[1]

        # Extract execution times for each test type
        int_execution_times = re.findall(r'(\w+ sort) on test_int_\d+: (\d+\.\d+) seconds', results)
        float_execution_times = re.findall(r'(\w+ sort) on test_float_\d+: (\d+\.\d+) seconds', results)

        # Organize the results in the dictionary
        for algorithm, time in int_execution_times:
            if algorithm not in results_dict:
                results_dict[algorithm] = {'int': [], 'float': []}
            results_dict[algorithm]['int'].append(float(time))

        for algorithm, time in float_execution_times:
            if algorithm not in results_dict:
                results_dict[algorithm] = {'int': [], 'float': []}
            results_dict[algorithm]['float'].append(float(time))

    return results_dict


def draw(input_size, execution_times_1, execution_times_2, sort_label, label1, label2):
    # Plotting results for test_int_1
    plt.plot(input_size, execution_times_1, marker='o', label=label1, color='purple')

    # Plotting results for test_float_1
    plt.plot(input_size, execution_times_2, marker='o', label=label2, color='red')

    plt.title(f'{sort_label} Performance')
    plt.xlabel('Size of Array (N)')
    plt.ylabel('Execution Time (seconds)')
    plt.xscale('log')
    plt.yscale('log')
    plt.legend()
    plt.grid(True)
    plt.savefig(f'{sort_label}.png')  # Save as PNG format
    plt.show()


array_sizes = [10000, 100000, 1000000, 10000000, 100000000]
data = process_data()

for key in data:
    print(key)
    draw(array_sizes, data[key]["int"], data[key]["float"], key, 'INT', 'FLOAT')

draw(array_sizes, data['Radix10 sort']['int'], data['Radix2la16 sort']['int'], 'Radix base 10 vs Radix base 2^16 on INT', 'Radix10', 'Radix2^16')
draw(array_sizes, data['Radix10 sort']['float'], data['Radix2la16 sort']['float'], 'Radix base 10 vs Radix base 2^16 on FLOAT', 'Radix10', 'Radix2^16')

for key in data:
    if key != 'Native sort':
        draw(array_sizes, data['Native sort']['int'], data[key]['int'], f'Native sort vs {key} on INT', 'Native sort', key)
        draw(array_sizes, data['Native sort']['float'], data[key]['float'], f'Native sort vs {key} on FLOAT', 'Native sort', key)