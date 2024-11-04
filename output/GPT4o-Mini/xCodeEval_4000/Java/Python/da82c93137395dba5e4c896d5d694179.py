import sys
import random
from collections import defaultdict

class CF1172C:
    @staticmethod
    def main():
        local = 'ONLINE_JUDGE' not in sys.environ
        async_mode = False

        io = FastIO(open("D:\\DATABASE\\TESTCASE\\Code.in", "r") if local else sys.stdin, sys.stdout)
        task = Task(io)

        if async_mode:
            import threading
            t = threading.Thread(target=task.run)
            t.start()
            t.join()
        else:
            task.run()

        if local:
            io.cache.append("\n\n--memory -- \n" + str((sys.getsizeof(task) >> 20)) + "M")

        io.flush()

class Task:
    def __init__(self, io):
        self.io = io
        self.inf = int(1e8)
        self.modular = MathUtils.Modular(998244353)
        self.power = MathUtils.Power(self.modular)

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
        fW = hW = 0
        for i in range(n):
            if a[i] % 2 == 0:
                hW += w[i]
            else:
                fW += w[i]

        inv = [0] * (m * 2 + 1)
        for i in range(m * 2 + 1):
            inv[i] = self.power.inverse(self.modular.value_of(hW + fW + i - m))

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

class MathUtils:
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
        self.is_ = input_stream
        self.os = output_stream
        self.next = None

    def read(self):
        return self.is_.read(1)

    def read_int(self):
        self.skip_blank()
        sign = 1
        if self.next == b'-':
            sign = -1
            self.next = self.read()
        elif self.next == b'+':
            self.next = self.read()

        val = 0
        while self.next >= b'0' and self.next <= b'9':
            val = val * 10 + int(self.next)
            self.next = self.read()
        return sign * val

    def skip_blank(self):
        while self.next is not None and self.next <= b' ':
            self.next = self.read()

    def flush(self):
        self.os.write(b''.join(self.cache).encode())
        self.cache.clear()

if __name__ == "__main__":
    CF1172C.main()
