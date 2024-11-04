import sys
from typing import List, Tuple
from collections import defaultdict

def minimum_sum(n: int, k: int, nums: List[int]) -> int:
    ans = sys.maxsize
    t = defaultdict(bool)
    a = defaultdict(list)
    
    for i in range(n):
        temp = nums[i]
        cnt = 0
        while temp:
            a[temp].append(cnt)
            t[temp] = True
            temp //= 2
            cnt += 1
    
    for i in t:
        if len(a[i]) < k:
            continue
        a[i].sort()
        ans = min(ans, sum(a[i][:k]))
    
    return ans

if __name__ == "__main__":
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    result = minimum_sum(n, k, nums)
    print(result)
