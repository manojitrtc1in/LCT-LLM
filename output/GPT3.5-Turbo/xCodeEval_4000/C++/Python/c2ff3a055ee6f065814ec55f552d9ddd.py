import sys

def dijkstra(graph, start):
    n = len(graph)
    dist = [float('inf')] * n
    dist[start] = 0
    visited = [False] * n

    for _ in range(n):
        u = -1
        for i in range(n):
            if not visited[i] and (u == -1 or dist[i] < dist[u]):
                u = i
        visited[u] = True

        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist

def solve():
    N, K = map(int, input().split())
    A = []
    A_sum = []
    for _ in range(N):
        t = int(input())
        a = list(map(int, input().split()))
        if t > K:
            a = a[:K]
        A.append(a)
        A_sum.append(sum(a))

    best = 0
    knapsack = [0] * (K + 1)
    for i in range(N):
        for j in range(K - len(A[i]), -1, -1):
            knapsack[j + len(A[i])] = max(knapsack[j + len(A[i])], knapsack[j] + A_sum[i])

    for i in range(N):
        for j in range(len(A[i])):
            for k in range(K - j, -1, -1):
                knapsack[k + j] = max(knapsack[k + j], knapsack[k] + A[i][j])

    print(max(knapsack))

solve()
