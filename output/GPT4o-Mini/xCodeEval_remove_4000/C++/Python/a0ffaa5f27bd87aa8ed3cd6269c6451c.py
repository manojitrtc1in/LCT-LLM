class Scanner:
    def __init__(self, fp):
        self.fd = fp.fileno()
        self.line = bytearray(1 << 15)
        self.st = 0
        self.ed = 0
        self.eof = False

    def read(self):
        pass

    def read_single(self, ref):
        if not self.skip_space():
            return False
        ref.clear()
        while True:
            c = self.top()
            if c <= 32:
                break
            ref.append(c)
            self.st += 1
        return True

    def skip_space(self, token_len=0):
        while True:
            while self.st != self.ed and self.line[self.st] <= 32:
                self.st += 1
            if self.ed - self.st > token_len:
                return True
            for i in range(self.st, self.ed):
                if self.line[i] <= 32:
                    return True
            if not self.reread():
                return False

    def reread(self):
        if self.ed - self.st >= 50:
            return True
        if self.st > len(self.line) // 2:
            self.line[:self.ed - self.st] = self.line[self.st:self.ed]
            self.ed -= self.st
            self.st = 0
        if self.eof:
            return False
        u = os.read(self.fd, len(self.line) - self.ed)
        if u == 0:
            self.eof = True
            self.line[self.ed] = 0
            u = 1
        self.ed += u
        return True

    def top(self):
        if self.st == self.ed:
            self.reread()
        return self.line[self.st]

import sys
from collections import defaultdict

class Printer:
    def __init__(self, fp):
        self.fd = fp.fileno()
        self.line = bytearray(1 << 15)
        self.pos = 0

    def flush(self):
        os.write(self.fd, self.line[:self.pos])
        self.pos = 0

    def write_single(self, val):
        if self.pos == len(self.line):
            self.flush()
        self.line[self.pos] = val
        self.pos += 1

    def writeln(self, *args):
        for arg in args:
            self.write_single(arg)
        self.write_single(b'\n')

def modint_set_mod(mod):
    global MOD
    MOD = mod

class ModInt:
    def __init__(self, v=0):
        self._v = v % MOD

    def __add__(self, other):
        return ModInt(self._v + other._v)

    def __sub__(self, other):
        return ModInt(self._v - other._v)

    def __mul__(self, other):
        return ModInt(self._v * other._v)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        return self.pow(MOD - 2)

    def pow(self, n):
        assert n >= 0
        x = self
        r = ModInt(1)
        while n:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r

    def val(self):
        return self._v

def binomial_coeff(n, k):
    if k > n or k < 0:
        return ModInt(0)
    if k == 0 or k == n:
        return ModInt(1)
    return C[n][k]

n, m, mod = map(int, sys.stdin.readline().split())
modint_set_mod(mod)

C = [[ModInt(0) for _ in range(n + 1)] for _ in range(n + 1)]
C[0][0] = ModInt(1)
for i in range(1, n + 1):
    C[i][0] = ModInt(1)
    for j in range(1, n + 1):
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

g = [ModInt(0) for _ in range(n + 1)]
for i in range(n + 1):
    g[i] = ModInt(i * (i + 1) // 2)

f = [(ModInt(0), ModInt(0)) for _ in range(n + 1)]
f[0] = (ModInt(1), ModInt(0))

for i in range(1, n + 1):
    for j in range(i):
        z = f[j][0] * f[i - 1 - j][0] * C[i - 1][j]
        f[i] = (f[i][0] + z * ModInt(i + 1), f[i][1] + z * (g[j] + g[i - 1 - j]))
        f[i] = (f[i][0], f[i][1] + (f[i - 1 - j][0] * f[j][1] + f[j][0] * f[i - 1 - j][1]) * C[i - 1][j] * ModInt(i + 1))

dp = [[(ModInt(0), ModInt(0)) for _ in range(m + 1)] for _ in range(n + 2)]
dp[0][0] = (ModInt(1), ModInt(0))

for l in range(n + 1):
    for r in range(l + 1, n + 2):
        di = r - l - 1
        for i in range(m + 1 - di):
            z = dp[l][i][0] * f[di][0]
            dp[r][i + di] = (dp[r][i + di][0] + z * binomial_coeff(i + di, di),
                             dp[r][i + di][1] + (dp[l][i][1] * f[di][0] + dp[l][i][0] * f[di][1]) * binomial_coeff(i + di, di))

print(dp[n + 1][m][1].val())
