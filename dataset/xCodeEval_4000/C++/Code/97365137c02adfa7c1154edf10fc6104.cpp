#include <bits/stdc++.h>
using namespace std;


#define st first
#define nd second
#define pb push_back
#define pp pop_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define len(x) (int)(x).size()
#define low(x) ((x) & (-x)) 

#define ispow(x) low(x) == x 

#define subm(m, mask) for (int m = (mask); m; m = (m - 1) & (mask)) 

#define pct(x) __builtin_popcount(x) 

#define bits(x) (31 - __builtin_clz(x)) 



typedef long long	ll;
typedef double 	db;
typedef long double ldb;
typedef complex<db> cd;
typedef string      str;

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef pair<db, db>	pdb;
typedef pair<ldb, ldb>	pldb;
typedef pair<int, ll>	pil;
typedef pair<ll, int>	pli;

typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<string>	vs;
typedef vector<char>	vc;
typedef vector<db>		vdb;
typedef vector<ldb>		vldb;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<pdb>		vpdb;
typedef vector<pldb>	vpldb;
typedef vector<pil>		vpil;
typedef vector<pli>		vpli;


template<typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& a, const pair<T1, T2>& b);
template<typename T1, typename T2>
pair<T1, T2>& operator+=(pair<T1, T2>& a, const pair<T1, T2>& b);
template<typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p);
template<typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& a, const pair<T1, T2>& b);
template<typename T1, typename T2>
pair<T1, T2>& operator-=(pair<T1, T2>& a, const pair<T1, T2>& b);
template<typename T1, typename T2, typename T3>
pair<T1, T2> operator*(const pair<T1, T2>& p, T3 mult);
template<typename T1, typename T2, typename T3>
pair<T1, T2> operator*(T3 mult, const pair<T1, T2>& p);


template<int MOD = 7>
struct Modular
{
	int value;
	static const int MOD_VAL = MOD;
	
	Modular(ll=0);
	Modular(ll, ll);

	Modular exp(Modular, ll);
	Modular inv();

	Modular& operator+=(const Modular&);
	Modular& operator-=(const Modular&);
	Modular& operator*=(const Modular&);
	Modular& operator/=(const Modular&);
	Modular& operator++();
	Modular& operator--();
	
	
	template<int MOD_>
	friend Modular<MOD> operator+(const Modular&, const Modular&);
	template<int MOD_>
	friend Modular<MOD> operator-(const Modular&, const Modular&);
	template<int MOD_>
	friend Modular operator-(const Modular&);
	template<int MOD_>
	friend Modular operator*(const Modular&, const Modular&);
	template<int MOD_>
	friend Modular operator/(const Modular&, const Modular&);
	template<int MOD_>
	friend ostream& operator<<(ostream&, const Modular&);

	operator int();

	bool operator==(const Modular&);
	bool operator!=(const Modular&);
};

typedef Modular<> mod;


template<typename T> T scanf_t();


template<>  int            scanf_t();
template<>  ll             scanf_t();
template<>  db             scanf_t();
template<>  ldb            scanf_t();
template<>  char           scanf_t();
template<>  float          scanf_t();
template<>  string 	       scanf_t();
string      scanf_t(int);  


int     (*si)()     =  scanf_t<int>;
ll      (*sl)()     =  scanf_t<ll>;
db      (*sdb)()    =  scanf_t<db>;
ldb     (*sldb)()   =  scanf_t<ldb>;
char    (*sc)()     =  scanf_t<char>;
float   (*sf)()     =  scanf_t<float>;
string  (*ss)(int)  =  scanf_t;


template<typename T> void printf_t(const T&, char='\n', FILE* = stdout);
template<typename T> void printf_t(const T*, char='\n', FILE* = stdout);
template<typename T> void printf_t(T*, char='\n', FILE* = stdout);
template<typename T1, typename T2> void printf_t(const pair<T1, T2>&, char='\n', FILE* = stdout);
template<typename T, typename Alloc, template<typename, typename> class Container>
void printf_t(const Container<T, Alloc>&, char='\n', FILE* = stdout);


void print();
template<typename T> void print(const T&);
template<typename T, typename... Args> void print(const T&, const Args&...);


void _dbg();
template<typename T> void _dbg(const T&); 
template<typename T, typename... Args> void _dbg(const T&, const Args&...);
template<typename... Args> void dbg(const Args&...);


template<typename T> void in(T*, int);

template<typename T, typename Alloc, template<typename, typename> class Container>
void sv(Container<T, Alloc>&, int);
template<typename T, typename Alloc>
void sv(vector<T, Alloc>&, int);


template<typename It> void out(It, It, char='\n', char=' ', FILE* = stdout);

template<typename Container> void pv(const Container&, char='\n', char=' ', FILE* = stdout);


void pi(const int&, char='\n');
void pl(const ll&, char='\n');
void pd(const db&, char='\n');
void pld(const ldb&, char='\n');
void pf(const float&, char='\n');
void pc(const char&, char='\n');
void ps(const string&, char='\n');


ll russian(ll, ll, ll);
ll fastpow(ll, ll, ll);
ll slowpow(ll, ll, ll);
ll extgcd(ll, ll);
ll _gcd(ll, ll);
ll _lcm(ll, ll);
ll _inv(ll, ll);


template<typename T>
void print_bits(T x, int=0);


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const  int  INF   =  1e9;
const  ll   LINF  =  1e18;
const  ll   M     =  1e9 + 7;

const int C = 20;
vi G[C], cur;
int masks[C];
bool dp[1 << C], vis[C];
int mask;

void dfs(int v)
{
	vis[v] = true;
	mask |= 1 << v;
	cur.pb(v);

	trav (s, G[v])
		if (!vis[s])
			dfs(s);
}

int count()
{
	vi sub;
	subm (m, mask)
		sub.pb(m);
	reverse(all(sub));

	int res = 0;
	trav (m, sub)
	{
		trav (v, cur)
			if (m & 1 << v)
				dp[m] |= dp[m ^ 1 << v] & ((m & masks[v] & mask) == 0);
		if (dp[m])
			res = max(res, pct(m));
	}
	return res;
}

int solve()
{
	int n = si();
	string s = ss(n), t = ss(n);

	auto get = [](char c) { return c - 'a'; };

	forn (i, n)
		if (s[i] != t[i])
		{
			int a = get(s[i]);
			int b = get(t[i]);
			G[a].pb(b);
			G[b].pb(a);
			masks[a] |= 1 << b;
		}

	int res = 0;
	dp[0] = true;
	forn (i, C)
		if (!vis[i])
		{
			mask = 0;
			cur.clear();
			dfs(i);
			int tmp = count();
			res += 2 * len(cur) - 1 - tmp;
		}

	fill(vis, vis + C, false);
	fill(masks, masks + C, 0);
	fill(dp, dp + (1 << C), false);
	forn (i, C) G[i].clear();

	return res;
}

int main()
{
	int t = si();
	while (t--)
		print(solve());

	return 0;
}


template<> int scanf_t() { int x; scanf("%d", &x); return x; }
template<> ll scanf_t() { ll x; scanf("%lld", &x); return x; }
template<> db scanf_t() { db x; scanf("%lf", &x); return x; }
template<> ldb scanf_t() { ldb x; scanf("%Lf", &x); return x; }
template<> char scanf_t() { char x; scanf(" %c", &x); return x; }
template<> float scanf_t() { float x; scanf("%f", &x); return x; }

string scanf_t(int n) { char x[n + 7]; scanf("%s", x); return string(x); }


template<> void printf_t(const int& x, char end, FILE* out) { fprintf(out, "%d%c", x, end); }
template<> void printf_t(const ll& x, char end, FILE* out) { fprintf(out, "%lld%c", x, end); }
template<> void printf_t(const db& x, char end, FILE* out) { fprintf(out, "%.8lf%c", x, end); }
template<> void printf_t(const ldb& x, char end, FILE* out) { fprintf(out, "%.10Lf%c", x, end); }
template<> void printf_t(const float& x, char end, FILE* out) { fprintf(out, "%f%c", x, end); }
template<> void printf_t(const char& x, char end, FILE* out) { fprintf(out, "%c%c", x, end); }
template<> void printf_t(const string& x, char end, FILE* out) { fprintf(out, "%s%c", x.c_str(), end); }
template<> void printf_t(const char* x, char end, FILE* out) { fprintf(out, "%s%c", x, end); }
template<> void printf_t(char* x, char end, FILE* out) { fprintf(out, "%s%c", x, end); }
template<> void printf_t(const mod& x, char end, FILE* out) { printf_t(x.value, end, out); }
template<> void printf_t(const uint64_t& x, char end, FILE* out) { fprintf(out, "%lu%c", x, end); }
template<> void printf_t(const uint32_t& x, char end, FILE* out) { fprintf(out, "%u%c", x, end); }
template<> void printf_t(const bool& x, char end, FILE* out) { fprintf(out, "%d%c", x, end); }
template<> void printf_t(const long& x, char end, FILE* out) { fprintf(out, "%ld%c", x, end); }
template<typename T1, typename T2> void printf_t(const pair<T1, T2>& x, char end, FILE* out) { fprintf_t(x.st, ' ', out); printf_t(x.nd, end, out); }
template<typename T, typename Alloc, template<typename, typename> class Container>
void printf_t(const Container<T, Alloc>& v, char end, FILE* out) { pv(v, end, ' ', out); }


template<>
string scanf_t()
{
	int size = 8;
	char* s = (char*)malloc(size * sizeof(char));

	char c;
	while (isspace(c = getchar()));
	*s = c;

	int i = 1;
	while (!isspace(c = getchar()))
	{
		s[i++] = c;
		if (i == size)
			s = (char*)realloc(s, size *= 2);
	}
	s[i] = '\0';

	string res(s);
	free(s);
	return res;
}


void print() { printf("\n"); }


template<typename T> void print(const T& last) { printf_t(last, '\n'); }


template<typename T, typename... Args>
void print(const T& first, const Args&... rest)
{
	printf_t(first, ' ');
	print(rest...);
}


void _dbg() {}


template<typename T> void _dbg(const T& last) { printf_t(last, ' ', stderr); }


template<typename T, typename... Args>
void _dbg(const T& first, const Args&... rest)
{
	printf_t(first, ' ', stderr);
	_dbg(rest...);
}


template<typename... Args>
void dbg(const Args&... args)
{
	fprintf(stderr, "[ ");
	_dbg(args...);
	fprintf(stderr, "]\n");
}


template<typename T>
void in(T* begin, int n)
{
	while (n--)
		*begin++ = scanf_t<T>();
}


template<typename T, typename Alloc, template<typename, typename> class Container>
void sv(Container<T, Alloc>& v, int n)
{
	auto it = std::back_inserter(v);
	while (n--)
		*it = scanf_t<T>();
}


template<typename T, typename Alloc>
void sv(vector<T, Alloc>& v, int n)
{
	v.reserve(n);
	auto it = std::back_inserter(v);
	while (n--)
		*it = scanf_t<T>();
}


template<typename It>
void out(It begin, It end, char endl, char sep, FILE* outs)
{
	if (begin == end)
	{
		fprintf(outs, "%c", endl);
		return;
	}	
	while (next(begin) != end)
		printf_t(*begin++, sep, outs);
	printf_t(*begin, endl, outs);
}


template<typename Container>
void pv(const Container& v, char end, char sep, FILE* outs) { out(all(v), end, sep, outs); }


void  pi(const   int&     x, char end)  {  printf_t(x, end);  }
void  pl(const   ll&      x, char end)  {  printf_t(x, end);  }
void  pd(const   db&      x, char end)  {  printf_t(x, end);  }
void  pld(const  ldb&     x, char end)  {  printf_t(x, end);  }
void  pf(const   float&   x, char end)  {  printf_t(x, end);  }
void  pc(const   char&    x, char end)  {  printf_t(x, end);  }
void  ps(const   string&  x, char end)  {  printf_t(x, end);  }


template<typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& a, const pair<T1, T2>& b) { return { a.st + b.st, a.nd + b.nd }; }
template<typename T1, typename T2>
pair<T1, T2>& operator+=(pair<T1, T2>& a, const pair<T1, T2>& b) { a.st += b.st; a.nd += b.nd; return a; }
template<typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p) { return { -p.st, -p.nd }; }
template<typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& a, const pair<T1, T2>& b) { return { a.st - b.st, a.nd - b.nd }; }
template<typename T1, typename T2>
pair<T1, T2>& operator-=(pair<T1, T2>& a, const pair<T1, T2>& b) { a.st -= b.st; a.nd -= b.nd; return a; }
template<typename T1, typename T2, typename T3>
pair<T1, T2> operator*(const pair<T1, T2>& p, T3 mult) { return {p.st * mult, p.nd * mult}; }
template<typename T1, typename T2, typename T3>
pair<T1, T2> operator*(T3 mult, const pair<T1, T2>& p) { return {p.st * mult, p.nd * mult}; }


ll russian(ll a, ll k, ll m)
{
	ll res = 0LL;
	while (k)
	{
		if (k & 1LL)
			res = (res + a) % m;
		a = (a + a) % m;
	}
	return res;
}


ll fastpow(ll a, ll k, ll m)
{
	ll res = 1LL;
	while (k)
	{
		if (k & 1LL)
			res = (res * a) % m;
		a = (a * a) % m;
		k >>= 1;
	}
	return res;
}


ll slowpow(ll a, ll k, ll m)
{
	ll res = 1LL;
	while (k)
	{
		if (k & 1LL)
			res = russian(res, a, m);
		a = russian(a, a, m);
		k >>= 1;	
	}
	return res;
}


ll _gcd(ll a, ll b)
{
	while (b)
		swap(a %= b, b);
	return a;
}


ll _lcm(ll a, ll b)
{
	return a / _gcd(a, b) * b;
}


ll _inv(ll a, ll p)
{
	return fastpow(a, p - 2, p);
}


ll extgcd(ll a, ll b, ll& k, ll& l)
{
	if (b == 0)
	{
		k = 1; l = 0;
		return a;
	}
	ll res = extgcd(b, a % b, l, k);
	l -= a / b * k;
	return res;
}


template<typename T>
void print_bits(T x, int force_len)
{
	assert(0 <= force_len && force_len <= 64);
	static char s[64];
	int i = 63;
	if (force_len)
		while (force_len--)
			s[i--] = '0' + (x & 1),
			x >>= 1;
	else
		while (x)
			s[i--] = '0' + (x & 1),
			x >>= 1;
	printf("%s\n", s + i + 1);
}


template<int MOD> Modular<MOD>::Modular(ll v) { value = v % MOD; if (value < 0) value += MOD; }
template<int MOD> Modular<MOD>::Modular(ll a, ll b) : value(0) { *this += a; *this /= b; }

template<int MOD> Modular<MOD>& Modular<MOD>::operator+=(const Modular& o)
{
	value += o.value;
	if (value >= MOD) value -= MOD;
	return *this;
}
template<int MOD> Modular<MOD>& Modular<MOD>::operator-=(const Modular& o)
{
	value -= o.value;
	if (value < 0) value += MOD;
	return *this;
}
template<int MOD> Modular<MOD>& Modular<MOD>::operator*=(const Modular& o)
{
	value = (ll)value * o.value % MOD;
	return *this;
}
template<int MOD> Modular<MOD>& Modular<MOD>::operator/=(const Modular& o){ return *this *= o.inv(); }
template<int MOD> Modular<MOD>& Modular<MOD>::operator++() { return *this += 1; }
template<int MOD> Modular<MOD>& Modular<MOD>::operator--() { return *this -= 1; }

template<int MOD>
Modular<MOD> exp(Modular<MOD> a, ll k)
{
	Modular<MOD> res = 1;
	while (k) { if (k & 1LL) res *= a; a *= a; k >>= 1; }
	return res;
}
template<int MOD>
Modular<MOD> Modular<MOD>::inv() { return exp(value, MOD - 2); }

template<int MOD> Modular<MOD> operator+(const Modular<MOD>& a, const Modular<MOD>& b) { return { a.value + b.value }; }
template<int MOD> Modular<MOD> operator-(const Modular<MOD>& a, const Modular<MOD>& b) { return a -= b; }
template<int MOD> Modular<MOD> operator-(const Modular<MOD>& a) { return 0 - a; }
template<int MOD> Modular<MOD> operator*(const Modular<MOD>& a, const Modular<MOD>& b) { return a *= b; }
template<int MOD> Modular<MOD> operator/(const Modular<MOD>& a, const Modular<MOD>& b) { return a /= b; }
template<int MOD> ostream& operator<<(ostream& os, const Modular<MOD>& m) { os << m.value; return os; }

template<int MOD> Modular<MOD>::operator int() { return value; }

template<int MOD> bool Modular<MOD>::operator==(const Modular& o) { return value == o.value; }
template<int MOD> bool Modular<MOD>::operator!=(const Modular& o) { return value != o.value; }
