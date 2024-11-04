from fractions import Fraction
from collections import defaultdict
import sys
import math

mod = 998244353

class Matrix:
    def __init__(self, n):
        self.A = [[0] * 4 for _ in range(4)]
        for i in range(n):
            self.A[i][i] = 1

    def __getitem__(self, k):
        return self.A[k]

    def __mul__(self, B):
        C = [[0] * 4 for _ in range(4)]
        for i in range(4):
            for j in range(4):
                for k in range(4):
                    C[i][j] += self.A[i][k] * B[k][j]
        return Matrix(4).set_matrix(C)

    def set_matrix(self, C):
        self.A = C
        return self

    @staticmethod
    def I(n):
        return Matrix(n)

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
    input = sys.stdin.read
    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1
    X = [0] * N
    V = [0] * N
    P = [0] * N
    Q = [0] * N

    for i in range(N):
        X[i] = int(data[idx])
        V[i] = int(data[idx + 1])
        P[i] = Fraction(int(data[idx + 2]), 100)
        Q[i] = 1 - P[i]
        idx += 3

    ev = defaultdict(list)
    for i in range(1, N):
        if V[i - 1] < V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i - 1] - V[i])].append((i, 0))
        ev[Fraction(X[i] - X[i - 1], V[i - 1] + V[i])].append((i, 2))
        if V[i - 1] > V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i] - V[i - 1])].append((i, 1))

    e = Matrix(4)
    f = lambda a, b: a * b
    seg = SegmentTree(N, f, e)

    for i in range(N):
        u = Matrix(4)
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

    ret = Fraction(0)

    for p in ev:
        vs = ev[p]
        for tt in vs:
            now = seg.seg[tt[0]]
            if tt[1] == 0:
                now[0][0] = 0
                now[0][2] = Q[tt[0]]
            elif tt[1] == 1:
                now[1][1] = 0
                now[1][3] = P[tt[0]]
            else:
                now[1][0] = 0
                now[1][2] = Q[tt[0]]
            seg.update(tt[0], now)

        uku = seg.seg[1]
        sum_ = uku[0][2] + uku[0][3]
        ret += Fraction(p.numerator, p.denominator) * sum_
        
        for tt in vs:
            now = seg[tt[0]]
            if tt[1] == 0:
                now[0][2] = 0
                now[2][2] = 0
            elif tt[1] == 1:
                now[1][3] = 0
                now[3][3] = 0
            else:
                now[1][2] = 0
                now[3][2] = 0
            seg.update(tt[0], now)

    print(float(ret))

if __name__ == "__main__":
    main()
