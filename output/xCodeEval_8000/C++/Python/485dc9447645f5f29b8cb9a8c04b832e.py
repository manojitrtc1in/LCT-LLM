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
            if res[j] > res[i] + ew:
                res[j] = res[i] + ew
                if not added[j]:
                    added[j] = True
                    pq.append((res[j], j))
    return res, added

def solve(N: int, K: int, A: List[List[int]]) -> int:
    A_sum = [sum(a) for a in A]
    best = 0
    knapsack = [0] * (K + 1)
    def add_item(knapsack: List[int], size: int, sum: int) -> None:
        for k in range(K - size, -1, -1):
            knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum)

    def recurse(start: int, end: int, knapsack: List[int]) -> None:
        nonlocal best
        if start >= end:
            return
        if end - start == 1:
            sum = 0
            best = max(best, knapsack[K])
            for prefix in range(1, len(A[start]) + 1):
                sum += A[start][prefix - 1]
                best = max(best, sum + knapsack[K - prefix])
            return
        mid = (start + end) // 2
        state = knapsack[:]
        for i in range(start, mid):
            add_item(state, len(A[i]), A_sum[i])
        recurse(mid, end, state)
        state = knapsack[:]
        for i in range(mid, end):
            add_item(state, len(A[i]), A_sum[i])
        recurse(start, mid, state)
    
    recurse(0, N, knapsack)
    return best

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split("\n")
    N, K = map(int, lines[0].strip().split())
    A = [list(map(int, x.strip().split())) for x in lines[1:]]
    return N, K, A

def to_input_string(inputs: Tuple[int, int, List[List[int]]]) -> str:
    N, K, A = inputs
    res = []
    res.append(f"{N} {K}")
    for a in A:
        res.append(" ".join(str(x) for x in a))
    return "\n".join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)

def main():
    stdin = sys.stdin
    stdout = sys.stdout
    N, K, A = from_input_string(stdin.read())
    result = solve(N, K, A)
    stdout.write(to_output_string(result))

if __name__ == "__main__":
    main()
