
































































































































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
	++hi; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); 

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
	template<int lev, class T> void id10(const T& t) {
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

struct Frag{
	pi min_pref;
	int sum;
	Frag(int num, int ind){
		sum = num;
		min_pref = min(mp(num, ind), mp(0, ind-1));
	}
	Frag(){
		min_pref = mp(MOD, -1);
		sum = 0;
	}
};

Frag combFrag(Frag a, Frag b){
	Frag res = Frag();
	res.min_pref = min(a.min_pref, mp(b.min_pref.f+a.sum, b.min_pref.s));
	res.sum = a.sum+b.sum;
	return res;
}



tcT> struct SegTree { 

	const T ID = Frag(); T cmb(T a, T b) { return combFrag(a, b); } 
	int n; V<T> seg;
	void init(int _n) { 

		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, int val) { 

		seg[p += n] = Frag(val, p); for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	

		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

const int mx = 400005;


int n, q;
int p[mx];
int ip[mx];
int vals[mx];
ll id9 = 0;
ll id1 = 0;

int red(int a){
	int res = a % (2*n+1);
	res = (res+2*n+1) % (2*n+1);
	if(res == 0) return 2*n+1;
	return res;
}

void contrib(int cur0, int cur1, int mult){
	if(cur0 <= n+1 && cur1 <= n+1){
		int val = red(ip[cur1]-ip[cur0]);
		id9 += mult*val;
	}
	else{
		assert(cur0 >= n+1 && cur1 >= n+1);
		int val = red(ip[cur1]-ip[cur0]);
		id1 += mult*val;
	}
}

void setIP(int a, int b){ 

	set<pi> affected;
	if(a < n+1){
		if(a-1 <= 0){
			assert(a-1 == 0);
			affected.insert(mp(n+1, a));
		}
		else{
			affected.insert(mp(a-1, a));
		}

		affected.insert(mp(a, a+1));
	}
	else if(a > n+1){
		if(a+1 > 2*n+1){
			assert(a+1 == 2*n+2);
			affected.insert(mp(a, n+1));
		}
		else{
			affected.insert(mp(a, a+1));
		}

		affected.insert(mp(a-1, a));
	}
	else{
		affected.insert(mp(2*n+1, n+1));
		affected.insert(mp(n+1, 1));
		affected.insert(mp(n, n+1));
		affected.insert(mp(n+1, n+2));
	}

	for(auto u: affected){
		contrib(u.f, u.s, -1);
	}

	ip[a] = b;
	for(auto u: affected){
		contrib(u.f, u.s, +1);
	}
}

SegTree<Frag> seg;



int main() {
	setIO();
	seg.init(262144*2);
	cin >> n >> q;
	for(int i = 1; i <= 2*n+1; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= 2*n+1; i++){
		ip[p[i]] = i;
	}
	dbg("HI");
	for(int i = 1; i <= 2*n+1; i++){
		dbg("UPD", i);
		int coresp = 0;
		if(p[i] < n+1){
			coresp = -1;
		}
		else if(p[i] > n+1){
			coresp = +1;
		}
		vals[i] = coresp;
		seg.upd(i, vals[i]);
		seg.upd(i+2*n+1, vals[i]);
	}
	for(int i = 1; i <= n+1; i++){
		int next_val = i+1;
		if(next_val > n+1){
			next_val = 1;
		}
		id9+=red(ip[next_val]-ip[i]);
	}

	for(int i = n+1; i <= 2*n+1; i++){
		int next_val = i+1;
		if(next_val > 2*n+1){
			next_val = n+1;
		}
		id1+=red(ip[next_val]-ip[i]);
	}

	for(int i = 1; i <= q; i++){
		int u, v;
		cin >> u >> v;

		swap(p[u], p[v]);
		setIP(p[u], u);
		setIP(p[v], v);

		swap(vals[u], vals[v]);
		seg.upd(u, vals[u]);
		seg.upd(v, vals[v]);
		seg.upd(u+2*n+1, vals[u]);
		seg.upd(v+2*n+1, vals[v]);

		Frag lowest_frag = seg.query(ip[n+1], ip[n+1]+2*n);
		int start_val = -1;
		if(lowest_frag.min_pref.f < 0){
			dbg(lowest_frag.min_pref);
			start_val = red(lowest_frag.min_pref.s+1);
		}
		else if(id9 > 2*n+1){
			start_val = red(ip[n+1]+1);
		}
		else if(id1 > 2*n+1){
			start_val = red(ip[n+1]);
		}
		else{
			ps(-1);
			continue;
		}
		assert(start_val != -1);
		ps(start_val-1);
	}




	

}


