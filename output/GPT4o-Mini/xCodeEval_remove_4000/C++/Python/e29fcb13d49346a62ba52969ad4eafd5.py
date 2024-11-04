from typing import List, Tuple
from functools import lru_cache
import sys

input = sys.stdin.read

def gcd(a: int, b: int) -> int:
    return gcd(b, a % b) if b else a

def lcm(a: int, b: int) -> int:
    return a // gcd(a, b) * b

@lru_cache(None)
def inverse(a: int, mod: int) -> int:
    return id1(a, mod)[0]

def id1(a: int, b: int) -> Tuple[int, int]:
    if b == 0:
        return 1, 0
    g = gcd(a, b)
    da = abs(b) // g
    p = id1(b, a % b)
    x = (da + p[1] % da) % da
    y = (g - a * x) // b
    return x, y

class ModInt:
    def __init__(self, value: int, mod: int):
        self.mod = mod
        self.v = value % mod

    def __add__(self, other):
        return ModInt((self.v + other.v) % self.mod, self.mod)

    def __sub__(self, other):
        return ModInt((self.v - other.v) % self.mod, self.mod)

    def __mul__(self, other):
        return ModInt((self.v * other.v) % self.mod, self.mod)

    def __truediv__(self, other):
        return self * inverse(other.v, self.mod)

    def __repr__(self):
        return str(self.v)

def main():
    mod = 998244353
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    w = list(map(int, input().split()))

    zw = sum(w[i] for i in range(n) if a[i] == 0)
    ow = sum(w[i] for i in range(n) if a[i] == 1)
    s = zw + ow

    inv = [ModInt(0, mod) for _ in range(2 * m + 1)]
    for d in range(-m, m + 1):
        if s + d > 0:
            inv[d + m] = ModInt(1, mod) / ModInt(s + d, mod)

    dp = [[ModInt(0, mod) for _ in range(2)] for _ in range(m + 1)]
    dp[0][0] = ModInt(1, mod)

    for i in range(m):
        ndp = [[ModInt(0, mod) for _ in range(2)] for _ in range(m + 1)]
        for z in range(i + 1):
            o = i - z
            wz = zw - z
            wo = ow + o
            if wz < 0:
                continue
            for dz in range(-1, 1):
                nwz = wz + dz
                nz = z - dz
                if nwz < 0:
                    continue
                eps = inv[wz + wo - s + m]
                p = ModInt(nwz if dz == -1 else wo, mod) * eps
                ndp[nz][-dz] += dp[z][-dz] * p
                ndp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * dp[z][1 + dz]
        dp = ndp

    cz = sum(dp[i][0] for i in range(m + 1))
    co = sum(dp[i][1] for i in range(m + 1))

    for i in range(n):
        print(w[i] * (cz if a[i] == 0 else co))

if __name__ == "__main__":
    main()
