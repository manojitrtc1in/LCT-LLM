

























using namespace std;






























double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };


template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a < t2.a; else return t1.b < t2.b; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }





















































inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return (x >> 31) | (-x >> 31); }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }







template<typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i < v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i < sz; i++) cout << a[i] << " "; cout << endl; }








inline ll binpow(ll x, ll n){ ll res = 1; while (n){ if (n & 1)res *= x; x *= x; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(int a, int b){ return a / gcd(a, b)*(ll)b; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
inline ll lcm(ll a, ll b, ll c){ return lcm(lcm(a, b), c); }
inline ll lcm(int a, int b, int c){ return lcm(lcm(a, b), (ll)c); }

inline ll max(ll a, ll b){ return (a > b) ? a : b; }
inline int max(int a, int b){ return (a > b) ? a : b; }
inline double max(double a, double b){ return (a > b) ? a : b; }
inline ll max(ll a, ll b, ll c){ return max(a, max(b, c)); }
inline int max(int a, int b, int c){ return max(a, max(b, c)); }
inline double max(double a, double b, double c){ return max(a, max(b, c)); }
inline ll min(ll a, ll b){ return (a < b) ? a : b; }
inline int min(int a, int b){ return (a < b) ? a : b; }
inline double min(double a, double b){ return (a < b) ? a : b; }
inline ll min(ll a, ll b, ll c){ return min(a, min(b, c)); }
inline int min(int a, int b, int c){ return min(a, min(b, c)); }
inline double min(double a, double b, double c){ return min(a, min(b, c)); }

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }











int fact[100010];
int revf[100010];
bool e[100010];
int C(int n, int m)
{
	if (n < m) return 0;
	return (((fact[n] * 1ll * revf[m]) % mod) * revf[n - m]) % mod;
}
int *divs[100010];
int buff[1000000];
int *curp = buff;
int divss[100010];
map<pair<int, int>, int> m;

int prime[100010];
vector<int> primes;
void id1(int n)
{
	int t = (n*1.2) / log(1.0*n);
	primes.reserve(n < 5000 ? 1000 : t);
	for (int i = 2; i <= n; ++i)
	{
		if (prime[i] == 0)
		{
			primes.push_back(i);
			prime[i] = i;
		}
		for (int j = 0; j < primes.size() && i * primes[j] <= n && primes[j] <= prime[i]; ++j)
		{
			prime[i * primes[j]] = primes[j];
		}
	}
}
int foo(int n, int f)
{
	return (fact[n - 1] * 1ll * revf[n - f]) % mod;
}
int powmod(ll x)
{
	int n = mod - 2;
	ll res = 1;
	while (n)
	{
		if (n & 1)
		{
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	id1(100000);
	fact[0] = 1;
	revf[0] = 1;
	for (int i = 1; i <= 100000; ++i)
	{
		fact[i] = (fact[i - 1] * 1ll * i) % mod;
		revf[i] = powmod(fact[i]);
	}
	for (int i = 2; i <= 100000; ++i)
	{
		divs[i] = curp;
		int *a = curp;
		int p = prime[i];
		int t = i / p;
		e[i] = !e[t];
		if (prime[i] != i)
		{
			int siz = divss[t];
			memcpy(a, divs[t], siz * 4);
			divss[i] = siz;
			if (p != prime[t])
			{
				divss[i] += siz + 1;
				for (int j = 0; j < siz; ++j)
				{
					a[j + siz] = a[j] * p;
				}
				a[siz + siz] = p;
			}
		}
		else
		{
			a[0] = i;
			divss[i] = 1;
		}
		curp += divss[i];
	}
	DBN(clock());

	int q;
	cin >> q;
	while (q--)
	{
		int f, n;
		cin >> n >> f;
		if (f == 1)
		{
			cout << (n == 1) << '\n';
			continue;
		}
		int ans = foo(n, f);
		int siz = divss[n];
		int *end = divs[n] + siz;
		for (int* beg = divs[n]; beg != end; ++beg)
		{
			int p = *beg;
			int q = n / p;
			if (q < f) continue;

			int t = foo(q, f);
			if (e[p])
			{
				ans -= t;
				if (ans < 0) ans += mod;
			}
			else
			{
				ans += t;
				if (ans >= mod) ans -= mod;
			}
		}
		ans = (ans * 1ll * revf[f - 1]) % mod;
		cout << ans << '\n';
	}
	return 0;
}
