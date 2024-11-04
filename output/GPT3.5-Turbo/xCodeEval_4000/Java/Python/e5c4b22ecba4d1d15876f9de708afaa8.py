import sys
from typing import List

class FastWriter:
    def __init__(self, out=sys.stdout):
        self.out = out
        self.buf = []
    
    def write(self, s):
        self.buf.append(str(s))
    
    def writeln(self, s=""):
        self.buf.append(str(s))
        self.buf.append("\n")
    
    def flush(self):
        self.out.write("".join(self.buf))
        self.out.flush()

class F2:
    def __init__(self, input_str):
        self.input = input_str.strip().split("\n")
        self.ispace = 0
        self.fast_writer = FastWriter()
    
    def solve(self):
        n = self.ni()
        g = [[False] * 10 for _ in range(10)]
        for _ in range(self.ni()):
            x, y = self.ni(), self.ni()
            g[x][y] = g[y][x] = True
        for i in range(10):
            g[i][i] = True

        njs = [[0] * 10 for _ in range(1 << 9)]
        for j in range(1 << 9):
            for k in range(10):
                if j << ~k >= 0:
                    nj = j
                    for l in range(10):
                        if g[k][l]:
                            if k > l:
                                nj |= 1 << l
                        else:
                            nj &= ~(1 << l)
                    njs[j][k] = nj

        mod = 998244353
        dp = [0] * (1 << 9)
        dp[0] = 1
        for i in range(1, n + 1):
            ndp = [0] * (1 << 9)
            for j in range(1 << 9):
                for k in range(10):
                    if j << ~k >= 0:
                        nj = njs[j][k]
                        ndp[nj] += dp[j]
                        if ndp[nj] >= mod:
                            ndp[nj] -= mod
            dp = ndp
        ans = sum(dp) % mod
        self.fast_writer.writeln(ans)
    
    def sum(self, a: List[int]) -> int:
        return sum(a)
    
    def mul(self, a: List[int], b: List[int]) -> List[int]:
        if len(a) == 0 and len(b) == 0:
            return []
        if len(a) + len(b) >= 300:
            return self.mulnaive(a, b)
        else:
            return self.mulnaive(a, b)
    
    def mulnaive(self, a: List[int], b: List[int]) -> List[int]:
        c = [0] * (len(a) + len(b) - 1)
        for i in range(len(a)):
            for j in range(len(b)):
                c[i + j] += a[i] * b[j]
                if c[i + j] >= self.big:
                    c[i + j] -= self.big
        for i in range(len(c)):
            c[i] %= self.mod
        return c
    
    def big(self):
        return (sys.maxsize // self.mod // self.mod - 1) * self.mod * self.mod
    
    def mulnaive(self, a: List[int], b: List[int], lim: int) -> List[int]:
        c = [0] * lim
        for i in range(len(a)):
            for j in range(len(b)):
                if i + j < lim:
                    c[i + j] += a[i] * b[j]
                    if c[i + j] >= self.big:
                        c[i + j] -= self.big
        for i in range(len(c)):
            c[i] %= self.mod
        return c
    
    def convolve(self, a: List[int], b: List[int]) -> List[int]:
        m = max(2, 1 << (a.bit_length() - 1).bit_length() << 2)

        wps = [0] * m
        unit = self.pow(self.G, (self.P - 1) // m)
        wps[0] = 1
        for p in range(1, m):
            wps[p] = wps[p - 1] * unit % self.mod

        fa = self.go(a, m, False)
        fb = fa if a == b else self.go(b, m, False)
        for i in range(m):
            fa[i] = fa[i] * fb[i] % self.mod
        fa = self.go(fa, m, True)
        fa[1:m] = fa[m - 1:0:-1]
        return fa
    
    def go(self, src: List[int], n: int, inverse: bool) -> List[int]:
        dst = src.copy()
        self.fft(dst, [0] * n)
        if inverse:
            in_ = self.invl(n)
            for i in range(n):
                dst[i] = dst[i] * in_ % self.mod
        return dst
    
    def fft(self, X: List[int], Y: List[int]):
        s = 1
        eo = False
        n = len(X)
        for m in range(n, 3, -1):
            m >>= 1
            for p in range(m):
                wp = self.wps[s * p]
                wk = (wp << 32) // self.P
                for q in range(s):
                    a = X[q + s * (p + 0)]
                    b = X[q + s * (p + m)]
                    ndsts = a + b
                    if ndsts >= 2 * self.P:
                        ndsts -= 2 * self.P
                    T = a - b + 2 * self.P
                    Q = wk * T >> 32
                    Y[q + s * (2 * p + 0)] = ndsts
                    Y[q + s * (2 * p + 1)] = wp * T - Q * self.P & ((1 << 32) - 1)
            s *= 2
            eo = not eo
            X, Y = Y, X
        z = Y if eo else X
        for q in range(s):
            a = X[q + 0]
            b = X[q + s]
            z[q + 0] = (a + b) % self.P
            z[q + s] = (a - b + 2 * self.P) % self.P
    
    def pow(self, a: int, n: int) -> int:
        ret = 1
        x = 63 - n.bit_length()
        while x >= 0:
            ret = ret * ret % self.mod
            if n << ~x < 0:
                ret = ret * a % self.mod
            x -= 1
        return ret
    
    def invl(self, a: int) -> int:
        b = self.mod
        p, q = 1, 0
        while b > 0:
            c = a // b
            d = a
            a = b
            b = d % b
            d = p
            p = q
            q = d - c * q
        return p + self.mod if p < 0 else p
    
    def C(self, n: int, r: int, mod: int, fif: List[List[int]]) -> int:
        if n < 0 or r < 0 or r > n:
            return 0
        return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod
    
    def enumFIF(self, n: int, mod: int) -> List[List[int]]:
        f = [0] * (n + 1)
        invf = [0] * (n + 1)
        f[0] = 1
        for i in range(1, n + 1):
            f[i] = f[i - 1] * i % mod
        a = f[n]
        b = mod
        p, q = 1, 0
        while b > 0:
            c = a // b
            d = a
            a = b
            b = d % b
            d = p
            p = q
            q = d - c * q
        invf[n] = p + mod if p < 0 else p
        for i in range(n - 1, -1, -1):
            invf[i] = invf[i + 1] * (i + 1) % mod
        return [f, invf]
    
    def DJSet(self, n: int):
        self.upper = [-1] * n
    
    def root(self, x: int) -> int:
        return x if self.upper[x] < 0 else self.root(self.upper[x])
    
    def equiv(self, x: int, y: int) -> bool:
        return self.root(x) == self.root(y)
    
    def unite(self, x: int, y: int) -> bool:
        x = self.root(x)
        y = self.root(y)
        if x != y:
            if self.upper[y] < self.upper[x]:
                x, y = y, x
            self.upper[x] += self.upper[y]
            self.upper[y] = x
        return x == y
    
    def count(self) -> int:
        return sum(1 for u in self.upper if u < 0)
    
    def toBucket(self) -> List[List[int]]:
        n = len(self.upper)
        ret = [[] for _ in range(n)]
        rp = [0] * n
        for i in range(n):
            if self.upper[i] < 0:
                ret[i] = [0] * -self.upper[i]
        for i in range(n):
            r = self.root(i)
            ret[r][rp[r]] = i
            rp[r] += 1
        return ret
    
    def run(self):
        self.solve()
        self.fast_writer.flush()
    
    def readByte(self) -> int:
        if self.ispace == len(self.input[self.ispace]):
            self.ispace = 0
            self.input = self.input[self.ispace + 1:]
            return -1
        b = self.input[self.ispace][self.ptrbuf]
        self.ptrbuf += 1
        return b
    
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
    
    def ns(self) -> str:
        b = self.skip()
        sb = []
        while not self.isSpaceChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)
    
    def na(self, n: int) -> List[int]:
        return [self.ni() for _ in range(n)]
    
    def nal(self, n: int) -> List[int]:
        return [self.nl() for _ in range(n)]
    
    def nm(self, n: int, m: int) -> List[List[str]]:
        return [list(self.ns()) for _ in range(n)]
    
    def nmi(self, n: int, m: int) -> List[List[int]]:
        return [self.na(m) for _ in range(n)]
    
    def ni(self) -> int:
        return int(self.nl())
    
    def nl(self) -> int:
        num = 0
        b = self.readByte()
        minus = False
        while True:
            if b >= ord("0") and b <= ord("9"):
                num = num * 10 + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()
            if b == ord("-"):
                minus = True
                b = self.readByte()
    
    def tr(self, *o):
        if not self.oj:
            print(*o)
    
    def trnz(self, *o):
        for i in range(len(o)):
            if o[i] != 0:
                self.tr(i, ":", o[i])
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def tf(self, *r):
        for x in r:
            self.tr("#" if x else ".")
        self.tr()
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            x = o[i]
            while x != 0:
                stands.append((i, x & -x))
                x &= x - 1
        self.tr(stands)
    
    def run(self):
        self.solve()
        self.fast_writer.flush()
    
    def readByte(self) -> int:
        if self.ispace == len(self.input[self.ispace]):
            self.ispace = 0
            self.input = self.input[self.ispace + 1:]
            return -1
        b = self.input[self.ispace][self.ptrbuf]
        self.ptrbuf += 1
        return b
    
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
    
    def ns(self) -> str:
        b = self.skip()
        sb = []
        while not self.isSpaceChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)
    
    def na(self, n: int) -> List[int]:
        return [self.ni() for _ in range(n)]
    
    def nal(self, n: int) -> List[int]:
        return [self.nl() for _ in range(n)]
    
    def nm(self, n: int, m: int) -> List[List[str]]:
        return [list(self.ns()) for _ in range(n)]
    
    def nmi(self, n: int, m: int) -> List[List[int]]:
        return [self.na(m) for _ in range(n)]
    
    def ni(self) -> int:
        return int(self.nl())
    
    def nl(self) -> int:
        num = 0
        b = self.readByte()
        minus = False
        while True:
            if b >= ord("0") and b <= ord("9"):
                num = num * 10 + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()
            if b == ord("-"):
                minus = True
                b = self.readByte()

input_str = '''
10
10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 1
'''
f2 = F2(input_str)
f2.run()
