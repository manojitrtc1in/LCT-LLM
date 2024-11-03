
































































































































using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;



















tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id11(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } 


tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); 

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
	tcT> constexpr bool id22 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id2 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id6 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id18 = !id2<T> && id22<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id2<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id18<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id18<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id8 = !id6<T> && id22<T>;

	

	tcT> typename enable_if<id6<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id10(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id8<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id22<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id8<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id8<T>,vs>::type 
	  id12(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id8<T>,vs>::type 
	  id12(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id12<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id10(i,sz(res)) {
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
	template<int lev, class T> void id26(const T& t) {
		cerr << "\n\n" << ts_sep(id12<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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

	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
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

using mi = mint<MOD,5>; 

using vmi = V<mi>;
using pmi = pair<mi,mi>;
using vpmi = V<pmi>;

V<vmi> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) id10(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}




using T = mi;
using Mat = V<V<T>>; 


Mat makeMat(int r, int c) { return Mat(r,V<T>(c)); }
Mat makeId(int n) { 
	Mat m = makeMat(n,n);
	id10(i,n) m[i][i] = 1;
	return m;
}
Mat& operator+=(Mat& a, const Mat& b) {
	assert(sz(a) == sz(b) && sz(a[0]) == sz(b[0]));
	id10(i,sz(a)) id10(j,sz(a[0])) a[i][j] += b[i][j];
	return a;
}
Mat& operator-=(Mat& a, const Mat& b) {
	assert(sz(a) == sz(b) && sz(a[0]) == sz(b[0]));
	id10(i,sz(a)) id10(j,sz(a[0])) a[i][j] -= b[i][j];
	return a;
}
Mat operator*(const Mat& a, const Mat& b) {
	int x = sz(a), y = sz(a[0]), z = sz(b[0]); 
	assert(y == sz(b)); Mat c = makeMat(x,z);
	id10(i,x) id10(j,y) id10(k,z) c[i][k] += a[i][j]*b[j][k];
	return c;
}
Mat operator+(Mat a, const Mat& b) { return a += b; }
Mat operator-(Mat a, const Mat& b) { return a -= b; }
Mat& operator*=(Mat& a, const Mat& b) { return a = a*b; }
Mat pow(Mat m, ll p) {
	int n = sz(m); assert(n == sz(m[0]) && p >= 0);
	Mat res = makeId(n);
	for (; p; p /= 2, m *= m) if (p&1) res *= m;
	return res;
}




using T = mi; using poly = V<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly REMZ(poly p) { remz(p); return p; }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { 
	if (x >= 0) p.insert(begin(p),x,0); 
	else assert(sz(p)+x >= 0), p.erase(begin(p),begin(p)-x);
	return p; 
}
poly RSZ(const poly& p, int x) { 
	if (x <= sz(p)) return poly(begin(p),begin(p)+x);
	poly q = p; q.rsz(x); return q;  }
T eval(const poly& p, T x) { 

	T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
	return res; }
poly dif(const poly& p) { 

	poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
	return res; }
poly integ(const poly& p) { 

	static poly invs{0,1};
	for (int i = sz(invs); i <= sz(p); ++i) 
		invs.pb(-MOD/i*invs[MOD%i]);
	poly res(sz(p)+1); id10(i,sz(p)) res[i+1] = p[i]*invs[i+1];
	return res; 
}

poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); id10(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); id10(i,sz(r)) l[i] -= r[i]; 
	return l; }
poly& operator*=(poly& l, const T& r) { each(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { each(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { each(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;	 }
poly operator*(const poly& l, const poly& r) {
	if (!min(sz(l),sz(r))) return {};
	poly x(sz(l)+sz(r)-1); 
	id10(i,sz(l)) id10(j,sz(r)) x[i+j] += l[i]*r[j];
	return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRem(poly a, poly b) { 
	remz(a); remz(b); assert(sz(b));
	T lst = b.bk, B = T(1)/lst; each(t,a) t *= B; 
	each(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; id10(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	each(t,a) t *= lst;
	return {q,a}; 

}
poly operator%(const poly& a, const poly& b) { 
	return quoRem(a,b).s; }

T resultant(poly a, poly b) { 

	

	

	

	

	

	int ad = sz(a)-1, bd = sz(b)-1; 
	if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
	int pw = ad; a = a%b; pw -= (ad = sz(a)-1);
	return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}




tcT> void fft(V<T>& A, bool inv = 0) { 

	int n = sz(A); assert((T::mod-1)%n == 0); V<T> B(n);
	for(int b = n/2; b; b /= 2, swap(A,B)) { 

		T w = pow(T::rt(),(T::mod-1)/n*b), m = 1; 
		for(int i = 0; i < n; i += b*2, m *= w) id10(j,b) {
			T u = A[i+j], v = A[i+j+b]*m;
			B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
		}
	}
	if (inv) { reverse(1+all(A)); 
		T z = T(1)/T(n); each(t,A) t *= z; }
} 

tcT> V<T> mul(V<T> A, V<T> B) {
	if (!min(sz(A),sz(B))) return {};
	int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
	bool eq = A == B; A.rsz(n), fft(A);
	if (eq) B = A; 

	else B.rsz(n), fft(B);
	id10(i,n) A[i] *= B[i];
	fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(V<T> x, V<T> y) {
	auto con = [](const V<T>& v) {
		V<M> w(sz(v)); id10(i,sz(v)) w[i] = (int)v[i];
		return w; };
	return mul(con(x),con(y));
} 

tcT> V<T> MUL(const V<T>& A, const V<T>& B) {
	using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
	using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
	using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
	int n = sz(c0); V<T> res(n); m1 r01 = 1/m1(m0::mod); 
	m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
	id10(i,n) { 

		int a = c0[i].v, b = ((c1[i]-a)*r01).v, 
			c = (((c2[i]-a)*r02-b)*r12).v;
		res[i] = (T(c)*m1::mod+b)*m0::mod+a; 

	}
	return res;
}



bool small(const poly& a, const poly& b) { 

	return min(sz(a),sz(b)) <= 60; }










poly conv(const poly& a, const poly& b) {
	return small(a,b) ? a*b : mul(a,b); } 







void id27(poly& A_inv, poly a, 
		const poly& a_inv) {
	int N = sz(A_inv);
	id10(i,2*N) a[i] *= a_inv[i];
	fft(a,1); id10(i,N) a[i] = 0; 
	

	

	fft(a); id10(i,2*N) a[i] *= a_inv[i];
	fft(a,1); FOR(i,N,2*N) A_inv.pb(-a[i]);
}

void double_inverse(const poly& A, poly& A_inv) { 
	

	

	int N = sz(A_inv);
	poly f = RSZ(A,2*N); fft(f); 

	poly g = RSZ(A_inv,2*N); fft(g);
	id27(A_inv,f,g);
}



poly inv(const poly& A, int id20) { assert(A[0] != 0);
	

	

	

	poly A_inv{1/A[0]};
	while (sz(A_inv) < id20) double_inverse(A,A_inv);
	return RSZ(A_inv,id20);
}



poly log(poly A, int N) { assert(A[0] == 1); 
	

	return integ(RSZ(mul(dif(A),inv(A,N-1)),N-1)); }



poly sqrt(const poly& A, int id20) { assert(A[0] == 1); 
	

	

	

	const T i2 = T(1)/T(2);
	poly id14{1}, id13{1},id3{1};
	auto value_at = [&](int i) -> T { return i<sz(A)?A[i]:0; };
	for (int N = 1; N < id20; N *= 2) {
		id10(i,N) id3[i] *= id3[i]; 

		fft(id3,1); poly delta(2*N); 

		id10(i,N) delta[N+i] = id3[i]-value_at(i)-value_at(N+i);
		fft(delta); 
		poly id0 = RSZ(id13,2*N);
		fft(id0); id10(i,2*N) delta[i] *= id0[i];
		fft(delta,1); FOR(i,N,2*N) id14.pb(-i2*delta[i]);
		

		if (2*N >= id20) break;
		id3 = id14; fft(id3);
		id27(id13,id3,id0);
	}
	return RSZ(id14,id20);
}



poly exp(const poly& A, int id20) { assert(A[0] == 0);
	

	

	

	auto value_at = [&](int i) -> T { return i<sz(A)?A[i]:0; };
	auto conv_given = [&](const poly& a, poly b) {
		b.rsz(sz(a)); fft(b); 

		id10(i,sz(b)) b[i] *= a[i];
		fft(b,1); return b; };
	poly A_exp{1}, A_inv{1};
	for (int N = 1; N < id20; N *= 2) { 

		poly a_exp = RSZ(A_exp,2*N); fft(a_exp);
		if (N > 1) {
			poly id21 = RSZ(A_inv,2*N); fft(id21);
			id10(i,2*N) id21[i] *= id21[i]*a_exp[i];
			fft(id21,1);
			FOR(i,N/2,N) A_inv.pb(-id21[i]);
		}
		poly a_inv = RSZ(A_inv,2*N); fft(a_inv);
		poly ln = conv_given(a_inv,dif(A_exp));
		poly id24(2*N); 
		id10(i,2*N) id24[i] = a_inv[i]*a_exp[i];

		poly id5 = RSZ(dif(RSZ(A,N)),2*N); fft(id5);
		id10(i,2*N) id24[i] *= id5[i];
		fft(id24,1); FOR(i,N,2*N) ln[i] -= id24[i];
		ln.pop_back(); ln = integ(ln);

		poly id15(N); 
		id10(i,N) id15[i] = value_at(i+N)-ln[i+N];
		poly prod = conv_given(a_exp,id15); 

		FOR(i,N,2*N) A_exp.pb(prod[i-N]);
	} 
	return RSZ(A_exp,id20);
}


pair<poly,poly> divi(const poly& f, const poly& g) {
	if (sz(f) < sz(g)) return {{},f};
	poly q = conv(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	poly r = RSZ(f-conv(q,g),sz(g)-1); return {q,r};
}

poly pow(poly a, int expo){
	assert(expo <= 100);
	poly res = {1};
	for(int i = 0; i < expo; i++){
		res*=a;
	}
	return res;
}





void segProd(V<poly>& stor, poly& v, int ind, int l, int r) { 

	if (l == r) { stor[ind] = {-v[l],1}; return; }
	int m = (l+r)/2; segProd(stor,v,2*ind,l,m); segProd(stor,v,2*ind+1,m+1,r);
	stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
}
void evalAll(V<poly>& stor, poly& res, poly v, int ind = 1) {
	v = divi(v,stor[ind]).s;
	if (sz(stor[ind]) == 2) { res.pb(sz(v)?v[0]:0); return; }
	evalAll(stor,res,v,2*ind); evalAll(stor,res,v,2*ind+1);
}
poly multiEval(poly v, poly p) {
	V<poly> stor(4*sz(p)); segProd(stor,p,1,0,sz(p)-1);
	poly res; evalAll(stor,res,v); return res; }

poly combAll(V<poly>& stor, poly& dems, int ind, int l, int r) {
	if (l == r) return {dems[l]};
	int m = (l+r)/2;
	poly a = combAll(stor,dems,2*ind,l,m), b = combAll(stor,dems,2*ind+1,m+1,r);
	return conv(a,stor[2*ind+1])+conv(b,stor[2*ind]);
}
poly interpolate(V<pair<T,T>> v) {
	int n = sz(v); poly x; each(t,v) x.pb(t.f);
	V<poly> stor(4*n); segProd(stor,x,1,0,n-1);
	poly dems; evalAll(stor,dems,dif(stor[1]));
	id10(i,n) dems[i] = v[i].s/dems[i];
	return combAll(stor,dems,1,0,n-1);
}




vmi invs, fac, ifac;
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
	FOR(i,1,SZ) fac[i] = fac[i-1]*i, ifac[i] = ifac[i-1]*invs[i];
}
mi comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return fac[a]*ifac[b]*ifac[a-b]; }

const int mx = 100005;
int n, k;
mi p;
mi a[mx];

Mat dp[mx];
mi quant[mx];

pair<vmi, vmi> id16(vmi& A, vmi& B, int L, int R){
	if(L == R){
		return mp(vmi{B[L]}, vmi{1, -A[L]});
	}
	int M = (L+R)/2;
	pair<vmi, vmi> frac1 = id16(A, B, L, M);
	pair<vmi, vmi> frac2 = id16(A, B, M+1, R);
	return mp(conv(frac1.f, frac2.s)+conv(frac1.s, frac2.f), conv(frac1.s, frac2.s));
}
vmi id25(vmi A, vmi B){
	

	

	

	

	

	

	

	

	


	pair<vmi, vmi> frac_sum = id16(A, B, 0, k);

	vmi id1 = inv(frac_sum.s, k+5);
	vmi id17 = conv(frac_sum.f, id1);
	id17.rsz(k+1);
	return id17;
}



vmi solveNext(vmi A, vmi B){
	

	

	

	

	

	vmi id9 = id25(A, B);

	vmi res;
	for(int i = 0; i <= k; i++){
		res.pb(id9[k-i]*comb(k, i));
	}
	return res;
}

vmi id19(vmi g){
	

	

	

	

	

	vmi A, B;
	for(int i = 0; i <= k; i++){
		A.pb(i);
		B.pb(g[i]);
	}
	return solveNext(A, B);
}

void genQuant(){

	mi second_sum = mi(0);
	for(int i = 0; i <= k+1; i++){
		second_sum+=comb(k+1, i)*pow(mi(-1), i)*pow(p, i);
	}

	vmi id4(k+2, mi(0));
	for(int i = 0; i <= k+1; i++){
		id4[i]+=comb(k+1, i)*pow(mi(-1), i)*pow(p, i);
		if(i-1 >= 0){
			id4[i]+=id4[i-1];
		}
	}

	vmi g(k+1, 0);
	for(int i = 0; i <= k; i++){
		g[i] = id4[k-i]*pow(p, i);
	}

	
	vmi poly_S = id19(g);
	

	vmi x_vals;
	x_vals.pb(0);
	for(int i = 1; i <= n; i++){
		x_vals.pb(a[i]+1);
	}

	

	

	

	

	

	

	

	

	dbg("HI1");
	dbg(sz(poly_S), sz(x_vals));
	clock_t BEG = clock();
	vmi y_vals = multiEval(poly_S, x_vals);
	dbg(db(clock()-BEG)/db(CLOCKS_PER_SEC));
	dbg("HI2");
	


	map<int, mi> id7;

	for(int i = 0; i < sz(x_vals); i++){
		id7[x_vals[i].v] = y_vals[i];
	}


	auto evalS = [&](int s){
		assert(id7.count(s));
		return id7[s];
		

		

		

		

		

	};


	auto evalINF = [&](int s){
		return evalS(s)/second_sum;
	};

	

	

	

	

	

	

	


	

	

	


	for(int i = 1; i <= n; i++){
		quant[i] = evalINF(0)-pow(p, a[i].v+1)*evalINF(a[i].v+1);
		

	}


	

	

	

	

	

	

}

int main() {
	setIO();
	genFac(1000005);

	

	

	

	re(n, k, p);
	for(int i = 1; i <= n; i++){
		re(a[i]);
		

	}

	genQuant();

	for(int i = 1; i <= n; i++){
		dp[i] = makeMat(4, 4);
		dp[i][0][0] = a[i]+1;
		dp[i][0][1] = a[i];
		dp[i][0][2] = quant[i];
		dp[i][0][3] = quant[i];
		dp[i][1][1] = a[i]+1;
		dp[i][1][3] = quant[i];
		dp[i][2][2] = a[i]+1;
		dp[i][2][3] = a[i];
		dp[i][3][3] = a[i]+1;
	}

	Mat id23 = makeMat(4, 4);
	Mat cur_sum = makeMat(4, 4);
	

	for(int l = n; l >= 1; l--){
		id23 = dp[l]*id23+dp[l]; 

		cur_sum+=id23;
	}

	mi ans = cur_sum[0][3];
	ps(ans);


	

}


