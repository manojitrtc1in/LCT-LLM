



























using namespace std;




using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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



























mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<V<V<T>>>;
template <class T> using VVVV = V<V<V<V<T>>>>;

template <typename T, typename S> ostream& operator << (ostream& os, const pair<T, S>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream& os, const C& c) { bool f = true; os << "{"; for (const auto& x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
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
	template <class T> constexpr bool id5 = is_iterable<T>::value;

	

	template <class T, class = void> struct is_readable : false_type {};
	template <class T> struct is_readable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cin >> declval<T&>()), istream&>
			>
		> : true_type {};
	template <class T> constexpr bool id0 = is_readable<T>::value;

	

	

	template <class T, class = void> struct is_printable : false_type {};
	template <class T> struct is_printable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cout << declval<T>()), ostream&>
			>
		> : true_type {};
	template <class T> constexpr bool id1 = is_printable<T>::value;
}

inline namespace Input {
	template <class T> constexpr bool id4 = !id0<T> && id5<T>;
	template <class T, class... U> void re(T& t, U&... u);
	template <class T, class U> void re(pair<T, U>& p); 


	

	template <class T> typename enable_if<id0<T>, void>::type re(T& x) { cin >> x; } 

	template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } 

	template <class T> typename enable_if<id4<T>, void>::type re(T& i); 

	template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
	template <class T> typename enable_if<id4<T>, void>::type re(T& i) {
		for (auto& x : i) re(x); }
	template <class T, class... U> void re(T& t, U&... u) { re(t); re(u...); } 


	

	void rv(std::size_t) {}
	template <class T, class... U> void rv(std::size_t N, vector<T>& t, U&... u);
	template <class...U> void rv(std::size_t, std::size_t N2, U&... u);
	template <class T, class... U> void rv(std::size_t N, vector<T>& t, U&... u) {
		t.resize(N); re(t);
		rv(N, u...); }
	template <class...U> void rv(std::size_t, std::size_t N2, U&... u) {
		rv(N2, u...); }

	

	void decrement() {} 

	template <class T, class... U> void decrement(T& t, U&... u) { --t; decrement(u...); }
	
	
}

inline namespace ToString {
	template <class T> constexpr bool id2 = !id1<T> && id5<T>;

	

	template <class T> typename enable_if<id1<T>, string>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	template <class T> string bit_vec(T t) { 

		string res = "{"; for (int i = 0; i < (int)t.size(); ++i) res += ts(t[i]);
		res += "}"; return res; }
	string ts(vector<bool> v) { return bit_vec(v); }
	template <std::size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } 

	template <class T, class U> string ts(pair<T, U> p); 

	template <class T> typename enable_if<id2<T>, string>::type ts(T v); 

	template <class T, class U> string ts(pair<T, U> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
	template <class T> typename enable_if<id5<T>, string>::type ts_sep(T v, string sep) {
		

		bool fst = 1; string res = "";
		for (const auto& x : v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template <class T> typename enable_if<id2<T>, string>::type ts(T v) {
		return "{" + ts_sep(v, ", ") + "}"; }

	

	template <int, class T> typename enable_if<!id2<T>, vector<string>>::type 
	  id3(const T& v) { return {ts(v)}; }
	template <int lev, class T> typename enable_if<id2<T>, vector<string>>::type 
	  id3(const T& v) {
		if (lev == 0 || !(int)v.size()) return {ts(v)};
		vector<string> res;
		for (const auto& t : v) {
			if ((int)res.size()) res.back() += ",";
			vector<string> tmp = id3<lev - 1>(t);
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
	

	template <class... T> void pr(const T&... t) { pr_sep(cout, "", t...); } 
	

	void ps() { cout << "\n"; }
	template <class... T> void ps(const T&... t) { pr_sep(cout, " ", t...); ps(); } 
	

	template <class... T> void dbg_out(const T&... t) {
		pr_sep(cerr, " | ", t...); cerr << endl; }
	void loc_info(int line, string names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template <int lev, class T> void id6(const T& t) {
		cerr << "\n\n" << ts_sep(id3<lev>(t), "\n") << "\n" << endl; }
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void set_in(string s)  { freopen(s.c_str(), "r", stdin); }
	void set_out(string s) { freopen(s.c_str(), "w", stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (!s.empty()) set_in(s + ".in"), set_out(s + ".out"); 

	}
}



template <int MOD, int RT> struct Mint {
	static const int mod = MOD;
	static constexpr Mint rt() { return RT; } 

	static constexpr int md() { return MOD; } 

	int v; 
	explicit operator int() const { return v; } 

	explicit operator bool() const { return v != 0; }
	Mint() { v = 0; }
	Mint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
	friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
	friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
	friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
	friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
	friend std::istream& operator >> (std::istream& in, Mint& a) { 
		long long x; std::cin >> x; a = Mint(x); return in; }
	friend std::ostream& operator << (std::ostream& os, const Mint& a) { return os << a.v; }
	Mint& operator+=(const Mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	Mint& operator-=(const Mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	Mint& operator*=(const Mint& m) { 
		v = (long long)v * m.v % MOD; return *this; }
	Mint& operator/=(const Mint& m) { return (*this) *= inv(m); }
	friend Mint pow(Mint a, long long p) {
		Mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; 
	}
	friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }
	Mint operator-() const { return Mint(-v); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
};

using mi = Mint<1000000007, 5>;

const ld PI = acos((ld)-1);

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<int>> jump;

	int level(int x) { return 31 - __builtin_clz(x); }

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
		for (auto &nxt : adj[src]) {
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

struct DSU {
	std::vector<int> e;

	void init(int n) {
		e = std::vector<int>(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool same_set(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) std::swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

const int N = 105;

bool a[N][N][N];

void solve_case(int tc = 0) {
	int n;
	re(n);
	id7(i, N) {
		id7(j, N) {
			id7(k, N) {
				a[i][j][k] = false;
			}
		}
	}
	f1r(i, 1, n) {
		f1r(j, 1, n - i + 1) {
			string s;
			re(s);
			s = '?' + s;
			f1r(k, 1, n + 1) {
				int x = i;
				int y = i + j;
				int z = k;
				

				--x, --y, --z;
				if (s[k] == '1') {
					a[x][y][z] = true;
					a[y][x][z] = true;
				} 
			}
		}
	}
	id7(i, n) {
		id7(j, n) {
			a[i][i][j] = true;
		}
	}
	auto test = [&](int r1, int r2) {
		LCARMQ lca;
		lca.init(n);
		vpi edges;
		VV<bool> vis(n, vb(n));
		auto ae = [&](int u, int v) {
			if (u > v) {
				swap(u, v);
			}
			if (vis[u][v]) {
				return false;
			}
			vis[u][v] = true;
			lca.ae(u, v);
			edges.eb(u, v);
			return true;
		};	
		vpi que;
		que.pb({r1, r2});
		auto expand = [&](int u, int v) {
			id7(i, n) {
				if (a[i][v][u] && ae(i, u)) {
					que.eb(i, u);
				}
				if (a[i][u][v] && ae(i, v)) {
					que.eb(i, v);
				}
			}
		};
		int times = 0;
		while (!que.empty()) {
			auto x = que.bk;
			que.pop_back();
			expand(x.f, x.s);
			++times;
			if (times > n + 2) {
				return false;
			}
		}
		DSU dsu;
		dsu.init(n);
		each(e, edges) {
			if (!dsu.unite(e.f, e.s)) {
				return false;
			}
		}
		if (sz(edges) != n - 1) {
			return false;
		}
		lca.gen(0);
		VV<int> dist(n, vi(n));
		id7(i, n) {
			id7(j, n) {
				dist[i][j] = lca.dist(i, j);
			}
		}
		id7(x, n) {
			f1r(y, x + 1, n) {
				id7(z, n) {
					bool ok = dist[x][z] == dist[y][z];
					if (ok != a[x][y][z]) {
						return false;
					}
				}
			}
		}
		ps("Yes");
		for (auto [u, v] : edges) {
			ps(u + 1, v + 1);
		}
		return true;
	};
	f1r(i, 1, n) { 

		if (test(0, i)) {
			return;
		}
	}
	ps("No");
}

int main() {
	setIO("");
	int tt = 1;
	re(tt);
	f1r(tc, 1, tt + 1) {
		solve_case(tc);
	}
	return 0;
}