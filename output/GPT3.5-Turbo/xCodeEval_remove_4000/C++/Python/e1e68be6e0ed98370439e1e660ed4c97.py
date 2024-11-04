import math

mod = 1000000007

class ModInt:
    def __init__(self, x):
        self.x = x % mod

    def __mul__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * other.x)
        return ModInt(self.x * other)

    def __add__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x + other.x)
        return ModInt(self.x + other)

    def __sub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x - other.x)
        return ModInt(self.x - other)

    def __pow__(self, n):
        return ModInt(pow(self.x, n, mod))

    def __str__(self):
        return str(self.x)

    def __repr__(self):
        return str(self.x)

def combination(n, k):
    return math.comb(n, k)

def multi_choose(n, r):
    if n == 0:
        return ModInt(1 if r == 0 else 0)
    if r == 0:
        return ModInt(1)
    return combination(n + r - 1, r)

def multi_choose_with_limit(n, r, lim):
    if n == 0:
        return ModInt(1 if r == 0 else 0)
    if lim <= 0 and r > 0:
        return ModInt(0)
    if r == 0:
        return ModInt(1 if lim < 0 else 0)
    ret = ModInt(0)
    for i in range(n + 1):
        if i * (lim + 1) > r:
            break
        ret += ((-1) ** i) * combination(n, i) * multi_choose(n, r - i * (lim + 1))
    return ret

def main():
    p, s, r = map(int, input().split())
    ret = ModInt(0)
    for top in range(r, s + 1):
        tot = ModInt(0)
        for q in range(p):
            if top * q > s - top:
                break
            tot += combination(p - 1, q) * multi_choose_with_limit(p - q - 1, s - top - top * q, top - 1) * (q + 1).inv()
        ret += tot
    ret *= multi_choose(p, s - r).inv()
    print(ret)

if __name__ == "__main__":
    main()
