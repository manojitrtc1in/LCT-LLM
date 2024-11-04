from collections import defaultdict

def remove_leaf(s, deg, v):
    if not s[v]:
        deg[c[v]].remove((0, v))
        return
    u = next(iter(s[v]))
    deg[c[v]].remove((len(s[v]), v))
    deg[c[u]].remove((len(s[u]), u))
    s[u].remove(v)
    s[v].remove(u)
    deg[c[u]].add((len(s[u]), u))

def erase_grey(s, deg):
    while True:
        if not deg[0]:
            break
        ret = min(deg[0])
        if ret[0] > 1:
            break
        remove_leaf(s, deg, ret[1])

def solve(s, deg, beg):
    res = 0
    erase_grey(s, deg)
    while True:
        if not deg[0] and not deg[1] and not deg[2]:
            break
        if not deg[beg]:
            beg = 3 - beg
            continue
        res += 1
        while True:
            if not deg[beg]:
                break
            ret = min(deg[beg])
            if ret[0] > 1:
                break
            remove_leaf(s, deg, ret[1])
            erase_grey(s, deg)
        beg = 3 - beg
    return res

t = int(input())
for _ in range(t):
    n = int(input())
    c = list(map(int, input().split()))
    s = defaultdict(set)
    st = defaultdict(set)
    deg = defaultdict(set)
    degt = defaultdict(set)
    for _ in range(n-1):
        u, v = map(int, input().split())
        s[u].add(v)
        s[v].add(u)
        st[u].add(v)
        st[v].add(u)
    for i in range(1, n+1):
        deg[c[i]].add((len(s[i]), i))
        degt[c[i]].add((len(s[i]), i))
    print(max(min(solve(s, deg, 1), solve(st, degt, 2)), 1))
