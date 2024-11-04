





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

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}







template<class N>
struct id5{
	vc<N> x;
	int s;
	id5(){}
	template<class t>
	id5(vc<t> a){
		int n=a.size();
		s=1;
		while(s<n){s*=2;}
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	

	id5(int n){
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

struct MaxNode{
	pi v;
	MaxNode(pi vv=pi(-inf,-1)):v(vv){}
	static MaxNode merge(const MaxNode&a,const MaxNode&b){
		return MaxNode(max(a.v,b.v));
	}
};

struct MinNode{
	int v;
	MinNode(int vv=inf):v(vv){}
	static MinNode merge(const MinNode&a,const MinNode&b){
		return MinNode(min(a.v,b.v));
	}
	bool ok(int x){return x<=v;}
};





template<class t,class u>
struct id2{
	vvc<t> a;
	u f;
	const t id;
	id2(const vc<t>& d,u ff,t w):f(ff),id(w){
		if(d.empty())return;
		int n=d.size(),h=topbit(n);
		a.resize(h+1);
		a[0]=d;
		rng(j,1,h+1){
			a[j].resize(n-(1<<j)+1);
			rep(i,n-(1<<j)+1)
				a[j][i]=f(a[j-1][i],a[j-1][i+(1<<(j-1))]);
		}
	}
	t get(int b,int e){
		assert(b<=e);
		if(b==e)return id;
		int d=topbit(e-b);
		return f(a[d][b],a[d][e-(1<<d)]);
	}
};
const auto imin=[](int a,int b){
	return min(a,b);
};
using minst=id2<int,decltype(imin)>;
const auto imax=[](int a,int b){
	return max(a,b);
};
using maxst=id2<int,decltype(imax)>;

void slv(){
	int n,q;cin>>n>>q;
	vi a=readvi(n,-1);
	minst mn(a,imin,inf);
	maxst mx(a,imax,-inf);
	
	set<pi> s;
	s.emplace(-1,-1);
	s.emplace(n,n);
	
	using T=tuple<int,int,int>;
	vc<T> ls;
	
	id5<MaxNode> id4(n);
	vc<priority_queue<T>> id1(n);
	auto upd_seg=[&](int i){
		if(si(id1[i])){
			id4.set(i,pi(get<0>(id1[i].top()),i));
		}else{
			id4.set(i,pi(-inf,-1));
		}
	};
	
	auto id0=[&](int l,int r){
		if(l>r)return;
		int lw=mn.get(l,r+1);
		int up=mx.get(l,r+1);
		
		id1[lw].emplace(up,l,r);
		upd_seg(lw);
	};
	
	

	auto reach=[&](int l,int r,int d){
		ls.eb(l,r,d);
		
		auto itr=s.lower_bound(pi(l+1,-1));
		while(1){
			auto pre=prev(itr);
			if(pre->b>=r)s.erase(pre);
			else break;
		}
		
		id0(l+1,itr->b-1);
		id0(prev(itr)->a+1,r-1);
		
		s.emplace(l,r);
	};
	
	reach(0,n-1,0);
	
	rep(head,si(ls)){
		auto [l,r,d]=ls[head];
		
		while(1){
			auto [tmp,idx]=id4.composite(0,l+1).v;
			if(r<=tmp&&idx!=-1){
				auto [up,b,e]=id1[idx].top();
				id1[idx].pop();
				upd_seg(idx);
				
				{
					auto itr=s.lower_bound(pi(b,-1));
					if(itr->b<=e)continue;
				}
				
				e++;
				int i,j;
				{
					int lf=b,rt=e;
					while(rt-lf>1){
						int mid=(lf+rt)/2;
						if(mn.get(b,mid)<=l&&r<=mx.get(b,mid))rt=mid;
						else lf=mid;
					}
					j=rt;
				}
				{
					int lf=b,rt=j;
					while(rt-lf>1){
						int mid=(lf+rt)/2;
						if(mn.get(mid,j)<=l&&r<=mx.get(mid,j))lf=mid;
						else rt=mid;
					}
					i=lf;
				}
				j--;
				
				reach(i,j,d+1);
			}else break;
		}
	}
	
	dmp(ls);
	
	
	vvc<pi> qs(n);
	vi ans(q,-1);
	rep(i,q){
		int b,e;cin>>b>>e;
		b--;
		qs[b].eb(e,i);
	}
	sort(all(ls));
	int tail=si(ls);
	id5<MinNode> z(n);
	per(i,n){
		while(tail>0&&get<0>(ls[tail-1])>=i){
			auto [l,r,d]=ls[--tail];
			z.point_merge(r,d);
		}
		for(auto [e,j]:qs[i]){
			int v=z.composite(i,e).v;
			if(v<inf)ans[j]=v;
		}
	}
	rep(i,q)print(ans[i]);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	

	slv();
}
