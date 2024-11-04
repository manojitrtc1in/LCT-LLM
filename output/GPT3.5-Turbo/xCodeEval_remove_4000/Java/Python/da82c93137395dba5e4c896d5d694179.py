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
    f = [[-1] * (m + 1) for _ in range(m + 1)]
    h = [[-1] * (m + 1) for _ in range(m + 1)]
    fW = 0
    hW = 0
    inv = [0] * (m * 2 + 1)

    count = [0, 0]
    for i in range(n):
        count[a[i] % 2] += 1

    for i in range(n):
        if a[i] % 2 == 0:
            hW += w[i]
        else:
            fW += w[i]

    for i in range(m * 2 + 1):
        inv[i] = pow(hW + fW + i - m, -1, 998244353)

    for i in range(m + 1):
        f[i][0] = 1
        h[i][0] = 1

    for i in range(n):
        if a[i] % 2 == 1:
            yield (w[i] * f(0, m)) % 998244353
        else:
            yield (w[i] * h(0, m)) % 998244353

def f(i: int, k: int) -> int:
    if f[i][k] == -1:
        j = (m - k) - i
        fixI = i + fW
        fixJ = hW - j
        f[i][k] = 0
        inv = inv[i - j + m]
        f[i][k] = (f[i][k] + ((fixI + 1) * inv * f(i + 1, k - 1)) % 998244353) % 998244353
        f[i][k] = (f[i][k] + (fixJ * inv * f(i, k - 1)) % 998244353) % 998244353
    return f[i][k]

def h(i: int, k: int) -> int:
    if h[i][k] == -1:
        j = (m - k) - i
        fixI = i + fW
        fixJ = hW - j
        h[i][k] = 0
        inv = inv[i - j + m]
        h[i][k] = (h[i][k] + ((fixJ - 1) * inv * h(i, k - 1)) % 998244353) % 998244353
        h[i][k] = (h[i][k] + (fixI * inv * h(i + 1, k - 1)) % 998244353) % 998244353
    return h[i][k]

def main():
    io = FastIO()
    n, m = io.read_int(), io.read_int()
    a = io.read_int_list(n)
    w = io.read_int_list(n)
    for ans in solve(n, m, a, w):
        io.write(ans)
        io.write('\n')
    io.flush()

if __name__ == '__main__':
    main()
