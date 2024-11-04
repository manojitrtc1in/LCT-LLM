from math import gcd
from sys import stdin, stdout

class ModInt:
    def __init__(self, x=0, mod=1):
        self.mod = mod
        self.x = x % mod

    def __mul__(self, other):
        return ModInt(self.x * other.x % self.mod, self.mod)

    def __add__(self, other):
        return ModInt(self.x + other.x, self.mod)

    def __sub__(self, other):
        return ModInt(self.x - other.x, self.mod)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        a, b, u, v = self.x, self.mod, 1, 0
        while b:
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v
        return ModInt(u, self.mod)

    def __int__(self):
        return self.x

    @staticmethod
    def raw(x, mod):
        return ModInt(x % mod, mod)

class Factorial:
    def __init__(self, size, mod):
        self.size = size
        self.mod = mod
        self.factorial = [ModInt(1, mod)] * size
        self.inverse_factorial = [ModInt(1, mod)] * size
        self.build()

    def build(self):
        for i in range(1, self.size):
            self.factorial[i] = self.factorial[i - 1] * ModInt(i, self.mod)
        self.inverse_factorial[self.size - 1] = self.factorial[self.size - 1].inv()
        for i in range(self.size - 1, 0, -1):
            self.inverse_factorial[i - 1] = self.inverse_factorial[i] * ModInt(i, self.mod)

    def combination(self, n, k):
        if k < 0 or k > n:
            return ModInt(0, self.mod)
        return self.factorial[n] * self.inverse_factorial[k] * self.inverse_factorial[n - k]

    def multi_choose(self, n, r):
        if n == 0:
            return ModInt(1 if r == 0 else 0, self.mod)
        return self.combination(n + r - 1, r)

def main():
    p, s, r = map(int, stdin.readline().split())
    mod = 10**9 + 7
    factorial = Factorial(3123456, mod)
    ret = ModInt(0, mod)

    for top in range(r, s + 1):
        tot = ModInt(0, mod)
        for q in range(p):
            if top * q > s - top:
                break
            tot += (factorial.combination(p - 1, q) *
                     factorial.multi_choose(p - q - 1, s - top - top * q) *
                     ModInt.inv(q + 1, mod))
        ret += tot

    ret *= factorial.inv(factorial.multi_choose(p, s - r))
    stdout.write(f"{int(ret)}\n")

if __name__ == "__main__":
    main()
