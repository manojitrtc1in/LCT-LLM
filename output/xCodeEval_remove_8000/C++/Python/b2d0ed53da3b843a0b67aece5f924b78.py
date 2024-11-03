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

    dp = [[0] * (k+1) for _ in range(13)]
    for i in range(n):
        carr = arrs[i]
        for j in range(k, -1, -1):
            dp[0][j] = max(dp[0][j], dp[0][j-1] + carr[j-1]) if j > 0 else 0

    for i in range(1, n):
        for j in range(k+1):
            dp[i][j] = max(dp[i][j], dp[i-1][j])
            if j > 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + sums[i])

    print(dp[n-1][k])

solve()
