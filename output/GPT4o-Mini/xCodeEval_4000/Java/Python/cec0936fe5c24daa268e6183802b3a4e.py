import sys

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = bytearray(1024)
        self.cur_char = 0
        self.num_chars = 0

    def read(self):
        if self.num_chars == -1:
            raise ValueError("InputMismatchException")
        if self.cur_char >= self.num_chars:
            self.cur_char = 0
            self.num_chars = self.stream.readinto(self.buffer)
            if self.num_chars <= 0:
                return -1
        return self.buffer[self.cur_char]

    def read_int(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.is_space_char(c):
            if c < ord('0') or c > ord('9'):
                raise ValueError("InputMismatchException")
            res = res * 10 + (c - ord('0'))
            c = self.read()
        return res * sgn

    def read_long_array(self, size):
        return [self.read_int() for _ in range(size)]

    def is_space_char(self, c):
        return c in (ord(' '), ord('\n'), ord('\r'), ord('\t'), -1)

class OutputWriter:
    def __init__(self, output_stream):
        self.writer = output_stream

    def close(self):
        self.writer.close()

    def print_line(self, i):
        self.writer.write(f"{i}\n")

class AMarcinAndTrainingCamp:
    def solve(self, test_number, in_reader, out_writer):
        n = in_reader.read_int()
        A = in_reader.read_long_array(n)
        B = in_reader.read_long_array(n)
        used = [False] * n
        order = sorted(range(n), key=lambda i: A[i], reverse=True)
        res = 0
        idx = 0

        while idx < n:
            to = idx
            while to + 1 < n and A[order[to + 1]] == A[order[idx]]:
                to += 1
            valid = to > idx
            if not valid:
                for i in range(idx):
                    if used[i] and (A[order[i]] & A[order[idx]]) == A[order[idx]]:
                        valid = True
            if valid:
                for i in range(idx, to + 1):
                    res += B[order[i]]
                    used[i] = True
            idx = to + 1
        out_writer.print_line(res)

def main():
    input_stream = sys.stdin.buffer
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = OutputWriter(output_stream)
    solver = AMarcinAndTrainingCamp()
    solver.solve(1, in_reader, out_writer)
    out_writer.close()

if __name__ == "__main__":
    main()
