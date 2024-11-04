import sys
from typing import List, Tuple

def dijkstra(e: List[List[Tuple[int, int]]], start: int, start_dist: int) -> Tuple[List[int], List[bool]]:
    n = len(e)
    added = [False] * n
    res = [float('inf')] * n
    res[start] = start_dist
    added[start] = True
    pq = [(start_dist, start)]
    while pq:
        d, i = pq.pop(0)
        if res[i] < d:
            continue
        for j, ew in e[i]:
            if not added[j] or d + ew < res[j]:
                res[j] = d + ew
                added[j] = True
                pq.append((res[j], j))
    return res, added

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dps = [[0] * (k+1) for _ in range(13)]
    for i in range(n):
        for dpi in range(12):
            do_copy(dpi+1, dpi)
            v = sums[i]
            k1 = len(arrs[i])
            for j in range(k, k1-1, -1):
                dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1] + v)
    return id13(lambda rec, l, r, dpi: (
        ans := 0,
        carr := arrs[l],
        dp := dps[dpi],
        if l+1 == r:
            ans = max(ans, dp[k])
            sum = 0
            for i in range(min(k, len(carr))):
                sum += carr[i]
                ans = max(ans, dp[k-i-1] + sum)
        else:
            do_split = lambda l1, r1, l2, r2: (
                do_copy(dpi+1, dpi),
                for i in range(l1, r1-1):
                    id14(i, dpi+1),
                rec(l2, r2, dpi+1)
            )
            m = (l+r) // 2
            ans = max(ans, do_split(l, m, m, r))
            ans = max(ans, do_split(m, r, l, m))
        ans
    )(0, n, 0))

def do_copy(dpi1: int, dpi2: int) -> None:
    dps[dpi1] = dps[dpi2].copy()

def id14(i: int, dpi: int) -> None:
    v = sums[i]
    k1 = len(arrs[i])
    for j in range(k, k1-1, -1):
        dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1] + v)

def main() -> None:
    n, k = map(int, input().split())
    arrs = [list(map(int, input().split())) for _ in range(n)]
    print(solve(n, k, arrs))

if __name__ == "__main__":
    main()
