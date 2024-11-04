import math
import sys
sys.setrecursionlimit(200006)












 

























t = int(input())
for t in range(t):
    a,b,c,x,y = map(int, input().split())
    x = max(0, x-a)
    y = max(0, y-b)
    if(c >= x + y):
        print("YES")
    else:
        print("NO")
