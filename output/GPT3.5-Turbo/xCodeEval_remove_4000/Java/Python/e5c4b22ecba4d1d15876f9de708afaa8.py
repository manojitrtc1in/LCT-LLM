import sys
from typing import List

class FastWriter:
    def __init__(self, output=sys.stdout):
        self.output = output
        self.buffer = []

    def write(self, s):
        self.buffer.append(str(s))

    def writeln(self, s=''):
        self.buffer.append(str(s))
        self.buffer.append('\n')

    def flush(self):
        self.output.write(''.join(self.buffer))
        self.output.flush()

    def print(self, *args, sep=' ', end='\n'):
        self.write(sep.join(map(str, args)) + end)

    def println(self, *args):
        self.print(*args, end='\n')

    def close(self):
        self.flush()
        if self.output != sys.stdout:
            self.output.close()

class F2:
    def __init__(self):
        self.INPUT = ''
        self.is_oj = sys.stdin is not sys.__stdin__

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
        self.out.println(ans)

    def sum(self, a: List[int]) -> int:
        return sum(a)

    def mul(self, a: List[int], b: List[int]) -> List[int]:
        if len(a) == 0 and len(b) == 0:
            return []
        if len(a) + len(b) >= 300:
            return self.id2_convolve(a, b)[:len(a) + len(b) - 1]
        else:
            return self.id3(a, b)

    def id2_convolve(self, a: List[int], b: List[int]) -> List[int]:
        P = 998244353
        mod = P
        G = 3
        m = max(2, 1 << (2 * (max(len(a), len(b)) - 1).bit_length()))
        wps = [0] * m
        unit = pow(G, (P - 1) // m, P)
        wps[0] = 1
        for p in range(1, m):
            wps[p] = wps[p - 1] * unit % mod

        def fft(X: List[int], Y: List[int]) -> None:
            s = 1
            eo = False
            for n in range(len(X), 3, -1):
                m = n // 2
                for p in range(m):
                    wp = wps[s * p]
                    wk = (wp << 32) // P
                    for q in range(s):
                        a = X[q + s * (p + 0)]
                        b = X[q + s * (p + m)]
                        ndsts = a + b
                        if ndsts >= 2 * P:
                            ndsts -= 2 * P
                        T = a - b + 2 * P
                        Q = wk * T >> 32
                        Y[q + s * (2 * p + 0)] = ndsts
                        Y[q + s * (2 * p + 1)] = wp * T - Q * P & ((1 << 32) - 1)
                s *= 2
                eo = not eo
                X, Y = Y, X
            z = Y if eo else X
            for q in range(s):
                a = X[q + 0]
                b = X[q + s]
                z[q + 0] = (a + b) % P
                z[q + s] = (a - b + 2 * P) % P

        def go(src: List[int], n: int, inverse: bool) -> List[int]:
            dst = src[:n]
            fft(dst, [0] * n)
            if inverse:
                in_ = self.invl(n)
                for i in range(n):
                    dst[i] = dst[i] * in_ % mod
            return dst

        def pow(a: int, n: int) -> int:
            ret = 1
            x = 63 - n.bit_length()
            while x >= 0:
                ret = ret * ret % mod
                if n << ~x < 0:
                    ret = ret * a % mod
                x -= 1
            return ret

        def invl(a: int) -> int:
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
            return p + mod if p < 0 else p

        def id3(a: List[int], b: List[int]) -> List[int]:
            c = [0] * (len(a) + len(b) - 1)
            for i in range(len(a)):
                for j in range(len(b)):
                    c[i + j] += a[i] * b[j]
                    if c[i + j] >= big:
                        c[i + j] -= big
            for i in range(len(c)):
                c[i] %= mod
            return c

        if len(a) + len(b) >= 300:
            return id2_convolve(a, b)[:lim]
        else:
            return id3(a, b, lim)

    def id3(self, a: List[int], b: List[int], lim: int = -1) -> List[int]:
        c = [0] * (lim if lim != -1 else len(a) + len(b) - 1)
        for i in range(len(a)):
            for j in range(len(b) if lim == -1 else min(len(b), lim - i)):
                c[i + j] += a[i] * b[j]
                if c[i + j] >= big:
                    c[i + j] -= big
        for i in range(len(c)):
            c[i] %= mod
        return c

    def C(self, n: int, r: int, mod: int, fif: List[List[int]]) -> int:
        if n < 0 or r < 0 or r > n:
            return 0
        return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod

    def id0(self, n: int, mod: int) -> List[List[int]]:
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
                ret[i] = [0] * (-self.upper[i])
        for i in range(n):
            r = self.root(i)
            ret[r][rp[r]] = i
            rp[r] += 1
        return ret

    def run(self):
        self.is = sys.stdin if self.is_oj else sys.stdin.buffer
        self.out = FastWriter(sys.stdout)

        self.solve()
        self.out.flush()

    def main(self):
        self.run()

    def readByte(self) -> int:
        b = sys.stdin.buffer.read(1)
        if not b:
            return -1
        return b[0]

    def skip(self) -> int:
        b = self.readByte()
        while b != -1 and not (33 <= b <= 126):
            b = self.readByte()
        return b

    def nd(self) -> float:
        return float(self.ns())

    def nc(self) -> str:
        return chr(self.skip())

    def ns(self) -> str:
        b = self.skip()
        sb = []
        while 33 <= b <= 126:
            sb.append(chr(b))
            b = self.readByte()
        return ''.join(sb)

    def ns(self, n: int) -> List[str]:
        buf = [''] * n
        b = self.skip()
        p = 0
        while p < n and 33 <= b <= 126:
            buf[p] = chr(b)
            p += 1
            b = self.readByte()
        return buf[:p]

    def na(self, n: int) -> List[int]:
        return [self.ni() for _ in range(n)]

    def nal(self, n: int) -> List[int]:
        return [self.nl() for _ in range(n)]

    def nm(self, n: int, m: int) -> List[List[str]]:
        return [self.ns(m) for _ in range(n)]

    def nmi(self, n: int, m: int) -> List[List[int]]:
        return [self.na(m) for _ in range(n)]

    def ni(self) -> int:
        return int(self.nl())

    def nl(self) -> int:
        num = 0
        b = self.readByte()
        minus = False
        while True:
            if b == ord('-'):
                minus = True
            elif b >= ord('0') and b <= ord('9'):
                num = num * 10 + (b - ord('0'))
            else:
                return -num if minus else num
            b = self.readByte()

    def tr(self, *args):
        if not self.is_oj:
            print(*args)

    def trnz(self, *o):
        for i, x in enumerate(o):
            if x != 0:
                print(i, ':', x, end=' ')
        print()

    def trt(self, *o):
        stands = []
        for i, x in enumerate(o):
            for j in range(64):
                if x << ~j < 0:
                    stands.append(i << 6 | j)
        print(stands)

    def tf(self, *r):
        for x in r:
            print('T' if x else 'F', end=' ')
        print()

    def tf(self, *r):
        for x in r:
            for y in x:
                print('T' if y else 'F', end=' ')
            print()
        print()

    def tf(self, *r):
        for x in r:
            for y in x:
                for i in range(64):
                    print('T' if y << ~i < 0 else 'F', end=' ')
            print()

    def tf(self, *r):
        for x in r:
            for i in range(64):
                print('T' if x << ~i < 0 else 'F', end=' ')
            print()

    def invl(self, a: int) -> int:
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
        return p + mod if p < 0 else p

if __name__ == '__main__':
    f2 = F2()
    f2.main()
