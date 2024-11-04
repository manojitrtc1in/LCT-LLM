




























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



























mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<V<V<T>>>;
template <class T> using VVVV = V<V<V<V<T>>>>;







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
	template <class T, class ...U> void re(T& t, U&... u);
	template <class T, class U> void re(pair<T, U>& p); 


	

	template <class T> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } 

	template <class T> typename enable_if<id4<T>,void>::type re(T& i); 

	template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
	template <class T> typename enable_if<id4<T>,void>::type re(T& i) {
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
	

	template <class ...T> void pr(const T&... t) { pr_sep(cout, "", t...); } 
	

	void ps() { cout << "\n"; }
	template <class ...T> void ps(const T&... t) { pr_sep(cout, " ", t...); ps(); } 
	

	template <class ...T> void dbg_out(const T&... t) {
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

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; 

		return r >= b ? r - b : r;
	}
};

FastMod F(2);

int MOD = 998244353;
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
	mi& operator*=(const mi& m) { 
		

		val = (long long)val * m.val % MOD;
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

const int N = 505;
const int I = N * N / 2;

bool vis[N][I];
mi C[N][N];
mi dp[N][I];
mi diff[2 * I];
mi pdiff[2 * I];
mi fact[N];

mi solve(int n, int k) {
    int total = n * (n - 1) / 2;       
    if (k < 0 || k > total) {
    	return 0;  
    }
    ckmin(k, total - k);      
    if (vis[n][k]) {
    	return dp[n][k]; 
    }
    vis[n][k] = true;
    if (k == 0) {
    	return dp[n][0] = 1;   
    }
    if (n == 0) {
    	return dp[0][k] = 0;   
    }
    return dp[n][k] = solve(n, k - 1) + solve(n - 1, k) - solve(n - 1, k - n);
}

void solve_case(int tc = 0) {
	int n; 
	re(n, MOD);	
	C[0][0] = 1;
	f1r(i, 1, N + 1) {
		f0r(j, N + 1) {
			C[i][j] = C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);
		}
	}
	mi ans = 0;
	fact[0] = 1;
	f1r(i, 1, n + 1) {
		fact[i] = fact[i - 1] * i;
	}
	F = FastMod(MOD);
	vector<mi> p1;
	vector<mi> p2;
	f1r(i, 4, n + 1) { 

		int m = i - 1;
		int inv = m * (m - 1) / 2;
		if (m == 3) {
			f0r(jj, inv + 1) {
				f0r(kk, inv + 1) {
					diff[kk - jj + I] += solve(m, jj) * solve(m, kk);
				}
			}
		} else {
			p1.assign(inv + 1 + I, 0);
			p2.assign(inv + 1 + I, 0);
			f1r(ii, -inv, inv + 1) {
				p1[ii + I] = p1[ii - 1 + I] + pdiff[ii + I];
				p2[ii + I] = p2[ii - 1 + I] + ii * pdiff[ii + I];		
			}
			f1r(ii, -inv, inv + 1) {
				int st = max(ii - m, -inv);
				int coeff = m - (ii - st);
				diff[ii + I] = p2[ii + I] - p2[st - 1 + I] + (coeff - st) * (p1[ii + I] - p1[st - 1 + I]);
				int ed = min(ii + m, inv);
				

				

				

				

				coeff = m - 1;
				diff[ii + I] += p2[ii + I] - p2[ed + I] + (coeff + (ii + 1)) * (p1[ed + I] - p1[ii + I]);
				

				

			}
		}
		f1r(ii, -inv, inv + 1) {
			pdiff[ii + I] = diff[ii + I];
		}
		int lim = max(inv, i);
		vmi use(lim + 2);
		vmi store(lim + 2);
		f0r(j, inv + 1) {
			use[j] = diff[j + I];
		}
		for (int j = lim; j >= 1; --j) {
			use[j - 1] += use[j];
		}
		

		f1r(j, 1, i + 1) {
			f1r(k, j + 1, i + 1) {
				mi ways = C[n][n - i] * fact[n - i];
				mi res = ways * use[k - j + 1];
				ans += res;
			}
		}
	}
	ps(ans);
}

int main() {
	setIO("");
	int tt = 1;
	

	f1r(tc, 1, tt + 1) {
		solve_case(tc);
	}
	return 0;
}