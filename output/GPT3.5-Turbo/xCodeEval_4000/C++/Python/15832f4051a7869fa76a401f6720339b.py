import sys
from typing import List, Tuple

def floor_sum(n: int, m: int, a: int, b: int) -> int:
    ans = 0
    if a >= m:
        ans += (n - 1) * n * (a // m) // 2
        a %= m
    if b >= m:
        ans += n * (b // m)
        b %= m

    y_max = (a * n + b) // m
    x_max = y_max * m - b
    if y_max == 0:
        return ans
    ans += (n - (x_max + a - 1) // a) * y_max
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a)
    return ans

def solve(m: int, hh: List[int], aa: List[int], xx: List[int], yy: List[int]) -> int:
    def F(i: int) -> Tuple[int, int]:
        h, a, x, y = hh[i], aa[i], xx[i], yy[i]
        id = [-1] * m
        out = [0] * m
        f = False
        id[h] = 0
        for i in range(m + 2):
            h = (h * x + y) % m
            if id[h] != -1:
                if not f or out[h]:
                    return (-1, -1)
                return (i + 1 - id[h], id[a])
            else:
                id[h] = i + 1
                out[h] = f
                if h == a:
                    f = True

    d1, c1 = F(0)
    d2, c2 = F(1)
    for i in range(m * 3 + 1):
        for j in range(2):
            hh[j] = (hh[j] * xx[j] + yy[j]) % m
        if hh[0] == aa[0] and hh[1] == aa[1]:
            return i + 1

    if d1 == -1 or d2 == -1:
        return -1
    else:
        x, y = crt([c1, c2], [d1, d2])
        if not x and not y:
            return -1
        else:
            M = max(c1, c2)
            if x < M:
                x += ((M - x - 1) // y + 1) * y
            return x

def crt(r: List[int], m: List[int]) -> Tuple[int, int]:
    def inv_gcd(a: int, b: int) -> Tuple[int, int]:
        a = a % b
        if a == 0:
            return (b, 0)

        s, t = b, a
        m0, m1 = 0, 1

        while t:
            u = s // t
            s -= t * u
            m0 -= m1 * u

            tmp = s
            s = t
            t = tmp
            tmp = m0
            m0 = m1
            m1 = tmp

        if m0 < 0:
            m0 += b // s
        return (s, m0)

    n = len(r)
    r0, m0 = 0, 1
    for i in range(n):
        assert 1 <= m[i]
        r1, m1 = r[i] % m[i], m[i]
        if m0 < m1:
            r0, r1 = r1, r0
            m0, m1 = m1, m0
        if m0 % m1 == 0:
            if r0 % m1 != r1:
                return (0, 0)
            continue

        g, im = inv_gcd(m0, m1)
        u1 = m1 // g
        if (r1 - r0) % g:
            return (0, 0)
        x = (r1 - r0) // g % u1 * im % u1
        r0 += x * m0
        m0 *= u1
        if r0 < 0:
            r0 += m0
    return (r0, m0)

def main() -> None:
    m = int(input())
    hh = [0] * 2
    aa = [0] * 2
    xx = [0] * 2
    yy = [0] * 2
    for i in range(2):
        hh[i], aa[i], xx[i], yy[i] = map(int, input().split())
    result = solve(m, hh, aa, xx, yy)
    print(result)

if __name__ == "__main__":
    main()
