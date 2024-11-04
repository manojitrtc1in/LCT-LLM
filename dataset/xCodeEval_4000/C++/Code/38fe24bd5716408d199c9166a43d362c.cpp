#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <limits>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <unordered_map>
#include <random>
#include <cmath>
#include <complex>



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
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loopll(i, n) for(ll i = 0; i < (ll)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopll1(i, n) for(ll i = 1; i <= (ll)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = (ll)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define Looprll1(i, n) for(ll i = (ll)n; i >= 1; i--)
#define Foreach(buf, container) for(auto buf : container)
#define Loopdiag(i, j, h, w, sum) for(int i = ((sum) >= h ? h - 1 : (sum)), j = (sum) - i; i >= 0 && j < w; i--, j++)
#define Loopdiagr(i, j, h, w, sum) for(int j = ((sum) >= w ? w - 1 : (sum)), i = (sum) - j; j >= 0 && i < h; j--, i++)
#define Loopdiagsym(i, j, h, w, gap) for (int i = ((gap) >= 0 ? (gap) : 0), j = i - (gap); i < (h) && j < (w); i++, j++)
#define Loopdiagsymr(i, j, h, w, gap) for (int i = ((gap) > (h) - (w) - 1 ? (h) - 1 : (w) - 1 + (gap)), j = i - (gap); i >= 0 && j >= 0; i--, j--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define printv(vector) Loop(extra_i, vector.size()) { cout << vector[extra_i] << " "; } cout << endl;
#define printmx(matrix) Loop(extra_i, matrix.size()) { Loop(extra_j, matrix[extra_i].size()) { cout << matrix[extra_i][extra_j] << " "; } cout << endl; }
#define quickio() ios::sync_with_stdio(false); cin.tie(0);
#define readfile(filename) ifstream in(filename); cin.rdbuf(in.rdbuf());
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
bool nearlyeq(double x, double y) { return abs(x - y) < 1e-9; }
bool inrange(int x, int t) { return x >= 0 && x < t; }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(double x) { ll m = (ll)sqrt(x); return m + (m * m <= (ll)(x) ? 0 : -1); }
ll ceilsqrt(double x) { ll m = (ll)sqrt(x); return m + ((ll)x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }



template <class seg_t>
class SegTree {
private:
	void local_update(int index, seg_t(*update_rule)(seg_t, seg_t, seg_t)) {
		int l = left_of(index), r = index * 2 + 2;
		segs[index] = update_rule(segs[index], segs[l], segs[r]);
	}
	void get_index_of_range_rec(int s, int t, int l, int r, int index, vi *v) {
		if (s == l && t == r) v->push_back(index);
		else {
			int mid = (l + r) / 2;
			if (s < mid && mid < t) {
				get_index_of_range_rec(s, mid, l, mid, left_of(index), v);
				get_index_of_range_rec(mid, t, mid, r, right_of(index), v);
			}
			else if (s < mid) {
				get_index_of_range_rec(s, t, l, mid, left_of(index), v);
			}
			else if (mid < t) {
				get_index_of_range_rec(s, t, mid, r, right_of(index), v);
			}
		}
	}
public:
	int n;
	vector<seg_t> segs;
	enum direction_t { NONE, LEFT, RIGHT };
	vector<direction_t> froms;
	SegTree(vector<seg_t> a, seg_t init, seg_t(*update_rule)(seg_t, seg_t, seg_t)) {
		n = (int)pow(2, ceil(log2(a.size())));
		segs = vector<seg_t>(n * 2 - 1, init);
		froms = vector<direction_t>(n * 2 - 1, NONE);
		Loop(i, a.size()) segs[n - 1 + i] = a[i];
		Loopr(i, n - 1) local_update(i, update_rule);
	}
	int left_of(int index) {
		int ret = index * 2 + 1;
		if (ret < n * 2 - 1) return ret;
		else return -1;
	}
	int right_of(int index) {
		int ret = index * 2 + 2;
		if (ret < n * 2 - 1) return ret;
		else return -1;
	}
	void update(int k, seg_t x, seg_t(*update_rule)(seg_t, seg_t, seg_t), bool by_index) {
		vi indices = get_index_above(k, by_index);
		segs[indices[0]] = x;
		Loop1(i, indices.size() - 1) local_update(indices[i], update_rule);
	}
	

	vi get_index_of_range(int s, int t) {
		vi ret = {};
		get_index_of_range_rec(s, t, 0, n, 0, &ret);
		return ret;
	}
	vi get_index_above(int k, bool by_index) {
		int index = by_index ? k : k + n - 1;
		vi ret = { index };
		while (index > 0) {
			index = (index - 1) / 2;
			ret.push_back(index);
		}
		return ret;
	}
	vi get_index_under(int k, bool by_index) {
		int index = by_index ? k : k + n - 1;
		vi ret = { index };
		while (index < n * 2 - 1) {
			if (froms[index] == NONE) break;
			index = (froms[index] == LEFT ? left_of(index) : right_of(index));
			ret.push_back(index);
		}
		return ret;
	}
	seg_t get_val(int k, bool by_index = false) {
		int index = by_index ? k : k + n - 1;
		return segs[index];
	}
	void debug_output() {
		int index = 0;
		int cnt = 0;
		while (index < n * 2 - 1) {
			Loop(i, 1 << cnt) {
				cout << segs[index] << " ";
				index++;
			}
			cout << endl;
			cnt++;
		}
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
	static const edgeval_t init_cost = 1;
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
	void solve_sparse_ancestors() {
		sparse_ancestors.resize(n);
		vector<int> current_ancestors;
		stack<int> stk;
		stk.push(Tree::root);
		int time_stamp = 0;
		while (stk.size()) {
			int a = stk.top(); stk.pop();
			nodes[a].visited = time_stamp++;
			for (int i = 1; i <= (int)(current_ancestors.size()); i *= 2) {
				sparse_ancestors[a].push_back(current_ancestors[current_ancestors.size() - i]);
			}
			if (nodes[a].childs.size()) {
				Loop(i, nodes[a].childs.size()) {
					stk.push(nodes[a].childs[i]);
				}
				current_ancestors.push_back(a);
			}
			else {
				nodes[a].departed = time_stamp++;
				while (current_ancestors.size() && (stk.empty() || nodes[stk.top()].parent != current_ancestors.back())) {
					nodes[current_ancestors.back()].departed = time_stamp++;
					current_ancestors.pop_back();
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
	int get_ancestor(int descendant, int k) {
		if (k == 0) return descendant;
		int l = (int)log2(k);
		if (l >= sparse_ancestors[descendant].size()) return -1;
		else return get_ancestor(sparse_ancestors[descendant][l], k - (1 << l));
	}
	

	

	template<typename bsargv_t>
	int binary_search_upper_ancestor(int descendant, const bsargv_t &bsargv, bool(*evalfunc)(int, const bsargv_t&)) {
		if (evalfunc(descendant, bsargv)) return descendant;
		if (descendant == root) return -1;
		Loop(i, sparse_ancestors[descendant].size()) {
			if (evalfunc(sparse_ancestors[descendant][i], bsargv)) {
				if (i == 0) return binary_search_upper_ancestor(sparse_ancestors[descendant][0], bsargv, evalfunc);
				else return binary_search_upper_ancestor(sparse_ancestors[descendant][i - 1], bsargv, evalfunc);
			}
		}
		return binary_search_upper_ancestor(sparse_ancestors[descendant].back(), bsargv, evalfunc);
	}
	

	

	template<typename bsargv_t>
	int binary_search_lower_ancestor(int descendant, const bsargv_t &bsargv, bool(*evalfunc)(int, const bsargv_t&)) {
		if (!evalfunc(descendant, bsargv)) return -1;
		if (descendant == root) return root;
		Loop(i, sparse_ancestors[descendant].size()) {
			if (!evalfunc(sparse_ancestors[descendant][i], bsargv)) {
				if (i == 0) return descendant;
				else return binary_search_lower_ancestor(sparse_ancestors[descendant][i - 1], bsargv, evalfunc);
			}
		}
		return binary_search_lower_ancestor(sparse_ancestors[descendant].back(), bsargv, evalfunc);
	}
	

};

Tree *tree;
SegTree<int> *segtree;

int update_rule(int o, int l, int r) {
	if (l == -1 && r == -1) return -1;
	else if (l == -1) return r;
	else if (r == -1) return l;
	else return tree->get_lowest_common_ancestor(l, r);
}

int main() {
	quickio();
	tree_t T; cin >> T.n;
	int q; cin >> q;
	Loop(i, T.n - 1) {
		int t; cin >> t;
		T.edges.push_back({ i + 1, t - 1 });
	}
	tree = new Tree(T, 0);
	vi a(T.n); Loop(i, T.n) a[i] = i;
	segtree = new SegTree<int>(a, -1, update_rule);
	Loop(unused, q) {
		int s, t; cin >> s >> t; s--; t--;
		vi lst = segtree->get_index_of_range(s, t + 1);
		int p = segtree->segs[lst[0]];
		vi p_log = { p };
		Loop1(i, lst.size() - 1) {
			p = tree->get_lowest_common_ancestor(p, segtree->segs[lst[i]]);
			p_log.push_back(p);
		}
		int target, target2;
		if (s <= p && p <= t) {
			target = p;
			target2 = p;
		}
		else {
			int base = s;
			vi lst2 = segtree->get_index_of_range(s + 1, t + 1);
			vi p_log2;
			bool judge = true;
			Loop(i, lst2.size()) {
				p_log2.push_back(tree->get_lowest_common_ancestor(base, segtree->segs[lst2[i]]));
				if (p_log2.back() != p) judge = false;
			}
			int focus = 0;
			Loop(i, p_log2.size()) {
				if (p_log2[i] == p) focus = lst2[i];
			}
			while (true) {
				if (focus >= (segtree->n - 1)) {
					target = focus - (segtree->n - 1);
					break;
				}
				else {
					lst2 = { segtree->left_of(focus), segtree->right_of(focus) };
					Loop(i, 2) {
						if (tree->get_lowest_common_ancestor(base, segtree->segs[lst2[i]]) == p) focus = lst2[i];
					}
				}
			}
			base = s + 1;
			lst2 = segtree->get_index_of_range(s + 2, t + 1);
			lst2.push_back(segtree->get_index_of_range(s, s + 1)[0]);
			p_log2 = {};
			judge = true;
			Loop(i, lst2.size()) {
				p_log2.push_back(tree->get_lowest_common_ancestor(base, segtree->segs[lst2[i]]));
				if (p_log2.back() != p) judge = false;
			}
			focus = 0;
			Loop(i, p_log2.size()) {
				if (p_log2[i] == p) focus = lst2[i];
			}
			while (true) {
				if (focus >= (segtree->n - 1)) {
					target2 = focus - (segtree->n - 1);
					break;
				}
				else {
					lst2 = { segtree->left_of(focus), segtree->right_of(focus) };
					Loop(i, 2) {
						if (tree->get_lowest_common_ancestor(base, segtree->segs[lst2[i]]) == p) focus = lst2[i];
					}
				}
			}
		}
		vi lst3 = segtree->get_index_of_range(s, target);
		vi lst4 = segtree->get_index_of_range(target + 1, t + 1);
		int p3 = lst3.size() > 0 ? segtree->segs[lst3[0]] : segtree->segs[lst4[0]];
		Loop(i, lst3.size()) {
			p3 = tree->get_lowest_common_ancestor(p3, segtree->segs[lst3[i]]);
		}
		Loop(i, lst4.size()) {
			p3 = tree->get_lowest_common_ancestor(p3, segtree->segs[lst4[i]]);
		}
		lst3 = segtree->get_index_of_range(s, target2);
		lst4 = segtree->get_index_of_range(target2 + 1, t + 1);
		int p4 = lst3.size() > 0 ? segtree->segs[lst3[0]] : segtree->segs[lst4[0]];
		Loop(i, lst3.size()) {
			p4 = tree->get_lowest_common_ancestor(p4, segtree->segs[lst3[i]]);
		}
		Loop(i, lst4.size()) {
			p4 = tree->get_lowest_common_ancestor(p4, segtree->segs[lst4[i]]);
		}
		if (tree->nodes[p3].deg > tree->nodes[p4].deg) {
			cout << target + 1 << " " << tree->nodes[p3].deg << endl;
		}
		else {
			cout << target2 + 1 << " " << tree->nodes[p4].deg << endl;
		}
	}
}