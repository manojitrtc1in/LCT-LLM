import sys
from collections import deque

class F2:
    mod = 998244353
    G = 3

    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def ni(self):
        value = int(self.data[self.index])
        self.index += 1
        return value

    def solve(self):
        n = self.ni()
        g = [[False] * 10 for _ in range(10)]
        for _ in range(self.ni()):
            x = self.ni()
            y = self.ni()
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
                        if ndp[nj] >= self.mod:
                            ndp[nj] -= self.mod
            dp = ndp
        ans = sum(dp) % self.mod
        print(ans)

    def run(self):
        self.solve()

if __name__ == "__main__":
    F2().run()
