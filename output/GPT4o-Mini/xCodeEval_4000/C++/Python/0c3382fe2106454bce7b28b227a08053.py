import sys
from collections import defaultdict
from itertools import repeat

MAXN = 3005
INT_INF = 0x3f3f3f3f

def read():
    return map(int, sys.stdin.readline().split())

def dfs(v, prev):
    SZV = 1
    dp[v][0] = (0, W[v] - B[v])
    for w in adj[v]:
        if w != prev:
            SZW = dfs(w, v)
            for i in range(SZW, 0, -1):
                dp[w][i] = max(dp[w][i], (dp[w][i - 1][0] + (1 if dp[w][i - 1][1] > 0 else 0), 0))
            merged = [(-INT_INF, -float('inf'))] * (SZV + SZW)
            for i in range(SZV):
                for j in range(SZW + 1):
                    merged[i + j] = max(merged[i + j], (dp[v][i][0] + dp[w][j][0], dp[v][i][1] + dp[w][j][1]))
            dp[v][:SZV + SZW] = merged
            SZV += SZW
    return SZV

T = int(sys.stdin.readline())
for _ in range(T):
    N, M = read()
    B = list(read())
    W = list(read())
    adj = defaultdict(list)
    
    for _ in range(N - 1):
        a, b = read()
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    
    dp = [[(-INT_INF, -float('inf'))] * (N + 1) for _ in range(N)]
    dfs(0, -1)
    print(dp[0][M - 1][0] + (1 if dp[0][M - 1][1] > 0 else 0))
    adj.clear()
