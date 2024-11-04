#include <bits/stdc++.h>
using namespace std;










#define db(x) 0
#define db2(x, y) 0
#define db3(x, y, z) 0
#define dbv(v) 0
#define dba(a, n) 0
typedef long long ll;
typedef long double ld;
struct Tree {
	struct Edge {
		int cost;
		int id;
	};
	int n;
	vector<Edge> edges;
	vector<vector<pair<int, int>>> adj;
	Tree() {}
	Tree(int _n) : n(_n), adj(n + 1) {}
	template <typename... T>
	int addEdge(int from, int to, const T&... e) {
		int id = edges.size();
		adj[from].emplace_back(to, id);
		adj[to].emplace_back(from, id);
		edges.push_back({e...});
		return id;
	}
	vector<int> depth, pv, pe, pre, endpre, preseq, siz;
	int logn;
	vector<vector<int>> anc;
	struct Jump {
		int mx;
		void init(Tree& g, int v) {
			Edge& e = g.edges[g.pe[v]];
			mx = e.cost;
		}
		void combine(const Jump& x, const Jump& a) { 

			mx = max(x.mx, a.mx);
		}
	};
	vector<vector<Jump>> jump;
	void dfs(int x, int p = -1) {
		siz[x] = 1;
		pre[x] = preseq.size();
		preseq.push_back(x);
		for (auto& e : adj[x]) {
			int y = e.first, eid = e.second;
			if (y == p) continue;
			depth[y] = depth[x] + 1;
			pv[y] = x;
			pe[y] = eid;
			dfs(y, x);
			siz[x] += siz[y];
		}
		endpre[x] = (int)preseq.size() - 1; 

	}
	void init(int root = 1) {
		siz = vector<int>(n + 1);
		depth = vector<int>(n + 1);
		pv = vector<int>(n + 1, -1);
		pe = vector<int>(n + 1, -1);
		pre = vector<int>(n + 1, -1);
		endpre = vector<int>(n + 1, -1);
		preseq.clear();
		dfs(root);
		logn = 31 - __builtin_clz(n);
		anc = vector<vector<int>>(n + 1, vector<int>(logn + 1));
		for (int i = 1; i <= n; ++i) anc[i][0] = pv[i];
		for (int p = 1; p <= logn; ++p)
			for (int i = 1; i <= n; ++i)
				anc[i][p] = anc[i][p - 1] == -1 ? -1 : anc[anc[i][p - 1]][p - 1];
		jump = vector<vector<Jump>>(n + 1, vector<Jump>(logn + 1));
		for (int i = 1; i <= n; ++i)
			if (anc[i][0] != -1) jump[i][0].init(*this, i);
		for (int p = 1; p <= logn; ++p)
			for (int i = 1; i <= n; ++i)
				if (anc[i][p] != -1)
					jump[i][p].combine(jump[i][p - 1], jump[anc[i][p - 1]][p - 1]);
	}
	bool isAnc(int a, int b) {
		return pre[a] <= pre[b] && endpre[a] >= endpre[b];
	}
	int getChildTowards(int a, int sub) {
		int dh = depth[sub] - depth[a] - 1;
		for (int p = logn; p >= 0; --p)
			if (dh & (1 << p)) sub = anc[sub][p];
		return sub;
	}
	int getLca(int a, int b) {
		if (isAnc(a, b)) return a;
		if (isAnc(b, a)) return b;
		for (int p = logn; p >= 0; --p)
			if (anc[a][p] != -1 && !isAnc(anc[a][p], b))
				a = anc[a][p];
		a = anc[a][0];
		return a;
	}
	

	void jumpUp(int a, int ancestor, function<void(Jump&)> f) {
		assert(isAnc(ancestor, a));
		int up = depth[a] - depth[ancestor];
		for (int p = logn; p >= 0; --p)
			if (up & (1 << p)) {
				f(jump[a][p]);
				a = anc[a][p];
			}
	}
	vector<int> chainRoot, chainBottom;
	void dfsSiz(int x, int p = -1) {
		for (auto it = adj[x].begin(); it != adj[x].end(); ++it)
			if (it->first == p) {
				adj[x].erase(it);
				break;
			}
		siz[x] = 1;
		for (auto& e : adj[x]) {
			int y = e.first;
			dfsSiz(y, x);
			siz[x] += siz[y];
			if (siz[y] > siz[adj[x][0].first]) swap(e, adj[x][0]);
		}
	}
	void dfsHld(int x, int hldroot) {
		chainRoot[x] = hldroot;
		chainBottom[hldroot] = x;
		for (auto& e : adj[x]) {
			int y = e.first;
			dfsHld(y, y == adj[x][0].first ? hldroot : y);
		}
	}
	struct Chain {
		vector<int> vs;
		

		void init(Tree& g, int bot, int top) {
			vs.clear();
			for (int x = bot; x != g.pv[top]; x = g.pv[x])
				vs.push_back(x);
		}
	};
	vector<Chain> chains;
	

	

	

	

	

	void moveUp(int x, int y, function<void(Chain&, int, int)> f) {
		for (;;) {
			int z = chainRoot[x];
			bool isLastChain = z == chainRoot[y];
			f(chains[chainRoot[x]], x, isLastChain ? y : z);
			if (isLastChain) break;
			x = pv[z];
		}
	}
	

	

	void initHld(int root = 1) {
		siz = vector<int>(n + 1);
		dfsSiz(root); 

		init(root); 

		chainRoot = vector<int>(n + 1);
		chainBottom = vector<int>(n + 1);
		dfsHld(root, root);
		chains = vector<Chain>(n + 1);
		for (int i = 1; i <= n; ++i) {
			if (chainRoot[i] != i) continue;
			chains[i].init(*this, chainBottom[i], i);
		}
	}
	vector<pair<ll, pair<int, int>>> getMiniTree(vector<int> vs) {
		

		

		auto cmppre = [&](int a, int b) {
			return pre[a] < pre[b];
		};
		sort(vs.begin(), vs.end(), cmppre);
		int origsiz = vs.size();
		for (int j = 0; j + 1 < origsiz; ++j)
			vs.push_back(getLca(vs[j], vs[j + 1]));
		sort(vs.begin(), vs.end(), cmppre);
		vs.resize(unique(vs.begin(), vs.end()) - vs.begin()); 

		stack<int> st;
		vector<pair<ll, pair<int, int>>> miniEdges; 

		for (int v : vs) {
			while (!st.empty() && endpre[st.top()] < endpre[v]) st.pop();
			if (!st.empty()) {
				int u = st.top();
				ll cost = 1; 

				miniEdges.push_back({cost, {v, u}});
			}
			st.push(v);
		}
		return miniEdges;
	}
};
using Chain = Tree::Chain;
using Jump = Tree::Jump;
struct SegTree {
	struct Node {
		ll x = 0; 



		Node() {}
		

		void apply(int s, int e, ll v) {
			x += v;


		}
	};
	inline Node combine(Node a, Node b) {
		Node res;
		res.x = max(a.x, b.x);
		return res;
	}
	inline void push(int sn, int s, int e) {












	}
	int start, end;
	vector<Node> tree;
	void build(int sn, int s, int e) {
		if (s == e) {
			

			return;
		}
		int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
		build(lsn, s, m);
		build(rsn, m + 1, e);
		tree[sn] = combine(tree[lsn], tree[rsn]);
	}
	template <typename T>
	void build(int sn, int s, int e, vector<T>& v) {
		if (s == e) {
			tree[sn].x = v[s];
			return;
		}
		int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
		build(lsn, s, m, v);
		build(rsn, m + 1, e, v);
		tree[sn] = combine(tree[lsn], tree[rsn]);
	}
	template <typename... T>
	void update(int sn, int s, int e, int qs, int qe, const T&... v) {
		if (qs <= s && e <= qe) {
			tree[sn].apply(s, e, v...);
			return;
		}
		int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
		push(sn, s, e);
		if (qs <= m) update(lsn, s, m, qs, qe, v...);
		if (qe > m) update(rsn, m + 1, e, qs, qe, v...);
		tree[sn] = combine(tree[lsn], tree[rsn]);
	}
	Node query(int sn, int s, int e, int qs, int qe) {
		if (qs <= s && e <= qe) return tree[sn];
		int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
		push(sn, s, e);
		if (qe <= m) return query(lsn, s, m, qs, qe);
		if (qs > m) return query(rsn, m + 1, e, qs, qe);
		return combine(query(lsn, s, m, qs, qe), query(rsn, m + 1, e, qs, qe));
	}
	SegTree(int n) : SegTree(0, n - 1) {}
	SegTree(int _start, int _end) : start(_start), end(_end) {
		int n = end - start + 1;
		int maxs = n == 1 ? 2 : 1 << (33 - __builtin_clz(n - 1));
		tree.resize(maxs);
		build(1, start, end);
	}
	template <typename T>
	SegTree(vector<T>& v) {
		int n = v.size();
		int maxs = n == 1 ? 2 : 1 << (33 - __builtin_clz(n - 1));
		tree.resize(maxs);
		start = 0;
		end = n - 1;
		build(1, start, end, v);
	}
	Node query(int qs, int qe) {
		return query(1, start, end, qs, qe);
	}
	Node query(int p) {
		return query(1, start, end, p, p);
	}
	template <typename... T>
	void update(int qs, int qe, const T&... v) {
		update(1, start, end, qs, qe, v...);
	}
};
int mstPar[100005];
int root(int a) {
	if (a == mstPar[a]) return a;
	return mstPar[a] = root(mstPar[a]);
}
bool inMst[1000005];
multiset<int> ews[100005];
vector<int> vrem[100005], vadd[100005];
int ans[1000005];
Tree g;
void solve(int x, int p = -1) {
	for (auto& e : g.adj[x]) {
		int y = e.first;
		if (y == p) continue;
		solve(y, x);
		if (ews[y].size() > ews[x].size()) {
			swap(ews[y], ews[x]);
		}
		for (int z : ews[y]) {
			ews[x].insert(z);
		}
		ews[y].clear();
	}
	for (int z : vadd[x]) {
		ews[x].insert(z);
	}
	for (int z : vrem[x]) {
		ews[x].erase(ews[x].find(z));
	}
	if (p == -1) {
		assert(ews[x].empty());
	} else {
		dbv(ews[x]);
		auto& e = g.edges[g.pe[x]];
		int eid = e.id;
		db(eid);
		ans[eid] = 1000000000;
		if (!ews[x].empty()) {
			assert(*ews[x].begin() >= e.cost);
			ans[eid] = *ews[x].begin();
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	g = Tree(n);
	vector<pair<int, int>> edges(m);
	vector<pair<int, pair<int, int>>> origEdges(m);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		origEdges[i] = {w, {a, b}};
		edges[i] = {w, i};
	}
	sort(edges.begin(), edges.end());
	iota(mstPar, mstPar + n + 1, 0);
	int mstCnt = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, w, eid;
		tie(w, eid) = edges[i];
		tie(a, b) = origEdges[eid].second;
		int ra = root(a);
		int rb = root(b);
		if (ra == rb) continue;
		mstPar[ra] = rb;
		db(eid);
		g.addEdge(a, b, w, eid);
		inMst[eid] = true;
		++mstCnt;
	}
	assert(mstCnt == n - 1);
	

	g.initHld();
	for (int i = 0; i < m; ++i) {
		int a, b, w = origEdges[i].first;
		tie(a, b) = origEdges[i].second;
		if (!inMst[i]) {
			int lca = g.getLca(a, b);
			vadd[a].push_back(w);
			vadd[b].push_back(w);
			vrem[lca].push_back(w);
			vrem[lca].push_back(w);
		}
	}
	solve(1);
	vector<int> a(n);
	for (int i = 2; i <= n; ++i) {
		a[g.pre[i]] = g.edges[g.pe[i]].cost;
	}
	SegTree st(a);
	for (int i = 0; i < m; ++i) {
		int a, b;
		tie(a, b) = origEdges[i].second;
		if (!inMst[i]) {
			int lca = g.getLca(a, b);
			int ret = 0;
			auto f = [&](Chain& chain, int x, int y) {
				int prey = g.pre[y];
				if (y == lca) ++prey;
				if (g.pre[x] < prey) return;
				ret = max(ret, (int)st.query(prey, g.pre[x]).x);
			};
			g.moveUp(a, lca, f);
			g.moveUp(b, lca, f);
			ans[i] = ret;




		}
	}
	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
}

