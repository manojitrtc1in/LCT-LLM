import sys
import math
from collections import defaultdict

def rep(n):
    return range(n)

def all(c):
    return c

def pb(x, c):
    c.append(x)

def chmin(x, y):
    return min(x, y)

def chmax(x, y):
    return max(x, y)

class ModInt:
    mod = 998244353

    def __init__(self, v=0):
        self.v = self.normS(v % self.mod + self.mod)

    @staticmethod
    def normS(x):
        return x if x < ModInt.mod else x - ModInt.mod

    def __add__(self, other):
        return ModInt(self.normS(self.v + other.v))

    def __sub__(self, other):
        return ModInt(self.normS(self.v + ModInt.mod - other.v))

    def __neg__(self):
        return ModInt(self.normS(ModInt.mod - self.v))

    def __mul__(self, other):
        return ModInt((self.v * other.v) % ModInt.mod)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        x, y = self.extgcd(self.v, self.mod)
        return ModInt(self.normS(x + self.mod))

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

    def __repr__(self):
        return str(self.v)

def fft(type, c):
    N = len(c)
    s = bsr(N)
    assert (1 << s) == N
    buf = [[0] * N for _ in range(30)]
    if not buf[s][0]:
        for i in range(N):
            buf[s][i] = complex(math.cos(2 * math.pi * i / N), math.sin(2 * math.pi * i / N))
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
    N = 2 << bsr(S - 1)
    a = [[0] * N for _ in range(2)]
    b = [[0] * N for _ in range(2)]
    for t in range(2):
        for i in range(len(x)):
            a[t][i] = complex((x[i].v >> (t * B)) & ((1 << B) - 1), 0)
        for i in range(len(y)):
            b[t][i] = complex((y[i].v >> (t * B)) & ((1 << B) - 1), 0)
        a[t] = fft(False, a[t])
        b[t] = fft(False, b[t])
    z = [ModInt(0)] * S
    c = [0] * N
    base = ModInt(1)
    for t in range(3):
        c = [0] * N
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
        if i >= self.size() and x.v == 0:
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

    def __repr__(self):
        if self.size() == 0:
            return "0"
        return " + ".join(f"{self.v[i]}x^{i}" for i in range(self.size()) if self.v[i] != ModInt(0))

    def mul_fft(self, r):
        ret = multiply_fft(self.v, r.v)
        return Poly(ret)

def InitFact(N):
    global fact, ifact
    fact = [ModInt(0)] * N
    ifact = [ModInt(0)] * N
    fact[0] = ModInt(1)
    for i in range(1, N):
        fact[i] = fact[i - 1] * ModInt(i)
    ifact[N - 1] = fact[N - 1].inv()
    for i in range(N - 2, -1, -1):
        ifact[i] = ifact[i + 1] * ModInt(i + 1)

def Choose(a, b):
    if b < 0 or a < b:
        return ModInt(0)
    return fact[a] * ifact[b] * ifact[a - b]

def solve(N):
    res = ModInt(0)
    for i in range(N + 1):
        if i == 0:
            for j in range(1, N + 1):
                res += ModInt(-1).pow(i + j) * Choose(N, j) * ModInt(3).pow(j + N * (N - j))
        else:
            res += ModInt(-1).pow(i) * Choose(N, i) * ((ModInt(3).pow(N - i) - ModInt(1)).pow(N) - ModInt(3).pow((N - i) * N)) * ModInt(3)
            res += ModInt(-1).pow(i) * Choose(N, i) * ModInt(3).pow(i + N * (N - i))
    return -res

def main():
    sys.stdin = open(0)
    input = sys.stdin.read
    data = input().strip().split()
    N = int(data[0])
    InitFact(2000010)
    print(solve(N))

if __name__ == "__main__":
    main()
