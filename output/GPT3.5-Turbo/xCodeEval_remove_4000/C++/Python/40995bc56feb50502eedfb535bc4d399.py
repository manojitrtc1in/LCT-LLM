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
        return self * other.inv()
    
    def pow(self, e):
        if e < 0:
            return modnum(1) / self.pow(-e)
        if e == 0:
            return modnum(1)
        if e & 1:
            return self * self.pow(e-1)
        return (self * self).pow(e//2)
    
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
        if len(fact) <= n:
            for i in range(len(fact), n+1):
                fact.append(fact[i-1] * modnum(i))
        return fact[n]
    
    @staticmethod
    def inverse_factorial(n):
        finv = [modnum(1)]
        if len(finv) <= n:
            for i in range(n, len(finv), -1):
                finv.append(finv[i] * modnum(i+1))
        return finv[n]
    
    @staticmethod
    def small_inv(n):
        assert n > 0
        return modnum.factorial(n-1) * modnum.inverse_factorial(n)
    
    @staticmethod
    def ncr(n, r):
        if r < 0 or n < r:
            return modnum(0)
        return modnum.factorial(n) * modnum.inverse_factorial(r) * modnum.inverse_factorial(n-r)

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
        for _ in range(self.nums[v].lp_multiplicity):
            v = self.nums[v].div_least_prime
        return v
    
    def factor(self, v):
        assert 0 < v < len(self.nums)
        res = []
        while v > 1:
            res.append((self.nums[v].least_prime, self.nums[v].lp_multiplicity))
            v = self.eliminate_least_prime(v)
        res.reverse()
        return res
    
    def id0(self, v, f, c=1):
        assert 0 < v < len(self.nums)
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        for m in range(self.nums[v].lp_multiplicity + 1):
            self.id0(w, f, c)
            c *= self.nums[v].least_prime
    
    def unordered_divisors(self, v):
        assert 0 < v < len(self.nums)
        res = []
        self.id0(v, lambda d: res.append(d))
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
            return sieve.num(INT_MAX, 1, 0, 1, 1)
        
        def prod(self, my_value, p):
            if p < self.least_prime:
                return sieve.num(p, my_value, 1, -self.mu, self.phi * (p - 1))
            assert p == self.least_prime
            return sieve.num(p, my_value, self.lp_multiplicity + 1, 0, self.phi * p)

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
            for _ in range(1, m//g + 1):
                coeff[m] += g * sv.nums[c].mu
                if c > 1:
                    ct[g] += ct[m]
                c *= g
        ans += coeff[g] * modnum.ncr(ct[g], K)
    
    for qv in q:
        for d in sv.unordered_divisors(qv):
            ans += coeff[d] * (modnum.ncr(ct[d] + 1, K) - modnum.ncr(ct[d], K))
            ct[d] += 1
        print(ans)

if __name__ == "__main__":
    main()
