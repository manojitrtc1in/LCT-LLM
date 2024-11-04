import sys

input = lambda : sys.stdin.readline().strip()
lis = lambda : list( map( int , input().split() ) )
sin = lambda : int( input() )
many = lambda : map( int , input().split() )




import bisect
from math import ceil , sqrt , factorial , log
from collections import deque
from bisect import bisect_left









alp = "abcdefghijklmnopqrstuvwxyz"
ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

mod = 10 ** 9 + 7
INF = 10 ** 18





def solve() :
    n , k = map( int , input().split() )
    s = list( input() )
    d = {}
    p = [0]*26

    for i in range(n):
        x  = ord(s[i]) - ord('a')
        while x and k and p[x]!=1:
            p[x] = 1
            x-=1
            k-=1
    
    ans = ''
    for i in range(n):
        x =  ord(s[i])-ord('a')
        while x and p[x]==1:
            x-=1
        ans+=alp[x]

    print(ans)




id0 = int( input() )
for testis in range( id0 ) :
    solve()
