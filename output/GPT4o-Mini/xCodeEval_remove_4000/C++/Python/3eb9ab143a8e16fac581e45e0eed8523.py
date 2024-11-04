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


def id5(x, n, m):
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


def id2(n):
    if n <= 1:
        return False
    if n in {2, 7, 61}:
        return True
    if n % 2 == 0:
        return False
    d = n - 1
    while d % 2 == 0:
        d //= 2
    bases = [2, 7, 61]
    for a in bases:
        t = d
        y = id5(a, t, n)
        while t != n - 1 and y != 1 and y != n - 1:
            y = (y * y) % n
            t <<= 1
        if y != n - 1 and t % 2 == 0:
            return False
    return True


def id3(a, b):
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
    return s, m0


def id4(m):
    if m == 2:
        return 1
    if m in {167772161, 469762049, 998244353}:
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
            if id5(g, (m - 1) // divs[i], m) == 1:
                ok = False
                break
        if ok:
            return g


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
        eg = id3(self._v, self._m)
        assert eg[0] == 1
        return eg[1]

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


class TaskB:
    def solve(self, n, m):
        ModInt._m = m
        ways = [ModInt() for _ in range(n + 1)]
        extras = [ModInt() for _ in range(n + 1)]
        ways[1] = ModInt(1)
        sum_ = ModInt(0)
        extra = ModInt(0)
        for i in range(1, n + 1):
            ways[i] += sum_
            extra += extras[i]
            ways[i] += extra
            for j in range(2, n // i + 1):
                extras[i * j] += ways[i]
                if (i + 1) * j <= n:
                    extras[(i + 1) * j] -= ways[i]
            sum_ += ways[i]
        return ways[n].val()


if __name__ == "__main__":
    n, m = map(int, input().split())
    solver = TaskB()
    print(solver.solve(n, m))
