from typing import List, Tuple
import sys
from collections import defaultdict

def gcd(a: int, b: int) -> int:
    return gcd(b, a % b) if b else a

def lcm(a: int, b: int) -> int:
    return a // gcd(a, b) * b

def inverse(a: int, mod: int) -> int:
    return pow(a, mod - 2, mod)

class ModInt:
    def __init__(self, value: int, mod: int):
        self.mod = mod
        self.value = value % mod

    def __add__(self, other):
        return ModInt((self.value + other.value) % self.mod, self.mod)

    def __sub__(self, other):
        return ModInt((self.value - other.value) % self.mod, self.mod)

    def __mul__(self, other):
        return ModInt((self.value * other.value) % self.mod, self.mod)

    def __truediv__(self, other):
        return self * inverse(other.value, self.mod)

    def __repr__(self):
        return str(self.value)

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
    dp[0][1] = ModInt(1, mod)

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
                p = ModInt(wz if dz == -1 else wo, mod) * eps
                ndp[nz][-dz] += dp[z][-dz] * p
                ndp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * dp[z][1 + dz]
        dp = ndp

    cz = ModInt(0, mod)
    co = ModInt(0, mod)
    for i in range(m + 1):
        cz += dp[i][0]
        co += dp[i][1]

    for i in range(n):
        print(w[i] * (cz if a[i] == 0 else co))

if __name__ == "__main__":
    main()
