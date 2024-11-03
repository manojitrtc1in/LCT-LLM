import sys
from typing import List

def add_item(knapsack: List[int], size: int, sum: int) -> None:
    for k in range(K - size, -1, -1):
        knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum)

def recurse(start: int, end: int, knapsack: List[int]) -> None:
    if start >= end:
        return

    if end - start == 1:
        sum = 0
        global best
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

def solve() -> None:
    global N, K, A, A_sum, best
    N, K = map(int, input().split())
    A = []
    A_sum = []

    for _ in range(N):
        t = int(input())
        a = list(map(int, input().split()))
        if t > K:
            a = a[:K]
        A.append(a)
        A_sum.append(sum(a))

    best = 0
    knapsack = [0] * (K + 1)
    recurse(0, N, knapsack)
    print(best)

solve()
