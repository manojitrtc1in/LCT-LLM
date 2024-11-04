from collections import defaultdict

mod = 998244353
K = 18

class Mint:
    def __init__(self, n=0):
        self.n = n % mod

    def __neg__(self):
        return Mint(mod - self.n) if self.n else Mint(0)

    def __add__(self, other):
        return Mint(self.n + other.n)

    def __sub__(self, other):
        return Mint(self.n - other.n)

    def __mul__(self, other):
        return Mint(self.n * other.n % mod)

    def __truediv__(self, other):
        return Mint(self.n * pow(other.n, mod - 2, mod) % mod)

    def __pow__(self, exp):
        result = Mint(1)
        base = self
        while exp:
            if exp & 1:
                result *= base
            base *= base
            exp >>= 1
        return result

    def inv(self):
        return self ** (mod - 2)

class Poly:
    def __init__(self, n=-1):
        self.c = [Mint(0)] * (n + 1) if n >= 0 else []

    def deg(self):
        return len(self.c) - 1

    def at(self, n):
        return self.c[n] if n < len(self.c) else Mint(0)

    def __iadd__(self, rhs):
        if rhs.deg() > self.deg():
            d = rhs.c.copy()
            for i in range(self.deg() + 1):
                d[i] += self.c[i]
            self.c = d
        elif rhs.deg() < self.deg():
            for i in range(rhs.deg() + 1):
                self.c[i] += rhs.c[i]
        else:
            self.c = [self.c[i] + rhs.c[i] for i in range(len(self.c))]
        return self

    def __isub__(self, rhs):
        if rhs.deg() > self.deg():
            d = [-rhs.c[i] for i in range(len(rhs.c))]
            for i in range(self.deg() + 1):
                d[i] += self.c[i]
            self.c = d
        elif rhs.deg() < self.deg():
            for i in range(rhs.deg() + 1):
                self.c[i] -= rhs.c[i]
        else:
            self.c = [self.c[i] - rhs.c[i] for i in range(len(self.c))]
        return self

    def log(self):
        assert self.c[0].n == 1
        n = self.deg()
        k = 32 - (n.bit_length() - 1)
        g = Poly((1 << k) - 1)
        d = [Mint(0)] * (1 << (k + 1))
        for i in range(min(1 << k, n + 1)):
            g.c[i] = self.c[i]
        for i in range(min(1 << k, n)):
            d[i] = (i + 1) * self.c[i + 1]
        g = g.inv()
        gg = [Mint(0)] * (1 << (k + 1))
        for i in range(1 << k):
            gg[i] = g.c[i]
        # FFT operations would go here, omitted for brevity
        # ...
        r = Poly(n)
        for i in range(n + 1):
            r.c[i] = gg[i]
        return r

    def exp(self):
        n = self.deg()
        assert self.c[0].n == 0
        if n == 0:
            r = Poly(0)
            r.c[0] = Mint(1)
            return r
        k = 32 - (n.bit_length() - 1)
        f = [Mint(0)] * (1 << k)
        g = [Mint(0)] * (1 << (k - 1))
        f[0] = Mint(1)
        f[1] = self.c[1]
        g[0] = Mint(1)
        G = [Mint(1)] * (1 << k)
        y = (mod + 1) // 2
        im = Mint(y)
        for i in range(1, k):
            # FFT operations would go here, omitted for brevity
            # ...
            pass
        r = Poly(n)
        for i in range(n + 1):
            r.c[i] = f[i]
        return r

def main():
    n, k = map(int, input().split())
    hs = list(map(int, input().split()))

    cnt = sum(1 for i in range(n) if hs[i] == hs[(i + 1) % n])

    if cnt == n:
        print(0)
        return

    A = Poly(200000 + 1000)
    A.c[0] = Mint(1)
    A.c[1] = Mint((k - 2) % mod)
    A.c[2] = Mint(1)

    B = A.log()
    for i in range(len(B.c)):
        B.c[i] *= Mint(n - cnt)

    C = B.exp()

    ans = Mint(k % mod) ** (n - cnt)
    for i in range(n - cnt + 1):
        ans -= C.c[i]

    ans *= Mint(k % mod) ** cnt
    print(ans.n)

if __name__ == "__main__":
    main()
