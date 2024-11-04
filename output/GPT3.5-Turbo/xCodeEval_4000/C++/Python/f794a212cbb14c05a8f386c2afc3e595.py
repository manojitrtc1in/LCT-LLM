import sys
from typing import List

def dijkstra(n: int, e: List[List[int]], start: int) -> List[int]:
    INF = float('inf')
    dist = [INF] * n
    dist[start] = 0
    visited = [False] * n

    for _ in range(n):
        u = -1
        for v in range(n):
            if not visited[v] and (u == -1 or dist[v] < dist[u]):
                u = v
        visited[u] = True

        for v, w in e[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    e = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            dist = sum(arrs[i][k:]) + sum(arrs[j][:k])
            e[i].append((j, dist))
            e[j].append((i, dist))

    dist = dijkstra(n, e, 0)
    return dist[n-1]

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
