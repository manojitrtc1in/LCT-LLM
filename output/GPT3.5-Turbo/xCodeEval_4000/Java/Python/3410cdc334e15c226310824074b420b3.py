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
            self.input_buffer = input().split()
        return int(self.input_buffer.pop(0))

    def read_int_list(self, size: int) -> List[int]:
        return [self.read_int() for _ in range(size)]

    def write(self, value):
        self.output_buffer.append(str(value))

    def flush(self):
        if self.output_file:
            with open(self.output_file, 'w') as f:
                f.write(''.join(self.output_buffer))
        else:
            print(''.join(self.output_buffer), end='')

def solve(n: int, m: int, a: List[int], w: List[int]) -> List[int]:
    count = [0, 0]
    for i in range(n):
        count[a[i] % 2] += 1

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

    res = []
    for i in range(n):
        if a[i] % 2 == 1:
            res.append(w[i] * f(0, m, f, h, inv))
        else:
            res.append(w[i] * h(0, m, f, h, inv))
    return res

def f(i: int, k: int, f: List[List[int]], h: List[List[int]], inv: List[int]) -> int:
    if f[i][k] == -1:
        j = (m - k) - i
        fixI = i + fW
        fixJ = hW - j
        f[i][k] = 0
        f[i][k] += (fixI + 1) * inv[i - j + m] * f(i + 1, k - 1, f, h, inv)
        f[i][k] += fixJ * inv[i - j + m] * f(i, k - 1, f, h, inv)
        f[i][k] %= 998244353
    return f[i][k]

def h(i: int, k: int, f: List[List[int]], h: List[List[int]], inv: List[int]) -> int:
    if h[i][k] == -1:
        j = (m - k) - i
        fixI = i + fW
        fixJ = hW - j
        h[i][k] = 0
        h[i][k] += (fixJ - 1) * inv[i - j + m] * h(i, k - 1, f, h, inv)
        h[i][k] += fixI * inv[i - j + m] * h(i + 1, k - 1, f, h, inv)
        h[i][k] %= 998244353
    return h[i][k]

def main():
    io = FastIO()
    n, m = io.read_int(), io.read_int()
    a = io.read_int_list(n)
    w = io.read_int_list(n)
    res = solve(n, m, a, w)
    for r in res:
        io.write(r)
        io.write('\n')
    io.flush()

if __name__ == '__main__':
    main()
