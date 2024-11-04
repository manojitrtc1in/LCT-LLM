

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   

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
#define all(a)              (a).begin(), (a).end()
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
const int mod = 1e9 + 7;
const ld pi = 3.14159265359;
 
ll fast_pow(int a, int b){
	ll res = a, ret = 1;
	while(b > 0){
		if(b % 2)
			ret = (ret * res) % mod;
		res = (res * res) % mod;
		b /= 2;
	}
	return ret % mod;
}
 
ll fact(ll n){
    if(n == 1 || n == 0)
        return 1;
    return ((n % mod) * (fact(n - 1) % mod) % mod);
}
 
ll Cnk(ll n, ll r){
    return (fact(n) * fast_pow((fact(r) * fact(n - r)) % mod, mod - 2)) % mod;
}
 

 
int n,a[N];
 
int main(){
    IOS;
    cin >> n;
    if(n < 3 || n % 2 == 0){
        cout << -1;
        return 0;
    }
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    int res = 0;
    for(int i = (n - 1) / 2;i >= 1;--i){
        int p = max(0,a[2 * i]);
        p = max(p,a[2 * i + 1]);
        a[i] = max(0,a[i] - p);
        a[2 * i] = max(0,a[2 * i] - p);
        a[2 * i + 1] = max(0,a[2 * i + 1] - p);
        res += p;
    }
    cout << res + a[1];
}