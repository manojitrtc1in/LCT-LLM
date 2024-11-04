












namespace felix {

class random_t {
public:
	unsigned long long state, seed;

	random_t() : random_t(std::chrono::steady_clock::now().time_since_epoch().count()) {}

	random_t(unsigned long long s) : state(s), seed(s) {}

	inline void set_seed(unsigned long long s) {
		state = seed = s;
	}

	inline void reset() {
		set_seed(seed);
	}

	inline unsigned long long next() {
		state += 0x9e3779b97f4a7c15;
		unsigned long long result = state;
		result = (result ^ (result >> 30)) * 0xbf58476d1ce4e5b9;
		result = (result ^ (result >> 27)) * 0x94d049bb133111eb;
		return result ^ (result >> 31);
	}

	inline unsigned long long next(unsigned long long a) {
		return next() % a;
	}

	inline unsigned long long next(unsigned long long a, unsigned long long b) {
		return a + next(b - a + 1);
	}

	inline long double nextDouble() {
		return ((unsigned int) next()) / 4294967295.0;
	}

	inline long double nextDouble(long double a) {
		return nextDouble() * a;
	}

	inline long double nextDouble(long double a, long double b) {
		return a + nextDouble() * (b - a);
	}

	template<class T>
	void shuffle(std::vector<T>& a) {
		for(int i = int(a.size()) - 1; i >= 0; --i) {
			std::swap(a[i], a[next(i + 1)]);
		}
	}
};

random_t rnd;

} 



namespace felix {

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<class T> using pair2 = std::pair<T, T>;
using pii = pair2<int>;
using pll = pair2<ll>;
using pdd = pair2<ld>;
using tiii = std::tuple<int, int, int>;
template<class T, size_t S> using ar = std::array<T, S>;
template<class T, class U = std::less<T>> using mset = std::multiset<T, U>;
template<class T> using vt = std::vector<T>;
template<class T, class Comp = std::less<T>> using oset = __gnu_pbds::tree<T, __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<class T> using omset = oset<T, std::less_equal<T>>;

struct splitmix64_hash {
	static ull splitmix64(ull x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	ull operator()(ull x) const {
		static const ull id8 = rnd.next();
		return splitmix64(x + id8);
	}
};

template<class T, class U, class H = splitmix64_hash> using hash_map = __gnu_pbds::gp_hash_table<T, U, H>;
template<class T, class H = splitmix64_hash> using hash_set = hash_map<T, __gnu_pbds::null_type, H>;

} 






namespace felix {

const std::string NONE = "\033[m", RED = "\033[0;32;31m", LIGHT_RED = "\033[1;31m", GREEN = "\033[0;32;32m", LIGHT_GREEN = "\033[1;32m", BLUE = "\033[0;32;34m", LIGHT_BLUE = "\033[1;34m", id9 = "\033[1;30m", CYAN = "\033[0;36m", id4 = "\033[1;36m", PURPLE = "\033[0;35m", id2 = "\033[1;35m", BROWN = "\033[0;33m", YELLOW = "\033[1;33m", LIGHT_GRAY = "\033[0;37m", WHITE = "\033[1;37m";
template<class c> struct rge { c b, e; };
template<class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template<class c> auto dud(c* x)->decltype(std::cerr << *x, 0);
template<class c> char dud(...);
struct debug {

	~debug() { std::cerr << std::endl; }
	template<class c> typename std::enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { std::cerr << std::boolalpha << i; return *this; }
	template<class c> typename std::enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
	template<class c, class b> debug& operator<<(std::pair<b, c> d) { return *this << "(" << d.first << ", " << d.second << ")"; }
	template<class a, class b, class c> debug& operator<<(std::tuple<a, b, c> tp) { return *this << "(" << std::get<0>(tp) << ", " << std::get<1>(tp) << ", " << std::get<2>(tp) << ")"; };
	template<class a, class b, class c, class d> debug& operator<<(std::tuple<a, b, c, d> tp) { return *this << "(" << std::get<0>(tp) << ", " << std::get<1>(tp) << ", " << std::get<2>(tp) << ", " << std::get<3>(tp) << ")"; };
	template<class c> debug& operator<<(rge<c> d) {
		*this << "{";
		for(auto it = d.b; it != d.e; ++it) {
			*this << ", " + 2 * (it == d.b) << *it;
		}
		return *this << "}";
	}

	template<class c> debug& operator<<(const c&) { return *this; }

};


} 


















namespace felix {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}







class barrett {
public:
	unsigned int m;
	unsigned long long im;

	

	explicit barrett(unsigned int _m) : m(_m), im((unsigned long long)(-1) / _m + 1) {}

	

	unsigned int umod() const { return m; }

	

	

	

	unsigned int mul(unsigned int a, unsigned int b) const {
		

		


		

		

		

		

		

		

		

		unsigned long long z = a;
		z *= b;

		unsigned long long x;
		_umul128(z, im, &x);

		unsigned long long x = (unsigned long long)(((unsigned __int128)(z) * im) >> 64);

		unsigned int v = (unsigned int)(z - x * m);
		if(m <= v) {
			v += m;
		}
		return v;
	}
};







unsigned long long id1(unsigned long long n, unsigned long long m, unsigned long long a, unsigned long long b) {
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
		if(y_max < m) {
			break;
		}
		

		

		n = (unsigned long long)(y_max / m);
		b = (unsigned long long)(y_max % m);
		std::swap(m, a);
	}
	return ans;
}

} 


} 



namespace felix {

namespace internal {

class modint_base {};
class static_modint_base : modint_base {};

template<class T> using is_modint = std::is_base_of<modint_base, T>;
template<class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

} 


template<class T> T mod_inv(T, T);

template<int m>
class id11 : internal::static_modint_base {
public:
	static constexpr int mod() {
		return m;
	}
 
	id11() : value(0) {}
 
	template<class T>
	id11(T v) {
		v %= mod();
		if(v < 0) {
			v += mod();
		}
		value = v;
	}
 
	const int& operator()() const {
		return value;
	}
 
	template<class T>
	explicit operator T() const {
		return static_cast<T>(value);
	}
 
	id11& operator+=(const id11& rhs) {
		value += rhs.value;
		if(value >= mod()) {
			value -= mod();
		}
		return *this;
	}
 
	id11& operator-=(const id11& rhs) {
		value -= rhs.value;
		if(value < 0) {
			value += mod();
		}
		return *this;
	}
 
	id11& operator*=(const id11& rhs) {
		value = (long long) value * rhs.value % mod();
		return *this;
	}
 
	id11& operator/=(const id11& rhs) {
		return *this *= mod_inv(rhs.value, mod());
	}
 
	template<class T>
	id11& operator+=(const T& rhs) {
		return *this += id11(rhs);
	}
 
	template<class T>
	id11& operator-=(const T& rhs) {
		return *this -= id11(rhs);
	}
 
	template<class T>
	id11& operator*=(const T& rhs) {
		return *this *= id11(rhs);
	}
 
	template<class T>
	id11& operator/=(const T& rhs) {
		return *this /= id11(rhs);
	}
 
	id11 operator+() const {
		return *this;
	}
 
	id11 operator-() const {
		return id11() - *this;
	}
 
	id11& operator++() {
		return *this += 1;
	}
 
	id11& operator--() {
		return *this -= 1;
	}
 
	id11 operator++(int) {
		id11 res(*this);
		*this += 1;
		return res;
	}
 
	id11 operator--(int) {
		id11 res(*this);
		*this -= 1;
		return res;
	}
 
	id11 operator+(const id11& rhs) {
		return id11(*this) += rhs;
	}
 
	id11 operator-(const id11& rhs) {
		return id11(*this) -= rhs;
	}
 
	id11 operator*(const id11& rhs) {
		return id11(*this) *= rhs;
	}
 
	id11 operator/(const id11& rhs) {
		return id11(*this) /= rhs;
	}
 
	inline bool operator==(const id11& rhs) const {
		return value == rhs();
	}
 
	inline bool operator!=(const id11& rhs) const {
		return !(*this == rhs);
	}
 
private:
	int value;
};
 
template<int m, class T> id11<m> operator+(const T& lhs, const id11<m>& rhs) {
	return id11<m>(lhs) += rhs;
}
 
template<int m, class T> id11<m> operator-(const T& lhs, const id11<m>& rhs) {
	return id11<m>(lhs) -= rhs;
}
 
template<int m, class T> id11<m> operator*(const T& lhs, const id11<m>& rhs) {
	return id11<m>(lhs) *= rhs;
}
 
template<int m, class T> id11<m> operator/(const T& lhs, const id11<m>& rhs) {
	return id11<m>(lhs) /= rhs;
}
 
template<int m>
std::istream& operator>>(std::istream& in, id11<m>& num) {
	long long x;
	in >> x;
	num = id11<m>(x);
	return in;
}
 
template<int m>
std::ostream& operator<<(std::ostream& out, const id11<m>& num) {
	return out << num();
}
 
template<int id>
class id10 : internal::modint_base {
public:
	static int mod() {
		return int(bt.umod());
	}
 
	static void set_mod(int m) {
		assert(1 <= m);
		bt = internal::barrett(m);
	}
 
	id10() : value(0) {}
 
	template<class T>
	id10(T v) {
		v %= mod();
		if(v < 0) {
			v += mod();
		}
		value = v;
	}
 
	const unsigned int& operator()() const {
		return value;
	}
 
	template<class T>
	explicit operator T() const {
		return static_cast<T>(value);
	}
 
	id10& operator+=(const id10& rhs) {
		value += rhs.value;
		if(value >= umod()) {
			value -= umod();
		}
		return *this;
	}

	template<class T>
	id10& operator+=(const T& rhs) {
		return *this += id10(rhs);
	}
 
	id10& operator-=(const id10& rhs) {
		value += mod() - rhs.value;
		if(value >= umod()) {
			value -= umod();
		}
		return *this;
	}

	template<class T>
	id10& operator-=(const T& rhs) {
		return *this -= id10(rhs);
	}

	id10& operator*=(const id10& rhs) {
		value = bt.mul(value, rhs.value);
		return *this;
	}

	template<class T>
	id10& operator*=(const T& rhs) {
		return *this *= id10(rhs);
	}

	id10& operator/=(const id10& rhs) {
		return *this *= mod_inv(int(rhs.value), mod());
	}
 
	template<class T>
	id10& operator/=(const T& rhs) {
		return *this /= id10(rhs);
	}

	id10 operator+() const {
		return *this;
	}

	id10 operator-() const {
		return id10() - *this;
	}

	id10& operator++() {
		++value;
		if(value == umod()) {
			value = 0;
		}
		return *this;
	}
 
	id10& operator--() {
		if(value == 0) {
			value = umod();
		}
		--value;
		return *this;
	}
 
	id10 operator++(int) {
		id10 res(*this);
		++*this;
		return res;
	}
 
	id10 operator--(int) {
		id10 res(*this);
		--*this;
		return res;
	}
 
	id10 operator+(const id10& rhs) {
		return id10(*this) += rhs;
	}
 
	id10 operator-(const id10& rhs) {
		return id10(*this) -= rhs;
	}
 
	id10 operator*(const id10& rhs) {
		return id10(*this) *= rhs;
	}
 
	id10 operator/(const id10& rhs) {
		return id10(*this) /= rhs;
	}
 
	inline bool operator==(const id10& rhs) const {
		return value == rhs();
	}
 
	inline bool operator!=(const id10& rhs) const {
		return !(*this == rhs);
	}
 
private:
	unsigned int value;
	static internal::barrett bt;
	static unsigned int umod() { return bt.umod(); }
};
 
template<int id, class T> id10<id> operator+(const T& lhs, const id10<id>& rhs) {
	return id10<id>(lhs) += rhs;
}
 
template<int id, class T> id10<id> operator-(const T& lhs, const id10<id>& rhs) {
	return id10<id>(lhs) -= rhs;
}
 
template<int id, class T> id10<id> operator*(const T& lhs, const id10<id>& rhs) {
	return id10<id>(lhs) *= rhs;
}
 
template<int id, class T> id10<id> operator/(const T& lhs, const id10<id>& rhs) {
	return id10<id>(lhs) /= rhs;
}
 
template<int id> internal::barrett id10<id>::bt(998244353);
 
template<int id>
std::istream& operator>>(std::istream& in, id10<id>& num) {
	long long x;
	in >> x;
	num = id10<id>(x);
	return in;
}
 
template<int id>
std::ostream& operator<<(std::ostream& out, const id10<id>& num) {
	return out << num();
}
 
using modint998244353 = id11<998244353>;
using modint1000000007 = id11<1000000007>;
 
namespace internal {
 
template <class T>
using is_static_modint = std::is_base_of<static_modint_base, T>;
 
template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
 
template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id10<id>> : public std::true_type {};
 
template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
 
} 

 
} 












namespace felix {

template<class T>
T power(T a, unsigned long long b) {
	assert(b >= 0);
	T ans = 1;
	while(b) {
		if(b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

long long floor_sum(long long n, long long m, long long a, long long b) {
	assert(0 <= n && n < (1LL << 32));
	assert(1 <= m && m < (1LL << 32));
	unsigned long long ans = 0;
	if(a < 0) {
		unsigned long long a2 = internal::safe_mod(a, m);
		ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
		a = a2;
	}
	if(b < 0) {
		unsigned long long b2 = internal::safe_mod(b, m);
		ans -= 1ULL * n * ((b2 - b) / m);
		b = b2;
	}
	return ans + internal::id1(n, m, a, b);
}

} 



namespace felix {



std::tuple<long long, long long, long long> id5(long long x, long long y) {
	if(y == 0) {
		return {1, 0, x};
	}
	std::tuple<long long, long long, long long> result = id5(y, x % y);
	return {std::get<1>(result), std::get<0>(result) - std::get<1>(result) * (x / y), std::get<2>(result)};
}

template<class T>
T mod_inv(T a, T m) {
	T u = 0, v = 1;
	while(a != 0) {
		T t = m / a;
		m -= t * a; std::swap(a, m);
		u -= t * v; std::swap(u, v);
	}
	assert(m == 1);
	return u;
}



std::vector<int> id7(int m, int n = -1) {
	assert(n < m);
	if(n == -1) {
		n = m - 1;
	}
	std::vector<int> inv(n + 1);
	inv[1] = 1;
	for(int i = 2; i <= n; ++i) {
		inv[i] = m - (long long) (m / i) * inv[m % i] % m;
	}
	return inv;
}



long long phi_function(long long n) {
	long long ans = n;
	if(!(n & 1)) {
		do {
			n >>= 1;
		} while(!(n & 1));
		ans /= 2;
	}
	for(long long i = 3; i * i <= n; i += 2) {
		if(n % i == 0) {
			do {
				n /= i;
			} while(n % i == 0);
			ans -= ans / i;
		}
	}
	if(n > 1) {
		ans -= ans / n;
	}
	return ans;
}



std::vector<int> id6(int n) {
	std::vector<int> phi(n + 1);
	std::iota(phi.begin(), phi.end(), 0);
	for(int i = 2; i <= n; ++i) {
		if(phi[i] == i) {
			for(int j = i; j <= n; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}
	return phi;
}



template<class T>
bool is_prime(T n, const std::vector<T>& bases) {
	if(n <= 2) {
		return n == 2;
	}
	std::vector<short> id0 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	for(const T& x : id0) {
		if(n % x == 0) {
			return n == x;
		}
	}
	if(n < 37 * 37) {
		return true;
	}
	int s = __builtin_ctz(n - 1);
	T d = (n - 1) >> s;
	using mint = id10<1283842941>;
	mint::set_mod(n);
	for(const T& a : bases) {
		if(a % n == 0) {
			continue;
		}
		mint cur = a;
		cur = power(cur, d);
		if(int(cur()) == 1) {
			continue;
		}
		bool witness = true;
		for(int rep = 0; rep < s; ++rep) {
			if(int(cur()) == n - 1) {
				witness = false;
				break;
			}
			cur *= cur;
		}
		if(witness) {
			return false;
		}
	}
	return true;
}

bool is_prime(int n) {
	return is_prime(n, {2, 7, 61});
}

bool is_prime(long long n) {
	return is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}



std::vector<bool> id3(int n) {
	const int m = sqrt(n) + 1;
	std::vector<bool> isprime(n + 1, true);
	isprime[0] = isprime[1] = false;
	for(int i = 4; i <= n; i += 2) {
		isprime[i] = false;
	}
	for(int i = 3; i <= m; i += 2) {
		if(isprime[i]) {
			for(int j = i * i; j <= n; j += i << 1) {
				isprime[j] = false;
			}
		}
	}
	return isprime;
}

} 



using namespace std;
using namespace felix;

using mint = modint998244353;

void solve() {
	int n;
	cin >> n;
	n = 1 << n;
	string s;
	cin >> s;
	s = " " + s;
	mint ans = 1;
	auto dfs = [&](auto self, int u) -> string {
		if(u * 2 >= n) {
			return string(1, s[u]);
		}
		string L = self(self, u * 2);
		string R = self(self, u * 2 + 1);
		if(L != R) {
			ans *= 2;
		}
		if(L > R) {
			swap(L, R);
		}
		debug() << show(u) show(string(1, s[u]) + L + R);
		return string(1, s[u]) + L + R;
	};
	dfs(dfs, 1);
	cout << ans << "\n";
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	

	while(tt--) {
		solve();
	}
	return 0;
}
