






using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }






inline unsigned int id17(unsigned int x) { unsigned long r; _BitScanForward(&r, x); return r; }
inline unsigned int id5(unsigned int x) { unsigned long r; _BitScanReverse(&r, x); return 31 - r; }
inline unsigned int id8(unsigned int x) { unsigned long r; return _BitScanForward(&r, x) ? r + 1 : 0; }
inline unsigned int id14(unsigned int x) { return __popcnt(x); }

inline unsigned long long id13(unsigned long long x) { unsigned long r; _BitScanForward64(&r, x); return r; }
inline unsigned long long id15(unsigned long long x) { unsigned long r; _BitScanReverse64(&r, x); return 63 - r; }
inline unsigned long long id3(unsigned long long x) { unsigned long r; return _BitScanForward64(&r, x) ? r + 1 : 0; }
inline unsigned long long id10(unsigned long long x) { return __popcnt64(x); }

inline unsigned int hidword(unsigned long long x) { return static_cast<unsigned int>(x >> 32); }
inline unsigned int lodword(unsigned long long x) { return static_cast<unsigned int>(x & 0xFFFFFFFF); }
inline unsigned long long id13(unsigned long long x) { return lodword(x) ? id17(lodword(x)) : id17(hidword(x)) + 32; }
inline unsigned long long id15(unsigned long long x) { return hidword(x) ? id5(hidword(x)) : id5(lodword(x)) + 32; }
inline unsigned long long id3(unsigned long long x) { return lodword(x) ? id8(lodword(x)) : hidword(x) ? id8(hidword(x)) + 32 : 0; }
inline unsigned long long id10(unsigned long long x) { return id14(lodword(x)) + id14(hidword(x)); }







template<int MOD> struct ModInt {
	static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
	ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
	ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
	int get() const { return (int)x; }
	ModInt& operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt& operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt& operator/=(ModInt that) { return *this *= that.inverse(); }
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
	ModInt inverse() const {
		long long a = x, b = MOD, u = 1, v = 0;
		while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
		return ModInt(u);
	}
	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r;
}
typedef ModInt<998244353> mint;
template<typename T>
struct id0 {
	using Poly = vector<T>;
	using Conv = function<Poly(Poly, Poly)>;
	Conv conv;
	id0(Conv conv) :conv(conv) {}

	Poly pre(const Poly& as, int deg) {
		return Poly(as.begin(), as.begin() + min((int)as.size(), deg));
	}

	Poly add(Poly as, Poly bs) {
		int sz = max(as.size(), bs.size());
		Poly cs(sz, T(0));
		for (int i = 0; i < (int)as.size(); i++) cs[i] += as[i];
		for (int i = 0; i < (int)bs.size(); i++) cs[i] += bs[i];
		return cs;
	}

	Poly sub(Poly as, Poly bs) {
		int sz = max(as.size(), bs.size());
		Poly cs(sz, T(0));
		for (int i = 0; i < (int)as.size(); i++) cs[i] += as[i];
		for (int i = 0; i < (int)bs.size(); i++) cs[i] -= bs[i];
		return cs;
	}

	Poly mul(Poly as, Poly bs) {
		return conv(as, bs);
	}

	Poly mul(Poly as, T k) {
		Poly res(all(as));
		for (auto& a : res) a *= k;
		return res;
	}

	

	Poly inv(Poly as, int deg) {
		assert(as[0] != T(0));
		Poly rs({ T(1) / as[0] });
		for (int i = 1; i < deg; i <<= 1)
			rs = pre(sub(add(rs, rs), mul(mul(rs, rs), pre(as, i << 1))), i << 1);
		return rs;
	}

	

	Poly div(Poly as, Poly bs) {
		while (as.back() == T(0)) as.pop_back();
		while (bs.back() == T(0)) bs.pop_back();
		if (bs.size() > as.size()) return Poly();
		reverse(as.begin(), as.end());
		reverse(bs.begin(), bs.end());
		int need = as.size() - bs.size() + 1;
		Poly ds = pre(mul(as, inv(bs, need)), need);
		reverse(ds.begin(), ds.end());
		return ds;
	}

	

	Poly sqrt(Poly as, int deg) {
		assert(as[0] == T(1));
		T inv2 = T(1) / T(2);
		Poly ss({ T(1) });
		for (int i = 1; i < deg; i <<= 1) {
			ss = pre(add(ss, mul(pre(as, i << 1), inv(ss, i << 1))), i << 1);
			for (T& x : ss) x *= inv2;
		}
		return ss;
	}

	Poly diff(Poly as) {
		int n = as.size();
		Poly res(n - 1);
		for (int i = 1; i < n; i++) res[i - 1] = as[i] * T(i);
		return res;
	}

	Poly integral(Poly as) {
		int n = as.size();
		Poly res(n + 1);
		res[0] = T(0);
		for (int i = 0; i < n; i++) res[i + 1] = as[i] / T(i + 1);
		return res;
	}

	

	Poly log(Poly as, int deg) {
		return pre(integral(mul(diff(as), inv(as, deg))), deg);
	}

	

	Poly exp(Poly as, int deg) {
		Poly f({ T(1) });
		as[0] += T(1);
		for (int i = 1; i < deg; i <<= 1)
			f = pre(mul(f, sub(pre(as, i << 1), log(f, i << 1))), i << 1);
		return f;
	}

	Poly partition(int n) {
		Poly rs(n + 1);
		rs[0] = T(1);
		for (int k = 1; k <= n; k++) {
			if (1LL * k * (3 * k + 1) / 2 <= n) rs[k * (3 * k + 1) / 2] += T(k % 2 ? -1LL : 1LL);
			if (1LL * k * (3 * k - 1) / 2 <= n) rs[k * (3 * k - 1) / 2] += T(k % 2 ? -1LL : 1LL);
		}
		return inv(rs, n + 1);
	}






	int getrandmax() {
		static uint32_t y = time(NULL);
		y ^= (y << 13); y ^= (y >> 17);
		y ^= (y << 5);
		return abs((int)y);
	}

	template<typename T2>
	int jacobi(T2 a, T2 mod) {
		int s = 1;
		if (a < 0) a = a % mod + mod;
		while (mod > 1) {
			a %= mod;
			if (a == 0) return 0;
			int r = id17(a);
			if ((r & 1) && ((mod + 2) & 4)) s = -s;
			a >>= r;
			if (a & mod & 2) s = -s;
			swap(a, mod);
		}
		return s;
	}

	template<typename T2>
	vector<T2> id1(T2 a, T2 mod) {
		if (mod == 2) return { a & 1 };
		int j = jacobi(a, mod);
		if (j == 0) return { 0 };
		if (j == -1) return {};
		ll b, d;
		while (1) {
			b = getrandmax() % mod;
			d = (b * b - a) % mod;
			if (d < 0) d += mod;
			if (jacobi<ll>(d, mod) == -1) break;
		}

		ll f0 = b, f1 = 1, g0 = 1, g1 = 0;
		for (ll e = (mod + 1) >> 1; e; e >>= 1) {
			if (e & 1) {
				ll tmp = (g0 * f0 + d * ((g1 * f1) % mod)) % mod;
				g1 = (g0 * f1 + g1 * f0) % mod;
				g0 = tmp;
			}
			ll tmp = (f0 * f0 + d * ((f1 * f1) % mod)) % mod;
			f1 = (2 * f0 * f1) % mod;
			f0 = tmp;
		}
		if (g0 > mod - g0) g0 = mod - g0;
		return { T2(g0),T2(mod - g0) };
	}


	Poly super_sqrt(Poly from, int deg) {
		deque<int> as(deg);
		for (int i = 0; i < deg; i++) as[i] = from[i].get();

		while (!as.empty() && as.front() == 0) as.pop_front();

		if (as.empty()) {
			Poly res(deg, 0);
			return res;
		}

		int m = as.size();
		if ((deg - m) & 1) {
			return Poly();
		}

		auto ss = id1(as[0], 998244353);
		if (ss.empty()) return Poly();

		vector<T> ps(deg, T(0));
		for (int i = 0; i < m; i++) ps[i] = T(as[i]) / T(as[0]);

		auto bs = sqrt(ps, deg);
		bs.insert(bs.begin(), (deg - m) / 2, T(0));
		Poly res(deg);
		for (int i = 0; i < deg; i++) {
			res[i] = bs[i] * ss[0];
		}
		return res;
	}











};



template<class T> T id7(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; id7(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
struct MathsNTTModAny {
	template<int mod, int primitive_root>
	class NTT {
	public:
		int get_mod() const { return mod; }
		void _ntt(vector<ll>& a, int sign) {
			const int n = sz(a);
			assert((n ^ (n & -n)) == 0); 


			const int g = 3; 

			int h = (int)mod_pow(g, (mod - 1) / n, mod); 

			if (sign == -1) h = (int)mod_inv(h, mod); 


			

			int i = 0;
			for (int j = 1; j < n - 1; ++j) {
				for (int k = n >> 1; k > (i ^= k); k >>= 1);
				if (j < i) swap(a[i], a[j]);
			}

			for (int m = 1; m < n; m *= 2) {
				const int m2 = 2 * m;
				const ll base = mod_pow(h, n / m2, mod);
				ll w = 1;
				FOR(x, m) {
					for (int s = x; s < n; s += m2) {
						ll u = a[s];
						ll d = a[s + m] * w % mod;
						a[s] = u + d;
						if (a[s] >= mod) a[s] -= mod;
						a[s + m] = u - d;
						if (a[s + m] < 0) a[s + m] += mod;
					}
					w = w * base % mod;
				}
			}

			for (auto& x : a) if (x < 0) x += mod;
		}
		void ntt(vector<ll>& input) {
			_ntt(input, 1);
		}
		void intt(vector<ll>& input) {
			_ntt(input, -1);
			const int n_inv = mod_inv(sz(input), mod);
			for (auto& x : input) x = x * n_inv % mod;
		}

		vector<ll> convolution(const vector<ll>& a, const vector<ll>& b) {
			int id6 = 1;
			while (id6 < sz(a) + sz(b)) id6 *= 2;

			vector<ll> _a = a, _b = b;
			_a.resize(id6); _b.resize(id6);

			ntt(_a);
			ntt(_b);

			FOR(i, id6) {
				(_a[i] *= _b[i]) %= mod;
			}

			intt(_a);
			return _a;
		}
	};

	ll garner(vector<pair<int, int>> mr, int mod) {
		mr.emplace_back(mod, 0);

		vector<ll> coffs(sz(mr), 1);
		vector<ll> constants(sz(mr), 0);
		FOR(i, sz(mr) - 1) {
			

			ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
			if (v < 0) v += mr[i].first;

			for (int j = i + 1; j < sz(mr); j++) {
				(constants[j] += coffs[j] * v) %= mr[j].first;
				(coffs[j] *= mr[i].first) %= mr[j].first;
			}
		}

		return constants[sz(mr) - 1];
	}

	typedef NTT<167772161, 3> NTT_1;
	typedef NTT<469762049, 3> NTT_2;
	typedef NTT<1224736769, 3> NTT_3;

	vector<ll> solve(vector<ll> a, vector<ll> b, int mod = 1000000007) {
		for (auto& x : a) x %= mod;
		for (auto& x : b) x %= mod;

		NTT_1 id4; NTT_2 id2; NTT_3 id12;
		assert(id4.get_mod() < id2.get_mod() && id2.get_mod() < id12.get_mod());
		auto x = id4.convolution(a, b);
		auto y = id2.convolution(a, b);
		auto z = id12.convolution(a, b);

		const ll m1 = id4.get_mod(), m2 = id2.get_mod(), m3 = id12.get_mod();
		const ll id16 = mod_inv<ll>(m1, m2);
		const ll id11 = mod_inv<ll>(m1 * m2, m3);
		const ll id9 = m1 * m2 % mod;
		vector<ll> ret(sz(x));
		FOR(i, sz(x)) {
			ll v1 = (y[i] - x[i]) * id16 % m2;
			if (v1 < 0) v1 += m2;
			ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * id11 % m3;
			if (v2 < 0) v2 += m3;
			ll constants3 = (x[i] + m1 * v1 + id9 * v2) % mod;
			if (constants3 < 0) constants3 += mod;
			ret[i] = constants3;
		}

		return ret;
	}

	vector<int> solve(vector<int> a, vector<int> b, int mod = 1000000007) {
		vector<ll> x(all(a));
		vector<ll> y(all(b));

		auto z = solve(x, y, mod);
		vector<int> res;
		fore(aa, z) res.push_back(aa % mod);

		return res;
	}

	vector<mint> solve(vector<mint> a, vector<mint> b, int mod = 998244353) {
		int n = a.size();
		vector<ll> x(n);
		rep(i, 0, n) x[i] = a[i].get();
		n = b.size();
		vector<ll> y(n);
		rep(i, 0, n) y[i] = b[i].get();

		auto z = solve(x, y, mod);
		vector<mint> res;
		fore(aa, z) res.push_back(aa);

		return res;
	}
};














const int MAXSIZE = 101010;
int N, M, C[101010];
MathsNTTModAny ntt;


void _main() {
	using T = mint;
	id0<T> FPS([&](auto a, auto b) {
		return ntt.solve(a, b, 998244353);
		});

	cin >> N >> M;
	rep(i, 0, N) cin >> C[i];
	
	vector<T> sqr(MAXSIZE, 0);
	sqr[0] = T(1);
	rep(i, 0, N) sqr[C[i]] -= T(4);
	sqr = FPS.super_sqrt(sqr, MAXSIZE);

	vector<T> dwn = sqr;
	dwn[0] += 1;

	vector<T> up(MAXSIZE, 0);
	up[0] = 2;

	vector<T> ans = FPS.mul(up, FPS.inv(dwn, MAXSIZE));
	for (int i = 1; i <= M; i++) printf("%d\n", ans[i].get());
}





