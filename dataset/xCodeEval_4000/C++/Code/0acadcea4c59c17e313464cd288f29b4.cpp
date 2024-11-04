#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U


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





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }



#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

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
constexpr int msk2(int x) { return p2(x)-1; }

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


#define tcTUU tcT, class ...U

inline namespace Helpers {
	

	

	

	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
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
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	

	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
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
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else 

		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif

	const clock_t beg = clock();
	#define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}



using T = ll; 

const T EPS = 1e-9; 

using P = pair<T,T>; using vP = V<P>; using Line = pair<P,P>;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
T sq(T a) { return a*a; }

bool close(const P& a, const P& b) { 
	return sgn(a.f-b.f) == 0 && sgn(a.s-b.s) == 0; } 
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
T dot(const P& p, const P& a, const P& b) { return dot(a-p,b-p); }
T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
T cross(const P& p, const P& a, const P& b) {
	return cross(a-p,b-p); }
P reflect(const P& p, const Line& l) {
	P a = l.f, d = l.s-l.f;
	return a+conj((p-a)/d)*d; }
P foot(const P& p, const Line& l) {
	return (p+reflect(p,l))/(T)2; }
bool onSeg(const P& p, const Line& l) {
	return sgn(cross(l.f,l.s,p)) == 0 && sgn(dot(p,l.f,l.s)) <= 0; }

























vP strictIsect(const Line& a, const Line& b) {
	T a0 = cross(a.f,a.s,b.f), a1 = cross(a.f,a.s,b.s); 
	T b0 = cross(b.f,b.s,a.f), b1 = cross(b.f,b.s,a.s); 
	if (sgn(a0)*sgn(a1) < 0 && sgn(b0)*sgn(b1) < 0)
		return {P(0,0)};
		

	return {};
}



vP segIsect(const Line& a, const Line& b) { 
	vP v = strictIsect(a,b); if (sz(v)) return v;
	set<P> s;
	#define i(x,y) if (onSeg(x,y)) s.ins(x)
	i(a.f,b); i(a.s,b); i(b.f,a); i(b.s,a);
	return {all(s)};
}

int N,Q;
vb ans;

const Line ZERO{{0,0},{0,0}};

namespace Solver {

V<pair<P,P>> segs;
vP start;

struct cmp {
	bool operator()(int x, int y) const {
		

		

		

		if (segs[x].f.f > segs[y].f.f) return !(*this)(y,x);
		assert(segs[x].s.f >= segs[y].f.f);
		if (segs[x].f.f == segs[y].f.f) return segs[x].f.s < segs[y].f.s;
		

		assert(cross(segs[x].f,segs[y].f,segs[x].s) != 0);
		return cross(segs[x].f,segs[y].f,segs[x].s) < 0;
	};
};

set<int,cmp> cur_segs;

void solve() {
	

	

	


	V<tuple<ll,int,ll,int>> ev;
	vb bad;
	F0R(i,sz(segs)) {
		auto& t = segs[i];
		if (t.f > t.s) swap(t.f,t.s);
		ev.pb({t.f.f,-1,-t.f.s,i});
		ev.pb({t.s.f,1,t.s.s,i});
		P offset = t.s-t.f;
		if (abs(offset.s) <= abs(offset.f)) bad.pb(1);
		else bad.pb(0);
	}
	F0R(i,sz(start)) {
		ev.pb({start[i].f,0,0,i});
	}
	segs.pb({{-3e6,3e6},{3e6,3e6}});
	cur_segs.ins(sz(segs)-1);

	sor(ev);
	vi nex_seg(sz(segs),-1);
	vi nex_point(sz(start),-1);
	F0R(i,sz(segs)) if (segs[i] == ZERO) nex_seg.at(i) = -2;
	for (auto [x, type, _, ind]: ev) {
		

		if (type == -1) {
			segs.at(ind);
			auto it = cur_segs.insert(ind).f;
			if (!bad.at(ind) && segs[ind].f.s > segs[ind].s.s) {
				nex_seg.at(ind) = *next(it);
				

				

				

			}
		} else if (type == 1) {
			auto it = cur_segs.find(ind);
			if (!bad.at(ind) && segs[ind].f.s < segs[ind].s.s) {
				nex_seg.at(ind) = *next(it);
				

			}
			cur_segs.erase(ind);
		} else {
			segs.pb({start.at(ind),start.at(ind)});
			auto it = cur_segs.lb(sz(segs)-1);
			nex_point.at(ind) = *it;
			segs.pop_back();
		}
	}
	

	auto final_seg = [&](auto self, int x) -> int {
		if (nex_seg[x] < 0) return nex_seg[x];
		return nex_seg[x] = self(self,nex_seg[x]);
	};
	cur_segs.clear();
	F0R(i,sz(nex_point)) if (final_seg(final_seg,nex_point[i]) == -2) {
		

		ans[i] = true;
	}
	

}


};

void test_dir(P d, V<pair<P,P>> segs, vP start) {
	

	auto transform = [&](P p) -> P {
		return {dot(d*P{0,1},p),dot(d,p)};
	};
	each(t,segs) t.f = transform(t.f), t.s = transform(t.s);
	each(t,start) t = transform(t);
	Solver::segs = segs;
	Solver::start = start;
	Solver::solve();
}

int main() {
	setIO();
	re(N);
	V<Line> segs;
	vP start;
	segs.rsz(N); re(segs);
	re(Q);
	start.rsz(Q); re(start);
	ans.rsz(Q);
	F0R(i,Q) {
		ans[i] = true;
		each(t,segs) ans[i] = ans[i]&(!sz(segIsect(t,{start[i],P(0,0)})));
	}
	segs.pb(ZERO);
	F0R(i,N) {
		test_dir(P(0,0)-segs[i].f,segs,start);
		test_dir(P(0,0)-segs[i].s,segs,start);
	}
	for (bool t: ans) {
		if (t) ps("YES");
		else ps("NO");
	}
	

}


