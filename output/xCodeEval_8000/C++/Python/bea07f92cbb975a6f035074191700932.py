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

        for v, weight in adj_list[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight

    return dist

def solve(n, k, arrs):
    sums = [sum(arr) for arr in arrs]
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        arr = arrs[i]
        for j in range(len(arr)):
            adj_list[i].append((j+1, sums[i]))

    dp = [0] * (k+1)
    for i in range(n):
        for j in range(k, len(arrs[i])-1, -1):
            dp[j] = max(dp[j], dp[j-len(arrs[i])] + sums[i])

    for i in range(n):
        dist = dijkstra(adj_list, i)
        for j in range(k+1):
            dp[j] = max(dp[j], dp[j-1] + dist[j-1])

    return dp[k]

def main():
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        arr = list(map(int, input().split()))
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == "__main__":
    main()
