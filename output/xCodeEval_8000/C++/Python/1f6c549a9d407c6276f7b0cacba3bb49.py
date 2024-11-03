mod = 998244353
K = 18

class Mint:
    def __init__(self, n=0):
        self.n = n % mod

    def __neg__(self):
        return Mint(-self.n)

    def __pos__(self):
        return self

    def __iadd__(self, other):
        self.n += other.n
        if self.n >= mod:
            self.n -= mod
        return self

    def __isub__(self, other):
        self.n -= other.n
        if self.n < 0:
            self.n += mod
        return self

    def __imul__(self, other):
        self.n = (self.n * other.n) % mod
        return self

    def __ifloordiv__(self, other):
        self.n = (self.n * other.inv().n) % mod
        return self

    def __eq__(self, other):
        return self.n == other.n

    def __ne__(self, other):
        return self.n != other.n

    def __sub__(self, other):
        return Mint(self.n) - other

    def __add__(self, other):
        return Mint(self.n) + other

    def __mul__(self, other):
        return Mint(self.n) * other

    def __floordiv__(self, other):
        return Mint(self.n) // other

    def pow(self, n):
        res = Mint(1)
        x = Mint(self.n)
        while n > 0:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        return res

    def inv(self):
        return self.pow(mod - 2)

class Poly:
    def __init__(self, n=-1):
        self.c = [Mint(0)] * (n + 1)

    def deg(self):
        return len(self.c) - 1

    def at(self, n):
        if n < len(self.c):
            return self.c[n]
        else:
            return Mint(0)

    def __iadd__(self, other):
        if other.deg() > self.deg():
            d = list(other.c)
            for i in range(self.deg() + 1):
                d[i] += self.c[i]
            self.c = d
        else:
            for i in range(other.deg() + 1):
                self.c[i] += other.c[i]
        return self

    def __isub__(self, other):
        if other.deg() > self.deg():
            d = [-x for x in other.c]
            for i in range(self.deg() + 1):
                d[i] += self.c[i]
            self.c = d
        else:
            for i in range(other.deg() + 1):
                self.c[i] -= other.c[i]
        return self

    def __imul__(self, other):
        if self.deg() < 0 or other.deg() < 0:
            self.c = []
            return self
        rdeg = self.deg() + other.deg()
        k = 32 - (rdeg).bit_length()
        assert k <= K + 1
        d = [Mint(0)] * (1 << k)
        e = [Mint(0)] * (1 << k)
        for i in range(self.deg() + 1):
            d[i] = self.c[i]
        for i in range(other.deg() + 1):
            e[i] = other.c[i]
        fft(d, k)
        fft(e, k)
        for i in range(1 << k):
            d[i] *= e[i]
        ifft(d, k)
        self.c = d[:rdeg + 1]
        im = Mint((mod + 1) // 2).pow(k)
        for i in range(rdeg + 1):
            self.c[i] *= im
        return self

    def __add__(self, other):
        res = Poly()
        res.c = list(self.c)
        res += other
        return res

    def __sub__(self, other):
        res = Poly()
        res.c = list(self.c)
        res -= other
        return res

    def __mul__(self, other):
        res = Poly()
        res.c = list(self.c)
        res *= other
        return res

    def __floordiv__(self, other):
        res = Poly()
        res.c = list(self.c)
        res //= other
        return res

    def inv(self, n=-1):
        assert self.c[0] != 0
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        k = 32 - (n).bit_length()
        assert k <= K
        d = [Mint(0)] * (1 << k)
        ee = [Mint(0)] * (1 << k)
        res = Poly(n)
        res.c[0] = self.c[0].inv()
        y = (mod + 1) // 2
        if y & 1:
            y += mod
        y //= 2
        im = Mint(mod - y)
        for i in range(k):
            for j in range(1 << i):
                ff = res.c[j]
                gg = self.c[j << (k - i)]
                d[j] = ff
                ee[j] = gg
                d[j + (1 << i)] = 0
                ee[j + (1 << i)] = 0
            fft(d, i + 1)
            fft(ee, i + 1)
            for j in range(1 << (i + 1)):
                d[j] *= ee[j]
            ifft(d, i + 1)
            for j in range(1 << i):
                d[j] = d[j + (1 << i)]
                d[j + (1 << i)] = Mint(0)
            fft(d, i + 1)
            for j in range(1 << (i + 1)):
                d[j] *= ee[j]
            ifft(d, i + 1)
            for j in range(1 << i, min(1 << (i + 1), n + 1)):
                res.c[j] = d[j] * im
            if im.n & 1:
                im.n += mod
            im.n //= 2
            if im.n & 1:
                im.n += mod
            im.n //= 2
        return res

    def sqrt(self, n=-1):
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        assert self.c[0] == 1
        if n == 0:
            res = Poly(0)
            res.c[0] = 1
            return res
        k = 32 - (n).bit_length()
        assert k <= K
        g = Poly((1 << k) - 1)
        d = [Mint(0)] * (1 << (k + 1))
        ee = [Mint(0)] * (1 << (k + 1))
        res = Poly(n)
        res.c[0] = 1
        y = (mod + 1) // 2
        if y & 1:
            y += mod
        y //= 2
        if y & 1:
            y += mod
        y //= 2
        im = Mint(mod - y)
        for i in range(k):
            for j in range(1 << (k - i)):
                t = (1 << (k - i)) + j
                g.c = [self.c[(1 << k) - i - l - 1] for l in range(1 << i)]
                gg = g.c
                d[j] = res.c[j]
                ee[j] = gg[j]
                d[j + (1 << i)] = 0
                ee[j + (1 << i)] = 0
            fft(d, i + 2)
            fft(ee, i + 2)
            for j in range(1 << (i + 2)):
                d[j] *= ee[j]
            ifft(d, i + 2)
            for j in range(1 << (i + 1)):
                d[j] = d[j + (1 << (i + 1))]
                d[j + (1 << (i + 1))] = Mint(0)
            fft(d, i + 2)
            for j in range(1 << (i + 2)):
                d[j] *= ee[j]
            ifft(d, i + 2)
            for j in range(1 << (i + 1)):
                res.c[j + (1 << i)] = d[j] * im
            if im.n & 1:
                im.n += mod
            im.n //= 2
        return res

    def exp(self, n=-1):
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        assert self.c[0] == 0
        if n == 0:
            res = Poly(0)
            res.c[0] = 1
            return res
        k = 32 - (n).bit_length()
        assert k <= K
        A = Poly(1 << k)
        A.c[0] = 1
        A.c[1] = (k - 2) % mod
        A.c[2] = 1
        B = A.log()
        for i in range(len(B.c)):
            B.c[i] *= Mint(n)
        C = B.exp()
        ans = Mint(1).pow(n)
        for i in range(len(C.c)):
            ans -= C.c[i]
        ans *= Mint(n).pow(n)
        return ans

    def log(self, n=-1):
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        assert self.c[0] == 1
        k = 32 - (n).bit_length()
        assert k <= K
        B = Poly()
        B.c = list(self.c)
        B = B.inv(n)
        dQ = B.deg()
        while dQ >= 0 and B.c[dQ] == 0:
            dQ -= 1
        assert B.c[dQ] != 0
        if dQ > n:
            return Poly()
        P = Poly(min(dQ, n - dQ))
        for j in range(min(dQ, n - dQ) + 1):
            P.c[j] = B.c[dQ - j]
        k = 32 - (n - dQ).bit_length()
        assert k <= K + 1
        d = [Mint(0)] * (1 << k)
        e = [Mint(0)] * (1 << k)
        for i in range(P.deg() + 1):
            d[i] = P.c[i]
        fft(d, k)
        for i in range(Q.deg() + 1):
            e[i] = Q.c[i]
        fft(e, k)
        for i in range(1 << k):
            d[i] *= e[i]
        ifft(d, k)
        im = Mint((mod + 1) // 2).pow(k)
        dR = -1
        for i in range(Q.deg()):
            d[i] = self.c[i] - d[i] * im
            if d[i] != 0:
                dR = i
        self.c = d[:dR + 1]
        return self

    def quotient(self, Q):
        assert Q.deg() >= 0
        if self.deg() < 0:
            return self
        dP = self.deg()
        while dP >= 0 and self.c[dP] == 0:
            dP -= 1
        if self.c[dP] == 0:
            return Poly()
        dQ = Q.deg()
        while dQ >= 0 and Q.c[dQ] == 0:
            dQ -= 1
        assert Q.c[dQ] != 0
        if dQ > dP:
            return Poly()
        RQ = Poly(min(dQ, dP - dQ))
        for j in range(min(dQ, dP - dQ) + 1):
            RQ.c[j] = Q.c[dQ - j]
        k = 32 - (dP - dQ).bit_length()
        assert k <= K + 1
        d = [Mint(0)] * (1 << k)
        e = [Mint(0)] * (1 << k)
        for i in range(dP - dQ + 1):
            d[i] = self.c[dP - i]
        RQ = RQ.inv(dP - dQ)
        for i in range(RQ.deg() + 1):
            e[i] = RQ.c[i]
        fft(d, k)
        fft(e, k)
        for i in range(1 << k):
            d[i] *= e[i]
        ifft(d, k)
        im = Mint((mod + 1) // 2).pow(k)
        Q.c = d[:dP - dQ + 1]
        return self

    def eval(self, x):
        res = Mint(0)
        for i in range(self.deg(), -1, -1):
            res *= x
            res += self.c[i]
        return res

    def eval2(self, P):
        m = len(P)
        if m <= (1 << _ls):
            v = [self.eval(x) for x in P]
            return v
        k = 32 - (m - 1).bit_length()
        v = [Mint(0)] * m
        w = [Mint(0)] * m
        for i in range(m):
            v[i] = self.eval(P[i])
        fft(v, k)
        for i in range(m):
            w[i] = v[i]
        return w

    def interpolation(self, a, b):
        m = len(a)
        assert len(b) == m
        return Poly()

def fft(a, k):
    u = 1
    v = 1 << (k - 1)
    for i in range(k, 0, -1):
        for jh in range(u):
            wj = Mint(3).pow(jh)
            for j in range(jh << i, jh << i | v):
                Ajv = wj * a[j + v]
                a[j + v] = a[j] - Ajv
                a[j] += Ajv
        u <<= 1
        v >>= 1

def ifft(a, k):
    u = 1 << (k - 1)
    v = 1
    for i in range(1, k + 1):
        for jh in range(u):
            wj = Mint(332748118).pow(jh)
            for j in range(jh << i, jh << i | v):
                Ajv = a[j] - a[j + v]
                a[j] += a[j + v]
                a[j + v] = wj * Ajv
        u >>= 1
        v <<= 1

def middle_product(n, lhs, rhs):
    dl = lhs.deg()
    while lhs.c[dl] == 0:
        dl -= 1
    assert rhs.deg() <= n + dl
    k = 32 - (dl + n).bit_length()
    P = Poly((1 << k) - 1)
    Q = Poly((1 << k) - 1)
    for i in range(dl + 1):
        P.c[i] = lhs.c[dl - i]
    for i in range(rhs.deg() + 1):
        Q.c[i] = rhs.c[i]
    fft(P.c, k)
    fft(Q.c, k)
    for i in range(1 << k):
        P.c[i] *= Q.c[i]
    ifft(P.c, k)
    im = Mint((mod + 1) // 2).pow(k)
    Q.c = P.c[:n + 1]
    return Q

def uptree(C, T):
    m = len(C)
    k = 32 - (m - 1).bit_length()
    C = [Poly([C[i]]) for i in range(m)]
    for i in range(k, 0, -1):
        for j in range(1 << (k - i)):
            C[j] = T[(1 << (k - i)) + 2 * j + 1] * C[2 * j] + T[(1 << (k - i)) + 2 * j] * C[2 * j + 1]
    return C[0]

def tuptree(B, T):
    m = B.deg() + 1
    k = 32 - (m - 1).bit_length()
    C = [Poly([B.c[i]]) for i in range(m)]
    for i in range(k, 0, -1):
        for j in range((1 << (k - i)) - 1, -1, -1):
            n = (1 << (i - 1)) - 1
            C[2 * j + 1] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j], C[j])
            C[2 * j] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j + 1], C[j])
    return [C[i].c[0] for i in range(m)]

def solve():
    n, k = map(int, input().split())
    hs = list(map(int, input().split()))

    cnt = 0
    for i in range(n):
        if hs[i] == hs[(i + 1) % n]:
            cnt += 1

    if cnt == n:
        print(0)
        return

    A = Poly(2 * 10**5 + 1000)
    A.c[0] = 1
    A.c[1] = (k - 2) % mod
    A.c[2] = 1

    B = A.log()
    for i in range(len(B.c)):
        B.c[i] *= Mint(n - cnt)

    C = B.exp()

    ans = Mint(k).pow(n - cnt)
    for i in range(n - cnt + 1):
        ans -= C.c[i]

    ans *= Mint(k).pow(cnt)
    print(ans.n)

solve()
