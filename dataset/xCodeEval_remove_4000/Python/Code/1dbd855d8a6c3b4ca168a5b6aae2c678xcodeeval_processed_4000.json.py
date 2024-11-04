import math















t = int(input())
for t in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    a = 0
    b = 1
    maxNum = 0
    while(b < n):
        if(nums[b] != nums[a]):
            maxNum = max(maxNum, b-a)
            a = b
        b += 1
    maxNum = max(maxNum, b-a)
    if(maxNum > math.ceil(n/2)):
        print(n - ((n - maxNum)*2))
    else:
        if(n%2==0):
            print(0)
        else:
            print(1)
