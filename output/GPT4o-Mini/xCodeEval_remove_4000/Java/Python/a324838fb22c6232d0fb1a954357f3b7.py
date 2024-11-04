import sys
import math
from collections import defaultdict

class ProblemSolver:
    def id13(self, in_reader, out_writer, nt):
        test = 1

        while test > 0:
            test -= 1
            n = in_reader.next_int()
            ar = in_reader.id0(n, n)

            sum_ = 0
            for i in range(n):
                sum_ += ar[i][i]

            for i in range(n):
                sum_ += ar[n - i - 1][i]

            for i in range(n):
                sum_ += ar[(n - 1) // 2][i]

            for i in range(n):
                sum_ += ar[i][(n - 1) // 2]

            out_writer.println(sum_ - ar[(n - 1) // 2][(n - 1) // 2] * 3)

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.finished = False
        self.buf = bytearray(1024)
        self.cur_char = 0
        self.num_chars = 0

    def read(self):
        if self.num_chars == -1:
            raise ValueError("InputMismatchException")
        if self.cur_char >= self.num_chars:
            self.cur_char = 0
            self.num_chars = self.stream.readinto(self.buf)
            if self.num_chars <= 0:
                return -1
        return self.buf[self.cur_char]

    def next_int(self):
        c = self.read()
        while self.is_whitespace(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.is_whitespace(c):
            if c < ord('0') or c > ord('9'):
                raise ValueError("InputMismatchException")
            res = res * 10 + (c - ord('0'))
            c = self.read()
        return res * sgn

    def id0(self, n, m):
        matrix = []
        for i in range(n):
            row = [self.next_int() for _ in range(m)]
            matrix.append(row)
        return matrix

    def is_whitespace(self, c):
        return c in (ord(' '), ord('\n'), ord('\r'), ord('\t'), -1)

class OutputWriter:
    def __init__(self, output_stream):
        self.writer = output_stream

    def println(self, *objects):
        self.writer.write(' '.join(map(str, objects)) + '\n')

def main():
    input_stream = sys.stdin.buffer
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = OutputWriter(output_stream)
    nt = NumberTheory()
    problem_solver = ProblemSolver()
    problem_solver.id13(in_reader, out_writer, nt)

if __name__ == "__main__":
    main()

class NumberTheory:
    def id11(self, a, b, MOD):
        return (a % MOD + b % MOD) % MOD

    def id19(self, a, b, MOD):
        return (a % MOD * b % MOD) % MOD

    def id15(self, a, b, MOD):
        return (a % MOD - b % MOD + MOD) % MOD

    def id26(self, x, n):
        if n == 0:
            return 1
        elif n % 2 == 0:
            return self.id26(x * x, n // 2)
        else:
            return x * self.id26(x * x, (n - 1) // 2)

    def factorials(self, n):
        if n == 0:
            return 1
        return n * self.factorials(n - 1)

    def prime_factors(self, n):
        factors = []
        limit = int(math.sqrt(n))
        if n % 2 == 0:
            factors.append(2)
            while n % 2 == 0:
                n //= 2
        for i in range(3, limit + 1, 2):
            if n % i == 0:
                factors.append(i)
                while n % i == 0:
                    n //= i
        if n > 2:
            factors.append(n)
        return factors
