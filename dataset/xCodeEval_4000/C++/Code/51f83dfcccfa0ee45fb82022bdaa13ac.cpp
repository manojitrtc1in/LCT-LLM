#include <bits/stdc++.h>

#include <set>
#include <array>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

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
template<class T> using oset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<class T> using omset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

struct custom_hash {
	static ull splitmix64(ull x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	ull operator()(ull x) const {
		static const ull FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}

	template <class T, class U>
	ull operator()(const std::pair<T, U>& p) const {
		static const ull FIXED_RANDOM1 = std::chrono::steady_clock::now().time_since_epoch().count();
		static const ull FIXED_RANDOM2 = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(p.first + FIXED_RANDOM1) ^ splitmix64(p.second + FIXED_RANDOM2);
	}

	template <class A, class B, class C>
	ull operator()(const std::tuple<A, B, C>& tp) const {
		static const ull FIXED_RANDOM1 = std::chrono::steady_clock::now().time_since_epoch().count();
		static const ull FIXED_RANDOM2 = std::chrono::steady_clock::now().time_since_epoch().count();
		static const ull FIXED_RANDOM3 = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(std::get<0>(tp) + FIXED_RANDOM1) ^ splitmix64(std::get<1>(tp) + FIXED_RANDOM2) ^ splitmix64(std::get<2>(tp) + FIXED_RANDOM3);
	}

	template <class A, class B, class C, class D>
	ull operator()(const std::tuple<A, B, C, D>& tp) const {
		static const ull FIXED_RANDOM1 = std::chrono::steady_clock::now().time_since_epoch().count();
		static const ull FIXED_RANDOM2 = std::chrono::steady_clock::now().time_since_epoch().count();
		static const ull FIXED_RANDOM3 = std::chrono::steady_clock::now().time_since_epoch().count();
		static const ull FIXED_RANDOM4 = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(std::get<0>(tp) + FIXED_RANDOM1) ^ splitmix64(std::get<1>(tp) + FIXED_RANDOM2) ^ splitmix64(std::get<2>(tp) + FIXED_RANDOM3) ^ splitmix64(std::get<3>(tp) + FIXED_RANDOM4);
	}
};

template<class T> using uset = std::unordered_set<T, custom_hash>;
template<class T, class U> using umap = std::unordered_map<T, U, custom_hash>;

} 



#include <iostream>
#include <cstring>

namespace felix {

const std::string NONE = "\033[m", RED = "\033[0;32;31m", LIGHT_RED = "\033[1;31m", GREEN = "\033[0;32;32m", LIGHT_GREEN = "\033[1;32m", BLUE = "\033[0;32;34m", LIGHT_BLUE = "\033[1;34m", DARK_GRAY = "\033[1;30m", CYAN = "\033[0;36m", LIGHT_CYAN = "\033[1;36m", PURPLE = "\033[0;35m", LIGHT_PURPLE = "\033[1;35m", BROWN = "\033[0;33m", YELLOW = "\033[1;33m", LIGHT_GRAY = "\033[0;37m", WHITE = "\033[1;37m";
template<class c> struct rge { c b, e; };
template<class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template<class c> auto dud(c* x)->decltype(std::cerr << *x, 0);
template<class c> char dud(...);
struct debug {
	#ifdef LOCAL
		~debug() { std::cerr << std::endl; }
		template<class c> typename std::enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { std::cerr << std::boolalpha << i; return *this; }
		template<class c> typename std::enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
		template<class c, class b> debug& operator<<(std::pair<b, c> d) { return *this << "(" << d.first << ", " << d.second << ")"; }
		template<class a, class b, class c> debug& operator<<(std::tuple<a, b, c> tp) { return *this << "(" << std::get<0>(tp) << ", " << std::get<1>(tp) << ", " << std::get<2>(tp) << ")"; };
		template<class a, class b, class c, class d> debug& operator<<(std::tuple<a, b, c, d> tp) { return *this << "(" << std::get<0>(tp) << ", " << std::get<1>(tp) << ", " << std::get<2>(tp) << ", " << std::get<3>(tp) << ")"; };
		template<class c> debug& operator<<(rge<c> d) {
			*this << "{";
			for(auto it = d.b; it != d.e; ++it)
				*this << ", " + 2 * (it == d.b) << *it;
			return *this << "}";
		}
	#else
		template<class c> debug& operator<<(const c&) { return *this; }
	#endif
};
#define show(...) "" << LIGHT_RED << " [" << NONE << #__VA_ARGS__ ": " << (__VA_ARGS__) << LIGHT_RED << "] " << NONE << ""

} 



#include <iostream>
#include <cassert>
#include <type_traits>

namespace felix {

namespace internal {

class modint_base {};
class static_modint_base : modint_base {};

template<class T> using is_modint = std::is_base_of<modint_base, T>;
template<class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

} 


long long mod_inv(long long, long long);

template<int m>
class static_modint : internal::static_modint_base {
public:
	static constexpr int mod() {
		return m;
	}

	static_modint() : value(0) {}

	template<class T>
	static_modint(T v) {
		v %= mod();
		if(v < 0)
			v += mod();
		value = v;
	}

	const int& operator()() const {
		return value;
	}

	template<class T>
	explicit operator T() const {
		return static_cast<T>(value);
	}

	static_modint& operator+=(const static_modint& rhs) {
		value += rhs.value;
		if(value >= mod())
			value -= mod();
		return *this;
	}

	static_modint& operator-=(const static_modint& rhs) {
		value -= rhs.value;
		if(value < 0)
			value += mod();
		return *this;
	}

	static_modint& operator*=(const static_modint& rhs) {
		value = (long long) value * rhs.value % mod();
		return *this;
	}

	static_modint& operator/=(const static_modint& rhs) {
		return *this *= mod_inv(rhs.value, mod());
	}

	template<class T>
	static_modint& operator+=(const T& rhs) {
		return *this += static_modint(rhs);
	}

	template<class T>
	static_modint& operator-=(const T& rhs) {
		return *this -= static_modint(rhs);
	}

	template<class T>
	static_modint& operator*=(const T& rhs) {
		return *this *= static_modint(rhs);
	}

	template<class T>
	static_modint& operator/=(const T& rhs) {
		return *this /= static_modint(rhs);
	}

	static_modint operator+() const {
		return *this;
	}

	static_modint operator-() const {
		return static_modint() - *this;
	}

	static_modint operator+(const static_modint& rhs) {
		return static_modint(*this) += rhs;
	}

	static_modint operator-(const static_modint& rhs) {
		return static_modint(*this) -= rhs;
	}

	static_modint operator*(const static_modint& rhs) {
		return static_modint(*this) *= rhs;
	}

	static_modint operator/(const static_modint& rhs) {
		return static_modint(*this) /= rhs;
	}

	inline bool operator==(const static_modint& rhs) {
		return value == rhs();
	}

	inline bool operator!=(const static_modint& rhs) {
		return !(*this == rhs);
	}

private:
	int value;
};

template<int m, class T> static_modint<m> operator+(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) += rhs;
}

template<int m, class T> static_modint<m> operator-(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) -= rhs;
}

template<int m, class T> static_modint<m> operator*(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) *= rhs;
}

template<int m, class T> static_modint<m> operator/(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) /= rhs;
}

template<int m>
std::istream& operator>>(std::istream& in, static_modint<m>& num) {
	long long x;
	in >> x;
	num = static_modint<m>(x);
	return in;
}

template<int m>
std::ostream& operator<<(std::ostream& out, const static_modint<m>& num) {
	return out << num();
}

template<int id>
class dynamic_modint : internal::modint_base {
public:
	static int mod() {
		return mod_val;
	}

	static void set_mod(const int& m) {
		assert(1 <= m);
		mod_val = m;
	}

	dynamic_modint() : value(0) {}

	template<class T>
	dynamic_modint(T v) {
		v %= mod();
		if(v < 0)
			v += mod();
		value = v;
	}

	const int& operator()() const {
		return value;
	}

	template<class T>
	explicit operator T() const {
		return static_cast<T>(value);
	}

	dynamic_modint& operator+=(const dynamic_modint& rhs) {
		value += rhs.value;
		if(value >= mod())
			value -= mod();
		return *this;
	}

	dynamic_modint& operator-=(const dynamic_modint& rhs) {
		value -= rhs.value;
		if(value < 0)
			value += mod();
		return *this;
	}

	dynamic_modint& operator*=(const dynamic_modint& rhs) {
		value = (long long) value * rhs.value % mod();
		return *this;
	}

	dynamic_modint& operator/=(const dynamic_modint& rhs) {
		return *this *= mod_inv(rhs.value, mod());
	}

	template<class T>
	dynamic_modint& operator+=(const T& rhs) {
		return *this += dynamic_modint(rhs);
	}

	template<class T>
	dynamic_modint& operator-=(const T& rhs) {
		return *this -= dynamic_modint(rhs);
	}

	template<class T>
	dynamic_modint& operator*=(const T& rhs) {
		return *this *= dynamic_modint(rhs);
	}

	template<class T>
	dynamic_modint& operator/=(const T& rhs) {
		return *this /= dynamic_modint(rhs);
	}

	dynamic_modint operator+() const {
		return *this;
	}

	dynamic_modint operator-() const {
		return dynamic_modint() - *this;
	}

	dynamic_modint operator+(const dynamic_modint& rhs) {
		return dynamic_modint(*this) += rhs;
	}

	dynamic_modint operator-(const dynamic_modint& rhs) {
		return dynamic_modint(*this) -= rhs;
	}

	dynamic_modint operator*(const dynamic_modint& rhs) {
		return dynamic_modint(*this) *= rhs;
	}

	dynamic_modint operator/(const dynamic_modint& rhs) {
		return dynamic_modint(*this) /= rhs;
	}

	inline bool operator==(const dynamic_modint& rhs) {
		return value == rhs();
	}

	inline bool operator!=(const dynamic_modint& rhs) {
		return !(*this == rhs);
	}

private:
	int value;
	static int mod_val;
};

template<int id, class T> dynamic_modint<id> operator+(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) += rhs;
}

template<int id, class T> dynamic_modint<id> operator-(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) -= rhs;
}

template<int id, class T> dynamic_modint<id> operator*(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) *= rhs;
}

template<int id, class T> dynamic_modint<id> operator/(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) /= rhs;
}

template<int id> int dynamic_modint<id>::mod_val = 998244353;

template<int id>
std::istream& operator>>(std::istream& in, dynamic_modint<id>& num) {
	long long x;
	in >> x;
	num = dynamic_modint<id>(x);
	return in;
}

template<int id>
std::ostream& operator<<(std::ostream& out, const dynamic_modint<id>& num) {
	return out << num();
}

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

} 


} 



#include <vector>
#include <tuple>
#include <cmath>
#include <numeric>
#include <cassert>

#include <cassert>

namespace felix {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}







unsigned long long floor_sum_unsigned(unsigned long long n, unsigned long long m, unsigned long long a, unsigned long long b) {
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
        if(y_max < m)
        	break;
        

        

        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

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
    if (a < 0) {
        unsigned long long a2 = internal::safe_mod(a, m);
        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
        a = a2;
    }
    if (b < 0) {
        unsigned long long b2 = internal::safe_mod(b, m);
        ans -= 1ULL * n * ((b2 - b) / m);
        b = b2;
    }
    return ans + internal::floor_sum_unsigned(n, m, a, b);
}

} 



namespace felix {



std::tuple<long long, long long, long long> ext_gcd(long long x, long long y) {
	if(y == 0)
		return {1, 0, x};
	std::tuple<long long, long long, long long> result = ext_gcd(y, x % y);
	return {std::get<1>(result), std::get<0>(result) - std::get<1>(result) * (x / y), std::get<2>(result)};
}

long long mod_inv(long long d, long long m) {
	return std::get<0>(ext_gcd(d, m));
}



std::vector<int> mod_inv_in_range(int m, int n = -1) {
	assert(n < m);
	if(n == -1)
		n = m - 1;
	std::vector<int> inv(n + 1);
	inv[1] = 1;
	for(int i = 2; i <= n; ++i)
		inv[i] = m - (m / i) * inv[m % i] % m;
	return inv;
}



long long phi_function(long long n) {
	long long ans = n;
	if(!(n & 1)) {
		do
			n >>= 1;
		while(!(n & 1));
		ans /= 2;
	}
	for(long long i = 3; i * i <= n; i += 2) {
		if(n % i == 0) {
			do
				n /= i;
			while(n % i == 0);
			ans -= ans / i;
		}
	}
	if(n > 1)
		ans -= ans / n;
	return ans;
}



std::vector<int> phi_sieve(int n) {
	std::vector<int> phi(n + 1);
	std::iota(phi.begin(), phi.end(), 0);
	for(int i = 2; i <= n; ++i)
		if(phi[i] == i)
			for(int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
	return phi;
}



template<class T>
bool is_prime(T n, const std::vector<T>& bases) {
	if(n <= 2)
		return n == 2;
	std::vector<short> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	for(const T& x : small_primes)
		if(n % x == 0)
			return n == x;
	if(n < 37 * 37)
		return true;
	int s = __builtin_ctz(n - 1);
	T d = (n - 1) >> s;
	dynamic_modint<1283842941>::set_mod(n);
	for(const T& a : bases) {
		if(a % n == 0)
			continue;
		dynamic_modint<1283842941> cur = a;
		cur = power(cur, d);
		if(cur() == 1)
			continue;
		bool witness = true;
		for(int rep = 0; rep < s; ++rep) {
			if(cur() == n - 1) {
				witness = false;
				break;
			}
			cur *= cur;
		}
		if(witness)
			return false;
	}
	return true;
}

bool is_prime(int n) {
	return is_prime(n, {2, 7, 61});
}

bool is_prime(long long n) {
	return is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}



std::vector<bool> prime_sieve(int n) {
	const int m = sqrt(n) + 1;
	std::vector<bool> isprime(n + 1, true);
	isprime[0] = isprime[1] = false;
	for(int i = 4; i <= n; i += 2)
		isprime[i] = false;
	for(int i = 3; i <= m; i += 2)
		if(isprime[i])
			for(int j = i * i; j <= n; j += i << 1)
				isprime[j] = false;
	return isprime;
}

} 




#include <vector>

namespace felix {

template<class T>
class combination {
public:
	static const bool need_inv = !std::is_integral<T>::value;
	std::vector<T> fact, inv_fact;

	combination() : combination(0) {}

	combination(int n) {
		assert(n >= 0);
		fact.reserve(n + 1);
		fact.push_back(1);
		if(need_inv) {
			inv_fact.reserve(n + 1);
			inv_fact.push_back(1);
		}
		update(n);
	}

	inline void update(int n) {
		while(int(fact.size()) <= n) {
			fact.push_back(fact.back() * int(fact.size()));
			if(need_inv)
				inv_fact.push_back(1 / fact.back());
		}
	}

	inline T C(int n, int k) {
		assert(n >= 0);
		if(k < 0 || k > n)
			return 0;
		update(n);
		if(need_inv)
			return fact[n] * inv_fact[k] * inv_fact[n - k];
		return fact[n] / fact[k] / fact[n - k];
	}

	inline T P(int n, int k) {
		assert(n >= 0);
		if(k < 0 || k > n)
			return 0;
		update(n);
		if(need_inv)
			return fact[n] * inv_fact[n - k];
		return fact[n] / fact[n - k];
	}

	inline int size() const {
		return int(fact.size());
	}
};

} 


using namespace std;
using namespace felix;

#define fastio ios::sync_with_stdio(false), cin.tie(NULL)

using mint = modint998244353;

int main() {
	fastio;
	int n, k;
	string s;
	cin >> n >> k >> s;
	combination<mint> C(n + 5);
	vt<int> pos;
	for(int i = 0; i < n; ++i)
		if(s[i] == '1')
			pos.push_back(i);
	const int m = int(pos.size());
	if(m < k || k == 0) {
		cout << "1\n";
		return 0;
	}
	if(m == k) {
		cout << C.C(n, k) << "\n";
		return 0;
	}
	int len = pos[k], zero = 0;
	mint ans = C.C(len, k);
	for(int i = pos[k], j = -1; i < n; ++i) {
		if(s[i] == '1') {
			len = i - pos[++j];
			zero = len - k;
			if(zero > 0)
				ans += C.C(len - 1, zero - 1);
		} else {
			len = i - pos[j];
			zero = len - k;
			ans += C.C(len - 1, k - 1);
		}
	}
	cout << ans << "\n";
	return 0;
}
