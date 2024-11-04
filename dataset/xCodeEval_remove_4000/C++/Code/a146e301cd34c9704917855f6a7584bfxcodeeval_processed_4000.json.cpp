


 


using namespace std;
 
using ll = long long;
using ld = long double;
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<double,double>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
































const int di[4]={-1, 0, 1, 0}, dj[4]={0, 1, 0, -1};
const int di8[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dj8[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ld PI = acos((ld)-1);
const ll INF = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng);}

bool pow2(int i){ return i&&(i&-i)==i;}
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } 

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 

ll half(ll x) { return fdiv(x,2); }

tcT> bool chmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 
tcT> bool chmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcT> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void remAll(vector<T>& v, U a){
	v.erase(remove(all(v),a),v.end());
}
void HIGH(string &a){
	transform(all(a),a.begin(),::toupper);
}
void LOW(string &a){
	transform(all(a),a.begin(),::tolower);
}

tcTU> T fstTrue(T lo, T hi, U f) {  

	while (lo < hi) {
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) { 

	while (lo < hi) { 
		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}



tcTU3> string ts(tuple<T,U,C> p);
tcTU4> string ts(tuple<T,U,C,D> p);
string ts(char c) { return string(1,c); }
string ts(bool b) { 
    
		return b ? "true" : "false"; 
	
		return ts((int)b);
	
}
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
tcT> string ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vb v) { 
	string res = "{"; id0(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
	string res = ""; id0(i,sz(b)) res += char('0'+b[i]);
	return res; }
tcTU> string ts(pair<T,U> p);
tcT> string ts(T v) { 

	
		bool fst = 1; string res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	
		bool fst = 1; string res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
	
}
tcTU> string ts(pair<T,U> p) {
	
		return "("+ts(p.fe)+", "+ts(p.se)+")"; 
	
		return ts(p.fe)+" "+ts(p.se);
	
}
tcTU3> string ts(tuple<T,U,C> p) { 
	
	    return "("+ts(get<0>(p))+","+ts(get<1>(p))+","+ts(get<2>(p))+")";
	
	    return ts(get<0>(p))+" "+ts(get<1>(p))+" "+ts(get<2>(p));
	
}
tcTU4> string ts(tuple<T,U,C,D> p) {
	
	    return "("+ts(get<0>(p))+","+ts(get<1>(p))+","+ts(get<2>(p))+","+ts(get<3>(p))+")";
	
	    return ts(get<0>(p))+" "+ts(get<1>(p))+" "+ts(get<2>(p))+" "+ts(get<3>(p));
	
}



tcTU3> void re(tuple<T,U,C>& p);
tcTU4> void re(tuple<T,U,C,D>& p);
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);

tcT, size_t SZ> void re(array<T,SZ>& a);
tcT> void re(T& x) { cin >> x; }
void re(double& d) { string t; re(t); d = stod(t); }
void re(ld& d) { string t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.fe,p.se); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(array<T,SZ>& x) { trav(a,x) re(a); }
tcTU3> void re(tuple<T,U,C>& p){re(get<0>(p),get<1>(p),get<2>(p));}
tcTU4> void re(tuple<T,U,C,D>& p){re(get<0>(p),get<1>(p),get<2>(p),get<3>(p));}


tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } 

tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
 


void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }


	
	
		 << __FUNCTION__  << ") -> CHK FAILED: (" << 

	
	


struct chash {
	const uint64_t C = ll(2e18*PI)+71;
	const int RANDOM = rng();
	ll operator()(ll x) const { 
		return __builtin_bswap64((x^RANDOM)*C); }
};
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using mpq = priority_queue<T, vector<T>, greater<T>>;
tcTU> using um = unordered_map<T,U,chash>;
tcT> using us = unordered_set<T, chash>;


const int MOD = 1e9+7; 


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
	friend string ts(mint a) { return ts(a.v); }
   
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
vi invs, fac, ifac; 

void genFac(int SZ) {
	invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
	FOR(i,1,SZ) {
		fac[i] = (ll)fac[i-1]*i%MOD;
		ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
	}
}
mi comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
} 

ll gcd(ll a,ll b) {  return b?gcd(b,a%b):a;}
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void IOS(int n=10, string s=""){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  cout.precision(n); cerr.precision(n); cerr << fixed; cout << fixed;
  if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}






const ll mxN = 1e3;

vl adj[mxN],st,radj[mxN],co,a,c;
bool vis[mxN];

void dfs(int u){
	vis[u]=1;
	trav(v,adj[u]) if(!vis[v]) dfs(v);
	st.pb(u);
}
void dfs1(int u){
	vis[u]=0;
	trav(v,radj[u]) if(vis[v]) dfs1(v);
	co.pb(c[u]);
}

void solve(){
	int n; re(n); a=vl(n); re(a); vpl a1; c =vl(a); sort(rall(a));
	id0(i,n) FOR(j,i+1,n) if(a[j]*3==a[i]){
		int i1 = find(all(c),a[i])-c.begin(), i2 = find(all(c),a[j])-c.begin();
		a1.eb(i1,i2);
	}
	reverse(all(a));
	id0(i,n) FOR(j,i+1,n) if(a[i]*2==a[j]){
		int i1 = find(all(c),a[i])-c.begin(), i2 = find(all(c),a[j])-c.begin();	
		a1.eb(i1,i2);	
	}
	trav(i,a1) adj[i.fe].pb(i.se), radj[i.se].pb(i.fe);
	id0(i,n) if(!vis[i]) dfs(i);
	reverse(all(st));
	id0(i,n){
		if(vis[st[i]]){
			dfs1(st[i]);
			if(sz(co)==n){
				ps(co);
				return;
			}
		}
	}
	ps("IMPOSSIBLE");
}
int main(){
	IOS();
	int t=1; 

	id0(i,t){
        

		solve(); 
	}

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    

}





