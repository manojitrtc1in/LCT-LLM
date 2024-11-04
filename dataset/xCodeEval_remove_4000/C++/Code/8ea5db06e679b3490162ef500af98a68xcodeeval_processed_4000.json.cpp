
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 























const int MOD = 1e9+7; 

const ll INF = 1e18; 
const int SZ = 1<<17;
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } 

int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } 

int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); 

	while (lo < hi) { 

		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}



template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }




str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
	str res = "{"; id2(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; id2(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { 

	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }



template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } 

template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }



void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }









void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void id3() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	id3();
	

	

	

	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

}



struct mi {
	typedef decay<decltype(MOD)>::type T; 
 	

	T v; explicit operator T() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend str ts(mi a) { return ts(a.v); }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) id2(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



typedef array<mi,2> T; 

uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);
const T base = {BDIST(rng),BDIST(rng)};
T operator+(T l, T r) { 
	T x; id2(i,2) x[i] = l[i]+r[i];
	return x; }
T operator*(T l, T r) { 
	T x; id2(i,2) x[i] = l[i]*r[i];
	return x; }
vector<T> pows = {{1,1}};



struct tnode {
	int pri, val; int c[2]; 

	int sz; T hsh;
};

tnode treap[9000000];

int tot;

int makeNew(int _val) {
	int co = ++tot;
	treap[co].pri = rand()+(rand()<<15); 
	treap[co].val = _val;
	treap[co].hsh = {abs(_val),abs(_val)};
	treap[co].sz = 1; 
	treap[co].c[0] = treap[co].c[1] = NULL;
	return co;
}

int copy(int p) {
	int co = ++tot;
	treap[co] = treap[p];
	return co;
}

int getsz(int x) { return x?treap[x].sz:0; }
T id1(int x) { return x?treap[x].hsh:T{0,0}; }
int calc(int x) {
	treap[x].sz = 1+getsz(treap[x].c[0])+getsz(treap[x].c[1]);
	if (treap[x].val > 0) {
		treap[x].hsh = id1(treap[x].c[0])+pows[getsz(treap[x].c[0])]*(T{treap[x].val,treap[x].val}+base*id1(treap[x].c[1]));
	} else {
		treap[x].hsh = id1(treap[x].c[1])+pows[getsz(treap[x].c[1])]*(T{-treap[x].val,-treap[x].val}+base*id1(treap[x].c[0]));
	}
	return x;
}

pair<int,int> id0(int t, int sz) { 

	if (!t) return {t,t};
	int tt = copy(t);
	if (getsz(treap[t].c[0]) >= sz) {
		auto p = id0(treap[t].c[0],sz); treap[tt].c[0] = p.s;
		return {p.f,calc(tt)};
	} else {
		auto p=id0(treap[t].c[1],sz-getsz(treap[t].c[0])-1); treap[tt].c[1]=p.f;
		return {calc(tt),p.s};
	}
}
int merge(int l, int r) {
	if (!l || !r) return l?:r;
	int t;
	if (treap[l].pri > treap[r].pri) {
		t = copy(l); 
		treap[t].c[1] = merge(treap[l].c[1],r);
	} else {
		t = copy(r);
		treap[t].c[0] = merge(l,treap[r].c[0]);
	}
	return calc(t);
}

int n,k;
vi s;

struct node {
	bool bad = 0; int lef = NULL, rig = NULL;
	node() {}
	node(int x) {
		if (x > 0) rig = makeNew(x);
		else lef = makeNew(x);
	}
};

str ts(node n) { return ts(vi{n.bad,getsz(n.lef),getsz(n.rig)})+ts(id1(n.lef))+ts(id1(n.rig)); }

bool flag = 0;

node operator+(node l, node r) {
	node res; if (l.bad || r.bad) { res.bad = 1; return res; }
	res.lef = l.lef, res.rig = r.rig;
	int dif = getsz(l.rig)-getsz(r.lef);
	if (flag) dbg(l,r,dif);
	if (dif >= 0) {
		auto a = id0(l.rig,dif);
		

		if (id1(a.s) != id1(r.lef)) { res.bad = 1; return res; }
		res.rig = merge(a.f,res.rig);
		

	} else {
		auto b = id0(r.lef,getsz(l.rig));
		if (id1(l.rig) != id1(b.f)) { res.bad = 1; return res; }
		res.lef = merge(res.lef,b.s);
	}
	if (flag) dbg(res);
	return res;
}

node seg[2*SZ];

void init() {
	tot = 0;
	id2(i,n) seg[i+SZ] = node(s[i]);
	ROF(i,1,SZ) seg[i] = seg[2*i]+seg[2*i+1];
}

int main() {
	setIO(); re(n,k); s.rsz(n); re(s);
	id2(i,n) pows.pb(pows.bk*base);
	init();
	

	int q; re(q);
	flag = 1;
	id2(i,q) {
		int t,l,r; re(t,l,r);
		if (t == 1) {
			s[--l] = r; int p = l+SZ;
			seg[p] = node(s[l]);
			for (p /= 2; p; p /= 2) {
				seg[p] = seg[2*p]+seg[2*p+1];
			}
		} else {
			dbg("QUERY");
			l += SZ-1, r += SZ;
			node ln, rn;
			for (;l<r;l/=2,r/=2) {
				

				if (l&1) {
					dbg("LEF",l,seg[l]);
					ln = ln+seg[l++];
				}
				if (r&1) {
					dbg("RIG",r-1,seg[r-1]);
					rn = seg[--r]+rn;
				}
			}
			node res = ln+rn;
			dbg(res.bad,getsz(res.lef),getsz(res.rig));
			if (!res.bad && !res.lef && !res.rig) ps("Yes");
			else ps("No");
		}
		if (tot > 0.9*9000000) init();
	}
	

}



