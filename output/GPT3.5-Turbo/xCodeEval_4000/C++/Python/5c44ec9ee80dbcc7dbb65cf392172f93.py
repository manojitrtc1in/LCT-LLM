import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)

def dfs(u, visited, graph):
    ret = (1, len(graph[u]))
    visited[u] = True
    for v in graph[u]:
        if not visited[v]:
            p = dfs(v, visited, graph)
            ret = (ret[0] + p[0], ret[1] + p[1])
    return ret

MOD = 1000000007
maxn = 100005

n = int(input())
pts = []
trans = [defaultdict(int), defaultdict(int)]

for _ in range(n):
    x, y = map(int, input().split())
    pts.append((x, y))
    for j in range(2):
        trans[j][pts[-1][j]] = 0

cnt = 0
for j in range(2):
    for p in trans[j]:
        trans[j][p] = cnt
        cnt += 1

g = defaultdict(list)
for i in range(n):
    x = trans[0][pts[i][0]]
    y = trans[1][pts[i][1]]
    g[x].append(y)
    g[y].append(x)

ans = 1
visited = [False] * (cnt + 1)
for i in range(cnt):
    if not visited[i]:
        p = dfs(i, visited, g)
        vers = p[0]
        edgs = p[1] // 2
        if edgs == vers - 1:
            ans = (ans * (pow(2, vers, MOD) - 1)) % MOD
        else:
            ans = (ans * pow(2, vers, MOD)) % MOD

print(ans)
