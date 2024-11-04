import sys
from collections import deque
import heapq
from itertools import accumulate
from math import log2, inf, gcd, isqrt
from functools import reduce

MOD = 1000000007
INF = 1 << 62
EPS = 1e-10

def chmin(a, b):
    if a > b:
        a = b
        return True
    return False

def chmax(a, b):
    if a < b:
        a = b
        return True
    return False

class Edge:
    def __init__(self, to, cap, rev):
        self.to = to
        self.cap = cap
        self.rev = rev

def add_edge(G, from_, to, cap, revFlag, revCap):
    G[from_].append(Edge(to, cap, len(G[to]) + (from_ == to)))
    if revFlag:
        G[to].append(Edge(from_, revCap, len(G[from_]) - 1))

def max_flow_dfs(G, v, t, f, used):
    if v == t:
        return f
    used[v] = True
    for i in range(len(G[v])):
        e = G[v][i]
        if not used[e.to] and e.cap > 0:
            d = max_flow_dfs(G, e.to, t, min(f, e.cap), used)
            if d > 0:
                e.cap -= d
                G[e.to][e.rev].cap += d
                return d
    return 0

def max_flow(G, s, t):
    flow = 0
    while True:
        used = [False] * len(G)
        f = max_flow_dfs(G, s, t, INF, used)
        if f == 0:
            return flow
        flow += f

def bellman_ford(G, s):
    d = [INF] * len(G)
    negative = [False] * len(G)
    d[s] = 0
    for k in range(len(G) - 1):
        for i in range(len(G)):
            for j in range(len(G[i])):
                if d[i] != INF and d[G[i][j].to] > d[i] + G[i][j].cap:
                    d[G[i][j].to] = d[i] + G[i][j].cap
    for k in range(len(G) - 1):
        for i in range(len(G)):
            for j in range(len(G[i])):
                if d[i] != INF and d[G[i][j].to] > d[i] + G[i][j].cap:
                    d[G[i][j].to] = d[i] + G[i][j].cap
                    negative[G[i][j].to] = True
                if negative[i]:
                    negative[G[i][j].to] = True
    return d, negative

def dijkstra(G, s):
    d = [INF] * len(G)
    d[s] = 0
    q = []
    heapq.heappush(q, (0, s))
    while q:
        a = heapq.heappop(q)
        if d[a[1]] < a[0]:
            continue
        for i in range(len(G[a[1]])):
            e = G[a[1]][i]
            if d[e.to] > d[a[1]] + e.cap:
                d[e.to] = d[a[1]] + e.cap
                heapq.heappush(q, (d[e.to], e.to))

def warshall_floyd(G):
    d = [[INF] * len(G) for _ in range(len(G))]
    for i in range(len(G)):
        for j in range(len(G)):
            d[i][j] = 0 if i == j else INF
    for i in range(len(G)):
        for j in range(len(G[i])):
            chmin(d[i][G[i][j].to], G[i][j].cap)
    for i in range(len(G)):
        for j in range(len(G)):
            for k in range(len(G)):
                chmin(d[j][k], d[j][i] + d[i][k])
    return d

def tsort(graph):
    n = len(graph)
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
    return order if len(order) == n else None

class Lca:
    def __init__(self, g, root):
        self.n = len(g)
        self.log2_n = int(log2(self.n)) + 1
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

class FenwickTree:
    def __init__(self, n):
        self.data = [0] * (n + 1)
        self.n = n
        self.p = 1
        while self.p < len(self.data):
            self.p *= 2

    def sum(self, k):
        ret = 0
        while k > 0:
            ret += self.data[k]
            k -= k & -k
        return ret

    def add(self, k, x):
        for k in range(k + 1, self.n + 1, k & -k):
            self.data[k] += x

    def lower_bound(self, w):
        if w <= 0:
            return -1
        x = 0
        for k in self.p // 2:
            if x + k <= self.n and self.data[x + k] < w:
                w -= self.data[x + k]
                x += k
        return x

def divisor(n):
    ret = []
    for i in range(1, isqrt(n) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()
    return ret

def prime_factorization(n):
    ret = []
    for i in range(2, isqrt(n) + 1):
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
        self.mod = _mod
        n = min(_n + 1, self.mod)
        self.fact = [1] * n
        for i in range(1, n):
            self.fact[i] = self.fact[i - 1] * i % self.mod
        self.fact_inv = [1] * n
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
        return self.fact[n] * self.fact_inv[n - r] % self.mod

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

class LazySegmentTree:
    def __init__(self, v, id_t, id_e, f_tt, f_te, f_ee, f_ep):
        self.identity_t = id_t
        self.identity_e = id_e
        self.f_tt = f_tt
        self.f_te = f_te
        self.f_ee = f_ee
        self.f_ep = f_ep
        self.n = 1
        while self.n < len(v):
            self.n *= 2
        self.dat = [self.identity_t] * (2 * self.n - 1)
        self.lazy = [self.identity_e] * (2 * self.n - 1)
        for i in range(len(v)):
            self.dat[self.n + i - 1] = v[i]
        for i in range(self.n - 2, -1, -1):
            self.dat[i] = self.f_tt(self.dat[i * 2 + 1], self.dat[i * 2 + 2])

    def eval(self, k, length):
        if self.lazy[k] == self.identity_e:
            return
        if k < self.n - 1:
            self.lazy[2 * k + 1] = self.f_ee(self.lazy[2 * k + 1], self.lazy[k])
            self.lazy[2 * k + 2] = self.f_ee(self.lazy[2 * k + 2], self.lazy[k])
        self.dat[k] = self.f_te(self.dat[k], self.f_ep(self.lazy[k], length))
        self.lazy[k] = self.identity_e

    def update(self, a, b, x, k=0, l=0, r=None):
        if r is None:
            r = self.n
        self.eval(k, r - l)
        if a <= l and r <= b:
            self.lazy[k] = self.f_ee(self.lazy[k], x)
            self.eval(k, r - l)
        elif a < r and l < b:
            self.update(a, b, x, 2 * k + 1, l, (l + r) // 2)
            self.update(a, b, x, 2 * k + 2, (l + r) // 2, r)
            self.dat[k] = self.f_tt(self.dat[2 * k + 1], self.dat[2 * k + 2])

    def query(self, a, b, k=0, l=0, r=None):
        if r is None:
            r = self.n
        self.eval(k, r - l)
        if r <= a or b <= l:
            return self.identity_t
        elif a <= l and r <= b:
            return self.dat[k]
        else:
            vl = self.query(a, b, 2 * k + 1, l, (l + r) // 2)
            vr = self.query(a, b, 2 * k + 2, (l + r) // 2, r)
            return self.f_tt(vl, vr)

def mIdentity(n):
    return [[1 if i == j else 0 for j in range(n)] for i in range(n)]

def mMul(A, B, M):
    C = [[0] * len(B[0]) for _ in range(len(A))]
    for i in range(len(C)):
        for k in range(len(A[i])):
            for j in range(len(C[i])):
                C[i][j] = (C[i][j] + (A[i][k] % M) * (B[k][j] % M)) % M) % M
    return C

def mPow(A, e, M):
    return mIdentity(len(A)) if e == 0 else mMul(mPow(mMul(A, A, M), e // 2, M), A, M) if e % 2 == 0 else mMul(A, mPow(A, e - 1, M), M)

class NTT:
    def __init__(self, mod, root):
        self.mod = mod
        self.root = root

    def bit_reverse(self, a):
        n = len(a)
        i = 0
        for j in range(1, n - 1):
            for k in range(n >> 1, (i := i ^ k)):
                pass
            if j < i:
                a[i], a[j] = a[j], a[i]

    def _ntt(self, a, sign):
        n = len(a)
        assert (n ^ (n & -n)) == 0

        tmp = (self.mod - 1) * mod_pow(n, self.mod - 2, self.mod) % self.mod
        h = mod_pow(self.root, tmp, self.mod)

        if sign == -1:
            h = mod_pow(h, self.mod - 2, self.mod)

        self.bit_reverse(a)

        for m in range(1, n, m << 1):
            m2 = 2 * m
            base = mod_pow(h, n // m2, self.mod)
            w = 1
            for x in range(m):
                for s in range(x, n, m2):
                    u = a[s]
                    d = (a[s + m] * w) % self.mod
                    a[s] = (u + d) % self.mod
                    a[s + m] = (u - d + self.mod) % self.mod
                w = (w * base) % self.mod

    def ntt(self, input):
        self._ntt(input, 1)

    def intt(self, input):
        self._ntt(input, -1)
        n_inv = mod_pow(len(input), self.mod - 2, self.mod)
        for x in input:
            x = (x * n_inv) % self.mod

    def convolution(self, a, b):
        result_size = len(a) + len(b) - 1
        n = 1
        while n < result_size:
            n <<= 1

        _a = a + [0] * (n - len(a))
        _b = b + [0] * (n - len(b))

        self.ntt(_a)
        self.ntt(_b)
        for i in range(n):
            _a[i] = (_a[i] * _b[i]) % self.mod

        self.intt(_a)

        return _a[:result_size]

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0

    n = int(data[idx])
    k = int(data[idx + 1])
    idx += 2

    a = [[] for _ in range(n)]
    for i in range(n):
        t = int(data[idx])
        idx += 1
        for j in range(t):
            tmp = int(data[idx])
            if len(a[i]) < k:
                a[i].append(tmp)
            idx += 1

    w = [sum(a[i]) for i in range(n)]
    ans = 0

    def solve(solve, dp, l, r):
        nonlocal ans
        if r - l == 1:
            sum_ = 0
            for i in range(len(a[l]) + 1):
                chmax(ans, dp[k - i] + sum_)
                if i != len(a[l]):
                    sum_ += a[l][i]
            return
        m = (r + l) // 2
        dp2 = dp[:]
        for i in range(m, r):
            for j in range(k - 1, -1, -1):
                if len(a[i]) + j <= k:
                    chmax(dp2[j + len(a[i])], dp2[j] + w[i])
        solve(solve, dp2, l, m)
        for i in range(l, m):
            for j in range(k - 1, -1, -1):
                if len(a[i]) + j <= k:
                    chmax(dp[j + len(a[i])], dp[j] + w[i])
        solve(solve, dp, m, r)

    dp = [0] * (k + 1)
    solve(solve, dp, 0, n)
    print(ans)

if __name__ == "__main__":
    main()
