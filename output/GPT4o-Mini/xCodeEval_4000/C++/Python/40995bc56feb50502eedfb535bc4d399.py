import sys
from collections import defaultdict
from math import gcd, isqrt
from functools import lru_cache

input = sys.stdin.read
def setIO():
    input_data = input().splitlines()
    return input_data

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

    def pow(self, e):
        if e < 0:
            return 1 / self.pow(-e)
        if e == 0:
            return 1
        if e & 1:
            return self * self.pow(e - 1)
        return (self * self).pow(e // 2)

    def inv(self):
        g, x, y = self.MOD, 0, 1
        r = self.v
        while r != 0:
            q = g // r
            g, r = r, g % r
            x, y = y - q * x, x
        assert g == 1
        return ModNum(x % self.MOD, self.MOD)

    @staticmethod
    def ncr(n, r, MOD=int(1e9 + 7)):
        if r < 0 or n < r:
            return ModNum(0, MOD)
        return ModNum.factorial(n) * ModNum.inverse_factorial(r) * ModNum.inverse_factorial(n - r)

    @staticmethod
    @lru_cache(None)
    def factorial(n, MOD=int(1e9 + 7)):
        if n == 0:
            return ModNum(1, MOD)
        return ModNum(n, MOD) * ModNum.factorial(n - 1, MOD)

    @staticmethod
    @lru_cache(None)
    def inverse_factorial(n, MOD=int(1e9 + 7)):
        return ModNum.factorial(n, MOD).inv()

class Sieve:
    def __init__(self, MAXV):
        self.MAXV = MAXV
        self.primes = []
        self.nums = [self.num() for _ in range(MAXV)]
        self.nums[1] = self.num.ONE()
        for v in range(2, MAXV):
            n = self.nums[v]
            if n.least_prime == 0:
                n = self.nums[1].prod(1, v)
                self.primes.append(v)
            for p in self.primes:
                if p > n.least_prime or v * p >= MAXV:
                    break
                self.nums[v * p] = n.prod(v, p)

    class num:
        @staticmethod
        def ONE():
            return Sieve.num(INT_MAX, 1, 0, 1, 1)

        def __init__(self, least_prime=0, div_least_prime=1, lp_multiplicity=0, mu=1, phi=1):
            self.least_prime = least_prime
            self.div_least_prime = div_least_prime
            self.lp_multiplicity = lp_multiplicity
            self.mu = mu
            self.phi = phi

        def prod(self, my_value, p):
            if p < self.least_prime:
                return Sieve.num(p, my_value, 1, -self.mu, self.phi * (p - 1))
            assert p == self.least_prime
            return Sieve.num(p, my_value, self.lp_multiplicity + 1, 0, self.phi * p)

    def is_prime(self, v):
        assert 0 < v < self.MAXV
        return self.nums[v].least_prime == v

    def eliminate_least_prime(self, v):
        assert 1 < v < self.MAXV
        for _ in range(self.nums[v].lp_multiplicity):
            v = self.nums[v].div_least_prime
        return v

    def factor(self, v):
        assert 0 < v < self.MAXV
        res = []
        while v > 1:
            res.append((self.nums[v].least_prime, self.nums[v].lp_multiplicity))
            v = self.eliminate_least_prime(v)
        res.reverse()
        return res

    def for_each_divisor_unordered(self, v, f, c=1):
        assert 0 < v < self.MAXV
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        for m in range(self.nums[v].lp_multiplicity + 1):
            for_each_divisor_unordered(w, f, c)
            c *= self.nums[v].least_prime

    def unordered_divisors(self, v):
        assert 0 < v < self.MAXV
        res = []
        self.for_each_divisor_unordered(v, lambda d: res.append(d))
        return res

MAXV = int(1e6 + 1)
sv = Sieve(MAXV)

def main():
    input_data = setIO()
    N, K, Q = map(int, input_data[0].split())
    a = list(map(int, input_data[1].split()))
    q = list(map(int, input_data[2].split()))

    ans = ModNum(0)
    ct = [0] * MAXV
    coeff = [ModNum(0) for _ in range(MAXV)]

    for e in a:
        ct[e] += 1

    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += g * sv.nums[m].mu
            if m > 1:
                ct[g] += ct[m]
        ans += coeff[g] * ModNum.ncr(ct[g], K)

    for qv in q:
        sv.for_each_divisor_unordered(qv, lambda d: (
            ans += coeff[d] * (ModNum.ncr(ct[d] + 1, K) - ModNum.ncr(ct[d], K)),
            ct[d] += 1
        ))
        print(ans.v)

if __name__ == "__main__":
    main()
