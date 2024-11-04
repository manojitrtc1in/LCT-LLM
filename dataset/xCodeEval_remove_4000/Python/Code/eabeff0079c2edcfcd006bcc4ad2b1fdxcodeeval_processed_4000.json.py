import sys

input = lambda : sys.stdin.readline().strip()
lis = lambda : list( map( int , input().split() ) )
sin = lambda : int( input() )
many = lambda : map( int , input().split() )













alp = "abcdefghijklmnopqrstuvwxyz"
ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

mod = 10 ** 9 + 7
INF = 10 ** 18





def solve() :
    n = int( input() )
    a = list( map( int , input().split() ) )
    st , en = -1 , -1
    jj = False
    for i in range( n - 1 ) :
        if a[i] == a[i + 1] :
            if jj :
                en = i+1
            else :
                st = i
                en = i+1
                jj = True
    if st == en == -1 :
        print( 0 )
    else :
        ans = en - st
        if ans == 1 :
            print(0)
        elif ans==2:
            print(1)
        else:
            ans -= 2
            print( ans )




id0 = int( input() )
for testis in range( id0 ) :
    solve()
