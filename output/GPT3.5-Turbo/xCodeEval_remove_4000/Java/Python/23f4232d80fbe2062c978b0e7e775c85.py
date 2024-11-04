import sys
from collections import defaultdict

class IO:
    @staticmethod
    def read_int():
        return int(input().strip())

    @staticmethod
    def read_int_list():
        return list(map(int, input().strip().split()))

    @staticmethod
    def read_int_matrix(rows):
        matrix = []
        for _ in range(rows):
            matrix.append(IO.read_int_list())
        return matrix

    @staticmethod
    def write_int(value):
        print(value)

class Main:
    @staticmethod
    def main():
        i1 = IO.read_int()
        for _ in range(i1):
            count_value = defaultdict(int)
            quantity = IO.read_int_list()
            base = IO.read_int_list()
            for i in range(quantity[2]):
                count_value[base[i]] += 1
            min_val = len(count_value)
            for i in range(quantity[2], quantity[0]):
                count_value[base[i - quantity[2]]] -= 1
                if count_value[base[i - quantity[2]]] == 0:
                    del count_value[base[i - quantity[2]]]
                count_value[base[i]] += 1
                min_val = min(min_val, len(count_value))
            IO.write_int(min_val)

if __name__ == '__main__':
    Main.main()
