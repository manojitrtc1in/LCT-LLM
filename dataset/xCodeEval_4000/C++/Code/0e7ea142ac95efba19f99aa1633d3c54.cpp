#include <bits/stdc++.h>
using namespace std;


#define st first
#define nd second
#define pb push_back
#define pp pop_back
#define all(x) (x).begin(), (x).end()
#define lb(a, b, c) lower_bound(a, b, c)
#define ub(a, b, c) upper_bound(a, b, c)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define ford(i, n) for (int i = (n) - 1; i >= 0; --i)
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

template<typename T = int>
using vv = vector<T>;

template<typename T1 = int, typename T2 = int>
using umap = unordered_map<T1, T2>;

template<typename T1 = int, typename T2 = int>
using uset = unordered_set<T1, T2>;

typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<str>      vs;
typedef vector<char>	vc;
typedef vector<db>		vdb;
typedef vector<ldb>		vldb;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<pdb>		vpdb;
typedef vector<pldb>	vpldb;
typedef vector<pil>		vpil;
typedef vector<pli>		vpli;
typedef vector<vi> 		vvi;


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


template<ll MOD = 1'000'000'007>
struct Modular
{
	ll value;
	static const ll MOD_VAL = MOD;
	
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
	
	/* this templates are just to get rid of warnings
	really should use MOD_ in these function signatures */
	template<ll MOD_>
	friend Modular<MOD> operator+(const Modular&, const Modular&);
	template<ll MOD_>
	friend Modular<MOD> operator-(const Modular&, const Modular&);
	template<ll MOD_>
	friend Modular operator-(const Modular&);
	template<ll MOD_>
	friend Modular operator*(const Modular&, const Modular&);
	template<ll MOD_>
	friend Modular operator/(const Modular&, const Modular&);
	template<ll MOD_>
	friend ostream& operator<<(ostream&, const Modular&);

	operator ll();

	bool operator==(const Modular&);
	bool operator!=(const Modular&);
};

typedef Modular<> mod;

/* scanf with template */
template<typename T> T scanf_t();

/* scanf template specializations */
template<>  int            scanf_t();
template<>  ll             scanf_t();
template<>  db             scanf_t();
template<>  ldb            scanf_t();
template<>  char           scanf_t();
template<>  float          scanf_t();
template<>  str 	       scanf_t();
str         scanf_t(int);  

/* short names for scanf template specializations */
int     (*si)()     =  scanf_t<int>;
ll      (*sl)()     =  scanf_t<ll>;
db      (*sdb)()    =  scanf_t<db>;
ldb     (*sldb)()   =  scanf_t<ldb>;
char    (*sc)()     =  scanf_t<char>;
float   (*sf)()     =  scanf_t<float>;
str 	   (*ss)()     =  scanf_t<str>;

/* printf template functions */
template<typename T> void printf_t(const T&, char='\n', FILE* = stdout);
template<typename T> void printf_t(const T*, char='\n', FILE* = stdout);
template<typename T> void printf_t(T*, char='\n', FILE* = stdout);
template<typename T1, typename T2> void printf_t(const pair<T1, T2>&, char='\n', FILE* = stdout);
template<typename T, typename Alloc, template<typename, typename> class Container>
void printf_t(const Container<T, Alloc>&, char='\n', FILE* = stdout);

/* varadic print that uses printf */
void print();
template<typename T> void print(const T&);
template<typename T, typename... Args> void print(const T&, const Args&...);
template<typename T> void print(T*, T*);
template<typename T> void print(T*, int);

/* variadic print to stderr that uses printf */
template<typename T>
void __dbg(const char*, const T&);
template<typename T, typename... Args>
void __dbg(const char*, const T&, const Args&...);
template<typename... Args>
void _dbg(const char*, const Args&...);
template<typename T>
void _dbg(const char*, T*, T*, char='\n', char=' ');
template<typename T>
void _dbg(const char*, T*, int, char='\n', char=' ');

/* when debugging to stderr, grab also names of variables */
#ifdef LOCAL
	#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define dbg(...) 13
#endif

/* read to array from standard input with scanf */
template<typename T> void in(T*, int);
/* read to standard C++ container with scanf and push_back */
template<typename T, typename Alloc, template<typename, typename> class Container>
void sv(Container<T, Alloc>&, int);
template<typename T, typename Alloc>
void sv(vector<T, Alloc>&, int);

/* write an array to standard output */
template<typename It> void out(It, It, char='\n', char=' ', FILE* = stdout);
template<typename It> void out(It, int, char='\n', char=' ', FILE* = stdout);
/* write standard C++ container to standard output */
template<typename Container> void pv(const Container&, char='\n', char=' ', FILE* = stdout);

/* debug functions */
template<typename T>
void print_bits(T x, int=0);

/* useful variables, functions, definitions*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define shuffle(a, b) shuffle(a, b, rng)
template<typename T> T rand(T a, T b);
template<typename T> T rand(T n);
template<typename It> It uniq(It begin, It end);
template<typename T> void uniq(vv<T>& v);

/* short names for printf template specializations */
void pi(const int&, char='\n');
void pl(const ll&, char='\n');
void pd(const db&, char='\n');
void pld(const ldb&, char='\n');
void pf(const float&, char='\n');
void pc(const char&, char='\n');
void ps(const str&, char='\n');

/* useful, general purpose algorithms */
ll russian(ll, ll, ll);
ll fastpow(ll, ll, ll);
ll slowpow(ll, ll, ll);
ll extgcd(ll, ll);
ll _gcd(ll, ll);
ll _lcm(ll, ll);
ll _inv(ll, ll);

/* useful constants */
const  int  INF   =  1e9;
const  ll   LINF  =  1e18;
const  ll   M     =  1e9 + 7;
// const  ll   M 	   =  998244353LL; 
const  ldb  PI    =  acos(-1);

const int N = 300 + 7;
int A[N][N];
pii res[N];

int main()
{	
	int n = si();
	rep (i, 1, n + 2)
		rep (j, 1, n + 1)
			A[i][j] = si();

	rep (i, 1, n + 1)
		res[i] = {INF, INF};

	rep (i, 1, n + 1)
	{
		rep (j, 1, n + 1)
		{
			auto it = find_if(A[n + 1] + 1, A[n + 1] + n + 1, [&](int a){
				return a <= i && a != j;
			});
			if (it != A[n + 1] + n + 1)
			{
				int val = find(A[j] + 1, A[j] + n + 1, *it) - A[j];
				if (val < res[j].st)
					res[j]=  {val, *it};
			}
		}
	}

	rep (i, 1, n + 1)
		pi(res[i].nd, ' ');

	return 0;
}

/* scanf template specilizations */
template<> int scanf_t() { int x; scanf("%d", &x); return x; }
template<> db scanf_t() { db x; scanf("%lf", &x); return x; }
template<> ll scanf_t() { ll x; scanf("%lld", &x); return x; }
template<> ldb scanf_t() { ldb x; scanf("%Lf", &x); return x; }
template<> char scanf_t() { char x; scanf(" %c", &x); return x; }
template<> float scanf_t() { float x; scanf("%f", &x); return x; }

/* printf template specilizations */
template<> void printf_t(const int& x, char end, FILE* out) { fprintf(out, "%d%c", x, end); }
template<> void printf_t(const ll& x, char end, FILE* out) { fprintf(out, "%lld%c", x, end); }
template<> void printf_t(const db& x, char end, FILE* out) { fprintf(out, "%.8lf%c", x, end); }
template<> void printf_t(const ldb& x, char end, FILE* out) { fprintf(out, "%.10Lf%c", x, end); }
template<> void printf_t(const float& x, char end, FILE* out) { fprintf(out, "%f%c", x, end); }
template<> void printf_t(const char& x, char end, FILE* out) { fprintf(out, "%c%c", x, end); }
template<> void printf_t(const str& x, char end, FILE* out) { fprintf(out, "%s%c", x.c_str(), end); }
template<> void printf_t(const char* x, char end, FILE* out) { fprintf(out, "%s%c", x, end); }
template<> void printf_t(char* x, char end, FILE* out) { fprintf(out, "%s%c", x, end); }
template<> void printf_t(const mod& x, char end, FILE* out) { printf_t(x.value, end, out); }
template<> void printf_t(const uint64_t& x, char end, FILE* out) { fprintf(out, "%lu%c", x, end); }
template<> void printf_t(const uint32_t& x, char end, FILE* out) { fprintf(out, "%u%c", x, end); }
template<> void printf_t(const bool& x, char end, FILE* out) { fprintf(out, "%d%c", x, end); }
template<> void printf_t(const long& x, char end, FILE* out) { fprintf(out, "%ld%c", x, end); }
template<typename T1, typename T2> void printf_t(const pair<T1, T2>& x, char end, FILE* out) { printf_t(x.st, ' ', out); printf_t(x.nd, end, out); }
template<typename T, typename Alloc, template<typename, typename> class Container>
void printf_t(const Container<T, Alloc>& v, char end, FILE* out) { pv(v, end, ' ', out); }

/* scanf str of unknown length */
template<>
str scanf_t()
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

	str res(s);
	free(s);
	return res;
}

/* make print() possible */
void print() { printf("\n"); }

/* variadic print base case */
template<typename T> void print(const T& last) { printf_t(last, '\n'); }

/* variadic print */
template<typename T, typename... Args>
void print(const T& first, const Args&... rest)
{
	printf_t(first, ' ');
	print(rest...);
}

/* print array from begin iterator to end iterator */
template<typename T>
void print(T* begin, T* end) { out(begin, end); }

/* print n elements from of array starting from begin iterator */
template<typename T>
void print(T* begin, int n) { out(begin, begin + n); }

/* variadic __dbg base case */
template<typename T>
void __dbg(const char* s, const T& x)
{
	fprintf(stderr, "%s = ", s);
	printf_t(x, ' ', stderr);
}

/* variadic __dbg */
template<typename T, typename... Args>
void __dbg(const char* s, const T& x, const Args&... rest)
{
	while (*s != ',')
		fprintf(stderr, "%c", *s++);
	fprintf(stderr, " = ");
	printf_t(x, '\0', stderr);
	fprintf(stderr, ",");
	__dbg(s + 1, rest...);
}

/* variadic _dbg - print braces around */
template<typename... Args>
void _dbg(const char* s, const Args&... rest)
{
	fprintf(stderr, "[ ");
	__dbg(s, rest...);
	fprintf(stderr, "]\n");
}

/* _dbg array from begin to end */
template<typename T>
void _dbg(const char* s, T* begin, T* end, char endl, char sep)
{
	fprintf(stderr, "[ ");
	while (*s != ',')
		fprintf(stderr, "%c", *s++);
	fprintf(stderr, " = ");
	out(begin, end, ' ', sep, stderr);
	fprintf(stderr, "]%c", endl);
}

/* _dbg n elements of array starting from begin */
template<typename T>
void _dbg(const char* s, T* begin, int n, char endl, char sep)
{
	_dbg(s, begin, begin + n, endl, sep);
}

/* scanf n variables of type T */
template<typename T>
void in(T* begin, int n)
{
	while (n--)
		*begin++ = scanf_t<T>();
}

/* scanf n variables of type T to standard C++ container and push them back */
template<typename T, typename Alloc, template<typename, typename> class Container>
void sv(Container<T, Alloc>& v, int n)
{
	auto it = std::back_inserter(v);
	while (n--)
		*it = scanf_t<T>();
}

/* little optimization */
template<typename T, typename Alloc>
void sv(vector<T, Alloc>& v, int n)
{
	v.reserve(n);
	auto it = std::back_inserter(v);
	while (n--)
		*it = scanf_t<T>();
}

/* printf array to standard output */
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

/* printf array to standard output */
template<typename It>
void out(It begin, int n, char endl, char sep, FILE* outs) { out(begin, begin + n, endl, sep, outs); }

/* printf standard C++ container to standard output */
template<typename Container>
void pv(const Container& v, char end, char sep, FILE* outs) { out(all(v), end, sep, outs); }

/* implementation short named functions for template specializations */
void  pi(const   int&     x, char end)  {  printf_t(x, end);  }
void  pl(const   ll&      x, char end)  {  printf_t(x, end);  }
void  pd(const   db&      x, char end)  {  printf_t(x, end);  }
void  pld(const  ldb&     x, char end)  {  printf_t(x, end);  }
void  pf(const   float&   x, char end)  {  printf_t(x, end);  }
void  pc(const   char&    x, char end)  {  printf_t(x, end);  }
void  ps(const   str&  x, char end)     {  printf_t(x, end);  }

/* pair<T1, T2> operators: +, -, +=, -=, *, *=, -(unary) */
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

/* russian peasants algorithm */
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

/* fast power - a^k % m */
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

/* fast power with russian peasants algorithm */
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

/* greatest common divisor of a and b */
ll _gcd(ll a, ll b)
{
	while (b)
		swap(a %= b, b);
	return a;
}

/* least common multiple of a and b */
ll _lcm(ll a, ll b)
{
	return a / _gcd(a, b) * b;
}

/* calculate inverse of a modulo */
ll _inv(ll a, ll p)
{
	return fastpow(a, p - 2, p);
}

/* extended Eucilean algorithm implementation - calculate a * k + b * l = GCD(a, b) */
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

/* print bits of number x */
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


template<ll MOD> Modular<MOD>::Modular(ll v) { value = v % MOD; if (value < 0) value += MOD; }
template<ll MOD> Modular<MOD>::Modular(ll a, ll b) : value(0) { *this += a; *this /= b; }

template<ll MOD> Modular<MOD>& Modular<MOD>::operator+=(const Modular& o)
{
	value += o.value;
	if (value >= MOD) value -= MOD;
	return *this;
}
template<ll MOD> Modular<MOD>& Modular<MOD>::operator-=(const Modular& o)
{
	value -= o.value;
	if (value < 0) value += MOD;
	return *this;
}
template<ll MOD> Modular<MOD>& Modular<MOD>::operator*=(const Modular& o)
{
	value = (ll)value * o.value % MOD;
	return *this;
}
template<ll MOD> Modular<MOD>& Modular<MOD>::operator/=(const Modular& o){ return *this *= o.inv(); }
template<ll MOD> Modular<MOD>& Modular<MOD>::operator++() { return *this += 1; }
template<ll MOD> Modular<MOD>& Modular<MOD>::operator--() { return *this -= 1; }

template<ll MOD>
Modular<MOD> exp(Modular<MOD> a, ll k)
{
	Modular<MOD> res = 1;
	while (k) { if (k & 1LL) res *= a; a *= a; k >>= 1; }
	return res;
}
template<ll MOD>
Modular<MOD> Modular<MOD>::inv() { return exp(value, MOD - 2); }

template<ll MOD> Modular<MOD> operator+(const Modular<MOD>& a, const Modular<MOD>& b) { return { a.value + b.value }; }
template<ll MOD> Modular<MOD> operator-(const Modular<MOD>& a, const Modular<MOD>& b) { return a -= b; }
template<ll MOD> Modular<MOD> operator-(const Modular<MOD>& a) { return 0 - a; }
template<ll MOD> Modular<MOD> operator*(const Modular<MOD>& a, const Modular<MOD>& b) { return a *= b; }
template<ll MOD> Modular<MOD> operator/(const Modular<MOD>& a, const Modular<MOD>& b) { return a /= b; }
template<ll MOD> ostream& operator<<(ostream& os, const Modular<MOD>& m) { os << m.value; return os; }

template<ll MOD> Modular<MOD>::operator ll() { return value; }

template<ll MOD> bool Modular<MOD>::operator==(const Modular& o) { return value == o.value; }
template<ll MOD> bool Modular<MOD>::operator!=(const Modular& o) { return value != o.value; }


template<typename T>
T rand(T a, T b)
{
	using dist = conditional_t<
		is_integral<T>::value,
		uniform_int_distribution<T>,
		uniform_real_distribution<T>
	>;
	return dist(a, b)(rng);
}


template<typename T>
T rand(T n)
{
	static_assert(is_integral<T>::value, "Only integral type supported!");
	return uniform_int_distribution<T>(0, n - 1)(rng);
}


template<typename It>
It uniq(It begin, It end)
{
	sort(begin, end);
	return unique(begin, end);
}


template<typename T>
void uniq(vv<T>& v) { v.erase(uniq(all(v)), v.end()); }
