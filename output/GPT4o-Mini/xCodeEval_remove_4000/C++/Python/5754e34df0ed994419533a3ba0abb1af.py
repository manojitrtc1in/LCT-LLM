import sys
import random
from collections import defaultdict
from itertools import accumulate

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def read_list(n):
    return [read_int() for _ in range(n)]

def sum_list(lst):
    return sum(lst)

def max_list(lst):
    return max(lst)

def smax(a, b):
    return max(a, b)

def smin(a, b):
    return min(a, b)

class DSum:
    def solve(self):
        n, k = read_ints()
        arrs = [read_list(read_int()) for _ in range(n)]
        sums = [sum_list(arr) for arr in arrs]

        dps = [[0] * (k + 1) for _ in range(13)]

        def do_copy(dpi):
            dps[dpi + 1] = dps[dpi][:]

        def id14(i, dpi):
            v = sums[i]
            k1 = len(arrs[i])
            for j in range(k, k1 - 1, -1):
                dps[dpi][j] = smax(dps[dpi][j], dps[dpi][j - k1] + v)

        def rec(l, r, dpi):
            ans = 0
            carr = arrs[l]
            dp = dps[dpi]
            if l + 1 == r:
                ans = smax(ans, dp[k])
                sum_val = 0
                for i in range(min(k, len(carr))):
                    sum_val += carr[i]
                    ans = smax(ans, dp[k - i - 1] + sum_val)
            else:
                m = (l + r) // 2
                do_split = lambda l1, r1, l2, r2: self.do_split(l1, r1, l2, r2, dpi)
                ans = smax(ans, do_split(l, m, m, r))
                ans = smax(ans, do_split(m, r, l, m))
            return ans

        def do_split(self, l1, r1, l2, r2, dpi):
            do_copy(dpi)
            for i in range(l1, r1):
                id14(i, dpi + 1)
            return rec(l2, r2, dpi + 1)

        result = rec(0, n, 0)
        print(result)

if __name__ == "__main__":
    DSum().solve()
