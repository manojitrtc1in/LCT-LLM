import sys
from collections import defaultdict

class IO:
    @staticmethod
    def read_int():
        return int(sys.stdin.readline().strip())

    @staticmethod
    def read_int_list():
        return list(map(int, sys.stdin.readline().strip().split()))

    @staticmethod
    def read_string():
        return sys.stdin.readline().strip()

    @staticmethod
    def write(result):
        sys.stdout.write(str(result))
        sys.stdout.write('\n')
        sys.stdout.flush()

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
            IO.write(min_val)

if __name__ == '__main__':
    Main.main()
