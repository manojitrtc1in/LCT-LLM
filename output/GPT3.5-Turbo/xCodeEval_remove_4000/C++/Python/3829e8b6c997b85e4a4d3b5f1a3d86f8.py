import random
import math
import sys

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = math.acos(-1.0)

N = 32

n = 0
k = 0

def read():
    global n, k
    try:
        n, k = map(int, input().split())
        return True
    except:
        return False

def add(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def mul(a, b):
    return a * b % MOD

def mat_mul(a, b):
    c = [[0] * N for _ in range(N)]
    for i in range(k + 1):
        for j in range(k + 1):
            for t in range(k + 1):
                c[i][j] = add(c[i][j], mul(a[i][t], b[t][j]))
    return c

amat = [[[0] * N for _ in range(N)] for _ in range(62)]

def solve():
    num = []
    while n > 0:
        num.append(n % k)
        n //= k

    for d in range(k):
        for i in range(k + 1):
            for j in range(k + 1):
                amat[0][d][i][j] = 0
        for i in range(k + 1):
            amat[0][d][i][i] = 1
        for i in range(k + 1):
            amat[0][d][i][d] = 1

    pr = []
    pr.append([[0] * N for _ in range(N)])
    for i in range(k + 1):
        for j in range(k + 1):
            pr[0][i][j] = i == j
    for r in range(1, len(num)):
        pr.append(mat_mul(pr[-1], amat[r - 1][0]))
        for sh in range(k):
            amat[r][sh] = pr[0]
            for i in range(k - sh):
                amat[r][sh] = mat_mul(amat[r][sh], amat[r - 1][(i + sh) % k])
            amat[r][sh] = mat_mul(amat[r][sh], pr[sh])

    dp = [[0] * N for _ in range(N)]
    for i in range(k + 1):
        for j in range(k + 1):
            dp[i][j] = 0
    dp[0][k] = 1

    rem = 0
    for i in range(len(num) - 1, -1, -1):
        while num[i] > 0:
            dp = mat_mul(dp, amat[i][rem])
            rem = (rem + 1) % k
            num[i] -= 1

    ans = 0
    for i in range(k + 1):
        ans = add(ans, dp[0][i])
    print(ans)

tc = int(input())
while tc > 0:
    tc -= 1
    read()
    solve()
