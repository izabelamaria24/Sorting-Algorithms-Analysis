
import matplotlib.pyplot as plt
import re

def process_data():
    file = open("benchmarks.txt", "r")
    file_content = file.read()

    data = {}
    pattern = r'Results for ([\w\s\d<>]+), of size N=\d+:\n(.*?)(?=\n\nResults|$)'
    matches = re.findall(pattern, file_content, re.DOTALL)

    for match in matches:
        algorithm_name = match[0]
        results = match[1]

        int_execution_times = re.findall(r'(\w+ sort) on test_int_\d+: (\d+\.\d+) seconds', results)
        float_execution_times = re.findall(r'(\w+ sort) on test_float_\d+: (\d+\.\d+) seconds', results)

        for algorithm, time in int_execution_times:
            if algorithm not in data:
                data[algorithm] = {'int': [], 'float': []}
            data[algorithm]['int'].append(float(time))

        for algorithm, time in float_execution_times:
            if algorithm not in data:
                data[algorithm] = {'int': [], 'float': []}
            data[algorithm]['float'].append(float(time))

    return data


def draw(input_size, execution_times_1, execution_times_2, sort_label, label1, label2):
    plt.plot(input_size, execution_times_1, marker='o', label=label1, color='purple')
    plt.plot(input_size, execution_times_2, marker='o', label=label2, color='red')

    plt.title(f'{sort_label} Performance')
    plt.xlabel('Size of Array (N)')
    plt.ylabel('Execution Time (seconds)')
    plt.xscale('log')
    plt.yscale('log')
    plt.legend()
    plt.grid(True)
    plt.savefig(f'{sort_label}.png')
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
