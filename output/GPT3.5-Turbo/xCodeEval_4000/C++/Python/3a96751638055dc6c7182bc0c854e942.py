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
    ans = 0

    def copy_dp(dpi):
        for j in range(k+1):
            dp[dpi+1][j] = dp[dpi][j]

    def add_to_knap(i, dpi):
        v = sums[i]
        k1 = len(arrs[i])
        for j in range(k, k1-1, -1):
            dp[dpi][j] = max(dp[dpi][j], dp[dpi][j-k1] + v)

    def rec(l, r, dpi):
        nonlocal ans
        carr = arrs[l]
        if l+1 == r:
            ans = max(ans, dp[dpi][k])
            s = 0
            for i in range(min(k, len(carr))):
                s += carr[i]
                ans = max(ans, dp[dpi][k-i-1] + s)
        else:
            m = (l+r) // 2
            copy_dp(dpi)
            for i in range(l, m):
                add_to_knap(i, dpi+1)
            ans = max(ans, rec(m, r, dpi+1))
            copy_dp(dpi)
            for i in range(m, r):
                add_to_knap(i, dpi+1)
            ans = max(ans, rec(l, m, dpi+1))

    rec(0, n, 0)
    print(ans)

solve()
