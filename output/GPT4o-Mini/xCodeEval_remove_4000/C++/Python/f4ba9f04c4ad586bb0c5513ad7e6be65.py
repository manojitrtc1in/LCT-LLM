import sys
import random
from math import acos

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = acos(-1.0)

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

    @staticmethod
    def inv_mod(a, m=MOD):
        g, r, x, y = m, a, 0, 1
        while r != 0:
            q = g // r
            g, r = r, g % r
            x, y = y, x - q * y
        return x if x >= 0 else x + m

    def __int__(self):
        return self.val

    def __add__(self, other):
        return Mint((self.val + other.val) % MOD)

    def __sub__(self, other):
        return Mint((self.val - other.val) % MOD)

    def __mul__(self, other):
        return Mint((self.val * other.val) % MOD)

    def __truediv__(self, other):
        return self * other.inv()

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return self.val != other.val

    def __lt__(self, other):
        return self.val < other.val

    def __gt__(self, other):
        return self.val > other.val

    def __le__(self, other):
        return self.val <= other.val

    def __ge__(self, other):
        return self.val >= other.val

    def inv(self):
        return Mint(self.inv_mod(self.val))

    def pow(self, p):
        if p < 0:
            return self.inv().pow(-p)
        a = self
        result = Mint(1)
        while p > 0:
            if p & 1:
                result *= a
            a *= a
            p >>= 1
        return result

    def __str__(self):
        return str(self.val)

dp = [[[Mint() for _ in range(1 << BITS)] for _ in range(CR)] for _ in range(CR)]
cnt = [[[Mint() for _ in range(1 << BITS)] for _ in range(CR)] for _ in range(CR)]

def precalc():
    global dp, cnt
    for i in range(CR):
        for j in range(BITS + 1):
            for k in range(CR):
                for x in range(1 << BITS):
                    dp[i][j][k][x] = Mint(0)
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
    global dp2
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
    precalc()
    tc = int(input())
    for _ in range(tc):
        if read():
            solve()

if __name__ == "__main__":
    input_file = open("input.txt", "r")
    sys.stdin = input_file
    main()
