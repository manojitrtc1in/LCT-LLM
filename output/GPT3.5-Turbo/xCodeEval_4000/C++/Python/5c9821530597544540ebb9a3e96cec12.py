import sys
from typing import List

def dijkstra(e: List[List[int]], start: int) -> List[int]:
    n = len(e)
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
                    pq.append((res[j], j))
                    added[j] = True
    return res

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(n):
        carr = arrs[i]
        for j in range(k + 1):
            dp[i + 1][j] = dp[i][j]
            if j >= len(carr):
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - len(carr)] + sums[i])
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
    result = solve(n, k, arrs)
    print(result)

if __name__ == "__main__":
    main()
