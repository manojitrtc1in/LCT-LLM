import sys
from typing import List, Tuple

MOD = 998244353
INF = 1 << 30

class mint:
    def __init__(self, x: int = 0):
        self.x = x % MOD

    def __add__(self, other: 'mint') -> 'mint':
        if isinstance(other, int):
            other = mint(other)
        return mint((self.x + other.x) % MOD)

    def __sub__(self, other: 'mint') -> 'mint':
        if isinstance(other, int):
            other = mint(other)
        return mint((self.x - other.x + MOD) % MOD)

    def __mul__(self, other: 'mint') -> 'mint':
        if isinstance(other, int):
            other = mint(other)
        return mint((self.x * other.x) % MOD)

    def __truediv__(self, other: 'mint') -> 'mint':
        if isinstance(other, int):
            other = mint(other)
        return self * other.inverse()

    def __pow__(self, k: int) -> 'mint':
        res = mint(1)
        a = self
        while k > 0:
            if k & 1:
                res *= a
            a *= a
            k >>= 1
        return res

    def inverse(self) -> 'mint':
        a = self.x
        b = MOD
        u = 1
        v = 0
        while b:
            t = a // b
            a -= t * b
            a, b = b, a
            u -= t * v
            u, v = v, u
        if u < 0:
            u += MOD
        return mint(u)

    def __eq__(self, other: 'mint') -> bool:
        if isinstance(other, int):
            other = mint(other)
        return self.x == other.x

    def __ne__(self, other: 'mint') -> bool:
        if isinstance(other, int):
            other = mint(other)
        return self.x != other.x

    def __neg__(self) -> 'mint':
        return mint(-self.x)

    def __int__(self) -> int:
        return self.x

    def __str__(self) -> str:
        return str(self.x)

    def __repr__(self) -> str:
        return str(self.x)

class rational_t:
    def __init__(self, nu: int = 0, de: int = 1):
        self.nu = nu
        self.de = de
        if self.de < 0:
            self.nu = -self.nu
            self.de = -self.de

    def __add__(self, other: 'rational_t') -> 'rational_t':
        return rational_t(self.nu * other.de + self.de * other.nu, self.de * other.de)

    def __sub__(self, other: 'rational_t') -> 'rational_t':
        return rational_t(self.nu * other.de - self.de * other.nu, self.de * other.de)

    def __neg__(self) -> 'rational_t':
        return rational_t(-self.nu, self.de)

    def __mul__(self, other: 'rational_t') -> 'rational_t':
        return rational_t(self.nu * other.nu, self.de * other.de)

    def __truediv__(self, other: 'rational_t') -> 'rational_t':
        return rational_t(self.nu * other.de, self.de * other.nu)

    def __eq__(self, other: 'rational_t') -> bool:
        return self.nu * other.de == other.nu * self.de

    def __lt__(self, other: 'rational_t') -> bool:
        return self.nu * other.de < other.nu * self.de

    def __le__(self, other: 'rational_t') -> bool:
        return self.nu * other.de <= other.nu * self.de

    def __gt__(self, other: 'rational_t') -> bool:
        return self.nu * other.de > other.nu * self.de

    def __ge__(self, other: 'rational_t') -> bool:
        return self.nu * other.de >= other.nu * self.de

def solve(n: int, vpos: List[int], v: List[int], probBallDir: List[List[mint]]) -> int:
    def combine(x: Tuple[mint, mint, mint, bool], y: Tuple[mint, mint, mint, bool]) -> Tuple[mint, mint, mint, bool]:
        if x[3]:
            return y
        if y[3]:
            return x
        ans = (x[0] * y[0], x[1] * y[1], x[2] * y[2], False)
        return ans

    def getProdOfRange(l: int, r: int) -> mint:
        lo = INF
        hi = -INF
        ans = mint(1)
        for pos in range(l, r + 1):
            dat = gs.getData(pos)
            lo = min(lo, dat[0])
            hi = max(hi, dat[1])
            mult = seg.query(dat[0], dat[1])[2]
            ans *= mult
            pos = dat[1] + 1
        return ans

    def mergeFates(l: int, r: int) -> None:
        dl = gs.getDir(l)
        dr = gs.getDir(r)
        if (dl != -1 and dl != R) or (dr != -1 and dr != L):
            return
        if dl == dr:
            probNoCollide = 0
        else:
            den = getProdOfRange(l, r)
            gs.split(l, r, L, UNDEF)
            num = getProdOfRange(l, r)
            probNoCollide *= num / den

    def rat2Mint(r: rational_t) -> mint:
        return mint(r.nu) / mint(r.de)

    probNoCollide = mint(1)
    finalSum = mint(0)
    collisions = []
    for i in range(n - 1):
        dist = vpos[i + 1] - vpos[i]
        rlCollideTime = rational_t(dist, v[i + 1] + v[i])
        collisions.append((rlCollideTime, i, R, L))
        if v[i] > v[i + 1]:
            rrCollideTime = rational_t(dist, v[i] - v[i + 1])
            collisions.append((rrCollideTime, i, R, R))
        if v[i] < v[i + 1]:
            llCollideTime = rational_t(dist, v[i + 1] - v[i])
            collisions.append((llCollideTime, i, L, L))
    collisions.sort()
    for collideTime, pos, dirL, dirR in collisions:
        prevProbNoCollide = probNoCollide
        dl = gs.getDir(pos)
        dr = gs.getDir(pos + 1)
        if (dl != -1 and dl != dirL) or (dr != -1 and dr != dirR):
            continue
        if dirL == R and dirR == L:
            mergeFates(pos, pos + 1)
        elif dirL == R and dirR == R:
            if dl == R:
                probNoCollide = 0
            else:
                den = getProdOfRange(pos, pos + 1)
                gs.split(pos, pos + 1, L, UNDEF)
                num = getProdOfRange(pos, pos + 1)
                probNoCollide *= num / den
        elif dirL == L and dirR == L:
            if dr == L:
                probNoCollide = 0
            else:
                den = getProdOfRange(pos, pos + 1)
                gs.split(pos, pos + 1, UNDEF, R)
                num = getProdOfRange(pos, pos + 1)
                probNoCollide *= num / den
        else:
            assert False
        finalSum += collideTime * (prevProbNoCollide - probNoCollide)
        if probNoCollide == 0:
            break
    return int(finalSum)

def from_input_string(input_string: str) -> Tuple[int, List[int], List[int], List[List[mint]]]:
    lines = input_string.strip().split('\n')
    n = int(lines[0])
    vpos = list(map(int, lines[1].split()))
    v = list(map(int, lines[2].split()))
    probBallDir = []
    for line in lines[3:]:
        probBallDir.append(list(map(mint, line.split())))
    return n, vpos, v, probBallDir

def to_input_string(inputs: Tuple[int, List[int], List[int], List[List[mint]]]) -> str:
    n, vpos, v, probBallDir = inputs
    res = []
    res.append(str(n))
    res.append(' '.join(map(str, vpos)))
    res.append(' '.join(map(str, v)))
    for prob in probBallDir:
        res.append(' '.join(map(str, prob)))
    return '\n'.join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)

