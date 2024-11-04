from math import comb
import sys

DECIMAL_DIGITS = 10
STATIC_MOD = 998244353

class ModInt:
    def __init__(self, x=0):
        self.x = x % STATIC_MOD

    def __mul__(self, other):
        return ModInt(self.x * other.x % STATIC_MOD)

    def __add__(self, other):
        return ModInt(self.x + other.x)

    def __sub__(self, other):
        return ModInt(self.x - other.x)

    def __truediv__(self, other):
        return self * inv(other)

    def __pow__(self, exp):
        result = ModInt(1)
        base = self
        while exp:
            if exp % 2:
                result *= base
            base *= base
            exp //= 2
        return result

    def __int__(self):
        return self.x

def inv(x):
    a, b = x.x, STATIC_MOD
    u, v = 1, 0
    while b:
        t = a // b
        a, b = b, a - t * b
        u, v = v, u - t * v
    return ModInt(u)

def multi_choose(n, r):
    if n == 0:
        return ModInt(1 if r == 0 else 0)
    return comb(n + r - 1, r)

def multi_choose_limited(n, r, lim):
    if n == 0:
        return ModInt(1 if r == 0 else 0)
    if lim <= 0 and r > 0:
        return ModInt(0)
    if r == 0:
        return ModInt(1 if lim >= 0 else 0)
    
    ret = ModInt(0)
    for i in range(n + 1):
        if i * (lim + 1) > r:
            break
        sign = -1 if i % 2 else 1
        ret += ModInt(sign) * comb(n, i) * multi_choose(n, r - i * (lim + 1))
    return ret

def main():
    p, s, r = map(int, sys.stdin.readline().split())
    ret = ModInt(0)
    for top in range(r, s + 1):
        tot = ModInt(0)
        for q in range(p):
            if top * q > s - top:
                break
            tot += (comb(p - 1, q) *
                     multi_choose_limited(p - q - 1, s - top - top * q, top - 1) *
                     inv(ModInt(q + 1)))
        ret += tot
    ret *= inv(multi_choose(p, s - r))
    print(int(ret))

if __name__ == "__main__":
    main()
