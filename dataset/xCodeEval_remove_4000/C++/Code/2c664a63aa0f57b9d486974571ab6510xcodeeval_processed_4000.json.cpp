
































































































































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
	tcT> constexpr bool id11 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id2 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id4 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id10 = !id2<T> && id11<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id2<T>,void>::type re(T& x) { cin >> x; } 

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
	tcT> constexpr bool id5 = !id4<T> && id11<T>;

	

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
	tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
		

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
	template<int lev, class T> void id13(const T& t) {
		cerr << "\n\n" << ts_sep(id8<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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



const int mx = 205;

int n, k;
int p[mx];

int calcK(){
	int res = 0;
	vb visited(n+1, false);
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			res++;
			for(int cur = i;;cur = p[cur]){
				if(visited[cur]) break;
				visited[cur] = true;
			}
		}
	}
	return res;
}

bool edgesWork(vpi eds){
	

	vi has_to(n+1, -1);
	vi has_from(n+1, -1);
	DSU dsu; dsu.init(n+5);

	bool flag = false;
	auto addEdge = [&](int a, int b){
		if(has_to[a] != -1 && has_to[a] != b){
			flag = true;
		}
		has_to[a] = b;
		if(has_from[b] != -1 && has_from[b] != a){
			flag = true;
		}
		has_from[b] = a;
	};

	{ 

		for(auto u: eds){
			addEdge(u.f, u.s);

			if(u.f < u.s){
				for(int i = u.s-1; i-1 >= u.f+1; i--){
					

					addEdge(i, i-1);
				}
			}
			else if(u.f > u.s){
				for(int i = u.s+1; i+1 <= u.f-1; i++){
					

					addEdge(i, i+1);
				}
			}
			if(flag) return false;

			dbg(min(u.f, u.s), max(u.f, u.s));
			for(int i = min(u.f, u.s); i+1 <= max(u.f, u.s); i++){
				dsu.unite(i, i+1);
			}
		}
	}

	vb no_left(n+1, false);
	vb no_right(n+1, false);

	for(auto u: eds){
		if(u.f < u.s){
			for(int i = u.f+1; i <= u.s-1; i++){
				no_right[i] = true;
			}
		}
		else if(u.f > u.s){
			for(int i = u.f-1; i >= u.s+1; i--){
				no_left[i] = true;
			}
		}
	}

	dbg(no_left, no_right);

	vector<pair<int, pair<bool, bool>>> comps; 

	for(int i = 1; i <= n; i++){
		if(dsu.get(i) == i){
			

			int L = -1, R = -1;
			for(int l = i; l >= 1; l--){
				if(dsu.sameSet(l, i)){
					L = l;
				}
				else{
					break;
				}
			}

			for(int r = i; r <= n; r++){
				if(dsu.sameSet(r, i)){
					R = r;
				}
				else{
					break;
				}
			}

			dbg(L, i, R);

			for(int i = L+1; i <= R-1; i++){
				if(no_left[i] && no_right[i]) return false;
			}

			bool id12 = true;
			bool id0 = true;

			if(has_to[L] != -1 && has_from[L] != -1){
				id12 = false;
			}
			if(has_to[R] != -1 && has_from[R] != -1){
				id0 = false;
			}
			comps.pb(mp(L, mp(id12, id0)));


		}
	}

	dbg(comps);
	int id9 = sz(comps)-(n+1-k);

	if(id9 < 0) return false;

	for(int i = 1; i <= n; i++){
		dsu.unite(i, p[i]);
	}

	int id1 = 0;

	for(int i = 0; i+1 < sz(comps); i++){
		if(comps[i].s.s && comps[i+1].s.f){
			if(dsu.unite(comps[i].f, comps[i+1].f)){
				id1++;
			}
		}
	}

	

	for(int i = 1; i <= n; i++){
		if(!dsu.sameSet(i, 1)) return false;
	}



	if(id1 <= id9){
		return true;
	}



	return false;
}

void solve(){
	

	

	

	

	

	

	

	

	


	

	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	k = calcK();

	vi cur_perm(n+1, -1);
	vb id3(n+1, false);
	for(int i = 1; i <= n; i++){
		bool worked = false;
		dbg(cur_perm);
		for(int j = 1; j <= n; j++){
			if(id3[j]) continue;
			cur_perm[i] = j;
			vpi edges;
			for(int z = 1; z+1 <= i; z++){
				edges.pb(mp(cur_perm[z], p[cur_perm[z+1]]));
			}
			if(edgesWork(edges)){
				worked = true;
				id3[j] = true;
				break;
			}
		}
		dbg("AFTER", cur_perm);
		assert(worked);
	}

	for(int i = 1; i <= n; i++){
		cout << cur_perm[i];
		if(i+1 <= n){
			cout << " ";
		}
	}
	cout << "\n";
}

int main() {
	setIO();
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solve();
	}
	

}


