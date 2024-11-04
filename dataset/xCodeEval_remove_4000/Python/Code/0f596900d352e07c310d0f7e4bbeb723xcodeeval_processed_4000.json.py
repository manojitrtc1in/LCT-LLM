import sys
input = lambda: sys.stdin.readline().strip()
lis=lambda :list(map(int,input().split()))
sin=lambda :int(input())
many =lambda :map(int,input().split())





from math import ceil,sqrt,factorial,log
from collections import deque
from bisect import bisect_left










alp = "abcdefghijklmnopqrstuvwxyz"
ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

mod = 10**9 + 7
INF = 10**18



def solve():
    
    
    
    

    
    s = input()
    for (d, k) in zip("RGB", "rgb"):
        if s.find(d) < s.find(k):
            print("NO")
            break
    else:
        print("YES")





id0 = int(input())
for testis in range(id0):
    solve()

