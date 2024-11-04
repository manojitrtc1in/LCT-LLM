import math

MAXV = 1000001

class Sieve:
    def __init__(self):
        self.nums = [None] * MAXV
        self.primes = []
        self.nums[1] = self.Num(0, 1, 0, 1, 1)
        
        for v in range(2, MAXV):
            n = self.nums[v]
            if n is None:
                n = self.Num(v, v, 1, -1, v - 1)
                self.primes.append(v)
            for p in self.primes:
                if p > n.least_prime or v * p >= MAXV:
                    break
                self.nums[v * p] = n.prod(v, p)
    
    def is_prime(self, v):
        return self.nums[v].least_prime == v
    
    def eliminate_least_prime(self, v):
        n = self.nums[v]
        for m in range(n.lp_multiplicity, 0, -1):
            v = n.div_least_prime
        return v
    
    def factor(self, v):
        res = []
        while v > 1:
            n = self.nums[v]
            res.append((n.least_prime, n.lp_multiplicity))
            v = self.eliminate_least_prime(v)
        return res
    
    def for_each_divisor_unordered(self, v, f, c = 1):
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        for m in range(n.lp_multiplicity + 1):
            self.for_each_divisor_unordered(w, f, c)
            c *= n.least_prime
    
    def unordered_divisors(self, v):
        res = []
        self.for_each_divisor_unordered(v, lambda d: res.append(d))
        return res
    
    class Num:
        def __init__(self, least_prime, div_least_prime, lp_multiplicity, mu, phi):
            self.least_prime = least_prime
            self.div_least_prime = div_least_prime
            self.lp_multiplicity = lp_multiplicity
            self.mu = mu
            self.phi = phi
            
        def prod(self, my_value, p):
            if p < self.least_prime:
                return self.Num(p, my_value, 1, -self.mu, self.phi * (p - 1))
            return self.Num(p, my_value, self.lp_multiplicity + 1, 0, self.phi * p)

sv = Sieve()

class ModNum:
    def __init__(self, v):
        self.v = v % (10**9 + 7)
        if self.v < 0:
            self.v += (10**9 + 7)
    
    def __int__(self):
        return self.v
    
    def __eq__(self, other):
        return self.v == other.v
    
    def __ne__(self, other):
        return self.v != other.v
    
    def __add__(self, other):
        return ModNum(self.v + other.v)
    
    def __sub__(self, other):
        return ModNum(self.v - other.v)
    
    def __mul__(self, other):
        return ModNum(self.v * other.v)
    
    def __neg__(self):
        return ModNum(-(self.v))
    
    def __pow__(self, e):
        if e < 0:
            return ModNum(1) / self.pow(-e)
        if e == 0:
            return ModNum(1)
        if e & 1:
            return self * self.pow(e - 1)
        return (self * self).pow(e // 2)
    
    def __truediv__(self, other):
        return self * other.inv()
    
    def inv(self):
        g = 10**9 + 7
        x, y = 0, 1
        a, b = self.v, g
        while a != 0:
            q, a, b = b // a, b % a, a
            x, y = y - q * x, x
        assert b == 1
        assert y == g or y == -g
        return ModNum(x) if x >= 0 else ModNum(x + g)
    
    def __str__(self):
        return str(self.v)
    
    def __repr__(self):
        return str(self.v)

def ncr(n, r):
    if r < 0 or n < r:
        return ModNum(0)
    return ModNum(factorial(n)) * ModNum(inverse_factorial(r)) * ModNum(inverse_factorial(n - r))

def factorial(n):
    fact = [ModNum(1)]
    if len(fact) <= n:
        for i in range(len(fact), n + 1):
            fact.append(fact[i - 1] * ModNum(i))
    return fact[n]

def inverse_factorial(n):
    finv = [ModNum(1)]
    if len(finv) <= n:
        for i in range(len(finv), n + 1):
            finv.append(finv[i - 1] * ModNum(i).inv())
    return finv[n]

def small_inv(n):
    assert n > 0
    return factorial(n - 1) * inverse_factorial(n)

def intro(v):
    for d in sv.unordered_divisors(v):
        ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K))
        ct[d] += 1

N, K, Q = map(int, input().split())
a = list(map(int, input().split()))
q = list(map(int, input().split()))

coeff = [ModNum(0)] * MAXV
for g in range(1, MAXV):
    for m in range(g, MAXV, g):
        coeff[g] += ModNum(g) * ModNum(sv.nums[m].mu)

ans = ModNum(0)
ct = [0] * MAXV
for e in a:
    ct[e] += 1
for g in range(1, MAXV):
    for m in range(2 * g, MAXV, g):
        ct[g] += ct[m]
    ans += coeff[g] * ncr(ct[g], K)

for qv in q:
    intro(qv)
    print(ans)
