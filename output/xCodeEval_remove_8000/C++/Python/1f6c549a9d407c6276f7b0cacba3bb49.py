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
        self.n = (self.n + other.n) % mod
        return self

    def __isub__(self, other):
        self.n = (self.n - other.n) % mod
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
        return Mint(self.n - other.n)

    def __add__(self, other):
        return Mint(self.n + other.n)

    def __mul__(self, other):
        return Mint(self.n * other.n)

    def __floordiv__(self, other):
        return Mint(self.n * other.inv().n)

    def pow(self, n):
        r = Mint(1)
        x = self
        while n:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r

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
            self.c = [Mint(0)]
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
        r = Poly()
        r += self
        r += other
        return r

    def __sub__(self, other):
        r = Poly()
        r += self
        r -= other
        return r

    def __mul__(self, other):
        r = Poly()
        r += self
        r *= other
        return r

    def __mod__(self, other):
        r = Poly()
        r += self
        r %= other
        return r

    def inv(self, n=-1):
        assert self.c[0] != 0
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
                wj = w[j]
                for l in range(j << i, j << i + 1):
                    Ajv = wj * self.c[l + (1 << i)]
                    self.c[l + (1 << i)] = self.c[l] - Ajv
                    self.c[l] += Ajv
            u <<= 1
            v >>= 1
        return r

    def sqrt(self, n=-1):
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        assert self.c[0] == 1
        if n == 0:
            r = Poly(0)
            r.c[0] = 1
            return r
        k = 32 - n.bit_length()
        assert k <= K
        g = Poly((1 << k) - 1)
        d = [Mint(0)] * (1 << k)
        e = [Mint(0)] * (1 << (k - 1))
        f = [Mint(0)] * (1 << k)
        gg = [Mint(0)] * (1 << k)
        G = [Mint(0)] * (1 << k)
        f[0] = 1
        f[1] = self.c[1]
        g[0] = 1
        G[0] = G[1] = 1
        y = (mod + 1) // 2
        if y & 1:
            y += mod
        y //= 2
        if y & 1:
            y += mod
        y //= 2
        im = Mint(mod - y)
        for i in range(k):
            for j in range(1 << i):
                ff[j] = f[j] * im
            fft(ff, i + 1)
            for j in range(1 << i):
                gg[j] = g[j]
                gg[j + (1 << i)] = v[j << (K - i)] * g[j]
            fft(gg, i + 1)
            for j in range(1 << (i + 1)):
                gg[j] *= gg[j] * ff[j]
            ifft(gg, i + 1)
            for j in range(1 << i):
                g[j + (1 << i)] = -gg[j]
                gg[j] = self.c[j + 1] * (2 * j + 2)
            gg[(1 << i) - 1] = 0
            fft(gg, i)
            for j in range(1 << i):
                gg[j] *= ff[j]
            ifft(gg, i)
            tmp = -gg[(1 << i) - 1]
            for j in range((1 << i) - 1, -1, -1):
                gg[j] = f[j] * j - gg[j - 1]
            gg[0] = tmp
            fft(gg, i + 1)
            for j in range(1 << i):
                G[j] = g[j]
            fft(G, i + 1)
            for j in range(1 << (i + 1)):
                gg[j] *= G[j]
            ifft(gg, i + 1)
            for j in range(1 << i):
                gg[j] = self.c[j + (1 << i)] - gg[j] * minv[(1 << i) + j] * im
            fft(gg, i + 1)
            for j in range(1 << (i + 1)):
                ff[j] *= gg[j]
            ifft(ff, i + 1)
            for j in range(1 << i):
                f[j + (1 << i)] = ff[j]
            if im.n & 1:
                im.n += mod
            im.n //= 2
        r = Poly(n)
        for i in range(n + 1):
            r.c[i] = f[i]
        return r

    def exp(self, n=-1):
        if n == -1:
            n = self.deg()
        if n == -1:
            return self
        assert self.c[0] == 0
        if n == 0:
            r = Poly(0)
            r.c[0] = 1
            return r
        k = 32 - n.bit_length()
        assert k <= K
        A = Poly(1 << k)
        A.c[0] = 1
        A.c[1] = (k - 2) % mod
        A.c[2] = 1
        B = A.log()
        for i in range(len(B.c)):
            B.c[i] *= Mint(n)
        C = B.exp()
        ans = Mint(k).pow(n)
        for i in range(n + 1):
            ans -= C.c[i]
        ans *= Mint(k).pow(n)
        return ans

    def quotient(self, Q):
        assert Q.deg() >= 0
        if self.deg() < 0:
            return self
        dP = self.deg()
        while dP and self.c[dP] == 0:
            dP -= 1
        if self.c[dP] == 0:
            return Poly()
        dQ = Q.deg()
        while dQ and Q.c[dQ] == 0:
            dQ -= 1
        assert Q.c[dQ] != 0
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
        return self

    def __imod__(self, Q):
        if Q.deg() > self.deg():
            return self
        if Q.deg() < 32:
            dQ = Q.deg()
            while dQ and Q.c[dQ] == 0:
                dQ -= 1
            assert Q.c[dQ] != 0
            for i in range(self.deg(), dQ - 1, -1):
                if self.c[i] == 0:
                    continue
                x = self.c[i] // Q.c[dQ]
                self.c[i] = 0
                for j in range(1, dQ + 1):
                    self.c[i - j] -= x * Q.c[dQ - j]
            dP = dQ - 1
            while dP >= 0 and self.c[dP] == 0:
                dP -= 1
            self.c = self.c[:dP + 1]
            return self
        P = self.quotient(Q)
        k = 32 - self.deg().bit_length()
        rp = [Mint(0)] * (1 << k)
        for j in range(self.deg() + 1):
            rp[j] = self.c[j]
        rq = [Mint(0)] * (1 << k)
        for i in range(self.deg() + 1):
            rq[i] = P.c[i]
        fft(rp, k)
        fft(rq, k)
        rp *= rq
        ifft(rp, k)
        im = Mint((mod + 1) // 2).pow(k)
        dR = -1
        for i in range(self.deg(), -1, -1):
            rp[i] = self.c[i] - rp[i] * im
            if rp[i] != 0:
                dR = i
        self.c = rp[:dR + 1]
        return self

    def eval(self, x):
        r = Mint(0)
        for i in range(self.deg(), -1, -1):
            r *= x
            r += self.c[i]
        return r

def fft(a, k):
    u = 1
    v = 1 << (k - 1)
    for i in range(k, 0, -1):
        for jh in range(u):
            wj = w[jh]
            for j in range(jh << i, jh << i + 1):
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
            wj = y[jh]
            for j in range(jh << i, jh << i + 1):
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
    k = 32 - (dl + n + 1).bit_length()
    assert k <= K + 1
    P = Poly((1 << k) - 1)
    Q = Poly((1 << k) - 1)
    for i in range(dl + 1):
        P.c[i] = lhs.c[dl - i]
    for i in range(rhs.deg() + 1):
        Q.c[i] = rhs.c[i]
    fft(P.c, k)
    fft(Q.c, k)
    P.c *= Q.c
    ifft(P.c, k)
    im = Mint((mod + 1) // 2).pow(k)
    Q.c = P.c[:n + 1]
    return Q

def uptree(C, T):
    m = len(C)
    k = 32 - (m - 1).bit_length()
    C = [Poly([x]) for x in C]
    for i in range(k, 0, -1):
        for j in range((1 << (k - i)) - 1, -1, -1):
            n = (1 << (i - 1)) - 1
            C[2 * j + 1] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j], C[j])
            C[2 * j] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j + 1], C[j])
    return C[0]

def tuptree(B, T):
    m = B.deg() + 1
    k = 32 - (m - 1).bit_length()
    C = [Poly([x]) for x in B.c]
    for i in range(1, k + 1):
        for j in range((1 << (k - i)) - 1, -1, -1):
            n = (1 << (i - 1)) - 1
            C[2 * j + 1] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j], C[j])
            C[2 * j] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j + 1], C[j])
    return [C[i].c[0] for i in range(m)]

def gen_tree(P):
    m = len(P)
    k = 32 - (m - 1).bit_length()
    T = [Poly([Mint(0)])] * (1 << (k + 1))
    FT = [[Mint(0)] * (1 << k) for _ in range(1 << (k + 1))]
    w = [Mint(0)] * (1 << _ls)
    w[1] = 1
    fft(w, _ls)
    if _ls == 0:
        w[0] = 1
    for i in range(1 << (k - _ls)):
        t = (1 << (k - _ls)) + i
        T[t] = Poly([Mint(0)] * (_ls + 1))
        T[t].c[1 << _ls] = 1
        for j in range(1 << _ls):
            T[t].c[j] = 1
            for l in range(1 << _ls):
                T[t].c[j] *= w[j] - (P[(i << _ls) + l] if (i << _ls) + l < m else 0)
            T[t].c[j] -= 1
    im = Mint((mod + 1) // 2).pow(_ls)
    for i in range(_ls + 1, k + 1):
        for j in range(1 << (k - i)):
            t = (1 << (k - i)) + j
            T[t] = Poly([Mint(0)] * (1 << i))
            FT[2 * t] = [T[2 * t].c[l] + 1 for l in range(1 << (i - 1))]
            ifft(T[2 * t].c, i - 1)
            for l in range(1 << (i - 1)):
                T[2 * t].c[l] *= im
            for l in range(1 << (i - 1)):
                FT[2 * t][(1 << (i - 1)) + l] = T[2 * t].c[l] * fft.v[l << (K - i + 1)]
            FT[2 * t][1 << (i - 1)] -= 1
            fft(FT[2 * t][(1 << (i - 1)):], i - 1)
            FT[2 * t + 1] = [T[2 * t + 1].c[l] + 1 for l in range(1 << (i - 1))]
            ifft(T[2 * t + 1].c, i - 1)
            for l in range(1 << (i - 1)):
                T[2 * t + 1].c[l] *= im
            for l in range(1 << (i - 1)):
                FT[2 * t + 1][(1 << (i - 1)) + l] = T[2 * t + 1].c[l] * fft.v[l << (K - i + 1)]
            FT[2 * t + 1][1 << (i - 1)] -= 1
            fft(FT[2 * t + 1][(1 << (i - 1)):], i - 1)
            for l in range(1 << i):
                T[t].c[l] = FT[2 * t][l] * FT[2 * t + 1][l] - 1
    ifft(T[1].c, k)
    FT[1] = [T[1].c[l] * im for l in range(1 << k)]
    return T

def interpolation(a, b):
    m = len(a)
    assert len(b) == m
    return Poly()

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

    ans = Mint(k % mod).pow(n - cnt)
    for i in range(n - cnt + 1):
        ans -= C.c[i]

    ans *= Mint(k % mod).pow(cnt)
    print(ans.n)

solve()
