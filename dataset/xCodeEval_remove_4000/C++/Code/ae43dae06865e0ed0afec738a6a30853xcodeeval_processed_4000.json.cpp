





using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 0xcccccccccccccccLL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

namespace fft {

constexpr unsigned int id0 = 998244353;
constexpr unsigned int id8 = 1000000007;
constexpr long double PI = acos(-1);

struct modint_base {};
template<class C> using is_modint = is_base_of<modint_base, C>;
template<class C> using is_modint_t = enable_if_t<is_modint<C>::value>;
template<class C> using is_complex = typename conditional<is_same<C, complex<double>>::value || is_same<C, complex<long double>>::value, true_type, false_type>::type;



template<int m>
struct mint : modint_base {
	unsigned int x;
	static constexpr int mod() {return m;}
	static constexpr unsigned int umod() {return m;}
	mint():x(0) {}
	mint(int64_t x_) {
		int64_t v = int64_t(x_ % umod());
		if(v < 0) v += umod();
		x = (unsigned int)v;
	}
	static mint row(int v) {
		mint v_;
		v_.x = v;
		return v_;
	}
	mint operator-() const { return mint(-x);}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= umod()) x -= umod();
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += umod()-a.x) >= umod()) x -= umod();
		return *this;
	}
	mint& operator*=(const mint a) {
		uint64_t z = x;
		z *= a.x;
		x = (unsigned int)(z % umod());
		return *this;
	}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint &operator++() {
		x++;
		if(x == umod()) x = 0;
		return *this;
	}
	mint &operator--() {
		if(x == 0) x = umod();
		x--;
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
	mint pow(int64_t t) const {
		mint x_ = *this, r = 1;
		while(t) {
			if(t&1) r *= x_;
			x_ *= x_;
			t >>= 1;
		}
		return r;
	}
	mint inv() const { return pow(umod()-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) {return mint(*this) /= a;}
	friend bool operator==(const mint &a, const mint &b) {return a.x == b.x;}
	friend bool operator!=(const mint &a, const mint &b) {return a.x != b.x;}
};

constexpr int64_t safe_mod(int64_t x, int64_t m) {
	x %= m;
	if(x < 0) x += m;
	return x;
}

constexpr int64_t id12(int64_t x, int64_t n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	uint64_t r = 1;
	uint64_t y = safe_mod(x, m);
	while(n) {
		if(n&1) r = (r*y)%_m;
		y = (y*y)%_m;
		n >>= 1;
	}
	return r;
}

constexpr int id7(int m) {
	if(m == 2) return 1;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 998244353) return 3;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m-1)>>1;
	while(~x&1) x >>= 1;
	for(int i = 3; (int64_t)(i)*i <= x; i += 2) {
		if(x%i == 0) {
			divs[cnt++] = i;
			while(x%i == 0) x /= i;
		}
	}
	if(x > 1) divs[cnt++] = x;
	for(int g = 2;; g++) {
		bool ok = true;
		for(int i = 0; i < cnt; i++) {
			if(id12(g, (m-1)/divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) return g;
	}
}
template<int m> constexpr int primitive_root = id7(m);

constexpr pair<int64_t, int64_t> id3(int64_t a, int64_t b) {
	a = safe_mod(a, b);
	if(a == 0) return {b, 0};
	int64_t s = b, t = a;
	int64_t m0 = 0, m1 = 1;
	while(t) {
		int64_t u = s/t;
		s -= t*u;
		m0 -= m1*u;
		int64_t tmp = s;
		s = t;
		t = tmp;
		tmp = m0;
		m0 = m1;
		m1 = tmp;
	}
	if(m0 < 0) m0 += b/s;
	return {s, m0};
}

int id5(int n) {
	int x = 0;
	while((1U << x) < (unsigned int)(n)) x++;
	return x;
}

template<class mint, is_modint_t<mint>* = nullptr>
void id4(vector<mint> &ary) {
	static constexpr int g = primitive_root<mint::mod()>;
	int n = int(ary.size());
	int h = id5(n);

	static bool first = true;
	static mint sum_e[30];
	if(first) {
		first = false;
		mint es[30], ies[30];
		int cnt2 = __builtin_ctz(mint::mod()-1);
		mint e = mint(g).pow((mint::mod()-1)>>cnt2), ie = e.inv();
		for(int i = cnt2; i >= 2; i--) {
			es[i-2] = e;
			ies[i-2] = ie;
			e *= e;
			ie *= ie;
		}
		mint now(1);
		for(int i = 0; i < cnt2-2; i++) {
			sum_e[i] = es[i] * now;
			now *= ies[i];
		}
	}
	for(int ph = 1; ph <= h; ph++) {
		int w = 1<<(ph-1), p = 1<<(h-ph);
		mint now(1);
		for(int s = 0; s < w; s++) {
			int offset = s << (h-ph+1);
			for(int i = 0; i < p; i++) {
				mint l = ary[i+offset];
				mint r = ary[i+offset+p] * now;
				ary[i+offset] = l+r;
				ary[i+offset+p] = l-r;
			}
			now *= sum_e[__builtin_ctz(~(unsigned int)(s))];
		}
	}
}

template<class mint, is_modint_t<mint>* = nullptr>
void id11(vector<mint> &ary) {
	static constexpr int g = primitive_root<mint::mod()>;
	int n = int(ary.size());
	int h = id5(n);

	static bool first = true;
	static mint sum_ie[30];
	if(first) {
		first = false;
		mint es[30], ies[30];
		int cnt2 = __builtin_ctz(mint::mod()-1);
		mint e = mint(g).pow((mint::mod()-1)>>cnt2), ie = e.inv();
		for(int i = cnt2; i >= 2; i--) {
			es[i-2] = e;
			ies[i-2] = ie;
			e *= e;
			ie *= ie;
		}
		mint now(1);
		for(int i = 0; i < cnt2-2; i++) {
			sum_ie[i] = ies[i] * now;
			now *= es[i];
		}
	}
	for(int ph = h; ph >= 1; ph--) {
		int w = 1<<(ph-1), p = 1<<(h-ph);
		mint inow(1);
		for(int s = 0; s < w; s++) {
			int offset = s<<(h-ph+1);
			for(int i = 0; i < p; i++) {
				mint l = ary[i+offset];
				mint r = ary[i+offset+p];
				ary[i+offset] = l+r;
				ary[i+offset+p] = (uint64_t)(mint::mod() + l.x - r.x) * inow.x;
			}
			inow *= sum_ie[__builtin_ctz(~(unsigned int)(s))];
		}
	}
}

template<class mint, is_modint_t<mint>* = nullptr>
vector<mint> convolution(vector<mint> a, vector<mint> b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};
	if(min(n, m) <= 60) {
		if(n < m) {
			swap(n, m);
			swap(a, b);
		}
		vector<mint> ans(n+m-1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans[i+j] += a[i] * b[j];
			}
		}
		return ans;
	}
	int z = 1<<id5(n+m-1);
	a.resize(z);
	id4(a);
	b.resize(z);
	id4(b);
	for(int i = 0; i < z; i++) {
		a[i] *= b[i];
	}
	id11(a);
	a.resize(n+m-1);
	mint iz = mint(z).inv();
	for(int i = 0; i < n+m-1; i++) a[i] *= iz;
	return a;
}

template<unsigned int mod = id0, class T, enable_if_t<is_integral<T>::value>* = nullptr>
vector<T> convolution(const vector<T> &a, const vector<T> &b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};

	using Mint = mint<mod>;
	vector<Mint> a2(n), b2(m);
	for(int i = 0; i < n; i++) {
		a2[i] = Mint(a[i]);
	}
	for(int i = 0; i < m; i++) {
		b2[i] = Mint(b[i]);
	}
	vector<Mint> c2 = convolution<Mint>(move(a2), move(b2));
	vector<T> c(n+m-1);
	for(int i = 0; i < n+m-1; i++) c[i] = c2[i].x;
	return c;
}

vector<int64_t> id6(const vector<int64_t> &a, vector<int64_t> &b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};

	static constexpr uint64_t MOD1 = 754974721;  

	static constexpr uint64_t MOD2 = 167772161;  

	static constexpr uint64_t MOD3 = 469762049;  

	static constexpr uint64_t id2 = MOD2 * MOD3;
	static constexpr uint64_t id10 = MOD1 * MOD3;
	static constexpr uint64_t id1 = MOD1 * MOD2;
	static constexpr uint64_t id9 = MOD1 * MOD2 * MOD3;

	static constexpr uint64_t i1 = id3(id2, MOD1).second;
	static constexpr uint64_t i2 = id3(id10, MOD2).second;
	static constexpr uint64_t i3 = id3(id1, MOD3).second;

	vector<int64_t> c1 = convolution<MOD1>(a, b);
	vector<int64_t> c2 = convolution<MOD2>(a, b);
	vector<int64_t> c3 = convolution<MOD3>(a, b);

	vector<int64_t> c(n+m-1);
	for(int i = 0; i < n+m-1; i++) {
		uint64_t x = 0;
		x += (c1[i] * i1) % MOD1 * id2;
		x += (c2[i] * i2) % MOD2 * id10;
		x += (c3[i] * i3) % MOD3 * id1;
		int64_t diff = c1[i] - safe_mod(int64_t(x), int64_t(MOD1));
		if(diff < 0) diff += MOD1;
		static constexpr uint64_t offset[5] = {0, 0, id9, 2*id9, 3*id9};
		x -= offset[diff%5];
		c[i] = x;
	}
	return c;
}



template<class Float, enable_if_t<is_floating_point<Float>::value>* = nullptr>
void id4(vector<complex<Float>>& ary) {
	int n = int(ary.size());
	int h = id5(n);

	using Complex = complex<Float>;
	static bool first = true;
	static Complex sum_e[30];
	if(first) {
		first = false;
		Complex now = 1.0;
		for(int i = 0; i < 28; i++) {
			Complex es = polar(Float(1.0), Float(PI)/(1<<(i+1)));
			sum_e[i] = es * now;
			now *= conj(es);
		}
	}
	for(int ph = 1; ph <= h; ph++) {
		int w = 1<<(ph-1), p = 1<<(h-ph);
		Complex now = Complex(1.0, 0);
		for(int s = 0; s < w; s++) {
			int offset = s<<(h-ph+1);
			for(int i = 0; i < p; i++) {
				Complex l = ary[i+offset];
				Complex r = ary[i+offset+p] * now;
				ary[i+offset] = l+r;
				ary[i+offset+p] = l-r;
			}
			now *= sum_e[__builtin_ctz(~(unsigned int)(s))];
		}
	}
}

template<class Float, enable_if_t<is_floating_point<Float>::value>* = nullptr>
void id11(vector<complex<Float>> &ary) {
	int n = int(ary.size());
	int h = id5(n);

	using Complex = complex<Float>;
	static bool first = true;
	static Complex sum_ie[30];
	if(first) {
		first = false;
		Complex now = 1.0;
		for(int i = 0; i < 28; i++) {
			Complex es = polar(Float(1.0), Float(PI)/(1<<(i+1)));
			sum_ie[i] = conj(es) * now;
			now *= es;
		}
	}
	for(int ph = h; ph >= 1; ph--) {
		int w = 1<<(ph-1), p = 1<<(h-ph);
		Complex inow = Complex(1.0, 0);
		for(int s = 0; s < w; s++) {
			int offset = s<<(h-ph+1);
			for(int i = 0; i < p; i++) {
				Complex l = ary[i+offset];
				Complex r = ary[i+offset+p];
				ary[i+offset] = l+r;
				ary[i+offset+p] = (l-r) * inow;
			}
			inow *= sum_ie[__builtin_ctz(~(unsigned int)(s))];
		}
	}
	Complex in(1.0/n, 0);
	for(int i = 0; i < n; i++) ary[i] *= in;
}

template<class Complex, enable_if_t<is_complex<Complex>::value>* = nullptr>
vector<Complex> convolution(vector<Complex> a, vector<Complex> b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};
	if(min(n, m) <= 60) {
		if(n < m) {
			swap(n, m);
			swap(a, b);
		}
		vector<Complex> ans(n+m-1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans[i+j] += a[i] * b[j];
			}
		}
		return ans;
	}
	int z = 1<<id5(n+m-1);
	a.resize(z);
	id4(a);
	b.resize(z);
	id4(b);
	for(int i = 0; i < z; i++) {
		a[i] *= b[i];
	}
	id11(a);
	a.resize(n+m-1);
	return a;
}

template<class Float, enable_if_t<is_floating_point<Float>::value>* = nullptr>
vector<Float> convolution(vector<Float> &a, vector<Float> &b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};

	using Complex = complex<Float>;
	vector<Complex> a2(n), b2(m);
	for(int i = 0; i < n; i++) a2[i] = Complex(a[i], 0);
	for(int i = 0; i < m; i++) b2[i] = Complex(b[i], 0);
	vector<Complex> c2 = convolution(move(a2), move(b2));
	vector<Float> c(n+m-1);
	for(int i = 0; i < n+m-1; i++) c[i] = c2[i].real();
	return c;
}
















} 






struct UnionFind {
  vector<int> par; 

  UnionFind(int n=AL):par(n, -1) {} 

  int root(int x) { 

    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
  }
  bool unite(int x, int y) { 

    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  bool same(int x, int y) {return root(x) == root(y);} 

  int size(int x) {return -par[root(x)];} 

};




string s, t;
int n, m;
bitset<AL> check;
UnionFind Graph[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> t;
  n = s.size();
  m = t.size();
  reverse(all(t));
  rep(i, AL) {
    rep(j, AL) if(i != j) {
      vector<ll> a(n), b(m);
      rep(k, n) if(s[k] == 'a'+i) a[k]++;
      rep(k, m) if(t[k] == 'a'+j) b[k]++;
      auto c = fft::convolution(a, b);
      for(int ii = m-1; ii < n; ii++) if(c[ii]) {
        Graph[ii].unite(i, j);
      }
    }
  }
  for(int i = m-1; i < n; i++) {
    int cnt = 0;
    rep(j, AL) if(Graph[i].root(j) == j) cnt++;
    cout << AL-cnt << (i == n-1?'\n':' ');
  }
}