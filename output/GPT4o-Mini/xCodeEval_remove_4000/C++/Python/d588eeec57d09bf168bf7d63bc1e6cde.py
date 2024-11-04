import sys
from collections import defaultdict

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
    x, y = 1, 0
    g = gcd(a, m)
    if g != 1:
        return None  # No modular inverse if a and m are not coprime
    while m:
        q = a // m
        a, m = m, a % m
        x, y = y, x - q * y
    return x % m

def div_mod(u, v, m):
    g = gcd(v, m)
    assert u % g == 0
    mm = m // g
    return mul_mod(u // g, inv_mod(v // g, mm), mm)

def dfs(u):
    ret = [1, 0]
    visit[u] = True
    for vv in g[u]:
        if ve[vv[1]]:
            continue
        ret[1] += 1
        ve[vv[1]] = True
        if visit[vv[0]]:
            continue
        p = dfs(vv[0])
        ret[0] += p[0]
        ret[1] += p[1]
    return ret

n = int(sys.stdin.readline().strip())
pts = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
visit = [False] * (maxn * 2)
ve = [False] * (maxn * 2)
g = defaultdict(list)

trans = [defaultdict(int), defaultdict(int)]
now = 0

for i in range(n):
    for j in range(2):
        if pts[i][j] not in trans[j]:
            trans[j][pts[i][j]] = len(trans[j])
        pts[i][j] = trans[j][pts[i][j]]

x_start = now
now += len(trans[0])
y_start = now
now += len(trans[1])

assert now < maxn * 2

for i in range(n):
    x = x_start + pts[i][0]
    y = y_start + pts[i][1]
    g[x].append((y, i))
    g[y].append((x, i))

ans = 1

for i in range(now):
    if not visit[i]:
        p = dfs(i)
        k = p[0]
        if p[1] < p[0]:
            ans = mul_mod(ans, (pow_mod(2, k, MOD) - 1) % MOD)
        else:
            ans = mul_mod(ans, pow_mod(2, k, MOD))

print(ans)
