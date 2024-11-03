
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
constexpr int id12(int x) { return p2(x)-1; }

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
	tcT> constexpr bool id21 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id3 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id7 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id19 = !id3<T> && id21<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id3<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id19<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id19<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id10 = !id7<T> && id21<T>;

	

	tcT> typename enable_if<id7<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id11(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id10<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id21<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id10<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id10<T>,vs>::type 
	  id15(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id10<T>,vs>::type 
	  id15(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id15<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id11(i,sz(res)) {
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
	template<int lev, class T> void id25(const T& t) {
		cerr << "\n\n" << ts_sep(id15<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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
	FOR(i,1,SZ) id11(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
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
	poly res(sz(p)+1); id11(i,sz(p)) res[i+1] = p[i]*invs[i+1];
	return res; 
}

poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); id11(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); id11(i,sz(r)) l[i] -= r[i]; 
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
	id11(i,sz(l)) id11(j,sz(r)) x[i+j] += l[i]*r[j];
	return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> id0(poly a, poly b) { 
	remz(a); remz(b); assert(sz(b));
	T lst = b.bk, B = T(1)/lst; each(t,a) t *= B; 
	each(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; id11(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	each(t,a) t *= lst;
	return {q,a}; 

}
poly operator%(const poly& a, const poly& b) { 
	return id0(a,b).s; }

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
		for(int i = 0; i < n; i += b*2, m *= w) id11(j,b) {
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
	id11(i,n) A[i] *= B[i];
	fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(V<T> x, V<T> y) {
	auto con = [](const V<T>& v) {
		V<M> w(sz(v)); id11(i,sz(v)) w[i] = (int)v[i];
		return w; };
	return mul(con(x),con(y));
} 

tcT> V<T> MUL(const V<T>& A, const V<T>& B) {
	using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
	using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
	using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
	int n = sz(c0); V<T> res(n); m1 r01 = 1/m1(m0::mod); 
	m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
	id11(i,n) { 

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






poly inv(poly A, int n) { 

	poly B{1/A[0]};
	for (int x = 2; x/2 < n; x *= 2)
		B = 2*B-RSZ(conv(RSZ(A,x),conv(B,B)),x);
	return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  

	assert(A[0] == 1); poly B{1};
	for (int x = 2; x/2 < n; x *= 2)
		B = T(1)/T(2)*RSZ(B+conv(RSZ(A,x),inv(B,x)),x);
	return RSZ(B,n);
}


pair<poly,poly> quoRem(const poly& f, const poly& g) {
	if (sz(f) < sz(g)) return {{},f};
	poly q = conv(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	poly r = RSZ(f-conv(q,g),sz(g)-1); return {q,r};
}
poly log(poly A, int n) { assert(A[0] == 1); 

	A.rsz(n); return integ(RSZ(conv(dif(A),inv(A,n-1)),n-1)); }
poly exp(poly A, int n) { assert(A[0] == 0);
	poly B{1}, IB{1};
	for (int x = 1; x < n; x *= 2) {
		IB = 2*IB-RSZ(conv(B,conv(IB,IB)),x); 

		poly Q = dif(RSZ(A,x)); Q += RSZ(conv(IB,dif(B)-conv(B,Q)),2*x-1); 
		

		B = B+RSZ(conv(B,RSZ(A,2*x)-integ(Q)),2*x); 
	} 

	return RSZ(B,n);
}













int N,M;
str S;

bool id16(int l) {
	assert(l < N-1);
	return l >= sz(S) || S.at(l) == '<';
}

bool id17(int l) {
	assert(l < N-1);
	return l >= sz(S) || S.at(l) == '>';
}

mi two_one(int l, int r);


V<vb> id24;
V<vmi> id4;

mi one_two(int l, int r) { 

	assert(l < r);
	if (l+1 == r) {
		return id16(l);
	}
	if (l+2 == r) {
		return id16(l) && id17(l+1);
	}
	if (l >= M) return pow(mi(2),r-l-2);
	if (id24.at(l).at(r)) return id4.at(l).at(r);
	id24.at(l).at(r) = true;
	mi ans = 0;
	if (id16(l)) ans += two_one(l+1,r);
	if (id17(r-1)) ans += one_two(l,r-1);
	return id4.at(l).at(r) = ans;
}

V<vb> id5;
V<vmi> id9;

mi two_one(int l, int r) { 

	assert(l < r);
	if (l+1 == r) {
		return id17(l);
	}
	if (l+2 == r) {
		return id16(l) && id17(l+1);
	}
	if (l >= M) return pow(mi(2),r-l-2);
	if (id5.at(l).at(r)) return id9.at(l).at(r);
	id5.at(l).at(r) = true;
	mi ans = 0;
	if (id16(l)) ans += two_one(l+1,r);
	if (id17(r-1)) ans += one_two(l,r-1);
	return id9.at(l).at(r) = ans;
}

mi ways(int x, int y) {
	assert(x >= 0 && y >= 0);
	return comb(x+y,x);
}

vmi id6;

mi po2(int x) {
	return id6.at(x);
	

	

}

vb id13;
vmi id8;

mi id14(int dif) {
	assert(dif > 0);
	return po2(max(dif - 2,0)) * ifac.at(dif - 1);
}

mi id18(int r) {
	if (r == 0) return 1;
	if (id13.at(r)) return id8.at(r);
	id13.at(r) = true;
	mi ans = 0;
	id11(i,r) { 

		ans += id18(i) * id14(r - i);
			   

	}
	

	id11(i,min(r,M)) { 

		ans += id18(i)
			   * (two_one(i,r) - po2(max(r-i-2,0))) * ifac.at(r-i-1);
	}
	

	

	return id8.at(r) = ans / r;
}

mi star_one(int r) {
	return id18(r) * fac.at(r);
	

	

	

	

	

	

	

	

}

vb id1;
vmi id23;

mi id22(int l) {
	if (l == N-1) return 1;
	if (id1.at(l)) {
		return id23.at(l);
	}
	id1.at(l) = true;
	mi ans = 0;
	assert(l < N-1);
	FOR(i,l+1,N) {
		ans += one_two(l,i) * id22(i) * ifac.at(i-l-1); 

	}
	return id23.at(l) = ans / (N-1-l);
}

mi one_star(int l) {
	int r = N-1;
	assert(r == N-1);
	if (l == r) return 1;
	mi ans = 0;
	FOR(i,l+1,r+1) {
		ans += one_two(l,i) * one_star(i) * ways(i-l-1,r-i);
	}
	return ans;
}

vmi exp_size(vmi v) {
	return exp(v,sz(v));
}

vmi id2(vmi _V, vmi U) {
	return conv(exp_size(integ(U)), integ(conv(_V,exp_size(-integ(U))))+poly{1});
}

mi star_star(int l, int r) {
	mi ans = 0;
	FOR(i,l,r+1) {
		ans += star_one(i) * one_star(i) * ways(i-l,r-i);
	}
	return ans;
}

int main() {
	setIO();
	re(N,M);
	id24.assign(M,vb(N));
	id4.assign(M,vmi(N));
	id5.assign(M,vb(N));
	id9.assign(M,vmi(N));
	id13.rsz(N);
	id8.rsz(N);
	genFac(N+5);
	id11(i,N+5) id6.pb(pow(mi(2),i));
	re(S);
	vmi U; id11(i,N) U.pb(id14(i+1));
	vmi id20;
	{
		vmi X; id11(r,M) X.pb(id18(r));
		

		

		

		vmi _V(N);
		FOR(r,M,N) id11(i,M) {
			_V.at(r-1) += id18(i)
				    * (two_one(i,r) - po2(max(r-i-2,0))) * ifac.at(r-i-1);
		}
		FOR(r,1,M) {
			_V.at(r-1) = r * X.at(r);
			id11(i,r) _V.at(r-1) -= U.at(i) * X.at(r-1-i);
		}
		id20 = id2(_V, U);
	}
	id1 = vb(N);
	id23.rsz(N);
	{
		vmi wut = exp(integ(U), N+1);
		id11(i,N) if (N-1-i >= M) {
			id1.at(N-1-i) = true;
			id23.at(N-1-i) = wut.at(i);
		}
	}
	mi ans = 0;
	id11(i,N) {
		ans += id20.at(i) * fac.at(i) * id22(i) * fac.at(N-1-i) * ways(i,N-1-i);
	}
	ps(ans);
	

	

	



	

}


