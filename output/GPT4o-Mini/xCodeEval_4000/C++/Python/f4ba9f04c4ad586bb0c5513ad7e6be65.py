import sys
import time
from collections import defaultdict

MOD = int(1e9) + 7
CR = 7
BITS = 15

n = 0

def read():
    global n
    try:
        n = int(input())
        return True
    except EOFError:
        return False

class Mint:
    def __init__(self, v=0):
        if v < 0:
            v = v % MOD + MOD
        if v >= MOD:
            v %= MOD
        self.val = int(v)

    def inv_mod(self, a, m=MOD):
        g, r, x, y = m, a, 0, 1
        while r != 0:
            q = g // r
            g, r = r, g % r
            x, y = y, x - q * y
        return x if x >= 0 else x + m

    def inv(self):
        return Mint(self.inv_mod(self.val))

    def __add__(self, other):
        return Mint(self.val + other.val) if (self.val + other.val) < MOD else Mint(self.val + other.val - MOD)

    def __sub__(self, other):
        return Mint(self.val - other.val) if (self.val - other.val) >= 0 else Mint(self.val - other.val + MOD)

    def __mul__(self, other):
        return Mint((self.val * other.val) % MOD)

    def __truediv__(self, other):
        return self * other.inv()

    def __int__(self):
        return self.val

    def __repr__(self):
        return str(self.val)

dp = [[[defaultdict(Mint) for _ in range(1 << BITS)] for _ in range(BITS + 1)] for _ in range(CR)]
cnt = [[[Mint() for _ in range(1 << BITS)] for _ in range(CR)] for _ in range(CR)]

def precalc():
    for i in range(CR):
        dp[i][0][i][0] = Mint(1)
    for cs in range(CR):
        for i in range(BITS):
            for ct in range(CR):
                for x in range(1 << BITS):
                    if dp[cs][i][ct][x].val != 0:
                        for cc in range(CR + 1):
                            dp[cs][i + 1][(ct + cc) // 2][(((ct + cc) % 2) << i) | x] += dp[cs][i][ct][x]
    for i in range(CR):
        for j in range(CR):
            for x in range(1 << BITS):
                cnt[i][j][x] = dp[i][BITS][j][x]

dp2 = [[Mint() for _ in range(CR)] for _ in range(5)]

def solve():
    global n
    for i in range(5):
        for j in range(CR):
            dp2[i][j] = Mint(0)
    dp2[0][0] = Mint(1)
    for i in range(4):
        x = n & ((1 << BITS) - 1)
        n >>= BITS
        for j in range(CR):
            for k in range(CR):
                dp2[i + 1][k] += dp2[i][j] * cnt[j][k][x]
    print(int(dp2[4][0]))

def main():
    global n
    precalc()
    if len(sys.argv) > 1 and sys.argv[1] == 'debug':
        with open("input.txt", "r") as f:
            sys.stdin = f
    while read():
        solve()

if __name__ == "__main__":
    main()
