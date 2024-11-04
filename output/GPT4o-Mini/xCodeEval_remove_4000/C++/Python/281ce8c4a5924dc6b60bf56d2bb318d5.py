import sys
import random
from collections import defaultdict
from itertools import accumulate

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def sum_list(lst):
    return sum(lst)

def max_list(lst):
    return max(lst)

def dijkstra(e, start, start_dist=0):
    n = len(e)
    added = [False] * n
    res = [float('inf')] * n
    res[start] = start_dist
    pq = [(start_dist, start)]
    
    while pq:
        d, i = heapq.heappop(pq)
        if res[i] < d:
            continue
        for j, ew in e[i]:
            if not added[j] or d + ew < res[j]:
                added[j] = True
                res[j] = d + ew
                heapq.heappush(pq, (res[j], j))
    return res, added

class DSum:
    def solve(self):
        n, k = read_ints()
        arrs = []
        for _ in range(n):
            t = read_int()
            arr = read_ints()
            if t > k:
                arr = arr[:k]
            arrs.append(arr)

        sums = [sum_list(arr) for arr in arrs]
        dps = [[0] * (k + 1) for _ in range(13)]

        def id14(i, dpi):
            v = sums[i]
            k1 = len(arrs[i])
            for j in range(k, k1 - 1, -1):
                dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v)

        def rec(l, r, dpi):
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
                ans = max(ans, rec(l, m, dpi + 1))
                ans = max(ans, rec(m, r, dpi + 1))
            return ans

        result = rec(0, n, 0)
        print(result)

if __name__ == "__main__":
    DSum().solve()
