import sys
from collections import defaultdict
from math import gcd

MOD = 1000000007
maxn = 100005

def mul_mod(a, b, m):
    return (a * b) % m

def pow_mod(a, p, m):
    r = 1
    a %= m
    while p:
        if p & 1:
            r = mul_mod(r, a, m)
        a = mul_mod(a, a, m)
        p >>= 1
    return r

def addx_mod(u, v, m):
    r = u + v
    if r >= m:
        r -= m
    return r

def subx_mod(u, v, m):
    r = u - v
    if r < 0:
        r += m
    return r

def dfs(u):
    ret = [1, len(g[u])]
    visit[u] = True
    for v in g[u]:
        if not visit[v]:
            p = dfs(v)
            ret[0] += p[0]
            ret[1] += p[1]
    return ret

n = int(sys.stdin.readline().strip())
pts = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
visit = [False] * (maxn * 2)
g = defaultdict(list)

trans = [defaultdict(int), defaultdict(int)]
cnt = 0

for j in range(2):
    for i in range(n):
        if pts[i][j] not in trans[j]:
            trans[j][pts[i][j]] = cnt
            cnt += 1

for i in range(n):
    x = trans[0][pts[i][0]]
    y = trans[1][pts[i][1]]
    g[x].append(y)
    g[y].append(x)

ans = 1

for i in range(cnt):
    if not visit[i]:
        p = dfs(i)
        vers = p[0]
        edgs = p[1] // 2
        if edgs == vers - 1:
            ans = mul_mod(ans, subx_mod(pow_mod(2, vers, MOD), 1, MOD))
        else:
            ans = mul_mod(ans, pow_mod(2, vers, MOD))

print(ans)
