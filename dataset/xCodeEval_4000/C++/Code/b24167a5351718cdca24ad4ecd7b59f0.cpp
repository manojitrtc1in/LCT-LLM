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
#include <cstring>
#include <cassert>

#include <vector>
#include <tuple>
#include <cmath>
#include <numeric>
#include <cassert>

namespace felix {



std::tuple<long long, long long, long long> ext_gcd(long long x, long long y) {
	if(y == 0)
		return {1, 0, x};
	std::tuple<long long, long long, long long> result = ext_gcd(y, x % y);
	return {std::get<1>(result), std::get<0>(result) - std::get<1>(result) * (x / y), std::get<2>(result)};
}



bool is_prime(long long x) {
	if(x & 1) {
		for(long long i = 3; i * i <= x; i += 2)
			if(x % i == 0)
				return false;
		return true;
	} else
		return x == 2;
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

inline long long mod_inv(long long d, long long m) {
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

} 



namespace felix {
























template<int MD>
class static_modint {
public:
	static_assert(MD > 0, "MOD must be positive");

	static constexpr int MOD = MD;

	static_modint() : value(0) {}

	template<class T>
	static_modint(const T& x) {
		value = normalize(x);
	}

	template<class T>
	inline int normalize(T x) {
		if(-MOD > x || x >= MOD)
			x %= MOD;
		if(x < 0)
			x += MOD;
		return x;
	}

	inline const int& operator()() const { return value; }
	template<class T> inline explicit operator T() const { return static_cast<T>(value); }

	inline static_modint& operator+=(const static_modint& other) { if((value += other.value) >= MOD) value -= MOD; return *this; }
	inline static_modint& operator-=(const static_modint& other) { if((value -= other.value) < 0) value += MOD; return *this; }
	inline static_modint& operator*=(const static_modint& other) { value = normalize(static_cast<long long>(value) * other.value); return *this; }
	inline static_modint& operator/=(const static_modint& other) { return *this *= felix::mod_inv(other(), MOD); }
	

	template<class T> inline static_modint& operator+=(const T& other) { return *this += static_modint(other); }
	template<class T> inline static_modint& operator-=(const T& other) { return *this -= static_modint(other); }
	template<class T> inline static_modint& operator*=(const T& other) { return *this *= static_modint(other); }
	template<class T> inline static_modint& operator/=(const T& other) { return *this /= static_modint(other); }
	inline static_modint& operator++() { return *this += 1; }
	inline static_modint& operator--() { return *this -= 1; }
	inline static_modint operator++(int) { static_modint result(*this); *this += 1; return result; }
	inline static_modint operator--(int) { static_modint result(*this); *this -= 1; return result; }
	inline static_modint operator-() const { return static_modint(-value); }

	template<int T> friend inline bool operator==(const static_modint<T>& lhs, const static_modint<T>& rhs);
	template<int T> friend inline bool operator!=(const static_modint<T>& lhs, const static_modint<T>& rhs);
	template<int T> friend inline bool operator<(const static_modint<T>& lhs, const static_modint<T>& rhs);
	template<int T> friend inline bool operator>(const static_modint<T>& lhs, const static_modint<T>& rhs);
	template<int T> friend inline bool operator<=(const static_modint<T>& lhs, const static_modint<T>& rhs);
	template<int T> friend inline bool operator>=(const static_modint<T>& lhs, const static_modint<T>& rhs);

	template<class U, int T> friend U& operator>>(U& in, static_modint<T>& x);

private:
	int value;
};

template<int MOD> inline bool operator==(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return lhs.value == rhs.value; }
template<int MOD, class T> inline bool operator==(const static_modint<MOD>& lhs, T rhs) { return lhs.value == static_modint<MOD>(rhs); }
template<int MOD, class T> inline bool operator==(const T lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) == rhs; }

template<int MOD> inline bool operator!=(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return !(lhs == rhs); }
template<int MOD, class T> inline bool operator!=(const static_modint<MOD>& lhs, T rhs) { return !(lhs == rhs); }
template<int MOD, class T> inline bool operator!=(const T lhs, const static_modint<MOD>& rhs) { return !(lhs == rhs); }

template<int MOD> inline bool operator<(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return lhs.value < rhs.value; }
template<int MOD> inline bool operator<=(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return lhs.value <= rhs.value; }
template<int MOD> inline bool operator>(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return lhs.value > rhs.value; }
template<int MOD> inline bool operator>=(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return lhs.value >= rhs.value; }

template<int MOD> static_modint<MOD> inline operator+(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) += rhs; }
template<int MOD, class T> static_modint<MOD> inline operator+(const static_modint<MOD>& lhs, T rhs) { return static_modint<MOD>(lhs) += rhs; }
template<int MOD, class T> static_modint<MOD> inline operator+(T lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) += rhs; }

template<int MOD> static_modint<MOD> inline operator-(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) -= rhs; }
template<int MOD, class T> static_modint<MOD> inline operator-(const static_modint<MOD>& lhs, T rhs) { return static_modint<MOD>(lhs) -= rhs; }
template<int MOD, class T> static_modint<MOD> inline operator-(T lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) -= rhs; }

template<int MOD> static_modint<MOD> inline operator*(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) *= rhs; }
template<int MOD, class T> static_modint<MOD> inline operator*(const static_modint<MOD>& lhs, T rhs) { return static_modint<MOD>(lhs) *= rhs; }
template<int MOD, class T> static_modint<MOD> inline operator*(T lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) *= rhs; }

template<int MOD> static_modint<MOD> inline operator/(const static_modint<MOD>& lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) /= rhs; }
template<int MOD, class T> static_modint<MOD> inline operator/(const static_modint<MOD>& lhs, T rhs) { return static_modint<MOD>(lhs) /= rhs; }
template<int MOD, class T> static_modint<MOD> inline operator/(T lhs, const static_modint<MOD>& rhs) { return static_modint<MOD>(lhs) /= rhs; }

template<int MOD> inline std::string to_string(const static_modint<MOD>& x) { return to_string(x()); }

template<int MOD, class T> inline static_modint<MOD> power(static_modint<MOD> a, T b) { assert(b >= 0); static_modint<MOD> ans = 1; while(b) { if(b & 1) ans *= a; a *= a; b >>= 1; } return ans; }

template<class T, int MOD> inline T& operator>>(T& in, static_modint<MOD>& x) { long long temp; in >> temp; x.value = x.normalize(temp); return in; }

template<class T, int MOD> inline T& operator<<(T& out, const static_modint<MOD>& x) { return out << x(); }

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

const int mod = 998244353;
using mint = static_modint<mod>;

int main() {
	fastio;
	int n, k;
	string s;
	cin >> n >> k >> s;
	vt<int> ones(n);
	ones[0] = s[0] - '0';
	for(int i = 1; i < n; ++i)
		ones[i] = ones[i - 1] + s[i] - '0';
	if(ones.back() < k) {
		cout << "1\n";
		return 0;
	}
	auto get = [&](int l, int r) -> int {
		if(r < l)
			return 0;
		return ones[r] - (l == 0 ? 0 : ones[l - 1]);
	};
	vt<vt<mint>> C(n + 1);
	for(int i = 0; i < n; ++i) {
		C[i].resize(i + 1);
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	mint ans = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(get(i, j) <= k) {
				int cnt = j - i - 1;
				int one = get(i, j);
				if(s[i] == '0')
					--one;
				if(s[j] == '0')
					--one;
				if(one <= cnt && one >= 0 && cnt >= 0)
					ans += C[cnt][one];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
