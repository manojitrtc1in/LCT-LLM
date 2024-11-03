import sys
from typing import List, Tuple

def dijkstra(n: int, edges: List[List[Tuple[int, int]]], start: int) -> Tuple[List[int], List[bool]]:
    added = [False] * n
    res = [float('inf')] * n
    res[start] = 0
    added[start] = True
    pq = [(0, start)]
    while pq:
        d, i = pq.pop(0)
        if res[i] < d:
            continue
        for j, ew in edges[i]:
            if not added[j] or d + ew < res[j]:
                res[j] = d + ew
                added[j] = True
                pq.append((res[j], j))
    return res, added

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dps = [[0] * (k + 1) for _ in range(13)]
    def do_copy(dpi: int) -> None:
        dps[dpi + 1] = dps[dpi].copy()
    def add_to_knap(i: int, dpi: int) -> None:
        v = sums[i]
        k1 = len(arrs[i])
        for j in range(k, k1 - 1, -1):
            dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v)
    def rec(l: int, r: int, dpi: int) -> int:
        ans = 0
        carr = arrs[l]
        dp = dps[dpi]
        if l + 1 == r:
            ans = max(ans, dp[k])
            sm = 0
            for i in range(min(k, len(carr))):
                sm += carr[i]
                ans = max(ans, dp[k - i - 1] + sm)
        else:
            def do_split(l1: int, r1: int, l2: int, r2: int) -> int:
                do_copy(dpi)
                for i in range(l1, r1):
                    add_to_knap(i, dpi + 1)
                return rec(l2, r2, dpi + 1)
            m = (l + r) // 2
            ans = max(ans, do_split(l, m, m, r))
            ans = max(ans, do_split(m, r, l, m))
        return ans

    return rec(0, n, 0)

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split('\n')
    n, k = map(int, lines[0].strip().split())
    arrs = [list(map(int, line.strip().split())) for line in lines[1:]]
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

def main():
    stdin = sys.stdin
    stdout = sys.stdout
    n, k, arrs = from_input_string(stdin.read())
    result = solve(n, k, arrs)
    stdout.write(to_output_string(result))

if __name__ == "__main__":
    main()
