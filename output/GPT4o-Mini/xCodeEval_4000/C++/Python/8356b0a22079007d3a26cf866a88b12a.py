import sys
from collections import deque
from itertools import combinations

INF = 2147483647
MAXN = 1005
MAXK = 9

class Edge:
    def __init__(self, to, rev, cap):
        self.to = to
        self.rev = rev
        self.cap = cap

class MaxFlow:
    def __init__(self):
        self.src = 1002
        self.snk = 1003
        self.G = [[] for _ in range(MAXN)]
        self.dist = [-1] * MAXN
        self.seen = [0] * MAXN

    def clear(self):
        for i in range(MAXN):
            self.G[i].clear()

    def bfs(self, s):
        self.dist = [-1] * MAXN
        self.dist[s] = 0
        Q = deque([s])
        while Q:
            x = Q.popleft()
            for e in self.G[x]:
                if e.cap and self.dist[e.to] == -1:
                    self.dist[e.to] = self.dist[x] + 1
                    Q.append(e.to)

    def dfs(self, now, dest, fl):
        if now == dest:
            return fl
        for i in range(self.seen[now], len(self.G[now])):
            self.seen[now] = i
            ed = self.G[now][i]
            if ed.cap and self.dist[ed.to] == self.dist[now] + 1:
                f = self.dfs(ed.to, dest, min(fl, ed.cap))
                if f:
                    ed.cap -= f
                    self.G[ed.to][ed.rev].cap += f
                    return f
        return 0

    def dinic(self, s=None, t=None):
        if s is None: s = self.src
        if t is None: t = self.snk
        ret = 0
        while True:
            self.seen = [0] * MAXN
            self.bfs(s)
            if self.dist[t] == -1:
                return ret
            f = self.dfs(s, t, INF)
            while f:
                ret += f
                f = self.dfs(s, t, INF)

class Matrix:
    def __init__(self):
        self.dist = [[float('inf')] * 77 for _ in range(77)]

def read():
    return int(sys.stdin.readline().strip())

def qp(x, p, mod):
    ans = 1
    while p:
        if p & 1:
            ans = ans * x % mod
        x = x * x % mod
        p >>= 1
    return ans

def inv(x, mod):
    return qp(x, mod - 2, mod)

def init():
    global cc, id, T1
    cc = 0
    id = [0] * 256
    T1 = Matrix()
    for i in range(1 << k):
        cnt = bin(i).count('1')
        if cnt != x:
            continue
        cc += 1
        id[i] = cc
    for i in range(1 << k):
        cnt = bin(i).count('1')
        if cnt != x:
            continue
        v = i >> 1
        u = i & 1
        if not u:
            T1.dist[id[i]][id[v]] = 0
        else:
            for j in range(k):
                if v & (1 << j):
                    continue
                T1.dist[id[i]][id[v ^ (1 << j)]] = c[j + 1]

def build(pos):
    ret = T1
    for i in range(1 << k):
        if not id[i]:
            continue
        for j in range(1, q + 1):
            if p[j] <= pos and pos - p[j] < k:
                pp = pos - p[j]
                pp = k - 1 - pp
                if i >> (pp + 1) & 1:
                    continue
                for l in range(1 << k):
                    if not id[l]:
                        continue
                    if l >> pp & 1:
                        if ret.dist[id[i]][id[l]] != float('inf'):
                            ret.dist[id[i]][id[l]] += wp[j]
    return ret

def mul(x, y):
    ret = Matrix()
    for i in range(1, cc + 1):
        for j in range(1, cc + 1):
            for k in range(1, cc + 1):
                ret.dist[i][j] = min(ret.dist[i][j], x.dist[i][k] + y.dist[k][j])
    return ret

def multiply(X):
    global dp, dp2
    dp2 = [float('inf')] * 77
    for i in range(1, cc + 1):
        for j in range(1, cc + 1):
            dp2[j] = min(dp2[j], dp[i] + X.dist[i][j])
    dp = dp2[:]

def mqp(x, p):
    R = Matrix()
    for i in range(1, cc + 1):
        R.dist[i][i] = 0
    while p:
        if p & 1:
            R = mul(R, x)
        x = mul(x, x)
        p >>= 1
    return R

def normal(pos):
    for i in range(1, q + 1):
        if p[i] <= pos and pos - p[i] < k:
            return False
    return True

x = read()
k = read()
n = read()
q = read()
n += k - x
c = [0] * (MAXK + 1)
for i in range(1, k + 1):
    c[i] = read()
_init()
p = [0] * 30
wp = [0] * 30
for i in range(1, q + 1):
    p[i] = read()
    wp[i] = read()
dp = [float('inf')] * 77
dp[id[(1 << x) - 1]] = 0
now = k
while now < n:
    if not normal(now + 1):
        Tra = build(now + 1)
        multiply(Tra)
        now += 1
        continue
    Nxt = n + 1
    for i in range(1, q + 1):
        if p[i] > now:
            Nxt = min(Nxt, p[i])
    di = Nxt - now - 1
    Tra = mqp(T1, di)
    multiply(Tra)
    now = Nxt - 1

print(dp[id[(1 << x) - 1]])
