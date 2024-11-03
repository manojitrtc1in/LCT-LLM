import sys

def dijkstra(adj_list, start):
    n = len(adj_list)
    dist = [float('inf')] * n
    dist[start] = 0
    visited = [False] * n

    for _ in range(n):
        u = -1
        for i in range(n):
            if not visited[i] and (u == -1 or dist[i] < dist[u]):
                u = i
        visited[u] = True

        for v, w in adj_list[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist

def solve(n, k, arrs):
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        for j in range(len(arrs[i])):
            adj_list[i].append((j, arrs[i][j]))

    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k+1) for _ in range(n+1)]

    for i in range(n):
        for j in range(k+1):
            dp[i+1][j] = dp[i][j]
            for l in range(len(arrs[i])):
                if j >= l+1:
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j-l-1] + sums[i])

    dist = dijkstra(adj_list, 0)
    ans = 0
    for i in range(n):
        ans = max(ans, dp[i][k] + dist[i])

    return ans

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

if __name__ == "__main__":
    main()
