import sys
from collections import defaultdict
from math import gcd, isqrt

class Sieve:
    def __init__(self, maxv):
        self.maxv = maxv
        self.primes = []
        self.nums = [self.ONE()] + [None] * (maxv - 1)
        for v in range(2, maxv):
            n = self.nums[v]
            if n is None:
                n = self.prod(1, v)
                self.nums[v] = n
                self.primes.append(v)
            for p in self.primes:
                if p > n[0] or v * p >= maxv:
                    break
                self.nums[v * p] = self.prod(v, p)

    @staticmethod
    def ONE():
        return (float('inf'), 1, 0, 1, 1)

    def prod(self, my_value, p):
        least_prime, div_least_prime, lp_multiplicity, mu, phi = self.nums[my_value]
        if p < least_prime:
            return (p, my_value, 1, -mu, phi * (p - 1))
        assert p == least_prime
        return (p, my_value, lp_multiplicity + 1, 0, phi * p)

    def is_prime(self, v):
        assert 0 < v < self.maxv
        return self.nums[v][0] == v

    def eliminate_least_prime(self, v):
        assert 1 < v < self.maxv
        for _ in range(self.nums[v][2]):
            v = self.nums[v][1]
        return v

    def factor(self, v):
        assert 0 < v < self.maxv
        res = []
        while v > 1:
            least_prime, _, lp_multiplicity, _, _ = self.nums[v]
            res.append((least_prime, lp_multiplicity))
            v = self.eliminate_least_prime(v)
        res.reverse()
        return res

    def for_each_divisor_unordered(self, v, f, c=1):
        assert 0 < v < self.maxv
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        for m in range(self.nums[v][2] + 1):
            for_each_divisor_unordered(w, f, c)
            c *= self.nums[v][0]

    def unordered_divisors(self, v):
        assert 0 < v < self.maxv
        res = []
        self.for_each_divisor_unordered(v, lambda d: res.append(d))
        return res

MAXV = int(1e6) + 1
sv = Sieve(MAXV)

def ncr(n, r):
    if r < 0 or n < r:
        return 0
    return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r)

def factorial(n):
    if n == 0:
        return 1
    res = 1
    for i in range(2, n + 1):
        res *= i
    return res

def inverse_factorial(n):
    return pow(factorial(n), -1, MOD)

MOD = int(1e9 + 7)

def main():
    input = sys.stdin.read
    data = input().split()
    N, K, Q = map(int, data[:3])
    a = list(map(int, data[3:3 + N]))
    q = list(map(int, data[3 + N:3 + N + Q]))

    coeff = [0] * MAXV
    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += g * sv.nums[g][3]

    ans = 0
    ct = [0] * MAXV

    def intro(v):
        nonlocal ans
        for d in sv.unordered_divisors(v):
            ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K))
            ct[d] += 1

    for v in a:
        intro(v)

    for qv in q:
        intro(qv)
        print(ans)

if __name__ == "__main__":
    main()
