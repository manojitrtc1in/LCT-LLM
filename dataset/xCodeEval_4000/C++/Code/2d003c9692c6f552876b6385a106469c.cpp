


#include <bits/stdc++.h>
#include <bits/extc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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

struct Mint {
	int value;
	explicit operator int() const { return value; }
	Mint(int _value = 0) : value(_value) { }
	template <typename B = int> Mint(const B& _value) {
		long long llvalue = _value;
		value = (-mod <= llvalue && llvalue <= mod) ? llvalue : llvalue % mod;
		value += value < 0 ? mod : 0;
	}
	friend bool operator == (const Mint& a, const Mint& b) {
		return a.value == b.value;
	}
	friend bool operator != (const Mint& a, const Mint& b) {
		return !(a == b);
	}
	friend bool operator < (const Mint& a, const Mint& b) {
		return a.value < b.value;
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
		if (value < 0) {
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
	Mint& operator ++ () {
		return *this += 1;
	}
	Mint& operator -- () {
		return *this -= 1;
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
	friend std::istream& operator >> (std::istream& stream, Mint& a) {
		stream >> a.value;
		return stream;
	}
	friend std::ostream& operator << (std::ostream& stream, const Mint& a) {
		stream << a.value;
		return stream;
	}
};

typedef Mint mi;

mi fac(ll x) {
	if (x < 0LL) {
		return 0;
	}
	static ll ready = 1;
	static std::vector <mi> factorial = { 1, 1 };
	if (x <= ready) {
		return factorial[x];
	}
	ll y = x + (x >> 4LL);
	factorial.resize(y + 1);
	for (ll i = ready + 1; i <= y; i++) {
		factorial[i] = factorial[i - 1] * i;
	}
	ready = y;
	return factorial[x];
}

mi inv_fac(ll x) {
	if (x < 0LL) {
		return 0;
	}
	static ll ready = 1;
	static std::vector <mi> inv_factorial = { 1, 1 };
	if (x <= ready) {
		return inv_factorial[x];
	}
	ll y = x + (x >> 4LL);
	inv_factorial.resize(y + 1);
	inv_factorial[y] = mi(1) / fac(y);
	for (ll i = y - 1; i > ready; i--) {
		inv_factorial[i] = inv_factorial[i + 1] * (i + 1);
	}
	ready = y;
	return inv_factorial[x];
}

mi choose(ll n, ll k) {
	if (k < 0LL || k > n) {
		return 0;
	}
	return fac(n) * inv_fac(k) * inv_fac(n - k);
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

int ask(int x) {
	std::cout << "? " << x << std::endl;
	int r; std::cin >> r;
	if (r == -1) {
		exit(0);
	}
	return r;
}

constexpr int mxn = 1e5 + 3;
std::vector <int> g[mxn];
int dp[mxn], dep[mxn], ans = 0;

bool cmp(int a, int b) {
	return dp[a] > dp[b];
}

void dfs2(int node, int par, int pd) {
	std::vector <std::pair <int, int>> ch;
	if (pd != -1) {
		ch.emplace_back(pd, par);
	}
	for (int x : g[node]) if (x != par) {
		ch.emplace_back(dp[x], x);
	}
	std::sort(rall(ch));
	int res = 0;
	for (int i = 1; i < (int)ch.size(); i++) {
		res = std::max(res, ch[i].first + i - 1);
	}
	if ((int)ch.size()) {
		res += ch.front().first;
	}
	ans = std::max(ans, res);
	std::vector <int> pre, suf(ch.size());
	for (int i = 0; i < (int)ch.size(); i++) {
		pre.push_back(std::max(pre.size() ? pre.back() : 0, ch[i].first + i));
	}
	for (int i = (int)ch.size() - 1; i >= 0; i--) {
		suf[i] = std::max((i == (int)ch.size() - 1 ? 0 : suf[i + 1] + 1), ch[i].first);
	}
	for (int i = 0; i < (int)ch.size(); i++) {
		if (ch[i].second != par) {
			dfs2(ch[i].second, node, std::max((i - 1 >= 0 ? pre[i - 1] : 1), (i + 1 < (int)suf.size() ? suf[i + 1] + i : 1)));
		}
	}
}

void dfs(int node, int par) {
	std::vector <int> ch;
	dep[node] = dep[par] + 1;
	for (int x : g[node]) if (x != par) {
		dfs(x, node);
		ch.push_back(dp[x]);
	}
	std::sort(rall(ch));
	dp[node] = 1;
	if (par) {
		for (int i = 0; i < (int)ch.size(); i++) {
			dp[node] = std::max(dp[node], ch[i] + i);
		}
	} else {
		dp[node] = 0;
		for (int i = 1; i < (int)ch.size(); i++) {
			dp[node] = std::max(dp[node], ch[i] + i - 1);
		}
		if ((int)ch.size()) {
			dp[node] += ch.front();
		}
	}
}

int go(int node, int par) {
	std::vector <int> ch;
	for (int x : g[node]) if (x != par) {
		ch.push_back(x);
	}
	if (ch.empty() && par) {
		return ask(node);
	}
	std::sort(all(ch), cmp);
	if (par) {
		for (int i = 0; i < (int)ch.size(); i++) {
			int now = go(ch[i], node);
			if (dep[now] != dep[node]) {
				return now;
			}
		}
		return node;
	} else {
		std::vector <int> v;
		for (int i = 0; i < (int)ch.size(); i++) {
			int now = go(ch[i], node);
			if (dep[now] != dep[node]) {
				v.push_back(now);
				if ((int)v.size() == 2) {
					break;
				}
			}
		}
		while ((int)v.size() <= 1) {
			v.push_back(node);
		}
		std::cout << "! " << v[0] << " " << v[1] << std::endl;
	}
	return -1;
}

void solv(const int curt) {
	
	int n; std::cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0, -1);
	std::cout << ans << std::endl;
	int x; std::cin >> x;
	dfs(x, 0);
	go(x, 0);
	
}