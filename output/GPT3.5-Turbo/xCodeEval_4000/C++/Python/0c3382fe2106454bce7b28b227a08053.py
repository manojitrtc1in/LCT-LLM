import sys

def dfs(v, prev):
    SZV = 1
    dp[v][0] = (0, W[v] - B[v])
    for w in adj[v]:
        if w != prev:
            SZW = dfs(w, v)
            for i in range(SZW, 0, -1):
                dp[w][i] = max(dp[w][i], (dp[w][i - 1][0] + int(dp[w][i - 1][1] > 0), 0))
            merged = [(-sys.maxsize, -sys.maxsize)] * (SZV + SZW)
            for i in range(SZV):
                for j in range(SZW + 1):
                    merged[i + j] = max(merged[i + j], (dp[v][i][0] + dp[w][j][0], dp[v][i][1] + dp[w][j][1]))
            dp[v][:] = merged[:]
            SZV += SZW
    return SZV

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    B = list(map(int, input().split()))
    W = list(map(int, input().split()))
    adj = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = map(int, input().split())
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    dp = [[(-sys.maxsize, -sys.maxsize)] * (N + 1) for _ in range(N)]
    dfs(0, -1)
    print(dp[0][M - 1][0] + int(dp[0][M - 1][1] > 0))
    adj.clear()
