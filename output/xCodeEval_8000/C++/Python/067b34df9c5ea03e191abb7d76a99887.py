import sys
from typing import List, Tuple

def dijkstra(n: int, edges: List[List[Tuple[int, int]]], start: int) -> Tuple[List[int], List[bool]]:
    dist = [float('inf')] * n
    visited = [False] * n
    dist[start] = 0

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
    edges = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            edges[i].append((j, sums[j]))

    dist, visited = dijkstra(n, edges, 0)

    dp = [0] * (k+1)
    for i in range(n):
        if visited[i]:
            for j in range(k, -1, -1):
                if j >= len(arrs[i]):
                    dp[j] = max(dp[j], dp[j-len(arrs[i])] + sums[i])

    return dp[k]

def main() -> None:
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