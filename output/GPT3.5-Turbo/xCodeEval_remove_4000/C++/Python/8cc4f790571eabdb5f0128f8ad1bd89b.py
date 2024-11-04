import sys
from typing import List, Tuple
from fractions import Fraction
from math import gcd

class Frac:
    def __init__(self, n: int, d: int = 1):
        assert n != 0 or d != 0
        if d < 0:
            n *= -1
            d *= -1
        g = gcd(abs(n), d)
        self.n = n // g
        self.d = d // g

    def __str__(self) -> str:
        return f"{self.n}/{self.d}"

    def __eq__(self, other: 'Frac') -> bool:
        return self.n * other.d == self.d * other.n

    def __ne__(self, other: 'Frac') -> bool:
        return self.n * other.d != self.d * other.n

    def __lt__(self, other: 'Frac') -> bool:
        return self.n * other.d < self.d * other.n

    def __le__(self, other: 'Frac') -> bool:
        return self.n * other.d <= self.d * other.n

    def __gt__(self, other: 'Frac') -> bool:
        return self.n * other.d > self.d * other.n

    def __ge__(self, other: 'Frac') -> bool:
        return self.n * other.d >= self.d * other.n

    def __add__(self, other: 'Frac') -> 'Frac':
        return Frac(self.n * other.d + other.n * self.d, self.d * other.d)

    def __sub__(self, other: 'Frac') -> 'Frac':
        return Frac(self.n * other.d - other.n * self.d, self.d * other.d)

    def __mul__(self, other: 'Frac') -> 'Frac':
        return Frac(self.n * other.n, self.d * other.d)

    def __truediv__(self, other: 'Frac') -> 'Frac':
        return Frac(self.n * other.d, self.d * other.n)

    def __pos__(self) -> 'Frac':
        return self

    def __neg__(self) -> 'Frac':
        return Frac(-self.n, self.d)

    def __float__(self) -> float:
        return float(self.n) / self.d

    def floor(self) -> int:
        return self.n // self.d - (self.n < 0 and self.n % self.d != 0)

    def ceil(self) -> int:
        return self.n // self.d + (self.n > 0 and self.n % self.d != 0)

    def to_cont(self) -> List[int]:
        if self.d == 0:
            return [0]
        cont = []
        n, d = self.n, self.d
        while True:
            f = (n // d) if n >= 0 else (n - d + 1) // d
            cont.append(f)
            n -= f * d
            if n == 0:
                break
            n, d = d, n
        return cont

    @staticmethod
    def from_cont(cont: List[int]) -> 'Frac':
        n, d = 1, 0
        for i in range(len(cont) - 1, -1, -1):
            n, d = d, n
            n += d * cont[i]
        return Frac(n, d)

    @staticmethod
    def best_in(x: 'Frac', y: 'Frac') -> 'Frac':
        assert x < y
        x1 = x.to_cont()
        y1 = y.to_cont()
        x2 = x1[:]
        x2[-1] -= 1
        x2.append(1)
        y2 = y1[:]
        y2[-1] -= 1
        y2.append(1)

        def z(a: List[int], b: List[int]) -> 'Frac':
            c = []
            for i in range(max(len(a), len(b))):
                ai = a[i] if i < len(a) else 0
                bi = b[i] if i < len(b) else 0
                if ai != bi:
                    c.append(min(ai, bi) + 1)
                    return Frac.from_cont(c)
                c.append(ai)
            return Frac.from_cont(c)

        ans = Frac(1, 0)
        for f in [z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)]:
            if x < f and f < y and (ans.d == 0 or f.d < ans.d):
                ans = f
        return ans


class ModNum:
    def __init__(self, v: int):
        self.v = v % ModNum.MOD
        if self.v < 0:
            self.v += ModNum.MOD

    def __str__(self) -> str:
        return str(self.v)

    def __eq__(self, other: 'ModNum') -> bool:
        return self.v == other.v

    def __ne__(self, other: 'ModNum') -> bool:
        return self.v != other.v

    def __add__(self, other: 'ModNum') -> 'ModNum':
        return ModNum((self.v + other.v) % ModNum.MOD)

    def __sub__(self, other: 'ModNum') -> 'ModNum':
        return ModNum((self.v - other.v) % ModNum.MOD)

    def __mul__(self, other: 'ModNum') -> 'ModNum':
        return ModNum((self.v * other.v) % ModNum.MOD)

    def __pos__(self) -> 'ModNum':
        return self

    def __neg__(self) -> 'ModNum':
        return ModNum(ModNum.MOD - self.v)

    def __pow__(self, e: int) -> 'ModNum':
        if e < 0:
            return ModNum(1) / (self ** -e)
        if e == 0:
            return ModNum(1)
        if e & 1:
            return self * (self ** (e - 1))
        return (self * self) ** (e // 2)

    def __truediv__(self, other: 'ModNum') -> 'ModNum':
        return self * other.inv()

    def inv(self) -> 'ModNum':
        g, x, y = ModNum.MOD, 0, 1
        r = self.v
        while r != 0:
            q = g // r
            g, r = r, g - q * r
            x, y = y, x - q * y

        assert g == 1
        assert y == ModNum.MOD or y == -ModNum.MOD
        return x if x >= 0 else x + ModNum.MOD

    @staticmethod
    def totient() -> int:
        tot = ModNum.MOD
        tmp = ModNum.MOD
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
        if ModNum.MOD == 1:
            return 0
        if ModNum.MOD == 2:
            return 1

        tot = ModNum.totient()
        tmp = tot
        tot_pr = []
        for p in range(2, int(tmp ** 0.5) + 1):
            if tot % p == 0:
                tot_pr.append(p)
                while tmp % p == 0:
                    tmp //= p
        if tmp > 1:
            tot_pr.append(tmp)

        for r in range(2, ModNum.MOD):
            if gcd(r, ModNum.MOD) == 1:
                root = True
                for p in tot_pr:
                    root &= ModNum(r).pow(tot // p) != 1
                if root:
                    return r
        assert False

    @staticmethod
    def generator() -> 'ModNum':
        return ModNum.primitive_root().pow(ModNum.totient() - ModNum.M)

    @staticmethod
    def discrete_log(v: 'ModNum') -> int:
        M = ModNum.M
        table = {}
        if not table:
            e = ModNum(1)
            for i in range(M):
                table[e.v] = i
                e *= ModNum.generator()

        f = ModNum.generator().pow(ModNum.totient() - ModNum.M)

        for i in range(M):
            if v.v in table:
                return table[v.v] + i * M
            v *= f
        assert False

    @staticmethod
    def unity_root(deg: int) -> 'ModNum':
        assert ModNum.totient() % deg == 0
        return ModNum.generator().pow(ModNum.totient() // deg)

    @staticmethod
    def unity_root_pow(deg: int, pow: int) -> 'ModNum':
        table = [ModNum(0), ModNum(1)]
        while len(table) <= deg:
            w = ModNum.unity_root(len(table))
            for i in range(len(table) // 2, len(table)):
                table.append(table[i])
                table.append(table[i] * w)
        return table[deg + (deg + pow if pow < 0 else pow)]

    @staticmethod
    def factorial(n: int) -> 'ModNum':
        fact = [ModNum(1)]
        if len(fact) <= n:
            for i in range(len(fact), n + 1):
                fact.append(fact[i - 1] * ModNum(i))
        return fact[n]

    @staticmethod
    def inverse_factorial(n: int) -> 'ModNum':
        finv = [ModNum(1)]
        if len(finv) <= n:
            finv.extend([ModNum(0)] * (n - len(finv) + 1))
            finv[n] = ModNum.factorial(n).inv()
            for i in range(n - 1, len(finv) - 1, -1):
                finv[i] = finv[i + 1] * ModNum(i + 1)
        return finv[n]

    @staticmethod
    def small_inv(n: int) -> 'ModNum':
        assert n > 0
        return ModNum.factorial(n - 1) * ModNum.inverse_factorial(n)

    @staticmethod
    def ncr(n: int, r: int) -> 'ModNum':
        if r < 0 or n < r:
            return ModNum(0)
        return ModNum.factorial(n) * ModNum.inverse_factorial(r) * ModNum.inverse_factorial(n - r)

    MOD = 998244353
    M = int(MOD ** 0.5) + 1


class Pipe:
    def __init__(self, x: int, v: int, p: int):
        self.x = x
        self.v = v
        self.p = p

def solve(N: int, pipes: List[Pipe]) -> ModNum:
    evs = []
    for i in range(N - 1):
        dx = pipes[i + 1].x - pipes[i].x
        dv = pipes[i + 1].v - pipes[i].v

        evs.append((i, 'RL', Fraction(dx, pipes[i + 1].v + pipes[i].v)))

        if dv > 0:
            evs.append((i, 'LL', Fraction(dx, dv)))
        if dv < 0:
            evs.append((i, 'RR', Fraction(dx, -dv)))

    evs.sort(key=lambda x: x[2])

    class Node:
        def __init__(self):
            self.p = [ModNum(0)] * 4
            self.noLL = False
            self.noRR = False
            self.noRL = False
            self.none = True

    def nn(a: Node, b: Node) -> Node:
        if a.none:
            return b
        if b.none:
            return a
        r = Node()
        r.none = False
        for i in range(4):
            for j in range(4):
                iF = bool(i & 1)
                iB = bool(i >> 1 & 1)
                jF = bool(j & 1)
                jB = bool(j >> 1 & 1)
                if a.noLL and not iB and not jF:
                    continue
                if a.noRR and iB and jF:
                    continue
                if a.noRL and iB and not jF:
                    continue
                r.p[iF + 2 * jB] += a.p[i] * b.p[j]
        return r

    st = [Node() for _ in range(N)]
    for i in range(N):
        pR = pipes[i].p * ModNum.small_inv(100)
        st[i].p = [ModNum(1) - pR, ModNum(0), ModNum(0), pR]
        st[i].none = False

    ans = ModNum(0)
    prob = ModNum(1)
    for e in evs:
        c = st[e[0]]
        if e[1] == 'LL':
            c.noLL = True
        elif e[1] == 'RR':
            c.noRR = True
        elif e[1] == 'RL':
            c.noRL = True
        st[e[0]] = c

        u = Node()
        for i in range(2 * N):
            u = nn(u, st[i])
        PROB = sum(u.p)
        ans += (prob - PROB) * e[2].numerator * ModNum.small_inv(e[2].denominator)
        prob = PROB

    return ans

def from_input_string(input_string: str) -> Tuple[int, List[Pipe]]:
    lines = input_string.strip().split('\n')
    N = int(lines[0])
    pipes = []
    for line in lines[1:]:
        x, v, p = map(int, line.split())
        pipes.append(Pipe(x, v, p))
    return N, pipes

def to_input_string(inputs: Tuple[int, List[Pipe]]) -> str:
    N, pipes = inputs
    res = []
    res.append(str(N))
    for pipe in pipes:
        res.append(f"{pipe.x} {pipe.v} {pipe.p}")
    return '\n'.join(res)

def from_output_string(output_string: str) -> ModNum:
    return ModNum(int(output_string.strip()))

def to_output_string(output: ModNum) -> str:
    return str(output)

