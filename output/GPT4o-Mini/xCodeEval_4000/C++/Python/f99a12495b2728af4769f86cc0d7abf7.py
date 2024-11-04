import sys
from collections import defaultdict
from random import randint

MOD = 998244353

class ModInt:
    def __init__(self, x=0):
        self.x = x % MOD
        if self.x < 0:
            self.x += MOD

    def __add__(self, other):
        return ModInt(self.x + other.x)

    def __sub__(self, other):
        return ModInt(self.x - other.x)

    def __mul__(self, other):
        return ModInt(self.x * other.x)

    def __truediv__(self, other):
        return ModInt(self.x * pow(other.x, MOD - 2, MOD))

    def __pow__(self, n):
        return ModInt(pow(self.x, n, MOD))

    def __repr__(self):
        return str(self.x)

class NumberTheoreticTransform:
    def __init__(self):
        self.max_base = 0
        self.root = 2
        while pow(self.root, (MOD - 1) // 2, MOD) == 1:
            self.root += 1
        self.dw = []
        self.idw = []
        tmp = MOD - 1
        while tmp % 2 == 0:
            tmp //= 2
            self.max_base += 1
        for i in range(self.max_base):
            self.dw.append(ModInt(-pow(self.root, (MOD - 1) >> (i + 2), MOD)))
            self.idw.append(ModInt(1) / self.dw[i])

    def ntt(self, a):
        n = len(a)
        for m in range(n, 1, -1):
            w = ModInt(1)
            for s in range(0, n, 2 * m):
                for i in range(s, s + m):
                    j = i + m
                    x = a[i]
                    y = a[j] * w
                    a[i] = x + y
                    a[j] = x - y
                w *= self.dw[__builtin_ctz(m)]

    def intt(self, a, f=True):
        n = len(a)
        for m in range(1, n, 2):
            w = ModInt(1)
            for s in range(0, n, 2 * m):
                for i in range(s, s + m):
                    j = i + m
                    x = a[i]
                    y = a[j]
                    a[i] = x + y
                    a[j] = (x - y) * w
                w *= self.idw[__builtin_ctz(m)]
        if f:
            inv_sz = ModInt(1) / n
            for i in range(n):
                a[i] *= inv_sz

    def multiply(self, a, b):
        need = len(a) + len(b) - 1
        nbase = 1
        while (1 << nbase) < need:
            nbase += 1
        sz = 1 << nbase
        a += [ModInt(0)] * (sz - len(a))
        b += [ModInt(0)] * (sz - len(b))
        self.ntt(a)
        self.ntt(b)
        inv_sz = ModInt(1) / sz
        for i in range(sz):
            a[i] *= b[i] * inv_sz
        self.intt(a, False)
        return a[:need]

class FormalPowerSeries(list):
    @staticmethod
    def get_mult():
        return FormalPowerSeries._mult

    @staticmethod
    def set_mult(f):
        FormalPowerSeries._mult = f

    def __add__(self, other):
        return FormalPowerSeries(self) + other

    def __sub__(self, other):
        return FormalPowerSeries(self) - other

    def __mul__(self, other):
        return FormalPowerSeries(self) * other

    def __truediv__(self, other):
        return FormalPowerSeries(self) / other

    def inv(self, deg=-1):
        assert self[0] != ModInt(0)
        n = len(self)
        if deg == -1:
            deg = n
        res = [ModInt(1) / self[0]]
        for d in range(1, deg):
            f = [ModInt(0)] * (2 * d)
            g = [ModInt(0)] * (2 * d)
            for j in range(min(n, 2 * d)):
                f[j] = self[j]
            for j in range(d):
                g[j] = res[j]
            ntt.ntt(f)
            ntt.ntt(g)
            for j in range(2 * d):
                f[j] *= g[j]
            ntt.intt(f)
            for j in range(d):
                f[j] = 0
                f[j + d] = -f[j + d]
            ntt.ntt(f)
            for j in range(2 * d):
                f[j] *= g[j]
            ntt.intt(f)
            for j in range(d):
                f[j] = res[j]
            res = f
        return res[:n]

ntt = NumberTheoreticTransform()

def main():
    n, k = map(int, sys.stdin.readline().split())
    h = list(map(int, sys.stdin.readline().split()))
    h.append(h[0])

    cnt = sum(1 for i in range(n) if h[i] == h[i + 1])
    d = n - cnt

    res = ModInt(k) ** cnt
    sum_f = ModInt(0)

    f = FormalPowerSeries([ModInt(1), ModInt(k - 2), ModInt(1)] + [ModInt(0)] * (2 * d - 2))
    f = f.pow(d)
    for i in range(d + 1, 2 * d + 1):
        sum_f += f[i]

    print(res * sum_f)

if __name__ == "__main__":
    main()
