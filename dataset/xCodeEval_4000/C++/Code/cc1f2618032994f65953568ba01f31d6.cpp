#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1
#ifdef _MSC_VER
#include <intrin.h>
#include<cassert>
#endif
namespace atcoder {
	namespace internal {
		int ceil_pow2(int n) {
			int x = 0;
			while ((1U << x) < (unsigned int)(n)) x++;
			return x;
		}
		int bsf(unsigned int n) {
#ifdef _MSC_VER
			unsigned long index;
			_BitScanForward(&index, n);
			return index;
#else
			return __builtin_ctz(n);
#endif
		}
	}
}
#endif
#ifndef ATCODER_INTERNAL_MATH_HPP
#define ATCODER_INTERNAL_MATH_HPP 1
#include <utility>
namespace atcoder {
	namespace internal {
		constexpr long long safe_mod(long long x, long long m) {
			x %= m;
			if (x < 0) x += m;
			return x;
		}
		struct barrett {
			unsigned int _m;
			unsigned long long im;
			barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
			unsigned int umod() const { return _m; }
			unsigned int mul(unsigned int a, unsigned int b) const {
				unsigned long long z = a;
				z *= b;
#ifdef _MSC_VER
				unsigned long long x;
				_umul128(z, im, &x);
#else
				unsigned long long x =
					(unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
				unsigned int v = (unsigned int)(z - x * _m);
				if (_m <= v) v += _m;
				return v;
			}
		};
		constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
			if (m == 1) return 0;
			unsigned int _m = (unsigned int)(m);
			unsigned long long r = 1;
			unsigned long long y = safe_mod(x, m);
			while (n) {
				if (n & 1) r = (r * y) % _m;
				y = (y * y) % _m;
				n >>= 1;
			}
			return r;
		}
		constexpr bool is_prime_constexpr(int n) {
			if (n <= 1) return false;
			if (n == 2 || n == 7 || n == 61) return true;
			if (n % 2 == 0) return false;
			long long d = n - 1;
			while (d % 2 == 0) d /= 2;
			int v[] = { 2,7,61 };
			for (long long a : v) {
				long long t = d;
				long long y = pow_mod_constexpr(a, t, n);
				while (t != n - 1 && y != 1 && y != n - 1) {
					y = y * y % n;
					t <<= 1;
				}
				if (y != n - 1 && t % 2 == 0) {
					return false;
				}
			}
			return true;
		}
		template <int n> constexpr bool is_prime = is_prime_constexpr(n);
		constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
			a = safe_mod(a, b);
			if (a == 0) return { b, 0 };
			long long s = b, t = a;
			long long m0 = 0, m1 = 1;
			while (t) {
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
			if (m0 < 0) m0 += b / s;
			return { s, m0 };
		}
		constexpr int primitive_root_constexpr(int m) {
			if (m == 2) return 1;
			if (m == 167772161) return 3;
			if (m == 469762049) return 3;
			if (m == 754974721) return 11;
			if (m == 998244353) return 3;
			int divs[20] = {};
			divs[0] = 2;
			int cnt = 1;
			int x = (m - 1) / 2;
			while (x % 2 == 0) x /= 2;
			for (int i = 3; (long long)(i)*i <= x; i += 2) {
				if (x % i == 0) {
					divs[cnt++] = i;
					while (x % i == 0) {
						x /= i;
					}
				}
			}
			if (x > 1) {
				divs[cnt++] = x;
			}
			for (int g = 2;; g++) {
				bool ok = true;
				for (int i = 0; i < cnt; i++) {
					if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
						ok = false;
						break;
					}
				}
				if (ok) return g;
			}
		}
		template <int m> constexpr int primitive_root = primitive_root_constexpr(m);
	}
}
#endif 
#ifndef ATCODER_INTERNAL_TYPE_TRAITS_HPP
#define ATCODER_INTERNAL_TYPE_TRAITS_HPP 1
#include <cassert>
#include <numeric>
#include <type_traits>
namespace atcoder {
	namespace internal {
#ifndef _MSC_VER
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
		using is_signed_int = typename std::conditional<(is_integral<T>::value&&
			std::is_signed<T>::value) ||
			is_signed_int128<T>::value,
			std::true_type,
			std::false_type>::type;
		template <class T>
		using is_unsigned_int =
			typename std::conditional<(is_integral<T>::value&&
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
#else
		template <class T> using is_integral = typename std::is_integral<T>;
		template <class T>
		using is_signed_int =
			typename std::conditional<is_integral<T>::value&& std::is_signed<T>::value,
			std::true_type,
			std::false_type>::type;
		template <class T>
		using is_unsigned_int =
			typename std::conditional<is_integral<T>::value&&
			std::is_unsigned<T>::value,
			std::true_type,
			std::false_type>::type;
		template <class T>
		using to_unsigned = typename std::conditional<is_signed_int<T>::value,
			std::make_unsigned<T>,
			std::common_type<T>>::type;
#endif
		template <class T>
		using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
		template <class T>
		using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
		template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
	}
}
#endif 
#ifndef ATCODER_MODINT_HPP
#define ATCODER_MODINT_HPP 1
#include <cassert>
#include <numeric>
#include <type_traits>
#ifdef _MSC_VER
#include <intrin.h>
#endif
namespace atcoder {
	namespace internal {
		struct modint_base {};
		struct static_modint_base : modint_base {};
		template <class T> using is_modint = std::is_base_of<modint_base, T>;
		template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
	}
	template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
	struct static_modint : internal::static_modint_base {
		using mint = static_modint;
	public:
		static constexpr int mod() { return m; }
		static mint raw(int v) {
			mint x;
			x._v = v;
			return x;
		}
		static_modint() : _v(0) {}
		template <class T, internal::is_signed_int_t<T>* = nullptr>
		static_modint(T v) {
			long long x = (long long)(v % (long long)(umod()));
			if (x < 0) x += umod();
			_v = (unsigned int)(x);
		}
		template <class T, internal::is_unsigned_int_t<T>* = nullptr>
		static_modint(T v) {
			_v = (unsigned int)(v % umod());
		}
		static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }
		unsigned int val() const { return _v; }
		mint& operator++() {
			_v++;
			if (_v == umod()) _v = 0;
			return *this;
		}
		mint& operator--() {
			if (_v == 0) _v = umod();
			_v--;
			return *this;
		}
		mint operator++(int) {
			mint result = *this;
			++* this;
			return result;
		}
		mint operator--(int) {
			mint result = *this;
			--* this;
			return result;
		}
		mint& operator+=(const mint& rhs) {
			_v += rhs._v;
			if (_v >= umod()) _v -= umod();
			return *this;
		}
		mint& operator-=(const mint& rhs) {
			_v -= rhs._v;
			if (_v >= umod()) _v += umod();
			return *this;
		}
		mint& operator*=(const mint& rhs) {
			unsigned long long z = _v;
			z *= rhs._v;
			_v = (unsigned int)(z % umod());
			return *this;
		}
		mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
		mint operator+() const { return *this; }
		mint operator-() const { return mint() - *this; }
		mint pow(long long n) const {
			assert(0 <= n);
			mint x = *this, r = 1;
			while (n) {
				if (n & 1) r *= x;
				x *= x;
				n >>= 1;
			}
			return r;
		}
		mint inv() const {
			if (prime) {
				assert(_v);
				return pow(umod() - 2);
			}
			else {
				auto eg = internal::inv_gcd(_v, m);
				assert(eg.first == 1);
				return eg.second;
			}
		}
		friend mint operator+(const mint& lhs, const mint& rhs) {
			return mint(lhs) += rhs;
		}
		friend mint operator-(const mint& lhs, const mint& rhs) {
			return mint(lhs) -= rhs;
		}
		friend mint operator*(const mint& lhs, const mint& rhs) {
			return mint(lhs) *= rhs;
		}
		friend mint operator/(const mint& lhs, const mint& rhs) {
			return mint(lhs) /= rhs;
		}
		friend bool operator==(const mint& lhs, const mint& rhs) {
			return lhs._v == rhs._v;
		}
		friend bool operator!=(const mint& lhs, const mint& rhs) {
			return lhs._v != rhs._v;
		}
	private:
		unsigned int _v;
		static constexpr unsigned int umod() { return m; }
		static constexpr bool prime = internal::is_prime<m>;
	};
	template <int id> struct dynamic_modint : internal::modint_base {
		using mint = dynamic_modint;
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
		dynamic_modint() : _v(0) {}
		template <class T, internal::is_signed_int_t<T>* = nullptr>
		dynamic_modint(T v) {
			long long x = (long long)(v % (long long)(mod()));
			if (x < 0) x += mod();
			_v = (unsigned int)(x);
		}
		template <class T, internal::is_unsigned_int_t<T>* = nullptr>
		dynamic_modint(T v) {
			_v = (unsigned int)(v % mod());
		}
		dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }
		unsigned int val() const { return _v; }
		mint& operator++() {
			_v++;
			if (_v == umod()) _v = 0;
			return *this;
		}
		mint& operator--() {
			if (_v == 0) _v = umod();
			_v--;
			return *this;
		}
		mint operator++(int) {
			mint result = *this;
			++* this;
			return result;
		}
		mint operator--(int) {
			mint result = *this;
			--* this;
			return result;
		}
		mint& operator+=(const mint& rhs) {
			_v += rhs._v;
			if (_v >= umod()) _v -= umod();
			return *this;
		}
		mint& operator-=(const mint& rhs) {
			_v += mod() - rhs._v;
			if (_v >= umod()) _v -= umod();
			return *this;
		}
		mint& operator*=(const mint& rhs) {
			_v = bt.mul(_v, rhs._v);
			return *this;
		}
		mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
		mint operator+() const { return *this; }
		mint operator-() const { return mint() - *this; }
		mint pow(long long n) const {
			assert(0 <= n);
			mint x = *this, r = 1;
			while (n) {
				if (n & 1) r *= x;
				x *= x;
				n >>= 1;
			}
			return r;
		}
		mint inv() const {
			auto eg = internal::inv_gcd(_v, mod());
			assert(eg.first == 1);
			return eg.second;
		}
		friend mint operator+(const mint& lhs, const mint& rhs) {
			return mint(lhs) += rhs;
		}
		friend mint operator-(const mint& lhs, const mint& rhs) {
			return mint(lhs) -= rhs;
		}
		friend mint operator*(const mint& lhs, const mint& rhs) {
			return mint(lhs) *= rhs;
		}
		friend mint operator/(const mint& lhs, const mint& rhs) {
			return mint(lhs) /= rhs;
		}
		friend bool operator==(const mint& lhs, const mint& rhs) {
			return lhs._v == rhs._v;
		}
		friend bool operator!=(const mint& lhs, const mint& rhs) {
			return lhs._v != rhs._v;
		}
	private:
		unsigned int _v;
		static internal::barrett bt;
		static unsigned int umod() { return bt.umod(); }
	};
	template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;
	using modint998244353 = static_modint<998244353>;
	using modint1000000007 = static_modint<1000000007>;
	using modint = dynamic_modint<-1>;
	namespace internal {
		template <class T>
		using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
		template <class T>
		using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
		template <class> struct is_dynamic_modint : public std::false_type {};
		template <int id>
		struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};
		template <class T>
		using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
	}
}
#endif
#ifndef ATCODER_MATH_HPP
#define ATCODER_MATH_HPP 1
#include <algorithm>
#include <cassert>
#include <tuple>
#include <vector>
namespace atcoder {
	long long pow_mod(long long x, long long n, int m) {
		assert(0 <= n && 1 <= m);
		if (m == 1) return 0;
		internal::barrett bt((unsigned int)(m));
		unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));
		while (n) {
			if (n & 1) r = bt.mul(r, y);
			y = bt.mul(y, y);
			n >>= 1;
		}
		return r;
	}
	long long inv_mod(long long x, long long m) {
		assert(1 <= m);
		auto z = internal::inv_gcd(x, m);
		assert(z.first == 1);
		return z.second;
	}
	std::pair<long long, long long> crt(const std::vector<long long>& r,
		const std::vector<long long>& m) {
		assert(r.size() == m.size());
		int n = int(r.size());
		long long r0 = 0, m0 = 1;
		for (int i = 0; i < n; i++) {
			assert(1 <= m[i]);
			long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
			if (m0 < m1) {
				std::swap(r0, r1);
				std::swap(m0, m1);
			}
			if (m0 % m1 == 0) {
				if (r0 % m1 != r1) return { 0, 0 };
				continue;
			}
			long long g, im;
			std::tie(g, im) = internal::inv_gcd(m0, m1);
			long long u1 = (m1 / g);
			if ((r1 - r0) % g) return { 0, 0 };
			long long x = (r1 - r0) / g % u1 * im % u1;
			r0 += x * m0;
			m0 *= u1;
			if (r0 < 0) r0 += m0;
		}
		return { r0, m0 };
	}
	long long floor_sum(long long n, long long m, long long a, long long b) {
		long long ans = 0;
		if (a >= m) {
			ans += (n - 1) * n * (a / m) / 2;
			a %= m;
		}
		if (b >= m) {
			ans += n * (b / m);
			b %= m;
		}
		long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
		if (y_max == 0) return ans;
		ans += (n - (x_max + a - 1) / a) * y_max;
		ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
		return ans;
	}
}
#endif
#include <bits/stdc++.h>


using namespace std;
using namespace atcoder;




using mint = modint998244353;
const int mod = 998244353;




#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i,l,r)for(int i=(l);i<(r);++i)
#define rrep(i, n) for (int i = (n-1); i >= 0; --i)
#define rrep2(i,l,r)for(int i=(r-1);i>=(l);--i)
#define all(x) (x).begin(),(x).end()
#define allR(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define P pair<int,int>
template<typename A, typename B> inline bool chmax(A & a, const B & b) { if (a < b) { a = b; return true; } return false; }
template<typename A, typename B> inline bool chmin(A & a, const B & b) { if (a > b) { a = b; return true; } return false; }
pair<mint, pair<int, int>> dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;
	rep2(i, 1, n + 1) {
		rep(l, n) {
			

			int r = l + i;
			if (r > n)continue;
			if (1 == i) {
				char c = s[l];
				if ('?' == c) dp[l][r] = { 1,{1,0} };
				else dp[l][r] = { 1,{0,0} };
				continue;
			}
			if (2 == i) {
				char cl = s[l];
				char cr = s[r - 1];
				if (('?' == cl) && ('?' == cr))dp[l][r] = { 1,{1,0} };
				else if ('?' == cl) dp[l][r] = { 1,{0,(1 << (cr - 'a')) } };
				else if ('?' == cr) dp[l][r] = { 1,{0,(1 << (cl - 'a')) } };
				else if (cr == cl) dp[l][r] = { 1,{0,0} };
				else dp[l][r] = { 0,{0,0} };
				continue;
			}
			auto old = dp[l + 1][r - 1];
			mint m = old.first;
			int pw = old.second.first;
			int bit = old.second.second;
			char cl = s[l];
			char cr = s[r - 1];
			if (('?' == cl) && ('?' == cr)) dp[l][r] = { m,{pw + 1,bit} };
			else if ('?' == cl) dp[l][r] = { m,{pw,bit | (1 << (cr - 'a')) } };
			else if ('?' == cr) dp[l][r] = { m,{pw,bit | (1 << (cl - 'a')) } };
			else if (cr == cl) dp[l][r] = { old };
			else dp[l][r] = { 0,{0,0} };
		}
	}
	vector<int>c(s.size() + 1, 0);
	rep(i, c.size()) {
		c[i + 1] = c[i];
		if ('?' == s[i])c[i + 1]++;
	}
	

	vector<vector<mint>> ans(1 << 17, vector<mint>(17 + 1));
	rep(i, n) {
		rep2(j, i + 1, n + 1) {
			auto get = dp[i][j];
			mint m = get.first;
			int pw = get.second.first;
			pw += c[i] - c[0];
			pw += c[n] - c[j];
			int bit = get.second.second;
			rep(k, 17 + 1) {
				ans[bit][k] += m * pow_mod(k, pw, mod);
			}
		}
	}
	

	rep(k, 17 + 1) {
		rep(j, 17) {
			rrep(i, (1 << 17)) {
				if (1 & (i >> j))ans[i][k] += ans[i & ~(1 << j)][k];
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		int bit = 0;
		rep(i, s.size())bit += 1 << (s[i] - 'a');
		int sz = s.size();
		cout << ans[bit][sz].val() << endl;
	}
	return 0;
}