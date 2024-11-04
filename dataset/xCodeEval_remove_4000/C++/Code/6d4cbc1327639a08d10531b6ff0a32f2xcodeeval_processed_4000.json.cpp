





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
bool id3(int i){
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































template<class N>
struct id0{
	struct node{
		

		

		

		N d;
		bool rev;
		int c[3],p;
		node(char tt=-1):rev(false),c{-1,-1,-1},p(-1){d.t=tt;}
		void show(){
			cerr<<int(d.t)<<" "<<"("<<c[0]<<","<<c[1]<<","<<c[2]<<") "<<p<<endl;
		}
	};
	using np=node*;
	int n;
	vc<node> x;
	

	vi unused;
	id0(int nn):n(nn),x(n*2-1){
		gnr(i,n,n*2-1)unused.pb(i);
	}
	

	

	inline void reverse(int v){
		assert(v!=-1);
		assert(x[v].d.t<2);
		x[v].rev^=1;
		x[v].d.reverse();
		swap(x[v].c[0],x[v].c[1]);
	}
	

	

	inline void set_child(int v,int k,int c){
		assert(v!=-1);
		assert(inc(0,k,2));
		x[v].c[k]=c;
		if(c!=-1)x[c].p=v;
	}
	inline void set_light_left(int v,int c){set_child(v,0,c);}
	inline void set_light_right(int v,int c){set_child(v,2,c);}
	inline void set_path_left(int v,int c){set_child(v,0,c);}
	inline void set_path_right(int v,int c){set_child(v,1,c);}
	

	

	inline void insert_light(int v,int c){
		assert(v!=-1);
		assert(x[v].d.t==0);
		assert(c!=-1);
		assert(x[c].d.t==2);
		set_light_right(c,x[v].c[2]);
		x[v].c[2]=c;
		x[c].p=v;
	}
	inline void make_path_vertex(int v){assert(inc(0,v,n-1));x[v].d.t=0;}
	inline void make_path_edge(int v){assert(inc(n,v,n*2-2));x[v].d.t=1;}
	inline void make_light(int v){assert(inc(n,v,n*2-2));assert(!x[v].rev);x[v].d.t=2;}
	void update(int v){
		assert(v!=-1);
		assert(!x[v].rev);
		x[v].d.single();
		if(x[v].d.t<2){
			if(x[v].c[2]!=-1)x[v].d.update_light(x[x[v].c[2]].d);
			rep(k,2)if(x[v].c[k]!=-1)x[v].d.update_path(k,x[x[v].c[k]].d);
		}else if(x[v].d.t==2){
			assert(x[v].c[1]!=-1);
			x[v].d.update_path(1,x[x[v].c[1]].d);
			for(int k=0;k<3;k+=2)if(x[v].c[k]!=-1)x[v].d.update_light(x[x[v].c[k]].d);
		}else{
			assert(false);
		}
	}
	void downdate(int v){
		assert(v!=-1);
		if(x[v].d.t<2){
			if(x[v].rev){
				x[v].rev=false;
				rep(k,2)if(x[v].c[k]!=-1)reverse(x[v].c[k]);
			}
			if(x[v].c[2]!=-1)x[v].d.push_light(x[x[v].c[2]].d);
			rep(k,2)if(x[v].c[k]!=-1)x[v].d.push_path(k,x[x[v].c[k]].d);
		}else if(x[v].d.t==2){
			assert(!x[v].rev);
			assert(x[v].c[1]!=-1);
			x[v].d.push_path(1,x[x[v].c[1]].d);
			for(int k=0;k<3;k+=2)if(x[v].c[k]!=-1)x[v].d.push_light(x[x[v].c[k]].d);
		}else{
			assert(false);
		}
		x[v].d.clear_lazy();
	}
	

	void rotate(int v,int z){
		assert(v!=-1);
		int p=x[v].p,c;
		assert(p!=-1);
		if(x[p].c[0]==v){
			c=x[v].c[z];
			x[v].c[z]=p;
			x[p].c[0]=c;
		}else{
			c=x[v].c[0];
			x[v].c[0]=p;
			x[p].c[z]=c;
		}
		if(c!=-1)x[c].p=p;
		x[v].p=x[p].p;
		x[p].p=v;
		if(x[v].p!=-1){
			rep(k,3)if(x[x[v].p].c[k]==p)
				x[x[v].p].c[k]=v;
		}
		update(p);
		

		

	}
	

	

	

	

	void prepare(int v){
		assert(v!=-1);
		if(x[v].p!=-1)prepare(x[v].p);
		downdate(v);
	}
	

	

	

	void splay(int v){
		assert(v!=-1);
		int z=x[v].d.t<2?1:2;
		while(1){
			int p=x[v].p;
			if(p==-1||(x[p].d.t<2)^(x[v].d.t<2))break;
			int q=x[p].p;
			if(q==-1||(x[q].d.t<2)^(x[v].d.t<2)){
				rotate(v,z);
			}else{
				if((x[p].c[0]==v&&x[q].c[0]==p)||(x[p].c[z]==v&&x[q].c[z]==p))
					rotate(p,z);
				else
					rotate(v,z);
				rotate(v,z);
			}
		}
		update(v);
	}
	int go_deep(int v,int k){
		assert(v!=-1);
		while(1){
			downdate(v);
			if(x[v].c[k]!=-1)v=x[v].c[k];
			else return v;
		}
		assert(false);
	}
	void expose(int v){
		assert(v!=-1);
		prepare(v);
		for(int a=v;a!=-1;a=x[a].p)
			splay(a);
		for(int a=v;a!=-1;a=x[a].p){
			if(x[a].d.t==2){
				int b=x[a].p;
				assert(b!=-1);
				if(x[b].c[1]==-1){
					int l=x[a].c[0],r=x[a].c[2];
					if(l!=-1){
						x[l].p=-1;
						l=go_deep(l,2);
						splay(l);
						set_light_right(l,r);
						update(l);
					}else{
						l=r;
					}
					set_light_right(b,l);
				}else{
					int c=x[b].c[1];
					x[c].p=-1;
					c=go_deep(c,0);
					splay(c);
					assert(!x[c].rev);
					make_light(c);
					set_light_left(c,x[a].c[0]);
					set_light_right(c,x[a].c[2]);
					set_light_right(b,c);
					

					update(c);
					

				}
				x[a].c[0]=x[a].c[2]=-1;
				make_path_edge(a);
				set_path_right(b,a);
			}
		}
		

		

		splay(v);
		

		

	}
	template<class...Args>
	void init_vertex(int v,Args&&...args){
		assert(inc(0,v,n-1));
		x[v]=node(0);
		x[v].d.init_vertex(v,forward<Args>(args)...);
	}
	template<class...Args>
	void init_edge(int v,char t,int a,int b,Args&&...args){
		x[v]=node(t);
		x[v].d.init_edge(a,b,forward<Args>(args)...);
	}
	void evert(int v){
		assert(inc(0,v,n-1));
		assert(x[v].d.t==0);
		expose(v);
		if(x[v].c[0]!=-1){
			int c=x[v].c[0];
			x[v].c[0]=-1;
			x[c].p=-1;
			c=go_deep(c,1);
			splay(c);
			reverse(c);
			assert(x[c].rev);
			x[c].rev=false;
			reverse(x[c].c[1]);
			make_light(c);
			insert_light(v,c);
			

			update(c);
			update(v);
			

		}
	}
	

	

	template<class...Args>
	int link(int a,int b,Args&&...args){
		assert(inc(0,a,n-1));
		assert(inc(0,b,n-1));
		if(a==b)return -1;
		expose(a);
		evert(b);
		if(x[a].p==-1){
			assert(si(unused));
			int e=unused.back();unused.pop_back();
			init_edge(e,2,a,b,forward<Args>(args)...);
			set_path_right(e,b);
			insert_light(a,e);
			

			update(e);
			update(a);
			

			return e;
		}else{
			return -1;
		}
	}
	

	

	pi cut(int e){
		assert(inc(n,e,n*2-2));
		expose(e);
		pi res(x[e].c[0],x[e].c[1]);
		if(res.a!=-1)x[res.a].p=-1;
		if(res.b!=-1)x[res.b].p=-1;
		x[e].d.t=-1;
		unused.pb(e);
		return res;
	}
	int lca(int a,int b){
		assert(inc(0,a,n-1));
		assert(inc(0,b,n-1));
		if(a==b)return a;
		expose(a);
		expose(b);
		if(x[a].p==-1)return -1;
		int d=a;
		while(a!=b){
			int p=x[a].p;
			if(x[a].d.t==2&&x[p].d.t<2)d=p;
			else if(p==b&&x[p].c[1]==a)d=b;
			a=p;
		}
		assert(inc(0,d,n-1));
		return d;
	}
	int same(int a,int b){
		assert(inc(0,a,n-1));
		assert(inc(0,b,n-1));
		if(a==b)return true;
		expose(a);
		expose(b);
		return x[a].p!=-1;
	}
	void expose_path(int a,int b){
		assert(inc(0,a,n-1));
		assert(inc(0,b,n-1));
		evert(a);
		expose(b);
		int c=x[b].c[1];
		if(c!=-1){
			x[b].c[1]=-1;
			x[c].p=-1;
			c=go_deep(c,0);
			splay(c);
			assert(!x[c].rev);
			make_light(c);
			insert_light(b,c);
			update(c);
			update(b);
		}
	}
	

	template<class F,class... Args>
	void id2(int r,int v,F f,Args&&... args){
		assert(inc(0,r,n-1));
		assert(inc(0,v,n-1));
		evert(r);
		expose(v);
		int tmp=-1;
		assert(!x[v].rev);
		swap(x[v].c[0],tmp);
		(x[v].d.*f)(forward<Args>(args)...);
		downdate(v);
		swap(x[v].c[0],tmp);
		update(v);
	}
	

	template<class F,class... Args>
	void path_update(int a,int b,F f,Args&&... args){
		expose_path(a,b);
		(x[b].d.*f)(forward<Args>(args)...);
	}
	N&operator[](int i){return x[i].d;}
	void show(){
		rep(i,n*2-1)if(x[i].d.t!=-1){
			cerr<<i<<" ";
			x[i].show();
		}
	}
	

	

	template<class H> void id1(const H&hld){
		unused.clear();
		auto subtree=[&](auto id4,int root)->int{
			auto path=[&](auto path_self,int l,int r)->int{
				if(r<l)return -1;
				const int m=(l+r)/2;
				int v=hld.ni[(m+1)/2],z;
				if(m%2==0){
					z=v;
					auto light=[&](auto light_self,int a,int b)->int{
						if(b<a)return -1;
						const int c=(a+b)/2;
						int u=hld.g[v][c],w=hld.pe[u].idx+n;
						init_edge(w,2,v,u,hld.pe[u]);
						set_path_right(w,id4(id4,u));
						set_light_left(w,light_self(light_self,a,c-1));
						set_light_right(w,light_self(light_self,c+1,b));
						update(w);
						return w;
					};
					set_light_right(z,light(light,1,si(hld.g[v])-1));
				}else{
					z=hld.pe[v].idx+n;
					init_edge(z,1,hld.par[v],v,hld.pe[v]);
				}
				set_path_left(z,path_self(path_self,l,m-1));
				set_path_right(z,path_self(path_self,m+1,r));
				update(z);
				return z;
			};
			return path(path,hld.in[root]*2,(hld.in[root]+hld.hei[root]-1)*2);
		};
		subtree(subtree,hld.rt);
	}
};









































































struct N{
	char t;
	int rw,mx;
	pi z[2];
	void init_vertex(int,int val){
		rw=val;
		single();
	}
	void init_edge(int,int,int cap){
		rw=cap;
		single();
	}
	void single(){
		if(t==0){
			mx=-1;
			z[0]=z[1]=pi(rw,0);
		}
		else{
			mx=rw;
			z[0]=z[1]=pi(-1,0);
		}
	}
	void reverse(){
		swap(z[0],z[1]);
	}
	void update_path(int dir,const N&x_){
		N x[2]{x_,*this};
		if(dir)swap(x[0],x[1]);
		mx=max(x[0].mx,x[1].mx);
		rep(k,2)z[k]=max(x[k].z[k],pi(x[k^1].z[k].a,max(x[k^1].z[k].b,x[k].mx)));
	}
	void update_light(const N&x){
		chmax(z[0],x.z[0]);
		chmax(z[1],pi(x.z[0].a,max(x.z[0].b,mx)));
	}
	void push_path(int,N&){}
	void push_light(N&){}
	void clear_lazy(){}
};

void slv(){
	int n,q;cin>>n>>q;
	vi e=readvi(n);
	struct E{
		int a,b,c,t;
		void readinit(){
			cin>>a>>b>>c>>t;
			a--;b--;
		}
		bool operator<(const E&rhs)const{return c>rhs.c;}
	};
	vc<E> es(n-1);
	rep(i,n-1)es[i].readinit();
	sort(all(es));
	struct Q{
		int v,x,i;
		void readinit(){
			cin>>v>>x;
			x--;
		}
		bool operator<(const Q&rhs)const{return v>rhs.v;}
	};
	vc<Q> qs(q);
	rep(i,q){
		qs[i].readinit();
		qs[i].i=i;
	}
	sort(all(qs));
	
	id0<N> t(n);
	rep(i,n)t.init_vertex(i,e[i]);
	vc<pi> ans(q);
	int head=0;
	for(auto w:qs){
		while(head<n-1&&es[head].c>=w.v){
			t.link(es[head].a,es[head].b,es[head].t);
			head++;
		}
		t.evert(w.x);
		ans[w.i]=t[w.x].z[0];
	}
	rep(i,q)print(ans[i]);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	

	slv();
}
