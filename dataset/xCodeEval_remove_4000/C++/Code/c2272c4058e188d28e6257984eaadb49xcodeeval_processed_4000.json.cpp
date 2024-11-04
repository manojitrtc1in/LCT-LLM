
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 




typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 




















const int MOD = 1e9+7; 

const int MX = 1.5e5+5;
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
int pc(int x) { return __builtin_popcount(x); } 

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); 

		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } 

	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } 

	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		ios_base::sync_with_stdio(0); cin.tie(0); 

		

		

		

		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

	}
}

using namespace io;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 



typedef struct snode* sn;
struct snode { 
	

	sn p, c[2]; 

	bool flip = 0; 

	int id, val, sz; 

	sn extra; 

	int sub, vir = 0; 

	snode(int _id, int v) {
		p = c[0] = c[1] = extra = NULL;
		id = _id, val = v; calc();
	}
	friend int getSz(sn x) { return x?x->sz:0; }
	friend int getSub(sn x) { return x?x->sub:0; }
	void prop() { 

		if (!flip) return;
		swap(c[0],c[1]); F0R(i,2) if (c[i]) c[i]->flip ^= 1;
		flip = 0; 
	}
	ll totVal = 0, virVal = 0;
	void calc() { 

		F0R(i,2) if (c[i]) c[i]->prop();
		sz = 1+getSz(c[0])+getSz(c[1]);
		sub = 1+getSub(c[0])+getSub(c[1])+vir;
		totVal = virVal+(c[0]?c[0]->totVal:0)+(c[1]?c[1]->totVal:0);
		totVal += (ll)(getSz(c[0])+1)*((c[1]?c[1]->sub:0)+vir+1);
	}
	

	int dir() {
		if (!p) return -2;
		F0R(i,2) if (p->c[i] == this) return i;
		return -1; 

		

	}
	

	bool isRoot() { return dir() < 0; } 
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y;
	}
	void rot() { 

		assert(!isRoot()); int x = dir(); sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x^1], x);
		setLink(this, pa, x^1);
		pa->calc(); calc();
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
	}
	

	void access() { 

		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay(); 
			if (pre) v->vir -= pre->sub, v->virVal -= pre->totVal;
			if (v->c[1]) v->vir += v->c[1]->sub, v->virVal += v->c[1]->totVal;
			v->c[1] = pre; v->calc();
			pre = v;
			

		}
		splay(); 

		assert(!c[1]); 

	}
	void makeRoot() { 
		access(); flip ^= 1; prop(); 
		assert(!c[0]);
	}
	

	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access(); if (!x->p) return NULL; 
		

		x->splay(); return x->p?:x;
	}
	friend bool connected(sn x, sn y) { return lca(x,y); } 
	int distRoot() { access(); return getSz(c[0]); } 
	

	sn getRoot() { 

		access(); auto a = this; 
		while (a->c[0]) a = a->c[0], a->prop();
		a->access(); return a;
	}
	sn getPar(int b) { 

		access(); b = getSz(c[0])-b; assert(b >= 0);
		auto a = this;
		while (1) {
			int z = getSz(a->c[0]);
			if (b == z) { a->access(); return a; }
			if (b < z) a = a->c[0];
			else a = a->c[1], b -= z+1;
			a->prop();
		}
	}
	

	void set(int v) { access(); val = v; calc(); } 
	friend void link(sn x, sn y, bool force = 0) { 

		assert(!connected(x,y));
		if (force) y->makeRoot();
		else { y->access(); assert(!y->c[0]); }
		x->access(); setLink(y,x,0); y->calc();
	}
	friend void cut(sn y) { 

		y->access(); assert(y->c[0]);
		y->c[0]->p = NULL; y->c[0] = NULL; y->calc(); 
	}
	friend void cut(sn x, sn y) { 

		x->makeRoot(); y->access(); 
		assert(y->c[0] == x && !x->c[0] && !x->c[1]);
		cut(y); 
	}
};
sn LCT[MX];



void id0(sn a, sn b) { 

	if (connected(a,b)) a->extra = b;
	else link(b,a);
}
void id1(sn a) { 

	auto t = a->getRoot();
	if (t == a) { t->extra = NULL; return; }
	cut(a); assert(t->extra);
	if (!connected(t,t->extra)) 
		link(t->extra,t), t->extra = NULL; 
}
sn getPar(sn a, int b) { 

	int d = a->distRoot(); if (b <= d) return a->getPar(b);
	b -= d+1; auto r = a->getRoot()->extra; assert(r);
	d = r->distRoot()+1; return r->getPar(b%d);
}



template<class T> struct RMQ {
	

	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vi> jmp;
	int comb(int a, int b) { 

		return v[a]==v[b] ? min(a,b) : (v[a]>v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { 

		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

int N, iA[MX];
ll ans[MX];
vi A; 
RMQ<int> R;

sn makeTree(int l, int r) {
	if (l > r) return NULL;
	int i = R.index(l,r);
	auto L = makeTree(l,i-1);
	if (L) link(LCT[i],L);
	auto R = makeTree(i+1,r);
	if (R) link(LCT[i],R);
	return LCT[i];
}

sn cur;

void process(sn x) {
	if (!x) return;
	sn a = x->c[0], b = x->c[1];
	if (a) a->p = NULL;
	if (b) b->p = NULL;
	x->c[0] = x->c[1] = NULL; x->calc();
	process(a);
	

	

	sn ins = cur;
	while (1) {
		int d = (x->val < ins->val);
		if (ins->c[d] == NULL) {
			setLink(ins,x,d);
			break;
		} else ins = ins->c[d];
	}
	x->splay(); cur = x;
	process(b);
}

sn getLeft(sn x) {
	if (!x->c[0]) return x;
	return getLeft(x->c[0]);
}

int main() {
	

	setIO(); 
	re(N); A.rsz(N); re(A);
	F0R(i,N) iA[A[i]] = i;
	F0R(i,N) LCT[i] = new snode(i,A[i]);
	R.init(A);
	makeTree(0,N-1);
	

	

	set<int> vals; F0R(i,N) vals.insert(i);
	ROF(t,1,N+1) {
		int i = iA[t];
		

		LCT[i]->access(); 
		if (LCT[i]->c[0]) {
			cout << "AH " << LCT[i]->val << " " << LCT[i]->c[0]->val << "\n";
			ps("ID",LCT[i]->c[0]->id);
		}
		assert(!LCT[i]->c[0]);
		ans[t] = LCT[i]->totVal;
		auto it = vals.erase(vals.find(i));
		sn l = NULL, r = NULL;
		LCT[i]->access();
		

		if (it != end(vals)) {
			r = LCT[*it];
			r->access(); LCT[i]->access();
			r->splay(); assert(r->p == LCT[i]);
			cut(getLeft(r));
		}
		

		LCT[i]->access();
		

		if (it != begin(vals)) {
			l = LCT[*prev(it)];
			l->access(); LCT[i]->access();
			l->splay(); assert(l->p == LCT[i]);
			cut(getLeft(l));
		}
		

		LCT[i]->access();
		

		if (!l || !r) continue;
		l->access(), r->access();
		assert(!l->c[1] && !r->c[1]);
		if (l->sz > r->sz) swap(l,r);
		cur = r; process(l);
	}
	FOR(i,1,N+1) ps(ans[i]);
	

}

