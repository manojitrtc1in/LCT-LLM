import sys
from collections import deque

def dfs(u):
    if visited[u]:
        return False
    visited[u] = True
    path.append(u)
    if A[u] < B[u]:
        return True
    for v in adj[u]:
        if dfs(v):
            return True
    path.pop()
    return False

n, UP, e = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

adj = [[] for _ in range(n+1)]
for _ in range(e):
    x, y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)

op = []
visited = [False] * (n+1)
for i in range(1, n+1):
    if not visited[i]:
        path = []
        if dfs(i):
            f = min(A[i] - B[i], B[path[-1]] - A[path[-1]])
            for j in range(len(path)-1):
                u, v = path[j], path[j+1]
                d = min(f, A[u], UP - A[v])
                if d:
                    op.append((u, v, d))
            for j in range(len(path)-2, -1, -1):
                u, v = path[j], path[j+1]
                d = f - d
                if d:
                    op.append((u, v, d))
        else:
            print("NO")
            sys.exit(0)

for i in range(1, n+1):
    if A[i] != B[i]:
        print("NO")
        sys.exit(0)

print(len(op))
for u, v, d in op:
    print(u, v, d)
