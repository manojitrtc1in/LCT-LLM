import sys
import random
from functools import reduce

MOD = 998244353
N = 50 + 7
M = 3000 + 7

def read():
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    w = list(map(int, sys.stdin.readline().split()))
    return n, m, a, w

def add(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    if a < 0:
        a += MOD
    return a

def mul(a, b):
    return a * b % MOD

def binpow(a, b):
    res = 1
    while b:
        if b & 1:
            res = mul(res, a)
        a = mul(a, a)
        b >>= 1
    return res

def inv(x):
    return binpow(x, MOD - 2)

def solve(n, m, a, w):
    sum_w = sum(w)
    neg = sum(w[i] for i in range(n) if a[i] == 0)
    rev = [inv(i) for i in range(M)]
    
    for z in range(n):
        dp = [[[0] * (2 * N) for _ in range(N)] for _ in range(N)]
        dp[0][0][w[z]] = 1
        
        for i in range(m):
            for pos in range(i + 1):
                for val in range(2 * N):
                    if dp[i][pos][val]:
                        p = mul(val, rev[sum_w + pos - (i - pos)])
                        pneg = mul(neg - (val if a[z] == 0 else 0) - (i - pos), rev[sum_w + pos - (i - pos)])
                        ppos = add(1, -add(p, pneg))
                        
                        if a[z] == 0 and val > 0:
                            dp[i + 1][pos][val - 1] = add(dp[i + 1][pos][val - 1], mul(dp[i][pos][val], p))
                        if a[z] == 1:
                            dp[i + 1][pos + 1][val + 1] = add(dp[i + 1][pos + 1][val + 1], mul(dp[i][pos][val], p))
                        dp[i + 1][pos + 1][val] = add(dp[i + 1][pos + 1][val], mul(dp[i][pos][val], ppos))
                        dp[i + 1][pos][val] = add(dp[i + 1][pos][val], mul(dp[i][pos][val], pneg))
        
        ans = 0
        for pos in range(m + 1):
            for val in range(2 * N):
                if dp[m][pos][val]:
                    ans = add(ans, mul(dp[m][pos][val], val))
        print(ans)

def main():
    while True:
        try:
            n, m, a, w = read()
            solve(n, m, a, w)
        except EOFError:
            break

if __name__ == "__main__":
    main()
