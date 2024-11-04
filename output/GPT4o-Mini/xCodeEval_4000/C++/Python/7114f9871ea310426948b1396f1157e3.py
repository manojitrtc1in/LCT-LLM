import sys
from collections import defaultdict
from math import gcd, isqrt
from functools import lru_cache

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

    @staticmethod
    def factorial(n):
        if n == 0:
            return ModNum(1)
        res = ModNum(1)
        for i in range(2, n + 1):
            res *= i
        return res

    @staticmethod
    def inverse_factorial(n):
        return ModNum.factorial(n).inv()

    @staticmethod
    def ncr(n, r):
        if r < 0 or n < r:
            return ModNum(0)
        return ModNum.factorial(n) * ModNum.inverse_factorial(r) * ModNum.inverse_factorial(n - r)

class Sieve:
    def __init__(self, max_v):
        self.max_v = max_v
        self.primes = []
        self.nums = [None] * max_v
        self.nums[1] = (float('inf'), 1, 0, 1, 1)  # least_prime, div_least_prime, lp_multiplicity, mu, phi
        for v in range(2, max_v):
            if self.nums[v] is None:
                self.nums[v] = (v, v, 1, -1, v - 1)  # prime
                self.primes.append(v)
            for p in self.primes:
                if p > self.nums[v][0] or v * p >= max_v:
                    break
                self.nums[v * p] = self.prod(v, p)

    def prod(self, my_value, p):
        least_prime, div_least_prime, lp_multiplicity, mu, phi = self.nums[my_value]
        if p < least_prime:
            return (p, my_value, 1, -mu, phi * (p - 1))
        assert p == least_prime
        return (p, my_value, lp_multiplicity + 1, 0, phi * p)

    def eliminate_least_prime(self, v):
        for _ in range(self.nums[v][2]):
            v = self.nums[v][1]
        return v

    def factor(self, v):
        res = []
        while v > 1:
            res.append((self.nums[v][0], self.nums[v][2]))
            v = self.eliminate_least_prime(v)
        return res[::-1]

MAXV = int(1e6) + 1
sv = Sieve(MAXV)

def main():
    input = sys.stdin.read
    data = input().split()
    N, K, Q = map(int, data[:3])
    a = list(map(int, data[3:3 + N]))
    q = list(map(int, data[3 + N:]))

    coeff = [ModNum() for _ in range(MAXV)]
    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += g * sv.nums[g][3]  # mu

    ans = ModNum(0)
    ct = [0] * MAXV

    for e in a:
        ct[e] += 1

    for g in range(1, MAXV):
        for m in range(2 * g, MAXV, g):
            ct[g] += ct[m]
        ans += coeff[g] * ModNum.ncr(ct[g], K)

    def intro(v):
        nonlocal ans
        for d in sv.factor(v):
            ans += coeff[d[0]] * (ModNum.ncr(ct[d[0]] + 1, K) - ModNum.ncr(ct[d[0]], K))
            ct[d[0]] += 1

    for qv in q:
        intro(qv)
        print(ans.v)

if __name__ == "__main__":
    main()
