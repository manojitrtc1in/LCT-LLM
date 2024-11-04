from collections import defaultdict
from itertools import combinations

INF = int(1e9)
LINF = int(1e18)
M = int(1e9 + 7)

C = 20
G = defaultdict(list)
cur = []
masks = [0] * C
dp = [False] * (1 << C)
vis = [False] * C
mask = 0

def dfs(v):
    global mask
    vis[v] = True
    mask |= 1 << v
    cur.append(v)

    for s in G[v]:
        if not vis[s]:
            dfs(s)

def count():
    sub = []
    for m in range(mask + 1):
        if m & mask:
            sub.append(m)
    sub.reverse()

    res = 0
    for m in sub:
        for v in cur:
            if m & (1 << v):
                dp[m] |= dp[m ^ (1 << v)] and ((m & masks[v] & mask) == 0)
        if dp[m]:
            res = max(res, bin(m).count('1'))
    return res

def solve():
    n = int(input())
    s = input().strip()
    t = input().strip()

    def get(c):
        return ord(c) - ord('a')

    for i in range(n):
        if s[i] != t[i]:
            a = get(s[i])
            b = get(t[i])
            G[a].append(b)
            G[b].append(a)
            masks[a] |= 1 << b

    res = 0
    dp[0] = True
    for i in range(C):
        if not vis[i]:
            global mask, cur
            mask = 0
            cur.clear()
            dfs(i)
            tmp = count()
            res += 2 * len(cur) - 1 - tmp

    for i in range(C):
        vis[i] = False
        masks[i] = 0
    for i in range(1 << C):
        dp[i] = False
    for i in range(C):
        G[i].clear()

    return res

t = int(input())
for _ in range(t):
    print(solve())
