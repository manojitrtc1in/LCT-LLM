
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
const ll INF = (ll)(1e18)+5; 

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 




constexpr int pct(int x) { return __builtin_popcount(x); } 

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
	tcT> constexpr bool id7 = is_iterable<T>::value;
 
	

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
	tcT> constexpr bool id6 = !id0<T> && id7<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 

 
	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id6<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id6<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id2 = !id1<T> && id7<T>;
 
	

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
	tcT> typename enable_if<id7<T>,str>::type ts_sep(T v, str sep) {
		

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
	template<int lev, class T> void id8(const T& t) {
		cerr << "\n\n" << ts_sep(id5<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	
}
 
inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}
 
const int SZ = 1<<18;
 
int N,Q;
vi pos;
vl cur;
vi wei, val;
 
template<class T> struct Seg { 

	

	
	

	T comb(T a, T b) { return {a[0]+b[0],min(a[1],a[0]+b[1]),a[2]+b[2]}; } 
	int n; V<T> seg;
	void init(int _n) { 

		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,{0,INF,0}); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { 

		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	int walk(ll& c, ll& ans, int& next_ind, int ind, int L, int R) {
		if (R < next_ind) return MOD;
		if (next_ind <= L) {
			if (seg[ind][1] <= c) {
				if (L == R) return L;
			} else if (seg[ind][0] <= c) { 

				c -= seg[ind][0];
				ans += seg[ind][2];
				return MOD;
			} else {
				if (L == R) return L;
			}
		}
		int M = (L+R)/2;
		int done = walk(c,ans,next_ind,2*ind,L,M);
		if (done != MOD) return done;
		return walk(c,ans,next_ind,2*ind+1,M+1,R);
	}
};
 
Seg<AR<ll,3>> segs[31];
 
void fassert(bool b) {
	if (!b) exit(0);
}
 
void deal(ll& c, ll& ans, int& next_ind, int p) {
	

	ll ori_c = c;
	int done = segs[p].walk(c,ans,next_ind,1,0,SZ-1);
	if (done != MOD) {
		ll num = c/wei[done]; 
		if (!(num <= cur[done])) {
			ps("OOPSA",done,wei[done],cur[done]);
			exit(0);
		}
		c -= num*wei[done];
		ans += num*val[done];
		if (c >= (1<<p)) {
			ps("OOPSB");
			exit(0);
		}
		if (ori_c == c) {
			ps("OOPSC");
			exit(0);
		}
	}
	next_ind = done;
}
 
ll query(ll c) {
	ll ans = 0;
	int next_ind = 0;
	while (next_ind < N && c) {
		int p = 0; while (p < 30 && ((1<<(p+1)) <= c)) ++p;
		deal(c,ans,next_ind,p);
	}
	return ans;
}
 
void recalc(int p, int ind) {
	if (cur[ind] == 0) { 

		segs[p].upd(ind,{0,INF,0});
	} else if (wei[ind] <= (1<<p)) {
		segs[p].upd(ind,{cur[ind]*wei[ind],INF,cur[ind]*val[ind]});
	} else {
		segs[p].upd(ind,{0,wei[ind],0});
	}
}
 
void upd(int ind, int dif) {
	ind = pos[ind];
	assert(cur[ind]+dif >= 0);
	cur[ind] += dif;
	id3(p,31) recalc(p,ind);
}
 
int main() {
	setIO(); re(N,Q); cur.rsz(N);
	id3(i,31) segs[i].init(SZ);
	V<AR<int,4>> cands;
	vi init(N);
	id3(i,N) {
		ints(a,w,v);
		init[i] = a;
		cands.pb({v,-w,i});
	}
	sort(rall(cands));
	pos.rsz(N);
	dbg("FILL");
	id3(i,N) {
		pos[cands[i][2]] = i;
		val.pb(cands[i][0]);
		wei.pb(-cands[i][1]);
	}
	id3(i,N) upd(i,init[i]);
	id3(i,N) dbg(i,val[i],wei[i],cur[i]);
	dbg("INITED");
	rep(Q) {
		ints(t);
		if (t == 1) {
			ints(k,d);
			upd(d-1,k);
		} else if (t == 2) {
			ints(k,d);
			upd(d-1,-k);
		} else {
			ll c; re(c);
			ps(query(c));
		}
	}
}
