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
tcT> void re(V<T>& x) { each(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { each(a,x) re(a); }
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

#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);

class Fenwick{
public:
	vector<int> li;
	int nn;
	Fenwick(int x){
		nn = x+5;
		li.resize(nn);
	}
	void add(int ind, int val){
		ind+=2;
		while(ind<nn){
			li[ind] ^= val;
			ind += ind & (-ind);
		}
	}
	int sum(int ind){
		ind += 2;
		int ret = 0LL;
		while(ind>0){
			ret ^= li[ind];
			ind -= ind & (-ind);
		}
		return ret;
	}
	void res(){
		for(int i = 0; i<li.size(); i++){
			li[i] = 0LL;
		}
	}

};

struct LCA {
public:
	int N; vector<vi> par, adj_lca; vi depth;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) d ++;
		par.assign(d,vi(N)); adj_lca.rsz(N); depth.rsz(N);
	}
	void ae(int x, int y) { adj_lca[x].pb(y), adj_lca[y].pb(x); }
	void gen(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		FOR(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		each(y,adj_lca[x]) if (y != par[0][x]) 
			depth[y] = depth[par[0][y]=x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		F0R(i,sz(par)) if ((d>>i)&1) x = par[i][x];
		return x; }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		R0F(i,sz(par)) {
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) { 

		return depth[x]+depth[y]-2*depth[lca(x,y)]; }
};

vector<int> times[600001];
int pre[300001];
int results[300001];
int og_results[300001];
vector<pi> queries[600002];
int lo[300001];
int hi[300001];
bool has[300001];
int n, q;
int u[300001];
int v[300001];
int l[300001];
int r[300001];
int a[300001];
int lca_val[300001];

int hsh_val[300001];
vector<int> adj[300001];
int point = 1;
void go(int now, int from){
	times[a[now]].pb(point++);
	pre[now] = point-1;
	for(int i = 0; i<adj[now].size(); i++){
		int to = adj[now][i];
		if(to==from){
			continue;
		}
		go(to,now);
	}
	times[a[now]].pb(point++);
}
Fenwick fen = Fenwick(600002);
LCA lca_ds;
void reset_queries(){
	fen.res();
	for(int i = 0; i<point; i++){
		queries[i].clear();
	}
	for(int i = 0; i<=q; i++){
		results[i] = 0LL;
	}
}
void make_query_start(int st, int ind){
	

	queries[st-1].pb(mp(pre[u[ind]],ind));
	queries[st-1].pb(mp(pre[v[ind]],ind));

}
void make_query_end(int st, int en, int ind){
	

	queries[en].pb(mp(pre[u[ind]],ind));
	queries[en].pb(mp(pre[v[ind]],ind));
	int got_lca = lca_val[ind];
	if(a[got_lca]>=st && a[got_lca]<=en){
		results[ind] ^= hsh_val[a[got_lca]];
	}

}
void make_query(int st, int en, int ind){
	

	queries[en].pb(mp(pre[u[ind]],ind));
	queries[en].pb(mp(pre[v[ind]],ind));
	int got_lca = lca_val[ind];
	if(a[got_lca]>=st && a[got_lca]<=en){
		results[ind] ^= hsh_val[a[got_lca]];
	}
	queries[st-1].pb(mp(pre[u[ind]],ind));
	queries[st-1].pb(mp(pre[v[ind]],ind));

}
void handle_queries(){
	for(int i = 0; i<point; i++){
		for(int j = 0; j<times[i].size(); j++){
			fen.add(times[i][j],hsh_val[i]);
		}
		for(int j = 0; j<queries[i].size(); j++){
			results[queries[i][j].s] ^= fen.sum(queries[i][j].f);
		}
	}
}
int main() {
	setIO();
	cin >> n >> q;
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	lca_ds.init(n);
	for(int i = 1; i<n; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
		lca_ds.ae(a,b);
	}
	lca_ds.gen();
	go(0,-1);
	

	

	

	

	

	

	for(int i = 1; i<=n; i++){
		ll a = (ll)i*900004043LL+910004063LL;
		a %= 1000006019LL;
		hsh_val[i] = (int)a;
	}
	reset_queries();
	for(int i = 0; i<q; i++){
		cin >> u[i] >> v[i] >> l[i] >> r[i];
		u[i]--;
		v[i]--;
		lca_val[i] = lca_ds.lca(u[i],v[i]);
		make_query(l[i],r[i],i);
	}
	handle_queries();
	for(int i = 0; i<q; i++){
		if(results[i]!=0LL){
			has[i] = true;
			lo[i] = l[i];
			hi[i] = r[i];
		}
		else{
			has[i] = false;
		}
	}
	reset_queries();
	for(int i = 0; i<q; i++){
		if(has[i]){
			make_query_start(l[i],i);
		}
	}
	handle_queries();
	for(int i = 0; i<q; i++){
		if(has[i]){
			og_results[i] = results[i];
		}
	}
	while(true){
		int cnt = 0;
		reset_queries();
		for(int i = 0; i<q; i++){
			if(has[i] && lo[i]!=hi[i]){
				make_query_end(l[i],(lo[i]+hi[i])/2,i);
				

				cnt++;
			}
		}
		if(cnt==0){
			break;
		}
		handle_queries();
		for(int i = 0; i<q; i++){
			if(has[i] && lo[i]!=hi[i]){
				

				if(results[i] != og_results[i]){
					hi[i] = (lo[i]+hi[i])/2;
				}
				else{
					lo[i] = (lo[i]+hi[i])/2+1;
				}
			}
		}
	}
	for(int i = 0; i<q; i++){
		if(!has[i]){
			cout << -1 << "\n";
		}
		else{
			cout << lo[i] << "\n";
		}
	}
}


