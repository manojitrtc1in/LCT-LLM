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
    n , m  = many()
    l = []
    for i in range(n):
        x = list(input())
        l.append(x)

    for j in range(m):
        
        p = n-1
        cc = 0
        c = 0
        d = []
        for i in range(n-1 , -1 , -1):
            if l[i][j] =='o':
                d.append(c)
                c = 0
            elif l[i][j]=='*':
                c+=1
        d.append(c)


        
        for i in range( n-1 , - 1, -1):
            if cc>=len(d):
                break
            if l[i][j]=='o':
                cc+=1
            else:
                if d[cc]!=0:
                    l[i][j]='*'
                    d[cc]-=1
                else:
                    l[i][j] = '.'


    for i in l:
        print(''.join(i))




id0 = int( input() )
for testis in range( id0 ) :
    solve()
