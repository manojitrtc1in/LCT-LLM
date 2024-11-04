import sys

def dijkstra(graph, start):
    n = len(graph)
    dist = [float('inf')] * n
    dist[start] = 0
    visited = [False] * n

    for _ in range(n):
        min_dist = float('inf')
        min_node = -1

        for i in range(n):
            if not visited[i] and dist[i] < min_dist:
                min_dist = dist[i]
                min_node = i

        if min_node == -1:
            break

        visited[min_node] = True

        for neighbor, weight in graph[min_node]:
            if dist[min_node] + weight < dist[neighbor]:
                dist[neighbor] = dist[min_node] + weight

    return dist

def solve(n, k, arrs):
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(13)]

    def copy_dp(dpi):
        for i in range(k + 1):
            dp[dpi + 1][i] = dp[dpi][i]

    def add_to_knap(i, dpi):
        v = sums[i]
        k1 = len(arrs[i])
        for j in range(k, k1 - 1, -1):
            dp[dpi][j] = max(dp[dpi][j], dp[dpi][j - k1] + v)

    def rec(l, r, dpi):
        ans = 0
        carr = arrs[l]
        if l + 1 == r:
            ans = max(ans, dp[dpi][k])
            s = 0
            for i in range(min(k, len(carr))):
                s += carr[i]
                ans = max(ans, dp[dpi][k - i - 1] + s)
        else:
            m = (l + r) // 2
            copy_dp(dpi)
            for i in range(l, m):
                add_to_knap(i, dpi + 1)
            ans = max(ans, rec(m, r, dpi + 1))
            copy_dp(dpi)
            for i in range(m, r):
                add_to_knap(i, dpi + 1)
            ans = max(ans, rec(l, m, dpi + 1))
        return ans

    return rec(0, n, 0)

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
