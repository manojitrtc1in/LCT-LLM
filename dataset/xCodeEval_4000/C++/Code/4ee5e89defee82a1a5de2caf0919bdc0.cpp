#ifndef HIDDEN_IN_VS 




#define _CRT_SECURE_NO_WARNINGS



#include <bits/stdc++.h>
using namespace std;



using ll = long long; 

using pii = pair<int, int>;	using pll = pair<ll, ll>;	using pil = pair<int, ll>;	using pli = pair<ll, int>;
using vi = vector<int>;		using vvi = vector<vi>;		using vvvi = vector<vvi>;
using vl = vector<ll>;		using vvl = vector<vl>;		using vvvl = vector<vvl>;
using vb = vector<bool>;	using vvb = vector<vb>;		using vvvb = vector<vvb>;
using vc = vector<char>;	using vvc = vector<vc>;		using vvvc = vector<vvc>;
using vd = vector<double>;	using vvd = vector<vd>;		using vvvd = vector<vvd>;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
using Graph = vvi;



const double PI = acos(-1);
const vi dx4 = { 1, 0, -1, 0 }; 

const vi dy4 = { 0, 1, 0, -1 };
const vi dx8 = { 1, 1, 0, -1, -1, -1, 0, 1 }; 

const vi dy8 = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001; const ll INFL = 4004004004004004004LL;
const double EPS = 1e-12; 




struct fast_io { fast_io() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } fastIOtmp;



#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define distance (int)distance
#define Yes(b) {cout << ((b) ? "Yes\n" : "No\n");}
#define YES(b) {cout << ((b) ? "YES\n" : "NO\n");}
#define rep(i, n) for(int i = 0, i##_len = int(n); i < i##_len; ++i) 

#define repi(i, s, t) for(int i = int(s), i##_end = int(t); i <= i##_end; ++i) 

#define repir(i, s, t) for(int i = int(s), i##_end = int(t); i >= i##_end; --i) 

#define repe(v, a) for(const auto& v : (a)) 

#define repea(v, a) for(auto& v : (a)) 

#define repb(set, d) for(int set = 0; set < (1 << int(d)); ++set) 

#define repp(a) sort(all(a)); for(bool a##_perm = true; a##_perm; a##_perm = next_permutation(all(a))) 

#define smod(n, m) ((((n) % (m)) + (m)) % (m)) 

#define uniq(a) {sort(all(a)); (a).erase(unique(all(a)), (a).end());} 

#define EXIT(a) {cout << (a) << endl; exit(0);} 




template <class T> inline ll pow(T n, int k) { ll v = 1; rep(i, k) v *= n; return v; }
template <class T> inline bool chmax(T& M, const T& x) { if (M < x) { M = x; return true; } return false; } 

template <class T> inline bool chmin(T& m, const T& x) { if (m > x) { m = x; return true; } return false; } 




template <class T, class U> inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template <class T> inline istream& operator>>(istream& is, vector<T>& v) { repea(x, v) is >> x; return is; }
template <class T> inline vector<T>& operator--(vector<T>& v) { repea(x, v) --x; return v; }
template <class T> inline vector<T>& operator++(vector<T>& v) { repea(x, v) ++x; return v; }



#ifdef _MSC_VER
#include "local.hpp"


#else
#define popcount (int)__builtin_popcount
#define popcountll (int)__builtin_popcountll
#define lsb __builtin_ctz
#define lsbll __builtin_ctzll
#define msb(n) (31 - __builtin_clz(n))
#define msbll(n) (63 - __builtin_clzll(n))
#define gcd __gcd
#define dump(...)
#define dumpel(v)
#define input_from_file(f)
#define output_to_file(f)
#endif

#endif 

































template <class S, S(*add)(S, S), S(*o)(), S(*mul)(S, S), S(*e)()>
struct Matrix {
	int m, n; 

	vector<vector<S>> v; 


	

	Matrix() {}
	Matrix(const int& m_, const int& n_) : m(m_), n(n_), v(m_, vector<S>(n_, o())) {}
	Matrix(const int& n_) : m(n_), n(n_), v(n_, vector<S>(n_, o())) {
		rep(i, n) v[i][i] = e();
	}
	Matrix(const vector<vector<S>>& a) : m(sz(a)), n(sz(a[0])), v(a) {}

	

	Matrix(const Matrix& b) = default;
	Matrix& operator=(const Matrix& b) = default;

	

	friend istream& operator>>(istream& is, Matrix& a) {
		rep(i, a.m) rep(j, a.n) is >> a.v[i][j];
		return is;
	}

	

	vector<S> const& operator[](int i) const { return v[i]; }
	vector<S>& operator[](int i) { return v[i]; }

	

	bool operator==(const Matrix& b) const { return m == b.m && n == b.n && v == b.v; }
	bool operator!=(const Matrix& b) const { return !(*this == b); }

	

	Matrix& operator+=(const Matrix& b) {
		rep(i, m) rep(j, n) v[i][j] = add(v[i][j], b.v[i][j]);
		return *this;
	}
	Matrix operator+(const Matrix& b) const { Matrix a = *this; return a += b; }

	

	Matrix operator*(const S& c) const {
		Matrix res(*this);
		rep(i, m) rep(j, n) res.v[i][j] = mul(res.v[i][j], c);
		return res;
	}
	friend Matrix operator*(const S& c, const Matrix& a) {
		Matrix res(a);
		rep(i, a.m) rep(j, a.n) res.v[i][j] = mul(c, res.v[i][j]);
		return res;
	}

	

	vector<S> operator*(const vector<S>& x) const {
		vector<S> y(m);
		rep(i, m) rep(j, n)	y[i] = add(y[i], mul(v[i][j], x[j]));
		return y;
	}

	

	friend vector<S> operator*(const vector<S>& x, const Matrix& a) {
		vector<S> y(a.n);
		rep(i, a.m) rep(j, a.n) y[j] = add(y[j], mul(x[i], a.v[i][j]));
		return y;
	}

	

	Matrix operator*(const Matrix& b) const {
		Matrix res(m, b.n);
		rep(i, res.m) rep(j, res.n) rep(k, n)
			res.v[i][j] = add(res.v[i][j], mul(v[i][k], b.v[k][j]));
		return res;
	}

	

	Matrix pow(ll d) const {
		


		Matrix res(n), pow2(*this);
		while (d > 0) {
			if ((d & 1) != 0) res = res * pow2;
			pow2 = pow2 * pow2;
			d /= 2;
		}
		return res;
	}

#ifdef _MSC_VER
	friend ostream& operator<<(ostream& os, const Matrix& a) {
		rep(i, a.m) {
			rep(j, a.n) os << a.v[i][j] << " ";
			os << endl;
		}
		return os;
	}
#endif
};




using S803 = ll;
S803 add803(S803 x, S803 y) { return min(x, y); }
S803 o803() { return INFL; }
S803 mul803(S803 x, S803 y) { return x + y; }
S803 e803() { return 0; }
#define Min_plus_semiring S803, add803, o803, mul803, e803





template <class S, S(*op)(S, S), S(*e)()>
struct Segtree {
	


	

	int n;
	int actual_n; 


	

	

	

	

	vector<S> v;

	

	Segtree() : n(0), actual_n(0) {}

	

	Segtree(int n_) : actual_n(n_) {
		

		int pow2 = 1;
		while (pow2 < n_) {
			pow2 *= 2;
		}
		n = pow2;

		

		v = vector<S>(2 * n, e());
	}

	

	Segtree(vector<S>& v_) : Segtree(sz(v_)) {
		


		

		rep(i, sz(v_)) {
			v[i + n] = v_[i];
		}

		

		repir(i, n - 1, 1) {
			v[i] = op(v[i * 2], v[i * 2 + 1]);
		}
	}

	

	void set(int i, S x) {
		


		

		i += n;

		

		v[i] = x;

		

		while (i > 1) {
			i /= 2;
			v[i] = op(v[i * 2], v[i * 2 + 1]);
		}
	}

	

	S get(int i) const { return v[i + n]; }

	

	S prod(int l, int r) const {
		


		return prod_rf(l, r, 1, 0, n);
	}

	

	S prod_rf(int l, int r, int k, int kl, int kr) const {
		

		if (kr <= l || r <= kl) {
			return e();
		}

		

		if (l <= kl && kr <= r) {
			return v[k];
		}

		

		S vl = prod_rf(l, r, k * 2, kl, (kl + kr) / 2);
		S vr = prod_rf(l, r, k * 2 + 1, (kl + kr) / 2, kr);
		return op(vl, vr);
	}

	

	S all_prod() const { return prod_rf(0, n, 1, 0, n); }

	

	int max_right(int l, const function<bool(S)>& f) const {
		S x = e();
		return max_right_rf(l, actual_n, x, 1, 0, n, f);
	}

	

	int max_right_rf(int l, int r, S& x, int k, int kl, int kr, const function<bool(S)>& f) const {
		

		if (kr <= l || r <= kl) {
			return r;
		}

		

		if (f(op(x, v[k]))) {
			x = op(x, v[k]);
			return r;
		}

		

		if (k >= n) {
			return k - n;
		}

		

		int pos = max_right_rf(l, r, x, k * 2, kl, (kl + kr) / 2, f);
		if (pos != r) {
			return pos;
		}

		

		return max_right_rf(l, r, x, k * 2 + 1, (kl + kr) / 2, kr, f);
	}

	

	int min_left(int r, const function<bool(S)>& f) const {
		S x = e();
		return min_left_rf(0, r, x, 1, 0, n, f) + 1;
	}

	

	int min_left_rf(int l, int r, S& x, int k, int kl, int kr, const function<bool(S)>& f) const {
		

		if (kr <= l || r <= kl) {
			return l - 1;
		}

		

		if (f(op(v[k], x))) {
			x = op(v[k], x);
			return l - 1;
		}

		

		if (k >= n) {
			return k - n;
		}

		

		int pos = min_left_rf(l, r, x, k * 2 + 1, (kl + kr) / 2, kr, f);
		if (pos != l - 1) {
			return pos;
		}

		

		return min_left_rf(l, r, x, k * 2, kl, (kl + kr) / 2, f);
	}

#ifdef _MSC_VER
	friend ostream& operator<<(ostream& os, Segtree seg) {
		rep(i, seg.actual_n) {
			os << seg.get(i) << " ";
		}
		return os;
	}
#endif
};





using S20 = Matrix<Min_plus_semiring>;
S20 op20(S20 a, S20 b) { return a * b; }
S20 e20() { return Matrix<Min_plus_semiring>(2); }
#define Invmul_monoid S20, op20, e20


int main() {
	input_from_file("input.txt");



	int n;
	cin >> n;

	vi x1(n - 1), y1(n - 1), x2(n - 1), y2(n - 1);
	rep(i, n - 1) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	--x1; --y1; --x2; --y2;

	vector<Matrix<Min_plus_semiring>> mats(n - 2);
	rep(i, n - 2) {
		mats[i] = Matrix<Min_plus_semiring>(2, 2);
		mats[i][0][0] = 1 + abs(y1[i + 1] - y1[i]);
		mats[i][0][1] = 1 + abs((i + 1) - y1[i]) + abs(x2[i + 1] - (i + 1));
		mats[i][1][0] = 1 + abs((i + 1) - x2[i]) + abs(y1[i + 1] - (i + 1));
		mats[i][1][1] = 1 + abs(x2[i + 1] - x2[i]);
	}
	dump(mats);

	Segtree<Invmul_monoid> seg(mats);

	int m;
	cin >> m;

	rep(hoge, m) {
		dump("----------------------------");
		int u1, v1, u2, v2;
		cin >> u1 >> v1 >> u2 >> v2;
		--u1; --v1; --u2; --v2;
		dump(u1, v1, u2, v2);

		int i1 = max(u1, v1);
		int i2 = max(u2, v2);

		if (i1 == i2) {
			ll res = -1;
			if (u1 == u2) res = abs(v1 - v2);
			else if (v1 == v2) res = abs(u1 - u2);
			else res = abs(i1 - min(u1, v1)) + abs(i1 - min(u2, v2));

			cout << res << endl;

			continue;
		}

		if (i1 > i2) {
			swap(u1, u2);
			swap(v1, v2);
			swap(i1, i2);
		}
		dump(u1, v1, u2, v2);

		vl vec1(2);
		if (u1 < v1) {
			vec1[0] = abs(i1 - u1) + abs(y1[i1] - i1);
			vec1[1] = abs(x2[i1] - u1);
		}
		else {
			vec1[0] = abs(y1[i1] - v1);
			vec1[1] = abs(i1 - v1) + abs(x2[i1] - i1);
		}
		dump(vec1);

		vl vec2(2);
		if (u2 < v2) {
			vec2[0] = abs(i2 - u2) + abs(y1[i2 - 1] - i2) + 1;
			vec2[1] = abs(x2[i2 - 1] - u2) + 1;
		}
		else {
			vec2[0] = abs(y1[i2 - 1] - v2) + 1;
			vec2[1] = abs(i2 - v2) + abs(x2[i2 - 1] - i2) + 1;
		}
		dump(vec2);

		auto mat = seg.prod(i1, i2 - 1);
		dump(mat);
		

		

		


		ll res = INFL;
		chmin(res, vec1[0] + mat[0][0] + vec2[0]);
		chmin(res, vec1[0] + mat[0][1] + vec2[1]);
		chmin(res, vec1[1] + mat[1][0] + vec2[0]);
		chmin(res, vec1[1] + mat[1][1] + vec2[1]);

		cout << res << endl;
	}
}
