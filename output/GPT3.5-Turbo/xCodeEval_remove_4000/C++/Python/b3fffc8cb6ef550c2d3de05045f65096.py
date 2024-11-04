MOD = 998244353
UNDEF = -1
INF = 1 << 30

class mint:
    def __init__(self, x=0):
        self.x = x % MOD

    def _norm(self, x):
        if x < 0:
            x += MOD
        return x

    def get(self):
        return self.x

    def __add__(self, that):
        return mint(self._norm(self.x + that.x))

    def __sub__(self, that):
        return mint(self._norm(self.x - that.x))

    def __mul__(self, that):
        return mint((self.x * that.x) % MOD)

    def __truediv__(self, that):
        return self * that.inverse()

    def __iadd__(self, that):
        self.x = self._norm(self.x + that.x)
        return self

    def __isub__(self, that):
        self.x = self._norm(self.x - that.x)
        return self

    def __imul__(self, that):
        self.x = (self.x * that.x) % MOD
        return self

    def __itruediv__(self, that):
        return self * that.inverse()

    def __eq__(self, that):
        return self.x == that.x

    def __ne__(self, that):
        return self.x != that.x

    def __neg__(self):
        return mint(0 if self.x == 0 else MOD - self.x)

    def __pow__(self, k):
        a = self
        r = mint(1)
        while k:
            if k & 1:
                r *= a
            a *= a
            k >>= 1
        return r

    def inverse(self):
        a = self.x
        b = MOD
        u = 1
        v = 0
        while b:
            t = a // b
            a -= t * b
            a, b = b, a
            u -= t * v
            u, v = v, u
        if u < 0:
            u += MOD
        return mint(u)

class id5:
    def __init__(self, nu=0, de=1):
        self.nu = nu
        self.de = de
        if self.de < 0:
            self.nu = -self.nu
            self.de = -self.de

    def __add__(self, b):
        return id5(self.nu * b.de + self.de * b.nu, self.de * b.de)

    def __sub__(self, b):
        return id5(self.nu * b.de - self.de * b.nu, self.de * b.de)

    def __neg__(self):
        return id5(-self.nu, self.de)

    def __mul__(self, b):
        return id5(self.nu * b.nu, self.de * b.de)

    def __truediv__(self, b):
        return id5(self.nu * b.de, self.de * b.nu)

    def __eq__(self, b):
        return self.nu * b.de == b.nu * self.de

    def __eq__(self, k):
        return self.nu == k * self.de

    def __lt__(self, b):
        return self.nu * b.de < b.nu * self.de

    def __le__(self, b):
        return self.nu * b.de <= b.nu * self.de

    def __gt__(self, b):
        return self.nu * b.de > b.nu * self.de

    def __ge__(self, b):
        return self.nu * b.de >= b.nu * self.de

class SegNode:
    def __init__(self):
        self.prod = [mint(), mint()]
        self.sumlr = mint()
        self.ident = True

class MulSegTree:
    def __init__(self, id0):
        self.SEGSZ = id0
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
        n = self.segn
        for i in range(n - 1, 0, -1):
            self.t[i] = self.combine(self.t[i << 1], self.t[i << 1 | 1])

    def set_before_build(self, p, value):
        self.t[self.segn + p] = value

    def sset(self, p, value):
        n = self.segn
        t = self.t
        p += n
        t[p] = value
        while p > 1:
            p >>= 1
            t[p] = self.combine(t[p << 1], t[p << 1 | 1])

    def query(self, l, r):
        if l > r:
            return self.identity
        r += 1
        n = self.segn
        resl = self.identity
        resr = self.identity
        t = self.t
        for l += n, r += n; l < r; l >>= 1, r >>= 1:
            if l & 1:
                resl = self.combine(resl, t[l])
                l += 1
            if r & 1:
                r -= 1
                resr = self.combine(t[r], resr)
        return self.combine(resl, resr)

class Group:
    def __init__(self, l, r, forceDir):
        self.l = l
        self.r = r
        self.forceDir = forceDir

    def __lt__(self, other):
        return (self.r < other.r) or ((self.r == other.r) and (self.l < other.l)) or ((self.r == other.r) and (self.l == other.l) and (self.forceDir < other.forceDir))

class GroupSet:
    def __init__(self, mx):
        self.s = set()
        self.mx = mx

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
        it = self.s.upper_bound(Group(-2, x, -2))
        return it

    def funion(self, x, y):
        it1 = self.lb(x)
        it2 = self.lb(y)
        if it1 != it2:
            combined = self.combine(it1, it2)
            self.s.remove(it1)
            it2 = self.lb(y)
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
        assert UNDEF <= dl and dl < 2
        assert UNDEF <= dr and dr < 2
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
            assert 0

    def check(self):
        pass

    def getDir(self, x):
        return self.getData(x).forceDir

def probForce(dir, l, r):
    assert 0 <= dir < 2
    return seg.query(l, r).prod[dir]

def id1(l, r):
    return seg.query(l, r).sumlr

def id2(l, r):
    lo = INF
    hi = -INF
    ans = mint(1)
    gs.check()
    pos = l
    while pos <= r:
        dat = gs.getData(pos)
        lo = min(lo, dat.l)
        hi = max(hi, dat.r)
        if dat.forceDir == UNDEF:
            mult = seg.query(dat.l, dat.r).sumlr
        else:
            mult = seg.query(dat.l, dat.r).prod[dat.forceDir]
        ans *= mult
        pos = dat.r + 1
    return ans

def id12(l, r):
    dl = gs.getDir(l)
    dr = gs.getDir(r)
    if (dl == R and dr == -1) or (dl == -1 and dr == L) or (dl == -1 and dr == -1):
        den = id2(dl.l, dr.r)
        gs.funion(l, r)
        num = id2(dl.l, dr.r)
        id10 *= num / den
    elif dl == R and dr == -1:
        pass
    elif dl == -1 and dr == R:
        pass
    elif dl >= 0 and dr >= 0:
        if dl == dr:
            pass
        else:
            id10 = 0
    else:
        assert 0

def id3(r):
    return mint(r.nu) / mint(r.de)

n = rint()
alln = n
vpos = [0] * mn
v = [0] * mn
probBallDir = [[mint() for _ in range(2)] for _ in range(mn)]
gs = GroupSet(mn)
seg = MulSegTree(mn)

for i in range(n):
    vpos[i] = rint()
    v[i] = rint()
    probBallDir[i][R] = mint(rint()) / mint(100)
    probBallDir[i][L] = mint(1) - probBallDir[i][R]

gs.init(n)
seg.init(n)
for pos in range(n):
    seg.set_before_build(pos, SegNode([probBallDir[pos][L], probBallDir[pos][R]], probBallDir[pos][L] + probBallDir[pos][R], False]))
seg.build()

collisions = []
for i in range(n - 1):
    dist = vpos[i + 1] - vpos[i]
    id8 = id5(dist, v[i + 1] + v[i])
    collisions.append(Collision(id8, i, R, L))
    if v[i] > v[i + 1]:
        id6 = id5(dist, v[i] - v[i + 1])
        collisions.append(Collision(id6, i, R, R))
    if v[i] < v[i + 1]:
        id11 = id5(dist, v[i + 1] - v[i])
        collisions.append(Collision(id11, i, L, L))
collisions.sort()

finalSum = mint()
for c in collisions:
    pos = c.pos
    id9 = id10
    dl = gs.getDir(c.pos)
    dr = gs.getDir(c.pos + 1)
    if dl != UNDEF and dl != c.dirL:
        continue
    if dr != UNDEF and dr != c.dirR:
        continue
    if c.dirL == R and c.dirR == L:
        id12(pos, pos + 1)
    elif c.dirL == R and c.dirR == R:
        if dl == R:
            id10 = 0
        else:
            den = id2(pos, pos + 1)
            gs.split(c.pos, c.pos + 1, L, UNDEF)
            num = id2(pos, pos + 1)
            id10 *= num / den
    elif c.dirL == L and c.dirR == L:
        if dr == L:
            id10 = 0
        else:
            den = id2(pos, pos + 1)
            gs.split(c.pos, c.pos + 1, UNDEF, R)
            num = id2(pos, pos + 1)
            id10 *= num / den
    else:
        assert 0
    gs.check()
    id7 = id3(c.id7)
    finalSum += id7 * (id9 - id10)
    if id10 == 0:
        break

print(finalSum.get())
