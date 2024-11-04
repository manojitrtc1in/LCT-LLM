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
    n = int( input() )
    l = lis()



def solve2() :
    n , k = map( int , input().split() )
    a = lis()
    a.sort()
    b = n - 2 * k
    total = sum( a[:b] )
    if k > 0 :
        for i in range(n-1 , (n-k)-1 , -1):
            total+= a[i-k]//a[i]
    print( total )



id0 = int( input() )
for testis in range( id0 ) :
    solve2()
