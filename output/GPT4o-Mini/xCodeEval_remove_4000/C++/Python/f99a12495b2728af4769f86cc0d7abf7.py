from collections import defaultdict
import sys
import random

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

class NTT:
    def __init__(self):
        self.max_base = 0
        self.root = 2
        while self.root ** ((MOD - 1) // 2) == 1:
            self.root += 1
        self.dw = []
        self.idw = []

        tmp = MOD - 1
        while tmp % 2 == 0:
            tmp //= 2
            self.max_base += 1

        self.dw = [-self.root ** ((MOD - 1) // (1 << (i + 2))) for i in range(self.max_base)]
        self.idw = [ModInt(1) / self.dw[i] for i in range(self.max_base)]

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
                w *= self.dw[self.max_base - (m // 2).bit_length()]

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
                w *= self.idw[self.max_base - (m // 2).bit_length()]
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

ntt = NTT()

def main():
    n, k = map(int, input().split())
    h = list(map(int, input().split()))
    h.append(h[0])

    cnt = sum(1 for i in range(n) if h[i] == h[i + 1])
    d = n - cnt

    res = ModInt(k) ** cnt
    sum_f = ModInt(0)

    f = [ModInt(0)] * (2 * d + 1)
    f[0] = ModInt(1)
    f[1] = ModInt(k - 2)
    f[2] = ModInt(1)

    f = pow(f, d)
    for i in range(d + 1, 2 * d + 1):
        sum_f += f[i]

    print(res * sum_f)

if __name__ == "__main__":
    main()
