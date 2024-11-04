class Mint:
    def __init__(self, n=0, MOD=998244353):
        self.MOD = MOD
        self.n = n % MOD

    def __neg__(self):
        return Mint(self.MOD - self.n if self.n else 0, self.MOD)

    def __add__(self, other):
        return Mint((self.n + other.n) % self.MOD, self.MOD)

    def __sub__(self, other):
        return Mint((self.n - other.n) % self.MOD, self.MOD)

    def __mul__(self, other):
        return Mint(self.n * other.n % self.MOD, self.MOD)

    def __truediv__(self, other):
        return Mint(self.n * pow(other.n, self.MOD - 2, self.MOD) % self.MOD, self.MOD)

    def __pow__(self, exp):
        result = Mint(1, self.MOD)
        base = self
        while exp:
            if exp % 2:
                result *= base
            base *= base
            exp //= 2
        return result

    def __eq__(self, other):
        return self.n == other.n

    def __repr__(self):
        return str(self.n)


class Poly:
    def __init__(self, n=-1, MOD=998244353):
        self.MOD = MOD
        self.c = [Mint(0, MOD) for _ in range(n + 1)] if n >= 0 else []

    def deg(self):
        return len(self.c) - 1

    def __getitem__(self, index):
        if index < len(self.c):
            return self.c[index]
        return Mint(0, self.MOD)

    def __iadd__(self, other):
        if other.deg() > self.deg():
            d = other.c[:]
            for i in range(self.deg() + 1):
                d[i] += self.c[i]
            self.c = d
        elif other.deg() < self.deg():
            for i in range(other.deg() + 1):
                self.c[i] += other.c[i]
        else:
            self.c = [self.c[i] + other.c[i] for i in range(len(self.c))]
        return self

    def __isub__(self, other):
        if other.deg() > self.deg():
            d = [-x for x in other.c]
            for i in range(self.deg() + 1):
                d[i] += self.c[i]
            self.c = d
        elif other.deg() < self.deg():
            for i in range(other.deg() + 1):
                self.c[i] -= other.c[i]
        else:
            self.c = [self.c[i] - other.c[i] for i in range(len(self.c))]
        return self

    def log(self):
        assert self.c[0] == Mint(1, self.MOD)
        n = self.deg()
        g = Poly(n - 1, self.MOD)
        for i in range(1, n + 1):
            g.c[i - 1] = self.c[i] * Mint(i, self.MOD)
        return g

    def exp(self):
        assert self.c[0] == Mint(0, self.MOD)
        n = self.deg()
        if n == 0:
            r = Poly(0, self.MOD)
            r.c[0] = Mint(1, self.MOD)
            return r
        f = [Mint(0, self.MOD) for _ in range(n + 1)]
        f[0] = Mint(1, self.MOD)
        for i in range(1, n + 1):
            f[i] = self.c[i] * Mint(i, self.MOD)
        r = Poly(n, self.MOD)
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

    A = Poly(200000 + 1000, 998244353)
    A.c[0] = Mint(1, 998244353)
    A.c[1] = Mint((k - 2) % 998244353, 998244353)
    A.c[2] = Mint(1, 998244353)

    B = A.log()
    for i in range(len(B.c)):
        B.c[i] *= Mint(n - cnt, 998244353)

    C = B.exp()

    ans = Mint(k % 998244353, 998244353) ** (n - cnt)
    for i in range(n - cnt + 1):
        ans -= C[i]

    ans *= Mint(k % 998244353, 998244353) ** cnt
    print(ans.n)


if __name__ == "__main__":
    main()
