from typing import List, Tuple
from functools import lru_cache

MOD = 998244353

class ModInt:
    def __init__(self, value: int):
        self.value = value % MOD

    def __add__(self, other):
        return ModInt(self.value + other.value)

    def __sub__(self, other):
        return ModInt(self.value - other.value)

    def __mul__(self, other):
        return ModInt(self.value * other.value)

    def __truediv__(self, other):
        return self * pow(other.value, MOD - 2, MOD)

    def __repr__(self):
        return str(self.value)

def input_ints() -> Tuple[int, int]:
    return tuple(map(int, input().split()))

def input_bools(n: int) -> List[bool]:
    return list(map(bool, map(int, input().split())))

def input_ints_list(n: int) -> List[int]:
    return list(map(int, input().split()))

def main():
    n, m = input_ints()
    a = input_bools(n)
    w = input_ints_list(n)

    zw = sum(w[i] for i in range(n) if not a[i])
    ow = sum(w[i] for i in range(n) if a[i])
    s = zw + ow

    inv = [ModInt(0)] * (2 * m + 1)
    for d in range(-m, m + 1):
        if s + d > 0:
            inv[d + m] = ModInt(1) / ModInt(s + d)

    dp = [[ModInt(0) for _ in range(2)] for _ in range(m + 1)]
    dp[0][0] = ModInt(1)

    for i in range(m):
        ndp = [[ModInt(0) for _ in range(2)] for _ in range(m + 1)]
        for z in range(i + 1):
            o = i - z
            wz = zw - z
            wo = ow + o
            if wz < 0:
                continue
            for dz in range(-1, 1):
                nwz = wz + dz
                nz = z + (-dz)
                if nwz < 0:
                    continue
                eps = inv[wz + wo - s + m]
                p = (ModInt(wz) if dz == -1 else ModInt(wo)) * eps
                ndp[nz][-dz] += dp[z][-dz] * p
                ndp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * dp[z][1 + dz]
        dp = ndp

    cz = sum(dp[i][0] for i in range(m + 1))
    co = sum(dp[i][1] for i in range(m + 1))

    for i in range(n):
        print(w[i] * (cz if a[i] == 0 else co))

if __name__ == "__main__":
    main()
