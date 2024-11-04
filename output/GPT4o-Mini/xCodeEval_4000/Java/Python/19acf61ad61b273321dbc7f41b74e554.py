import sys
import random
from collections import defaultdict, deque

class Main:
    def __init__(self):
        self.groups = 0
        self.fa = []
        self.sz = []
        self.h = []
        self.to = []
        self.ne = []
        self.m = 0
        self.w = []
        self.cc = 0
        self.a = []
        self.o = []
        self.clr = []
        self.qr = []
        self.qs = []
        self.rr = 100
        self.cao = []
        self.dp = [0] * 1000001

    def init1(self, n):
        self.groups = n
        self.fa = list(range(n))
        self.sz = [1] * n

    def root(self, p):
        while p != self.fa[p]:
            self.fa[p] = self.fa[self.fa[p]]
            p = self.fa[p]
        return p

    def combine(self, p, q):
        i = self.root(p)
        j = self.root(q)
        if i == j:
            return
        self.fa[i] = j
        if self.sz[i] < self.sz[j]:
            self.fa[i] = j
            self.sz[j] += self.sz[i]
        else:
            self.fa[j] = i
            self.sz[i] += self.sz[j]
        self.groups -= 1

    @staticmethod
    def roundS(result, scale):
        return f"{result:.{scale}f}"

    def unique(self, a):
        p = 1
        for i in range(1, len(a)):
            if a[i] != a[i - 1]:
                a[p] = a[i]
                p += 1
        return a[:p]

    @staticmethod
    def bigger(a, key):
        return Main.bigger_helper(a, 0, len(a), key)

    @staticmethod
    def bigger_helper(a, lo, hi, key):
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] > key:
                hi = mid
            else:
                lo = mid + 1
        return lo

    def addEdge(self, u, v, w):
        self.to.append(v)
        self.ne.append(self.h[u])
        self.h[u] = self.m
        self.m += 1

    def add(self, u, v, ww):
        self.to.append(u)
        self.w.append(ww)
        self.ne.append(self.h[v])
        self.h[v] = self.cc
        self.cc += 1

        self.to.append(v)
        self.w.append(ww)
        self.ne.append(self.h[u])
        self.h[u] = self.cc
        self.cc += 1

    class S:
        def __init__(self, l, r):
            self.l = l
            self.r = r
            self.miss = 0
            self.cnt = 0
            self.c = 0

    def init11(self, f):
        self.o = f
        len_o = len(self.o)
        self.a = [self.S(0, 0) for _ in range(len_o * 4)]
        self.build1(1, 0, len_o - 1)

    def build1(self, num, l, r):
        cur = self.S(l, r)
        if l == r:
            cur.c = self.o[l]
            self.a[num] = cur
            return
        else:
            m = (l + r) // 2
            le = num * 2
            ri = le + 1
            self.build1(le, l, m)
            self.build1(ri, m + 1, r)
            self.a[num] = cur
            self.pushup(num, le, ri)

    def query1(self, num, l, r):
        if self.a[num].l >= l and self.a[num].r <= r:
            return self.a[num].c
        else:
            m = (self.a[num].l + self.a[num].r) // 2
            le = num * 2
            ri = le + 1

            mi = -1

            if r > m:
                res = self.query1(ri, l, r)
                mi = max(mi, res)

            if l <= m:
                res = self.query1(le, l, r)
                mi = max(mi, res)

            return mi

    def pushup(self, num, le, ri):
        self.a[num].c = max(self.a[le].c, self.a[ri].c)

    def df(self, n, li):
        sz = len(li)
        if sz >= self.rr or sz >= 11:
            return
        v = li[-1]
        if v == n:
            self.cao = list(li)
            self.rr = sz
            return
        res = list(reversed(li))

        for u in res:
            for vv in res:
                if u + vv > v and u + vv <= n:
                    li.append(u + vv)
                    self.df(n, li)
                    li.pop()
                elif u + vv > n:
                    break

    @staticmethod
    def mul(a, b, p):
        res = 0
        base = a
        while b > 0:
            if (b & 1) > 0:
                res = (res + base) % p
            base = (base + base) % p
            b >>= 1
        return res

    @staticmethod
    def mod_pow(k, n, p):
        res = 1
        temp = k % p
        while n != 0:
            if (n & 1) == 1:
                res = Main.mul(res, temp, p)
            temp = Main.mul(temp, temp, p)
            n >>= 1
        return res % p

    def gen(self, x):
        while True:
            f = random.randint(1, x - 1)
            if 1 <= f <= x - 1:
                return f

    def robin_miller(self, x):
        if x == 1:
            return False
        if x in (2, 3):
            return True
        if (x & 1) == 0:
            return False
        y = x % 6
        if y in (1, 5):
            ck = x - 1
            while (ck & 1) == 0:
                ck >>= 1

            as_ = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

            for a in as_:
                ck1 = ck
                a = self.mod_pow(a, ck1, x)
                while ck1 < x:
                    y = self.mod_pow(a, 2, x)
                    if y == 1 and a != 1 and a != x - 1:
                        return False
                    a = y
                    ck1 <<= 1
                if a != 1:
                    return False
            return True
        else:
            return False

    @staticmethod
    def inv(a, MOD):
        return 1 if a == 1 else (MOD - MOD // a) * Main.inv(MOD % a, MOD) % MOD

    def C(self, n, m, MOD):
        if m + m > n:
            m = n - m
        up = 1
        down = 1
        for i in range(m):
            up = up * (n - i) % MOD
            down = down * (i + 1) % MOD
        return up * self.inv(down, MOD) % MOD

    @staticmethod
    def ex_gcd(a, b):
        if b == 0:
            return [1, 0, a]
        r = Main.ex_gcd(b, a % b)
        return [r[1], r[0] - (a // b) * r[1], r[2]]

    def chinese_rm(self, m, r):
        res = self.ex_gcd(m[0], m[1])
        rm = r[1] - r[0]
        if rm % res[2] == 0:
            pass

    def go(self, i, c, cl):
        cl[i] = c
        for j in range(self.h[i], -1, -1):
            v = self.to[j]
            if cl[v] == 0:
                self.go(v, -c, cl)

    def solve(self):
        t = int(sys.stdin.readline())
        for _ in range(t):
            n = int(sys.stdin.readline())
            k = int(sys.stdin.readline())
            d = int(sys.stdin.readline())
            a = list(map(int, sys.stdin.readline().split()))

            g = 0
            for j in range(d):
                if self.dp[a[j]] == 0:
                    g += 1
                self.dp[a[j]] += 1

            all_ = g
            for j in range(d, n):
                if self.dp[a[j - d]] == 1:
                    g -= 1
                self.dp[a[j - d]] -= 1
                if self.dp[a[j]] == 0:
                    g += 1
                self.dp[a[j]] += 1
                all_ = min(all_, g)

            print(all_)
            for j in range(d):
                self.dp[a[n - j - 1]] -= 1

    def run(self):
        self.h = [-1] * 1000001
        self.solve()

if __name__ == "__main__":
    Main().run()
