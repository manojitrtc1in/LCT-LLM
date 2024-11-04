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
    ans = 0

    for l in range(n):
        carr = arrs[l]
        for i in range(k + 1):
            dp[0][i] = max(dp[0][i], dp[1][i])
        for i in range(1, min(k, len(carr)) + 1):
            dp[0][k - i] = max(dp[0][k - i], dp[1][k - i] + sums[l])
        for i in range(1, 13):
            for j in range(k + 1):
                dp[i][j] = dp[i - 1][j]
            for j in range(len(carr)):
                if j >= k:
                    break
                dp[i][k - j - 1] = max(dp[i][k - j - 1], dp[i - 1][k - j - 1] + sums[l] * (j + 1))

        ans = max(ans, dp[12][k])

    print(ans)

solve()
