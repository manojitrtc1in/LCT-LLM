





using namespace std;


using namespace atcoder;



































template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;



template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}

std::istream &operator>>(std::istream &is, atcoder::modint998244353 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
std::istream &operator>>(std::istream &is, atcoder::modint1000000007 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::static_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}

namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  


	std::vector<type> name(size); \
	scanner::INPUT(name)

	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)

	int id4; \
	scanner::INPUT(id4)

	long long id4; \
	scanner::INPUT(id4)

	std::string id4; \
	scanner::INPUT(id4)

	char id4; \
	scanner::INPUT(id4)

	double id4; \
	scanner::INPUT(id4)

	long double id4; \
	scanner::INPUT(id4)



template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}

std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &a) { return os << a.val(); }
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<m> &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::dynamic_modint<m> &a) { return os << a.val(); }

template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}



namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  


void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}

	do {                                                          \
		std::cerr << __LINE__ << " [" << 
		debug_out(id4);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)






template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}




template <class T>
void ADD(std::vector<T> &a, const T x) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}



template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}


long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}



struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} id10;
const int inf = 1e9;
const ll INF = 1e18;










struct Edge {
	int to;
	long long cost;
	Edge() = default;
	Edge(int to_, long long cost_) : to(to_), cost(cost_) {}
	bool operator<(const Edge &a) const { return cost < a.cost; }
	bool operator>(const Edge &a) const { return cost > a.cost; }
	friend std::ostream &operator<<(std::ostream &s, Edge &a) {
		s << "to: " << a.to << ", cost: " << a.cost;
		return s;
	}
};

class Graph {
	std::vector<std::vector<Edge>> edges;

public:
	inline const std::vector<Edge> &operator[](int k) const { return edges[k]; }
	inline std::vector<Edge> &operator[](int k) { return edges[k]; }

	int size() const { return edges.size(); }
	void resize(const int n) { edges.resize(n); }

	Graph() = default;
	Graph(int n) : edges(n) {}
	Graph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) : edges(n) { input(e, weight, directed, idx); }
	const long long INF = 3e18;

	void input(int e = -1, bool weight = 0, bool directed = false, int idx = 1) {
		if(e == -1) e = size() - 1;
		while(e--) {
			int u, v;
			long long cost = 1;
			std::cin >> u >> v;
			if(weight) std::cin >> cost;
			u -= idx, v -= idx;
			edges[u].emplace_back(v, cost);
			if(!directed) edges[v].emplace_back(u, cost);
		}
	}

	void add_edge(int u, int v, long long cost = 1, bool directed = false, int idx = 0) {
		u -= idx, v -= idx;
		edges[u].emplace_back(v, cost);
		if(!directed) edges[v].emplace_back(u, cost);
	}

	

	std::vector<long long> bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::queue<int> que;
		dist[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int v = que.front();
			que.pop();
			for(auto &e : edges[v]) {
				if(dist[e.to] != INF) continue;
				dist[e.to] = dist[v] + e.cost;
				que.push(e.to);
			}
		}
		return dist;
	}

	

	

	std::vector<long long> zero_one_bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::deque<int> deq;
		dist[s] = 0;
		deq.push_back(s);
		while(!deq.empty()) {
			int v = deq.front();
			deq.pop_front();
			for(auto &e : edges[v]) {
				assert(0LL <= e.cost and e.cost < 2LL);
				if(e.cost and dist[e.to] > dist[v] + 1) {
					dist[e.to] = dist[v] + 1;
					deq.push_back(e.to);
				} else if(!e.cost and dist[e.to] > dist[v]) {
					dist[e.to] = dist[v];
					deq.push_front(e.to);
				}
			}
		}
		return dist;
	}

	

	

	std::vector<long long> dijkstra(int s) {  

		std::vector<long long> dist(size(), INF);
		const auto compare = [](const std::pair<long long, int> &a, const std::pair<long long, int> &b) { return a.first > b.first; };
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, decltype(compare)> que{compare};
		dist[s] = 0;
		que.emplace(0, s);
		while(!que.empty()) {
			std::pair<long long, int> p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(auto &e : edges[v]) {
				if(dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					que.emplace(dist[e.to], e.to);
				}
			}
		}
		return dist;
	}

	

	

	

	std::vector<long long> bellman_ford(int s) {  

		int n = size();
		std::vector<long long> res(n, INF);
		res[s] = 0;
		for(int loop = 0; loop < n - 1; loop++) {
			for(int v = 0; v < n; v++) {
				if(res[v] == INF) continue;
				for(auto &e : edges[v]) {
					res[e.to] = std::min(res[e.to], res[v] + e.cost);
				}
			}
		}
		std::queue<int> que;
		std::vector<int> chk(n);
		for(int v = 0; v < n; v++) {
			if(res[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(res[e.to] > res[v] + e.cost and !chk[e.to]) {
					que.push(e.to);
					chk[e.to] = 1;
				}
			}
		}
		while(!que.empty()) {
			int now = que.front();
			que.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					que.push(e.to);
				}
			}
		}
		for(int i = 0; i < n; i++)
			if(chk[i]) res[i] = -INF;
		return res;
	}

	

	std::vector<std::vector<long long>> warshall_floyd() {  

		int n = size();
		std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));
		for(int i = 0; i < n; i++) dist[i][i] = 0;
		for(int i = 0; i < n; i++)
			for(auto &e : edges[i]) dist[i][e.to] = std::min(dist[i][e.to], e.cost);
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++) {
				if(dist[i][k] == INF) continue;
				for(int j = 0; j < n; j++) {
					if(dist[k][j] == INF) continue;
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		return dist;
	}

	

	

	std::vector<int> topological_sort() {  

		std::vector<int> res;
		int n = size();
		std::vector<int> used(n, 0);
		bool id9 = false;
		auto dfs = [&](auto self, int k) -> void {
			if(id9) return;
			if(used[k]) {
				if(used[k] == 1) id9 = true;
				return;
			}
			used[k] = 1;
			for(auto &e : edges[k]) self(self, e.to);
			used[k] = 2;
			res.push_back(k);
		};
		for(int i = 0; i < n; i++) dfs(dfs, i);
		if(id9) return std::vector<int>{};
		std::reverse(res.begin(), res.end());
		return res;
	}

	bool is_DAG() { return !topological_sort().empty(); }  


	

	

	std::vector<long long> height() {  

		auto vec1 = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v1 = i;
		vec1 = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v2 = i;
		auto vec2 = bfs(v2);
		for(int i = 0; i < int(size()); i++) {
			if(vec1[i] < vec2[i]) vec1[i] = vec2[i];
		}
		return vec1;
	}

	

	

	

	std::vector<int> bipartite_grouping() {
		std::vector<int> colors(size(), -1);
		auto dfs = [&](auto self, int now, int col) -> bool {
			colors[now] = col;
			for(auto &e : edges[now]) {
				if(col == colors[e.to]) return false;
				if(colors[e.to] == -1 and !self(self, e.to, !col)) return false;
			}
			return true;
		};
		for(int i = 0; i < int(size()); i++)
			if(!colors[i] and !dfs(dfs, i, 0)) return std::vector<int>{};
		return colors;
	}

	bool is_bipartite() { return !bipartite_grouping().empty(); }

	

	

	std::pair<std::pair<int, int>, long long> diameter() {  

		auto vec = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v1 = i;
		vec = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v2 = i;
		std::pair<std::pair<int, int>, long long> res = {{v1, v2}, dia};
		return res;
	}

	

	long long prim() {  

		long long res = 0;
		std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> que;
		for(auto &e : edges[0]) que.push(e);
		std::vector<int> chk(size());
		chk[0] = 1;
		int cnt = 1;
		while(cnt < size()) {
			auto e = que.top();
			que.pop();
			if(chk[e.to]) continue;
			cnt++;
			res += e.cost;
			chk[e.to] = 1;
			for(auto &e2 : edges[e.to]) que.push(e2);
		}
		return res;
	}

	

	long long kruskal() {  

		std::vector<std::tuple<int, int, long long>> Edges;
		for(int i = 0; i < int(size()); i++)
			for(auto &e : edges[i]) Edges.emplace_back(i, e.to, e.cost);
		std::sort(Edges.begin(), Edges.end(), [](const std::tuple<int, int, long long> &a, const std::tuple<int, int, long long> &b) {
			return std::get<2>(a) < std::get<2>(b);
		});
		std::vector<int> uf_data(size(), -1);
		auto root = [&uf_data](auto self, int x) -> int {
			if(uf_data[x] < 0) return x;
			return uf_data[x] = self(self, uf_data[x]);
		};
		auto unite = [&uf_data, &root](int u, int v) -> bool {
			u = root(root, u), v = root(root, v);
			if(u == v) return false;
			if(uf_data[u] > uf_data[v]) std::swap(u, v);
			uf_data[u] += uf_data[v];
			uf_data[v] = u;
			return true;
		};
		long long ret = 0;
		for(auto &e : Edges)
			if(unite(std::get<0>(e), std::get<1>(e))) ret += std::get<2>(e);
		return ret;
	}

	

	std::vector<int> centroid() {
		int n = size();
		std::vector<int> centroid, sz(n);
		auto dfs = [&](auto self, int now, int per) -> void {
			sz[now] = 1;
			bool id8 = true;
			for(auto &e : edges[now]) {
				if(e.to != per) {
					self(self, e.to, now);
					sz[now] += sz[e.to];
					if(sz[e.to] > n / 2) id8 = false;
				}
			}
			if(n - sz[now] > n / 2) id8 = false;
			if(id8) centroid.push_back(now);
		};
		dfs(dfs, 0, -1);
		return centroid;
	}

	

	

	Graph root_to_leaf(int root = 0) {
		Graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(now, e.to, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	

	

	Graph leaf_to_root(int root = 0) {
		Graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(e.to, now, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	

};

struct id0 {
private:
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;
	std::vector<long long> dist;
	int max_jump = 1;

	void build() {
		for(int i = 0; i < max_jump - 1; i++) {
			for(int v = 0; v < (int)dist.size(); v++) {
				if(parent[i][v] == -1)
					parent[i + 1][v] = -1;
				else
					parent[i + 1][v] = parent[i][parent[i][v]];
			}
		}
	}

public:
	id0() = default;
	id0(const Graph &g, const int root = 0) : dist(g.size()), depth(g.size()) {
		int n = g.size();
		while((1 << max_jump) < n) max_jump++;
		parent.assign(max_jump, std::vector<int>(n, -1));
		auto dfs = [&](auto self, int now, int per, int d, long long cost) -> void {
			parent[0][now] = per;
			depth[now] = d;
			dist[now] = cost;
			for(auto &e : g[now])
				if(e.to != per) self(self, e.to, now, d + 1, cost + e.cost);
		};
		dfs(dfs, root, -1, 0, 0LL);
		build();
	}

	int lowest_common_ancestor(int u, int v) {
		if(depth[u] < depth[v]) std::swap(u, v);
		int k = parent.size();
		for(int i = 0; i < k; i++)
			if((depth[u] - depth[v]) >> i & 1) u = parent[i][u];
		if(u == v) return u;
		for(int i = k - 1; i >= 0; i--)
			if(parent[i][u] != parent[i][v]) u = parent[i][u], v = parent[i][v];
		return parent[0][u];
	}

	long long length_of_path(const int u, const int v) { return dist[u] + dist[v] - dist[lowest_common_ancestor(u, v)] * 2; }

	int level_ancestor(int v, int level) {
		assert(level >= 0);
		for(int jump = 0; jump < max_jump and level; jump++) {
			if(level & 1) v = parent[jump][v];
			level >>= 1;
		}
		return v;
	}
};

struct id1 {
private:
	enum { CHECKED = -1,
		   UNCHECKED = -2 };
	const Graph &graph_given;
	Graph graph_reversed;
	std::vector<int> order, group_number; 

	void dfs(int now) {
		if(group_number[now] != UNCHECKED) return;
		group_number[now] = CHECKED;
		for(auto &e : graph_given[now]) dfs(e.to);
		order.push_back(now);
	}

	void rdfs(int now, int group_count) {
		if(group_number[now] != UNCHECKED) return;
		group_number[now] = group_count;
		for(auto &e : graph_reversed[now]) rdfs(e.to, group_count);
	}

	void build(bool id7) {
		for(int i = 0; i < (int)graph_given.size(); i++) dfs(i);
		reverse(order.begin(), order.end());
		group_number.assign(graph_given.size(), UNCHECKED);
		int group = 0;
		for(auto &i : order)
			if(group_number[i] == UNCHECKED) rdfs(i, group), group++;
		graph_compressed.resize(group);
		groups.resize(group);
		for(int i = 0; i < (int)graph_given.size(); i++) groups[group_number[i]].push_back(i);
		if(id7) {
			std::vector<int> edges(group, -1);
			for(int i = 0; i < group; i++)
				for(auto &vertex : groups[i])
					for(auto &e : graph_given[vertex])
						if(group_number[e.to] != i and edges[group_number[e.to]] != i) {
							edges[group_number[e.to]] = i;
							graph_compressed[i].emplace_back(group_number[e.to], 1);
						}
		}
		return;
	}

public:
	std::vector<std::vector<int>> groups;
	Graph graph_compressed;

	id1(const Graph &g_, bool id7 = false)
	  : graph_given(g_), graph_reversed(g_.size()), group_number(g_.size(), UNCHECKED) {
		for(size_t i = 0; i < g_.size(); i++)
			for(auto &e : graph_given[i]) graph_reversed[e.to].emplace_back(i, 1);
		build(id7);
	}

	const int &operator[](const int k) { return group_number[k]; }
};

struct low_link {
private:
	const Graph &graph_given;
	int order_next;

	void build() {
		int n = graph_given.size();
		order.resize(n, -1);
		low.resize(n);
		order_next = 0;
		for(int i = 0; i < n; i++)
			if(order[i] == -1) dfs(i);
	}

	void dfs(int now, int par = -1) {
		low[now] = order[now] = order_next++;
		bool id6 = false;
		int cnt = 0, cnt_par = 0;
		for(const auto &ed : graph_given[now]) {
			const int &nxt = ed.to;
			if(order[nxt] == -1) {
				cnt++;
				dfs(nxt, now);
				if(order[now] < low[nxt]) bridge.push_back(std::minmax(now, nxt));
				if(order[now] <= low[nxt]) id6 = true;
				low[now] = std::min(low[now], low[nxt]);
			} else if(nxt != par or cnt_par++ == 1) {
				low[now] = std::min(low[now], order[nxt]);
			}
		}
		if(par == -1 and cnt < 2) id6 = false;
		if(id6) articulation.push_back(now);
		return;
	}

public:
	std::vector<int> order, low, articulation;
	std::vector<std::pair<int, int>> bridge;
	low_link() = default;
	low_link(const Graph &g_) : graph_given(g_) { build(); }
};

struct id2 {
private:
	const Graph &graph_given;
	int group_next;
	low_link li;
	std::vector<int> group_number;

	void build(bool id7) {
		int n = graph_given.size();
		group_number.resize(n, -1);
		group_next = 0;
		for(int i = 0; i < n; i++)
			if(group_number[i] == -1) dfs(i);
		groups.resize(group_next);
		for(int i = 0; i < graph_given.size(); i++) groups[group_number[i]].push_back(i);

		if(id7) {
			graph_compressed.resize(group_next);
			for(const auto &[u, v] : li.bridge) {
				int x = group_number[u], y = group_number[v];
				graph_compressed.add_edge(x, y);
			}
		}
	}

	void dfs(int now, int par = -1) {
		if(par != -1 and li.order[par] >= li.low[now])
			group_number[now] = group_number[par];
		else
			group_number[now] = group_next++;
		for(const auto &e : graph_given[now])
			if(group_number[e.to] == -1) dfs(e.to, now);
	}

public:
	Graph graph_compressed;
	std::vector<std::vector<int>> groups;
	id2(const Graph &g_, bool id7 = false)
	  : graph_given(g_), li(g_) {
		build(id7);
	}

	const int &operator[](const int k) { return group_number[k]; }
};

struct id5 {
public:
	std::vector<int> sz, in, out, head, rev, par;

private:
	Graph &g;

	void dfs_sz(int v, int p = -1) {
		par[v] = p;
		if(!g[v].empty() and g[v].front().to == p) std::swap(g[v].front(), g[v].back());
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			dfs_sz(e.to, v);
			sz[v] += sz[e.to];
			if(sz[g[v].front().to] < sz[e.to]) std::swap(g[v].front(), e);
		}
	}

	void dfs_hld(int v, int &t, int p = -1) {
		in[v] = t++;
		rev[in[v]] = v;
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			head[e.to] = (g[v].front().to == e.to ? head[v] : e.to);
			dfs_hld(e.to, t, v);
		}
		out[v] = t;
	}

	void build(int root = 0) {
		dfs_sz(root);
		int t = 0;
		head[root] = root;
		dfs_hld(root, t);
	}

public:
	id5(Graph &g_, int root = 0) : g(g_) {
		int n = g.size();
		sz.resize(n, 1);
		in.resize(n);
		out.resize(n);
		head.resize(n);
		rev.resize(n);
		par.resize(n);
		build(root);
	}

	int level_ancestor(int v, int level) {
		while(true) {
			int u = head[v];
			if(in[v] - level >= in[u]) return rev[in[v] - level];
			level -= in[v] - in[u] + 1;
			v = par[u];
		}
	}

	int lowest_common_ancestor(int u, int v) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) return u;
		}
	}

	

	template <typename T, typename Q, typename F>
	T query(int u, int v, const T &unit, const Q &q, const F &f, bool edge = false) {
		T l = unit, r = unit;
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v), std::swap(l, r);
			if(head[u] == head[v]) break;
			l = f(q(in[head[v]], in[v] + 1), l);
		}
		return f(f(q(in[u] + edge, in[v] + 1), l), r);
	}

	

	template <typename Q>
	void add(int u, int v, const Q &q, bool edge = false) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) break;
			q(in[head[v]], in[v] + 1);
		}
		q(in[u] + edge, in[v] + 1);
	}

	std::pair<int, int> subtree(int v, bool edge = false) { return std::pair<int, int>(in[v] + edge, out[v]); }
};


void main_() {
	INT(n, m);
	Graph G(n, m, 1, 1);
	id1 scc(G);

	auto groups = scc.groups;
	int sz = groups.size();
	V<ll> id3(sz, -1);
	for(auto &vec : groups) {
		int k = SZ(vec);
		auto s = vec.front();
		auto c = vec;
		auto re = press(c);
		auto encode = [&re](int x) {
			return lb(re, x);
		};

		std::vector<long long> dist(k, INF);
		const auto compare = [](const std::pair<long long, int> &a, const std::pair<long long, int> &b) { return a.first > b.first; };
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, decltype(compare)> que{compare};
		dist[encode(s)] = 0;
		que.emplace(0, s);

        

        

		while(!que.empty()) {
			std::pair<long long, int> p = que.top();
			que.pop();
			int v = p.second;
			if(dist[encode(v)] < p.first) continue;
			for(auto &e : G[v]) {
				if(scc[e.to] != scc[s]) continue;
				int to = encode(e.to);
				if(dist[to] > dist[encode(v)] + e.cost) {
					dist[to] = dist[encode(v)] + e.cost;
					que.emplace(dist[to], e.to);
				}
			}
		}
		ll fold = 0;
		REP(i, k) {
			for(auto &[to, cost] : G[re[i]]) {
				if(scc[to] != scc[s]) continue;
				if(to == s) {
					fold = gcd(fold, dist[i] + cost);
				} else {
					fold = gcd(fold, abs(dist[encode(to)] - (dist[i] + cost)));
				}
			}
		}
		id3[scc[s]] = fold;
	}
	debug(groups);
	debug(id3);

	INT(q);
	while(q--) {
		INT(st, s, t);
		--st;
		ll g = id3[scc[st]];
		g %= t;
		if(g == 0) {
			YES(s == 0);
			continue;
		}
		g = gcd(t, g);
		YES(s == 0 or (t - s) % g == 0);
	}
}

int main() {
	int t = 1;
	

	while(t--) main_();
	return 0;
}