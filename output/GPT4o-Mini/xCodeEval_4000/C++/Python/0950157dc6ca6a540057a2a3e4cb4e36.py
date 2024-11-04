from collections import defaultdict

MOD = 10007

class Mint32:
    def __init__(self, x=0):
        self.x = x % MOD

    def __add__(self, other):
        return Mint32(self.x + other.x)

    def __sub__(self, other):
        return Mint32(self.x - other.x)

    def __mul__(self, other):
        return Mint32(self.x * other.x)

    def __truediv__(self, other):
        return Mint32(self.x * pow(other.x, MOD - 2, MOD))

    def __repr__(self):
        return str(self.x)

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def power(x, p):
    if p == 0:
        return 1 % MOD
    if p == 1:
        return x % MOD
    res = power(x, p // 2)
    res = (res * res) % MOD
    if p & 1:
        res = (res * x) % MOD
    return res

def go(left, right, i):
    if i < 0:
        return Mint32(0)
    if i == 0 and left >= right:
        return Mint32(1)
    if (left, right, i) in memo:
        return memo[(left, right, i)]
    
    res = Mint32(0)

    if left >= right:
        res += go(left, right, max(i - 2, 0)) * Mint32(26)
    elif left + 1 == right:
        if i == 0:
            res += go(left + 1, right - 1, i)
        else:
            res += go(left + 1, right, i - 1)
        res += go(left, right, i - 2) * Mint32(25)
    else:
        if s[left] == s[right - 1]:
            res += go(left + 1, right - 1, i)
            res += go(left, right, i - 2) * Mint32(25)
        else:
            res += go(left + 1, right, i - 1)
            res += go(left, right - 1, i - 1)
            res += go(left, right, i - 2) * Mint32(24)

    memo[(left, right, i)] = res
    return res

s = input().strip()
n = int(input().strip())
memo = {}
base = [go(0, len(s), i) for i in range(10 * len(s))]

class BMSolver:
    def __init__(self):
        self.base = []
        self.T = []

    def solve(self, base):
        self.base = base
        n = len(base)
        C = [Mint32(1)]
        B = [Mint32(1)]
        b = Mint32(1)
        L = 0

        for i in range(n):
            d = Mint32(0)
            for j in range(len(C)):
                d += base[i - j] * C[j]
            if d.x == 0:
                continue
            if 2 * L <= i:
                tmp = C[:]
                if len(C) < len(B) + (i + 1):
                    C += [Mint32(0)] * (len(B) + (i + 1) - len(C))
                coef = d / b
                for j in range(len(B)):
                    C[j + (i + 1)] -= coef * B[j]
                L = i + 1 - L
                B = tmp
                b = d
            else:
                if len(C) < len(B) + (i + 1):
                    C += [Mint32(0)] * (len(B) + (i + 1) - len(C))
                coef = d / b
                for j in range(len(B)):
                    C[j + (i + 1)] -= coef * B[j]

        self.T = [-C[i + 1] for i in range(len(C) - 1)]

    def compute(self, K):
        res = Mint32(0)
        N = len(self.T)
        if K < len(self.base):
            for j in range(N):
                res += self.base[K + j] * self.T[j]
        return res

solver = BMSolver()
solver.solve(base)
print(solver.compute(n))
