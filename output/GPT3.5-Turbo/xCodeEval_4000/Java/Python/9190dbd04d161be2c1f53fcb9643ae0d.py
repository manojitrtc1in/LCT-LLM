import sys
from typing import List

class FastWriter:
    def __init__(self, out=sys.stdout):
        self.out = out
        self.buf = []
    
    def write(self, b):
        self.buf.append(b)
    
    def write_char(self, c):
        self.write(ord(c))
    
    def write_str(self, s):
        for c in s:
            self.write_char(c)
    
    def write_int(self, x):
        if x == 0:
            self.write_char(ord('0'))
            return
        
        if x < 0:
            self.write_char(ord('-'))
            x = -x
        
        digits = []
        while x > 0:
            digits.append(chr(ord('0') + x % 10))
            x //= 10
        
        for i in range(len(digits) - 1, -1, -1):
            self.write_char(ord(digits[i]))
    
    def write_long(self, x):
        if x == 0:
            self.write_char(ord('0'))
            return
        
        if x < 0:
            self.write_char(ord('-'))
            x = -x
        
        digits = []
        while x > 0:
            digits.append(chr(ord('0') + x % 10))
            x //= 10
        
        for i in range(len(digits) - 1, -1, -1):
            self.write_char(ord(digits[i]))
    
    def write_double(self, x, precision):
        if x < 0:
            self.write_char(ord('-'))
            x = -x
        
        x += 10 ** -precision / 2
        
        self.write_long(int(x))
        self.write_char(ord('.'))
        
        x -= int(x)
        for _ in range(precision):
            x *= 10
            self.write_char(ord('0') + int(x))
            x -= int(x)
    
    def writeln(self):
        self.write_char(ord('\n'))
    
    def flush(self):
        self.out.write(''.join(map(chr, self.buf)))
        self.out.flush()

class F2:
    def __init__(self):
        self.INPUT = ""
        self.mod = 998244353
        self.G = 3
    
    def solve(self):
        n = self.ni()
        g = [[False] * 10 for _ in range(10)]
        m = self.ni()
        for _ in range(m):
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
        
        dp = [0] * (1 << 9)
        dp[0] = 1
        for i in range(1, n + 1):
            ndp = [0] * (1 << 9)
            for j in range(1 << 9):
                for k in range(10):
                    if j << ~k >= 0:
                        nj = njs[j][k]
                        ndp[nj] += dp[j]
                        if ndp[nj] >= self.mod:
                            ndp[nj] -= self.mod
            dp = ndp
        
        ans = sum(dp) % self.mod
        self.out.println(ans)
    
    def sum(self, a: List[int]) -> int:
        return sum(a)
    
    def mul(self, a: List[int], b: List[int]) -> List[int]:
        if len(a) == 0 and len(b) == 0:
            return []
        if len(a) + len(b) >= 300:
            return self.mul_convolve(a, b)
        else:
            return self.mul_naive(a, b)
    
    def mul_convolve(self, a: List[int], b: List[int]) -> List[int]:
        m = max(2, (1 << (a + b).bit_length()) << 2)
        wps = [0] * m
        unit = self.pow(self.G, (self.mod - 1) // m)
        wps[0] = 1
        for p in range(1, m):
            wps[p] = wps[p - 1] * unit % self.mod
        
        fa = self.go(a, m, False)
        fb = fa if a == b else self.go(b, m, False)
        for i in range(m):
            fa[i] = fa[i] * fb[i] % self.mod
        fa = self.go(fa, m, True)
        fa[1:] = fa[-1:0:-1]
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
        while n >= 4:
            m = n // 2
            for p in range(m):
                wp = self.wps[s * p]
                wk = (wp << 32) // self.mod
                for q in range(s):
                    a = X[q + s * (p + 0)]
                    b = X[q + s * (p + m)]
                    ndsts = a + b
                    if ndsts >= 2 * self.mod:
                        ndsts -= 2 * self.mod
                    T = a - b + 2 * self.mod
                    Q = wk * T >> 32
                    Y[q + s * (2 * p + 0)] = ndsts
                    Y[q + s * (2 * p + 1)] = wp * T - Q * self.mod & ((1 << 32) - 1)
            s *= 2
            eo = not eo
            X, Y = Y, X
        
        z = Y if eo else X
        for q in range(s):
            a = X[q + 0]
            b = X[q + s]
            z[q + 0] = (a + b) % self.mod
            z[q + s] = (a - b + 2 * self.mod) % self.mod
    
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
    
    def ni(self) -> int:
        return int(input())
    
    def nl(self) -> int:
        return int(input())
    
    def solve_problem(self):
        n = self.ni()
        self.out = FastWriter()
        self.solve()
        self.out.flush()

if __name__ == "__main__":
    f2 = F2()
    f2.solve_problem()
