#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define f1r(i, a, b) for (int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(a, x) for (auto& a : x)

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<V<V<T>>>;
template <class T> using VVVV = V<V<V<V<T>>>>;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template <typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template <typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template <typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); } 


inline namespace Helpers {
	

	

	

	template <class T, class = void> struct is_iterable : false_type {};
	template <class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
									  decltype(end(declval<T>()))
									 >
						   > : true_type {};
	template <class T> constexpr bool is_iterable_v = is_iterable<T>::value;

	

	template <class T, class = void> struct is_readable : false_type {};
	template <class T> struct is_readable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cin >> declval<T&>()), istream&>
			>
		> : true_type {};
	template <class T> constexpr bool is_readable_v = is_readable<T>::value;

	

	

	template <class T, class = void> struct is_printable : false_type {};
	template <class T> struct is_printable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cout << declval<T>()), ostream&>
			>
		> : true_type {};
	template <class T> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	template <class T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	template <class T, class ...U> void re(T& t, U&... u);
	template <class T, class U> void re(pair<T, U>& p); 


	

	template <class T> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 

	template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } 

	template <class T> typename enable_if<needs_input_v<T>,void>::type re(T& i); 

	template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
	template <class T> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		for (auto& x : i) re(x); }
	template <class T, class ...U> void re(T& t, U&... u) { re(t); re(u...); } 


	

	void rv(std::size_t) {}
	template <class T, class ...U> void rv(std::size_t N, vector<T>& t, U&... u);
	template <class...U> void rv(std::size_t, std::size_t N2, U&... u);
	template <class T, class ...U> void rv(std::size_t N, vector<T>& t, U&... u) {
		t.resize(N); re(t);
		rv(N, u...); }
	template <class...U> void rv(std::size_t, std::size_t N2, U&... u) {
		rv(N2, u...); }

	

	void decrement() {} 

	template <class T, class ...U> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	template <class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	

	template <class T> typename enable_if<is_printable_v<T>, string>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	template <class T> string bit_vec(T t) { 

		string res = "{"; for (int i = 0; i < (int)t.size(); ++i) res += ts(t[i]);
		res += "}"; return res; }
	string ts(vector<bool> v) { return bit_vec(v); }
	template <std::size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } 

	template <class T, class U> string ts(pair<T, U> p); 

	template <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v); 

	template <class T, class U> string ts(pair<T, U> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
	template <class T> typename enable_if<is_iterable_v<T>, string>::type ts_sep(T v, string sep) {
		

		bool fst = 1; string res = "";
		for (const auto& x : v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {
		return "{" + ts_sep(v, ", ") + "}"; }

	

	template <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template <int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !(int)v.size()) return {ts(v)};
		vector<string> res;
		for (const auto& t : v) {
			if ((int)res.size()) res.back() += ",";
			vector<string> tmp = ts_lev<lev - 1>(t);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		for (int i = 0; i < (int)res.size(); ++i) {
			string bef = " "; if (i == 0) bef = "{";
			res[i] = bef + res[i];
		}
		res.back() += "}";
		return res;
	}
}

inline namespace Output {
	template <class T> void pr_sep(ostream& os, string, const T& t) { os << ts(t); }
	template <class T, class... U> void pr_sep(ostream& os, string sep, const T& t, const U&... u) {
		pr_sep(os, sep, t); os << sep; pr_sep(os, sep, u...); }
	

	template <class ...T> void pr(const T&... t) { pr_sep(cout, "", t...); } 
	

	void ps() { cout << "\n"; }
	template <class ...T> void ps(const T&... t) { pr_sep(cout, " ", t...); ps(); } 
	

	template <class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr, " | ", t...); cerr << endl; }
	void loc_info(int line, string names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template <int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t), "\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)
	#else 

		#define dbg(...) 0
		#define dbgl(lev, x) 0
	#endif
}

inline namespace FileIO {
	void set_in(string s)  { freopen(s.c_str(), "r", stdin); }
	void set_out(string s) { freopen(s.c_str(), "w", stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (!s.empty()) set_in(s + ".in"), set_out(s + ".out"); 

	}
}

const int MOD = 1e9 + 7; 

const ld PI = acos((ld) -1);

typedef std::decay <decltype(MOD)>::type mod_t;
struct mi {
	mod_t val;
	explicit operator mod_t() const { return val; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend std::istream& operator>>(std::istream& in, mi& a) { 
		long long x; std::cin >> x; a = mi(x); return in; }
	friend std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { long long x; cin >> x; a = mi(x); }
	friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }    
	friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
	friend bool operator>(const mi& a, const mi& b) { return a.val > b.val; }
	friend bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }
	friend bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) { val = (long long) val * m.val % MOD;
		return *this; }
	friend mi pow(mi a, long long p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; }
	friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<int>> jump;

	int level(int x) {
		return 31 - __builtin_clz(x);
	}

	int comb(int a, int b) {
		return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
	}

	void init(const std::vector<T>& _v) {
		v = _v;
		jump = {std::vector<int>((int)v.size())};
		iota(jump[0].begin(), jump[0].end(), 0);
		for (int j = 1; (1 << j) <= (int)v.size(); j++) {
			jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
			for (int i = 0; i < (int)jump[j].size(); i++) {
				jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int index(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
	}

	T query(int l, int r) {
		return v[index(l, r)];
	}
};

struct LCARMQ {
	int n; 
	std::vector<std::vector<int>> adj;
	std::vector<int> dep, in, par, rev, out, pos;
	std::vector<std::pair<int, int>> tmp;
	SparseTable<std::pair<int, int>> S;
	std::vector<std::vector<int>> sparse;
	int ti = 0;

	void init(int _n) {
		n = _n;
		adj.resize(n);
		dep = in = out = par = rev = pos = std::vector<int>(n);
		sparse = {std::vector<int>(n)};
		for (int j = 1; (1 << j) <= n; j++) {
			sparse.push_back(std::vector<int>(n - (1 << j) + 1));
		}
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int src) {
		in[src] = ti++;
		sparse[0][in[src]] = src;
		pos[src] = (int)tmp.size();
		tmp.emplace_back(dep[src], src);
		for (auto& nxt : adj[src]) {
			if (nxt == par[src]) continue;
			dep[nxt] = dep[par[nxt] = src] + 1;
			dfs(nxt);
			tmp.emplace_back(dep[src], src);
		}
		out[src] = ti;
	}

	inline int mini(int u, int v) {
		return (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;
	}

	void gen(int root = 0) {
		par[root] = root;
		dfs(root);
		S.init(tmp); 
		for (int j = 1; j < (int)sparse.size(); j++) {
			for (int i = 0; i < (int)sparse[j].size(); i++) {
				sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int lca(int u, int v) {
		u = pos[u];
		v = pos[v];
		if (u > v) std::swap(u, v);
		return S.query(u, v).second;
	}

	int dist(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}

	bool is_ancestor(int anc, int src) {
		return in[anc] <= in[src] && out[anc] >= out[src];
	}

	int get_child(int anc, int src) {
		if (!is_ancestor(anc, src)) return -1;
		int l = in[anc] + 1;
		int r = in[src];
		int d = 31 - __builtin_clz(r - l + 1);
		return mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);
	}
	
	std::vector<std::pair<int, int>> compress(std::vector<int> nodes) {
		auto cmp = [&](int a, int b) {
			return pos[a] < pos[b];
		};
		sort(nodes.begin(), nodes.end(), cmp);
		for (int i = (int)nodes.size() - 2; i >= 0; i--) {
			nodes.push_back(lca(nodes[i], nodes[i + 1]));
		}
		sort(nodes.begin(), nodes.end(), cmp);
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
		std::vector<std::pair<int, int>> ret{{0, nodes[0]}};
		for (int i = 0; i < (int)nodes.size(); i++) {
			rev[nodes[i]] = i;
		}
		for (int i = 1; i < (int)nodes.size(); i++) {
			ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);
		}
		return ret;
	}
};

const int N = 205;

mi over[N];
mi dp[N][N];
bool vis[N][N];

mi solve(int x, int y) {
	if (vis[x][y]) {
		return dp[x][y];
	}
	vis[x][y] = true;
	auto& res = dp[x][y];
	if (x == 0) {
		res = 1;
		return res;
	}
	if (y == 0) {
		res = 0;
		return res;
	}
	res = over[2] * (solve(x - 1, y) + solve(x, y - 1));
	return res;
}


void solve_case(int tc = 0) {
	int n; 
	re(n);
	vector<vi> g(n);
	LCARMQ L; 
	L.init(n);
	f0r(i, n - 1) {
		int u, v; 
		re(u, v);
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
		L.ae(u, v);
	}
	L.gen(rng() % n);
	mi ans = 0;
	f0r(x, n) {
		f1r(y, x + 1, n) {
			f0r(z, n) {
				int a, b;
				int lca = L.lca(x, y);
				int X = L.lca(x, z);
				int Y = L.lca(y, z);
				int cen = lca;
				if (L.dep[cen] < L.dep[X]) {
					cen = X;
				}
				if (L.dep[cen] < L.dep[Y]) {
					cen = Y;
				}
				a = L.dist(cen, x);
				b = L.dist(cen, y);
				ans += solve(b, a);
			}
		}
	}
	ans *= over[n];
	ps(ans);
}




void pcp() {
	f1r(i, 1, N) {
		over[i] = mi(1) / i;
	}
}

int main() {
	setIO("");
	pcp();
	int tt = 1;
	

	f1r(tc, 1, tt + 1) {
		solve_case(tc);
	}
	return 0;
}