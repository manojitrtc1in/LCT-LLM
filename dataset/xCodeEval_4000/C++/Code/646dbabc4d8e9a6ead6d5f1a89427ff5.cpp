

using namespace std;
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#ifdef shivang_ka_laptop
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
	#define booga cerr << "booga" << endl;
#else
	#define debug(...) 42;
	#define booga 9;
#endif

template <typename T> std::ostream& operator<<(std::ostream& stream, const vector<T>& vec){ for(size_t i = 0; i < vec.size(); i++){stream << vec[i];if(i != vec.size() - 1)stream << ' ';}; return stream; }
template <typename T> std::istream& operator>>(std::istream& stream, vector<T>& vec) { for(T &x : vec)stream >> x;return stream; }
template <typename T,typename U> std::ostream& operator<<(std::ostream& stream, const pair<T,U>& pr){ stream << pr.first << ' ' << pr.second; return stream; }
template <typename T,typename U> std::istream& operator>>(std::istream& stream, pair<T,U>& pr){ stream >> pr.first >> pr.second; return stream; }
template <typename T, typename U> void operator+=(vector<T>& vec, const U value) { for(T &x : vec)x += value; }
template <typename T, typename U> void operator-=(vector<T>& vec, const U value) { for(T &x : vec)x -= value; }
template <typename T, typename U> void operator*=(vector<T>& vec, const U value) { for(T &x : vec)x *= value; }
template <typename T, typename U> void operator/=(vector<T>& vec, const U value) { for(T &x : vec)x /= value; }
template <typename T> void operator++(vector<T>& vec) { vec += 1; }
template <typename T> void operator++(vector<T>& vec,int) { vec += 1; }
template <typename T> void operator--(vector<T>& vec) { vec -= 1; }
template <typename T> void operator--(vector<T>& vec,int) { vec -= 1; }
template <typename T,typename U, typename V> void operator+=(pair<T,U>& vec, const V value) { vec.first += value;vec.second += value; }
template <typename T,typename U, typename V> void operator-=(pair<T,U>& vec, const V value) { vec.first -= value;vec.second -= value; }
template <typename T,typename U, typename V> void operator*=(pair<T,U>& vec, const V value) { vec.first *= value;vec.second *= value; }
template <typename T,typename U, typename V> void operator/=(pair<T,U>& vec, const V value) { vec.first /= value;vec.second /= value; }
template <typename T,typename U> void operator++(pair<T,U>& vec) { vec += 1; } 
template <typename T,typename U> void operator++(pair<T,U>& vec,int) { vec += 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec) { vec -= 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec,int) { vec -= 1; } 

template <typename A, typename B>string to_string(pair<A, B> p);
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char c) {string s;s += c;return s; }
string to_string(const char* s) {return to_string((string) s); }
string to_string(bool b) {return (b ? "1" : "0"); }
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N>string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void debug_out() { cerr << endl; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H);debug_out(T...);}
void bharo(int N_N) { return; }template <typename Head, typename... Tail>void bharo(int N_N, Head &H, Tail & ... T) {H.resize(N_N);bharo(N_N,T...);}
void safai() { return; }template <typename Head, typename... Tail>void safai(Head &H, Tail & ... T) {H.clear();safai(T...);}

class HLD{
	class LCA{
		template<typename T>
		struct SparseTable{
			vector<vector<T>> table;
			vector<int> logtable;
			function<T(T, T)> merge_func;
			SparseTable(){}
			SparseTable(const vector<T> &vec, const function<T(T, T)> &f): merge_func(f){
				int maxlength = 0;
				while((1 << (maxlength+1)) <= (int)vec.size()) maxlength++;
				table.resize(maxlength+1, vector<T>(vec.size()));
				logtable.resize(vec.size()+1);
				for(int i = 0;i < maxlength + 1;i++){
					for(int j = 0;j < (int)vec.size() - (1 << i) + 1;j++){
						if(i)table[i][j] = merge_func(table[i-1][j], table[i-1][j + (1 << (i-1))]);
						else table[i][j] = vec[j];
					}
				}
				for(int i = 2;i <= (int)vec.size();i++)logtable[i] = logtable[i >> 1]+1;
			}
			T query(int l, int r){
				assert(l < r);
				int length = r - l;
				return merge_func(table[logtable[length]][l], table[logtable[length]][r - (1 << logtable[length])]);
			}
		};
		private:
		int a = 0, b = 0;
		vector<int> begin, number, tour, dep, rev;
		SparseTable<int> table;
		void init_dfs(int v, int p, const vector<vector<int>> &g){
			number[v] = b;rev[b] = v;b++;
			for(auto t : g[v]){
				if(t == p) continue;
				dep[t] = dep[v] + 1;
				init_dfs(t, v, g);
				tour.push_back(number[v]);
				if(begin[v] == -1)begin[v] = a;
				a++;
			}
			if(begin[v] == -1)begin[v] = a;
		}
		public:
		LCA(){}
		

		LCA(const vector<vector<int>> &g, int root = 0):begin(g.size(), -1), number(g.size()), dep(g.size(), -1), rev(g.size()){
			dep[root] = 0;
			init_dfs(root, -1, g);
			table = SparseTable<int>(tour, [](int x, int y){return min(x, y);});
		}
		

		int lca(int u, int v){
			if(begin[u] == begin[v]) return (dep[u] > dep[v] ? v : u);
			if(begin[u] > begin[v]) swap(u, v);
				return rev[table.query(begin[u], begin[v]+1)];
		}
		int depth(int v){
			return dep[v];
		}
		int dist(int u, int v){
			return dep[u] + dep[v] - 2*dep[lca(u, v)];
		}
	};
	
	class segtree {
	 public:
		int neutral = 0;
		struct node {
			

			

			long long int osum = 0,esum = 0; 

			int cnt = 0;
			int add = 0;
			void apply(int l, int r, int v) { 

				esum = 0;
				osum = v;
				cnt = 1;
				

			}
			void push(int l, int r, int v) { 

				assert(v == 1);
				swap(osum,esum);
				cnt = r-l+1 - cnt;
				add ^= v;
			}
		};
		node unite(const node &a, const node &b) const { 

			node res;
			res.osum = a.osum + b.osum;
			res.esum = a.esum + b.esum;
			res.cnt = a.cnt + b.cnt;
			return res;
		}
		inline void push(int x, int l, int r) {
			int y = (l + r) >> 1;
			int z = x + ((y - l + 1) << 1);
			if (tree[x].add != neutral) {
				tree[x + 1].push(l, y, tree[x].add);
				tree[z].push(y + 1, r, tree[x].add);
				tree[x].add = neutral;
			}
			
			

		}
		inline void pull(int x, int z) {
			tree[x] = unite(tree[x + 1], tree[z]);
		}
	
		int n;
		vector<node> tree;
		void build(int x, int l, int r) {
			if (l == r) {
				return;
			}
			int y = (l + r) >> 1;
			int z = x + ((y - l + 1) << 1);
			build(x + 1, l, y);
			build(z, y + 1, r);
			pull(x, z);
		}
		template <typename M>
		void build(int x, int l, int r, const vector<M> &v) {
			if (l == r) {
				tree[x].apply(l, r, v[l]);
				return;
			}
			int y = (l + r) >> 1;
			int z = x + ((y - l + 1) << 1);
			build(x + 1, l, y, v);
			build(z, y + 1, r, v);
			pull(x, z);
		}
		node find(int x, int l, int r, int lx, int rx) {
			if (lx <= l && r <= rx) {
				return tree[x];
			}
			int y = (l + r) >> 1;
			int z = x + ((y - l + 1) << 1);
			push(x, l, r);
			node res{};
			if (rx <= y) {
				res = find(x + 1, l, y, lx, rx);
			} else {
				if (lx > y) {
				res = find(z, y + 1, r, lx, rx);
				} else {
				res = unite(find(x + 1, l, y, lx, rx), find(z, y + 1, r, lx, rx));
				}
			}
			pull(x, z);
			return res;
		}
		template <typename... M>
		void update(int x, int l, int r, int lx, int rx, const M&... v) {
			if (lx <= l && r <= rx) {
				tree[x].apply(l, r, v...);
				return;
			}
			int y = (l + r) >> 1;
			int z = x + ((y - l + 1) << 1);
			push(x, l, r);
			if (lx <= y) {
				update(x + 1, l, y, lx, rx, v...);
			}
			if (rx > y) {
				update(z, y + 1, r, lx, rx, v...);
			}
			pull(x, z);
		}
		template <typename... M>
		void add(int x, int l, int r, int lx, int rx, const M&... v) {
			if (lx <= l && r <= rx) {
				tree[x].push(l, r, v...);
				return;
			}
			int y = (l + r) >> 1;
			int z = x + ((y - l + 1) << 1);
			push(x, l, r);
			if (lx <= y) {
				add(x + 1, l, y, lx, rx, v...);
			}
			if (rx > y) {
				add(z, y + 1, r, lx, rx, v...);
			}
			pull(x, z);
		}
		segtree(){}
		segtree(int _n) : n(_n) {
			assert(n > 0);
			tree.resize(2 * n - 1);
			build(0, 0, n - 1);
		}
		template <typename M>
		segtree(const vector<M> &v) {
			n = v.size();
			assert(n > 0);
			tree.resize(2 * n - 1);
			build(0, 0, n - 1, v);
		}
		node find(int p) { 

			assert(0 <= p && p <= n - 1);
			return find(0, 0, n - 1, p, p);
		}
		template <typename... M>
		void update(int lx, int rx, const M&... v) {
			assert(0 <= lx && lx <= rx && rx <= n - 1);
			update(0, 0, n - 1, lx, rx, v...);
		}
		void add(int i, int v){
			assert(i >= 0 && i < n);
			add(i,i,v);
		}
		

		void update(int i, int v){ 

			assert(i >= 0 && i < n);
			update(i,i,v);
		}
		template <typename... M>
		void add(int lx, int rx, const M&... v) { 

			assert(0 <= lx && lx <= rx && rx <= n - 1);
			add(0, 0, n - 1, lx, rx, v...);
		}
		node find(int lx, int rx) { 

			assert(0 <= lx && lx <= rx && rx <= n - 1);
			return find(0, 0, n - 1, lx, rx);
		}
	};
	
	public:
	int N;
	vector<vector<int>> adj;
	vector<int> a;
	vector<int> label;
	vector<int> par;
	vector<int> depth;
	vector<int> siz;
	vector<int> heavy;
	vector<int> chain_head;
	int tim;
	bool leave_lca;
	LCA lca;
	segtree tr;
	HLD(const vector<vector<int>> &G,vector<int> &values,bool _leave_lca){
		adj = G;
		a = values;
		N = G.size();
		label.resize(N);
		depth.resize(N);
		par.resize(N,-1);
		siz.resize(N);
		heavy.resize(N,-1);
		chain_head.resize(N,-1);
		iota(chain_head.begin(),chain_head.end(),0);
		tim = 0;
		leave_lca = _leave_lca;
		lca = LCA(adj);
		tr = segtree(N);
		sub_dfs(0);
		label_dfs(0);
		chain_dfs(0);
	}
	void sub_dfs(int i,int parent = -1){
		par[i] = parent;
		siz[i] = 1;
		for(int v : adj[i]){
			if(v != parent){
				depth[v] = 1 + depth[i];
				sub_dfs(v,i);
				siz[i] += siz[v];
				if(heavy[i] == -1 || siz[heavy[i]] < siz[v]){
					heavy[i] = v;
				}
			}
		}
	}
	void label_dfs(int i,int parent = -1){
		tr.update(tim,a[i]);
		label[i] = tim++;
		if(heavy[i] != -1)label_dfs(heavy[i],i);
		for(int v : adj[i]){
			if(v != parent && v != heavy[i]){
				label_dfs(v,i);
			}
		}
	}
	void chain_dfs(int i,int parent = -1){
		for(int v : adj[i]){
			if(v != parent){
				if(v == heavy[i]){
					chain_head[v] = chain_head[i];
				}
				chain_dfs(v,i);
			}
		}
	}
	

	segtree::node find(int u,int v,int flag = -1){
		if(flag == -1){
			flag = leave_lca;
		}
		segtree::node res;
		if(u == v){
			return (flag ? res : tr.find(label[u],label[u]));
		}
		int lc = lca.lca(u,v);
		if(flag){
			while(depth[u] > depth[lc]){
				int where = (depth[chain_head[u]] <= depth[lc] ? lc : chain_head[u]);
				if(where == lc){
					res = tr.unite(res,tr.find(label[where]+1,label[u]));
					u = lc;
				}
				else{
					res = tr.unite(res,tr.find(label[where],label[u]));
					u = par[where];
				}
			}
		}
		else{
			while(u != -1 && depth[u] >= depth[lc]){
				int where = (depth[chain_head[u]] <= depth[lc] ? lc : chain_head[u]);
				res = tr.unite(res,tr.find(label[where],label[u]));
				u = par[where];
			}
		}
		u = v;
		while(depth[u] > depth[lc]){
			int where = (depth[chain_head[u]] <= depth[lc] ? lc : chain_head[u]);
			if(where == lc){
				res = tr.unite(res,tr.find(label[where]+1,label[u]));
				u = lc;
			}
			else{
				res = tr.unite(res,tr.find(label[where],label[u]));
				u = par[where];
			}
		}
		return res;
	}
	void update(int i,int v){
		tr.update(label[i],v);
	}
	void add(int u,int v,int x, int flag = -1){
		if(flag == -1)flag = leave_lca;
		if(u == v){
			if(flag)return;
			tr.add(label[u],label[u],x);
			return;
		}
		int lc = lca.lca(u,v);
		if(flag){
			while(depth[u] > depth[lc]){
				int where = (depth[chain_head[u]] <= depth[lc] ? lc : chain_head[u]);
				if(where == lc){
					tr.add(label[where]+1,label[u],x);
					u = lc;
				}
				else{
					tr.add(label[where],label[u],x);
					u = par[where];
				}
			}
		}
		else{
			while(u != -1 && depth[u] >= depth[lc]){
				int where = (depth[chain_head[u]] <= depth[lc] ? lc : chain_head[u]);
				tr.add(label[where],label[u],x);
				u = par[where];
			}
		}
		u = v;
		while(depth[u] > depth[lc]){
			int where = (depth[chain_head[u]] <= depth[lc] ? lc : chain_head[u]);
			if(where == lc){
				tr.add(label[where]+1,label[u],x);
				u = lc;
			}
			else{
				tr.add(label[where],label[u],x);
				u = par[where];
			}
		}
	}
};





void testcase(){
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	vector<pair<int,int>> edg;
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
		edg.push_back({u,v});
	}
	vector<int> par(n,-1);
	function<void(int)> dfs = [&](int i){
		for(int node : graph[i]){
			if(node != par[i]){
				par[node] = i;
				dfs(node);
			}
		}
	}; dfs(0);
	vector<int> a(n);
	for(int i = 0; i < (int)edg.size(); i++){
		auto [u,v] = edg[i];
		if(par[v] == u)swap(u,v);
		assert(par[u] == v);
		a[u] = i+1;
	}
	HLD hld(graph,a,false);
	int cnt = 1,tot = 1;
	long long int sum = 0;
	bool last = false;
	vector<bool> active(n,false);
	active[0] = true;
	while(true){
		int t;
		cin >> t;
		if(t == 3)return;
		if(t == 1){
			tot++;
			int u;
			cin >> u;
			u--;
			assert(!active[u]);active[u] = true;
			auto here = hld.find(par[u],0);
			sum -= here.osum;
			cnt -= here.cnt;
			hld.add(par[u],0,1);
			here = hld.find(u,0);
			sum += here.osum;
			cnt += here.cnt;
			last = (cnt == tot - cnt);
			cout << (last ? sum : 0ll) << endl;
		}
		else{
			if(!last){
				cout << 0 << endl;
				continue;
			}
			vector<int> ans;
			for(int i = 1; i < n; i++){
				if(!active[i])continue;
				if(hld.find(0,i).cnt != hld.find(0,par[i]).cnt){
					ans.push_back(a[i]);
				}
			}
			sort(ans.begin(),ans.end());
			cout << ans.size() << ' ' << ans << endl;
		}
	}
}

int main(){
	int tt = 1;
	

	while(tt--){
		testcase();
	}
	return (0-0);
}
