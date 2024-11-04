import sys
import numpy as np

def solve():
    n, r = map(int, input().split())
    f = [0] * 55
    s = [0] * 55
    p = [0.0] * 55

    for i in range(n):
        f[i], s[i], p[i] = map(float, input().split())
        p[i] *= 0.01

    K = 50 * 100 + 1
    lp = 0
    rp = 1e8

    for _ in range(100):
        z = (lp + rp) * 0.5
        dans = np.full((55, K), z)

        for i in range(n - 1, -1, -1):
            for j in range(int(f[i])):
                dans[i][j] = z
            fi = int(f[i])
            si = int(s[i])
            pi = p[i]

            for j in range(fi, si):
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + z) * (1 - pi))
            for j in range(si, K):
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + dans[i + 1][j - si]) * (1 - pi))

        if dans[0][r] < z - 1e-10:
            rp = z
        else:
            lp = z

    print(f"{(lp + rp) * 0.5:.10f}")

if __name__ == "__main__":
    solve()
