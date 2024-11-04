import sys
from typing import List, Tuple
from collections import defaultdict

MOD = int(1e9 + 7)
MAXV = int(1e6 + 1)


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

    def __add__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v + other.v)

    def __sub__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v - other.v)

    def __mul__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v * other.v)

    def __neg__(self) -> 'modnum':
        return modnum(-self.v)

    def pow(self, e: int) -> 'modnum':
        if e < 0:
            return modnum(1) / self.pow(-e)
        if e == 0:
            return modnum(1)
        if e & 1:
            return self * self.pow(e - 1)
        return (self * self).pow(e // 2)

    def inv(self) -> 'modnum':
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
        return modnum(x + MOD if x < 0 else x)

    def __truediv__(self, other: 'modnum') -> 'modnum':
        return self * other.inv()

    @staticmethod
    def totient() -> int:
        tot = MOD
        tmp = MOD
        for p in range(2, int(tmp ** 0.5) + 1):
            if tmp % p == 0:
                tot = tot // p * (p - 1)
                while tmp % p == 0:
                    tmp //= p
        if tmp > 1:
            tot = tot // tmp * (tmp - 1)
        return tot

    @staticmethod
    def primitive_root() -> int:
        if MOD == 1:
            return 0
        if MOD == 2:
            return 1
        tot = modnum.totient()
        tmp = tot
        tot_pr = []
        for p in range(2, int(tmp ** 0.5) + 1):
            if tot % p == 0:
                tot_pr.append(p)
                while tmp % p == 0:
                    tmp //= p
        if tmp > 1:
            tot_pr.append(tmp)
        for r in range(2, MOD):
            if math.gcd(r, MOD) == 1:
                root = True
                for p in tot_pr:
                    root &= modnum(r).pow(tot // p) != 1
                if root:
                    return r
        assert False

    @staticmethod
    def generator() -> 'modnum':
        return modnum(modnum.primitive_root())

    @staticmethod
    def discrete_log(v: 'modnum') -> int:
        M = math.ceil(math.sqrt(MOD))
        table = {}
        if not table:
            e = modnum(1)
            for i in range(M):
                table[e.v] = i
                e *= modnum.generator()
        f = modnum.generator().pow(modnum.totient() - M)
        for i in range(M):
            if v.v in table:
                return table[v.v] + i * M
            v *= f
        assert False

    @staticmethod
    def unity_root(deg: int) -> 'modnum':
        assert modnum.totient() % deg == 0
        return modnum.generator().pow(modnum.totient() // deg)

    @staticmethod
    def unity_root(deg: int, pow: int) -> 'modnum':
        table = [0, 1]
        while len(table) <= deg:
            w = modnum.unity_root(len(table))
            for i in range(len(table) // 2, len(table)):
                table.append(table[i])
                table.append(table[i] * w)
        return table[deg + (deg + pow if pow < 0 else pow)]

    @staticmethod
    def factorial(n: int) -> 'modnum':
        fact = [modnum(1)]
        if len(fact) <= n:
            had = len(fact)
            fact.extend([fact[i - 1] * modnum(i) for i in range(had, n + 1)])
        return fact[n]

    @staticmethod
    def inverse_factorial(n: int) -> 'modnum':
        finv = [modnum(1)]
        if len(finv) <= n:
            had = len(finv)
            finv.extend([finv[i + 1] * modnum(i + 1) for i in range(n - 1, had - 1, -1)])
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


class Sieve:
    def __init__(self) -> None:
        self.primes = []
        self.nums = [None] * MAXV
        self.nums[1] = self.num(least_prime=MAXV, div_least_prime=1, lp_multiplicity=0, mu=1, phi=1)
        for v in range(2, MAXV):
            n = self.nums[v]
            if n is None:
                n = self.nums[1].prod(1, v)
                self.primes.append(v)
            for p in self.primes:
                if p > n.least_prime or v * p >= MAXV:
                    break
                self.nums[v * p] = n.prod(v, p)

    def is_prime(self, v: int) -> bool:
        assert 0 < v < MAXV
        return self.nums[v].least_prime == v

    def eliminate_least_prime(self, v: int) -> int:
        assert 1 < v < MAXV
        n = self.nums[v]
        for _ in range(n.lp_multiplicity):
            v = n.div_least_prime
        return v

    def factor(self, v: int) -> List[Tuple[int, int]]:
        assert 0 < v < MAXV
        res = []
        while v > 1:
            n = self.nums[v]
            res.append((n.least_prime, n.lp_multiplicity))
            v = self.eliminate_least_prime(v)
        return res

    def id0(self, v: int, f: 'Callable[[int], None]', c: int = 1) -> None:
        assert 0 < v < MAXV
        if v == 1:
            f(c)
            return
        w = self.eliminate_least_prime(v)
        n = self.nums[v]
        for _ in range(n.lp_multiplicity + 1):
            self.id0(w, f, c)
            c *= n.least_prime

    def unordered_divisors(self, v: int) -> List[int]:
        assert 0 < v < MAXV
        res = []
        self.id0(v, lambda d: res.append(d))
        return res


def intro(v: int) -> None:
    global ans, ct
    for d in sv.unordered_divisors(v):
        ans += coeff[d] * (mn.ncr(ct[d] + 1, K) - mn.ncr(ct[d], K))
        ct[d] += 1


def solve(N: int, K: int, Q: int, a: List[int], q: List[int]) -> List[int]:
    global ans, ct, coeff, sv
    coeff = [modnum(0)] * MAXV
    for g in range(1, MAXV):
        for m in range(g, MAXV, g):
            coeff[m] += g * sv.nums[g].mu

    ans = modnum(0)
    ct = defaultdict(int)

    for v in a:
        intro(v)

    res = []
    for qv in q:
        intro(qv)
        res.append(int(ans))
    return res


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


def from_output_string(output_string: str) -> List[int]:
    lines = output_string.strip().split('\n')
    return [int(x) for x in lines]


def to_output_string(output: List[int]) -> str:
    res = [str(x) for x in output]
    return '\n'.join(res)


