import sys
from collections import defaultdict
from math import gcd, comb
from cmath import polar, exp, pi
from random import randint

mod = 1000000007
mxN = 2000005
fac = [1] * mxN

def bpow(x, n, m=None):
    if m is None:
        return x ** n
    res = 1
    while n:
        if n % 2:
            res = res * x % m
        x = x * x % m
        n //= 2
    return res

class Modular:
    def __init__(self, r=0):
        self.r = r % mod

    def __mul__(self, other):
        return Modular(self.r * other.r % mod)

    def __truediv__(self, other):
        return self * other.inv()

    def __add__(self, other):
        return Modular(self.r + other.r)

    def __sub__(self, other):
        return Modular(self.r - other.r)

    def inv(self):
        return bpow(self.r, mod - 2)

    def __int__(self):
        return self.r

    def __repr__(self):
        return str(self.r)

for i in range(1, mxN):
    fac[i] = fac[i - 1] * i % mod

n, k = map(int, sys.stdin.readline().split())
if k >= n:
    print(0)
    sys.exit()

def C(n, m):
    return fac[n] * pow(fac[m], mod - 2, mod) * pow(fac[n - m], mod - 2, mod) % mod

ans = Modular(0)
for i in range(n - k + 1):
    sign = 1 if (n - k - i) % 2 == 0 else -1
    ans += Modular(sign) * C(n - k, i) * bpow(i, n)

print((1 + (k > 0)) * ans * C(n, n - k))
