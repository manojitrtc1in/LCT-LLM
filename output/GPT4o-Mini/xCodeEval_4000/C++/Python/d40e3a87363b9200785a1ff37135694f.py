from fractions import Fraction
from collections import defaultdict
import sys

mod = 998244353

class ModInt:
    def __init__(self, y=0):
        self.x = y % mod if y >= 0 else (mod - (-y % mod)) % mod

    def __add__(self, other):
        return ModInt(self.x + other.x)

    def __sub__(self, other):
        return ModInt(self.x + mod - other.x)

    def __mul__(self, other):
        return ModInt(self.mul(self.x, other.x))

    def __truediv__(self, other):
        return self * other.inverse()

    def __neg__(self):
        return ModInt(-self.x)

    def __eq__(self, other):
        return self.x == other.x

    def __ne__(self, other):
        return self.x != other.x

    def inverse(self):
        a, b, u, v = self.x, mod, 1, 0
        while b > 0:
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v
        return ModInt(u)

    def pow(self, n):
        ret = ModInt(1)
        mul = ModInt(self.x)
        while n > 0:
            if n & 1:
                ret *= mul
            mul *= mul
            n >>= 1
        return ret

    @staticmethod
    def mul(a, b):
        return (a * b) % mod

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

    def __getitem__(self, k):
        return self.A[k]

    def __add__(self, other):
        return self.__class__(self) += other

    def __sub__(self, other):
        return self.__class__(self) -= other

    def __mul__(self, other):
        n, m, p = len(self.A), len(other.A[0]), len(self.A[0])
        C = [[ModInt() for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                for k in range(p):
                    C[i][j] += self[i][k] * other[k][j]
        self.A = C
        return self

    def __iadd__(self, other):
        for i in range(4):
            for j in range(4):
                self.A[i][j] += other[i][j]
        return self

    def __isub__(self, other):
        for i in range(4):
            for j in range(4):
                self.A[i][j] -= other[i][j]
        return self

    def __imul__(self, other):
        return self.__mul__(other)

    def __repr__(self):
        return '\n'.join(['[' + ', '.join(map(str, row)) + ']' for row in self.A])

class SegmentTree:
    def __init__(self, n, f, M1):
        self.sz = 1
        while self.sz < n:
            self.sz <<= 1
        self.seg = [M1] * (2 * self.sz)
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
            k //= 2
            self.seg[k] = self.f(self.seg[2 * k], self.seg[2 * k + 1])

    def query(self, a, b):
        L, R = self.M1, self.M1
        a += self.sz
        b += self.sz
        while a < b:
            if a & 1:
                L = self.f(L, self.seg[a])
                a += 1
            if b & 1:
                b -= 1
                R = self.f(self.seg[b], R)
            a //= 2
            b //= 2
        return self.f(L, R)

def main():
    N = int(input())
    X, V, P = [], [], []
    for _ in range(N):
        x, v, p = map(int, input().split())
        X.append(x)
        V.append(v)
        P.append(ModInt(p) / ModInt(100))

    Q = [ModInt(1) - p for p in P]
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
        ret += ModInt(p.numerator) / p.denominator * sum_

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
