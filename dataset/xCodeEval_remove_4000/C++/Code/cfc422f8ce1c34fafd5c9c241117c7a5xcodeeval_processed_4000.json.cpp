





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
 















 





 
const int root = 3, MOD = (119<<23)+1; 





 
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } 

int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } 

int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); 

	while (lo < hi) { 

		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
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
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
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
void id0() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	id0();
	

	

	

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
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
 

 
vi invs, fac, ifac;
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
	FOR(i,1,SZ) {
		fac[i] = (ll)fac[i-1]*i%MOD;
		ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
	}
}
 
ll comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}
 

 
typedef mi T; using poly = vector<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { p.insert(begin(p),x,0); return p; }
poly RSZ(poly p, int x) { p.rsz(x); return p; }
T eval(const poly& p, T x) { 

	T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
	return res; }
poly dif(const poly& p) { 

	poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
	return res; }
poly integ(const poly& p) { 

	poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/T(i+1);
	return res; }
 
poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
	return l; }
poly& operator*=(poly& l, const T& r) { trav(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { trav(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { trav(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;	 }
poly operator*(const poly& l, const poly& r) {
	if (!min(sz(l),sz(r))) return {};
	poly x(sz(l)+sz(r)-1); 
	F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
	return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }
 
pair<poly,poly> quoRem(poly a, poly b) { 
	remz(a); remz(b); assert(sz(b));
	T lst = b.bk, B = T(1)/lst; trav(t,a) t *= B; 
	trav(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	trav(t,a) t *= lst;
	return {q,a}; 

}
poly operator/(const poly& a, const poly& b) { return quoRem(a,b).f; }
poly operator%(const poly& a, const poly& b) { return quoRem(a,b).s; }

poly gcd(poly a, poly b) { return b == poly{} ? a : gcd(b,a%b); }
T resultant(poly a, poly b) { 

	

	

	

	

	

	int ad = sz(a)-1, bd = sz(b)-1; 
	if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
    int pw = ad; a = a%b; pw -= (ad = sz(a)-1);
    return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}
 

 


 
void genRoots(vmi& roots) { 

	int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
	roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r; }
typedef complex<db> cd; typedef vector<cd> vcd;
void genRoots(vcd& roots) { 

	int n = sz(roots); db ang = 2*PI/n;
	

	F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); }
 
int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
template<class T> void fft(vector<T>& a, 
  const vector<T>& rts, bool inv = 0) {
	int n = sz(a);
	for (int i = 1, j = 0; i < n; i++) { 
		int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
		j ^= bit; if (i < j) swap(a[i],a[j]);
	} 

	for (int len = 1; len < n; len *= 2)
		for (int i = 0; i < n; i += 2*len) F0R(j,len) {
			T u = a[i+j], v = a[i+j+len]*rts[n/2/len*j];
			a[i+j] = u+v, a[i+j+len] = u-v;
		}
	if (inv) {
		reverse(1+all(a));
		T i = T(1)/T(n); trav(x,a) x *= i; 
	}
}
template<class T> vector<T> mul(vector<T> a, vector<T> b) {
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s);
	vector<T> roots(n); genRoots(roots);
	a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
	F0R(i,n) a[i] *= b[i];
	fft(a,roots,1); a.rsz(s); return a;
}
 

 




 
bool small(const poly& a, const poly& b) { 

	return (ll)sz(a)*sz(b) <= 5000; } 
vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
vl smart(const vl& a, const vl& b) {
	auto X = mul(vcd(all(a)),vcd(all(b)));
	vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
	return x; }
poly conv(const poly& a, const poly& b) {
	return small(a,b) ? a*b : smart(a,b); } 
 

 


 
poly inv(poly A, int n) { 

	poly B{1/A[0]};
	while (sz(B) < n) { int x = 2*sz(B);
		B = RSZ(2*B-conv(RSZ(A,x),conv(B,B)),x); }
	return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  

	assert(A[0] == 1); poly B{1};
	while (sz(B) < n) { int x = 2*sz(B);
		B = T(1)/T(2)*RSZ(B+mul(RSZ(A,x),inv(B,x)),x); }
	return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { 
	if (sz(f) < sz(g)) return {{},f};
	auto q = mul(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	auto r = RSZ(f-mul(q,g),sz(g)-1); return {q,r};
}
poly log(poly A, int n) { assert(A[0] == 1); 

	return RSZ(integ(conv(dif(A),inv(A,n))),n); }
poly exp(poly A, int n) { 

	assert(A[0] == 0); poly B = {1};
	while (sz(B) < n) { int x = 2*sz(B);
		B = RSZ(B+conv(B,RSZ(A,x)-log(B,x)),x); }
	return RSZ(B,n);
}
 
void segProd(vector<poly>& stor, poly& v, int ind, int l, int r) { 

	if (l == r) { stor[ind] = {-v[l],1}; return; }
	int m = (l+r)/2; segProd(stor,v,2*ind,l,m); segProd(stor,v,2*ind+1,m+1,r);
	stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
}
void evalAll(vector<poly>& stor, poly& res, poly v, int ind = 1) {
	v = divi(v,stor[ind]).s;
	if (sz(stor[ind]) == 2) { res.pb(sz(v)?v[0]:0); return; }
	evalAll(stor,res,v,2*ind); evalAll(stor,res,v,2*ind+1);
}
poly multiEval(poly v, poly p) {
	vector<poly> stor(4*sz(p)); segProd(stor,p,1,0,sz(p)-1);
	poly res; evalAll(stor,res,v); return res; }
 
poly combAll(vector<poly>& stor, poly& dems, int ind, int l, int r) {
	if (l == r) return {dems[l]};
	int m = (l+r)/2;
	poly a = combAll(stor,dems,2*ind,l,m), b = combAll(stor,dems,2*ind+1,m+1,r);
	return conv(a,stor[2*ind+1])+conv(b,stor[2*ind]);
}
poly interpolate(vector<pair<T,T>> v) {
	int n = sz(v); poly x; trav(t,v) x.pb(t.f);
	vector<poly> stor(4*n); segProd(stor,x,1,0,n-1);
	poly dems; evalAll(stor,dems,dif(stor[1]));
	F0R(i,n) dems[i] = v[i].s/dems[i];
	return combAll(stor,dems,1,0,n-1);
}
 
int n;
 
poly py[5005]; 

vector<poly> po(int t) { 

	vector<poly> res(n+1); 

	F0R(i,n+1) res[i] = RSZ(shift(pow(mi(t),i)*py[i]*ifac[i],t),n+1);
	return res;
}
 
poly brute() { 

	py[0] = {1}; 
	FOR(i,1,n+1) py[i] = poly{1,-1}*py[i-1];
	vector<poly> ans(n+1);
	F0R(i,n+1) {
		auto a = po(i); 

		F0R(j,n+1) ans[j] += a[j];
	}
	poly res; F0R(i,n+1) res += ans[i];
	res = RSZ(res*poly{1,-1},n+1);
	return res;
}
 
poly coef1(poly p, int n) {
	p.rsz(n+1); reverse(all(p));
	poly difs; F0R(i,n+1) difs.pb(ifac[i]);
	F0R(i,n+1) p[i] *= ifac[i];
	p = conv(p,difs);
	F0R(i,n+1) p[i] *= fac[i];
	return RSZ(p,n+1);
}
 
poly coef2(poly p, int n) {
	poly q = coef1(p,n);
	F0R(i,n+1) q[i] *= i+1;
	return q;
}
 
poly LN;
 
poly po(poly a, int b) {
	assert(a[0] == 1);
	poly x = log(a,n+5);
	return exp(b*x,n+5);
}
 
poly deriv(poly a, int b) {
	assert(b < 0 && a[0] != 0);
	poly ans;
	F0R(i,sz(a)) ans.pb((i+b)*a[i]);
	return ans;
}
 
clock_t beg = clock();



poly frac1() {
	poly C, D;
	{
		poly ex{0}; FOR(i,1,n+5) ex.pb(i&1?1:-1);
		ex = exp(ex,n+5);
		poly dem = poly{1,1}-ex;
		assert(dem[0] == 0 && dem[1] == 0 && dem[2] != 0);
		dem = poly(2+all(dem));
		dem = inv(dem,n+5);
		C = poly{1,1}*poly{1,1}*dem;
	}
	{
		F0R(i,n+1) D.pb(comb(n,i));
	}
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	poly C2 = deriv(C,-2);
	poly X = conv(C2,D); 

	poly Y = conv(C,D); 

	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	return coef1(X,n+2)+shift(coef2(Y,n+1),1);
}
 


poly frac2() {
	poly C, D; 
	{ 

		poly oops = poly{1}-LN;
		poly dem = poly{1}-poly{1,1}*oops;
		assert(dem[0] == 0 && dem[1] == 0 && dem[2] != 0);
		dem = poly(2+all(dem));
		dem = inv(dem,n+5);
		C = poly{1,1}*dem;
	}
	{
		poly oops = LN; oops.erase(begin(oops));
		D = po(oops,-n);
	}
	poly C2 = deriv(C,-2);
	poly X = conv(C2,D); 

	poly Y = conv(C,D); 

	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	return coef1(X,n+2)+shift(coef2(Y,n+1),1);
}
 

poly smart() {
	LN.pb(0);
	FOR(i,1,n+5) {
		LN.pb(invs[i]);
		if (i%2 == 0) LN.bk *= -1;
	}
	poly res = frac1()-frac2();
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	res /= n;
	poly oops; 

	F0R(i,n+3) {
		oops.pb(comb(n+2,i));
		if (i&1) oops.bk *= -1;
	}
	res = RSZ(conv(res,oops),n+1);
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	return res;
}
 
int main() {
	setIO(); re(n); genFac(n+10);
	vmi res = smart(); 

	dbg(res[5000]);
	FOR(i,1,n+1) {
		res[i] *= fac[n];
		pr(res[i],' ');
	}
	ps();
}