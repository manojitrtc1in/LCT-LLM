from typing import List, Tuple
from collections import deque

def solve(q: int, queries: List[int]) -> List[int]:
    result = []
    for n in queries:
        M = n // 4 + 1
        if n % 4 <= 1:
            result.append((M * M) % 1000000007)
        else:
            result.append((M * (M + 1)) % 1000000007)
    return result

q = int(input())
queries = []
for _ in range(q):
