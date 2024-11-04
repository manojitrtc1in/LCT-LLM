from collections import deque
import sys

sys.setrecursionlimit(10**6)

n, v, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
edges = [[] for _ in range(305)]
c = [0] * 305
visit = [0] * 305
cnt = 0
s = [0] * 305
res = []
dist = [0] * 305

def dfs(x):
    global cnt
    visit[x] = 1
    c[x] = cnt
    for u in edges[x]:
        if visit[u]:
            continue
        dfs(u)

def bfs(src):
    global dist
    visit[:] = [0] * len(visit)
    visit[src] = 1
    dist[src] = 0
    que = deque([src])
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

def liu_recursive(i, flow, routes):
    if i == len(routes) - 1:
        return
    nxt = routes[i + 1]
    now = routes[i]
    if a[nxt] + flow <= v:
        liu(now, nxt, flow)
        liu_recursive(i + 1, flow, routes)
    else:
        original_a_now = a[now]
        moved = v - a[nxt]
        liu(now, nxt, v - a[nxt])
        liu_recursive(i + 1, flow, routes)
        liu(now, nxt, flow - moved)

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
    notEq = sum(1 for x in routes if a[x] != b[x])
    liu_recursive(0, flow, routes)
    for x in routes:
        if a[x] != b[x]:
            notEq -= 1
    assert notEq >= 1

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
    if s[i]:
        print("NO")
        sys.exit()

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
