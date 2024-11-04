import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)

def go(cur, iter, g, sz, used, c):
    sz[cur] = 1
    used[cur] = iter
    t = 0
    for to in g[cur]:
        if used[to] != iter:
            go(to, iter, g, sz, used, c)
            sz[cur] += sz[to]
            t = max(t, sz[to])
    t = max(t, n - sz[cur])
    if t * 2 <= n:
        c.append(cur)

def dfs2(cur, p, used, g, st):
    used[cur] = True
    for to in g[cur]:
        if not used[to]:
            dfs2(to, cur, used, g, st)
    st.append((cur, p))

def solve(cur, ct, ans):
    st = []
    dfs2(cur, -1, used, g, st)
    st.pop()
    last = cur
    for p in st:
        v, par = p
        if par != cur:
            ans.append((ct, last, v))
            ans.append((v, par, cur))
            last = v
    if last != cur:
        ans.append((ct, last, cur))

n = int(input())
g = defaultdict(set)
for _ in range(n-1):
    x, y = map(int, input().split())
    g[x].add(y)
    g[y].add(x)

ct = 0
c = []
sz = [0] * (n+1)
used = [0] * (n+1)
go(1, 1, g, sz, used, c)
used = [0] * (n+1)
assert len(c) > 0
for x in c:
    used[x] = True
for x in c:
    ct = x
    for to in g[ct]:
        if not used[to]:
            solve(to, ct, ans)

print(len(ans))
assert len(ans) <= 2 * n
for t in ans:
    print(t[0], t[1], t[2])
