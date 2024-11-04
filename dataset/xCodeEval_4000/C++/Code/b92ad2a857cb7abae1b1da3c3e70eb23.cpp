

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   

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
#define SZ(x) x.size()
 
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
 
int m,n;
bool was[N];
map < pii , int > ma;
vi g[N],t;
 
void dfs(int v){
	was[v] = 1;
	for(int i = 0;i < g[v].size();++i){
		if(!was[g[v][i]]){
			

			dfs(g[v][i]);
		}
	}
	t.pb(v);
	

}
 
int main(){
    IOS;
    cin >> n >> m;
    for(int i = 1,x,y;i <= m;++i){
    	cin >> x >> y;
    	ma[mp(x,y)] = i;
    	g[x].pb(y);
    }
    for(int i = 1;i <= n;++i){
    	if(!was[i]){
    		dfs(i);
    	}
    }
    

    
    int pos = 0;
    for(int i = 1;i < t.size();++i){
    	if(ma.count(mp(t[i],t[i - 1]))){
    		pos = max(pos,ma[mp(t[i],t[i - 1])]);
    	}
    	else{
    		cout << -1;
    		return 0;
    	}
    }
    cout << pos;
}