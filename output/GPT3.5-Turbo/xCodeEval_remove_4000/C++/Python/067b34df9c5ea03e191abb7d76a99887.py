import sys
from typing import List, Tuple

def dijkstra(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(n):
        carr = arrs[i]
        for j in range(k + 1):
            dp[i + 1][j] = dp[i][j]
            if j >= len(carr):
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - len(carr)] + sums[i])
            for l in range(1, min(j + 1, len(carr) + 1)):
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - l] + sum(carr[:l]))
    return dp[n][k]

def solve(n: int, queries: List[Tuple[int, List[int]]]) -> List[int]:
    res = []
    for k, arrs in queries:
        res.append(dijkstra(n, k, arrs))
    return res

def main() -> None:
    n = int(input())
    queries = []
    for _ in range(n):
        k = int(input())
        arrs = []
        for _ in range(k):
            arrs.append(list(map(int, input().split())))
        queries.append((k, arrs))
    res = solve(n, queries)
    for ans in res:
        print(ans)

if __name__ == "__main__":
    main()
