




















using namespace std;







typedef pair<ll, ll> P;
constexpr long double m_pi = 3.1415926535897932L;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 62;
constexpr long double EPS = 1e-10;
template<typename T> using vector2 = vector<vector<T>>;
template<typename T> using vector3 = vector<vector2<T>>;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
string operator*(const string& s, int k) {
	if (k == 0) return "";
	string p = (s + s) * (k / 2);
	if (k % 2 == 1) p += s;
	return p;
}

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {

	int to, rev; ll cap;
	Edge(int _to, ll _cap, int _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, int from, int to, ll cap, bool revFlag, ll revCap) {

	G[from].push_back(Edge(to, cap, (ll)G[to].size() + (from == to)));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));

}

ll id0(Graph& G, ll v, ll t, ll f, vector<bool>& used)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		Edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = id0(G, e.to, t, min(f, e.cap), used);
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}


ll max_flow(Graph& G, ll s, ll t)

{
	ll flow = 0;
	for (;;) {
		vector<bool> used(G.size());
		REP(i, used.size())used[i] = false;
		ll f = id0(G, s, t, INF, used);
		if (f == 0) {
			return flow;
		}
		flow += f;
	}
}

void id2(Graph& G, ll s, Array& d, Array& negative) {

	d.resize(G.size());
	negative.resize(G.size());
	REP(i, d.size())d[i] = INF;
	REP(i, d.size())negative[i] = false;
	d[s] = 0;
	REP(k, G.size() - 1) {
		REP(i, G.size()) {
			REP(j, G[i].size()) {
				if (d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
					d[G[i][j].to] = d[i] + G[i][j].cap;
				}
			}
		}
	}
	REP(k, G.size() - 1) {
		REP(i, G.size()) {
			REP(j, G[i].size()) {
				if (d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
					d[G[i][j].to] = d[i] + G[i][j].cap;
					negative[G[i][j].to] = true;
				}
				if (negative[i] == true)negative[G[i][j].to] = true;
			}
		}
	}
}
void Dijkstra(Graph& G, ll s, Array& d) {

	d.resize(G.size());
	REP(i, d.size())d[i] = INF;
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		P a = q.top();
		q.pop();
		if (d[a.second] < a.first)continue;
		REP(i, G[a.second].size()) {
			Edge e = G[a.second][i];
			if (d[e.to] > d[a.second] + e.cap) {
				d[e.to] = d[a.second] + e.cap;
				q.push(make_pair(d[e.to], e.to));
			}
		}
	}
}
void id4(Graph& G, Matrix& d) {

	d.resize(G.size());
	REP(i, d.size())d[i].resize(G.size());
	REP(i, d.size()) {
		REP(j, d[i].size()) {
			d[i][j] = ((i != j) ? INF : 0);
		}
	}
	REP(i, G.size()) {
		REP(j, G[i].size()) {
			chmin(d[i][G[i][j].to], G[i][j].cap);
		}
	}
	REP(i, G.size()) {
		REP(j, G.size()) {
			REP(k, G.size()) {
				chmin(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}
bool tsort(Graph& graph, Array& order) {

	int n = graph.size(), k = 0;
	Array in(n);
	for (auto& es : graph)
		for (auto& e : es)in[e.to]++;
	priority_queue<ll, Array, greater<ll>> que;
	REP(i, n)
		if (in[i] == 0)que.push(i);
	while (que.size()) {
		int v = que.top();
		que.pop();
		order.push_back(v);
		for (auto& e : graph[v])
			if (--in[e.to] == 0)que.push(e.to);
	}
	if (order.size() != n)return false;
	else return true;
}
class Lca {
public:
	const int n = 0;
	const int log2_n = 0;
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;

	Lca() {}

	Lca(const Graph& g, int root)
		: n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {
		dfs(g, root, -1, 0);
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < (int)g.size(); v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}

	void dfs(const Graph& g, int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		for (auto& e : g[v]) {
			if (e.to != p) dfs(g, e.to, v, d + 1);
		}
	}

	int get(int u, int v) {
		if (depth[u] > depth[v]) std::swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};

class UnionFind {
	vector<int> data;
	ll _num;
public:
	UnionFind(int size) : data(size, -1), _num(size) { }
	bool merge(int x, int y) {

		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		_num -= (x != y);
		return x != y;
	}
	bool same(int x, int y) {

		return root(x) == root(y);
	}
	int root(int x) {

		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	ll size(int x) {

		return -data[root(x)];
	}
	ll num() {

		return _num;
	}
};

template<typename T, typename F>
class SegmentTree {
private:
	T identity;
	F merge;
	ll n;
	vector<T> dat;
public:
	SegmentTree(F f, T id, vector<T> v) :merge(f), identity(id) {
		int _n = v.size();
		n = 1;
		while (n < _n)n *= 2;
		dat.resize(2 * n - 1, identity);
		REP(i, _n)dat[n + i - 1] = v[i];
		for (int i = n - 2; i >= 0; i--)dat[i] = merge(dat[i * 2 + 1], dat[i * 2 + 2]);
	}
	SegmentTree(F f, T id, int _n) :merge(f), identity(id) {
		n = 1;
		while (n < _n)n *= 2;
		dat.resize(2 * n - 1, identity);
	}
	void set_val(int i, T x) {
		i += n - 1;
		dat[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] = merge(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}
	T query(int l, int r) {
		T left = identity, right = identity;
		l += n - 1; r += n - 1;
		while (l < r) {
			if ((l & 1) == 0)left = merge(left, dat[l]);
			if ((r & 1) == 0)right = merge(dat[r - 1], right);
			l = l / 2;
			r = (r - 1) / 2;
		}
		return merge(left, right);
	}
};

template< typename T >
class id3 {
	vector< T > data;
	int n;
	int p;
public:
	id3(int n) :n(n) {
		data.resize(n + 1LL, 0);
		p = 1;
		while (p < data.size())p *= 2;
	}
	T sum(int k) {
		T ret = 0;
		for (; k > 0; k -= k & -k) ret += data[k];
		return (ret);
	}

	T sum(int a, int b) { return sum(b) - sum(a); }


	void add(int k, T x) {
		for (++k; k <= n; k += k & -k) data[k] += x;
	}

	int lower_bound(ll w) {
		if (w <= 0)return -1;
		int x = 0;
		for (int k = p / 2; k > 0; k /= 2) {
			if (x + k <= n && data[x + k] < w)w -= data[x + k], x += k;
		}
		return x;
	}
};





void divisor(ll n, vector<ll>& ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
}

void id5(ll n, vector<P>& ret) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back({ i,0 });
			while (n % i == 0) {
				n /= i;
				ret[ret.size() - 1].second++;
			}
		}
	}
	if (n != 1)ret.push_back({ n,1 });
}


inline ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

inline ll mod_inv(ll x, ll mod) {
	return mod_pow(x, mod - 2, mod);
}

class Combination {
public:
	Array fact;
	Array fact_inv;
	ll mod;
	

	ll nCr(ll n, ll r) {
		if (n < r)return 0;
		if (n < mod)return ((fact[n] * fact_inv[r] % mod) * fact_inv[n - r]) % mod;

		ll ret = 1;
		while (n || r) {
			ll _n = n % mod, _r = r % mod;
			n /= mod; r /= mod;
			(ret *= nCr(_n, _r)) %= mod;
		}
		return ret;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * fact_inv[n - r]) % mod;
	}
	ll nHr(ll n, ll r) {
		return nCr(r + n - 1, r);
	}
	Combination(ll _n, ll _mod) {
		mod = _mod;
		ll n = min(_n + 1, mod);
		fact.resize(n);
		fact[0] = 1;
		REP(i, n - 1) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		fact_inv.resize(n);
		fact_inv[n - 1] = mod_inv(fact[n - 1], mod);
		for (int i = n - 1; i > 0; i--) {
			fact_inv[i - 1] = fact_inv[i] * i % mod;
		}
	}
};

ll popcount(ll x) {
	x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
	x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
	x = (x & 0x0F0F0F0F0F0F0F0F) + (x >> 4 & 0x0F0F0F0F0F0F0F0F);
	x = (x & 0x00FF00FF00FF00FF) + (x >> 8 & 0x00FF00FF00FF00FF);
	x = (x & 0x0000FFFF0000FFFF) + (x >> 16 & 0x0000FFFF0000FFFF);
	x = (x & 0x00000000FFFFFFFF) + (x >> 32 & 0x00000000FFFFFFFF);

	return x;
}


template<typename T, typename E, typename F, typename G, typename H, typename P>
class id1 {
private:
	const T identity_t;
	const E identity_e;
	F f_tt;
	G f_te;
	H f_ee;
	P f_ep;

	vector<T> dat;
	vector<E> lazy;
	int n;
	void eval(int k, int len) {
		if (lazy[k] == identity_e)return;
		if (k < n - 1) {
			lazy[2 * k + 1] = f_ee(lazy[2 * k + 1], lazy[k]);
			lazy[2 * k + 2] = f_ee(lazy[2 * k + 2], lazy[k]);
		}
		dat[k] = f_te(dat[k], f_ep(lazy[k], len));
		lazy[k] = identity_e;
	}
	void update(int a, int b, E x, int k, int l, int r) {
		eval(k, r - l);
		if (a <= l && r <= b) {
			lazy[k] = f_ee(lazy[k], x);
			eval(k, r - l);
		}
		else if (a < r && l < b) {
			update(a, b, x, k * 2 + 1, l, (l + r) / 2);
			update(a, b, x, k * 2 + 2, (l + r) / 2, r);
			dat[k] = f_tt(dat[2 * k + 1], dat[2 * k + 2]);
		}
	}
	T query(int a, int b, int k, int l, int r) {
		eval(k, r - l);
		if (r <= a || b <= l)return identity_t;
		else if (a <= l && r <= b)return dat[k];
		else {
			T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
			T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
			return f_tt(vl, vr);
		}
	}
public:
	id1(vector<T> v, T id_t, E id_e, F f, G g, H h, P p) :
		identity_t(id_t), identity_e(id_e), f_tt(f), f_te(g), f_ee(h), f_ep(p) {
		n = 1;
		while (n < v.size())n *= 2;
		dat.resize(2 * n - 1, identity_t);
		lazy.resize(2 * n - 1, identity_e);
		REP(i, v.size())dat[n + i - 1] = v[i];
		for (int i = n - 2; i >= 0; i--)dat[i] = f_tt(dat[i * 2 + 1], dat[i * 2 + 2]);

	}
	void update(int a, int b, E x) { update(a, b, x, 0, 0, n); }
	T query(int a, int b) { return query(a, b, 0, 0, n); }
};



Matrix mIdentity(ll n) {
	Matrix A(n, Array(n));
	for (int i = 0; i < n; ++i) A[i][i] = 1;
	return A;
}

Matrix mMul(const Matrix& A, const Matrix& B,ll M) {
	Matrix C(A.size(), Array(B[0].size()));
	for (int i = 0; i < C.size(); ++i)
		for (int k = 0; k < A[i].size(); ++k)
			for (int j = 0; j < C[i].size(); ++j)
				(C[i][j] += (A[i][k] % M) * (B[k][j] % M)) %= M;
	return C;
}


Matrix mPow(const Matrix& A, ll e , ll M) {
	return e == 0 ? mIdentity(A.size()) :
		e % 2 == 0 ? mPow(mMul(A, A, M), e / 2, M) : mMul(A, mPow(A, e - 1, M), M);
}


template<ll mod, ll root>

class NTT {
private:
	template<typename T>
	inline void bit_reverse(vector<T>& a) {
		int n = a.size();
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k > (i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}
	}
	void _ntt(vector<long long>& a, int sign) {
		const int n = a.size();
		assert((n ^ (n & -n)) == 0); 


		long long tmp = (mod - 1) * mod_pow((ll)n, mod - 2, mod) % mod; 

		long long h = mod_pow(root, tmp, mod); 

		if (sign == -1) h = mod_pow(h, mod - 2, mod);

		bit_reverse(a);

		for (ll m = 1; m < n; m <<= 1) {
			const ll m2 = 2 * m;
			long long _base = mod_pow((ll)h, (ll)(n / m2), mod);
			long long _w = 1;
			for (int x = 0; x < m; ++x) {
				for (ll s = x; s < n; s += m2) {
					long long u = a[s];
					long long d = (a[s + m] * _w) % mod;
					a[s] = (u + d) % mod;
					a[s + m] = (u - d + mod) % mod;
				}
				_w = (_w * _base) % mod;
			}
		}
	}

	void ntt(vector<long long>& input) { _ntt(input, 1); }

	void intt(vector<long long>& input) {
		_ntt(input, -1);
		const long long n_inv = mod_pow((ll)input.size(), mod - 2, mod);
		for (auto& x : input) x = (x * n_inv) % mod;
	}
public:
	

	vector<long long> convolution(const vector<long long>& a, const vector<long long>& b) {
		int result_size = a.size() + b.size() - 1;
		int n = 1; while (n < result_size) n <<= 1;

		vector<long long> _a = a, _b = b;
		_a.resize(n, 0);
		_b.resize(n, 0);

		ntt(_a);
		ntt(_b);
		for (int i = 0; i < n; ++i) _a[i] = (_a[i] * _b[i]) % mod;

		intt(_a);

		_a.resize(result_size);
		return _a;
	}
};




int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	constexpr ll mod = 998244353;

	ll n, k;
	cin >> n >> k;
	Matrix a(n);
	REP(i, n) {
		ll t;
		cin >> t;
		REP(j, t) {
			ll tmp;
			cin >> tmp;
			if (a[i].size() < k)a[i].push_back(tmp);
		}
	}
	Array w(n, 0);
	REP(i, n)w[i] = accumulate(all(a[i]), 0LL);
	ll ans = 0;
	auto solve = [&](auto solve, Array& dp, ll l, ll r)->void {
		if (r - l == 1) {
			ll sum = 0;
			REP(i, a[l].size() + 1) {
				chmax(ans, dp[k - i] + sum);
				if (i != a[l].size())sum += a[l][i];
			}
			return;
		}
		ll m = (r + l) / 2;
		Array dp2 = dp;
		rep(i, m, r) {
			for (int j = k - 1; j >= 0; j--)if (a[i].size() + j <= k)chmax(dp2[j + a[i].size()], dp2[j] + w[i]);
		}
		solve(solve, dp2, l, m);
		rep(i, l, m) {
			for (int j = k - 1; j >= 0; j--)if (a[i].size() + j <= k)chmax(dp[j + a[i].size()], dp[j] + w[i]);
		}
		solve(solve, dp, m, r);
	};
	Array dp(k + 1, 0);
	solve(solve, dp, 0, n);
	cout << ans << "\n";

	return 0;
}