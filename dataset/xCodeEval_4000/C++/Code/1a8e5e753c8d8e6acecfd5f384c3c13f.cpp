


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

const bool isT = false;

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

class Dsu {
	
public:
	
	std::vector <int> p;
	int size;
	
	Dsu(int _size) :
	p(_size),
	size(_size)
	{
		std::iota(p.begin(), p.end(), 0);
	}
	
	inline int get(int i) {
		return i == p[i] ? i : (p[i] = get(p[i]));
	}
	
	inline bool unite(int i, int j) {
		i = get(i);
		j = get(j);
		if (i != j) {
			p[i] = j;
			return true;
		}
		return false;
	}
	
	friend std::ostream& operator << (std::ostream& stream, Dsu& dsu) {
		stream << "{";
		for (int i = 0; i < dsu.size; i++) {
			stream << dsu.get(i);
			if (i + 1 != dsu.size) {
				stream << ", ";
			}
		}
		stream << "}";
		return stream;
	}
	
};

void prep() {
	
}

struct Edge {
	int u, v, c;
};

int n, k, m, ans = 1 << 30;
std::vector <int> d, deg;
std::vector <std::vector <int>> g;
std::vector <std::pair <int, int>> ed;
std::vector <Edge> uv;

inline void kth() {
	for (int i = 0; i < k; i++) {
		for (int j = k; j < n; j++) {
			ed.emplace_back(i, j);
		}
	}
}

inline bool cmp(const std::pair <int, int>& e1, const std::pair <int, int>& e2) {
	return g[e1.first][e1.second] < g[e2.first][e2.second];
}

inline void mst() {
	std::vector <std::pair <int, int>> e;
	for (int i = k; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			e.emplace_back(i, j);
		}
	}
	std::sort(all(e), cmp);
	Dsu dsu(n);
	for (auto p : e) {
		if (dsu.get(p.first) != dsu.get(p.second)) {
			ed.emplace_back(p.first, p.second);
			dsu.unite(p.first, p.second);
		}
	}
}

inline void make_uv() {
	m = ed.size();
	uv.resize(m);
	for (int i = 0; i < m; i++) {
		uv[i].u = ed[i].first;
		uv[i].v = ed[i].second;
		uv[i].c = g[ed[i].first][ed[i].second];
	}
}

void dfs(int node, int weight, Dsu dsu) {
	if (k * k == node) {
		for (int i = 0; i < k; i++) {
			if (deg[i] > d[i]) {
				return;
			}
		}
		std::vector <bool> vis(m, false);
		while (true) {
			std::vector <int> di(m, 1 << 30), pr(m, -1), no = deg;
			Dsu dsu_swa = dsu;
			for (int i = 0; i < m; i++) {
				if (!vis[i]) {
					continue;
				}
				if (uv[i].u < k) {
					no[uv[i].u]++;
				}
				dsu_swa.unite(uv[i].u, uv[i].v);
			}
			std::vector <std::vector <int>> h(m);
			std::queue <int> q;
			std::vector <bool> vis2(m, false);
			for (int i = 0; i < m; i++) {
				if (vis[i] || dsu_swa.get(uv[i].u) == dsu_swa.get(uv[i].v)) {
					continue;
				}
				di[i] = uv[i].c;
				vis2[i] = true;
				q.push(i);
			}
			for (int i = 0; i < m; i++) {
				if (!vis[i]) {
					continue;
				}
				dsu_swa = dsu;
				for (int j = 0; j < m; j++) {
					if (i == j || !vis[j]) {
						continue;
					}
					dsu_swa.unite(uv[j].u, uv[j].v);
				}
				for (int j = 0; j < m; j++) {
					if (vis[j]) {
						continue;
					}
					if (dsu_swa.get(uv[j].u) != dsu_swa.get(uv[j].v)) {
						h[i].push_back(j);
					}
					bool yes = true;
					for (int l = 0; l < k; l++) {
						yes &= no[l] - (uv[i].u == l) + (uv[j].u == l) <= d[l];
					}
					if (yes) {
						h[j].push_back(i);
					}
				}
			}
			while (q.size()) {
				int v = q.front(); q.pop();
				vis2[v] = false;
				for (int x : h[v]) {
					int val = di[v] + uv[x].c * (!vis[x] * 2 - 1);
					if (di[x] > val) {
						di[x] = val;
						pr[x] = v;
						if (!vis2[x]) {
							vis2[x] = true;
							q.push(x);
						}
					}
				}
			}
			int target = -1;
			for (int i = 0; i < m; i++) {
				if (vis[i] || di[i] == (1 << 30)) {
					continue;
				}
				bool yes = target == -1 || di[i] < di[target];
				for (int j = 0; j < k; j++) {
					yes &= no[j] + (uv[i].u == j) <= d[j];
				}
				if (yes) {
					target = i;
				}
			}
			if (target == -1) {
				break;
			}
			for (int i = target; i != -1; i = pr[i]) {
				vis[i] = !vis[i];
			}
		}
		int res = weight;
		for (int i = 0; i < m; i++) {
			if (vis[i]) {
				dsu.unite(uv[i].u, uv[i].v);
				res += uv[i].c;
			}
		}
		for (int i = 0; i < n; i++) {
			if (dsu.get(0) != dsu.get(i)) {
				return;
			}
		}
		ans = std::min(ans, res);
		return;
	}
	dfs(node + 1, weight, dsu);
	std::pair <int, int> p = { node / k, node % k };
	if (p.first < p.second && dsu.get(p.first) != dsu.get(p.second)) {
		dsu.unite(p.first, p.second);
		deg[p.first]++, deg[p.second]++;
		dfs(node + 1, weight + g[p.first][p.second], dsu);
		deg[p.first]--, deg[p.second]--;
	}
}

void solv(const int curt) {
	
	std::cin >> n >> k;
	d.resize(k);
	g.resize(n, std::vector <int> (n, 0));
	deg.resize(k, 0);
	for (int& x : d) {
		std::cin >> x;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			std::cin >> g[i][j];
			g[j][i] = g[i][j];
		}
	}
	kth();
	mst();
	make_uv();
	Dsu dsu(n);
	dfs(0, 0, dsu);
	std::cout << ans << "\n";
	
}
