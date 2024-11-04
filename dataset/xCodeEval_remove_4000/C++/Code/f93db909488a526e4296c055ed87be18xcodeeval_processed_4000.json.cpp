
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 


using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;





tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;



























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }










const int MOD = 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; 

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id6(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { 

	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } 




inline namespace Helpers {
	

	

	

	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool id9 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id0 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id1 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id8 = !id0<T> && id9<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id8<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id8<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


	

	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	

	void decrement() {} 

	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	
	
}

inline namespace ToString {
	tcT> constexpr bool id4 = !id1<T> && id9<T>;

	

	tcT> typename enable_if<id1<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id5(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id4<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id9<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id4<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id4<T>,vs>::type 
	  id7(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id4<T>,vs>::type 
	  id7(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id7<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id5(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	

	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	

	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	

	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void id10(const T& t) {
		cerr << "\n\n" << ts_sep(id7<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}

int N;
vi adj[305];





template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } 

	int v; explicit operator int() const { return v; } 

	mint() { v = 0; }
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((ll)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; 

typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) id5(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

int max_bad;

map<pi,mi> solve(int x, int y) {
	map<pi,mi> dp;
	dp[{MOD,0}] = 1; 

	

	each(c,adj[x]) if (c != y) {
		auto c_ans = solve(c,x);
		map<pi,mi> DP;
		each(a,dp) each(b,c_ans) {
			int closest = min(a.f.f,b.f.f+1);
			int id3 = max(a.f.s,b.f.s+1);
			if (id3 <= max_bad)
				DP[{closest,id3}] += a.s*b.s;
		}
		swap(dp,DP);
	}
	map<pi,mi> DP;
	each(a,dp) {
		assert(a.f.s <= max_bad);
		if (a.f.f+a.f.s <= max_bad) {
			DP[{a.f.f,-1}] += a.s;
		} else {
			DP[a.f] += a.s;
		}
		DP[{0,-1}] += a.s;
	}
	return DP;
}

void ad(vmi& v, int ind, mi prod) {
	while (sz(v) <= ind) v.pb(0);
	v[ind] += prod;
}

AR<vmi,2> solve_new(int a, int b) {
	AR<vmi,2> dp; 

	dp[0] = {1};
	

	


	each(c,adj[a]) if (c != b) {
		auto c_ans = solve_new(c,a);
		id5(i,2) c_ans[i].ins(begin(c_ans[i]),0);
		AR<vmi,2> res;
		id5(x,2) id5(y,2) 
			id5(xx,sz(dp[x])) id5(yy,sz(c_ans[y])) {
				mi prod = dp[x][xx]*c_ans[y][yy];
				if (x == 0) {
					if (y == 0) {
						ad(res[0],max(xx,yy),prod);
					} else {
						if (xx+yy <= max_bad) {
							ad(res[1],yy,prod);
						} else {
							ad(res[0],xx,prod);
						}
					}
				} else {
					if (y == 0) {
						if (xx+yy <= max_bad) {
							ad(res[1],xx,prod);
						} else {
							ad(res[0],yy,prod);
						}
					} else {
						ad(res[1],min(xx,yy),prod);
					}
				}
			}
		swap(dp,res);
	}
	

	auto DP = dp;
	id5(i,sz(dp[0])) if (i <= max_bad) ad(DP[1],0,dp[0][i]);
	id5(i,sz(dp[1])) ad(DP[1],0,dp[1][i]);
	

	return DP;
}

mi id2(int x) {
	auto a = solve_new(1,0);
	dbg("HA",a);
	mi ans = 0;
	each(t,a[1]) ans += t;
	return ans;
	

	

	

	

	

}






	


int main() {
	setIO(); re(N);
	rep(N-1) {
		ints(a,b);
		adj[a].pb(b), adj[b].pb(a);
	}
	vmi rec(N);
	id5(x,N) {
		max_bad = x;
		rec[x] = id2(x);
	}
	dbg(rec);
	assert(rec.bk == pow(mi(2),N)-1);
	

	mi ans = 0;
	id5(i,N) {
		ans += (rec[i]-(i?rec[i-1]:0))*(i-1);
		

		

		

		

	}
	ans += N;
	dbg(ans);
	ps(ans/pow(mi(2),N));
	

	

}


