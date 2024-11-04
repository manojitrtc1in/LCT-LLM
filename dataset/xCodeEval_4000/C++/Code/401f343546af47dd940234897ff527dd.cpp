

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   

#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,a,b)       for(int i = (a); i <= (b); i++)
#define pb              push_back
#define f               first
#define se              second
#define pii             pair < int , int >
#define mp              make_pair
#define LOGMAX          17
#define FIND(N,pos)     ((N) & (1 << (pos)))
#define sf(h)           scanf("%d",&h)
#define sff(h,b)        scanf("%d%d",&h,&b)
#define sfff(h,b,c)     scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)     for(int z = 1;z <= test;z++)
#define PRINT           printf("Case %d:\n",z)
#define en              "\n"
#define lwb             lower_bound
#define upb             upper_bound
#define IOS             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      for(int i = (l);i <= (r);i++)
#define SZ(x) 			x.size()
#define forl(i, a, b)   for(ll i=(a);i<=(b);++i)
#define ford(i, a, b)   for(int i=(a);i>=(b);--i)
 
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
 
const int maxn = int(1.5 * 1e7);
const int inf = ~0U >> 1;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
 
int n,a[N],k,xc,yc;
bool was[110][110];
 
bool check(pair < int , pii > h){
    for(int i = h.se.f;i <= h.se.se;++i){
        if(was[h.f][i]){
            return 1;
        }
    }
    return 0;
}
 
int main(){
    IOS;
    cin >> n >> k;
    yc = xc = (k + 1) / 2;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        int mn = inf;
        pair < int , pii > v = mp(0,mp(0,0));
        for(int x = 1;x <= k;x++){
            for(int y = 1;y + a[i] - 1 <= k;++y){
                int len = 0;
                bool q = 0;
                for(int y1 = y;y1 <= y + a[i] - 1;++y1){
                    if(was[x][y1]){
                        len = inf + 100;
                        y = y1;
                        q = 1;
                        break;
                    }
                    len += abs(xc - x) + abs(yc - y1);
                }
                if(q)
                    continue;
                if(len < mn){
                    mn = len;
                    v = mp(x,mp(y,y + a[i] - 1));
                }
                else if(len == mn){
                    if(v.f > x || v.f == x && y < v.se.f){
                        v = mp(x,mp(y,y + a[i] - 1));
                    }
                }
            }
        }
        if(((v.f > k || v.f < 1) || (v.se.f > k || v.se.f < 1) || (v.se.se > k || v.se.se < 1)) || check(v)){
            cout << -1 << en;
            

        }
        else{
            cout << v.f << " " << v.se.f << " " << v.se.se << en;
            for(int i = v.se.f;i <= v.se.se;++i){
                was[v.f][i] = 1;
            }
            
        }
    }
}