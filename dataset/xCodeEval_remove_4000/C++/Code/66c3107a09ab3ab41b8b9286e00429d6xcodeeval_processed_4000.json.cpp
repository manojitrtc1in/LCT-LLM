



using namespace std;

using ll=long long;





















template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}






void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}





using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}



void yes(bool ex=true){
	
	cout<<"YES"<<"\n";
	
	cout<<"Yes"<<"\n";
	
	if(ex)exit(0);
	
	cout.flush();
	
}
void no(bool ex=true){
	
	cout<<"NO"<<"\n";
	
	cout<<"No"<<"\n";
	
	if(ex)exit(0);
	
	cout.flush();
	
}
void possible(bool ex=true){
	
	cout<<"POSSIBLE"<<"\n";
	
	cout<<"Possible"<<"\n";
	
	if(ex)exit(0);
	
	cout.flush();
	
}
void impossible(bool ex=true){
	
	cout<<"IMPOSSIBLE"<<"\n";
	
	cout<<"Impossible"<<"\n";
	
	if(ex)exit(0);
	
	cout.flush();
	
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;


const int inf=infLL;

const int inf=INT_MAX/2-100;


int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool id2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { 

	
	static mt19937_64 gen;
	
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		

		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

using int128=__int128_t;
using uint128=unsigned __int128_t;



istream& operator>>(istream&is,int128&res){
	res=0;
	string s;is>>s;
	int head=0;
	int128 w=1;
	if(s[0]=='_'){
		w=-1;
		head++;
	}
	while(head<si(s)){
		res=res*10+s[head++]-'0';
	}
	res*=w;
	return is;
}
ostream& operator<<(ostream&os,int128 i){
	if(i==0)
		return os<<0;
	static char buf[100];
	if(i<0){
		os<<"-";
		i=-i;
	}
	int p=0;
	while(i){
		buf[p++]='0'+i%10;
		i/=10;
	}
	reverse(buf,buf+p);
	buf[p]=0;
	return os<<buf;
}
int128 abs128(int128 a){
	return a<0?-a:a;
}
int botbit(int128 a){
	const int128 m=(int128(1)<<64)-1;
	if(a&m)return __builtin_ctzll(ll(a));
	else return __builtin_ctzll(ll(a>>64));
}
int128 gcd(int128 a,int128 b){
	if(a<0)a=-a;
	if(b<0)b=-b;
	if(a==0)return b;
	if(b==0)return a;
	int128 s=botbit(a|b);
	a>>=botbit(a);
	do{
		b>>=botbit(b);
		if(a>b)swap(a,b);
		b-=a;
	}while(b);
	return a<<s;
}
const int128 inf128=int128(1)<<122;













template<class d>
struct maxflow{
	struct E{
		int to,nx;
		d cap;
	};
	vc<E> es;
	vi head,q;
	vc<pi> itr,lv;
	int curt;
	maxflow(int n):head(n,-1),q(n),itr(n),lv(n),curt(0){}
	int ae(int s,int t,d c,d c2=0){
		int pres=head[s];
		int pret=head[t];
		head[s]=si(es);
		es.pb({t,pres,c});
		head[t]=si(es);
		es.pb({s,pret,c2});
		return head[s];
	}
	void bfs(int s,int t=-1){
		lv[s]=pi(0,curt);
		int l=0,r=0;
		q[r++]=s;
		while(l<r){
			int v=q[l++];
			for(int id=head[v];id!=-1;id=es[id].nx){
				auto e=es[id];
				if(e.cap>0&&lv[e.to].b<curt){
					lv[e.to]=pi(lv[v].a+1,curt);
					q[r++]=e.to;
					if(e.to==t)return;
				}
			}
		}
	}
	d dfs(int v,int t,d f){
		if(v==t)return f;
		if(itr[v].b<curt)itr[v]=pi(head[v],curt);
		d res=0;
		while(itr[v].a!=-1){
			E& e=es[itr[v].a];
			E& rev=es[itr[v].a^1];
			if(rev.cap>0&&lv[e.to].a==lv[v].a-1&&lv[e.to].b==curt){
				d a=dfs(e.to,t,min(f,rev.cap));
				if(a>0){
					rev.cap-=a;
					e.cap+=a;
					res+=a;
					f-=a;
					if(f<=0)break;
				}
			}
			itr[v].a=e.nx;
		}
		return res;
	}
	d calc(int s,int t,d mx=inf){
		d f=0;
		while(f<mx){
			curt++;
			bfs(s,t);
			if(lv[t].b<curt)
				return f;
			f+=dfs(t,s,mx-f);
		}
		return f;
	}
};





















template<class captype,class costtype,class anstype>
struct id0{
	struct E{
		int to,rev;
		captype cap;
		costtype cost;
	};
	int n;
	costtype eps;
	vvc<E> g;
	vc<pi> idx;
	vi itr,q;
	vc<bool> inq;
	vc<captype> fl,off;
	vc<costtype> p;
	maxflow<captype> mf;
	anstype ans;
	id0(int nn):n(nn),g(n),itr(n),inq(n),fl(n),p(n),mf(n+2),ans(0){}
	void ae(int s,int t,captype l,captype r,costtype c){
		assert(l<=r);
		
		if(s==t){
			idx.eb(-1,-1);
			captype f=c>0?l:r;
			ans+=anstype(c)*f;
			off.pb(f);
		}else{
			c*=(n+1);
			idx.eb(s,si(g[s]));
			off.pb(r);
			fl[s]-=l;
			fl[t]+=l;
			g[s].pb({t,si(g[t]),r-l,c});
			g[t].pb({s,si(g[s])-1,0,-c});
		}
		
		mf.ae(s,t,r-l);
	}
	void add_excess(int v,captype c){
		fl[v]+=c;
	}
	void add_demand(int v,captype c){
		fl[v]-=c;
	}
	costtype getcost(int v,const E&e){
		return e.cost-p[e.to]+p[v];
	}
	void addq(int v){
		if(fl[v]>0&&!inq[v]){
			q.pb(v);
			inq[v]=true;
		}
	}
	void push(int v,E&e,captype a){
		int to=e.to,j=e.rev;
		assert(0<=a);
		assert(a<=e.cap);
		e.cap-=a;
		g[to][j].cap+=a;
		fl[v]-=a;
		fl[to]+=a;
		addq(to);
	}
	void relabel(int v){
		p[v]=numeric_limits<costtype>::min();
		for(const auto&e:g[v]){
			if(e.cap>0){
				chmax(p[v],-eps-e.cost+p[e.to]);
			}
		}
		itr[v]=0;
	}
	bool slv(){
		int m=si(idx);
		{
			if(accumulate(all(fl),captype(0))){
				

				return false;
			}
			captype f=0;
			rep(i,n)if(fl[i]>0){
				f+=fl[i];
				mf.ae(n,i,fl[i]);
			}else if(fl[i]<0){
				mf.ae(i,n+1,-fl[i]);
			}
			captype did=mf.calc(n,n+1,f);
			if(did<f)return false;
			rep(k,m)if(idx[k].a!=-1){
				auto&e=g[idx[k].a][idx[k].b];
				e.cap=mf.es[k*2].cap;
				g[e.to][e.rev].cap=mf.es[k*2+1].cap;
			}
			rep(i,n)fl[i]=0;
		}
		while(1){
			

			rep(i,n)assert(fl[i]==0);
			eps=0;
			rep(v,n)for(const auto&e:g[v])if(e.cap>0)chmax(eps,-getcost(v,e));
			if(eps<=1)break;
			
			eps=max(eps/8,costtype(1));
			
			bool need=true;
			rep(_,5){
				bool upd=false;
				rep(v,n)for(const auto&e:g[v])if(e.cap>0){
					if(chmin(p[e.to],p[v]+e.cost+eps))
						upd=true;
				}
				if(!upd){
					need=false;
					break;
				}
			}
			if(!need)continue;
			
			rep(v,n)for(auto&e:g[v])if(getcost(v,e)<0)
				push(v,e,e.cap);
			
			q.clear();
			rep(i,n){
				itr[i]=0;
				inq[i]=false;
			}
			int qb=0;
			rep(i,n)addq(i);
			while(qb<si(q)){
				int v=q[qb++];
				inq[v]=false;
				while(fl[v]>0){
					if(itr[v]==si(g[v]))
						relabel(v);
					while(itr[v]<si(g[v])){
						auto&e=g[v][itr[v]];
						if(e.cap&&getcost(v,e)<0){
							push(v,e,min(e.cap,fl[v]));
							if(fl[v]==0)break;
						}
						itr[v]++;
					}
				}
			}
		}
		rep(i,n)assert(fl[i]==0);
		rep(v,n)for(const auto&e:g[v])if(e.cap>0)assert(getcost(v,e)>=-1);
		
		rep(v,n)for(auto&e:g[v])e.cost/=(n+1);
		return true;
	}
	pair<anstype,vc<captype>> get_solution(){
		rep(i,si(off))if(idx[i].a!=-1){
			const auto&e=g[idx[i].a][idx[i].b];
			off[i]-=e.cap;
			ans+=anstype(e.cost)*off[i];
		}
		return mp(ans,off);
	}
	vc<costtype> get_potential(){
		rep(i,n)p[i]/=(n+1);
		rep(_,n+1){
			bool upd=false;
			rep(v,n)for(const auto&e:g[v])if(e.cap>0){
				if(chmin(p[e.to],p[v]+e.cost))
					upd=true;
			}
			if(!upd)break;
			assert(_<n);
		}
		return p;
	}
};

void test(){
	int n=100,m=100000;
	id0<ll,ll,int128> cs(n);
	rep(i,n)cs.add_excess(i,0);
	rep(i,m){
		int s,t,l,u,c;

		s=rand_int(0,n-1);
		t=rand_int(0,n-1);
		l=rand_int(-ten(9),ten(9));
		u=rand_int(-ten(9),ten(9));
		if(u<l)swap(l,u);
		c=rand_int(-ten(9),ten(9));
		cs.ae(s,t,l,u,c);
	}
	if(cs.slv()){
		int128 ans;
		vc<ll> f;
		tie(ans,f)=cs.get_solution();
		vc<ll> p=cs.get_potential();
		cout<<ans<<endl;
		print(p);
		print(f);
	}else{
		cout<<"infeasible"<<endl;
	}
}

void slv(){
	int n,m;cin>>n>>m;
	id0<ll,ll,int128> cs(n);
	rep(i,n)cs.add_excess(i,read());
	rep(i,m){
		int s,t,l,u,c;cin>>s>>t>>l>>u>>c;
		cs.ae(s,t,l,u,c);
	}
	if(cs.slv()){
		int128 ans;
		vc<ll> f;
		tie(ans,f)=cs.get_solution();
		vc<ll> p=cs.get_potential();
		cout<<ans<<endl;
		print(p);
		print(f);
	}else{
		cout<<"infeasible"<<endl;
	}
}






using Int = long long;



template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }

constexpr int id1 = 1001001001;



int N, M;
vector<Int> A;
vector<int> U, V;

int main() {
  for (; ~scanf("%d%d", &N, &M); ) {
    A.resize(N);
    for (int u = 0; u < N; ++u) {
      scanf("%lld", &A[u]);
    }
    U.resize(M);
    V.resize(M);
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &U[i], &V[i]);
      --U[i];
      --V[i];
    }
    
    id0<Int, Int, Int> mcf(N + 1);
    for (int u = 0; u < N; ++u) {
      mcf.ae(N, u, 0, 1, A[u]);
      mcf.ae(u, N, 0, 1, -A[u]);
    }
    for (int i = 0; i < M; ++i) {
      

      mcf.ae(V[i], U[i], 0, id1, 0);
    }
    assert(mcf.slv());
    const auto res = mcf.get_solution();
    const vector<Int> ps = mcf.get_potential();
cerr<<"res = "<<res<<endl;
cerr<<"ps = ";pv(ps.begin(),ps.end());
    
    for (int u = 0; u < N; ++u) {
      if (u > 0) printf(" ");
      printf("%lld", ps[u] - ps[N]);
    }
    puts("");

Int sol=0;
for(int u=0;u<N;++u)sol+=abs(ps[u]-ps[N]-A[u]);
cerr<<"sol = "<<sol<<endl;
for(int i=0;i<M;++i)assert(ps[U[i]]<=ps[V[i]]);

  }
  return 0;
}
