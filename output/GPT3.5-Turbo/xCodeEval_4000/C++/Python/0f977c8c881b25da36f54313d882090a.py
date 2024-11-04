import random
import math

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = math.acos(-1.0)

N = 4 * 1000 * 1000 + 13

def add(a, b):
    a += b
    if a >= mod:
        a -= mod
    if a < 0:
        a += mod
    return a

def mul(a, b):
    return a * b % mod

def solve():
    dp = [0] * N
    pr = [0] * N
    pr[1] = 1
    pr[2] = mod - 1
    for i in range(1, n + 1):
        dp[i] = pr[i]
        pr[i + 1] = add(pr[i + 1], dp[i])
        for j in range(2, (n // i) + 1):
            pr[j * i] = add(pr[j * i], dp[i])
            if j * (i + 1) < N:
                pr[j * (i + 1)] = add(pr[j * (i + 1)], -dp[i])
        pr[i + 1] = add(pr[i + 1], pr[i])
    print(dp[n])

if __name__ == '__main__':
    # Read input
    n, mod = map(int, input().split())

    # Solve the problem
    solve()
