from collections import defaultdict, deque

maxn = 200007
mod = 998244353

n, t = 0, 0
c = [0] * maxn
s = [set() for _ in range(maxn)]
st = [set() for _ in range(maxn)]
deg = [set() for _ in range(3)]
degt = [set() for _ in range(3)]

def remove_leaf(s, deg, v):
    if not s[v]:
        deg[c[v]].discard((0, v))
        return
    u = next(iter(s[v]))

    assert v
    deg[c[v]].discard((len(s[v]), v))
    deg[c[u]].discard((len(s[u]), u))
    s[u].discard(v)
    s[v].discard(u)
    deg[c[u]].add((len(s[u]), u))

def id5(s, deg):
    while True:
        if not deg[0]:
            break
        ret = min(deg[0])
        if ret[0] > 1:
            break
        remove_leaf(s, deg, ret[1])

def solve(s, deg, beg):
    res = 0
    id5(s, deg)
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
            id5(s, deg)
        beg = 3 - beg
    return res

def main():
    global n, t, c, s, st, deg, degt
    t = int(input())
    for _ in range(t):
        n = int(input())
        for i in range(1, n + 1):
            c[i] = int(input())
        for _ in range(n - 1):
            u, v = map(int, input().split())
            s[u].add(v)
            s[v].add(u)
            st[u].add(v)
            st[v].add(u)
        for i in range(1, n + 1):
            deg[c[i]].add((len(s[i]), i))
            degt[c[i]].add((len(s[i]), i))
        print(max(min(solve(s, deg, 1), solve(st, degt, 2)), 1))

if __name__ == "__main__":
    main()
