class Barrett:
    def __init__(self, m):
        self._m = m
        self.im = (-1 // m) + 1

    def umod(self):
        return self._m

    def mul(self, a, b):
        z = a * b
        x = (z * self.im) >> 64
        v = z - x * self._m
        if self._m <= v:
            v += self._m
        return v


def safe_mod(x, m):
    x %= m
    if x < 0:
        x += m
    return x


def id4(x, n, m):
    if m == 1:
        return 0
    _m = m
    r = 1
    y = safe_mod(x, m)
    while n:
        if n & 1:
            r = (r * y) % _m
        y = (y * y) % _m
        n >>= 1
    return r


def id1(n):
    if n <= 1:
        return False
    if n in (2, 7, 61):
        return True
    if n % 2 == 0:
        return False
    d = n - 1
    while d % 2 == 0:
        d //= 2
    bases = [2, 7, 61]
    for a in bases:
        t = d
        y = id4(a, t, n)
        while t != n - 1 and y != 1 and y != n - 1:
            y = (y * y) % n
            t <<= 1
        if y != n - 1 and t % 2 == 0:
            return False
    return True


def id2(a, b):
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


def id3(m):
    if m == 2:
        return 1
    if m in (167772161, 469762049, 998244353):
        return 3
    if m == 754974721:
        return 11
    divs = [2]
    cnt = 1
    x = (m - 1) // 2
    while x % 2 == 0:
        x //= 2
    for i in range(3, int(x**0.5) + 1, 2):
        if x % i == 0:
            divs.append(i)
            while x % i == 0:
                x //= i
            cnt += 1
    if x > 1:
        divs.append(x)
        cnt += 1
    for g in range(2, 100):
        ok = True
        for i in range(cnt):
            if id4(g, (m - 1) // divs[i], m) == 1:
                ok = False
                break
        if ok:
            return g
    return -1


class ModInt:
    def __init__(self, v=0, m=998244353):
        self._v = v % m
        self._m = m

    def val(self):
        return self._v

    def __add__(self, other):
        return ModInt((self._v + other._v) % self._m)

    def __sub__(self, other):
        return ModInt((self._v - other._v) % self._m)

    def __mul__(self, other):
        return ModInt((self._v * other._v) % self._m)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        eg = id2(self._v, self._m)
        assert eg[0] == 1
        return ModInt(eg[1], self._m)

    def pow(self, n):
        assert n >= 0
        x = self
        r = ModInt(1, self._m)
        while n:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r


def solve():
    n, m = map(int, input().split())
    ModInt._m = m

    dp = [ModInt() for _ in range(n + 1)]
    p = [ModInt() for _ in range(n + 1)]

    dp[n] = ModInt(1)
    p[n] = ModInt(1)
    for i in range(n - 1, 0, -1):
        dp[i] += p[i + 1]

        z = 2
        while z * i <= n:
            r = i * z + z
            l = z * i
            dp[i] += p[l]
            if r <= n:
                dp[i] -= p[r]
            z += 1

        p[i] = p[i + 1] + dp[i]

    print(dp[1].val())


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    solve()
