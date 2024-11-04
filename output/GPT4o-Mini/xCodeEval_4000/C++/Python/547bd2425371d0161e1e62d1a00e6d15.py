import sys
from collections import defaultdict
from fractions import Fraction

mod = 998244353

class ModInt:
    def __init__(self, x=0):
        self.x = x % mod

    def __add__(self, other):
        return ModInt(self.x + other.x)

    def __sub__(self, other):
        return ModInt(self.x - other.x)

    def __mul__(self, other):
        return ModInt(self.x * other.x)

    def __truediv__(self, other):
        return self * other.inverse()

    def inverse(self):
        return self.pow(mod - 2)

    def pow(self, n):
        result = ModInt(1)
        base = self
        while n > 0:
            if n & 1:
                result *= base
            base *= base
            n >>= 1
        return result

    def __repr__(self):
        return str(self.x)

class Matrix:
    def __init__(self):
        self.A = [[ModInt() for _ in range(4)] for _ in range(4)]

    @staticmethod
    def I():
        mat = Matrix()
        for i in range(4):
            mat.A[i][i] = ModInt(1)
        return mat

    def __mul__(self, other):
        C = Matrix()
        for i in range(4):
            for j in range(4):
                for k in range(4):
                    C.A[i][j] += self.A[i][k] * other.A[k][j]
        return C

    def __getitem__(self, idx):
        return self.A[idx]

class SegmentTree:
    def __init__(self, n, f, M1):
        self.sz = 1
        while self.sz < n:
            self.sz <<= 1
        self.seg = [M1 for _ in range(2 * self.sz)]
        self.f = f
        self.M1 = M1

    def set(self, k, x):
        self.seg[k + self.sz] = x

    def build(self):
        for k in range(self.sz - 1, 0, -1):
            self.seg[k] = self.f(self.seg[2 * k], self.seg[2 * k + 1])

    def update(self, k, x):
        k += self.sz
        self.seg[k] = x
        while k > 1:
            k >>= 1
            self.seg[k] = self.f(self.seg[2 * k], self.seg[2 * k + 1])

    def query(self, a, b):
        L = self.M1
        R = self.M1
        a += self.sz
        b += self.sz
        while a < b:
            if a & 1:
                L = self.f(L, self.seg[a])
                a += 1
            if b & 1:
                b -= 1
                R = self.f(self.seg[b], R)
            a >>= 1
            b >>= 1
        return self.f(L, R)

def main():
    N = int(sys.stdin.readline().strip())
    X = []
    V = []
    P = []
    Q = []
    
    for _ in range(N):
        x, v, p = map(int, sys.stdin.readline().strip().split())
        X.append(x)
        V.append(v)
        P.append(ModInt(p) / ModInt(100))
        Q.append(ModInt(1) - P[-1])

    ev = defaultdict(list)
    for i in range(1, N):
        if V[i - 1] < V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i - 1] - V[i])].append((i, 0))
        ev[Fraction(X[i] - X[i - 1], V[i - 1] + V[i])].append((i, 2))
        if V[i - 1] > V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i] - V[i - 1])].append((i, 1))

    Mat = Matrix
    e = Mat.I()
    f = lambda a, b: a * b

    seg = SegmentTree(N, f, e)
    for i in range(N):
        u = Mat()
        u[0][0] = Q[i]
        u[1][0] = Q[i]
        u[2][2] = Q[i]
        u[3][2] = Q[i]
        u[0][1] = P[i]
        u[1][1] = P[i]
        u[2][3] = P[i]
        u[3][3] = P[i]
        seg.set(i, u)
    seg.build()

    ret = ModInt(0)

    for p, vs in ev.items():
        for tt in vs:
            now = seg.seg[tt[0]]
            if tt[1] == 0:
                now[0][0] = ModInt(0)
                now[0][2] = Q[tt[0]]
            elif tt[1] == 1:
                now[1][1] = ModInt(0)
                now[1][3] = P[tt[0]]
            else:
                now[1][0] = ModInt(0)
                now[1][2] = Q[tt[0]]
            seg.update(tt[0], now)

        uku = seg.seg[1]
        sum_ = uku[0][2] + uku[0][3]
        ret += ModInt(p.numerator) / ModInt(p.denominator) * sum_

        for tt in vs:
            now = seg.seg[tt[0]]
            if tt[1] == 0:
                now[0][2] = ModInt(0)
                now[2][2] = ModInt(0)
            elif tt[1] == 1:
                now[1][3] = ModInt(0)
                now[3][3] = ModInt(0)
            else:
                now[1][2] = ModInt(0)
                now[3][2] = ModInt(0)
            seg.update(tt[0], now)

    print(ret)

if __name__ == "__main__":
    main()
