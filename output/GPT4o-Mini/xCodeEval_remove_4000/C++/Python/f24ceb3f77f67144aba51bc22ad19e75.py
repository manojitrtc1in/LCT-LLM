import sys
import math
from collections import defaultdict

MOD7 = 1000000007
MOD9 = 1000000009
MODF = 998244353

mod = MOD7

def gcd(a, b):
    if a == 0:
        return b
    x, y = gcd(b % a, a)
    return y, x - (b // a) * y

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
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        n = self.n + other.n
        if n >= mod:
            n -= mod
        return ModInt(n)

    def __sub__(self, other):
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        n = self.n - other.n
        if n < 0:
            n += mod
        return ModInt(n)

    def __mul__(self, other):
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        return ModInt(self.n * other.n % mod)

    def __truediv__(self, other):
        if other.n == 0:
            raise Exception("Division by zero")
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        return self * other.inverse()

    def __neg__(self):
        if self.n == -1:
            raise Exception("Illegal state")
        if self.n == 0:
            return ModInt(0)
        return ModInt(mod - self.n)

    def inverse(self):
        if self.n == -1:
            raise Exception("Illegal state")
        x, y = gcd(self.n, mod)
        if x != 1:
            raise Exception("not inversable")
        return ModInt(x)

    def __eq__(self, other):
        return self.n == other.n

    def __ne__(self, other):
        return self.n != other.n

    def __repr__(self):
        return str(self.n)

class FenwickTree:
    def __init__(self, size):
        self.value = [0] * size

    def add(self, at, v):
        while at < len(self.value):
            self.value[at] += v
            at |= (at + 1)

    def get(self, from_idx, to):
        if from_idx >= to:
            return 0
        return self._get(to - 1) - self._get(from_idx - 1)

    def _get(self, to):
        result = 0
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
        ft.add(n, 1)

        for i in range(n, 0, -1):
            res = ft.get(i + 1, n + 1)
            for z in range(2, n // i + 1):
                res += ft.get(z * i, z * i + z)
            ft.add(i, res)

        print(ft.get(1, 2))

if __name__ == "__main__":
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")
    
    solver = BVerkhnyayaYacheika()
    solver.solve()
