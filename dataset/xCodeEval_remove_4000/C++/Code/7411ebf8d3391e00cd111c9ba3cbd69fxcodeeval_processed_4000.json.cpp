
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
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










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
	tcT> constexpr bool id9 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id8 = !id1<T> && id9<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

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
	tcT> constexpr bool id3 = !id2<T> && id9<T>;

	

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
	tcT> typename enable_if<id9<T>,str>::type ts_sep(T v, str sep) {
		

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
	template<int lev, class T> void id11(const T& t) {
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
	FOR(i,1,SZ) id4(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

void fassert(bool b) {
	if (!b) {
		ps(0);
		exit(0);
	}
}

using PN = struct Node*;
struct Node {
	set<int> vals;
	int status = 0; 

	V<PN> children;
	int size() { return sz(vals); }
	Node() {}
	Node(int _status, V<PN> _children) {
		status = _status;
		children = _children;
		each(t,children) {
			each(u,t->vals) vals.ins(u);
		}
	}
	Node(int x) {
		vals.ins(x);
	}
	vi isect(vi v) {
		vi w;
		each(t,v) if (vals.count(t)) w.pb(t);
		return w;
	}
};

PN flip(PN cur) {
	assert(cur);
	if (cur->status != 1) return cur;
	return new Node(cur->status,{flip(cur->children[1]),flip(cur->children[0])});
}

PN id7(V<PN> v) {
	if (sz(v) == 0) return nullptr;
	each(t,v) assert(t->status == 0);
	if (sz(v) == 1) {
		return v[0];
	} else {
		return new Node(0,v);
	}
}

PN make_fixed(PN a, PN b) {
	if (!a) return b;
	if (!b) return a;
	return new Node(1,{a,b});
}

PN make_fixed(PN a, PN b, int dir) {
	if (dir == 0) return make_fixed(a,b);
	return make_fixed(b,a);
}

PN add_side(PN cur, vi v, int side);

PN id10(PN cur, vi v, int side) {
	

	v = cur->isect(v);
	if (sz(v) == 0 || sz(v) == cur->size()) return cur;
	assert(cur->status == 1);
	{
		PN a = cur->children[side], b = cur->children[side^1];
		if (sz(b->isect(v)) == 0 || sz(a->isect(v)) == a->size()) return add_side(cur,v,side);
	}
	cur = flip(cur);
	{
		PN a = cur->children[side], b = cur->children[side^1];
		if (sz(b->isect(v)) == 0 || sz(a->isect(v)) == a->size()) return add_side(cur,v,side);
	}
	fassert(0);
	assert(0);
}

PN add_side(PN cur, vi v, int side) {
	v = cur->isect(v);
	

	if (sz(v) == 0 || sz(v) == cur->size()) return cur;
	if (cur->status == 1) {
		PN a = cur->children[side], b = cur->children[side^1];
		if (sz(a->isect(v)) == a->size()) {
			return make_fixed(a,add_side(b,v,side),side);
		} else {
			fassert(sz(b->isect(v)) == 0);
			return make_fixed(add_side(a,v,side),b,side);
		}
	} else {
		assert(cur->status == 0);
		if (sz(cur->children) == 1) {
			assert(cur->children[0]->status == 1);
			PN n = id10(cur->children[0],v,side);
			assert(n->status == 1);
			return n;
		} else {
			V<PN> full, partial, zero;
			each(t,cur->children) {
				if (sz(t->isect(v)) == sz(t->vals)) {
					full.pb(t);
				} else if (sz(t->isect(v))) {
					partial.pb(t);
				} else {
					zero.pb(t);
				}
			}
			fassert(sz(partial) <= 1);
			PN x = id7(full);
			if (sz(partial)) {
				partial[0] = add_side(partial[0],v,side);
				x = make_fixed(x,partial[0],side);
			}
			x = make_fixed(x,id7(zero),side);
			return x;
		}
	}
}

PN add(PN cur, vi v) {
	v = cur->isect(v);
	

	

	


	if (sz(v) == 0 || sz(v) == cur->size()) return cur; 


	V<PN> children = cur->children;
	int imp = 0; each(t,children) if (sz(t->isect(v))) ++imp;
	if (imp == 1) {
		each(t,children) if (sz(t->isect(v))) t = add(t,v);
		return new Node(cur->status,children);
	} 


	assert(sz(children) > 1);
	if (cur->status == 0) { 

		

		V<PN> full, zero, partial;
		each(t,children) {
			assert(t->status != 1);
			int s = sz(t->isect(v));
			if (s == 0) zero.pb(t);
			else if (s == t->size()) full.pb(t);
			else partial.pb(t);
		}
		fassert(sz(partial) <= 2);
		PN mid = id7(full);
		if (sz(partial) >= 1) {
			partial[0] = add_side(partial[0],v,1);
			mid = make_fixed(partial[0],mid);
		}
		if (sz(partial) >= 2) {
			partial[1] = add_side(partial[1],v,0);
			mid = make_fixed(mid,partial[1]);
		}
		assert(mid);
		if (mid->status == 1) mid = new Node(0,{mid});
		zero.pb(mid);
		return id7(zero);
	} else {
		assert(sz(children) == 2);
		return make_fixed(add_side(children[0],v,1),add_side(children[1],v,0));
	}
}

mi id0(PN p) {
	if (sz(p->children) == 0) return 1;
	if (p->status == 1) return id0(p->children.at(0))*id0(p->children.at(1));
	if (sz(p->children) == 1) {
		assert(p->children[0]->status == 1);
		return 2*id0(p->children[0]);
	}
	mi mul = 1; FOR(i,1,sz(p->children)+1) mul *= i;
	each(t,p->children) mul *= id0(t);
	return mul;
}

void print_rec(PN p) {
	ps(p->status,p->vals);
	ps("----");
	each(t,p->children) print_rec(t);
}

PN root = new Node();

int N,M;

int main() {
	setIO(); re(N,M);
	if (N == 1) {
		ps(1);
		exit(0);
	}
	V<PN> children;
	FOR(i,1,N+1) {
		children.pb(new Node(i));
	}
	root = id7(children);
	

	rep(M) {
		ints(q);
		vi v(q); re(v);
		

		root = add(root,v);
		assert(root->size() == N);
		

		

	}
	ps(id0(root));
	

}


