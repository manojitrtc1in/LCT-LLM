import sys
from collections import defaultdict
from itertools import accumulate

class DSum:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self.in_stream = in_stream
            self.out_stream = out_stream
            self.k = 0
            self.dps = []
            self.sums = []
            self.arrs = []

        def read(self):
            return map(int, self.in_stream.readline().split())

        def print(self, *args):
            self.out_stream.write(' '.join(map(str, args)) + '\n')

        def do_copy(self, dpi):
            self.dps[dpi + 1] = self.dps[dpi][:]

        def add_to_knap(self, i, dpi):
            v = self.sums[i]
            k1 = len(self.arrs[i])
            for j in range(self.k, k1 - 1, -1):
                self.dps[dpi][j] = max(self.dps[dpi][j], self.dps[dpi][j - k1] + v)

        def rec(self, l, r, dpi):
            ans = 0
            carr = self.arrs[l]
            dp = self.dps[dpi]
            if l + 1 == r:
                ans = max(ans, dp[self.k])
                sum_val = 0
                for i in range(min(self.k, len(carr))):
                    sum_val += carr[i]
                    ans = max(ans, dp[self.k - i - 1] + sum_val)
            else:
                def do_split(l1, r1, l2, r2):
                    self.do_copy(dpi)
                    for i in range(l1, r1):
                        self.add_to_knap(i, dpi + 1)
                    return self.rec(l2, r2, dpi + 1)

                m = (l + r) // 2
                ans = max(ans, do_split(l, m, m, r))
                ans = max(ans, do_split(m, r, l, m))
            return ans

        def solve(self):
            n, self.k = self.read()
            self.sums = [0] * n
            self.arrs = []
            for i in range(n):
                t, *arr = self.read()
                self.arrs.append(arr)
                if t > self.k:
                    arr = arr[:self.k]
                self.sums[i] = sum(arr)

            self.dps = [[0] * (self.k + 1) for _ in range(13)]
            self.print(self.rec(0, n, 0))

    @staticmethod
    def solve(in_stream, out_stream):
        DSum.Solver(in_stream, out_stream).solve()

if __name__ == "__main__":
    DSum.solve(sys.stdin, sys.stdout)