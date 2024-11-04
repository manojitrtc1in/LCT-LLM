import sys
import itertools
from collections import deque
from typing import List, Tuple, Dict

def refill(k: int, left: List[Tuple[int, int, int]], right: List[Tuple[int, int, int]]) -> int:
    def comp(i: int, j: int) -> bool:
        return right[i][1] - left[i][0] < right[j][1] - left[j][0]

    idx = list(range(len(left)))
    heap = sorted(idx, key=comp)
    val = 0

    while heap and k > 0:
        i = heap.pop(0)

        if left[i][0] < right[i][1]:
            w = min(k, left[i][2])
            k -= w
            val += w * (right[i][1] - left[i][0])
    
    return val

def a176() -> int:
    n, m, k = map(int, sys.stdin.readline().split())
    a = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    val = 0
    for i in range(n):
        for j in range(n):
            if i != j:
                val = max(val, refill(k, a[i], a[j]))

    return val

if __name__ == "__main__":
    print(a176())
