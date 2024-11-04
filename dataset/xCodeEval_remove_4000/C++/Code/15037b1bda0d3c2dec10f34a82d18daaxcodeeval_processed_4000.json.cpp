

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   


 
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
 
int n,m,q,b[110][110];
ppiipii a[N];
 
void rec(int x,int y){
    vi h;
    if(x == 1){
        for(int i = 1;i < m;++i){
            h.pb(b[y][i]);
        }
        b[y][1] = b[y][m];
        for(int i = 2;i <= m;++i){
            b[y][i] = h[i - 2];
        }
    }
    else{
        for(int i = 1;i < n;++i){
            h.pb(b[i][y]);
        }
        b[1][y] = b[n][y];
        for(int i = 2;i <= n;++i){
            b[i][y] = h[i - 2];
        }
    }
}
 
int main() {
    IOS;
    cin >> n >> m >> q;
    for(int i = 1;i <= q;++i){
        cin >> a[i].f.f;
        if(a[i].f.f == 1 || a[i].f.f == 2){
            cin >> a[i].f.se;
        }
        else{
            cin >> a[i].f.se >> a[i].se.f >> a[i].se.se;
        }
    }
    for(int i = q;i >= 1;--i){
        if(a[i].f.f == 1 || a[i].f.f == 2){
            rec(a[i].f.f,a[i].f.se);
        }
        else{
            

            b[a[i].f.se][a[i].se.f] = a[i].se.se;
        }
    }
    for(int i = 1;i <= n;++i,cout << endl){
        for(int j = 1;j <= m;++j,cout << " "){
            cout << b[i][j];
        }
    }
}