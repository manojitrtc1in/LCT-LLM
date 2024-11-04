import sys
from collections import defaultdict

input = sys.stdin.read
MOD = int(1e9) + 7

class Op:
    def __init__(self, u, v, d):
        self.u = u
        self.v = v
        self.d = d

    def output(self):
        print(self.u, self.v, self.d)

def dfs(u):
    if vis[u]:
        return False
    vis[u] = True
    path.append(u)
    if A[u] < B[u]:
        return True
    for v in adj[u]:
        if dfs(v):
            return True
    path.pop()
    return False

data = input().split()
index = 0

def RD():
    global index
    x = int(data[index])
    index += 1
    return x

n = RD()
UP = RD()
e = RD()

A = [0] * (n + 1)
B = [0] * (n + 1)
for i in range(1, n + 1):
    A[i] = RD()
for i in range(1, n + 1):
    B[i] = RD()

adj = defaultdict(list)
for _ in range(e):
    x = RD()
    y = RD()
    adj[x].append(y)
    adj[y].append(x)

op = []
for i in range(1, n + 1):
    while A[i] > B[i]:
        vis = [False] * (n + 1)
        path = []
        if not dfs(i):
            print("NO")
            sys.exit(0)

        f = min(A[i] - B[i], B[path[-1]] - A[path[-1]])

        t = [0] * (len(path) - 1)
        for j in range(len(path) - 1):
            u = path[j]
            v = path[j + 1]
            d = min(f, A[u], UP - A[v])
            t[j] = f - d
            if d:
                op.append(Op(u, v, d))

        for j in range(len(path) - 2, -1, -1):
            u = path[j]
            v = path[j + 1]
            d = t[j]
            if d:
                op.append(Op(u, v, d))

for i in range(1, n + 1):
    if A[i] != B[i]:
        print("NO")
        sys.exit(0)

print(len(op))
for operation in op:
    operation.output()
