







namespace lc {
struct Edge {
	int to;
	explicit Edge(int to) : to(to) { }
};
}
namespace lc {
template <typename EdgeType>
class id13 {
public:
	typedef std::vector<EdgeType> ListType;
private:
	std::vector<ListType> m_lists;
public:
	explicit id13(int n = 0)
		: m_lists(n)
	{ }
	int size() const { return m_lists.size(); }
	template <typename... Args>
	void add_edge(int u, Args&&... args){
		m_lists[u].emplace_back(args...);
	}
	const ListType &operator[](int u) const { return m_lists[u]; }
};
}
namespace lc {
template <class T>
class id3 {
private:
	std::vector<T> m_coords;
public:
	id3() : m_coords() { }
	void push(const T &x){
		m_coords.push_back(x);
	}
	size_t build(){
		sort(m_coords.begin(), m_coords.end());
		m_coords.erase(
			unique(m_coords.begin(), m_coords.end()), m_coords.end());
		return m_coords.size();
	}
	size_t compress(const T &x) const {
		return std::lower_bound(
			m_coords.begin(), m_coords.end(), x) - m_coords.begin();
	}
	const T &decompress(const size_t x) const {
		return m_coords[x];
	}
};
}
namespace lc {
template <typename EdgeType>
class ConnectedComponents {
public:
	typedef lc::id13<EdgeType> GraphType;
private:
	std::vector<std::pair<int, int>> m_compress_table;
	std::vector<std::vector<int>> m_decompress_table;
	std::vector<GraphType> m_contracted_graphs;
public:
	ConnectedComponents(const GraphType &graph)
		: m_compress_table(graph.size(), std::make_pair(-1, -1))
		, m_decompress_table()
		, m_contracted_graphs()
	{
		const int n = graph.size();
		int current_component = 0;
		for(int root = 0; root < n; ++root){
			if(m_compress_table[root].first >= 0){ continue; }
			id3<int> comp;
			std::queue<int> q;
			q.push(root);
			m_compress_table[root].first = current_component;
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				comp.push(u);
				for(const auto &e : graph[u]){
					if(m_compress_table[e.to].first >= 0){ continue; }
					m_compress_table[e.to].first = current_component;
					q.push(e.to);
				}
			}
			const int m = comp.build();
			m_decompress_table.emplace_back(m);
			GraphType contracted(m);
			for(int cu = 0; cu < m; ++cu){
				const int u = comp.decompress(cu);
				m_compress_table[u].second = cu;
				m_decompress_table[current_component][cu] = u;
				for(const auto &e : graph[u]){
					const int v = e.to, cv = comp.compress(v);
					EdgeType f(e);
					f.to = cv;
					contracted.add_edge(cu, f);
				}
			}
			m_contracted_graphs.emplace_back(std::move(contracted));
			++current_component;
		}
	}
	int size() const { return m_contracted_graphs.size(); }
	const GraphType &contracted_graph(int component_id) const {
		return m_contracted_graphs[component_id];
	}
	int component_id(int v) const { return m_compress_table[v].first; }
	int local_vertex_id(int v) const { return m_compress_table[v].second; }
};
template <typename EdgeType>
ConnectedComponents<EdgeType> connected_components(
	const id13<EdgeType> &graph)
{
	return ConnectedComponents<EdgeType>(graph);
}
}
namespace lc {
class id5 {
private:
	std::vector<int> m_parent;
	std::vector<int> m_rank;
public:
	explicit id5(int n = 0)
		: m_parent(n)
		, m_rank(n)
	{
		for(int i = 0; i < n; ++i){ m_parent[i] = i; }
	}
	int find(int x){
		if(m_parent[x] == x){ return x; }
		m_parent[x] = find(m_parent[x]);
		return m_parent[x];
	}
	int unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y){ return x; }
		if(m_rank[x] < m_rank[y]){
			m_parent[x] = y;
			return y;
		}else if(m_rank[x] > m_rank[y]){
			m_parent[y] = x;
			return x;
		}else{
			m_parent[y] = x;
			++m_rank[x];
			return x;
		}
	}
};
}
namespace lc {
template <class EdgeType>
std::vector<int> id0(
	const id13<EdgeType> &graph)
{
	const int inf = std::numeric_limits<int>::max();
	const int n = graph.size();
	id5 uft(n);
	for(int i = 0; i < n; ++i){
		std::vector<int> v;
		for(const auto &e : graph[i]){ v.push_back(e.to); }
		std::sort(v.begin(), v.end());
		for(int j = 1; j < static_cast<int>(v.size()); ++j){
			if(v[j - 1] == v[j]){ uft.unite(i, v[j]); }
		}
	}
	std::vector<int> depth(n, -1);
	std::stack<std::tuple<int, int, int, int>> stack;
	int id9 = -1;
	for(int i = 0; i < n; ++i){
		if(depth[i] >= 0){ continue; }
		stack.emplace(i, -1, 0, inf);
		while(!stack.empty()){
			const int u = std::get<0>(stack.top());
			const int p = std::get<1>(stack.top());
			const size_t j = std::get<2>(stack.top());
			int minval = std::get<3>(stack.top());
			stack.pop();
			if(j == 0 && depth[u] >= 0){
				id9 = depth[u];
				continue;
			}else if(j == 0){
				depth[u] = static_cast<int>(stack.size());
			}else{
				if(id9 <= static_cast<int>(stack.size())){
					uft.unite(u, graph[u][j - 1].to);
				}
				minval = std::min(minval, id9);
			}
			if(j == graph[u].size()){
				id9 = minval;
			}else{
				const int v = graph[u][j].to;
				stack.emplace(u, p, j + 1, minval);
				if(v != p){
					stack.emplace(v, u, 0, inf);
				}else{
					id9 = inf;
				}
			}
		}
	}
	std::vector<int> tcc(n, -1);
	for(int i = 0; i < n; ++i){ tcc[i] = uft.find(i); }
	return tcc;
}
template <class EdgeType>
id13<EdgeType> id11(
	const id13<EdgeType> &graph,
	const std::vector<int> &tcc)
{
	const int n = graph.size();
	id13<EdgeType> result(n);
	for(int u = 0; u < n; ++u){
		const int bu = tcc[u];
		for(const auto &e : graph[u]){
			const int v = e.to, bv = tcc[v];
			if(bv == bu){ continue; }
			EdgeType f(e);
			f.to = bv;
			result.add_edge(bu, f);
		}
	}
	return result;
}
}
namespace lc {
class id12 {
public:
	struct Connection {
		int local_index;
		int child_path;
		explicit Connection(int li = -1, int cp = -1) :
			local_index(li), child_path(cp)
		{ }
	};
	struct Segment {
		int path;
		int first;
		int last;
		explicit Segment(int path = -1, int first = -1, int last = -1) :
			path(path), first(first), last(last)
		{ }
	};
private:
	typedef std::pair<int, int> pii;
	struct Path {
		int parent_vertex;
		std::vector<Connection> children;
		std::vector<int> vertices;
		int depth;
	};
	std::vector<Path> m_paths;
	std::vector<int> m_path_ids;
	std::vector<int> m_local_indices;
	template <typename EdgeType>
	std::vector<int> id8(
		const id13<EdgeType> &conn, int root) const
	{
		const int n = conn.size();
		std::vector<int> id10(n);
		std::vector<bool> passed(n), id4(n);
		std::stack<pii> count_stack;
		count_stack.push(pii(root, 0));
		while(!count_stack.empty()){
			const pii p = count_stack.top();
			count_stack.pop();
			const int u = p.first, i = p.second;
			if(i == 0){
				passed[u] = true;
				count_stack.push(pii(u, 1));
				for(size_t j = 0; j < conn[u].size(); ++j){
					const int v = conn[u][j].to;
					if(passed[v]){ continue; }
					count_stack.push(pii(v, 0));
				}
			}else{
				int sum = 1;
				id4[u] = true;
				for(size_t j = 0; j < conn[u].size(); ++j){
					const int v = conn[u][j].to;
					if(!id4[v]){ continue; }
					sum += id10[v];
				}
				id10[u] = sum;
			}
		}
		return id10;
	}
public:
	id12()
		: m_paths(0)
		, m_path_ids(0)
		, m_local_indices(0)
	{ }
	template <typename EdgeType>
	explicit id12(
		const id13<EdgeType> &conn, int root = 0)
		: m_paths(0)
		, m_path_ids(conn.size(), -1)
		, m_local_indices(conn.size(), -1)
	{
		const std::vector<int> id10 = id8(conn, root);
		std::stack<pii> id7;
		id7.push(pii(root, -1));
		while(!id7.empty()){
			const pii p = id7.top();
			id7.pop();
			const int parent_vertex = p.second;
			const int pid = m_paths.size();
			m_paths.push_back(Path());
			Path &path = m_paths.back();
			path.parent_vertex = parent_vertex;
			if(parent_vertex >= 0){
				const int parent_pid = m_path_ids[parent_vertex];
				const int parent_index = m_local_indices[parent_vertex];
				m_paths[parent_pid].children.push_back(
					Connection(parent_index, pid));
				path.depth = m_paths[parent_pid].depth + 1;
			}else{
				path.depth = 0;
			}
			int cur = p.first;
			while(cur >= 0){
				const int st_size = id10[cur], threshold = st_size / 2;
				m_path_ids[cur] = pid;
				m_local_indices[cur] = path.vertices.size();
				path.vertices.push_back(cur);
				int heavy_edge = -1;
				for(size_t i = 0; i < conn[cur].size(); ++i){
					const int v = conn[cur][i].to;
					if(id10[v] > id10[cur]){ continue; }
					if(heavy_edge < 0 && id10[v] >= threshold){
						heavy_edge = v;
					}else{
						id7.push(pii(v, cur));
					}
				}
				cur = heavy_edge;
			}
		}
	}
	int path_count() const { return m_paths.size(); }
	int path_length(int p) const { return m_paths[p].vertices.size(); }
	int path_depth(int p) const { return m_paths[p].depth; }
	int parent_path_id(int p) const {
		if(m_paths[p].parent_vertex < 0){ return -1; }
		return m_path_ids[m_paths[p].parent_vertex];
	}
	int parent_local_index(int p) const {
		if(m_paths[p].parent_vertex < 0){ return -1; }
		return m_local_indices[m_paths[p].parent_vertex];
	}
	int path_id(int v) const { return m_path_ids[v]; }
	int local_index(int v) const { return m_local_indices[v]; }
	std::vector<Segment> shortest_path(int u, int v) const {
		std::vector<Segment> usegs, id2, result;
		int up = path_id(u), ul = local_index(u);
		int vp = path_id(v), vl = local_index(v);
		while(up != vp){
			const bool update_u = path_depth(up) >= path_depth(vp);
			const bool update_v = path_depth(up) <= path_depth(vp);
			if(update_u){
				usegs.push_back(Segment(up, 0, ul + 1));
				ul = parent_local_index(up);
				up = parent_path_id(up);
			}
			if(update_v){
				id2.push_back(Segment(vp, 0, vl + 1));
				vl = parent_local_index(vp);
				vp = parent_path_id(vp);
			}
		}
		for(int i = 0; i < static_cast<int>(usegs.size()); ++i){
			const Segment &s = usegs[i];
			result.push_back(Segment(s.path, s.last - 1, s.first - 1));
		}
		result.push_back(Segment(up, ul, vl + (ul > vl ? -1 : 1)));
		for(int i = static_cast<int>(id2.size()) - 1; i >= 0; --i){
			result.push_back(id2[i]);
		}
		return result;
	}
};
}
using namespace std;
typedef pair<int, int> pii;
typedef lc::Edge Edge;
int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	lc::id13<Edge> conn(n);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		--a; --b;
		conn.add_edge(a, b);
		conn.add_edge(b, a);
	}
	const auto tcc = lc::id0(conn);
	const auto cont_conn = id11(conn, tcc);
	lc::id3<int> comp;
	for(const auto &v : tcc){ comp.push(v); }
	const int k = comp.build();
	lc::id13<Edge> forest(k);
	for(int i = 0; i < n; ++i){
		const int ci = comp.compress(i);
		for(const auto &e : cont_conn[i]){
			forest.add_edge(ci, comp.compress(e.to));
		}
	}
	const auto trees = connected_components(forest);
	const int id1 = trees.size();
	vector<lc::id12> id6(id1);
	vector<vector<vector<pii>>> paths(id1);
	for(int i = 0; i < id1; ++i){
		id6[i] = lc::id12(trees.contracted_graph(i), 0);
		const int num_paths = id6[i].path_count();
		paths[i].assign(num_paths, vector<pii>());
		for(int j = 0; j < num_paths; ++j){
			paths[i][j].assign(id6[i].path_length(j) + 1, pii(0, 0));
		}
	}
	bool answer = true;
	for(int i = 0; i < q; ++i){
		int u, v;
		cin >> u >> v;
		u = comp.compress(tcc[u - 1]);
		v = comp.compress(tcc[v - 1]);
		if(trees.component_id(u) != trees.component_id(v)){
			answer = false;
			continue;
		}
		const int cid = trees.component_id(u);
		const int cu = trees.local_vertex_id(u);
		const int cv = trees.local_vertex_id(v);
		if(cu == cv){ continue; }
		const auto route = id6[cid].shortest_path(cu, cv);
		const int route_len = route.size();
		for(int j = 0; j < route_len; ++j){
			const auto &s = route[j];
			auto &path = paths[cid][s.path];
			if(s.first < s.last){
				int first = s.first + 1, last = s.last;
				if(first == 1 && j > 0){
					const int pp = id6[cid].parent_path_id(s.path);
					if(route[j - 1].path == pp){ --first; }
				}
				++path[first].first;
				--path[last].first;
			}else{
				int first = s.last + 2, last = s.first + 1;
				if(first == 1 && j + 1 < route_len){
					const int pp = id6[cid].parent_path_id(s.path);
					if(route[j + 1].path == pp){ --first; }
				}
				++path[first].second;
				--path[last].second;
			}
		}
	}
	for(int i = 0; i < id1; ++i){
		const int num_paths = paths[i].size();
		for(int j = 0; j < num_paths; ++j){
			const int len = paths[i][j].size();
			for(int k = 1; k < len; ++k){
				paths[i][j][k].first += paths[i][j][k - 1].first;
				paths[i][j][k].second += paths[i][j][k - 1].second;
			}
			for(int k = 0; k < len; ++k){
				if(paths[i][j][k].first && paths[i][j][k].second){
					answer = false;
				}
			}
		}
	}
	cout << (answer ? "Yes" : "No") << endl;
	return 0;
}
