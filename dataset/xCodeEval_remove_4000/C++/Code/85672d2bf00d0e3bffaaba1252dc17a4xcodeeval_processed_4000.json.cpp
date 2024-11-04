
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
	tcT> constexpr bool id1 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id10 = !id1<T> && id11<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

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
	tcT> constexpr bool id4 = !id2<T> && id11<T>;

	

	tcT> typename enable_if<id2<T>,str>::type ts(T v) {
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

vi bit(25005,MOD);
void id3(int x, int y) {
	for (;x; x -= x&-x) ckmin(bit[x],y);
}
int id9(int x) {
	int ans = MOD;
	for (;x<sz(bit); x+=x&-x) ckmin(ans,bit[x]);
	return ans;
}





























































int N,Q;
vpi imp;
vi A, rev_A;
vpi _ranges, ranges, cand;
vpi cand_left[25005], cand_right[25005];

void id7() {
	ranges = _ranges;
	const int B = max(int(N/sqrt(Q)),1);
	sort(all(ranges),[&](pi a, pi b) {
		if (a.f/B != b.f/B) return a.f < b.f;
		return a.s < b.s;
	});
	set<int> s;
	int l = 1, r = 0;
	each(t,ranges) {
		auto ins = [&](int x) {
			auto it = s.ins(x).f;
			if (it != begin(s)) cand.pb({*prev(it),*it});
			if (next(it) != end(s)) cand.pb({*it,*next(it)});
		};
		auto del = [&](int x) {
			auto it = s.find(x);
			if (it != begin(s) && next(it) != end(s)) cand.pb({*prev(it),*next(it)});
			s.erase(it);
		};
		while (l > t.f) ins(A[--l]);
		while (r < t.s) ins(A[++r]);
		while (l < t.f) del(A[l++]);
		while (r > t.s) del(A[r--]);
	}
	sor(cand); cand.erase(unique(all(cand)),end(cand));
	id5(i,sz(cand)) {
		int lo = rev_A[cand[i].f], hi = rev_A[cand[i].s];
		if (lo < hi) cand_right[lo].eb(hi,i);
		else cand_left[lo].eb(hi,i);
	}
	swap(ranges,_ranges);
}

V<AR<int,3>> ev[MX];
vpi add[MX];

void id0() {
	A.pb(0);
	FOR(i,1,N+1) {
		reverse(all(cand_left[i]));
		reverse(all(cand_right[i]));
		cand_left[i].eb(0,-1), cand_right[i].eb(N+1,-1);
		

		for (int il = 0, ir = 0; il < sz(cand_left[i])-1 || ir < sz(cand_right[i])-1; ) {
			

			if (A[cand_left[i][il].f] > A[cand_right[i][ir].f]) {
				assert(il < sz(cand_left[i])-1);
				int id = cand_left[i][il].s;
				ev[cand_left[i][il].f].pb({i,id,0});
				ev[cand_left[i][il+1].f].pb({i,id,1});
				ev[cand_left[i][il].f].pb({cand_right[i][ir].f,id,1});
				++il;
			} else {
				assert(ir < sz(cand_right[i])-1);
				int id = cand_right[i][ir].s;
				assert(cand_right[i][ir].f < cand_right[i][ir+1].f);
				ev[i].pb({cand_right[i][ir].f,id,0});
				ev[i].pb({cand_right[i][ir+1].f,id,1});
				ev[cand_left[i][il].f].pb({cand_right[i][ir].f,id,1});
				++ir;
			}
		}
	}
	id5(i,Q) add[ranges[i].f].pb({ranges[i].s,i});
}

int main() {
	setIO(); re(N,Q);
	A.rsz(N+1); FOR(i,1,N+1) re(A[i]);
	rev_A.rsz(N+1); FOR(i,1,N+1) rev_A[A[i]] = i;

	_ranges.rsz(Q); re(_ranges);
	id7();
	id0();

	dbg(cand);
	vi in(sz(cand),Q), out(sz(cand),Q);
	FOR(i,1,N+1) {
		each(t,add[i]) id3(t.f,t.s);
		each(t,ev[i]) {
			dbg("HA",i,t);
			if (t[2] == 0) {
				ckmin(in[t[1]],id9(t[0]));
			} else {
				ckmin(out[t[1]],id9(t[0]));
			}
		}
	}
	vi ans(Q+1);
	id5(i,sz(cand)) {
		dbg("OOPS",i,in[i],out[i]);
		assert(in[i] <= out[i]);
		++ans[in[i]]; --ans[out[i]];
	}
	id5(i,Q) {
		if (i) ans[i] += ans[i-1];
		ps(ans[i]);
	}
	

}


