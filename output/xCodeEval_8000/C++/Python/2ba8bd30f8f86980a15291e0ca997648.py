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

def solve(n, k, arrs):
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        dp[i] = dp[i - 1].copy()
        for j in range(k, len(arrs[i - 1]) - 1, -1):
            dp[i][j] = max(dp[i][j], dp[i][j - len(arrs[i - 1])] + sums[i - 1])

    for i in range(1, n + 1):
        for j in range(k + 1):
            for l in range(min(k, len(arrs[i - 1])) + 1):
                if j - l >= 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + sum(arrs[i - 1][:l]))

    return dp[n][k]

def main():
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        if t > k:
            arr = arr[:k]
        arrs.append(arr)
    print(solve(n, k, arrs))

if __name__ == "__main__":
    main()
