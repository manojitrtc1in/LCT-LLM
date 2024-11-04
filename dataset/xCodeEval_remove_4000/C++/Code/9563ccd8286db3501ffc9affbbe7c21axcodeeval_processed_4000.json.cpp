


using namespace std;
using namespace __gnu_pbds;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << arr.first << " " << arr.second << "\n";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef tuple<int, int, int, int> tpl;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using Ftn = function<T(T, T)>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
template<class T, class BO1, class BO2, class BO3>
struct ldseg{
	ldseg *l = 0, *r = 0;
	int low, high;
	BO1 &lop;		

	BO2 &qop;		

	BO3 &aop;		

	vector<T> &id;	

	T lset, lazy, val;
	ldseg(int low, int high, BO1 &lop, BO2 &qop, BO3 &aop, vector<T> &id)
	: low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], val = id[1], lset = id[2];
	}
	ldseg(const vector<T> &arr, int low, int high, BO1 &lop, BO2 &qop, BO3 &aop, vector<T> &id)
	: low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], lset = id[2];
		if(high - low > 1){
			int mid = low + (high - low) / 2;
			l = new ldseg(arr, low, mid, lop, qop, aop, id);
			r = new ldseg(arr, mid, high, lop, qop, aop, id);
			val = qop(l->val, r->val);
		}
		else val = arr[low];
	}
	void push(){
		if(!l){
			int mid = low + (high - low) / 2;
			l = new ldseg(low, mid, lop, qop, aop, id);
			r = new ldseg(mid, high, lop, qop, aop, id);
		}
		if(lset != id[2]){
			l->set(low, high, lset);
			r->set(low, high, lset);
			lset = id[2];
		}
		else if(lazy != id[0]){
			l->update(low, high, lazy);
			r->update(low, high, lazy);
			lazy = id[0];
		}
	}
	void set(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			lset = x;
			lazy = id[0];
			val = aop(id[1], x, high - low);
		}
		else{
			push();
			l->set(ql, qr, x);
			r->set(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	void update(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			if(lset != 	id[2]) lset = lop(lset, x);
			else lazy = lop(lazy, x);
			val = aop(val, x, high - low);
		}
		else{
			push(), l->update(ql, qr, x), r->update(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	T query(int ql, int qr){
		if(qr <= low || high <= ql) return id[1];
		if(ql <= low && high <= qr) return val;
		push();
		return qop(l->query(ql, qr), r->query(ql, qr));
	}
};
template<class DS, class BO, class T, int id0 = 1>
struct HLD{
	int N, root;
	vector<vi> adj;
	vi par, sz, depth, next, pos, rpos;
	DS &tr;
	BO bin_op;
	const T id;
	HLD(int N, int root, DS &tr, BO bin_op, T id):
	N(N), root(root), adj(N), par(N, -1), sz(N, 1), depth(N), next(N), pos(N), tr(tr), bin_op(bin_op), id(id){
		this->root = next[root] = root;
	}
	void insert(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs_sz(int u){
		if(par[u] != -1) adj[u].erase(find(all(adj[u]), par[u]));
		for(auto &v: adj[u]){
			par[v] = u, depth[v] = depth[u] + 1;
			dfs_sz(v);
			sz[u] += sz[v];
			if(sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
		}
	}
	void dfs_hld(int u){
		static int t = 0;
		pos[u] = t ++;
		rpos.push_back(u);
		for(auto &v: adj[u]){
			next[v] = (v == adj[u][0] ? next[u] : v);
			dfs_hld(v);
		}
	}
	void init(){
		dfs_sz(root), dfs_hld(root);
	}
	template<class Action>
	void processpath(int u, int v, Action act){
		for(; next[u] != next[v]; v = par[next[v]]){
			if(depth[next[u]] > depth[next[v]]) swap(u, v);
			act(pos[next[v]], pos[v] + 1);
		}
		if(depth[u] > depth[v]) swap(u, v);
		act(pos[u] + id0, pos[v] + 1);
	}
	void updatepath(int u, int v, T val, int is_update = true){
		if(is_update) processpath(u, v, [this, &val](int l, int r){tr.update(l, r, val);});
		else processpath(u, v, [this, &val](int l, int r){tr.set(l, r, val);});
	}
	void updatesubtree(int u, T val, int is_update = true){
		if(is_update) tr.update(pos[u] + id0, pos[u] + sz[u], val);
		else tr.set(pos[u] + id0, pos[u] + sz[u], val);
	}
	T querypath(int u, int v){
		T res = id;
		processpath(u, v, [this, &res](int l, int r){res = bin_op(res, tr.query(l, r));});
		return res;
	}
	T querysubtree(int u){
		return tr.query(pos[u] + id0, pos[u] + sz[u]);
	}
};
 
struct binarylift: vector<vi>{
	int n, root, lg;
	vector<vi> up;
	vi depth;
	binarylift(int n, int root):
		n(n), root(root), lg(ceil(log2(n))), depth(n), up(n, vector<int>(lg + 1)){
		this->resize(n);
	}
	void insert(int u, int v){
		(*this)[u].push_back(v);
		(*this)[v].push_back(u);
	}
	void init(){
		dfs(root, root);
	}
	void dfs(int u, int p){
		up[u][0] = p;
		for(int i = 1; i <= lg; i ++){
			up[u][i] = up[up[u][i - 1]][i - 1];
		}
		for(auto &v: (*this)[u]) if(v != p){
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
	int lca(int u, int v){
		if(depth[u] < depth[v]){
			std::swap(u, v);
		}
		u = trace_up(u, depth[u] - depth[v]);
		for(int d = lg; d >= 0; d --){
			if(up[u][d] != up[v][d]){
				u = up[u][d], v = up[v][d];
			}
		}
		return u == v ? u : up[u][0];
	}
	int dist(int u, int v){
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}
	int trace_up(int u, int dist){
		if(dist >= depth[u] - depth[root]){
			return root;
		}
		for(int d = lg; d >= 0; d --){
			if(dist & (1 << d)) u = up[u][d];
		}
		return u;
	}
};
 
struct disjoint: vi{
	int N;
	

	disjoint(int N): N(N){
		this->resize(N);
		iota(all((*this)), 0);
	}
	int root(int u){
		

		return (*this)[u] == u ? u : ((*this)[u] = root((*this)[u]));
	}
	void merge(int u, int v){
		(*this)[root(v)] = root(u);
	}
	int share(int u, int v){
		return root((*this)[u]) == root((*this)[v]);
	}
	
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<tpl> edge(m);
	for(auto &[w, u, v, ind]: edge){
		static int cnt = 0;
		cin >> u >> v >> w, u --, v --, ind = cnt ++;
	}
	sort(all(edge));
	vi ismst(m);
	disjoint dsu(n);
	binarylift lift(n, 0);
	auto lop = plus<int>{};
	auto qop = [&](int x, int y){ return max(x, y);};
	auto aop = [&](int x, int y, int z){ return x + y;};
	vi ID{0, 0, -int(2e9)};
	ldseg tr{0, n, lop, qop, aop, ID};
	HLD hld(n, 0, tr, qop, 0);
	for(int i = 0; i < m; i ++){
		auto [w, u, v, ind] = edge[i];
		if(!dsu.share(u, v)){
			ismst[i] = true;
			dsu.merge(u, v);
			hld.insert(u, v);
			lift.insert(u, v);
		}
	}
	ll cost = 0;
	hld.init();
	lift.init();
	for(int i = 0; i < m; i ++){
		if(ismst[i]){
			auto [w, u, v, ind] = edge[i];
			hld.updatepath(u, v, w);
			cost += w;
		}
	}
	vl res(m);
	for(int i = 0; i < m; i ++){
		auto [w, u, v, ind] = edge[i];
		if(ismst[i]){
			res[ind] = cost;
		}
		else{
			int lca = lift.lca(u, v);
			res[ind] = cost - max(hld.querypath(u, lca), hld.querypath(v, lca)) + w;
		}
	}
	for(auto x: res){
		cout << x << "\n";
	}
	return 0;
}

 

















































































