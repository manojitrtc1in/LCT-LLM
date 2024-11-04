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

using namespace std;
#define ll long long
#define ull unsigned long long
#define rrep(i,m,n) for(ll (i)=(ll)(m);(i)>=(ll)(n);(i)--)
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
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
void WarshallFloyd(Graph& G, Matrix& d) {

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
	ll num;
public:
	UnionFind(int size) : data(size, -1), num(size) { }
	bool unite(int x, int y) {

		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		num -= (x != y);
		return x != y;
	}
	bool findSet(int x, int y) {

		return root(x) == root(y);
	}
	int root(int x) {

		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	ll size(int x) {

		return -data[root(x)];
	}
	ll numSet() {

		return num;
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





void divisor(ll n, vector<ll>& ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
}

void prime_factorization(ll n, vector<P>& ret) {
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



template< typename flow_t >
struct Dinic {
	const flow_t INF;

	struct edge {
		int to;
		flow_t cap;
		int rev;
		bool isrev;
		int idx;
		edge(int to,flow_t cap,int rev,bool isrev,int idx):to(to),cap(cap),rev(rev),isrev(isrev),idx(idx){}
	};

	vector< vector< edge > > graph;
	vector< int > min_cost, iter;

	Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

	void add_edge(int from, int to, flow_t cap, int idx = -1) {
		graph[from].emplace_back(edge( to, cap, (int)graph[to].size(), false, idx ));
		graph[to].emplace_back(edge( from, 0, (int)graph[from].size() - 1, true, idx ));
	}

	bool bfs(int s, int t) {
		min_cost.assign(graph.size(), -1);
		queue< int > que;
		min_cost[s] = 0;
		que.push(s);
		while (!que.empty() && min_cost[t] == -1) {
			int p = que.front();
			que.pop();
			for (auto& e : graph[p]) {
				if (e.cap > 0 && min_cost[e.to] == -1) {
					min_cost[e.to] = min_cost[p] + 1;
					que.push(e.to);
				}
			}
		}
		return min_cost[t] != -1;
	}

	flow_t dfs(int idx, const int t, flow_t flow) {
		if (idx == t) return flow;
		for (int& i = iter[idx]; i < graph[idx].size(); i++) {
			edge& e = graph[idx][i];
			if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
				flow_t d = dfs(e.to, t, min(flow, e.cap));
				if (d > 0) {
					e.cap -= d;
					graph[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	flow_t max_flow(int s, int t) {
		flow_t flow = 0;
		while (bfs(s, t)) {
			iter.assign(graph.size(), 0);
			flow_t f = 0;
			while ((f = dfs(s, t, INF)) > 0) flow += f;
		}
		return flow;
	}

	void output() {
		for (int i = 0; i < graph.size(); i++) {
			for (auto& e : graph[i]) {
				if (e.isrev) continue;
				auto& rev_e = graph[e.to][e.rev];
				cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	constexpr ll mod = 998244353;

	ll n, m;
	cin >> n >> m;
	vector<string> a(n);
	REP(i, n)cin >> a[i];
	ll ans = 0;
	REP(i, n)REP(j, m)if (a[i][j] == '#')ans++;
	Dinic<int> g(2 * n * m - n - m + 2);






	REP(i, n * (m - 1))g.add_edge(i + 1, 2 * n * m - n - m + 1, 1);
	REP(i, m * (n - 1)) g.add_edge(0, i + 1 + n * (m - 1), 1);
	REP(i, n)REP(j, m - 1)if (a[i][j] == '#' && a[i][j + 1] == '#')ans--;
	REP(i, n - 1)REP(j, m)if (a[i][j] == '#' && a[i + 1][j] == '#')ans--;
	REP(i, n)REP(j, m - 1) {
		if (a[i][j] != '#' || a[i][j + 1] != '#')continue;
		ll v = (m - 1) * i + j + 1;
		auto calc = [&](ll i, ll j) {return n * (m - 1) + 1 + m * i + j; };
		if (i != 0) {
			if (a[i - 1][j] == '#')g.add_edge(calc(i - 1, j), v, 1);
			if (a[i - 1][j + 1] == '#')g.add_edge(calc(i - 1, j + 1), v, 1);
		}
		if (i != n - 1) {
			if (a[i + 1][j] == '#')g.add_edge(calc(i, j), v, 1);
			if (a[i + 1][j + 1] == '#')g.add_edge(calc(i, j + 1), v, 1);
		}
	}
	ll f =g.max_flow(0, 2 * n * m - n - m + 1);
	cout << ans + f << "\n";



	return 0;
}