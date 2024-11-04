import sys
from typing import List, Tuple

def dijkstra(adj_list: List[List[Tuple[int, int]]], start: int, start_dist: int) -> Tuple[List[int], List[bool]]:
    n = len(adj_list)
    added = [False] * n
    res = [float('inf')] * n
    res[start] = start_dist
    added[start] = True
    pq = [(start_dist, start)]
    while pq:
        d, u = pq.pop(0)
        if d > res[u]:
            continue
        for v, w in adj_list[u]:
            if res[u] + w < res[v]:
                res[v] = res[u] + w
                if not added[v]:
                    added[v] = True
                    pq.append((res[v], v))
    return res, added

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(k + 1):
            dp[i][j] = dp[i - 1][j]
            if j >= len(arrs[i - 1]):
                dp[i][j] = max(dp[i][j], dp[i - 1][j - len(arrs[i - 1])] + sums[i - 1])
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
