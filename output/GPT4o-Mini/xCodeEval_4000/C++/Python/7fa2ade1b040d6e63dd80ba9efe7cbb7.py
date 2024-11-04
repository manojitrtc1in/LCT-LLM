import sys
from collections import defaultdict

class DualSegTree:
    def __init__(self, n):
        self.n = n
        self.log = 1
        while (1 << self.log) < n:
            self.log += 1
        self.size = 1 << self.log
        self.laz = [0] * (self.size << 1)

    def reset(self):
        self.laz = [0] * (self.size << 1)

    def all_apply(self, k, a):
        self.laz[k] += a

    def get(self, p):
        assert 0 <= p < self.n
        p += self.size
        for i in range(self.log, 0, -1):
            self.push(p >> i)
        return self.laz[p]

    def get_all(self):
        for i in range(self.size):
            self.push(i)
        return self.laz[self.size:]

    def apply(self, l, r, a):
        assert 0 <= l <= r <= self.n
        if l == r:
            return

        l += self.size
        r += self.size

        for i in range(self.log, 0, -1):
            if ((l >> i) << i) != l:
                self.push(l >> i)
            if ((r >> i) << i) != r:
                self.push((r - 1) >> i)

        l2, r2 = l, r
        while l < r:
            if l & 1:
                self.all_apply(l, a)
                l += 1
            if r & 1:
                r -= 1
                self.all_apply(r, a)
            l >>= 1
            r >>= 1

    def push(self, k):
        self.all_apply(2 * k, self.laz[k])
        self.all_apply(2 * k + 1, self.laz[k])
        self.laz[k] = 0

def solve():
    N, mod = map(int, sys.stdin.readline().split())
    
    seg = DualSegTree(N + 1)
    dp = [0] * (N + 1)
    dp[1] = 1

    for n in range(1, N + 1):
        dp[n] += seg.get(n)
        seg.apply(n + 1, N + 1, dp[n])
        z = 2
        while True:
            l = n * z
            r = (n + 1) * z
            if l > N:
                break
            z += 1
            r = min(r, N + 1)
            seg.apply(l, r, dp[n])

    print(dp[-1])

if __name__ == "__main__":
    sys.setrecursionlimit(10**6)
    input = sys.stdin.read
    data = input().splitlines()
    T = 1
    for _ in range(T):
        solve()
