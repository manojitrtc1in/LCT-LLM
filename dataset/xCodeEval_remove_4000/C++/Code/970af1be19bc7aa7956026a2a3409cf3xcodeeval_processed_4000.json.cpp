
using namespace std;
 
using ll = long long;
using db = long double; 

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



























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id7(int x) { return p2(x)-1; }

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




inline namespace Helpers {
	

	

	

	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool id14 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id0 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id3 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id12 = !id0<T> && id14<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id12<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id12<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id5 = !id3<T> && id14<T>;

	

	tcT> typename enable_if<id3<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id6(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id5<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id14<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id5<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id5<T>,vs>::type 
	  id8(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id5<T>,vs>::type 
	  id8(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id8<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id6(i,sz(res)) {
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
	template<int lev, class T> void id15(const T& t) {
		cerr << "\n\n" << ts_sep(id8<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	
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

	mint() { v = 0; }
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
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
		v = int((ll)v*m.v%MOD); return *this; }
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
	FOR(i,1,SZ) id6(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



template <class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd_pre(int pos, Args... args) {
		++pos;
		assert(pos > 0);
		bit[pos].upd(args...); }
	template<typename... Args> void upd(int pos, Args... args) {
		++pos;
		assert(pos > 0);
		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
	void upd_all() {
		FOR(pos,1,N+1) {
			int npos = pos+(pos&-pos);
			if (npos <= N) bit[npos].val += bit[pos].val;
		}
	}
	template<typename... Args> T sum(int r, Args... args) {
		++r;
		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
		return res; }
	template<typename... Args> T query(int l, int r, Args... 
		args) { return sum(r,args...)-sum(l-1,args...); }
}; 
template<class T, int N> int id2(const BIT<T,N>& bit, T des) { 
	assert(des > 0);
	int ind = 0;
	for (int i = 1<<bits(N); i; i /= 2)
		if (ind+i <= N && bit.bit[ind+i].val < des)
			des -= bit.bit[ind += i].val;
	assert(ind < N); return ind+1;
}







using T = mi;
using Mat = V<V<T>>;

Mat makeMat(int r, int c) { return Mat(r,vector<T>(c)); }
Mat makeId(int n) { 
	Mat m = makeMat(n,n);
	id6(i,n) m[i][i] = 1;
	return m;
}
Mat& operator+=(Mat& a, const Mat& b) {
	assert(sz(a) == sz(b) && sz(a[0]) == sz(b[0]));
	id6(i,sz(a)) id6(j,sz(a[0])) a[i][j] += b[i][j];
	return a;
}
Mat& operator-=(Mat& a, const Mat& b) {
	assert(sz(a) == sz(b) && sz(a[0]) == sz(b[0]));
	id6(i,sz(a)) id6(j,sz(a[0])) a[i][j] -= b[i][j];
	return a;
}
Mat operator*(const Mat& a, const Mat& b) {
	int x = sz(a), y = sz(a[0]), z = sz(b[0]); 
	assert(y == sz(b)); Mat c = makeMat(x,z);
	id6(i,x) id6(j,y) id6(k,z) c[i][k] += a[i][j]*b[j][k];
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


const db EPS = 1e-12;
int getRow(V<V<db>>& m, int R, int i, int nex) {
    pair<db,int> bes = {0,-1}; 

    FOR(j,nex,R) ckmax(bes,{abs(m[j][i]),j}); 
    return bes.f < EPS ? -1 : bes.s; }
int getRow(V<vmi>& m, int R, int i, int nex) {
    FOR(j,nex,R) if (m[j][i] != 0) return j;
    return -1; }
pair<T,int> gauss(Mat& m) {
    if (!sz(m)) return {1,0};
    int R = sz(m), C = sz(m[0]), rank = 0, nex = 0;
    T prod = 1; 

    id6(i,C) {
        int row = getRow(m,R,i,nex);
        if (row == -1) { prod = 0; continue; }
        if (row != nex) prod *= -1, swap(m[row],m[nex]);
        prod *= m[nex][i]; rank ++;
        T x = 1/m[nex][i]; FOR(k,i,C) m[nex][k] *= x;
        id6(j,R) if (j != nex) {
            T v = m[j][i]; if (v == 0) continue;
            FOR(k,i,C) m[j][k] -= v*m[nex][k];
        }
        nex ++;
    }
    return {prod,rank};
}
Mat inv(Mat m) {
    int R = sz(m); assert(R == sz(m[0]));
    Mat x = makeMat(R,2*R);
    id6(i,R) {
        x[i][i+R] = 1;
        id6(j,R) x[i][j] = m[i][j];
    }
    if (gauss(x).s != R) return Mat();
    Mat res = makeMat(R,R);
    id6(i,R) id6(j,R) res[i][j] = x[i][j+R];
    return res;
}

int N;
Mat tran;
mi lambda_pow[300][1005], lambda_pow_neg[300][1005]; 

mi eigen_pref_sum[300][301]; 


Mat coef; 

int dist[300];
BIT<mi,305> bit_neg[300], bit_zero[300]; 

mi bit_zero_sum[300];
vi A;

mi get_ans(int k, int l, int r) {
	

	


	

	

	

	


	int kk = min(k,N);
	mi ans = 0;
	id6(i,N) {
		mi mul = lambda_pow[i][k]*bit_neg[i].sum(kk)-bit_zero[i].sum(kk)+bit_zero_sum[i];
		ans += mul*(eigen_pref_sum[i][r]-eigen_pref_sum[i][l]);
	}
	return ans;
}

void id1() {
	

	

	Mat id13 = makeMat(N,N);
	V<vmi> id11(N);
	id6(i,N) {
		id6(j,1005) {
			lambda_pow[i][j] = pow(mi(i+1),j);
			lambda_pow_neg[i][j] = pow(inv(mi(i+1)),j);
		}
		id11[i].rsz(i+1); id11[i][i] = 1;
		id9(j,i) {
			mi sum = 0;
			FOR(k,j+1,i+1) sum += tran[j][k]*id11[i][k];
			sum /= i-j;
			id11[i][j] = sum;
			

		}
		id11[i].rsz(N);
		id6(j,N) {
			eigen_pref_sum[i][j+1] = eigen_pref_sum[i][j];
			eigen_pref_sum[i][j+1] += id11[i][j];
			id13[j][i] = id11[i][j];
		}
	}
	

	

	

	id13 = inv(id13); 

	

	

	coef = makeMat(N,N);
	id6(chef,N) {
		vmi sum(N);
		id6(i,N) {
			coef[chef][i] = id13[i][chef];
			id6(pos,N) sum[pos] += coef[chef][i]*id11[i][pos];
		}
		id6(i,N) {
			if (i == chef) assert(sum[i] == 1);
			else assert(sum[i] == 0);
		}
		

	}
	

}

void id4() { 

	id9(i,N) { 

		dist[i] = 1000;
		if (A[i] > 0) dist[i] = 0;
		FOR(j,i+1,N) if (tran[i][j] != 0) ckmin(dist[i],dist[j]+1);
	}
	id6(i,N) { 

		bit_neg[i] = bit_zero[i] = BIT<mi,305>(); bit_zero_sum[i] = 0;
		id6(chef,N) {
			if (dist[chef] != 1000) {
				bit_neg[i].upd_pre(dist[chef],A[chef]*coef[chef][i]*lambda_pow_neg[i][dist[chef]]);
				bit_zero[i].upd_pre(dist[chef],A[chef]*coef[chef][i]);
			}
			bit_zero_sum[i] += A[chef]*coef[chef][i];
		}
		bit_neg[i].upd_all();
		bit_zero[i].upd_all();
	}
}

int main() {
	setIO();
	re(N);
	A.rsz(N); re(A);
	tran = makeMat(N,N);
	id6(i,N) {
		tran[i][i] = i+1;
		ints(c);
		vi id10(c); re(id10);
		for (int j: id10) {
			--j;
			tran[i][j] = j+1;
		}
	}
	id1();
	id4();
	ints(Q);
	rep(Q) {
		ints(t);
		if (t == 1) {
			ints(k,l,r);
			ps(get_ans(k,l-1,r));
		} else {
			ints(chef,x); --chef;
			A[chef] += x;
			if (0 < A[chef] && A[chef] <= x) id4(); 

			else {
				id6(i,N) {
					if (dist[chef] != 1000) {
						bit_neg[i].upd(dist[chef],x*coef[chef][i]*lambda_pow_neg[i][dist[chef]]);
						bit_zero[i].upd(dist[chef],x*coef[chef][i]);
					}
					bit_zero_sum[i] += x*coef[chef][i];
				}
			}
		}
	}
	

}


