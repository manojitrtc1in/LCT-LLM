import sys
import random
from collections import defaultdict

class CF1172C:
    def main():
        local = 'ONLINE_JUDGE' not in os.environ
        async_mode = False

        io = FastIO(sys.stdin if not local else open("D:\\DATABASE\\TESTCASE\\Code.in"), sys.stdout)
        task = Task(io)

        if async_mode:
            import threading
            t = threading.Thread(target=task.run)
            t.start()
            t.join()
        else:
            task.run()

        if local:
            io.cache.append(f"\n\n--memory -- \n{(sys.getsizeof(task) >> 20)}M")

        io.flush()

class Task:
    def __init__(self, io):
        self.io = io
        self.inf = int(1e8)
        self.modular = Modular(998244353)
        self.power = Power(self.modular)

    def run(self):
        self.solve()

    def solve(self):
        n = self.io.read_int()
        m = self.io.read_int()
        a = [self.io.read_int() for _ in range(n)]
        count = [0, 0]
        for num in a:
            count[num % 2] += 1

        w = [self.io.read_int() for _ in range(n)]
        hW = sum(w[i] for i in range(n) if a[i] % 2 == 0)
        fW = sum(w[i] for i in range(n) if a[i] % 2 == 1)

        inv = [self.power.inverse(self.modular.value_of(hW + fW + i - m)) for i in range(m * 2 + 1)]

        self.f = [[-1] * (m + 1) for _ in range(m + 1)]
        self.h = [[-1] * (m + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            self.f[i][0] = 1
            self.h[i][0] = 1

        for i in range(n):
            if a[i] % 2 == 1:
                self.io.cache.append(self.modular.mul(w[i], self.f_func(0, m)))
            else:
                self.io.cache.append(self.modular.mul(w[i], self.h_func(0, m)))
            self.io.cache.append('\n')

    def f_func(self, i, k):
        if self.f[i][k] == -1:
            j = (m - k) - i
            fixI = self.modular.plus(i, fW)
            fixJ = self.modular.plus(hW, -j)
            self.f[i][k] = 0
            inv = self.inv[i - j + m]
            self.f[i][k] = self.modular.plus(self.f[i][k], self.modular.mul(self.modular.mul(fixI + 1, inv), self.f_func(i + 1, k - 1)))
            self.f[i][k] = self.modular.plus(self.f[i][k], self.modular.mul(self.modular.mul(fixJ, inv), self.f_func(i, k - 1)))
        return self.f[i][k]

    def h_func(self, i, k):
        if self.h[i][k] == -1:
            j = (m - k) - i
            fixI = self.modular.plus(i, fW)
            fixJ = self.modular.plus(hW, -j)
            self.h[i][k] = 0
            inv = self.inv[i - j + m]
            self.h[i][k] = self.modular.plus(self.h[i][k], self.modular.mul(self.modular.mul(fixJ - 1, inv), self.h_func(i, k - 1)))
            self.h[i][k] = self.modular.plus(self.h[i][k], self.modular.mul(self.modular.mul(fixI, inv), self.h_func(i + 1, k - 1)))
        return self.h[i][k]

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

class FastIO:
    def __init__(self, input_stream, output_stream):
        self.cache = []
        self.is = input_stream
        self.os = output_stream
        self.next = None

    def read_int(self):
        self.skip_blank()
        sign = 1
        if self.next == '+' or self.next == '-':
            sign = 1 if self.next == '+' else -1
            self.next = self.read()
        val = 0
        while '0' <= self.next <= '9':
            val = val * 10 + ord(self.next) - ord('0')
            self.next = self.read()
        return sign * val

    def read(self):
        return self.is.read(1)

    def skip_blank(self):
        while self.next is not None and self.next <= ' ':
            self.next = self.read()

    def flush(self):
        self.os.write(''.join(self.cache).encode())
        self.cache.clear()

if __name__ == "__main__":
    CF1172C.main()
