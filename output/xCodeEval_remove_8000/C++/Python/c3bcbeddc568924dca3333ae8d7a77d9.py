import sys
from typing import List

def solve(n: int, k: int, arrs: List[List[int]]) -> int:
    sums = [sum(arr) for arr in arrs]
    dps = [[0] * (k + 1) for _ in range(13)]
    
    def do_copy(dpi: int) -> None:
        dps[dpi + 1] = dps[dpi].copy()
    
    def add_to_knap(i: int, dpi: int) -> None:
        v = sums[i]
        k1 = len(arrs[i])
        for j in range(k, k1 - 1, -1):
            dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v)
    
    def rec(l: int, r: int, dpi: int) -> int:
        ans = 0
        carr = arrs[l]
        dp = dps[dpi]
        
        if l + 1 == r:
            ans = max(ans, dp[k])
            _sum = 0
            for i in range(min(k, len(carr))):
                _sum += carr[i]
                ans = max(ans, dp[k - i - 1] + _sum)
        else:
            m = (l + r) // 2
            do_copy(dpi)
            for i in range(l, m):
                add_to_knap(i, dpi + 1)
            ans = max(ans, rec(m, r, dpi + 1))
            do_copy(dpi)
            for i in range(m, r):
                add_to_knap(i, dpi + 1)
            ans = max(ans, rec(l, m, dpi + 1))
        
        return ans
    
    return rec(0, n, 0)

def main() -> None:
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        if t > k:
            arr = arr[:k]
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == "__main__":
    main()
