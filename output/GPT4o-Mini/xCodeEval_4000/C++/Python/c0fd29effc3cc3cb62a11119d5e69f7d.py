import sys
import random
from collections import defaultdict

MOD = 1000000007

class Modular:
    def __init__(self, val=0):
        self.val = val % MOD

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return self.val != other.val

    def __lt__(self, other):
        return self.val < other.val

    def __add__(self, other):
        return Modular(self.val + other.val)

    def __sub__(self, other):
        return Modular(self.val - other.val)

    def __mul__(self, other):
        return Modular(self.val * other.val)

    def __pow__(self, power):
        result = Modular(1)
        base = self
        while power:
            if power & 1:
                result *= base
            base *= base
            power >>= 1
        return result

    def __repr__(self):
        return str(self.val)

class HashTable:
    def __init__(self, s, m):
        self.size = len(s)
        self.xp = [Modular(1)] * (self.size + 1)
        self.hash = [Modular(0)] * (self.size + 1)

        for i in range(1, self.size + 1):
            self.xp[i] = self.xp[i - 1] * m

        for i in range(self.size - 1, -1, -1):
            self.hash[i] = self.hash[i + 1] * m + Modular(ord(s[i]))

    def get_hash(self, l, r):
        assert l <= r and r < self.size
        return self.hash[l] - self.hash[r + 1] * self.xp[r - l + 1]

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    t = data[1]
    
    zp = [i for i in range(len(t)) if t[i] == '0']
    zpl = len(zp)

    mul = [7, 11, 13, 17, 19]
    m = Modular(random.choice(mul))

    s = ['0'] * zpl
    for i in range(zpl):
        s[i] = str(zp[i] & 1)

    hash_table = HashTable(''.join(s), m)

    for i in range(zpl):
        s[i] = str(1 - (zp[i] & 1))

    rhash_table = HashTable(''.join(s), m)

    q = int(data[2])
    results = []

    for i in range(q):
        l1, l2, length = map(int, data[3 + i].split())
        l1 -= 1
        l2 -= 1

        d1 = next((i for i, v in enumerate(zp) if v >= l1), zpl)
        d2 = next((i for i, v in enumerate(zp) if v >= l2), zpl)

        z1 = next((i for i, v in enumerate(zp[d1:], start=d1) if v > l1 + length - 1), zpl) - d1
        z2 = next((i for i, v in enumerate(zp[d2:], start=d2) if v > l2 + length - 1), zpl) - d2

        if z1 != z2:
            results.append("No")
            continue

        if z1 == 0:
            results.append("Yes")
            continue

        hash1 = hash_table.get_hash(d1, d1 + z1 - 1)
        hash2 = (hash_table.get_hash(d2, d2 + z1 - 1) if (l1 & 1) == (l2 & 1) else rhash_table.get_hash(d2, d2 + z1 - 1))

        results.append("Yes" if hash1 == hash2 else "No")

    print("\n".join(results))

if __name__ == "__main__":
    main()
