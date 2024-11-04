from collections import deque
import sys

def read():
    return int(sys.stdin.readline().strip())

class Mymath:
    @staticmethod
    def qp(x, p, mod):
        ans = 1
        while p:
            if p & 1:
                ans = ans * x % mod
            x = x * x % mod
            p >>= 1
        return ans

    @staticmethod
    def inv(x, mod):
        return Mymath.qp(x, mod - 2, mod)

    @staticmethod
    def C(N, K, fact, mod):
        return fact[N] * Mymath.inv(fact[K], mod) % mod * Mymath.inv(fact[N - K], mod) % mod

    @staticmethod
    def gcd(A, B):
        if B == 0:
            return A
        return Mymath.gcd(B, A % B)

    @staticmethod
    def lcm(A, B):
        return A * B // Mymath.gcd(A, B)

class fwt:
    @staticmethod
    def FWT(a, n, mod):
        d = 1
        while d < n:
            m = d << 1
            for i in range(0, n, m):
                for j in range(d):
                    x = a[i + j]
                    y = a[i + j + d]
                    a[i + j] = (x + y) % mod
                    a[i + j + d] = (x - y + mod) % mod
            d <<= 1

    @staticmethod
    def UFWT(a, n, mod):
        rev = Mymath.inv(2, mod)
        d = 1
        while d < n:
            m = d << 1
            for i in range(0, n, m):
                for j in range(d):
                    x = a[i + j]
                    y = a[i + j + d]
                    a[i + j] = (x + y) * rev % mod
                    a[i + j + d] = (x - y) * rev % mod + mod % mod
            d <<= 1

    @staticmethod
    def solve(a, b, n, mod):
        fwt.FWT(a, n, mod)
        fwt.FWT(b, n, mod)
        for i in range(n):
            a[i] = a[i] * b[i] % mod
        fwt.UFWT(a, n, mod)

class Maxflow:
    Maxn = 1005

    class edge:
        def __init__(self, _to, _rev, _cap):
            self.to = _to
            self.rev = _rev
            self.cap = _cap

    src = 1002
    snk = 1003
    G = [[] for _ in range(Maxn)]
    dist = [-1] * Maxn
    seen = [0] * Maxn
    n = 0

    @staticmethod
    def Clear():
        for i in range(Maxflow.Maxn):
            Maxflow.G[i].clear()

    @staticmethod
    def bfs(s):
        for i in range(Maxflow.Maxn):
            Maxflow.dist[i] = -1
        Maxflow.dist[s] = 0
        Q = deque([s])
        while Q:
            x = Q.popleft()
            for e in Maxflow.G[x]:
                if e.cap and Maxflow.dist[e.to] == -1:
                    Maxflow.dist[e.to] = Maxflow.dist[x] + 1
                    Q.append(e.to)

    @staticmethod
    def dfs(now, dest, fl):
        if now == dest:
            return fl
        for i in range(Maxflow.seen[now], len(Maxflow.G[now])):
            ed = Maxflow.G[now][i]
            if ed.cap and Maxflow.dist[ed.to] == Maxflow.dist[now] + 1:
                f = Maxflow.dfs(ed.to, dest, min(fl, ed.cap))
                if f:
                    ed.cap -= f
                    Maxflow.G[ed.to][ed.rev].cap += f
                    return f
        return 0

    @staticmethod
    def dinic(s=src, t=snk):
        ret = 0
        while True:
            Maxflow.seen = [0] * Maxflow.Maxn
            Maxflow.bfs(s)
            if Maxflow.dist[t] == -1:
                return ret
            f = Maxflow.dfs(s, t, float('inf'))
            while f:
                ret += f
                f = Maxflow.dfs(s, t, float('inf'))

class Geometry:
    class iP:
        def __init__(self, _x=0, _y=0):
            self.x = _x
            self.y = _y

        def __add__(self, p):
            return Geometry.iP(self.x + p.x, self.y + p.y)

        def __sub__(self, p):
            return Geometry.iP(self.x - p.x, self.y - p.y)

        def __mul__(self, k):
            return Geometry.iP(self.x * k, self.y * k)

        def det(self, p):
            return self.x * p.y - self.y * p.x

        def dot(self, p):
            return self.x * p.x + self.y * p.y

        def dist(self):
            return self.x * self.x + self.y * self.y

        def __lt__(self, p):
            return (self.x, self.y) < (p.x, p.y)

    class dP:
        def __init__(self, _x=0.0, _y=0.0):
            self.x = _x
            self.y = _y

        def __add__(self, p):
            return Geometry.dP(self.x + p.x, self.y + p.y)

        def __sub__(self, p):
            return Geometry.dP(self.x - p.x, self.y - p.y)

        def __mul__(self, k):
            return Geometry.dP(self.x * k, self.y * k)

        def det(self, p):
            return self.x * p.y - self.y * p.x

        def dot(self, p):
            return self.x * p.x + self.y * p.y

        def dist(self):
            return self.x * self.x + self.y * self.y

        def __lt__(self, p):
            return (self.x, self.y) < (p.x, p.y)

def id0(X, l):
    ret = []
    X.sort()
    ret.append(X[0])
    for i in range(1, l):
        while len(ret) >= 2 and (ret[-2] - X[i]).det(ret[-1] - X[i]) >= 0:
            ret.pop()
        ret.append(X[i])
    rs = len(ret) + 1
    for i in range(l - 1, 0, -1):
        while len(ret) >= rs and (ret[-2] - X[i]).det(ret[-1] - X[i]) >= 0:
            ret.pop()
        ret.append(X[i])
    return ret

Maxn = 9
x = read()
k = read()
n = read()
q = read()
n += k - x
c = [0] * (Maxn + 1)
for i in range(1, k + 1):
    c[i] = read()

id = [0] * 256
T1 = [[float('inf')] * 77 for _ in range(77)]
cc = 0

def _init():
    global cc
    for i in range(1 << k):
        cnt = bin(i).count('1')
        if cnt != x:
            continue
        id[i] = cc + 1
        cc += 1

    for i in range(1 << k):
        cnt = bin(i).count('1')
        if cnt != x:
            continue
        v = i >> 1
        u = i & 1
        if not u:
            T1[id[i]][id[v]] = 0
        else:
            for j in range(k):
                if v & (1 << j):
                    continue
                T1[id[i]][id[v ^ (1 << j)]] = c[j + 1]

_init()

p = [0] * 30
wp = [0] * 30
dp = [float('inf')] * 77
dp2 = [float('inf')] * 77

for i in range(1, q + 1):
    p[i] = read()
    wp[i] = read()

for i in range(1, cc + 1):
    dp[i] = float('inf')
dp[id[(1 << x) - 1]] = 0
now = k

def normal(pos):
    for i in range(1, q + 1):
        if p[i] <= pos and pos - p[i] < k:
            return False
    return True

while now < n:
    if not normal(now + 1):
        Tra = Build(now + 1)
        Mul(Tra)
        now += 1
        continue

    Nxt = n + 1
    for i in range(1, q + 1):
        if p[i] > now:
            Nxt = min(Nxt, p[i])

    di = Nxt - now - 1
    Tra = mqp(T1, di)
    Mul(Tra)
    now = Nxt - 1

print(dp[id[(1 << x) - 1]])
