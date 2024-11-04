import sys
import random
from collections import defaultdict

class FastIO:
    def __init__(self, input_stream, output_stream):
        self.input_stream = input_stream
        self.output_stream = output_stream
        self.cache = []

    def read_int(self):
        return int(self.read_string().strip())

    def read_string(self):
        return self.input_stream.readline()

    def flush(self):
        self.output_stream.write(''.join(self.cache))
        self.output_stream.flush()
        self.cache.clear()

class Modular:
    def __init__(self, m):
        self.m = m

    def value_of(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.value_of(x * y)

    def plus(self, x, y):
        return self.value_of(x + y)

class Power:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return 1
        r = self.pow(x, n >> 1)
        r = self.modular.value_of(r * r)
        if (n & 1) == 1:
            r = self.modular.value_of(r * x)
        return r

    def inverse(self, x):
        return self.pow(x, self.modular.m - 2)

class Task:
    def __init__(self, io):
        self.io = io
        self.inf = int(1e8)
        self.modular = Modular(998244353)
        self.power = Power(self.modular)

    def solve(self):
        n = self.io.read_int()
        m = self.io.read_int()
        a = [self.io.read_int() for _ in range(n)]
        count = [0, 0]
        for num in a:
            count[num % 2] += 1

        w = [self.io.read_int() for _ in range(n)]
        fW = sum(w[i] for i in range(n) if a[i] % 2 != 0)
        hW = sum(w[i] for i in range(n) if a[i] % 2 == 0)

        inv = [self.power.inverse(self.modular.value_of(hW + fW + i - m)) for i in range(m * 2 + 1)]
        f = [[-1] * (m + 1) for _ in range(m + 1)]
        h = [[-1] * (m + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            f[i][0] = 1
            h[i][0] = 1

        for i in range(n):
            if a[i] % 2 == 1:
                self.io.cache.append(str(self.modular.mul(w[i], self.f(0, m))) + '\n')
            else:
                self.io.cache.append(str(self.modular.mul(w[i], self.h(0, m))) + '\n')

    def f(self, i, k):
        if self.f[i][k] == -1:
            j = (m - k) - i
            fixI = self.modular.plus(i, fW)
            fixJ = self.modular.plus(hW, -j)
            self.f[i][k] = 0
            inv = self.inv[i - j + m]
            self.f[i][k] = self.modular.plus(self.f[i][k], self.modular.mul(self.modular.mul(fixI + 1, inv), self.f(i + 1, k - 1)))
            self.f[i][k] = self.modular.plus(self.f[i][k], self.modular.mul(self.modular.mul(fixJ, inv), self.f(i, k - 1)))
        return self.f[i][k]

    def h(self, i, k):
        if self.h[i][k] == -1:
            j = (m - k) - i
            fixI = self.modular.plus(i, fW)
            fixJ = self.modular.plus(hW, -j)
            self.h[i][k] = 0
            inv = self.inv[i - j + m]
            self.h[i][k] = self.modular.plus(self.h[i][k], self.modular.mul(self.modular.mul(fixJ - 1, inv), self.h(i, k - 1)))
            self.h[i][k] = self.modular.plus(self.h[i][k], self.modular.mul(self.modular.mul(fixI, inv), self.h(i + 1, k - 1)))
        return self.h[i][k]

def main():
    local = 'ONLINE_JUDGE' not in os.environ
    io = FastIO(sys.stdin, sys.stdout)
    task = Task(io)

    task.solve()
    io.flush()

if __name__ == "__main__":
    main()
