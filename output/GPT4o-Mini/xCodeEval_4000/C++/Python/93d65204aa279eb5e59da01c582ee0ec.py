import sys
from collections import defaultdict

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def smax(a, b):
    return max(a, b)

class DSum:
    def __init__(self):
        self.k = 0
        self.sums = []
        self.arrs = []
        self.dps = []

    def do_copy(self, dpi):
        self.dps[dpi + 1] = self.dps[dpi][:]

    def add_to_knap(self, i, dpi):
        v = self.sums[i]
        k1 = len(self.arrs[i])
        for j in range(self.k, k1 - 1, -1):
            self.dps[dpi][j] = smax(self.dps[dpi][j], self.dps[dpi][j - k1] + v)

    def rec(self, l, r, dpi):
        ans = 0
        carr = self.arrs[l]
        dp = self.dps[dpi]
        if l + 1 == r:
            ans = smax(ans, dp[self.k])
            sum_val = 0
            for i in range(min(self.k, len(carr))):
                sum_val += carr[i]
                ans = smax(ans, dp[self.k - i - 1] + sum_val)
        else:
            m = (l + r) // 2
            self.do_copy(dpi)
            for i in range(l, m):
                self.add_to_knap(i, dpi + 1)
            ans = smax(ans, self.rec(m, r, dpi + 1))
            self.do_copy(dpi)
            for i in range(m, r):
                self.add_to_knap(i, dpi + 1)
            ans = smax(ans, self.rec(l, m, dpi + 1))
        return ans

    def solve(self):
        n = read_int()
        self.k = read_int()
        self.sums = [0] * n
        self.arrs = []
        for i in range(n):
            t = read_int()
            arr = read_ints()
            self.arrs.append(arr[:self.k] if t > self.k else arr)
            self.sums[i] = sum(self.arrs[i])
        self.dps = [[0] * (self.k + 1) for _ in range(13)]
        print(self.rec(0, n, 0))

if __name__ == "__main__":
    sys.stdin = open(0)  # For reading from standard input
    DSum().solve()
