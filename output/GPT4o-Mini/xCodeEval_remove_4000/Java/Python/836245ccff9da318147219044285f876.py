import sys
import random
from functools import reduce

mod = 1000000007
mod2 = 998244353

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        self.index += 1
        return self.data[self.index - 1]

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.data[self.index:]

def main():
    inp = FastReader()
    n = inp.next_int()
    a = [inp.next_long() for _ in range(n)]
    
    if n > 66:
        print(1)
        return

    pref = [0] * (n + 1)
    pref[1] = a[0]
    for i in range(1, n):
        pref[i + 1] = pref[i] ^ a[i]

    gg = 34
    for c in range(n - 1):
        for left in range(c + 1):
            for right in range(c + 1, n):
                if xor(left, c, pref) > xor(c + 1, right, pref):
                    gg = min(gg, right - left - 1)

    print(-1 if gg == 34 else gg)

def xor(i, j, pref):
    return pref[j + 1] ^ pref[i]

def sort(arr):
    arr.sort()

def id0(arr):
    random.shuffle(arr)
    arr.sort()

def init(n):
    fact = [0] * (n + 1)
    invFact = [0] * (n + 1)
    fact[0] = 1
    for i in range(1, n + 1):
        fact[i] = mul(i, fact[i - 1])
    invFact[n] = mod_inv(fact[n])
    for i in range(n - 1, -1, -1):
        invFact[i] = mul(invFact[i + 1], i + 1)
    return fact, invFact

def mod_inv(x):
    return power(x, mod - 2)

def nCr(n, r, fact, invFact):
    if n < r or r < 0:
        return 0
    return mul(fact[n], mul(invFact[r], invFact[n - r]))

def mul(a, b):
    return a * b % mod

def add(a, b):
    return (a + b) % mod

def power(x, y):
    gg = 1
    while y > 0:
        if y % 2 == 1:
            gg = mul(gg, x)
        x = mul(x, x)
        y //= 2
    return gg

def gcd(a, b):
    return b if b == 0 else gcd(b, a % b)

def input_array(arr, n, inp):
    for i in range(n):
        arr[i] = inp.next_long()

if __name__ == "__main__":
    main()
