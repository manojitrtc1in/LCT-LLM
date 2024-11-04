import sys
from collections import defaultdict
from itertools import accumulate

input = sys.stdin.read

def add_item(knapsack, size, sum_value):
    for k in range(K - size, -1, -1):
        knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum_value)

def recurse(start, end, knapsack):
    global best
    if start >= end:
        return

    if end - start == 1:
        sum_value = 0
        best = max(best, knapsack[K])

        for prefix in range(1, len(A[start]) + 1):
            sum_value += A[start][prefix - 1]
            best = max(best, sum_value + knapsack[K - prefix])

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

class DSum:
    @staticmethod
    def solve():
        global N, K, A, A_sum, best
        data = input().split()
        idx = 0
        N = int(data[idx])
        K = int(data[idx + 1])
        idx += 2
        A = []
        A_sum = []

        for i in range(N):
            t = int(data[idx])
            idx += 1
            A.append(list(map(int, data[idx:idx + t])))
            idx += t

            if t > K:
                A[i] = A[i][:K]

            A_sum.append(sum(A[i]))

        best = 0
        knapsack = [0] * (K + 1)
        recurse(0, N, knapsack)
        print(best)

if __name__ == "__main__":
    DSum.solve()
