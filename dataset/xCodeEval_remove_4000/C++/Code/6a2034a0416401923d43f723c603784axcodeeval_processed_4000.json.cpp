




















using namespace std;







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

	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
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
void id6(Graph& G, Matrix& d) {

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
void visit(const Graph& g, int v, vector<vector<int>>& scc, stack<int>& S, vector<int>& inS, vector<int>& low,vector<int>& num, int& time) {
	low[v] = num[v] = ++time;
	S.push(v); inS[v] = true;
	FOR(e, g[v]) {
		int w = e->to;
		if (num[w] == 0) {
			visit(g, w, scc, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		}
		else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		scc.push_back(vector<int>());
		while (1) {
			int w = S.top(); S.pop(); inS[w] = false;
			scc.back().push_back(w);
			if (v == w) break;
		}
	}
}
void id4(const Graph& g, vector<vector<int>>& scc) {

	const int n = g.size();
	vector<int> num(n), low(n);
	stack<int> S;
	vector<int> inS(n);
	int time = 0;
	REP(u, n) if (num[u] == 0)
		visit(g, u, scc, S, inS, low, num, time);
}

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
	SegmentTree(F f, T id,vector<T> v) :merge(f), identity(id) {
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
class id5 {
public:
	ll n, height;
	vector<ll> dat;

	

	id5(ll _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<ll>(2 * n - 1, 0);
	}

	

	void add(ll i, ll x) {
		i += n - 1; 

		dat[i] += x;
		while (i > 0) { 

			i = (i - 1) / 2;
			dat[i] += x;
		}
	}
	

	ll sum(ll l, ll r) {
		ll ret = 0;
		l += n - 1; r += n - 1;
		while (l < r) {
			if ((l & 1) == 0)ret += dat[l];
			if ((r & 1) == 0)ret += dat[r - 1];
			l = l / 2;
			r = (r - 1) / 2;
		}
		return ret;
	}
};
class id8 {
private:

	ll _find(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l)return INF;    

		if (a <= l && r <= b)return dat[k];   

		else {
			ll s1 = _find(a, b, 2 * k + 1, l, (l + r) / 2); 

			ll s2 = _find(a, b, 2 * k + 2, (l + r) / 2, r); 

			return min(s1, s2);
		}
	}
public:
	ll n, height;
	vector<ll> dat;

	

	id8(ll _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<ll>(2 * n - 1, INF);
	}

	

	void update(ll i, ll x) {
		i += n - 1; 

		dat[i] = x;
		while (i > 0) { 

			i = (i - 1) / 2;
			dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}

	

	ll find(ll a, ll b) {
		return _find(a, b, 0, 0, n);
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

void id7(ll n, vector<P>& ret) {
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


ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
while (n > 0) {
	if (n & 1) res = res * x % mod;
	x = x * x % mod;
	n >>= 1;
}
return res;
}

ll mod_inv(ll x, ll mod) {
	return mod_pow(x, mod - 2, mod);
}

class Combination {
public:
	Array fact;
	Array inv;
	ll mod;
	ll mod_inv(ll x) {
		ll n = mod - 2LL;
		ll res = 1LL;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	

	ll nCr(ll n, ll r) {
		if (n < r)return 0;
		if (n < mod)return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod;

		ll ret = 1;
		while (n || r) {
			ll _n = n % mod, _r = r % mod;
			n /= mod; r /= mod;
			(ret *= nCr(_n, _r)) %= mod;
		}
		return ret;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * inv[n - r]) % mod;
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
		inv.resize(n);
		inv[n - 1] = mod_inv(fact[n - 1]);
		for (int i = n - 1; i > 0; i--) {
			inv[i - 1] = inv[i] * i % mod;
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


class id1 {
	Graph& g;
	ll n;
	vector<int> sz, dead;
	ll dfs(ll v, ll par) {
		sz[v] = 1;
		for (auto e : g[v])
			if (e.to != par && !dead[e.to]) sz[v] += dfs(e.to, v);
		return sz[v];
	}

	void find(ll v, ll par, ll tmp, Array& cs) {
		ll ok = 1;
		for (auto e : g[v]) {
			if (e.to == par || dead[e.to]) continue;
			find(e.to, v, tmp, cs);
			ok &= (sz[e.to] <= tmp / 2);
		}
		ok &= (tmp - sz[v] <= tmp / 2);
		if (ok) cs.push_back(v);
	};
	
public:
	id1(Graph& _g) :g(_g),n(g.size()),sz(n, 1), dead(n, 0) {}

	vector<ll> build(ll r) {
		ll tmp = dfs(r, -1);
		vector<ll> cs;
		find(r, -1, tmp, cs);
		return cs;
	}

	inline ll get_sz(ll v) { return sz[v]; }

	inline void disable(ll v) { dead[v] = 1; }

	inline void enable(ll v) { dead[v] = 0; }

	inline ll alive(ll v) { return !dead[v]; }
};

template<class T> class id3 {
private:
	struct Line {
		T a, b;
		Line(T a = 0, T b = 0) : a(a), b(b) { }
		T get(T x) {
			return a * x + b;
		}
	};
	struct Node {
		Line l;
		Node* lhs, * rhs;
		Node(Line l) : l(l), lhs(nullptr), rhs(nullptr) {}
	};
	const T MIN, MAX, INF;
	Node* root;
	Node* insert(Node* p, T left, T right, Line& l) {
		

		if (!p) return new Node(l);
		

		if (p->l.get(left) <= l.get(left) && p->l.get(right) <= l.get(right)) return p;
		if (p->l.get(left) >= l.get(left) && p->l.get(right) >= l.get(right)) {
			p->l = l;
			return p;
		}
		

		T mid = (left + right) / 2;
		if (p->l.get(mid) > l.get(mid)) swap(p->l, l);
		

		if (p->l.get(left) >= l.get(left)) p->lhs = insert(p->lhs, left, mid, l);
		else p->rhs = insert(p->rhs, mid + 1, right, l);
		return p;
	}
	T query(Node* p, T left, T right, T x) {
		if (!p) return INF;
		if (left == right) return p->l.get(x);
		T mid = (left + right) / 2;
		if (x <= mid) return min(p->l.get(x), query(p->lhs, left, mid, x));
		else return min(p->l.get(x), query(p->rhs, mid + 1, right, x));
	}
public:
	

	id3(T MIN, T MAX, T INF) : MIN(MIN), MAX(MAX), INF(INF), root(nullptr) { }
	

	void insert(T a, T b) {
		Line l(a, b);
		root = insert(root, MIN, MAX, l);
	}
	

	T query(T x) {
		return query(root, MIN, MAX, x);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	ll n;
	cin >> n;
	Graph g(n);
	REP(i, n - 1) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		add_edge(g, a, b, 1, true, 1);
	}
	Array a(n);
	REP(i, n)cin >> a[i];
	queue<ll> que;
	que.push(0);
	id1 c(g);
	ll ans = 0;
	while (que.size()) {
		ll r = c.build(que.front())[0];
		c.disable(r);
		que.pop();
		vector<P> p;
		auto dfs = [&](auto dfs, ll v, ll par,ll d,ll sum,ll pre,ll suf,id3<ll>& cht) -> void{
			sum += a[v];
			suf += sum;
			pre += (d + 1) * a[v];
			chmax(ans, -cht.query(d) + suf);
			chmax(ans, pre);
			p.push_back({ sum + a[r],pre });
			for(auto e:g[v]){
				if (e.to == par || c.alive(e.to) == false)continue;				
				dfs(dfs, e.to, v, d + 1, sum, pre, suf, cht);
			}
		};
		id3<ll> cht_l(0, 1LL << 30, INF);
		cht_l.insert(-a[r],- a[r]);
		REP(i, g[r].size()) {
			ll to = g[r][i].to;
			if (c.alive(to) == false)continue;
			que.push(to);
			dfs(dfs, to, -1, 1, 0, a[r], 0, cht_l);
			while (p.size())cht_l.insert(-p.back().first, -p.back().second), p.pop_back();
		}
		id3<ll> cht_r(0, 1LL << 30, INF);
		cht_r.insert(-a[r], -a[r]);
		for (int i = g[r].size() - 1; i >= 0; i--) {
			ll to = g[r][i].to;
			if (c.alive(to) == false)continue;
			dfs(dfs, to, -1, 1, 0, a[r], 0, cht_r);
			while (p.size())cht_r.insert(-p.back().first, -p.back().second), p.pop_back();
		}
	}

	cout << ans << "\n";

	return 0;
}