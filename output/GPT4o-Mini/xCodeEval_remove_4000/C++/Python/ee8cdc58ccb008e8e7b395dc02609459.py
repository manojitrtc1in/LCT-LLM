from collections import deque, defaultdict
import sys
import math

MAXMEM = 200 * 1000 * 1024
_memory = bytearray(MAXMEM)
_ptr = 0

def fast_scan_int():
    return int(sys.stdin.readline().strip())

def fast_scan_long():
    return int(sys.stdin.readline().strip())

def fast_scan_unsigned_long():
    return int(sys.stdin.readline().strip())

def fast_scan_double():
    return float(sys.stdin.readline().strip())

def fast_scan_string():
    return sys.stdin.readline().strip()

def fast_print(x):
    sys.stdout.write(str(x))

def floor_mod(a, b):
    a %= b
    if a < 0:
        a += b
    return a

MOD = 10**9 + 7

class Ring:
    def __init__(self, value=0):
        self.value = floor_mod(value, MOD)

    def __mul__(self, other):
        return Ring(floor_mod(self.value * other.value, MOD))

    def __add__(self, other):
        return Ring(floor_mod(self.value + other.value, MOD))

    def __sub__(self, other):
        return Ring(floor_mod(self.value - other.value, MOD))

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

fact = [Ring(1)]

def binom(n, k):
    if k > n:
        return Ring(0)
    return fact[n] / (fact[n - k] * fact[k])

n = fast_scan_int()
for i in range(n + 100):
    fact.append(fact[-1] * Ring(i + 1))

v = [fast_scan_int() for _ in range(n)]

for i in range(n):
    for j in range(2, int(math.sqrt(v[i])) + 1):
        while v[i] % j == 0 and (v[i] // j) % j == 0:
            v[i] //= j
            v[i] //= j

cnt = defaultdict(int)
for x in v:
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
    final *= fact[x]

fast_print(final)
