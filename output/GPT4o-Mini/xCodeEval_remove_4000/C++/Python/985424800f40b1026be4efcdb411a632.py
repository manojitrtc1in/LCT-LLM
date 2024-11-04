from collections import deque
from math import gcd
from itertools import accumulate

MOD = 1000000007
INF = 1 << 60

def lcm(a, b):
    return a // gcd(a, b) * b

def is_prime(x):
    if x == 1:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def divisor(n):
    ret = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()
    return ret

def modpow(a, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res

def modinv(a, mod):
    return modpow(a, mod - 2, mod)

MAX = 510000
fac = [1] * MAX
finv = [1] * MAX
inv = [0] * MAX

def COMinit():
    for i in range(2, MAX):
        fac[i] = fac[i - 1] * i % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
        finv[i] = finv[i - 1] * inv[i] % MOD

def COM(n, k):
    if n < k or n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD

class UnionFind:
    def __init__(self, n):
        self.par = [-1] * n

    def root(self, x):
        if self.par[x] < 0:
            return x
        else:
            self.par[x] = self.root(self.par[x])
            return self.par[x]

    def issame(self, x, y):
        return self.root(x) == self.root(y)

    def merge(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        if self.par[x] > self.par[y]:
            x, y = y, x
        self.par[x] += self.par[y]
        self.par[y] = x
        return True

    def size(self, x):
        return -self.par[self.root(x)]

class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.n:
            self.bit[i] += x
            i += i & -i

class SegmentTree:
    def __init__(self, v):
        sz = len(v)
        self.n = 1
        while self.n < sz:
            self.n *= 2
        self.node = [0] * (2 * self.n - 1)
        self.lazy = [0] * (2 * self.n - 1)

        for i in range(sz):
            self.node[i + self.n - 1] = v[i]
        for i in range(self.n - 2, -1, -1):
            self.node[i] = self.node[i * 2 + 1] + self.node[i * 2 + 2]

    def eval(self, k, l, r):
        if self.lazy[k] != 0:
            self.node[k] += self.lazy[k]
            if r - l > 1:
                self.lazy[2 * k + 1] += self.lazy[k] // 2
                self.lazy[2 * k + 2] += self.lazy[k] // 2
            self.lazy[k] = 0

    def add(self, a, b, x, k=0, l=0, r=-1):
        if r < 0:
            r = self.n
        self.eval(k, l, r)
        if b <= l or r <= a:
            return
        if a <= l and r <= b:
            self.lazy[k] += (r - l) * x
            self.eval(k, l, r)
        else:
            self.add(a, b, x, 2 * k + 1, l, (l + r) // 2)
            self.add(a, b, x, 2 * k + 2, (l + r) // 2, r)
            self.node[k] = self.node[2 * k + 1] + self.node[2 * k + 2]

    def getsum(self, a, b, k=0, l=0, r=-1):
        if r < 0:
            r = self.n
        self.eval(k, l, r)
        if b <= l or r <= a:
            return 0
        if a <= l and r <= b:
            return self.node[k]
        vl = self.getsum(a, b, 2 * k + 1, l, (l + r) // 2)
        vr = self.getsum(a, b, 2 * k + 2, (l + r) // 2, r)
        return vl + vr

def digit_sum(v):
    ret = 0
    while v:
        ret += (v % 10)
        v //= 10
    return ret

class Graph:
    class Edge:
        def __init__(self, from_, to, cost):
            self.from_ = from_
            self.to = to
            self.cost = cost
            self.used = 0

        def __lt__(self, other):
            return self.cost < other.cost

    def __init__(self, n):
        self.n = n
        self.p = list(range(n))
        self.r = [1] * n
        self.edges = []

    def find(self, x):
        if x == self.p[x]:
            return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.r[x] < self.r[y]:
            x, y = y, x
        self.r[x] += self.r[y]
        self.p[y] = x

    def add_edge(self, u, v, c):
        self.edges.append(self.Edge(u, v, c))

    def build(self):
        self.edges.sort()
        self.init(self.n)
        res = 0
        for e in self.edges:
            if not self.same(e.from_, e.to):
                res += e.cost
                self.unite(e.from_, e.to)
                e.used = 1
        return res

    def build_k(self, k):
        self.edges.sort()
        self.init(self.n)
        res = 0
        cnt = 0
        for e in self.edges:
            if not self.same(e.from_, e.to):
                res += e.cost
                self.unite(e.from_, e.to)
                e.used = 1
                cnt += 1
            if cnt == k:
                break
        return res

def LIS(a):
    n = len(a)
    A = [float('inf')] * n
    for i in range(n):
        A[lower_bound(A, a[i])] = a[i]
    return A.index(float('inf'))

def lower_bound(arr, x):
    l, r = 0, len(arr)
    while l < r:
        m = (l + r) // 2
        if arr[m] < x:
            l = m + 1
        else:
            r = m
    return l

maze = [[0] * 100 for _ in range(100)]

def id2(H, W, sx, sy, gx, gy):
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    dist = [[-1] * W for _ in range(H)]
    dist[sy][sx] = 0

    q = deque()
    q.append((sy, sx))
    while q:
        y, x = q.popleft()
        if y == gy and x == gx:
            break
        for t in range(4):
            nx, ny = x + dx[t], y + dy[t]
            if nx < 0 or ny < 0 or nx >= W or ny >= H or dist[ny][nx] != -1 or maze[ny][nx] == 1:
                continue
            dist[ny][nx] = dist[y][x] + 1
            q.append((ny, nx))

    return dist[gy][gx]

def id3(n, g, INF):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if g[i][k] == INF or g[k][j] == INF:
                    continue
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])
    return g

class Dijkstra:
    def __init__(self, n):
        self.n = n
        self.Edges = [[] for _ in range(n)]
        self.Dist = [0] * n
        self.Prev = [-1] * n
        self.PathNum = [0] * n

    def add_edge(self, a, b, c, directed=True):
        if directed:
            self.Edges[a].append((b, c))
        else:
            self.Edges[a].append((b, c))
            self.Edges[b].append((a, c))

    def build(self, start):
        queue = []
        self.Dist = [1e+18] * self.n
        self.Prev = [-1] * self.n
        self.Dist[start] = 0
        self.PathNum[start] = 1
        queue.append((0, start))

        while queue:
            p = min(queue)
            queue.remove(p)
            v = p[1]
            if self.Dist[v] < p[0]:
                continue

            for e in self.Edges[v]:
                if self.Dist[e[0]] > self.Dist[v] + e[1]:
                    self.Dist[e[0]] = self.Dist[v] + e[1]
                    queue.append((self.Dist[e[0]], e[0]))
                    self.Prev[e[0]] = v
                    self.PathNum[e[0]] = self.PathNum[v]
                elif self.Dist[e[0]] == self.Dist[v] + e[1]:
                    self.PathNum[e[0]] += self.PathNum[v]
                    self.PathNum[e[0]] %= MOD

    def dist(self, t):
        return self.Dist[t]

    def get_path(self, t):
        path = []
        while t != -1:
            path.append(t)
            t = self.Prev[t]
        path.reverse()
        return path

    def get_path_num(self, t):
        return self.PathNum[t]

class id1:
    def __init__(self, H, W):
        self.H = H
        self.W = W
        self.data = [[0] * (W + 1) for _ in range(H + 1)]

    def add(self, x, y, z):
        self.data[x + 1][y + 1] += z

    def build(self):
        for i in range(1, len(self.data)):
            for j in range(1, len(self.data[i])):
                self.data[i][j] += self.data[i][j - 1] + self.data[i - 1][j] - self.data[i - 1][j - 1]

    def print_data(self):
        for i in range(self.H + 1):
            print(" ".join(map(str, self.data[i])))

    def query(self, sx, sy, gx, gy):
        return (self.data[gy][gx] - self.data[sy - 1][gx] - self.data[gy][sx - 1] + self.data[sy - 1][sx - 1])

class LCA:
    def __init__(self, sz):
        self.n = sz
        self.h = 1
        while (1 << self.h) < sz:
            self.h += 1
        self.par = [[-1] * sz for _ in range(self.h)]
        self.v = [[] for _ in range(sz)]
        self.depth = [0] * sz
        self.dis = [0] * sz

    def add_edge(self, x, y, z):
        self.v[x].append((y, z))
        self.v[y].append((x, z))

    def dfs(self, x, p, d, di):
        self.par[0][x] = p
        self.depth[x] = d
        self.dis[x] = di
        for to in self.v[x]:
            if to[0] != p:
                self.dfs(to[0], x, d + 1, di + to[1])

    def build(self):
        self.dfs(0, -1, 0, 0)
        for i in range(self.h - 1):
            for j in range(self.n):
                if self.par[i][j] < 0:
                    self.par[i + 1][j] = -1
                else:
                    self.par[i + 1][j] = self.par[i][self.par[i][j]]

    def lca(self, u, v):
        if self.depth[u] > self.depth[v]:
            u, v = v, u
        for i in range(self.h):
            if (self.depth[v] - self.depth[u]) >> i & 1:
                v = self.par[i][v]
        if u == v:
            return u
        for i in range(self.h - 1, -1, -1):
            if self.par[i][u] != self.par[i][v]:
                u = self.par[i][u]
                v = self.par[i][v]
        return self.par[0][u]

    def dist(self, u, v):
        return self.dis[u] + self.dis[v] - 2 * self.dis[self.lca(u, v)]

def cnk(n, k):
    ret = 1
    for i in range(n - k + 1, n + 1):
        ret *= i
    for i in range(1, k + 1):
        ret //= i
    return ret

def solve():
    n, k = map(int, input().split())
    if k == 1:
        print(1)
        return
    a = [0] * 11
    a[2] = 1
    for i in range(3, 11):
        a[i] = (i - 1) * (a[i - 1] + a[i - 2])

    ans = 1
    for i in range(k):
        ans += cnk(n, k - i) * a[k - i]
    
    print(ans)

if __name__ == "__main__":
    import sys
    input = sys.stdin.readline
    solve()
