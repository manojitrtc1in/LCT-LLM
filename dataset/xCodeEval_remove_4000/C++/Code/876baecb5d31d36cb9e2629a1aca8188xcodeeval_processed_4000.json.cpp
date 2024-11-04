





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
struct segbeats{
	vc<N> x;
	int s;
	segbeats(){}
	template<class T>
	segbeats(const vc<T>& a){
		int n=a.size();
		s=1;
		while(s<n)s*=2;
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			upd(i);
	}
	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	void upd(int i){
		x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	template<class F,class... Args>
	void chr(int l,int r,int i,int b,int e,F f,Args&&... args){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e&&(x[i].*f)(forward<Args>(args)...))
			return;
		push(i);
		int m=(l+r)/2;
		chr(l,m,i*2,b,e,f,forward<Args>(args)...);
		chr(m,r,i*2+1,b,e,f,forward<Args>(args)...);
		upd(i);
	}
	template<class F,class... Args>
	void ch(int b,int e,F f,Args&&... args){
		assert(b<=e);
		chr(0,s,1,b,e,f,forward<Args>(args)...);
	}
	

	template<class F,class G,class H>
	auto getr(int l,int r,int i,int b,int e,F f,G g,H h){
		if(e<=l||r<=b)
			return h;
		if(b<=l&&r<=e)
			return (x[i].*f)();
		push(i);
		int m=(l+r)/2;
		return g(getr(l,m,i*2,b,e,f,g,h),getr(m,r,i*2+1,b,e,f,g,h));
	}
	template<class F,class G,class H>
	auto get(int b,int e,F f,G g,H h){
		assert(b<=e);
		return getr(0,s,1,b,e,f,g,h);
	}
	auto compositer(int l,int r,int i,int b,int e){
		if(e<=l||r<=b)assert(0);
		if(b<=l&&r<=e)
			return x[i];
		push(i);
		int m=(l+r)/2;
		if(e<=m)return compositer(l,m,i*2,b,e);
		if(m<=b)return compositer(m,r,i*2+1,b,e);
		return N::merge(compositer(l,m,i*2,b,e),compositer(m,r,i*2+1,b,e));
	}
	

	auto composite(int b,int e){
		assert(b<e);
		return compositer(0,s,1,b,e);
	}
	N getall(){return x[1];}
	

	template<class F,class...Args>
	pair<int,N> id2(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {e,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {e,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=id2(i*2,l,m,b,e,f,forward<Args>(args)...);
		if(a.a<e)return a;
		return id2(i*2+1,m,r,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> findmin(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return id2(1,0,s,b,e,f,forward<Args>(args)...);
	}
	

	template<class F,class...Args>
	pair<int,N> id0(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {b-1,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {b-1,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=id0(i*2+1,m,r,b,e,f,forward<Args>(args)...);
		if(a.a>=b)return a;
		return id0(i*2,l,m,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> findmax(int b,int e,F f,Args&&...args){
		assert(b<=e);
		return id0(1,0,s,b,e,f,forward<Args>(args)...);
	}
	void enumerater(int l,int r,int i,int b,int e,vc<N>&dst){
		if(e<=l||r<=b)
			return;
		if(l+1==r){
			dst.pb(x[i]);
			return;
		}
		push(i);
		int m=(l+r)/2;
		enumerater(l,m,i*2,b,e,dst);
		enumerater(m,r,i*2+1,b,e,dst);
	}
	void enumerate(int b,int e,vc<N>&dst){
		assert(b<=e);
		return enumerater(0,s,1,b,e,dst);
	}
	
	

	template<class F,class...Args>
	void id1(int l,int r,int i,int b,int e,vc<pair<int,N>>&dst,F f,Args&&...args){
		if(e<=l||r<=b||!(x[i].*f)(forward<Args>(args)...))
			return;
		if(l+1==r){
			dst.eb(l,x[i]);
			return;
		}
		push(i);
		int m=(l+r)/2;
		id1(l,m,i*2,b,e,dst,f,forward<Args>(args)...);
		id1(m,r,i*2+1,b,e,dst,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	void id4(int b,int e,vc<pair<int,N>>&dst,F f,Args&&...args){
		assert(b<=e);
		id1(0,s,1,b,e,dst,f,forward<Args>(args)...);
	}
	void prepare(int i){
		if(i/=2){
			prepare(i);
			push(i);
		}
	}
	

	void point_set(int i,N w){
		i+=s;
		prepare(i);
		x[i]=w;
		while(i/=2)
			upd(i);
	}
	template<class F,class...Args>
	void point_change(int i,F f,Args&&...args){
		i+=s;
		prepare(i);
		(x[i].*f)(forward<Args>(args)...);
		while(i/=2)
			upd(i);
	}
	

	N point_get(int i){
		i+=s;
		prepare(i);
		return x[i];
	}
};








struct N{
	ull mx,cnt,sec,sum,lz;
	N(ull v=0):mx(v),cnt(1),sec(0),sum(v),lz(-1){}
	bool setlim(ull v){
		if(mx<=v){
			chmin(lz,v);
			return true;
		}
		if(sec<v){
			chmin(lz,v);
			sum-=(mx-v)*cnt;
			mx=v;
			return true;
		}
		return false;
	}
	void push(N&x,N&y){
		bool tmp=x.setlim(lz);
		assert(tmp);
		tmp=y.setlim(lz);
		assert(tmp);
		lz=-1;
	}
	static N merge(N x,N y){
		N res;
		res.mx=max(x.mx,y.mx);
		res.sec=max(x.sec,y.sec);
		res.cnt=0;
		if(res.mx==x.mx)res.cnt+=x.cnt;
		else chmax(res.sec,x.mx);
		if(res.mx==y.mx)res.cnt+=y.cnt;
		else chmax(res.sec,y.mx);
		res.sum=x.sum+y.sum;
		return res;
	}
};

template<class E,class D=ll>
pair<vc<D>,vi> dijkstra(const vvc<E>& g,int s){
	const int n=g.size();
	using P=pair<D,int>;
	priority_queue<P,vc<P>,greater<P>> pq;
	vc<D> dist(n,infLL);
	vi from(n,-1);
	const auto ar=[&](int v,D d,int f){
		if(dist[v]>d){
			dist[v]=d;
			pq.emplace(d,v);
			from[v]=f;
		}
	};
	ar(s,0,-1);
	while(pq.size()){
		D d;
		int v;
		tie(d,v)=pq.top();pq.pop();
		if(dist[v]!=d)continue;
		for(auto e:g[v])
			ar(e.to,d+e.cost,v);
	}
	return mp(dist,from);
}

struct E{
	int to,cost;
	operator int()const{return to;}
};

void slv(){
	int n,m,q;cin>>n>>m>>q;
	vi w=readvi(n);
	vvc<E> g(n);
	rep(_,m){
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		g[a].pb({b,c});
		g[b].pb({a,c});
	}
	vi dist=dijkstra(g,0).a;
	vc<pi> qs(q);
	rep(i,q){
		qs[i]=readpi();
		qs[i].a--;
		w[qs[i].a]+=qs[i].b;
	}
	vi ls,cnt(n),idx(n);iota(all(idx),0);
	sort(all(idx),[&](int i,int j){return dist[i]<dist[j];});
	vi pos(n);
	rep(i,n)pos[idx[i]]=i;
	rep(i,n){
		for(auto e:g[i]){
			if(dist[e.to]==dist[i]+e.cost){
				cnt[e.to]++;
			}
		}
	}
	vi lds;
	for(auto i:idx){
		if(cnt[i]==1){
			ls.pb(pos[i]);
			lds.pb(dist[i]);
		}
	}
	assert(is_sorted(all(ls)));
	assert(is_sorted(all(lds)));
	vvc<pi> zs(n);
	rep(i,n){
		vi cut{lwb(lds,dist[i]+1)-1,si(ls)};
		if(i)for(auto e:g[i]){
			if(dist[e.to]==dist[i]+e.cost){
				auto itr=lower_bound(all(ls),pos[e.to]);
				if(itr!=ls.ed&&*itr==pos[e.to]&&cut[0]<itr-ls.bg)
					cut.pb(itr-ls.bg);
			}
		}
		sort(all(cut));
		rep(j,si(cut)-1)if(cut[j]+1<cut[j+1]){
			zs[i].eb(cut[j]+1,cut[j+1]);
		}
	}
	

	

	segbeats<N> seg(vi(si(ls),*max_element(all(w))));
	auto upd=[&](int i,int val){
		for(const auto&[l,r]:zs[i])
			seg.ch(l,r,&N::setlim,val);
	};
	vc<ull> tmp;
	auto output=[&](){
		tmp.pb(seg.x[1].sum);
	};
	rep(i,n)upd(i,w[i]);
	output();
	per(i,q){
		upd(qs[i].a,w[qs[i].a]-=qs[i].b);
		output();
	}
	reverse(all(tmp));
	for(auto val:tmp)print(val);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	

	slv();
}