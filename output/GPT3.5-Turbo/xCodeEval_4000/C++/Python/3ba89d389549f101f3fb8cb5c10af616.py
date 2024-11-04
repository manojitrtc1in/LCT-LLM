MOD = 1000000007

def add_edge(G, from_, to, cap, revFlag, revCap):
    G[from_].append(Edge(to, cap, len(G[to])))
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

def BellmanFord(G, s, d, negative):
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
                if negative[i] == True:
                    negative[G[i][j].to] = True

def Dijkstra(G, s, d):
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

def WarshallFloyd(G, d):
    d = [[INF] * len(G) for _ in range(len(G))]
    for i in range(len(G)):
        for j in range(len(G[i])):
            d[i][G[i][j].to] = G[i][j].cap
    for i in range(len(G)):
        for j in range(len(G)):
            for k in range(len(G)):
                d[j][k] = min(d[j][k], d[j][i] + d[i][k])

def tsort(graph, order):
    n = len(graph)
    k = 0
    in_ = [0] * n
    for es in graph:
        for e in es:
            in_[e.to] += 1
    que = []
    for i in range(n):
        if in_[i] == 0:
            heapq.heappush(que, i)
    while que:
        v = heapq.heappop(que)
        order.append(v)
        for e in graph[v]:
            in_[e.to] -= 1
            if in_[e.to] == 0:
                heapq.heappush(que, e.to)
    if len(order) != n:
        return False
    else:
        return True

class lca:
    def __init__(self, g, root):
        self.n = len(g)
        self.log2_n = (self.n - 1).bit_length()
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

def visit(g, v, scc, S, inS, low, num, time):
    low[v] = num[v] = time
    time += 1
    S.append(v)
    inS[v] = True
    for e in g[v]:
        w = e.to
        if num[w] == 0:
            visit(g, w, scc, S, inS, low, num, time)
            low[v] = min(low[v], low[w])
        elif inS[w]:
            low[v] = min(low[v], num[w])
    if low[v] == num[v]:
        scc.append([])
        while True:
            w = S.pop()
            inS[w] = False
            scc[-1].append(w)
            if v == w:
                break

def stronglyConnectedComponents(g, scc):
    n = len(g)
    num = [0] * n
    low = [0] * n
    inS = [False] * n
    S = []
    time = 1
    for u in range(n):
        if num[u] == 0:
            visit(g, u, scc, S, inS, low, num, time)

class UnionFind:
    def __init__(self, size):
        self.data = [-1] * size
        self.num = size
    
    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x != y:
            if self.data[y] < self.data[x]:
                x, y = y, x
            self.data[x] += self.data[y]
            self.data[y] = x
        self.num -= (x != y)
        return x != y
    
    def findSet(self, x, y):
        return self.root(x) == self.root(y)
    
    def root(self, x):
        if self.data[x] < 0:
            return x
        self.data[x] = self.root(self.data[x])
        return self.data[x]
    
    def size(self, x):
        return -self.data[self.root(x)]
    
    def numSet(self):
        return self.num

class SumSegTree:
    def __init__(self, n):
        self.n = 1
        self.height = 1
        while self.n < n:
            self.n *= 2
            self.height += 1
        self.dat = [0] * (2 * self.n - 1)
    
    def add(self, i, x):
        i += self.n - 1
        self.dat[i] += x
        while i > 0:
            i = (i - 1) // 2
            self.dat[i] += x
    
    def sum(self, a, b):
        return self._sum(a, b, 0, 0, self.n)
    
    def _sum(self, a, b, k, l, r):
        if r <= a or b <= l:
            return 0
        if a <= l and r <= b:
            return self.dat[k]
        else:
            s1 = self._sum(a, b, 2 * k + 1, l, (l + r) // 2)
            s2 = self._sum(a, b, 2 * k + 2, (l + r) // 2, r)
            return s1 + s2

class RmqTree:
    def __init__(self, n):
        self.n = 1
        self.height = 1
        while self.n < n:
            self.n *= 2
            self.height += 1
        self.dat = [INF] * (2 * self.n - 1)
    
    def update(self, i, x):
        i += self.n - 1
        self.dat[i] = x
        while i > 0:
            i = (i - 1) // 2
            self.dat[i] = min(self.dat[i * 2 + 1], self.dat[i * 2 + 2])
    
    def find(self, a, b):
        return self._find(a, b, 0, 0, self.n)
    
    def _find(self, a, b, k, l, r):
        if r <= a or b <= l:
            return INF
        if a <= l and r <= b:
            return self.dat[k]
        else:
            s1 = self._find(a, b, 2 * k + 1, l, (l + r) // 2)
            s2 = self._find(a, b, 2 * k + 2, (l + r) // 2, r)
            return min(s1, s2)

def divisor(n, ret):
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()

def lis_fast(a):
    n = len(a)
    A = [INF] * n
    id = [0] * n
    for i in range(n):
        id[i] = bisect_left(A, a[i])
        A[id[i]] = a[i]
    m = max(id)
    b = [0] * (m + 1)
    for i in range(n - 1, -1, -1):
        if id[i] == m:
            b[m] = a[i]
            m -= 1
    return b

def z_algorithm(s, z):
    L = len(s)
    z = [0] * len(s)
    for i in range(1, L):
        if i > r:
            l = r = i
            while r < L and s[r - l] == s[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:
            k = i - l
            if z[k] < r - i + 1:
                z[i] = z[k]
            else:
                l = i
                while r < L and s[r - l] == s[r]:
                    r += 1
                z[i] = r - l
                r -= 1
    return True

class RollingHash:
    def __init__(self, S):
        self.n = len(S)
        self.hash1 = [0] * (self.n + 1)
        self.hash2 = [0] * (self.n + 1)
        self.power1 = [1] * (self.n + 1)
        self.power2 = [1] * (self.n + 1)
        for i in range(self.n):
            self.hash1[i + 1] = (self.hash1[i] * base1 + ord(S[i])) % mod1
            self.hash2[i + 1] = (self.hash2[i] * base2 + ord(S[i])) % mod2
            self.power1[i + 1] = (self.power1[i] * base1) % mod1
            self.power2[i + 1] = (self.power2[i] * base2) % mod2
    
    def get(self, l, r):
        res1 = self.hash1[r] - self.hash1[l] * self.power1[r - l] % mod1
        if res1 < 0:
            res1 += mod1
        res2 = self.hash2[r] - self.hash2[l] * self.power2[r - l] % mod2
        if res2 < 0:
            res2 += mod2
        return (res1, res2)

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
        self.fact = [0] * (n + 1)
        self.inv = [0] * (n + 1)
        self.fact[0] = 1
        for i in range(n):
            self.fact[i + 1] = (self.fact[i] * (i + 1)) % mod
        self.inv[n] = mod_inv(self.fact[n], mod)
        for i in range(n, 0, -1):
            self.inv[i - 1] = (self.inv[i] * i) % mod
    
    def nCr(self, n, r):
        return ((self.fact[n] * self.inv[r] % self.mod) * self.inv[n - r]) % self.mod
    
    def nPr(self, n, r):
        return (self.fact[n] * self.inv[n - r]) % self.mod
    
    def nHr(self, n, r):
        return self.nCr(r + n - 1, r)

def gcd(m, n):
    if n == 0:
        return m
    return gcd(n, m % n)

def lcm(m, n):
    return m // gcd(m, n) * n

def mIdentity(n):
    A = [[0] * n for _ in range(n)]
    for i in range(n):
        A[i][i] = 1
    return A

def mMul(A, B):
    C = [[0] * len(B[0]) for _ in range(len(A))]
    for i in range(len(C)):
        for j in range(len(C[i])):
            for k in range(len(A[i])):
                C[i][j] += (A[i][k] % MOD) * (B[k][j] % MOD)
                C[i][j] %= MOD
    return C

def mPow(A, e):
    if e == 0:
        return mIdentity(len(A))
    elif e % 2 == 0:
        return mPow(mMul(A, A), e // 2)
    else:
        return mMul(A, mPow(A, e - 1))

class RectangleSum:
    def __init__(self, s, h, w):
        self.sum = [[0] * w for _ in range(h)]
        for y in range(h):
            for x in range(w):
                self.sum[y][x] = s[y][x]
                if y > 0:
                    self.sum[y][x] += self.sum[y - 1][x]
                if x > 0:
                    self.sum[y][x] += self.sum[y][x - 1]
                if y > 0 and x > 0:
                    self.sum[y][x] -= self.sum[y - 1][x - 1]
    
    def GetSum(self, left, right, top, bottom):
        res = self.sum[bottom][right]
        if left > 0:
            res -= self.sum[bottom][left - 1]
        if top > 0:
            res -= self.sum[top - 1][right]
        if left > 0 and top > 0:
            res += self.sum[top - 1][left - 1]
        return res

def _garner(xs, mods):
    M = len(xs)
    coeffs = [1] * M
    constants = [0] * M

    for i in range(M - 1):
        mod_i = mods[i]

        v = (xs[i] - constants[i] + mod_i) % mod_i
        v = (v * mod_pow(coeffs[i], mod_i - 2, mod_i)) % mod_i

        for j in range(i + 1, M):
            mod_j = mods[j]
            constants[j] = (constants[j] + coeffs[j] * v) % mod_j
            coeffs[j] = (coeffs[j] * mod_i) % mod_j

    return constants[-1]

def convolution_ntt(a, b, mod = 1224736769):
    for i in range(len(a)):
        a[i] %= mod
    for i in range(len(b)):
        b[i] %= mod

    maxval = max(len(a), len(b)) * max(max(a), max(b))
    if maxval < 1224736769:
        ntt3 = NTT(1224736769, 3)
        return ntt3.convolution(a, b)

    ntt1 = NTT(167772161, 3)
    ntt2 = NTT(469762049, 3)
    ntt3 = NTT(1224736769, 3)

    x1 = ntt1.convolution(a, b)
    x2 = ntt2.convolution(a, b)
    x3 = ntt3.convolution(a, b)

    ret = [0] * len(x1)
    mods = [167772161, 469762049, 1224736769, mod]
    for i in range(len(x1)):
        xs = [x1[i], x2[i], x3[i], 0]
        ret[i] = _garner(xs, mods)

    return ret

def popcount3(x):
    x = (x & 0x55555555) + (x >> 1 & 0x55555555)
    x = (x & 0x33333333) + (x >> 2 & 0x33333333)
    x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F)
    x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF)
    x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF)

    return x

def rowReduction(mat, basis):
    for e in mat:
        for b in basis:
            e = min(e, e ^ b)
        if e:
            basis.append(e)
    basis.sort(reverse=True)

class SegT:
    def __init__(self, sz):
        self.n = 1
        while self.n < sz:
            self.n <<= 1
        self.node = [0] * (2 * self.n - 1)
        self.lazy = [0] * (2 * self.n - 1)
    
    def f(self, a, b):
        return max(a, b)
    
    def eval(self, k, l, r):
        self.node[k] += self.lazy[k]
        if r - l > 1:
            self.lazy[2 * k + 1] += self.lazy[k]
            self.lazy[2 * k + 2] += self.lazy[k]
        self.lazy[k] = 0
    
    def add(self, x, a, b, k = 0, l = 0, r = -1):
        if r < 0:
            r = self.n
        self.eval(k, l, r)
        if r <= a or b <= l:
            return
        if a <= l and r <= b:
            self.lazy[k] += x
            self.eval(k, l, r)
        else:
            self.add(x, a, b, k * 2 + 1, l, (l + r) // 2)
            self.add(x, a, b, k * 2 + 2, (l + r) // 2, r)
            self.node[k] = self.f(self.node[k * 2 + 1], self.node[k * 2 + 2])
    
    def query(self, a, b, k = 0, l = 0, r = -1):
        if r < 0:
            r = self.n
        self.eval(k, l, r)
        if r <= a or b <= l:
            return 0
        if a <= l and r <= b:
            return self.node[k]
        else:
            vl = self.query(a, b, k * 2 + 1, l, (l + r) // 2)
            vr = self.query(a, b, k * 2 + 2, (l + r) // 2, r)
            return self.f(vl, vr)

def dfs(g, v, t, st, used, s):
    used[v] = 1
    if v != s:
        st.add(v)
    if v == t:
        return
    if v != s:
        for i in range(len(g[v])):
            to = g[v][i].to
            if used[to] == 0:
                dfs(g, to, t, st, used, s)
            elif used[to] == 2:
                st.add(t)
    else:
        for i in range(len(g[v])):
            to = g[v][i].to
            if used[to] != 0:
                continue
            dfs(g, to, t, st, used, s)
            if t in st:
                for itr in st:
                    used[itr] = 2
            st.clear()

def solve():
    n, m, a, b = map(int, input().split())
    a -= 1
    b -= 1
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        add_edge(g, u, v, 1, True, 1)
    used = [0] * n
    st = set()
    dfs(g, a, b, st, used, a)
    s = 0
    t = 0
    for i in range(n):
        if used[i] == 1:
            s += 1
        elif used[i] == 0:
            t += 1
    s -= 1
    print(s * t)

t = int(input())
for _ in range(t):
    solve()
