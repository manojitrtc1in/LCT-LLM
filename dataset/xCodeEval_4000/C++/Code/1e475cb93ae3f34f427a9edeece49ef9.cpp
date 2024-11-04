


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

constexpr int mxn = 2e5 + 3;
int p[mxn], bin[mxn][20], s[mxn], dp[mxn], cnt[mxn], n, q, tmp = 0;
ll a[mxn], b[mxn], vl[mxn], ds[mxn], sum = 0;
bool vis[mxn];
std::set <int> contains;

void prep() {
	memset(p, 0, sizeof(p));
	memset(bin, 0, sizeof(bin));
	memset(s, 0, sizeof(s));
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(vl, 0, sizeof(vl));
	memset(ds, 0, sizeof(ds));
	memset(vis, false, sizeof(vis));
}

int lca(int u, int v) {
	if (dp[u] < dp[v]) {
		std::swap(u, v);
	}
	for (int i = dp[u] - dp[v], j = 0; i; i >>= 1, j++) {
		if (i & 1) {
			u = bin[u][j];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = 19; i >= 0; i--) {
		if (bin[u][i] != bin[v][i]) {
			u = bin[u][i];
			v = bin[v][i];
		}
	}
	return bin[u][0];
}

ll dist(int u, int v) {
	return ds[u] + ds[v] - ds[lca(u, v)] * 2;
}

void insert(int v) {
	auto it = contains.insert(v).first;
	it--;
	int l = *it++;
	int r = *(++it == contains.end() ? contains.begin() : it);
	sum += dist(l, v) + dist(r, v) - dist(l, r);
}

void erase(int v) {
	auto it = --contains.find(v);
	int l = *it++;
	int r = *(++it == contains.end() ? contains.begin() : it);
	contains.erase(--it);
	sum -= dist(l, v) + dist(r, v) - dist(l, r);
}

void make_anc(int v) {
	bin[v][0] = s[tmp];
	dp[v] = dp[bin[v][0]];
	dp[v]++;
	tmp++;
	s[tmp] = v;
	for (int i = 0; (1 << (i + 1)) <= dp[v]; i++) {
		bin[v][i + 1] = bin[bin[v][i]][i];
	}
}

void solv(const int curt) {
	
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
		while (tmp && p[s[tmp]] < p[i]) {
			tmp--;
		}
		make_anc(i);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		vl[i] += a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		vl[i] -= b[i];
		vl[bin[i][0]] += b[i];
	}
	for (int i = n; i > 0; i--) {
		ds[bin[i][0]] += std::min(0LL, ds[i] += vl[i]);
		ds[i] -= std::min(0LL, ds[i]);
	}
	ds[0] += vl[0];
	for (int i = 1; i <= n; i++) {
		ds[i] += ds[bin[i][0]];
	}
	cnt[0] = 1;
	contains.insert(0);
	for (int i = 0; i < q; i++) {
		int v; std::cin >> v;
		vis[v] ^= 1;
		if (vis[v]) {
			if (!(cnt[bin[v][0]])) {
				insert(bin[v][0]);
			}
			cnt[bin[v][0]]++;
		} else {
			cnt[bin[v][0]]--;
			if (!(cnt[bin[v][0]])) {
				erase(bin[v][0]);
			}
		}
		std::cout << (sum / 2) + ds[0] << "\n";
	}
	
}
