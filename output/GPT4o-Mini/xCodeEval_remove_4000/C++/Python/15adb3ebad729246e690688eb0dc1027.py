MOD = int(1e9) + 7

BUFFER_SIZE = 1 << 12
MAX_LENGTH = 1 << 7

class InputDevice:
    def __init__(self, head, tail):
        self.head = head
        self.tail = tail
        self.base = 10

    def fill_input(self):
        raise NotImplementedError

    def next_char(self):
        if self.head >= self.tail:
            self.fill_input()
        return self.head

    def read_char(self):
        if self.head >= self.tail:
            self.fill_input()
            if self.head >= self.tail:
                return '\0', 0
        char = self.head
        self.head += 1
        return char, 1

    def is_space(self, c):
        return c in ('\t', ' ', '\n', '\r')

    def skip_characters(self, is_skipped):
        c = self.next_char()
        while is_skipped(c):
            c = self.next_char()
        return c

class InputFile(InputDevice):
    def __init__(self, file):
        super().__init__(b'', b'')
        self.file = file
        self.line_buffered = True
        self.buffer = bytearray(BUFFER_SIZE)

    def fill_input(self):
        self.head = self.buffer
        self.tail = self.buffer + self.file.readinto(self.buffer)

class OutputDevice:
    def __init__(self):
        self.buffer = bytearray(BUFFER_SIZE + MAX_LENGTH)
        self.output = 0
        self.end = len(self.buffer)
        self.separate = False

    def write_to_device(self, count):
        raise NotImplementedError

    def flush(self):
        self.write_to_device(self.output)
        self.output = 0

class OutputFile(OutputDevice):
    def __init__(self, file):
        super().__init__()
        self.file = file

    def write_to_device(self, count):
        self.file.write(self.buffer[:count])
        self.file.flush()

def read_int():
    return int(input())

def write_int(value):
    print(value)

def solve(n):
    dp = [[0] * 8 for _ in range(61)]
    dp[0][0] = 1

    for i in range(60):
        bit = (1 << i) & n

        for j in range(8):
            if dp[i][j] == 0:
                continue

            for k in range((j % 2) ^ bit, 8, 2):
                lol = j + k
                dp[i + 1][lol // 2] += dp[i][j]
                if dp[i + 1][lol // 2] >= MOD:
                    dp[i + 1][lol // 2] -= MOD

    write_int(dp[60][0])

def main():
    tests = read_int()
    for _ in range(tests):
        n = read_int()
        solve(n)

if __name__ == "__main__":
    main()
