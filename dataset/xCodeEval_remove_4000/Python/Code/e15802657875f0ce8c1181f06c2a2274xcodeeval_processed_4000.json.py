import math
import sys
sys.setrecursionlimit(200006)












 






















t = int(input())

for t in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    a = 0
    b = 1
    ans = [0] * n
    if(n == 1 or nums[-1] != nums[-2]):
        ans = -1
    else:
        while(b != n):
            if(b == a+1 and nums[b] != nums[a]):
                ans = -1
                break
            elif(nums[b] != nums[a]):
                ans[a] = b
                for i in range(a+1, b):
                    ans[i] = i
                a = b
            elif(b == n-1):
                ans[a] = b+1
                for i in range(a+1, n):
                    ans[i] = i
            b += 1
    if(ans == -1):
        print(ans)
    else:
        print(' '.join([str(num) for num in ans]))
