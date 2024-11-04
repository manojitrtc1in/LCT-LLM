

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   

#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fr(i,a,b)       	        for(int i = (a); i <= (b); i++)
#define pb              	        push_back
#define f               	        first
#define se              	        second
#define pii             	        pair < int , int >
#define mp              	        make_pair
#define FIND(N,pos)     	        ((N) & (1 << (pos)))
#define sf(h)           	        scanf("%d",&h)
#define sff(h,b)        	        scanf("%d%d",&h,&b)
#define sfff(h,b,c)     	        scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)    		        for(int z = 1;z <= test;z++)
#define PRINT           	        printf("Case %d:\n",z)
#define en              	        "\n"
#define lwb             	        lower_bound
#define upb             	        upper_bound
#define IOS             	        ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      	        for(int i = (l);i <= (r);i++)
#define cno             	        cout<<"NO";return 0;
#define cye             	        cout<<"YES";return 0;
#define sz(x)           	        ((int)(x).size())
#define forn(i, n)          	    for(ll i=0;i<n;++i)
#define forl(i, a, b)       	    for(ll i=(a);i<=(b);++i)
#define ford(i, a, b)       	    for(int i=(a);i>=(b);--i)
#define forg(i, a, b, c)		    for(ll i=(a);i<=(b);i += (c))
#define FOR(i, a, b)		        for(ll i=(a);i<=(b);i++)
#define all(a)                      a.begin(),a.end()
#define fbo                         find_by_order
#define ofk                         order_of_key
 
typedef long long ll;
typedef long long LL;
typedef long double ld;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ll > sll;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef set < pll > spll;
typedef multiset < int > msi;
typedef multiset < ll > msll;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
template <typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int maxn = int(1.5 * 1e7);
const int inf = 1e9 + 7;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-9;
const int N = 1e6 + 7;
const int MAX = 3e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll bpow(ll x, ll y,ll mod = MOD) {
    if(y == 0){
        return 1ll;
    }
    ll res = 1;
    x = x % mod;
    while(y > 0) {
        if(y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
 
void Random(){
    unsigned int seed;
    asm("rdtsc" : "=A" (seed));
    srand(seed);
}
 
ll fact(ll n,int mod = 1e9 + 7){
    int fuc = 1;
    for(int i = 2;i <= n;++i){
        fuc = fuc * i % mod;
    }
    return fuc;
}
 
ll Cnk(ll n, ll r,int mod = 1e9 + 7){
    r = min(r,n - r);
    ll ans = 1;
    for(int i = n;i >= (n - r + 1);--i){
        ans = (ans * i) % mod;
    }
    for(int i = 1;i <= r;++i){
        ans = (ans * bpow(i,mod - 2,mod)) % mod;
    }
    return ans;
}

int n,p;
ll ans[N],t;
spll s;
sll q;
queue < ll > k;

int main(){
    IOS;
    Random();
    

    

    cin >> n >> p;
    for(int i = 1,x;i <= n;++i){
        cin >> x;
        s.insert(mp(x,i));
    }
    for(int i = 1;i <= n;++i){
        if(q.size() == 0 && k.empty()){
            t = (*s.begin()).f;
        }
        t += p;
        while(s.size() != 0 && (*s.begin()).f <= t){
            if(k.empty() || (*s.begin()).se < k.back()){
                k.push((*s.begin()).se);
            }
			else{
			    q.insert((*s.begin()).se);
			}
			s.erase(s.begin());
        }
        ans[k.front()] = t;
		k.pop();
		if(k.empty() && !q.empty()){
			k.push(*q.begin());
			q.erase(q.begin());
		}
    }
    for(int i = 1;i <= n;++i){
        cout << ans[i] << " ";
    }
}
 
 
 
 
 
 
 
 
 
 
 
 