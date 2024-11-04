import sys
from collections import defaultdict
from itertools import accumulate
from typing import List, Tuple

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def sum_list(lst):
    return sum(lst)

def smax(a, b):
    return max(a, b)

class DSum:
    @staticmethod
    def solve():
        n, k = read_ints()
        arrs = []
        for _ in range(n):
            t = read_int()
            arr = read_ints()[:t]
            if t > k:
                arr = arr[:k]
            arrs.append(arr)

        sums = [sum_list(arr) for arr in arrs]

        dps = [[0] * (k + 1) for _ in range(13)]

        def do_copy(dpi):
            dps[dpi + 1] = dps[dpi][:]

        def add_to_knap(i, dpi):
            v = sums[i]
            k1 = len(arrs[i])
            for j in range(k, k1 - 1, -1):
                dps[dpi][j] = smax(dps[dpi][j], dps[dpi][j - k1] + v)

        def y_combinator(rec, l, r, dpi):
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
                do_split = lambda l1, r1, l2, r2: (do_copy(dpi), 
                                                     [add_to_knap(i, dpi + 1) for i in range(l1, r1)], 
                                                     rec(l2, r2, dpi + 1))
                ans = smax(ans, do_split(l, m, m, r))
                ans = smax(ans, do_split(m, r, l, m))
            return ans

        result = y_combinator(y_combinator, 0, n, 0)
        print(result)

if __name__ == "__main__":
    DSum.solve()
