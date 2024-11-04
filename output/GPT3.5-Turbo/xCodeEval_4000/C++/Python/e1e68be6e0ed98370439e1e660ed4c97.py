import sys

MOD = 998244353

class ModInt:
    def __init__(self, x):
        self.x = x % MOD

    def __add__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x + other.x)
        return ModInt(self.x + other)

    def __sub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x - other.x)
        return ModInt(self.x - other)

    def __mul__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * other.x)
        return ModInt(self.x * other)

    def __pow__(self, n):
        if n == 0:
            return ModInt(1)
        if n % 2 == 0:
            half = self.__pow__(n // 2)
            return half * half
        return self * self.__pow__(n - 1)

    def __str__(self):
        return str(self.x)

    def __repr__(self):
        return str(self.x)


def main():
    p, s, r = map(int, input().split())
    ret = ModInt(0)
    for top in range(r, s + 1):
        tot = ModInt(0)
        for q in range(p):
            if top * q > s - top:
                break
            tot += ModInt.combination(p - 1, q) * ModInt.multi_choose(p - q - 1, s - top - top * q, top - 1) * ModInt.inv(q + 1)
        ret += tot
    ret *= ModInt.inv(ModInt.multi_choose(p, s - r))
    print(ret)


if __name__ == "__main__":
    main()
