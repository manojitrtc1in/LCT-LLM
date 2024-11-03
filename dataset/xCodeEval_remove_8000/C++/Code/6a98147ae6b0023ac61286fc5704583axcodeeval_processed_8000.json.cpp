



























using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using ti3 = tuple<int, int, int>;
using vti3 = vector<ti3>;
template<class T, int s>using va = vector<array<T, s>>;
template<class T, class T2> using umap = unordered_map<T, T2>;
template<class T> using uset = unordered_set<T>;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }








template<class T>using heap = priority_queue<T, vector<T>, greater<T>>;
template<class T>using pque = priority_queue<T, vector<T>, function<T(T, T)>>;
template <class T>
inline void id10(size_t & seed, const T & v) {
	hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b97f4a7c15 + (seed << 6) + (seed >> 2);
}
namespace std {
	template<typename S, typename T> struct hash<pair<S, T>> {
		inline size_t operator()(const pair<S, T> & v) const {
			size_t seed = 0;
			id10(seed, v.first);
			id10(seed, v.second);
			return seed;
		}
	};
	

	template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
	struct HashValueImpl {
		static void apply(size_t& seed, Tuple const& tuple) {
			HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
			id10(seed, std::get<Index>(tuple));
		}
	};
	template <class Tuple>
	struct HashValueImpl<Tuple, 0> {
		static void apply(size_t& seed, Tuple const& tuple) {
			id10(seed, std::get<0>(tuple));
		}
	};
	template <typename ... TT>
	struct hash<std::tuple<TT...>> {
		size_t operator()(std::tuple<TT...> const& tt) const {
			size_t seed = 0;
			HashValueImpl<std::tuple<TT...> >::apply(seed, tt);
			return seed;
		}
	};
}
template<class T>int id(vector<T> &a, T b) {
	return lower_bound(ALL(a), b) - a.begin();
}
ll pow(ll base, ll i, ll mod) {
	ll a = 1;
	while (i) {
		if (i & 1) {
			a *= base;
			a %= mod;
		}
		base *= base;
		base %= mod;
		i /= 2;
	}
	return a;
}
ll gcd(ll a, ll b) {
	while (b) {
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b)*b;
}



int popcnt(unsigned long long a) {

	return __builtin_popcountll(a);

	return _mm_popcnt_u64(a);

	return _mm_popcnt_u32(a >> 32) + _mm_popcnt_u32(a);
	a = (a & 0x5555555555555555) + (a >> 1 & 0x5555555555555555);
	a = (a & 0x3333333333333333) + (a >> 2 & 0x3333333333333333);
	a = (a & 0x0f0f0f0f0f0f0f0f) + (a >> 4 & 0x0f0f0f0f0f0f0f0f);
	a = (a & 0x00ff00ff00ff00ff) + (a >> 8 & 0x00ff00ff00ff00ff);
	a = (a & 0x0000ffff0000ffff) + (a >> 16 & 0x0000ffff0000ffff);
	return (a & 0xffffffff) + (a >> 32);

}
int id6(unsigned long long a) {

	return __builtin_ctzll(a);

	unsigned long ret;
	_BitScanForward64(&ret, a);
	return a;

	unsigned long ret;
	if (!(unsigned long)a) {
		_BitScanForward(&ret, a);
		ret += 32;
	}
	else _BitScanForward(&ret, (unsigned long)a);
	return ret;

}
int id7(unsigned long long a) {

	return 63 - __builtin_clzll(a);

	unsigned long ret;
	_BitScanReverse64(&ret, a);
	return a;

	unsigned long ret;
	if (a >> 32) {
		_BitScanReverse(&ret, a);
		ret += 32;
	}
	else _BitScanReverse(&ret, (unsigned long)a);
	return ret;

}
template<class T>
class matrix {
public:
	vector<valarray<T>> obj;
	pair<int, int> s;
public:
	matrix(pair<int, int> size, T e = 0) :matrix(size.first, size.second, e) {}
	matrix(int n, int m = -1, T e = 0) :obj(n, valarray<T>(e, m == -1 ? n : m)), s(n, m == -1 ? n : m) {}
	static matrix e(int n) {
		matrix a = (n);
		for (int i = 0; i < n; i++)a[i][i] = 1;
		return a;
	}
	matrix& operator+=(const matrix &p) {
		if (s != p.s)throw runtime_error("matrix error");
		for (int i = 0; i < s.first; i++)
			for (int j = 0; j < s.second; j++)obj[i][j] += p.obj[i][j];
		return *this;
	}
	matrix operator+(const matrix &p) {
		matrix res(*this);
		return res += p;
	}
	matrix& operator-=(const matrix &p) {
		if (s != p.s)throw runtime_error("matrix error");
		for (int i = 0; i < s.first; i++)
			for (int j = 0; j < s.second; j++)obj[i][j] -= p.obj[i][j];
		return *this;
	}
	matrix operator-(const matrix &p) {
		matrix res(*this);
		return res -= p;
	}
	matrix& operator*=(T p) {
		for (auto &a : obj)
			for (auto &b : a)b *= p;
		return *this;
	}
	matrix operator*(T p) {
		matrix res(*this);
		return res *= p;
	}
	matrix operator*(const matrix &p) {
		if (s.second != p.s.first)throw runtime_error("matrix error");
		matrix ret(s.first, p.s.second);
		for (int i = 0; i < s.first; i++)
			for (int j = 0; j < s.second; j++)ret[i] += obj[i][j] * p.obj[j];
		return ret;
	}
	matrix &operator*=(const matrix &p) {
		return *this = *this*p;
	}
	bool operator==(const matrix&p) {
		if (s != p.s)return 0;
		for (int i = 0; i<s.first; i++)for (int j; j< s.second; j++)if (obj[i][j] != p.obj[i][j])return 0;
		return 1;
	}
	pair<int, int> size() const {
		return s;
	}
	matrix &mod(T m) {
		for (auto &a : obj)
			for (auto &b : a)b %= m;
		return *this;
	}
	valarray<T>& operator[](int t) {
		return obj[t];
	}
	void gauss() {
		if (size().first + 1 != size().second)return;
		rep(i, size().first) {
			int p = i;
			repi(j, i, size().first)if (abs(obj[j][i]) > abs(obj[p][i]))p = j;
			swap(obj[i], obj[p]);
			if (abs(obj[i][i]) < 1e-8)return;

			repi(j, i + 1, size().second)obj[i][j] /= obj[i][i];
			rep(j, size().first) {
				if (i != j) {
					repi(k, i + 1, size().second)obj[j][k] -= obj[j][i] * obj[i][k];
				}
			}
		}
	}
};
template<class T>
std::pair<matrix<T>, vector<int>> id5(matrix<T> a) {
	if (a.size().first != a.size().second)throw runtime_error("matrix error");
	std::vector<int> pi(a.size().first);
	std::iota(ALL(pi), 0);
	valarray<T> tmp(a.size().first);
	for (int i = 0; i < a.size().first; i++) {
		

		

		

		

		

		

		

		

		

		

		std::slice slice(i + 1, a.size().first - i - 1, 1);
		for (int j = i + 1; j < a.size().first; j++) {
			tmp[slice] = a[i][slice];
			tmp *= a[j][i] / a[i][i];
			a[j][slice] -= tmp[slice];
			a[j][i] = a[j][i] / a[i][i];
		}
	}
	return std::make_pair(std::move(a), std::move(pi));
}
template<class T>
matrix<T>id14(pair<matrix<T>, std::vector<int>> a, matrix<T> b) {
	auto pi = std::move(a.second);
	auto A = std::move(a.first);
	if (A.size().first != A.size().second || A.size().first != b.size().first)throw runtime_error("matrix error");
	for (int i = 0; i < A.size().first; i++) {
		std::swap(b[i], b[pi[i]]);
	}
	for (int i = 0; i < A.size().first; i++) {
		for (int j = 0; j < i; j++)b[i] -= A[i][j] * b[j];
	}
	for (int i = A.size().first - 1; i >= 0; i--) {
		for (int j = i + 1; j < A.size().first; j++)b[i] -= A[i][j] * b[j];
		b[i] /= A[i][i];
	}
	return b;
}
template<class T> inline
matrix<T> pow(matrix<T> &base, unsigned long long exp) {
	auto base_(base);
	if (base_.size().first != base_.size().second)throw runtime_error("matrix error");
	matrix<T> res = matrix<T>::e(base_.size().first);
	for (;;) {
		if (exp & 1)res *= base_;
		if (res.obj[0].size() > 100) {
			int a = 0;
		}
		if (!(exp /= 2))break;
		base_ *= base_;
	}
	return res;
}
template<class T> inline
matrix<T> modpow(matrix<T> &base, unsigned long long exp, ll m) {
	auto base_(base);
	if (base.size().first != base_.size().second)throw runtime_error("matrix error");
	matrix<T> res = matrix<T>::e(base_.size().first);
	for (;;) {
		if (exp & 1)(res *= base_).mod(m);
		if (res.obj[0].size() > 100) {
			int a = 0;
		}
		if (!(exp /= 2))break;
		(base_ *= base_).mod(m);
	}
	return res;
}
class unionfind {
	vector<int> par, rank, size_;

public:
	unionfind(int n) :par(n), rank(n), size_(n, 1) {
		iota(ALL(par), 0);
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (rank[x] < rank[y])swap(x, y);
		par[y] = x;
		size_[x] += size_[y];
		if (rank[x] == rank[y])rank[x]++;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return size_[find(x)];
	}
};








































































template<class T, class Func = function<T(T, T)>>
class id15 {
	vector<T> obj;
	int offset;
	Func updater;
	T e;
	int bufsize(int num) {
		int i = 1;
		for (; num >i; i <<= 1);
		offset = i - 1;
		return (i << 1) - 1;
	}
	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return e;
		if (a <= l && r <= b)return obj[k];
		else return updater(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
	}
public:
	void propagate(int a, int b, int k, int l, int r, int p) {
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			obj[k].second += p;
			(obj[k].first *= pow(2, p, (ll)1e9 + 7)) %= (ll)(1e9 + 7);
			return;
		}
		else {
			if (obj[k].second) {
				(obj[k * 2 + 1].first *= pow(2, obj[k].second, (ll)1e9 + 7)) %= (ll)(1e9 + 7);
				(obj[k * 2 + 2].first *= pow(2, obj[k].second, (ll)1e9 + 7)) %= (ll)(1e9 + 7);
				obj[k * 2 + 1].second += obj[k].second;
				obj[k * 2 + 2].second += obj[k].second;
			}
			propagate(a, b, k * 2 + 1, l, (l + r) / 2, p), propagate(a, b, k * 2 + 2, (l + r) / 2, r, p);
			obj[k] = updater(obj[k * 2 + 1], obj[k * 2 + 2]);
		}
	}
	T query(int a, int b) {

		

		return query(a, b, 0, 0, offset + 1);
	}
	void propagate(int a, int b, int p = 1) {

		return propagate(a, b, 0, 0, offset + 1, p);
	}
	void updateall(int l = 0, int r = -1) {
		if (r < 0)r = offset + 1;
		l += offset, r += offset;
		if (l == 0)return;
		do {
			l = l - 1 >> 1, r = r - 1 >> 1;
			for (int i = l; i < r; i++)obj[i] = updater(obj[i * 2 + 1], obj[i * 2 + 2]);
		} while (l);
	}
	void update(int k, const T &a) {
		

		k += offset;
		obj[k] = a;
		while (k) {
			k = k - 1 >> 1;
			obj[k] = updater(obj[k * 2 + 1], obj[k * 2 + 2]);
		}
	}
	id15(int n, T e, const Func &updater = Func()) :obj(bufsize(n), e), e(e), updater(updater) {}
	id15(vector<T> &vec, T e, const Func &updater = Func()) :obj(bufsize(vec.size()), e), e(e), updater(updater) {
		copy(vec.begin(), vec.end(), obj.begin() + offset);
		updateall();
	}
	T& operator[](int n) {
		return obj[n + offset];
	}
};
template<class T = int>
class BIT {

	vector<T> bit;
public:
	BIT(int n) :bit(n + 1, 0) {}
	void add(int i, T x) {
		i++;
		while (i <= bit.size()) {
			bit[i - 1] += x;
			i += i & -i;
		}
	}
	T sum(int i) {
		T s = 0;
		i++;
		while (i) {
			s += bit[i - 1];
			i &= i - 1;
		}
		return s;
	}
};
template<class T>
class rangeadd {
	BIT<T> b0, b1;
	int n;
	rangeadd(int n) :b0(n), b1(n), n(n) {}
	void add(int l, int r, T x) {

		b0.add(l, -x(l - 1));
		b1.add(l, x);
		b0.add(r, x*r);
		b1.add(r, -x);
	}
	T sum(int i) {
		return b0.sum(i) + b1.sum(i)*i;
	}
};
class Flow {
public:
	int V;
	struct edge { int to, cap, rev, cost, add; };
	vector<vector<edge>> G;
	vector<int> level, iter, prevv, preve;
	vector<ll> h, dist;
	void bfs(int s) {
		fill(level.begin(), level.end(), -1);
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (int i = 0; i < G[v].size(); i++) {
				edge &e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f) {
		if (v == t)return f;
		for (int &i = iter[v]; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	ll res = 0;
	int flow = 0;
	int s, t;
	int max_flow(int s, int t, int fmax = numeric_limits<int>::max()) {
		level.resize(V);
		iter.resize(V);
		for (;;) {
			bfs(s);
			if (level[t] < 0)return flow;
			fill(iter.begin(), iter.end(), 0);
			int f;
			while ((f = dfs(s, t, fmax))>0) {
				flow += f;
				fmax -= f;
			}
			if (fmax == 0)return flow;
		}
	}
	typedef pair<ll, int> P;
	ll min_cost_flow(int s, int t, int f) {
		h.resize(V);
		dist.resize(V);
		prevv.resize(V);
		preve.resize(V);
		fill(h.begin(), h.end(), 0);
		while (f > 0) {
			priority_queue<P, vector<P>, greater<P>> que;
			fill(dist.begin(), dist.end(), numeric_limits<int>::max());
			dist[s] = 0;
			que.push({ 0,s });
			while (!que.empty()) {
				P p = que.top(); que.pop();
				int v = p.second;
				if (dist[v] < p.first)continue;
				for (int i = 0; i < G[v].size(); i++) {
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to]>dist[v] + e.cost + h[v] - h[e.to]) {
						dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
						prevv[e.to] = v;
						preve[e.to] = i;
						que.push({ dist[e.to],e.to });
					}
				}
			}
			if (dist[t] == numeric_limits<int>::max()) {
				return -1;
			}
			for (int v = 0; v < V; v++)h[v] += dist[v];

			int d = f;
			for (int v = t; v != s; v = prevv[v]) {
				d = min(d, G[prevv[v]][preve[v]].cap);
			}
			f -= d;
			res += d * h[t];
			for (int v = t; v != s; v = prevv[v]) {
				edge &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return res;
	}
public:
	Flow(int size, int s, int t) :G(size + 1), V(size + 1), s(s), t(t) {
	}
	void add_edge(int from, int to, int cap, int cost = 0) {
		G[from].push_back(edge{ to, cap, (int)G[to].size(),cost,1 });
		G[to].push_back(edge{ from,0,(int)G[from].size() - 1,-cost,0 });
	}
	void remove_edge_max(int from, int to, int cap, int cost = 0) {
		for (auto &x : G[from]) {
			if (!x.add || x.to != to || x.cap + G[to][x.rev].cap != cap || x.cost != cost)continue;
			int prev = flow;
			int cap = G[to][x.rev].cap;
			G[to][x.rev].cap = 0;
			x.cap = 0;
			cap -= max_flow(from, to, cap) - prev;
			max_flow(t, to, cap);
			max_flow(from, s, cap);
			flow = prev - cap;
			break;
		}
	}
	void remove_edge_cost(int from, int to, int cap, int cost = 0) {
		for (auto &x : G[from]) {
			if (!x.add || x.to != to || x.cap + G[to][x.rev].cap != cap || x.cost != cost)continue;
			cost += G[to][x.rev].cap*G[to][x.rev].cost;
			int cap = G[to][x.rev].cap;
			G[to][x.rev].cap = 0;
			x.cap = 0;
			min_cost_flow(from, to, cap);
			break;
		}
	}
	int max_flow() {
		return max_flow(s, t);
	}
	ll min_cost_flow(int f) {
		return min_cost_flow(s, t, f);
	}
};
ll id4(ll a, ll b, ll&x, ll&y) {
	int d = a;
	if (b != 0) {
		d = id4(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
ll mod_inv(ll a, ll m) {
	ll x, y;
	id4(a, m, x, y);
	return(m + x % m) % m;
}
pll id9(const vector<ll>& A, const vll& B, const vll&M) {
	ll x = 0, m = 1;
	for (int i = 0; i < A.size(); i++) {
		ll a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);
		if (b%d != 0)return make_pair(0, -1);
		ll t = b / d * mod_inv(a / d, M[i] / d) % (M[i] / d);
		

		x = x + m * t;
		m *= M[i] / d;
	}
	return make_pair(x%m, m);
}
typedef complex<ld> P;
typedef vector<P> VP;
const ld eps = 1e-11, pi = acos(-1.0);

ld dot(P a, P b) { return real(conj(a) * b); }
ld cross(P a, P b) { return imag(conj(a) * b); }

namespace std {
	bool operator<(const P &a, const P &b) {
		return abs(a.real() - b.real()) < eps ? a.imag() < b.imag() : a.real() < b.real();
	}
}

struct L { P a, b; };

struct C { P p; ld r; };

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;   

	if (cross(b, c) < -eps) return -1; 

	if (dot(b, c) < 0) return 2;       

	if (norm(b) < norm(c)) return -2;  

	return 0;                          

}

bool isis_ll(L l, L m) {

	return abs(cross(l.b - l.a, m.b - m.a)) > eps;
}

bool isis_ls(L l, L s) {
	ld a = cross(l.b - l.a, s.a - l.a);
	ld b = cross(l.b - l.a, s.b - l.a);
	return (a * b < eps);
}

bool isis_lp(L l, P p) {
	return abs(cross(l.b - p, l.a - p)) < eps;
}

bool isis_ss(L s, L t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

P is_ll(L s, L t) { 

	P sv = s.b - s.a, tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

bool isis_sp(L s, P p) {
	return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps;
}

P proj(L l, P p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

ld dist_lp(L l, P p) {
	return abs(p - proj(l, p));
}

ld dist_ll(L l, L m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

ld dist_ls(L l, L s) {
	if (isis_ls(l, s)) return 0;
	return min(dist_lp(l, s.a), dist_lp(l, s.b));
}

ld dist_sp(L s, P p) {
	P r = proj(s, p);
	if (isis_sp(s, r)) return abs(r - p);
	return min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss(L s, L t) {
	if (isis_ss(s, t)) return 0;
	ld a = min(dist_sp(s, t.a), dist_sp(t, s.a));
	ld b = min(dist_sp(s, t.b), dist_sp(t, s.b));
	return min(a, b);
}

VP is_cc(C c1, C c2) {
	VP res;
	ld d = abs(c1.p - c2.p);
	ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
	ld dfr = c1.r * c1.r - rc * rc;
	if (abs(dfr) < eps) dfr = 0.0;
	else if (dfr < 0.0) return res; 

	ld rs = sqrt(dfr);
	P diff = (c2.p - c1.p) / d;
	res.push_back(c1.p + diff * P(rc, rs));
	if (dfr != 0.0) res.push_back(c1.p + diff * P(rc, -rs));
	return res;
}

bool id2(vector<C> vc) {
	VP crs;
	int n = vc.size();
	rep(i, n)rep(j, i)
		for (P p : is_cc(vc[i], vc[j]))
			crs.push_back(p);
	rep(i, n)
		crs.push_back(vc[i].p);
	for (P p : crs) {
		bool valid = true;
		rep(i, n)
			if (abs(p - vc[i].p)>vc[i].r + eps)
				valid = false;
		if (valid) return true;
	}
	return false;
}

VP id11(C c, L l) {
	VP res;
	ld d = dist_lp(l, c.p);
	if (d < c.r + eps) {
		ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); 

		P nor = (l.a - l.b) / abs(l.a - l.b);
		res.push_back(proj(l, c.p) + len * nor);
		res.push_back(proj(l, c.p) - len * nor);
	}
	return res;
}

VP is_sc(C c, L l) {
	VP v = id11(c, l), res;
	for (P p : v)
		if (isis_sp(l, p)) res.push_back(p);
	return res;
}

vector<L> id17(C c, P p) {

	vector<L> ret;
	P v = c.p - p;
	ld d = abs(v);
	ld l = sqrt(norm(v) - c.r * c.r);
	if (std::isnan(l)) { return ret; }
	P v1 = v * P(l / d, c.r / d);
	P v2 = v * P(l / d, -c.r / d);
	ret.push_back(L{ p, p + v1 });
	if (l < eps) return ret;
	ret.push_back(L{ p, p + v2 });
	return ret;
}

vector<L> id8(C c1, C c2) {
	vector<L> ret;
	if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
		P center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
		ret = id17(c1, center);
	}
	if (abs(c1.r - c2.r) > eps) {
		P out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
		vector<L> nret = id17(c1, out);
		ret.insert(ret.end(), ALL(nret));
	}
	else {
		P v = c2.p - c1.p;
		v /= abs(v);
		P q1 = c1.p + v * P(0, 1) * c1.r;
		P q2 = c1.p + v * P(0, -1) * c1.r;
		ret.push_back(L{ q1, q1 + v });
		ret.push_back(L{ q2, q2 + v });
	}
	return ret;
}

ld area(const VP &p) {

	ld res = 0;
	int n = p.size();
	rep(j, n) res += cross(p[j], p[(j + 1) % n]);
	return res / 2;
}

bool is_polygon(L l, VP &g) {
	int n = g.size();
	for (int i = 0; i < n; i++) {
		P a = g[i];
		P b = g[(i + 1) % n];
		if (isis_ss(l, L{ a, b })) return true;
	}
	return false;
}

int id3(const VP &g, P p) {
	bool in = false;
	int n = g.size();
	for (int i = 0; i < n; i++) {
		P a = g[i] - p, b = g[(i + 1) % n] - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
			if (cross(a, b) < 0) in = !in;
		if (abs(cross(a, b)) < eps && dot(a, b) < eps) return 0; 

	}
	if (in) return 1; 

	return -1; 

}

VP id16(VP ps) {
	int n = ps.size();
	int k = 0;
	sort(ps.begin(), ps.end());
	VP ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}

VP id13(const VP &ps, L l) {
	VP Q;
	for (int i = 0; i < (int)ps.size(); i++) {
		P A = ps[i], B = ps[(i + 1) % ps.size()];
		if (ccw(l.a, l.b, A) != -1) Q.push_back(A);
		if (ccw(l.a, l.b, A) * ccw(l.a, l.b, B) < 0)
			Q.push_back(is_ll(L{ A, B }, l));
	}
	return Q;
}
struct id0 {
	vector<int> par, rank, size_,a;

public:
	id0(int n) :par(n), rank(n), size_(n, 1),a(n) {
		iota(ALL(par), 0);
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (rank[x] < rank[y])swap(x, y);
		par[y] = x;
		size_[x] += size_[y];
		cmin(a[x],a[y]);
		if (rank[x] == rank[y])rank[x]++;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return size_[find(x)];
	}
};
template<class T>
class id1 {
	vector<T> obj;
	int offset;
	T e;
	int bufsize(int num) {
		int i = 1;
		for (; num >i; i <<= 1);
		offset = i - 1;
		return (i << 1) - 1;
	}
	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return e;
		if (a <= l && r <= b)return obj[k];
		else {
			T ret(e);
			obj[k].propagate(obj[k * 2 + 1], obj[k * 2 + 2]);
			return ret.merge(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
		}
	}
	void propagateall(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l || l == r - 1)return;
		obj[k].propagate(obj[k * 2 + 1], obj[k * 2 + 2]);
		propagateall(a, b, k * 2 + 1, l, (l + r) / 2);
		propagateall(a, b, k * 2 + 2, (l + r) / 2, r);
	}
	template<class Param>
	T update(int a, int b, int k, int l, int r, const Param& param) {
		if (r <= a || b <= l)return obj[k];
		if (a <= l && r <= b) {
			obj[k].update(param);
			return obj[k];
		}
		obj[k].propagate(obj[k * 2 + 1], obj[k * 2 + 2]);
		return obj[k].merge(update(a, b, k * 2 + 1, l, (l + r) / 2, param), update(a, b, k * 2 + 2, (l + r) / 2, r, param));
	}
public:
	T query(int a, int b) {

		return query(a, b, 0, 0, offset + 1);
	}
	template<class Param>
	void update(int a, int b, Param&& param) {
		update(a, b, 0, 0, offset + 1, param);
	}
	void updateall(int l = 0, int r = -1) {
		if (r < 0)r = offset + 1;
		l += offset, r += offset;
		if (l == 0)return;
		do {
			l = l - 1 >> 1, r = r - 1 >> 1;
			for (int i = l; i < r; i++)obj[i].merge(obj[i * 2 + 1], obj[i * 2 + 2]);
		} while (l);
	}
	void propagateall(int l = 0, int r = -1) {
		if (r < 0)r = offset + 1;
		l += offset, r += offset;
		updateall(l, r, 0, 0, offset + 1);
	}
	
	id1(int n, T e) :obj(bufsize(n), e), e(e) {}
	id1(vector<T> &vec, T e) :obj(bufsize(vec.size()), e), e(e) {
		copy(vec.begin(), vec.end(), obj.begin() + offset);
		updateall();
	}
	T& operator[](int n) {
		return obj[n + offset];
	}
};
class id12 {
	ll min, set;
public:
	ll getmin() {
		return min;
	}
	id12() {
		min = numeric_limits<ll>::max() / 2; set = min;
	}
	id12(ll a, ll b = 0) {
		min = a; set = b;
	}
	void propagate(id12 &a, id12 &b) {
		cmin(a.min, set);
		cmin(b.min, set);
		cmin(a.set, set);
		cmin(b.set, set);
		set = numeric_limits<ll>::max() / 2;
	}
	id12& merge(const id12 &a, const id12 &b) {
		min = std::min(a.min, b.min);
		set = numeric_limits<ll>::max() / 2;
		return *this;
	}
	id12& update(ll k) {
		cmin(min, k);
		cmin(set, k);
		return *this;
	}
};
int main() {
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	vi a1, b1;
	rep(i, n) {
		if (a[i] == 1) {
			a1.assign(a.begin(), a.begin() + i);
			a1.insert(a1.begin(), i + ALL(a));
		}
	}
	rep(i, n) {
		if (a1[i] == 0) {
			a1.erase(a1.begin() + i);
			break;
		}
	}
	rep(i, n) {
		if (b[i] == 1) {
			b1.assign(b.begin(), b.begin() + i);
			b1.insert(b1.begin(), i + ALL(b));
		}
	}
	rep(i, n) {
		if (b1[i] == 0) {
			b1.erase(b1.begin() + i);
			break;
		}
	}
	cout << (a1 == b1 ? "YES" : "NO") << endl;
}



