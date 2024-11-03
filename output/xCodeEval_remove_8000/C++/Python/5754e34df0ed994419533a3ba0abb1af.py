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
    dps = [[0] * (k + 1) for _ in range(13)]
    for i in range(n):
        for j in range(k + 1):
            dps[0][j] = max(dps[0][j], dps[0][j - len(arrs[i])] + sums[i]) if j >= len(arrs[i]) else dps[0][j]
    for dpi in range(12):
        for i in range(n):
            v = sums[i]
            k1 = len(arrs[i])
            for j in range(k, k1 - 1, -1):
                dps[dpi + 1][j] = max(dps[dpi + 1][j], dps[dpi + 1][j - k1] + v)
    return dps[12][k]

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
    n, k, arrs = from_input_string(stdin.read())
    result = solve(n, k, arrs)
    stdout.write(to_output_string(result))

if __name__ == "__main__":
    main()
