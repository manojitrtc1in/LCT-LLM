
using namespace std;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-7;























bool feq(double x, double y) { return abs(x - y) <= eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int id6(ll x) { return int(ceil(log2(x))); }
int id1(ll x) { return int(floor(log2(x))); }
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll id4(ll x) { ll m = (ll)sqrt((double)x); return m + (m * m <= x ? 0 : -1); }
ll id10(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }




struct tree_t {
	using nodeval_t = int;
	using edgeval_t = int;
	int n;           

	vector<P> edges; 

	vector<nodeval_t> vals; 

	vector<edgeval_t> costs; 

};




template<class val_t, class tree_t>
int id2(const vector<val_t> &a, const tree_t &T, int l = 0, int r = -1, int p = -1) {
	if (r == -1) { r = a.size(); T.n = a.size(); }
	if (r - l == 0) return -1;
	int mid = (l + r) / 2;
	if (p != -1) T.edges.push_back({ mid, p });
	id2(a, T, l, mid, mid);
	id2(a, T, mid + 1, r, mid);
	return mid;
}



class Tree {
	using nodeval_t = int;
	using edgeval_t = int;
private:
	struct node {
		vi childs; int parent = -1;
		int deg = -1; 

		int eid = -1; 

		int subtree_n = 1; 


		int visited = -1; 

		int departed = -1; 



		int pid = -1; 

		int qid = -1; 


		nodeval_t val; 

		edgeval_t cost; 

	};
	struct edgeinfo_t {
		int eid; int to; edgeval_t cost;
	};
	int n;
	static const nodeval_t init_val = 0;
	static const edgeval_t init_cost = 1;

	vvi sprs_ancestors; 



	vvi hld_paths; 


	void tree_construction(const vector<vector<edgeinfo_t>> &edges) {
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
public:
	vector<node> nodes;
	vi deg_order; 

	vi leaves;
	int root;
public:
	

	Tree(const tree_t &T, int root) {
		this->n = T.n;
		this->root = root;
		nodes.resize(n);
		Loop(i, n) {
			nodes[i].val = (int)(T.vals.size()) > i ? T.vals[i] : init_val;
			nodes[i].cost = init_cost;
		}
		vector<vector<edgeinfo_t>> edges(n);
		Loop(i, n - 1) {
			edges[T.edges[i].fst].push_back({ i, T.edges[i].snd, ((int)(T.costs.size()) > i ? T.costs[i] : init_cost) });
			edges[T.edges[i].snd].push_back({ i, T.edges[i].fst, ((int)(T.costs.size()) > i ? T.costs[i] : init_cost) });
		}
		tree_construction(edges);
		return;
	}
	int solve_diameter() {
		vi d(n, -1);
		queue<int> que;
		d[deg_order[n - 1]] = 0;
		que.push(deg_order[n - 1]);
		while (que.size()) {
			int a = que.front(); que.pop();
			int p = nodes[a].parent;
			if (d[p] == -1) {
				d[p] = d[a] + 1;
				que.push(nodes[a].parent);
			}
			Foreach(b, nodes[a].childs) {
				if (d[b] == -1) {
					d[b] = d[a] + 1;
					que.push(b);
				}
			}
		}
		return *max_element(d.begin(), d.end());
	}
	pair<int, vi> solve_center_of_gravity() {
		pair<int, vi> ret = { INT_MAX,{} };
		vi record(n, 1);
		Foreach(a, deg_order) {
			int x = n - 1, max_x = INT_MIN;
			Foreach(b, nodes[a].childs) {
				max_x = max(max_x, record[b]);
				x -= record[b];
				record[a] += record[b];
			}
			max_x = max(max_x, x);
			if (max_x < ret.fst) ret = { max_x,{ a } };
			else if (max_x == ret.fst) ret.snd.push_back(a);
		}
		sort(ret.snd.begin(), ret.snd.end());
		return ret;
	}
	vi solve_node_inclusion_cnt_in_all_path(bool id0) {
		vi ret(n, 0);
		Loop(i, n) {
			int a = i;
			

			Foreach(b, nodes[a].childs) {
				ret[i] += nodes[b].subtree_n * (nodes[a].subtree_n - nodes[b].subtree_n - 1);
			}
			ret[i] /= 2; 

			ret[i] += (nodes[a].subtree_n - 1) * (n - nodes[a].subtree_n); 

			ret[i] += n - 1; 

			if (id0) ret[i]++; 

		}
		return ret;
	}
	vi solve_edge_inclusion_cnt_in_all_path() {
		vi ret(n - 1, 0);
		Loop(i, n) {
			int eid = nodes[i].eid;
			if (eid < 0) continue;
			ret[eid] = nodes[i].subtree_n * (n - nodes[i].subtree_n); 

		}
		return ret;
	}

	void solve_sprs_ancestors() {
		sprs_ancestors.resize(n);
		vector<int> id5;
		stack<int> stk;
		stk.push(Tree::root);
		int time_stamp = 0;
		while (stk.size()) {
			int a = stk.top(); stk.pop();
			nodes[a].visited = time_stamp++;
			for (int i = 1; i <= (int)(id5.size()); i *= 2) {
				sprs_ancestors[a].push_back(id5[id5.size() - i]);
			}
			if (nodes[a].childs.size()) {
				Loop(i, nodes[a].childs.size()) {
					stk.push(nodes[a].childs[i]);
				}
				id5.push_back(a);
			}
			else {
				nodes[a].departed = time_stamp++;
				while (id5.size() && (stk.empty() || nodes[stk.top()].parent != id5.back())) {
					nodes[id5.back()].departed = time_stamp++;
					id5.pop_back();
				}
			}
		}
		return;
	}
	bool is_ancestor(int descendant, int ancestor) {
		return nodes[ancestor].visited < nodes[descendant].visited
			&& nodes[descendant].departed < nodes[ancestor].departed;
	}
	int get_lowest_common_ancestor(int u, int v) {
		if (u == v) return u;
		if (is_ancestor(u, v)) return v;
		if (is_ancestor(v, u)) return u;
		int a = u;
		while (!is_ancestor(v, sprs_ancestors[a][0])) {
			int b = sprs_ancestors[a][0];
			Loop1(i, sprs_ancestors[a].size() - 1) {
				if (is_ancestor(v, sprs_ancestors[a][i])) break;
				else b = sprs_ancestors[a][i - 1];
			}
			a = b;
		}
		return sprs_ancestors[a][0];
	}
	int get_ancestor(int descendant, int k) {
		if (k == 0) return descendant;
		int l = (int)log2(k);
		if (l >= sprs_ancestors[descendant].size()) return -1;
		else return get_ancestor(sprs_ancestors[descendant][l], k - (1 << l));
	}
	

	

	template<typename bsargv_t>
	int id8(int descendant, const bsargv_t &bsargv, bool(*evalfunc)(int, const bsargv_t&)) {
		if (evalfunc(descendant, bsargv)) return descendant;
		if (descendant == root) return -1;
		Loop(i, sprs_ancestors[descendant].size()) {
			if (evalfunc(sprs_ancestors[descendant][i], bsargv)) {
				if (i == 0) return id8(sprs_ancestors[descendant][0], bsargv, evalfunc);
				else return id8(sprs_ancestors[descendant][i - 1], bsargv, evalfunc);
			}
		}
		return id8(sprs_ancestors[descendant].back(), bsargv, evalfunc);
	}
	

	

	template<typename bsargv_t>
	int id7(int descendant, const bsargv_t &bsargv, bool(*evalfunc)(int, const bsargv_t&)) {
		if (!evalfunc(descendant, bsargv)) return -1;
		if (descendant == root) return root;
		Loop(i, sprs_ancestors[descendant].size()) {
			if (!evalfunc(sprs_ancestors[descendant][i], bsargv)) {
				if (i == 0) return descendant;
				else return id7(sprs_ancestors[descendant][i - 1], bsargv, evalfunc);
			}
		}
		return id7(sprs_ancestors[descendant].back(), bsargv, evalfunc);
	}
	



	void solve_hld() {
		Foreach(a, deg_order) {
			if (nodes[a].pid == -1) {
				nodes[a].pid = int(hld_paths.size());
				nodes[a].qid = 0;
				hld_paths.push_back({ a });
			}
			int max_id = -1;
			int id9 = 0;
			Foreach(b, nodes[a].childs) {
				if (nodes[b].subtree_n > id9) {
					max_id = b;
					id9 = nodes[b].subtree_n;
				}
			}
			if (max_id == -1) continue;
			nodes[max_id].pid = nodes[a].pid;
			nodes[max_id].qid = nodes[a].qid + 1;
			hld_paths[nodes[a].pid].push_back(max_id);
		}
	}
	struct pathinfo_t {
		int id;
		int l, r; 

	};
	vector<int> get_ids_in_path(const pathinfo_t &pathinfo) {
		vi ret(pathinfo.r - pathinfo.l);
		Loop(i, ret.size()) {
			ret[i] = hld_paths[pathinfo.id][pathinfo.l + i];
		}
		return ret;
	}
	

	

	vector<pathinfo_t> get_path_in_hld(int u, int v, bool id3) {
		vector<pathinfo_t> ret;
		int w = get_lowest_common_ancestor(u, v);
		Foreach(x, vector<int>({ u, v })) {
			int a = x;
			while (a != w) {
				if (nodes[a].pid != nodes[w].pid) {
					ret.push_back({ nodes[a].pid, 0, nodes[a].qid + 1 });
					a = nodes[hld_paths[nodes[a].pid][0]].parent;
				}
				else {
					ret.push_back({ nodes[a].pid, nodes[w].qid + 1, nodes[a].qid + 1 });
					a = w;
				}
			}
		}
		if (id3) {
			Loop(i, ret.size()) {
				if (nodes[w].pid == ret[i].id) {
					ret[i].l -= 1;
					id3 = false;
				}
			}
		}
		if (id3) {
			ret.push_back({ nodes[w].pid, nodes[w].qid, nodes[w].qid + 1 });
		}
		return ret;
	}
	vi get_hldpathsizes() {
		vi ret(hld_paths.size());
		Loop(i, hld_paths.size()) {
			ret[i] = int(hld_paths[i].size());
		}
		return ret;
	}
	int get_hldpathsize(int pid) {
		return int(hld_paths[pid].size());
	}

};

int ask_next(int x) {
	cout << "s " << x + 1 << endl;
	int res; cin >> res;
	res--;
	return res;
}

int ask_dist(int x) {
	cout << "d " << x + 1 << endl;
	int res; cin >> res;
	return res;
}

void ans_id(int x) {
	cout << "! " << x + 1 << endl;
}

int main() {
	quickio();
	tree_t T; cin >> T.n;
	Loop(_, T.n - 1) {
		int s, t; cin >> s >> t; s--; t--;
		T.edges.push_back({ s, t });
	}
	Tree *tree = new Tree(T, 0);
	tree->solve_sprs_ancestors();
	tree->solve_hld();
	int depth = ask_dist(0);
	int a = 0;
	while (true) {
		if (tree->nodes[a].deg < depth) {
			if (tree->nodes[a].childs.size() == 1) {
				a = tree->nodes[a].childs[0];
			}
			else {
				int u = ask_next(a);
				auto pathinfos = tree->get_path_in_hld(u, a, true);
				if (pathinfos.size() == 1) {
					int l = pathinfos[0].l;
					int r = min(tree->get_hldpathsize(pathinfos[0].id) - 1, l + depth - tree->nodes[a].deg);
					vi ids = tree->get_ids_in_path({ pathinfos[0].id, r, r + 1 });
					a = ids[0];
					int d = ask_dist(a);
					if (d == 0) {
						ans_id(a);
						return 0;
					}
					else {
						a = tree->get_ancestor(a, tree->nodes[a].deg - ((tree->nodes[a].deg + depth - d) >> 1));
					}
				}
				else {
					a = u;
				}
			}
		}
		else {
			ans_id(a);
			return 0;
		}
	}
	return 0;
}