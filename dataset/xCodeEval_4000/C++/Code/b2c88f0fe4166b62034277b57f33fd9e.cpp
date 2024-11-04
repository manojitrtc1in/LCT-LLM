




#define FILE_NAME "C:\\Users\\Double\\Documents\\Visual Studio 2015\\Projects\\acm\\acm\\#model.cpp"

#if 1






#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>


#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <typeinfo>
using namespace std;
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define per(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define all(x) (x).begin(), (x).end()
#define si size()
#define sz(x) ((int)(x).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pbmp(a, b) pb(mp((a), (b)))
#define fi first
#define se second
#define ms(a, b) memset((a), (b), sizeof(a))
#define cp(a, b) memcpy((a), (b), sizeof(a))
#define rush() for (int iCase = 1, TCase = RD(); iCase <= TCase; ++iCase)
#define IOSS0 std::ios::sync_with_stdio(false)
#define sqr(x) ((x) * (x))
#define cub(x) ((x) * (x) * (x))
typedef double db;
typedef long double ld;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<string, int> PSI;
typedef pair<db, db> PDD;
typedef pair<db, int> PDI;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PSI> VPSI;
typedef vector<PDD> VPDD;
typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<db, db> MDD;
typedef map<string, int> MSI;
typedef queue<int> QI;
typedef queue<PII> QPII;
const db  eps = 1e-9;
const db  pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int mod2 = 1000000006;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
template<typename T> inline bool RD(T&v) { char c; bool n; while (c = getchar(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = getchar(), c >= '0' && c <= '9') v = (v << 3) + (v << 1) + c - '0'; if (n) v *= -1; return true; }
template<typename T> inline bool RD(T&a, T&b) { return RD(a) && RD(b); }
template<typename T> inline bool RD(T&a, T&b, T&c) { return RD(a, b) && RD(c); }
template<typename T> inline bool RD(T&a, T&b, T&c, T&d) { return RD(a, b, c) && RD(d); }
template<typename T> inline bool RD(T&a, T&b, T&c, T&d, T&e) { return RD(a, b, c, d) && RD(e); }
template<typename T> inline bool RD(T&a, T&b, T&c, T&d, T&e, T&f) { return RD(a, b, c, d, e) && RD(f); }
inline int RD() { int v; RD(v); return v; }
char BUF[1 << 15], *HEAD = BUF, *TAIL = BUF; inline char getchar_buffered() { return HEAD == TAIL && (TAIL = (HEAD = BUF) + fread(BUF, 1, 1 << 15, stdin), HEAD == TAIL) ? EOF : *HEAD++; }
template<typename T> inline bool RDB(T&v) { char c; bool n; while (c = getchar_buffered(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = getchar_buffered() - '0', c >= 0 && c <= 9) v = (v << 3) + (v << 1) + c; if (n) v *= -1; return true; }
template<typename T> inline bool RDB(T&a, T&b) { return RDB(a) && RDB(b); }
template<typename T> inline bool RDB(T&a, T&b, T&c) { return RDB(a, b) && RDB(c); }
template<typename T> inline bool RDB(T&a, T&b, T&c, T&d) { return RDB(a, b, c) && RDB(d); }
template<typename T> inline bool RDB(T&a, T&b, T&c, T&d, T&e) { return RDB(a, b, c, d) && RDB(e); }
template<typename T> inline bool RDB(T&a, T&b, T&c, T&d, T&e, T&f) { return RDB(a, b, c, d, e) && RDB(f); }
inline int RDB() { int v; RDB(v); return v; }
template<typename T> inline void _WR(T a) { if (a < 0) { putchar('-'); a *= -1; } T t = a / 10; if (t) _WR(t); putchar(a - (t << 1) - (t << 3) + '0'); }
template<typename T> inline void WR_(const T&a) { _WR(a); putchar(' '); }
template<typename T> inline void WR(const T&a) { _WR(a); putchar('\n'); }
template<typename T> inline void WR(const T&a, const T&b) { WR_(a); WR(b); }
template<typename T> inline void WR(const T&a, const T&b, const T&c) { WR_(a); WR_(b); WR(c); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d) { WR_(a); WR_(b); WR_(c); WR(d); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d, const T&e) { WR_(a); WR_(b); WR_(c); WR_(d); WR(e); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d, const T&e, const T&f) { WR_(a); WR_(b); WR_(c); WR_(d); WR_(e); WR(f); }
void OUT() { std::cout << std::endl; }
template<typename T> inline void _OUT(const T&a) { std::cout << a; }
template<typename T> inline void OUT_(const T&a) { std::cout << a << ' '; }
template<typename T> inline void OUT(const T&a) { std::cout << a << std::endl; }
template<typename T, typename U> inline void OUT(const T&a, const U&b) { std::cout << a << " " << b << std::endl; }
template<typename T, typename U, typename V> inline void OUT(const T&a, const U&b, const V&c) { std::cout << a << " " << b << " " << c << std::endl; }
template<typename T, typename U, typename V, typename W> inline void OUT(const T&a, const U&b, const V&c, const W&d) { std::cout << a << " " << b << " " << c << " " << d << std::endl; }
template<typename T, typename U, typename V, typename W, typename X> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { std::cout << a << " " << b << " " << c << " " << d << " " << e << std::endl; }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << std::endl; }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << std::endl; }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << std::endl; }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << std::endl; }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << std::endl; }
template<typename T> inline T max(const T&a, const T&b, const T&c) { return std::max(std::max(a, b), c); }
template<typename T> inline T max(const T&a, const T&b, const T&c, const T&d) { return std::max(max(a, b, c), d); }
template<typename T> inline T max(const T&a, const T&b, const T&c, const T&d, const T&e) { return std::max(max(a, b, c, d), e); }
template<typename T> inline T max(const T&a, const T&b, const T&c, const T&d, const T&e, const T&f) { return std::max(max(a, b, c, d, e), f); }
template<typename T> inline T min(const T&a, const T&b, const T&c) { return std::min(std::min(a, b), c); }
template<typename T> inline T min(const T&a, const T&b, const T&c, const T&d) { return std::min(min(a, b, c), d); }
template<typename T> inline T min(const T&a, const T&b, const T&c, const T&d, const T&e) { return std::min(min(a, b, c, d), e); }
template<typename T> inline T min(const T&a, const T&b, const T&c, const T&d, const T&e, const T&f) { return std::min(min(a, b, c, d, e), f); }
inline ll madd(ll a, ll b, const int mod = 1000000007) { return (a + b) % mod; }
inline ll madd(ll a, ll b, ll c, const int mod = 1000000007) { return (a + b + c) % mod; }
inline ll madd(ll a, ll b, ll c, ll d, const int mod = 1000000007) { return (a + b + c + d) % mod; }
inline ll madd(ll a, ll b, ll c, ll d, ll e, const int mod = 1000000007) { return (a + b + c + d + e) % mod; }
inline ll madd(ll a, ll b, ll c, ll d, ll e, ll f, const int mod = 1000000007) { return (a + b + c + d + e + f) % mod; }
inline ll msub(ll a, ll b, const int mod = 1000000007) { ll ret = a - b; while (ret < 0) ret += mod; return ret; }
inline ll mmul(ll a, ll b, const int mod = 1000000007) { return a * b % mod; }
inline ll mmul(ll a, ll b, ll c, const int mod = 1000000007) { return a * b % mod * c % mod; }
inline ll mmul(ll a, ll b, ll c, ll d, const int mod = 1000000007) { return a * b % mod * c % mod * d % mod; }
inline ll mmul(ll a, ll b, ll c, ll d, ll e, const int mod = 1000000007) { return a * b % mod * c % mod * d % mod * e % mod; }
inline ll mmul(ll a, ll b, ll c, ll d, ll e, ll f, const int mod = 1000000007) { return a * b % mod * c % mod * d % mod * e % mod * f % mod; }
inline ll mpow(ll x, ll k, const int mod = 1000000007) { x %= mod; ll ret = 1; while (k) { if (k & 1) ret = ret * x % mod; x = x * x % mod; k >>= 1; } return ret; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll Phi(ll n) { ll ret = n; for (ll i = 2; i * i <= n; ++i) if (n % i == 0) { ret = ret / i * (i - 1); do n /= i; while (n % i == 0); } if (n > 1) ret = ret / n * (n - 1); return ret; }
template<typename T, typename U> inline bool cmax(T&a, const U&b) { return a < b ? a = b, true : false; }
template<typename T, typename U> inline bool cmin(T&a, const U&b) { return a > b ? a = b, true : false; }
template<typename T, typename U> inline T cadd(T&a, const U&b, const int mod = 1000000007) { return a = (a + b) % mod; }
template<typename T, typename U> inline T csub(T&a, const U&b, const int mod = 1000000007) { a = (a - b + mod) % mod; while (a < 0) a += mod; return a; }
template<typename T, typename U> inline T cmul(T&a, const U&b, const int mod = 1000000007) { return a = (1ll * a * b) % mod; }
template<typename T> inline T clow(T&a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T cup(T&a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T check(T&a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }
template<typename T> inline T validate_lower(T a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T validate_upper(T a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T validate(T a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }
inline int lowbit(int x) { return x & -x; }
inline int setbit(int x, int i) { return x |= (1 << --i); }
inline int setbit2(int&x, int i) { return x |= (1 << --i); }
inline int resetbit(int x, int i) { return x &= ~(1 << --i); }
inline int resetbit2(int&x, int i) { return x &= ~(1 << --i); }
inline bool testbit(int x, int i) { return (bool)(x & (1 << --i)); }
inline int cntbit(int x) { int cnt = 0; while (x) { ++cnt; x &= x - 1; } return cnt; }
void delay_s(int x) { time_t t0 = time(0); while (time(0) < t0 + x); }
void delay_ms(int x) { clock_t c0 = clock(); while (clock() < c0 + x); }
double run_time() { return 1.0 * clock() / CLOCKS_PER_SEC; }
char *local_time() { time_t t; time(&t); return ctime(&t); }
#ifdef _LOCAL_JUDGE
template<typename T, typename U> ostream& operator<< (ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")" << std::flush; return os; }
template<typename T> ostream& operator<< (ostream &os, const vector<T> &v) { os << "["; for (T i : v) { os << " "; os << i; } os << " ]" << std::flush; return os; }




#endif





#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>  
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 210000;

const int l = 17;

using namespace std;

int n, m;
vector<pair<int, int> > g[N];
vector<pair<int, pair<int, int> > > edges, edges2, mst;
int w[N];
long long COST;
int timer;
int up[N][l + 1];
int bedge[N][l + 1];
int tin[N];
int tout[N];
int dep[N];

void dfs(int v, int p = 1, int pcost = 0)
{
	tin[v] = timer;
	++timer;
	up[v][0] = p;
	bedge[v][0] = pcost;
	for (int i = 1; i <= l; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
		bedge[v][i] = max(bedge[v][i - 1], bedge[up[v][i - 1]][i - 1]);
	}
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int cost = g[v][i].second;
		if (to == p)
			continue;
		dep[to] = dep[v] + 1;
		dfs(to, v, cost);
	}
	tout[v] = timer;
	++timer;
}

bool upper(int a, int b)
{
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b)
{
	if (upper(a, b))
		return a;
	if (upper(b, a))
		return b;
	for (int i = l; i >= 0; --i)
	{
		if (!upper(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}

int get(int x)
{
	if (x == w[x])
		return x;
	return w[x] = get(w[x]);
}

void merge(int a, int b)
{
	if (rand() % 2)
		swap(a, b);
	a = get(a);
	b = get(b);
	w[a] = b;
}

int get_best(int v, int span)
{
	int ret = 0;
	for (int i = l; i >= 0; --i)
	{
		if (span&(1 << i))
		{
			ret = max(ret, bedge[v][i]);
			v = up[v][i];
		}
	}
	return ret;
}

int main() {
	

	

	

	

	

	

#ifdef _LOCAL_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(make_pair(c, make_pair(a, b)));
		edges2.push_back(make_pair(c, make_pair(a, b)));
		w[i] = i;
	}

	sort(edges.begin(), edges.end());
	

	

	

	


	for (int i = 0; i < edges.size(); i++)
	{
		int a, b, c;
		a = edges[i].second.first;
		b = edges[i].second.second;
		int ta, tb;
		c = edges[i].first;
		ta = get(a);
		tb = get(b);
		if (ta == tb)
			continue;
		merge(ta, tb);
		mst.push_back(make_pair(c, make_pair(a, b)));
		COST += c;
	}

	for (int i = 0; i < mst.size(); i++)
	{
		int v1 = mst[i].second.first;
		int v2 = mst[i].second.second;
		int cost = mst[i].first;
		g[v1].push_back(make_pair(v2, cost));
		g[v2].push_back(make_pair(v1, cost));
	}

	dfs(1);

	for (int i = 0; i < edges2.size(); i++)
	{
		int v1 = edges2[i].second.first;
		int v2 = edges2[i].second.second;
		int L = lca(v1, v2);
		int bst = 0;
		bst = max(bst, get_best(v1, dep[v1] - dep[L]));
		bst = max(bst, get_best(v2, dep[v2] - dep[L]));
		cout << COST + edges2[i].first - bst << "\n";
	}

	cin.get(); cin.get();
#ifdef _LOCAL_JUDGE
	cout << "Time elapsed:" << clock() / 1000.0 << "s." << endl;
	

#endif
	return 0;
}
#endif