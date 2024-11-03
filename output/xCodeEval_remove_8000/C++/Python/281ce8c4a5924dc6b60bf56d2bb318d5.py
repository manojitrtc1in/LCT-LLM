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
    dps = [[0] * (k + 1) for _ in range(13)]
    for i in range(n):
        sums[i] = sum(arrs[i])
    for i in range(n):
        carr = arrs[i]
        dp = dps[0]
        if i + 1 == n:
            ans = dp[k]
            sm = 0
            for j in range(min(k, len(carr))):
                sm += carr[j]
                ans = max(ans, dp[k - j - 1] + sm)
        else:
            def do_split(l1, r1, l2, r2):
                dpi = 0
                for j in range(l1, r1 - 1):
                    v = sums[j]
                    k1 = len(arrs[j])
                    for l in range(k, k1 - 1, -1):
                        dp[l] = max(dp[l], dp[l - k1] + v)
                return rec(l2, r2, dpi + 1)
            m = (i + n) // 2
            ans = max(do_split(i, m, m, n), do_split(m, n, i, m))
    return ans

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split("\n")
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
    inputs = from_input_string(stdin.read())
    stdout.write(to_output_string(solve(*inputs)))

main()
