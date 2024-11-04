





using namespace std;


using namespace atcoder;



































template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;



template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}

std::istream &operator>>(std::istream &is, atcoder::modint998244353 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
std::istream &operator>>(std::istream &is, atcoder::modint1000000007 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::static_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}

namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  


	std::vector<type> name(size); \
	scanner::INPUT(name)

	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)

	int id1; \
	scanner::INPUT(id1)

	long long id1; \
	scanner::INPUT(id1)

	std::string id1; \
	scanner::INPUT(id1)

	char id1; \
	scanner::INPUT(id1)

	double id1; \
	scanner::INPUT(id1)

	long double id1; \
	scanner::INPUT(id1)



template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}

std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &a) { return os << a.val(); }
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<m> &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::dynamic_modint<m> &a) { return os << a.val(); }

template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}



namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  


void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}

	do {                                                          \
		std::cerr << __LINE__ << " [" << 
		debug_out(id1);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)






template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}




template <class T>
void ADD(std::vector<T> &a, const T x) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}



template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}


long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	a = (a % mod + mod) % mod;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}



struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} id2;
const int inf = 1e9;
const ll INF = 1e18;




template <const int &mod>
struct ModInt {
private:
	int x;

public:
	ModInt() : x(0) {}

	ModInt(long long x_) {
		if((x = x_ % mod + mod) >= mod) x -= mod;
	}

	int val() const { return x; }

	static int get_mod() { return mod; }

	constexpr ModInt &operator+=(ModInt rhs) {
		if((x += rhs.x) >= mod) x -= mod;
		return *this;
	}

	constexpr ModInt &operator-=(ModInt rhs) {
		if((x -= rhs.x) < 0) x += mod;
		return *this;
	}

	constexpr ModInt &operator*=(ModInt rhs) {
		x = (unsigned long long)x * rhs.x % mod;
		return *this;
	}

	constexpr ModInt &operator/=(ModInt rhs) {
		x = (unsigned long long)x * rhs.inv().x % mod;
		return *this;
	}

	constexpr ModInt operator-() const noexcept { return -x < 0 ? mod - x : -x; }

	constexpr ModInt operator+(ModInt rhs) const noexcept { return ModInt(*this) += rhs; }

	constexpr ModInt operator-(ModInt rhs) const noexcept { return ModInt(*this) -= rhs; }

	constexpr ModInt operator*(ModInt rhs) const noexcept { return ModInt(*this) *= rhs; }

	constexpr ModInt operator/(ModInt rhs) const noexcept { return ModInt(*this) /= rhs; }

	constexpr ModInt &operator++() {
		*this += 1;
		return *this;
	}

	constexpr ModInt operator++(int) {
		*this += 1;
		return *this - 1;
	}

	constexpr ModInt &operator--() {
		*this -= 1;
		return *this;
	}

	constexpr ModInt operator--(int) {
		*this -= 1;
		return *this + 1;
	}

	bool operator==(ModInt rhs) const { return x == rhs.x; }

	bool operator!=(ModInt rhs) const { return x != rhs.x; }

	bool operator<=(ModInt rhs) const { return x <= rhs.x; }

	bool operator>=(ModInt rhs) const { return x >= rhs.x; }

	bool operator<(ModInt rhs) const { return x < rhs.x; }

	bool operator>(ModInt rhs) const { return x > rhs.x; }

	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while(b > 0) {
			t = a / b;
			std::swap(a -= t * b, b);
			std::swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(long long n) const {
		ModInt ret(1), mul(x);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	ModInt sqrt() const {
		if(x <= 1) return x;
		int v = (mod - 1) / 2;
		if(pow(v) != 1) return -1;
		int q = mod - 1, m = 0;
		while(~q & 1) q >>= 1, m++;
		std::mt19937 mt;
		ModInt z = mt();
		while(z.pow(v) != mod - 1) z = mt();
		ModInt c = z.pow(q), t = pow(q), r = pow((q + 1) / 2);
		for(; m > 1; m--) {
			ModInt tmp = t.pow(1 << (m - 2));
			if(tmp != 1) r = r * c, t = t * c * c;
			c = c * c;
		}
		return std::min(r.x, mod - r.x);
	}

	friend std::ostream &operator<<(std::ostream &s, ModInt<mod> a) {
		s << a.x;
		return s;
	}

	friend std::istream &operator>>(std::istream &s, ModInt<mod> &a) {
		s >> a.x;
		return s;
	}
};



static int MOD = 1e9 + 7;


using mint = ModInt<MOD>;

const int CombMAX = 4000000;
mint fac[CombMAX + 1], finv[CombMAX + 1], inv[CombMAX + 1];

struct Combinationinit {
	Combinationinit() {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for(int i = 2; i <= CombMAX; i++) {
			fac[i] = fac[i - 1] * (mint)i;
			inv[i] = (mint)MOD - inv[MOD % i] * (MOD / i);
			finv[i] = finv[i - 1] * inv[i];
		}
	}
} id0;



mint COM(int n, int k) {
	if(n < k or n < 0 or k < 0) return 0;
	return fac[n] * finv[k] * finv[n - k];
}



mint PER(int n, int k) {
	if(n < k or n < 0 or k < 0) return 0;
	return fac[n] * finv[n - k];
}



mint HOM(int n, int k) { return COM(n + k - 1, k); };






template <class T>
struct FormalPowerSeries : vector<T> {
	using vector<T>::vector;
	using vector<T>::operator=;
	using F = FormalPowerSeries;

	F operator-() const {
		F res(*this);
		for(auto &e : res) e = -e;
		return res;
	}
	F &operator*=(const T &g) {
		for(auto &e : *this) e *= g;
		return *this;
	}
	F &operator/=(const T &g) {
		assert(g != T(0));
		*this *= g.inv();
		return *this;
	}
	F &operator+=(const F &g) {
		int n = (*this).size(), m = g.size();
		rep(i, min(n, m))(*this)[i] += g[i];
		return *this;
	}
	F &operator-=(const F &g) {
		int n = (*this).size(), m = g.size();
		rep(i, min(n, m))(*this)[i] -= g[i];
		return *this;
	}
	F &operator<<=(const int d) {
		int n = (*this).size();
		(*this).insert((*this).begin(), d, 0);
		(*this).resize(n);
		return *this;
	}
	F &operator>>=(const int d) {
		int n = (*this).size();
		(*this).erase((*this).begin(), (*this).begin() + min(n, d));
		(*this).resize(n);
		return *this;
	}

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	F &operator*=(const F &g) {
		int n = (*this).size(), m = g.size();
		drep(i, n) {
			(*this)[i] *= g[0];
			rep2(j, 1, min(i + 1, m))(*this)[i] += (*this)[i - j] * g[j];
		}
		return *this;
	}
	F &operator/=(const F &g) {
		assert(g[0] != T(0));
		mint ig0 = g[0].inv();
		int n = (*this).size(), m = g.size();
		rep(i, n) {
			rep2(j, 1, min(i + 1, m))(*this)[i] -= (*this)[i - j] * g[j];
			(*this)[i] *= ig0;
		}
		return *this;
	}

	

	F &operator*=(vector<pair<int, T>> g) {
		int n = (*this).size();
		auto [d, c] = g.front();
		if(d == 0)
			g.erase(g.begin());
		else
			c = 0;
		drep(i, n) {
			(*this)[i] *= c;
			for(auto &[j, b] : g) {
				if(j > i) break;
				(*this)[i] += (*this)[i - j] * b;
			}
		}
		return *this;
	}
	F &operator/=(vector<pair<int, T>> g) {
		int n = (*this).size();
		auto [d, c] = g.front();
		assert(d == 0 && c != T(0));
		T ic = c.inv();
		g.erase(g.begin());
		rep(i, n) {
			for(auto &[j, b] : g) {
				if(j > i) break;
				(*this)[i] -= (*this)[i - j] * b;
			}
			(*this)[i] *= ic;
		}
		return *this;
	}

	

	void multiply(const int d, const T c) {
		int n = (*this).size();
		if(c == T(1))
			drep(i, n - d)(*this)[i + d] += (*this)[i];
		else if(c == T(-1))
			drep(i, n - d)(*this)[i + d] -= (*this)[i];
		else
			drep(i, n - d)(*this)[i + d] += (*this)[i] * c;
	}
	void divide(const int d, const T c) {
		int n = (*this).size();
		if(c == T(1))
			rep(i, n - d)(*this)[i + d] -= (*this)[i];
		else if(c == T(-1))
			rep(i, n - d)(*this)[i + d] += (*this)[i];
		else
			rep(i, n - d)(*this)[i + d] -= (*this)[i] * c;
	}

	T eval(const T &a) const {
		T x(1), res(0);
		for(auto e : *this) res += e * x, x *= a;
		return res;
	}

	F operator*(const T &g) const { return F(*this) *= g; }
	F operator/(const T &g) const { return F(*this) /= g; }
	F operator+(const F &g) const { return F(*this) += g; }
	F operator-(const F &g) const { return F(*this) -= g; }
	F operator<<(const int d) const { return F(*this) <<= d; }
	F operator>>(const int d) const { return F(*this) >>= d; }
	F operator*(const F &g) const { return F(*this) *= g; }
	F operator/(const F &g) const { return F(*this) /= g; }
	F operator*(vector<pair<int, T>> g) const { return F(*this) *= g; }
	F operator/(vector<pair<int, T>> g) const { return F(*this) /= g; }
};

using fps = FormalPowerSeries<mint>;

void main_() {
	INT(n, q);
	int m = 3 * (n + 1);
	fps f(m);
	REP(i, 0, m) { f[i] = -COM(m, i + 1); }
	fps g(3);
	g[0] = -3;
	g[1] = -3;
	g[2] = -1;
	f /= g;
	while(q--) {
		INT(x);
		cout << f[x] << endl;
	}
}

int main() {
	int t = 1;
	

	while(t--) main_();
	return 0;
}