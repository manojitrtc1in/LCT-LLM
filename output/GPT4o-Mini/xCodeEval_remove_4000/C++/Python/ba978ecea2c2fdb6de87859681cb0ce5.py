import sys
from collections import defaultdict
from itertools import accumulate

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

class DSum:
    def __init__(self):
        self.dps = []
        self.sums = []
        self.arrs = []

    def do_copy(self, dpi):
        self.dps[dpi + 1] = self.dps[dpi][:]

    def add_to_knap(self, i, dpi):
        v = self.sums[i]
        k1 = len(self.arrs[i])
        for j in range(len(self.dps[dpi]) - 1, k1 - 1, -1):
            self.dps[dpi][j] = max(self.dps[dpi][j], self.dps[dpi][j - k1] + v)

    def rec(self, l, r, dpi):
        ans = 0
        carr = self.arrs[l]
        dp = self.dps[dpi]
        if l + 1 == r:
            ans = max(ans, dp[k])
            sum_val = 0
            for i in range(min(k, len(carr))):
                sum_val += carr[i]
                ans = max(ans, dp[k - i - 1] + sum_val)
        else:
            m = (l + r) // 2
            self.do_copy(dpi)
            for i in range(l, m):
                self.add_to_knap(i, dpi + 1)
            ans = max(ans, self.rec(m, r, dpi + 1))
            self.do_copy(dpi)
            for i in range(m, r):
                self.add_to_knap(i, dpi + 1)
            ans = max(ans, self.rec(l, m, dpi + 1))
        return ans

    def solve(self):
        n, k = read_ints()
        self.sums = [0] * n
        self.arrs = []
        for i in range(n):
            t = read_int()
            arr = read_ints()
            if t > k:
                arr = arr[:k]
            self.arrs.append(arr)
            self.sums[i] = sum(arr)
        self.dps = [[0] * (k + 1) for _ in range(13)]
        print(self.rec(0, n, 0))

if __name__ == "__main__":
    DSum().solve()
