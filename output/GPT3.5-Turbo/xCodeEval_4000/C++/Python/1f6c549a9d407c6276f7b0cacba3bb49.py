mod = 998244353
K = 18

class Mint:
    def __init__(self, n=0):
        self.n = n % mod

    def __neg__(self):
        return Mint(mod - self.n)

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
        self.n = (self.n * pow(other.n, mod - 2, mod)) % mod
        return self

    def __eq__(self, other):
        return self.n == other.n

    def __ne__(self, other):
        return self.n != other.n

    def __add__(self, other):
        res = Mint(self.n)
        res += other
        return res

    def __sub__(self, other):
        res = Mint(self.n)
        res -= other
        return res

    def __mul__(self, other):
        res = Mint(self.n)
        res *= other
        return res

    def __floordiv__(self, other):
        res = Mint(self.n)
        res //= other
        return res

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
            d = [-other.c[i] for i in range(other.deg() + 1)]
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
        k = 32 - (rdeg + 1).bit_length()
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
        res = Poly(self.deg())
        res += other
        return res

    def __sub__(self, other):
        res = Poly(self.deg())
        res -= other
        return res

    def __mul__(self, other):
        res = Poly(self.deg())
        res *= other
        return res

    def pow(self, n):
        r = Poly(0)
        r.c[0] = Mint(1)
        x = Poly(self.deg())
        for i in range(self.deg() + 1):
            x.c[i] = self.c[i]
        while n > 0:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r

    def inv(self, n=-1):
        assert self.c[0] != Mint(0)
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        k = 32 - n.bit_length()
        assert k <= K
        d = [Mint(0)] * (1 << k)
        ee = [Mint(0)] * (1 << k)
        r = Poly(n)
        r.c[0] = self.c[0].inv()
        y = (mod + 1) // 2
        if y & 1:
            y += mod
        y //= 2
        im = Mint(mod - y)
        for i in range(k):
            for j in range(1 << i):
                ee[j] = r.c[j]
            fft(ee, i + 1)
            for j in range(1 << (i + 1)):
                d[j] = self.c[j] * ee[j]
            ifft(d, i + 1)
            for j in range(1 << i):
                d[j] = d[j + (1 << i)]
                d[j + (1 << i)] = Mint(0)
            fft(d, i + 1)
            for j in range(1 << (i + 1)):
                d[j] *= ee[j]
            ifft(d, i + 1)
            for j in range(1 << i, min(1 << (i + 1), n + 1)):
                r.c[j] = d[j] * im
            if im.n & 1:
                im.n += mod
            im.n //= 2
            if im.n & 1:
                im.n += mod
            im.n //= 2
        return r

    def sqrt(self, n=-1):
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        assert self.c[0] == Mint(1)
        if n == 0:
            r = Poly(0)
            r.c[0] = Mint(1)
            return r
        k = 32 - n.bit_length()
        assert k <= K
        g = Poly((1 << k) - 1)
        d = [Mint(0)] * (1 << (k + 1))
        ee = [Mint(0)] * (1 << (k + 1))
        r = Poly(n)
        r.c[0] = Mint(1)
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
                g.c[j] = self.c[(1 << k) - j]
                r.c[j] = r.c[j + (1 << k)]
            fft(g.c, i + 2)
            fft(r.c, i + 2)
            for j in range(1 << (i + 2)):
                d[j] = g.c[j] * r.c[j]
            ifft(d, i + 2)
            for j in range(1 << i):
                d[j] = d[j + (1 << (i + 1))]
                d[j + (1 << (i + 1))] = Mint(0)
            fft(d, i + 2)
            for j in range(1 << (i + 2)):
                d[j] *= g.c[j]
            ifft(d, i + 2)
            for j in range(1 << (i + 1), min(1 << (i + 2), n + 1)):
                r.c[j] = d[j] * im
            if im.n & 1:
                im.n += mod
            im.n //= 2
        return r

    def exp(self, n=-1):
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        assert self.c[0] == Mint(0)
        if n == 0:
            r = Poly(0)
            r.c[0] = Mint(1)
            return r
        k = 32 - n.bit_length()
        assert k <= K
        A = Poly(1 << k)
        A.c[0] = Mint(1)
        A.c[1] = (k - 2) % mod
        A.c[2] = 1
        B = A.log()
        for i in range(len(B.c)):
            B.c[i] *= Mint(n)
        C = B.exp()
        ans = Mint(1)
        for i in range(len(C.c)):
            ans -= C.c[i]
        ans *= Mint(n)
        return ans

    def quotient(self, Q):
        assert Q.deg() >= 0
        if self.deg() < 0:
            return self
        dP = self.deg()
        while dP >= 0 and self.c[dP] == Mint(0):
            dP -= 1
        if dP < 0:
            return Poly()
        dQ = Q.deg()
        while dQ >= 0 and Q.c[dQ] == Mint(0):
            dQ -= 1
        assert Q.c[dQ] != Mint(0)
        if dQ > dP:
            return Poly()
        RQ = Poly(min(dQ, dP - dQ))
        for j in range(min(dQ, dP - dQ) + 1):
            RQ.c[j] = Q.c[dQ - j]
        k = 32 - (dP - dQ + 1).bit_length()
        assert k <= K + 1
        rp = [Mint(0)] * (1 << k)
        for j in range(dP - dQ + 1):
            rp[j] = self.c[dP - j]
        RQ = RQ.inv(dP - dQ)
        rq = [Mint(0)] * (1 << k)
        for i in range(dP - dQ + 1):
            rq[i] = RQ.c[i]
        fft(rp, k)
        fft(rq, k)
        rq *= rp
        ifft(rq, k)
        im = Mint((mod + 1) // 2).pow(k)
        Q.c = rq[:dP - dQ + 1]
        for i in range(dP - dQ + 1):
            Q.c[i] *= im
        return Q

    def __ifloordiv__(self, Q):
        self = self.quotient(Q)
        return self

    def __mod__(self, Q):
        self //= Q
        return self

    def eval(self, x):
        r = Mint(0)
        for i in range(self.deg(), -1, -1):
            r *= x
            r += self.c[i]
        return r

    def eval2(self, P):
        m = len(P)
        if m <= (1 << _ls):
            v = [self.eval(P[i]) for i in range(m)]
            return v
        k = 32 - (m - 1).bit_length()
        v = [Mint(0)] * m
        w = [Mint(0)] * (1 << _ls)
        w[1] = Mint(1)
        fft(w, _ls)
        if _ls == 0:
            w[0] = Mint(1)
        for i in range(m):
            v[i] = self.eval(P[i])
        fft(v, k)
        fft(w, k)
        v *= w
        ifft(v, k)
        im = Mint((mod + 1) // 2).pow(k)
        for i in range(m):
            v[i] *= im
        return v

    def interpolation(self, a, b):
        m = len(a)
        assert len(b) == m
        return Poly()

    def __str__(self):
        return str(self.c)

def fft(a, k):
    u = 1
    v = 1 << (k - 1)
    for i in range(k, 0, -1):
        for jh in range(u):
            wj = Mint(3) ** (jh << (18 - i))
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
            wj = Mint(332748118) ** (jh << (18 - i))
            for j in range(jh << i, jh << i | v):
                Ajv = a[j] - a[j + v]
                a[j] += a[j + v]
                a[j + v] = wj * Ajv
        u >>= 1
        v <<= 1

def middle_product(n, lhs, rhs):
    dl = lhs.deg()
    while dl >= 0 and lhs.c[dl] == Mint(0):
        dl -= 1
    assert rhs.deg() <= n + dl
    k = 32 - (dl + n + 1).bit_length()
    assert k <= K + 1
    P = Poly(0)
    P.c = [Mint(0)] * (1 << k)
    Q = Poly(0)
    Q.c = [Mint(0)] * (1 << k)
    for i in range(dl + 1):
        P.c[i] = lhs.c[dl - i]
    for i in range(rhs.deg() + 1):
        Q.c[i] = rhs.c[i]
    fft(P.c, k)
    fft(Q.c, k)
    P.c *= Q.c
    ifft(P.c, k)
    P.c = P.c[:dl + n + 1]
    im = Mint((mod + 1) // 2).pow(k)
    for i in range(dl + n + 1):
        P.c[i] *= im
    return P

def uptree(C, T):
    m = len(C)
    k = 32 - (m - 1).bit_length()
    C = [Poly(0) for _ in range(1 << k)]
    for i in range(m):
        C[i].c = [Mint(0)] * (1 << _ls)
        C[i].c[1] = C[i]
    for i in range(k, 0, -1):
        for j in range(1 << (k - i)):
            n = (1 << (i - 1)) - 1
            C[2 * j + 1] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j], C[j])
            C[2 * j] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j + 1], C[j])
    return C[0]

def tuptree(B, T):
    m = B.deg() + 1
    k = 32 - (m - 1).bit_length()
    C = [Poly(0) for _ in range(1 << k)]
    C[0] = B
    for i in range(k, 0, -1):
        for j in range((1 << (k - i)) - 1, -1, -1):
            n = (1 << (i - 1)) - 1
            C[2 * j + 1] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j], C[j])
            C[2 * j] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j + 1], C[j])
    v = [C[i].c[0] for i in range(m)]
    return v

def gen_tree(P):
    m = len(P)
    k = 32 - (m - 1).bit_length()
    T = [Poly(0) for _ in range(1 << (k + 1))]
    FT = [Poly(0) for _ in range(1 << (k + 1))]
    w = [Mint(0)] * (1 << _ls)
    w[1] = Mint(1)
    fft(w, _ls)
    if _ls == 0:
        w[0] = Mint(1)
    for i in range(1 << (k - _ls)):
        t = (1 << (k - _ls)) + i
        T[t] = Poly(0)
        T[t].c = [Mint(0)] * ((1 << _ls) + 1)
        T[t].c[1 << _ls] = Mint(1)
        for j in range(1 << _ls):
            T[t].c[j] = Mint(1)
            for l in range(1 << _ls):
                T[t].c[j] *= w[j] - (P[(i << _ls) + l] if (i << _ls) + l < m else Mint(0))
            T[t].c[j] -= Mint(1)
    im = Mint((mod + 1) // 2).pow(_ls)
    for i in range(_ls + 1, k + 1):
        for j in range(1 << (k - i)):
            t = (1 << (k - i)) + j
            T[t] = Poly(0)
            T[t].c = [Mint(0)] * ((1 << i) + 1)
            T[t].c[1 << i] = Mint(1)
            FT[2 * t] = Poly(0)
            FT[2 * t].c = [Mint(0)] * (1 << i)
            for l in range(1 << (i - 1)):
                FT[2 * t].c[l] = T[2 * t].c[l] + Mint(1)
            ifft(T[2 * t].c, i - 1)
            for l in range(1 << (i - 1)):
                T[2 * t].c[l] *= im
            for l in range(1 << (i - 1)):
                FT[2 * t].c[(1 << (i - 1)) + l] = T[2 * t].c[l] * fft.v[l << (K - i + 1)]
            FT[2 * t].c[1 << (i - 1)] -= Mint(1)
            fft(FT[2 * t].c[(1 << (i - 1)):], i - 1)
            FT[2 * t + 1] = Poly(0)
            FT[2 * t + 1].c = [Mint(0)] * (1 << i)
            for l in range(1 << (i - 1)):
                FT[2 * t + 1].c[l] = T[2 * t + 1].c[l] + Mint(1)
            ifft(T[2 * t + 1].c, i - 1)
            for l in range(1 << (i - 1)):
                T[2 * t + 1].c[l] *= im
            for l in range(1 << (i - 1)):
                FT[2 * t + 1].c[(1 << (i - 1)) + l] = T[2 * t + 1].c[l] * fft.v[l << (K - i + 1)]
            FT[2 * t + 1].c[1 << (i - 1)] -= Mint(1)
            fft(FT[2 * t + 1].c[(1 << (i - 1)):], i - 1)
            for l in range(1 << i):
                T[t].c[l] = FT[2 * t].c[l] * FT[2 * t + 1].c[l] - Mint(1)
    fft(T[1].c, k)
    FT[1] = Poly(0)
    FT[1].c = [Mint(0)] * (1 << k)
    for l in range(1 << k):
        FT[1].c[l] = T[1].c[l] *= im
    return FT

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
    A.c[0] = Mint(1)
    A.c[1] = Mint((k - 2) % mod)
    A.c[2] = Mint(1)

    B = A.log()
    for i in range(len(B.c)):
        B.c[i] *= Mint(n - cnt)

    C = B.exp()

    ans = Mint(k % mod).pow(n - cnt)
    for i in range(len(C.c)):
        ans -= C.c[i]

    ans *= Mint(k % mod).pow(cnt)
    print(ans.n)

solve()
