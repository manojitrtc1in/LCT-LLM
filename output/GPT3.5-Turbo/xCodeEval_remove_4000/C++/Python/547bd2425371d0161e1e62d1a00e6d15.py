import math

mod = 998244353
infll = (1 << 62) - 1
inf = (1 << 30) - 1

class IoSetup:
    def __init__(self):
        cin.tie(None)
        ios.sync_with_stdio(False)
        print("{:.10f}".format)
        print("{:.10f}".format)

def operator<<(os, p):
    os << p.first << " " << p.second
    return os

def operator>>(is, p):
    is >> p.first >> p.second
    return is

def operator<<(os, v):
    for i in range(len(v)):
        os << v[i] << (" " if i + 1 != len(v) else "")
    return os

def operator>>(is, v):
    for in in v:
        is >> in
    return is

def chmax(a, b):
    return a < b and (a = b, True)

def chmin(a, b):
    return a > b and (a = b, True)

def make_v(a):
    return [0] * a

def make_v(a, *ts):
    return [make_v(*ts) for _ in range(a)]

def fill_v(t, v):
    t = v

def fill_v(t, v):
    for e in t:
        fill_v(e, v)

class FixPoint:
    def __init__(self, f):
        self.f = f

    def __call__(self, *args):
        return self.f(self, *args)

def MFP(f):
    return FixPoint(f)

def mul_inv(n, e = 5, x = 1):
    return x if e == 0 else mul_inv(n, e - 1, x * (2 - x * n))

class ModInt:
    def __init__(self, x):
        self.x = self.reduce(x)

    def reduce(self, w):
        return (w >> 32) + mod - ((u64(u32(w) * inv) * mod) >> 32)

    def __iadd__(self, p):
        if int(self.x += p.x - 2 * mod) < 0:
            self.x += 2 * mod
        return self

    def __isub__(self, p):
        if int(self.x -= p.x) < 0:
            self.x += 2 * mod
        return self

    def __imul__(self, p):
        self.x = self.reduce(uint64_t(self.x) * p.x)
        return self

    def __idiv__(self, p):
        self *= p.inverse()
        return self

    def __add__(self, p):
        return ModInt(self) += p

    def __sub__(self, p):
        return ModInt(self) -= p

    def __mul__(self, p):
        return ModInt(self) *= p

    def __div__(self, p):
        return ModInt(self) /= p

    def __eq__(self, p):
        return self.get() == p.get()

    def __ne__(self, p):
        return self.get() != p.get()

    def get(self):
        return self.reduce(self.x) % mod

    def pow(self, n):
        ret = ModInt(1)
        mul = ModInt(self)
        while n > 0:
            if n & 1:
                ret *= mul
            mul *= mul
            n >>= 1
        return ret

    def inverse(self):
        return self.pow(mod - 2)

    def __str__(self):
        return str(self.get())

    def __int__(self):
        return self.get()

    def __long__(self):
        return self.get()

    def __float__(self):
        return float(self.get())

    def __complex__(self):
        return complex(self.get())

    def __hash__(self):
        return hash(self.get())

    def __index__(self):
        return self.get()

    def __repr__(self):
        return repr(self.get())

def operator<<(os, p):
    return os << p.get()

def operator>>(is, a):
    t = int64_t()
    is >> t
    a = ModInt< mod >(t)
    return is

def get_mod():
    return mod

modint = ModInt< mod >

class fraction:
    def __init__(self, n, d):
        self.num = n
        self.dom = d
        assert self.dom != 0
        if self.dom < 0:
            self.num *= -1
            self.dom *= -1
        tmp = math.gcd(abs(self.num), abs(self.dom))
        self.num //= tmp
        self.dom //= tmp

    def __add__(self, a):
        return fraction(self.num * a.dom + a.num * self.dom, self.dom * a.dom)

    def __sub__(self, a):
        return fraction(self.num * a.dom - a.num * self.dom, self.dom * a.dom)

    def __mul__(self, a):
        return fraction(self.num * a.num, self.dom * a.dom)

    def __div__(self, a):
        return fraction(self.num * a.dom, self.dom * a.num)

    def __mul__(self, k):
        return fraction(self.num * k, self.dom)

    def __div__(self, k):
        return fraction(self.num, self.dom * k)

    def __lt__(self, a):
        return self.num * a.dom < a.num * self.dom

    def __gt__(self, a):
        return self.num * a.dom > a.num * self.dom

    def __eq__(self, a):
        return self.num * a.dom == a.num * self.dom

    def __ne__(self, a):
        return self.num * a.dom != a.num * self.dom

    def __le__(self, a):
        return self.num * a.dom <= a.num * self.dom

    def __ge__(self, a):
        return self.num * a.dom >= a.num * self.dom

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
            self.seg[k] = self.f(self.seg[2 * k + 0], self.seg[2 * k + 1])

    def update(self, k, x):
        k += self.sz
        self.seg[k] = x
        while k >>= 1:
            self.seg[k] = self.f(self.seg[2 * k + 0], self.seg[2 * k + 1])

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
                R = self.f(self.seg[b - 1], R)
            a >>= 1
            b >>= 1
        return self.f(L, R)

    def __getitem__(self, k):
        return self.seg[k + self.sz]

    def id0(self, a, check, M, type):
        while a < self.sz:
            nxt = self.f(self.seg[2 * a + type], M) if type else self.f(M, self.seg[2 * a + type])
            if check(nxt):
                a = 2 * a + type
            else:
                M = nxt
                a = 2 * a + 1 - type
        return a - self.sz

    def find_first(self, a, check):
        L = self.M1
        if a <= 0:
            if check(self.f(L, self.seg[1])):
                return self.id0(1, check, L, False)
            return -1
        b = self.sz
        a += self.sz
        b += self.sz
        while a < b:
            if a & 1:
                nxt = self.f(L, self.seg[a])
                if check(nxt):
                    return self.id0(a, check, L, False)
                L = nxt
                a += 1
            a >>= 1
            b >>= 1
        return -1

    def find_last(self, b, check):
        R = self.M1
        if b >= self.sz:
            if check(self.f(self.seg[1], R)):
                return self.id0(1, check, R, True)
            return -1
        a = self.sz
        b += self.sz
        while a < b:
            if b & 1:
                nxt = self.f(self.seg[b - 1], R)
                if check(nxt):
                    return self.id0(b, check, R, True)
                R = nxt
            b >>= 1
        return -1

class Matrix:
    def __init__(self, n):
        self.A = [[0] * 4 for _ in range(4)]

    def height(self):
        return len(self.A)

    def width(self):
        return len(self.A[0])

    def __getitem__(self, k):
        return self.A[k]

    def __setitem__(self, k, v):
        self.A[k] = v

    @staticmethod
    def I(n):
        mat = Matrix(n)
        for i in range(n):
            mat[i][i] = 1
        return mat

    def __iadd__(self, B):
        n = self.height()
        m = self.width()
        assert n == B.height() and m == B.width()
        for i in range(n):
            for j in range(m):
                self[i][j] += B[i][j]
        return self

    def __isub__(self, B):
        n = self.height()
        m = self.width()
        assert n == B.height() and m == B.width()
        for i in range(n):
            for j in range(m):
                self[i][j] -= B[i][j]
        return self

    def __imul__(self, B):
        n = self.height()
        m = B.width()
        p = self.width()
        assert p == B.height()
        C = [[0] * 4 for _ in range(4)]
        for i in range(n):
            for j in range(m):
                for k in range(p):
                    C[i][j] = (C[i][j] + self[i][k] * B[k][j])
        self.A = C
        return self

    def __pow__(self, k):
        B = Matrix.I(self.height())
        while k > 0:
            if k & 1:
                B *= self
            self *= self
            k >>= 1
        self.A = B.A
        return self

    def __add__(self, B):
        return Matrix(self) += B

    def __sub__(self, B):
        return Matrix(self) -= B

    def __mul__(self, B):
        return Matrix(self) *= B

    def __pow__(self, k):
        return Matrix(self) ^= k

    def __str__(self):
        n = self.height()
        m = self.width()
        res = ""
        for i in range(n):
            res += "["
            for j in range(m):
                res += str(self[i][j]) + ("]\n" if j + 1 == m else ",")
        return res

    def determinant(self):
        B = Matrix(self)
        assert self.width() == self.height()
        ret = 1
        for i in range(self.width()):
            idx = -1
            for j in range(i, self.width()):
                if B[j][i] != 0:
                    idx = j
            if idx == -1:
                return 0
            if i != idx:
                ret *= -1
                B[i], B[idx] = B[idx], B[i]
            ret *= B[i][i]
            vv = B[i][i]
            for j in range(self.width()):
                B[i][j] /= vv
            for j in range(i + 1, self.width()):
                a = B[j][i]
                for k in range(self.width()):
                    B[j][k] -= B[i][k] * a
        return ret

N = int(input())
X = [0] * N
V = [0] * N
P = [0] * N
Q = [0] * N
for i in range(N):
    X[i], V[i], P[i] = map(int, input().split())
    P[i] //= 100
    Q[i] = modint(1) - P[i]

ev = {}
for i in range(1, N):
    if V[i - 1] < V[i]:
        ev[fraction(X[i - 1] - X[i], V[i - 1] - V[i])].append((i, 0))
    ev[fraction(X[i] - X[i - 1], V[i - 1] + V[i])].append((i, 2))
    if V[i - 1] > V[i]:
        ev[fraction(X[i - 1] - X[i], V[i] - V[i - 1])].append((i, 1))

f = lambda a, b: a * b
seg = SegmentTree(N, f, Matrix.I(4))
for i in range(N):
    u = Matrix.I(4)
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
    uku = seg.seg[1]
    sum = uku[0][2] + uku[0][3]
    ret += modint(p.num) / p.dom * sum
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
