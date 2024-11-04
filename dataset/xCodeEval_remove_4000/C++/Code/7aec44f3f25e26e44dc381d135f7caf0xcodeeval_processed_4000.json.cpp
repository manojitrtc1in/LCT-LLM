




























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
	template <class T, class ...U> void re(T& t, U&... u);
	template <class T, class U> void re(pair<T, U>& p); 


	

	template <class T> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	template <class T> void re(complex<T>& c) { T a, b; re(a, b); c = {a, b}; } 

	template <class T> typename enable_if<id5<T>,void>::type re(T& i); 

	template <class T, class U> void re(pair<T, U>& p) { re(p.first, p.second); }
	template <class T> typename enable_if<id5<T>,void>::type re(T& i) {
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
	

	template <class ...T> void pr(const T&... t) { pr_sep(cout, "", t...); } 
	

	void ps() { cout << "\n"; }
	template <class ...T> void ps(const T&... t) { pr_sep(cout, " ", t...); ps(); } 
	

	template <class ...T> void dbg_out(const T&... t) {
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

template <class T> struct FenwickTree {
	std::vector<T> fwt;
	int n;

	void init(int n_) {
		n = n_;
		fwt.assign(n, 0);
	}

	void init(std::vector<T>& a) {
		n = (int)a.size();
		fwt.assign(n, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			add(i, a[i]);
		}
	}

	T sum(int r) {
		T ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) 
			ret += fwt[r];
		return ret;
	}

	T query(int l, int r) {
		if (l > r) {
			return 0;
		}
		return sum(r) - sum(l - 1);
	}
	
	void add(int idx, T delta) {
		for (; idx < n; idx = idx | (idx + 1)) 
			fwt[idx] += delta;
	}
};

const int A = 3e5 + 5;
const int N = 2e5 + 5;
const int B = 1100;

int main() {
	setIO("");
	int n; 
	re(n);
	vl a(n);
	re(a);
	vl ans(n);
	{ 

		ll run = 0;
		id8(i, n) {
			run += a[i];
			ans[i] += run * (i + 1);
		}
	}
	vl sub(n);
	{ 

		FenwickTree<int> F; 
		F.init(A);
		id8(i, n) { 
			F.add(a[i], 1);
			id1(d, 1, A + 1) {
				if (d * a[i] >= A) {
					break;
				}
				auto res = F.query(a[i] * d, A - 1);
				sub[i] += a[i] * F.query(a[i] * d, A - 1);
			}
		}
		id8(i, n) {
			if (a[i] <= B) {
				id1(j, i, n) {
					if (a[i] < a[j]) {
						sub[j] += a[j] / a[i] * a[i];
					}
				}
			}
		}
		FenwickTree<ll> sum;
		sum.init(A);
		id8(i, n) {
			

			id8(j, i) {
				if (a[j] < a[i] && a[j] > B) {
					

				}
			}
			id1(d, 1, A + 1) {
				

				

				int lb = B + 1;
				int rb = a[i] / d;
				if (lb > rb) {
					break;
				}	
				sub[i] += sum.query(lb, rb);
			}
			sum.add(a[i], a[i]);
		}
	}
	id1(i, 1, n) {
		sub[i] += sub[i - 1];
	}
	id8(i, n) ans[i] -= sub[i];
	

	id8(i, n) {
		if (a[i] <= B) {

		}
	}
	id8(i, n) pr(ans[i], " ");
	ps();
	return 0;
}

