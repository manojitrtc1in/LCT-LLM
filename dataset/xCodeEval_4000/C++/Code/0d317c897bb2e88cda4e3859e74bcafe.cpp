


#include <bits/stdc++.h>
#include <bits/extc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace __gnu_pbds;

template <typename A, typename B = std::less <A>> using ordered_set =
tree <A, null_type, B, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B, typename C = std::less <A>> using ordered_map =
tree <A, B, C, rb_tree_tag, tree_order_statistics_node_update>;

void prep();
void solv(const int curt);

const bool isT = true;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	prep();
	
	int t = 1; if (isT) { std::cin >> t; }
	for (int i = 1; i <= t; i++) { solv(i); }
	
	return 0;
}

template <typename A> std::string bs(A x, int digs) {
	std::string r(digs, '0');
	for (int i = 0; i < digs; i++) {
		r[digs - i - 1] += (x >> i) & 1;
	}
	return r;
}

template <typename A> std::string bs(A x) {
	std::string r;
	while (x) {
		r += (x & 1) + '0';
		x >>= 1;
	}
	std::reverse(r.begin(), r.end());
	return r;
}

namespace dbg_pr {
	
	std::string to_string(const std::string& s);
	std::string to_string(const char* s);
	std::string to_string(const bool& b);
	std::string to_string(const char& c);
	std::string to_string(const std::vector <bool>& v);
	template <typename A> std::string to_string(A x);
	template <typename A, typename B> std::string to_string(std::pair <A, B> p);
	template <typename A> std::string to_string(const std::vector <A>& v);
	template <typename A> std::string to_string(const std::set <A>& st);
	template <typename A, typename B> std::string to_string(const std::set <A, B>& st);
	template <typename A> std::string to_string(const std::unordered_set <A>& st);
	template <typename A, typename B> std::string to_string(const std::unordered_set <A, B>& st);
	template <typename A, typename B> std::string to_string(const std::map <A, B>& mp);
	template <typename A, typename B, typename C> std::string to_string(const std::map <A, B, C>& mp);
	template <typename A, typename B> std::string to_string(const std::unordered_map <A, B>& mp);
	template <typename A, typename B, typename C> std::string to_string(const std::unordered_map <A, B, C>& mp);
	template <typename A> std::string to_string(const std::queue <A>& q);
	template <typename A> std::string to_string(const std::priority_queue <A>& pq);
	template <typename A, typename B, typename C> std::string to_string(const std::priority_queue <A, B, C>& pq);
	template <typename A> std::string to_string(const std::stack <A>& stck);
	template <typename A> std::string to_string(const std::deque <A>& q);
	template <typename A, size_t size> std::string to_string(const std::array <A, size>& a);
	template <typename A, typename B> std::string to_string(const __gnu_pbds::tree <A, __gnu_pbds::null_type, B, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& st);
	template <typename A, typename B, typename C> std::string to_string(const __gnu_pbds::tree <A, B, C, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& mp);
	
	std::string to_string(const std::string& s) {
		return '"' + s + '"';
	}
	
	std::string to_string(const char* s) {
		return to_string((std::string)s);
	}
	
	std::string to_string(const bool& b) {
		return b ? "true" : "false";
	}
	
	std::string to_string(const char& c) {
		return (std::string)"'" + c + "'";
	}
	
	std::string to_string(const std::vector <bool>& v) {
		if (v.empty()) {
			return "{ }";
		}
		std::string ret = "{";
		for (auto it = v.begin(); it != v.end(); it++) {
			ret += to_string(*it) + (next(it) == v.end() ? "}" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(A x) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(3) << x;
		return stream.str();
	}
	
	template <typename A, typename B> std::string to_string(std::pair <A, B> p) {
		return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
	}
	
	template <typename A> std::string to_string(const std::vector <A>& v) {
		if (v.empty()) {
			return "{ }";
		}
		std::string ret = "{";
		for (auto it = v.begin(); it != v.end(); it++) {
			ret += to_string(*it) + (next(it) == v.end() ? "}" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::set <A>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::set <A, B>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::unordered_set <A>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::unordered_set <A, B>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::map <A, B>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const std::map <A, B, C>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const std::unordered_map <A, B>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const std::unordered_map <A, B, C>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::queue <A>& q) {
		if (q.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto Q = q;
		while (!Q.empty()) {
			auto now = Q.front();
			Q.pop();
			ret += to_string(now) + (Q.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::priority_queue <A>& pq) {
		if (pq.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto PQ = pq;
		while (!PQ.empty()) {
			auto now = PQ.top();
			PQ.pop();
			ret += to_string(now) + (PQ.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const std::priority_queue <A, B, C>& pq) {
		if (pq.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto PQ = pq;
		while (!PQ.empty()) {
			auto now = PQ.top();
			PQ.pop();
			ret += to_string(now) + (PQ.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::stack <A>& stck) {
		if (stck.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		auto STCK = stck;
		while (!STCK.empty()) {
			auto now = STCK.top();
			STCK.pop();
			ret += to_string(now) + (STCK.empty() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A> std::string to_string(const std::deque <A>& q) {
		if (q.empty()) {
			return "[ ";
		}
		std::string ret = "[";
		for (auto it = q.begin(); it != q.end(); it++) {
			ret += to_string(*it) + (next(it) == q.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, size_t size> std::string to_string(const std::array <A, size>& a) {
		std::string ret = "(";
		for (size_t i = 0; i < size; i++) {
			ret += to_string(a[i]) + (i + size_t(1) == size ? ")" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B> std::string to_string(const __gnu_pbds::tree <A, __gnu_pbds::null_type, B, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const __gnu_pbds::tree <A, B, C, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& mp) {
		if (mp.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == mp.end() ? ")]" : "), ");
		}
		return ret;
	}
	
	void debug_out() {
		std::cerr << std::endl;
	}
	
	template <typename A, typename... B> void debug_out(A a, B... b) {
		std::cerr << "\033[96m " << to_string(a) << "\033[0m";
		debug_out(b...);
	}
	
	void debum_out() {
		std::cerr << std::endl;
	}
	
	void debum_tab(const int cnt = 1) {
		for (int i = 0; i < cnt; i++) {
			std::cerr << " ";
		}
	}
	
	template <typename A> void debum_out(A a) {
		for (auto it = a.begin(); it != a.end(); it++) {
			debum_tab(1);
			std::cerr << "\033[96m[ " << to_string(*it) << " ]\033[0m" << std::endl;
		}
	}
	
}

#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "\033[94m[" << #__VA_ARGS__ << "]:\033[0m", dbg_pr::debug_out(__VA_ARGS__)
#define debum(...) std::cerr << "\033[94m[" << #__VA_ARGS__ << "]:\033[0m\n", dbg_pr::debum_out(__VA_ARGS__)
#else
#define debug(...)
#define debum(...)
#endif

template <typename A> class Graph {
	
public:
	
	struct Edge {
		
		int from, to;
		A weight;
		
		Edge(int _from = -1, int _to = -1, A _weight = 0) :
		from(_from),
		to(_to),
		weight(_weight)
		{ }
		
		friend std::ostream& operator << (std::ostream& stream, const Edge& edge) {
			stream << "{[" << edge.from << " -> " << edge.to << "]: (" << edge.weight << ")}";
			return stream;
		}
		
	};
	
	std::vector <Edge> edges;
	std::vector <std::vector <int>> g;
	int size;
	
	Graph(int _size) :
	g(_size),
	size(_size)
	{ }
	
	virtual int add(int from, int to, A weight = 1) {
		assert(from >= 0 && from < size && to >= 0 && to < size);
		int ind = edges.size();
		g[from].push_back(ind);
		edges.emplace_back(from, to, weight);
		return ind;
	}
	
	virtual std::vector <int>& operator [] (int ind) {
		assert(ind >= 0 && ind < size);
		return g[ind];
	}
	
	virtual const std::vector <int>& operator [] (int ind) const {
		assert(ind >= 0 && ind < size);
		return g[ind];
	}
	
	friend std::ostream& operator << (std::ostream& stream, const Graph& graph) {
		stream << "[\n";
		for (int i = 0; i < graph.size; i++) {
			stream << "  " << i << ": {";
			for (int j = 0; j < (int)graph[i].size(); j++) {
				stream << "(" << graph.edges[graph[i][j]].to << ": ";
				stream << graph.edges[graph[i][j]].weight << ")";
				if (j + 1 != (int)graph[i].size()) {
					stream << ", ";
				}
			}
			stream << "}\n";
		}
		stream << "]";
		return stream;
	}
	
};

template <typename A> class Forest : public Graph <A> {
	
public:
	
	using Graph <A>::edges;
	using Graph <A>::g;
	using Graph <A>::size;
	
	Forest(int _size) :
	Graph <A> (_size)
	{ }
	
	int add(int from, int to, A weight = 1) override {
		assert(from >= 0 && from < size && to >= 0 && to < size);
		int ind = edges.size();
		assert(ind < size - 1);
		g[from].push_back(ind);
		g[to].push_back(ind);
		edges.emplace_back(from, to, weight);
		return ind;
	}
	
};

template <typename A> class Dfs_forest : public Forest <A> {
	
public:
	
	using Forest <A>::edges;
	using Forest <A>::g;
	using Forest <A>::size;
	
	std::vector <int> par_node, par_edge, pre, post, order, sub, root, dep;
	std::vector <A> dist;
	
	Dfs_forest(int _size, bool _init = false) :
	Forest <A> (_size)
	{ 
		if (_init) {
			init();
		}
	}
	
	void init() {
		par_node = par_edge = pre = post = std::vector <int> (size, -1);
		order.clear();
		sub = std::vector <int> (size, 0);
		root = dep = std::vector <int> (size, -1);
		dist = std::vector <A> (size);
	}
	
	void clear() {
		par_node.clear();
		par_edge.clear();
		pre.clear();
		post.clear();
		order.clear();
		sub.clear();
		root.clear();
		dep.clear();
		dist.clear();
	}
	
	void dfs(int node, bool reset_order = true) {
		if (par_node.empty()) {
			init();
		} else if (reset_order) {
			order.clear();
		}
		m_dfs_from(node);
	}
	
	void dfs_all() {
		init();
		for (int i = 0; i < size; i++) {
			if (dep[i] != -1) {
				continue;
			}
			m_dfs_from(i);
		}
		assert(size == (int)order.size());
	}
	
private:
	
	void m_dfs(int node) {
		pre[node] = order.size();
		order.push_back(node);
		sub[node] = 1;
		for (int x : g[node]) {
			if (x == par_edge[node]) {
				continue;
			}
			auto& e = edges[x];
			int v = e.from ^ e.to ^ node;
			dep[v] = dep[node] + 1;
			dist[v] = dist[node] + e.weight;
			par_node[v] = node;
			par_edge[v] = x;
			root[v] = root[node];
			m_dfs(v);
			sub[node] += sub[v];
		}
		post[node] = (int)order.size() - 1;
	}
	
	void m_dfs_from(int node) {
		m_prep_dfs(node);
		m_dfs(node);
	}
	
	void m_prep_dfs(int node) {
		dep[node] = 0;
		dist[node] = A { };
		root[node] = node;
		par_node[node] = par_edge[node] = -1;
	}
	
};

void prep() {
	
}

void solv(const int curt) {
	
	int n; std::cin >> n;
	Dfs_forest <int> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v;
		g.add(u, v);
	}
	g.dfs(0);
	std::vector <ll> ans(n + 1, 0);
	ans[0] = ans[1] = ((ll)n * (n - 1)) >> 1;
	for (int x : g.g[0]) {
		int s = g.sub[g.edges[x].from ^ g.edges[x].to];
		ans[1] -= ((ll)s * (s - 1)) >> 1;
	}
	std::vector <bool> vis(n, false);
	int u = 0, v = 1, node = 1, dir;
	while (node) {
		vis[node] = true;
		dir = node;
		node = g.par_node[node];
	}
	vis[0] = true;
	for (int i = 3; i <= n + 1; i++) {
		ans[i - 1] = ll(u ? g.sub[u] : n - g.sub[dir]) * g.sub[v];
		if (i - 1 == n || vis[i - 1]) {
			continue;
		}
		node = i - 1;
		while (!vis[node]) {
			vis[node] = true;
			node = g.par_node[node];
		}
		if (node != u && node != v) {
			break;
		}
		if (node == u) {
			u = i - 1;
		}
		if (node == v) {
			v = i - 1;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] - ans[i + 1] << " ";
	}
	std::cout << ans[n] << "\n";
	
}
