
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
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}

const int BIG = (1<<20)-1;

struct Node {
	int sum = 0; 

	int branch = 0; 

	int lazy_or = 0, lazy_xor = 0; 

	int depth;
	AR<int,2> c{0,0};
};




int N,Q;

const int STORAGE = 10000000;
vi avail;
Node trie[STORAGE];
bool use[STORAGE];

void id6(int ind, int val) { 

	if (ind == 0) return;
	Node& n = trie[ind];
	n.lazy_xor ^= val;
}

void free_up(int x) {
	assert(x);
	assert(use[x]);
	use[x] = 0;
	avail.pb(x);
}

void prop(int ind, int lev) {
	assert(ind); --lev;
	Node& n = trie[ind];
	if (lev >= 0) {
		if (n.lazy_or&(1<<lev)) {
			assert(!n.c[0] || !n.c[1]);
			if (n.c[0]) swap(n.c[0],n.c[1]);
		}
		if (n.lazy_xor&(1<<lev)) {
			swap(n.c[0],n.c[1]);
		}
	}
	id3(i,2) if (n.c[i]) {
		trie[n.c[i]].lazy_or |= n.lazy_or;
		trie[n.c[i]].lazy_xor &= BIG-n.lazy_or;
		trie[n.c[i]].lazy_xor ^= n.lazy_xor;
	}
	n.lazy_or = n.lazy_xor = 0;
}

int make_node(int l, int r, int lev) {
	if (lev == 0) {
		assert(l == 0 && r == 0);
	} else {
		if (l == 0 && r == 0) return 0;
	}
	assert(sz(avail));
	int pos = avail.bk; avail.pop_back();
	use[pos] = 1;
	Node& n = trie[pos];
	n = Node();
	n.c = {l,r};
	n.depth = lev;
	if (lev == 0) {
		n.sum = 1;
	} else {
		id3(i,2) if (n.c[i]) {
			n.sum += trie[n.c[i]].sum;
			n.branch |= trie[n.c[i]].branch;
			assert(n.depth == trie[n.c[i]].depth+1);
		}
		if (n.c[0] && n.c[1]) n.branch |= 1<<(lev-1);
	}
	assert(n.sum);
	return pos;
}

int merge(int x, int y, int lev = 20) {
	if (!x) return y;
	if (!y) return x;
	prop(x,lev), prop(y,lev);
	AR<int,2> child;
	id3(i,2) child[i] = merge(trie[x].c[i],trie[y].c[i],lev-1);
	free_up(x), free_up(y);
	return make_node(child[0],child[1],lev);
}

int make_or(int ind, int val, int lev = 20) {
	if (!ind) return ind;
	Node& n = trie[ind];
	if (!(n.branch&val)) {
		n.lazy_xor &= BIG-val;
		n.lazy_or |= val;
		return ind;
	}
	assert(lev); prop(ind,lev);
	AR<int,2> child;
	id3(i,2) child[i] = make_or(n.c[i],val,lev-1);
	if (val&(1<<(lev-1))) {
		child[1] = merge(child[0],child[1],lev-1);
		child[0] = 0;
	}
	free_up(ind);
	return make_node(child[0],child[1],lev);
}

pi split(int ind, int hi, int lev = 20, int l = 0) {
	if (ind == 0) return {0,0};
	assert(trie[ind].depth == lev);
	int r = l+(1<<lev)-1;
	if (r <= hi) return {ind,0};
	if (hi < l) return {0,ind};
	assert(lev); prop(ind,lev);
	Node& n = trie[ind];
	pi res;
	int m = (l+r)/2;
	if (hi <= m) {
		pi p = split(n.c[0],hi,lev-1,l);
		res = {make_node(p.f,0,lev),make_node(p.s,n.c[1],lev)};
	} else {
		pi p = split(n.c[1],hi,lev-1,m+1);
		res = {make_node(n.c[0],p.f,lev),make_node(0,p.s,lev)};
	}
	free_up(ind);
	return res;
}

AR<int,3> rope(int root, int l, int r) {
	pi a = split(root,r);
	pi b = split(a.f,l-1);
	return {b.f,b.s,a.s};
}

int make_single(int x, int lev = 20) {
	if (lev == 0) return make_node(0,0,lev);
	int cur = make_single(x,lev-1);
	if (x&(1<<(lev-1))) return make_node(0,cur,lev);
	return make_node(cur,0,lev);
}

int main() {
	setIO(); re(N,Q);
	FOR(i,1,STORAGE) avail.pb(i);
	int root = 0;
	id3(i,N) {
		ints(a);
		int cur = make_single(a);
		

		root = merge(root,cur);
		

		assert(trie[root].depth == 20);
	}
	

	rep(Q) {
		ints(t,l,r);
		AR<int,3> a = rope(root,l,r);
		if (t <= 3) {
			ints(x);
			if (t == 1) {
				a[1] = make_or(a[1],BIG-x);
				id6(a[1],BIG-x);
			} else if (t == 2) {
				a[1] = make_or(a[1],x);
			} else if (t == 3) {
				id6(a[1],x);
			}
		} else {
			ps(trie[a[1]].sum);
		}
		root = merge(merge(a[0],a[1]),a[2]);
		assert(trie[root].depth == 20);
	}
}


