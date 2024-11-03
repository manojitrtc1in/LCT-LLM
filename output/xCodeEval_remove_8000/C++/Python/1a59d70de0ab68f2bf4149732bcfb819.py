import sys
from typing import List, Tuple, Dict, Any

def get_gain(xs: List[int], l: int, r: int) -> int:
    len = len(xs) - l - r
    return xs[l + len // 2] if len % 2 else 0

def c388() -> None:
    n = int(input())
    xs = []
    for _ in range(n):
        row = list(map(int, input().split()))
        xs.append(row)
    
    k = sum(len(row) for row in xs)
    acc = sum(sum(row) for row in xs)
    
    left = [0] * n
    right = [0] * n
    left_acc = 0
    
    for j in range(k):
        imax = 0
        while len(xs[imax]) == left[imax] + right[imax]:
            imax += 1
        
        val = get_gain(xs[imax], left[imax], right[imax])
        
        for i in range(imax + 1, n):
            if left[i] + right[i] < len(xs[i]):
                g = get_gain(xs[i], left[i], right[i])
                if val < g:
                    val = g
                    imax = i
        
        if j % 2 == 1:
            right[imax] += 1
        else:
            left_acc += xs[imax][left[imax]]
            left[imax] += 1
    
    print(left_acc, acc - left_acc)

c388()
