from collections import defaultdict
from math import gcd, isqrt
from sys import stdin, stdout
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
        if e == 0:
            return ModNum(1)
        if e % 2 == 1:
            return self * self.pow(e - 1)
        half = self.pow(e // 2)
        return half * half

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
    def __init__(self, maxv):
        self.maxv = maxv
        self.primes = []
        self.nums = [None] * maxv
        self.nums[1] = (float('inf'), 1, 0, 1, 1)
        for v in range(2, maxv):
            if self.nums[v] is None:
                self.nums[v] = (v, 1, 1, -1, v - 1)
                self.primes.append(v)
            for p in self.primes:
                if p > self.nums[v][0] or v * p >= maxv:
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

    def unordered_divisors(self, v):
        res = []
        self.id0(v, lambda d: res.append(d))
        return res

    def id0(self, v, f, c=1):
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        for m in range(self.nums[v][2] + 1):
            self.id0(w, f, c)
            c *= self.nums[v][0]

MAXV = int(1e6) + 1
sv = Sieve(MAXV)

def main():
    input = stdin.read
    data = input().split()
    idx = 0
    N = int(data[idx])
    K = int(data[idx + 1])
    Q = int(data[idx + 2])
    idx += 3
    a = list(map(int, data[idx:idx + N]))
    idx += N
    q = list(map(int, data[idx:idx + Q]))

    coeff = [ModNum() for _ in range(MAXV)]
    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += ModNum(g) * sv.nums[g][3]

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

    output = []
    for qv in q:
        intro(qv)
        output.append(str(ans))

    stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    main()
