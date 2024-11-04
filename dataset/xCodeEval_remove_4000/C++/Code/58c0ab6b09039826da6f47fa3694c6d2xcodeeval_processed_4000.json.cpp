




























using namespace std;




typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;



























 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
 

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + id1);
	}
	

	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};




using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}


const int mod = 998244353;


mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}

int par[szz],ran[szz];
void init(){ for(int i=0;i<szz;i++) par[i] = i, ran[i] = 0; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
int nxt, zan[300005];
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) {
		par[x] = y;
		zan[y] = nxt++;
	}
	else{
		par[y] = x;
		zan[x] = nxt++;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
int n, m, q;
vc<int>edge[600005];
int cs[600005];


int up[20][SZ],dep[SZ],in[SZ],out[SZ],id,root,rev[SZ];
struct dbling{
	bool ready = 0;
	void dfs(int v,int u,int d){
		in[v] = id++;
		up[0][v] = u; dep[v] = d;
		rep(i,edge[v].size()){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i], v, d+1);
		}
		out[v] = id-1;
	}
	void prepare(){
	    dfs(root,-1,0);
		rep(j,19){
			rep(i,SZ){
				if(up[j][i] == -1) up[j+1][i] = up[j][i];
				else up[j+1][i] = up[j][up[j][i]];
			}
		}
		rep(i,600005) rev[in[i]] = i;
		ready = 1;
	}
	int get(int a,int b){
		if(dep[a] > dep[b]) swap(a,b);
		int D = dep[b]-dep[a];
		rep(i,20){
			if(((D>>i)&1)) b = up[i][b];
		}
		if(a == b) return a;
		for(int i=19;i>=0;i--){
			if(up[i][a] != up[i][b]){
				a = up[i][a];
				b = up[i][b];
			}
		}
		return up[0][a];
	}
	int dist(int a,int b){
		int c = get(a,b);
		return dep[a]+dep[b]-2*dep[c];
	}
	int dist(int a,int b,int c){
		

		return dep[a]+dep[b]-2*dep[c];
	}
	int go_up(int v,int a){
	    if(dep[v] < a) return -1;
	    rep(i,20) if(((a>>i)&1)) v = up[i][v];
	    return v;
	}
	

	

	

	

	int v_on_path(int a,int b,int x){
		int c = get(a,b);
		int d = dist(a,b,c);
		if(x <= 0 || x > d+1) return -1;
		if(x <= dep[a]-dep[c]+1){
			return go_up(a, x-1);
		}
		else{
			x = d+2-x;
			return go_up(b, x-1);
		}
	}
	vc<int>get_path(int a, int b){
		int upp = get(a, b);
		int cur;
		vc<int>ret;
		
		cur = a;
		while(1){
			ret.pb(cur);
			if(cur == upp) break;
			cur = up[0][cur];
		}
		vc<int>ret2;
		cur = b;
		while(1){
			if(cur == upp) break;
			ret2.pb(cur);
			cur = up[0][cur];
		}
		reverse(all(ret2));
		int geta = ret.size();
		ret.resize(ret.size()+ret2.size());
		rep(i, ret2.size()) ret[geta+i] = ret2[i];
		return ret;
	}
}kaede;
template<typename F, typename T>
struct id0{
	int sz;
	vector<T>seg;
	const F f;
	const T e;
	id0(int n, const F f, const T e): f(f), e(e) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	

	void update(int a, T p, bool mrg){
		a += sz-1;
		if(mrg) seg[a] = f(seg[a], p);
		else seg[a] = p;
		while(a){
			a = (a-1)/2;
			seg[a] = f(seg[a*2+1], seg[a*2+2]);
		}
	}
	void make(vector<T>a){
		rep(i, a.size()) seg[i+sz-1] = a[i];
		for(int i=sz-2;i>=0;i--) seg[i] = f(seg[i*2+1], seg[i*2+2]);
	}
	T query(int a, int b){
		a += sz-1, b += sz-1;
		T L = e, R = e;
		while(a <= b){
			if((a&1) == 0) { L = f(L, seg[a++]); }
			if((b&1) == 1) { R = f(seg[b--], R); }
			if(a > b) break;
			a = (a-1) >> 1;
			b = (b-1) >> 1;
		}
		return f(L, R);
	}
	int find_left(int a, int b, int k, int l, int r, T v){
		if(r < a || b < l) return INF;
		if(a <= l && r <= b){
			if(f(seg[k], v) == seg[k]){
				while(k < sz-1){
					if(f(seg[k*2+1], v) == seg[k*2+1]) k = k*2+1;
					else k = k*2+2;
				}
				return k - (sz-1);
			}
			return INF;
		}
		int ret = find_left(a, b, k*2+1, l, (l+r)/2, v);
		if(ret != INF) return ret;
		return find_left(a, b, k*2+2, 1+(l+r)/2, r, v);
	}
	

	int find_right(int a, int b, int k, int l, int r, T v){
		if(r < a || b < l) return -INF;
		if(a <= l && r <= b){
			if(f(seg[k], v) == seg[k]){
				while(k < sz-1){
					if(f(seg[k*2+2], v) == seg[k*2+2]) k = k*2+2;
					else k = k*2+1;
				}
				return k - (sz-1);
			}
			return -INF;
		}
		int ret = find_right(a, b, k*2+2, 1+(l+r)/2, r, v);
		if(ret != -INF) return ret;
		return find_right(a, b, k*2+1, l, (l+r)/2, v);
	}
	

	int find_left(int a, int b, T v){
		return find_left(a, b, 0, 0, sz-1, v);
	}
	

	

	int find_right(int a, int b, T v){
		return find_right(a, b, 0, 0, sz-1, v);
	}
	
};




auto f = [](int a, int b){ return min(a, b); };
int e = INF;
id0<decltype(f), decltype(e)>getmn((1<<20), f, e);
auto f2 = [](int a, int b){ return max(a, b); };
int e2 = -INF;
id0<decltype(f2), decltype(e2)>getmx((1<<20), f2, e2);





multiset<int,greater<int>>mx;
multiset<int>mn;
set<P2>M;

int ini(P a){
	if(M.empty()){
		int pp = getmn.query(a.a, a.b);
		int qq = getmx.query(a.a, a.b);
		M.insert(mp(a, mp(pp,qq)));
		mn.insert(pp);
		mx.insert(qq);
		return a.sc-a.fi+1;
	}
    auto it = M.lower_bound(mp(mp(a.fi,-1LL),mp(-1LL,-1LL)));
    if(it != M.begin()){
        it--;
        if((*it).fi.sc < a.fi) it++;
    }
    int ret = 0;
    while(it != M.end()){
        if(a.sc < (*it).fi.fi){
            int pp = getmn.query(a.a, a.b);
			int qq = getmx.query(a.a, a.b);
			M.insert(mp(a, mp(pp,qq)));
			mn.insert(pp);
			mx.insert(qq);
            return ret+a.sc-a.fi+1;
        }
        else if((*it).fi.sc < a.fi){
        	it++; continue;
        }
        assert(a.fi <= (*it).fi.sc && a.sc >= (*it).fi.fi);
        a.fi = min(a.fi,(*it).fi.fi);
        a.sc = max(a.sc,(*it).fi.sc);
        ret -= (*it).fi.sc-(*it).fi.fi+1;
        mn.erase(mn.find((*it).sc.fi));
        mx.erase(mx.find((*it).sc.sc));
       	it = M.erase(it);
    }
    	int pp = getmn.query(a.a, a.b);
		int qq = getmx.query(a.a, a.b);
		M.insert(mp(a, mp(pp,qq)));
		mn.insert(pp);
		mx.insert(qq);
    return ret+a.sc-a.fi+1;
}
int outi(P a){
	if(M.empty()){
		return a.sc-a.fi+1;
	}
    auto it = M.lower_bound(mp(mp(a.fi,-1LL),mp(-1LL,-1LL)));
    if(it != M.begin()){
        it--;
        if((*it).fi.sc < a.fi) it++;
    }
    int ret = 0;
    P orig = a;
    while(it != M.end()){
        if(a.sc < (*it).fi.fi){
           	break;
        }
        else if((*it).fi.sc < a.fi){
        	it++; continue;
        }
        assert(a.fi <= (*it).fi.sc && a.sc >= (*it).fi.fi);
        a.fi = min(a.fi,(*it).fi.fi);
        a.sc = max(a.sc,(*it).fi.sc);
        ret -= (*it).fi.sc-(*it).fi.fi+1;
        mn.erase(mn.find((*it).sc.fi));
        mx.erase(mx.find((*it).sc.sc));
       	it = M.erase(it);
    }
    if(a.a != orig.a){
    	int pp = getmn.query(a.a, orig.a-1);
		int qq = getmx.query(a.a, orig.a-1);
		

		mn.insert(pp);
		mx.insert(qq);
    	M.insert(mp(mp(a.a, orig.a-1), mp(pp,qq)));
    }
    if(a.b != orig.b){
    	int pp = getmn.query(orig.b+1, a.b);
		int qq = getmx.query(orig.b+1, a.b);
		

		mn.insert(pp);
		mx.insert(qq);
    	M.insert(mp(mp(orig.b+1, a.b), mp(pp,qq)));
    }
    return ret+a.sc-a.fi+1;
}
void solve(){
	cin>>n>>q;
	m = n-1;
	init();
	map<int,vc<P>>MM;
	rep(i,m){
		int a,b,c;cin>>a>>b>>c;
		MM[c].pb(mp(a,b));
	}
	repn(i,n)zan[i]=i;
	repn(i,n)cs[i]=-1;
	nxt = n+1;
	for(auto mm:MM){
		auto x = mm.b;
		vc<int>cmp;
		map<int, int>M;
		for(auto a:x){
			int u = a.a;
			int v = a.b;
			if(same(u,v)) continue;
			
			cmp.pb(zan[find(u)]);
			M[cmp.back()] = u;
			cmp.pb(zan[find(v)]);
			M[cmp.back()] = v;
		}
		SORT(cmp); ERASE(cmp);
		for(auto a:x){
			int u = a.a;
			int v = a.b;
			unite(u, v);
		}
		vc<int>par;
		for(auto a:x){
			int u = a.a;
			int v = a.b;
			par.pb(zan[find(u)]);
			M[par.back()] = u;
		}
		SORT(par); ERASE(par);
		
		for(auto a:cmp){
			int k = M[a];
			k = zan[find(k)];
			edge[k].pb(a);
			cs[k] = mm.a;
		}
	}
	
	root = nxt-1;
	kaede.prepare();
	
	repn(i,n){
		getmn.update(i, in[i], true);
		getmx.update(i, in[i], true);
	}
	

	while(q--){
		int ty; cin >> ty;
		assert(mn.size()==mx.size());
		if(ty == 1){
			int l, r; cin >> l >> r;
			ini(mp(l,r));
		}
		else if(ty == 2){
			int l, r; cin >> l >> r;
			outi(mp(l,r));
		}
		else{
			int v; cin >> v;
			if(mn.empty()){
				o(-1);
			}
			else{
				
				int p = rev[*mn.begin()];
				int q = rev[*mx.begin()];
				p = cs[kaede.get(p, v)];
				q = cs[kaede.get(q, v)];
				o(max(p,q));
			}
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; 

	while(t--) solve();
}