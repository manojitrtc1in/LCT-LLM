from collections import defaultdict
import sys
import math

MOD = 1000000007
maxn = 100005

def gcd(a, b):
    while a != 0:
        b %= a
        if b == 0:
            return a
        a %= b
    return b

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

def inv_mod(a, m):
    x, y = extended_gcd(a, m)
    if x < 0:
        return x + m
    return x

def extended_gcd(a, b):
    if b == 0:
        return 1, 0, a
    x1, y1, g = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return x, y, g

def div_mod(u, v, m):
    g = gcd(v, m)
    assert u % g == 0
    mm = m // g
    return mul_mod(u // g, inv_mod(v // g, mm), mm)

def dfs(u):
    ret = [1, len(g[u])]
    visit[u] = True
    for v in g[u]:
        if not visit[v]:
            p = dfs(v)
            ret[0] += p[0]
            ret[1] += p[1]
    return ret

input = sys.stdin.read
data = input().split()
n = int(data[0])
pts = []
for i in range(n):
    pts.append((int(data[2 * i + 1]), int(data[2 * i + 2])))

trans = [defaultdict(int), defaultdict(int)]
cnt = 0
for j in range(2):
    for i in range(n):
        if pts[i][j] not in trans[j]:
            trans[j][pts[i][j]] = cnt
            cnt += 1

g = defaultdict(list)
for i in range(n):
    x = trans[0][pts[i][0]]
    y = trans[1][pts[i][1]]
    g[x].append(y)
    g[y].append(x)

ans = 1
visit = [False] * (cnt * 2)
for i in range(cnt):
    if not visit[i]:
        p = dfs(i)
        vers = p[0]
        edgs = p[1] // 2
        if edgs == vers - 1:
            ans = mul_mod(ans, (pow_mod(2, vers, MOD) - 1) % MOD)
        else:
            ans = mul_mod(ans, pow_mod(2, vers, MOD))

print(ans)
