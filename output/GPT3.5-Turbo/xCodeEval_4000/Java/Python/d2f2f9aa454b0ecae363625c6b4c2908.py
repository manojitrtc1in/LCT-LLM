import sys

class IO:
    @staticmethod
    def read_int():
        return int(input().strip())

    @staticmethod
    def read_long():
        return int(input().strip())

    @staticmethod
    def read_string():
        return input().strip()

    @staticmethod
    def read_array_int():
        return list(map(int, input().strip().split()))

    @staticmethod
    def read_array_long():
        return list(map(int, input().strip().split()))

    @staticmethod
    def read_array_string():
        return input().strip().split()

    @staticmethod
    def write_array(array, end=" "):
        print(" ".join(map(str, array)), end=end)

    @staticmethod
    def write_int(number, end=" "):
        print(number, end=end)

    @staticmethod
    def write_long(number, end=" "):
        print(number, end=end)

    @staticmethod
    def write_string(word, end=" "):
        print(word, end=end)

    @staticmethod
    def write_boolean(value, end=" "):
        print(value, end=end)

    @staticmethod
    def write_char(word, end=" "):
        print(word, end=end)

    @staticmethod
    def write_enter():
        print()

    @staticmethod
    def print():
        sys.stdout.flush()

class Main:
    @staticmethod
    def main():
        i1 = IO.read_int()
        countValue = {}
        for i2 in range(i1):
            countValue.clear()
            quantity = IO.read_array_int()
            base = IO.read_array_int()
            for i in range(quantity[2]):
                countValue[base[i]] = countValue.get(base[i], 0) + 1
            min_val = len(countValue)
            for i in range(quantity[2], quantity[0]):
                countValue[base[i - quantity[2]]] -= 1
                if countValue[base[i - quantity[2]]] == 0:
                    del countValue[base[i - quantity[2]]]
                countValue[base[i]] = countValue.get(base[i], 0) + 1
                min_val = min(min_val, len(countValue))
            IO.write_int(min_val, "\n")
        IO.print()

if __name__ == "__main__":
    Main.main()
