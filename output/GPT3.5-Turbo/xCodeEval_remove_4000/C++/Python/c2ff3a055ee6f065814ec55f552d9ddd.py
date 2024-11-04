import sys
from typing import List

def dijkstra(n: int, e: List[List[int]]) -> List[int]:
    INF = float('inf')
    dist = [INF] * n
    dist[0] = 0
    visited = [False] * n

    for _ in range(n):
        u = -1
        for i in range(n):
            if not visited[i] and (u == -1 or dist[i] < dist[u]):
                u = i
        visited[u] = True

        for v, w in e[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist

def solve(n: int, k: int, a: List[List[int]]) -> int:
    e = [[] for _ in range(n)]
    for i in range(n):
        for j in range(len(a[i])):
            e[i].append((j, a[i][j]))

    dist = dijkstra(n, e)
    return dist[k]

def main() -> None:
    n, k = map(int, input().split())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))
    ans = solve(n, k, a)
    print(ans)

if __name__ == "__main__":
    main()
