








typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

constexpr int mod = 1000000007;



template <typename A> A inverse(A a, A b) {
	a %= b;
	if (!a) {
		return b == A(1) ? 0 : -1;
	}
	A c = inverse(b, a);
	return c == A(-1) ? -1LL :
	((1LL - (long long)b * (long long)c) / (long long)a + b) % b;
}

template <typename A = int> struct Mint {
	A value;
	Mint(A _value = 0) : value(_value) { }
	template <typename B = int> Mint(const B& _value) {
		value = (-mod <= _value && _value <= mod) ? _value : _value % mod;
		value += value < A(0) ? mod : 0;
	}
	operator A() const { return value; }
	friend bool operator == (const Mint& a, const Mint& b) {
		return a.value == b.value;
	}
	friend bool operator != (const Mint& a, const Mint& b) {
		return !(a == b);
	}
	Mint operator - () const { return Mint(-value); }
	Mint& operator += (const Mint& oth) {
		value += oth.value;
		if (value >= mod) {
			value -= mod;
		}
		return *this;
	}
	Mint& operator -= (const Mint& oth) {
		value -= oth.value;
		if (value < A(0)) {
			value += mod;
		}
		return *this;
	}
	Mint& operator *= (const Mint& oth) {
		value = (long long)value * (long long)oth.value % (long long)mod;
		return *this;
	}
	friend Mint pow(Mint mint, long long p) {
		Mint ret = 1;
		while (p) {
			if (p & 1LL) {
				ret *= mint;
			}
			p >>= 1LL;
			mint *= mint;
		}
		return ret;
	}
	friend Mint inv(const Mint& mint) {
		return inverse(mint.value, mod);
	}
	Mint& operator /= (const Mint& oth) {
		(*this) *= inv(oth);
		return *this;
	}
	friend Mint operator + (Mint a, const Mint& b) {
		return a += b;
	}
	friend Mint operator - (Mint a, const Mint& b) {
		return a -= b;
	}
	friend Mint operator * (Mint a, const Mint& b) {
		return a *= b;
	}
	friend Mint operator / (Mint a, const Mint& b) {
		return a /= b;
	}
};

typedef Mint <int> mi;

using namespace __gnu_pbds;

template <typename A, typename B = std::less <A>> using ordered_set =
tree <A, null_type, B, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B, typename C = std::less <A>> using ordered_map =
tree <A, B, C, rb_tree_tag, tree_order_statistics_node_update>;

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
	template <typename A, typename B> std::string to_string(const ordered_set <A, B>& st);
	template <typename A, typename B, typename C> std::string to_string(const ordered_map <A, B, C>& mp);
	
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
	
	template <typename A, typename B> std::string to_string(const ordered_set <A, B>& st) {
		if (st.empty()) {
			return "[ ]";
		}
		std::string ret = "[";
		for (auto it = st.begin(); it != st.end(); it++) {
			ret += to_string(*it) + (next(it) == st.end() ? "]" : ", ");
		}
		return ret;
	}
	
	template <typename A, typename B, typename C> std::string to_string(const ordered_map <A, B, C>& mp) {
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
	
	void id0() {
		std::cerr << std::endl;
	}
	
	void id2(const int cnt = 1) {
		for (int i = 0; i < cnt; i++) {
			std::cerr << " ";
		}
	}
	
	template <typename A> void id0(A a) {
		for (auto it = a.begin(); it != a.end(); it++) {
			id2(1);
			std::cerr << "\033[96m[ " << to_string(*it) << " ]\033[0m" << std::endl;
		}
	}
	
}









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

void prep() {
	
}

struct Edge {
	int u, v;
	bool dead = false;
	bool brid = false;
};

std::vector <Edge> ed;

int n, m, odd = 0;
std::vector <std::vector <int>> g;
std::vector <int> deg;

bool bridge(int node, int par = -1, int d = 0) {
	static std::vector <bool> vis(n, false);
	static std::vector <int> up(n, 1 << 30), dep(n, 0);
	vis[node] = true;
	dep[node] = up[node] = d;
	for (int x : g[node]) {
		int v = ed[x].u ^ ed[x].v ^ node;
		if (v == par) continue;
		if (!vis[v]) {
			ed[x].brid = bridge(v, node, d + 1) && (int)g[node].size() > 1;
			up[node] = std::min(up[node], up[v]);
		}
		up[node] = std::min(up[node], dep[v]);
	}
	return up[node] == d && (int)g[node].size() > 1;
}

void dfs(int node, std::vector <int>& ans) {
	while (true) {
		while (g[node].size() && ed[g[node].back()].dead) g[node].pop_back();
		if (g[node].empty()) break;
		ed[g[node].back()].dead = true;
		dfs(ed[g[node].back()].u ^ ed[g[node].back()].v ^ node, ans);
	}
	ans.push_back(node);
}

void ff(int node, int col, std::vector <int>& c) {
	if (c[node] != -1) return;
	c[node] = col;
	for (int x : g[node]) {
		int v = ed[x].u ^ ed[x].v ^ node;
		ff(v, col, c);
	}
}

void go(int root, int id1) {
	std::vector <int> c(n, -1);
	c[root] = n + 1;
	int col = 0;
	for (int x : g[root]) ff(ed[x].u ^ ed[x].v ^ root, col++, c);
	std::vector <int> towards(n, 0);
	for (int x : g[root]) towards[c[ed[x].u ^ ed[x].v ^ root]]++;
	std::vector <int> id3 = towards;
	for (Edge& e : ed) e.dead = false;
	int cur = -1;
	std::vector <int> del;
	int o = odd;
	int deg_me = deg[root];
	auto tmp_deg = deg;
	while ((o && o != 2) || id1 || (o && !(deg_me & 1))) {
		cur++;
		if (cur >= (int)g[root].size()) return;
		int x = g[root][cur];
		if (ed[x].brid) continue;
		if (!(tmp_deg[ed[x].u ^ ed[x].v ^ root] & 1)) continue;
		if (towards[c[ed[x].u ^ ed[x].v ^ root]] == 1 && id3[c[ed[x].u ^ ed[x].v ^ root]] > 1) continue;
		towards[c[ed[x].u ^ ed[x].v ^ root]]--;
		ed[x].dead = true;
		tmp_deg[ed[x].u]--; o += ((tmp_deg[ed[x].u] & 1) << 1) - 1;
		tmp_deg[ed[x].v]--; o += ((tmp_deg[ed[x].v] & 1) << 1) - 1;
		del.push_back(ed[x].u ^ ed[x].v ^ root);
		del.push_back(root);
		id1 -= (int)g[ed[x].u ^ ed[x].v ^ root].size() == 1;
		deg_me--;
	}
	std::vector <int> ans;
	dfs(root, ans);
	std::cout << ans.size() + del.size() + !!del.size() << "\n";
	for (int x : ans) std::cout << x + 1 << " ";
	if (del.size()) std::cout << "-1 ";
	for (int x : del) std::cout << x + 1 << " ";
	std::cout << "\n";
	exit(0);
}

void solv(const int curt) {
	
	std::cin >> n >> m;
	g.resize(n);
	ed.resize(m);
	deg.resize(n, 0);
	std::vector <int> id1(n, 0);
	for (int i = 0; i < m; i++) {
		std::cin >> ed[i].u >> ed[i].v; ed[i].u--, ed[i].v--;
		g[ed[i].u].push_back(i);
		g[ed[i].v].push_back(i);
		deg[ed[i].u]++; odd += ((deg[ed[i].u] & 1) << 1) - 1;
		deg[ed[i].v]++; odd += ((deg[ed[i].v] & 1) << 1) - 1;
	}
	bridge(0);
	for (int i = 0; i < n; i++) {
		for (int x : g[i]) {
			id1[i] += (int)g[ed[x].u ^ ed[x].v ^ i].size() == 1;
		}
	}
	for (int i = 0; i < n; i++) go(i, id1[i]);
	std::cout << "0\n";
	
}
