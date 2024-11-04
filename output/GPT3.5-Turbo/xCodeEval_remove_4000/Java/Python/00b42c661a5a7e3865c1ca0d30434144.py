class Main:
    def __init__(self):
        self.ct = 0
        self.f = [0] * 200001
        self.b = [0] * 200001
        self.str = [0] * 200001
        self.add = 0
        self.h = []
        self.ne = []
        self.to = []
        self.fa = []
        self.clr = []
        self.aa = []
        self.s1 = 0
        self.s2 = 0
        self.t1 = []

    def mul(self, a, b, p):
        res = 0
        base = a
        while b > 0:
            if b & 1 > 0:
                res = (res + base) % p
            base = (base + base) % p
            b >>= 1
        return res

    def mod_pow(self, k, n, p):
        res = 1
        temp = k
        while n != 0:
            if n & 1 == 1:
                res = (res * temp) % p
            temp = (temp * temp) % p
            n = n >> 1
        return res % p

    def go(self, rt, g):
        self.str[self.ct] = rt
        self.f[rt] = self.ct
        for cd in g[rt]:
            self.ct += 1
            self.go(cd, g)
        self.b[rt] = self.ct

    def dfs(self, from_, k):
        pass

    def add(self, u, v):
        self.to[self.ct] = u
        self.ne[self.ct] = self.h[v]
        self.h[v] = self.ct
        self.ct += 1

    def dfs1(self, c, ff):
        self.clr[c][self.aa[c]] += 1
        for j in self.h[c]:
            if self.to[j] == ff:
                continue
            self.dfs1(self.to[j], c)
            self.clr[c][1] += self.clr[self.to[j]][1]
            self.clr[c][2] += self.clr[self.to[j]][2]
            if (self.clr[self.to[j]][1] == self.s1 and self.clr[self.to[j]][2] == 0) or (self.clr[self.to[j]][2] == self.s2 and self.clr[self.to[j]][1] == 0):
                self.r += 1

    def f(self, n):
        c = 0
        while n > 0:
            c += n % 10
            n //= 10
        return c & 3 == 0

    def next(self, s):
        len_ = len(s)
        ne = [[-1] * 26 for _ in range(len_ + 1)]
        for i in range(len_ - 1, -1, -1):
            ne[i] = ne[i + 1].copy()
            ne[i][ord(s[i]) - ord('a')] = i + 1
        return ne

    def solve(self):
        s = self.ns()
        t = self.ns()
        len_ = len(s)
        pref = [0] * len_
        suf = [0] * (len_ + 1)
        p = 0
        tlen = len(t)
        for i in range(len_):
            if p < tlen and s[i] == t[p]:
                p += 1
            pref[i] = p
        p = 0
        for i in range(len_ - 1, -1, -1):
            if p < tlen and s[i] == t[tlen - 1 - p]:
                p += 1
            suf[i] = p
        e = -1
        all_ = 0
        for i in range(-1, len_):
            r = tlen - (0 if i < 0 else pref[i])
            while e + 1 <= len_ and suf[e + 1] >= r:
                e += 1
            all_ = max(all_, e - i - 1)
        self.println(all_)

    def update(self, t, i, v):
        while i < len(t):
            t[i] += v
            i += i & -i

    def get(self, t, i):
        s = 0
        while i > 0:
            s += t[i]
            i -= i & -i
        return s

    def id0(self, t, v):
        s = 0
        p = 0
        for i in range(t.bit_length(), -1, -1):
            if p + (1 << i) < len(t) and s + t[p + (1 << i)] < v:
                v -= t[p + (1 << i)]
                p |= 1 << i
        return p + 1

    def init(self, f):
        self.o = f
        len_ = len(self.o)
        self.a = [None] * (len_ * 4)
        self.build(1, 0, len_ - 1)

    def build(self, num, l, r):
        cur = self.S(l, r)
        if l == r:
            self.a[num] = cur
            return
        else:
            m = (l + r) >> 1
            le = num << 1
            ri = le | 1
            self.build(le, l, m)
            self.build(ri, m + 1, r)
            self.a[num] = cur
            self.pushup(num, le, ri)

    def update(self, num, l, v):
        if self.a[num].l == self.a[num].r:
            self.a[num].le = v % self.dd
            self.a[num].ri = v % self.dd
            self.a[num].all = v % self.dd
            self.a[num].tot = v % self.dd
        else:
            m = (self.a[num].l + self.a[num].r) >> 1
            le = num << 1
            ri = le | 1
            self.pushdown(num, le, ri)
            if l <= m:
                self.update(le, l, v)
            if l > m:
                self.update(ri, l, v)
            self.pushup(num, le, ri)

    def pushup(self, num, le, ri):
        self.a[num].all = (self.a[le].all * self.a[ri].all) % self.dd
        self.a[num].le = (self.a[le].le + self.a[le].all * self.a[ri].le) % self.dd
        self.a[num].ri = (self.a[ri].ri + self.a[ri].all * self.a[le].ri) % self.dd
        self.a[num].tot = (self.a[le].tot + self.a[ri].tot + self.a[le].ri * self.a[ri].le) % self.dd

    def pushdown(self, num, le, ri):
        pass

    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def solve(self):
        self.is = sys.stdin
        self.out = sys.stdout
        self.solve()
        self.out.flush()

    def readByte(self):
        if self.lenbuf == -1:
            raise Exception("InputMismatchException")
        if self.ptrbuf >= self.lenbuf:
            self.ptrbuf = 0
            self.lenbuf = self.is.read(self.inbuf)
            if self.lenbuf <= 0:
                return -1
        return self.inbuf[self.ptrbuf]

    def id1(self, c):
        return not (c >= 33 and c <= 126)

    def skip(self):
        b = 0
        while (b := self.readByte()) != -1 and self.id1(b):
            pass
        return b

    def nd(self):
        return float(self.ns())

    def nc(self):
        return chr(self.skip())

    def ncc(self):
        b = 0
        while (b := self.readByte()) != -1 and not (b >= 32 and b <= 126):
            pass
        return chr(b)

    def ns(self):
        b = self.skip()
        sb = []
        while not self.id1(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def ns(self, n):
        buf = [0] * n
        b = self.skip()
        p = 0
        while not self.id1(b):
            buf[p] = chr(b)
            p += 1
            b = self.readByte()
        return buf if n == p else buf[:p]

    def nline(self):
        b = self.skip()
        sb = []
        while not self.id1(b) or b == ord(" "):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def nm(self, n, m):
        a = []
        for _ in range(n):
            a.append(self.ns(m))
        return a

    def na(self, n):
        a = []
        for _ in range(n):
            a.append(self.ni())
        return a

    def nal(self, n):
        a = []
        for _ in range(n):
            a.append(self.nl())
        return a

    def ni(self):
        num = 0
        b = self.skip()
        minus = False
        while True:
            if b >= ord("0") and b <= ord("9"):
                num = (num << 3) + (num << 1) + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()

    def nl(self):
        num = 0
        b = self.skip()
        minus = False
        while True:
            if b >= ord("0") and b <= ord("9"):
                num = num * 10 + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()

    def print(self, obj):
        self.out.write(str(obj))

    def println(self, obj):
        self.out.write(str(obj) + "\n")

    def println(self):
        self.out.write("\n")

    class S:
        def __init__(self, l, r):
            self.l = l
            self.r = r
            self.le = 0
            self.ri = 0
            self.tot = 0
            self.all = 0

    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def solve(self):
        self.is = sys.stdin
        self.out = sys.stdout
        self.solve()
        self.out.flush()

    def readByte(self):
        if self.lenbuf == -1:
            raise Exception("InputMismatchException")
        if self.ptrbuf >= self.lenbuf:
            self.ptrbuf = 0
            self.lenbuf = self.is.read(self.inbuf)
            if self.lenbuf <= 0:
                return -1
        return self.inbuf[self.ptrbuf]

    def id1(self, c):
        return not (c >= 33 and c <= 126)

    def skip(self):
        b = 0
        while (b := self.readByte()) != -1 and self.id1(b):
            pass
        return b

    def nd(self):
        return float(self.ns())

    def nc(self):
        return chr(self.skip())

    def ncc(self):
        b = 0
        while (b := self.readByte()) != -1 and not (b >= 32 and b <= 126):
            pass
        return chr(b)

    def ns(self):
        b = self.skip()
        sb = []
        while not self.id1(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def ns(self, n):
        buf = [0] * n
        b = self.skip()
        p = 0
        while not self.id1(b):
            buf[p] = chr(b)
            p += 1
            b = self.readByte()
        return buf if n == p else buf[:p]

    def nline(self):
        b = self.skip()
        sb = []
        while not self.id1(b) or b == ord(" "):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def nm(self, n, m):
        a = []
        for _ in range(n):
            a.append(self.ns(m))
        return a

    def na(self, n):
        a = []
        for _ in range(n):
            a.append(self.ni())
        return a

    def nal(self, n):
        a = []
        for _ in range(n):
            a.append(self.nl())
        return a

    def ni(self):
        num = 0
        b = self.skip()
        minus = False
        while True:
            if b >= ord("0") and b <= ord("9"):
                num = (num << 3) + (num << 1) + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()

    def nl(self):
        num = 0
        b = self.skip()
        minus = False
        while True:
            if b >= ord("0") and b <= ord("9"):
                num = num * 10 + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()

    def print(self, obj):
        self.out.write(str(obj))

    def println(self, obj):
        self.out.write(str(obj) + "\n")

    def println(self):
        self.out.write("\n")


if __name__ == "__main__":
    Main().run()
