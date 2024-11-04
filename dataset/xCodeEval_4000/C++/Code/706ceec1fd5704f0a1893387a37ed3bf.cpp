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
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }



#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

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
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}



struct BCC {
	V<vpi> adj; vpi ed; 
	V<vi> comps, vertSets; 

	int N, ti = 0; vi disc, st; 
	void init(int _N) { N = _N; disc.rsz(N), adj.rsz(N); }
	void ae(int x, int y) { 
		adj[x].eb(y,sz(ed)), adj[y].eb(x,sz(ed)), ed.eb(x,y); }
	int dfs(int x, int p = -1) { 

		int low = disc[x] = ++ti;
		each(e,adj[x]) if (e.s != p) {
			if (!disc[e.f]) {
				st.pb(e.s); 

				int LOW = dfs(e.f,e.s); ckmin(low,LOW); 
				if (disc[x] <= LOW) { 

					comps.eb(); vi& tmp = comps.bk; 

					for (int y = -1; y != e.s; )
						tmp.pb(y = st.bk), st.pop_back();
				}
			} else if (disc[e.f] < disc[x]) 

				ckmin(low,disc[e.f]), st.pb(e.s);
		}
		return low;
	}
	void gen() { 
		F0R(i,N) if (!disc[i]) dfs(i);  
		vb in(N);
		each(c,comps) { 

			vertSets.eb(); 

			auto ad = [&](int x) { if (!in[x]) in[x] = 1, vertSets.bk.pb(x); };
			each(e,c) ad(ed[e].f), ad(ed[e].s);
			each(e,c) in[ed[e].f] = in[ed[e].s] = 0;
		}
	}
};

const int mx = 100005;
int n, m;
int input_edges[1005];
vi adj[mx];
vi children[mx];
bool visited[mx];
vpi ans;

pair<ll, vi> dp[2];
pair<ll, vi> ndp[2];
pair<ll, vi> DP[mx][2][2]; 


void markVisited(int node){
	visited[node] = 1;
	for(auto u: adj[node]){
		if(visited[u]) continue;
		children[node].pb(u);
		markVisited(u);
	}
}

void genDP(int node){
	if(sz(children[node]) == 0){
		DP[node][0][0] = mp(0, vi{-1, -1});
		DP[node][1][0] = mp(1, vi{-1, node});
		DP[node][0][1] = DP[node][1][1] = mp(MOD, vi{-1, -1});
		return;
	}
	for(auto u: children[node]){
		genDP(u);	
	}

	dp[0] = mp(0, vi{-1});
	dp[1] = mp(MOD, vi{-1});

	for(auto u: children[node]){
		ndp[0] = ndp[1] = mp(MOD, vi{-1});
		ckmin(ndp[0], mp(dp[0].f+DP[u][1][1].f, vi{-1}));
		ckmin(ndp[0], mp(dp[0].f+DP[u][1][0].f, vi{-1}));
		ckmin(ndp[1], mp(dp[1].f+DP[u][1][1].f, vi{dp[1].s}));
		ckmin(ndp[1], mp(dp[1].f+DP[u][1][0].f, vi{dp[1].s}));
		ckmin(ndp[1], mp(dp[0].f+DP[u][0][0].f, vi{u}));
		swap(dp[0], ndp[0]); swap(dp[1], ndp[1]);
	}

	


	for(int i1 = 0; i1 < 2; i1++){
		for(int i2 = 0; i2 < 2; i2++){
			

			if(i1+i2 > sz(children[node])){ 

				continue;
			}
			int children_left = sz(children[node])-i1-i2;
			int spec = -1;
			for(auto u: children[node]){
				if(u == dp[i1].s[0]){
					continue;
				}
				spec = u;
				break;
			}
			pair<ll, vi> res = mp(dp[i1].f-children_left/2, vi{dp[i1].s[0], -1});
			if(spec != -1){
				if(DP[spec][1][0].f <= DP[spec][1][1].f){
					res.s[1] = DP[spec][1][0].s[1];
				}
				else{
					res.s[1] = DP[spec][1][1].s[1];
				}
			}
			ckmin(DP[node][i2][i1], res);
		}
	}

}

void buildDP(int node, bool type1 = 0, bool type2 = 1, int forbid = -1){
	

	int leftover = DP[node][type1][type2].s[0];

	vi to_pair;
	for(auto u: children[node]){
		if(u == leftover) continue;

		int bot_node = -1;
		int n_type2 = -1;
		if(DP[u][1][0].f <= DP[u][1][1].f){
			bot_node = DP[u][1][0].s[1];
			n_type2 = 0;
		}
		else{
			bot_node = DP[u][1][1].s[1];
			n_type2 = 1;
		}
		if(bot_node != forbid){
			to_pair.pb(bot_node);
		}
		buildDP(u, 1, n_type2, bot_node);
	}

	if(leftover != -1){
		buildDP(leftover, 0, 0);
	}


	while(sz(to_pair) >= 2){
		int node_1 = to_pair.bk; to_pair.pop_back();
		int node_2 = to_pair.bk; to_pair.pop_back();
		ans.pb(mp(node_1, node_2));
	}
	if(sz(to_pair) == 1){
		ans.pb(mp(node, to_pair[0]));
	}

	
}

int main() {
	setIO();
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;


		

		for(int i = 1; i <= n; i++){
			adj[i].clear();
			children[i].clear();
			visited[i] = 0;
		}
		ans.clear();
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					DP[i][j][k] = mp(MOD, vi{});
				}
			}
		}



		BCC bcc;
		bcc.init(n+5);
		for(int i = 1; i <= m; i++){
			int si;
			cin >> si;
			for(int j = 1; j <= si; j++){
				cin >> input_edges[j];
			}
			for(int j = 1; j+1 <= si; j++){
				bcc.ae(input_edges[j], input_edges[j+1]);
			}
		}
		bcc.gen();

		for(auto u: bcc.vertSets){
			if(sz(u) == 2){
				adj[u[0]].pb(u[1]);
				adj[u[1]].pb(u[0]);
			}
		}

		for(int i = 1; i <= n; i++){
			if(visited[i]) continue;
			markVisited(i);
			genDP(i);

			if(DP[i][0][0] <= DP[i][0][1]){
				buildDP(i, 0, 0);
			}
			else{
				buildDP(i, 0, 1);
			}
			
		}

		

		

		


		ps(sz(ans));
		for(auto u: ans){
			ps(u.f, u.s);
		}

	}
	

}


