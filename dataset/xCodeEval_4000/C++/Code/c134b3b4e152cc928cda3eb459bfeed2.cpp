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
typedef pair<ll, ll> P;
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
				if (d[j][i] != INF && d[i][k] != INF)chmin(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
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
	int num;
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
	int size(int x) {

		return -data[root(x)];
	}
	int numSet() {

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


namespace FastFourierTransform {
	using real = double;

	struct C {
		real x, y;

		C() : x(0), y(0) {}

		C(real x, real y) : x(x), y(y) {}

		inline C operator+(const C& c) const { return C(x + c.x, y + c.y); }

		inline C operator-(const C& c) const { return C(x - c.x, y - c.y); }

		inline C operator*(const C& c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

		inline C conj() const { return C(x, -y); }
	};

	const real PI = acosl(-1);
	int base = 1;
	vector< C > rts = { {0, 0},
					   {1, 0} };
	vector< int > rev = { 0, 1 };


	void ensure_base(int nbase) {
		if (nbase <= base) return;
		rev.resize(1 << nbase);
		rts.resize(1 << nbase);
		for (int i = 0; i < (1 << nbase); i++) {
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
		}
		while (base < nbase) {
			real angle = PI * 2.0 / (1 << (base + 1));
			for (int i = 1 << (base - 1); i < (1 << base); i++) {
				rts[i << 1] = rts[i];
				real angle_i = angle * (2 * i + 1 - (1 << base));
				rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
			}
			++base;
		}
	}

	void fft(vector< C >& a, int n) {
		assert((n & (n - 1)) == 0);
		int zeros = __builtin_ctz(n);
		ensure_base(zeros);
		int shift = base - zeros;
		for (int i = 0; i < n; i++) {
			if (i < (rev[i] >> shift)) {
				swap(a[i], a[rev[i] >> shift]);
			}
		}
		for (int k = 1; k < n; k <<= 1) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					C z = a[i + j + k] * rts[j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	vector< int64_t > multiply(const vector< int >& a, const vector< int >& b) {
		int need = (int)a.size() + (int)b.size() - 1;
		int nbase = 1;
		while ((1 << nbase) < need) nbase++;
		ensure_base(nbase);
		int sz = 1 << nbase;
		vector< C > fa(sz);
		for (int i = 0; i < sz; i++) {
			int x = (i < (int)a.size() ? a[i] : 0);
			int y = (i < (int)b.size() ? b[i] : 0);
			fa[i] = C(x, y);
		}
		fft(fa, sz);
		C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
		for (int i = 0; i <= (sz >> 1); i++) {
			int j = (sz - i) & (sz - 1);
			C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
			fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
			fa[i] = z;
		}
		for (int i = 0; i < (sz >> 1); i++) {
			C A0 = (fa[i] + fa[i + (sz >> 1)])* t;
			C A1 = (fa[i] - fa[i + (sz >> 1)])* t* rts[(sz >> 1) + i];
			fa[i] = A0 + A1 * s;
		}
		fft(fa, sz >> 1);
		vector< int64_t > ret(need);
		for (int i = 0; i < need; i++) {
			ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	
	string s, t;
	cin >> s >> t;
	ll n = s.size(), m = t.size();
	reverse(all(t));
	vector<UnionFind> uni;
	REP(i, n - m + 1)uni.emplace_back(UnionFind(6));
	REP(i, 6)REP(j, 6) {
	vector<int> a(n, 0), b(m, 0);
		REP(k, n)if (s[k] == 'a' + i)a[k] = 1;
		REP(k, m)if (t[k] == 'a' + j)b[k] = 1;
		auto c = FastFourierTransform::multiply(a, b);
		rep(k, m - 1, n) if (c[k])uni[k - (m - 1)].unite(i, j);
	}
	REP(i, n - m + 1)cout <<  6 - uni[i].numSet() << (i == n - m ? "\n" : " ");


	return 0;
}