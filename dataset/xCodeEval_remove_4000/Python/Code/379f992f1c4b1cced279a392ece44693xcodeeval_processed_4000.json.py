import math
import sys
sys.setrecursionlimit(200006)












 


























t = int(input())
for t in range(t):
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))
    ans = sum(nums)
    ans += max(nums)
    ans += (n-1)
    ans -= min(nums)
    if(ans + 1 <= m):
        print("YES")
    else:
        print("NO")
