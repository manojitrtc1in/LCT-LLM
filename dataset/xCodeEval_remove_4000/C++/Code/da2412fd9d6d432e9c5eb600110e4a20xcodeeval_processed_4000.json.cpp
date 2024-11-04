
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

const int MX = 1<<18;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id5(int x) { return p2(x)-1; }

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
	tcT> constexpr bool id2 = is_printable<T>::value;
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
	tcT> constexpr bool id3 = !id2<T> && id8<T>;

	

	tcT> typename enable_if<id2<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id4(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id3<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id8<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id3<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id3<T>,vs>::type 
	  id6(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id3<T>,vs>::type 
	  id6(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id6<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id4(i,sz(res)) {
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
		cerr << "\n\n" << ts_sep(id6<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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



template <class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
	template<typename... Args> T sum(int r, Args... args) {
		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
		return res; }
	template<typename... Args> T query(int l, int r, Args... 
		args) { return sum(r,args...)-sum(l-1,args...); }
}; 
template<class T, int N> int id1(const BIT<T,N>& bit, T des) { 
	assert(des > 0);
	int ind = 0;
	for (int i = 1<<bits(N); i; i /= 2)
		if (ind+i <= N && bit.bit[ind+i].val < des)
			des -= bit.bit[ind += i].val;
	assert(ind < N); return ind+1;
}

BIT<ll,MX> B0, B1;
int N,Q;
pair<pi,int> seg[2*MX]; 

int lazy[2*MX];

pair<pi,int> operator+(pair<pi,int> a, pair<pi,int> b) {
	if (a < b) swap(a,b);
	if (a.f.f == b.f.f) {
		return {{a.f.f,a.f.s+b.f.s},max(a.s,b.s)};
	} else {
		return {a.f,max(a.s,b.f.f)};
	}
}

void pull(int ind) {
	seg[ind] = seg[2*ind]+seg[2*ind+1];
}

void build(int ind, int L, int R) {
	lazy[ind] = MOD;
	if (L == R) {
		seg[ind] = {{L,1},-MOD};
		return;
	}
	int M = (L+R)/2;
	build(2*ind,L,M); build(2*ind+1,M+1,R);
	pull(ind);
}

void push(int ind, int L, int R) {
	assert(lazy[ind] > seg[ind].s);
	ckmin(seg[ind].f.f,lazy[ind]);
	if (L != R) {
		ckmin(lazy[2*ind],lazy[ind]);
		ckmin(lazy[2*ind+1],lazy[ind]);
	}
	lazy[ind] = MOD;
}

void upd(int index, ll dif) {
	

	B1.upd(1,dif);
	B1.upd(index+1,-dif);
	B0.upd(index+1,dif*index);
}

void set_equal(int c, int g, int ind, int L, int R) {
	push(ind,L,R);
	if (R < c || c < L) return;
	if (L == R) {
		

		upd(seg[ind].f.f,-seg[ind].f.s);
		upd(g,seg[ind].f.s);
		seg[ind].f.f = g;
		return;
	}
	int M = (L+R)/2;
	set_equal(c,g,2*ind,L,M);
	set_equal(c,g,2*ind+1,M+1,R);
	pull(ind);
}


void make_min(int lo, int hi, int v, int ind, int L, int R) {
	push(ind,L,R);
	if (v >= seg[ind].f.f || R < lo || hi < L) return;
	if (lo <= L && R <= hi && v > seg[ind].s) {
		upd(seg[ind].f.f,-seg[ind].f.s);
		upd(v,seg[ind].f.s);
		lazy[ind] = v;
		push(ind,L,R);
		return;
	}
	int M = (L+R)/2;
	make_min(lo,hi,v,2*ind,L,M);
	make_min(lo,hi,v,2*ind+1,M+1,R);
	pull(ind);
}

ll get_sum(int r) {
	return B1.sum(r)*r+B0.sum(r);
}

void add_range(int l, int r) {
	upd(l-1,-1);
	upd(r,1);
}

int main() {
	setIO();
	re(N,Q);
	upd(N,1);
	build(1,1,N);
	rep(Q) {
		ints(p);
		if (p == 1) {
			ints(c,g);
			set_equal(c,g,1,1,N);
			make_min(1,c-1,c-1,1,1,N);
		} else {
			ints(l,r);
			ps(get_sum(r)-get_sum(l-1));
		}
	}
	

}


