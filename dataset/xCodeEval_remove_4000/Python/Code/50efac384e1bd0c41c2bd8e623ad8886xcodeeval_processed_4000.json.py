import sys

input = lambda : sys.stdin.readline().strip()
lis = lambda : list( map( int , input().split() ) )
sin = lambda : int( input() )
many = lambda : map( int , input().split() )













alp = "abcdefghijklmnopqrstuvwxyz"
ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

mod = 10 ** 9 + 7
INF = 10 ** 18


import collections



import bisect
from collections import Counter
import math

from math import sqrt


def id0(n) :
    p = int( math.log( n , 2 ) )
    return int( pow( 2 , p ) )

def solve():
    input()
    n , k = many()
    ll = lis()
    l = []
    pre = -1
    for i in range(n):
        if ll[i]!=pre:
            l.append(ll[i])
            pre = ll[i]
    print(l)
    s = set()
    p = []
    rep = -1
    for i in l:
        if i in s:
            rep = i
            break
        else:
            p.append(i)
            s.add(i)

    print(p)
    for q in range(k):
        a, b = many()
        if a not in s or b not in s:
            print("NO")
        else:
            x = p.index(a)
            y = p.index(b)
            r = len(p)
            if rep==-1:
                if x<y:
                    print("YES")
                else:
                    print("NO")
            else:
                if a == rep:
                    if x < y :
                        print( "YES" )
                    else :
                        print( "NO" )
                elif b==rep:
                    print( "YES" )
                else:
                    if x < y :
                        print( "YES" )
                    else :
                        print( "NO" )

from collections import OrderedDict
def solve2():
    s = input()
    p = sin()

    fre = Counter()
    for i in range(len(s)):
        
        
        
        

        if s[i] in fre:
            fre[s[i]]+=1
        else:
            fre[s[i]] = 1
    su = 0
    for i in s:
        su += ord(i[0])- ord('a')+1
    ss = set(s)

    
    for i in alp[::-1]:
        
        c = fre[i]
        if su<=p:
            break
        x = ord(i) - ord('a')
        
        ext = min(fre[i], (su-p + (x+1)-1)//(x+1) )
        fre[i]-=ext
        su -= ext*(x+1)


    ans = ''
    for i in s:
        if fre[i]>0:
            fre[i]-=1
            ans+= i

    print(ans)





id1 = int( input() )

for testis in range( id1 ) :
    solve2()