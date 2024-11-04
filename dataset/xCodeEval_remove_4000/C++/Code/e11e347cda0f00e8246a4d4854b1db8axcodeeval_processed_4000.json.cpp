
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
	tcT> constexpr bool id9 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id8 = !id0<T> && id9<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id8<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id8<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id2 = !id1<T> && id9<T>;

	

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
	tcT> typename enable_if<id9<T>,str>::type ts_sep(T v, str sep) {
		

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
	template<int lev, class T> void id11(const T& t) {
		cerr << "\n\n" << ts_sep(id5<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}




vi cat(str s) {
	int zero = 0;
	vi ans;
	id3(i,sz(s)) {
		if (s[i] == '1') {
			ans.pb(zero);
			zero = 0;
		} else {
			++zero;
		}
	}
	ans.pb(zero);
	return ans;
}

vi rev(vi v) {
	reverse(all(v));
	return v;
}

int N,K;

str id7(vi v) {
	str ans;
	id3(i,sz(v)) {
		if (i) ans += '1';
		rep(v[i]) ans += '0';
	}
	assert(sz(ans) == N);
	return ans;
}

str process_mov(str a, int L, int R) {
	assert(1 <= L && L <= R && R <= N);
	--L;
	int ones = 0;
	FOR(i,L,R) ones += a.at(i) == '1';
	assert(ones == K);
	reverse(begin(a)+L, begin(a)+R);
	return a;
}


pair<vi,vpi> normalize(vi v) {
	vpi ans;
	if (K > sz(v)-1 || K == 0) return {v,ans};
	auto tri_rev = [&](int pos, int val_left) {
		assert(0 <= pos && pos+K < sz(v));
		int before = pos; id3(i,pos) before += v[i];
		int con = K;
		FOR(i,pos,pos+K+1) {
			con += v.at(i);
		}
		assert(0 <= val_left && val_left <= v.at(pos)+v.at(pos+K));
		int val_right = v.at(pos)+v.at(pos+K)-val_left;
		int L = before+1, R = before+con-v.at(pos+K);
		int _val = val_left;

		vi new_v = v;
		reverse(begin(new_v)+pos+1,begin(new_v)+pos+K);
		new_v.at(pos) = val_left, new_v.at(pos+K) = val_right;
		

		while (L <= before+v.at(pos) && _val) {
			++L, --_val;
		}
		while (_val) {
			

			++R, --_val;
		}
		

		

		assert(R <= before+con);
		

		

		assert(process_mov(id7(v),L,R) == id7(new_v));
		v = new_v;
		ans.pb({L,R});
	};
	auto move_left = [&](int ind) {
		tri_rev(ind,v.at(ind)+v.at(ind+K));
	};
	auto move_right = [&](int ind) {
		tri_rev(ind,0);
	};
	if (K == sz(v)-1) {
		move_left(0);
		vi tmp;
		FOR(i,1,sz(v)-1) tmp.pb(v[i]);
		if (rev(tmp) < tmp) move_left(0);
		return {v,ans};
	}
	for (int cur = sz(v); cur-2 > K;--cur) {
		move_left(cur-1-K);
	}
	

	

	

	

	

	

	

	auto id10 = [&]() {
		FOR(i,K+2,sz(v)) assert(v[i] == 0);
		FOR(i,1,K+1) if (v.at(i)) return 0;
		return 1;
	};
	auto id6 = [&]() {
		FOR(i,K+2,sz(v)) assert(v[i] == 0);
		FOR(i,1,K+2) if (v.at(i)) return 0;
		return 1;
	};
	

	

	for (int parity = 0; !id10(); parity ^= 1) {
		

		if (parity == 0) {
			move_left(0);
		} else {
			move_right(1);
		}
	}
	

	if (K&1) {
		

		for (int parity = 1; !id6(); parity ^= 1) {
			if (parity == 0) {
				move_left(0);
			} else {
				move_left(1);
			}
		}
	}
	return {v,ans};
}

void solve(int tc) {
	str _A,_B;
	re(N,K,_A,_B);
	vi a = cat(_A), b = cat(_B);
	pair<vi,vpi> aa = normalize(a);
	pair<vi,vpi> bb = normalize(b);
	assert(sz(aa.s) <= 2*N);
	assert(sz(bb.s) <= 2*N);
	if (aa.f != bb.f) {
		ps(-1);
		return;
	}
	

	

	

	ps(sz(aa.s)+sz(bb.s));
	auto mov = [&](int l, int r) {
		_A = process_mov(_A,l,r);
		

		ps(l,r);
	};
	each(t,aa.s) mov(t.f,t.s);
	

	reverse(all(bb.s));
	each(t,bb.s) mov(t.f,t.s);
	

	assert(_A == _B);
	

	

	

	

	

	

}

int main() {
	setIO();
	int TC; re(TC);
	FOR(i,1,TC+1) solve(i);
}


