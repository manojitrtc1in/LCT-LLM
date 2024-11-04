#include <iostream>
#include <queue> 
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <list>
#include <stack>
#include <deque>
#include <cmath>
#include <string>
#include <string.h>
#include <iomanip>
#include <sstream> 
#include <set> 
using namespace std; 
#define rep(i,n)        for(int i = 0;  i < n ; ++i)
#define REP(i,a,b)      for(int i = a ; i <= b; ++i)
#define s(n)            scanf("%d",&n)
#define rev(i,n)        for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b)      for(int i = a ; i >= b ; --i)
#define INF             1000000000 
#define pp              pair<int,int> 
#define pb(a)           push_back(a)
#define ll              long long
#define vi              vector<int> 
#define mii             map<int,int> 
#define msi             map<string,int> 
#define vii             vector<vector<int> > 
#define vpp             vector<pair<int,int> > 
#define MOD             1000000007
#define pdd             pair<double,double>
#define LIM             20000000
int O_O = (1<<30)-1 ; 
struct O_O_O_O_O_O_O_O_O_O
{
    int v ; 
    int O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO ;  
};
int l[100001] , r[100001] , q[100001] ; 
O_O_O_O_O_O_O_O_O_O O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[4*100001] ; 
void O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO(int O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o , int a , int b ,int l , int r , int val)
{
    if(O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO != 0 )
    {
        O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v |= O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO ; 
        if(a != b)
        {
            O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO |= O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO; 
            O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o+1].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO |= O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO ; 
        }
        O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO = 0 ; 
    }
    if(l > b or r < a )
    {
        return ; 
    }
    if(a >= l and b <= r)
    {
        O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO |= val ; 
        O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v |= val ; 
        return ; 
    }
    O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO(2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o , a , (a+b)/2 , l , r , val) ; 
    O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO(2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o + 1, (a+b)/2 + 1 , b , l , r , val) ; 
    O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v = (O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v)&(O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o+1].v) ; 
    return ; 
}
int O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o(int O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o , int a , int b , int l , int r)
{
    int q1 , q2 ; 
    if(O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO != 0 )
    {
        O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v |= O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO ; 
        if(a != b)
        {
            O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO |= O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO; 
            O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o+1].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO |= O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO ; 
        }
        O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO = 0 ; 
    }
    if(l > b or r < a )
    {
        return O_O; 
    }
    if(a >= l and b <= r)
    {
        return O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v ; 
    }
    q1 = O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o(2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o , a , (a+b)/2 , l , r ); 
    q2 = O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o(2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o + 1, (a+b)/2 + 1 , b , l , r ) ; 
    O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v = (O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o].v)&(O_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_OO_O_O_O_O_O_O_O_O_O[2*O_O_O_O_O_O_O_O_OO_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o+1].v) ; 
    return (q1&q2) ; 
}
int main()
{
    ios_base::sync_with_stdio(0) ; 
    int n , m ; 
    cin >> n >> m ; 
    for(int _O_O_O_O_O_OO__OO_O__O_OOOOOO = 0 ; _O_O_O_O_O_OO__OO_O__O_OOOOOO < m ; ++_O_O_O_O_O_OO__OO_O__O_OOOOOO)
    {
        cin >> l[_O_O_O_O_O_OO__OO_O__O_OOOOOO] >> r[_O_O_O_O_O_OO__OO_O__O_OOOOOO] >> q[_O_O_O_O_O_OO__OO_O__O_OOOOOO] ; 
        O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO(1,1,n,l[_O_O_O_O_O_OO__OO_O__O_OOOOOO],r[_O_O_O_O_O_OO__OO_O__O_OOOOOO],q[_O_O_O_O_O_OO__OO_O__O_OOOOOO]) ; 
    }
    for(int _O_O_O_O_O_OO__OO_O__O_OOOOOO = 0 ; _O_O_O_O_O_OO__OO_O__O_OOOOOO < m ; ++_O_O_O_O_O_OO__OO_O__O_OOOOOO)
    {
        if(O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o(1,1,n,l[_O_O_O_O_O_OO__OO_O__O_OOOOOO],r[_O_O_O_O_O_OO__OO_O__O_OOOOOO]) != q[_O_O_O_O_O_OO__OO_O__O_OOOOOO])
        {
            cout << "NO" ;
            return 0 ; 
        }
    }
    cout << "YES\n" ; 
    for(int _O_O_O_O_O_OO__OO_O__O_OOOOOO = 0 ; _O_O_O_O_O_OO__OO_O__O_OOOOOO < n ; ++_O_O_O_O_O_OO__OO_O__O_OOOOOO)
    {
        cout << O_O_O_O_O_O_O_O_O_O_OOOOOOOOOOOOOOOOOOOOOO_________________O_OOOOOOOOOOOOO_________OOOOOOOOOOOOO_o_o_o(1,1,n,_O_O_O_O_O_OO__OO_O__O_OOOOOO+1,_O_O_O_O_O_OO__OO_O__O_OOOOOO+1) << " " ; 
    }
    return 0 ; 
}