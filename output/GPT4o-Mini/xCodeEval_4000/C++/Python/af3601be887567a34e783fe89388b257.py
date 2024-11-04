import sys
import random
from collections import defaultdict

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = -1  # Not used in the original code

N = 3000 + 7

def read():
    global n, k, a, b, g
    n, k = map(int, sys.stdin.readline().split())
    g = defaultdict(list)
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    for _ in range(n - 1):
        v, u = map(int, sys.stdin.readline().split())
        v -= 1
        u -= 1
        g[v].append(u)
        g[u].append(v)

def dfs(v, p=-1):
    global val, dp, siz
    val[v] = b[v] - a[v]
    dp[v] = [(-INF, -INF64)] * (n + 1)
    dp[v][0] = (0, val[v])
    siz[v] = 1
    
    for u in g[v]:
        if u != p:
            dfs(u, v)
            tmp = [(-INF, -INF64)] * (siz[v] + siz[u])
            for i in range(siz[v]):
                for j in range(siz[u] + 1):
                    nw = (dp[v][i][0] + dp[u][j][0], dp[v][i][1] + dp[u][j][1])
                    tmp[i + j] = max(tmp[i + j], nw)
            for i in range(len(tmp)):
                dp[v][i] = tmp[i]
            siz[v] += siz[u]
            val[v] += val[u]

    for i in range(siz[v] - 1, -1, -1):
        dp[v][i + 1] = max(dp[v][i + 1], (dp[v][i][0] + (dp[v][i][1] > 0), 0))

def solve():
    dfs(0)
    print(dp[0][k - 1][0] + (dp[0][k - 1][1] > 0))

if __name__ == "__main__":
    sys_input = sys.stdin.read
    data = sys_input().splitlines()
    index = 0
    tc = int(data[index])
    index += 1
    while tc > 0:
        read()
        solve()
        tc -= 1
