import random

class Modular:
    def __init__(self, val):
        self.val = val

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return not self == other

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
        return self + other

    def __radd__(self, other):
        return Modular(other) + self

    def __sub__(self, other):
        return Modular(self.val - other.val)

    def __isub__(self, other):
        return self - other

    def __rsub__(self, other):
        return Modular(other) - self

    def __mul__(self, other):
        return Modular(self.val * other.val)

    def __imul__(self, other):
        return self * other

    def __rmul__(self, other):
        return Modular(other) * self

    def pow(self, power):
        m = self
        ans = Modular(1)
        while power:
            if power & 1:
                ans *= m
            m *= m
            power >>= 1
        return ans

    def inv(self):
        return self.pow(MODVALUE - 2)

    def __truediv__(self, other):
        return self * other.inv()

    def __itruediv__(self, other):
        return self / other

    def __rtruediv__(self, other):
        return Modular(other) / self

    def __str__(self):
        return str(self.val)

class HashTable:
    def __init__(self, s, m):
        self.size = len(s)
        self.xp = [Modular(0)] * (self.size + 1)
        self.hash = [Modular(0)] * (self.size + 1)

        self.xp[0] = Modular(1)
        for i in range(1, self.size + 1):
            self.xp[i] = self.xp[i - 1] * m

        self.hash[self.size] = Modular(0)
        for i in range(self.size - 1, -1, -1):
            self.hash[i] = self.hash[i + 1] * m + ord(s[i])

def solve():
    n = int(input())
    t = input()

    zp = []
    for i in range(len(t)):
        if t[i] == '0':
            zp.append(i)

    zpl = len(zp)

    m = random.choice([7, 11, 13, 17, 19])

    s = ['0' if zp[i] & 1 else '1' for i in range(zpl)]
    s = ''.join(s)

    hash = HashTable(s, m)

    s = ['1' if zp[i] & 1 else '0' for i in range(zpl)]
    s = ''.join(s)

    rhash = HashTable(s, m)

    for _ in range(q):
        l1, l2, length = map(int, input().split())
        l1 -= 1
        l2 -= 1

        d1 = len([x for x in zp if x < l1])
        d2 = len([x for x in zp if x < l2])

        z1 = len([x for x in zp if l1 <= x < l1 + length])
        z2 = len([x for x in zp if l2 <= x < l2 + length])

        if z1 != z2:
            print("No")
            continue

        if z1 == 0:
            print("Yes")
            continue

        hash1 = hash.getHash(d1, d1 + z1 - 1)
        hash2 = hash.getHash(d2, d2 + z1 - 1) if l1 & 1 == l2 & 1 else rhash.getHash(d2, d2 + z1 - 1)

        print("Yes" if hash1 == hash2 else "No")

if __name__ == "__main__":
    solve()
