


#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <unordered_map>
#include <random>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define debug(x) cout << (#x) << " " << x << "\n";
typedef long double ld;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define fi first
#define se second
int dx4[4] = { 1, 0, -1, 0 };
int dy4[4] = { 0, 1, 0, -1 };
int dx8[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
typedef complex<double> base;
const double PI = acos(-1);

#if defined(OJ)

constexpr int SZ = 1 << 20;

class INPUT {
private:
	char read_buf[SZ];
	int read_idx, next_idx;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in;
}

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out;
}

#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
#endif

template<typename T>
struct Matrix {
	vector<vector<T>> mat;
	int w, h;
	Matrix() {}
	Matrix(int _w, int _h) { w = _w, h = _h, mat.resize(w, vector<T>(h)); }
	Matrix(int _w, int _h, T t) { w = _w, h = _h, mat.resize(w, vector<T>(h, t)); }

	vector<T>& operator[](unsigned int idx) { return mat[idx]; }

	Matrix<T> Reverse() {
		int n = min(w, h);
		Matrix<T> arr(n, 2 * n); arr.mat.assign(mat.begin(), mat.end());
		for (int i = 0; i < n; i++) arr[i].resize(2 * n);
		for (int i = 0; i < n; i++) {
			for (int j = n; j < 2 * n; j++)
				if (i == j - n) arr[i][j] = 1;
		}
		for (int i = 0; i < n; i++) {
			T t = arr[i][i];
			for (int j = i; j < 2 * n; j++) arr[i][j] /= t;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					t = arr[j][i];
					for (int k = 0; k < 2 * n; k++)
						arr[j][k] -= t * arr[i][k];
				}
			}
		}
		Matrix<T> ans(n, n);
		for (int i = 0; i < n; i++) for (int j = n; j < 2 * n; j++)
			ans[i][j - n] = arr[i][j];
		return ans;
	}
};
template<typename T>
Matrix<T> matmultiply(Matrix<T> a, Matrix<T> b) {
	Matrix<T> ans(a.w, b.h);

	for (int i = 0; i < a.w; i++) {
		for (int j = 0; j < b.h; j++) {
			T& ret = ans[i][j];
			for (int k = 0; k < b.w; k++)
				ret += a[i][k] * b[k][j];
		}
	}
	return ans;
}
Matrix<ll> matmultiply(Matrix<ll> a, Matrix<ll> b, ll mod = 0) {
	Matrix<ll> ans(a.w, b.h);

	for (int i = 0; i < a.w; i++) {
		for (int j = 0; j < b.h; j++) {
			ll& ret = ans[i][j];
			for (int k = 0; k < b.w; k++) {
				ret += a[i][k] * b[k][j];
				if (mod) ret = ret % mod;
			}
		}
	}
	return ans;
}
Matrix<int> matmultiply(Matrix<int> a, Matrix<int> b, ll mod = 0) {
	Matrix<int> ans(a.w, b.h);

	for (int i = 0; i < a.w; i++) {
		for (int j = 0; j < b.h; j++) {
			int& ret = ans[i][j];
			for (int k = 0; k < b.w; k++) {
				ret += a[i][k] * b[k][j];
				if (mod) ret = ret % mod;
			}
		}
	}
	return ans;
}
Matrix<ll> llmatOne(int w, int h) { return Matrix<ll>(w, h, 1); }
Matrix<ld> ldmatOne(int w, int h) { return Matrix<ld>(w, h, 1.0); }
template<typename T>
Matrix<T> operator+(Matrix<T> a, Matrix<T> b) {
	assert(a.w == b.w && a.h == b.h);
	Matrix<T> ans(a.w, a.h);
	for (int i = 0; i < a.w; i++) for (int j = 0; j < a.h; j++)
		ans[i][j] = a[i][j] + b[i][j];
	return ans;
}
template<typename T>
Matrix<T> operator-(Matrix<T> a, Matrix<T> b) {
	assert(a.w == b.w && a.h == b.h);
	Matrix<T> ans(a.w, a.h);
	for (int i = 0; i < a.w; i++) for (int j = 0; j < a.h; j++)
		ans[i][j] = a[i][j] - b[i][j];
	return ans;
}
template<typename T>
Matrix<T> operator*(Matrix<T> a, Matrix<T> b) {
	return matmultiply(a, b);
}
template<typename T>
Matrix<T> operator%(Matrix<T> a, ll b) {
	for (int i = 0; i < a.w; i++)
		for (int j = 0; j < a.h; j++)
			a[i][j] %= b;
	return a;
}
template<typename T>
Matrix<T> operator%(ll b, Matrix<T> a) {
	return a % b;
}

template<typename T>
ostream& operator<<(ostream& os, Matrix<T> mat) {
	for (int i = 0; i < mat.w; i++) {
		for (int j = 0; j < mat.h; j++)
			os << mat[i][j] << " ";
		os << "\n";
	}
	return os;
}

pi operator-(const pi& a, const pi& b) {
	return pi(a.fi - b.fi, a.se - b.se);
}
pi operator+(const pi& a, const pi& b) {
	return pi(a.fi + b.fi, a.se + b.se);
}
pi operator*(const pi& a, ll b) {
	return pi(a.fi * b, a.se * b);
}
pll operator-(const pll& a, const pll& b) {
	return pi(a.fi - b.fi, a.se - b.se);
}
pll operator+(const pll& a, const pll& b) {
	return pi(a.fi + b.fi, a.se + b.se);
}
pll operator*(const pll& a, ll b) {
	return pi(a.fi * b, a.se * b);
}
ostream& operator<<(ostream& os, pi p) {
	os << "(" << p.fi << ", " << p.second << ")";
	return os;
}
ostream& operator<<(ostream& os, pll p) {
	os << "(" << p.fi << ", " << p.second << ")";
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
	for (T w : vec) os << w << " ";
	return os;
}
ll mtrand(ll min, ll max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<ll> dist(min, max);
	return dist(mt);
}
ll ccw(pi a, pi b, pi c, bool area = false) {
	ll ans = (b.fi - a.fi) * (c.se - a.se) - (c.fi - a.fi) * (b.se - a.se);
	if (area) return ans;
	else {
		if (ans < 0) return -1;
		else if (ans == 0) return 0;
		else return 1;
	}
}
ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll mypow(ll x, ll cnt, ll mod = 0) {
	if (!cnt) return 1;
	if (cnt == 1) return x;
	ll mid = mypow(x, cnt / 2, mod); if (mod) mid %= mod;
	ll ans = mid * mid; if (mod) ans %= mod;
	ans *= (cnt % 2 ? x : 1); if (mod) ans %= mod;
	return ans;
}
Matrix<ll> mypow(Matrix<ll> x, ll cnt, ll mod = 0) {
	if (!cnt) return llmatOne(x.w, x.h);
	if (cnt == 1) return x;
	Matrix<ll> mid = mypow(x, cnt / 2, mod);
	Matrix<ll> ans = matmultiply(mid, mid, mod);
	if (cnt % 2) { ans = matmultiply(x, ans, mod); }
	return ans;
}
vector<ll> getdivisor(ll x) {
	vector<ll> ans;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			ans.push_back(i);
			if (i != x / i)ans.push_back(x / i);
		}
	}
	if (x != 1) ans.push_back(x);
	return ans;
}
vector<ll> getfactor(ll x) {
	vector<ll> ans;
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			ans.push_back(i);
			x /= i;
		}
	}
	if (x != 1) ans.push_back(x);
	return ans;
}
bool isPrime(ll x) {
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}
ll egcd(ll a, ll b, ll& x, ll& y) {
	if (!a) { x = 0, y = 1; return b; }
	ll x1, y1;
	ll g = egcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1, y = x1;
	return g;
}
ll modinv(ll a, ll mod) {
	ll x, y;
	ll g = egcd(a, mod, x, y);
	if (g != -1) return -1;
	else { x = (x % mod + mod) % mod; return x; }
}
ll fibo(ll x, ll mod = 0) {
	Matrix<ll> mat(2, 2);
	mat.mat = { {1, 1}, {1, 0} };
	mat = mypow(mat, x, mod);
	return mat[0][1];
}

void FFT(vector<base>& f, base w) {
	int n = f.size();
	if (n == 1) return;

	int half = n >> 1;
	vector<base> even(half), odd(half);
	for (int i = 0; i < n; i++)
		(i % 2 ? odd : even)[i >> 1] = f[i];

	FFT(even, w * w); FFT(odd, w * w);

	base wp(1, 0);
	for (int i = 0; i < half; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + half] = even[i] - wp * odd[i];
		wp *= w;
	}
}

vector<base> FFTmultiply(vector<base>& a, vector<base>& b) {
	int n = 1;
	while (n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2;
	a.resize(n); b.resize(n);
	vector<base> c(n);

	base w(cos(2 * PI / n), sin(2 * PI / n));
	FFT(a, w); FFT(b, w);

	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

	FFT(c, base(1, 0) / w);
	for (int i = 0; i < n; i++) {
		c[i] /= base(n, 0);
		c[i] = base(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}

struct UnionFind {
	int n;
	vector<int> dsu;
	void Init(int _n) {
		dsu.clear(); dsu.resize(n = _n);
		iota(dsu.begin(), dsu.end(), 0);
	}
	int find(int x) { return (dsu[x] == x ? x : dsu[x] = find(dsu[x])); }
	bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		dsu[b] = a; return true;
	}
};

struct Segment {
	int n;
	vector<ll> seg;
	void Init(int _n) {
		n = _n;
		seg.clear(); seg.resize(4 * n);
	}
	ll update(int num, int s, int e, int idx, ll diff) {
		if (idx < s || e < idx) return seg[num];
		if (s == e) return seg[num] = diff;
		int mid = s + e >> 1;
		return seg[num] = update(2 * num, s, mid, idx, diff) + update(2 * num + 1, mid + 1, e, idx, diff);
	}
	void update(int idx, ll diff) { update(1, 0, n - 1, idx, diff); }
	ll query(int num, int s, int e, int l, int r) {
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) return seg[num];
		int mid = s + e >> 1;
		return query(2 * num, s, mid, l, r) + query(2 * num + 1, mid + 1, e, l, r);
	}
	ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
struct LazySegment {
	int n;
	vector<ll> lazy, seg;
	void Init(int _n) {
		n = _n;
		seg.clear(); seg.resize(4 * n);
		lazy.clear(); lazy.resize(4 * n);
	}
	void updatelazy(int num, int s, int e) {
		seg[num] += 1LL * (e - s + 1) * lazy[num];
		if (s != e) {
			lazy[2 * num] += lazy[num];
			lazy[2 * num + 1] += lazy[num];
		}
		lazy[num] = 0;
	}
	ll update(int num, int s, int e, int l, int r, ll diff) {
		updatelazy(num, s, e);
		if (r < s || e < l) return seg[num];
		if (l <= s && e <= r) {
			lazy[num] += diff;
			updatelazy(num, s, e);
			return seg[num];
		}
		int mid = s + e >> 1;
		return seg[num] = update(2 * num, s, mid, l, r, diff) + update(2 * num + 1, mid + 1, e, l, r, diff);
	}
	void update(int l, int r, ll diff) { update(1, 0, n - 1, l, r, diff); }
	void update(int idx, ll diff) { update(idx, idx, diff); }
	ll query(int num, int s, int e, int l, int r) {
		updatelazy(num, s, e);
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) return seg[num];
		int mid = s + e >> 1;
		return query(2 * num, s, mid, l, r) + query(2 * num + 1, mid + 1, e, l, r);
	}
	ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
struct RMQ {
	int n;
	vector<ll> minseg, maxseg;
	void Init(int _n) {
		n = _n;
		minseg.clear(); minseg.resize(4 * n, 1e18);
		maxseg.clear(); maxseg.resize(4 * n, -1e18);
	}
	void update(int num, int s, int e, int idx, ll diff) {
		if (idx < s || e < idx) return;
		if (s == e) {
			minseg[idx] = maxseg[idx] = diff;
			return;
		}
		int mid = s + e >> 1;
		update(2 * num, s, mid, idx, diff);
		update(2 * num + 1, mid + 1, e, idx, diff);
		minseg[num] = min(minseg[2 * num], minseg[2 * num + 1]);
		maxseg[num] = max(maxseg[2 * num], maxseg[2 * num + 1]);
	}
	ll maxquery(int num, int s, int e, int l, int r) {
		if (r < s || e < l) return -1e18;
		if (l <= s && e <= r) return maxseg[num];
		int mid = s + e >> 1;
		return max(maxquery(2 * num, s, mid, l, r), maxquery(2 * num + 1, mid + 1, e, l, r));
	}
	ll maxquery(int l, int r) { return maxquery(1, 0, n - 1, l, r); }
	ll minquery(int num, int s, int e, int l, int r) {
		if (r < s || e < l) return 1e18;
		if (l <= s && e <= r) return minseg[num];
		int mid = s + e >> 1;
		return min(minquery(2 * num, s, mid, l, r), minquery(2 * num + 1, mid + 1, e, l, r));
	}
	ll minquery(int l, int r) { return minquery(1, 0, n - 1, l, r); }
};
struct Fenwick {
	int n;
	vector<ll> tree;
	void Init(int _n) {
		n = _n;
		tree.resize(n + 1);
	}
	void udpate(int idx, ll diff) {
		idx++;
		for (;; idx += (idx & -idx)) tree[idx] += diff;
	}
	ll query(int idx) {
		ll ans = 0; idx++;
		for (; idx <= n; idx -= (idx & -idx)) ans += tree[idx];
		return ans;
	}
	ll query(int l, int r) { return query(r) - query(l - 1); }
};
struct LazyFenwick {
	int n;
	vector<ll> tree;
	void Init(int _n) {
		n = _n;
		tree.resize(n + 1);
	}
	void upt(int idx, ll diff) {
		idx++;
		for (;; idx += (idx & -idx)) tree[idx] += diff;
	}
	void update(int l, int r, ll diff) {
		upt(l, diff); upt(r + 1, -diff);
	}
	ll query(int idx) {
		ll ans = 0; idx++;
		for (; idx > 0; idx -= (idx & -idx)) ans += tree[idx];
		return ans;
	}
};

const ll inf = 1e9;

ll func(ll sa, ll sb, ld sp, ll ea, ll eb, ld eq) {
	function<ll(ll)> f = [&](ll x) -> ll {
		if (-sa*x+sp < 0 || -eb*x+eq < 0) return -inf;
		ld fa = (-1.0 * sa*x + 1.0 * sp) / sb,
			fb = (-1.0 * ea * x + 1.0 * eq) / eb;
		fa = floor(fa), fb = floor(fb);
		if (fa > fb) return -inf;
		return x + fa;
	};
	ll ans = 0, lo = 0, hi = 1e9;
	lo = 0, hi = 1e9;
	while (hi-lo>=3) {
		ll p = (2 * lo + hi) / 3, q = (lo + 2 * hi) / 3;
		if (f(p) <= f(q)) lo = p;
		else hi = q;
	}
	for (ll i = lo; i <= hi; i++) ans = max(ans, f(i));
	lo = 0, hi = 1e9;
	while (hi - lo >= 3) {
		ll p = (2 * lo + hi) / 3, q = (lo + 2 * hi) / 3;
		if (f(p) <= f(q)) hi = q;
		else lo = p;
	}
	for (ll i = lo; i <= hi; i++) ans = max(ans, f(i));

	lo = 0, hi = 1e9;
	while (hi - lo >= 3) {
		ll p = (2 * lo + hi) / 3, q = (lo + 2 * hi) / 3;
		if (f(p) >= f(q)) lo = p;
		else hi = q;
	}
	for (ll i = lo; i <= hi; i++) ans = max(ans, f(i));
	lo = 0, hi = 1e9;
	while (hi - lo >= 3) {
		ll p = (2 * lo + hi) / 3, q = (lo + 2 * hi) / 3;
		if (f(p) >= f(q)) hi = q;
		else lo = p;
	}
	for (ll i = lo; i <= hi; i++) ans = max(ans, f(i));
	return ans;
}

ll solve() {
	ll a, b, p, q; cin >> p >> q >> a >> b;
	return max(func(a, b, p, b, a, q), func(b, a, q, a, b, p));
}

int main() {
#if defined(OJ)
	fastio;
#else
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
#endif

	int tc; cin >> tc;
	while (tc--) cout << solve() << "\n";
	return 0;
}