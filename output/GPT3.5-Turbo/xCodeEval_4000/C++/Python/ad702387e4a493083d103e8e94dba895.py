import sys
from collections import deque

def dfs(x):
    visit[x] = 1
    c[x] = cnt
    for u in edges[x]:
        if visit[u]:
            continue
        dfs(u)

def bfs(src):
    visit = [0] * (n + 1)
    dist = [0] * (n + 1)
    visit[src] = 1
    dist[src] = 0
    que = deque()
    que.append(src)
    while que:
        x = que.popleft()
        for u in edges[x]:
            if visit[u]:
                continue
            dist[u] = dist[x] + 1
            visit[u] = 1
            que.append(u)

def liu(x, y, flow):
    assert flow >= 0
    a[x] -= flow
    assert a[x] >= 0
    a[y] += flow
    assert a[y] <= v
    res.append(((x, y), flow))

def liu(i, flow, routes):
    if i == len(routes) - 1:
        return
    nxt = routes[i + 1]
    now = routes[i]
    if a[nxt] + flow <= v:
        liu(now, nxt, flow)
        liu(i + 1, flow, routes)
    else:
        original_a_now = a[now]
        moved = v - a[nxt]
        liu(now, nxt, v - a[nxt])
        liu(i + 1, flow, routes)
        liu(now, nxt, flow - moved)
        new_a_now = a[now]

def adjust(x, y):
    assert a[x] != b[x]
    assert a[y] != b[y]
    if a[x] < b[x]:
        x, y = y, x
    flow = min(abs(a[x] - b[x]), abs(a[y] - b[y]))
    bfs(x)
    routes = [y]
    while y != x:
        step = dist[y]
        nxt = -1
        for ny in edges[y]:
            if dist[ny] != step - 1:
                continue
            nxt = ny
            break
        y = nxt
        routes.append(y)
    routes.reverse()
    notEq = 0
    for x in routes:
        if a[x] != b[x]:
            notEq += 1
    liu(0, flow, routes)
    for x in routes:
        if a[x] != b[x]:
            notEq -= 1
    assert notEq >= 1

n, v, m = map(int, input().split())
a = [0] * n
b = [0] * n
edges = [[] for _ in range(n)]
c = [0] * n
visit = [0] * n
cnt = 0
s = [0] * n
res = []

for i in range(n):
    a[i] = int(input())
for i in range(n):
    b[i] = int(input())
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    edges[x].append(y)
    edges[y].append(x)

for i in range(n):
    if visit[i]:
        continue
    dfs(i)
    cnt += 1

for i in range(n):
    s[c[i]] += a[i]
    s[c[i]] -= b[i]

for i in range(n):
    if a[i] == b[i]:
        continue
    for j in range(i + 1, n):
        if c[i] != c[j]:
            continue
        if a[j] == b[j]:
            continue
        if a[i] < b[i] and a[j] < b[j]:
            continue
        if a[i] > b[i] and a[j] > b[j]:
            continue
        adjust(i, j)
        break
    if a[i] != b[i]:
        i -= 1

print(len(res))
for e in res:
    print(e[0][0] + 1, e[0][1] + 1, e[1])
