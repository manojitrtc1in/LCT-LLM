
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
	tcT> constexpr bool id10 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id8 = !id0<T> && id10<T>;
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
	tcT> constexpr bool id3 = !id2<T> && id10<T>;

	

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
	tcT> typename enable_if<id10<T>,str>::type ts_sep(T v, str sep) {
		

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
	template<int lev, class T> void id11(const T& t) {
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

const int mx = 1000015;

const bool DEBUG_TIME = false;
int n;
vpi adj[mx];
vpi eds;

pi par[mx];



pair<ll, int> dp[2*mx];
bool used[2 * mx];


















































void id1(int id){ 

	int node = eds[id >> 1].second;
	int p = eds[id >> 1].first; 


	

	

	if ((id & 1)) {
		swap(node, p);
	}

	


	dp[id^1].f = 1;
	dp[id^1].s = 1;
	for(auto u: adj[node]){
		if(u.f == p) continue;
		id1(u.s);
		dp[id^1].f+=dp[u.s^1].f+dp[u.s^1].s;
		dp[id^1].s+=dp[u.s^1].s;
	}
}

void id12(int node){ 

	int p = par[node].f;

	pair<ll, int> tot_sum = mp(1, 1);
	if(node != 1){
		tot_sum.f+=dp[par[node].s^1].f+dp[par[node].s^1].s;
		tot_sum.s+=dp[par[node].s^1].s;
	}
	for(auto u: adj[node]){
		if(u.f == p) continue;
		tot_sum.f+=dp[u.s^1].f+dp[u.s^1].s;
		tot_sum.s+=dp[u.s^1].s;
	}

	for(auto u: adj[node]){
		if(u.f == p) continue;
		tot_sum.f-=dp[u.s^1].f+dp[u.s^1].s;
		tot_sum.s-=dp[u.s^1].s;

		dp[u.s] = tot_sum;

		tot_sum.f+=dp[u.s^1].f+dp[u.s^1].s;
		tot_sum.s+=dp[u.s^1].s;
	}

	for(auto u: adj[node]){
		if(u.f == p) continue;
		id12(u.f);
	}
}

int id7(vi sizes){
	

	

	int sum = 0;
	for(auto u: sizes){
		sum+=u;
	}
	assert(sum == n-1);

	sort(all(sizes));

	vi occ((n-1)/2+1, 0);
	for(auto u: sizes){
		occ[u]++;
	}

	for(int i = 1; i < sz(occ); i++){
		if(occ[i] >= 3){
			int extras = 0;
			if(occ[i] % 2 == 0){
				extras = occ[i]-2;
			}
			else{
				extras = occ[i]-1;
			}
			occ[i]-=extras;
			if(2*i < sz(occ)) occ[2*i]+=extras/2;
		}
	}

	bitset<500005> possibles;
	possibles[0] = 1;

	int num_times = 0;
	for(int i = 1; i < sz(occ); i++){
		for(int j = 0; j < occ[i]; j++){
			num_times++;
			possibles |= (possibles<<i);
		}
	}
	


	int closest = 0;
	for(int i = (n-1)/2; i >= 0; i--){
		if(possibles[i] == 1){
			closest = i;
			break;
		}
	}

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	



	return closest;
}

ll getAns(int node){
	ll id9 = 0;
	
	int max_size = 0;
	for(auto u: adj[node]){
		pair<ll, int> dp_val = dp[u.s^1];
		id9+=dp_val.f;
		ckmax(max_size, dp_val.s);
	}

	int closest_partition = 0;
	if(max_size >= (n-1)/2){
		closest_partition = max_size;
	}
	else{
		vi sizes;
		for(auto u: adj[node]){
			pair<ll, int> dp_val = dp[u.s^1];

			sizes.pb(dp_val.s);
		}
		closest_partition = id7(sizes);
	}

	ll res = id9+ll(closest_partition+1)*ll(n-1-closest_partition+1);
	

	

	

	return res;
}



int main() {
	setIO();

	if(DEBUG_TIME){
		n = 1000000;
	}
	else{
		cin >> n;
	}

	

	clock_t BEG = clock();
	int id = 0;
	for(int i = 2; i <= n; i++){
		int p; 
		if(DEBUG_TIME){
			

			p = 1 + rng() % (i-1);
		}
		else{
			cin >> p;
		}

		par[i] = mp(p, id*2);
		

		
		eds.pb(mp(i, p));
		adj[i].pb(mp(p, id * 2));
		adj[p].pb(mp(i, id * 2 + 1));
		id++;
	}

	


	for(auto u: adj[1]){
		id1(u.s);
	}

	

	

	

	


	

	id12(1);

	


	

	

	

	

	

	


	

	

	

	


	


	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ckmax(ans, getAns(i));
	}

	ps(ans);

	




	

}

