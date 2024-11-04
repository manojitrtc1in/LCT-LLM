import sys
from collections import deque

class G3:
    def __init__(self):
        self.INPUT = ""
        self.mod = 998244353

    def solve(self):
        n = self.ni()
        a = self.na(26)
        all = 26 * 26 * self.pow(25, n - 2, self.mod) % self.mod

        dp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(3)]
        dp[0][1][0] = 1
        dp[1][0][1] = 1
        dp[2][0][0] = 1

        for i in range(n - 1):
            ndp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(3)]
            if i == (n + 1) // 2 - 1:
                for j in range(n + 1):
                    for k in range(n + 1):
                        if j + k <= n:
                            if j + 1 <= n:
                                ndp[0][j + 1][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % self.mod
                            if k + 1 <= n:
                                ndp[1][j][k + 1] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % self.mod
                            ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % self.mod
            else:
                for j in range(n + 1):
                    for k in range(n + 1):
                        if j + k <= n:
                            if j + 1 <= n:
                                ndp[0][j + 1][k] += (dp[1][j][k] + dp[2][j][k] * 24) % self.mod
                            if k + 1 <= n:
                                ndp[1][j][k + 1] += (dp[0][j][k] + dp[2][j][k] * 24) % self.mod
                            ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23) % self.mod
            dp = ndp

        sdp = [0] * (n + 1)
        for i in range(n + 1):
            for j in range(n + 1):
                sdp[i] += (dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24) % self.mod
            sdp[i] %= self.mod

        for i in range(26):
            for k in range(a[i] + 1, n + 1):
                all -= sdp[k]
        
        for i in range(26):
            for j in range(i + 1, 26):
                for k in range(a[i] + 1, n + 1):
                    for l in range(a[j] + 1, n + 1):
                        if l + k <= n:
                            all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24)
                all %= self.mod
        all %= self.mod

        if all < 0:
            all += self.mod
        print(all)

    @staticmethod
    def pow(a, n, mod):
        ret = 1
        x = 63 - (n.bit_length() - 1)
        for x in range(x, -1, -1):
            ret = ret * ret % mod
            if n & (1 << x):
                ret = ret * a % mod
        return ret

    @staticmethod
    def invl(a, mod):
        b = mod
        p, q = 1, 0
        while b > 0:
            c = a // b
            a, b = b, a % b
            p, q = q, p - c * q
        return p if p >= 0 else p + mod

    @staticmethod
    def C(n, r, mod, fif):
        if n < 0 or r < 0 or r > n:
            return 0
        return (fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod)

    @staticmethod
    def id0(n, mod):
        f = [0] * (n + 1)
        invf = [0] * (n + 1)
        f[0] = 1
        for i in range(1, n + 1):
            f[i] = f[i - 1] * i % mod
        a = f[n]
        b = mod
        p, q = 1, 0
        while b > 0:
            c = a // b
            a, b = b, a % b
            p, q = q, p - c * q
        invf[n] = p if p >= 0 else p + mod
        for i in range(n - 1, -1, -1):
            invf[i] = invf[i + 1] * (i + 1) % mod
        return f, invf

    def run(self):
        self.is = sys.stdin
        self.solve()

    def ni(self):
        return int(self.nl())

    def nl(self):
        return int(sys.stdin.readline().strip())

    def na(self, n):
        return list(map(int, sys.stdin.readline().strip().split()))

if __name__ == "__main__":
    G3().run()
