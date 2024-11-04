import sys
from collections import defaultdict
from math import gcd

MOD = 1000000007
maxn = 100005

n = int(sys.stdin.readline().strip())
pts = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
visit = [False] * (maxn * 2)
ve = [False] * (maxn * 2)
g = defaultdict(list)

def dfs(u):
    ret = [1, 0]
    visit[u] = True
    for vv in g[u]:
        if ve[vv[1]]:
            continue
        ret[1] += 1
        ve[vv[1]] = True
        if visit[vv[0]]:
            continue
        p = dfs(vv[0])
        ret[0] += p[0]
        ret[1] += p[1]
    return ret

trans = [defaultdict(int), defaultdict(int)]
for i in range(n):
    for j in range(2):
        if pts[i][j] not in trans[j]:
            s = len(trans[j])
            trans[j][pts[i][j]] = s
        pts[i][j] = trans[j][pts[i][j]]

x_start = sum(len(trans[0]))
y_start = x_start + len(trans[1])

for i in range(n):
    x = x_start + pts[i][0]
    y = y_start + pts[i][1]
    g[x].append((y, i))
    g[y].append((x, i))

ans = 1
for i in range(x_start + y_start):
    if not visit[i]:
        p = dfs(i)
        k = p[0]
        if p[1] < p[0]:
            ans = (ans * (pow(2, k, MOD) - 1)) % MOD
        else:
            ans = (ans * pow(2, k, MOD)) % MOD

print(ans)
