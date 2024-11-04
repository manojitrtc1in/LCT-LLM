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
    m , n = many()
    ans = 0
    l = []
    for i in range(m):
        x = input()
        l.append(x)
    new = []
    for i in range(m):
        new.append(['.']*n)

    for i in range(n):
        x = m-1
        for j in range(m-1 , - 1, -1):
            if l[j][i]=='o':
                x = j-1
                new[j][i] = 'o'
            elif l[j][i]=='*':
                new[x][i] = '*'
                x-=1
    for i in new:
        print(''.join(i))



id0 = int( input() )
for testis in range( id0 ) :
    solve()
