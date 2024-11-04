import sys
from collections import defaultdict

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.current_index = 0

    def read_int(self):
        while True:
            if self.current_index >= len(self.buffer):
                self.buffer = self.stream.readline().strip().split()
                self.current_index = 0
            if self.current_index < len(self.buffer):
                return int(self.buffer[self.current_index])
            self.current_index += 1

    def read_ints(self, count):
        return [self.read_int() for _ in range(count)]

class OutputWriter:
    def __init__(self, stream):
        self.writer = stream

    def print_line(self, value):
        self.writer.write(f"{value}\n")

class TaskC:
    def solve(self, test_number, in_reader, out_writer):
        x = in_reader.read_int()
        k = in_reader.read_int()
        n = in_reader.read_int()
        q = in_reader.read_int()
        c = in_reader.read_ints(k)
        p = in_reader.read_ints(q)
        w = in_reader.read_ints(q)

        order = sorted(range(q), key=lambda i: p[i])
        p = [p[i] for i in order]
        w = [w[i] for i in order]

        id_map = [-1] * (1 << k)
        by_id = []
        size = 0
        for i in range(1 << k):
            if bin(i).count('1') == x:
                id_map[i] = size
                by_id.append(i)
                size += 1

        base_mat = [[float('inf')] * size for _ in range(size)]
        spec_mat = [[[float('inf')] * size for _ in range(size)] for _ in range(q)]

        for i in range(size):
            ii = by_id[i]
            if (ii & 1) == 0:
                base_mat[id_map[ii]][id_map[ii >> 1]] = 0
                for j in range(q):
                    spec_mat[j][id_map[ii]][id_map[ii >> 1]] = 0
            else:
                ni = ii >> 1
                for j in range(k):
                    if (ni >> j & 1) == 0:
                        base_mat[id_map[ii]][id_map[ni + (1 << j)]] = c[j]
                        for l in range(q):
                            spec_mat[l][id_map[ii]][id_map[ni + (1 << j)]] = c[j] + w[l]

        current = [[float('inf')] * size for _ in range(size)]
        self.make_one(current)
        temp = [[0] * size for _ in range(size)]
        start = 0

        for i in range(q + 1):
            stop = n - x
            if i < q:
                stop = min(stop, p[i])
            self.power(base_mat, stop - start, temp)
            self.multiply(current, temp, spec_mat[i] if i < q else [[0] * size for _ in range(size)])
            if stop == n - x:
                break
            start = stop + 1

        answer = current[id_map[(1 << x) - 1]][id_map[(1 << x) - 1]]
        for i in range(q):
            if p[i] >= n - x:
                answer += w[i]

        out_writer.print_line(answer)

    def power(self, base, exponent, result):
        if exponent == 0:
            self.make_one(result)
            return
        temp = [[0] * len(result) for _ in range(len(result))]
        if (exponent & 1) == 0:
            self.power(base, exponent >> 1, temp)
            self.multiply(result, temp, temp)
        else:
            self.power(base, exponent - 1, temp)
            self.multiply(result, temp, base)

    def multiply(self, c, a, b):
        for i in range(len(c)):
            for j in range(len(c)):
                c[i][j] = float('inf')
                for k in range(len(c)):
                    if a[i][k] != float('inf') and b[k][j] != float('inf'):
                        c[i][j] = min(c[i][j], a[i][k] + b[k][j])

    def make_one(self, current):
        for i in range(len(current)):
            for j in range(len(current)):
                current[i][j] = float('inf')
            current[i][i] = 0

def main():
    input_reader = InputReader(sys.stdin)
    output_writer = OutputWriter(sys.stdout)
    solver = TaskC()
    solver.solve(1, input_reader, output_writer)

if __name__ == "__main__":
    main()
