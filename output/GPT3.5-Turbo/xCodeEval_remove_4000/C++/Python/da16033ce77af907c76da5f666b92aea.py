import math
from typing import List
from functools import cmp_to_key

pi = 2 * math.acos(0.0)

id1, test_case = 1, 1

main_array = []
dp_table = []

def function_name():
    global main_array, dp_table

    array_number, operation_number = map(int, input().split())

    id3 = [[0] * array_number for _ in range(operation_number)]
    main_array = [[0] * operation_number for _ in range(array_number)]

    maximum = 0
    dp_table = [[maximum] * (operation_number + 1) for _ in range(array_number)]

    for i in range(array_number):
        element_number = int(input())
        for j in range(element_number):
            element = int(input())
            if j < operation_number:
                main_array[i][j] = element + (main_array[i][j-1] if j > 0 else 0)
                id3[j][i] = main_array[i][j]

    for i in range(operation_number):
        id3[i].sort(reverse=True)

    for i in range(array_number):
        for j in range(operation_number):
            if main_array[i][j] < id3[j][min(operation_number // (j+1), array_number-1)]:
                main_array[i][j] = 0

    for id0 in range(array_number):
        if id0 > 0:
            dp_table[id0] = dp_table[id0-1][:]

        for id2 in range(operation_number):
            if main_array[id0][id2] != 0:
                for operation_left in range(operation_number, id2, -1):
                    old = operation_number - (id2 + 1)
                    if id0 == 0:
                        dp_table[id0][operation_left] = max(dp_table[id0][operation_left], main_array[id0][id2])
                    else:
                        dp_table[id0][operation_left] = max(dp_table[id0][operation_left], main_array[id0][id2] + dp_table[id0-1][old])

    answer = dp_table[array_number-1][operation_number]
    print(answer)

def function_name(v1: int, v2: int, v3: int):
    pass

def function_name(line: str):
    pass

class initial_works:
    def with_test_case_number(self):
        global id1, test_case

        id1 = int(input())

        while test_case <= id1:
            function_name()
            test_case += 1

    def single_iteration(self):
        function_name()

    def without_test_case_number(self):
        while True:
            v1, v2, v3 = map(int, input().split())
            if v1 == 0:
                break
            function_name(v1, v2, v3)
            test_case += 1

    def eoof(self):
        while True:
            try:
                line = input()
                function_name(line)
                test_case += 1
            except EOFError:
                break

if __name__ == "__main__":
    initial_works().single_iteration()
