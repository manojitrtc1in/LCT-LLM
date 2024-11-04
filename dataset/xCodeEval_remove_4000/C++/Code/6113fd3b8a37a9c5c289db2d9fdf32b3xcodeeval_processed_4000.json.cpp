
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
























const int MOD = 1e9+7; 

const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
const char zd[4] = {'D', 'R', 'U', 'L'};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } 

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 

ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) { 
	

	hi ++; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }



template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }




str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	
		return b ? "true" : "false"; 
	
		return ts((int)b);
	
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { 

	
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	
}
template<class A, class B> str ts(pair<A,B> p) {
	
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	
		return ts(p.f)+" "+ts(p.s);
	
}



template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } 

template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }



void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }


	
	
		 << __FUNCTION__  << ") -> CHK FAILED: (" << 

	
	




void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void id1() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	id1();
	

	

	

	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

}



template<int SZ> struct Dinic {
	int N,s,t; 

	typedef int F; 

	struct Edge { int to, rev; F flo, cap; };
	vector<Edge> adj[SZ]; 

	void reset() { F0R(i,N) adj[i].clear(); }
	void ae(int u, int v, F cap, F rcap = 0, F inflo = 0) { 
		assert(min(cap,rcap) >= 0);
		assert(inflo <= cap); 
		Edge a{v,sz(adj[v]),inflo,cap}, b{u,sz(adj[u]),-inflo,rcap};
		adj[u].pb(a), adj[v].pb(b); } 
	int lev[SZ]; typename vector<Edge>::iterator cur[SZ]; 
	bool bfs() { 

		F0R(i,N) lev[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); lev[s] = 0; 
		while (sz(q)) {
			int u = q.ft; q.pop();
			trav(e,adj[u]) if (lev[e.to] < 0 && e.flo < e.cap) 
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
		return lev[t] >= 0;
	}
	F dfs(int v, F flo) {
		if (v == t) return flo;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (lev[e.to]!=lev[v]+1||e.flo==e.cap) continue;
			F df = dfs(e.to,min(flo,e.cap-e.flo));
			if (df) { e.flo += df; adj[e.to][e.rev].flo -= df;
				return df; } 

		}
		return 0;
	}
	F maxFlow(int _N, int _s, int _t) {
		N = _N, s = _s, t = _t; assert(s != t);
		F tot = 0; while (bfs()) while (F df = 
			dfs(s,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

Dinic<100105> din; 


int n, m;
vector<vi> S, costmat, id0, typ;

bool inBox(int x, int y){
	if(x < 0 || x > n-1 || y < 0 || y > m-1) return 0;
	return 1;
}

bool solve(){
	typ = costmat;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			bool haseq = 0;
			bool hasles = 0;
			for(int d = 0; d < 4; d++){
				int x = i+xd[d];
				int y = j+yd[d];
				if(!inBox(x, y)) continue;
				if(S[x][y] < S[i][j]) hasles = 1;
				if(S[x][y] == S[i][j]) haseq = 1;
			}
			if(!haseq && !hasles){
				return 0;
			}
			else if(!haseq && hasles){
				typ[i][j] = 2;
				for(int d = 0; d < 4; d++){
					int x = i+xd[d];
					int y = j+yd[d];
					if(!inBox(x, y)) continue;
					if(S[x][y] < S[i][j]){
						id0[i][j] = d;
						costmat[i][j] = S[i][j]-S[x][y];
					}
				}
			}
			else if(haseq && !hasles){
				typ[i][j] = 0;
			}
			else if(haseq && hasles){
				typ[i][j] = 1;
			}
		}
	}

	din.reset();

	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(typ[i][j] == 2) continue;
			if((i+j) % 2 != 0) continue;
			for(int d = 0; d < 4; d++){
				int x = i+xd[d];
				int y = j+yd[d];
				if(!inBox(x, y)) continue;
				if(S[x][y] == S[i][j]){
					din.ae(m*i+j, m*x+y, 1);
				}
			}
		}
	}

	

	din.ae(n*m+1, n*m, MOD);	
	int lsum = 0, rsum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(typ[i][j] == 2) continue;

			if(typ[i][j] == 0){
				if((i+j) % 2 == 0){
					din.ae(n*m+2, m*i+j, 1);
					lsum++;
				}
				else{
					din.ae(m*i+j, n*m+3, 1);
					rsum--;
				}
			}
			else{
				if((i+j) % 2 == 0){
					din.ae(n*m, m*i+j, 1);
				}
				else{
					din.ae(m*i+j, n*m+1, 1);
				}
			}
		}
	}

	din.ae(n*m, n*m+3, lsum);
	din.ae(n*m+2, n*m+1, -rsum);

	int flo = din.maxFlow(n*m+4, n*m+2, n*m+3);

	if(flo != lsum-rsum) return 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i+j) % 2 != 0) continue;
			for(auto u: din.adj[m*i+j]){
				if(u.to >= n*m) continue;
				if(u.flo > 0){
					assert(u.flo == 1);
					for(int d = 0; d < 4; d++){
						int x = i+xd[d];
						int y = j+yd[d];
						if(!inBox(x, y)) continue;
						if(m*x+y == u.to){ 

							id0[i][j] = d;
							id0[x][y] = (d+2) % 4;

							assert(S[i][j] == S[x][y]);
							costmat[i][j] = 1;
							costmat[x][y] = S[i][j]-1;
						}	
					}
					

					

				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(id0[i][j] == -1){
				assert(typ[i][j] == 1);
				bool found = 0;
				for(int d = 0; d < 4; d++){
					int x = i+xd[d];
					int y = j+yd[d];
					if(!inBox(x, y)) continue;
					if(S[x][y] < S[i][j]){
						found = 1;
						id0[i][j] = d;
						costmat[i][j] = S[i][j]-S[x][y];
					}
				}
				assert(found);
			}
		}
	}

	return 1;
}

int main() {
	setIO();
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> m;
		S.clear(); costmat.clear(); id0.clear();
		for(int i = 0; i < n; i++){
			vi ro;
			for(int j = 0; j < m; j++){
				int val;
				cin >> val;
				ro.pb(val);
			}
			S.pb(ro);
			costmat.pb(vi(m, -1)); id0.pb(vi(m, -1));
		}
		if(solve()){
			ps("YES");
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << costmat[i][j] << " ";
				}
				cout << "\n";
			}
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << zd[id0[i][j]] << " ";
				}
				cout << "\n";
			}
		}
		else{
			ps("NO");
		}
	}
	

}



