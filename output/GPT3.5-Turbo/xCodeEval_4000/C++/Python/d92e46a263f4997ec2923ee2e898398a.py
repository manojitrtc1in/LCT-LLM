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
    graph = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            graph[i].append((j, sums[j]))

    dp = [0] * (k+1)
    for i in range(n):
        for j in range(k, -1, -1):
            dp[j] = max(dp[j], dp[j-1] + sums[i]) if j > 0 else dp[j] + sums[i]

    for i in range(n):
        dist = dijkstra(graph, i)
        for j in range(k+1):
            dp[j] = max(dp[j], dp[j-len(arrs[i])] + dist[i])

    return dp[k]

def main():
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        arr = list(map(int, input().split()))
        if len(arr) > k:
            arr = arr[:k]
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == '__main__':
    main()
