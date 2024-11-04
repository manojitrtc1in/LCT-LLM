


 

  

 

 

 

 

 


 

 

 

  

   






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

ll n,q;

int main(){
    IOS;
    Random();
    

    

    cin >> n >> q;
    for(ll i = 1,x;i <= q;++i){
        cin >> x;
        while(x % 2 == 0){
            x += (n - x / 2);
        }
        cout << (x + 1) / 2 << en;
    }
}
