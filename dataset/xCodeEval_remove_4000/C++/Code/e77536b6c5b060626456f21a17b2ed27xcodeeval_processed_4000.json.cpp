



























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
	template <class T> constexpr bool id6 = is_iterable<T>::value;

	

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
	template <class T> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
	template <class T> constexpr bool id5 = !id0<T> && id6<T>;
	template <class T, class... U> void re(T& t, U&... u);
	template <class T, class U> void re(pair<T, U>& p); 


	

	template <class T> typename enable_if<id0<T>, void>::type re(T& x) { cin >> x; } 

	template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } 

	template <class T> typename enable_if<id5<T>, void>::type re(T& i); 

	template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
	template <class T> typename enable_if<id5<T>, void>::type re(T& i) {
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
	template <class T> constexpr bool id3 = !id2<T> && id6<T>;

	

	template <class T> typename enable_if<id2<T>, string>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	template <class T> string bit_vec(T t) { 

		string res = "{"; for (int i = 0; i < (int)t.size(); ++i) res += ts(t[i]);
		res += "}"; return res; }
	string ts(vector<bool> v) { return bit_vec(v); }
	template <std::size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } 

	template <class T, class U> string ts(pair<T, U> p); 

	template <class T> typename enable_if<id3<T>, string>::type ts(T v); 

	template <class T, class U> string ts(pair<T, U> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
	template <class T> typename enable_if<id6<T>, string>::type ts_sep(T v, string sep) {
		

		bool fst = 1; string res = "";
		for (const auto& x : v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template <class T> typename enable_if<id3<T>, string>::type ts(T v) {
		return "{" + ts_sep(v, ", ") + "}"; }

	

	template <int, class T> typename enable_if<!id3<T>, vector<string>>::type 
	  id4(const T& v) { return {ts(v)}; }
	template <int lev, class T> typename enable_if<id3<T>, vector<string>>::type 
	  id4(const T& v) {
		if (lev == 0 || !(int)v.size()) return {ts(v)};
		vector<string> res;
		for (const auto& t : v) {
			if ((int)res.size()) res.back() += ",";
			vector<string> tmp = id4<lev - 1>(t);
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
	template <int lev, class T> void id7(const T& t) {
		cerr << "\n\n" << ts_sep(id4<lev>(t), "\n") << "\n" << endl; }
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void set_in(string s)  { freopen(s.c_str(), "r", stdin); }
	void set_out(string s) { freopen(s.c_str(), "w", stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (!s.empty()) set_in(s + ".in"), set_out(s + ".out"); 

	}
}

int MOD = 998244353;

typedef std::decay<decltype(MOD)>::type mod_t; 
struct mi {
	mod_t v;
	explicit operator mod_t() const { return v; }
	explicit operator bool() const { return v != 0; }
	mi() { v = 0; }
	mi(const long long& _v) {
		v = (-MOD <= _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; }
	friend std::istream& operator>>(std::istream& in, mi& a) { 
		long long x; std::cin >> x; a = mi(x); return in; }
	friend std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.v; }
	friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }    
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
	friend bool operator>(const mi& a, const mi& b) { return a.v > b.v; }
	friend bool operator<=(const mi& a, const mi& b) { return a.v <= b.v; }
	friend bool operator>=(const mi& a, const mi& b) { return a.v >= b.v; }
	mi operator-() const { return mi(-v); }
	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this; }
	mi& operator*=(const mi& m) { v = (long long)v * m.v % MOD;
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

const ld PI = acos((ld)-1);

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int main() {
	setIO("");
	int n;
	re(n, MOD);	
	VV<int> g(n);
	id8(i, n - 1) {
		int u, v;
		re(u, v);
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	VV<mi> dp(n, vmi(n)), sum(dp);
	function<void(int, int)> solve = [&](int u, int p) {
		if (p != -1) {
			g[u].erase(find(all(g[u]), p));
		}
		each(v, g[u]) {
			solve(v, u);
		}
		int sz = sz(g[u]);
		vmi run(sz), pre(sz), suf(sz);
		f1r(i, 1, n) {
			if (u) {
				vi& sons = g[u];
				id8(j, sz) {
					dp[u][i] += dp[sons[j]][i] * run[j];
				}
				id8(j, sz) {
					pre[j] = (j ? pre[j - 1] : 1) * sum[sons[j]][i];
				}
				id1(j, sz) {
					suf[j] = (j < sz - 1 ? suf[j + 1] : 1) * sum[sons[j]][i];
				}
				id8(j, sz) {
					run[j] += (j ? pre[j - 1] : 1) * (j < sz - 1 ? suf[j + 1] : 1);
				}
			}
			mi prod = 1;	
			each(v, g[u]) {
				prod *= sum[v][i];
			}
			dp[u][i] += prod;	
		}
		id8(i, n) {
			sum[u][i] = dp[u][i] + (i ? sum[u][i - 1] : 0);
		}
	};
	solve(0, -1);
	vmi fact(n + 1), ifact(n + 1);
	fact[0] = 1;
	f1r(i, 1, n + 1) {
		fact[i] = fact[i - 1] * i;
	}
	ifact.bk = 1 / fact.bk;
	id1(i, n) {
		ifact[i] = ifact[i + 1] * (i + 1);
	}
	auto C = [&](int x, int y) {
		if (x < y) {
			return mi(0);
		} else {
			return fact[x] * ifact[y] * ifact[x - y];
		}
	};
	vmi ans(n);
	f1r(i, 1, n) {
		ans[i] = dp[0][i];
		id8(j, i) {
			ans[i] -= C(i, j) * ans[j];
		}
		pr(ans[i], ' ');
	}
	ps();
	return 0;
}