#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(bool b) { return to_string(int(b)); }
string to_string(vector<bool>::reference b) { return to_string(int(b)); }
string to_string(char b) { return "'" + string(1, b) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename T = typename A::value_type>
string to_string(A v) {
	string res = "{";
	for (const auto& x : v) res += (res == "{" ? "" : ", ") + to_string(x);
	return res + "}";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug(T...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define db(...) 42
#endif
using ll = long long;
using ld = long double;
const int MOD = 998244353; 

struct Mint {
	int val;
	Mint() { val = 0; }
	Mint(const ll& x) {
		val = (-MOD <= x && x < MOD) ? x : x % MOD;
		if (val < 0) val += MOD;
	}
	template <typename U>
	explicit operator U() const { return (U)val; }
	friend bool operator==(const Mint& a, const Mint& b) { return a.val == b.val; }
	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { return a.val < b.val; }
	Mint& operator+=(const Mint& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Mint& operator-=(const Mint& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	Mint& operator*=(const Mint& m) { val = (ll)val * m.val % MOD; return *this; }
	friend Mint modex(Mint a, ll p) {
		assert(p >= 0);
		Mint ans = 1;
		for (; p; p >>= 1, a *= a) if (p & 1) ans *= a;
		return ans;
	}
	Mint& operator/=(const Mint& m) { return *this *= modex(m, MOD - 2); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	Mint operator++(int) { Mint result(*this); *this += 1; return result; }
	Mint operator--(int) { Mint result(*this); *this -= 1; return result; }
	Mint operator-() const { return Mint(-val); }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const Mint& x) { return os << x.val; }
	friend string to_string(const Mint& b) { return to_string(b.val); }
};
namespace fft {
#define NTT
const Mint gen = 3; 

vector<int> rev(1, 0); 

vector<Mint> roots;
int base = 0;
void precompute(int nbase) {
	if (nbase <= base) return;
	rev.resize(1 << nbase);
	for (int i = 0; i < (1 << nbase); ++i) {
		rev[i] = rev[i >> 1] >> 1 | ((i & 1) << (nbase - 1));
	}
	roots.resize(1 << nbase);
	for (; base < nbase; ++base) {
		int len = 1 << base;
		Mint root = modex(gen, (MOD - 1) >> (base + 1));
		roots[len] = 1;
		for (int i = 1; i < len; ++i) roots[len + i] = roots[len + i - 1] * root;
	}
}
void fft(vector<Mint>& a) {
	int n = a.size();
	assert((n & (n - 1)) == 0);
	int zeros = __builtin_ctz(n);
	precompute(zeros);
	int shift = base - zeros;
	for (int i = 0; i < n; ++i) {
		if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
	}
	for (int len = 1; len < n; len <<= 1)
		for (int i = 0; i < n; i += 2 * len)
			for (int j = 0; j < len; ++j) {
				Mint u = a[i + j], v = a[i + j + len] * roots[len + j];
				a[i + j] = u + v;
				a[i + j + len] = u - v;
			}
}
vector<Mint> multiply(vector<Mint> a, vector<Mint> b) {
	if (a.empty() || b.empty()) return {};
	int sz = a.size() + b.size() - 1;
	int n = sz == 1 ? 1 : 1 << (32 - __builtin_clz(sz - 1));
	bool eq = (a == b);
	a.resize(n);
	fft(a);
	if (eq) b = a;
	else {
		b.resize(n);
		fft(b);
	}
	Mint inv = Mint(1) / n;
	for (int i = 0; i < n; ++i) a[i] *= b[i] * inv;
	fft(a);
	reverse(a.begin() + 1, a.end());
	a.resize(sz);
	return a;
}
vector<Mint> multiply(const vector<Mint>& a, const vector<Mint>& b, int m) {
	assert(m == MOD);
	return multiply(a, b);
}
}; 

namespace polynomial {


vector<Mint> subtract(vector<Mint> a, const vector<Mint>& b) {
	if (a.size() < b.size()) {
		a.resize(b.size());
	}
	for (int i = 0; i < b.size(); ++i) {
		a[i] -= b[i];
	}
	while (!a.empty() && a.back() == 0) a.pop_back();
	return a;
}


vector<Mint> add(vector<Mint> a, const vector<Mint>& b) {
	if (a.size() < b.size()) {
		a.resize(b.size());
	}
	for (int i = 0; i < b.size(); ++i) {
		a[i] += b[i];
	}
	while (!a.empty() && a.back() == 0) a.pop_back();
	return a;
}






vector<Mint> inverse(const vector<Mint>& a) {
#ifdef NTT
	assert(!a.empty() && a[0] != 0);
	int n = a.size();
	vector<Mint> b = {1 / a[0]};
	for (int m = 2; b.size() < n; m <<= 1) {
		vector<Mint> aCut(a.begin(), a.begin() + min((int)a.size(), m));
		aCut.resize(2 * m);
		b.resize(2 * m);
		fft::fft(aCut);
		fft::fft(b);
		for (int i = 0; i < 2 * m; ++i) {
			b[i] *= 2 - aCut[i] * b[i];
		}
		fft::fft(b);
		reverse(b.begin() + 1, b.end());
		b.resize(m);
		Mint inv = Mint(1) / (2 * m);
		for (int i = 0; i < m; ++i) b[i] *= inv;
	}
	b.resize(n);
	return b;
#else
	assert(!a.empty() && a[0] != 0);
	int n = a.size();
	vector<Mint> b = {1 / a[0]};
	for (int m = 2; b.size() < n; m <<= 1) {
		vector<Mint> aCut(a.begin(), a.begin() + min((int)a.size(), m));
		auto x = fft::multiply(aCut, fft::multiply(b, b, MOD), MOD);
		b.resize(m);
		for (int i = 0; i < m; ++i) {
			b[i] += b[i] - x[i];
		}
	}
	b.resize(n);
	return b;
#endif
}
















vector<Mint> divide(vector<Mint> a, vector<Mint> b) {
	assert(!b.empty() && b.back() != 0);
	int n = a.size();
	int m = b.size();
	if (n < m) return {};
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	b.resize(n - m + 1);
	a = fft::multiply(a, inverse(b), MOD);
	a.erase(a.begin() + n - m + 1, a.end());
	reverse(a.begin(), a.end());
	return a;
}


vector<Mint> remainder(const vector<Mint>& a, const vector<Mint>& b) {
	return subtract(a, fft::multiply(b, divide(a, b), MOD));
}


vector<Mint> integral(const vector<Mint>& a) {
	vector<Mint> ret(a.size() + 1);
	for (int i = 1; i < ret.size(); ++i) {
		ret[i] = a[i - 1] / i;
	}
	return ret;
}


vector<Mint> derivative(const vector<Mint>& a) {
	if (a.empty()) return a;
	vector<Mint> ret(a.size() - 1);
	for (int i = 0; i + 1 < a.size(); ++i)
		ret[i] = a[i + 1] * (i + 1);
	return ret;
}




vector<Mint> logarithm(const vector<Mint>& a) {
	assert(!a.empty() && a[0] == 1);
	auto ret = integral(fft::multiply(derivative(a), inverse(a), MOD));
	ret.resize(a.size());
	return ret;
}






vector<Mint> exponent(const vector<Mint>& a) {
	assert(!a.empty() && a[0] == 0);
	int n = a.size();
	vector<Mint> b = {1};
	for (int m = 2; b.size() < n; m <<= 1) {
		vector<Mint> x(a.begin(), a.begin() + min((int)a.size(), m));
		++x[0];
		auto oldB = b;
		b.resize(m);
		b = fft::multiply(oldB, subtract(x, logarithm(b)), MOD);
		b.resize(m);
	}
	b.resize(n);
	return b;
}








vector<Mint> multipoint(const vector<Mint>& a, vector<Mint> xs) {
	int n = xs.size();
	vector<vector<Mint>> prods(2 * n - 1);
	function<void(int, int, int)> getProds = [&](int sn, int s, int e) {
		if (s == e) {
			prods[sn] = {-xs[s], 1};
			return;
		}
		int m = (s + e) >> 1, lsn = sn + 1, rsn = sn + ((m - s + 1) << 1);
		getProds(lsn, s, m);
		getProds(rsn, m + 1, e);
		prods[sn] = fft::multiply(prods[lsn], prods[rsn], MOD);
	};
	getProds(0, 0, n - 1);
	function<void(int, int, int, vector<Mint>)> calc = [&](int sn, int s, int e, vector<Mint> f) {
		if (s == e) {
			xs[s] = f.empty() ? 0 : f[0];
			return;
		}
		int m = (s + e) >> 1, lsn = sn + 1, rsn = sn + ((m - s + 1) << 1);
		calc(lsn, s, m, remainder(f, prods[lsn]));
		calc(rsn, m + 1, e, remainder(f, prods[rsn]));
	};
	calc(0, 0, n - 1, a);
	return xs;
}










vector<Mint> chirpz(vector<Mint> a, Mint g, int n) {
	int d = a.size();
	int phi = MOD - 1;
	vector<Mint> pw(phi + 1);
	pw[0] = 1;
	for (int i = 1; i <= phi; ++i) pw[i] = pw[i - 1] * g;
	auto chirpzEven = [&](const vector<Mint>& b, int m) {
		vector<Mint> u(d), v(m + d - 1);
		for (int i = 0; i < d; ++i) {
			u[i] = b[i] * pw[(ll)i * i % phi];
		}
		for (int i = -(d - 1); i < m; ++i) {
			v[d - 1 + i] = pw[phi - (ll)i * i % phi];
		}
		auto z = fft::multiply(u, v, MOD);
		vector<Mint> ret(m);
		for (int i = 0; i < m; ++i) {
			ret[i] = pw[(ll)i * i % phi] * z[d - 1 + i];
		}
		return ret;
	};
	auto even = chirpzEven(a, (n + 1) >> 1);
	for (int i = 0; i < d; ++i) a[i] *= pw[i % phi];
	auto odd = chirpzEven(a, n >> 1);
	vector<Mint> ret(n);
	for (int i = 0; i < n; ++i) {
		ret[i] = (i & 1) ? odd[i >> 1] : even[i >> 1];
	}
	return ret;
}


vector<Mint> powerMod(const vector<Mint>& a, ll p, const vector<Mint>& b) {
	if (!p) return {1};
	vector<Mint> c;
	if (p & 1) {
		c = fft::multiply(powerMod(a, p - 1, b), a, MOD);
	} else {
		c = powerMod(a, p >> 1, b);
		c = fft::multiply(c, c, MOD);
	}
	return remainder(c, b);
}


vector<Mint> power(vector<Mint> a, ll p, int n) {
	if (!p) return {1};
	assert(a.size() <= n);
	int m = 0;
	while (m < a.size() && a[m] == 0) ++m;
	if (m * p >= n) return {};
	a.erase(a.begin(), a.begin() + m);
	Mint inv = 1 / a[0];
	Mint c = modex(a[0], p);
	for (Mint& x : a) x *= inv;
	a = logarithm(a);
	Mint q = p;
	for (Mint& x : a) x *= q;
	a = exponent(a);
	a.insert(a.begin(), m * p, 0);
	a.resize(n);
	for (Mint& x : a) x *= c;
	return a;
}
vector<Mint> multiplyAll(const vector<vector<Mint>>& polys, int s, int e) {
	if (s == e) return polys[s];
	int m = (s + e) >> 1;
	auto a = multiplyAll(polys, s, m);
	auto b = multiplyAll(polys, m + 1, e);
	return fft::multiply(a, b, MOD);
}

vector<Mint> multiplyAll(const vector<vector<Mint>>& polys) {
	return polys.empty() ? vector<Mint>{1} : multiplyAll(polys, 0, polys.size() - 1);
}
template <typename T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); ++i) a[i] += b[i];
	return a;
}
template <typename T>
vector<T> operator+(vector<T> a, const vector<T>& b) {
	return a += b;
}
template <typename T>
vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); ++i) a[i] -= b[i];
	return a;
}
template <typename T>
vector<T> operator-(vector<T> a, const vector<T>& b) {
	return a -= b;
}
template <typename T>
vector<T> operator-(vector<T> a) {
	for (int i = 0; i < a.size(); ++i) a[i] = -a[i];
	return a;
}
template <typename T>
vector<T> operator+=(vector<T>& a, const T& b) {
	for (int i = 0; i < a.size(); ++i) a[i] += b;
	return a;
}
template <typename T>
vector<T> operator-=(vector<T>& a, const T& b) {
	for (int i = 0; i < a.size(); ++i) a[i] -= b;
	return a;
}
template <typename T>
vector<T> operator*=(vector<T>& a, const T& b) {
	for (int i = 0; i < a.size(); ++i) a[i] *= b;
	return a;
}
template <typename T>
vector<T> operator/=(vector<T>& a, const T& b) {
	for (int i = 0; i < a.size(); ++i) a[i] /= b;
	return a;
}
template <typename T>
vector<T> operator+(vector<T> a, const T& b) { return a += b; }
template <typename T>
vector<T> operator-(vector<T> a, const T& b) { return a -= b; }
template <typename T>
vector<T> operator*(vector<T> a, const T& b) { return a *= b; }
template <typename T>
vector<T> operator/(vector<T> a, const T& b) { return a /= b; }
template <typename T>
vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
	return a = fft::multiply(a, b);
}
template <typename T>
vector<T> operator*(vector<T> a, const vector<T>& b) {
	return a *= b;
}
}; 

using namespace polynomial;
vector<Mint> fac(1, 1), invfac(1, 1);
Mint binom(int n, int k) {
	if (k < 0 || k > n) return 0;
	while (fac.size() <= n) {
		fac.push_back(fac.back() * fac.size());
		invfac.push_back(1 / fac.back());
	}
	return fac[n] * invfac[k] * invfac[n - k];
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> A(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	int las = 0;
	vector<int> R = {A[0]};
	for (int i = 1; i < n; ++i) {
		if (i - las == A[las]) {
			R.push_back(A[i]);
			las = i;
		}
		if (A[i] != A[las]) {
			printf("0\n");
			return 0;
		}
	}
	assert(accumulate(R.begin(), R.end(), 0) == n);
	Mint inv2 = Mint(1) / 2;
	function<array<array<vector<Mint>, 2>, 2>(int, int)> solve = [&](int l, int r) {
		array<array<vector<Mint>, 2>, 2> ret;
		if (l == r) {
			if (R[l] == 1) {
				ret[0][0] = {0, 1};
			} else {
				ret[1][1] = {0, 2};
			}
			return ret;
		}
		int m = (l + r) >> 1;
		auto a = solve(l, m);
		auto b = solve(m + 1, r);
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				vector<Mint> merged = (a[i][0] + a[i][1]) * (b[0][j] + b[1][j]);
				ret[i][j] += merged;
				merged += a[i][0] * b[0][j];
				merged -= a[i][1] * b[1][j] * inv2;
				if (!merged.empty()) merged.erase(merged.begin());
				int ii = i, jj = j;
				if (l == m && R[l] == 1) ii = 1;
				if (m + 1 == r && R[r] == 1) jj = 1;
				ret[ii][jj] += merged;
			}
		db(l, r, ret);
		return ret;
	};
	int r = R.size();
	auto v = solve(0, r - 1);
	vector<Mint> ret;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			ret += v[i][j];
	ret.resize(r + 1);
	db(ret);
	Mint ans = 0;
	binom(r, 0);
	for (int i = 1; i <= r; ++i) {
		int sgn = (r - i) % 2 == 0 ? 1 : -1;
		ans += ret[i] * fac[i] * sgn;
	}
	printf("%d\n", ans.val);
}

