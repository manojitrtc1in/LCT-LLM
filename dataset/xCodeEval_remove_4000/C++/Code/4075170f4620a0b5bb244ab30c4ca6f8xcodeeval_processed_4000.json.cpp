
































































































































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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
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
	tcT> constexpr bool id11 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id10 = !id0<T> && id11<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id10<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id10<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id3 = !id2<T> && id11<T>;

	

	tcT> typename enable_if<id2<T>,str>::type ts(T v) {
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
	tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
		

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
	template<int lev, class T> void id12(const T& t) {
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



vpi id1(vpi v){
	sort(all(v), [&](pi l, pi r){
		if(l.f != r.f) return l > r;
		return l < r;
	});

	vpi new_v;
	int cur_r = MOD;
	for(auto u: v){
		if(u.s >= cur_r){
			continue;
		}
		ckmin(cur_r, u.s);
		new_v.pb(u);
	}
	sor(new_v);
	return new_v;
}



tcT, int SZ> struct LazySeg { 
	static_assert(pct(SZ) == 1); 

	ll seg1[2*SZ];
	ll seg2[2*SZ];
	ll lazy1[2*SZ];
	pl lazy2[2*SZ];

	LazySeg() { 
		id4(i,2*SZ){
			seg1[i] = seg2[i] = 0;
			lazy1[i] = 0;
			lazy2[i] = mp(0, 0);
		}
	}
	void push(int ind, int L, int R) { 

		seg2[ind]+=seg1[ind]*lazy2[ind].f+lazy2[ind].s*(R-L+1);
		seg1[ind]+=lazy1[ind]*(R-L+1);

		if(L != R){
			id4(i, 2){
				lazy2[2*ind+i].f+=lazy2[ind].f;
				lazy2[2*ind+i].s+=lazy2[ind].s+lazy2[ind].f*lazy1[2*ind+i];
				lazy1[2*ind+i]+=lazy1[ind];
			}
		}

		lazy1[ind] = 0;
		lazy2[ind] = mp(0, 0);

		

		

		

	} 

	void pull(int ind){
		seg1[ind] = seg1[2*ind]+seg1[2*ind+1];
		seg2[ind] = seg2[2*ind]+seg2[2*ind+1];
	}
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi, bool typ, ll inc, int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			if(typ == 0){
				lazy1[ind] = inc;
			}
			else{
				lazy2[ind] = mp(1, 0);
			}
			push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,typ, inc,2*ind,L,M); 
		upd(lo,hi,typ, inc,2*ind+1,M+1,R); pull(ind);
	}
	ll query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return seg2[ind];
		int M = (L+R)/2; return query(lo,hi,2*ind,L,M)+
			query(lo,hi,2*ind+1,M+1,R);
	}
};

const int SZ = 262144;
LazySeg<ll, SZ> seg = LazySeg<ll, SZ>();

void addUpd(int l, int r, int amt){
	dbg(l, r, amt);
	seg.upd(l, r, 0, amt);
}

void convUpd(){
	dbg("conv");
	seg.upd(0, SZ-1, 1, 0);
}

ll queryRect(int l, int r){
	dbg("q", l, r);
	return seg.query(l, r);
}













































const int mx = 200005;
const int mx2 = 1000005;

int n, q;
int p[mx];
int ip[mx];
int l[mx2];
int r[mx2];
ll ans[mx2];

int main() {
	setIO();
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		ip[p[i]] = i;
	}
	for(int i = 1; i <= q; i++){
		cin >> l[i] >> r[i];
	}

	set<pi> rangs; rangs.insert(mp(1, n));

	vector<pair<pi, pi>> rects;

	for(int i = n; i >= 1; i--){
		int pos = ip[i];
		pi rang = mp(-1, -1);
		{
			auto it = prev(rangs.lb(mp(pos+1, 0)));
			rang = *it;
		}

		rangs.erase(rang);
		if(rang.f <= pos-1){
			rangs.insert(mp(rang.f, pos-1));
		}
		if(pos+1 <= rang.s){
			rangs.insert(mp(pos+1, rang.s));
		}

		vpi adds;
		for(int fac1 = 1; fac1*fac1 < i; fac1++){
			if(i % fac1 == 0){
				int fac2 = i/fac1;
				int id9 = ip[fac1];
				int id7 = ip[fac2];
				if(rang.f <= id9 && id9 <= rang.s && rang.f <= id7 && id7 <= rang.s){
					adds.pb(mp(min(pos, min(id9, id7)), max(pos, max(id9, id7))));
				}
			}
		}

		adds = id1(adds);
		sor(adds);

		dbg(adds);

		int last_x = rang.f-1;
		for(auto u: adds){
			rects.pb(mp(mp(last_x+1, u.f), mp(u.s, rang.s)));
			last_x = u.f;
		}
	}

	dbg(rects);

	

	vector<pair<int, pair<pi, int>>> upds; 

	vector<pair<int, pair<pi, int>>> queries; 


	for(auto u: rects){
		upds.pb(mp(u.s.f, mp(u.f, +1)));
		upds.pb(mp(u.s.s+1, mp(u.f, -1)));
	}

	for(int i = 1; i <= q; i++){
		queries.pb(mp(r[i], mp(mp(l[i], n), i)));
	}
	sor(upds);
	sor(queries);

	int id8 = 0;
	int queries_ind = 0;

	for(int y = 1; y <= n; y++){
		while(id8 < sz(upds) && upds[id8].f <= y){
			assert(upds[id8].f == y);
			addUpd(upds[id8].s.f.f, upds[id8].s.f.s, upds[id8].s.s);
			id8++;
		}
		convUpd();
		while(queries_ind < sz(queries) && queries[queries_ind].f <= y){
			assert(queries[queries_ind].f == y);
			ans[queries[queries_ind].s.s] = queryRect(queries[queries_ind].s.f.f, queries[queries_ind].s.f.s);
			queries_ind++;
		}
	}

	for(int i = 1; i <= q; i++){
		cout << ans[i] << "\n";
	}

	

}


