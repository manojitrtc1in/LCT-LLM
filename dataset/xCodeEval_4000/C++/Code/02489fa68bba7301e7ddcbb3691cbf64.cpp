


 

  

 

 

 

 

 


 

 

 

  

   

#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b)       	for(int i = (a); i <= (b); i++)
#define pb              	push_back
#define f               	first
#define se              	second
#define pii             	pair < int , int >
#define mp              	make_pair
#define LOGMAX          	17
#define FIND(N,pos)     	((N) & (1 << (pos)))
#define sf(h)           	scanf("%d",&h)
#define sff(h,b)        	scanf("%d%d",&h,&b)
#define sfff(h,b,c)     	scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)    		for(int z = 1;z <= test;z++)
#define PRINT           	printf("Case %d:\n",z)
#define en              	"\n"
#define lwb             	lower_bound
#define upb             	upper_bound
#define IOS             	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      	for(int i = (l);i <= (r);i++)
#define cno             	cout<<"NO";return 0;
#define cye             	cout<<"YES";return 0;
#define sz(x)           	((int)(x).size())
#define forn(i, n)          	for(ll i=0;i<n;++i)
#define forl(i, a, b)       	for(ll i=(a);i<=(b);++i)
#define ford(i, a, b)       	for(int i=(a);i>=(b);--i)
#define forg(i, a, b, c)		for(ll i=(a);i<=(b);i += (c))

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
const int inf = 1e9 + 7;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

ll fast_pow(int a, int b,int mod = 1e9 + 7){
	ll res = a, ret = 1;
	while(b > 0){
		if(b % 2)
			ret = (ret * res) % mod;
		res = (res * res) % mod;
		b /= 2;
	}
	return ret % mod;
}

ll fact(ll n,int mod = 1e9 + 7){
    if(n==1 || n==0) return 1;
    return ((n%mod)*(fact(n-1)%mod)%mod);
}

ll Cnk(ll n, ll r,int mod = 1e9 + 7){
    return (fact(n) * fast_pow((fact(r) * fact(n - r)) % mod, mod - 2)) % mod;
}

const int b[] = {2,3,5,7,11,13,17,19};

ll n,a[MAX],cnt[MAX],dp[MAX],ans[MAX];
vll s[MAX];


void resheto() {
	for (int i = 1 ; i <= 1e5 ; i++) {
		for (int j = i ; j <= 1e5 ; j += i) {
			s[j].pb(i);
		}
	}
}

int main() {
    IOS;
    cin >> n;
    resheto();
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i){
		for (auto it : s[a[i]]) {
			cnt[it]++;
		}
    }
    for(int i = 1;i <= 1e5;++i){
        dp[i] = (fast_pow(2,cnt[i]) - 1 + MOD) % MOD;
    }
    for(int i = 1e5;i >= 1;--i){
        ans[i] = dp[i];
        for(int j = 2 * i;j <= 1e5;j += i){
            ans[i] = (ans[i] - ans[j] + MOD) % MOD;
        }
    }
    cout << ans[1];
}