from collections import defaultdict
import sys
import heapq

input = sys.stdin.read
def chmin(a, b):
    if a > b:
        return b
    return a

def chmax(a, b):
    if a < b:
        return b
    return a

class Edge:
    def __init__(self, to, cap, rev):
        self.to = to
        self.cap = cap
        self.rev = rev

def add_edge(G, from_, to, cap, revFlag, revCap):
    G[from_].append(Edge(to, cap, len(G[to]) + (from_ == to)))
    if revFlag:
        G[to].append(Edge(from_, revCap, len(G[from_]) - 1))

def id1(G, v, t, f, used):
    if v == t:
        return f
    used[v] = True
    for e in G[v]:
        if not used[e.to] and e.cap > 0:
            d = id1(G, e.to, t, min(f, e.cap), used)
            if d > 0:
                e.cap -= d
                G[e.to][e.rev].cap += d
                return d
    return 0

def max_flow(G, s, t):
    flow = 0
    while True:
        used = [False] * len(G)
        f = id1(G, s, t, float('inf'), used)
        if f == 0:
            return flow
        flow += f

def id5(G, s):
    d = [float('inf')] * len(G)
    negative = [False] * len(G)
    d[s] = 0
    for _ in range(len(G) - 1):
        for i in range(len(G)):
            for e in G[i]:
                if d[i] != float('inf') and d[e.to] > d[i] + e.cap:
                    d[e.to] = d[i] + e.cap
    for _ in range(len(G) - 1):
        for i in range(len(G)):
            for e in G[i]:
                if d[i] != float('inf') and d[e.to] > d[i] + e.cap:
                    d[e.to] = d[i] + e.cap
                    negative[e.to] = True
                if negative[i]:
                    negative[e.to] = True

def Dijkstra(G, s):
    d = [float('inf')] * len(G)
    d[s] = 0
    q = []
    heapq.heappush(q, (0, s))
    while q:
        a = heapq.heappop(q)
        if d[a[1]] < a[0]:
            continue
        for e in G[a[1]]:
            if d[e.to] > d[a[1]] + e.cap:
                d[e.to] = d[a[1]] + e.cap
                heapq.heappush(q, (d[e.to], e.to))

def id7(G):
    d = [[float('inf')] * len(G) for _ in range(len(G))]
    for i in range(len(G)):
        d[i][i] = 0
    for i in range(len(G)):
        for e in G[i]:
            chmin(d[i][e.to], e.cap)
    for j in range(len(G)):
        for k in range(len(G)):
            for i in range(len(G)):
                chmin(d[j][k], d[j][i] + d[i][k])

def tsort(graph):
    n = len(graph)
    k = 0
    order = []
    in_degree = [0] * n
    for es in graph:
        for e in es:
            in_degree[e.to] += 1
    que = []
    for i in range(n):
        if in_degree[i] == 0:
            heapq.heappush(que, i)
    while que:
        v = heapq.heappop(que)
        order.append(v)
        for e in graph[v]:
            if (in_degree[e.to] := in_degree[e.to] - 1) == 0:
                heapq.heappush(que, e.to)
    return len(order) == n, order

class Lca:
    def __init__(self, g, root):
        self.n = len(g)
        self.log2_n = (self.n).bit_length()
        self.parent = [[-1] * self.n for _ in range(self.log2_n)]
        self.depth = [0] * self.n
        self.dfs(g, root, -1, 0)
        for k in range(self.log2_n - 1):
            for v in range(self.n):
                if self.parent[k][v] < 0:
                    self.parent[k + 1][v] = -1
                else:
                    self.parent[k + 1][v] = self.parent[k][self.parent[k][v]]

    def dfs(self, g, v, p, d):
        self.parent[0][v] = p
        self.depth[v] = d
        for e in g[v]:
            if e.to != p:
                self.dfs(g, e.to, v, d + 1)

    def get(self, u, v):
        if self.depth[u] > self.depth[v]:
            u, v = v, u
        for k in range(self.log2_n):
            if (self.depth[v] - self.depth[u]) >> k & 1:
                v = self.parent[k][v]
        if u == v:
            return u
        for k in range(self.log2_n - 1, -1, -1):
            if self.parent[k][u] != self.parent[k][v]:
                u = self.parent[k][u]
                v = self.parent[k][v]
        return self.parent[0][u]

class UnionFind:
    def __init__(self, size):
        self.data = [-1] * size
        self._num = size

    def merge(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x != y:
            if self.data[y] < self.data[x]:
                x, y = y, x
            self.data[x] += self.data[y]
            self.data[y] = x
        self._num -= (x != y)
        return x != y

    def same(self, x, y):
        return self.root(x) == self.root(y)

    def root(self, x):
        if self.data[x] < 0:
            return x
        self.data[x] = self.root(self.data[x])
        return self.data[x]

    def size(self, x):
        return -self.data[self.root(x)]

    def num(self):
        return self._num

class SegmentTree:
    def __init__(self, f, id_, v):
        self.merge = f
        self.identity = id_
        self.n = 1
        while self.n < len(v):
            self.n *= 2
        self.dat = [self.identity] * (2 * self.n - 1)
        for i in range(len(v)):
            self.dat[self.n + i - 1] = v[i]
        for i in range(self.n - 2, -1, -1):
            self.dat[i] = self.merge(self.dat[i * 2 + 1], self.dat[i * 2 + 2])

    def set_val(self, i, x):
        i += self.n - 1
        self.dat[i] = x
        while i > 0:
            i = (i - 1) // 2
            self.dat[i] = self.merge(self.dat[i * 2 + 1], self.dat[i * 2 + 2])

    def query(self, l, r):
        left = self.identity
        right = self.identity
        l += self.n - 1
        r += self.n - 1
        while l < r:
            if (l & 1) == 0:
                left = self.merge(left, self.dat[l])
            if (r & 1) == 0:
                right = self.merge(self.dat[r - 1], right)
            l //= 2
            r = (r - 1) // 2
        return self.merge(left, right)

def divisor(n):
    ret = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()
    return ret

def id8(n):
    ret = []
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            ret.append((i, 0))
            while n % i == 0:
                n //= i
                ret[-1] = (ret[-1][0], ret[-1][1] + 1)
    if n != 1:
        ret.append((n, 1))
    return ret

def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res

def mod_inv(x, mod):
    return mod_pow(x, mod - 2, mod)

class Combination:
    def __init__(self, _n, _mod):
        self.fact = []
        self.fact_inv = []
        self.mod = _mod
        n = min(_n + 1, _mod)
        self.fact = [1] * n
        for i in range(1, n):
            self.fact[i] = (self.fact[i - 1] * (i + 1)) % self.mod
        self.fact_inv = [0] * n
        self.fact_inv[n - 1] = mod_inv(self.fact[n - 1], self.mod)
        for i in range(n - 1, 0, -1):
            self.fact_inv[i - 1] = self.fact_inv[i] * i % self.mod

    def nCr(self, n, r):
        if n < r:
            return 0
        if n < self.mod:
            return (self.fact[n] * self.fact_inv[r] % self.mod) * self.fact_inv[n - r] % self.mod
        ret = 1
        while n or r:
            _n = n % self.mod
            _r = r % self.mod
            n //= self.mod
            r //= self.mod
            ret = ret * self.nCr(_n, _r) % self.mod
        return ret

    def nPr(self, n, r):
        return (self.fact[n] * self.fact_inv[n - r]) % self.mod

    def nHr(self, n, r):
        return self.nCr(r + n - 1, r)

def popcount(x):
    x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555)
    x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333)
    x = (x & 0x0F0F0F0F0F0F0F0F) + (x >> 4 & 0x0F0F0F0F0F0F0F0F)
    x = (x & 0x00FF00FF00FF00FF) + (x >> 8 & 0x00FF00FF00FF00FF)
    x = (x & 0x0000FFFF0000FFFF) + (x >> 16 & 0x0000FFFF0000FFFF)
    x = (x & 0x00000000FFFFFFFF) + (x >> 32 & 0x00000000FFFFFFFF)
    return x

def rowReduction(mat, basis):
    for e in mat:
        for b in basis:
            chmin(e, e ^ b)
        if e:
            basis.append(e)
    basis.sort(reverse=True)

def main():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        a[i] -= 1
    sum_ = [[0] * (n + 1) for _ in range(100)]
    b = [[] for _ in range(100)]
    for i in range(n):
        sum_[a[i]][i + 1] += 1
        b[a[i]].append(i)
    for i in range(100):
        for j in range(n):
            sum_[i][j + 1] += sum_[i][j]
    
    def find():
        mx = 0
        ret = -1
        for i in range(100):
            if chmax(mx, sum_[i][n]):
                ret = i
        return ret

    i = find()
    ans = 0
    mp = [-1] * 404040

    for j in range(100):
        if i == j:
            continue
        if not b[i] or not b[j]:
            continue
        x = 0
        y = 0
        now = 202020
        mp[202020] = 0
        era = []
        while True:
            def nex(x, y):
                if x != len(b[i]) and y != len(b[j]):
                    if b[i][x] < b[j][y]:
                        return 1, b[i][x]
                    else:
                        return -1, b[j][y]
                elif x != len(b[i]):
                    return 1, b[i][x]
                elif y != len(b[j]):
                    return -1, b[j][y]
                else:
                    return -2, 0
            
            tmp = nex(x, y)
            if tmp[0] == -2:
                break
            if tmp[0] == 1:
                x += 1
            else:
                y += 1
            now += tmp[0]
            if mp[now] != -1:
                tmp = nex(x, y)
                if tmp[0] == -2:
                    chmax(ans, n - mp[now])
                else:
                    chmax(ans, tmp[1] - mp[now])
            else:
                mp[now] = tmp[1] + 1
                era.append(now)
        for e in era:
            mp[e] = -1
    print(ans)

if __name__ == "__main__":
    main()
