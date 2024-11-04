import sys
import random
from functools import reduce
from math import gcd

mod = 1000000007
mod2 = 998244353

class InVoker:
    def __init__(self):
        self.pref = []
        self.fact = []
        self.invFact = []

    def main(self):
        n = int(input())
        a = list(map(int, input().split()))
        self.input(a, n)
        if n > 66:
            print(1)
            return
        self.pref = [0] * (n + 1)
        self.pref[1] = a[0]
        for i in range(1, n):
            self.pref[i + 1] = self.pref[i] ^ a[i]
        gg = 34
        for c in range(n - 1):
            for left in range(c + 1):
                for right in range(c + 1, n):
                    if self.xor(left, c) > self.xor(c + 1, right):
                        gg = min(gg, right - left - 1)
        print(-1 if gg == 34 else gg)

    def xor(self, i, j):
        return self.pref[j + 1] ^ self.pref[i]

    def sort(self, a):
        a.sort()

    def ruffle_sort(self, a):
        n = len(a)
        for i in range(n):
            j = random.randint(0, n - 1)
            a[i], a[j] = a[j], a[i]
        a.sort()

    def init(self, n):
        self.fact = [0] * (n + 1)
        self.invFact = [0] * (n + 1)
        self.fact[0] = 1
        for i in range(1, n + 1):
            self.fact[i] = self.mul(i, self.fact[i - 1])
        self.invFact[n] = self.mod_inv(self.fact[n])
        for i in range(n - 1, -1, -1):
            self.invFact[i] = self.mul(self.invFact[i + 1], i + 1)

    def mod_inv(self, x):
        return self.power(x, mod - 2)

    def nCr(self, n, r):
        if n < r or r < 0:
            return 0
        return self.mul(self.fact[n], self.mul(self.invFact[r], self.invFact[n - r]))

    def mul(self, a, b):
        return a * b % mod

    def add(self, a, b):
        return (a + b) % mod

    def power(self, x, y):
        gg = 1
        while y > 0:
            if y % 2 == 1:
                gg = self.mul(gg, x)
            x = self.mul(x, x)
            y //= 2
        return gg

    @staticmethod
    def input(a, n):
        for i in range(n):
            a[i] = int(input())

if __name__ == "__main__":
    invoker = InVoker()
    invoker.main()
