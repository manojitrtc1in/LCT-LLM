









using namespace std;



using ll = long long; 

using pii = pair<int, int>;	using pll = pair<ll, ll>;	using pil = pair<int, ll>;	using pli = pair<ll, int>;
using vi = vector<int>;		using vvi = vector<vi>;		using vvvi = vector<vvi>;
using vl = vector<ll>;		using vvl = vector<vl>;		using vvvl = vector<vvl>;
using vb = vector<bool>;	using vvb = vector<vb>;		using vvvb = vector<vvb>;
using vc = vector<char>;	using vvc = vector<vc>;		using vvvc = vector<vvc>;
using vd = vector<double>;	using vvd = vector<vd>;		using vvvd = vector<vvd>;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
using Graph = vvi;



const double PI = 3.14159265359;
const double DEG = PI / 180.; 

const vi dx4 = { 1, 0, -1, 0 }; 

const vi dy4 = { 0, 1, 0, -1 };
const vi dx8 = { 1, 1, 0, -1, -1, -1, 0, 1 }; 

const vi dy8 = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001; const ll INFL = 2002002002002002002LL;
const double EPS = 1e-10; 




struct fast_io { fast_io() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } id2;
































template <class T> inline ll pow(T n, int k) { ll v = 1; rep(i, k) v *= n; return v; }
template <class T> inline bool chmax(T& M, const T& x) { if (M < x) { M = x; return true; } return false; } 

template <class T> inline bool chmin(T& m, const T& x) { if (m > x) { m = x; return true; } return false; } 




template <class T, class U> inline istream& operator>> (istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template <class T, class U> inline ostream& operator<< (ostream& os, const pair<T, U>& p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <class T, class U, class V> inline istream& operator>> (istream& is, tuple<T, U, V>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template <class T, class U, class V> inline ostream& operator<< (ostream& os, const tuple<T, U, V>& t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template <class T, class U, class V, class W> inline istream& operator>> (istream& is, tuple<T, U, V, W>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t); return is; }
template <class T, class U, class V, class W> inline ostream& operator<< (ostream& os, const tuple<T, U, V, W>& t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << "," << get<3>(t) << ")"; return os; }
template <class T> inline istream& operator>> (istream& is, vector<T>& v) { repea(x, v) is >> x; return is; }
template <class T> inline ostream& operator<< (ostream& os, const vector<T>& v) { repe(x, v) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const list<T>& v) { repe(x, v) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const set<T, greater<T>>& s) { repe(x, s) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const unordered_set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const multiset<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const unordered_map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, stack<T> s) { while (!s.empty()) { os << s.top() << " "; s.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, queue<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, deque<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop_front(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, priority_queue<T> q) { while (!q.empty()) { os << q.top() << " "; q.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, priority_queue_rev<T> q) { while (!q.empty()) { os << q.top() << " "; q.pop(); } return os; }
template <class T> inline vector<T>& operator--(vector<T>& v) { rep(_i_, sz(v)) --v[_i_]; return v; }
template <class T> inline vector<T>& operator++(vector<T>& v) { rep(_i_, sz(v)) ++v[_i_]; return v; }







inline int lsb(unsigned int n) { unsigned long i; _BitScanForward(&i, n); return i; } 

inline int id1(unsigned long long n) { unsigned long i; _BitScanForward64(&i, n); return i; }
inline int msb(unsigned int n) { unsigned long i; _BitScanReverse(&i, n); return i; } 

inline int id0(unsigned long long n) { unsigned long i; _BitScanReverse64(&i, n); return i; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }






























































struct mint {
	


	ll v;

	

	static const ll MOD = (ll)1e9 + 7;



	

	mint() : v(0) {};
	mint(const mint& a) = default;
	mint(int a) : v(safe_mod(a)) {};
	mint(ll a) : v(safe_mod(a)) {};

	

	mint& operator=(const mint& a) { v = a.v; return *this; }
	mint& operator=(int a) { v = safe_mod(a); return *this; }
	mint& operator=(ll a) { v = safe_mod(a); return *this; }

	

	friend istream& operator>> (istream& is, mint& x) { is >> x.v; x.v = safe_mod(x.v); return is; }
	friend ostream& operator<< (ostream& os, const mint& x) { os << x.v; return os; }

	

	template <class T> static ll safe_mod(T a) { return (((ll)a % MOD) + MOD) % MOD; }

	

	bool operator==(const mint& b) const { return v == b.v; }
	bool operator==(int b) const { return v == safe_mod(b); }
	bool operator==(ll b) const { return v == safe_mod(b); }
	friend bool operator==(int a, const mint& b) { return b == a; }
	friend bool operator==(ll a, const mint& b) { return b == a; }
	bool operator!=(const mint& b) const { return v != b.v; }
	bool operator!=(int b) const { return v != safe_mod(b); }
	bool operator!=(ll b) const { return v != safe_mod(b); }
	friend bool operator!=(int a, const mint& b) { return b != a; }
	friend bool operator!=(ll a, const mint& b) { return b != a; }

	

	mint operator-() const { mint a = *this; return a *= -1; }
	mint& operator++() { v = safe_mod(v + 1); return *this; }
	mint operator++(int) { mint tmp = *this; ++(*this); return tmp; }
	mint& operator--() { v = safe_mod(v - 1); return *this; }
	mint operator--(int) { mint tmp = *this; --(*this); return tmp; }

	

	mint& operator+=(const mint& b) { v = safe_mod(v + b.v); return *this; }
	mint& operator-=(const mint& b) { v = safe_mod(v - b.v); return *this; }
	mint& operator*=(const mint& b) { v = safe_mod(v * b.v); return *this; }
	mint& operator/=(const mint& b) { *this *= b.inv(); return *this; }
	mint operator+(const mint& b) const { mint a = *this; return a += b; }
	mint operator-(const mint& b) const { mint a = *this; return a -= b; }
	mint operator*(const mint& b) const { mint a = *this; return a *= b; }
	mint operator/(const mint& b) const { mint a = *this; return a /= b; }

	

	mint& operator+=(int b) { v = safe_mod(v + b); return *this; }
	mint& operator-=(int b) { v = safe_mod(v - b); return *this; }
	mint& operator*=(int b) { v = safe_mod(v * b); return *this; }
	mint& operator/=(int b) { *this *= mint(b).inv(); return *this; }
	mint operator+(int b) const { mint a = *this; return a += b; }
	mint operator-(int b) const { mint a = *this; return a -= b; }
	mint operator*(int b) const { mint a = *this; return a *= b; }
	mint operator/(int b) const { mint a = *this; return a /= b; }
	friend mint operator+(int a, const mint& b) { return b + a; }
	friend mint operator-(int a, const mint& b) { return -(b - a); }
	friend mint operator*(int a, const mint& b) { return b * a; }
	friend mint operator/(int a, const mint& b) { return b.inv() * a; }

	

	mint& operator+=(ll b) { v = safe_mod(v + (b % MOD)); return *this; }
	mint& operator-=(ll b) { v = safe_mod(v - (b % MOD)); return *this; }
	mint& operator*=(ll b) { v = safe_mod(v * (b % MOD)); return *this; }
	mint& operator/=(ll b) { *this *= mint(b).inv(); return *this; }
	mint operator+(ll b) const { mint a = *this; return a += b; }
	mint operator-(ll b) const { mint a = *this; return a -= b; }
	mint operator*(ll b) const { mint a = *this; return a *= b; }
	mint operator/(ll b) const { mint a = *this; return a /= b; }
	friend mint operator+(ll a, const mint& b) { return b + a; }
	friend mint operator-(ll a, const mint& b) { return -(b - a); }
	friend mint operator*(ll a, const mint& b) { return b * a; }
	friend mint operator/(ll a, const mint& b) { return b.inv() * a; }

	

	mint pow(ll d) const {
		mint res(1), pow2 = *this;
		while (d > 0) {
			if (d & 1LL) res *= pow2;
			pow2 *= pow2;
			d /= 2;
		}
		return res;
	}

	

	mint inv() const {
		assert(v != 0);
		return pow(MOD - 2);
	}

	

	static int mod() { return MOD; }

	

	int val() const { return int(v); }
};
using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>; 

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	

	vvm dp(n + 1, vm(n + 1));
	repi(i, 1, n) {
		repi(j, 1, i - 1) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) / 2;
		}
		dp[i][i] = mint(i) * k;
	}

	cout << dp[n][m] << endl;
}

int main() {





	int t;
	cin >> t; 




	while (t--) {
		dump("------------------------------");
		solve();
	}
}
