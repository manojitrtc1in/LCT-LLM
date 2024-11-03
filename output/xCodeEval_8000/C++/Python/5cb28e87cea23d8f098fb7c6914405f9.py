import sys

def dijkstra(graph, start):
    n = len(graph)
    dist = [float('inf')] * n
    dist[start] = 0
    visited = [False] * n

    for _ in range(n):
        u = -1
        for i in range(n):
            if not visited[i] and (u == -1 or dist[i] < dist[u]):
                u = i
        visited[u] = True

        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist

def solve():
    n, k = map(int, input().split())
    sums = []
    arrs = []
    for _ in range(n):
        arr = list(map(int, input().split()))
        sums.append(sum(arr))
        arrs.append(arr[:k])

    dp = [[0] * (k + 1) for _ in range(13)]
    for i in range(n):
        carr = arrs[i]
        for j in range(k, len(carr), -1):
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - len(carr)] + sums[i])

    ans = 0
    for i in range(n + 1):
        ans = max(ans, dp[i][k])

    print(ans)

solve()
