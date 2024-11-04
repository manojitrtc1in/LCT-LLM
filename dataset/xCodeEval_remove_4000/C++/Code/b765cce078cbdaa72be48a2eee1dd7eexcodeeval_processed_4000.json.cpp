


 

  

 

 

 

 

 


 

 

 

  

   



using namespace std;



























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
const int MOD = 998244353;
const ld pi = 3.14159265359;

ll fast_pow(int a, int b){
    int mod = 1e9 + 7;
	ll res = a, ret = 1;
	while(b>0){
		if(b%2)
			ret = (ret*res)%mod;
		res = (res*res)%mod;
		b/=2;
	}
	return ret;
}

ll fact(ll n){
    int mod = 1e9 + 7;
    if(n==1 || n==0) return 1;
    return ((n%mod)*(fact(n-1)%mod)%mod);
}

ll Cnk(ll n, ll r){
    int mod = 1e9 + 7;
    return (fact(n) * fast_pow((fact(r) * fact(n - r)) % mod, mod - 2)) % mod;
}

int n;
ll cnt[3000][3000];
int x[3000],y[3000];

int main() {
    IOS;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            int x1 = x[i] - x[j];
            int y1 = y[i] - y[j];
            int gc = __gcd (x1, y1);
            x1 /= gc;
            y1 /= gc;
            x1 += 200;
            y1 += 200;
            cnt[x1][y1] ++;
        }
        for (int j = i + 1; j <= n; j ++) {
            int x1 = x[i] - x[j];
            int y1 = y[i] - y[j];
            int gc = __gcd (x1, y1);
            x1 /= gc;
            y1 /= gc;
            x1 += 200;
            y1 += 200;
            if (!cnt[x1][y1]){
                continue;
            }
            ans += cnt[x1][y1] * (cnt[x1][y1] - 1) / 2;
            cnt[x1][y1] = 0;
        }
    }
    cout << 1ll * n * (n - 1) * (n - 2) / 6ll - ans;
}