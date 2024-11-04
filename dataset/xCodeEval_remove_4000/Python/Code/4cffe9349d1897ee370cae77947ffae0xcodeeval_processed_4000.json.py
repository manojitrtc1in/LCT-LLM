




















import math

for _ in range(int(input())):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    nums.sort()
    MEX = 0
    MAX = nums[-1]
    for i in range(n):
        if(i == nums[i]):
            MEX += 1
        else:
            break
    if(MEX > MAX):
        print(n + k)
    else:
        if(k != 0 and math.ceil((MEX + MAX)/2) not in nums):
            n += 1
        print(n)
