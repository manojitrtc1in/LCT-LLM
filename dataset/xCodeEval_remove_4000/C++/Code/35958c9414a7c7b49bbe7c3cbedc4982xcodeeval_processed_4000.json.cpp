
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










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng(0);
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id5(int x) { return p2(x)-1; }

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
	tcT> constexpr bool id8 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id7 = !id0<T> && id8<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id7<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id7<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id3 = !id1<T> && id8<T>;

	

	tcT> typename enable_if<id1<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id4(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id3<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id8<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id3<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id3<T>,vs>::type 
	  id6(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id3<T>,vs>::type 
	  id6(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id6<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id4(i,sz(res)) {
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
	template<int lev, class T> void id9(const T& t) {
		cerr << "\n\n" << ts_sep(id6<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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



struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { 

		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

vi MAX_D;

vpi edges;
vi cost;

int N,M,K;
struct Gmat { 

	DSU D;
	Gmat() { D.init(N); }
	void ins(int i) { assert(D.unite(edges[i].f,edges[i].s)); }
	bool indep(int i) {
		return !D.sameSet(edges[i].f,edges[i].s);
	}
};

struct Cmat { 

	vi cnt;
	Cmat() { cnt = vi(K); }
	void ins(int i) {
		int a = edges[i].f, b = edges[i].s;
		if (a < K) assert((++cnt.at(a)) <= MAX_D.at(a));
		if (b < K) assert((++cnt.at(b)) <= MAX_D.at(b));
	}
	bool indep(int i) { 
		bool res = 1;
		int a = edges[i].f, b = edges[i].s;
		if (a < K) res &= cnt.at(a) < MAX_D.at(a);
		if (b < K) res &= cnt.at(b) < MAX_D.at(b);
		return res;
	}
};

bool is_special(int x) {
	assert(x < M);
	return edges[x].s < K;
}

































const int FACTOR = 500;

vpi adj[2500];

vi get_path(int cnt, const V<pair<pi,int>>& edges) { 


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	



	vi pre(cnt,-1), dist(cnt,MOD); dist[cnt-2] = 0;
	bool upd = 1;
	while (upd) {
		upd = 0;
		each(t,edges) if (dist[t.f.f] != MOD)
			if (ckmin(dist[t.f.s],dist[t.f.f]+t.s)) 
				pre[t.f.s] = t.f.f, upd = 1;
	}
	assert(dist[cnt-2] >= 0);

	

	if (dist[cnt-1] != MOD) {
		vi path{cnt-1};
		while (path.bk != cnt-2) path.pb(pre[path.bk]);
		reverse(all(path));
		return path;
	}
	return {};

	

	

}

struct MatroidIsect {
	vb iset;
	bool augment() { 

		V<pair<pi,int>> tmp_ed;
		vi id(M+2,-1);
		int cnt = 0;
		vi rid;
		id4(i,M) if (iset[i]) {
			id[i] = cnt++;
			rid.pb(i);
		}
		id[M] = cnt++; rid.pb(M);
		id[M+1] = cnt++; rid.pb(M+1);
		vl to(M), from(M);
		id4(i,M+1) if (i == M || (iset.at(i) && !is_special(i))) {
			Gmat gmat; Cmat cmat;
			id4(j,M) if (iset[j] && j != i) gmat.ins(j), cmat.ins(j);
			id4(j,M) if (!iset[j] && !is_special(j)) {
				if (gmat.indep(j)) {
					

					to[j] |= 1LL<<id[i];
					

				}
				if (cmat.indep(j)) {
					

					from[j] |= 1LL<<(i == M ? id[M+1] : id[i]);
					

					

				}
			}
		}
		

		V<vi> dist(cnt,vi(cnt,MOD));
		id4(i,cnt) dist.at(i).at(i) = 0;
		V<vi> between(cnt,vi(cnt,-1));
		vl lef(cnt,(1LL<<cnt)-1);
		

		id4(i,M) {
			id4(a,cnt) if (to[i]&(1LL<<a)) {
				while (1) {
					ll huh = lef.at(a)&from.at(i); if (huh == 0) break;
					int b = __builtin_ctzll(huh);
					assert(from[i]&(1LL<<b));
					lef.at(a) ^= 1LL<<b;
					dist.at(a).at(b) = cost.at(i);
					between[a][b] = i;
					

				}
				

				

				

				

				

				

			}
		}
		

		V<pair<pi,int>> tmp;
		id4(i,cnt) id4(j,cnt) 
			if (i != j) if (dist[i][j] != MOD) tmp.pb({{i,j},FACTOR*(dist[i][j]-(rid.at(j) == M+1 ? 0 : cost.at(rid.at(j))))+1});
		

		

		

		vi _path = get_path(cnt,tmp); 
		if (!sz(_path)) return 0;
		vi path;
		id4(i,sz(_path)) {
			int a = _path[i]; path.pb(rid.at(a));
			if (i+1 < sz(_path)) {
				int b = _path[i+1];
				path.pb(between.at(a).at(b));
			}
		}
		

		assert(path.ft == M && path.bk == M+1);
		each(t,path) if (t < M) {
			

			iset.at(t) = iset.at(t)^1;
		}
		return 1;
		

		

		

		

		


		

		

		


		

		


		

		

		

		

	}
	int solve(vi included) {
		iset = vb(M);
		Gmat gmat; Cmat cmat;
		each(t,included) {
			gmat.ins(t), cmat.ins(t); iset.at(t) = 1;
		}
		FOR(i,sz(included),N-1) {
			if (!augment()) return MOD;
		}
		int cnt = 0, tot_cost = 0;
		id4(i,M) {
			cnt += iset[i];
			if (iset[i]) tot_cost += cost.at(i);
		}
		assert(cnt == N-1);
		if (cnt == N-1) return tot_cost;
		return MOD;
	}
};

pair<vi,vi> prelim(vi v) {
	Gmat gmat; Cmat cmat;
	each(t,v) {
		if (!gmat.indep(t) || !cmat.indep(t)) return {{},{}};
		gmat.ins(t), cmat.ins(t);
	}
	map<int,int> m; int cnt = 0;
	vi res;
	id4(i,K) {
		int cur = gmat.D.get(i);
		if (!m.count(cur)) m[cur] = cnt++;
		res.pb(m[cur]);
	}
	return {res,cmat.cnt};
}

int main() {
	setIO();
	re(N,K); 

	MAX_D.rsz(K); re(MAX_D);
	V<pair<int,pi>> _edges;
	id4(i,N) {
		FOR(j,i+1,N) {
			ints(w);
			_edges.pb({w,{i,j}});
		}
	}
	sor(_edges);
	DSU DD; DD.init(N);
	each(t,_edges) {
		if (t.s.f < K) {
			edges.pb(t.s);
			cost.pb(t.f);
		} else if (DD.unite(t.s.f,t.s.s)) {
			edges.pb(t.s);
			cost.pb(t.f);
		}
	}
	M = sz(edges);
	vi special;
	id4(i,M) if (is_special(i)) special.pb(i);
	assert(sz(special) == K*(K-1)/2);
	int ans = MOD;
	map<pair<vi,vi>,pi> bes;
	auto id2 = [&](vi v) {
		int sum_cost = 0;
		each(t,v) sum_cost += cost.at(t);
		return sum_cost;
	};
	id4(i,1<<sz(special)) {
		vi init; id4(j,sz(special)) if (i&(1<<j)) init.pb(special[j]);
		auto a = prelim(init); if (!sz(a.f)) continue;
		if (!bes.count(a)) bes[a] = {MOD,MOD};
		ckmin(bes[a],mp(id2(init),i));
	}
	dbg(sz(bes));
	each(t,bes) {
		int i = t.s.s;
		vi init; id4(j,sz(special)) if (i&(1<<j)) init.pb(special[j]);
		MatroidIsect mi;
		ckmin(ans,mi.solve(init));
	}
	ps(ans);
	dbg_time();

}

