import sys
from typing import List, Tuple
from fractions import Fraction

sys.setrecursionlimit(10 ** 7)
INF = float('inf')
MOD = 998244353

def main() -> None:
    N = int(input())
    X = [0] * N
    V = [0] * N
    P = [0] * N
    Q = [0] * N
    for i in range(N):
        X[i], V[i], P[i] = map(int, input().split())
        P[i] //= 100
        Q[i] = 1 - P[i]

    ev = {}
    for i in range(1, N):
        if V[i - 1] < V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i - 1] - V[i])].append((i, 0))
        ev[Fraction(X[i] - X[i - 1], V[i - 1] + V[i])].append((i, 2))
        if V[i - 1] > V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i] - V[i - 1])].append((i, 1))

    class Matrix:
        def __init__(self, n: int) -> None:
            self.A = [[0] * 4 for _ in range(4)]
            for i in range(n):
                self.A[i][i] = 1

        def __getitem__(self, k: int) -> List[int]:
            return self.A[k]

        def __setitem__(self, k: int, value: List[int]) -> None:
            self.A[k] = value

        @staticmethod
        def I(n: int) -> 'Matrix':
            mat = Matrix(n)
            for i in range(n):
                mat[i][i] = 1
            return mat

        def __add__(self, B: 'Matrix') -> 'Matrix':
            C = Matrix(len(self.A))
            for i in range(len(self.A)):
                for j in range(len(self.A[0])):
                    C[i][j] = self[i][j] + B[i][j]
            return C

        def __sub__(self, B: 'Matrix') -> 'Matrix':
            C = Matrix(len(self.A))
            for i in range(len(self.A)):
                for j in range(len(self.A[0])):
                    C[i][j] = self[i][j] - B[i][j]
            return C

        def __mul__(self, B: 'Matrix') -> 'Matrix':
            C = Matrix(len(self.A))
            for i in range(len(self.A)):
                for j in range(len(B.A[0])):
                    for k in range(len(self.A[0])):
                        C[i][j] += self[i][k] * B[k][j]
            return C

        def __pow__(self, k: int) -> 'Matrix':
            B = Matrix.I(len(self.A))
            while k > 0:
                if k & 1:
                    B *= self
                self *= self
                k >>= 1
            self.A = B.A
            return self

        def determinant(self) -> int:
            B = Matrix(self)
            ret = 1
            for i in range(len(self.A)):
                idx = -1
                for j in range(i, len(self.A)):
                    if B[j][i] != 0:
                        idx = j
                if idx == -1:
                    return 0
                if i != idx:
                    ret *= -1
                    B[i], B[idx] = B[idx], B[i]
                ret *= B[i][i]
                vv = B[i][i]
                for j in range(len(self.A)):
                    B[i][j] /= vv
                for j in range(i + 1, len(self.A)):
                    a = B[j][i]
                    for k in range(len(self.A)):
                        B[j][k] -= B[i][k] * a
            return ret

    ret = 0
    for p, vs in ev.items():
        for tt in vs:
            now = seg[tt[0]]
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

        uku = seg[1]
        sum = uku[0][2] + uku[0][3]
        ret += p.numerator // p.denominator * sum

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

    print(ret)

if __name__ == '__main__':
    main()
