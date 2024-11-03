















































using namespace std;





























typedef double                db;
typedef long double           ldb;
typedef unsigned char         uchar;
typedef unsigned short        ushort;
typedef unsigned int          uint;
typedef long long             ll;
typedef unsigned long long    ull;
typedef vector<bool>          VB;
typedef vector<char>          VC;
typedef vector<VC>            VVC;
typedef vector<int>           VI;
typedef vector<VI>            VVI;
typedef vector<ll>            VLL;
typedef vector<VLL>           VVLL;
typedef vector<double>        VD;
typedef vector<VD>            VVD;
typedef vector<string>        VS;
typedef vector<VS>            VVS;
typedef pair<int, int>        PII;
typedef pair<ll, ll>          PLL;
typedef pair<string, int>     PSI;
typedef pair<db, db>          PDD;
typedef pair<db, int>         PDI;
typedef vector<PII>           VPII;
typedef vector<PLL>           VPLL;
typedef vector<PSI>           VPSI;
typedef vector<PDD>           VPDD;
typedef map<int, int>         MII;
typedef map<ll, ll>           MLL;
typedef map<db, db>           MDD;
typedef map<string, int>      MSI;
typedef map<int, string>      MIS;
typedef set<int>              SI;
typedef set<ll>               SL;
typedef queue<int>            QI;
typedef queue<PII>            QPII;
typedef deque<int>            DI;
typedef deque<ll>             DLL;
typedef pair<int, PII>        PIPII;
typedef pair<ll, PLL>         PLPLL;
typedef pair<PII, int>        PPIII;
typedef pair<PLL, ll>         PPLLL;
const db  eps = 1e-9;
const db  pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int mod2 = 1000000006;
const ll  infl = 0x3f3f3f3f3f3f3f3fLL;
template<typename T> inline bool RD(T&v) { char c; bool n; while (c = getchar(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = getchar(), c >= '0' && c <= '9') v = (v << 3) + (v << 1) + c - '0'; if (n) v *= -1; return true; }
template<typename T> inline bool RD(T&a, T&b) { return RD(a) && RD(b); }
template<typename T> inline bool RD(T&a, T&b, T&c) { return RD(a, b) && RD(c); }
template<typename T> inline bool RD(T&a, T&b, T&c, T&d) { return RD(a, b, c) && RD(d); }
template<typename T> inline bool RD(T&a, T&b, T&c, T&d, T&e) { return RD(a, b, c, d) && RD(e); }
template<typename T> inline bool RD(T&a, T&b, T&c, T&d, T&e, T&f) { return RD(a, b, c, d, e) && RD(f); }
inline int RD() { int v; RD(v); return v; }
char _BUF_[1 << 15], *_HEAD_ = _BUF_, *_TAIL_ = _BUF_; inline char id2() { return _HEAD_ == _TAIL_ && (_TAIL_ = (_HEAD_ = _BUF_) + fread(_BUF_, 1, 1 << 15, stdin), _HEAD_ == _TAIL_) ? EOF : *_HEAD_++; }
template<typename T> inline bool RDB(T&v) { char c; bool n; while (c = id2(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = id2() - '0', c >= 0 && c <= 9) v = (v << 3) + (v << 1) + c; if (n) v *= -1; return true; }
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
inline ll madd(ll a, ll b, const ll mod = 1000000007) { return (a + b) % mod; }
inline ll madd(ll a, ll b, ll c, const ll mod = 1000000007) { return (a + b + c) % mod; }
inline ll madd(ll a, ll b, ll c, ll d, const ll mod = 1000000007) { return (a + b + c + d) % mod; }
inline ll madd(ll a, ll b, ll c, ll d, ll e, const ll mod = 1000000007) { return (a + b + c + d + e) % mod; }
inline ll madd(ll a, ll b, ll c, ll d, ll e, ll f, const ll mod = 1000000007) { return (a + b + c + d + e + f) % mod; }
inline ll msub(ll a, ll b, const ll mod = 1000000007) { ll ret = a - b; while (ret < 0) ret += mod; return ret; }
inline ll mmul(ll a, ll b, const ll mod = 1000000007) { return a * b % mod; }
inline ll mmul(ll a, ll b, ll c, const ll mod = 1000000007) { return a * b % mod * c % mod; }
inline ll mmul(ll a, ll b, ll c, ll d, const ll mod = 1000000007) { return a * b % mod * c % mod * d % mod; }
inline ll mmul(ll a, ll b, ll c, ll d, ll e, const ll mod = 1000000007) { return a * b % mod * c % mod * d % mod * e % mod; }
inline ll mmul(ll a, ll b, ll c, ll d, ll e, ll f, const ll mod = 1000000007) { return a * b % mod * c % mod * d % mod * e % mod * f % mod; }
inline ll mpow(ll x, ll k, const ll mod = 1000000007) { x %= mod; ll ret = 1; while (k) { if (k & 1) ret = ret * x % mod; x = x * x % mod; k >>= 1; } return ret; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template<typename T, typename U> inline bool cmax(T&a, const U&b) { return a < b ? a = b, true : false; }
template<typename T, typename U> inline bool cmin(T&a, const U&b) { return a > b ? a = b, true : false; }
template<typename T, typename U> inline T cadd(T&a, const U&b, const int mod = 1000000007) { return a = (a + b) % mod; }
template<typename T, typename U> inline T csub(T&a, const U&b, const int mod = 1000000007) { a = (a - b + mod) % mod; while (a < 0) a += mod; return a; }
template<typename T, typename U> inline T cmul(T&a, const U&b, const int mod = 1000000007) { return a = (1ll * a * b) % mod; }
template<typename T> inline T clow(T&a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T cup(T&a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T cboth(T&a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }
template<typename T> inline T vlow(T a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T vup(T a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T vboth(T a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }
template<typename T> inline int lowbit(T x) { return x & -x; }
template<typename T> inline int setbit(T x, int i) { return x | ((T)(1) << i); }
template<typename T> inline int id4(T&x, int i) { return x |= ((T)(1) << i); }
template<typename T> inline int resetbit(T x, int i) { return x & ~((T)(1) << i); }
template<typename T> inline int id0(T&x, int i) { return x &= ~((T)(1) << i); }
template<typename T> inline bool testbit(T x, int i) { return (bool)(x & ((T)(1) << i)); }
template<typename T> inline int id1(T x) { int cnt = 0; while (x) { ++cnt; x &= x - 1; } return cnt; }
template<typename T> inline int cntbits(T x) { int cnt = 1; while (x >> cnt) ++cnt; return cnt; }
void delay_s(int x) { time_t t0 = time(0); while (time(0) < t0 + x); }
void delay_ms(int x) { clock_t c0 = clock(); while (clock() < c0 + x); }
double run_time() { return 1.0 * clock() / CLOCKS_PER_SEC; }
char *local_time() { time_t t; time(&t); return ctime(&t); }

template<typename T> string to_binary(T a) { string ret; for (int i = sizeof(T) * 8 - 1; i >= 0; --i) { ret += a&(1 << i) ? '1' : '0'; if (i % 8 == 0) ret += ' '; } return ret; }
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")" << std::flush; return os; }
template<typename T> ostream& operator<< (ostream& os, const vector<T>& v) { os << "["; for (vector<T>::const_iterator b = v.begin(), e = v.end(); b != e; ++b) os << " " << *b; os << " ]" << std::flush; return os; }
template<typename T> ostream& operator<< (ostream& os, const deque<T>& d) { os << "["; for (deque<T>::const_iterator b = d.begin(), e = d.end(); b != e; ++b) os << " " << *b; os << " ]" << std::flush; return os; }
template<typename T> ostream& operator<< (ostream& os, const set<T>& s) { os << "["; for (set<T>::const_iterator b = s.begin(), e = s.end(); b != e; ++b) os << " " << *b; os << " ]" << std::flush; return os; }
template<typename T> ostream& operator<< (ostream& os, const multiset<T>& s) { os << "["; for (set<T>::const_iterator b = s.begin(), e = s.end(); b != e; ++b) os << " " << *b; os << " ]" << std::flush; return os; }
template<typename T, typename U> ostream& operator<< (ostream& os, const map<T, U>& m) { os << "["; for (map<T, U>::const_iterator b = m.begin(), e = m.end(); b != e; ++b) os << " " << b->first << ":" << b->second; os << " ]" << std::flush; return os; }
template<typename T, typename U> ostream& operator<< (ostream& os, const multimap<T, U>& m) { os << "["; for (map<T, U>::const_iterator b = m.begin(), e = m.end(); b != e; ++b) os << " " << b->first << ":" << b->second; os << " ]" << std::flush; return os; }














/

/

/

/

const int dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
const int dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };


const int _ = (int)(5e5 + 10);
const int __ = (int)(1e6 + 10);
const int LOG = 17;

int n, m;
string s, sub;
int cnt[11];
int find(int l, int r, int sum) {
	int mid = (l + r) / 2;
	int t = to_string(mid).size();
	if (mid + t == sum) return mid;
	if (mid + t < sum) return find(mid + 1, r, sum);
	if (mid + t > sum) return find(l, mid, sum);
}
void insert(string &s, const string &sub) {
	if (s.empty()) { s = sub; return; }
	if (sub[0] == '0') {
		if (s[0] == '0') {
			int i = s.find_first_not_of('0');
			swap(s[0], s[i]);
		}
		int i = 1;
		while (s[i] == '0') ++i;
		

		s.insert(i, sub);
		return;
	}
	if (s[0] == '0') {
		int i = s.find_first_not_of('0');
		if (i == -1) { s = sub + s; return; }
		if (sub[0] < s[i]) { 
			s = sub + s; 
			return;
		}
		if (sub[0] == s[i]) {

		}
		swap(s[0], s[i]);
		i = 1;
		int j = sub.find_first_not_of(sub[0]);
		char c = sub[0];
		if (j != -1) c = sub[j];
		if (c > s[0]) {
			while (i <sz(s) && s[i] <= sub[0]) ++i;
		}
		else {
			while (i <sz(s) && s[i] < sub[0]) ++i;
		}
		s.insert(i, sub);
		return;
	}

	int i = 0;
	int j = sub.find_first_not_of(sub[0]);
	char c = sub[0];
	if (j != -1) c = sub[j];
	if (c > s[0]) {
		while (i <sz(s) && s[i] <= sub[0]) ++i;
	}
	else {
		while (i <sz(s) && s[i] < sub[0]) ++i;
	}
	s.insert(i, sub);
	return;
}
bool isEmpty() {
	rep(i, 0, 10) if (cnt[i]) return false;
	return true;
}
string form(int mid) {
	string ret;
	rep(i, 0, mid) ret += string(cnt[i], '0' + i);
	ret += sub;
	rep(i, mid, 10) ret += string(cnt[i], '0' + i);
	return ret;
}
string solve() {
	if (isEmpty()) return sub;

	string ret(m, '9');

	rep(i, 0, 10) {
		string t = form(i);
		if (t[0] == '0') continue;
		cmin(ret, t);
	}
	if (cnt[0] != 0 || sub[0] == '0') {
		int i = 1; while (cnt[i] == 0) ++i;
		string head(1, char('0' + i));
		--cnt[i];
		rep(i, 0, 10) {
			string t = form(i);
			t = head + t;
			cmin(ret, t);
		}
	}
	return ret;
	

	

	


	

	

	

	

	

	

	

	

}
inline void _main() {
	IOSS0;
	cin >> s >> sub;
	n = sz(s);
	m = find(1, n, n);
	OUT("m =", m);
	string t = to_string(m);

	for (char c : s) ++cnt[c - '0'];
	for (char c : t) --cnt[c - '0'];
	for (char c : sub) --cnt[c - '0'];

	OUTn(cnt, 0, 10); OUT("sub =", sub);
	cout << solve() << endl;




	

	

	

	

}

void id3() {
	int n = 1000000 - rand() % 1000;
	rep(i, 0, n) { _WR(rand() % 10); }
	OUT(n);
	exit(0);
}
int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	_main();

	id3();


	OUT("Time elapsed:", run_time(), "s.");
	_OUT(local_time());

	FILE * fp = fopen(FILE_NAME, "r+");
	fprintf(fp, "//Latest run time : %s", local_time());
	fclose(fp);


	return 0;
}

