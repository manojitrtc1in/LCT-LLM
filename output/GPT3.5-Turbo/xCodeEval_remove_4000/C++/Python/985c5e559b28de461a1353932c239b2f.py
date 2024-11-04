import sys
from typing import List

def dijkstra(e: List[List[int]], start: int, start_dist: int) -> List[int]:
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
    return res

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
        state = knapsack.copy()
        for i in range(start, mid):
            add_item(state, len(A[i]), A_sum[i])
        recurse(mid, end, state)
        state = knapsack.copy()
        for i in range(mid, end):
            add_item(state, len(A[i]), A_sum[i])
        recurse(start, mid, state)
    
    recurse(0, N, knapsack)
    return best

def main() -> None:
    N, K = map(int, input().split())
    A = []
    for _ in range(N):
        t = int(input())
        a = list(map(int, input().split()))
        if t > K:
            a = a[:K]
        A.append(a)
    result = solve(N, K, A)
    print(result)

if __name__ == "__main__":
    main()
