import sys
import math
from collections import defaultdict

pi = 2 * math.acos(0.0)

id1 = 0
test_case = 1

main_array = []
dp_table = []

def function_name():
    global main_array, dp_table
    array_number, operation_number = map(int, sys.stdin.readline().split())
    
    id3 = [[0] * array_number for _ in range(operation_number)]
    main_array = [[0] * operation_number for _ in range(array_number)]
    
    maximum = 0
    dp_table = [[maximum] * (operation_number + 1) for _ in range(array_number)]

    for i in range(array_number):
        element_number = int(sys.stdin.readline().strip())
        for j in range(element_number):
            element = int(sys.stdin.readline().strip())
            if j < operation_number:
                main_array[i][j] = element + (j > 0) * main_array[i][j - 1]
                id3[j][i] = main_array[i][j]

    for i in range(operation_number):
        id3[i].sort(reverse=True)

    for i in range(array_number):
        for j in range(operation_number):
            if main_array[i][j] < id3[j][min(operation_number // (j + 1), array_number - 1)]:
                main_array[i][j] = 0

    for id0 in range(array_number):
        if id0 > 0:
            dp_table[id0] = dp_table[id0 - 1][:]

        for id2 in range(operation_number):
            if main_array[id0][id2] != 0:
                for operation_left in range(operation_number, id2, -1):
                    old = operation_number - (id2 + 1)
                    if id0 == 0:
                        dp_table[id0][operation_left] = max(dp_table[id0][operation_left], main_array[id0][id2])
                    else:
                        dp_table[id0][operation_left] = max(dp_table[id0][operation_left], main_array[id0][id2] + dp_table[id0 - 1][old])

    answer = dp_table[array_number - 1][operation_number]
    print(answer)

def function_name_v1(v1, v2, v3):
    pass

def function_name_line(line):
    pass

class InitialWorks:
    def with_test_case_number(self):
        global id1, test_case
        id1 = int(sys.stdin.readline().strip())

        while test_case <= id1:
            function_name()
            test_case += 1

    def single_iteration(self):
        function_name()

    def without_test_case_number(self):
        global test_case
        while True:
            line = sys.stdin.readline().strip()
            if not line:
                break
            v1, v2, v3 = map(int, line.split())
            if v1 == 0:
                break
            function_name_v1(v1, v2, v3)
            test_case += 1

    def eoof(self):
        global test_case
        while True:
            try:
                line = input()
                function_name_line(line)
                test_case += 1
            except EOFError:
                break

if __name__ == "__main__":
    initial_works = InitialWorks()
    initial_works.single_iteration()
