import queue

class Maxflow:
    def __init__(self, Maxn):
        self.Maxn = Maxn
        self.G = [[] for _ in range(Maxn)]
        self.dist = [-1] * Maxn
        self.seen = [0] * Maxn

    def Clear(self):
        for i in range(self.Maxn):
            self.G[i].clear()

    def bfs(self, s):
        for i in range(self.Maxn):
            self.dist[i] = -1
        self.dist[s] = 0
        Q = queue.Queue()
        Q.put(s)
        while not Q.empty():
            x = Q.get()
            for i in range(len(self.G[x])):
                e = self.G[x][i]
                if e.cap and self.dist[e.to] == -1:
                    self.dist[e.to] = self.dist[x] + 1
                    Q.put(e.to)

    def dfs(self, now, dest, fl):
        if now == dest:
            return fl
        for i in range(self.seen[now], len(self.G[now])):
            ed = self.G[now][i]
            if ed.cap and self.dist[ed.to] == self.dist[now] + 1:
                f = self.dfs(ed.to, dest, min(fl, ed.cap))
                if f:
                    ed.cap -= f
                    self.G[ed.to][ed.rev].cap += f
                    return f
        return 0

    def dinic(self, s, t):
        ret = 0
        while True:
            self.seen = [0] * self.Maxn
            self.bfs(s)
            if self.dist[t] == -1:
                return ret
            f = self.dfs(s, t, float('inf'))
            while f:
                ret += f
                f = self.dfs(s, t, float('inf'))

class Geometry:
    class iP:
        def __init__(self, x, y):
            self.x = x
            self.y = y

        def __add__(self, p):
            return self.__class__(self.x + p.x, self.y + p.y)

        def __sub__(self, p):
            return self.__class__(self.x - p.x, self.y - p.y)

        def __mul__(self, k):
            return self.__class__(self.x * k, self.y * k)

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
            return self.__class__(self.x + p.x, self.y + p.y)

        def __sub__(self, p):
            return self.__class__(self.x - p.x, self.y - p.y)

        def __mul__(self, k):
            return self.__class__(self.x * k, self.y * k)

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

    def convex_hull(self, X, l):
        ret = []
        X.sort()
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

class Mymath:
    def qp(self, x, p, mod):
        ans = 1
        while p:
            if p & 1:
                ans = ans * x % mod
            x = x * x % mod
            p >>= 1
        return ans

    def inv(self, x, mod):
        return self.qp(x, mod - 2, mod)

    def C(self, N, K, fact, mod):
        return fact[N] * self.inv(fact[K], mod) % mod * self.inv(fact[N - K], mod) % mod

    def gcd(self, A, B):
        if B == 0:
            return A
        return self.gcd(B, A % B)

    def lcm(self, A, B):
        return A * B // self.gcd(A, B)

class fwt:
    def __init__(self, Mymath):
        self.Mymath = Mymath

    def FWT(self, a, n, mod):
        for d in range(1, n, d << 1):
            for i in range(0, n, d << 1):
                for j in range(d):
                    x, y = a[i + j], a[i + j + d]
                    a[i + j] = (x + y) % mod
                    a[i + j + d] = (x - y + mod) % mod

    def UFWT(self, a, n, mod):
        rev = self.Mymath.inv(2, mod)
        for d in range(1, n, d << 1):
            for i in range(0, n, d << 1):
                for j in range(d):
                    x, y = a[i + j], a[i + j + d]
                    a[i + j] = 1LL * (x + y) * rev % mod
                    a[i + j + d] = (1LL * (x - y) * rev % mod + mod) % mod

    def solve(self, a, b, n, mod):
        self.FWT(a, n, mod)
        self.FWT(b, n, mod)
        for i in range(n):
            a[i] = 1LL * a[i] * b[i] % mod
        self.UFWT(a, n, mod)

class mat:
    def __init__(self):
        self.dist = [[1e18] * 77 for _ in range(77)]

class Solution:
    def __init__(self):
        self.Maxn = 9
        self.x = 0
        self.k = 0
        self.n = 0
        self.q = 0
        self.tl = 0
        self.T1 = mat()
        self.cc = 0
        self.c = [0] * self.Maxn
        self.id = [0] * 256
        self.p = [0] * 30
        self.wp = [0] * 30
        self.dp = [0] * 77
        self.dp2 = [0] * 77

    def _init(self):
        self.cc = 0
        for i in range(1 << self.k):
            cnt = 0
            for j in range(self.k):
                if i >> j & 1:
                    cnt += 1
            if cnt != self.x:
                continue
            self.id[i] = self.cc
            self.cc += 1
        for i in range(1 << self.k):
            cnt = 0
            for j in range(self.k):
                if i >> j & 1:
                    cnt += 1
            if cnt != self.x:
                continue
            v = i >> 1
            u = i & 1
            if not u:
                self.T1.dist[self.id[i]][self.id[v]] = 0
            else:
                for j in range(1 << self.k):
                    if not self.id[l]:
                        continue
                    if l >> pp & 1:
                        self.T1.dist[self.id[i]][self.id[l]] = self.c[j + 1]
        return

    def Build(self, pos):
        ret = self.T1
        for i in range(1 << self.k):
            if not self.id[i]:
                continue
            for j in range(1, self.q + 1):
                if self.p[j] <= pos and pos - self.p[j] < self.k:
                    pp = pos - self.p[j]
                    pp = self.k - 1 - pp
                    if i >> (pp + 1) & 1:
                        continue
                    for l in range(1 << self.k):
                        if not self.id[l]:
                            continue
                        if l >> pp & 1:
                            if ret.dist[self.id[i]][self.id[l]] != 1e18:
                                ret.dist[self.id[i]][self.id[l]] += self.wp[j]
        return ret

    def mul(self, x, y):
        ret = mat()
        for i in range(1, self.cc + 1):
            for j in range(1, self.cc + 1):
                for k in range(1, self.cc + 1):
                    ret.dist[i][j] = min(ret.dist[i][j], x.dist[i][k] + y.dist[k][j])
        return ret

    def Mul(self, X):
        for i in range(1, self.cc + 1):
            self.dp2[i] = 1e18
        for i in range(1, self.cc + 1):
            for j in range(1, self.cc + 1):
                self.dp2[j] = min(self.dp2[j], self.dp[i] + X.dist[i][j])
        for i in range(1, self.cc + 1):
            self.dp[i] = self.dp2[i]

    def mqp(self, x, p):
        R = mat()
        for i in range(1, self.cc + 1):
            R.dist[i][i] = 0
        while p:
            if p & 1:
                R = self.mul(R, x)
            x = self.mul(x, x)
            p >>= 1
        return R

    def normal(self, pos):
        for i in range(1, self.q + 1):
            if self.p[i] <= pos and pos - self.p[i] < self.k:
                return False
        return True

    def solve(self):
        self.x = int(input())
        self.k = int(input())
        self.n = int(input())
        self.q = int(input())
        self.n += self.k - self.x
        self.c = list(map(int, input().split()))
        self._init()
        self.p = list(map(int, input().split()))
        self.wp = list(map(int, input().split()))
        for i in range(1, self.cc + 1):
            self.dp[i] = 1e18
        self.dp[self.id[(1 << self.x) - 1]] = 0
        now = self.k
        while now < self.n:
            if not self.normal(now + 1):
                Tra = self.Build(now + 1)
                self.Mul(Tra)
                now += 1
                continue
            Nxt = self.n + 1
            for i in range(1, self.q + 1):
                if self.p[i] > now:
                    Nxt = min(Nxt, self.p[i])
            di = Nxt - now - 1
            Tra = self.mqp(self.T1, di)
            self.Mul(Tra)
            now = Nxt - 1
        print(self.dp[self.id[(1 << self.x) - 1]])
        return

if __name__ == "__main__":
    solution = Solution()
    solution.solve()
