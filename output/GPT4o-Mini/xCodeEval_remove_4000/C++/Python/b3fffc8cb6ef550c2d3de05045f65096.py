MOD = 998244353
UNDEF = -1
INF = 1 << 30

def chkmax(aa, bb):
    if aa < bb:
        aa[0] = bb
        return True
    return False

def chkmin(aa, bb):
    if aa > bb:
        aa[0] = bb
        return True
    return False

class Mint:
    def __init__(self, sig=0):
        self.x = sig % MOD if sig >= 0 else (sig + MOD) % MOD

    def get(self):
        return self.x

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

class Id5:
    def __init__(self, n=0, d=1):
        self.nu = n
        self.de = d
        if self.de < 0:
            self.nu = -self.nu
            self.de = -self.de

    def __add__(self, other):
        return Id5(self.nu * other.de + self.de * other.nu, self.de * other.de)

    def __sub__(self, other):
        return Id5(self.nu * other.de - self.de * other.nu, self.de * other.de)

    def __neg__(self):
        return Id5(-self.nu, self.de)

    def __mul__(self, other):
        return Id5(self.nu * other.nu, self.de * other.de)

    def __truediv__(self, other):
        return Id5(self.nu * other.de, self.de * other.nu)

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
    def __init__(self, id0):
        self.segn = id0
        self.t = [SegNode() for _ in range(2 * id0)]
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

    def init(self, n):
        self.segn = n

    def build(self):
        for i in range(self.segn - 1, 0, -1):
            self.t[i] = self.combine(self.t[i << 1], self.t[i << 1 | 1])

    def set_before_build(self, p, value):
        self.t[self.segn + p] = value

    def sset(self, p, value):
        for self.t[p + self.segn] = value; p >>= 1:
            self.t[p] = self.combine(self.t[p << 1], self.t[p << 1 | 1])

    def query(self, l, r):
        if l > r:
            return self.identity
        r += 1
        resl, resr = self.identity, self.identity
        for l += self.segn, r += self.segn; l < r; l >>= 1, r >>= 1:
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

    def combine(self, x, y):
        if min(x.forceDir, y.forceDir) >= 0:
            assert x.forceDir == y.forceDir
        return Group(min(x.l, y.l), max(x.r, y.r), max(x.forceDir, y.forceDir))

    def getInitialValue(self, x):
        return Group(x, x, -1)

    def ufreset(self, x):
        self.s.add(self.getInitialValue(x))

    def init(self, n):
        for x in range(n):
            self.ufreset(x)

    def lb(self, x):
        it = next((g for g in self.s if g.l > x), None)
        return it

    def funion(self, x, y):
        it1 = self.lb(x)
        it2 = self.lb(y)
        if it1 != it2:
            combined = self.combine(it1, it2)
            self.s.remove(it1)
            self.s.remove(it2)
            self.s.add(combined)

    def getData(self, x):
        it = self.lb(x)
        return it

    def setData(self, x, dat):
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

    def getDir(self, x):
        return self.getData(x).forceDir

def rint():
    return int(input().strip())

def main():
    n = rint()
    alln = n
    vpos = [0] * n
    v = [0] * n
    probBallDir = [[Mint() for _ in range(2)] for _ in range(n)]
    gs = GroupSet(n)
    seg = MulSegTree(n)

    for i in range(n):
        vpos[i] = rint()
        v[i] = rint()
        probBallDir[i][1] = Mint(rint()) / Mint(100)
        probBallDir[i][0] = Mint(1) - probBallDir[i][1]

    gs.init(n)
    seg.init(n)
    for pos in range(n):
        seg.set_before_build(pos, SegNode())
        seg.t[seg.segn + pos].prod[0] = probBallDir[pos][0]
        seg.t[seg.segn + pos].prod[1] = probBallDir[pos][1]
        seg.t[seg.segn + pos].sumlr = probBallDir[pos][0] + probBallDir[pos][1]
        seg.t[seg.segn + pos].ident = False
    seg.build()

    collisions = []
    for i in range(n - 1):
        dist = vpos[i + 1] - vpos[i]
        id8 = Id5(dist, v[i + 1] + v[i])
        collisions.append((id8, i, 1, 0))

        if v[i] > v[i + 1]:
            id6 = Id5(dist, v[i] - v[i + 1])
            collisions.append((id6, i, 1, 1))

        if v[i] < v[i + 1]:
            id11 = Id5(dist, v[i + 1] - v[i])
            collisions.append((id11, i, 0, 0))

    collisions.sort()
    finalSum = Mint(0)
    id10 = Mint(1)

    for c in collisions:
        pos = c[1]
        id9 = id10
        dl = gs.getDir(c[1])
        dr = gs.getDir(c[1] + 1)

        if dl != UNDEF and dl != c[2]:
            continue
        if dr != UNDEF and dr != c[3]:
            continue

        if c[2] == 1 and c[3] == 0:
            pass  # Implement id12 logic here
        elif c[2] == 1 and c[3] == 1:
            if dl == 1:
                id10 = Mint(0)
            else:
                den = seg.query(pos, pos + 1).sumlr
                gs.split(c[1], c[1] + 1, 0, UNDEF)
                num = seg.query(pos, pos + 1).sumlr
                id10 *= num / den
        elif c[2] == 0 and c[3] == 0:
            if dr == 0:
                id10 = Mint(0)
            else:
                den = seg.query(pos, pos + 1).sumlr
                gs.split(c[1], c[1] + 1, UNDEF, 1)
                num = seg.query(pos, pos + 1).sumlr
                id10 *= num / den
        else:
            assert False

        id7 = Mint(c[0].nu) / Mint(c[0].de)
        finalSum += id7 * (id9 - id10)
        if id10.get() == 0:
            break

    print(finalSum.get())

if __name__ == "__main__":
    main()
