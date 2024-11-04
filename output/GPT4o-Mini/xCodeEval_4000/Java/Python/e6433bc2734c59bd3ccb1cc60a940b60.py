import sys
from collections import deque

class G3:
    def solve(self):
        mod = 998244353
        n = self.ni()
        a = self.na(26)
        all = 26 * 26 * self.pow(25, n - 2, mod) % mod

        dp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(3)]
        dp[0][1][0] = 1
        dp[1][0][1] = 1
        dp[2][0][0] = 1
        
        for i in range(n - 1):
            ndp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(3)]
            if i == (n + 1) // 2 - 1:
                for j in range(n + 1):
                    for k in range(n + 1 - j):
                        if j + 1 <= n:
                            ndp[0][j + 1][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod
                        if k + 1 <= n:
                            ndp[1][j][k + 1] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod
                        ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod
            else:
                for j in range(n + 1):
                    for k in range(n + 1 - j):
                        if j + 1 <= n:
                            ndp[0][j + 1][k] += (dp[1][j][k] + dp[2][j][k] * 24) % mod
                        if k + 1 <= n:
                            ndp[1][j][k + 1] += (dp[0][j][k] + dp[2][j][k] * 24) % mod
                        ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23) % mod

            dp = ndp

        sdp = [0] * (n + 1)
        for i in range(n + 1):
            for j in range(n + 1):
                sdp[i] += (dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24) % mod
                sdp[i] %= mod

        for i in range(26):
            for k in range(a[i] + 1, n + 1):
                all -= sdp[k]
        
        for i in range(26):
            for j in range(i + 1, 26):
                for k in range(a[i] + 1, n + 1):
                    for l in range(a[j] + 1, n + 1 - k):
                        all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24) % mod
                all %= mod
        
        all %= mod
        if all < 0:
            all += mod
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
    def ni():
        return int(sys.stdin.readline().strip())

    @staticmethod
    def na(n):
        return list(map(int, sys.stdin.readline().strip().split()))[:n]

    def run(self):
        self.solve()

if __name__ == "__main__":
    G3().run()
