from collections import defaultdict
import sys
import math
from typing import List, Tuple

input = sys.stdin.read
def iota(n: int) -> List[int]:
    return list(range(n))

def factor(x: int) -> List[Tuple[int, int]]:
    ans = []
    for i in range(2, int(math.isqrt(x)) + 1):
        if x % i == 0:
            ans.append((i, 1))
            while x //= i and x % i == 0:
                ans[-1] = (ans[-1][0], ans[-1][1] + 1)
    if x != 1:
        ans.append((x, 1))
    return ans

def divisor(x: int) -> List[int]:
    ans = []
    for i in range(1, int(math.isqrt(x)) + 1):
        if x % i == 0:
            ans.append(i)
            if i * i != x:
                ans.append(x // i)
    return ans

def zip_vector(x: List[int]) -> None:
    y = sorted(x)
    for i in range(len(x)):
        x[i] = y.index(x[i])

def popcount(x: int) -> int:
    return bin(x).count('1')

def setup_io():
    sys.stdin = open(0)
    sys.stdout = open(1)

def safe_mod(x: int, m: int) -> int:
    x %= m
    if x < 0:
        x += m
    return x

class Barrett:
    def __init__(self, m: int):
        self._m = m
        self.im = (2**64 - 1) // m + 1

    def umod(self) -> int:
        return self._m

    def mul(self, a: int, b: int) -> int:
        z = a * b
        x = (z * self.im) >> 64
        v = z - x * self._m
        if self._m <= v:
            v += self._m
        return v

def pow_mod(x: int, n: int, m: int) -> int:
    assert 0 <= n and 1 <= m
    if m == 1:
        return 0
    bt = Barrett(m)
    r = 1
    y = safe_mod(x, m)
    while n:
        if n & 1:
            r = bt.mul(r, y)
        y = bt.mul(y, y)
        n >>= 1
    return r

def inv_mod(x: int, m: int) -> int:
    assert 1 <= m
    g, im = id0(x, m)
    assert g == 1
    return im

def id0(a: int, b: int) -> Tuple[int, int]:
    a = safe_mod(a, b)
    if a == 0:
        return (b, 0)
    s, t = b, a
    m0, m1 = 0, 1
    while t:
        u = s // t
        s -= t * u
        m0 -= m1 * u
        s, t = t, s
        m0, m1 = m1, m0
    if m0 < 0:
        m0 += b // s
    return (s, m0)

def crt(r: List[int], m: List[int]) -> Tuple[int, int]:
    assert len(r) == len(m)
    n = len(r)
    r0, m0 = 0, 1
    for i in range(n):
        assert 1 <= m[i]
        r1, m1 = safe_mod(r[i], m[i]), m[i]
        if m0 < m1:
            r0, r1 = r1, r0
            m0, m1 = m1, m0
        if m0 % m1 == 0:
            if r0 % m1 != r1:
                return (0, 0)
            continue
        g, im = id0(m0, m1)
        u1 = m1 // g
        if (r1 - r0) % g:
            return (0, 0)
        x = (r1 - r0) // g % u1 * im % u1
        r0 += x * m0
        m0 *= u1
        if r0 < 0:
            r0 += m0
    return (r0, m0)

def floor_sum(n: int, m: int, a: int, b: int) -> int:
    ans = 0
    if a >= m:
        ans += (n - 1) * n * (a // m) // 2
        a %= m
    if b >= m:
        ans += n * (b // m)
        b %= m
    y_max = (a * n + b) // m
    x_max = (y_max * m - b)
    if y_max == 0:
        return ans
    ans += (n - (x_max + a - 1) // a) * y_max
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a)
    return ans

def main():
    m = int(input())
    hh = [0] * 2
    aa = [0] * 2
    xx = [0] * 2
    yy = [0] * 2
    for i in range(2):
        hh[i], aa[i], xx[i], yy[i] = map(int, input().split())

    def F(i: int) -> Tuple[int, int]:
        h, a, x, y = hh[i], aa[i], xx[i], yy[i]
        id_map = [-1] * m
        out = [0] * m
        f = False
        id_map[h] = 0
        for i in range(m + 2):
            h = (h * x + y) % m
            if id_map[h] != -1:
                if not f or out[h]:
                    return (-1, -1)
                return (i + 1 - id_map[h], id_map[a])
            else:
                id_map[h] = i + 1
                out[h] = f
                if h == a:
                    f = True

    d1, c1 = F(0)
    d2, c2 = F(1)

    for i in range(m * 3 + 1):
        for j in range(2):
            hh[j] = (hh[j] * xx[j] + yy[j]) % m
        if hh[0] == aa[0] and hh[1] == aa[1]:
            print(i + 1)
            return

    if d1 == -1 or d2 == -1:
        print(-1)
    else:
        x, y = crt([c1, c2], [d1, d2])
        if not x and not y:
            print(-1)
        else:
            M = max(c1, c2)
            if x < M:
                x += ((M - x - 1) // y + 1) * y
            print(x)

if __name__ == "__main__":
    setup_io()
    main()
