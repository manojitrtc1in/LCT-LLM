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
    n = int(input())
    l =lis()
    f = [1]*n
    f[0] = l[0]
    r = [1]*n
    r[-1] = l[-1]
    mf = f[0]
    bf = 0
    mr = r[-1]
    br = n-1
    remf = -1
    remr = -1

    for i in range(1,n):
        f[i] = f[i-1]*l[i]
        if f[i]>mf:
            mf = f[i]
            bf = i
        if f[i] == 0:
            f[i] = 1
            remf = i
    for i in range(n-2 , -1 , -1):
        r[i] = r[i+1]*l[i]
        if r[i]>mr:
            mr = r[i]
            br = i
        if r[i]==0:
            r[i] =1
            remr = i
    print(*f)
    print(*r)
    print(mf , mr)
    if mf<=0 and mr<=0:
        print(n , 0)
    else:
        if mf>=mr:
            if remf!=-1 and remr!=-1:
                print(0 , n-1-bf )
            else:
                print(remf ,  )
        else:
            print(n-1-br , 0 )






def solve2():
    s = input()
    ss = set()
    c = 0
    n = len(s)
    for i in s:
        if i in ss:
            c+= len(ss)-1
            ss = set()
        else:
            ss.add(i)
    ans = (c + len(ss))

    if (n-ans)%2==0:
        print(ans)
    else:
        print(n)




id0 = int(input())
for testis in range(id0):
    solve2()

