import random
import sys
from collections import deque, defaultdict
from functools import reduce
from itertools import combinations, permutations, product
from math import gcd, ceil, floor, sqrt, log2, log10, factorial, pi, sin, cos, tan, asin, acos, atan

INF = float('inf')
MOD = 1000000007
MOD2 = 998244353

def distinct(x):
    x.sort()
    x = list(set(x))
    return x

def CASE(x):
    for _ in range(x):
        yield

def CASEt(x):
    for tc in range(1, x + 1):
        yield tc

class Modular:
    def __init__(self, val):
        self.val = val % MOD

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return not self.__eq__(other)

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        return self.val < other.val

    def __le__(self, other):
        return self.val <= other.val

    def __gt__(self, other):
        return self.val > other.val

    def __ge__(self, other):
        return self.val >= other.val

    def __add__(self, other):
        return Modular(self.val + other.val)

    def __iadd__(self, other):
        return self.__add__(other)

    def __radd__(self, other):
        return self.__add__(other)

    def __sub__(self, other):
        return Modular(self.val - other.val)

    def __isub__(self, other):
        return self.__sub__(other)

    def __rsub__(self, other):
        return self.__sub__(other)

    def __mul__(self, other):
        return Modular(self.val * other.val)

    def __imul__(self, other):
        return self.__mul__(other)

    def __rmul__(self, other):
        return self.__mul__(other)

    def __pow__(self, power):
        m = self
        ans = Modular(1)
        while power:
            if power & 1:
                ans *= m
            m *= m
            power >>= 1
        return ans

    def __divmod__(self, other):
        return self.__mul__(other.inv())

    def __idivmod__(self, other):
        return self.__divmod__(other)

    def __rdivmod__(self, other):
        return self.__divmod__(other)

    def __repr__(self):
        return str(self.val)

    def inv(self):
        return self ** (MOD - 2)

class HashTable:
    def __init__(self, s, m):
        self.size = len(s)
        self.xp = [Modular(1)] * (self.size + 1)
        self.hash = [Modular(0)] * (self.size + 1)

        for i in range(1, self.size + 1):
            self.xp[i] = self.xp[i - 1] * m

        self.hash[self.size] = Modular(0)
        for i in range(self.size - 1, -1, -1):
            self.hash[i] = self.hash[i + 1] * m + ord(s[i])

def solve():
    n = int(input())
    t = input().strip()

    zp = []
    for i in range(len(t)):
        if t[i] == '0':
            zp.append(i)

    zpl = len(zp)

    m = random.choice([7, 11, 13, 17, 19])

    s = ['0' for _ in range(zpl)]
    for i in range(zpl):
        s[i] = str(ord('0') + (zp[i] & 1))

    s = ''.join(s)
    hash = HashTable(s, Modular(m))

    s = ['0' for _ in range(zpl)]
    for i in range(zpl):
        s[i] = str(ord('1') - (zp[i] & 1))

    s = ''.join(s)
    rhash = HashTable(s, Modular(m))

    q = int(input())
    for _ in range(q):
        l1, l2, length = map(int, input().split())
        l1 -= 1
        l2 -= 1

        d1 = bisect_left(zp, l1)
        d2 = bisect_left(zp, l2)

        z1 = bisect_left(zp, l1 + length) - d1
        z2 = bisect_left(zp, l2 + length) - d2

        if z1 != z2:
            print("No")
            continue

        if z1 == 0:
            print("Yes")
            continue

        hash1 = hash.getHash(d1, d1 + z1 - 1)
        hash2 = hash.getHash(d2, d2 + z1 - 1) if (l1 & 1) == (l2 & 1) else rhash.getHash(d2, d2 + z1 - 1)

        print("Yes" if hash1 == hash2 else "No")

def main():
    n = int(input())
    for _ in range(n):
        solve()

if __name__ == "__main__":
    main()
