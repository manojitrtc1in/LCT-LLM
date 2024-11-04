import sys
from typing import List, Tuple
from fractions import Fraction

MOD = 998244353

class ModInt:
    def __init__(self, x: int = 0):
        self.x = x % MOD

    def __add__(self, other: 'ModInt') -> 'ModInt':
        return ModInt((self.x + other.x) % MOD)

    def __sub__(self, other: 'ModInt') -> 'ModInt':
        return ModInt((self.x - other.x + MOD) % MOD)

    def __mul__(self, other: 'ModInt') -> 'ModInt':
        return ModInt((self.x * other.x) % MOD)

    def __pow__(self, n: int) -> 'ModInt':
        if n == 0:
            return ModInt(1)
        elif n % 2 == 0:
            return (self * self) ** (n // 2)
        else:
            return self * (self * self) ** (n // 2)

    def __str__(self) -> str:
        return str(self.x)

    def __repr__(self) -> str:
        return str(self.x)

class Matrix:
    def __init__(self, n: int):
        self.n = n
        self.A = [[ModInt(0)] * n for _ in range(n)]

    def __getitem__(self, i: int) -> List[ModInt]:
        return self.A[i]

    def __setitem__(self, i: int, value: List[ModInt]) -> None:
        self.A[i] = value

    @staticmethod
    def identity(n: int) -> 'Matrix':
        mat = Matrix(n)
        for i in range(n):
            mat[i][i] = ModInt(1)
        return mat

    def __mul__(self, other: 'Matrix') -> 'Matrix':
        n = self.n
        m = other.n
        p = len(other[0])
        res = Matrix(n)
        for i in range(n):
            for j in range(p):
                for k in range(m):
                    res[i][j] += self[i][k] * other[k][j]
        return res

    def __pow__(self, k: int) -> 'Matrix':
        res = Matrix.identity(self.n)
        while k > 0:
            if k & 1:
                res *= self
            self *= self
            k >>= 1
        return res

def solve(N: int, X: List[int], V: List[int], P: List[int]) -> ModInt:
    Q = [ModInt(1) - ModInt(p) for p in P]
    ev = {}
    for i in range(1, N):
        if V[i - 1] < V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i - 1] - V[i])].append((i, 0))
        ev[Fraction(X[i] - X[i - 1], V[i - 1] + V[i])].append((i, 2))
        if V[i - 1] > V[i]:
            ev[Fraction(X[i - 1] - X[i], V[i] - V[i - 1])].append((i, 1))

    e = Matrix.identity(4)
    seg = [e] * N
    for i in range(N):
        u = Matrix(e)
        u[0][0] = Q[i]
        u[1][0] = Q[i]
        u[2][2] = Q[i]
        u[3][2] = Q[i]
        u[0][1] = P[i]
        u[1][1] = P[i]
        u[2][3] = P[i]
        u[3][3] = P[i]
        seg[i] = u

    ret = ModInt(0)
    for p, vs in ev.items():
        for tt in vs:
            now = seg[tt[0]]
            if tt[1] == 0:
                now[0][0] = ModInt(0)
                now[0][2] = Q[tt[0]]
            elif tt[1] == 1:
                now[1][1] = ModInt(0)
                now[1][3] = P[tt[0]]
            else:
                now[1][0] = ModInt(0)
                now[1][2] = Q[tt[0]]
            seg[tt[0]] = now

        uku = seg[1]
        sum = uku[0][2] + uku[0][3]
        ret += ModInt(p.numerator) // ModInt(p.denominator) * sum

        for tt in vs:
            now = seg[tt[0]]
            if tt[1] == 0:
                now[0][2] = ModInt(0)
                now[2][2] = ModInt(0)
            elif tt[1] == 1:
                now[1][3] = ModInt(0)
                now[3][3] = ModInt(0)
            else:
                now[1][2] = ModInt(0)
                now[3][2] = ModInt(0)
            seg[tt[0]] = now

    return ret

def main() -> None:
    N = int(input())
    X = list(map(int, input().split()))
    V = list(map(int, input().split()))
    P = list(map(int, input().split()))
    ans = solve(N, X, V, P)
    print(ans)

if __name__ == '__main__':
    main()
