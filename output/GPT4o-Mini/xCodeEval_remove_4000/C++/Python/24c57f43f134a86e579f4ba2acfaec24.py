from collections import defaultdict
import sys
import math
from functools import lru_cache

input = sys.stdin.read
def setIO():
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

class ModNum:
    def __init__(self, v=0, MOD=int(1e9 + 7)):
        self.MOD = MOD
        self.v = v % MOD
        if self.v < 0:
            self.v += MOD

    def __int__(self):
        return self.v

    def __add__(self, other):
        return ModNum(self.v + other.v, self.MOD)

    def __sub__(self, other):
        return ModNum(self.v - other.v, self.MOD)

    def __mul__(self, other):
        return ModNum(self.v * other.v, self.MOD)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        return self.pow(self.MOD - 2)

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
    def __init__(self, MAXV):
        self.MAXV = MAXV
        self.primes = []
        self.nums = [self.ONE()] + [None] * (MAXV - 1)
        for v in range(2, MAXV):
            n = self.nums[v]
            if n is None:
                self.nums[v] = self.prod(1, v)
                self.primes.append(v)
            for p in self.primes:
                if p > n.least_prime or v * p >= MAXV:
                    break
                self.nums[v * p] = n.prod(v, p)

    @staticmethod
    def ONE():
        return {'least_prime': float('inf'), 'div_least_prime': 1, 'lp_multiplicity': 0, 'mu': 1, 'phi': 1}

    def prod(self, my_value, p):
        if p < self.least_prime:
            return {'least_prime': p, 'div_least_prime': my_value, 'lp_multiplicity': 1, 'mu': -self.mu, 'phi': self.phi * (p - 1)}
        assert p == self.least_prime
        return {'least_prime': p, 'div_least_prime': my_value, 'lp_multiplicity': self.lp_multiplicity + 1, 'mu': 0, 'phi': self.phi * p}

    def eliminate_least_prime(self, v):
        for _ in range(self.nums[v]['lp_multiplicity']):
            v = self.nums[v]['div_least_prime']
        return v

    def factor(self, v):
        res = []
        while v > 1:
            res.append((self.nums[v]['least_prime'], self.nums[v]['lp_multiplicity']))
            v = self.eliminate_least_prime(v)
        return res[::-1]

    def unordered_divisors(self, v):
        res = []
        self.id0(v, lambda d: res.append(d))
        return res

    def id0(self, v, f, c=1):
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        for m in range(self.nums[v]['lp_multiplicity'] + 1):
            self.id0(w, f, c)
            c *= self.nums[v]['least_prime']

MAXV = int(1e6 + 1)
sv = Sieve(MAXV)

def main():
    setIO()
    N, K, Q = map(int, input().split())
    a = list(map(int, input().split()))
    q = list(map(int, input().split()))

    coeff = [ModNum(0) for _ in range(MAXV)]
    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += g * sv.nums[g]['mu']

    ans = ModNum(0)
    ct = [0] * MAXV

    def intro(v):
        nonlocal ans
        for d in sv.factor(v):
            ans += coeff[d[0]] * (ModNum.ncr(ct[d[0]] + 1, K) - ModNum.ncr(ct[d[0]], K))
            ct[d[0]] += 1

    for v in a:
        intro(v)

    for qv in q:
        intro(qv)
        print(ans)

if __name__ == "__main__":
    main()
