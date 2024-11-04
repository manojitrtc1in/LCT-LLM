







using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


















const int MOD = 1000000007; 

const ll INF = 1e18;
const int MX = 100005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { id1(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id1(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 

        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); 

    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); 

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

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } 

    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct frac {
    ll n,d;
    frac() { n = 0, d = 1; }
    frac(ll _n, ll _d) {
        n = _n, d = _d;
        if (d < 0) n *= -1, d *= -1;
    }
    frac(ll _n) : frac(_n,1) {}

    friend frac abs(frac F) { return frac(abs(F.n),F.d); }
	friend ll simp(frac F) { 
		assert(F.n%F.d == 0);
		return F.n/F.d;
	} 
    friend bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
    friend bool operator==(const frac& l, const frac& r) { return l.n*r.d == l.d*r.n; }
    friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }

    friend frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
    friend frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
    friend frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
    friend frac operator*(const frac& l, int r) { return l*frac(r,1); }
    friend frac operator*(int r, const frac& l) { return l*r; }
    friend frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
    friend frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
    friend frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }

    friend frac& operator+=(frac& l, const frac& r) { return l = l+r; }
    friend frac& operator-=(frac& l, const frac& r) { return l = l-r; }
    template<class T> friend frac& operator*=(frac& l, const T& r) { return l = l*r; }
    template<class T> friend frac& operator/=(frac& l, const T& r) { return l = l/r; }

    friend ostream& operator<<(ostream& strm, const frac& a) {
        strm << a.n;
        if (a.d != 1) strm << "/" << a.d;
        return strm;
    }
};

typedef pair<frac,array<int,3>> Z;

int N,M;
int u[MX],v[MX],T[MX],C[MX];
vector<Z> todo[MX];
	
template<int SZ, bool id0> struct HLD { 
    int N; vi adj[SZ];
    int par[SZ], sz[SZ], depth[SZ];
    int root[SZ], pos[SZ];
    


    void addEdge(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
    
    void dfs_sz(int v = 1) {
        if (par[v]) adj[v].erase(find(all(adj[v]),par[v]));
        sz[v] = 1;
        trav(u,adj[v]) {
            par[u] = v; depth[u] = depth[v]+1;
            dfs_sz(u); sz[v] += sz[u];
            if (sz[u] > sz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }
    
    int t = 0;
    void dfs_hld(int v = 1) {
        pos[v] = t++;
        trav(u,adj[v]) {
            root[u] = (u == adj[v][0] ? root[v] : u);
            dfs_hld(u);
        }
    }
    
    void init(int _N) {
        N = _N; par[1] = depth[1] = 0; root[1] = 1; 
        dfs_sz(); dfs_hld();
    }

	int lca(int u, int v) {
        for (; root[u] != root[v]; v = par[root[v]]) 
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
        if (depth[u] > depth[v]) swap(u, v);
		return u;
	}
	
	void add(int loc, frac st, frac en, int ST, int EN, int ind) {
		int sign = EN >= ST ? 1 : -1;
		todo[loc].pb({st,{sign*C[ind],ST,ind}});
		todo[loc].pb({en,{MOD,EN,ind}});
	}
	
    void processPath(int i) {
    	int x = lca(u[i],v[i]);
    	

    	int U = u[i], V = v[i];
    	

    	while (root[U] != root[x]) {
    		frac st = T[i]+frac(depth[u[i]]-depth[U],C[i]);
    		frac en = T[i]+frac(depth[u[i]]-depth[par[root[U]]],C[i]);
    		add(root[U],st,en,pos[U],pos[root[U]]-1,i);
    		U = par[root[U]];
    	}
    	while (root[V] != root[x]) {
    		frac st = T[i]+frac(depth[u[i]]+depth[par[root[V]]]-2*depth[x],C[i]);
    		frac en = T[i]+frac(depth[u[i]]+depth[V]-2*depth[x],C[i]);
    		add(root[V],st,en,pos[root[V]]-1,pos[V],i);
    		V = par[root[V]];
    	}
    	if (depth[U] >= depth[V]) {
    		frac st = T[i]+frac(depth[u[i]]-depth[U],C[i]);
    		frac en = T[i]+frac(depth[u[i]]-depth[x],C[i]);
    		add(root[U],st,en,pos[U],pos[x],i);
    	} else {
    		frac st = T[i]+frac(depth[u[i]]+depth[x]-2*depth[x],C[i]);
    		frac en = T[i]+frac(depth[u[i]]+depth[V]-2*depth[x],C[i]);
    		add(root[V],st,en,pos[x],pos[V],i);
    	}
    }
};

frac ans(MOD);
HLD<MX,0> H;

frac ti = 0;
frac st[MX], en[MX];
int vel[MX], ST[MX];

frac pos(const int& a) {
	return ST[a]+vel[a]*ti-simp(vel[a]*st[a]);
}

struct cmp {
	bool operator()(const int& a, const int& b) {
		

		frac x = pos(a), y = pos(b);
		if (x != y) return x < y;
		return a < b;
	}
};

void upd(int a, int b) {
	if (vel[a] < vel[b]) return;
	ll dis = (ST[b]-ST[a]+simp(vel[a]*st[a])-simp(vel[b]*st[b]));
	if (vel[a] == vel[b]) {
		if (dis != 0) return;
		frac z = max(st[a],st[b]);
		if (z < ans) ans = z;
		return;
	}
	frac z = frac(dis)/(vel[a]-vel[b]);
	if (en[a] < z || en[b] < z) return;
	if (z < ans) ans = z;
	

	

	

	

}

set<int,cmp> cur;
int co = 0;

void solve(vector<pair<frac,array<int,3>>> v) {
	if (!sz(v)) return;
	sort(all(v));
	
	co ++;
	
	

	

	trav(t,v) {
		if (t.s[0] < MOD) {
			vel[t.s[2]] = t.s[0];
			ST[t.s[2]] = t.s[1];
			st[t.s[2]] = t.f;
		} else {
			en[t.s[2]] = t.f;
		}
	}
	cur.clear();
	trav(t,v) {
		if (!(t.f < ans)) return;
		ti = t.f;
		if (t.s[0] < MOD) {
			cur.insert(t.s[2]);
			auto it = cur.find(t.s[2]);
			if (it != cur.begin()) upd(*prev(it),*it);
			if (next(it) != cur.end()) upd(*it,*next(it));
		} else {
			auto it = cur.find(t.s[2]);
			if (it != cur.begin() && next(it) != cur.end()) upd(*prev(it),*next(it));
			cur.erase(it);
		}
	}
	

}

int main() {
    setIO(); re(N,M);
    id1(i,N-1) {
    	int a,b; re(a,b);
    	H.addEdge(a,b);
    }
    H.init(N);
    id1(i,M) {
    	re(T[i],C[i],u[i],v[i]);
    	H.processPath(i);
    }
    

    FOR(i,1,N+1) if (sz(todo[i])) {
    	

    	solve(todo[i]);
    }
    if (ans == MOD) ps(-1);
    else {
    	cout << fixed << setprecision(8);
    	ps((double)ans.n/ans.d);
    }
}

