

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   

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
#define fbo                         find_by_order
#define ofk                         order_of_key
 
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
typedef set < ll > sll;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef set < pll > spll;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int maxn = int(1.5 * 1e7);
const int inf = 1e9 + 7;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
 
ll bpow(int a, int b,int mod = 1e9 + 7){
	ll res = a, ret = 1;
	while(b > 0){
		if(b % 2)
			ret = (ret * res) % mod;
		res = (res * res) % mod;
		b /= 2;
	}
	return ret % mod;
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
        ans = (ans * bpow(i,mod - 2)) % mod;
    }
    return ans;
}
 
int t,n,m,a[100][3000],b[20][20],sum[(1 << 14)],dp[20][(1 << 14)];
pii h[2010];
 
int main(){
    IOS;
    Random();
    

    

    cin >> t;
    for(int i0 = 1;i0 <= t;++i0){
        cin >> n >> m;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                cin >> a[i][j];
                h[j].f = max(h[j].f,a[i][j]);
                h[j].se = j;
            }
        }
        sort(h,h + m);
        reverse(h, h + m);
        

        

        memset(b,0,sizeof(b));
        m = min(m,n);
        for(int i = 0;i < m; i++){
            for(int j = 0;j < n;++j){
                b[j][i] = a[j][h[i].se];
            }
        }
 
        
        

        

        for(int j = 0;j < m;++j){
            

            for(int sh = 0;sh < n;++sh){
                for(int mask = 0;mask < (1 << n);++mask){
                    int res = 0;
                    for(int k = 0;k < n;++k){
                        if(mask & (1 << ((k + sh) % n))){
                            res += b[k][j];
                        }
                    }
                    sum[mask] = max(sum[mask],res);
                    

                }
            }
            

            

            for(int mask = 0;mask < (1 << n);++mask){
                int rev = ((1 << n) - 1) ^ mask;
                for(int nmask = rev;; nmask = (nmask - 1) & rev){
                    dp[j + 1][nmask | mask] = max(dp[j][mask] + sum[nmask],dp[j + 1][mask | nmask]);
                    if(nmask == 0)
                        break;
                }
            }
            memset(sum,0,sizeof(sum));
            

            

        }
        

        cout << dp[m][(1 << n) - 1] << endl;
        memset(dp,0,sizeof(dp));
        memset(h,0,sizeof(h));
    }
}