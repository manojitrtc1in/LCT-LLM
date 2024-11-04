import math
import sys
from collections import defaultdict

EPS = 1e-9
PI = math.atan(1) * 4
M = 1000000007

class PT:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __add__(self, p):
        return PT(self.x + p.x, self.y + p.y)

    def __sub__(self, p):
        return PT(self.x - p.x, self.y - p.y)

    def __mul__(self, c):
        return PT(self.x * c, self.y * c)

    def __truediv__(self, c):
        return PT(self.x / c, self.y / c)

def dot(p, q):
    return p.x * q.x + p.y * q.y

def dist2(p, q):
    return dot(p - q, p - q)

def cross(p, q):
    return p.x * q.y - p.y * q.x

def cos_u2v(u, v):
    return dot(u, v) / math.sqrt(dot(u, u) * dot(v, v))

def sin_u2v(u, v):
    return cross(u, v) / math.sqrt(dot(u, u) * dot(v, v))

def vector2angle(v):
    return math.atan2(v.y, v.x)

class UnionFind:
    def __init__(self, n):
        self.C = [i for i in range(n)]

    def find(self, x):
        if self.C[x] == x:
            return x
        self.C[x] = self.find(self.C[x])
        return self.C[x]

    def merge(self, x, y):
        self.C[self.find(x)] = self.find(y)

def mod(x, m):
    return ((x % m) + m) % m

def gcd(a, b):
    while b > 0:
        a %= b
        a, b = b, a
    return a

def extended_euclid(a, b, x, y):
    xx = y = 0
    yy = x = 1
    while b:
        q = a // b
        t = b
        b = a % b
        a = t
        t = xx
        xx = x - q * xx
        x = t
        t = yy
        yy = y - q * yy
        y = t
    return a

def mod_inverse(a, n):
    x, y = 0, 0
    d = extended_euclid(a, n, x, y)
    if d > 1:
        return -1
    return mod(x, n)

class LPSolver:
    def __init__(self, A, b, c):
        self.m = len(b)
        self.n = len(c)
        self.N = [i for i in range(self.n + 1)]
        self.B = [i for i in range(self.m)]
        self.D = [[A[i][j] for j in range(self.n)] for i in range(self.m)]
        for i in range(self.m):
            self.B[i] = self.n + i
            self.D[i][self.n] = -1
            self.D[i][self.n + 1] = b[i]
        for j in range(self.n):
            self.N[j] = j
            self.D[self.m][j] = -c[j]
        self.N[self.n] = -1
        self.D[self.m + 1][self.n] = 1

    def pivot(self, r, s):
        for i in range(self.m + 2):
            if i != r:
                for j in range(self.n + 2):
                    if j != s:
                        self.D[i][j] -= self.D[r][j] * self.D[i][s] / self.D[r][s]
        for j in range(self.n + 2):
            if j != s:
                self.D[r][j] /= self.D[r][s]
        for i in range(self.m + 2):
            if i != r:
                self.D[i][s] /= -self.D[r][s]
        self.D[r][s] = 1.0 / self.D[r][s]
        self.B[r], self.N[s] = self.N[s], self.B[r]

    def simplex(self, phase):
        x = self.m + 1 if phase == 1 else self.m
        while True:
            s = -1
            for j in range(self.n + 1):
                if phase == 2 and self.N[j] == -1:
                    continue
                if s == -1 or self.D[x][j] < self.D[x][s] or (self.D[x][j] == self.D[x][s] and self.N[j] < self.N[s]):
                    s = j
            if self.D[x][s] > -EPS:
                return True
            r = -1
            for i in range(self.m):
                if self.D[i][s] < EPS:
                    continue
                if r == -1 or self.D[i][self.n + 1] / self.D[i][s] < self.D[r][self.n + 1] / self.D[r][s] or (self.D[i][self.n + 1] / self.D[i][s]) == (self.D[r][self.n + 1] / self.D[r][s]) and self.B[i] < self.B[r]:
                    r = i
            if r == -1:
                return False
            self.pivot(r, s)

    def solve(self, x):
        r = 0
        for i in range(1, self.m):
            if self.D[i][self.n + 1] < self.D[r][self.n + 1]:
                r = i
        if self.D[r][self.n + 1] < -EPS:
            self.pivot(r, self.n)
            if not self.simplex(1) or self.D[self.m + 1][self.n + 1] < -EPS:
                return -sys.float_info.max
            for i in range(self.m):
                if self.B[i] == -1:
                    s = -1
                    for j in range(self.n):
                        if s == -1 or self.D[i][j] < self.D[i][s] or self.D[i][j] == self.D[i][s] and self.N[j] < self.N[s]:
                            s = j
                    self.pivot(i, s)
        if not self.simplex(2):
            return sys.float_info.max
        x = [0] * self.n
        for i in range(self.m):
            if self.B[i] < self.n:
                x[self.B[i]] = self.D[i][self.n + 1]
        return self.D[self.m][self.n + 1]

def edgelist2adjlists(n, froms, tos, v2e0, e2n):
    v2e0 = [-1] * n
    e2n = []
    for i in range(len(froms)):
        f = froms[i]
        t = tos[i]
        e2n.append(v2e0[f])
        v2e0[f] = i

class FordFulk:
    def __init__(self, v2e0, e2f, e2t, e2c, e2n, s, t):
        self.v2e0 = v2e0
        self.e2f = e2f
        self.e2t = e2t
        self.e2c = e2c
        self.e2n = e2n
        self.s = s
        self.t = t

    def _find_aug_path(self, v2e0, e2f, e2t, e2c, e2n, s, t, epath):
        q2v = []
        q2p = []
        q2e = []
        q2f = []
        inq = [False] * len(v2e0)

        q2v.append(s)
        q2p.append(-1)
        q2e.append(-1)
        q2f.append(sys.maxsize)
        inq[s] = True
        for i in range(len(q2v)):
            crt = q2v[i]
            f = q2f[i]
            for j in range(v2e0[crt], -1, e2n[j]):
                to = e2t[j]
                rem = e2c[j]
                if inq[to]:
                    continue
                if rem <= 0:
                    continue
                q2v.append(to)
                q2p.append(i)
                q2e.append(j)
                q2f.append(min(f, rem))
                inq[to] = True

        for i in range(len(q2v)):
            if q2v[i] != t:
                continue
            stk = []
            for j in range(i, 0, q2p[j]):
                stk.append(q2e[j])
            while stk:
                epath.append(stk.pop())
            return q2f[i]
        return 0

    def eval(self):
        en = len(self.e2f)
        rsd = defaultdict(int)
        for i in range(en):
            f = self.e2f[i]
            t = self.e2t[i]
            rsd[(f, t)] += self.e2c[i]
            rsd[(t, f)] += 0
        nei = {}
        ren = 0
        for er in rsd:
            nei[er] = ren
            ren += 1
        rvn = len(self.v2e0)
        rv2e0 = [-1] * rvn
        re2f = [0] * ren
        re2t = [0] * ren
        re2c = [0] * ren
        re2n = [0] * ren
        re2p = [0] * ren
        rei = 0
        for er in rsd:
            f = er[0]
            t = er[1]
            c = rsd[er]
            re2f[rei] = f
            re2t[rei] = t
            re2c[rei] = c
            re2p[rei] = nei[(t, f)]
            re2n[rei] = rv2e0[f]
            rv2e0[f] = rei
            rei += 1
        sol = 0
        epath = []
        while True:
            epath.clear()
            res = self._find_aug_path(rv2e0, re2f, re2t, re2c, re2n, self.s, self.t, epath)
            if res == 0:
                break
            for ei in epath:
                re2c[ei] -= res
                re2c[re2p[ei]] += res
            sol += res
        return sol

def edgelist2adjlists(n, froms, tos, v2e0, e2n):
    v2e0 = [-1] * n
    e2n = []
    for i in range(len(froms)):
        f = froms[i]
        t = tos[i]
        e2n.append(v2e0[f])
        v2e0[f] = i

def vector2angle(v):
    return math.atan2(v.y, v.x)

def opp(a, b):
    return (a == 'W' and b == 'E') or (a == 'E' and b == 'W') or (a == 'S' and b == 'N') or (a == 'N' and b == 'S')

def ccinv(x):
    if x == 'N':
        return 'S'
    if x == 'S':
        return 'N'
    if x == 'W':
        return 'E'
    if x == 'E':
        return 'W'
    return 'W'

def main():
    r = input()
    a = input()
    b = input()
    n = len(a)
    ar = a[::-1]
    for i in range(n):
        ar[i] = ccinv(ar[i])
    va = 0
    vb = 0
    p = 1
    for i in range(n):
        va = (va * 131 + ar[i]) % M
        vb = (vb + b[n - 1 - i] * p) % M
        p = (p * 131) % M
        if vb == va:
            print("NO")
            return
    print("YES")

if __name__ == "__main__":
    main()
