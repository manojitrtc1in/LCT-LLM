
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
const uint64_t BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

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
	tcT> constexpr bool id13 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id12 = !id0<T> && id13<T>;
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
	tcT> constexpr bool id3 = !id2<T> && id13<T>;

	

	tcT> typename enable_if<id2<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id6(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id3<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id13<T>,str>::type ts_sep(T v, str sep) {
		

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
	  id9(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id3<T>,vs>::type 
	  id9(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id9<lev-1>(t);
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
		cerr << "\n\n" << ts_sep(id9<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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



template<class C, bool directed> struct Dijkstra {
	int SZ; V<C> dist; 
	V<V<pair<int,C>>> adj;
	void init(int _SZ) { SZ = _SZ; adj.clear(); adj.rsz(SZ); }
	void ae(int u, int v, C cost) {
		adj[u].pb({v,cost}); if (!directed) adj[v].pb({u,cost}); }
	void gen(int st) {
		dist.assign(SZ,numeric_limits<C>::max());
		using T = pair<C,int>; pqg<T> pq; 
		auto ad = [&](int a, C b) {
			if (dist[a] <= b) return;
			pq.push({dist[a] = b,a});
		}; ad(st,0);
		while (sz(pq)) {
			T x = pq.top(); pq.pop(); if (dist[x.s] < x.f) continue;
			each(y,adj[x.s]) ad(y.f,x.f+y.s);
		}
	}
};

int N,M,Q;

V<uint64_t> W;
Dijkstra<ll,0> D;
vi bad;
vi pre_, pre;
vl dist;

vi with_illegal[200000];




AR<uint64_t,2> get_val(AR<int,2> a) {
	return {W.at(a[0]), a[1] == -1 ? BIG : W.at(a[1])};
}
















map<int,AR<int,2>> segs;






int id11(int x, int r) {
	return upb(with_illegal[x],r);
	

	

	


}

int id11(int x, int l, int r) {
	assert(x >= 0);
	return id11(x,r)-id11(x,l-1);
	

	

	

}

int id8(int x, int l, int r) {
	return r-l+1-id11(x,l,r);
}

AR<int,2> id10(AR<int,2> p, int x) {
	vi cands{x};
	id6(i,2) if (p[i] != -1) cands.pb(p[i]);
	remDup(cands);
	sort(all(cands),[](int a, int b) { return mp(W[a],a) < mp(W[b],b); }); 

	p = {-1,-1};
	id6(i,min(sz(cands),2)) p[i] = cands[i];
	return p;
}

pair<uint64_t,int> get_pair(int x) {
	if (x == -1) return {BIG,x};
	return {W.at(x),x};
}

uint64_t cur_ans;
AR<int,MX> endpoint;

void _process_W(int k, uint64_t nval) {
	const int idx = int(ub(all(dist),D.dist[k])-begin(dist));
	if (idx == sz(dist)) return;
	auto id5 = [&](map<int,AR<int,2>>::iterator it) -> uint64_t {
		if (it->s.at(0) == -1) return 0;
		uint64_t illegal = id11(it->s[0],it->f,next(it)->f-1);
		const uint64_t len = next(it)->f-it->f;
		uint64_t res = 0;
		res += (len-illegal)*W.at(it->s.at(0));
		if (illegal) res += illegal*W.at(it->s.at(1));
		return res;
	};
	

	

	

	

	

	

	auto id1 = [&](map<int,AR<int,2>>::iterator it) {
		if (it->s.at(0) == k) {
			endpoint.at(k) = next(it)->f;
			const int prev_ind = prev(it)->s.at(0);
			if (prev_ind != k && prev_ind != -1) {
				endpoint.at(prev_ind) = it->f;
			}
		}
	};
	
	auto it = prev(segs.ub(idx));
	for (;next(it) != end(segs);) {
		if (it->s[0] == k) {
			

			

			assert(endpoint.at(k) >= next(it)->f);
			auto IT = segs.find(endpoint.at(k)); assert(IT != end(segs));
			cur_ans += id8(k,it->f,IT->f-1)*(nval-W.at(k));
			it = IT;
		} else if (it->s[1] == k) { 

			

			cur_ans -= id5(it);
			swap(W.at(k),nval);
			it->s = id10(it->s,k);
			cur_ans += id5(it);
			swap(W.at(k),nval);
			id1(it);
			++it;
		} else {
			if (mp(nval,k) < get_pair(it->s[1])) {
				if (it->f < idx) {
					segs[idx] = it->s;
					++it;
				} else {
					cur_ans -= id5(it);
					swap(W.at(k),nval);
					it->s = id10(it->s,k);
					cur_ans += id5(it);
					swap(W.at(k),nval);
					id1(it);
					bool id4 = false;
					if (it != begin(segs) && it->s == prev(it)->s) {
						id4 = true;
					}
					++it;
					if (id4) segs.erase(prev(it));
				}
			} else break;
		}
	}
}

void process_W(int k, uint64_t nval) {
	_process_W(k,nval);
	W.at(k) = nval;
}

uint64_t get_ans() {
	return cur_ans;
	

	

	

	

	

	

	

	

	

	

	

}

int main() {
	setIO();
	re(N,M,Q);
	D.init(N);
	W.rsz(N);  re(W);
	rep(M) {
		ints(u,v,d);
		--u,--v;
		D.ae(u,v,d);
	}
	D.gen(0);
	pre_ = vi(N,-1);
	

	FOR(i,1,N) {
		int in_deg = 0;
		each(t,D.adj[i]) if (D.dist[t.f]+t.s == D.dist[i]) {
			++in_deg;
			pre_.at(i) = t.f;
		}
		assert(in_deg > 0);
		if (in_deg == 1) bad.pb(i);
		if (pre_.at(i) == 0) pre_.at(i) = -1;
	}
	

	sort(all(bad),[&](int x, int y) { return D.dist[x] < D.dist[y]; });
	vpi queries;
	rep(Q) {
		ints(K,X);
		--K;
		W.at(K) += X;
		queries.pb({K,X});
	}
	reverse(all(queries));
	for (int i: bad) {
		

		dist.pb(D.dist[i]);
	}
	segs[0] = {-1,-1};
	segs[sz(bad)] = {-1,-1};
	

	pre = vi(sz(bad));
	id6(i,sz(bad)) pre.at(i) = pre_[bad[i]];
	id6(i,sz(bad)) if (pre.at(i) != -1) with_illegal[pre.at(i)].pb(i);
	id6(i,N) process_W(i,W.at(i));
	V<uint64_t> ans;
	ans.pb(get_ans());
	for (auto [K,X]: queries) {
		process_W(K,W.at(K)-X);
		ans.pb(get_ans());
	}
	reverse(all(ans));
	each(t,ans) ps(t);
	
	

}


