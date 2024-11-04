

























using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef complex<double> cdouble;

const int INFL = (int)1e9;
const ll INFLL = (ll)1e18;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;


















bool id3(double x, double y) { return abs(x - y) < 1e-9; }
bool inrange(int x, int t) { return x >= 0 && x < t; }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll id0(double x) { ll m = (ll)sqrt(x); return m + (m * m <= (ll)(x) ? 0 : -1); }
ll id4(double x) { ll m = (ll)sqrt(x); return m + ((ll)x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }



typedef ll val_t;

struct graph_t {
	int n;           

	int m;           

	vector<P> edges; 

	vector<val_t> vals; 

	vector<ll> costs; 

	vector<ll> caps;  

};

class Dijkstra {
private:
	struct node {
		int id; bool done; vi to_eid; vi to; vll cost; int from_eid; int from; ll d;
		bool operator<(const node & another) const {
			return d != another.d ? d > another.d : id > another.id;
		}
	};
	vector<node> nodes;
	int n, source;
public:
	Dijkstra(graph_t G, int start) {
		n = G.n;
		nodes.resize(n);
		Loop(i, n) nodes[i] = { i, false,{},{},{}, -1, -1, id2 };
		Loop(i, G.edges.size()) {
			nodes[G.edges[i].first].to_eid.push_back(i);
			nodes[G.edges[i].first].to.push_back(G.edges[i].second);
			nodes[G.edges[i].first].cost.push_back(G.costs[i]);
		}
		source = start;
		nodes[source].d = 0;
		priority_queue<node> pq;
		pq.push(nodes[source]);
		while (pq.size()) {
			node a = pq.top();
			pq.pop();
			if (nodes[a.id].done) continue;
			nodes[a.id].done = true;
			Loop(j, a.to.size()) {
				node *b = &nodes[a.to[j]];
				if (b->done) continue;
				ll buf = a.d + a.cost[j];
				if (buf < b->d) {
					b->d = buf;
					b->from_eid = a.to_eid[j];
					b->from = a.id;
					pq.push(*b);
				}
			}
		}
		return;
	}
	vi get_path(int v) {
		stack<int> stk;
		stk.push(v);
		int a = v;
		while (nodes[a].from != -1) {
			stk.push(nodes[a].from);
			a = nodes[a].from;
		}
		if (a != source) return {};
		vi ret;
		while (stk.size()) {
			ret.push_back(stk.top());
			stk.pop();
		}
		return ret;
	}
	vi get_path_eid(int v) {
		stack<int> stk;
		int a = v;
		while (nodes[a].from != -1) {
			stk.push(nodes[a].from_eid);
			a = nodes[a].from;
		}
		if (a != source) return {};
		vi ret;
		while (stk.size()) {
			ret.push_back(stk.top());
			stk.pop();
		}
		return ret;
	}
	ll get_dist(int v) {
		return nodes[v].d;
	}
	vvll multi_dijkstra(vi vs) {
		vvll ret(vs.size(), vll(n));
		Loop(i, vs.size()) {
			Loop(j, n) {
				nodes[j].done = false;
				nodes[j].from = -1;
				nodes[j].from_eid = -1;
				nodes[j].d = id2;
			}
			source = vs[i];
			nodes[source].d = 0;
			priority_queue<node> pq;
			pq.push(nodes[source]);
			while (pq.size()) {
				node a = pq.top();
				pq.pop();
				if (nodes[a.id].done) continue;
				nodes[a.id].done = true;
				Loop(j, a.to.size()) {
					node *b = &nodes[a.to[j]];
					if (b->done) continue;
					ll buf = a.d + a.cost[j];
					if (buf < b->d) {
						b->d = buf;
						b->from_eid = a.to_eid[j];
						b->from = a.id;
						pq.push(*b);
					}
				}
			}
			Loop(j, n) {
				ret[i][j] = nodes[j].d;
			}
		}
		return ret;
	}
};


class Prim {
private:
	

	struct node {
		int id; bool done; vi to_eid; vi to; vll cost; int from_eid; int from; ll d;
		bool operator<(const node & another) const {
			return d != another.d ? d > another.d : id > another.id;
		}
	};
	vector<node> nodes;
	int n, m, root;
public:
	Prim(graph_t G, int start) {
		n = G.n;
		m = G.edges.size();
		nodes.resize(n);
		Loop(i, n) nodes[i] = { i, false,{},{},{}, -1, -1, id2 };
		Loop(i, G.edges.size()) {
			nodes[G.edges[i].first].to_eid.push_back(i);
			nodes[G.edges[i].first].to.push_back(G.edges[i].second);
			nodes[G.edges[i].first].cost.push_back(G.costs[i]);
			nodes[G.edges[i].second].to_eid.push_back(i - m);
			nodes[G.edges[i].second].to.push_back(G.edges[i].first);
			nodes[G.edges[i].second].cost.push_back(G.costs[i]);
		}
		root = start;
		nodes[root].d = 0;
		priority_queue<node> pq;
		pq.push(nodes[root]);
		while (pq.size()) {
			node a = pq.top(); pq.pop();
			if (nodes[a.id].done) continue;
			nodes[a.id].done = true;
			Loop(j, a.to.size()) {
				node *b = &nodes[a.to[j]];
				if (b->done) continue;
				ll buf = a.cost[j];
				if (buf < b->d) {
					b->d = buf;
					b->from_eid = a.to_eid[j];
					b->from = a.id;
					pq.push(*b);
				}
			}
		}
		return;
	}
	vector<P> get_tree_idpair() {
		vector<P> ret;
		Loop(i, n) {
			if (i != root) ret.push_back({ nodes[i].from, i });
		}
		return ret;
	}
	

	vi get_tree_eid() {
		vi ret;
		Loop(i, n) {
			if (i != root) {
				ret.push_back(nodes[i].from_eid);
				if (ret.back() < 0) ret.back() += m;
			}
		}
		return ret;
	}
	ll get_weight() {
		ll ret = 0;
		Loop(i, n) {
			if (i != root) ret += nodes[i].d;
		}
		return ret;
	}
};

typedef ll nodeval_t;
typedef ll edgeval_t;

struct tree_t {
	int n;           

	vector<P> edges; 

	vector<nodeval_t> vals; 

	vector<edgeval_t> costs; 

};

class Tree {
private:
	struct node {
		int id; vi childs; int parent = -1;
		int deg = -1; 

		int eid = -1; 

		int subtree_n = 1; 

		int visited = -1; 

		int departed = -1; 

		nodeval_t val; 

		edgeval_t cost; 

		bool operator<(const node & another) const {
			return deg != another.deg ? deg < another.deg : id < another.id;
		}
	};
	struct edgeinfo {
		int eid; int to; edgeval_t cost;
	};
	int n;
	static const nodeval_t init_val = 0;
	static const edgeval_t init_cost = 0;
	vector<vector<edgeinfo>> edges;
	vvi sparse_ancestors; 

	void tree_construction() {
		leaves = {};
		queue<int> que;
		que.push(root);
		while (que.size()) {
			int a = que.front(); que.pop();
			deg_order.push_back(a);
			if (a == Tree::root) nodes[a].deg = 0;
			int leaf_flag = true;
			Loop(i, edges[a].size()) {
				int b = edges[a][i].to;
				if (nodes[b].deg != -1) {
					nodes[a].parent = b;
					nodes[a].eid = edges[a][i].eid;
					nodes[a].cost = edges[a][i].cost;
					nodes[a].deg = nodes[b].deg + 1;
				}
				else {
					leaf_flag = false;
					nodes[a].childs.push_back(b);
					que.push(b);
				}
			}
			if (leaf_flag) leaves.push_back(a);
		}
		Loopr(i, n) {
			int a = deg_order[i];
			Loop(j, nodes[a].childs.size()) {
				int b = nodes[a].childs[j];
				nodes[a].subtree_n += nodes[b].subtree_n;
			}
		}
	}
	void solve_sparse_ancestors() {
		sparse_ancestors.resize(n);
		vector<int> id1;
		stack<int> stk;
		stk.push(Tree::root);
		int time_stamp = 1;
		while (stk.size()) {
			int a = stk.top(); stk.pop();
			nodes[a].visited = time_stamp++;
			for (int i = 1; i <= (int)(id1.size()); i *= 2) {
				sparse_ancestors[a].push_back(id1[id1.size() - i]);
			}
			if (nodes[a].childs.size()) {
				Loop(i, nodes[a].childs.size()) {
					stk.push(nodes[a].childs[i]);
				}
				id1.push_back(a);
			}
			else {
				nodes[a].departed = time_stamp++;
				while (id1.size() && (stk.empty() || nodes[stk.top()].parent != id1.back())) {
					nodes[id1.back()].departed = time_stamp++;
					id1.pop_back();
				}
			}
		}
		return;
	}
	bool is_ancestor(int descendant, int ancestor) {
		return nodes[ancestor].visited < nodes[descendant].visited
			&& nodes[descendant].departed < nodes[ancestor].departed;
	}
public:
	vector<node> nodes;
	vi deg_order; 

	vi leaves;
	int root;
	

	Tree(tree_t T, int root = -1) {
		n = T.n;
		nodes.resize(n);
		Loop(i, n) {
			nodes[i].id = i;
			nodes[i].val = (int)(T.vals.size()) > i ? T.vals[i] : init_val;
			nodes[i].cost = init_cost;
		}
		edges.resize(n);
		Loop(i, n - 1) {
			edges[T.edges[i].first].push_back({ i, T.edges[i].second, ((int)(T.costs.size()) > i ? T.costs[i] : init_cost) });
			edges[T.edges[i].second].push_back({ i, T.edges[i].first, ((int)(T.costs.size()) > i ? T.costs[i] : init_cost) });
		}
		

		if (root < 0) {
			int max_d = -1;
			Loop(i, n) {
				if ((int)(edges[i].size()) > max_d) {
					Tree::root = i;
					max_d = edges[i].size();
				}
			}
		}
		else {
			this->root = min(root, n - 1);
		}
		tree_construction();
		return;
	}
	int get_lowest_common_ancestor(int u, int v) {
		if (sparse_ancestors.size() == 0) solve_sparse_ancestors();
		if (u == v) return u;
		if (is_ancestor(u, v)) return v;
		if (is_ancestor(v, u)) return u;
		int a = u;
		while (!is_ancestor(v, sparse_ancestors[a][0])) {
			int b = sparse_ancestors[a][0];
			Loop1(i, sparse_ancestors[a].size() - 1) {
				if (is_ancestor(v, sparse_ancestors[a][i])) break;
				else b = sparse_ancestors[a][i - 1];
			}
			a = b;
		}
		return sparse_ancestors[a][0];
	}
};

int main() {
	quickio();
	graph_t G; cin >> G.n >> G.m;
	Loop(i, G.m) {
		int s, t;
		ll c;
		cin >> s >> t >> c; s--; t--;
		G.edges.push_back({ s, t });
		G.costs.push_back(c);
	}
	Prim prim(G, 0);
	vi es1 = prim.get_tree_eid();
	vector<bool> es_done(G.m, false);
	vi es2;
	set<int> st2;
	vi v2;
	Loop(i, es1.size()) {
		es_done[es1[i]] = true;
	}
	Loop(i, G.m) {
		if (!es_done[i]) {
			es2.push_back(i);
			st2.insert(G.edges[i].first);
		}
	}
	Loopitr(itr, st2) {
		v2.push_back(*itr);
	}
	tree_t T; T.n = G.n;
	Loop(i, T.n - 1) {
		T.edges.push_back({ G.edges[es1[i]].first, G.edges[es1[i]].second });
		T.costs.push_back(G.costs[es1[i]]);
	}
	Tree tree(T, 0);
	Loop1(i, tree.deg_order.size() - 1) {
		int a = tree.deg_order[i];
		int b = tree.nodes[a].parent;
		tree.nodes[a].cost += tree.nodes[b].cost;
	}
	Loop(i, G.m) {
		G.edges.push_back({ G.edges[i].second, G.edges[i].first });
		G.costs.push_back(G.costs[i]);
	}
	vvll ds(v2.size(), vll(G.n));
	Dijkstra dijks(G, 0);
	ds = dijks.multi_dijkstra(v2);
	int q; cin >> q;
	vll ans(q);
	Loop(i, q) {
		int s, t; cin >> s >> t; s--; t--;
		int a = tree.get_lowest_common_ancestor(s, t);
		ans[i] = tree.nodes[s].cost + tree.nodes[t].cost - 2 * tree.nodes[a].cost;
		Loop(j, v2.size()) {
			ll buf = ds[j][s] + ds[j][t];
			ans[i] = min(ans[i], buf);
		}
	}
	Loop(i, q) {
		cout << ans[i] << "\n";
	}
}