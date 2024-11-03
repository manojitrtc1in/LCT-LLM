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

    for i in range(1, n + 1):
        for j in range(k + 1):
            dp[i][j] = dp[i - 1][j]
            if j >= len(arrs[i - 1]):
                dp[i][j] = max(dp[i][j], dp[i - 1][j - len(arrs[i - 1])] + sums[i - 1])

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
    result = solve(n, k, arrs)
    print(result)

if __name__ == '__main__':
    main()
