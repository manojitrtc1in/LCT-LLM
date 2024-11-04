#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<limits>
#include<complex>
#include<array>
#include<numeric>
#include<functional>
#include<random>


using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define all(hoge) (hoge).begin(),(hoge).end()
#define llsize(c) ((ll)c.size())
typedef pair<ll, ll> P;
P operator+(const P a, P b) { return P(a.first + b.first, a.second + b.second); }
P operator-(const P a, P b) { return P(a.first - b.first, a.second - b.second); }


constexpr long double m_pi = 3.1415926535897932L;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 61;
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

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }

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

ll max_flow_dfs(Graph& G, ll v, ll t, ll f, vector<bool>& used)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		Edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = max_flow_dfs(G, e.to, t, min(f, e.cap), used);
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
		ll f = max_flow_dfs(G, s, t, INF, used);
		if (f == 0) {
			return flow;
		}
		flow += f;
	}
}

void BellmanFord(Graph& G, ll s, Array& d, Array& negative) {

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
Array Dijkstra(Graph& g, ll s) {

	Array ret(g.size(), INF);
	ret[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ ret[s], s });
	while (!q.empty()) {
		auto [d, v] = q.top();
		q.pop();
		if (ret[v] < d)continue;
		for (auto e : g[v]) {
			if (chmin(ret[e.to], ret[v] + e.cap)) q.push({ ret[e.to], e.to });
		}
	}
	return ret;
}
Matrix WarshallFloyd(Graph& g) {

	Matrix ret(g.size(), Array(g.size(), INF));
	REP(i, ret.size())ret[i][i] = 0;
	REP(i, g.size()) {
		for (auto e : g[i])chmin(ret[i][e.to], e.cap);
	}
	REP(i, g.size()) {
		REP(j, g.size()) {
			REP(k, g.size()) {
				if (ret[j][i] != INF && ret[i][k] != INF)chmin(ret[j][k], ret[j][i] + ret[i][k]);
			}
		}
	}
	return ret;
}
bool tsort(Graph& graph, vector<int>& order) {

	int n = graph.size(), k = 0;
	vector<int> in(n);
	for (auto& es : graph)
		for (auto& e : es)in[e.to]++;
	priority_queue<int, vector<int>, greater<int>> que;
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
	int n;
public:
	UnionFind(int size) : data(size, -1), n(size) { }
	bool merge(int x, int y) {

		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		n -= (x != y);
		return x != y;
	}
	bool same(int x, int y) {

		return root(x) == root(y);
	}
	int root(int x) {

		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {

		return -data[root(x)];
	}
	int num() {

		return n;
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
class FenwickTree {
	vector< T > data;
	int n;
	int p;
public:
	FenwickTree(int n) :n(n) {
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





template<typename T>
vector<T> divisor(T n) {
	vector<T> ret;
	for (T i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

template<typename T>
vector<pair<T, int>> prime_factorization(T n) {
	vector<pair<T, int>> ret;
	for (T i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back({ i,0 });
			while (n % i == 0) {
				n /= i;
				ret[ret.size() - 1].second++;
			}
		}
	}
	if (n != 1)ret.push_back({ n,1 });
	return ret;
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



constexpr ll mod = 998244353;



template<typename T, typename E, typename F, typename G, typename H, typename P>
class LazySegmentTree {
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
	LazySegmentTree(vector<T> v, T id_t, E id_e, F f, G g, H h, P p) :
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



class HeavyLightDecomposition {
private:
	Graph& g;
	int n, root;
	vector<int> sz, par, in, out, head, rev, dep;
	void dfs_sz(int v, int p) {
		sz[v] = 1, par[v] = p;
		for (auto& e : g[v]) {
			if (e.to == p)swap(e, g[v].back());
			if (e.to == p)continue;
			dep[e.to] = dep[v] + 1;
			dfs_sz(e.to, v);
			sz[v] += sz[e.to];
			if (sz[e.to] > sz[g[v][0].to])swap(e, g[v][0]);
		}
	}
	void dfs_hld(int v, int p, int& t) {
		in[v] = t++; rev[in[v]] = v;
		for (auto e : g[v]) {
			if (e.to == p)continue;
			head[e.to] = (e.to == g[v][0].to ? head[v] : e.to);
			dfs_hld(e.to, v, t);
		}
		out[v] = t;
	}
public:
	HeavyLightDecomposition(Graph& _g, int _root = 0)
		:g(_g), n(g.size()), root(_root), sz(n), par(n, -1), head(n, -1), in(n), out(n), rev(n), dep(n, 0) {
		dfs_sz(root, -1);
		int t = 0;
		head[root] = root;
		dfs_hld(root, -1, t);
	}
	inline int get_in(int a) { return in[a]; }
	inline int get_sz(int a) { return sz[a]; }
	inline int get_rev(int a) { return rev[a]; }
	inline int get_dep(int a) { return dep[a]; }
	inline int get_par(int a) { return par[a]; }
	int lca(int a, int b) {
		for (;; b = par[head[b]]) {
			if (in[a] > in[b])swap(a, b);
			if (head[a] == head[b])return a;
		}
	}
	P subtree_query(int a) { return { in[a], out[a] }; }
	vector<P> path_query(int a, int b, bool edge = false) {
		vector<P> ret;
		for (;; b = par[head[b]]) {
			if (in[a] > in[b])swap(a, b);
			if (head[a] == head[b])break;
			ret.push_back({ in[head[b]],in[b] + 1 });
		}
		ret.push_back({ in[a] + edge,in[b] + 1 });
		return ret;
	}
};


int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);





	ll n, m;
	cin >> n >> m;
	Graph g(n);
	REP(i, m) {
		ll a, b, c;
		cin >> a >> b >> c;
		add_edge(g, a, b, c, false, 0);
	}

	REP(i, n) {
		Array d(n, INF);
		Array used(n, 0);
		ll v = i, now = 0;
		bool first = true;
		while (v != -1) {
			if (first)first = false;
			else chmin(d[(v + 1) % n], now + 1);
			ll m = now % n;
			for (auto e : g[v]) chmin(d[(e.to + m) % n], now + e.cap);
			v = -1, now = INF;
			REP(j, n)if (used[j] == 0 && chmin(now, d[j]))v = j;
			if (v != -1)used[v] = 1;
		}
		d[i] = 0;
		REP(j, n)cout << d[j] << (j == n - 1 ? "\n" : " ");
	}



	return 0;
}