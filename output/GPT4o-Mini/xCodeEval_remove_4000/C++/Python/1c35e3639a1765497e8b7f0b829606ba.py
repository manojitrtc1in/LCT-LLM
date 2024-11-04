from math import gcd
from cmath import polar
from collections import defaultdict
from itertools import accumulate
from functools import reduce

class ModInt:
    def __init__(self, v=0, mod=998244353):
        self.mod = mod
        self.v = self.normS(v % mod + mod)

    def normS(self, x):
        return x if x < self.mod else x - self.mod

    def __add__(self, other):
        return ModInt(self.normS(self.v + other.v), self.mod)

    def __sub__(self, other):
        return ModInt(self.normS(self.v + self.mod - other.v), self.mod)

    def __neg__(self):
        return ModInt(self.normS(self.mod - self.v), self.mod)

    def __mul__(self, other):
        return ModInt((self.v * other.v) % self.mod, self.mod)

    def __truediv__(self, other):
        return self * other.inv()

    def __eq__(self, other):
        return self.v == other.v

    def __ne__(self, other):
        return self.v != other.v

    def inv(self):
        x, y = self.extgcd(self.v, self.mod)
        return ModInt(self.normS(x + self.mod), self.mod)

    def extgcd(self, a, b):
        p, q = [a, 1, 0], [b, 0, 1]
        while q[0]:
            t = p[0] // q[0]
            for i in range(3):
                p[i] -= t * q[i]
                p[i], q[i] = q[i], p[i]
        if p[0] < 0:
            for i in range(3):
                p[i] = -p[i]
        return p[1], p[2]

    def pow(self, p):
        if p < 0:
            return self.inv().pow(-p)
        a = ModInt(1, self.mod)
        x = self
        while p:
            if p & 1:
                a *= x
            x *= x
            p >>= 1
        return a

    def __str__(self):
        return str(self.v)

def fft(type, c):
    N = len(c)
    s = N.bit_length() - 1
    buf = [None] * 30
    if buf[s] is None:
        buf[s] = [polar(1, i * 2 * 3.141592653589793 / N) for i in range(N)]
    a = c[:]
    b = [0] * N
    for i in range(1, s + 1):
        W = 1 << (s - i)
        for y in range(0, N // 2, W):
            now = buf[s][y]
            if type:
                now = now.conjugate()
            for x in range(W):
                l = a[y << 1 | x]
                r = now * a[y << 1 | x | W]
                b[y | x] = l + r
                b[y | x | (N >> 1)] = l - r
        a, b = b, a
    return a

def multiply_fft(x, y):
    B = 15
    S = len(x) + len(y) - 1
    N = 2 << (S - 1).bit_length()
    a = [[0] * N for _ in range(2)]
    b = [[0] * N for _ in range(2)]
    for t in range(2):
        for i in range(len(x)):
            a[t][i] = complex((x[i].v >> (t * B)) & ((1 << B) - 1), 0)
        for i in range(len(y)):
            b[t][i] = complex((y[i].v >> (t * B)) & ((1 << B) - 1), 0)
        fft(False, a[t])
        fft(False, b[t])
    z = [ModInt(0) for _ in range(S)]
    c = [0] * N
    base = ModInt(1)
    for t in range(3):
        for i in range(N):
            c[i] = 0
        for xt in range(max(t - 1, 0), min(1, t) + 1):
            yt = t - xt
            for i in range(N):
                c[i] += a[xt][i] * b[yt][i]
        c = fft(True, c)
        for i in range(S):
            c[i] *= 1.0 / N
            z[i] += ModInt(round(c[i].real)) * base
        base *= (1 << B)
    return z

class Poly:
    def __init__(self, v=None):
        if v is None:
            self.v = []
        else:
            self.v = v
            self.shrink()

    def size(self):
        return len(self.v)

    def shrink(self):
        while self.v and self.v[-1] == ModInt(0):
            self.v.pop()
        return self

    def at(self, i):
        return self.v[i] if i < self.size() else ModInt(0)

    def set(self, i, x):
        if i >= self.size() and x == ModInt(0):
            return
        while i >= self.size():
            self.v.append(ModInt(0))
        self.v[i] = x
        self.shrink()

    def __add__(self, other):
        N = max(self.size(), other.size())
        ret = [self.at(i) + other.at(i) for i in range(N)]
        return Poly(ret)

    def __sub__(self, other):
        N = max(self.size(), other.size())
        ret = [self.at(i) - other.at(i) for i in range(N)]
        return Poly(ret)

    def __neg__(self):
        return Poly([-self.at(i) for i in range(self.size())])

    def __mul__(self, other):
        if self.size() == 0 or other.size() == 0:
            return Poly()
        return self.mul_fft(other)

    def __str__(self):
        if self.size() == 0:
            return "0"
        return " + ".join(f"{self.v[i]}x^{i}" for i in range(self.size()) if self.v[i] != ModInt(0))

    def mul_fft(self, r):
        ret = multiply_fft(self.v, r.v)
        return Poly(ret)

def extended(n, coeffs, terms):
    ret = [ModInt(0)] * max(n + 1, len(terms))
    for i in range(len(terms)):
        ret[i] = terms[i]
    order = len(coeffs) - 1
    deg = len(coeffs[0]) - 1
    assert len(terms) >= order
    for m in range(len(terms), n + 1):
        s = ModInt(0)
        for i in range(1, order + 1):
            k = m - i
            t = ret[k]
            for d in range(deg + 1):
                s += t * coeffs[i][d]
                t *= k
        denom = ModInt(0)
        mpow = ModInt(1)
        for d in range(deg + 1):
            denom += mpow * coeffs[0][d]
            mpow *= m
        ret[m] = -s / denom
    return ret

def id3(terms, deg, ord=-1, verify=True):
    if ord != -1:
        n = (deg + 1) * (ord + 1) + ord - 1
        while len(terms) > n:
            terms.pop()
    n = len(terms)
    B = (n + 2) // (deg + 2)
    C = B * (deg + 1)
    R = n - (B - 1)
    assert B >= 2
    assert R >= C - 1

    mat = [[ModInt(0) for _ in range(C)] for _ in range(R)]
    for y in range(R):
        for b in range(B):
            v = terms[y + b]
            for d in range(deg + 1):
                mat[y][b * (deg + 1) + d] = v
                v *= y + b

    rank = 0
    for x in range(C):
        pivot = -1
        for y in range(rank, R):
            if mat[y][x] != ModInt(0):
                pivot = y
                break
        if pivot < 0:
            break
        if pivot != rank:
            mat[rank], mat[pivot] = mat[pivot], mat[rank]
        inv = mat[rank][x].inv()
        for x2 in range(x, C):
            mat[rank][x2] *= inv
        for y in range(rank + 1, R):
            if mat[y][x] != ModInt(0):
                c = -mat[y][x]
                for x2 in range(x, C):
                    mat[y][x2] += c * mat[rank][x2]
        rank += 1

    if rank == C:
        raise ValueError("Error: Could not find a recurrence relation of order <= {} and degree <= {}.".format(B - 1, deg))

    for y in range(rank - 1, -1, -1):
        if mat[y][rank] != ModInt(0):
            assert mat[y][y] == ModInt(1)
            c = -mat[y][rank]
            for y2 in range(y):
                mat[y2][rank] += c * mat[y2][y]

    order = rank // (deg + 1)
    ret = [[ModInt(0) for _ in range(deg + 1)] for _ in range(order + 1)]
    ret[0][rank % (deg + 1)] = ModInt(1)
    for y in range(rank - 1, -1, -1):
        k = order - y // (deg + 1)
        d = y % (deg + 1)
        ret[k][d] = -mat[y][rank]

    if verify:
        extended_terms = extended(n - 1, ret, terms[:order])
        for i in range(len(terms)):
            if terms[i] != extended_terms[i]:
                raise ValueError("Error: Could not find a recurrence relation of order <= {} and degree <= {}.".format(B - 1, deg))

    return ret

def id1(n, terms, degree, order=-1):
    coeffs = id3(terms, degree, order)
    extended_terms = extended(n, coeffs, terms)
    for i in range(len(extended_terms)):
        print(i, extended_terms[i].v)
    print()

def main():
    N = int(input())
    print(f"{N:.20f}")
    InitFact(2000010)

    def solve(N):
        res = ModInt(0)
        for i in range(N + 1):
            if i == 0:
                for j in range(1, N + 1):
                    res += ModInt(-1).pow(i + j) * Choose(N, j) * ModInt(3).pow(j + N * (N - j))
            else:
                res += ModInt(-1).pow(i) * Choose(N, i) * ((ModInt(3).pow(N - i) - ModInt(1)).pow(N) - ModInt(3).pow((N - i) * N)) * 3
                res += ModInt(-1).pow(i) * Choose(N, i) * ModInt(3).pow(i + N * (N - i))
        return -res

    print(solve(N))

if __name__ == "__main__":
    main()
