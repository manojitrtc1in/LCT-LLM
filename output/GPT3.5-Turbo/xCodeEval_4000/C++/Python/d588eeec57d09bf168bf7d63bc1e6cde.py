import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)

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

MOD = 1000000007
maxn = 100005

n = int(input())
pts = []
trans = [defaultdict(int), defaultdict(int)]

for _ in range(n):
    x, y = map(int, input().split())
    for j in range(2):
        if x not in trans[j]:
            s = len(trans[j])
            trans[j][x] = s
        x = trans[j][x]
    pts.append([x, y])

x_start, y_start, now = 0, 0, 0
g = defaultdict(list)
visit = [False] * (maxn * 2)
ve = [False] * (maxn * 2)

for i in range(n):
    x = x_start + pts[i][0]
    y = y_start + pts[i][1]
    g[x].append((y, i))
    g[y].append((x, i))

ans = 1
for i in range(now):
    if not visit[i]:
        p = dfs(i)
        k = p[0]
        if p[1] < p[0]:
            ans = (ans * ((2 ** k) - 1)) % MOD
        else:
            ans = (ans * (2 ** k)) % MOD

print(ans)
