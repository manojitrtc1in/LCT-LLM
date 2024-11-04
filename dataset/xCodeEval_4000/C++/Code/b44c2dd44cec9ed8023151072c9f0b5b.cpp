#include<bits/stdc++.h>
using namespace std;



const int MOD = 998244353;

#pragma region


using ll = long long;
using ld = long double;
using db = long double; 
using str = string; 
 
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

#define tcT template<class T
#define tcTUU tcT, class ...U
#define tcTU tcT, class U

#define eb emplace_back 
#define mp make_pair
#define ts to_string
#define rsz resize 
#define ins insert 
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)(v).size())
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back 
#define lb lower_bound 
#define ub upper_bound 
#define fe first
#define se second
#define bs binary_search
#define bk back()
#define pob pop_back()
#define sor(x) sort(all(x))

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define rep(a) F0R(_,a)

template<typename A, typename B>
pair<A, B>& operator++(pair<A, B>& a){++a.se;++a.fe;return a;}
template<typename A, typename B>
pair<A, B>& operator--(pair<A, B>& a){--a.fe;--a.se;return a;}
template<typename A>
vector<A>& operator++(vector<A>& a){for (auto it = a.begin(); it != a.end(); ++it)	++* it;return a;}
template<typename A>
vector<A>& operator--(vector<A>& a){for (auto it = a.begin(); it != a.end(); ++it)--* it;return a;}



const int di[4]={-1, 0, 1, 0}, dj[4]={0, 1, 0, -1};
const int di8[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dj8[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ld PI = acos((ld)-1);
const ll INF = 1e18;
const double eps=1e-11;


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng);}

using ul = unsigned long long;
ul modMul(ul a, ul b, const ul mod) {ll ret = a*b-mod*(ul)((ld)a*b/mod);return ret+((ret<0)-(ret>=(ll)mod))*mod; }
ul modPow(ul a, ul b, const ul mod) {if (b == 0) return 1;ul res = modPow(a,b/2,mod); res = modMul(res,res,mod);return b&1 ? modMul(res,a,mod) : res;}
bool prime(ul n) { if (n < 2 || n % 6 % 4 != 1) return n-2 < 2;ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},s = __builtin_ctzll(n-1), d = n>>s;trav(a,A) {   ul p = modPow(a,d,n), i = s;while (p != 1 && p != n-1 && a%n && i--) p = modMul(p,p,n);if (p != n-1 && i != s) return 0;}return 1;}
bool pow2(int i){ return i&&(i&-i)==i;}
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } 

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 

ll half(ll x) { return fdiv(x,2); }
bool inc(ll a,ll b,ll c){return a<=b&&b<=c;}
template<class t>
int lwb(const vector<t>&v,const t&a){
	return lower_bound(all(v),a)-v.begin();
}

#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);

tcT> bool chmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 
tcT> bool chmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
void TIME(){
	#ifdef __APPLE__
	    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}

tcT> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void remAll(vector<T>& v, U a){
	v.erase(remove(all(v),a),v.end());
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

template <typename I> struct _reversed_struct { I &v_; explicit _reversed_struct(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
template <typename I> _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }


string ts(char c) { return string(1,c); }
string ts(bool b) { 
    #ifdef __APPLE__
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
tcT> string ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vb v) { 
	string res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
	string res = ""; F0R(i,sz(b)) res += char('0'+b[i]);
	return res; }
tcTU> string ts(pair<T,U> p);
tcT> string ts(T v) { 

	#ifdef __APPLE__
		bool fst = 1; string res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; string res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
	#endif
}
tcTU> string ts(pair<T,U> p) {
	#ifdef __APPLE__
		return "("+ts(p.fe)+", "+ts(p.se)+")"; 
	#else
		return ts(p.fe)+" "+ts(p.se);
	#endif
}




tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT> void rv(int n, vector<T>& x) { x.rsz(n); re(x); }

tcT, size_t SZ> void re(array<T,SZ>& a);
tcT> void re(T& x) { cin >> x; }
void re(double& d) { string t; re(t); d = stod(t); }
void re(ld& d) { string t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.fe,p.se); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(array<T,SZ>& x) { trav(a,x) re(a); }


tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } 

tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }

struct chash { 

    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using mpq = priority_queue<T, vector<T>, greater<T>>;
tcT> using pq = priority_queue<T>;
tcT> using ms = multiset<T>;
tcTU> using um = unordered_map<T,U,chash>;
tcT> using us = unordered_set<T, chash>;
tcT> using PR = pair<T,T>;
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#define MAX(x) memset(x,0x3f,sizeof(x))
#define MIN(x) memset(x,0xc0,sizeof(x))




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
ll lcm(ll a,ll b) {  return (a / gcd(a, b)) * b;}
ll ncr(ll a, ll b){ if(a<b) return 0; ll f = 1; FOR(i,1,b+1){ f*=(a+1-i); f/=i; } return f;}


void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef __APPLE__ 

	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif
 





void setPrec() { cout << fixed << setprecision(15); }
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	unsyncIO(); setPrec();
	

	

	

	if (sz(s)) { setIn(s+".in");setOut(s+".out"); } 

}
#pragma endregion

#pragma region



V<vi> reg(int n,int m){
	V<vi>g(n);
	F0R(i,m){
		int a,b;
		re(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}
V<vpl> rew(int n,int m){
	V<vpl>g(n);
	F0R(i,m){
		ll a,b,w;
		re(a,b,w);
		a--;b--;
		g[a].eb(b,w);
		g[b].eb(a,w);
	}
	return g;
}

template<typename T>
vector<vector<T>> genZ(vector<T>a){
	vector<vector<T>>p;
	sort(a.begin(),a.end());
	do{
		p.push_back(a);
	}
	while(next_permutation(a.begin(),a.end()));
	return p;
}


vs genS(str a){
	vs p;
	sor(a);
	do{
		p.pb(a);
	}while(next_permutation(all(a)));
	return p;
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key 

#define fbo find_by_order 


#pragma endregion










#define ff dbg("RANDOM IM HERE")

const int N = 150005;

ll dp[4][N];
vi adj[4][N];

void solve(int tc){
	MAX(dp);
	V<vl>v(4);
	F0R(i,4){
		int n;
		re(n);
		v[i].rsz(n);
	}
	trav(i,v) re(i);
	

	FOR(i,1,4){
	
		int n;
		re(n);
		rep(n){
			int x,y;
			re(x,y),--x,--y;
			adj[i][y].pb(x);
		}
	}

	
	F0R(i,4){
		bool ok=1;
		ms<ll>dp2;
		
		if(!i) {
			F0R(j,sz(v[i])) dp[i][j]=v[i][j];
		
		}else{
			F0R(j,sz(v[i-1])) dp2.ins(dp[i-1][j]);
			F0R(j,sz(v[i])){
				trav(k,adj[i][j]) dp2.erase(dp2.lb(dp[i-1][k]));
				if(!sz(dp2)) {
					trav(k,adj[i][j]) dp2.ins(dp[i-1][k]);
					continue;
				}else ok=0;
				dp[i][j]=*dp2.begin()+v[i][j];
				trav(k,adj[i][j]) dp2.ins(dp[i-1][k]);
			}
			if(ok){
				ps(-1);
				return;
			}
		
		}
		
	}
	ll ans=INF;
	F0R(i,N) chmin(ans,dp[3][i]);
	ps(ans==INF?-1:ans);
}
int main() {
	setIO(); 
	int T = 1; 

	FOR(_,1,T+1) solve(_);
    
}

