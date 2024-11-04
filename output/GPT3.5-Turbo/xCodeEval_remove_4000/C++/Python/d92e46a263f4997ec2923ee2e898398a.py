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

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    return dijkstra(n, k, arrs)

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split('\n')
    n, k = map(int, lines[0].split())
    arrs = [list(map(int, line.split())) for line in lines[1:]]
    return n, k, arrs

def to_input_string(inputs: Tuple[int, int, List[List[int]]]) -> str:
    n, k, arrs = inputs
    res = []
    res.append(f"{n} {k}")
    for arr in arrs:
        res.append(' '.join(str(x) for x in arr))
    return '\n'.join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
