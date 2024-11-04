class ModInt:
    def __init__(self, v=0, mod=1):
        self.mod = mod
        self._v = v % mod
        if self._v < 0:
            self._v += mod

    def __add__(self, other):
        return ModInt(self._v + other._v, self.mod)

    def __sub__(self, other):
        return ModInt(self._v - other._v, self.mod)

    def __mul__(self, other):
        return ModInt(self._v * other._v, self.mod)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        return self.pow(self.mod - 2)

    def pow(self, n):
        assert n >= 0
        x = self
        r = ModInt(1, self.mod)
        while n:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r

    def val(self):
        return self._v


class TaskB:
    def solve(self, n, m):
        ModInt.set_mod(m)
        ways = [ModInt(0) for _ in range(n + 1)]
        extras = [ModInt(0) for _ in range(n + 1)]
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

        print(ways[n].val())


if __name__ == "__main__":
    n, m = map(int, input().split())
    solver = TaskB()
    solver.solve(n, m)
