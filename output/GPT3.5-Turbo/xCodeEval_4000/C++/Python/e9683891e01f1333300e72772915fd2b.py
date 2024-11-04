import sys
from typing import List, Tuple

def dijkstra(n: int, edges: List[List[Tuple[int, int]]], start: int) -> Tuple[List[int], List[bool]]:
    dist = [float('inf')] * n
    dist[start] = 0
    visited = [False] * n

    for _ in range(n):
        u = -1
        for i in range(n):
            if not visited[i] and (u == -1 or dist[i] < dist[u]):
                u = i
        visited[u] = True

        for v, w in edges[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist, visited

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]

    for i in range(n):
        for j in range(k + 1):
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j])
            for x in range(min(k, len(arrs[i]))):
                dp[i + 1][j + x + 1] = max(dp[i + 1][j + x + 1], dp[i][j] + sums[i])

    return dp[n][k]

def main() -> None:
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        if t > k:
            arr = arr[:k]
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == "__main__":
    main()
