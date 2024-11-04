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
    def read_int_array():
        return list(map(int, input().strip().split()))

    @staticmethod
    def read_long_array():
        return list(map(int, input().strip().split()))

    @staticmethod
    def read_string_array():
        return input().strip().split()

    @staticmethod
    def write_array(array, separator=' ', end='\n'):
        print(separator.join(map(str, array)), end=end)

    @staticmethod
    def write_int(number, end='\n'):
        print(number, end=end)

    @staticmethod
    def write_long(number, end='\n'):
        print(number, end=end)

    @staticmethod
    def write_string(word, end='\n'):
        print(word, end=end)

    @staticmethod
    def write_boolean(value, end='\n'):
        print(str(value).lower(), end=end)

    @staticmethod
    def write_char(word, end='\n'):
        print(word, end=end)


class Main:
    @staticmethod
    def main():
        i1 = IO.read_int()
        count_value = {}
        for i2 in range(i1):
            count_value.clear()
            quantity = IO.read_int_array()
            base = IO.read_int_array()
            for i in range(quantity[2]):
                count_value[base[i]] = count_value.get(base[i], 0) + 1
            min_val = len(count_value)
            for i in range(quantity[2], quantity[0]):
                count_value[base[i - quantity[2]]] -= 1
                if count_value[base[i - quantity[2]]] == 0:
                    del count_value[base[i - quantity[2]]]
                count_value[base[i]] = count_value.get(base[i], 0) + 1
                min_val = min(min_val, len(count_value))
            IO.write_int(min_val)


if __name__ == '__main__':
    Main.main()
