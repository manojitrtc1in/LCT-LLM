import sys
import random
from math import acos

INF = int(1e9)
INF64 = int(1e18)
MOD = 998244353
EPS = 1e-9
PI = acos(-1.0)

N = 300 * 1000 + 13

n = 0
g = [[] for _ in range(N)]

def read():
    global n
    try:
        n = int(sys.stdin.readline().strip())
    except ValueError:
        return False
    for i in range(n):
        g[i].clear()
    for _ in range(n - 1):
        v, u = map(int, sys.stdin.readline().strip().split())
        v -= 1
        u -= 1
        g[v].append(u)
        g[u].append(v)
    return True

def add(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    if a < 0:
        a += MOD
    return a

def mul(a, b):
    return a * b % MOD

dp = [[0] * 3 for _ in range(N)]

def dfs(v, p=-1):
    dp[v][0] = 1
    dp[v][1] = 1
    vals = []
    init = []
    for u in g[v]:
        if u != p:
            dfs(u, v)
            vals.append(add(dp[u][1], add(dp[u][2], dp[u][2])))
            init.append(add(dp[u][0], dp[u][1]))
            dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])))
            dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]))
    
    dp[v][0] = add(dp[v][0], -dp[v][1])
    
    pr = [1]
    su = [1]
    for it in vals:
        pr.append(mul(pr[-1], it))
    vals.reverse()
    for it in vals:
        su.append(mul(su[-1], it))
    vals.reverse()
    su.reverse()
    
    dp[v][2] = 0
    for i in range(len(vals)):
        dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i + 1])))

def solve():
    dfs(0)
    print(add(dp[0][1], dp[0][2]))

def main():
    input_file = open("input.txt", "r")
    sys.stdin = input_file

    while read():
        solve()

if __name__ == "__main__":
    main()
