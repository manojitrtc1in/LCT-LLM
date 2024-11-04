
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;



















tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr ll pct(ll x) { return __builtin_popcountll(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id4(int x) { return p2(x)-1; }

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
	tcT> constexpr bool id8 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id7 = !id0<T> && id8<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id7<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id7<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id2 = !id1<T> && id8<T>;

	

	tcT> typename enable_if<id1<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id3(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id2<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id8<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id2<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id2<T>,vs>::type 
	  id5(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id2<T>,vs>::type 
	  id5(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id5<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id3(i,sz(res)) {
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
	template<int lev, class T> void id9(const T& t) {
		cerr << "\n\n" << ts_sep(id5<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

	const clock_t beg = clock();
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}



struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { 

		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};



DSU D;

int N,M;
vl sig;

void add_all(ll l, ll r, int ind) {
	assert(l < r);
	ll dif = r-l;
	if (pct(dif) == 1 && l%dif == 0) return;
	

	ll m = ((r-1)>>ind)<<ind;
	if (l < m && m < r) {
		add_all(l,m,ind-1);
		sig.pb(m);
		add_all(m,r,ind-1);
		return;
	}
	add_all(l,r,ind-1);
}

int main() {
	setIO();
	re(N,M);
	V<tuple<char,ll,ll>> query;
	vl _sig{0};
	_sig.pb(1LL<<N);
	rep(M) {
		str t; re(t);
		if (t == "block") {
			ll l,r; re(l,r); ++r;
			_sig.pb(l), _sig.pb(r);
			query.pb({'B',l,r});
		} else {
			ll a,b; re(a,b);
			query.pb({'A',a,b});
		}
	}
	

	remDup(_sig);
	id3(i,sz(_sig)-1) {
		sig.pb(_sig[i]);
		add_all(_sig[i],_sig[i+1],N);
	}
	

	sig.pb(_sig.bk);
	

	dbg(sig);
	id3(i,sz(sig)-1) assert(sig[i] < sig[i+1]);

	D.init(sz(sig)-1);
	auto comp = [&](ll x) {
		return upb(sig,x)-1;
	};
	vb active(sz(sig)-1,1);
	each(t,query) {
		auto [c,x,y] = t;
		if (c == 'B')
		FOR(i,comp(x),comp(y)) {
			

			active[i] = 0;
		}
	}
	auto activate = [&](int x) {
		

		active[x] = 1;
		

		ll a = sig.at(x), b = sig.at(x+1);
		

		ll dif = b-a;
		assert(pct(dif) == 1);
		

		id3(i,N) if (dif <= (1LL<<i)) {
			

			ll st = a^(1LL<<i), en = (b-1)^(1LL<<i);
			assert(st <= en); ++en;
			int it = upb(sig,st);
			for (int j = it-1; j < sz(sig) && sig[j] < en; ++j) {
				if (active[j]) D.unite(x,j);
			}
		}
		

	};
	

	id3(i,sz(active)) if (active[i]) activate(i);
	

	


	vb ans;
	id6(q,sz(query)) {
		auto [c,x,y] = query[q];
		

		if (c != 'A') {
			int l = lwb(sig,x), r = lwb(sig,y);
			FOR(i,l,r) activate(i);
		} else {
			int a = comp(x), b = comp(y);
			ans.pb(D.sameSet(a,b));
			

		}
	}
	reverse(all(ans));
	dbg(ans);
	for (bool t: ans) ps(t);
	

}


