#include <bits/stdc++.h>
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

#define tcT template<class T
#define tcTU tcT, class U


tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;



#define mp make_pair
#define f first
#define s second





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }



#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

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
constexpr int msk2(int x) { return p2(x)-1; }

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




#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }



#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	

	

	

	return ts((int)b);
	

}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(V<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { 

	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
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
#ifdef LOCAL 

	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }


void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s = "") {
	unsyncIO(); setPrec();
	

	

	

	if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

}



using T = db; 

db fdiv(db a, db b) { return a/b; } 




const T inf = LLONG_MAX; bool _Q;
struct Line { 

	mutable T a, b, lst; 

	

	T eval(T x) const { return a*x+b; }
	bool operator<(const Line& y) const { return _Q?lst<y.lst:a<y.a; }
	T bet(const Line& y) const { assert(a <= y.a);
		return a == y.a ? (b >= y.b ? inf : -inf) : fdiv(b-y.b,y.a-a); }
};

struct LC : multiset<Line> {
	bool rem(iterator IT) { auto it = IT++; 

		if (IT == end()) return it->lst = inf, 0;
		return (it->lst = it->bet(*IT)) >= IT->lst; }
	void add(T a, T b) { 

		auto z = insert({a,b,0}), y = z++, x = y; 
		while (rem(y)) erase(z++); 

		if (x != begin() && rem(--x)) erase(y), rem(x); 

		while ((y = x) != begin() && (--x)->lst >= y->lst) 
			erase(y), rem(x); 

	}
	T query(T p) { 
		assert(size()); _Q = 1; 
		T ret = lb({0,0,p})->eval(p); _Q = 0; return ret; }
};

int N;
vpl points;
ll ans;

ll len(pl p) { return p.s-p.f; }

pl operator+(pl a, pl b) { return {min(a.f,b.f),max(a.s,b.s)}; }
pl make(ll x) { return {x,x}; }

void non_intersect() {
	sor(points);
	vpl pre_y(N), suf_y(N);
	pre_y[0] = make(points[0].s);
	FOR(i,1,N) pre_y[i] = pre_y[i-1]+make(points[i].s);
	suf_y[N-1] = make(points[N-1].s);
	R0F(i,N-1) suf_y[i] = suf_y[i+1]+make(points[i].s);
	F0R(i,N-1) {
		ll sum = (points[i].f-points.ft.f)*len(pre_y[i]);
		sum += (points.bk.f-points[i+1].f)*len(suf_y[i+1]);
		ckmin(ans,sum);
	}
	ckmin(ans,(points.bk.f-points.ft.f)*len(pre_y.bk));
}

bool contains(pl a, pl b) { return a.f <= b.f && b.s <= a.s; } 




template<class T> struct RMQ { 

	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vi> jmp;
	int comb(int a, int b) { 

		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { 

		assert(l <= r); int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

void solve_plus() {
	sor(points);
	vl x;
	vpl pref, suf;
	{
		pl cur{INF,-INF};
		int j = 0;
		FOR(i,1,sz(points)) if (points[i].f > points[i-1].f) {
			while (j < i) {
				cur = cur+make(points[j].s);
				++j;
			}
			pref.pb(cur);
			x.pb(points[i].f);
		}
		if (!sz(x)) return;
		pref.pop_back(), x.pop_back();
	}
	{
		pl cur{INF,-INF};
		int j = sz(points)-1;
		R0F(i,sz(points)-1) if (points[i].f < points[i+1].f) {
			while (j > i) {
				cur = cur+make(points[j].s);
				--j;
			}
			suf.pb(cur);
		}
		suf.pop_back();
		reverse(all(suf));
	}
	pl bx{INF,-INF}, by{INF,-INF};
	trav(t,points) {
		bx = bx+make(t.f);
		by = by+make(t.s);
	}
	{
		int j = sz(pref);
		F0R(i,sz(pref)) {
			ckmax(j,i);
			while (j > i && contains(pref[i],suf[j-1])) --j;
			if (j < sz(pref))
				ckmin(ans,(x[j]-x[i])*len(by)+len(pref[i])*len(bx));
		}
	}
	{
		int j_lo = sz(pref), j_hi = sz(pref);
		

		RMQ<ll> RR;
		{
			vl tmp;
			F0R(J,sz(pref)) {
				tmp.pb(x[J]*len(by)-suf[J].f*len(bx));
			}
			RR.init(tmp);
		}
		F0R(i,sz(pref)) {
			ckmax(j_lo,i);
			while (j_lo > i && suf[j_lo-1].s <= pref[i].s) --j_lo;
			while (j_hi > j_lo && suf[j_hi-1].f > pref[i].f) --j_hi;
			if (j_lo >= j_hi) continue;
			ckmin(ans,RR.query(j_lo,j_hi-1)-x[i]*len(by)+pref[i].s*len(bx));
			

			

			

			


			

			

			

			

			

		}
	}
}

void origin() {
	ll lo_x = INF, lo_y = INF;
	trav(t,points) {
		ckmin(lo_x,t.f);
		ckmin(lo_y,t.s);
	}
	trav(t,points) t.f -= lo_x, t.s -= lo_y;
}

void corners() {
	sor(points);
	origin();
	

	ll hi_x = 0, hi_y = 0;
	trav(t,points) ckmax(hi_x,t.f), ckmax(hi_y,t.s);
	vl y(sz(points)); y.bk = INF;
	R0F(i,sz(points)-1) {
		

		y[i] = min(y[i+1],points[i+1].s);
	}
	vpl important;
	vi hi;
	{
		int mx = -1;
		F0R(i,sz(points)-1) {
			if (!sz(important) || points[i].s > important.bk.s) {
				important.pb(points[i]);
				hi.pb(++mx);
			} else {
				hi.pb(mx);
			}
		}
	}
	vpl imp;
	F0R(j,sz(important)-1) imp.pb({important[j].s,hi_x-important[j+1].f});
	

	int lo = 0;
	V<pair<pi,pl>> query;
	F0R(i,sz(points)-1) {
		if (!sz(important) || points[i].s > important.bk.s) {
			important.pb(points[i]);
		}
		while (lo < hi[i] && important[lo].s < y[i]) ++lo;
		if (lo < hi[i]) {
			

			

			

			

			

			query.pb({{lo,hi[i]-1},{points[i].f,hi_y-y[i]}});
			

		}
	}

	for (int i = 0; i < sz(query); ) {
		int I = i; while (i < sz(query) && query[i].f.f <= query[I].f.s) ++i;
		deque<pl> whoops;
		LC tmp;
		ll min_second;
		auto add_les = [&](pl p) {
			ckmin(min_second,p.s);
			tmp.add(-p.s,-p.f);
			whoops.pb(p);
			

		};
		auto add_gre = [&](pl p) {
			ckmin(min_second,p.s);
			tmp.add(-p.s,-p.f);
			whoops.pb(p);
			

		};
		auto query_all = [&](pl p) {
			if (p.f == 0) {
				ckmin(ans,min_second*p.s);
			} else {
				ckmin(ans,-llround(p.f*tmp.query((db)p.s/p.f)));
			}
			

			

		};
		

		

		{
			tmp.clear(); min_second = INF;
			int x = query[i-1].f.f-1;
			ROF(j,I,i) {
				while (query[j].f.f <= x) {
					add_les(imp[x]);
					-- x;
				}
				if (sz(tmp)) query_all(query[j].s);
			}
		}
		{
			tmp.clear(); min_second = INF;
			int x = query[i-1].f.f;
			FOR(j,I,i) {
				while (x <= query[j].f.s) {
					add_gre(imp[x]);
					++ x;
				}
				if (sz(tmp)) query_all(query[j].s);
			}
		}
	}

	

	

	


	

}

void solve() {
	re(N); 
	points.rsz(N); re(points);
	ans = INF;
	non_intersect();
	trav(t,points) swap(t.f,t.s);
	non_intersect();
	dbg(ans);
	solve_plus();
	trav(t,points) t.f *= -1;
	solve_plus();
	dbg(ans);
	corners();
	trav(t,points) t.f *= -1;
	corners();
	dbg(ans);
	ps(ans);
}

int main() {
	setIO();
	int T; re(T);
	F0R(_,T) {
		solve();
	}
	

}


