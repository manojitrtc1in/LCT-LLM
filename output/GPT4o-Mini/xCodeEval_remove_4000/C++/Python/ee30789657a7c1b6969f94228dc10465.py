import sys
import random

MOD = 10**9 + 7
MAX = 500050
LINF = 10**17 + 1

class Mint:
    def __init__(self, x=0):
        self.x = (x % MOD + MOD) % MOD

    def __neg__(self):
        return Mint(-self.x)

    def __iadd__(self, a):
        self.x += a.x
        if self.x >= MOD:
            self.x -= MOD
        return self

    def __isub__(self, a):
        self.x += MOD - a.x
        if self.x >= MOD:
            self.x -= MOD
        return self

    def __imul__(self, a):
        self.x = (self.x * a.x) % MOD
        return self

    def __add__(self, a):
        return Mint(self) + a

    def __sub__(self, a):
        return Mint(self) - a

    def __mul__(self, a):
        return Mint(self) * a

    def pow(self, t):
        if t == 0:
            return Mint(1)
        a = self.pow(t // 2)
        a *= a
        if t % 2 == 1:
            a *= self
        return a

    def inv(self):
        return self.pow(MOD - 2)

    def __itruediv__(self, a):
        return self.__imul__(a.inv())

    def __truediv__(self, a):
        return Mint(self) / a

    def __repr__(self):
        return str(self.x)

def read_int():
    return int(sys.stdin.readline().strip())

def write_int(x):
    sys.stdout.write(str(x) + '\n')

def solve():
    t = read_int()
    dp = [[[[0 for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(65)]
    dp[0][0][0][0] = 1

    for i in range(60):
        f2 = (t >> i) & 1
        if f2:
            dp[i + 1][0][0][0] += dp[i][0][0][0]
            dp[i + 1][1][0][0] += dp[i][0][0][0]
            dp[i + 1][0][1][0] += dp[i][0][0][0]
            dp[i + 1][1][1][0] += dp[i][0][0][0]
            dp[i + 1][0][1][0] += dp[i][0][0][1]
            dp[i + 1][1][1][0] += dp[i][0][0][1]
            dp[i + 1][0][0][1] += dp[i][0][0][1]
            dp[i + 1][1][0][1] += dp[i][0][0][1]
            dp[i + 1][1][0][0] += dp[i][0][1][0]
            dp[i + 1][0][1][0] += dp[i][0][1][0]
            dp[i + 1][1][1][0] += dp[i][0][1][0]
            dp[i + 1][0][0][1] += dp[i][0][1][0]
            dp[i + 1][1][1][0] += dp[i][0][1][1]
            dp[i + 1][0][0][1] += dp[i][0][1][1]
            dp[i + 1][1][0][1] += dp[i][0][1][1]
            dp[i + 1][0][1][1] += dp[i][0][1][1]
            dp[i + 1][0][0][0] += dp[i][1][0][0]
            dp[i + 1][1][0][0] += dp[i][1][0][0]
            dp[i + 1][0][1][0] += dp[i][1][0][0]
            dp[i + 1][1][1][0] += dp[i][1][0][0]
            dp[i + 1][0][1][0] += dp[i][1][0][1]
            dp[i + 1][1][1][0] += dp[i][1][0][1]
            dp[i + 1][0][0][1] += dp[i][1][0][1]
            dp[i + 1][1][0][1] += dp[i][1][0][1]
            dp[i + 1][1][0][0] += dp[i][1][1][0]
            dp[i + 1][0][1][0] += dp[i][1][1][0]
            dp[i + 1][1][1][0] += dp[i][1][1][0]
            dp[i + 1][0][0][1] += dp[i][1][1][0]
            dp[i + 1][1][1][0] += dp[i][1][1][1]
            dp[i + 1][0][0][1] += dp[i][1][1][1]
            dp[i + 1][1][0][1] += dp[i][1][1][1]
            dp[i + 1][0][1][1] += dp[i][1][1][1]
        else:
            dp[i + 1][0][0][0] += dp[i][0][0][0]
            dp[i + 1][1][0][0] += dp[i][0][0][0]
            dp[i + 1][0][1][0] += dp[i][0][0][0]
            dp[i + 1][1][1][0] += dp[i][0][0][0]
            dp[i + 1][0][1][0] += dp[i][0][0][1]
            dp[i + 1][1][1][0] += dp[i][0][0][1]
            dp[i + 1][0][0][1] += dp[i][0][0][1]
            dp[i + 1][1][0][1] += dp[i][0][0][1]
            dp[i + 1][1][0][0] += dp[i][0][1][0]
            dp[i + 1][0][1][0] += dp[i][0][1][0]
            dp[i + 1][1][1][0] += dp[i][0][1][0]
            dp[i + 1][0][0][1] += dp[i][0][1][0]
            dp[i + 1][1][1][0] += dp[i][0][1][1]
            dp[i + 1][0][0][1] += dp[i][0][1][1]
            dp[i + 1][1][0][1] += dp[i][0][1][1]
            dp[i + 1][0][1][1] += dp[i][0][1][1]
            dp[i + 1][1][0][0] += dp[i][1][0][0]
            dp[i + 1][0][1][0] += dp[i][1][0][0]
            dp[i + 1][1][1][0] += dp[i][1][0][0]
            dp[i + 1][0][0][1] += dp[i][1][0][0]
            dp[i + 1][1][1][0] += dp[i][1][0][1]
            dp[i + 1][0][0][1] += dp[i][1][0][1]
            dp[i + 1][1][0][1] += dp[i][1][0][1]
            dp[i + 1][0][1][1] += dp[i][1][0][1]
            dp[i + 1][0][1][0] += dp[i][1][1][0]
            dp[i + 1][1][1][0] += dp[i][1][1][0]
            dp[i + 1][0][0][1] += dp[i][1][1][0]
            dp[i + 1][1][0][1] += dp[i][1][1][0]
            dp[i + 1][0][0][1] += dp[i][1][1][1]
            dp[i + 1][1][0][1] += dp[i][1][1][1]
            dp[i + 1][0][1][1] += dp[i][1][1][1]
            dp[i + 1][1][1][1] += dp[i][1][1][1]

        for j in range(2):
            for k in range(2):
                for l in range(2):
                    dp[i + 1][j][k][l] %= MOD

    write_int(dp[60][0][0][0])

def main():
    q = read_int()
    for _ in range(q):
        solve()

if __name__ == "__main__":
    main()
