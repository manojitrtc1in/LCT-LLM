import math
import sys
import time
from typing import List, Tuple

EPS = 1e-9
PI = math.atan(1) * 4
M = 1000000007

class PT:
    def __init__(self, x: float = 0, y: float = 0):
        self.x = x
        self.y = y
    
    def __add__(self, p: 'PT') -> 'PT':
        return PT(self.x + p.x, self.y + p.y)
    
    def __sub__(self, p: 'PT') -> 'PT':
        return PT(self.x - p.x, self.y - p.y)
    
    def __mul__(self, c: float) -> 'PT':
        return PT(self.x * c, self.y * c)
    
    def __truediv__(self, c: float) -> 'PT':
        return PT(self.x / c, self.y / c)

def dot(p: PT, q: PT) -> float:
    return p.x * q.x + p.y * q.y

def dist2(p: PT, q: PT) -> float:
    return dot(p - q, p - q)

def cross(p: PT, q: PT) -> float:
    return p.x * q.y - p.y * q.x

def id22(u: PT, v: PT) -> float:
    return dot(u, v) / math.sqrt(dot(u, u) * dot(v, v))

def id6(u: PT, v: PT) -> float:
    return cross(u, v) / math.sqrt(dot(u, u) * dot(v, v))

def id17(v: PT) -> float:
    return math.atan2(v.y, v.x)

class UnionFind:
    def __init__(self, n: int):
        self.C = [i for i in range(n)]
    
    def find(self, x: int) -> int:
        return x if self.C[x] == x else self.find(self.C[x])
    
    def merge(self, x: int, y: int) -> None:
        self.C[self.find(x)] = self.find(y)

def mod(x: int, m: int) -> int:
    return ((x % m) + m) % m

def gcd(a: int, b: int) -> int:
    while b > 0:
        a %= b
        a, b = b, a
    return a

def id11(a: int, b: int, x: int, y: int) -> int:
    xx, yy = 0, 1
    x, y = 1, 0
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

def mod_inverse(a: int, n: int) -> int:
    x, y = 0, 0
    d = id11(a, n, x, y)
    if d > 1:
        return -1
    return mod(x, n)

class id3:
    def __init__(self, A: List[List[float]], b: List[float], c: List[float]):
        self.m = len(b)
        self.n = len(c)
        self.B = [i for i in range(self.m)]
        self.D = [[A[i][j] for j in range(self.n)] for i in range(self.m)]
        for i in range(self.m):
            self.D[i].append(-1)
            self.D[i].append(b[i])
        for j in range(self.n):
            self.D[self.m].append(-c[j])
        self.D[self.m].append(1)
        self.N = [j for j in range(self.n)]
        self.N.append(-1)
    
    def Pivot(self, r: int, s: int) -> None:
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
    
    def Simplex(self, phase: int) -> bool:
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
            self.Pivot(r, s)
    
    def solve(self, x: List[float]) -> float:
        r = 0
        for i in range(1, self.m):
            if self.D[i][self.n + 1] < self.D[r][self.n + 1]:
                r = i
        if self.D[r][self.n + 1] < -EPS:
            self.Pivot(r, self.n)
            if not self.Simplex(1) or self.D[self.m + 1][self.n + 1] < -EPS:
                return -sys.float_info.max
            for i in range(self.m):
                if self.B[i] == -1:
                    s = -1
                    for j in range(self.n):
                        if s == -1 or self.D[i][j] < self.D[i][s] or self.D[i][j] == self.D[i][s] and self.N[j] < self.N[s]:
                            s = j
                    self.Pivot(i, s)
        if not self.Simplex(2):
            return sys.float_info.max
        x = [0] * self.n
        for i in range(self.m):
            if self.B[i] < self.n:
                x[self.B[i]] = self.D[i][self.n + 1]
        return self.D[self.m][self.n + 1]

def id8(n: int, froms: List[int], tos: List[int], id16: List[int], id4: List[int]) -> None:
    id16 = [-1] * n
    id4 = []
    en = len(froms)
    for i in range(en):
        f = froms[i]
        t = tos[i]
        id4.append(id16[f])
        id16[f] = i

class id18:
    def __init__(self, id23: List[int], id2: List[int], id26: List[int], id14: List[int], id5: List[int], _s: int, _t: int):
        self.id16 = id23
        self.id13 = id2
        self.id7 = id26
        self.id9 = id14
        self.id4 = id5
        self.s = _s
        self.t = _t
    
    def _find_aug_path(self, id16: List[int], id13: List[int], id7: List[int], id9: List[int], id4: List[int], s: int, t: int, epath: List[int]) -> int:
        id24 = [s]
        id0 = [-1]
        id21 = [-1]
        id27 = [sys.maxsize]
        inq = [False] * len(id16)
        inq[s] = True
        for i in range(len(id24)):
            crt = id24[i]
            f = id27[i]
            for j in range(id16[crt], -1, id4[j]):
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
            for j in range(i, 0, id0[j]):
                stk.append(id21[j])
            while stk:
                epath.append(stk.pop())
            return id27[i]
        return 0
    
    def eval(self) -> int:
        rsd = {}
        for i in range(len(self.id13)):
            f = self.id13[i]
            t = self.id7[i]
            rsd[(f, t)] = rsd.get((f, t), 0) + self.id9[i]
            rsd[(t, f)] = rsd.get((t, f), 0) + 0
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

def id19(T):
    v = [T()]
    opr = [0]
    opd = [T()]
    nxt = [-1]
    LEFT = 0
    RGHT = 0
    fnx = None
    fab = None
    
    def __init__(self, _l: int, _r: int, _v: T, _fnx, _fab):
        self.v[0] = self.fnx(_r - _l + 1, _v)
        self.opr[0] = 0
        self.opd[0] = _v
        self.nxt[0] = -1
        self.LEFT = _l
        self.RGHT = _r
        self.fnx = _fnx
        self.fab = _fab
    
    def _split(self, i: int, l0: int, r0: int) -> None:
        assert self.nxt[i] == -1
        assert self.opr[i] == 0
        assert l0 < r0
        n = len(self.v)
        self.nxt[i] = n
        m0 = (l0 + r0) // 2
        self.v.append(self.fnx(m0 - l0 + 1, self.opd[i]))
        self.v.append(self.fnx(r0 - m0, self.opd[i]))
        self.opr.append(0)
        self.opr.append(0)
        self.opd.append(self.opd[i])
        self.opd.append(self.opd[i])
        self.nxt.append(-1)
        self.nxt.append(-1)
    
    def _pushdown(self, i: int, l0: int, r0: int) -> None:
        if self.opr[i] == -1:
            return
        m0 = (l0 + r0) // 2
        if self.nxt[i] == -1:
            self._split(i, l0, r0)
        elif self.opr[i] >= 0:
            self._set(self.nxt[i], l0, m0, l0, m0, self.opr[i], self.opd[i])
            self._set(self.nxt[i] + 1, m0 + 1, r0, m0 + 1, r0, self.opr[i], self.opd[i])
        self.opr[i] = -1
    
    def _set(self, i: int, l0: int, r0: int, l1: int, r1: int, o1: int, v1: T) -> None:
        assert l1 >= l0 and r1 <= r0
        if l0 == l1 and r0 == r1:
            if o1 == 0:
                self.v[i] = self.fnx(r0 - l0 + 1, v1)
                self.opr[i] = 0
                self.opd[i] = v1
            elif o1 == 1:
                self.v[i] = self.fab(self.v[i], self.fnx(r0 - l0 + 1, v1))
                if self.opr[i] == -1:
                    self.opr[i] = 1
                    self.opd[i] = v1
                elif self.opr[i] == 0:
                    self.opr[i] = 0
                    self.opd[i] = self.fab(self.opd[i], v1)
                elif self.opr[i] == 1:
                    self.opr[i] = 1
                    self.opd[i] = self.fab(self.opd[i], v1)
            return
        m0 = (l0 + r0) // 2
        self._pushdown(i, l0, r0)
        if l1 <= m0:
            self._set(self.nxt[i], l0, m0, l1, min(r1, m0), o1, v1)
        if r1 > m0:
            self._set(self.nxt[i] + 1, m0 + 1, r0, max(l1, m0 + 1), r1, o1, v1)
        self.v[i] = self.fab(self.v[self.nxt[i]], self.v[self.nxt[i] + 1])
    
    def _get(self, i: int, l0: int, r0: int, l1: int, r1: int) -> T:
        assert l0 <= l1 and r1 <= r0
        if l0 == l1 and r1 == r0:
            return self.v[i]
        self._pushdown(i, l0, r0)
        m0 = (l0 + r0) // 2
        if r1 <= m0:
            return self._get(self.nxt[i], l0, m0, l1, r1)
        if m0 + 1 <= l1:
            return self._get(self.nxt[i] + 1, m0 + 1, r0, l1, r1)
        lv = self._get(self.nxt[i], l0, m0, l1, m0)
        rv = self._get(self.nxt[i] + 1, m0 + 1, r0, m0 + 1, r1)
        return self.fab(lv, rv)
    
    def updres(self, l1: int, r1: int, v1: T) -> None:
        self._set(0, self.LEFT, self.RGHT, l1, r1, 1, v1)
    
    def setval(self, l1: int, r1: int, v1: T) -> None:
        self._set(0, self.LEFT, self.RGHT, l1, r1, 0, v1)
    
    def get(self, l1: int, r1: int) -> T:
        return self._get(0, self.LEFT, self.RGHT, l1, r1)

def opp(a: str, b: str) -> bool:
    return (a == 'W' and b == 'E') or (a == 'E' and b == 'W') or (a == 'S' and b == 'N') or (a == 'N' and b == 'S')

def ccinv(x: str) -> str:
    if x == 'N':
        return 'S'
    elif x == 'S':
        return 'N'
    elif x == 'W':
        return 'E'
    elif x == 'E':
        return 'W'
    return 'W'

def main() -> None:
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

if __name__ == '__main__':
    main()
