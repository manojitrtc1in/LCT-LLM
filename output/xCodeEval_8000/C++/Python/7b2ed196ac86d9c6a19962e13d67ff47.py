import sys
from typing import List

def dijkstra(adj_list: List[List[int]], start: int) -> List[int]:
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

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            weight = sum(arrs[i][:k])
            adj_list[i].append((j, weight))
            weight = sum(arrs[j][:k])
            adj_list[j].append((i, weight))

    dist = dijkstra(adj_list, 0)
    return dist[n-1]

def main() -> None:
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        arr = list(map(int, input().split()))
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == "__main__":
    main()
