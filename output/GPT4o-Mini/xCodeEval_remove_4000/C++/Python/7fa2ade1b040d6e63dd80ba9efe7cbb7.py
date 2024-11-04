from collections import defaultdict
import sys
import itertools

input = sys.stdin.read
def read():
    return list(map(int, input().split()))

class ModInt:
    def __init__(self, val=0, mod=0):
        self.mod = mod
        self.val = val % mod if val >= 0 else (mod - (-val % mod)) % mod

    def __add__(self, other):
        return ModInt(self.val + other.val, self.mod)

    def __sub__(self, other):
        return ModInt(self.val - other.val, self.mod)

    def __mul__(self, other):
        return ModInt(self.val * other.val % self.mod, self.mod)

    def __truediv__(self, other):
        return self * other.inverse()

    def __neg__(self):
        return ModInt(self.mod - self.val)

    def inverse(self):
        a, b, u, v = self.val, self.mod, 1, 0
        while b > 0:
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v
        return ModInt(u, self.mod)

    def __repr__(self):
        return str(self.val)

def solve():
    data = read()
    N, mod = data[0], data[1]
    mint = ModInt(mod=mod)

    seg = [mint(0) for _ in range(N + 1)]
    dp = [mint(0) for _ in range(N + 1)]
    dp[1] = mint(1)

    for n in range(1, N + 1):
        dp[n] += seg[n]
        for i in range(n + 1, N + 1):
            seg[i] += dp[n]
        z = 2
        while True:
            l = n * z
            r = (n + 1) * z
            if l > N:
                break
            z += 1
            r = min(r, N + 1)
            for j in range(l, r):
                seg[j] += dp[n]

    print(dp[-1])

if __name__ == "__main__":
    sys.setrecursionlimit(10**6)
    input = sys.stdin.read
    solve()
