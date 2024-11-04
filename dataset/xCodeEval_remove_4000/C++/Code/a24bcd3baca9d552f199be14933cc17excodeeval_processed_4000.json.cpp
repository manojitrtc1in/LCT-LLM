

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   





 
using namespace std;
using namespace __gnu_pbds;
 



























 
typedef long long ll;
typedef long long LL;
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
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int maxn = 5e5 + 10;
const int inf = 1e9 + 7;
const ld ll_inf = 8e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
 
ll bpow(int a, int b,ll mod = 1e9 + 7){
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
 
ll fact(ll n,ll mod = 1e9 + 7){
    ll fuc = 1;
    for(int i = 2;i <= n;++i){
        fuc = fuc * i % mod;
    }
    return fuc;
}
 
ll Cnk(ll n, ll r,ll mod = 1e9 + 7){
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
 
int n,a,b,w[300],h[300],s[300],dp[300][40020][3],ans = 1e9;
 
int main(){
    

    Random();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for(int i = 1;i <= n;++i){
        cin >> h[i];
        w[i] = min(h[i],h[i - 1]);
        s[i] = s[i - 1] + h[i];
    }
    memset(dp,127,sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 0,mx = min(s[i],a);j <= mx;++j){
            if(h[i] <= j){
                dp[i][j][0] = min(dp[i - 1][j - h[i]][0],dp[i - 1][j - h[i]][1] + w[i]);
            }
            if(h[i] <= b - s[i - 1] + j){
                dp[i][j][1] = min(dp[i - 1][j][0] + w[i],dp[i - 1][j][1]);
            }
        }
    }
    for(int i = 0;i <= a;++i){
        ans = min(ans,min(dp[n][i][0],dp[n][i][1]));
    }
    if(ans == 1e9){
        cout << -1;
    }
    else
        cout << ans;
}