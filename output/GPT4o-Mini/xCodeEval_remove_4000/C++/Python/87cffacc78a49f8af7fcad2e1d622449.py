import math
from collections import defaultdict
import sys
import random

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

def id22(u, v):
    return dot(u, v) / math.sqrt(dot(u, u) * dot(v, v))

def id6(u, v):
    return cross(u, v) / math.sqrt(dot(u, u) * dot(v, v))

def id17(v):
    return math.atan2(v.y, v.x)

class UnionFind:
    def __init__(self, n):
        self.C = list(range(n))

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
        a, b = b, a % b
    return a

def id11(a, b):
    x, y = 0, 1
    xx, yy = y, x
    while b:
        q = a // b
        a, b = b, a % b
        t = xx
        xx = x - q * xx
        x = t
        t = yy
        yy = y - q * yy
        y = t
    return a, x, y

def mod_inverse(a, n):
    d, x, y = id11(a, n)
    if d > 1:
        return -1
    return mod(x, n)

class id3:
    def __init__(self, A, b, c):
        self.m = len(b)
        self.n = len(c)
        self.N = list(range(self.n + 1))
        self.B = list(range(self.m))
        self.D = [[0] * (self.n + 2) for _ in range(self.m + 2)]
        for i in range(self.m):
            for j in range(self.n):
                self.D[i][j] = A[i][j]
        for i in range(self.m):
            self.B[i] = self.n + i
            self.D[i][self.n] = -1
            self.D[i][self.n + 1] = b[i]
        for j in range(self.n):
            self.N[j] = j
            self.D[self.m][j] = -c[j]
        self.N[self.n] = -1
        self.D[self.m + 1][self.n] = 1

    def Pivot(self, r, s):
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

    def Simplex(self, phase):
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
                if r == -1 or self.D[i][self.n + 1] / self.D[i][s] < self.D[r][self.n + 1] / self.D[r][s] or \
                   (self.D[i][self.n + 1] / self.D[i][s] == self.D[r][self.n + 1] / self.D[r][s] and self.B[i] < self.B[r]):
                    r = i
            if r == -1:
                return False
            self.Pivot(r, s)

    def solve(self, x):
        r = 0
        for i in range(1, self.m):
            if self.D[i][self.n + 1] < self.D[r][self.n + 1]:
                r = i
        if self.D[r][self.n + 1] < -EPS:
            self.Pivot(r, self.n)
            if not self.Simplex(1) or self.D[self.m + 1][self.n + 1] < -EPS:
                return -float('inf')
            for i in range(self.m):
                if self.B[i] == -1:
                    s = -1
                    for j in range(self.n + 1):
                        if s == -1 or self.D[i][j] < self.D[i][s] or (self.D[i][j] == self.D[i][s] and self.N[j] < self.N[s]):
                            s = j
                    self.Pivot(i, s)
        if not self.Simplex(2):
            return float('inf')
        x.clear()
        for i in range(self.m):
            if self.B[i] < self.n:
                x.append(self.D[i][self.n + 1])
        return self.D[self.m][self.n + 1]

def id8(n, froms, tos):
    id16 = [-1] * n
    en = len(froms)
    id4 = [0] * en
    for i in range(en):
        f = froms[i]
        t = tos[i]
        id4[i] = id16[f]
        id16[f] = i
    return id16, id4

class id18:
    def __init__(self, id23, id2, id26, id14, id5, _s, _t):
        self.s = _s
        self.t = _t
        self.id16 = id23
        self.id13 = id2
        self.id7 = id26
        self.id9 = id14
        self.id4 = id5

    def _find_aug_path(self, id16, id13, id7, id9, id4, s, t, epath):
        id24 = []
        id0 = []
        id21 = []
        id27 = []
        inq = [False] * len(id16)

        id24.append(s)
        id0.append(-1)
        id21.append(-1)
        id27.append(float('inf'))
        inq[s] = True
        for i in range(len(id24)):
            crt = id24[i]
            f = id27[i]
            for j in range(id16[crt], -1, -1):
                to = id7[j]
                rem = id9[j]
                if inq[to]:
                    continue
                if rem <= 0:
                    continue
                id24.append(to)
                id0.append(i)
                id21.append(j)
                id27.append(min(f, rem))
                inq[to] = True

        for i in range(len(id24)):
            if id24[i] != t:
                continue
            stk = []
            for j in range(i, 0, -1):
                stk.append(id21[j])
            while stk:
                epath.append(stk.pop())
            return id27[i]
        return 0

    def eval(self):
        en = len(self.id13)
        rsd = defaultdict(int)
        for i in range(en):
            f = self.id13[i]
            t = self.id7[i]
            rsd[(f, t)] += self.id9[i]
            rsd[(t, f)] += 0
        nei = {}
        ren = 0
        for er in rsd:
            nei[er] = ren
            ren += 1
        rvn = len(self.id16)
        id12 = [-1] * rvn
        id20 = [0] * ren

        id1 = [0] * ren
        id10 = [0] * ren
        id15 = [0] * ren

        id25 = [0] * ren

        rei = 0
        for er in rsd:
            f = er[0]
            t = er[1]
            c = rsd[er]
            id20[rei] = f
            id1[rei] = t
            id10[rei] = c
            id25[rei] = nei[(t, f)]
            id15[rei] = id12[f]
            id12[f] = rei
            rei += 1

        sol = 0
        epath = []
        while True:
            epath.clear()
            res = self._find_aug_path(id12, id20, id1, id10, id15, self.s, self.t, epath)
            if res == 0:
                break
            for ei in epath:
                id10[ei] -= res
                id10[id25[ei]] += res
            sol += res
        return sol

def opp(a, b):
    return (a == 'W' and b == 'E') or (a == 'E' and b == 'W') or (a == 'S' and b == 'N') or (a == 'N' and b == 'S')

def ccinv(x):
    if x == 'N':
        return 'S'
    elif x == 'S':
        return 'N'
    elif x == 'W':
        return 'E'
    elif x == 'E':
        return 'W'
    return 'W'

def main():
    random.seed()
    r = input()
    a = input()
    b = input()
    n = len(a)
    ar = a[::-1]
    ar = [ccinv(ch) for ch in ar]
    va = 0
    vb = 0
    p = 1
    for i in range(n):
        va = (va * 131 + ord(ar[i])) % M
        vb = (vb + ord(b[n - 1 - i]) * p) % M
        p = (p * 131) % M
        if vb == va:
            print("NO")
            return
    print("YES")

if __name__ == "__main__":
    main()
