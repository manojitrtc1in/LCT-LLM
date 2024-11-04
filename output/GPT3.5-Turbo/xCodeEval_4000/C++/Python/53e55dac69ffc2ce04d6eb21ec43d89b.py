import sys
from collections import deque

sys.setrecursionlimit(10**6)

def dfs(v, p):
    global ans
    global g
    global used
    global c
    global sz
    global n
    sz[v] = 1
    used[v] = True
    t = 0
    for to in g[v]:
        if not used[to]:
            dfs(to, v)
            sz[v] += sz[to]
            t = max(t, sz[to])
    t = max(t, n - sz[v])
    if t * 2 <= n:
        c.append(v)

def solve(v):
    global ans
    global g
    global used
    global c
    global ct
    global n
    global sz
    st = []
    def dfs2(v, p):
        global used
        global g
        st.append((v, p))
        used[v] = True
        for to in g[v]:
            if not used[to]:
                dfs2(to, v)
    dfs2(v, -1)
    st.pop()
    last = v
    for p in st:
        v, par = p
        if par != v:
            ans.append((ct, last, v))
            ans.append((v, par, ct))
            last = v
    if last != v:
        ans.append((ct, last, v))

n = int(input())
g = [[] for _ in range(n+1)]
for _ in range(n-1):
    x, y = map(int, input().split())
    g[x].append(y)
    g[y].append(x)

ct = 0
c = []
sz = [0] * (n+1)
used = [False] * (n+1)
dfs(1, -1)
used = [False] * (n+1)
assert len(c) > 0
for x in c:
    used[x] = True
for x in c:
    ct = x
    for to in g[ct]:
        if not used[to]:
            solve(to)

print(len(ans))
assert len(ans) <= 2 * n
for t in ans:
    print(t[0], t[1], t[2])
