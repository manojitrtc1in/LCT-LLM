from typing import List
from atcoder import modint1000000007

def max_sum(n: int) -> int:
    M = n // 4 + 1
    m = modint1000000007(M)
    if n % 4 <= 1:
        return (m * m).val()
    else:
        return (m * (m + 1)).val()

def solve(q: int, nums: List[int]) -> List[int]:
    res = []
    for n in nums:
        res.append(max_sum(n))
    return res

q = int(input())
nums = []
for _ in range(q):
    n = int(input())
    nums.append(n)

ans = solve(q, nums)
for a in ans:
    print(a)
