import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)

INF = 1011111111
LLINF = 1000111000111000111
EPS = 1e-10
mod = 1000000007
PI = 3.14159265358979323

g = defaultdict(set)
ct = 0
c = []
sz = [0] * 202020
used = [0] * 202020
n = 0
ans = []

def go(cur, iter=1):
    global ct
    sz[cur] = 1
    used[cur] = iter
    t = 0
    for to in g[cur]:
        if used[to] != iter:
            go(to, iter)
            sz[cur] += sz[to]
            t = max(t, sz[to])
    t = max(t, n - sz[cur])
    if t * 2 <= n:
        ct = cur
        c.append(cur)

st = []

def dfs2(cur, p=-1):
    used[cur] = True
    for to in g[cur]:
        if not used[to]:
            dfs2(to, cur)
    st.append((cur, p))

def solve(cur):
    global ct
    st.clear()
    dfs2(cur)
    st.pop()
    last = cur
    for v, par in st:
        if par != cur:
            ans.append((ct, last, v))
            ans.append((v, par, cur))
            last = v
    if last != cur:
        ans.append((ct, last, cur))

def main():
    global n
    n = int(input())
    for _ in range(n - 1):
        x, y = map(int, input().split())
        g[x].add(y)
        g[y].add(x)
    
    go(1)
    used[:] = [0] * len(used)
    assert len(c) > 0
    for x in c:
        used[x] = True
    for x in c:
        global ct
        ct = x
        for to in g[ct]:
            if not used[to]:
                solve(to)
    
    print(len(ans))
    assert len(ans) <= 2 * n
    for t in ans:
        print(t[0], t[1], t[2])

if __name__ == "__main__":
    main()
