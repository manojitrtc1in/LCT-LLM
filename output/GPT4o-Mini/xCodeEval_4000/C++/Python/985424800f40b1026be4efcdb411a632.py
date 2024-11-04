import sys
from math import gcd

MOD = 1000000007
INF = 1 << 60

def lcm(a, b):
    return a // gcd(a, b) * b

def is_prime(x):
    if x == 1:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def divisor(n):
    ret = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()
    return ret

def modpow(a, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res

def modinv(a, mod):
    return modpow(a, mod - 2, mod)

MAX = 510000
fac = [1] * MAX
finv = [1] * MAX
inv = [0] * MAX

def COMinit():
    for i in range(2, MAX):
        fac[i] = fac[i - 1] * i % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
        finv[i] = finv[i - 1] * inv[i] % MOD

class UnionFind:
    def __init__(self, n):
        self.par = [-1] * n

    def root(self, x):
        if self.par[x] < 0:
            return x
        else:
            self.par[x] = self.root(self.par[x])
            return self.par[x]

    def issame(self, x, y):
        return self.root(x) == self.root(y)

    def merge(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        if self.par[x] > self.par[y]:
            x, y = y, x
        self.par[x] += self.par[y]
        self.par[y] = x
        return True

    def size(self, x):
        return -self.par[self.root(x)]

class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.n:
            self.bit[i] += x
            i += i & -i

def digit_sum(v):
    ret = 0
    while v:
        ret += (v % 10)
        v //= 10
    return ret

def cnk(n, k):
    ret = 1
    for i in range(n - k + 1, n + 1):
        ret *= i
    for i in range(1, k + 1):
        ret //= i
    return ret

def solve():
    n, k = map(int, input().split())
    if k == 1:
        print(1)
        return
    a = [0] * 11
    a[2] = 1
    for i in range(3, 11):
        a[i] = (i - 1) * (a[i - 1] + a[i - 2])
    
    ans = 1
    for i in range(k):
        ans += cnk(n, k - i) * a[k - i]
    
    print(ans)

if __name__ == "__main__":
    sys.setrecursionlimit(10**6)
    input = sys.stdin.readline
    solve()
