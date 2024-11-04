
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































const int MOD = 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; 

const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 



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
	t.erase(u); } 





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
	str res = "{"; id0(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; id0(i,SZ) res += char('0'+b[i]);
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


vector<vmi> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) id0(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}








template<class T> void fft(V<T>& A, bool inv = 0) { 

	int n = sz(A); assert((T::mod-1)%n == 0); V<T> B(n);
	for(int b = n/2; b; b /= 2, swap(A,B)) {
		T w = pow(T::rt(),(T::mod-1)/n*b), m = 1;
		for(int i = 0; i < n; i += b*2, m *= w) id0(j,b) {
			T u = A[i+j], v = A[i+j+b]*m;
			B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
		}
	}
	if (inv) { reverse(1+all(A)); 
		T z = T(1)/T(n); trav(t,A) t *= z; }
}
template<class T> V<T> mul(V<T> A, V<T> B) { 

	if (!min(sz(A),sz(B))) return {};
	int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
	bool eq = A == B; A.rsz(n), fft(A);
	if (eq) B = A; 

	else B.rsz(n), fft(B);
	id0(i,n) A[i] *= B[i];
	fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(V<T> x, V<T> y) {
	auto con = [](const V<T>& v) {
		V<M> w(sz(v)); id0(i,sz(v)) w[i] = (int)v[i];
		return w; };
	return mul(con(x),con(y));
}
template<class T> V<T> MUL(const V<T>& A, const V<T>& B) { 

	using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
	using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
	using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
	int n = sz(c0); V<T> res(n);
	m1 r01 = 1/m1(m0::mod); m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
	id0(i,n) { 

		int a = c0[i].v, b = ((c1[i]-a)*r01).v, c = (((c2[i]-a)*r02-b)*r12).v;
		res[i] = (T(c)*m1::mod+b)*m0::mod+a; 

	}
	return res;
}

int n,k,c;









map<int,int> todo[17];

void fwht(vmi& v) {
	int n = sz(v);
	for (int bit = 1; bit < n; bit *= 2) {
		id0(i,n) if (!(i&bit)) {
			tie(v[i],v[i+bit]) = mp(v[i]+v[i+bit],v[i]-v[i+bit]);
		}
	}
}

vmi tran(int i, int x) {
	assert(x&((1<<i)-1));
	vmi res(1<<i);
	id0(z,k+1) {
		res[x-z] += ifac[z];
	}
	return res;
}


void AD(vmi& a, vmi& b, int c, mi d) {
	id0(i,sz(b)) a[i^c] += b[i]*d;
}

void ad(int i, V<vmi>& a, int b) {
	

	V<vmi> res(k+1,vmi(1<<i));
	R0F(i,k+1) id0(j,k+1-i) AD(res[i+j],a[i],b-j,ifac[j]);
	a = res;
	

}

vmi getAns() {
	V<vmi> res(k+1,{0});
	res[0] = {1}; 
	

	FOR(i,1,c+1) {
		dbg("DOING",i);
		trav(t,res) t.rsz(1<<i);
		

		trav(t,todo[i]) {
			id0(j,t.s) ad(i,res,t.f);
		}
		

	}
	return res[k];
}

int main() {
	genFac(20);
	setIO(); 
	re(n,k,c);
	int xo = 0;
	int cnt = 16;
	id0(_,n) {
	   

		int x; re(x);
		int bits = 0;
		while ((x&((1<<bits)-1)) < k) bits ++;
		int lef = x&((1<<bits)-1);
		xo ^= x^lef;
		todo[bits][lef] ++;
	}
	vmi v = getAns();


	vmi ans(1<<c);
	id0(i,sz(v)) ans[i^xo] = v[i];
	mi sum = 0; trav(t,ans) sum += t;
	trav(t,ans) t /= sum;
	trav(t,ans) pr(t,' ');
	ps();
	

}


