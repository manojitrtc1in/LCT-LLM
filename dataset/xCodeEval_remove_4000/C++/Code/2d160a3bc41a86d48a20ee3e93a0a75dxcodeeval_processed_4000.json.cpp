
























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

template <typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& p) { 
  return os << "(" << p.first << ", " << p.second << ")"; 
}
template <typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream& os, const C& c) { 
  bool f = true; 
  os << "{"; 
  for (const auto& x : c) { 
    if (!f) 
      os << ", "; 
    f = false; os << x; 
  } 
  return os << "}"; 
}
template <typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template <typename T, typename... Args> void debug(string s, T x, Args... args) { 
  cerr << s.substr(0, s.find(',')) << " = " << x << " | "; 
  debug(s.substr(s.find(',') + 2), args...); 
}

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); } 



inline namespace Helpers {
	


	


	


	template <class T, class = void> struct is_iterable : false_type {};
	template <class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
									  decltype(end(declval<T>()))
									 >
						   > : true_type {};
	template <class T> constexpr bool id3 = is_iterable<T>::value;

	


	template <class T, class = void> struct is_readable : false_type {};
	template <class T> struct is_readable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cin >> declval<T&>()), istream&>
			>
		> : true_type {};
	template <class T> constexpr bool id5 = is_readable<T>::value;

	


	


	template <class T, class = void> struct is_printable : false_type {};
	template <class T> struct is_printable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cout << declval<T>()), ostream&>
			>
		> : true_type {};
	template <class T> constexpr bool id1 = is_printable<T>::value;
}

inline namespace Input {
	template <class T> constexpr bool id2 = !id5<T> && id3<T>;
	template <class T, class... U> void re(T& t, U&... u);
	template <class T, class U> void re(pair<T, U>& p); 



	


	template <class T> typename enable_if<id5<T>, void>::type re(T& x) { cin >> x; } 


	template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } 


	template <class T> typename enable_if<id2<T>, void>::type re(T& i); 


	template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
	template <class T> typename enable_if<id2<T>, void>::type re(T& i) {
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
	template <class T> constexpr bool id4 = !id1<T> && id3<T>;

	


	template <class T> typename enable_if<id1<T>, string>::type ts(T v) {
		stringstream ss; 
		

		ss << v;
		return ss.str(); } 


	template <class T> string bit_vec(T t) { 


		string res = "{"; for (int i = 0; i < (int)t.size(); ++i) res += ts(t[i]);
		res += "}"; return res; }
	string ts(vector<bool> v) { return bit_vec(v); }
	template <std::size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } 


	template <class T, class U> string ts(pair<T, U> p); 


	template <class T> typename enable_if<id4<T>, string>::type ts(T v); 


	template <class T, class U> string ts(pair<T, U> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
	template <class T> typename enable_if<id3<T>, string>::type ts_sep(T v, string sep) { 
		


		bool fst = 1; string res = "";
		for (const auto& x : v) { 
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template <class T> typename enable_if<id4<T>, string>::type ts(T v) {
		return "{" + ts_sep(v, ", ") + "}"; } 

	


	template <int, class T> typename enable_if<!id4<T>, vector<string>>::type 
	  id6(const T& v) { return {ts(v)}; }
	template <int lev, class T> typename enable_if<id4<T>, vector<string>>::type 
	  id6(const T& v) {
		if (lev == 0 || !(int)v.size()) return {ts(v)};
		vector<string> res;
		for (const auto& t : v) {
			if ((int)res.size()) res.back() += ",";
			vector<string> tmp = id6<lev - 1>(t);
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
		cerr << "\n\n" << ts_sep(id6<lev>(t), "\n") << "\n" << endl; }
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void set_in(string s)  { (void)!freopen(s.c_str(), "r", stdin); }
	void set_out(string s) { (void)!freopen(s.c_str(), "w", stdout); }
	void set_io(string s = "") {
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

using mi = Mint<998244353, 5>;

const ld PI = acos((ld)-1);

typedef pair<mi, mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int main() {
	set_io();
	int n;
	re(n);
	vi a(n);
	re(a);
	map<int, int> cnt;
	each(x, a) {
		++cnt[x];
	}
	vi use;
	each(x, cnt) {
		use.pb(x.s);
	}
	sor(use);
	reverse(all(use));
	use.resize(n);
	vi pre(n);
	id8(i, n) {
		pre[i] = (i ? pre[i - 1] : 0) + use[i];
	}
	VVV<mi> dp(n, VV<mi>(n + 1));
	id8(i, n) {
		id8(j, n + 1) {
			dp[i][j].resize(j / (i + 1) + 1);
		}
	}
	auto suf(dp);
	f1r(j, pre[0], n + 1) {
		dp[0][j][j] = 1;
	}
	auto comp = [&](int i) {
		id8(j, n + 1) {
			id0(k, sz(dp[i][j])) {
				suf[i][j][k] = (k == sz(dp[i][j]) - 1 ? 0 : suf[i][j][k + 1]) + dp[i][j][k];
			}
		}
	};
	comp(0);
	f1r(i, 1, n) {
		f1r(j, pre[i], n + 1) {
			id8(k, sz(dp[i][j])) {
				if (j >= k && k < sz(dp[i - 1][j - k])) {
					dp[i][j][k] = suf[i - 1][j - k][k];
				}
			}
		}
		comp(i);
	}
	mi ans = accumulate(all(dp.bk.bk), mi(0));
	ps(ans);
	return 0;
}