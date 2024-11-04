import math

MOD = int(1e9 + 7)

class modnum:
    def __init__(self, v):
        self.v = v % MOD
        if self.v < 0:
            self.v += MOD
    
    def __int__(self):
        return self.v
    
    def __str__(self):
        return str(self.v)
    
    def __eq__(self, other):
        return self.v == other.v
    
    def __ne__(self, other):
        return self.v != other.v
    
    def __add__(self, other):
        return modnum(self.v + other.v)
    
    def __sub__(self, other):
        return modnum(self.v - other.v)
    
    def __mul__(self, other):
        return modnum(self.v * other.v)
    
    def __neg__(self):
        return modnum(MOD - self.v)
    
    def __truediv__(self, other):
        return modnum(self.v * pow(other.v, MOD - 2, MOD))
    
    def pow(self, e):
        if e < 0:
            return modnum(1) / self.pow(-e)
        if e == 0:
            return modnum(1)
        if e & 1:
            return self * self.pow(e - 1)
        return (self * self).pow(e // 2)
    
    def inv(self):
        g = MOD
        x = 0
        y = 1
        r = self.v
        while r != 0:
            q = g // r
            g, r = r, g % r
            x, y = y, x - q * y
        assert g == 1
        assert y == MOD or y == -MOD
        return x if x >= 0 else x + MOD
    
    @staticmethod
    def factorial(n):
        fact = [modnum(1)]
        for i in range(1, n + 1):
            fact.append(fact[i - 1] * modnum(i))
        return fact
    
    @staticmethod
    def inverse_factorial(n):
        finv = [modnum(1)]
        for i in range(n - 1, -1, -1):
            finv.append(finv[-1] * modnum(i + 1))
        finv.reverse()
        return finv
    
    @staticmethod
    def ncr(n, r):
        if r < 0 or n < r:
            return modnum(0)
        return modnum.factorial(n) * modnum.inverse_factorial(r) * modnum.inverse_factorial(n - r)

class sieve:
    def __init__(self, MAXV):
        self.primes = []
        self.nums = [self.num() for _ in range(MAXV)]
        self.nums[1] = self.num.ONE()
        for v in range(2, MAXV):
            n = self.nums[v]
            if not n.least_prime:
                n = self.nums[1].prod(1, v)
                self.primes.append(v)
            for p in self.primes:
                if p > n.least_prime or v * p >= MAXV:
                    break
                self.nums[v * p] = n.prod(v, p)
    
    def is_prime(self, v):
        assert 0 < v < len(self.nums)
        return self.nums[v].least_prime == v
    
    def eliminate_least_prime(self, v):
        assert 1 < v < len(self.nums)
        while True:
            m = self.nums[v].lp_multiplicity
            if m == 0:
                return v
            v = self.nums[v].div_least_prime
    
    def factor(self, v):
        assert 0 < v < len(self.nums)
        res = []
        while v > 1:
            res.append((self.nums[v].least_prime, self.nums[v].lp_multiplicity))
            v = self.eliminate_least_prime(v)
        return res
    
    def for_each_divisor_unordered(self, v, f, c = 1):
        assert 0 < v < len(self.nums)
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        for m in range(self.nums[v].lp_multiplicity + 1):
            self.for_each_divisor_unordered(w, f, c)
            c *= self.nums[v].least_prime
    
    def unordered_divisors(self, v):
        assert 0 < v < len(self.nums)
        res = []
        self.for_each_divisor_unordered(v, lambda d: res.append(d))
        return res

class num:
    def __init__(self):
        self.least_prime = 0
        self.div_least_prime = 0
        self.lp_multiplicity = 0
        self.mu = 0
        self.phi = 0
    
    @staticmethod
    def ONE():
        n = num()
        n.least_prime = int(1e9)
        n.div_least_prime = 1
        n.lp_multiplicity = 0
        n.mu = 1
        n.phi = 1
        return n
    
    def prod(self, my_value, p):
        if p < self.least_prime:
            n = num()
            n.least_prime = p
            n.div_least_prime = my_value
            n.lp_multiplicity = 1
            n.mu = -self.mu
            n.phi = self.phi * (p - 1)
            return n
        assert p == self.least_prime
        n = num()
        n.least_prime = p
        n.div_least_prime = my_value
        n.lp_multiplicity = self.lp_multiplicity + 1
        n.mu = 0
        n.phi = self.phi * p
        return n

MAXV = int(1e6 + 1)
sv = sieve(MAXV)

def main():
    N, K, Q = map(int, input().split())
    a = list(map(int, input().split()))
    q = list(map(int, input().split()))
    
    ans = modnum(0)
    ct = [0] * MAXV
    coeff = [modnum(0)] * MAXV
    
    for e in a:
        ct[e] += 1
    
    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            c = 1
            for i in range(g, m + 1, g):
                coeff[m] += g * sv[i].mu
                if i > g:
                    ct[g] += ct[i]
        ans += coeff[g] * modnum.ncr(ct[g], K)
    
    for qv in q:
        for d in sv.unordered_divisors(qv):
            ans += coeff[d] * (modnum.ncr(ct[d] + 1, K) - modnum.ncr(ct[d], K))
            ct[d] += 1
        print(ans)

if __name__ == "__main__":
    main()
