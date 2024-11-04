import sys
import math
from collections import deque

def function_name():
    array_number, operation_number = map(int, sys.stdin.readline().split())
    
    reversed_array = [[0] * array_number for _ in range(operation_number)]
    main_array = [[0] * operation_number for _ in range(array_number)]
    
    maximum = 0
    dp_table = [[maximum] * (operation_number + 1) for _ in range(array_number)]

    for i in range(array_number):
        element_number = int(sys.stdin.readline().strip())
        for j in range(element_number):
            element = int(sys.stdin.readline().strip())
            if j < operation_number:
                main_array[i][j] = element + (main_array[i][j - 1] if j > 0 else 0)
                reversed_array[j][i] = main_array[i][j]

    for i in range(operation_number):
        reversed_array[i].sort(reverse=True)

    for i in range(array_number):
        for j in range(operation_number):
            if main_array[i][j] < reversed_array[j][min(operation_number // (j + 1), array_number - 1)]:
                main_array[i][j] = 0

    for current_array_no in range(array_number):
        if current_array_no > 0:
            dp_table[current_array_no] = dp_table[current_array_no - 1]

        for current_column_no in range(operation_number):
            if main_array[current_array_no][current_column_no] != 0:
                for operation_left, old in zip(range(operation_number, current_column_no, -1), range(operation_number - (current_column_no + 1), current_column_no, -1)):
                    if current_array_no == 0:
                        dp_table[current_array_no][operation_left] = max(dp_table[current_array_no][operation_left], main_array[current_array_no][current_column_no])
                    else:
                        dp_table[current_array_no][operation_left] = max(dp_table[current_array_no][operation_left], main_array[current_array_no][current_column_no] + dp_table[current_array_no - 1][old])

    answer = dp_table[array_number - 1][operation_number]
    print(answer)

class InitialWorks:
    def with_test_case_number(self):
        test_case_number = int(sys.stdin.readline().strip())
        for _ in range(test_case_number):
            function_name()

    def single_iteration(self):
        function_name()

    def without_test_case_number(self):
        while True:
            line = sys.stdin.readline().strip()
            if not line:
                break
            v1, v2, v3 = map(int, line.split())
            if v1 == 0:
                break
            function_name(v1, v2, v3)

    def eoof(self):
        while True:
            try:
                line = input()
                function_name(line)
            except EOFError:
                break

if __name__ == "__main__":
    initial_works = InitialWorks()
    initial_works.single_iteration()
