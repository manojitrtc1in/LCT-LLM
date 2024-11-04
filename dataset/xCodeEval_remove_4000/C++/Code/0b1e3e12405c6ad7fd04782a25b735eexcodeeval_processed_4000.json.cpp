



















using namespace std;








typedef pair<ll, ll> P;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr long double EPS = 1e-10;
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

	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {

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
void id1(Graph& G, ll s, Array& d, Array& negative) {

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
bool tsort(Graph& graph, vector<int>& order) {

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
class lca {
public:
	const int n = 0;
	const int log2_n = 0;
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;

	lca() {}

	lca(const Graph& g, int root)
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
void visit(const Graph& g, int v, Matrix& scc, stack<ll>& S, Array& inS, Array& low, Array& num, int& time) {
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
		scc.push_back(Array());
		while (1) {
			int w = S.top(); S.pop(); inS[w] = false;
			scc.back().push_back(w);
			if (v == w) break;
		}
	}
}
void id2(const Graph& g, Matrix& scc) {

	const int n = g.size();
	Array num(n), low(n);
	stack<ll> S;
	Array inS(n);
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
class id3 {
public:
	ll n, height;
	vector<ll> dat;

	

	id3(ll _n) {
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
class id6 {
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

	

	id6(ll _n) {
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

template<typename T>
struct RollingHash {
	static const ll base1 = 1007, base2 = 2009;
	static const ll mod1 = 1000000007, mod2 = 1000000009;
	vector<long long> hash1, hash2, power1, power2;

	

	RollingHash(const T& S) {
		ll n = (ll)S.size();
		hash1.assign(n + 1, 0);
		hash2.assign(n + 1, 0);
		power1.assign(n + 1, 1);
		power2.assign(n + 1, 1);
		for (int i = 0; i < n; ++i) {
			hash1[i + 1] = (hash1[i] * base1 + S[i]) % mod1;
			hash2[i + 1] = (hash2[i] * base2 + S[i]) % mod2;
			power1[i + 1] = (power1[i] * base1) % mod1;
			power2[i + 1] = (power2[i] * base2) % mod2;
		}
	}

	

	inline pair<long long, long long> get(int l, int r) const {
		long long res1 = hash1[r] - hash1[l] * power1[r - l] % mod1;
		if (res1 < 0) res1 += mod1;
		long long res2 = hash2[r] - hash2[l] * power2[r - l] % mod2;
		if (res2 < 0) res2 += mod2;
		return { res1, res2 };
	}

	

	inline int getLCP(int a, int b) const {
		int len = min((int)hash1.size() - a, (int)hash1.size() - b);
		int low = 0, high = len;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (get(a, a + mid) != get(b, b + mid)) high = mid;
			else low = mid;
		}
		return low;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	ll n;
	cin >> n;
	vector<P> a(n);
	vector<string> s(n);
	ll sum = 0;
	REP(i, n){
		cin >> s[i];
		sum += s[i].size();
		RollingHash<string> r(s[i]);
		a[i] = r.get(0, s[i].size());
	}

	ll ans = sum + n - 1;

	map<vector<P>, vector<P>> mp;
	REP(i, n) {
		vector<P> sub;
		rep(j, i, n) {
			sub.push_back(a[j]);
			mp[sub].push_back({ i,j + 1 });
			if (sub.size() >= n / 2)break;
		}
	}
	for (auto& itr : mp) {
		if (itr.second.size() < 2)continue;
		sort(all(itr.second));
		ll r = 0;
		ll cnt = 0;
		REP(i, itr.second.size()) {
			if (r <= itr.second[i].first)cnt++, r = itr.second[i].second;
		}
		ll temp = sum + n - 1;
		for (int i = itr.second[0].first; i < itr.second[0].second; i++)temp -= (s[i].size()) * cnt;
		temp += cnt;
		chmin(ans, temp);
	}
	cout << ans << "\n";
	


	return 0;
}
