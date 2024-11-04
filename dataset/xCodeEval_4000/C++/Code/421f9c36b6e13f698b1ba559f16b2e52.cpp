


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

void prep() {
	
}

constexpr const ll mxn = 503;

void solv(const int curt) {
	
	int n, m; std::cin >> n >> m;
	static ll g[mxn][mxn];
	for (int i = 0; i < mxn; i++) for (int j = 0; j < mxn; j++) g[i][j] = 1LL << 60;
	for (int i = 0; i < m; i++) {
		int u, v, w; std::cin >> u >> v >> w; u--, v--;
		g[u][v] = g[v][u] = std::min(g[u][v], (ll) w);
	}
	auto bfs = [&] (std::vector <ll>& res, int s) -> void {
		std::queue <std::pair <int, int>> q;
		q.push({ s, 0 });
		res = std::vector <ll> (n, -1);
		while (q.size()) {
			int v = q.front().first; int w = q.front().second; q.pop();
			if (res[v] != -1) continue;
			res[v] = w;
			for (int i = 0; i < n; i++) {
				if (g[v][i] < (1LL << 60)) {
					q.push({ i, w + 1 });
				}
			}
		}
	};
	std::vector <ll> res[2];
	bfs(res[0], 0);
	bfs(res[1], n - 1);
	std::vector <ll> to(n, 1LL << 60);
	std::queue <std::pair <int, int>> q;
	for (int i = 0; i < n; i++) {
		if (res[0][i] + res[1][i] == res[0][n - 1]) {
			q.push({ i, 0 });
		}
	}
	while (q.size()) {
		int v = q.front().first;
		int w = q.front().second;
		q.pop();
		if (to[v] < 1LL << 60) continue;
		to[v] = w;
		for (int i = 0; i < n; i++) {
			if (g[v][i] < (1LL << 60)) {
				q.push({ i, w + 1 });
			}
		}
	}
	ll ans = 1LL << 60;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] >= (1LL << 60)) continue;
			

				

				

			

				

				

			

			ans = std::min(ans,
			g[i][j] * std::min(to[i], to[j]) + g[i][j] + g[i][j] + g[i][j] * res[0][n - 1]);
			ans = std::min({ ans,
			g[i][j] * res[0][i] +
			g[i][j] * res[1][j] +
			g[i][j] });
		}
	}
	std::cout << ans << "\n";
	
}
