

                                                                                     
 




 

 

 





























using namespace std;

















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
char BUF[1 << 15], *HEAD = BUF, *TAIL = BUF; inline char id1() { return HEAD == TAIL && (TAIL = (HEAD = BUF) + fread(BUF, 1, 1 << 15, stdin), HEAD == TAIL) ? EOF : *HEAD++; }
template<typename T> inline bool RDB(T&v) { char c; bool n; while (c = id1(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = id1() - '0', c >= 0 && c <= 9) v = (v << 3) + (v << 1) + c; if (n) v *= -1; return true; }
template<typename T> inline bool RDB(T&a, T&b) { return RDB(a) && RDB(b); }
template<typename T> inline bool RDB(T&a, T&b, T&c) { return RDB(a, b) && RDB(c); }
template<typename T> inline bool RDB(T&a, T&b, T&c, T&d) { return RDB(a, b, c) && RDB(d); }
template<typename T> inline bool RDB(T&a, T&b, T&c, T&d, T&e) { return RDB(a, b, c, d) && RDB(e); }
template<typename T> inline bool RDB(T&a, T&b, T&c, T&d, T&e, T&f) { return RDB(a, b, c, d, e) && RDB(f); }
inline int RDB() { int v; RDB(v); return v; }
template<typename T> inline void _WR(T a) { if (a < 0) { putchar('-'); a *= -1; } T t = a / 10; if (t) _WR(t); putchar(a - (t << 1) - (t << 3) + '0'); }
template<typename T> inline void WR_(const T&a) { _WR(a); putchar(' '); }
template<typename T> inline void WR(const T&a) { _WR(a); putchar('\n'); }
template<typename T> inline void WR(const T&a, const T&b) { WR_(a); WR(b);}
template<typename T> inline void WR(const T&a, const T&b, const T&c) { WR_(a); WR_(b); WR(c);}
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d) { WR_(a); WR_(b); WR_(c); WR(d); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d, const T&e) { WR_(a); WR_(b); WR_(c); WR_(d); WR(e); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d, const T&e, const T&f) { WR_(a); WR_(b); WR_(c); WR_(d); WR_(e); WR(f); }
void OUT() { std::cout << std::endl; }
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
inline int id3(int&x, int i) { return x |= (1 << --i); }
inline int resetbit(int x, int i) { return x &= ~(1 << --i); }
inline int id0(int&x, int i) { return x &= ~(1 << --i); }
inline bool testbit(int x, int i) { return (bool)(x & (1 << --i)); }
inline int cntbit(int x) { int cnt = 0; while (x) { ++cnt; x &= x - 1; } return cnt; }
void delay_s(int x) { time_t t0 = time(0); while (time(0) < t0 + x); }
void delay_ms(int x) { clock_t c0 = clock(); while (clock() < c0 + x); }
double run_time() { return 1.0 * clock() / CLOCKS_PER_SEC; }
char *local_time() { time_t t; time(&t); return ctime(&t); }

template<typename T, typename U> ostream& operator<< (ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")" << std::flush; return os; }
template<typename T> ostream& operator<< (ostream &os, const vector<T> &v) { os << "["; for (T i : v) { os << " "; os << i; } os << " ]" << std::flush; return os; }






const int _ = (int)(1e5 + 10);
const int __ = (int)(1e6 + 10);
const int LOG = 18;
int n, m, q;
VI e[_], cc[_][LOG];
int dep[_], fa[_][LOG];
void merge(VI &a, VI &b) {
	for (int i : b) {
		a.insert(lower_bound(all(a), i), i);
		if (sz(a) > 10) a.pop_back();
	}
}

void sub(VI &a, VI &b) {
	int j = sz(b) - 1;
	per(i, 0, sz(a)) {
		if (j >= 0 && a[i] == b[j]) {
			a.erase(a.begin() + i);
			--j;
		}
	}
}






















void dfs(int f, int u, int d) {
	fa[u][0] = f;
	dep[u] = d;
	for (int v : e[u]) if (v != f) {
		dfs(u, v, d + 1);
	}
}
int LCA(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	int d = dep[v] - dep[u];
	rep(i, 0, LOG) if (d &(1 << i)) v = fa[v][i];
	if (u == v) return u;
	per(i, 0, LOG) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
inline void _main() {
	RDB(n, m, q);
	rep(i, 1, n + 1) {
		e[i].clear();
		rep(j, 0, LOG) cc[i][j].clear();
	}
	rep(i, 1, n) {
		int u, v;
		RDB(u, v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rep(i, 1, m + 1) {
		int u = RDB();
		cc[u][0].push_back(i);
		if (sz(cc[u][0]) > 10) cc[u][0].pop_back();
	}
	dfs(0, 1, 0);
	rep(k, 1, LOG) rep(i, 1, n + 1) {
		fa[i][k] = fa[fa[i][k - 1]][k - 1];
		merge(cc[i][k], cc[i][k - 1]);
		merge(cc[i][k], cc[fa[i][k - 1]][k - 1]);
	}

	rep(i, 0, q) {
		int u, v, a;
		RDB(u, v, a);
		int f = LCA(u, v);
		

		VI x, y;
		int du = dep[u] - dep[f];
		rep(i, 0, LOG) if (du & (1 << i)) { merge(x, cc[u][i]); u = fa[u][i]; }
		

		int dv = dep[v] - dep[f];
		rep(i, 0, LOG) if (dv & (1 << i)) { merge(y, cc[v][i]); v = fa[v][i]; }
		

		merge(x, y);
		merge(x, cc[f][0]);

		int len = min(sz(x), a);
		if (len == 0) { puts("0"); continue; }
		WR_(len); rep(i, 0, len - 1) WR_(x[i]); WR(x[len - 1]);
	}
}

void id2() {
	int n = 100000;
	WR(1, n, n);
	rep(i, 0, n) WR_(1); OUT();
	rep(i, 0, n) WR(1, 1, 10);
	exit(0);
}
int main() {

	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);


	_main();

	id2();


	OUT("Time elapsed:", run_time(), "s."); OUT(local_time());
	FILE * fp = fopen(FILE_NAME, "r+");
	fprintf(fp, "//Latest run date : %s", local_time());
	fclose(fp);

	return 0;
}

