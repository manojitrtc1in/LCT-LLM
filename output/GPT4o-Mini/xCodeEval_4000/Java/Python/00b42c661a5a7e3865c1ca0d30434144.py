import random
import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.ct = 0
        self.f = [0] * 200001
        self.b = [0] * 200001
        self.str = [0] * 200001
        self.add = 0
        self.h = [-1] * 200001
        self.ne = [0] * 200001
        self.to = [0] * 200001
        self.fa = [0] * 200001
        self.clr = [[0] * 3 for _ in range(200001)]
        self.aa = [0] * 200001
        self.s1 = 0
        self.s2 = 0
        self.r = 0
        self.dd = 10007
        self.t1 = []

    def run(self):
        self.solve()

    def mul(self, a, b, p):
        res = 0
        base = a
        while b > 0:
            if (b & 1) > 0:
                res = (res + base) % p
            base = (base + base) % p
            b >>= 1
        return res

    def mod_pow(self, k, n, p):
        res = 1
        temp = k
        while n != 0:
            if (n & 1) == 1:
                res = (res * temp) % p
            temp = (temp * temp) % p
            n >>= 1
        return res % p

    def go(self, rt, g):
        self.str[self.ct] = rt
        self.f[rt] = self.ct
        for cd in g[rt]:
            self.ct += 1
            self.go(cd, g)
        self.b[rt] = self.ct

    def sort(self, a):
        for i in range(1, len(a)):
            p = random.randint(0, i - 1)
            a[p], a[i] = a[i], a[p]
        a.sort()

    def dfs(self, from_node, k):
        pass

    def add_edge(self, u, v):
        self.to[self.ct] = u
        self.ne[self.ct] = self.h[v]
        self.h[v] = self.ct
        self.ct += 1

    def dfs1(self, c, ff):
        self.clr[c][self.aa[c]] += 1
        for j in range(self.h[c], -1, -1):
            if self.to[j] == ff:
                continue
            self.dfs1(self.to[j], c)
            self.clr[c][1] += self.clr[self.to[j]][1]
            self.clr[c][2] += self.clr[self.to[j]][2]
            if (self.clr[self.to[j]][1] == self.s1 and self.clr[self.to[j]][2] == 0) or \
               (self.clr[self.to[j]][2] == self.s2 and self.clr[self.to[j]][1] == 0):
                self.r += 1

    def f_check(self, n):
        c = 0
        while n > 0:
            c += n % 10
            n //= 10
        return (c & 3) == 0

    def next_array(self, s):
        length = len(s)
        ne = [[-1] * 26 for _ in range(length + 1)]
        for i in range(length - 1, -1, -1):
            ne[i] = ne[i + 1][:]
            ne[i][ord(s[i]) - ord('a')] = i + 1
        return ne

    def solve(self):
        s = self.ns()
        t = self.ns()
        length = len(s)
        pref = [0] * length
        suf = [0] * (length + 1)
        p = 0
        tlen = len(t)

        for i in range(length):
            if p < tlen and s[i] == t[p]:
                p += 1
            pref[i] = p

        p = 0
        for i in range(length - 1, -1, -1):
            if p < tlen and s[i] == t[tlen - 1 - p]:
                p += 1
            suf[i] = p

        e = -1
        all_count = 0
        for i in range(-1, length):
            r = tlen - (0 if i < 0 else pref[i])
            while e + 1 <= length and suf[e + 1] >= r:
                e += 1
            all_count = max(all_count, e - i - 1)

        self.println(all_count)

    def update(self, t, i, v):
        while i < len(t):
            t[i] += v
            i += (i & -i)

    def get(self, t, i):
        s = 0
        while i > 0:
            s += t[i]
            i -= (i & -i)
        return s

    def equal_bigger(self, t, v):
        s = 0
        p = 0
        for i in range(31 - (t.length() - 1).bit_length(), -1, -1):
            if p + (1 << i) < len(t) and s + t[p + (1 << i)] < v:
                v -= t[p + (1 << i)]
                p |= 1 << i
        return p + 1

    class S:
        def __init__(self, l, r):
            self.l = l
            self.r = r
            self.le = 0
            self.ri = 0
            self.tot = 0
            self.all = 0

    a = []
    o = []

    @staticmethod
    def init(f):
        Main.o = f
        length = len(Main.o)
        Main.a = [Main.S(0, 0) for _ in range(length * 4)]
        Main.build(1, 0, length - 1)

    @staticmethod
    def build(num, l, r):
        cur = Main.S(l, r)
        if l == r:
            Main.a[num] = cur
            return
        m = (l + r) >> 1
        le = num << 1
        ri = le | 1
        Main.build(le, l, m)
        Main.build(ri, m + 1, r)
        Main.a[num] = cur
        Main.pushup(num, le, ri)

    @staticmethod
    def update(num, l, v):
        if Main.a[num].l == Main.a[num].r:
            Main.a[num].le = v % Main.dd
            Main.a[num].ri = v % Main.dd
            Main.a[num].all = v % Main.dd
            Main.a[num].tot = v % Main.dd
        else:
            m = (Main.a[num].l + Main.a[num].r) >> 1
            le = num << 1
            ri = le | 1
            Main.pushdown(num, le, ri)
            if l <= m:
                Main.update(le, l, v)
            if l > m:
                Main.update(ri, l, v)
            Main.pushup(num, le, ri)

    @staticmethod
    def pushup(num, le, ri):
        Main.a[num].all = (Main.a[le].all * Main.a[ri].all) % Main.dd
        Main.a[num].le = (Main.a[le].le + Main.a[le].all * Main.a[ri].le) % Main.dd
        Main.a[num].ri = (Main.a[ri].ri + Main.a[ri].all * Main.a[le].ri) % Main.dd
        Main.a[num].tot = (Main.a[le].tot + Main.a[ri].tot + Main.a[le].ri * Main.a[ri].le) % Main.dd

    @staticmethod
    def pushdown(num, le, ri):
        pass

    @staticmethod
    def gcd(a, b):
        return b if b == 0 else Main.gcd(b, a % b)

    def read_input(self):
        return sys.stdin.read().splitlines()

    def ns(self):
        return input().strip()

    def print(self, obj):
        print(obj, end='')

    def println(self, obj):
        print(obj)

if __name__ == "__main__":
    Main().run()
