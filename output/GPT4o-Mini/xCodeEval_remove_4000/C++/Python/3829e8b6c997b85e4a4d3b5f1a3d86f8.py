from collections import defaultdict
import random
import sys
import time
import math

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
    line = sys.stdin.readline().strip()
    if not line:
        return False
    n, k = map(int, line.split())
    return True

def add(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def mul(a, b):
    return a * b % MOD

def mat_mult(a, b):
    c = [[0] * (k + 1) for _ in range(k + 1)]
    for i in range(k + 1):
        for j in range(k + 1):
            for t in range(k + 1):
                c[i][j] = add(c[i][j], mul(a[i][t], b[t][j]))
    return c

amat = [[[[0] * (N) for _ in range(N)] for _ in range(62)] for _ in range(N)]

def solve():
    global n, k
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
    
    for r in range(1, len(num)):
        pr = []
        pr.append([[1 if i == j else 0 for j in range(k + 1)] for i in range(k + 1)])
        for i in range(k):
            pr.append(mat_mult(pr[-1], amat[r - 1][i]))
        for sh in range(k):
            amat[r][sh] = pr[0]
            for i in range(k - sh):
                amat[r][sh] = mat_mult(amat[r][sh], amat[r - 1][(i + sh) % k])
            amat[r][sh] = mat_mult(amat[r][sh], pr[sh])
    
    dp = [[0] * (k + 1) for _ in range(k + 1)]
    dp[0][k] = 1
    
    rem = 0
    for i in range(len(num) - 1, -1, -1):
        while num[i] > 0:
            dp = mat_mult(dp, amat[i][rem])
            rem = (rem + 1) % k
            num[i] -= 1
    
    ans = 0
    for i in range(k + 1):
        ans = add(ans, dp[0][i])
    print(ans)

if __name__ == "__main__":
    sys.stdin = open("input.txt", "r")
    
    tt = time.clock()
    
    tc = int(sys.stdin.readline().strip())
    for _ in range(tc):
        read()
        while read():
            solve()
            print("TIME =", time.clock() - tt)
            tt = time.clock()
