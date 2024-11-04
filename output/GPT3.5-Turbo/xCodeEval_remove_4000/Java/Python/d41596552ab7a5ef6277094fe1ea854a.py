import sys
from typing import List
from io import IOBase, BytesIO

class InputReader:
    def __init__(self, stream: IOBase):
        self.stream = stream
        self.buffer = BytesIO()
        self.cur_char = 0
        self.num_chars = 0

    def read(self) -> int:
        if self.num_chars == -1:
            raise EOFError()
        if self.cur_char >= self.num_chars:
            self.cur_char = 0
            self.buffer = BytesIO(self.stream.read())
            self.num_chars = len(self.buffer)
            if self.num_chars <= 0:
                return -1
        return self.buffer.read(1)[0]

    def read_int(self) -> int:
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
                raise ValueError("Invalid integer")
            res = res * 10 + (c - ord('0'))
            c = self.read()
        return res * sgn

    @staticmethod
    def is_whitespace(c: int) -> bool:
        return c == ord(' ') or c == ord('\n') or c == ord('\r') or c == ord('\t') or c == -1

class OutputWriter:
    def __init__(self, stream: IOBase):
        self.stream = stream

    def print_line(self, i: int):
        self.stream.write(str(i) + '\n')

class TaskC:
    def solve(self, test_number: int, in_stream: InputReader, out_stream: OutputWriter):
        x = in_stream.read_int()
        k = in_stream.read_int()
        n = in_stream.read_int()
        q = in_stream.read_int()
        c = [in_stream.read_int() for _ in range(k)]
        p = [0] * q
        w = [0] * q
        for i in range(q):
            p[i], w[i] = in_stream.read_int(), in_stream.read_int()
        order_by(p, w)
        id5(p)
        id = [-1] * (1 << k)
        by_id = [0] * (1 << k)
        size = 0
        for i in range(1 << k):
            if bin(i).count('1') == x:
                id[i] = size
                by_id[size] = i
                size += 1
        base_mat = [[sys.maxsize] * size for _ in range(size)]
        spec_mat = [[[sys.maxsize] * size for _ in range(size)] for _ in range(q)]
        for i in range(size):
            ii = by_id[i]
            if (ii & 1) == 0:
                base_mat[id[ii]][id[ii >> 1]] = 0
                for j in range(q):
                    spec_mat[j][id[ii]][id[ii >> 1]] = 0
            else:
                ni = ii >> 1
                for j in range(k):
                    if (ni >> j) & 1 == 0:
                        base_mat[id[ii]][id[ni + (1 << j)]] = c[j]
                        for l in range(q):
                            spec_mat[l][id[ii]][id[ni + (1 << j)]] = c[j] + w[l]
        current = [[0] * size for _ in range(size)]
        make_one(current)
        temp = [[0] * size for _ in range(size)]
        temp1 = [[0] * size for _ in range(size)]
        temp2 = [[0] * size for _ in range(size)]
        start = 0
        for i in range(q + 1):
            stop = n - x
            if i < q:
                stop = min(stop, p[i])
            power(base_mat, stop - start, temp1, temp2)
            multiply(temp, current, temp1)
            if stop == n - x:
                current = temp
                break
            else:
                multiply(current, temp, spec_mat[i])
                start = stop + 1
        answer = current[id[(1 << x) - 1]][id[(1 << x) - 1]]
        for i in range(q):
            if p[i] >= n - x:
                answer += w[i]
        out_stream.print_line(answer)

    def power(self, base: List[List[int]], exponent: int, result: List[List[int]], temp: List[List[int]]):
        if exponent == 0:
            make_one(result)
            return
        if exponent & 1 == 0:
            self.power(base, exponent >> 1, temp, result)
            multiply(result, temp, temp)
        else:
            self.power(base, exponent - 1, temp, result)
            multiply(result, temp, base)

    def multiply(self, c: List[List[int]], a: List[List[int]], b: List[List[int]]):
        size = len(c)
        for i in range(size):
            for j in range(size):
                c[i][j] = sys.maxsize
                for k in range(size):
                    if a[i][k] != sys.maxsize and b[k][j] != sys.maxsize:
                        c[i][j] = min(c[i][j], a[i][k] + b[k][j])

    def make_one(self, current: List[List[int]]):
        size = len(current)
        for i in range(size):
            current[i][i] = 0

    def order_by(self, base: List[int], *arrays: List[int]):
        order = list(range(len(base)))
        order.sort(key=lambda x: base[x])
        order(order, base)
        for array in arrays:
            order(order, array)

    def order(self, order: List[int], array: List[int]):
        size = len(order)
        temp_int = [0] * size
        for i in range(size):
            temp_int[i] = array[order[i]]
        array[:] = temp_int

    def id5(self, *arrays: List[int]):
        for array in arrays:
            for i in range(len(array)):
                array[i] -= 1

    def main(self):
        in_stream = InputReader(sys.stdin)
        out_stream = OutputWriter(sys.stdout)
        solver = TaskC()
        solver.solve(1, in_stream, out_stream)
        out_stream.close()

if __name__ == "__main__":
    TaskC().main()
