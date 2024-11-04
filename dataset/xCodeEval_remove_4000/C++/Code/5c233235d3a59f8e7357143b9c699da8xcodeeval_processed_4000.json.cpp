
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























const int MOD = 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } 

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 

ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }



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
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	
		return b ? "true" : "false"; 
	
		return ts((int)b);
	
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; id0(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; id0(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { 

	
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	
}
template<class A, class B> str ts(pair<A,B> p) {
	
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	
		return ts(p.f)+" "+ts(p.s);
	
}



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


	
	
		 << __FUNCTION__  << ") -> CHK FAILED: (" << 

	
	




void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void id1() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(str s = "") {
	id1();
	

	

	

	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

}



template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } 

	int v; explicit operator int() const { return v; } 

	mint() { v = 0; }
	mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
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
		v = (ll)v*m.v%MOD; return *this; }
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
	FOR(i,1,SZ) id0(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



struct LCA {
	int N; 
	vector<vi> par, adj; vi depth;
	vi LEF, RIG;
	vector<vl> lef, rig;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) d ++;
		par.assign(d,vi(N)); adj.rsz(N); depth.rsz(N);
	}
	void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void gen(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		FOR(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		trav(y,adj[x]) if (y != par[0][x]) 
			depth[y] = depth[par[0][y] = x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		id0(i,sz(par)) if ((d>>i)&1) x = par[i][x];
		return x; }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		id2(i,sz(par)) {
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) { 

		return depth[x]+depth[y]-2*depth[lca(x,y)]; }
};

LCA LC;

typedef pi T;

const int SZ = 1<<19;
struct LazySeg { 
	const T ID = {MOD,0}; 
	T comb(T l, T r) { return l.f != r.f ? min(l,r) : T{l.f,l.s+r.s}; }
	T seg[2*SZ]; int lazy[2*SZ]; 
	LazySeg() { 
		id0(i,2*SZ) lazy[i] = 0; 
		id0(i,SZ) seg[SZ+i] = {0,1};
		ROF(i,1,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
	}
	void push(int ind, int L, int R) { 

		if (L != R) id0(i,2) lazy[2*ind+i] += lazy[ind]; 

		seg[ind].f += lazy[ind]; 

		lazy[ind] = 0; 
	} 

	void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,int inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	pi query(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return {MOD,0};
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2;
		return comb(query(lo,hi,2*ind,L,M),query(lo,hi,2*ind+1,M+1,R));
	}
};

int n;
vi p;
vector<vi> child;
vi ind;
vpi inter, range;
vi typ;
vi loc;

pi operator+(pi a, pi b) { return {min(a.f,b.f),max(a.s,b.s)}; }
int len(pi p) { return p.s-p.f; }
bool adj(int _a, int _b) {
	pi a = range[_a], b = range[_b];
	return a.s+1 == b.f || b.s+1 == a.f; 
}

int N = 0;
vector<bool> isLeft, isRight;
vl totAns, lefAns, rigAns;

void dfsAns(int x) {
	totAns[x] = 1;
	ll sum = 0;
	trav(t,child[x]) {
		dfsAns(t); 
		rigAns[t] = sum; sum += totAns[t];
		

	}
	totAns[x] += sum;
	sum = 0;
	id2(i,sz(child[x])) {
		int t = child[x][i];
		lefAns[t] = sum; sum += totAns[t];
	}
	if (typ[x]) totAns[x] += (ll)(sz(child[x])-2)*(sz(child[x])+1)/2;
}

void solve() {
	dbg(p);
	

	LazySeg L;
	vi mn{-1}, mx{-1};
	vi st;
	id0(i,n) {
		if (i) L.upd(0,i-1,-1);
		dbg("ADDING",i);
		{
			while (mn.bk != -1 && p[mn.bk] > p[i]) {
				int t = mn.bk; mn.pop_back();
				L.upd(mn.bk+1,t,p[t]);
			}
			L.upd(mn.bk+1,i,-p[i]); mn.pb(i); 
		}
		{
			while (mx.bk != -1 && p[mx.bk] < p[i]) {
				int t = mx.bk; mx.pop_back();
				L.upd(mx.bk+1,t,-p[t]);
			}
			L.upd(mx.bk+1,i,p[i]); mx.pb(i);
		}
		int cur = N++; loc.pb(cur);
		inter.pb({i,i}); range.pb({p[i],p[i]}); typ.pb(0); child.eb();
		while (sz(st)) {
			if (adj(st.bk,cur)) {
				if (sz(child[st.bk]) && adj(child[st.bk].bk,cur)) {
					assert(typ[st.bk]); 

					inter[st.bk] = inter[st.bk]+inter[cur];
					range[st.bk] = range[st.bk]+range[cur];
					child[st.bk].pb(cur);
					cur = st.bk; st.pop_back();
				} else { 

					int CUR = N++;
					inter.pb(inter[cur]+inter[st.bk]);
					range.pb(range[cur]+range[st.bk]);
					typ.pb(range[st.bk] < range[cur] ? 1 : 2);
					child.pb({st.bk,cur});
					cur = CUR; st.pop_back();
				}
				continue;
			}
			if (L.query(0,inter[cur].f-1).f != 0) break;
			int CUR = N++;
			inter.pb(inter[cur]); range.pb(range[cur]); typ.pb(0); child.pb({cur});
			do {
				assert(sz(st));
				inter[CUR] = inter[CUR]+inter[st.bk];
				range[CUR] = range[CUR]+range[st.bk];
				child[CUR].pb(st.bk); st.pop_back();
			} while (len(inter.bk) != len(range.bk));
			reverse(all(child[CUR])); cur = CUR;
		}
		

		st.pb(cur);
	}
	dbg(st);
	assert(sz(st) == 1);
	int root = st.bk;
	dbg(root);
	LC.init(N);
	id0(i,N) trav(t,child[i]) LC.ae(i,t);
	id0(i,N) dbg(i,typ[i],inter[i],range[i],child[i]);
	LC.gen(root);
	ind = vi(N,-1);
	totAns.rsz(N), lefAns.rsz(N), rigAns.rsz(N);
	isLeft = isRight = vector<bool>(N);
	id0(i,N) {
		if (typ[i] == 1) {
			FOR(j,1,sz(child[i])) assert(range[child[i][j-1]].s+1 == range[child[i][j]].f);
		} else if (typ[i] == 2) {
			FOR(j,1,sz(child[i])) assert(range[child[i][j-1]].f-1 == range[child[i][j]].s);
		}
		id0(j,sz(child[i])) ind[child[i][j]] = j;
		if (sz(child[i])) {
			isLeft[child[i][0]] = 1;
			isRight[child[i].bk] = 1;
		}
	}
	dfsAns(root);
}

ll c2(ll x) { return x*(x-1)/2; }

int main() {
	setIO();
	re(n); p.rsz(n); re(p);
	solve();
	int q; re(q);
	id0(i,N) dbg(i,inter[i],typ[i]);
	id0(i,q) {
		int l,r; re(l,r); l--,r--;
		if (l == r) {
			ps(1);
			continue;
		}
		l = loc[l], r = loc[r];
		int x = LC.lca(l,r);
		while (isLeft[l] && l != x) l = LC.par[0][l];
		while (isRight[r] && r != x) r = LC.par[0][r];
		if (l == x && r == x) {
			ps(totAns[x]);
			continue;
		}
		if (l == x) l = child[x][0];
		if (r == x) r = child[x].bk;
		dbg("HAHA",l,r);
		ll ans = 0;
		int lind, rind;
		auto oops = [](ll x) {
			return x*(x-1)/2;
		};
		if (LC.par[0][l] == x) {
			lind = ind[l];
		} else {
			ans += totAns[l];
			bool fst = 1;
			while (LC.par[0][l] != x) {
				if (typ[LC.par[0][l]]) {
					if (fst) {
						ans += oops(sz(child[LC.par[0][l]])-ind[l]);
					} else {
						ans += oops(sz(child[LC.par[0][l]])-ind[l]-1);
					}
				}
				fst = 0;
				ans += lefAns[l];
				l = LC.par[0][l];
			}
			lind = ind[l]+1;
		}
		if (LC.par[0][r] == x) {
			rind = ind[r];
		} else {
			ans += totAns[r];
			bool fst = 1;
			while (LC.par[0][r] != x) {
				if (typ[LC.par[0][r]]) {
					if (fst) {
						ans += oops(ind[r]+1);
					} else {
						ans += oops(ind[r]);
					}
				}
				fst = 0;
				ans += rigAns[r];
				r = LC.par[0][r];
			}
			rind = ind[r]-1;
		}
		dbg("HUH",lind,rind);
		int num = rind-lind+1; assert(num >= 0);
		if (num) ans += rigAns[child[x][rind]]+totAns[child[x][rind]]-rigAns[child[x][lind]];
		if (typ[x]) ans += (ll)num*(num-1)/2;
		ps(ans);
	}
	

}



