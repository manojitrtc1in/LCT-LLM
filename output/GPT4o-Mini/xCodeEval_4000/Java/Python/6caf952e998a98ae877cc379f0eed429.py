import sys
from collections import deque
from math import acos, pi, sqrt, sin, cos, atan2

class Main:
    @staticmethod
    def main():
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_reader = InputReader(input_stream)
        out_writer = OutputWriter(output_stream)
        solver = A()
        solver.solve(1, in_reader, out_writer)
        out_writer.close()

class Task:
    def solve(self, test_number, in_reader, out_writer):
        pass

class A(Task):
    def solve(self, test_number, in_reader, out_writer):
        str_input = in_reader.next()
        ret = 0
        n = len(str_input)
        c = 0
        for i in range(1, n):
            if str_input[i] != str_input[i - 1]:
                ret += c % 2
                c = 0
            else:
                c += 1
        ret += c % 2
        out_writer.print_line(ret)

class B(Task):
    def solve(self, test_number, in_reader, out_writer):
        str_input = in_reader.next()
        ret = []
        for c in str_input:
            if c == '>':
                ret.append("1000")
            elif c == '<':
                ret.append("1001")
            elif c == '+':
                ret.append("1010")
            elif c == '-':
                ret.append("1011")
            elif c == '.':
                ret.append("1100")
            elif c == ',':
                ret.append("1101")
            elif c == '[':
                ret.append("1110")
            else:
                ret.append("1111")
        n = 0
        for char in ''.join(ret):
            n = (2 * n + int(char)) % 1000003
        out_writer.print_line(n)

class C(Task):
    def solve(self, test_number, in_reader, out_writer):
        pass

class D(Task):
    def solve(self, test_number, in_reader, out_writer):
        pass

class E(Task):
    def solve(self, test_number, in_reader, out_writer):
        pass

class F(Task):
    def solve(self, test_number, in_reader, out_writer):
        pass

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

    def read_string(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        res = []
        while not self.is_space_char(c):
            res.append(chr(c))
            c = self.read()
        return ''.join(res)

    def is_space_char(self, c):
        return c in (ord(' '), ord('\n'), ord('\r'), ord('\t'), -1)

    def next(self):
        return self.read_string()

class OutputWriter:
    def __init__(self, output_stream):
        self.writer = output_stream

    def print_line(self, *objects):
        self.writer.write(' '.join(map(str, objects)) + '\n')

    def close(self):
        self.writer.close()

if __name__ == "__main__":
    Main.main()
