#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-7;
#define Loop(i, n) for(int i = 0; i < int(n); i++)
#define Loopll(i, n) for(ll i = 0; i < ll(n); i++)
#define Loop1(i, n) for(int i = 1; i <= int(n); i++)
#define Loopll1(i, n) for(ll i = 1; i <= ll(n); i++)
#define Loopr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = ll(n) - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = int(n); i >= 1; i--)
#define Looprll1(i, n) for(ll i = ll(n); i >= 1; i--)
#define Foreach(buf, container) for(const auto &buf : container)
#define Foreachr(buf, container)  for(const auto &buf : reversed(container))
#define Loopdiag(i, j, h, w, sum) for(int i = ((sum) >= (h) ? (h) - 1 : (sum)), j = (sum) - i; i >= 0 && j < (w); i--, j++)
#define Loopdiagr(i, j, h, w, sum) for(int j = ((sum) >= (w) ? (w) - 1 : (sum)), i = (sum) - j; j >= 0 && i < (h); j--, i++)
#define Loopdiagsym(i, j, h, w, gap) for (int i = ((gap) >= 0 ? (gap) : 0), j = i - (gap); i < (h) && j < (w); i++, j++)
#define Loopdiagsymr(i, j, h, w, gap) for (int i = ((gap) > (h) - (w) - 1 ? (h) - 1 : (w) - 1 + (gap)), j = i - (gap); i >= 0 && j >= 0; i--, j--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define quickio() ios::sync_with_stdio(false); cin.tie(0);
#define endl "\n"
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
#define Comp(type_t) bool operator<(const type_t &another) const
#define fst first
#define snd second
#define INF INFINITY
bool feq(double x, double y) { return abs(x - y) <= eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int ceillog2(ll x) { return int(ceil(log2(x))); }
int floorlog2(ll x) { return int(floor(log2(x))); }
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
template<class T> void printv(const vector<T> &v) { for (const T &x : v) cout << x << " "; cout << endl; }
template<class T> void printmx(const vector<vector<T>> &mx) { for (const vector<T> &v : mx) printv(v); }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (m * m <= x ? 0 : -1); }
ll ceilsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }




class SegTreeSum {
	using val_t = ll;
private:
	struct segval_t {
		bool enable;
		val_t upd, add, sum;
	};
	int n, N; 

	int base;
	vector<segval_t> nodes;
	vi idl, idr, cover_size;
	void merge(int id) {
		nodes[id].sum = nodes[idl[id]].sum + nodes[idl[id]].add * cover_size[idl[id]]
			+ nodes[idr[id]].sum + nodes[idr[id]].add * cover_size[idr[id]];
	}
	void lazy(int id) {
		if (id >= base) return;
		if (nodes[id].enable) {
			val_t upd = nodes[id].upd + nodes[id].add;
			nodes[idl[id]] = { true, upd, 0, upd * cover_size[idl[id]] };
			nodes[idr[id]] = { true, upd, 0, upd * cover_size[idr[id]] };
			nodes[id] = { false, 0, 0, upd * cover_size[id] };
		}
		else {
			nodes[idl[id]].add += nodes[id].add;
			nodes[idr[id]].add += nodes[id].add;
			nodes[id].add = 0;
			merge(id);
		}
	}
	enum change_t {
		UPD, ADD
	};
	void change_rec(int s, int t, int l, int r, int id, val_t x, change_t op) {
		if (s == l && t == r) {
			if (op == UPD) nodes[id] = { true, x, 0, x * cover_size[id] };
			if (op == ADD) nodes[id].add += x;
		}
		else {
			lazy(id);
			int m = (l + r) >> 1;
			if (s < m && m < t) {
				change_rec(s, m, l, m, idl[id], x, op);
				change_rec(m, t, m, r, idr[id], x, op);
			}
			else if (s < m) {
				change_rec(s, t, l, m, idl[id], x, op);
			}
			else if (m < t) {
				change_rec(s, t, m, r, idr[id], x, op);
			}
			merge(id);
		}
	}
	val_t solve_rec(int s, int t, int l, int r, int id) {
		val_t v = 0;
		if (s == l && t == r) {
			v = nodes[id].sum;
		}
		else {
			lazy(id);
			int m = (l + r) >> 1;
			if (s < m && m < t) {
				val_t v0 = solve_rec(s, m, l, m, idl[id]);
				val_t v1 = solve_rec(m, t, m, r, idr[id]);
				v = v0 + v1;
			}
			else if (s < m) {
				v = solve_rec(s, t, l, m, idl[id]);
			}
			else if (m < t) {
				v = solve_rec(s, t, m, r, idr[id]);
			}
		}
		v += nodes[id].add * (t - s);
		return v;
	}
	void common_init() {
		idl.resize(base + N, -1);
		idr.resize(base + N, -1);
		Loop(i, base) {
			idl[i] = (i << 1) + 1;
			idr[i] = (i << 1) + 2;
		}
		cover_size.resize(base + N);
		Loop(i, n) {
			cover_size[base + i] = 1;
		}
		Loopr(i, base) {
			cover_size[i] = cover_size[idl[i]] + cover_size[idr[i]];
		}
	}
public:
	SegTreeSum(int n, val_t init = 0) {
		this->n = n;
		N = 1 << ceillog2(n);
		base = N - 1;
		nodes = vector<segval_t>(base + N, { false, 0, 0, 0 });
		common_init();
		Loop(i, n) {
			nodes[base + i] = { true, init, 0, init };
		}
		Loopr(i, base) {
			merge(i);
		}
	}
	SegTreeSum(const vector<val_t> &a) {
		this->n = int(a.size());
		N = 1 << ceillog2(n);
		base = N - 1;
		nodes = vector<segval_t>(base + N, { false, 0, 0, 0 });
		common_init();
		Loop(i, n) {
			nodes[base + i] = { true, a[i], 0, a[i] };
		}
		Loopr(i, base) {
			merge(i);
		}
	}
	void upd(int s, int t, val_t x) {
		if (s >= t) return;
		change_rec(s, t, 0, N, 0, x, UPD);
	}
	void add(int s, int t, val_t x) {
		if (s >= t) return;
		change_rec(s, t, 0, N, 0, x, ADD);
	}
	val_t sumof(int s, int t) {
		if (s >= t) return 0;
		return solve_rec(s, t, 0, N, 0);
	}
};

class SuffixTree26 {
private:
	int n;
	string s;
	

	

	

	

	struct node_t {
		int l; int r; array<node_t*, 26> childs; int dep; node_t *parent; int cnt; node_t *suf; P v = { INT_MAX, INT_MIN };
	};
	const char base = 'a';
	node_t *root;
	

	vector<node_t*> sufnodes;
	inline node_t* proceed(node_t *cur, int &k, int &i) {
		if (i == n) return cur;
		if (k == cur->r - cur->l) {
			if (cur->childs[s[i] - base] == nullptr) return cur;
			else {
				cur = cur->childs[s[i] - base];
				k = 1;
				i++;
				return proceed(cur, k, i);
			}
		}
		else {
			if (s[cur->l + k] != s[i]) return cur;
			else {
				k++;
				i++;
				return proceed(cur, k, i);
			}
		}
	}
	inline node_t* insert(node_t *cur, const int k, const int i) {
		if (k < cur->r - cur->l) {
			node_t *branch = new node_t{ cur->l, cur->l + k, {}, cur->parent->dep + k, cur->parent, 0, nullptr };
			branch->childs[s[cur->l + k] - base] = cur;
			branch->parent->childs[s[cur->l] - base] = branch;
			cur->l = cur->l + k;
			cur->parent = branch;
			cur = branch;
		}
		if (i < n) {
			node_t *leaf = new node_t{ i, n, {}, cur->dep + n - i, cur, 1, nullptr };
			cur->childs[s[i] - base] = leaf;
			sufnodes[n - leaf->dep] = leaf;
		}
		else {
			cur->cnt++;
			sufnodes[n - cur->dep] = cur;
		}
		return cur;
	}
	inline node_t* proceed_suf(node_t *pre, int &k) {
		if (pre == root) return root;
		node_t *cur;
		int j;
		if (pre->parent == root) {
			cur = root;
			j = 1;
		}
		else {
			cur = pre->parent->suf;
			j = 0;
		}
		k = cur->r - cur->l;
		while (j < pre->r - pre->l) {
			cur = cur->childs[s[pre->l + j] - base];
			k = pre->r - pre->l - j;
			if (k > cur->r - cur->l) {
				j += cur->r - cur->l;
			}
			else {
				break;
			}
		}
		return cur;
	}
	void construct() {
		node_t *cur = root;
		node_t *pre = nullptr;
		int k = 0;
		int i = 0;
		root->suf = root;
		while (i != n || cur != root) {
			cur = proceed(cur, k, i);
			cur = insert(cur, k, i);
			if (pre != nullptr) {
				pre->suf = cur;
			}
			pre = cur;
			if (pre == root) i++;
			cur = proceed_suf(pre, k);
			if (k == cur->r - cur->l) {
				pre->suf = cur;
				pre = nullptr;
			}
		}
		sufnodes.push_back(root);
		Loop(i, n) {
			sufnodes[i]->suf = sufnodes[i + 1];
		}
		sufnodes.pop_back();
	}
	

	

	bool get_pos(node_t *&a, int &k, const string &t) {
		Loop(i, t.length()) {
			if (k == a->r - a->l) {
				if (a->childs[t[i] - base] == nullptr) return false;
				a = a->childs[t[i] - base];
				k = 1;
			}
			else if (t[i] == s[a->l + k]) {
				k++;
			}
			else {
				return false;
			}
		}
		return true;
	}
public:
	SuffixTree26(const string &s) {
		this->root = new node_t{ 0, 0, {}, 0, nullptr, 0, nullptr };
		this->n = s.length();
		this->s = s;
		this->sufnodes = vector<node_t*>(n, nullptr);
		this->construct();
		return;
	}
	

	bool is_suffix(const string &t) {
		node_t *a = root;
		int k = 0;
		bool judge = get_pos(a, k, t);
		if (judge && k == a->r - a->l) {
			return a->cnt;
		}
		else {
			return false;
		}
	}
	

	bool is_substring(const string &t) {
		node_t *a = root;
		int k = 0;
		return get_pos(a, k, t);
	}
	

	vi get_suffix_array() {
		vi ret(n, -1);
		stack<pair<node_t*, int>> stk;
		stk.push({ root, 0 });
		int k = 0;
		while (stk.size()) {
			node_t* a = stk.top().fst;
			int &i = stk.top().snd;
			if (i == 0 && a->cnt) {
				ret[k++] = n - a->dep;
			}
			for (; i < 27; ++i) {
				if (i == 26) {
					stk.pop();
				}
				else if (a->childs[i] != nullptr) {
					stk.push({ a->childs[i], 0 });
					++i;
					break;
				}
			}
		}
		return ret;
	}
	void accumulate_id_rec(node_t *a) {
		Loop(i, 26) {
			if (a->childs[i] != nullptr) {
				accumulate_id_rec(a->childs[i]);
				a->v.fst = min(a->v.fst, a->childs[i]->v.fst);
				a->v.snd = max(a->v.snd, a->childs[i]->v.snd);
			}
		}
	}
	void accumulate_id() {
		vi u = get_suffix_array();
		vi v(n);
		

		Loop(i, n) {
			v[u[i]] = i;
		}
		Loop(i, n) {
			sufnodes[i]->v = { v[i], v[i] };
		}
		accumulate_id_rec(root);
	}
	void run(SegTreeSum *sts, const string &t) {
		node_t *a = root;
		int k = 0;
		bool judge = get_pos(a, k, t);
		if (judge) {
			sts->add(a->v.fst, a->v.snd + 1, 1);
		}
	}
};

int main() {
	quickio();
	string t; cin >> t;
	int n; cin >> n;
	vector<string> s(n);
	Loop(i, n) cin >> s[i];
	

	SuffixTree26 *sft = new SuffixTree26(t);
	sft->accumulate_id();
	SegTreeSum *sts0 = new SegTreeSum(t.length());
	vll v0(t.length());
	Loop(i, n) {
		sft->run(sts0, s[i]);
	}
	vi u = sft->get_suffix_array();
	Loop(i, t.length()) {
		v0[u[i]] = sts0->sumof(i, i + 1);
	}
	

	reverse(t.begin(), t.end());
	Loop(i, n) {
		reverse(s[i].begin(), s[i].end());
	}
	delete sft;
	

	sft = new SuffixTree26(t);
	sft->accumulate_id();
	SegTreeSum *sts1 = new SegTreeSum(t.length());
	vll v1(t.length());
	Loop(i, n) {
		sft->run(sts1, s[i]);
	}
	u = sft->get_suffix_array();
	Loop(i, t.length()) {
		v1[u[i]] = sts1->sumof(i, i + 1);
	}
	ll ans = 0;
	Loop(i, t.length() - 1) {
		ans += v0[i + 1] * v1[t.length() - 1 - i];
	}
	cout << ans << endl;
}