import math

class frac:
    def __init__(self, n, d=1):
        self.n = n
        self.d = d
        assert self.n != 0 or self.d != 0
        if self.d < 0:
            self.n *= -1
            self.d *= -1
        g = math.gcd(abs(self.n), self.d)
        self.n //= g
        self.d //= g

    def __str__(self):
        return f"{self.n}/{self.d}"

    def __lt__(self, other):
        return self.n * other.d < other.n * self.d

    def __le__(self, other):
        return self.n * other.d <= other.n * self.d

    def __eq__(self, other):
        return self.n * other.d == other.n * self.d

    def __ne__(self, other):
        return self.n * other.d != other.n * self.d

    def __gt__(self, other):
        return self.n * other.d > other.n * self.d

    def __ge__(self, other):
        return self.n * other.d >= other.n * self.d

    def __add__(self, other):
        return frac(self.n * other.d + other.n * self.d, self.d * other.d)

    def __sub__(self, other):
        return frac(self.n * other.d - other.n * self.d, self.d * other.d)

    def __mul__(self, other):
        return frac(self.n * other.n, self.d * other.d)

    def __truediv__(self, other):
        return frac(self.n * other.d, self.d * other.n)

    def __pos__(self):
        return self

    def __neg__(self):
        return frac(-self.n, self.d)

    def floor(self):
        assert self.d > 0
        return self.n // self.d - ((self.n < 0) and (self.n % self.d))

    def ceil(self):
        assert self.d > 0
        return self.n // self.d + ((self.n > 0) and (self.n % self.d))

    def to_cont(self):
        if self.d == 0:
            return [float('inf')]
        cont = []
        n, d = self.n, self.d
        while True:
            f = (n // d) if n >= 0 else (n - d + 1) // d
            cont.append(f)
            n -= f * d
            if n == 0:
                break
        return cont

    @staticmethod
    def from_cont(cont):
        n, d = 1, 0
        for i in range(len(cont) - 1, -1, -1):
            n, d = d, n
            n += d * cont[i]
        return frac(n, d)

    @staticmethod
    def best_in(x, y):
        assert x < y
        x1 = x.to_cont()
        y1 = y.to_cont()
        x2 = list(x1)
        x2[-1] -= 1
        x2.append(1)
        y2 = list(y1)
        y2[-1] -= 1
        y2.append(1)

        def z(a, b):
            c = []
            for i in range(len(a)):
                ai = a[i] if i < len(a) else float('inf')
                bi = b[i] if i < len(b) else float('inf')
                if ai != bi:
                    c.append(min(ai, bi) + 1)
                    return frac.from_cont(c)
                c.append(ai)
            return c

        ans = frac(1, 0)
        for f in [z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)]:
            if x < f and f < y and (ans.d == 0 or f.d < ans.d):
                ans = f
        return ans


class modnum:
    def __init__(self, v):
        self.v = v % modnum.MOD
        if self.v < 0:
            self.v += modnum.MOD

    def __str__(self):
        return str(self.v)

    def __int__(self):
        return self.v

    def __eq__(self, other):
        return self.v == other.v

    def __ne__(self, other):
        return self.v != other.v

    def __add__(self, other):
        return modnum(self.v + other.v)

    def __sub__(self, other):
        return modnum(self.v - other.v)

    def __mul__(self, other):
        return modnum(self.v * other.v)

    def __neg__(self):
        return modnum(modnum.MOD - self.v)

    def pow(self, e):
        if e < 0:
            return modnum(1) / self.pow(-e)
        if e == 0:
            return modnum(1)
        if e & 1:
            return self * self.pow(e - 1)
        return (self * self).pow(e // 2)

    def inv(self):
        g, x, y = modnum.MOD, 0, 1
        r = self.v
        while r != 0:
            q = g // r
            g, r = r, g - q * r
            x, y = y, x - q * y

        assert g == 1
        assert y == modnum.MOD or y == -modnum.MOD
        return x if x >= 0 else x + modnum.MOD

    def __truediv__(self, other):
        return self * other.inv()

    @staticmethod
    def fast_mod(x, m=modnum.MOD):
        return x % m

    @staticmethod
    def primitive_root():
        if modnum.MOD == 1:
            return 0
        if modnum.MOD == 2:
            return 1

        tot = modnum.totient()
        tmp = tot
        tot_pr = []
        for p in range(2, int(math.sqrt(tmp)) + 1):
            if tmp % p == 0:
                tot_pr.append(p)
                while tmp % p == 0:
                    tmp //= p
        if tmp > 1:
            tot_pr.append(tmp)

        for r in range(2, modnum.MOD):
            if math.gcd(r, modnum.MOD) == 1:
                root = True
                for p in tot_pr:
                    root &= modnum(r).pow(tot // p) != 1
                if root:
                    return r
        assert False

    @staticmethod
    def unity_root(deg):
        assert modnum.totient() % deg == 0
        return modnum.generator().pow(modnum.totient() // deg)

    @staticmethod
    def unity_root(deg, pow):
        table = [0, 1]
        while len(table) <= deg:
            w = modnum.unity_root(len(table))
            for i in range(len(table) // 2, len(table)):
                table.append(table[i])
                table.append(table[i] * w)
        return table[deg + (deg + pow if pow < 0 else pow)]

    @staticmethod
    def factorial(n):
        fact = [modnum(1)]
        if len(fact) <= n:
            for i in range(len(fact), n + 1):
                fact.append(fact[i - 1] * modnum(i))
        return fact[n]

    @staticmethod
    def inverse_factorial(n):
        finv = [modnum(1)]
        if len(finv) <= n:
            for i in range(len(finv), n + 1):
                finv.append(finv[i - 1] * modnum(i).inv())
        return finv[n]

    @staticmethod
    def small_inv(n):
        assert n > 0
        return modnum.factorial(n - 1) * modnum.inverse_factorial(n)

    @staticmethod
    def ncr(n, r):
        if r < 0 or n < r:
            return modnum(0)
        return modnum.factorial(n) * modnum.inverse_factorial(r) * modnum.inverse_factorial(n - r)

    MOD = 998244353
    @staticmethod
    def totient():
        tot = modnum.MOD
        tmp = modnum.MOD
        for p in range(2, int(math.sqrt(tmp)) + 1):
            if tmp % p == 0:
                tot = tot // p * (p - 1)
                while tmp % p == 0:
                    tmp //= p
        if tmp > 1:
            tot = tot // tmp * (tmp - 1)
        return tot


class segment_tree:
    def __init__(self, SZ, id, tt):
        self.SZ = SZ
        self.id = id
        self.tt = tt
        self.table = [id] * (2 * SZ)

    def set_leaves(self, create):
        for i in range(self.SZ):
            self.table[self.SZ + i] = create(i)
        for i in range(self.SZ - 1, 0, -1):
            self.table[i] = self.tt(self.table[2 * i], self.table[2 * i + 1])

    def replace(self, i, v):
        self.table[i + self.SZ] = v
        i //= 2
        while i > 0:
            self.table[i] = self.tt(self.table[2 * i], self.table[2 * i + 1])
            i //= 2

    def __call__(self, i, j):
        left = self.id
        right = self.id
        i += self.SZ
        j += self.SZ
        while i < j:
            if i & 1:
                left = self.tt(left, self.table[i])
                i += 1
            if j & 1:
                j -= 1
                right = self.tt(self.table[j], right)
            i //= 2
            j //= 2
        return self.tt(left, right)

    def __getitem__(self, i):
        return self.table[self.SZ + i]


N = int(input())
pipes = []
for _ in range(N):
    x, v, p = map(int, input().split())
    pipes.append((x, v, p))

evs = []
for i in range(N - 1):
    dx = pipes[i + 1][0] - pipes[i][0]
    dv = pipes[i + 1][1] - pipes[i][1]
    evs.append((i, "RL", frac(dx, pipes[i + 1][1] + pipes[i][1])))

    if dv > 0:
        evs.append((i, "LL", frac(dx, dv)))
    if dv < 0:
        evs.append((i, "RR", frac(dx, -dv)))
evs.sort(key=lambda x: x[2])

class node:
    def __init__(self):
        self.p = [modnum(0)] * 4
        self.noLL = False
        self.noRR = False
        self.noRL = False
        self.none = True

def nn(a, b):
    if a.none:
        return b
    if b.none:
        return a
    r = b
    r.p = [modnum(0)] * 4
    for i in range(4):
        for j in range(4):
            iF = bool(i & 1)
            iB = bool((i >> 1) & 1)
            jF = bool(j & 1)
            jB = bool((j >> 1) & 1)
            if a.noLL and not iB and not jF:
                continue
            if a.noRR and iB and jF:
                continue
            if a.noRL and iB and not jF:
                continue
            r.p[iF + 2 * jB] += a.p[i] * b.p[j]
    return r

st = segment_tree(N, node(), nn)
def create(i):
    pR = pipes[i][2] * modnum.small_inv(100)
    r = node()
    r.p = [modnum(1) - pR, modnum(0), modnum(0), pR]
    r.none = False
    return r
st.set_leaves(create)

ans = modnum(0)
prob = modnum(1)
for e in evs:
    c = st[e[0]]
    if e[1] == "LL":
        c.noLL = True
    elif e[1] == "RR":
        c.noRR = True
    elif e[1] == "RL":
        c.noRL = True
    st.replace(e[0], c)

    u = st(0, st.SZ)
    PROB = sum(u.p)
    ans += (prob - PROB) * e[2].n * modnum.small_inv(e[2].d)
    prob = PROB

print(ans)
