import sys

input = lambda : sys.stdin.readline().strip()
lis = lambda : list( map( int , input().split() ) )
sin = lambda : int( input() )
many = lambda : map( int , input().split() )





from math import ceil , sqrt , factorial , log
from collections import deque
from bisect import bisect_left









alp = "abcdefghijklmnopqrstuvwxyz"
ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

mod = 10 ** 9 + 7
INF = 10 ** 18





def solve() :
    n , k  = many()
    kk = k
    ans = 0
    l = lis()

    p = [0]*32
    r = [0]*32


    for i in range(n):
        b = bin(l[i])[2:]
        for j in range(31):
            if l[i]&(1<<j):
                p[j]+=1

    for i in range(30, - 1, -1):
        if (n-p[i])<= kk:
            r[i] = 1
            kk-= (n-p[i])

    for i in range(30, -1 , -1):
        if (p[i]==n) or  r[i] > 0 :
            ans|=(1<<i)
    print(ans)


id0 = int( input() )
for testis in range( id0 ) :
    solve()
