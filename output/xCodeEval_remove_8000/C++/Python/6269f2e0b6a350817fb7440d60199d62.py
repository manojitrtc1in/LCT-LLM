from typing import List
from atcoder import modint1000000007

def max(a: int, b: int) -> int:
    if a < b:
        return b
    else:
        return a

def min(a: int, b: int) -> int:
    if a > b:
        return b
    else:
        return a

def chmax(a: int, b: int) -> bool:
    if a < b:
        a = b
        return True
    return False

def chmin(a: int, b: int) -> bool:
    if a > b:
        a = b
        return True
    return False

def solve(q: int, queries: List[int]) -> List[int]:
    res = []
    for n in queries:
        M = n // 4 + 1
        m = modint1000000007(M)
        if n % 4 <= 1:
            res.append((m * m).val())
        else:
            res.append((m * (m + 1)).val())
    return res

q = int(input())
queries = [int(input()) for _ in range(q)]
ans = solve(q, queries)
for a in ans:
    print(a)
