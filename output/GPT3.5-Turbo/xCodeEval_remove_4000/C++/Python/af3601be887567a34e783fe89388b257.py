import random
import math

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = math.acos(-1.0)

N = 3000 + 7

n = 0
k = 0
a = [0] * N
b = [0] * N
g = [[] for _ in range(N)]

def read():
    global n, k, a, b, g
    try:
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        for _ in range(n - 1):
            v, u = map(int, input().split())
            v -= 1
            u -= 1
            g[v].append(u)
            g[u].append(v)
        return True
    except:
        return False

dp = [[(0, 0)] * N for _ in range(N)]
val = [0] * N
siz = [0] * N

def dfs(v, p = -1):
    global dp, val, siz
    val[v] = b[v] - a[v]
    for i in range(n + 1):
        dp[v][i] = (-INF, -INF64)
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

tc = int(input())
while tc > 0:
    read()
    solve()
    tc -= 1
