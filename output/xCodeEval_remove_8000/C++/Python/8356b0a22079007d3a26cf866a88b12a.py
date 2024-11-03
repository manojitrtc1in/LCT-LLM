import queue

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
        for d in range(1, n, d << 1):
            for i in range(0, n, d << 1):
                for j in range(d):
                    x = a[i + j]
                    y = a[i + j + d]
                    a[i + j] = (x + y) % mod
                    a[i + j + d] = (x - y + mod) % mod
    
    @staticmethod
    def UFWT(a, n, mod):
        rev = Mymath.inv(2, mod)
        for d in range(1, n, d << 1):
            for i in range(0, n, d << 1):
                for j in range(d):
                    x = a[i + j]
                    y = a[i + j + d]
                    a[i + j] = (x + y) * rev % mod
                    a[i + j + d] = ((x - y) * rev % mod + mod) % mod
    
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
        def __init__(self, to, rev, cap):
            self.to = to
            self.rev = rev
            self.cap = cap
    
    src = 1002
    snk = 1003
    G = [[] for _ in range(Maxn)]
    dist = [0] * Maxn
    seen = [0] * Maxn
    n = 0
    
    @staticmethod
    def Clear():
        for i in range(Maxn):
            Maxflow.G[i].clear()
    
    @staticmethod
    def bfs(s):
        for i in range(Maxn):
            Maxflow.dist[i] = -1
        Maxflow.dist[s] = 0
        Q = queue.Queue()
        Q.put(s)
        while not Q.empty():
            x = Q.get()
            for i in range(len(Maxflow.G[x])):
                e = Maxflow.G[x][i]
                if e.cap and Maxflow.dist[e.to] == -1:
                    Maxflow.dist[e.to] = Maxflow.dist[x] + 1
                    Q.put(e.to)
    
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
            Maxflow.seen = [0] * Maxn
            Maxflow.bfs(s)
            if Maxflow.dist[t] == -1:
                return ret
            f = Maxflow.dfs(s, t, INF)
            while f:
                ret += f
                f = Maxflow.dfs(s, t, INF)
        return ret

class Geometry:
    class iP:
        def __init__(self, x, y):
            self.x = x
            self.y = y
        
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
            if self.x != p.x:
                return self.x < p.x
            return self.y < p.y
    
    class dP:
        def __init__(self, x, y):
            self.x = x
            self.y = y
        
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
            if self.x != p.x:
                return self.x < p.x
            return self.y < p.y
    
    @staticmethod
    def id0(X, l):
        ret = []
        X.sort(key=lambda p: (p.x, p.y))
        ret.append(X[0])
        for i in range(1, l):
            while len(ret) >= 2 and (ret[-2] - X[i]).det(ret[-1] - X[i]) >= 0:
                ret.pop()
            ret.append(X[i])
        rs = len(ret) + 1
        for i in range(l - 2, -1, -1):
            while len(ret) >= rs and (ret[-2] - X[i]).det(ret[-1] - X[i]) >= 0:
                ret.pop()
            ret.append(X[i])
        return ret

Maxn = 9
x, k, n, q = map(int, input().split())
tl = 0

class mat:
    def __init__(self):
        self.dist = [[1e18] * 77 for _ in range(77)]

c = [0] * Maxn
T1 = mat()
cc = 0
id = [0] * 256

def _init():
    global cc
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

p = [0] * 30
wp = [0] * 30
dp = [0] * 77
dp2 = [0] * 77

def Build(pos):
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
                        if ret.dist[id[i]][id[l]] != 1e18:
                            ret.dist[id[i]][id[l]] += wp[j]
    return ret

def Mul(X):
    global dp
    for i in range(1, cc + 1):
        dp2[i] = 1e18
    for i in range(1, cc + 1):
        for j in range(1, cc + 1):
            dp2[j] = min(dp2[j], dp[i] + X.dist[i][j])
    for i in range(1, cc + 1):
        dp[i] = dp2[i]

def mul(x, y):
    ret = mat()
    for i in range(1, cc + 1):
        for j in range(1, cc + 1):
            for k in range(1, cc + 1):
                ret.dist[i][j] = min(ret.dist[i][j], x.dist[i][k] + y.dist[k][j])
    return ret

def mqp(x, p):
    R = mat()
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

x, k, n, q = map(int, input().split())
tl = 0

c = list(map(int, input().split()))

_init()

p = [0] * 30
wp = [0] * 30
dp = [1e18] * 77
dp[id[(1 << x) - 1]] = 0

now = k
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
