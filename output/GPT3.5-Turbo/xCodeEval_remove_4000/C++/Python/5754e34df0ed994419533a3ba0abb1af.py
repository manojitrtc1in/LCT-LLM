import sys
from typing import List, Tuple

def dijkstra(n: int, e: List[List[Tuple[int, int]]], start: int, start_dist: int) -> Tuple[List[int], List[bool]]:
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
        sums[i] = sum(arrs[i])
    for i in range(n):
        carr = arrs[i]
        dp = dps[0]
        if i+1 == n:
            ans = dp[k]
            sm = 0
            for j in range(min(k, len(carr))):
                sm += carr[j]
                ans = max(ans, dp[k-j-1] + sm)
        else:
            dp1 = dps[1]
            for j in range(k+1):
                dp1[j] = dp[j]
            for j in range(k+1):
                dp[j] = 0
            for j in range(len(carr)):
                v = carr[j]
                k1 = len(carr)
                for j1 in range(k, k1-1, -1):
                    dp[j1] = max(dp[j1], dp[j1-k1] + v)
    return dps[0][k]

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split('\n')
    n, k = map(int, lines[0].strip().split())
    arrs = [list(map(int, x.strip().split())) for x in lines[1:]]
    return n, k, arrs

def to_input_string(inputs: Tuple[int, int, List[List[int]]]) -> str:
    n, k, arrs = inputs
    res = []
    res.append(f"{n} {k}")
    for arr in arrs:
        res.append(" ".join(str(x) for x in arr))
    return "\n".join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)

def main():
    stdin = sys.stdin
    stdout = sys.stdout
    n, k, arrs = from_input_string(stdin.read())
    result = solve(n, k, arrs)
    stdout.write(to_output_string(result))

if __name__ == "__main__":
    main()
