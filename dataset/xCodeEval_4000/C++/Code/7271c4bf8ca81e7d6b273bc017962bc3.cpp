#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;



typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}


struct SegT {
private:
	int sz; vector<P> node;
	const P init_c = { -1,0 };
public:
	void init(vector<P> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	P f(P a, P b) {
		return { a.first,a.second + b.second };
	}
	void update(int k, P a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	P take_xth(int x) {
		int k = 0;
		while (k < sz - 1) {
			int cl = node[2 * k + 1].second;
			if (x < cl) {
				k = 2 * k + 1;
			}
			else {
				k = 2 * k + 2;
				x -= cl;
			}
		}
		return P{ node[k].first,k - (sz - 1) };
	}
	vector<int> take_all() {
		vector<int> res;
		rep(i, sz) {
			if (node[i + sz - 1].second > 0) {
				res.push_back(node[i + sz - 1].first);
			}
		}
		return res;
	}
};


vector<int> ori;
struct edge {
	int to;
};
using edges = vector<edge>;
using Graph = vector<edges>;
struct HLDecomposition {
	struct Chain {
		int depth;
		P parent;

		vector<P> child;

		vector<int> mapfrom;
		vector<int> ids;

		Chain() { ; }
		Chain(vector<int>seq) {
			for (int id : seq) {
				ids.push_back(id);
			}
		}
	};
	Graph baseG;
	vector<Chain> chains;
	vector<P> mapto;

	vector<vector<int>> mapfrom;


	HLDecomposition() { ; }
	HLDecomposition(const Graph& g) {
		baseG = g;
		const int n = baseG.size();
		mapto = vector<P>(n, P{ -1,-1 });
		mapfrom.clear();
		vector<int> sz(n, 0);
		

		

		int start = 0;
		

		size_check_bfs(start, sz);
		decomposition(start, start, 0, 0, 0, sz);
	}
	int depth(int t) {
		return chains[mapto[t].first].depth;
	}

private:
	void size_check_bfs(int start, vector<int>& sz) {
		const int n = baseG.size();
		queue<P> que;
		que.push({ start,start });
		int cnt = 0; vector<int> ord(n, -1);
		while (!que.empty()) {
			int from, parent;
			tie(from, parent) = que.front(); que.pop();
			ord[cnt++] = from;
			for (edge e : baseG[from]) {
				if (e.to == parent)continue;
				que.push({ e.to,from });
			}
		}
		

		reverse(all(ord));
		rep(i, n) {
			int from = ord[i];
			sz[from] = 1; for (edge e : baseG[from])sz[from] += sz[e.to];
		}
	}
	int decomposition(int from, int parent, int depth, int pnumber, int pindex, const vector<int>& sz) {
		vector<int> seq;
		bfs(from, parent, seq, sz);
		const int c = chains.size();
		chains.push_back(Chain(seq));
		

		chains[c].depth = depth;
		chains[c].parent = { pnumber,pindex };
		rep(i, seq.size()) {
			mapto[seq[i]] = { c,i };
			chains[c].mapfrom.push_back(seq[i]);
		}
		mapfrom.push_back(chains[c].mapfrom);
		rep(i, seq.size()) {
			for (edge e : baseG[seq[i]]) {
				if (mapto[e.to].first != -1)continue;
				int nc = decomposition(e.to, seq[i], depth + 1, c, i, sz);
				chains[c].child.push_back({ nc,i });
			}
		}
		return c;
	}
	void bfs(int from, int parent, vector<int>& seq, const vector<int>& sz) {
		for (;;) {
			seq.push_back(from);
			int best = -1, next = -1;
			for (edge e : baseG[from]) {
				if (e.to == parent)continue;
				if (best < sz[e.to]) {
					best = sz[e.to]; next = e.to;
				}
			}
			if (next == -1)break;
			parent = from; from = next;
		}
	}
	vector<pair<int, P>> all_vertice(int u, int v) {
		vector<pair<int, P>> res;
		if (depth(u) > depth(v))swap(u, v);
		while (depth(v) > depth(u)) {
			res.push_back({ mapto[v].first,{ 0,mapto[v].second + 1 } });
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
		}
		while (mapto[v].first != mapto[u].first) {
			res.push_back({ mapto[v].first,{ 0,mapto[v].second + 1 } });
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
			res.push_back({ mapto[u].first,{ 0,mapto[u].second + 1 } });
			par = chains[mapto[u].first].parent;
			u = mapfrom[par.first][par.second];
		}
		P p = minmax(mapto[v].second, mapto[u].second);
		res.push_back({ mapto[v].first,{ p.first,p.second + 1 } });
		return res;
	}
	vector<pair<int, P>> all_vertice(int v) {
		vector<pair<int, P>> res;
		while (depth(v) > 0) {
			res.push_back({ mapto[v].first,{0,mapto[v].second + 1} });
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
		}
		res.push_back({ mapto[v].first,{0,mapto[v].second + 1} });
		return res;
	}

public:
	vector<int> sz;
	vector<int> cursz;
	vector<SegT> st;
	void pre_add(vector<int> v) {
		sz.resize(chains.size());
		cursz.resize(chains.size());
		rep(i, sz.size()) {
			sz[i] = chains[i].ids.size();
		}
		for (int id : v) {
			vector<pair<int, P>> vs = all_vertice(id);
			for (auto p : vs) {
				sz[p.first]++;
			}
		}
		st.resize(chains.size());
		rep(i, sz.size()) {
			vector<P> ori_(sz[i]);
			int len = chains[i].ids.size();
			cursz[i] = len;
			rep(j, len) {
				int val = ori[chains[i].ids[len - 1 - j]];
				ori_[j] = { val,1 };
			}
			st[i].init(ori_);
		}
	}
	void shift_root(int a) {
		

		vector<int> cs;
		vector<pair<int, P>> vs = all_vertice(a);
		int pre = -1;
		per(j, vs.size()) {
			auto p = vs[j];
			int id = p.first;
			int loc = chains[id].ids.size() - p.second.second;
			P pq = st[id].take_xth(loc);
			st[id].update(pq.second, { -1,0 });
			if (pre >= 0) {
				st[id].update(cursz[id], { pre,1 });
				cursz[id]++;
			}
			pre = pq.first;
		}
		st[0].update(cursz[0], { pre,1 });
		cursz[0]++;
	}
	vector<int> query() {
		vector<int> res(baseG.size());
		rep(i, chains.size()) {
			vector<int> vals = st[i].take_all();
			int len = chains[i].ids.size();
			

			assert(vals.size() == len);
			rep(j, len) {
				res[chains[i].ids[len - 1 - j]] = vals[j];
			}
		}
		return res;
	}
};
struct lcagraph {
private:
	int n;
	vector<vector<int>> G;
	vector<vector<int>> parent;
	vector<int> depth;
	int root;
	int tmp;
public:
	lcagraph(int n_) {
		n = n_;
		G.resize(n);
		parent.resize(n);
		depth.resize(n);
		tmp = 0;
		int cop = n;
		while (cop) {
			tmp++; cop /= 2;
		}
		rep(i, n)parent[i].resize(tmp);
		root = 0;
	}
	lcagraph() {}
	void init(int n_) {
		n = n_;
		G.resize(n);
		parent.resize(n);
		depth.resize(n);
		tmp = 0;
		int cop = n;
		while (cop) {
			tmp++; cop /= 2;
		}
		rep(i, n)parent[i].resize(tmp);
		root = 0;
	}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void dfs(int id, int fr, int d) {
		parent[id][0] = fr;
		depth[id] = d;
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (to == fr)continue;
			dfs(to, id, d + 1);
		}
	}
	void complete(int r = 0) {
		root = r;
		dfs(root, -1, 0);
		rep(j, tmp - 1)rep(i, n) {
			if (parent[i][j] < 0)parent[i][j + 1] = -1;
			else parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}
	int lca(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int k = 0; k < tmp; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[v][k];
			}
		}
		if (u == v)return u;
		for (int k = tmp - 1; k >= 0; k--) {
			if (parent[u][k] != parent[v][k]) {
				u = parent[u][k];
				v = parent[v][k];
			}
		}
		return parent[u][0];
	}
	int dep(int x) {
		return depth[x];
	}
	int dist(int x, int y) {
		int l = lca(x, y);
		return depth[x] + depth[y] - 2 * depth[l];
	}
};


void solve() {
	int n; cin >> n;
	ori.resize(n);
	rep(i, n) {
		cin >> ori[i]; ori[i]--;
	}
	lcagraph lc(n);
	vector<vector<int>> G(n);
	Graph g(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back({ b });
		g[b].push_back({ a });
		G[a].push_back(b);
		lc.add_edge(a, b);
	}
	lc.complete();
	HLDecomposition hld(g);
	vector<int> rev(n);
	rep(i, n) {
		rev[ori[i]] = i;
	}
	vector<int> depth(n);
	vector<int> par(n, -1);
	{
		queue<int> q; q.push(0);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int to : G[v]) {
				depth[to] = depth[v] + 1;
				q.push(to);
				par[to] = v;
			}
		}
	}
	int chk = n - 1;
	ll sk = 0;
	rep(i, n) {
		int loc = rev[i];
		bool exi = false;
		for (int to : G[loc]) {
			if (ori[to] > ori[loc]) {
				exi = true;
			}
		}
		sk += depth[loc];
		if (exi) {
			chk = i; break;
		}
	}
	vector<int> adds;
	for (int i = chk; i >= 0; i--) {
		adds.push_back(rev[i]);
	}
	hld.pre_add(adds);
	for (int id : adds) {
		hld.shift_root(id);
	}
	vector<int> a = hld.query();
	

	bool valid = true;
	int tmp = 0;
	function<void(int)> dfs = [&](int id) {
		if (a[id] != tmp)valid = false;
		tmp++;
		vector<P> tos;
		for (int to : G[id]) {
			tos.push_back({ a[to],to });
		}
		sort(all(tos));
		for (P p : tos) {
			int to = p.second;
			dfs(to);
		}
	};
	dfs(0);
	int cur = rev[chk];
	while (true) {
		int mi = mod;
		int nex = -1;
		for (int to : G[cur]) {
			if (ori[to] > ori[cur]) {
				if (ori[to] < mi) {
					mi = ori[to];
					nex = to;
				}
			}
		}
		if (nex < 0)break;
		swap(ori[cur], ori[nex]);
		cur = nex;
	}
	

	rep(i, n)rev[ori[i]] = i;
	cur = 0;
	for (int i = 0; i <= chk; i++) {
		int to = rev[i];
		

		if (lc.lca(cur, to) != cur)valid = false;
		cur = par[to];
	}
	vector<int> b = a;
	rep(i, chk + 1)b[rev[i]] = i;
	if (cur >= 0) {
		vector<int> lasts;
		while (cur != 0) {
			lasts.push_back(cur);
			cur = par[cur];
		}
		lasts.push_back(0);
		reverse(all(lasts));
		rep(i, lasts.size()) {
			b[lasts[i]] = chk + 1 + i;
		}
		

		rep(i, n)if (ori[i] != b[i]) {
			valid = false;
		}
	}
	if (valid) {
		cout << "YES\n";
		cout << sk << "\n";
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << a[i] + 1;
		}
		cout << "\n";
	}
	else {
		cout << "NO\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	

	

	

	

	solve();
	return 0;
}