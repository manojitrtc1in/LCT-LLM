import sys
from collections import defaultdict
from itertools import accumulate

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def sum(arr):
    return sum(arr)

class DSum:
    @staticmethod
    def solve():
        n, k = read_ints()
        arrs = [read_ints() for _ in range(n)]
        sums = [sum(arr) for arr in arrs]

        dps = [[0] * (k + 1) for _ in range(13)]

        def do_copy(dpi):
            dps[dpi + 1] = dps[dpi][:]

        def add_to_knap(i, dpi):
            v = sums[i]
            k1 = len(arrs[i])
            for j in range(k, k1 - 1, -1):
                dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v)

        def y_combinator(rec, l, r, dpi):
            ans = 0
            carr = arrs[l]
            dp = dps[dpi]
            if l + 1 == r:
                ans = max(ans, dp[k])
                sum_val = 0
                for i in range(min(k, len(carr))):
                    sum_val += carr[i]
                    ans = max(ans, dp[k - i - 1] + sum_val)
            else:
                m = (l + r) // 2
                def do_split(l1, r1, l2, r2):
                    do_copy(dpi)
                    for i in range(l1, r1):
                        add_to_knap(i, dpi + 1)
                    return rec(l2, r2, dpi + 1)

                ans = max(ans, do_split(l, m, m, r))
                ans = max(ans, do_split(m, r, l, m))
            return ans

        result = y_combinator(y_combinator, 0, n, 0)
        print(result)

if __name__ == "__main__":
    DSum.solve()
