






using namespace std;













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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int CR = 7;
const int BITS = 15;

li n;

bool read () {
	if (!(cin >> n))
		return false;
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

		return unsigned(x % m);

		

		

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
 
using Mint = _m_int<MOD>;

Mint dp[CR][BITS + 1][CR][1 << BITS];
Mint cnt[CR][CR][1 << BITS];

void precalc(){
	memset(dp, 0, sizeof(dp));
	forn(i, CR) dp[i][0][i][0] = 1;
	forn(cs, CR) forn(i, BITS) forn(ct, CR) forn(x, 1 << BITS) if (dp[cs][i][ct][x] != 0){
		forn(cc, CR + 1)
			dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x] += dp[cs][i][ct][x];
	}
	forn(i, CR) forn(j, CR) forn(x, 1 << BITS){
		cnt[i][j][x] = dp[i][BITS][j][x];
	}
}

Mint dp2[5][CR];

void solve() {
	memset(dp2, 0, sizeof(dp2));
	dp2[0][0] = 1;
	forn(i, 4){
		int x = (n & ((1 << BITS) - 1));
		n >>= BITS;
		forn(j, CR) forn(k, CR)
			dp2[i + 1][k] += dp2[i][j] * cnt[j][k][x];
	}
	cout << int(dp2[4][0]) << '\n';
}

int main() {
ios::sync_with_stdio(!cin.tie(0));


	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;
	
	precalc();


	int tc;
	cin >> tc;
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}