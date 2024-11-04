import sys
from typing import List, Tuple

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

def solve(N: int, K: int, A: List[List[int]]) -> int:
    global best
    A_sum = [sum(a) for a in A]
    best = 0
    knapsack = [0] * (K + 1)
    recurse(0, N, knapsack)
    return best

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split('\n')
    N, K = map(int, lines[0].split())
    A = [list(map(int, line.split())) for line in lines[1:]]
    return N, K, A

def to_input_string(inputs: Tuple[int, int, List[List[int]]]) -> str:
    N, K, A = inputs
    res = []
    res.append(f"{N} {K}")
    for a in A:
        res.append(' '.join(str(x) for x in a))
    return '\n'.join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
    
