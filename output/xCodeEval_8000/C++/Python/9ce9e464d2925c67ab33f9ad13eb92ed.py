import sys
from typing import List, Tuple

def dijkstra(n: int, e: List[List[Tuple[int, int]]], start: int) -> Tuple[List[int], List[bool]]:
    added = [False] * n
    res = [float('inf')] * n
    res[start] = 0
    added[start] = True
    pq = [(0, start)]
    while pq:
        d, i = pq.pop(0)
        if res[i] < d:
            continue
        for j, ew in e[i]:
            if res[j] > res[i] + ew:
                res[j] = res[i] + ew
                if not added[j]:
                    added[j] = True
                    pq.append((res[j], j))
    return res, added

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(n):
        for j in range(k + 1):
            dp[i + 1][j] = dp[i][j]
            if j >= len(arrs[i]):
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - len(arrs[i])] + sums[i])
    return dp[n][k]

def main() -> None:
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        if t > k:
            arr = arr[:k]
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == "__main__":
    main()
