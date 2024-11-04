
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
constexpr int id8(int x) { return p2(x)-1; }

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
	tcT> constexpr bool id13 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id4 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id12 = !id3<T> && id13<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id3<T>,void>::type re(T& x) { cin >> x; } 

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
	tcT> constexpr bool id5 = !id4<T> && id13<T>;

	

	tcT> typename enable_if<id4<T>,str>::type ts(T v) {
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
	tcT> typename enable_if<id13<T>,str>::type ts_sep(T v, str sep) {
		

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
	  id10(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id5<T>,vs>::type 
	  id10(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id10<lev-1>(t);
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
	template<int lev, class T> void id14(const T& t) {
		cerr << "\n\n" << ts_sep(id10<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}

using dpl = deque<pl>; 


int N,X; 

V<pair<pl,dpl>> ranges;
int cur_time;

void id7(pair<pl,dpl>& p, ll best_left) {
	ll L = p.f.f;
	if (!sz(p.s) || p.s.ft.s+(p.s.ft.f+cur_time)-L > best_left) 
		p.s.push_front({L-cur_time,best_left});
}

void id0(pair<pl,dpl>& p, ll best_right) {
	ll R = p.f.s;
	if (!sz(p.s) || p.s.bk.s+R-(p.s.bk.f+cur_time) > best_right) 
		p.s.pb({R-cur_time,best_right});
}

void cleanup(pair<pl,dpl>& p) {
	

	ll best_right = INF;
	ll R = p.f.s;
	while (sz(p.s)) {
		ll dif = (p.s.bk.f+cur_time)-R;
		if (dif <= 0) break;
		best_right = p.s.bk.s+dif;
		p.s.pop_back();
	}
	id0(p,best_right);
	

}

map<int,int> start_cnt, end_cnt;

void ban(int L, int R) {
	++start_cnt[L], ++end_cnt[R];
	V<pair<pl,dpl>> nranges;
	each(t,ranges) {
		if (t.f.s <= L || t.f.f >= R) {
			nranges.pb(t);
			continue;
		} 
		cleanup(t);
		if (t.f.f <= L) {
			pair<pl,dpl> nt; nt.f = {t.f.f,L};
			each(u,t.s) {
				if (u.f+cur_time <= L) nt.s.pb(u);
				else {
					id0(nt,u.s+(u.f+cur_time)-L);
					break;
				}
			}	
			nranges.pb(nt);
		}
		if (R <= t.f.s) {
			pair<pl,dpl> nt; nt.f = {R,t.f.s};
			ll id11 = INF;
			each(u,t.s) {
				if (u.f+cur_time < R) {
					id11 = u.s+R-(u.f+cur_time);
				} else nt.s.pb(u);
			}
			id7(nt,id11);
			nranges.pb(nt);
		}
	}
	swap(ranges,nranges);
}

void subtract(map<int,int>& m, int x) {
	--m[x];
	assert(m[x] >= 0);
	if (m[x] == 0) m.erase(x);
}

int id9(int L) {
	auto it = start_cnt.lb(L);
	if (it == end(start_cnt)) return MOD;
	return it->f;
}

int id1(int R) {
	auto it = end_cnt.ub(R);
	if (it == begin(end_cnt)) return -MOD;
	return prev(it)->f;
}

dpl id2(dpl l, dpl r) {
	dbg("MERGE DEQUES",l,r);
	while (sz(l) && sz(r)) {
		assert(l.bk.f < r.ft.f);
		ll dif = r.ft.f-l.bk.f;
		if (l.bk.s >= r.ft.s+dif) {
			l.pop_back();
			continue;
		}
		if (r.ft.s >= l.bk.s+dif) {
			r.pop_front();
			continue;
		}
		break;
	}
	dbg("RESULT",l);
	l.ins(end(l),all(r));
	return l;
}

void revert(int L, int R) {
	subtract(start_cnt,L), subtract(end_cnt,R);
	V<pair<pl,dpl>> nranges;

	int LL = id9(L), RR = id1(R);
	bool flag = 0;
	each(t,ranges) {
		assert(t.f.s <= L || t.f.f >= R);
		if (t.f.s < L || t.f.f > R) {
			nranges.pb(t);
			continue;
		}
		cleanup(t); 

		if (t.f.s == L) {
			t.f.s = LL; nranges.pb(t);
			flag = (LL >= R);
			continue;
		}
		if (t.f.f == R) {
			if (flag) {
				assert(RR <= L);
				assert(nranges.bk.f.s == t.f.s);
				assert(RR == nranges.bk.f.f);
				nranges.bk.s = id2(nranges.bk.s,t.s);
			} else {
				t.f.f = RR;
				nranges.pb(t);
			}
			continue;
		}
		assert(0);
	}
	swap(ranges,nranges);
}

int main() {
	setIO();
	re(N,X);
	ranges.pb({{-MOD,MOD},{{X,0}}}); 


	V<tuple<int,int,int,int>> mod;
	rep(N) {
		ints(TL,TR,L,R);
		--TL, ++TR, --L, ++R;
		

		mod.pb({TL,1,L,R});
		mod.pb({TR,-1,L,R});
	}
	sor(mod);
	each(t,mod) {
		auto [_time, ad, L, R] = t;
		cur_time = _time;
		if (ad == 1) ban(L,R);
		else revert(L,R);
		

	}
	assert(sz(start_cnt) == 0 && sz(end_cnt) == 0);
	assert(sz(ranges) == 1);
	each(t,ranges) cleanup(t);
	ll ans = INF;
	each(t,ranges[0].s) ckmin(ans,t.s);
	ps(ans);
	

	

}


