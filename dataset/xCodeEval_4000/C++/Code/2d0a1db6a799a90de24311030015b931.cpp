

#include <bits/stdc++.h>

using namespace std;

#define MULTITEST

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 256 + 7;

int n, m;
vector<pair<pt, int>> e;

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	e.clear();
	forn(i, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		e.pb(mp(mp(v, u), w));
	}
	return true;
}

template<const int &MOD>
struct _m_int {
	int val;
 
	_m_int(int64_t v = 0) {
		if (v < 0) v = v % MOD + MOD;
		if (v >= MOD) v %= MOD;
		val = int(v);
	}
 
	_m_int(uint64_t v) {
		if (v >= MOD) v %= MOD;
		val = int(v);
	}
 
	_m_int(int v) : _m_int(int64_t(v)) {}
	_m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
	static int inv_mod(int a, int m = MOD) {
		int g = m, r = a, x = 0, y = 1;
 
		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
 
		return x < 0 ? x + m : x;
	}
 
	explicit operator int() const { return val; }
	explicit operator unsigned() const { return val; }
	explicit operator int64_t() const { return val; }
	explicit operator uint64_t() const { return val; }
	explicit operator double() const { return val; }
	explicit operator long double() const { return val; }
 
	_m_int& operator+=(const _m_int &other) {
		val -= MOD - other.val;
		if (val < 0) val += MOD;
		return *this;
	}
 
	_m_int& operator-=(const _m_int &other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}
 
	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
		return unsigned(x % m);
#endif
		

		

		unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
		unsigned quot, rem;
		asm("divl %4\n"
			: "=a" (quot), "=d" (rem)
			: "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}
 
	_m_int& operator*=(const _m_int &other) {
		val = fast_mod(uint64_t(val) * other.val);
		return *this;
	}
 
	_m_int& operator/=(const _m_int &other) {
		return *this *= other.inv();
	}
 
	friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
	friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
	friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
	friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
	_m_int& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}
 
	_m_int& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}
 
	_m_int operator++(int) { _m_int before = *this; ++*this; return before; }
	_m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
	_m_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}
 
	friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
	friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
	friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
	friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
	friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
	friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
	_m_int inv() const {
		return inv_mod(val);
	}
 
	_m_int pow(int64_t p) const {
		if (p < 0)
			return inv().pow(-p);
 
		_m_int a = *this, result = 1;
 
		while (p > 0) {
			if (p & 1)
				result *= a;
			a *= a;
			p >>= 1;
		}
 
		return result;
	}
 
	friend ostream& operator<<(ostream &os, const _m_int &m) {
		return os << m.val;
	}
};
 
extern const int MOD = 3;
using Mint = _m_int<MOD>;

template<class T>
int gauss(vector<valarray<T>> a, vector<T> &ans) {
	if (a.empty()){
		ans = vector<T>(m);
		return 1;
	}
	int n = sz(a);
	int m = sz(a[0]) - 1;

	vector<int> where(m, -1);
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int sel = row;
		fore(i, row, n) if (a[i][col] > a[sel][col])
			sel = i;
		if (a[sel][col] == 0)
			continue;
		swap(a[sel], a[row]);
		where[col] = row;
		forn(i, n) if (i != row) {
			T c = a[i][col] / a[row][col];
			a[i] -= a[row] * c;
		}
		++row;
	}

	ans.assign(m, 0);
	forn(i, m) if (where[i] != -1)
		ans[i] = a[where[i]][m] / a[where[i]][i];
	
	forn(i, n) {
		T sum = 0;
		forn(j, m)
			sum += ans[j] * a[i][j];
		if (sum != a[i][m])
			return 0;
	}
	
	return 1;
}

void solve() {
	vector<valarray<Mint>> a;
	forn(i, m) if (e[i].y != -1){
		a.pb({});
		a.back().resize(m + 1);
		a.back()[i] = 1;
		a.back()[m] = e[i].y % 3;
	}
	map<pt, int> es;
	forn(i, m){
		if (e[i].x.x > e[i].x.y)
			swap(e[i].x.x, e[i].x.y);
		es[e[i].x] = i;
	}
	forn(i, n) forn(j, i) forn(k, j){
		if (!es.count(mp(j, i))) continue;
		if (!es.count(mp(k, j))) continue;
		if (!es.count(mp(k, i))) continue;
		a.pb({});
		a.back().resize(m + 1);
		a.back()[es[mp(j, i)]] = 1;
		a.back()[es[mp(k, j)]] = 1;
		a.back()[es[mp(k, i)]] = 1;
		a.back()[m] = 0;
	}
	vector<Mint> ans;
	if (!gauss(a, ans)){
		puts("-1");
		return;
	}
	forn(i, m) printf("%d ", ans[i] == 0 ? 3 : int(ans[i]));
	puts("");
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}