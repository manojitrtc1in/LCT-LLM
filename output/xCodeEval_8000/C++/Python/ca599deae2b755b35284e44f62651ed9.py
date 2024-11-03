import sys
from collections import deque

def bfs(graph, start, end, parent):
    visited = [False] * len(graph)
    queue = deque()
    queue.append(start)
    visited[start] = True

    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if not visited[v]:
                queue.append(v)
                visited[v] = True
                parent[v] = u
                if v == end:
                    return True

    return False

def find_matching(graph, m, n):
    parent = [-1] * n
    max_matching = 0

    for u in range(m):
        if bfs(graph, u, parent):
            max_matching += 1

    return max_matching

def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]

    for _ in range(m):
        u, v = map(int, input().split())
        graph[u-1].append(v-1)

    max_matching = find_matching(graph, n, m)
    print(max_matching)

if __name__ == "__main__":
    main()
