import sys
from typing import List, Tuple

MOD = int(1e9 + 7)

class modnum:
    def __init__(self, v: int):
        self.v = v % MOD
        if self.v < 0:
            self.v += MOD
    
    def __int__(self) -> int:
        return self.v
    
    def __str__(self) -> str:
        return str(self.v)
    
    def __eq__(self, other: 'modnum') -> bool:
        return self.v == other.v
    
    def __ne__(self, other: 'modnum') -> bool:
        return self.v != other.v
    
    def __neg__(self) -> 'modnum':
        return modnum(MOD - self.v)
    
    def __add__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v + other.v)
    
    def __sub__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v - other.v)
    
    def __mul__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v * other.v)
    
    def __truediv__(self, other: 'modnum') -> 'modnum':
        return self * other.inv()
    
    def __iadd__(self, other: 'modnum') -> 'modnum':
        self.v += other.v
        if self.v >= MOD:
            self.v -= MOD
        return self
    
    def __isub__(self, other: 'modnum') -> 'modnum':
        self.v -= other.v
        if self.v < 0:
            self.v += MOD
        return self
    
    def __imul__(self, other: 'modnum') -> 'modnum':
        self.v = (self.v * other.v) % MOD
        return self
    
    def __itruediv__(self, other: 'modnum') -> 'modnum':
        return self * other.inv()
    
    def pow(self, e: int) -> 'modnum':
        if e < 0:
            return modnum(1) / self.pow(-e)
        if e == 0:
            return modnum(1)
        if e & 1:
            return self * self.pow(e-1)
        return (self * self).pow(e // 2)
    
    def inv(self) -> 'modnum':
        g = MOD
        x = 0
        y = 1
        r = self.v
        while r != 0:
            q = g // r
            g, r = r, g - q * r
            x, y = y, x - q * y
        
        assert g == 1
        assert y == MOD or y == -MOD
        return modnum(x + MOD if x < 0 else x)
    
    @staticmethod
    def factorial(n: int) -> 'modnum':
        fact = [modnum(1)]
        if len(fact) <= n:
            for i in range(len(fact), n+1):
                fact.append(fact[i-1] * modnum(i))
        return fact[n]
    
    @staticmethod
    def inverse_factorial(n: int) -> 'modnum':
        finv = [modnum(1)]
        if len(finv) <= n:
            for i in range(len(finv), n+1):
                finv.append(finv[i-1] * modnum(i).inv())
        return finv[n]
    
    @staticmethod
    def small_inv(n: int) -> 'modnum':
        assert n > 0
        return modnum.factorial(n - 1) * modnum.inverse_factorial(n)
    
    @staticmethod
    def ncr(n: int, r: int) -> 'modnum':
        if r < 0 or n < r:
            return modnum(0)
        return modnum.factorial(n) * modnum.inverse_factorial(r) * modnum.inverse_factorial(n - r)

def intro(v: int, ct: List[int], coeff: List[modnum]) -> modnum:
    ans = modnum(0)
    for d in sv.unordered_divisors(v):
        ans += coeff[d] * (modnum.ncr(ct[d] + 1, K) - modnum.ncr(ct[d], K))
        ct[d] += 1
    return ans

def solve(N: int, K: int, Q: int, a: List[int], q: List[int]) -> List[modnum]:
    coeff = [modnum(0) for _ in range(MAXV)]
    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += g * sv[m // g].mu
    
    ans = modnum(0)
    ct = [0] * MAXV
    
    res = []
    for v in a:
        ans += intro(v, ct, coeff)
    
    res.append(ans)
    
    for qv in q:
        ans += intro(qv, ct, coeff)
        res.append(ans)
    
    return res

MAXV = int(1e6 + 1)
sv = sieve(MAXV)

def from_input_string(input_string: str) -> Tuple[int, int, int, List[int], List[int]]:
    lines = input_string.strip().split('\n')
    N, K, Q = map(int, lines[0].strip().split())
    a = list(map(int, lines[1].strip().split()))
    q = list(map(int, lines[2].strip().split()))
    return N, K, Q, a, q

def to_input_string(inputs: Tuple[int, int, int, List[int], List[int]]) -> str:
    N, K, Q, a, q = inputs
    res = []
    res.append(f"{N} {K} {Q}")
    res.append(' '.join(str(x) for x in a))
    res.append(' '.join(str(x) for x in q))
    return '\n'.join(res)

def from_output_string(output_string: str) -> List[modnum]:
    lines = output_string.strip().split('\n')
    return [modnum(int(x)) for x in lines]

def to_output_string(output: List[modnum]) -> str:
    res = [str(x) for x in output]
    return '\n'.join(res)
