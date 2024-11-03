



 

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
bool id6(int i){
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
 




 
struct modinfo{uint mod,root;

constexpr modinfo(uint m,uint r):mod(m),root(r),im(0){set_mod(m);}
ull im;
constexpr void set_mod(uint m){
	mod=m;
	im=ull(-1)/m+1;
}
uint product(uint a,uint b)const{
	ull z=ull(a)*b;
	uint x=((unsigned __int128)z*im)>>64;
	uint v=uint(z)-x*mod;
	return v<mod?v:v+mod;
}

};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	

	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		
		v=ull(v)*rhs.v%mod;
		
		v=ref.product(v,rhs.v);
		
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(ll n)const{
		if(n<0)return inv().pow(-n);
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	
	friend modular operator+(ll x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(ll x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(ll x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(ll x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
 

 








template<class mint>
void id1(const int n,mint*const f,bool inv){
	static constexpr uint mod=mint::mod;
	static constexpr uint mod2=mod*2;
	static constexpr int L=30;
	static mint g[L],ig[L],p2[L];
	if(g[0].v==0){
		rep(i,L){
			mint w=-mint::root().pow(((mod-1)>>(i+2))*3);
			g[i]=w;
			ig[i]=w.inv();
			p2[i]=mint(1<<i).inv();
		}
	}
	if(!inv){
		int b=n;
		if(b>>=1){

			rep(i,b){
				uint x=f[i+b].v;
				f[i+b].v=f[i].v+mod-x;
				f[i].v+=x;
			}
		}
		if(b>>=1){

			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					uint x=(f[j+b]*p).v;
					f[j+b].v=f[j].v+mod-x;
					f[j].v+=x;
				}
				p*=g[__builtin_ctz(++k)];
			}
		}
		while(b){
			if(b>>=1){

				mint p=1;
				for(int i=0,k=0;i<n;i+=b*2){
					rng(j,i,i+b){
						uint x=(f[j+b]*p).v;
						f[j+b].v=f[j].v+mod-x;
						f[j].v+=x;
					}
					p*=g[__builtin_ctz(++k)];
				}
			}
			if(b>>=1){

				mint p=1;
				for(int i=0,k=0;i<n;i+=b*2){
					rng(j,i,i+b){
						uint x=(f[j+b]*p).v;
						f[j].v=(f[j].v<mod2?f[j].v:f[j].v-mod2);
						f[j+b].v=f[j].v+mod-x;
						f[j].v+=x;
					}
					p*=g[__builtin_ctz(++k)];
				}
			}
		}
	}else{
		int b=1;
		if(b<n/2){

			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					ull x=f[j].v+mod-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j+b].v=x*p.v%mod;
				}
				p*=ig[__builtin_ctz(++k)];
			}
			b<<=1;
		}
		for(;b<n/2;b<<=1){
			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b/2){

					ull x=f[j].v+mod2-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
					f[j+b].v=x*p.v%mod;
				}
				rng(j,i+b/2,i+b){

					ull x=f[j].v+mod-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j+b].v=x*p.v%mod;
				}
				p*=ig[__builtin_ctz(++k)];
			}
		}
		if(b<n){

			rep(i,b){
				uint x=f[i+b].v;
				f[i+b].v=f[i].v+mod2-x;
				f[i].v+=x;
			}
		}
		mint z=p2[__lg(n)];
		rep(i,n)f[i]*=z;
	}
}
 
template<class mint>
void id1(vector<mint>&f,bool inv){
	id1(si(f),f.data(),inv);
}
 




template<class mint>
void half_fmt(const int n,mint*const f){
	static constexpr uint mod=mint::mod;
	static constexpr uint mod2=mod*2;
	static const int L=30;
	static mint g[L],h[L];
	if(g[0].v==0){
		rep(i,L){
			g[i]=-mint::root().pow(((mod-1)>>(i+2))*3);
			h[i]=mint::root().pow((mod-1)>>(i+2));
		}
	}
	int b=n;
	int lv=0;
	if(b>>=1){

		mint p=h[lv++];
		for(int i=0,k=0;i<n;i+=b*2){
			rng(j,i,i+b){
				uint x=(f[j+b]*p).v;
				f[j+b].v=f[j].v+mod-x;
				f[j].v+=x;
			}
			p*=g[__builtin_ctz(++k)];
		}
	}
	if(b>>=1){

		mint p=h[lv++];
		for(int i=0,k=0;i<n;i+=b*2){
			rng(j,i,i+b){
				uint x=(f[j+b]*p).v;
				f[j+b].v=f[j].v+mod-x;
				f[j].v+=x;
			}
			p*=g[__builtin_ctz(++k)];
		}
	}
	while(b){
		if(b>>=1){

			mint p=h[lv++];
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					uint x=(f[j+b]*p).v;
					f[j+b].v=f[j].v+mod-x;
					f[j].v+=x;
				}
				p*=g[__builtin_ctz(++k)];
			}
		}
		if(b>>=1){

			mint p=h[lv++];
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					uint x=(f[j+b]*p).v;
					f[j].v=(f[j].v<mod2?f[j].v:f[j].v-mod2);
					f[j+b].v=f[j].v+mod-x;
					f[j].v+=x;
				}
				p*=g[__builtin_ctz(++k)];
			}
		}
	}
}
 
template<class mint>
void half_fmt(vector<mint>&f){
	half_fmt(si(f),f.data());
}
 

 
template<class mint>
vc<mint> multiply(vc<mint> x,const vc<mint>&y,bool same=false){
	int n=si(x)+si(y)-1;
	int s=1;
	while(s<n)s*=2;
	x.resize(s);id1(x,false);
	if(!same){
		vc<mint> z(s);
		rep(i,si(y))z[i]=y[i];
		id1(z,false);
		rep(i,s)x[i]*=z[i];
	}else{
		rep(i,s)x[i]*=x[i];
	}
	id1(x,true);x.resize(n);
	return x;
}
template<class mint>
vc<mint> id4(vc<mint> x,const vc<mint>&y,bool same=false){
	int s=si(x);
	assert(id6(s));
	assert(si(y));
	x.resize(s);id1(x,false);
	if(!same){
		vc<mint> z(s);
		rep(i,si(y))z[i]=y[i];
		id1(z,false);
		rep(i,s)x[i]*=z[i];
	}else{
		rep(i,s)x[i]*=x[i];
	}
	id1(x,true);
	return x;
}
 

 










namespace arbitrary_convolution{
	constexpr modinfo base0{167772161,3};

	constexpr modinfo base1{469762049,3};

	constexpr modinfo base2{754974721,11};

	

	

	

	using mint0=modular<base0>;
	using mint1=modular<base1>;
	using mint2=modular<base2>;
	template<class t,class mint>
	vc<t> sub(const vc<mint>&x,const vc<mint>&y,bool same=false){
		int n=si(x)+si(y)-1;
		int s=1;
		while(s<n)s*=2;
		vc<t> z(s);rep(i,si(x))z[i]=x[i].v;
		id1(z,false);
		if(!same){
			vc<t> w(s);rep(i,si(y))w[i]=y[i].v;
			id1(w,false);
			rep(i,s)z[i]*=w[i];
		}else{
			rep(i,s)z[i]*=z[i];
		}
		id1(z,true);z.resize(n);
		return z;
	}
	template<class mint>
	vc<mint> multiply(const vc<mint>&x,const vc<mint>&y,bool same=false){
		auto d0=sub<mint0>(x,y,same);
		auto d1=sub<mint1>(x,y,same);
		auto d2=sub<mint2>(x,y,same);
		int n=si(d0);
		vc<mint> res(n);
		static const mint1 r01=mint1(mint0::mod).inv();
		static const mint2 r02=mint2(mint0::mod).inv();
		static const mint2 r12=mint2(mint1::mod).inv();
		static const mint2 id3=r02*r12;
		static const mint w1=mint(mint0::mod);
		static const mint w2=w1*mint(mint1::mod);
		rep(i,n){
			ull a=d0[i].v;
			ull b=(d1[i].v+mint1::mod-a)*r01.v%mint1::mod;
			ull c=((d2[i].v+mint2::mod-a)*id3.v+(mint2::mod-b)*r12.v)%mint2::mod;
			res[i].v=(a+b*w1.v+c*w2.v)%mint::mod;
		}
		return res;
	}
	template<class t,class mint>
	vc<t> id8(const vc<mint>&x,const vc<mint>&y,bool same=false){
		int s=si(x);
		assert(id6(s));
		assert(si(y)==s);
		vc<t> z(s);rep(i,si(x))z[i]=x[i].v;
		id1(z,false);
		if(!same){
			vc<t> w(s);rep(i,si(y))w[i]=y[i].v;
			id1(w,false);
			rep(i,s)z[i]*=w[i];
		}else{
			rep(i,s)z[i]*=z[i];
		}
		id1(z,true);
		return z;
	}
	template<class mint>
	vc<mint> id4(const vc<mint>&x,const vc<mint>&y,bool same=false){
		auto d0=id8<mint0>(x,y,same);
		auto d1=id8<mint1>(x,y,same);
		auto d2=id8<mint2>(x,y,same);
		int n=si(d0);
		vc<mint> res(n);
		static const mint1 r01=mint1(mint0::mod).inv();
		static const mint2 r02=mint2(mint0::mod).inv();
		static const mint2 r12=mint2(mint1::mod).inv();
		static const mint2 id3=r02*r12;
		static const mint w1=mint(mint0::mod);
		static const mint w2=w1*mint(mint1::mod);
		rep(i,n){
			ull a=d0[i].v;
			ull b=(d1[i].v+mint1::mod-a)*r01.v%mint1::mod;
			ull c=((d2[i].v+mint2::mod-a)*id3.v+(mint2::mod-b)*r12.v)%mint2::mod;
			res[i].v=(a+b*w1.v+c*w2.v)%mint::mod;
		}
		return res;
	}
}
using arbitrary_convolution::multiply;
using arbitrary_convolution::id4;
 

 


namespace integer_convolution{
	extern constexpr modinfo base0{1045430273,3};

	extern constexpr modinfo base1{1051721729,6};

	using mint0=modular<base0>;
	using mint1=modular<base1>;
	template<class t>
	vc<t> sub(const vi&x,const vi&y,bool same=false){
		int n=si(x)+si(y)-1;
		int s=1;
		while(s<n)s*=2;
		vc<t> z(s);rep(i,si(x))z[i]=x[i];
		id1(z,false);
		if(!same){
			vc<t> w(s);rep(i,si(y))w[i]=y[i];
			id1(w,false);
			rep(i,s)z[i]*=w[i];
		}else{
			rep(i,s)z[i]*=z[i];
		}
		id1(z,true);z.resize(n);
		return z;
	}
	vi multiply(const vi&x,const vi&y,bool same=false){
		auto d0=sub<mint0>(x,y,same);
		auto d1=sub<mint1>(x,y,same);
		const mint1 r=mint1(mint0::mod).inv();
		const ll v=ll(mint0::mod)*mint1::mod;
		int n=si(d0);
		vi res(n);
		rep(i,n){
			res[i]=d0[i].v+(r*(d1[i]-d0[i].v)).v*(ull)mint0::mod;
			if(res[i]>v/2)res[i]-=v;
		}
		return res;
	}
}
 






template<class mint>
struct Poly:public vc<mint>{
	template<class...Args>
	Poly(Args...args):vc<mint>(args...){}
	Poly(initializer_list<mint>init):vc<mint>(all(init)){}
	int size()const{
		return vc<mint>::size();
	}
	void ups(int s){
		if(size()<s)this->resize(s,0);
	}
	Poly low(int s)const{
		assert(s);
		Poly res(s);
		rep(i,min(s,size()))res[i]=(*this)[i];
		return res;
	}
	Poly rev()const{
		auto r=*this;
		reverse(all(r));
		return r;
	}
	Poly operator>>(int x)const{
		assert(x<size());
		Poly res(size()-x);
		rep(i,size()-x)res[i]=(*this)[i+x];
		return res;
	}
	Poly operator<<(int x)const{
		Poly res(size()+x);
		rep(i,size())res[i+x]=(*this)[i];
		return res;
	}
	mint freq(int i)const{
		return i<size()?(*this)[i]:0;
	}
	Poly operator-()const{
		Poly res=*this;
		for(auto&v:res)v=-v;
		return res;
	}
	Poly& operator+=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]+=r[i];
		return *this;
	}
	template<class T>
	Poly& operator+=(T t){
		(*this)[0]+=t;
		return *this;
	}
	Poly& operator-=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]-=r[i];
		return *this;
	}
	template<class T>
	Poly& operator-=(T t){
		(*this)[0]-=t;
		return *this;
	}
	template<class T>
	Poly& operator*=(T t){
		for(auto&v:*this)
			v*=t;
		return *this;
	}
	Poly& operator*=(const Poly&r){
		return *this=multiply(*this,r);
	}
	Poly square()const{
		return multiply(*this,*this,true);
	}
	
	Poly inv(int s)const{
		Poly r{mint(1)/(*this)[0]};
		for(int n=1;n<s;n*=2)
			r=r*2-(r.square()*low(2*n)).low(2*n);
		r.resize(s);
		return r;
	}
	
	

	

	Poly inv(int s)const{
		Poly r(s);
		r[0]=mint(1)/(*this)[0];
		for(int n=1;n<s;n*=2){
			vc<mint> f=low(2*n);
			f.resize(2*n);
			id1(f,false);
			vc<mint> g=r.low(2*n);
			g.resize(2*n);
			id1(g,false);
			rep(i,2*n)f[i]*=g[i];
			id1(f,true);
			rep(i,n)f[i]=0;
			id1(f,false);
			rep(i,2*n)f[i]*=g[i];
			id1(f,true);
			rng(i,n,min(2*n,s))r[i]=-f[i];
		}
		return r;
	}
	
	template<class T>
	Poly& operator/=(T t){
		return *this*=mint(1)/mint(t);
	}
	Poly quotient(const Poly&r,const Poly&rri)const{
		int m=r.size();
		assert(r[m-1].v);
		int n=size();
		int s=n-m+1;
		if(s<=0) return {0};
		return (rev().low(s)*rri.low(s)).low(s).rev();
	}
	Poly& operator/=(const Poly&r){
		return *this=quotient(r,r.rev().inv(max(size()-r.size(),int(0))+1));
	}
	Poly& operator%=(const Poly&r){
		*this-=*this/r*r;
		return *this=low(r.size()-1);
	}
	Poly operator+(const Poly&r)const{return Poly(*this)+=r;}
	template<class T>
	Poly operator+(T t)const{return Poly(*this)+=t;}
	Poly operator-(const Poly&r)const{return Poly(*this)-=r;}
	template<class T>
	Poly operator-(T t)const{return Poly(*this)-=t;}
	template<class T>
	Poly operator*(T t)const{return Poly(*this)*=t;}
	Poly operator*(const Poly&r)const{return Poly(*this)*=r;}
	template<class T>
	Poly operator/(T t)const{return Poly(*this)/=t;}
	Poly operator/(const Poly&r)const{return Poly(*this)/=r;}
	Poly operator%(const Poly&r)const{return Poly(*this)%=r;}
	Poly dif()const{
		assert(size());
		if(size()==1){
			return {0};
		}else{
			Poly r(size()-1);
			rep(i,r.size())
				r[i]=(*this)[i+1]*(i+1);
			return r;
		}
	}
	Poly inte(const mint invs[])const{
		Poly r(size()+1,0);
		rep(i,size())
			r[i+1]=(*this)[i]*invs[i+1];
		return r;
	}
	

	

	Poly log(int s,const mint invs[])const{
		assert((*this)[0]==1);
		if(s==1)return {0};
		return (low(s).dif()*inv(s-1)).low(s-1).inte(invs);
	}
	

	

	

	Poly exp(int s,const mint invs[])const{
		assert((*this)[0]==mint(0));
		Poly f{1},g{1};
		for(int n=1;;n*=2){
			if(n>=s)break;
			g=g*2-(g.square()*f).low(n);
			

			Poly q=low(n).dif();
			q=q+g*(f.dif()-f*q).low(2*n-1);
			f=f+(f*(low(2*n)-q.inte(invs))).low(2*n);
		}
		return f.low(s);
	}
	

	

	pair<Poly,Poly> exp2(int s,const mint invs[])const{
		assert((*this)[0]==mint(0));
		Poly f{1},g{1};
		for(int n=1;;n*=2){
			

			g=g*2-(g.square()*f).low(n);
			if(n>=s)break;
			Poly q=low(n).dif();
			q=q+g*(f.dif()-f*q).low(2*n-1);
			f=f+(f*(low(2*n)-q.inte(invs))).low(2*n);
		}
		return make_pair(f.low(s),g.low(s));
	}
	
	

	Poly sqrt(int s)const{
		assert((*this)[0]==1);
		static const mint half=mint(1)/mint(2);
		Poly r{1};
		for(int n=1;n<s;n*=2)
			r=(r+(r.inv(n*2)*low(n*2)).low(n*2))*half;
		return r.low(s);
	}
	
	

	

	Poly sqrt(int s)const{
		assert((*this)[0]==1);
		static const mint half=mint(1)/mint(2);
		vc<mint> f{1},g{1},z{1};
		for(int n=1;n<s;n*=2){
			rep(i,n)z[i]*=z[i];
			id1(z,true);
			
			vc<mint> delta(2*n);
			rep(i,n)delta[n+i]=z[i]-freq(i)-freq(n+i);
			id1(delta,false);
			
			vc<mint> gbuf(2*n);
			rep(i,n)gbuf[i]=g[i];
			id1(gbuf,false);
			
			rep(i,2*n)delta[i]*=gbuf[i];
			id1(delta,true);
			f.resize(2*n);
			rng(i,n,2*n)f[i]=-half*delta[i];
			
			if(2*n>=s)break;
			
			z=f;
			id1(z,false);
			
			vc<mint> eps=gbuf;
			rep(i,2*n)eps[i]*=z[i];
			id1(eps,true);
			
			rep(i,n)eps[i]=0;
			id1(eps,false);
			
			rep(i,2*n)eps[i]*=gbuf[i];
			id1(eps,true);
			g.resize(2*n);
			rng(i,n,2*n)g[i]=-eps[i];
		}
		f.resize(s);
		return f;
	}
	
	pair<Poly,Poly> divide(const Poly&r,const Poly&rri)const{
		Poly a=quotient(r,rri);
		Poly b=*this-a*r;
		return make_pair(a,b.low(r.size()-1));
	}
	

	Poly pow_mod(int n,const Poly&r)const{
		Poly rri=r.rev().inv(r.size());
		Poly cur{1},x=*this%r;
		while(n){
			if(n%2)
				cur=(cur*x).divide(r,rri).b;
			x=(x*x).divide(r,rri).b;
			n/=2;
		}
		return cur;
	}
	int lowzero()const{
		rep(i,size())if((*this)[i]!=0)return i;
		return size();
	}
	

	

	Poly pow(int s,int p,const mint invs[])const{
		assert(s>0);
		int n=size(),z=0;
		for(;z<n&&(*this)[z]==0;z++);
		assert(z==0||p>0);
		if(z*p>=s)return Poly(s,0);
		mint c=(*this)[z],cinv=c.inv();
		mint d=c.pow(p);
		int t=s-z*p;
		Poly x(t);
		rng(i,z,min(z+t,n))x[i-z]=(*this)[i]*cinv;
		x=x.log(t,invs);
		rep(i,t)x[i]*=p;
		x=x.exp(t,invs);
		rep(i,t)x[i]*=d;
		Poly y(s);
		rep(i,t)y[z*p+i]=x[i];
		return y;
	}
	mint eval(mint x)const{
		mint r=0,w=1;
		for(auto v:*this){
			r+=w*v;
			w*=x;
		}
		return r;
	}
};
 




template<class mint>
struct Laurent{
	Poly<mint> f;
	int a;
	Laurent(const Poly<mint>&num,const Poly<mint>&den,int s){
		a=den.lowzero();
		assert(a<si(den));
		f=(num*(den>>a).inv(s)).low(s);
	}
	Laurent(const Poly<mint>&ff,int aa):f(ff),a(aa){}
	Laurent dif()const{
		return Laurent(f*(-a)+(f.dif()<<1),a+1);
	}
	mint&operator[](int i){
		assert(inc(0,i+a,si(f)-1));
		return f[i+a];
	}
};
 
template<class mint>
ll id9(mint a){
	return a.v<mint::mod/2?a.v:ll(a.v)-ll(mint::mod);
}
 
template<class mint>
void showpoly(const Poly<mint>&a){
	vi tmp(si(a));
	rep(i,si(a)){
		tmp[i]=id9(a[i]);
	}
	cerr<<tmp<<endl;
}
 


template<class mint>
vc<mint> id5(const vc<mint>&a,const vc<mint>&b,int mx){
	int n=si(a),m=si(b);
	vc<mint> c(n+m-1);
	int len=1<<(mx-1);
	for(int i=0;i<n;i+=len){
		for(int j=0;j<n;j+=len){
			int x=min(len,n-i),y=min(len,m-j);
			auto d=multiply(vc<mint>(a.bg+i,a.bg+i+x),vc<mint>(b.bg+j,b.bg+j+y));
			rep(k,si(d))
				c[i+j+k]+=d[k];
		}
	}
	return c;
}
 


 












template<class mint>
struct id10{
	using poly=Poly<mint>;
	int raws,s,h;
	mint*buf;
	vc<mint*>f;
	vi len;
	poly top;
	void inner_product(const int n,const mint*a,const mint*b,mint*c){
		rep(i,n)c[i]=a[i]*b[i];
	}
	

	

	

	

	void doubling_fmt(const int n,mint*a,const mint v){
		a[n]-=v*2;
		half_fmt(n,a+n);
	}
	id10(const vc<mint>&a){
		raws=si(a);
		s=1;while(s<si(a))s*=2;
		h=__lg(s)+1;
		buf=new mint[s*h*2];
		f.resize(s*2);
		len.resize(s*2);
		{
			mint*head=buf;
			rng(i,1,s*2){
				len[i]=s>>__lg(i);
				f[i]=head;
				head+=len[i]*2;
			}
		}
		rep(i,s){
			mint w=i<si(a)?a[i]:0;
			f[s+i][0]=-w+1;
			f[s+i][1]=-w-1;
		}
		if(s==1)f[1][1]=f[1][0];
		gnr(i,1,s){
			inner_product(len[i],f[i*2],f[i*2+1],f[i]);
			copy(f[i],f[i]+len[i],f[i]+len[i]);
			id1(len[i],f[i]+len[i],true);
			if(i>1)doubling_fmt(len[i],f[i],1);
		}
		top.resize(s+1);
		rep(i,s)top[i]=f[1][s+i];
		top[0]-=1;
		top[s]=1;
	}
	~id10(){
		delete[] buf;
	}
	

	vc<mint> multieval(const poly&b){
		mint*buf2=new mint[s*2];
		vc<mint*> c(s*2);
		{
			mint*head=buf2;
			rng(i,1,s*2){
				if((i&(i-1))==0&&__lg(i)%2==0)head=buf2;
				c[i]=head;
				head+=len[i];
			}
		}
		{
			poly tmp=top.rev().inv(si(b)).rev()*b;
			rep(i,s)c[1][i]=i<si(b)?tmp[si(b)-1+i]:0;
		}
		vc<mint> tmp(s);
		rng(i,1,s){
			id1(len[i],c[i],false);
			rep(k,2){
				tmp.resize(len[i]);
				rep(j,len[i])tmp[j]=f[i*2+(k^1)][j]*c[i][j];
				id1(tmp,true);
				rep(j,len[i]/2)c[i*2+k][j]=tmp[len[i]/2+j];
			}
		}
		vc<mint> ans(raws);
		rep(i,raws)ans[i]=c[s+i][0];
		delete[] buf2;
		return ans;
	}
	poly interpolate(const vc<mint>&val){
		mint*buf2=new mint[s*2*2];
		vc<mint*> c(s*2);
		{
			mint*head=buf2;
			rng(i,1,s*2){
				if((i&(i-1))==0&&__lg(i)%2==0)head=buf2;
				c[i]=head;
				head+=len[i]*2;
			}
		}
		{
			vc<mint> z=multieval(poly(top.bg+(s-si(val)),top.ed).dif());
			rep(i,s){
				mint w=i<si(val)?val[i]/z[i]:0;
				c[s+i][0]=c[s+i][1]=w;
			}
		}
		gnr(i,1,s){
			rep(j,len[i])
				c[i][j]=c[i*2][j]*f[i*2+1][j]+c[i*2+1][j]*f[i*2][j];
			copy(c[i],c[i]+len[i],c[i]+len[i]);
			id1(len[i],c[i]+len[i],true);
			if(i>1)doubling_fmt(len[i],c[i],0);
		}
		poly res(c[1]+s+(s-si(val)),c[1]+s*2);
		delete[] buf2;
		return res;
	}
};
 
template<class mint>
vc<mint> multieval(const Poly<mint>&f,const vc<mint>&x){
	return id10<mint>(x).multieval(f);
}
 
template<class mint>
Poly<mint> interpolate(const vc<mint>&x,const vc<mint>&y){
	assert(si(x)==si(y));
	if(si(x)==1)return {y[0]};
	id10<mint> tree(x);
	return tree.interpolate(y);
}
 

extern constexpr modinfo base{998244353,3};





static_assert(base.mod==998244353);


modinfo base(1,0);
extern constexpr modinfo base107(1000000007,0);
using mint107=modular<base107>;

using mint=modular<base>;
 

const int vmax=1010;

const int vmax=(1<<21)+10;

mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rng(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return fact[n]*finv[n-k]*finv[k];
}
mint binom(int a,int b){
	return fact[a+b]*finv[a]*finv[b];
}
mint id11(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
 

 
mint p2[vmax];
void id0(){
	p2[0]=1;
	rep(i,vmax-1)p2[i+1]=p2[i]*2;
}
 


mint interpolate(const vc<mint>&a,mint x){
	int n=si(a);
	if(inc(0,x.v,n-1))return a[x.v];
	vc<mint> z(n+1);
	z[n]=1;
	per(i,n)z[i]=z[i+1]*(x-i);
	mint res,w=1;
	rep(i,n){
		res+=w*z[i+1]*a[i]*finv[i]*finv[n-1-i]*((n-1-i)%2?-1:1);
		w*=x-i;
	}
	return res;
}
 








mint id7(const mint a,const vc<mint>&f,const int n){
	if(n==0)return 0;
	int k=si(f)-1;
	if(a==0){
		return f[0];
	}else if(a==1){
		vc<mint> g(k+2);
		rep(i,k+1)g[i+1]=g[i]+f[i];
		return interpolate(g,n);
	}else{
		vc<mint> g(k+1);
		{
			mint r=1;
			rep(i,k+1){
				g[i]=f[i]*r;
				r*=a;
			}
		}
		mint c;
		{
			mint w,r=1;
			rep(i,k+1){
				w+=choose(k+1,i)*r;
				r*=-a;
				c+=g[k-i]*w;
			}
			c/=mint(1-a).pow(k+1);
		}
		rep(i,k)g[i+1]+=g[i];
		mint ainv=a.inv(),w=1;
		rep(i,k+1){
			g[i]=(g[i]-c)*w;
			w*=ainv;
		}
		return interpolate(g,n-1)*a.pow(n-1)+c;
	}
}
 
 




vc<mint> id2(const mint a,const vc<mint>&f,vi xs){
	int k=si(f)-1;
	if(a==0){
		assert(false);
	}else if(a==1){
		assert(false);
	}else{
		vc<mint> g(k+1);
		{
			mint r=1;
			rep(i,k+1){
				g[i]=f[i]*r;
				r*=a;
			}
		}
		mint c;
		{
			mint w,r=1;
			rep(i,k+1){
				w+=choose(k+1,i)*r;
				r*=-a;
				c+=g[k-i]*w;
			}
			c/=mint(1-a).pow(k+1);
		}
		rep(i,k)g[i+1]+=g[i];
		mint ainv=a.inv(),w=1;
		rep(i,k+1){
			g[i]=(g[i]-c)*w;
			w*=ainv;
		}
		vc<mint> tmp(k+1);
		rep(i,k+1)tmp[i]=i;
		Poly z=interpolate(tmp,g);
		vc<mint> use(si(xs));
		rep(i,si(xs))use[i]=xs[i]-1;
		vc<mint> res=multieval(z,use);
		rep(i,si(xs)){
			res[i]=res[i]*a.pow(xs[i]-1)+c;
			
		}
		return res;
		

	}
}
 
void slv(){
	int n,k,p;cin>>n>>k>>p;
	vc<mint> f(k+1);
	rep(i,k+1)f[i]=mint(i).pow(k);
	vi mx=readvi(n);
	vi evp(n);
	rep(i,n)evp[i]=mx[i]+1;
	auto sum=id2(p,f,evp);
	
	mint ans;
	mint dp[2][2];
	
	rep(i,n){
		dp[0][0]+=1;
		mint nx[2][2];
		{

			rep(j,2)rep(q,2)nx[j][q]+=dp[j][q]*(mx[i]+1);
		}
		{

			nx[1][0]+=dp[0][0]*sum[i];
			nx[1][1]+=dp[0][1]*sum[i];
		}
		{

			nx[0][1]+=dp[0][0]*mx[i];
			nx[1][1]+=dp[1][0]*mx[i];
		}
		{

			nx[1][1]+=dp[0][0]*sum[i];
		}
		swap(dp,nx);
		ans+=dp[1][1];
	}
	
	print(ans);
}
 
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initfact();
	

	slv();
}