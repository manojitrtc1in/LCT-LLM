import sys
from typing import List, Tuple

class FastIO:
    def __init__(self, input_file=None, output_file=None):
        self.input_file = input_file
        self.output_file = output_file
        self.input_buffer = []
        self.output_buffer = []

    def read_int(self) -> int:
        if not self.input_buffer:
            self.input_buffer = self.input_file.readline().split()
        return int(self.input_buffer.pop(0))

    def read_int_list(self, size: int) -> List[int]:
        return [self.read_int() for _ in range(size)]

    def write(self, value):
        self.output_buffer.append(str(value))

    def write_line(self, value):
        self.write(value)
        self.write('\n')

    def flush(self):
        self.output_file.write(''.join(self.output_buffer))
        self.output_file.flush()
        self.output_buffer.clear()

def solve(io: FastIO):
    n, m = io.read_int(), io.read_int()
    a = io.read_int_list(n)
    count = [0, 0]
    for i in range(n):
        count[a[i] % 2] += 1
    w = io.read_int_list(n)
    fW, hW = 0, 0
    for i in range(n):
        if a[i] % 2 == 0:
            hW += w[i]
        else:
            fW += w[i]
    inv = [0] * (m * 2 + 1)
    for i in range(m * 2 + 1):
        inv[i] = pow(hW + fW + i - m, -1, 998244353)
    f = [[-1] * (m + 1) for _ in range(m + 1)]
    h = [[-1] * (m + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        f[i][0] = 1
        h[i][0] = 1
    for i in range(n):
        if a[i] % 2 == 1:
            io.write_line((w[i] * f(0, m)) % 998244353)
        else:
            io.write_line((w[i] * h(0, m)) % 998244353)

def main():
    io = FastIO(sys.stdin, sys.stdout)
    solve(io)
    io.flush()

if __name__ == '__main__':
    main()
