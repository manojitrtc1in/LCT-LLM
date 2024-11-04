
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
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
 





 















 







 
const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 


constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { return 31-__builtin_clz(x); } 

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

 



tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);
 
tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
 
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int& n, vector<T>& x) { re(n); x.rsz(n); trav(a,x) re(a); }
 



str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	
		return b ? "true" : "false"; 
	
		return ts((int)b);
	
}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { 

	
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
tcTU> str ts(pair<T,U> p) {
	
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	
		return ts(p.f)+" "+ts(p.s);
	
}
 


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

	
	

 


void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void id1() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	id1();
	

	

	

	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

}
 

 
using T = ll;
int sgn(T a) { return (a>0)-(a<0); }
T sq(T a) { return a*a; }
 
typedef pair<T,T> P; typedef vector<P> vP;
T norm(const P& p) { return sq(p.f)+sq(p.s); }
T abs(const P& p) { return sqrt(norm(p)); }
T arg(const P& p) { return atan2(p.s,p.f); }
P conj(const P& p) { return P(p.f,-p.s); }
P perp(const P& p) { return P(-p.s,p.f); }
P dir(T ang) { return P(cos(ang),sin(ang)); }
 
P operator-(const P& l) { return P(-l.f,-l.s); }
P operator+(const P& l, const P& r) { 
	return P(l.f+r.f,l.s+r.s); }
P operator-(const P& l, const P& r) { 
	return P(l.f-r.f,l.s-r.s); }
P operator*(const P& l, const T& r) { 
	return P(l.f*r,l.s*r); }
P operator*(const T& l, const P& r) { return r*l; }
P operator/(const P& l, const T& r) { 
	return P(l.f/r,l.s/r); }
P operator*(const P& l, const P& r) { 
	return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
P operator/(const P& l, const P& r) { 
	return l*conj(r)/norm(r); }
P& operator+=(P& l, const P& r) { return l = l+r; }
P& operator-=(P& l, const P& r) { return l = l-r; }
P& operator*=(P& l, const T& r) { return l = l*r; }
P& operator/=(P& l, const T& r) { return l = l/r; }
P& operator*=(P& l, const P& r) { return l = l*r; }
P& operator/=(P& l, const P& r) { return l = l/r; }
 
P unit(const P& p) { return p/abs(p); }
T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
T cross(const P& p, const P& a, const P& b) {
	return cross(a-p,b-p); }
P reflect(const P& p, const P& a, const P& b) { 
	return a+conj((p-a)/(b-a))*(b-a); }
P foot(const P& p, const P& a, const P& b) { 
	return (p+reflect(p,a,b))/(T)2; }
bool onSeg(const P& p, const P& a, const P& b) { 
	return cross(a,b,p) == 0 && dot(p-a,p-b) <= 0; }
 

 
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
 
BIT<int,400005> B;
 
int N;
ll K;
vP v;
db ti = 0, ti2 = 0;
vpi todo[400005];
 
ll id0(db mid) {
	

	V<pair<pair<db,db>,int>> intervals;
	int cnt = 0;
	trav(t,v) {
		

		db frac = mid/sqrt(norm(t));
		if (frac <= 1) {
			frac = acos(frac);
			db ang = atan2(t.s,t.f);
			pair<db,db> interval = {ang-frac,ang+frac};
			

			intervals.pb({interval,cnt});
			interval.f += 2*PI, interval.s += 2*PI;
			

			intervals.pb({interval,cnt});
		}
		cnt ++;
	}
	V<db> compress; compress.reserve(4*N);
	trav(t,intervals) {
		compress.pb(t.f.f);
		compress.pb(t.f.s);
	}
	remDup(compress);
	auto ind = [&](db d) {
		return lb(all(compress),d)-begin(compress)+1;
	};
	F0R(i,400005) todo[i].clear();
	

	trav(t,intervals) todo[ind(t.f.f)].pb({ind(t.f.s),t.s});
		

		

		

	

	

	

	

	

	

	B = BIT<int,400005>();
	vi seen(N);
	ll tot = 0;
	F0R(i,400005) trav(t,todo[i]) {
		

		seen[t.s] ++;
		if (seen[t.s] == 2) {
			

			tot += B.query(i,t.f);
		}
		B.upd(t.f,1);
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	return tot;
}
 
int main() {
	setIO(); re(N,K);
	clock_t beg = clock();
	v.rsz(N); 
	re(v);
	

	

	

	

	

	

	

	

	

	db lo = 0, hi = 3e4;
	F0R(_,50) {
		dbg(_);
		db mid = (lo+hi)/2;
		ll num = id0(mid);
		num = (ll)N*(N-1)/2-num;
		

		

		if (num >= K) hi = mid;
		else lo = mid;
	}
	

	

	cout << fixed << setprecision(9) << lo;
 
	
	

}
 
