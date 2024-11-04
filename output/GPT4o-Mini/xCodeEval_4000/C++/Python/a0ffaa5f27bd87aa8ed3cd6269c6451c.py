import sys
from collections import defaultdict

class Mint:
    def __init__(self, v=0, mod=1):
        self.mod = mod
        self._v = v % mod if v >= 0 else (v % mod + mod) % mod

    def __add__(self, other):
        return Mint(self._v + other._v, self.mod)

    def __sub__(self, other):
        return Mint(self._v - other._v, self.mod)

    def __mul__(self, other):
        return Mint(self._v * other._v, self.mod)

    def __truediv__(self, other):
        return self * other.inv()

    def __eq__(self, other):
        return self._v == other._v

    def __repr__(self):
        return str(self._v)

    def pow(self, n):
        assert n >= 0
        x = self
        r = Mint(1, self.mod)
        while n:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r

    def inv(self):
        return self.pow(self.mod - 2)

def safe_mod(x, m):
    x %= m
    if x < 0:
        x += m
    return x

def barrett(m):
    return (-1 // m) + 1

def comb(n, k, C):
    if k < 0 or k > n:
        return Mint(0)
    return C[n][k]

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    m = int(data[1])
    mod = int(data[2])

    C = [[Mint(0, mod) for _ in range(n + 1)] for _ in range(n + 1)]
    C[0][0] = Mint(1, mod)

    for i in range(1, n + 1):
        C[i][0] = Mint(1, mod)
        for j in range(1, n + 1):
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

    g = [Mint(0, mod) for _ in range(n + 1)]
    for i in range(n + 1):
        g[i] = Mint(i * (i + 1) // 2, mod)

    f = [(Mint(0, mod), Mint(0, mod)) for _ in range(n + 1)]
    f[0] = (Mint(1, mod), Mint(0, mod))

    for i in range(1, n + 1):
        for j in range(i):
            z = f[j][0] * f[i - 1 - j][0] * C[i - 1][j]
            f[i] = (f[i][0] + z * Mint(i + 1, mod), 
                     f[i][1] + z * (g[j] + g[i - 1 - j]) + 
                     (f[i - 1 - j][0] * f[j][1] + f[j][0] * f[i - 1 - j][1]) * C[i - 1][j] * Mint(i + 1, mod))

    dp = [[(Mint(0, mod), Mint(0, mod)) for _ in range(m + 1)] for _ in range(n + 2)]
    dp[0][0] = (Mint(1, mod), Mint(0, mod))

    for l in range(n + 1):
        for r in range(l + 1, n + 2):
            di = r - l - 1
            for i in range(m + 1 - di):
                z = dp[l][i][0] * f[di][0]
                dp[r][i + di] = (dp[r][i + di][0] + z * comb(i + di, di, C),
                                 dp[r][i + di][1] + (dp[l][i][1] * f[di][0] + dp[l][i][0] * f[di][1]) * comb(i + di, di, C)

    print(dp[n + 1][m][1])

if __name__ == "__main__":
    main()
