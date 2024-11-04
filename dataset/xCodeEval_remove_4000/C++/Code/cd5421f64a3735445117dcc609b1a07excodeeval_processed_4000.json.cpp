





namespace atcoder {
	namespace internal {
		int id5(int n) {
			int x = 0;
			while ((1U << x) < (unsigned int)(n)) x++;
			return x;
		}
		int bsf(unsigned int n) {

			unsigned long index;
			_BitScanForward(&index, n);
			return index;

			return __builtin_ctz(n);

		}
	}
}




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

				unsigned long long x;
				_umul128(z, im, &x);

				unsigned long long x =
					(unsigned long long)(((unsigned __int128)(z)*im) >> 64);

				unsigned int v = (unsigned int)(z - x * _m);
				if (_m <= v) v += _m;
				return v;
			}
		};
		constexpr long long id6(long long x, long long n, int m) {
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
		constexpr bool id2(int n) {
			if (n <= 1) return false;
			if (n == 2 || n == 7 || n == 61) return true;
			if (n % 2 == 0) return false;
			long long d = n - 1;
			while (d % 2 == 0) d /= 2;
			int v[] = { 2,7,61 };
			for (long long a : v) {
				long long t = d;
				long long y = id6(a, t, n);
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
		template <int n> constexpr bool is_prime = id2(n);
		constexpr std::pair<long long, long long> id3(long long a, long long b) {
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
		constexpr int id4(int m) {
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
					if (id6(g, (m - 1) / divs[i], m) == 1) {
						ok = false;
						break;
					}
				}
				if (ok) return g;
			}
		}
		template <int m> constexpr int primitive_root = id4(m);
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

		template <class T>
		using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
		template <class T>
		using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
		template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
	}
}









namespace atcoder {
	namespace internal {
		struct modint_base {};
		struct static_modint_base : modint_base {};
		template <class T> using is_modint = std::is_base_of<modint_base, T>;
		template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
	}
	template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
	struct id0 : internal::static_modint_base {
		using mint = id0;
	public:
		static constexpr int mod() { return m; }
		static mint raw(int v) {
			mint x;
			x._v = v;
			return x;
		}
		id0() : _v(0) {}
		template <class T, internal::is_signed_int_t<T>* = nullptr>
		id0(T v) {
			long long x = (long long)(v % (long long)(umod()));
			if (x < 0) x += umod();
			_v = (unsigned int)(x);
		}
		template <class T, internal::is_unsigned_int_t<T>* = nullptr>
		id0(T v) {
			_v = (unsigned int)(v % umod());
		}
		id0(bool v) { _v = ((unsigned int)(v) % umod()); }
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
				auto eg = internal::id3(_v, m);
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
	template <int id> struct id7 : internal::modint_base {
		using mint = id7;
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
		id7() : _v(0) {}
		template <class T, internal::is_signed_int_t<T>* = nullptr>
		id7(T v) {
			long long x = (long long)(v % (long long)(mod()));
			if (x < 0) x += mod();
			_v = (unsigned int)(x);
		}
		template <class T, internal::is_unsigned_int_t<T>* = nullptr>
		id7(T v) {
			_v = (unsigned int)(v % mod());
		}
		id7(bool v) { _v = ((unsigned int)(v) % mod()); }
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
			auto eg = internal::id3(_v, mod());
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
	template <int id> internal::barrett id7<id>::bt = 998244353;
	using modint998244353 = id0<998244353>;
	using modint1000000007 = id0<1000000007>;
	using modint = id7<-1>;
	namespace internal {
		template <class T>
		using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
		template <class T>
		using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
		template <class> struct is_dynamic_modint : public std::false_type {};
		template <int id>
		struct is_dynamic_modint<id7<id>> : public std::true_type {};
		template <class T>
		using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
	}
}







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
		auto z = internal::id3(x, m);
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
			std::tie(g, im) = internal::id3(m0, m1);
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




using namespace std;
using namespace atcoder;








using mint = atcoder::modint;
const int INF = 1e9;












template<typename A, typename B> inline bool chmax(A & a, const B & b) { if (a < b) { a = b; return true; } return false; }
template<typename A, typename B> inline bool chmin(A & a, const B & b) { if (a > b) { a = b; return true; } return false; }
struct id1 {
	id1(vector<vector<mint>>_a, vector<mint>_b, long long _mod) :mod(_mod), a(_a), b(_b) {}
	id1(long long _mod) :mod(_mod) {}
	void init() {
		n = a.size();
		m = a[0].size();
		x.resize(m);
	}
	void solve() {
		init();
		result = true;
		vector<int>used(n, -1);
		rep(i, m) {
			rep(j, n) {
				if (-1 != used[j])continue;
				if (0 == a[j][i].val()) continue;
				rep(k, n) {
					if (j == k)continue;
					if (0 == a[k][i].val())continue;
					mint x = a[k][i] / a[j][i];
					rep(l, m) a[k][l] -= x * a[j][l];
					b[k] -= x * b[j];
				}
				used[j] = i;
				break;
			}
		}
		rep(i, n) {
			if (-1 == used[i])continue;
			mint inv = inv_mod(a[i][used[i]].val(), mod);
			x[used[i]] = inv * b[i];
		}
		rep(i, n) {
			bool chk = true;
			rep(j, m) if (0 != a[i][j].val())chk = false;
			if (chk && (0 != b[i].val())) result = false;
		}
	}
	long long mod;
	vector<vector<mint>>a;
	vector<mint>x;
	vector<mint>b;
	bool result;
	int n, m;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	mint::set_mod(3);
	while (t--) {
		int n, m; cin >> n >> m;
		vector<vector<P>> data(n, vector<P>(n, { INF,INF }));

		vector<int>ans(m);
		rep(i, m) {
			int a, b, c; cin >> a >> b >> c;
			a--; b--;
			if (a > b)swap(a, b);
			data[a][b] = { c,i };
			ans[i] = c;
		}
		vector<vector<mint>>a;
		vector<mint>b;
		rep(i, n)rep2(j, i + 1, n)rep2(k, j + 1, n) {
			vector<P>vp = { {i,j},{i,k},{j,k} };
			bool chk = true;
			vector<mint>v(m, 0);
			mint val = 0;
			rep(l, 3) {
				int x = vp[l].first;
				int y = vp[l].second;
				if (INF == data[x][y].first) {
					chk = false;
					break;
				}
				else {
					P p = data[x][y];
					if (-1 != p.first) val -= p.first;
					else v[p.second] = 1;
				}
			}
			if (!chk) continue;
			a.push_back(v);
			b.push_back(val);
		}
		if (0 == a.size()) {
			rep(i, m) if (-1 == ans[i])ans[i] = 1;
			rep(i, m) cout << ans[i] << " ";
			cout << endl;
			continue;
		};
		id1 gs(3);
		swap(gs.a, a);
		swap(gs.b, b);
		gs.solve();
		if (gs.result) {
			rep(i, m) {
				if (-1 != ans[i])continue;
				ans[i] = gs.x[i].val();
				if (0 == ans[i])ans[i] = 3;
			}
			rep(i, m) cout << ans[i] << " ";
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}