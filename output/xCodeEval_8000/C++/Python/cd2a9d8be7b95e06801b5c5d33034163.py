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

def solve(N: int, K: int, A: List[List[int]]) -> int:
    adj_list = [[] for _ in range(N)]
    for i in range(N):
        for j in range(len(A[i])):
            adj_list[i].append((i+j+1, A[i][j]))

    dist = dijkstra(adj_list, 0)
    return dist[N-1]

def main():
    N, K = map(int, input().split())
    A = []
    for _ in range(N):
        t = int(input())
        a = list(map(int, input().split()))
        if t > K:
            a = a[:K]
        A.append(a)
    result = solve(N, K, A)
    print(result)

if __name__ == "__main__":
    main()
