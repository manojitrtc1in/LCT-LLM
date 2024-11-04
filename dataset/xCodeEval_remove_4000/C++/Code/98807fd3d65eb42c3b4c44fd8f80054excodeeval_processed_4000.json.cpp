




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










const int MOD = 1e9+7; 

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
	tcT> constexpr bool id11 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id2 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id3 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id10 = !id2<T> && id11<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id2<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id10<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id10<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id4 = !id3<T> && id11<T>;

	

	tcT> typename enable_if<id3<T>,str>::type ts(T v) {
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
	tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
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
	  id8(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id4<T>,vs>::type 
	  id8(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id8<lev-1>(t);
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
	template<int lev, class T> void id12(const T& t) {
		cerr << "\n\n" << ts_sep(id8<lev>(t),"\n") << "\n" << endl; }
	
		
		
	
		
		
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0);
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 
	}
}

int N,M;
V<AR<int,3>> val;
int BLOCK = 1;

void sub(vi& v) { each(t,v) --t; }

struct RangeQuery {
	static constexpr int SZ = 450;
	ll block_sum[SZ];
	ll sing[SZ*SZ];
	ll get_sum(int r) {
		ll ans = 0; while (r%BLOCK != 0) ans += sing[--r];
		for (r /= BLOCK;r;) ans += block_sum[--r];
		return ans;
	}
	void increment(int x, ll v) {
		block_sum[x/BLOCK] += v;
		sing[x] += v;
	}
};

RangeQuery RQ;

vpi cur[MX];


const int THRESH = 0;

const int THRESH = 1500;


vi oc;
void contrib(int v, int sgn) {
	if (oc[v] > THRESH) return;
	int one = 0; ll two = 0;
	each(t,cur[v]) {
		if (t.s == 0) {
			++one;
		} else if (t.s == -1) {
			two += one;
		} else if (t.s == -2) {
			RQ.increment(t.f,sgn*two);
		}
	}
}

void upd(int pos, int j, int sgn) {
	int v = val[pos][j];
	if (oc[v] > THRESH) return;
	contrib(v,-1);
	pi p{pos,-j};
	if (sgn == -1) {
		auto it = find(all(cur[v]),p); assert(it != end(cur[v]));
		cur[v].erase(it);
	} else {
		auto it = lb(all(cur[v]),p); cur[v].ins(it,p);
	}
	contrib(v,1);
}

vi A, B, C;
void add_oc(int x) { ++oc[B[x]], ++oc[x], ++oc[C[x]]; }

vl ans;
V<tuple<int,int,int>> queries;

void deal_small() {
	id5(i,N) {
		val[i] = {B[A[i]],A[i],C[A[i]]};
		R0F(j,3) cur[val[i][j]].pb({i,-j});
	}
	id5(i,N) contrib(i,1);
	each(t,queries) {;
		auto [type,_a,_b] = t;
		if (type == 1) {
			auto [_,i,x] = t; 
			id5(j,3) upd(i,j,-1);
			val[i] = {B[x],x,C[x]};
			id5(j,3) upd(i,j,1);
		} else {
			auto [_a,r,_b] = t;
			ans.pb(RQ.get_sum(r));
		}
	}
}

constexpr AR<AR<int,4>,4> zz{{
	{-1,0,1,2},
	{-1,-1,3,4},
	{-1,-1,-1,5},
	{-1,-1,-1,-1}
}};

AR<ll,3> id0(const AR<ll,3>& pref, const AR<ll,6>& block) {
	return {pref[0]+block[zz[0][1]],
			pref[0]*block[zz[1][2]]+pref[1]+block[zz[0][2]],
			pref[0]*block[zz[1][3]]+pref[1]*block[zz[2][3]]+pref[2]+block[zz[0][3]]};
}

vpi relevant[450];
AR<ll,3> pref[450];
AR<ll,6> blocks[450];

void deal_large() {
	id5(v,N) if (oc[v] > THRESH) {
		auto id1 = [&]() {
			id5(i,BLOCK-1) pref[i+1] = id0(pref[i],blocks[i]);
		};
		auto id9 = [&](int x) {
			assert(0 <= x && x < BLOCK);
			relevant[x].clear();
			AR<ll,6>& stor = blocks[x]; stor = {};
			FOR(i,x*BLOCK,min((x+1)*BLOCK,N)) {
				if (val[i][2] == v) {
					relevant[x].pb({i,-2});
					++stor[zz[2][3]];
					stor[zz[1][3]] += stor[zz[1][2]];
					stor[zz[0][3]] += stor[zz[0][2]];
				}
				if (val[i][1] == v) {
					relevant[x].pb({i,-1});
					++stor[zz[1][2]];
					stor[zz[0][2]] += stor[zz[0][1]];
				}
				if (val[i][0] == v) {
					relevant[x].pb({i,0});
					++stor[zz[0][1]];
				}
			}
		};
		auto id7 = [&](int x) {
			AR<ll,6>& stor = blocks[x]; stor = {};
			for (const pi& p: relevant[x]) {
				if (p.s == -2) {
					++stor[zz[2][3]];
					stor[zz[1][3]] += stor[zz[1][2]];
					stor[zz[0][3]] += stor[zz[0][2]];
				} else if (p.s == -1) {
					++stor[zz[1][2]];
					stor[zz[0][2]] += stor[zz[0][1]];
				} else {
					++stor[zz[0][1]];
				}
			}
			FOR(i,x,BLOCK-1) pref[i+1] = id0(pref[i],blocks[i]);
		};
		
	
		id5(i,N) val[i] = {B[A[i]],A[i],C[A[i]]};
		id5(x,BLOCK) id9(x);
		id1();
		int ans_cnt = 0;
		each(t,queries) {
			auto [type,_a,_b] = t;
			if (type == 1) {
				auto [_,i,x] = t; 
				bool flag = 0;
				int label = i/BLOCK;
				id5(j,3) if (val[i][j] == v) relevant[label].erase(lb(all(relevant[label]),mp(i,-j))), flag = 1;
				val[i] = {B[x],x,C[x]};
				id5(j,3) if (val[i][j] == v) relevant[label].ins(lb(all(relevant[label]),mp(i,-j)),mp(i,-j)), flag = 1;
				if (flag) id7(label);
			} else {
				auto [_a,r,_b] = t;
				AR<ll,3> a = pref[r/BLOCK];
				for (const auto& p: relevant[r/BLOCK]) {
					if (p.f >= r) break;
					if (p.s == 0) ++a[0];
					else if (p.s == -1) a[1] += a[0];
					else if (p.s == -2) a[2] += a[1];
				}
				ans[ans_cnt++] += a[2];
			}
		}
		assert(ans_cnt == sz(ans));
	}
}

int main() {
	dbg(THRESH);
	setIO(); re(N,M);
	while (BLOCK*BLOCK <= N) ++BLOCK;
	A.rsz(N), B.rsz(N), C.rsz(N); re(A,B,C);
	sub(A), sub(B), sub(C);
	val.rsz(N);
	oc = vi(N);
	id5(i,N) add_oc(A[i]);
	rep(M) {
		ints(type);
		if (type == 1) {
			ints(i,x); --i, --x;
			queries.pb({type,i,x});
			add_oc(x);
		} else {
			ints(r);
			queries.pb({type,r,-1});
		}
	}
	deal_small();
	deal_large();
	each(t,ans) ps(t);
}