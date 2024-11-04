import sys
from collections import defaultdict

N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

mp = defaultdict(int)
for num in a:
    mp[num] += 1

vs = []
for num, count in mp.items():
    if count > 1:
        vs.append(num)

ans = 0
for i in range(N):
    isok = False
    for elem in vs:
        if (elem & a[i]) == a[i]:
            isok = True
            break
    
    if isok:
        ans += b[i]

print(ans)
