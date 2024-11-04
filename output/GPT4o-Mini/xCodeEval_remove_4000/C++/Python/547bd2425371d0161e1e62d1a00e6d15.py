from fractions import Fraction
from collections import defaultdict
import sys
import math

mod = 998244353

class Matrix:
    def __init__(self, n):
        self.A = [[0] * 4 for _ in range(4)]
        if n:
            for i in range(n):
                self.A[i][i] = 1

    def __getitem__(self, k):
        return self.A[k]

    def __mul__(self, B):
        C = Matrix(0)
        for i in range(4):
            for j in range(4):
                for k in range(4):
                    C[i][j] += self.A[i][k] * B[k][j]
                    C[i][j] %= mod
        return C

    def pow(self, k):
        B = Matrix(4)
        while k > 0:
            if k & 1:
                B = B * self
            self = self * self
            k >>= 1
        return B

    def __str__(self):
        return '\n'.join(['[' + ', '.join(map(str, row)) + ']' for row in self.A])

def main():
    N = int(sys.stdin.readline().strip())
    X, V, P, Q = [], [], [], []
    for _ in range(N):
        x, v, p = map(int, sys.stdin.readline().strip().split())
        X.append(x)
        V.append(v)
        P.append(Fraction(p, 100))
        Q.append(1 - P[-1])

    ev = defaultdict(list)
    for i in range(1, N):
        if V[i - 1] < V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i - 1] - V[i])].append((i, 0))
        ev[Fraction(X[i] - X[i - 1], V[i - 1] + V[i])].append((i, 2))
        if V[i - 1] > V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i] - V[i - 1])].append((i, 1))

    seg = [Matrix(0) for _ in range(2 * N)]
    for i in range(N):
        u = Matrix(0)
        u[0][0] = Q[i]
        u[1][0] = Q[i]
        u[2][2] = Q[i]
        u[3][2] = Q[i]
        u[0][1] = P[i]
        u[1][1] = P[i]
        u[2][3] = P[i]
        u[3][3] = P[i]
        seg[i + N] = u

    for i in range(N - 1, 0, -1):
        seg[i] = seg[2 * i] * seg[2 * i + 1]

    ret = 0

    for p in ev:
        vs = ev[p]
        for tt in vs:
            now = seg[tt[0] + N]
            if tt[1] == 0:
                now[0][0] = 0
                now[0][2] = Q[tt[0]]
            elif tt[1] == 1:
                now[1][1] = 0
                now[1][3] = P[tt[0]]
            else:
                now[1][0] = 0
                now[1][2] = Q[tt[0]]
            seg[tt[0] + N] = now

        uku = seg[1]
        sum_ = (uku[0][2] + uku[0][3]) % mod
        ret += (p.numerator * sum_) // p.denominator
        for tt in vs:
            now = seg[tt[0] + N]
            if tt[1] == 0:
                now[0][2] = 0
                now[2][2] = 0
            elif tt[1] == 1:
                now[1][3] = 0
                now[3][3] = 0
            else:
                now[1][2] = 0
                now[3][2] = 0
            seg[tt[0] + N] = now

    print(ret)

if __name__ == "__main__":
    main()
