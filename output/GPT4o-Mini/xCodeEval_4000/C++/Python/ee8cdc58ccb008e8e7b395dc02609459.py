import sys
from collections import defaultdict
from math import comb

MOD = 10**9 + 7

class Ring:
    def __init__(self, value=0):
        self.value = value % MOD

    def __mul__(self, other):
        return Ring(self.value * other.value % MOD)

    def __add__(self, other):
        return Ring((self.value + other.value) % MOD)

    def __sub__(self, other):
        return Ring((self.value - other.value) % MOD)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        return self.pow(MOD - 2)

    def pow(self, p):
        r = Ring(1)
        x = Ring(self.value)
        while p:
            if p & 1:
                r *= x
            x *= x
            p //= 2
        return r

    def __repr__(self):
        return str(self.value)

def fast_scan():
    return list(map(int, sys.stdin.readline().split()))

def fast_print(value):
    print(value)

def binom(n, k):
    if k > n:
        return Ring(0)
    return Ring(fact[n]) / (Ring(fact[n - k]) * Ring(fact[k]))

n = int(sys.stdin.readline())
fact = [1] * (n + 100)

for i in range(1, n + 100):
    fact[i] = fact[i - 1] * i % MOD

v = fast_scan()
cnt = defaultdict(int)

for x in v:
    for j in range(2, int(x**0.5) + 1):
        while x % j == 0 and (x // j) % j == 0:
            x //= j
            x //= j
    cnt[x] += 1

c = list(cnt.values())
dp = [Ring(0)] * (n + 10)
dp[0] = Ring(1)

for x in c:
    ndp = [Ring(0)] * (n + 10)
    for i in range(len(dp)):
        if dp[i].value:
            for j in range(x):
                dist = x - j
                ndp[i + dist] += dp[i] * binom(x - 1, j) * binom(i + dist, dist)
    dp = ndp

conds = n - len(c)
final = Ring(0)
sign = Ring(1)

for i in range(conds + 1):
    final += sign * dp[n - i]
    sign = Ring(-1) * sign

for x in c:
    final *= Ring(fact[x])

fast_print(final)
