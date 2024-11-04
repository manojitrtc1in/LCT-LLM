import sys
from collections import deque

def bfs(graph, start, end, parent):
    visited = [False] * len(graph)
    queue = deque()
    queue.append(start)
    visited[start] = True

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True
                parent[neighbor] = node
                if neighbor == end:
                    return True

    return False

def find_augmenting_path(graph, match, parent, start, end):
    visited = [False] * len(graph)
    queue = deque()
    queue.append(start)
    visited[start] = True

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if not visited[neighbor] and match[node] != neighbor:
                queue.append(neighbor)
                visited[neighbor] = True
                parent[neighbor] = node
                if neighbor == end:
                    return True

    return False

def hopcroft_karp(graph, n, m):
    match = [-1] * n
    parent = [-1] * m
    max_matching = 0

    while bfs(graph, 0, n-1, parent):
        for i in range(1, n-1):
            if match[i] == -1 and find_augmenting_path(graph, match, parent, 0, i):
                max_matching += 1

    return max_matching

def solve():
    str = input()
    n = int(input())

    soln = [[0] * (n+1) for _ in range(2)]
    xsoln = [[0] * (n+1) for _ in range(2)]

    if str[-1] == 'F':
        for j in range(n+1):
            soln[0][j] = j if j & 1 else 1
    else:
        for j in range(n+1):
            soln[0][j] = 1 if j & 1 else 0

    for i in range(1, len(str)):
        xsoln = soln.copy()
        if str[-i] == 'F':
            soln[0][0] = 1 + xsoln[0][0]
            soln[1][0] = 1 + xsoln[1][0]
            for j in range(1, n+1):
                soln[0][j] = max(1 + xsoln[0][j], -xsoln[1][j-1])
                soln[1][j] = min(1 + xsoln[1][j], -xsoln[0][j-1])
        else:
            soln[0][0] = -xsoln[1][0]
            soln[1][0] = -xsoln[0][0]
            for j in range(1, n+1):
                soln[0][j] = max(-xsoln[1][j], 1 + xsoln[0][j-1])
                soln[1][j] = min(-xsoln[0][j], 1 + xsoln[1][j-1])

    return max(soln[0][n], -soln[1][n])

print(solve())
