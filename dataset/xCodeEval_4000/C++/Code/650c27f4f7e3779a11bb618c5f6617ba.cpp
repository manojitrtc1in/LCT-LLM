#include <bits/stdc++.h>

using namespace std;






#define ret return
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define be(x) x.begin()
#define en(x) x.end()
#define sz(x) x.size()
#define for0(i,n) for (long long  i = 0; i < (n); i++)
#define for1(i,n) for (long long i = 1; i < (n); i++)
#define rfor(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define rep(i,a,n) for (long long i = a; i < ll(n); i++)
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define fastIO() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define con continue
#define pb push_back
#define pob pop_back
#define watch(x) cout << (#x) << " is " << (x) << endl
#define ins insert
#define endl '\n'
#define len(s) (s).length()
#define gi greater<int>()
#define gll greater<long long>()
#define gstr greater<string>()
#define rast(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define rev reverse
#define fac fact
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define rs resize
#define last(a) a.back()
#define co count
#define ba(a) a.back()
#define um unordered_map


#ifdef _DEBUG
bool local = true;
#else
bool local = false;
#endif











const long double pi = 3.141592653589793238462643383279;
const long long mod1 = 1e9 + 7;
const long long mod2 = 998244353;
const long long MAX_LL = 9223372036854775807;
const long long MAX_INT = 2147483647;












long long gcd(long long a, long long b)
{
	if (b > a)
	{
		swap(a, b);
	} if (b == 0) ret a; ret(gcd(b, a % b));
}
long long lcm(long long a, long long b)
{
	if (b > a)
	{
		swap(a, b);
	} ret a / gcd(a, b) * b;
}
long long max(long long a, long long b)
{
	ret a < b ? b : a;
}
long long min(long long a, long long b)
{
	ret a > b ? b : a;
}
double getTime()
{
	ret clock() / (double)CLOCKS_PER_SEC;
};
long long count(string s, string a)
{
	long long n = len(s); long long m = len(a); long long r = 0; for0(i, n)
	{
		if (s[i] == a[0] && n - i >= m)
		{
			r++; for0(j, m)
			{
				if (a[j] != s[i + j])
				{
					r--; break;
				}
			}
		}
	}ret r;
}
long long fact(long long x, long long mod)
{
	if (x == 0) return 1; return (x * fact(x - 1, mod)) % mod;
}
int find(vector<int> a, int x)
{
	int n = sz(a); for0(i, n)
	{
		if (a[i] == x)
		{
			ret i;
		}
	}ret - 1;
}
long long fpow(long long b, long long m, long long mod)
{
	long long ans = 1 % mod; long long x = b; while (m != 0)
	{
		if (m % 2 == 1) ans *= x; ans %= mod; x *= x; x %= mod; m /= 2;
	}return ans;
}
long long ssum(long long a)
{
	int r = 0; while (a > 9)
	{
		r += a % 10; a /= 10;
	}r += a; ret r;
}
ostream& operator << (ostream& out, vector <char>& a)
{
	for (char j : a) out << j; out << endl; return out;
}
string nsys(int n, int k)
{
	string s = ""; while (n != 0)
	{
		int d = n % k; if (d < 10)s = to_string(d) + s; else
		{
			s = char(d + 'A' - 10) + s;
		}n /= k;
	}ret s;
}
int find(string s, string a)
{
	long long n = len(s); long long m = len(a); long long r = 0; for0(i, n)
	{
		if (s[i] == a[0] && n - i >= m)
		{
			if (r > 0) ret 1; r++; for0(j, m)
			{
				if (a[j] != s[i + j])
				{
					r--; break;
				}
			}
		}
	}ret r;
}
long long rnd(long long l, long long r)
{
	long long a = rand() % (r - l + 1) + l; ret a;
}
long long gcd_ext(long long a, long long b, long long& x, long long& y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd_ext(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
long long  phi(long long n)
{
	long long res = n;
	for (long long p = 2; p * p <= n; ++p)
	{
		if (n % p == 0)
			res -= res / p;
		while (n % p == 0)
			n /= p;
	}
	if (n > 1)
		res -= res / n;
	return res;
}
long long mtf(long long a, long long b, long long mod)
{
	ret((a % mod) * fpow((b % mod), (mod - 2), mod)) % mod;
}
long double sqrt1(long double x)
{
	long double l = 0, r = 1e9 + 1;
	for0(i, 128)
	{
		long double m = (l + r) / 2;
		if (m * m <= x)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	if (l * l <= x)
	{
		ret l;
	}
	else
	{
		ret r;
	}
}
long long vkl_iskl(long long r, long long n) {
	vector<long long> p;
	for (long long i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			p.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		p.push_back(n);

	long long sum = 0;
	for (long long msk = 1; msk < (static_cast<long long>(1) << p.size()); ++msk)
	{
		long long mult = 1,
			bits = 0;
		for (long long i = 0; i < (long long)p.size(); ++i)
			if (msk & (static_cast<long long>(1) << i))
			{
				++bits;
				mult *= p[i];
			}
		long long cur = r / mult;
		if (bits % 2 == 1)
			sum += cur;
		else
			sum -= cur;
	}
	return sum;
}
struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);
	}
};
vector<long long> z_function(string s)
{
	long long n = (long long)s.length();
	vector<long long> z(n);
	z[0] = sz(s);
	for (long long i = 1, l = 0, r = 0; i < n; ++i)
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}
vector<long long> p_function(string s)
{
	long long n = (long long)s.length();
	vector<long long> p(n);
	for (long long i = 1; i < n; ++i)
	{
		long long j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])  ++j;
		p[i] = j;
	}
	ret p;
}












typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef pair<double, double> pdd;
typedef long double ld;
typedef double D;
typedef vector<ld> vld;
typedef vector<pair<ld, ld>> vpld;
typedef string str;
typedef set<ll> sll;
typedef set<int> si;
typedef set<str> ss;
typedef set<pii> spii;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<str> mss;
typedef multiset<pii> mspii;
typedef multiset<pll> mspll;
typedef map<str, str> mps;
typedef map<int, int> mpi;
typedef map<ll, ll> mpll;
typedef map<int, vi> mpvi;
typedef map<int, vll> mpvll;
typedef map<char, int> mpci;
typedef multimap<ll, ll> mmpll;
typedef multimap<str, str> mmps;
typedef multimap<int, int> mmpi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<long double>> vvld;
typedef vector<vector<char>> vvc;
typedef vector<vs> vvs;
typedef vector<D> vD;
typedef set<pair<ll, ll>> spll;
typedef vector<bool> vb;
typedef set<char> sc;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<bool> qb;
typedef queue<pair<int, int>> qpii;
typedef vector < vector<pair<int, int>>> vvpii;
typedef vector < vector<pair<ll, ll>>> vvpll;












template <typename T>
istream& operator >> (istream& in, vector <T>& a)
{
	for (T& i : a) in >> i;
	return in;
}
template <typename T>
ostream& operator << (ostream& out, set <T>& a)
{
	out << a.size() << '\n';
	for (T i : a) out << i << ' ';
	cout << endl;
	return out;
}
template <typename T>
ostream& operator << (ostream& out, set <pair<T, T>>& a)
{
	out << a.size() << '\n';
	for (pair<T, T> i : a) out << i.fi << ' ' << i.se << endl;
	cout << endl;
	return out;
}
template <typename T>
ostream& operator << (ostream& out, multiset <T>& a)
{
	out << a.size() << '\n';
	for (T i : a) out << i << ' ';
	cout << endl;
	return out;
}
template <typename T1, typename T2>
istream& operator >> (istream& in, vector <pair<T1, T2>>& a)
{
	for (pair<T1, T2>& i : a) in >> i.fi >> i.se;
	return in;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
	for (auto i : a)
	{
		out << i << " ";
	}
	return out;
}
template <typename T1, typename T2>
ostream& operator << (ostream& out, vector <pair<T1, T2>>& a)
{
	for (pair<T1, T2> i : a) out << i.fi << " " << i.se << endl;
	return out;
}
template <typename T1>
ostream& operator << (ostream& out, vector <vector<T1>>& a)
{
	for (vector<T1> i : a)
	{
		for (T1 j : i) out << j << " ";
		out << endl;
	}
	return out;
}
template <typename T1, typename T2>
inline void amin(T1& a, T2 b)
{
	a = min(a, b);
}
template <typename T1, typename T2>
inline void amax(T1& a, T2 b)
{
	a = max(a, b);
}













ll n, a, b;
vvpll g;
vll dp;
map<ll,vll> mpl;

void dfs(ll v, ll pr)
{
	for (auto x : g[v])
	{
		if (x.first != pr)
		{
			dp[x.fi] = dp[v] ^ x.second;
			mpl[dp[x.fi]].push_back(v);
			dfs(x.fi, v);
		}
	}
}
ll dfs1(ll v, ll pr, ll sum)
{
	if (sz(mpl[sum]) >= 1)

	{
		ret 1;
	}
	ll r = 0;
	for (auto x : g[v])
	{
		if (x.first != pr && x.first!=b)
		{
			amax(r,dfs1(x.first, v, sum ^ x.se));
		}
	}
	ret r;
}



void solve()
{
	cin >> n >> a >> b;
	a--;
	b--;
	g.clear();
	dp.clear();
	mpl.clear();
	g.rs(n);
	dp.rs(n);
	for0(i, n - 1)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		g[x].push_back({ y,w });
		g[y].push_back({ x,w });
	}
	dfs(b, b);
	ll r=dfs1(a, a, 0);
	if (r)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}




int main()
{
	srand(time(0));
	fastIO();
	if (local)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	ll t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	if (local)
	{
		cout.precision(32);
		cout << endl << fixed << "time = " << getTime();
	}
}