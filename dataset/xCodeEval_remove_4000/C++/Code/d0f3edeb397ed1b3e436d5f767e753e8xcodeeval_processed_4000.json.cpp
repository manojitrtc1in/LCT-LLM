


















namespace atcoder {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) x += m;
	return x;
}







struct barrett {
	unsigned int _m;
	unsigned long long im;

	

	explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

	

	unsigned int umod() const { return _m; }

	

	

	

	unsigned int mul(unsigned int a, unsigned int b) const {
		

		


		

		

		

		

		

		

		

		unsigned long long z = a;
		z *= b;

		unsigned long long x;
		_umul128(z, im, &x);

		unsigned long long x =
		    (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

		unsigned int v = (unsigned int)(z - x * _m);
		if(_m <= v) v += _m;
		return v;
	}
};







constexpr long long id8(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while(n) {
		if(n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}









constexpr bool id6(int n) {
	if(n <= 1) return false;
	if(n == 2 || n == 7 || n == 61) return true;
	if(n % 2 == 0) return false;
	long long d = n - 1;
	while(d % 2 == 0) d /= 2;
	constexpr long long bases[3] = {2, 7, 61};
	for(long long a : bases) {
		long long t = d;
		long long y = id8(a, t, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = y * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}
template <int n>
constexpr bool is_prime = id6(n);





constexpr std::pair<long long, long long> id1(long long a, long long b) {
	a = safe_mod(a, b);
	if(a == 0) return {b, 0};

	

	

	

	

	long long s = b, t = a;
	long long m0 = 0, m1 = 1;

	while(t) {
		long long u = s / t;
		s -= t * u;
		m0 -= m1 * u;  


		

		

		

		


		auto tmp = s;
		s = t;
		t = tmp;
		tmp = m0;
		m0 = m1;
		m1 = tmp;
	}
	

	

	if(m0 < 0) m0 += b / s;
	return {s, m0};
}







constexpr int id3(int m) {
	if(m == 2) return 1;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 998244353) return 3;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m - 1) / 2;
	while(x % 2 == 0) x /= 2;
	for(int i = 3; (long long)(i)*i <= x; i += 2) {
		if(x % i == 0) {
			divs[cnt++] = i;
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) {
		divs[cnt++] = x;
	}
	for(int g = 2;; g++) {
		bool ok = true;
		for(int i = 0; i < cnt; i++) {
			if(id8(g, (m - 1) / divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) return g;
	}
}
template <int m>
constexpr int primitive_root = id3(m);







unsigned long long id0(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
	unsigned long long ans = 0;
	while(true) {
		if(a >= m) {
			ans += n * (n - 1) / 2 * (a / m);
			a %= m;
		}
		if(b >= m) {
			ans += n * (b / m);
			b %= m;
		}

		unsigned long long y_max = a * n + b;
		if(y_max < m) break;
		

		

		n = (unsigned long long)(y_max / m);
		b = (unsigned long long)(y_max % m);
		std::swap(m, a);
	}
	return ans;
}

}  


}  






namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



template <class T>
using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  


namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T>
using is_modint = std::is_base_of<modint_base, T>;
template <class T>
using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
struct id5 : internal::static_modint_base {
	using mint = id5;

public:
	static constexpr int mod() { return m; }
	static mint raw(int v) {
		mint x;
		x._v = v;
		return x;
	}

	id5() : _v(0) {}
	template <class T, internal::is_signed_int_t<T> * = nullptr>
	id5(T v) {
		long long x = (long long)(v % (long long)(umod()));
		if(x < 0) x += umod();
		_v = (unsigned int)(x);
	}
	template <class T, internal::is_unsigned_int_t<T> * = nullptr>
	id5(T v) {
		_v = (unsigned int)(v % umod());
	}

	unsigned int val() const { return _v; }

	mint &operator++() {
		_v++;
		if(_v == umod()) _v = 0;
		return *this;
	}
	mint &operator--() {
		if(_v == 0) _v = umod();
		_v--;
		return *this;
	}
	mint operator++(int) {
		mint result = *this;
		++*this;
		return result;
	}
	mint operator--(int) {
		mint result = *this;
		--*this;
		return result;
	}

	mint &operator+=(const mint &rhs) {
		_v += rhs._v;
		if(_v >= umod()) _v -= umod();
		return *this;
	}
	mint &operator-=(const mint &rhs) {
		_v -= rhs._v;
		if(_v >= umod()) _v += umod();
		return *this;
	}
	mint &operator*=(const mint &rhs) {
		unsigned long long z = _v;
		z *= rhs._v;
		_v = (unsigned int)(z % umod());
		return *this;
	}
	mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

	mint operator+() const { return *this; }
	mint operator-() const { return mint() - *this; }

	mint pow(long long n) const {
		assert(0 <= n);
		mint x = *this, r = 1;
		while(n) {
			if(n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	mint inv() const {
		if(prime) {
			assert(_v);
			return pow(umod() - 2);
		} else {
			auto eg = internal::id1(_v, m);
			assert(eg.first == 1);
			return eg.second;
		}
	}

	friend mint operator+(const mint &lhs, const mint &rhs) {
		return mint(lhs) += rhs;
	}
	friend mint operator-(const mint &lhs, const mint &rhs) {
		return mint(lhs) -= rhs;
	}
	friend mint operator*(const mint &lhs, const mint &rhs) {
		return mint(lhs) *= rhs;
	}
	friend mint operator/(const mint &lhs, const mint &rhs) {
		return mint(lhs) /= rhs;
	}
	friend bool operator==(const mint &lhs, const mint &rhs) {
		return lhs._v == rhs._v;
	}
	friend bool operator!=(const mint &lhs, const mint &rhs) {
		return lhs._v != rhs._v;
	}

private:
	unsigned int _v;
	static constexpr unsigned int umod() { return m; }
	static constexpr bool prime = internal::is_prime<m>;
};

template <int id>
struct id4 : internal::modint_base {
	using mint = id4;

public:
	static int mod() { return (int)(bt.umod()); }
	static void set_mod(int m) {
		assert(1 <= m);
		bt = internal::barrett(m);
	}
	static mint raw(int v) {
		mint x;
		x._v = v;
		return x;
	}

	id4() : _v(0) {}
	template <class T, internal::is_signed_int_t<T> * = nullptr>
	id4(T v) {
		long long x = (long long)(v % (long long)(mod()));
		if(x < 0) x += mod();
		_v = (unsigned int)(x);
	}
	template <class T, internal::is_unsigned_int_t<T> * = nullptr>
	id4(T v) {
		_v = (unsigned int)(v % mod());
	}

	unsigned int val() const { return _v; }

	mint &operator++() {
		_v++;
		if(_v == umod()) _v = 0;
		return *this;
	}
	mint &operator--() {
		if(_v == 0) _v = umod();
		_v--;
		return *this;
	}
	mint operator++(int) {
		mint result = *this;
		++*this;
		return result;
	}
	mint operator--(int) {
		mint result = *this;
		--*this;
		return result;
	}

	mint &operator+=(const mint &rhs) {
		_v += rhs._v;
		if(_v >= umod()) _v -= umod();
		return *this;
	}
	mint &operator-=(const mint &rhs) {
		_v += mod() - rhs._v;
		if(_v >= umod()) _v -= umod();
		return *this;
	}
	mint &operator*=(const mint &rhs) {
		_v = bt.mul(_v, rhs._v);
		return *this;
	}
	mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

	mint operator+() const { return *this; }
	mint operator-() const { return mint() - *this; }

	mint pow(long long n) const {
		assert(0 <= n);
		mint x = *this, r = 1;
		while(n) {
			if(n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	mint inv() const {
		auto eg = internal::id1(_v, mod());
		assert(eg.first == 1);
		return eg.second;
	}

	friend mint operator+(const mint &lhs, const mint &rhs) {
		return mint(lhs) += rhs;
	}
	friend mint operator-(const mint &lhs, const mint &rhs) {
		return mint(lhs) -= rhs;
	}
	friend mint operator*(const mint &lhs, const mint &rhs) {
		return mint(lhs) *= rhs;
	}
	friend mint operator/(const mint &lhs, const mint &rhs) {
		return mint(lhs) /= rhs;
	}
	friend bool operator==(const mint &lhs, const mint &rhs) {
		return lhs._v == rhs._v;
	}
	friend bool operator!=(const mint &lhs, const mint &rhs) {
		return lhs._v != rhs._v;
	}

private:
	unsigned int _v;
	static internal::barrett bt;
	static unsigned int umod() { return bt.umod(); }
};
template <int id>
internal::barrett id4<id>::bt(998244353);

using modint998244353 = id5<998244353>;
using modint1000000007 = id5<1000000007>;
using modint = id4<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class>
struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id4<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  




using namespace std;


































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

	int id2; \
	scanner::INPUT(id2)

	long long id2; \
	scanner::INPUT(id2)

	std::string id2; \
	scanner::INPUT(id2)

	char id2; \
	scanner::INPUT(id2)

	double id2; \
	scanner::INPUT(id2)

	long double id2; \
	scanner::INPUT(id2)



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
		debug_out(id2);                                   \
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
void ADD(std::vector<T> &a, const T x = 1) {
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
std::vector<std::pair<char, int>> rle(const string &s) {
	int n = s.size();
	std::vector<std::pair<char, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and s[l] == s[r]; r++) {}
		ret.emplace_back(s[l], r - l);
		l = r;
	}
	return ret;
}
template <class T>
std::vector<std::pair<T, int>> rle(const std::vector<T> &v) {
	int n = v.size();
	std::vector<std::pair<T, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and v[l] == v[r]; r++) {}
		ret.emplace_back(v[l], r - l);
		l = r;
	}
	return ret;
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
} id7;
const int inf = 1e9;
const ll INF = 1e18;


void main_();

int main() {
	main_();
	return 0;
}


std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &a) { return os << a.val(); }
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::id5<m> &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::id4<m> &a) { return os << a.val(); }

using mint = atcoder::modint1000000007;

mint res;
void main_() {
	INT(n);
	vector<mint> a(n);
	{
		VEC(int, tmp_vec, n);
		REP(i, n) { a[i] = tmp_vec[i]; }
	}
	vector gyaku(n, vector(n, mint(0)));
	REP(i, n) {
		REP(j, n) {
			gyaku[i][j] = 1 / (a[i] + a[j]);
		}
	}

	VV<> id9(1 << (n - 1));
	REP(b, 1 << (n - 1)) {
		REP(i, n - 1) {
			if(b >> i & 1) id9[b].pb(i);
		}
	}
	REP(i, n) {
		vector<int> benri;
		REP(j, n) {
			if(j == i) continue;
			benri.pb(j);
		}
		int s = n - 1;
		int mask = (1 << s) - 1;
		vector f(1 << s, mint(0));
		f[mask] = 1;
		RREP(b, 1 << s) {
			if(b == 0) break;
			for(int t = b;; t = (t - 1) & b) {
				if(t == b) continue;
				int opo = t ^ b;
				int now = b ^ mask;
				mint mul = 1;
				foa(opo_id, id9[opo]) {
					int op = benri[opo_id];
					mint lose = 1;
					foa(mi, id9[now]) {
						lose *= a[op] * gyaku[op][benri[mi]];
					}
					lose *= a[op] * gyaku[op][i];
					mul *= (1 - lose);
				}
				f[t] -= f[b] * mul;
				if(t == 0) break;
			}
		}
		res += f[0];
	}
	if((n & 1) == 0) res *= -1;

	print(res.val());
}