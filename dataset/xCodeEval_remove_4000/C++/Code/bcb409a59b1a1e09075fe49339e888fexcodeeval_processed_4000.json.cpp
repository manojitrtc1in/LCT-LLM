





using std::cin, std::cout, std::bitset, std::complex;
using std::vector, std::array, std::string, std::pair, std::list, std::queue, std::deque;
using std::priority_queue, std::set, std::map, std::unordered_map;
using std::greater;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ull = unsigned long long int;
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
int id3(ll x) { int m = int(log2(x)); return m + ((1LL << m) < x ? 1 : 0); }
int id1(ll x) { int m = int(log2(x)); return m - ((1LL << m) > x ? 1 : 0); }
const string endl = "\n";
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
template<class T> void printv(const vector<T> &v) { for (const T &x : v) cout << x << " "; cout << endl; }
template<class T> void printmx(const vector<vector<T>> &mx) { for (const vector<T> &v : mx) printv(v); }
template<class T> void chmin(T &x, const T &y) { x = std::min(x, y); }
template<class T> void chmax(T &x, const T &y) { x = std::max(x, y); }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll id8(ll x) { ll m = (ll)sqrt((double)x); return m + (m*  m <= x ? 0 : -1); }
ll id7(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return ll(m) * ll(n) / gcd(m, n); }







struct tree_t {
	using nodeval_t = int;
	using edgeval_t = int;
	int n;           

	vector<P> edges; 

	vector<nodeval_t> vals; 

	vector<edgeval_t> costs; 

};




template<class val_t, class tree_t>
int id9(const vector<val_t> &a, const tree_t &T, int l = 0, int r = -1, int p = -1) {
	if (r == -1) { r = a.size(); T.n = a.size(); }
	if (r - l == 0) return -1;
	int mid = (l + r) / 2;
	if (p != -1) T.edges.push_back({ mid, p });
	id9(a, T, l, mid, mid);
	id9(a, T, mid + 1, r, mid);
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

    void dfs_order(int a, int &timestamp) {
        nodes[a].visited = timestamp++;
        for (const auto b : nodes[a].childs) {
            dfs_order(b, timestamp);
        }
        nodes[a].departed = timestamp++;
    }
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
				max_x = std::max(max_x, record[b]);
				x -= record[b];
				record[a] += record[b];
			}
			max_x = std::max(max_x, x);
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
    int global_ans = 0;
    void dfs_solve_with_array(int a, const vector<pair<int, int>> &arr, set<int> &l, set<int> &r, set<int, greater<int>> &rev_l, set<int, greater<int>> &rev_r, int cnt) {
        

        int cur_l = arr[a].fst;
        int cur_r = arr[a].snd;
        if (*(rev_r.lower_bound(cur_l)) < *(rev_l.lower_bound(cur_l))) {
            

            int mem_l = *(rev_l.lower_bound(cur_l));
            int mem_r = *(r.lower_bound(cur_r));
            l.erase(mem_l);
            r.erase(mem_r);
            rev_l.erase(mem_l);
            rev_r.erase(mem_r);
            l.insert(cur_l);
            r.insert(cur_r);
            rev_l.insert(cur_l);
            rev_r.insert(cur_r);
            for (const auto b : nodes[a].childs) {
                dfs_solve_with_array(b, arr, l, r, rev_l, rev_r, cnt);
            }
            if (nodes[a].childs.size() == 0) {
                chmax(global_ans, cnt);
            }
            l.insert(mem_l);
            r.insert(mem_r);
            rev_l.insert(mem_l);
            rev_r.insert(mem_r);
            l.erase(cur_l);
            r.erase(cur_r);
            rev_l.erase(cur_l);
            rev_r.erase(cur_r);
        }
        else {
            if (cur_l < *(rev_r.lower_bound(cur_r))) {
                

                for (const auto b : nodes[a].childs) {
                    dfs_solve_with_array(b, arr, l, r, rev_l, rev_r, cnt);
                }
                if (nodes[a].childs.size() == 0) {
                    chmax(global_ans, cnt);
                }
            }
            else {
                

                l.insert(cur_l);
                r.insert(cur_r);
                rev_l.insert(cur_l);
                rev_r.insert(cur_r);
                cnt++;
                for (const auto b : nodes[a].childs) {
                    dfs_solve_with_array(b, arr, l, r, rev_l, rev_r, cnt);
                }
                if (nodes[a].childs.size() == 0) {
                    chmax(global_ans, cnt);
                }
                l.erase(cur_l);
                r.erase(cur_r);
                rev_l.erase(cur_l);
                rev_r.erase(cur_r);
            }
        }
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
	int id4(int descendant, const bsargv_t &bsargv, bool(*evalfunc)(int, const bsargv_t&)) {
		if (evalfunc(descendant, bsargv)) return descendant;
		if (descendant == root) return -1;
		Loop(i, sprs_ancestors[descendant].size()) {
			if (evalfunc(sprs_ancestors[descendant][i], bsargv)) {
				if (i == 0) return id4(sprs_ancestors[descendant][0], bsargv, evalfunc);
				else return id4(sprs_ancestors[descendant][i - 1], bsargv, evalfunc);
			}
		}
		return id4(sprs_ancestors[descendant].back(), bsargv, evalfunc);
	}
	

	

	template<typename bsargv_t>
	int id6(int descendant, const bsargv_t &bsargv, bool(*evalfunc)(int, const bsargv_t&)) {
		if (!evalfunc(descendant, bsargv)) return -1;
		if (descendant == root) return root;
		Loop(i, sprs_ancestors[descendant].size()) {
			if (!evalfunc(sprs_ancestors[descendant][i], bsargv)) {
				if (i == 0) return descendant;
				else return id6(sprs_ancestors[descendant][i - 1], bsargv, evalfunc);
			}
		}
		return id6(sprs_ancestors[descendant].back(), bsargv, evalfunc);
	}
	



	void solve_hld() {
		Foreach(a, deg_order) {
			if (nodes[a].pid == -1) {
				nodes[a].pid = int(hld_paths.size());
				nodes[a].qid = 0;
				hld_paths.push_back({ a });
			}
			int max_id = -1;
			int id10 = 0;
			Foreach(b, nodes[a].childs) {
				if (nodes[b].subtree_n > id10) {
					max_id = b;
					id10 = nodes[b].subtree_n;
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
	

	

	vector<pathinfo_t> get_path_in_hld(int u, int v, bool id2) {
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
		if (id2) {
			Loop(i, ret.size()) {
				if (nodes[w].pid == ret[i].id) {
					ret[i].l -= 1;
					id2 = false;
				}
			}
		}
		if (id2) {
			ret.push_back({ nodes[w].pid, nodes[w].qid, nodes[w].qid + 1 });
		}
		return ret;
	}
	vi get_hld_path_sizes() {
		vi ret(hld_paths.size());
		Loop(i, hld_paths.size()) {
			ret[i] = int(hld_paths[i].size());
		}
		return ret;
	}
	int get_hld_path_size(int pid) {
		return int(hld_paths[pid].size());
	}

};

int main() {
    quickio();
    int t; cin >> t;
    Loop(_, t) {
        tree_t T0, T1;
        cin >> T0.n;
        T1.n = T0.n;
        Loop1(i, T0.n - 1) {
            int p; cin >> p; p--;
            T0.edges.push_back({p, i});
        }
        Loop1(i, T1.n - 1) {
            int p; cin >> p; p--;
            T1.edges.push_back({p, i});
        }
        Tree tree0(T0, 0), tree1(T1, 0);
        int timestamp = 0;
        tree1.dfs_order(0, timestamp);

        vector<pair<int, int>> arr(T1.n);
        Loop(i, T1.n) {
            arr[i] = {tree1.nodes[i].visited, tree1.nodes[i].departed};
        }
        set<int> l;
        set<int> r;
        set<int, greater<int>> rev_l;
        set<int, greater<int>> rev_r;
        l.insert(INT_MIN);
        r.insert(INT_MIN + 1);
        rev_l.insert(INT_MIN);
        rev_r.insert(INT_MIN + 1);
        l.insert(INT_MAX - 1);
        r.insert(INT_MAX);
        rev_l.insert(INT_MAX - 1);
        rev_r.insert(INT_MAX);
        tree0.dfs_solve_with_array(0, arr, l, r, rev_l, rev_r, 0);
        cout << tree0.global_ans << endl;
    }
}
		      		 			 	 		 	  			  	 	