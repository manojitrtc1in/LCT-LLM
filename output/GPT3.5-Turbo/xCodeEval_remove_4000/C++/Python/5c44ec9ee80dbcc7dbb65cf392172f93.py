import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)

MOD = 1000000007
maxn = 100005

def mul_mod(a, b, m):
    p = a
    p = (p * b) % m
    return p

def pow_mod(a, p, m):
    r = 1
    a %= m
    while p:
        if p & 1:
            r = mul_mod(r, a, m)
        a = mul_mod(a, a, m)
        p >>= 1
    return r

def inv_mod(a, m):
    x, y = id1(a, m)
    if x < 0:
        return x + m
    return x

def id1(a, b):
    if b == 0:
        return 1, 0
    x, y = id1(b, a % b)
    y -= (a // b) * x
    return y, x

def id7(u, v, m):
    r = u + v
    if r >= m:
        r -= m
    return r

def id3(u, v, m):
    r = u - v
    if r < 0:
        r += m
    return r

def div_mod(u, v, m):
    g = gcd(v, m)
    assert u % g == 0
    mm = m // g
    return mul_mod(u // g, inv_mod(v // g, mm), mm)

def id0(a, b):
    q = a // b
    r = a % b
    if r < 0:
        if b < 0:
            q += 1
            r -= b
        else:
            q -= 1
            r += b
    return q, r

def gcd(a, b):
    while a != 0:
        b %= a
        if b == 0:
            return a
        a %= b
    return b

def dfs(u):
    ret = (1, len(g[u]))
    visit[u] = True
    for v in g[u]:
        if not visit[v]:
            p = dfs(v)
            ret = (ret[0] + p[0], ret[1] + p[1])
    return ret

n = int(input())
pts = []
trans = [defaultdict(int), defaultdict(int)]
for _ in range(n):
    x, y = map(int, input().split())
    pts.append((x, y))
    for j in range(2):
        trans[j][pts[-1][j]] = 0

cnt = 0
for j in range(2):
    for p in trans[j]:
        trans[j][p] = cnt
        cnt += 1

g = [[] for _ in range(cnt)]
visit = [False] * (2 * cnt)

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
            ans = mul_mod(ans, pow_mod(2, vers) - 1, MOD)
        else:
            ans = mul_mod(ans, pow_mod(2, vers), MOD)

print(ans)
