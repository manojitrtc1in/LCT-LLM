import sys
from collections import defaultdict
from fractions import Fraction

MOD = 998244353
UNDEF = -1
INF = 1 << 30

class Mint:
    def __init__(self, sig=0):
        self.x = sig % MOD if sig >= 0 else (sig % MOD + MOD) % MOD

    def __add__(self, other):
        return Mint(self.x + other.x)

    def __sub__(self, other):
        return Mint(self.x - other.x)

    def __mul__(self, other):
        return Mint(self.x * other.x)

    def __truediv__(self, other):
        return self * other.inverse()

    def inverse(self):
        a, b, u, v = self.x, MOD, 1, 0
        while b:
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v
        if u < 0:
            u += MOD
        return Mint(u)

    def __eq__(self, other):
        return self.x == other.x

    def __ne__(self, other):
        return self.x != other.x

    def __neg__(self):
        return Mint(MOD - self.x if self.x != 0 else 0)

    def __pow__(self, k):
        a = self
        r = Mint(1)
        while k:
            if k & 1:
                r *= a
            a *= a
            k >>= 1
        return r

    def get(self):
        return self.x

class Rational:
    def __init__(self, nu=0, de=1):
        self.nu = nu
        self.de = de
        if self.de < 0:
            self.nu = -self.nu
            self.de = -self.de

    def __add__(self, other):
        return Rational(self.nu * other.de + self.de * other.nu, self.de * other.de)

    def __sub__(self, other):
        return Rational(self.nu * other.de - self.de * other.nu, self.de * other.de)

    def __neg__(self):
        return Rational(-self.nu, self.de)

    def __mul__(self, other):
        return Rational(self.nu * other.nu, self.de * other.de)

    def __truediv__(self, other):
        return Rational(self.nu * other.de, self.de * other.nu)

    def __eq__(self, other):
        return self.nu * other.de == other.nu * self.de

    def __lt__(self, other):
        return self.nu * other.de < other.nu * self.de

class SegNode:
    def __init__(self):
        self.prod = [Mint(1), Mint(1)]
        self.sumlr = Mint(1)
        self.ident = True

class MulSegTree:
    def __init__(self, size):
        self.segn = size
        self.t = [SegNode() for _ in range(2 * size)]
        self.identity = SegNode()

    def combine(self, x, y):
        if x.ident:
            return y
        if y.ident:
            return x
        ans = SegNode()
        for d in range(2):
            ans.prod[d] = x.prod[d] * y.prod[d]
        ans.sumlr = (x.sumlr * y.prod[1]) + (x.prod[0] * y.sumlr) - (x.prod[0] * y.prod[1])
        ans.ident = False
        return ans

    def set_before_build(self, p, value):
        self.t[self.segn + p] = value

    def build(self):
        for i in range(self.segn - 1, 0, -1):
            self.t[i] = self.combine(self.t[i << 1], self.t[i << 1 | 1])

    def query(self, l, r):
        if l > r:
            return self.identity
        r += 1
        resl = self.identity
        resr = self.identity
        for l, r in zip(range(l + self.segn, r + self.segn), range(r + self.segn)):
            if l & 1:
                resl = self.combine(resl, self.t[l])
                l += 1
            if r & 1:
                r -= 1
                resr = self.combine(self.t[r], resr)
        return self.combine(resl, resr)

class Group:
    def __init__(self, l=0, r=0, forceDir=-1):
        self.l = l
        self.r = r
        self.forceDir = forceDir

    def __lt__(self, other):
        return (self.r < other.r) or (self.r == other.r and self.l < other.l) or (self.r == other.r and self.l == other.l and self.forceDir < other.forceDir)

class GroupSet:
    def __init__(self, mx):
        self.s = set()
        self.mx = mx

    def combine(self, x, y):
        if min(x.forceDir, y.forceDir) >= 0:
            assert x.forceDir == y.forceDir
        return Group(min(x.l, y.l), max(x.r, y.r), max(x.forceDir, y.forceDir))

    def get_initial_value(self, x):
        return Group(x, x, -1)

    def ufreset(self, x):
        self.s.add(self.get_initial_value(x))

    def init(self, n):
        for x in range(n):
            self.ufreset(x)

    def lb(self, x):
        return next((g for g in self.s if g.l >= x), None)

    def funion(self, x, y):
        it1 = self.lb(x)
        it2 = self.lb(y)
        if it1 != it2:
            combined = self.combine(it1, it2)
            self.s.remove(it1)
            self.s.remove(it2)
            self.s.add(combined)

    def get_data(self, x):
        return self.lb(x)

    def set_data(self, x, dat):
        it = self.lb(x)
        self.s.remove(it)
        self.s.add(dat)

    def split(self, pl, pr, dl, dr):
        assert UNDEF <= dl < 2
        assert UNDEF <= dr < 2
        assert pl + 1 == pr
        itl = self.lb(pl)
        itr = self.lb(pr)
        assert itl.forceDir == -1
        assert itr.forceDir == -1
        if itl == itr:
            g = itl
            self.s.remove(itl)
            self.s.add(Group(g.l, pl, dl))
            self.s.add(Group(pr, g.r, dr))
        else:
            assert False

    def get_dir(self, x):
        return self.get_data(x).forceDir

def read_int():
    return int(sys.stdin.readline().strip())

def main():
    n = read_int()
    vpos = [0] * n
    v = [0] * n
    probBallDir = [[Mint() for _ in range(2)] for _ in range(n)]
    gs = GroupSet(n)
    seg = MulSegTree(n)

    for i in range(n):
        vpos[i] = read_int()
        v[i] = read_int()
        probBallDir[i][1] = Mint(read_int()) / Mint(100)
        probBallDir[i][0] = Mint(1) - probBallDir[i][1]

    gs.init(n)
    for pos in range(n):
        seg.set_before_build(pos, SegNode())
        seg.t[seg.segn + pos].prod = [probBallDir[pos][0], probBallDir[pos][1]]
        seg.t[seg.segn + pos].sumlr = probBallDir[pos][0] + probBallDir[pos][1]
        seg.t[seg.segn + pos].ident = False
    seg.build()

    collisions = []
    for i in range(n - 1):
        dist = vpos[i + 1] - vpos[i]
        rlCollideTime = Rational(dist, v[i + 1] + v[i])
        collisions.append((rlCollideTime, i, 1, 0))

        if v[i] > v[i + 1]:
            rrCollideTime = Rational(dist, v[i] - v[i + 1])
            collisions.append((rrCollideTime, i, 1, 1))

        if v[i] < v[i + 1]:
            llCollideTime = Rational(dist, v[i + 1] - v[i])
            collisions.append((llCollideTime, i, 0, 0))

    collisions.sort()
    finalSum = Mint(0)
    probNoCollide = Mint(1)

    for collideTime, pos, dirL, dirR in collisions:
        prevProbNoCollide = probNoCollide
        dl = gs.get_dir(pos)
        dr = gs.get_dir(pos + 1)

        if dl != UNDEF and dl != dirL:
            continue
        if dr != UNDEF and dr != dirR:
            continue

        if dirL == 1 and dirR == 0:
            gs.funion(pos, pos + 1)
        elif dirL == 1 and dirR == 1:
            if dl == 1:
                probNoCollide = Mint(0)
            else:
                den = seg.query(pos, pos + 1).sumlr
                gs.split(pos, pos + 1, 0, UNDEF)
                num = seg.query(pos, pos + 1).sumlr
                probNoCollide *= num / den
        elif dirL == 0 and dirR == 0:
            if dr == 0:
                probNoCollide = Mint(0)
            else:
                den = seg.query(pos, pos + 1).sumlr
                gs.split(pos, pos + 1, UNDEF, 1)
                num = seg.query(pos, pos + 1).sumlr
                probNoCollide *= num / den
        else:
            assert False

        collideTimeMint = Mint(collideTime.nu) / Mint(collideTime.de)
        finalSum += collideTimeMint * (prevProbNoCollide - probNoCollide)
        if probNoCollide == Mint(0):
            break

    print(finalSum.get())

if __name__ == "__main__":
    main()
