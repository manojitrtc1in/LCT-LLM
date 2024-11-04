#define XTREME_IO
#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define BE(x) (x).begin(), (x).end()
#define y1 ___y1
#define max mymax
#define min mymin
#define pq priority_queue
#define FOR(i, l, r) for (int i = (l), i##end = (r); i <= i##end; i++)
#define ROF(i, r, l) for (int i = (r), i##end = (l); i >= i##end; i--)
#define SON(i, u) for (int i = head[u]; i; i = e[i].nxt)

using namespace std;

#ifndef XTREME_IO
inline int gc() { return getchar(); }
inline void pc(int c) { return putchar(c); }
inline void fl() { flush(stdout); }
#define gc getchar
#define pc putchar
#define fl() fflush(stdout)
#else
#define cin
#define cout
#define scanf 1
#define printf 1
namespace XTREME_IOS {
	const int SZ = 1 << 20;
	char ib[SZ], ob[SZ], *li, *ri, *lo = ob, *ro = ob + SZ;
}
inline int gc() {
	using namespace XTREME_IOS;
	if (li == ri) ri = (li = ib) + fread(ib, 1, SZ, stdin);
	return *li++;
}
inline void fl() {
	using namespace XTREME_IOS;
	fwrite(ob, 1, lo - ob, stdout), lo = ob, fflush(stdout);
}
inline void pc(int ch) {
	using namespace XTREME_IOS;
	if (lo == ro) fl();
	*lo++ = ch;
}
#endif

template <typename T, typename Ret = void>
using efsi = typename enable_if<is_signed<T>::value && is_integral<T>::value, Ret>::type;
template <typename T, typename Ret = void>
using efui = typename enable_if<is_unsigned<T>::value && is_integral<T>::value, Ret>::type;

template <typename T>
inline efsi<T> read(T &x) {
	int c = gc(), tag = 0; x = 0;
	for (; !isdigit(c); c = gc()) tag |= (c == '-');
	for (; isdigit(c); c = gc()) x = (x * 10) + (c ^ 48);
	if (tag) x = -x;
}
template <typename T>
inline efui<T> read(T &x) {
	int c = gc(); x = 0;
	for (; !isdigit(c); c = gc());
	for (; isdigit(c); c = gc()) x = (x * 10) + (c ^ 48);
}
inline void read(char &x) {
	for (x = gc(); isspace(x); x = gc());
}
inline void read(char *s) {
	char c; read(c);
	for (; !isspace(c); c = gc()) *s++ = c;
	*s++ = '\0';
}
inline void read(string &s) {
	char c; read(c); s = "";
	for (; !isspace(c); c = gc()) s += c;
}
template <typename T>
inline typename enable_if<!is_integral<T>::value>::type read(T &x) {
	string s; read(s);
	stringstream(s) >> x;
}
template <typename A, typename B>
inline void read(pair<A, B> &pr) { read(pr.fi); read(pr.se); }
template <typename It, typename = decltype(*It())>
void read(It l, It r) { for (; l != r; ++l) read(*l); }
template <typename A, typename... B>
inline void read(A &x, B&... y) { read(x); read(y...); }

template <typename T>
inline efui<T> write(T x) {
	if (x >= 10) write(x / 10);
	pc((x % 10) ^ 48);
}
template <typename T>
inline efsi<T> write(T x) {
	if (x < 0) pc('-'), x = -x;
	write(typename make_unsigned<T>::type (x));
}
template <typename A, typename B>
void write(const pair<A, B> &x) { write(x.fi), pc(' '), write(x.se); }
inline void write(char c) { pc(c); }
inline void write(const char *s) { for (; *s; pc(*s++)); }
inline void write(const string &s) { for (auto c: s) pc(c); }
template <typename T>
inline typename enable_if<is_floating_point<T>::value>::type write(T x) {
	write((stringstream() << fixed << setprecision(12) << x).str());
}
template <typename T>
inline typename enable_if<!is_arithmetic<T>::value>::type write(T x) {
	write((stringstream() << x).str());
}
template <typename It, typename = decltype(*It())>
void write(It l, It r) { for (; l != r; ++l) write(*l), pc(' '); }
template <typename T, typename = decltype(T().begin())>
void write(const T &x) { write(x.begin(), x.end()); }


inline void debug_out(char c) {
	pc('\''), pc(c), pc('\'');
}
inline void debug_out(const char *s) {
	pc('"'), write(s), pc('"');
}
inline void debug_out(const string &s) {
	pc('"'), write(s), pc('"');
}
template <typename A, typename B>
void debug_out(const pair<A, B> &x) {
	pc('('), debug_out(x.fi), pc(' '), debug_out(x.se), pc(')');
}
template <typename T>
inline typename enable_if<is_arithmetic<T>::value>::type debug_out(T x) {
	write(x);
}
template <typename It, typename = decltype(*It())>
void debug_out(It l, It r) {
	pc('{');
	for (It p = l; p != r; ++p) {
		if (p != l) pc(','), pc(' ');
		debug_out(*p);
	}
	pc('}');
}
template <typename T, typename = decltype(T().begin())>
void debug_out(const T &x) { debug_out(x.begin(), x.end()); }

inline void wts() { }
template <typename A, typename... B>
inline void wts(const A &x, const B&... y) { write(x), pc(' '), wts(y...); }
template <typename... A>
inline void wtb(const A&... x) { wts(x...), pc('\n'); }
template <typename... A>
inline void wte(const A&... x) { wts(x...), exit(0); }

int __init__ = []() {
#ifdef LOCAL
	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	atexit([](){ system("grep VmPeak /proc/$PPID/status > /dev/tty"); });
#endif
	atexit(fl);
	return 0;
}();

using ui = unsigned;
using ll = long long;
using ul = unsigned long long;
using db = double;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using l3 = __int128_t;
using u3 = __uint128_t;

const double finf = 1e121, eps = 1e-10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

template <typename A, typename B>
auto mymax(const A &x, const B &y) -> decltype(x > y ? x : y) { return x > y ? x : y; }
template <typename A, typename B>
auto mymin(const A &x, const B &y) -> decltype(x < y ? x : y) { return x < y ? x : y; }
template <typename A, typename B>
inline int chkmn(A &x, const B &y) { return x > y ? (x = y, 1) : 0; }
template <typename A, typename B>
inline int chkmx(A &x, const B &y) { return x < y ? (x = y, 1) : 0; }

const int N = 50100, M = 1000000007;
inline int add(int x, int y) { return x + y >= M ? x + y - M : x + y; }
inline int sub(int x, int y) { return x - y < 0 ? x - y + M : x - y; }
inline int mul(int x, int y) { return (ul)x * y % M; }
template <typename... args> inline int mul(int x, args... y) { return mul(x, mul(y...)); }

struct Mat {
	int a00, a01, a10, a11;
	Mat(): a00(), a01(), a10(), a11() {}
	Mat(int x, int y, int z, int w): a00(x), a01(y), a10(z), a11(w) {}
	friend Mat operator + (const Mat &x, const Mat &y) {
		return Mat(
			add(x.a00, y.a00),
			add(x.a01, y.a01),
			add(x.a10, y.a10),
			add(x.a11, y.a11)
		);
	}
	friend Mat operator * (const Mat &x, const Mat &y) {
		return Mat(
			add(mul(x.a00, y.a00), mul(x.a01, y.a10)),
			add(mul(x.a00, y.a01), mul(x.a01, y.a11)),
			add(mul(x.a10, y.a00), mul(x.a11, y.a10)),
			add(mul(x.a10, y.a01), mul(x.a11, y.a11))
		);
	}
	friend void write(const Mat &a) {
		wtb(a.a00, a.a01);
		wtb(a.a10, a.a11);
	}
} pw1[1 << 19], pw2[1 << 18], T(1, 1, 1, 0), IT(0, 1, 1, M - 1);
struct Vec {
	int a0, a1;
	Vec(): a0(), a1() {}
	Vec(int x, int y): a0(x), a1(y) {}
	friend Vec operator + (const Vec &x, const Vec &y) {
		return Vec(add(x.a0, y.a0), add(x.a1, y.a1));
	}
	void operator += (const Vec &x) {
		a0 = add(a0, x.a0), a1 = add(a1, x.a1);
	}
	friend Vec operator * (const Mat &x, const Vec &y) {
		return Vec(
			add(mul(x.a00, y.a0), mul(x.a01, y.a1)),
			add(mul(x.a10, y.a0), mul(x.a11, y.a1))
		);
	}
};
void init() {
	Mat pw(1, 0, 0, 1), pwi = pw;
	FOR (i, 0, (1 << 18) - 1)
		pw2[i] = pw, pw = pw * T, pwi = pwi * IT;
	pw1[1 << 18] = pw2[0];
	T = pw, IT = pwi, pw = pwi = Mat(1, 0, 0, 1);
	FOR (i, 0, (1 << 18) - 1) {
		pw1[(1 << 18) + i] = pw;
		pw1[(1 << 18) - i] = pwi;
		pw = pw * T, pwi = pwi * IT;
	}
}
Mat query(ll k) {
	return pw1[(1 << 18) + (k >> 18)] * pw2[k & ((1 << 18) - 1)];
}

int n, q, a[2][N];

struct Node {
	ll mx[2][2], mn[2][2], tag[2];
	Vec a[3][3];
} arr[N << 2];

#define lc p << 1
#define rc p << 1 | 1

inline void build(Node &z, int a0, int a1) {
	int a[2] = {a0, a1};
	FOR (i, 0, 1) {
		z.tag[i] = 0;
		z.mx[i][1] = z.mx[i][0] = a[i];
		z.mn[i][1] = z.mn[i][0] = a[i];
	}
	FOR (i, 0, 2) FOR (j, 0, 2) z.a[i][j] = Vec();
	z.a[0][0] = query(a0 + a1) * Vec(1, 0);
	z.a[2][2] = z.a[2][0] = z.a[0][2] = z.a[0][0];
}
inline void contribute(Node &x, const Node &y) {
	int mp[2][3];
	FOR (i, 0, 1) FOR (j, 0, 1) {
		if (y.mx[i][j] != x.mx[i][0]) chkmx(x.mx[i][1], y.mx[i][j]);
		if (y.mn[i][j] != x.mn[i][0]) chkmn(x.mn[i][1], y.mn[i][j]);
	}
	FOR (i, 0, 1) {
		if (y.mx[i][0] == y.mx[i][1]) {
			if (x.mx[i][0] == x.mx[i][1]) {
				mp[i][0] = 0, mp[i][2] = 2, mp[i][1] = -1;
			} else {
				mp[i][1] = mp[i][2] = -1;
				if (y.mx[i][0] == x.mx[i][0]) mp[i][0] = 0;
				else if (y.mx[i][0] == x.mn[i][0]) mp[i][0] = 2;
				else mp[i][0] = 1;
			}
		} else {
			mp[i][0] = (y.mx[i][0] == x.mx[i][0]) ? 0 : 1;
			mp[i][1] = 1;
			mp[i][2] = (y.mn[i][0] == x.mn[i][0]) ? 2 : 1;
		}
	}
	FOR (i, 0, 2) FOR (j, 0, 2) if (~mp[0][i] && ~mp[1][j])
		x.a[ mp[0][i] ][ mp[1][j] ] += y.a[i][j];
}
inline void merge(Node &z, const Node &x, const Node &y) {
	FOR (i, 0, 1) {
		z.mx[i][0] = max(x.mx[i][0], y.mx[i][0]);
		z.mn[i][0] = min(x.mn[i][0], y.mn[i][0]);
		z.mx[i][1] = -INF, z.mn[i][1] = INF;
	}
	FOR (i, 0, 2) FOR (j, 0, 2) z.a[i][j] = Vec();
	contribute(z, x);
	contribute(z, y);
	FOR (i, 0, 1)
		if (z.mx[i][0] == z.mn[i][0])
			z.mx[i][1] = z.mn[i][1] = z.mx[i][0];
}
inline ll qsum(const Node &x) {
	int tag[2][3];
	FOR (i, 0, 1) {
		tag[i][0] = 1;
		tag[i][1] = tag[i][2] = (x.mx[i][0] != x.mn[i][0]);
	}
	Vec res;
	FOR (i, 0, 2) FOR (j, 0, 2) if (tag[0][i] && tag[1][j])
		res += x.a[i][j];
	return res.a1;
}

inline void add(int t, int p, ll k) {
	arr[p].mx[t][0] += k, arr[p].mx[t][1] += k;
	arr[p].mn[t][0] += k, arr[p].mn[t][1] += k;
	arr[p].tag[t] += k;
	Mat tmp = query(k);
	FOR (i, 0, 2) FOR (j, 0, 2)
		arr[p].a[i][j] = tmp * arr[p].a[i][j];
}
inline void pushmx(int t, int p, ll k) {
	if (k >= arr[p].mx[t][0]) return;
	if (arr[p].mx[t][0] == arr[p].mn[t][0])
		return add(t, p, k - arr[p].mx[t][0]);
	assert(k > arr[p].mx[t][1]);
	Mat tr = query(k - arr[p].mx[t][0]);
	arr[p].mx[t][0] = k;
	arr[p].mn[t][1] = min(arr[p].mn[t][1], k); 

	if (t == 0) {
		FOR (i, 0, 2) arr[p].a[0][i] = tr * arr[p].a[0][i];
	} else {
		FOR (i, 0, 2) arr[p].a[i][0] = tr * arr[p].a[i][0];
	}
}
inline void pushmn(int t, int p, ll k) {
	if (k <= arr[p].mn[t][0]) return;
	if (arr[p].mx[t][0] == arr[p].mn[t][0])
		return add(t, p, k - arr[p].mn[t][0]);
	assert(k < arr[p].mn[t][1]);
	Mat tr = query(k - arr[p].mn[t][0]);
	arr[p].mn[t][0] = k;
	arr[p].mx[t][1] = max(arr[p].mx[t][1], k); 

	if (t == 0) {
		FOR (i, 0, 2) arr[p].a[2][i] = tr * arr[p].a[2][i];
	} else {
		FOR (i, 0, 2) arr[p].a[i][2] = tr * arr[p].a[i][2];
	}
}
inline void down(int p) {
	FOR (i, 0, 1) {
		add(i, lc, arr[p].tag[i]), add(i, rc, arr[p].tag[i]), arr[p].tag[i] = 0;
		pushmx(i, lc, arr[p].mx[i][0]), pushmx(i, rc, arr[p].mx[i][0]);
		pushmn(i, lc, arr[p].mn[i][0]), pushmn(i, rc, arr[p].mn[i][0]);
	}
}
inline void up(int p) { merge(arr[p], arr[lc], arr[rc]); }
inline void build(int l, int r, int p) {
	if (l == r) {
		build(arr[p], a[0][l], a[1][l]);
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lc), build(m + 1, r, rc), up(p);
}
inline void chkmx(int ql, int qr, int t, ll k, int l, int r, int p) {
	if (r < ql || qr < l) return;
	if (ql <= l && qr >= r) {
		if (k >= arr[p].mx[t][0]) return;
		if (k > arr[p].mx[t][1])
			return pushmx(t, p, k);
		if (arr[p].mx[t][0] == arr[p].mn[t][0]) {
			return add(t, p, k - arr[p].mx[t][0]);
		}
	}
	int m = (l + r) >> 1; down(p);
	chkmx(ql, qr, t, k, l, m, lc);
	chkmx(ql, qr, t, k, m + 1, r, rc);
	up(p);
}
inline void chkmn(int ql, int qr, int t, ll k, int l, int r, int p) {
	if (r < ql || qr < l) return;
	if (ql <= l && qr >= r) {
		if (k <= arr[p].mn[t][0]) return;
		if (k < arr[p].mn[t][1])
			return pushmn(t, p, k);
		if (arr[p].mx[t][0] == arr[p].mn[t][0])
			return add(t, p, k - arr[p].mn[t][0]);
	}
	int m = (l + r) >> 1; down(p);
	chkmn(ql, qr, t, k, l, m, lc);
	chkmn(ql, qr, t, k, m + 1, r, rc);
	up(p);
}
inline void modify(int ql, int qr, int t, ll k, int l, int r, int p) {
	if (r < ql || qr < l) return;
	if (ql <= l && qr >= r) return add(t, p, k);
	int m = (l + r) >> 1; down(p);
	modify(ql, qr, t, k, l, m, lc);
	modify(ql, qr, t, k, m + 1, r, rc);
	up(p);
}
inline ll qsum(int ql, int qr, int l, int r, int p) {
	if (r < ql || qr < l) return 0;
	if (ql <= l && qr >= r) return qsum(arr[p]);
	int m = (l + r) >> 1; down(p);
	return qsum(ql, qr, l, m, lc) + qsum(ql, qr, m + 1, r, rc);
}

void dfs(int l, int r, int p) {
	if (l == r) {
		wtb(arr[p].mn[0][0], arr[p].mn[1][0]);
		return;
	}
	int m = (l + r) >> 1; down(p);
	dfs(l, m, lc), dfs(m + 1, r, rc);
}

int main() {
	init(), read(n, q);
	FOR (i, 0, 1) read(a[i] + 1, a[i] + n + 1);
	build(1, n, 1);

	FOR (i, 1, q) {
		int op, k, l, r, x;
		read(op);
		if (op == 4) {
			read(l, r);
			wtb(qsum(l, r, 1, n, 1) % M);
			continue;
		}
		read(k, l, r, x), k--;
		if (op == 1)
			chkmx(l, r, k, x, 1, n, 1);
		else if (op == 2)
			chkmn(l, r, k, x, 1, n, 1);
		else if (op == 3)
			modify(l, r, k, x, 1, n, 1);
	}
}
