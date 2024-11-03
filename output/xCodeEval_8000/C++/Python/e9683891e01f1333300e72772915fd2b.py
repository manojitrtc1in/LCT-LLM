import sys
from typing import List, Tuple

def dijkstra(n: int, edges: List[List[Tuple[int, int]]], start: int) -> Tuple[List[int], List[bool]]:
    dist = [float('inf')] * n
    dist[start] = 0
    added = [False] * n
    added[start] = True
    pq = [(0, start)]
    while pq:
        d, u = pq.pop(0)
        if d > dist[u]:
            continue
        for v, w in edges[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                if not added[v]:
                    added[v] = True
                    pq.append((dist[v], v))
    return dist, added

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(n):
        carr = arrs[i]
        for j in range(k + 1):
            dp[i + 1][j] = dp[i][j]
            if j >= len(carr):
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - len(carr)] + sums[i])
    return dp[n][k]

def main() -> None:
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        if len(arr) > k:
            arr = arr[:k]
        arrs.append(arr)
    result = solve(n, k, arrs)
    print(result)

if __name__ == "__main__":
    main()
