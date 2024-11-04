


 

  

 

 

 

 

 


 

 

 

  

   



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
	while(b > 0){
		if(b % 2)
			ret = (ret * res) % mod;
		res = (res * res) % mod;
		b /= 2;
	}
	return ret;
}

ll fact(ll n){
    int mod = 1e9 + 7;
    if(n == 1 || n == 0)
        return 1;
    return ((n % mod) * (fact(n - 1) % mod) % mod);
}

ll Cnk(ll n, ll r){
    int mod = 1e9 + 7;
    return (fact(n) * fast_pow((fact(r) * fact(n - r)) % mod, mod - 2)) % mod;
}

int n,a[N];
stack < int > q;
vpii ans;

int main() {
    IOS;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i){
        while(q.size() < a[i]){
            q.push(i);
        }
        while(q.size() > a[i]){
            ans.pb(mp(q.top(),i - 1));
            q.pop();
        }
        if(i == n){
            while(!q.empty()){
                ans.pb(mp(q.top(),n));
                q.pop();
            }
        }
    }
    cout << ans.size() << en;
    for(int i = 0;i < ans.size();++i){
        cout << ans[i].f << " " << ans[i].se << en;
    }
}
