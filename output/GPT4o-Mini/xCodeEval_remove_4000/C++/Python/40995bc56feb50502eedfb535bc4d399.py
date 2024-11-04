import sys
from collections import defaultdict
from math import gcd, isqrt
from functools import lru_cache
from itertools import accumulate

MOD = int(1e9 + 7)

class ModNum:
    def __init__(self, v=0):
        self.v = v % MOD
        if self.v < 0:
            self.v += MOD

    def __int__(self):
        return self.v

    def __add__(self, other):
        return ModNum(self.v + other.v)

    def __sub__(self, other):
        return ModNum(self.v - other.v)

    def __mul__(self, other):
        return ModNum(self.v * other.v)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        return self.pow(MOD - 2)

    def pow(self, e):
        if e < 0:
            return 1 / self.pow(-e)
        if e == 0:
            return 1
        if e & 1:
            return self * self.pow(e - 1)
        return (self * self).pow(e // 2)

    def __repr__(self):
        return str(self.v)

def sieve(max_v):
    primes = []
    nums = [None] * max_v
    nums[1] = (float('inf'), 1, 0, 1, 1)

    for v in range(2, max_v):
        if nums[v] is None:
            nums[v] = (v, 1, 1, -1, v - 1)
            primes.append(v)
        for p in primes:
            if p > nums[v][0] or v * p >= max_v:
                break
            nums[v * p] = (nums[v][0], nums[v][1], 0, nums[v][3], nums[v][4] * p)

    return nums

def factor(nums, v):
    res = []
    while v > 1:
        res.append((nums[v][0], nums[v][2]))
        v = v // nums[v][0]
    return res[::-1]

def ncr(n, r):
    if r < 0 or n < r:
        return ModNum(0)
    return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r)

def factorial(n):
    if n == 0:
        return ModNum(1)
    if len(fact) <= n:
        fact.extend([ModNum(0)] * (n + 1 - len(fact)))
        for i in range(len(fact) - 1, n + 1):
            fact[i] = fact[i - 1] * ModNum(i)
    return fact[n]

def inverse_factorial(n):
    if n == 0:
        return ModNum(1)
    if len(finv) <= n:
        finv.extend([ModNum(0)] * (n + 1 - len(finv)))
        finv[n] = factorial(n).inv()
        for i in range(n - 1, len(finv) - 1, -1):
            finv[i] = finv[i + 1] * ModNum(i + 1)
    return finv[n]

MAXV = int(1e6) + 1
fact = [ModNum(1)]
finv = [ModNum(1)]
nums = sieve(MAXV)

def main():
    input = sys.stdin.read
    data = input().split()
    N, K, Q = map(int, data[:3])
    a = list(map(int, data[3:3 + N]))
    q = list(map(int, data[3 + N:]))

    ans = ModNum(0)
    ct = [0] * MAXV
    coeff = [ModNum(0)] * MAXV

    for e in a:
        ct[e] += 1

    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += g * nums[m][3]
            if m // g > 1:
                ct[g] += ct[m]

        ans += coeff[g] * ncr(ct[g], K)

    results = []
    for qv in q:
        for d in factor(nums, qv):
            ans += coeff[d[0]] * (ncr(ct[d[0]] + 1, K) - ncr(ct[d[0]], K))
            ct[d[0]] += 1
        results.append(ans)

    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
