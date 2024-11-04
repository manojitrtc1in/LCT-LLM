#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

const uint MOD = 998244353, G = 3, Inv2 = (MOD + 1) >> 1;
const int BRUTE_LIMIT = 100;

inline uint norm(const uint &x) {
	return x < MOD ? x : x - MOD;
}

struct Z {
	uint v;
	Z() {}
	Z(const uint &v) : v(v) {}
	inline bool operator < (const Z &x) const {
		return v < x.v;
	}
	inline Z operator + (const Z &rhs) const {
		return norm(v + rhs.v);
	}
	inline Z operator - (const Z &rhs) const {
		return norm(v + MOD - rhs.v);
	}
	inline Z operator - () const {
		return v == 0 ? 0 : MOD - v;
	}
	inline Z operator * (const Z &rhs) const {
		return static_cast<uint64>(v) * rhs.v % MOD;
	}
	inline Z &operator += (const Z &rhs) {
		return *this = this->operator+(rhs);
	}
	inline Z &operator -= (const Z &rhs) {
		return *this = this->operator-(rhs);
	}
	inline Z &operator *= (const Z &rhs) {
		return *this = this->operator*(rhs);
	}
	inline Z &operator ++ () {
		++v == MOD && (v = 0);
		return *this;
	}
	inline Z &operator -- () {
		v-- == 0 && (v = MOD - 1);
		return *this;
	}
};

inline Z power(Z x, int k) {
	Z ans = 1;
	for (; k > 0; k >>= 1, x *= x) {
		if (k & 1) {
			ans *= x;
		}
	}
	return ans;
}
inline Z inv(const Z &x) {
	return power(x, MOD - 2);
}
int root(int p) {
    std::vector<int> fac;
    int phi = p - 1, x = phi;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            fac.emplace_back(i);
            for (; x % i == 0; x /= i);
        }
    }
    if (x > 1) fac.emplace_back(x);
    for (int i = 2; i <= phi; i++) {
        bool flg = true;
        for (auto j : fac) {
			auto pow = [](int x, int k, int p) {
				int ans = 1;
				for (; k > 0; k >>= 1, x = (int64)x * x % p) {
					if (k & 1) {
						ans = (int64)ans * x % p;
					}
				}
				return ans;
			};
            if (pow(i, phi / j, p) == 1) {
                flg = false;
                break;
            }
        }
        if (flg) return i;
    }
    return -1;
}
inline int ceilLog(const int &n) {
	return std::__lg((n << 1) - 1);
}
inline int bsgs(Z a, Z b) {
	if (b.v == 1) {
		return 0;
	}
	int m = ceil(sqrt(MOD));
	std::unordered_map<uint, int> map;
	Z w(1);
	for (int i = 0; i < m; i++, b *= a, w *= a) {
		map[b.v] = i;
	}
	a = w;
	for (int i = 1; i <= m; i++, a *= w) {
		if (map.count(a.v)) {
			return i * m - map[a.v];
		}
	}
	return -1;
}
inline Z degree(Z x, const int &k) {
	if (x.v == 0) {
		return 0;
	}
	int r = bsgs(G, x);
	assert(r >= 0 && r % k == 0);
	x = power(G, r / k);
	return std::min(x, -x);
}

namespace NTT {
	int K = 0;
	std::vector<Z> w[22];
	inline void prepare(const int &k) {
		for (; K < k; ) {
			K++;
			w[K].resize((1 << K) + 1, 0);
			Z root = ::power(G, (MOD - 1) >> K);
			w[K][0] = 1;
			for (int i = 1; i < (1 << K); i++) {
				w[K][i] = w[K][i - 1] * root;
			}
		}
	}
	inline void ntt(Z *f, const int &k, const bool &opt) {
		if (k > K) {
			prepare(k);
		}
		int n = 1 << k;
		std::vector<int> rev(n, 0);
		for (int i = 0; i < n; i++) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << (k - 1);
			if (i < rev[i]) {
				std::swap(f[i], f[rev[i]]);
			}
		}
		for (int l = 1, t = 1; l < n; l <<= 1, t++) {
			for (int i = 0; i < n; i += l << 1) {
				Z *f1 = f + i, *f2 = f + i + l, *wk = w[t].data();
				for (int j = 0; j < l; j++) {
					Z x = (*f2) * (*wk++);
					*f2++ = *f1 - x;
					*f1++ += x;
				}
			}
		}
		if (opt) {
			std::reverse(f + 1, f + n);
			Z invN = inv(n);
			for (int i = 0; i < n; i++) {
				f[i] *= invN;
			}
		}
	}
}

struct Poly : std::vector<Z> {
	using std::vector<Z>::vector;
	inline void read() {
		for (auto &x : *this) {
			scanf("%u", &x.v);
		}
	}
	inline void write(const char &mid = ' ') const {
		int n = this->size();
		for (int i = 0; i < n; i++) {
			printf("%u%c", this->operator[](i).v, i == n - 1 ? '\n' : mid);
		}
	}
	inline void reset(const int &n) {
		this->clear();
		this->resize(n, 0);
	}
	inline void reverse() {
		std::reverse(this->begin(), this->end());
	}
	inline void dft(const int &k) {
		NTT::ntt(this->data(), k, false);
	}
	inline void idft(const int &k) {
		NTT::ntt(this->data(), k, true);
	}
	inline Poly operator + (const Poly &rhs) const {
		Poly f(*this);
		f.resize(std::max(this->size(), rhs.size()), 0);
		for (int i = 0; i < (int)rhs.size(); i++) {
			f[i] += rhs[i];
		}
		return f;
	}
	inline Poly operator + (const Z &w) const {
		return this->operator+(Poly{w});
	}
	inline Poly operator += (const Poly &rhs) {
		this->resize(std::max(this->size(), rhs.size()), 0);
		for (int i = 0; i < (int)rhs.size(); i++) {
			this->operator[](i) += rhs[i];
		}
		return *this;
	}
	inline Poly operator += (const Z &w) {
		this->operator[](0) += w;
		return *this;
	}
	inline Poly operator - (const Poly &rhs) const {
		Poly f(*this);
		f.resize(std::max(this->size(), rhs.size()), 0);
		for (int i = 0; i < (int)rhs.size(); i++) {
			f[i] -= rhs[i];
		}
		return f;
	}
	inline Poly operator - (const Z &w) const {
		return this->operator-(Poly{w});
	}
	inline Poly operator -= (const Poly &rhs) {
		this->resize(std::max(this->size(), rhs.size()), 0);
		for (int i = 0; i < (int)rhs.size(); i++) {
			this->operator[](i) -= rhs[i];
		}
		return *this;
	}
	inline Poly operator -= (const Z &w) {
		this->operator[](0) -= w;
		return *this;
	}
	inline Poly operator - () const {
		Poly f(*this);
		for (auto &x : f) {
			x = -x;
		}
		return f;
	}
	inline Poly operator * (const Z &w) const {
		Poly f(*this);
		for (auto &x : f) {
			x *= w;
		}
		return f;
	}
	inline Poly operator *= (const Z &w) {
		for (auto &x : *this) {
			x *= w;
		}
		return *this;
	}
	inline Poly der() const {
		if (this->size() == 1u) {
			return Poly(0, 0);
		}
		int n = this->size();
		Poly f(n - 1, 0);
		for (int i = 1; i < n; i++) {
			f[i - 1] = this->operator[](i) * i;
		}
		return f;
	}
	inline Poly itg() const {
		int n = this->size();
		Poly f(n + 1, 0);
		for (int i = 0; i < n; i++) {
			f[i + 1] = this->operator[](i) * ::inv(i + 1);
		}
		return f;
	}
	inline Poly operator * (const Poly &rhs) const {
		int n = this->size(), m = rhs.size();
		if (n <= 10 || m <= 10 || n + m <= BRUTE_LIMIT) {
			Poly f(n + m - 1, 0);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					f[i + j] += this->operator[](i) * rhs[j];
				}
			}
			return f;
		}
		n += m - 1;
		int k = ceilLog(n), N = 1 << k;
		Poly f(*this), g(rhs);
		f.resize(N, 0);
		g.resize(N, 0);
		f.dft(k);
		g.dft(k);
		for (int i = 0; i < N; i++) {
			f[i] *= g[i];
		}
		f.idft(k);
		f.resize(n, 0);
		return f;
	}
	inline Poly operator *= (const Poly &rhs) {
		return (*this) = this->operator*(rhs);
	}
	inline Poly operator << (const int &k) const {
		int n = this->size();
		if (k >= n) {
			return Poly(n, 0);
		}
		Poly f(n, 0);
		std::copy_n(this->data(), n - k, f.data() + k);
		return f;
	}
	inline Poly operator >> (const int &k) const {
		int n = this->size();
		if (k >= n) {
			return Poly(n, 0);
		}
		Poly f(n, 0);
		std::copy_n(this->data() + k, n - k, f.data());
		return f;
	}
	inline Poly inv() const {
		assert(this->operator[](0).v != 0);
		int n = this->size(), k = ceilLog(n), N = 1 << k;
		Poly f(N, 0);
		f[0] = ::inv(this->operator[](0));
		for (int l = 2, i = 1; l <= N; l <<= 1, i++) {
			Poly p(this->data(), this->data() + std::min(n, l));
			p.resize(l, 0);
			Poly q(f.data(), f.data() + l);
			p.dft(i);
			q.dft(i);
			for (int j = 0; j < l; j++) {
				p[j] *= q[j];
			}
			p.idft(i);
			std::fill_n(p.data(), l >> 1, 0);
			p.dft(i);
			for (int j = 0; j < l; j++) {
				p[j] *= q[j];
			}
			p.idft(i);
			for (int j = (l >> 1); j < l; j++) {
				f[j] = -p[j];
			}
		}
		f.resize(n, 0);
		return f;
	}
	inline Poly operator / (const Poly &rhs) const {
		int n = this->size(), m = rhs.size();
		Poly f(*this), g(rhs);
		f.reverse();
		g.reverse();
		n -= m - 1;
		f.resize(n, 0);
		g.resize(n, 0);
		f *= g.inv();
		f.resize(n, 0);
		f.reverse();
		return f;
	}
	inline Poly operator % (const Poly &rhs) const {
		Poly f = this->operator-(this->operator/(rhs) * rhs);
		f.resize(rhs.size() - 1, 0);
		return f;
	}
	inline std::pair<Poly, Poly> div(const Poly &rhs) const {
		Poly f = this->operator/(rhs), g = this->operator-(f * rhs);
		g.resize(rhs.size() - 1, 0);
		return std::make_pair(f, g);
	}
	inline Poly sqrt() const {
		int n = this->size(), k = ceilLog(n), N = 1 << k;
		Poly a(*this), f(N, 0);
		a.resize(N, 0);
		f[0] = degree(a[0], 2);
		for (int i = 1; i <= k; i++) {
			int n = 1 << i, N = n << 1;
			Poly p(f.data(), f.data() + n);
			Poly q(a.data(), a.data() + n);
			Poly r = p.inv();
			p.resize(N, 0);
			q.resize(N, 0);
			r.resize(N, 0);
			p.dft(i + 1);
			q.dft(i + 1);
			r.dft(i + 1);
			for (int j = 0; j < N; j++) {
				p[j] = (p[j] + q[j] * r[j]) * Inv2;
			}
			p.idft(i + 1);
			std::copy_n(p.data(), n, f.data());
		}
		f.resize(n, 0);
		return f;
	}
	inline Poly ln() const {
		assert(this->operator[](0).v == 1);
		Poly f = this->der() * this->inv();
		f.resize(this->size(), 0);
		f = f.itg();
		f.pop_back();
		return f;
	}
	inline Poly exp() const {
		assert(this->operator[](0).v == 0);
		int n = this->size(), k = ceilLog(n), N = 1 << k;
		Poly a(*this), f(N, 0);
		a.resize(N, 0);
		f[0] = 1;
		for (int l = 2; l <= N; l <<= 1) {
			Poly p(f.data(), f.data() + l);
			Poly q(a.data(), a.data() + l);
			p *= q - p.ln() + 1;
			std::copy_n(p.data(), l, f.data());
		}
		f.resize(n, 0);
		return f;
	}
	inline Poly root(const int &k) const {
		assert(k >= 1);
		return k == 2 ? this->sqrt() : (this->ln() * ::inv(k)).exp();
	}
	inline Poly power(const int &k) const {
		assert(k >= 0);
		int n = this->size(), p = 0;
		for (; p < n && this->operator[](p).v == 0; p++);
		if (static_cast<uint64>(k) * p >= static_cast<uint64>(n)) {
			return Poly(n, 0);
		}
		Z w = this->operator[](p);
		return (((this->operator>>(p) * ::inv(w)).ln() * k).exp() * ::power(w, k)) << (k * p);
	}
};

struct Transposition {
	std::vector<int> ls, rs, pos;
	std::vector<Poly> h, g;
	inline Poly bruteMul(const Poly &a, const Poly &b) {
		int n = a.size(), m = b.size();
		Poly f(n - m + 1, 0);
		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j < m; j++) {
				f[i] += a[i + j] * b[j];
			}
		}
		return f;
	}
	inline Poly mul(const Poly &a, const Poly &b) {
		if (a.size() <= BRUTE_LIMIT) {
			return bruteMul(a, b);
		}
		int n = a.size(), m = b.size(), k = ceilLog(n), N = 1 << k;
		Poly f(a), g(b);
		g.reverse();
		f.resize(N, 0);
		g.resize(N, 0);
		f.dft(k);
		g.dft(k);
		for (int i = 0; i < N; i++) {
			f[i] *= g[i];
		}
		f.idft(k);
		return Poly(f.data() + m - 1, f.data() + n);
	}
	inline std::pair<Poly, Poly> mul2(const Poly &a, const Poly &b1, const Poly &b2) {
		if (a.size() <= BRUTE_LIMIT) {
			return std::make_pair(bruteMul(a, b2), bruteMul(a, b1));
		}
		int n = a.size(), m1 = b1.size(), m2 = b2.size(), k = ceilLog(n), N = 1 << k;
		Poly f(a), g(b2);
		g.reverse();
		f.resize(N, 0);
		g.resize(N, 0);
		f.dft(k);
		g.dft(k);
		for (int i = 0; i < N; i++) {
			g[i] *= f[i];
		}
		g.idft(k);
		Poly f1(g.data() + m2 - 1, g.data() + n);
		g = b1;
		g.reverse();
		g.resize(N, 0);
		g.dft(k);
		for (int i = 0; i < N; i++) {
			g[i] *= f[i];
		}
		g.idft(k);
		Poly f2(g.data() + m1 - 1, g.data() + n);
		return std::make_pair(f1, f2);
	}
	inline void build(int n) {
		ls.assign(n * 2 - 1, 0);
		rs.assign(n * 2 - 1, 0);
		h.assign(n * 2 - 1, Poly());
		g.assign(n * 2 - 1, Poly());
		pos.assign(n, 0);
		int idx = 0;
		std::function<void(int&, int, int)> dfs = [&](int &u, int l, int r) {
			u = idx++;
			if (l == r) {
				pos[l] = u;
				return;
			}
			int mid = (l + r) >> 1;
			dfs(ls[u], l, mid);
			dfs(rs[u], mid + 1, r);
		};
		int t;
		dfs(t, 0, n - 1);
	}
	inline std::vector<Z> _eval(const Poly &a, const std::vector<Z> &x) {
		int n = a.size();
		build(n);
		for (int i = 0; i < n; i++) {
			g[pos[i]] = Poly({1, -x[i]});
		}
		for (int i = n * 2 - 2; i >= 0; i--) {
			if (ls[i] > 0) {
				g[i] = g[ls[i]] * g[rs[i]];
			}
		}
		Poly f(a);
		f.resize(n * 2, 0);
		h[0] = mul(f, g[0].inv());
		for (int i = 0; i < n * 2 - 1; i++) {
			if (ls[i] > 0) {
				std::tie(h[ls[i]], h[rs[i]]) = mul2(h[i], g[ls[i]], g[rs[i]]);
			}
		}
		std::vector<Z> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = h[pos[i]][0];
		}
		return ans;
	}
	inline std::vector<Z> eval(const Poly &a, const std::vector<Z> &_x) {
		int n = a.size(), m = _x.size();
		Poly f(a);
		std::vector<Z> x(_x);
		f.resize(std::max(n, m), 0);
		x.resize(std::max(n, m), 0);
		std::vector<Z> ans = _eval(f, x);
		ans.resize(m);
		return ans;
	}
	inline Poly inter(const std::vector<Z> &x, const std::vector<Z> &y) {
		int n = x.size();
		build(n);
		for (int i = 0; i < n; i++) {
			g[pos[i]] = Poly({1, -x[i]});
		}
		for (int i = n * 2 - 2; i >= 0; i--) {
			if (ls[i] > 0) {
				g[i] = g[ls[i]] * g[rs[i]];
			}
		}
		Poly f(g[0]);
		f.reverse();
		f = f.der();
		f.resize(n * 2, 0);
		h[0] = mul(f, g[0].inv());
		for (int i = 0; i < n * 2 - 1; i++) {
			if (ls[i] > 0) {
				std::tie(h[ls[i]], h[rs[i]]) = mul2(h[i], g[ls[i]], g[rs[i]]);
			}
		}
		for (int i = 0; i < 2 * n - 1; i++) {
			g[i].reverse();
		}
		for (int i = 0; i < n; i++) {
			h[pos[i]] = Poly({y[i] * ::inv(h[pos[i]][0])});
		}
		for (int i = n * 2 - 2; i >= 0; i--) {
			if (ls[i] > 0) {
				h[i] = h[ls[i]] * g[rs[i]] + h[rs[i]] * g[ls[i]];
			}
		}
		return h[0];
	}
};

const int N = 2e5;

int n, m, perm[27], a[N + 5];
Z val[27];
char s[N + 5], t[N + 5];

int main() {
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	for (int i = 1; i <= 26; i++) {
		scanf("%d", &perm[i]);
		val[i] = std::uniform_int_distribution<uint>(1, 998244352)(rng);
	}
	scanf("%s%s", t, s);
	n = strlen(s);
	m = strlen(t);
	std::reverse(t, t + m);
	for (int i = 0; i < n; i++) {
		s[i] -= 'a' - 1;
	}
	for (int i = 0; i < m; i++) {
		t[i] -= 'a' - 1;
		a[i] = perm[t[i]];
	}
	Poly p(n), q(m);
	for (int i = 0; i < n; i++) {
		p[i] = val[s[i]] * val[s[i]];
	}
	for (int i = 0; i < m; i++) {
		q[i] = val[t[i]] * val[t[i]] + val[a[i]] * val[a[i]] + val[t[i]] * val[a[i]] * 4;
	}
	Poly f = p * q;
	for (int i = 0; i < n; i++) {
		p[i] = val[s[i]] * val[s[i]] * val[s[i]];
	}
	for (int i = 0; i < m; i++) {
		q[i] = val[a[i]] + val[t[i]];
	}
	f -= p * q * 2;
	for (int i = 0; i < n; i++) {
		p[i] = val[s[i]];
	}
	for (int i = 0; i < m; i++) {
		q[i] = val[a[i]] * val[t[i]] * (val[a[i]] + val[t[i]]);
	}
	f -= p * q * 2;
	std::vector<Z> s1(n, 0), s2(m, 0);
	for (int i = 0; i < n; i++) {
		s1[i] = val[s[i]] * val[s[i]] * val[s[i]] * val[s[i]];
	}
	for (int i = 0; i < m; i++) {
		s2[i] = val[t[i]] * val[t[i]] * val[a[i]] * val[a[i]];
	}
	std::partial_sum(s1.begin(), s1.end(), s1.begin());
	std::partial_sum(s2.begin(), s2.end(), s2.begin());
	for (int i = 0; i < n; i++) {
		f[i] += s1[i] - (i - m + 1 <= 0 ? 0 : s1[i - m]);
		f[i] += s2[std::min(i, m - 1)];
	}
	for (int i = m - 1; i < n; i++) {
		printf("%d", f[i].v == 0 ? 1 : 0);
	}
	printf("\n");
	return 0;
}