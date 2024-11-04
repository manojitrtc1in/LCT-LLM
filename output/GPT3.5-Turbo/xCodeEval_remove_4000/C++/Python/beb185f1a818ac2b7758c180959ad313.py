import math
import heapq

MOD = 1000000007
INF = float('inf')

def id0(G, v, t, f, used):
    if v == t:
        return f
    used[v] = True
    for i in range(len(G[v])):
        e = G[v][i]
        if not used[e[0]] and e[1] > 0:
            d = id0(G, e[0], t, min(f, e[1]), used)
            if d > 0:
                e[1] -= d
                G[e[0]][e[2]][1] += d
                return d
    return 0

def max_flow(G, s, t):
    flow = 0
    while True:
        used = [False] * len(G)
        f = id0(G, s, t, INF, used)
        if f == 0:
            return flow
        flow += f

def id2(G, s, d, negative):
    d = [INF] * len(G)
    negative = [False] * len(G)
    d[s] = 0
    for k in range(len(G) - 1):
        for i in range(len(G)):
            for j in range(len(G[i])):
                if d[i] != INF and d[G[i][j][0]] > d[i] + G[i][j][1]:
                    d[G[i][j][0]] = d[i] + G[i][j][1]
    for k in range(len(G) - 1):
        for i in range(len(G)):
            for j in range(len(G[i])):
                if d[i] != INF and d[G[i][j][0]] > d[i] + G[i][j][1]:
                    d[G[i][j][0]] = d[i] + G[i][j][1]
                    negative[G[i][j][0]] = True
                if negative[i] == True:
                    negative[G[i][j][0]] = True

def Dijkstra(G, s, d):
    d = [INF] * len(G)
    d[s] = 0
    q = [(0, s)]
    while q:
        a = heapq.heappop(q)
        if d[a[1]] < a[0]:
            continue
        for i in range(len(G[a[1]])):
            e = G[a[1]][i]
            if d[e[0]] > d[a[1]] + e[1]:
                d[e[0]] = d[a[1]] + e[1]
                heapq.heappush(q, (d[e[0]], e[0]))

def id4(G, d):
    d = [[INF] * len(G) for _ in range(len(G))]
    for i in range(len(G)):
        for j in range(len(G[i])):
            d[i][G[i][j][0]] = G[i][j][1]
    for i in range(len(G)):
        for j in range(len(G)):
            for k in range(len(G)):
                if d[j][i] != INF and d[i][k] != INF:
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k])

def tsort(graph, order):
    n = len(graph)
    k = 0
    in_degree = [0] * n
    for es in graph:
        for e in es:
            in_degree[e[0]] += 1
    que = []
    for i in range(n):
        if in_degree[i] == 0:
            heapq.heappush(que, i)
    while que:
        v = heapq.heappop(que)
        order.append(v)
        for e in graph[v]:
            in_degree[e[0]] -= 1
            if in_degree[e[0]] == 0:
                heapq.heappush(que, e[0])
    if len(order) != n:
        return False
    else:
        return True

class Lca:
    def __init__(self, g, root):
        self.n = len(g)
        self.log2_n = int(math.log2(self.n) + 1)
        self.parent = [[-1] * self.n for _ in range(self.log2_n)]
        self.depth = [0] * self.n
        self.dfs(g, root, -1, 0)
        for k in range(1, self.log2_n):
            for v in range(self.n):
                if self.parent[k - 1][v] < 0:
                    self.parent[k][v] = -1
                else:
                    self.parent[k][v] = self.parent[k - 1][self.parent[k - 1][v]]
    
    def dfs(self, g, v, p, d):
        self.parent[0][v] = p
        self.depth[v] = d
        for e in g[v]:
            if e[0] != p:
                self.dfs(g, e[0], v, d + 1)
    
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
        self.n = size
    
    def merge(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x != y:
            if self.data[y] < self.data[x]:
                x, y = y, x
            self.data[x] += self.data[y]
            self.data[y] = x
        self.n -= (x != y)
        return x != y
    
    def same(self, x, y):
        return self.root(x) == self.root(y)
    
    def root(self, x):
        if self.data[x] < 0:
            return x
        else:
            self.data[x] = self.root(self.data[x])
            return self.data[x]
    
    def size(self, x):
        return -self.data[self.root(x)]
    
    def num(self):
        return self.n

class SegmentTree:
    def __init__(self, f, id, v):
        self.merge = f
        self.identity = id
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
            if l & 1 == 0:
                left = self.merge(left, self.dat[l])
            if r & 1 == 0:
                right = self.merge(self.dat[r - 1], right)
            l = l // 2
            r = (r - 1) // 2
        return self.merge(left, right)

class id3:
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
        k += 1
        while k <= self.n:
            self.data[k] += x
            k += k & -k
    
    def lower_bound(self, w):
        if w <= 0:
            return -1
        x = 0
        k = self.p // 2
        while k > 0:
            if x + k <= self.n and self.data[x + k] < w:
                w -= self.data[x + k]
                x += k
            k //= 2
        return x

def divisor(n):
    ret = []
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()
    return ret

def id5(n):
    ret = []
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            ret.append((i, 0))
            while n % i == 0:
                n //= i
                ret[-1][1] += 1
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
    def __init__(self, n, mod):
        self.mod = mod
        self.fact = [0] * n
        self.fact_inv = [0] * n
        self.fact[0] = 1
        for i in range(1, n):
            self.fact[i] = self.fact[i - 1] * i % mod
        self.fact_inv[n - 1] = mod_inv(self.fact[n - 1], mod)
        for i in range(n - 2, -1, -1):
            self.fact_inv[i] = self.fact_inv[i + 1] * (i + 1) % mod
    
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
            ret *= self.nCr(_n, _r)
            ret %= self.mod
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

def id1(a, b, x, y):
    if a < b:
        return id1(b, a, y, x)
    if b > 0:
        g = id1(b, a % b, y, x)
        y -= (a // b) * x
        return g
    else:
        x = 1
        y = 0
        return a

m = int(input())
h1, a1, x1, y1 = map(int, input().split())
t = [h1]
used = [False] * m
used[h1] = True
while True:
    tmp = (t[-1] * x1 + y1) % m
    t.append(tmp)
    if used[tmp]:
        break
    used[tmp] = True
used = [False] * m
h2, a2, x2, y2 = map(int, input().split())
used[h2] = True
s = [h2]
while True:
    tmp = (s[-1] * x2 + y2) % m
    s.append(tmp)
    if used[tmp]:
        break
    used[tmp] = True

l1, l2 = -1, -1
mn1, mn2 = INF, INF
now = 0
while True:
    if t[-1] == t[now]:
        l1 = len(t) - now - 1
    if t[now] == a1:
        mn1 = now
        break
    now += 1
    if now == len(t):
        break
now = 0
while True:
    if s[-1] == s[now]:
        l2 = len(s) - now - 1
    if s[now] == a2:
        mn2 = now
        break
    now += 1
    if now == len(s):
        break

def calc():
    if mn1 != INF and mn2 != INF:
        if mn1 == mn2:
            return mn1
        if mn1 > mn2 and l2 == -1:
            return -1
        if mn1 < mn2 and l1 == -1:
            return -1
        if l1 == -1:
            if (mn1 - mn2) % l2 == 0:
                return mn1
            else:
                return -1
        if l2 == -1:
            if (mn2 - mn1) % l1 == 0:
                return mn2
            else:
                return -1
        if l1 == l2:
            if abs(mn1 - mn2) % l1 == 0:
                return max(mn1, mn2)
            else:
                return -1
        if mn2 > mn1 and (mn2 - mn1) % l1 == 0:
            return mn2
        if mn1 > mn2 and (mn1 - mn2) % l2 == 0:
            return mn1
        if abs(mn2 - mn1) % math.gcd(l1, l2) != 0:
            return -1
        x, y = id1(l1, l2, 0, 0)
        x *= (mn2 - mn1) // math.gcd(l1, l2)
        y *= (mn2 - mn1) // math.gcd(l1, l2)
        mn = INF
        while x * l1 + mn1 < max(mn1, mn2):
            x += l2 // math.gcd(l1, l2)
        mn = x * l1 + mn1
        while True:
            x -= l2 // math.gcd(l1, l2)
            if x * l1 + mn1 >= max(mn1, mn2):
                mn = min(mn, x * l1 + mn1)
            else:
                break
        return mn
    else:
        return -1

print(calc())
