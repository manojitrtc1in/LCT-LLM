import sys
from collections import deque

mod = 998244353
big = (2**63 // mod // mod - 1) * mod * mod

def sum_array(a):
    return sum(a) % mod

def mul(a, b):
    if len(a) == 0 and len(b) == 0:
        return []
    if len(a) + len(b) >= 300:
        return id2.convolve(a, b)[:len(a) + len(b) - 1]
    else:
        return id3(a, b)

def id3(a, b):
    c = [0] * (len(a) + len(b) - 1)
    for i in range(len(a)):
        for j in range(len(b)):
            c[i + j] += a[i] * b[j]
            if c[i + j] >= big:
                c[i + j] -= big
    return [x % mod for x in c]

class id2:
    P = 998244353
    mod = P
    G = 3
    wps = []

    @staticmethod
    def convolve(a, b):
        m = max(2, 1 << (len(a) + len(b) - 1).bit_length() + 2)
        id2.wps = [0] * m
        unit = pow(id2.G, (id2.P - 1) // m)
        id2.wps[0] = 1
        for p in range(1, m):
            id2.wps[p] = id2.wps[p - 1] * unit % id2.mod

        fa = id2.go(a, m, False)
        fb = id2.go(b, m, False) if a != b else fa
        for i in range(m):
            fa[i] = fa[i] * fb[i] % id2.mod
        fa = id2.go(fa, m, True)
        fa[1:m] = fa[m-1:0:-1]
        return fa

    @staticmethod
    def go(src, n, inverse):
        dst = src + [0] * (n - len(src))
        id2.fft(dst, [0] * n)
        if inverse:
            inv = id2.invl(n)
            for i in range(n):
                dst[i] = dst[i] * inv % id2.mod
        return dst

    @staticmethod
    def fft(X, Y):
        s = 1
        eo = False
        for n in range(len(X), 3, -1):
            m = n // 2
            for p in range(m):
                wp = id2.wps[s * p]
                wk = (wp << 32) // id2.P
                for q in range(s):
                    a = X[q + s * (p + 0)]
                    b = X[q + s * (p + m)]
                    ndsts = a + b
                    if ndsts >= 2 * id2.P:
                        ndsts -= 2 * id2.P
                    T = a - b + 2 * id2.P
                    Q = wk * T >> 32
                    Y[q + s * (2 * p + 0)] = ndsts
                    Y[q + s * (2 * p + 1)] = wp * T - Q * id2.P & (1 << 32) - 1
            s *= 2
            eo = not eo
            X, Y = Y, X
        z = Y if eo else X
        for q in range(s):
            a = X[q + 0]
            b = X[q + s]
            z[q + 0] = (a + b) % id2.P
            z[q + s] = (a - b + 2 * id2.P) % id2.P

    @staticmethod
    def invl(a):
        b = id2.mod
        p, q = 1, 0
        while b > 0:
            c = a // b
            a, b = b, a % b
            p, q = q, p - c * q
        return p if p >= 0 else p + id2.mod

class F2:
    def solve(self):
        n = int(sys.stdin.readline().strip())
        g = [[False] * 10 for _ in range(10)]
        for _ in range(int(sys.stdin.readline().strip())):
            x, y = map(int, sys.stdin.readline().strip().split())
            g[x][y] = g[y][x] = True
        for i in range(10):
            g[i][i] = True

        njs = [[0] * 10 for _ in range(1 << 9)]
        for j in range(1 << 9):
            for k in range(10):
                if j & (1 << k):
                    nj = j
                    for l in range(10):
                        if g[k][l]:
                            if k > l:
                                nj |= 1 << l
                        else:
                            nj &= ~(1 << l)
                    njs[j][k] = nj

        dp = [0] * (1 << 9)
        dp[0] = 1
        for _ in range(1, n + 1):
            ndp = [0] * (1 << 9)
            for j in range(1 << 9):
                for k in range(10):
                    if j & (1 << k):
                        nj = njs[j][k]
                        ndp[nj] += dp[j]
                        if ndp[nj] >= mod:
                            ndp[nj] -= mod
            dp = ndp
        ans = sum_array(dp) % mod
        print(ans)

    def run(self):
        self.solve()

if __name__ == "__main__":
    F2().run()
