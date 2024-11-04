import sys
from collections import defaultdict
from itertools import accumulate

class DSum:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self._in = in_stream
            self._out = out_stream
            self.k = 0
            self.dps = []
            self.sums = []
            self.arrs = []

        def rd(self):
            return map(int, self._in.readline().split())

        def pr(self, *args):
            self._out.write(' '.join(map(str, args)))

        def prln(self, *args):
            self.pr(*args)
            self._out.write('\n')

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
            n, self.k = self.rd()
            self.sums = [0] * n
            self.arrs = []
            for i in range(n):
                t, *arr = self.rd()
                self.arrs.append(arr[:self.k])
                self.sums[i] = sum(self.arrs[i])
            self.dps = [[0] * (self.k + 1) for _ in range(13)]
            self.prln(self.rec(0, n, 0))

    @staticmethod
    def solve(in_stream, out_stream):
        DSum.Solver(in_stream, out_stream).solve()

if __name__ == "__main__":
    input_stream = sys.stdin
    output_stream = sys.stdout
    DSum.solve(input_stream, output_stream)