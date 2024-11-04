









































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
typedef map<int, string> MIS;
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
char _BUF_[1 << 15], *_HEAD_ = _BUF_, *_TAIL_ = _BUF_; inline char id1() { return _HEAD_ == _TAIL_ && (_TAIL_ = (_HEAD_ = _BUF_) + fread(_BUF_, 1, 1 << 15, stdin), _HEAD_ == _TAIL_) ? EOF : *_HEAD_++; }
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
template<typename T> inline void _WR(const T&a, const T&b) { WR_(a); _WR(b); }
template<typename T> inline void WR_(const T&a, const T&b) { WR_(a); WR_(b); }
template<typename T> inline void WR(const T&a, const T&b) { WR_(a); WR(b); }
template<typename T> inline void _WR(const T&a, const T&b, const T&c) { WR_(a, b); _WR(c); }
template<typename T> inline void WR_(const T&a, const T&b, const T&c) { WR_(a, b); WR_(c); }
template<typename T> inline void WR(const T&a, const T&b, const T&c) { WR_(a, b); WR(c); }
template<typename T> inline void _WR(const T&a, const T&b, const T&c, const T&d) { WR_(a, b, c); _WR(d); }
template<typename T> inline void WR_(const T&a, const T&b, const T&c, const T&d) { WR_(a, b, c); WR_(d); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d) { WR_(a, b, c); WR(d); }
template<typename T> inline void _WR(const T&a, const T&b, const T&c, const T&d, const T&e) { WR_(a, b, c, d); _WR(e); }
template<typename T> inline void WR_(const T&a, const T&b, const T&c, const T&d, const T&e) { WR_(a, b, c, d); WR_(e); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d, const T&e) { WR_(a, b, c, d); WR(e); }
template<typename T> inline void _WR(const T&a, const T&b, const T&c, const T&d, const T&e, const T&f) { WR_(a, b, c, d, e); _WR(f); }
template<typename T> inline void WR_(const T&a, const T&b, const T&c, const T&d, const T&e, const T&f) { WR_(a, b, c, d, e); WR_(f); }
template<typename T> inline void WR(const T&a, const T&b, const T&c, const T&d, const T&e, const T&f) { WR_(a, b, c, d, e); WR(f); }
void OUT() { std::cout << std::endl; }
template<typename T> inline void _OUT(const T&a) { std::cout << a; }
template<typename T> inline void OUT_(const T&a) { std::cout << a << ' '; }
template<typename T> inline void OUT(const T&a) { std::cout << a << std::endl; }
template<typename T, typename U> inline void _OUT(const T&a, const U&b) { std::cout << a << " " << b; }
template<typename T, typename U> inline void OUT_(const T&a, const U&b) { std::cout << a << " " << b << " "; }
template<typename T, typename U> inline void OUT(const T&a, const U&b) { std::cout << a << " " << b << std::endl; }
template<typename T, typename U, typename V> inline void _OUT(const T&a, const U&b, const V&c) { OUT_(a, b); _OUT(c); }
template<typename T, typename U, typename V> inline void OUT_(const T&a, const U&b, const V&c) { OUT_(a, b); OUT_(c); }
template<typename T, typename U, typename V> inline void OUT(const T&a, const U&b, const V&c) { OUT_(a, b); OUT(c); }
template<typename T, typename U, typename V, typename W> inline void _OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); _OUT(d); }
template<typename T, typename U, typename V, typename W> inline void OUT_(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); OUT_(d); }
template<typename T, typename U, typename V, typename W> inline void OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); OUT(d); }
template<typename T, typename U, typename V, typename W, typename X> inline void _OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); _OUT(e); }
template<typename T, typename U, typename V, typename W, typename X> inline void OUT_(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); OUT_(e); }
template<typename T, typename U, typename V, typename W, typename X> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); OUT(e); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline void _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); _OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline void OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); OUT_(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline void _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); _OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline void OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); OUT_(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline void _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); _OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline void OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); OUT_(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline void _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); _OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline void OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); OUT_(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline void _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); _OUT(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline void OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); OUT_(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline void OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); OUT(j); }
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
template<int n = 1048576, typename T = int> class BIT { T c[n]; public: BIT() { memset(c, 0, sizeof(c)); } int add(int i, int d) { if (i <= 0) return -1; for (; i < n; i += i & -i) c[i] += d; return 0; } T sum(int i) { T sum = 0; for (; i > 0; i -= i & -i) sum += c[i]; return sum; } T sum(int l, int r) { return sum(r) - sum(l - 1); } };
template<int n = 1048576, typename T = int> class BIT0 { T c[n]; public: BIT0() { memset(c, 0, sizeof(0)); } int add(int i, int d) { if (i < 0) return -1; for (; i < n; i = i | (i + 1)) c[i] += d; return 0; } T sum(int i) { T sum = 0; for (; i >= 0; i = (i & (i + 1)) - 1) sum += c[i]; return sum; } T sum(int l, int r) { return sum(r) - sum(l - 1); } };

template<typename T, typename U> ostream& operator<< (ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")" << std::flush; return os; }
template<typename T> ostream& operator<< (ostream &os, const vector<T> &v) { os << "["; for (T i : v) { os << " "; os << i; } os << " ]" << std::flush; return os; }








const int _ = (int)(5000 + 10);
const int __ = (int)(1e6 + 10);
const int LOG = 20;
int n;
string s;

bool is_less(const string &a, const string &b) {
	if (sz(a) == sz(b)) {
		rep(i, 0, sz(a)) if (a[i] != b[i]) return a[i] < b[i];
		return false;
	}
	else {
		return sz(a) < sz(b);
	}
}


































int dp[_][_], sum[_][_];
void solve() {

	int mn = 1;
	rep(i, 1, n + 1) {
		rep(j, 1, i) {
			int p = i - j;
			if (s[p] == '0') { sum[i][j] = sum[i][j - 1]; continue; }

			if (p >= j - 1) cadd(dp[i][j], sum[p][j - 1]);
			else cadd(dp[i][j], sum[p][p]);
			if (p >= j && dp[p][j]) {
				

				

				


				int x = memcmp(&s[p], &s[p - j], j);
				if (x > 0) {
					cadd(dp[i][j], dp[p][j]);
				}

				

				

				

				

				

			}
			cadd(sum[i][j], sum[i][j - 1] + dp[i][j]);
		}
		dp[i][i] = 1;
		cadd(sum[i][i], sum[i][i - 1] + dp[i][i]);
	}

	

	

	ll ans = sum[n][n];
	WR(ans);
}
inline void _main() {

	cin >> n >> s;
	solve();
}


void id2() {
	int n = 5000;
	WR(n);
	rep(i, 0, n) putchar(9 + '0');
	exit(0);
}
int main() {

	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);


	_main();

	id2();


	OUT("Time elapsed:", run_time(), "s."); _OUT(local_time());
	FILE * fp = fopen(FILE_NAME, "r+");
	fprintf(fp, "//Latest run time : %s", local_time());
	fclose(fp);

	return 0;
}

