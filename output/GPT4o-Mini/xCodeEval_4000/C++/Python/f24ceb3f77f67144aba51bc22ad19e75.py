import sys
from collections import defaultdict
from itertools import islice

MOD7 = 1000000007
MOD9 = 1000000009
MODF = 998244353

mod = MOD7

class ModInt:
    def __init__(self, n, special=False):
        if special:
            self.n = -1
            return
        if 0 <= n < mod:
            self.n = n
            return
        n %= mod
        if n < 0:
            n += mod
        self.n = n

    def __add__(self, other):
        return ModInt(self.n + other.n)

    def __sub__(self, other):
        return ModInt(self.n - other.n)

    def __mul__(self, other):
        return ModInt(self.n * other.n % mod)

    def __truediv__(self, other):
        return self * other.inverse()

    def __neg__(self):
        return ModInt(mod - self.n) if self.n != 0 else ModInt(0)

    def inverse(self):
        x, y = self.gcd(self.n, mod)
        if x < 0:
            x += mod
        return ModInt(x)

    @staticmethod
    def gcd(a, b):
        if a == 0:
            return (0, 1, b)
        x1, y1, g = ModInt.gcd(b % a, a)
        x = y1 - (b // a) * x1
        return (x, y1, g)

class FenwickTree:
    def __init__(self, size):
        self.value = [ModInt(0) for _ in range(size)]

    def add(self, at, v):
        while at < len(self.value):
            self.value[at] += v
            at |= at + 1

    def get(self, from_idx, to):
        if from_idx >= to:
            return ModInt(0)
        return self._get(to - 1) - self._get(from_idx - 1)

    def _get(self, to):
        result = ModInt(0)
        while to >= 0:
            result += self.value[to]
            to = (to & (to + 1)) - 1
        return result

class BVerkhnyayaYacheika:
    def solve(self):
        n = int(sys.stdin.readline().strip())
        m = int(sys.stdin.readline().strip())

        global mod
        mod = m
        ft = FenwickTree(n + 1)
        ft.add(n, ModInt(1))

        for i in range(n, 0, -1):
            res = ft.get(i + 1, n + 1)
            for z in range(2, n // i + 1):
                res += ft.get(z * i, z * i + z)
            ft.add(i, res)

        print(ft.get(1, 2).n)

if __name__ == "__main__":
    BVerkhnyayaYacheika().solve()
