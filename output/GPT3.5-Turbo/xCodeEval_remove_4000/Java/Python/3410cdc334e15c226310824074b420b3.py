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

class Task:
    def __init__(self, io):
        self.io = io

    def run(self):
        n, m = self.io.read_int(), self.io.read_int()
        a = self.io.read_int_list(n)
        count = [0, 0]
        for i in range(n):
            count[a[i] % 2] += 1
        w = self.io.read_int_list(n)
        fW, hW = 0, 0
        for i in range(n):
            if a[i] % 2 == 0:
                hW += w[i]
            else:
                fW += w[i]
        inv = [0] * (m * 2 + 1)
        for i in range(m * 2 + 1):
            inv[i] = self.inverse(hW + fW + i - m)
        f = [[-1] * (m + 1) for _ in range(m + 1)]
        h = [[-1] * (m + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            f[i][0] = 1
            h[i][0] = 1
        for i in range(n):
            if a[i] % 2 == 1:
                self.io.write_line(self.mul(w[i], self.f(0, m)))
            else:
                self.io.write_line(self.mul(w[i], self.h(0, m)))

    def f(self, i: int, k: int) -> int:
        if self.f[i][k] == -1:
            j = (m - k) - i
            fixI = i + fW
            fixJ = hW - j
            self.f[i][k] = 0
            inv = self.inv[i - j + m]
            self.f[i][k] = self.plus(self.f[i][k], self.mul(self.mul(fixI + 1, inv), self.f(i + 1, k - 1)))
            self.f[i][k] = self.plus(self.f[i][k], self.mul(self.mul(fixJ, inv), self.f(i, k - 1)))
        return self.f[i][k]

    def h(self, i: int, k: int) -> int:
        if self.h[i][k] == -1:
            j = (m - k) - i
            fixI = i + fW
            fixJ = hW - j
            self.h[i][k] = 0
            inv = self.inv[i - j + m]
            self.h[i][k] = self.plus(self.h[i][k], self.mul(self.mul(fixJ - 1, inv), self.h(i, k - 1)))
            self.h[i][k] = self.plus(self.h[i][k], self.mul(self.mul(fixI, inv), self.h(i + 1, k - 1)))
        return self.h[i][k]

    def plus(self, a: int, b: int) -> int:
        return (a + b) % 998244353

    def mul(self, a: int, b: int) -> int:
        return (a * b) % 998244353

    def inverse(self, x: int) -> int:
        return pow(x, 998244353 - 2, 998244353)

def main():
    io = FastIO(sys.stdin, sys.stdout)
    task = Task(io)
    task.run()
    io.flush()

if __name__ == '__main__':
    main()
