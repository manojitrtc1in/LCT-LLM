
 
using namespace std;
using namespace chrono;
 








































template <typename val1>
    void __f(const char* name, val1&& value) { 
    cout << name << " = " << value << endl; 
  }
template <typename val1, typename... values>
void __f( const char* names, val1&& value, values&&... multiplevalue) 
{
  const char* comma = strchr( names + 1, ','); cout.write(names, comma - names) << " = " << value << " "; __f(comma + 1, multiplevalue...); 
}
    
 
typedef   vector<int> vi;
typedef   vector< pair<int, int> > vii;
typedef   vector<long long> vl;
typedef   pair<int, int> pii;
typedef   pair<ll, ll> pll;
typedef   vector< pair<ll, ll> > vll;
typedef priority_queue<int, vector<int>, greater<int>> min_heapi;
typedef priority_queue<ll, vector<ll>, greater<ll>> min_heapli;
typedef priority_queue<int> max_heapi;
typedef priority_queue<ll> max_heapli;
typedef unordered_map<int, int> umapi;
typedef unordered_map<ll, ll> umapli;
 
 





 
typedef pair<ll, ll>	pl;
typedef pair <int,int> pii;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef priority_queue<int, vector<int>, greater<int>> min_heap32;
typedef priority_queue<ll, vector<ll>, greater<ll>> min_heap64;
typedef priority_queue<int> max_heap32;
typedef priority_queue<ll> max_heap64;
typedef unordered_map<int, int> umap32;
typedef unordered_map<ll, ll> umap64;
 
const ll INF2=0x3f3f3f3f;
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void id2(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} id2(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll id3(ll a, ll b) {ll arr[3]; id2(a, b, arr); return arr[0];} 

ll id0(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case 
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, id0(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

int cmp(int a,int b){return a>b;}


int bin_pow(int ind, int power){if(power == 0){return 1;}if(power & 1){return ind * bin_pow(ind,power - 1) % MOD;}else{return bin_pow((ind * ind) % MOD , power / 2) % MOD;}}








long long id1(long long *array,long long n){long long best = 0, sum = 0;for (long long  k = 0; k < n; k++) {sum = max(array[k],sum+array[k]);best = max(best,sum);}return  best ;}
void printBinary(int num){for(int i=10;i>=0;--i){cout<<((num>>i)&1);}cout<<endl;}








int id4(int n){if (n % 4 == 0)return n;if (n % 4 == 1)return 1;if (n % 4 == 2)return n + 1;return 0;}
string toBinary(long long x){if(x == 0)return "";else{string s = toBinary(x / 2);s.push_back(char('0' + x % 2));return s;}}


struct DSU {
	vector<int>par, ra;
	DSU(int n)
	{
		par.resize(n + 5); ra.resize(n + 5, 0);
		for (int i = 0; i <= n; i++)
			par[i] = i;
	}
	int get(int u)
	{
		if (par[u] == u)
			return u;
		return par[u] = get(par[u]);
		

        

        

        

        

        

	}
	void merge(int u, int v)
	{
		u = get(u), v = get(v);
		if (u == v) return;
		if (ra[v] > ra[u]){
			swap(u, v);
		}
		par[v] = u;
		if (ra[u] == ra[v])
			ra[u]++;
	}
}; 

















































 
 
























 


const ll L = 1e10;
const ll M = 1e4;
const ll N = 2e5+10;




using namespace __gnu_pbds;
 








void solve(){
	ll n, m, k, q;
	cin>>n>>m>>k>>q;
	vvi v(q, vi(2, 0));
	fi(0, q){
		cin>>v[i][0];
		cin>>v[i][1];
	}
	set<ll> a, b;
	ll ans = 0;
	for(int i = q-1; i>=0; i--){
		ll f = v[i][0], s = v[i][1];
		if(a.find(f)==a.end() and b.size()!=m){
			ans++;
		}
		else if(b.find(s)==b.end() and a.size()!=n){
			ans++;
		}
		a.insert(f);
		b.insert(s);
	}
	cout<<expo(k, ans, 998244353)<<endl;
}
	
int main() {
    fast;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    auto start1 = high_resolution_clock::now(); 




    ll tc=1, tc1=1;
    cin>>tc;
    while(tc--) {


        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

    cerr << "Time: " << duration.count() / 1000 << "ms"<< endl;

    return 0;
}

 
