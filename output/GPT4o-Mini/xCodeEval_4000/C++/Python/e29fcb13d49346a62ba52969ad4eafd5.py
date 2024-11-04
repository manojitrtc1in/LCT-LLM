from sys import stdin, stdout
from collections import defaultdict
from math import gcd

def modinv(a, mod):
    m0, x0, x1 = mod, 0, 1
    if mod == 1:
        return 0
    while a > 1:
        q = a // mod
        m0, mod = mod, a % mod
        a, x0, x1 = m0, x1 - q * x0, x0
    return x1 + mod if x1 < 0 else x1

def main():
    mod = 998244353
    n, m = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))
    w = list(map(int, stdin.readline().split()))

    zw = sum(w[i] for i in range(n) if a[i] == 0)
    ow = sum(w[i] for i in range(n) if a[i] == 1)
    s = zw + ow

    inv = [0] * (2 * m + 1)
    for d in range(-m, m + 1):
        if s + d > 0:
            inv[d + m] = modinv(s + d, mod)

    dp = [[0] * 2 for _ in range(m + 1)]
    dp[0][1] = 1

    for i in range(m):
        ndp = [[0] * 2 for _ in range(m + 1)]
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
                p = (wz if dz == -1 else wo) * eps % mod
                ndp[nz][-dz] = (ndp[nz][-dz] + dp[z][-dz] * p) % mod
                ndp[nz][1 + dz] = (ndp[nz][1 + dz] + (p + (2 * dz + 1) * eps) * dp[z][1 + dz]) % mod

        dp = ndp

    cz = sum(dp[i][0] for i in range(m + 1)) % mod
    co = sum(dp[i][1] for i in range(m + 1)) % mod

    for i in range(n):
        stdout.write(f"{w[i] * (cz if a[i] == 0 else co)}\n")

if __name__ == "__main__":
    main()
