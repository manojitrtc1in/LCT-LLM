
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
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

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
constexpr int id4(int x) { return p2(x)-1; }

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
	tcT> constexpr bool id7 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id1 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id6 = !id0<T> && id7<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id6<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id6<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id2 = !id1<T> && id7<T>;

	

	tcT> typename enable_if<id1<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id3(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id2<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id7<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id2<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id2<T>,vs>::type 
	  id5(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id2<T>,vs>::type 
	  id5(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id5<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id3(i,sz(res)) {
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
	template<int lev, class T> void id8(const T& t) {
		cerr << "\n\n" << ts_sep(id5<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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



tcT, int SZ> struct LazySeg { 
	static_assert(pct(SZ) == 1); 

	const T ID = -MOD; T cmb(T a, T b) { return max(a,b); }
	T seg[2*SZ], lazy[2*SZ]; 
	

	void push(int ind, int L, int R) { 

		seg[ind] += lazy[ind];
		if (L != R) id3(i,2) lazy[2*ind+i] += lazy[ind]; 

		lazy[ind] = 0; 
	} 

	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build(int ind, int L, int R) {
		seg[ind] = -MOD; lazy[ind] = 0;
		if (L == R) return;
		int M = (L+R)/2;
		build(2*ind,L,M), build(2*ind+1,M+1,R);
	}
	void upd(int lo,int hi,T inc,int ind,int L, int R) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind, int L, int R) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};

LazySeg<int,1<<18> LS;




int movs(vi A, int turn = 0) {
	int N = sz(A); assert(N&1);
	for (int i = 0; ; ++i) {
		if (is_sorted(all(A))) return i;
		

		if ((i+turn)%2 == 0) {
			for (int j = 0; j < N-1; j += 2) if (A[j] > A[j+1]) swap(A[j],A[j+1]);
		} else {
			for (int j = 1; j < N; j += 2) if (A[j] > A[j+1]) swap(A[j],A[j+1]);
		}
	}
}

int dumb(vi zeros) {
	if (!sz(zeros)) return 0;
	int max_pos = 0; each(t,zeros) ckmax(max_pos,t);
	vi init(max_pos+1,1); while (sz(init)%2 == 0) init.pb(1);
	each(t,zeros) init[t] = 0;
	for (int i = 0; ; ++i) {
		vi tmp(sz(init),1); each(t,zeros) tmp[t] = 0;
		

		

		if (zeros.bk == sz(zeros)-1) {
			assert(i == movs(init));
			

			return i;
		}
		

		if (i%2 == 0) {
			id3(j,sz(zeros)) {
				

				if (zeros[j]&1) if (j == 0 || zeros[j] != zeros[j-1]+1) --zeros[j];
			}
			

		} else {
			id3(j,sz(zeros)) if (!(zeros[j]&1)) if (zeros[j]) if (j == 0 || zeros[j] != zeros[j-1]+1) --zeros[j];
		}
		

	}
}

int solve_range(int st, int len, int turn) {
	if (st == 0) return 0;
	int ans = 0;
	if ((st&1) == (turn&1)) {
		++ans; turn ^= 1;
	}
	vi res(21,1);
	id3(i,len) res[st+i] = 0;

	return ans+len-1+st;

	


	

}

int smart(vi zeros) {
	if (!sz(zeros) || zeros.bk == sz(zeros)-1) return 0;
	int ans = -MOD;
	id3(i,sz(zeros)) if (zeros[i] != i) {
		ckmax(ans,zeros[i]+(zeros[i]%2 == 0)-2*i);
	}
	ans += sz(zeros)-1;
	return ans;
}

void solve(int tc) {
	int N; re(N);
	vi A(N); re(A);
	

	vi pos(N,-1);
	id3(i,N) pos[A[i]-1] = i;
	set<int> cur;
	int lo = 0;
	int ans = 0;
	

	

	LS.build(1,0,N-1);
	id3(i,N-1) {
		cur.ins(pos[i]);
		

		while (cur.count(lo)) ++lo;
		LS.upd(pos[i]+1,N-1,-2,1,0,N-1);
		LS.upd(pos[i],pos[i],MOD+pos[i]+(pos[i]%2 == 0),1,0,N-1);
		ckmax(ans,LS.query(lo+1,N-1,1,0,N-1)+i);
	}
	ps(ans);
}

int main() {
	setIO();
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	int TC; re(TC);
	FOR(i,1,TC+1) solve(i);
}


