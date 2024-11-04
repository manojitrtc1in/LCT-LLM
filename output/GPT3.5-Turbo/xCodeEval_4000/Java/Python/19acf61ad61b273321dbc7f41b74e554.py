import sys
from typing import List

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
        self.s = []
        self.a = []
        self.o = []
        self.clr = []
        self.qr = []
        self.qs = []
        self.rr = 100
        self.cao = []
        self.rd = random.Random(1274873)

    def main(self):
        self.run()

    def init1(self, n: int):
        self.groups = n
        self.fa = [0] * n
        for i in range(1, n):
            self.fa[i] = i
        self.sz = [1] * n

    def root(self, p: int) -> int:
        while p != self.fa[p]:
            self.fa[p] = self.fa[self.fa[p]]
            p = self.fa[p]
        return p

    def combine(self, p: int, q: int):
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

    def roundS(self, result: float, scale: int) -> str:
        fmt = "%%.%df" % scale
        return fmt % result

    def unique(self, a: List[int]) -> List[int]:
        p = 1
        for i in range(1, len(a)):
            if a[i] != a[i - 1]:
                a[p] = a[i]
                p += 1
        return a[:p]

    def bigger(self, a: List[int], key: int) -> int:
        return self.bigger(a, 0, len(a), key)

    def bigger(self, a: List[int], lo: int, hi: int, key: int) -> int:
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] > key:
                hi = mid
            else:
                lo = mid + 1
        return lo

    def addEdge(self, u: int, v: int, w: int):
        self.to.append(v)
        self.ne.append(self.h[u])
        self.h[u] = self.m
        self.m += 1

    def add(self, u: int, v: int, ww: int):
        self.to.append(u)
        self.w.append(ww)
        self.ne.append(self.h[v])
        self.h[v] = self.cc

        self.to.append(v)
        self.w.append(ww)
        self.ne.append(self.h[u])
        self.h[u] = self.cc

        self.cc += 1

    def init11(self, f: List[int]):
        self.o = f
        length = len(self.o)
        self.a = [None] * (length * 4)
        self.build1(1, 0, length - 1)

    def build1(self, num: int, l: int, r: int):
        cur = S(l, r)
        if l == r:
            cur.c = self.o[l]
            self.a[num] = cur
            return
        else:
            m = (l + r) // 2
            le = num << 1
            ri = le | 1
            self.build1(le, l, m)
            self.build1(ri, m + 1, r)
            self.a[num] = cur
            self.pushup(num, le, ri)

    def query1(self, num: int, l: int, r: int) -> int:
        if self.a[num].l >= l and self.a[num].r <= r:
            return self.a[num].c
        else:
            m = (self.a[num].l + self.a[num].r) // 2
            le = num << 1
            ri = le | 1

            mi = -1

            if r > m:
                res = self.query1(ri, l, r)
                mi = max(mi, res)

            if l <= m:
                res = self.query1(le, l, r)
                mi = max(mi, res)

            return mi

    def pushup(self, num: int, le: int, ri: int):
        self.a[num].c = max(self.a[le].c, self.a[ri].c)

    def df(self, n: int, li: List[int]):
        sz = len(li)
        if sz >= self.rr or sz >= 11:
            return
        v = li[-1]
        if v == n:
            self.cao = li.copy()
            self.rr = sz
            return
        res = li[::-1]
        for u in res:
            for vv in res:
                if u + vv > v and u + vv <= n:
                    li.append(u + vv)
                    self.df(n, li)
                    li.pop()
                elif u + vv > n:
                    break

    def gen(self, x: int) -> int:
        while True:
            f = self.rd.randint(0, x - 1)
            if f >= 1 and f <= x - 1:
                return f

    def robin_miller(self, x: int) -> bool:
        if x == 1:
            return False
        if x == 2:
            return True
        if x == 3:
            return True
        if x % 2 == 0:
            return False
        y = x % 6
        if y == 1 or y == 5:
            ck = x - 1
            while ck % 2 == 0:
                ck //= 2

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

    def mul(self, a: int, b: int, p: int) -> int:
        res = 0
        base = a
        while b > 0:
            if b & 1 > 0:
                res = (res + base) % p
            base = (base + base) % p
            b >>= 1
        return res

    def mod_pow(self, k: int, n: int, p: int) -> int:
        res = 1
        temp = k % p
        while n != 0:
            if n & 1 == 1:
                res = self.mul(res, temp, p)
            temp = self.mul(temp, temp, p)
            n = n >> 1
        return res % p

    def inv(self, a: int, MOD: int) -> int:
        return a if a == 1 else (MOD - MOD // a) * self.inv(MOD % a, MOD) % MOD

    def C(self, n: int, m: int, MOD: int) -> int:
        if m + m > n:
            m = n - m
        up = 1
        down = 1
        for i in range(m):
            up = self.mul(up, n - i, MOD)
            down = self.mul(down, i + 1, MOD)
        return self.mul(up, self.inv(down, MOD), MOD)

    def ex_gcd(self, a: int, b: int) -> List[int]:
        if b == 0:
            return [1, 0, a]
        r = self.ex_gcd(b, a % b)
        return [r[1], r[0] - (a // b) * r[1], r[2]]

    def chinese_rm(self, m: List[int], r: List[int]):
        res = self.ex_gcd(m[0], m[1])
        rm = r[1] - r[0]
        if rm % res[2] == 0:
            pass

    def go(self, i: int, c: int, cl: List[int]):
        cl[i] = c
        for j in range(self.h[i], -1, self.ne[j]):
            v = self.to[j]
            if cl[v] == 0:
                self.go(v, -c, cl)

    def solve(self):
        t = self.ni()
        dp = [0] * 1000001
        for _ in range(t):
            n = self.ni()
            k = self.ni()
            d = self.ni()
            a = self.na(n)

            g = 0
            for j in range(d):
                if dp[a[j]] == 0:
                    g += 1
                dp[a[j]] += 1
            all_ = g
            for j in range(d, n):
                dp[a[j - d]] -= 1
                if dp[a[j - d]] == 0:
                    g -= 1
                if dp[a[j]] == 0:
                    g += 1
                dp[a[j]] += 1
                all_ = min(all_, g)
            self.println(all_)
            for j in range(d):
                dp[a[n - j - 1]] -= 1

    def readByte(self) -> int:
        if self.ptrbuf >= self.lenbuf:
            self.ptrbuf = 0
            self.lenbuf = sys.stdin.buffer.readinto(self.inbuf)
            if self.lenbuf <= 0:
                return -1
        return self.inbuf[self.ptrbuf]

    def isSpaceChar(self, c: int) -> bool:
        return not (c >= 33 and c <= 126)

    def skip(self) -> int:
        b = self.readByte()
        while b != -1 and self.isSpaceChar(b):
            b = self.readByte()
        return b

    def nd(self) -> float:
        return float(self.ns())

    def nc(self) -> str:
        return chr(self.skip())

    def ncc(self) -> str:
        b = self.readByte()
        return chr(b)

    def ns(self) -> str:
        b = self.skip()
        sb = []
        while not self.isSpaceChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return ''.join(sb)

    def ns(self, n: int) -> List[str]:
        buf = [''] * n
        b = self.skip()
        p = 0
        while p < n and not self.isSpaceChar(b):
            buf[p] = chr(b)
            p += 1
            b = self.readByte()
        return buf if n == p else buf[:p]

    def nline(self) -> str:
        b = self.skip()
        sb = []
        while not self.isSpaceChar(b) or b == ord(' '):
            sb.append(chr(b))
            b = self.readByte()
        return ''.join(sb)

    def nm(self, n: int, m: int) -> List[List[str]]:
        a = []
        for _ in range(n):
            a.append(self.ns(m))
        return a

    def na(self, n: int) -> List[int]:
        a = [0] * n
        for i in range(n):
            a[i] = self.ni()
        return a

    def nal(self, n: int) -> List[int]:
        a = [0] * n
        for i in range(n):
            a[i] = self.nl()
        return a

    def ni(self) -> int:
        num = 0
        b = self.readByte()
        minus = False
        while not (b >= ord('0') and b <= ord('9')) and b != ord('-'):
            b = self.readByte()
        if b == ord('-'):
            minus = True
            b = self.readByte()
        while True:
            if b >= ord('0') and b <= ord('9'):
                num = (num << 3) + (num << 1) + (b - ord('0'))
            else:
                return -num if minus else num
            b = self.readByte()

    def nl(self) -> int:
        num = 0
        b = self.readByte()
        minus = False
        while not (b >= ord('0') and b <= ord('9')) and b != ord('-'):
            b = self.readByte()
        if b == ord('-'):
            minus = True
            b = self.readByte()
        while True:
            if b >= ord('0') and b <= ord('9'):
                num = num * 10 + (b - ord('0'))
            else:
                return -num if minus else num
            b = self.readByte()

    def print(self, obj: object):
        sys.stdout.write(str(obj))

    def println(self, obj: object = ''):
        sys.stdout.write(str(obj) + '\n')

class S:
    def __init__(self, l: int, r: int):
        self.l = l
        self.r = r
        self.miss = 0
        self.cnt = 0
        self.c = 0

if __name__ == '__main__':
    main = Main()
    main.main()
