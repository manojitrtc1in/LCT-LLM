import sys
from typing import List, Tuple

def solve() -> int:
    n, r = map(int, input().split())
    f = [0] * n
    s = [0] * n
    p = [0] * n

    for i in range(n):
        f[i], s[i], p[i] = map(int, input().split())
        p[i] *= 0.01

    K = 50 * 100 + 1

    lp = 0
    rp = 1e8
    for _ in range(100):
        z = (lp + rp) * 0.5
        dans = [[z] * K for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(f[i]):
                dans[i][j] = z
            fi = f[i]
            si = s[i]
            pi = p[i]
            for j in range(fi, si):
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + z) * (1 - pi))
            for j in range(si, K):
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + dans[i + 1][j - si]) * (1 - pi))
        if dans[0][r] < z - 1e-10:
            rp = z
        else:
            lp = z
    print("{:.10f}".format((lp + rp) * 0.5))
    return 0

if __name__ == "__main__":
    solve()
