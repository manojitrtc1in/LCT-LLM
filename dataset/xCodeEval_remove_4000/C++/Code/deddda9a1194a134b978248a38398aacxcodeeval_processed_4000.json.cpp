





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

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class t,class u>
void print_offset(const pair<t,u>&p,ll off,int suc=1){
	print(p.a+off,2);
	print(p.b+off,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
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

void YES(bool ex=true){
	cout<<"YES\n";
	if(ex)exit(0);
	
	cout.flush();
	
}
void NO(bool ex=true){
	cout<<"NO\n";
	if(ex)exit(0);
	
	cout.flush();
	
}
void Yes(bool ex=true){
	cout<<"Yes\n";
	if(ex)exit(0);
	
	cout.flush();
	
}
void No(bool ex=true){
	cout<<"No\n";
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
int botbit(ull a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
int popcount(ull t){
	return __builtin_popcountll(t);
}
bool id1(int i){
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

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}







template<class N>
struct id2{
	vc<N> x;
	int s;
	id2(){}
	template<class t>
	id2(vc<t> a){
		int n=a.size();
		s=1;
		while(s<n){s*=2;}
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	

	id2(int n){
		resize(n);
	}
	void resize(int n){
		s=1;
		while(s<n){s*=2;}
		x.assign(s*2,N());
		gnr(i,1,s)
			x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	void set(int i,const N&t){
		i+=s;
		x[i]=t;
		while(i>>=1)x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	void point_merge(int i,const N&t){
		i+=s;
		x[i]=N::merge(x[i],t);
		while(i>>=1)x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	template<class F,class...Args>
	void point_change(int i,F f,Args&&...args){
		i+=s;
		(x[i].*f)(forward<Args>(args)...);
		while(i>>=1)x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	N composite(int b,int e){
		assert(b<=e);
		N lf,rt;
		for(int l=b+s,r=e+s;l<r;l>>=1,r>>=1){
			if (l&1){
				lf=N::merge(lf,x[l]);
				l++;
			}
			if (r&1){
				r--;
				rt=N::merge(x[r],rt);
			}
		}
		return N::merge(lf,rt);
	}
	N getall(){
		return x[1];
	}
	

	

	template <class F,class... Args> 
	pair<int,N> max_right(int l,F f,Args&&... args){
		assert(0<=l&&l<=s);
		if(l==s)return mp(s,N());
		l+=s;
		
		N sm;
		assert((sm.*f)(forward<Args>(args)...));
		do {
			while (l % 2 == 0) l >>= 1;
			if (!(N::merge(sm,x[l]).*f)(forward<Args>(args)...)){
				while (l < s) {
					l = (2 * l);
					N tmp=N::merge(sm,x[l]);
					if ((tmp.*f)(forward<Args>(args)...)) {
						sm = tmp;
						l++;
					}
				}
				return mp(l - s,sm);
			}
			sm = N::merge(sm, x[l]);
			l++;
		} while ((l & -l) != l);
		return mp(s,sm);
	}
	

	template <class F,class... Args> 
	pair<int,N> min_left(int r,F f,Args&&... args){
		assert((N().*f)(forward<Args>(args)...));
		assert(0<=r&&r<=s);
        if(r==0)return mp(0,N());
        r+=s;
        N sm;
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!(N::merge(x[r],sm).*f)(forward<Args>(args)...)) {
                while (r < s) {
                    r = (2 * r + 1);
                    N tmp=N::merge(x[r],sm);
                    if ((tmp.*f)(forward<Args>(args)...)) {
                        sm = tmp;
                        r--;
                    }
                }
                return mp(r + 1 - s,sm);
            }
            sm = N::merge(x[r], sm);
        } while ((r & -r) != r);
        return mp(0,sm);
    }
    

    

	template<class F,class T>
	T accumulate(int l, int r,F f,T t) {
		assert(0<=l&&l<=r&&r<=s);
		if (l == r) return t;

		l+=s;
		r+=s;

		static int buf[2][30];
		int cnt[2]{};
		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1){
					

					buf[0][cnt[0]++]=l++;
				}
				if (r & 1){
					

					buf[1][cnt[1]++]=--r;
				}
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}
		rep(i,cnt[0])t=(x[buf[0][i]].*f)(t);
		per(i,cnt[1])t=(x[buf[1][i]].*f)(t);

		return t;
	}
};




















template<class E>
struct HLD{
	vvc<E> g;
	int n,rt,cnt;
	vi sub,in,out,par,head,dep,hei,ni;
	vc<E> pe;
	int dfs1(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		for(auto itr=g[v].bg;itr!=g[v].ed;itr++)
			if(*itr==p){
				pe[v]=*itr;
				g[v].erase(itr);
				break;
			}
		for(auto&e:g[v]){
			pe[e]=e;
			sub[v]+=dfs1(e,v,d+1);
			if(sub[g[v][0]]<sub[e])
				swap(g[v][0],e);
		}
		return sub[v];
	}
	void dfs2(int v,int h){
		in[v]=cnt++;
		head[v]=h;
		for(int to:g[v])
			dfs2(to,to==g[v][0]?h:to);
		out[v]=cnt;
		if(si(g[v]))hei[v]=hei[g[v][0]]+1;
	}
	HLD(){}
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),rt(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n),hei(n,1),ni(n),
		pe(n){
		dfs1(rt,-1,0);
		dfs2(rt,rt);
		rep(i,n)ni[in[i]]=i;
	}
	int lca(int a,int b){
		while(head[a]!=head[b]){
			if(dep[head[a]]>dep[head[b]])
				swap(a,b);
			b=par[head[b]];
		}
		if(dep[a]>dep[b])
			swap(a,b);
		return a;
	}
	int len(int a,int b){
		return dep[a]+dep[b]-dep[lca(a,b)]*2;
	}
	bool asde(int a,int b){
		return in[a]<=in[b]&&out[b]<=out[a];
	}
	

	int getpar(int v,int len){
		assert(dep[v]>=len);
		int tar=dep[v]-len;
		while(1){
			int h=head[v];
			if(dep[h]<=tar){
				return ni[in[h]+(tar-dep[h])];
			}
			v=par[h];
		}
		assert(false);
	}
	

	

	

	

	vi index;
	

	

	

	

	

	

	

	pair<vi,vc<pi>> tree_compress(vi vs){
		if(si(index)==0)index.resize(n);
		assert(index.size());
		auto comp = [&](int x,int y){
			return in[x] < in[y];
		};
		sort(all(vs),comp);
		vs.erase(unique(all(vs)),vs.ed);
		int k = vs.size();
		rep(i,k-1){
			vs.pb(lca(vs[i],vs[i+1]));
		}
		sort(all(vs),comp);
		vs.erase(unique(all(vs)),vs.ed);
		k = vs.size();
		rep(i,k) index[vs[i]] = i;
		vc<pi> es;
		rng(i,1,k){
			int p = lca(vs[i-1],vs[i]);
			es.eb(i,index[p]);
		}
		return mp(vs,es);
	}
	

	

	template<class F>
	void id0(int a,int b,bool ex,F f){
		while(1){
			if(head[a]==head[b]){
				f(in[b]+ex,in[a]+1);
				break;
			}else{
				int h=head[a];
				f(in[h],in[a]+1);
				a=par[h];
			}
		}
	}
	

	

	

	

	template<class F>
	void path_work(int a,int b,bool ex,F f){
		int c=lca(a,b);
		id0(a,c,ex,f);
		id0(b,c,true,f);
	}
};

struct E{
	int to,idx;
	operator int()const{
		return to;
	}
};

struct N{
	bool e;
	int a,s,x,t,y;
	N():e(true){}
	N(int p,int q):e(false){
		a=p,s=q,x=q;
		t=p,y=p;
	}
	pi unko(int v)const{
		return e?pi(0,-1):(a==v?pi(s,x):pi(t,y));
	}
	static N merge(const N&r,const N&l){
		if(l.e)return r;
		if(r.e)return l;
		N res=l;
		pi w=r.unko(l.x);
		res.s+=w.a;
		res.x=w.b;
		w=r.unko(l.y);
		res.t+=w.a;
		res.y=w.b;
		return res;
	}
	int getsum(){
		return e?y:0;
	}
};

const int nmax=300010;
int cnt[nmax][100];

void slv(){
	int n;cin>>n;n++;
	vvc<int> t(n);
	rng(i,1,n)t[read()-1].pb(i);
	HLD<int> hld(t,0);
	vc<N> ini(n);
	ini[0]=N(0,1);
	id2<N> seg(ini);
	int ans=0;
	auto gettop=[&](int h){
		int l=hld.in[h],r=l+hld.hei[h];
		return seg.composite(l,r).unko(inf);
	};
	rng(tmp,1,n){
		int v=tmp;
		while(v>=0){
			int h=hld.head[v];
			int p=hld.par[h];
			{
				auto [sum,x]=gettop(h);
				ans-=sum;
				if(x!=-1&&p!=-1)cnt[p][x]--;
			}
			int a=-1,b=-1;
			rep(j,100)if(cnt[v][j]==0){
				if(a==-1)a=j;
				else{b=j;break;}
			}
			assert(b!=-1);
			seg.set(hld.in[v],N(a,b));
			auto [sum,x]=gettop(h);
			ans+=sum;
			if(x!=-1&&p!=-1)cnt[p][x]++;
			v=p;
		}
		print(ans);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	

	slv();
}
