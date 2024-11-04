import sys
from collections import deque

class Main:
    @staticmethod
    def main():
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_reader = InputReader(input_stream)
        out_writer = OutputWriter(output_stream)
        solver = TaskE()
        solver.solve(1, in_reader, out_writer)
        out_writer.close()

class TaskE:
    def solve(self, test_number, in_reader, out_writer):
        r = in_reader.read_int()
        c = in_reader.read_int()
        n = in_reader.read_int()
        k = in_reader.read_int()
        x = [0] * n
        y = [0] * n
        IOUtils.read_int_arrays(in_reader, x, y)
        MiscUtils.decrease_by_one(x, y)
        ArrayUtils.order_by(y, x)
        head_position = [Position(-1, -1) for _ in range(k)]
        for i in range(k):
            if i != 0:
                head_position[i].last = head_position[i - 1]
                head_position[i - 1].next = head_position[i]
        tail_position = [Position(r, -2) for _ in range(k)]
        for i in range(k):
            if i != 0:
                tail_position[i].last = tail_position[i - 1]
                tail_position[i - 1].next = tail_position[i]
        positions = [Position(x[i], i) for i in range(n)]
        answer = 0
        for i in range(c):
            at = 0
            while at < n and y[at] < i:
                at += 1
            for j in range(k - 1):
                head_position[j + 1].link = tail_position[j]
            set_positions = set()
            set_positions.add(head_position[k - 1])
            set_positions.add(tail_position[0])
            head_position[k - 1].next = tail_position[0]
            tail_position[0].last = head_position[k - 1]
            delta = 0
            for j in range(i, c):
                while at < n and y[at] == j:
                    where = max((pos for pos in set_positions if pos < positions[at]), default=None)
                    current = where
                    for l in range(1, k):
                        delta -= current.value(r)
                        current = current.last
                    next_pos = where.next
                    delta -= next_pos.value(r)
                    current = positions[at]
                    where.next = current
                    current.last = where
                    next_pos.last = current
                    current.next = next_pos
                    current.link = current if k == 1 else where.link
                    set_positions.add(current)
                    delta += next_pos.value(r)
                    delta += current.value(r)
                    current = where
                    for l in range(1, k):
                        current.link = current.link.last
                        delta += current.value(r)
                        current = current.last
                    at += 1
                answer += delta
        out_writer.print_line(answer)

class Position:
    def __init__(self, row, id):
        self.row = row
        self.id = id
        self.last = None
        self.next = None
        self.link = None

    def __lt__(self, other):
        if self.row != other.row:
            return self.row < other.row
        return self.id < other.id

    def value(self, r):
        if self.link is None:
            return 0
        return (self.row - self.last.row) * (r - self.link.row)

class IOUtils:
    @staticmethod
    def read_int_arrays(in_reader, *arrays):
        for i in range(len(arrays[0])):
            for j in range(len(arrays)):
                arrays[j][i] = in_reader.read_int()

class InputReader:
    def __init__(self, stream):
        self.stream = stream
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

    def is_space_char(self, c):
        return c in (ord(' '), ord('\n'), ord('\r'), ord('\t'), -1)

class OutputWriter:
    def __init__(self, output_stream):
        self.writer = output_stream

    def close(self):
        self.writer.close()

    def print_line(self, i):
        self.writer.write(f"{i}\n")

class ArrayUtils:
    @staticmethod
    def order_by(base, *arrays):
        order = ArrayUtils.order(base)
        ArrayUtils.order(order, base)
        for array in arrays:
            ArrayUtils.order(order, array)

    @staticmethod
    def order(array):
        return sorted(range(len(array)), key=lambda i: array[i])

    @staticmethod
    def order(order, array):
        temp_int = [array[i] for i in order]
        for i in range(len(array)):
            array[i] = temp_int[i]

class MiscUtils:
    @staticmethod
    def decrease_by_one(*arrays):
        for array in arrays:
            for i in range(len(array)):
                array[i] -= 1

if __name__ == "__main__":
    Main.main()
