

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
mt19937 rng(1);
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
template<int SZ> struct UnweightedMatch {
	int match[SZ], N; vi adj[SZ];
	void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
	queue<int> q;
	int par[SZ], vis[SZ], orig[SZ], aux[SZ];
	void augment(int u, int v) {
		while (1) {
			int pv = par[v], nv = match[pv];
			match[v] = pv; match[pv] = v;
			v = nv; if (u == pv) return;
		}
	}
	int lca(int u, int v) {
		static int t = 0;
		for (++t;;swap(u,v)) {
			if (!u) continue;
			if (aux[u] == t) return u;
			aux[u] = t; u = orig[par[match[u]]];
		}
	}
	void blossom(int u, int v, int a) {
		for (; orig[u] != a; u = par[v]) {
			par[u] = v; v = match[u]; 
			if (vis[v] == 1) vis[v] = 0, q.push(v);
			orig[u] = orig[v] = a;
		}
	}
	bool bfs(int u) { 
		F0R(i,N+1) par[i] = 0, vis[i] = -1, orig[i] = i;
		q = queue<int>(); vis[u] = 0, q.push(u);
		while (sz(q)) {
			int v = q.ft; q.pop();
			each(x,adj[v]) {
				if (vis[x] == -1) {
					vis[x] = 1; par[x] = v;
					if (!match[x]) return augment(u,x),1;
					vis[match[x]] = 0, q.push(match[x]);
				} else if (vis[x] == 0 && orig[v] != orig[x]) {
					int a = lca(orig[v],orig[x]); 
					blossom(x,v,a), blossom(v,x,a); 
				} 
			}
		}
		return 0;
	}
	int calc(int _N) {
		N = _N; F0R(i,N+1) match[i] = aux[i] = 0; 
		int ans = 0; vi V(N); iota(all(V),1); shuffle(all(V),rng);
		each(x,V) if (!match[x]) each(y,adj[x]) if (!match[y]) { 
			match[x] = y, match[y] = x; ++ans; break; }
		FOR(i,1,N+1) if (!match[i] && bfs(i)) ++ans;
		return ans;
	}
};
UnweightedMatch<601> UM;
struct DSU {
	vi e;
	void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { 
		x = get(x), y = get(y); if (x == y) return 0;
		if (x > y) swap(x,y);
		e[x] += e[y]; e[y] = x; 
		return 1;
	}
};
int N;
vi A;
void set_A(int i, int x) {
	assert(x);
	assert(A.at(i) == 0);
	A.at(i) = x;
}
V<V<tuple<int,int,int,int>>> extra_edge;
V<vpi> tree_edges;
void fill_tree(int c0, int p = -1) {
	for (auto [c1,r]: tree_edges.at(c0)) if (c1 != p) {
		fill_tree(c1,c0);
		set_A(r,c1);
	}
}
void fill_extra_edge(int c) {
	auto [c0,c1,l,r] = extra_edge.at(c).at(0);
	fill_tree(c0);
	if (l != -1) set_A(l,c0);
}
void setup() {
	DSU D; D.init(N+1);
	tree_edges.rsz(N+1);
	V<tuple<int,int,int,int>> extra_edges;
	auto AE = [&](int c0, int c1, int l, int r) {
		assert(c0 && c1);
		if (D.unite(c0,c1)) {
			tree_edges.at(c0).pb({c1,r});
			tree_edges.at(c1).pb({c0,l});
		} else {
			extra_edges.pb({c0,c1,l,r});
		}
	};
	auto ae = [&](int c0, int c1, int l, int r) {
		if (c0 == 0) {
			swap(c0,c1);
			swap(l,r);
		}
		if (c0 == 0) return;
		dbg("ae",c0,c1,l,r);
		if (c1 == 0) {
			AE(c0,c0,l,l);
		} else {
			AE(c0,c1,l,r);
		}
	};
	F0R(i,N-1) if (A[i] && A[i] == A[i+1]) {
		AE(A[i],A[i],-1,-1);
	}
	auto get_A = [&](int x) {
		if (0 <= x && x < N) return A.at(x);
		return 0;
	};
	auto odd_seg = [&](int l, int r) {
		ae(get_A(l-1),get_A(r+1),l,r);
	};
	V<tuple<int,int,int,int>> even_seg;
	for (int r = 0; r < N; ++r) {
		if (A[r] == 0) {
			int l = r; while (r+1 < N && A.at(r+1) == 0) ++r;
			if ((r-l)%2 == 0) {
				odd_seg(l,r); 
			} else {
				even_seg.pb({get_A(l-1),get_A(r+1),l,r});
			}
		}
	}
	extra_edge.rsz(N+1);
	each(t,extra_edges) if (!sz(extra_edge.at(D.get(get<0>(t))))) {
		extra_edge.at(D.get(get<0>(t))).pb(t);
	}
	FOR(i,1,N+1) if (D.get(i) == i && sz(extra_edge.at(i))) {
		dbg("EXTRA EDGE",i);
		fill_extra_edge(i);
	}
	map<pi,pi> exist;
	int max_col = 0;
	for (auto [c0,c1,l,r]: even_seg) {
		c0 = D.get(c0), c1 = D.get(c1);
		if (c0 == 0 || c1 == 0) continue;
		if (c0 > c1) {
			swap(c0,c1);
			swap(l,r);
		}
		if (!sz(extra_edge.at(c0)) && !sz(extra_edge.at(c1))) if (c0 != c1) {
			if (!exist.count({c0,c1})) {
				exist[{c0,c1}] = {l,r};
				UM.ae(c0,c1);
				ckmax(max_col,c0);
				ckmax(max_col,c1);
			}
		}
	}
	assert(max_col <= 600);
	UM.calc(max_col);
	vb done(N+1);
	FOR(i,1,max_col+1) {
		dbg(i,UM.match[i]);
		if (i < UM.match[i]) {
			done.at(i) = done.at(UM.match[i]) = 1;
			auto [l,r] = exist.at({i,UM.match[i]});
			if (l > r) swap(l,r);
			assert(l < r);
			fill_tree(A.at(l-1));
			fill_tree(A.at(r+1));
			set_A(l,A.at(l-1));
			set_A(r,A.at(r+1));
		}
	}
	FOR(i,1,N+1) if (D.get(i) == i && !sz(extra_edge.at(i)) && !done.at(i)) {
		fill_tree(i);
	}
}
void greed() {
	vb used(N+1);
	each(t,A) used.at(t) = 1;
	int nex = 1;
	F0R(i,N) if (A[i] == 0) {
		while (used.at(nex)) ++nex;
		used.at(nex) = 1;
		A.at(i) = nex;
		if (i+1 < N && A.at(i+1) == 0) {
			A.at(i+1) = nex;
		}
	}
}
int val(vi v) {
	set<int> pairs;
	F0R(i,N-1) if (v[i] == v[i+1]) pairs.ins(v[i]);
	return sz(pairs);
}
int main() {
	setIO();
	re(N);
	A.rsz(N); re(A);
	setup();
	greed();
	each(t,A) assert(1 <= t && t <= N);
	dbg(A);
	each(t,A) pr(t,' ');
	ps();
}