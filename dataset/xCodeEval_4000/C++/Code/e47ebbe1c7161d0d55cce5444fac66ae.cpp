

#pragma GCC target ("avx")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		

	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<1000000007>;

typedef long long ll;
typedef pair<ll,ll> P;		

ll inv(ll a,ll m){
	ll b=m,u=1,v=0;
	while(b){
		ll t=a/b;
		swap(a-=t*b,b);
		swap(u-=t*v,v);
	}
	u%=m;
	if(u<0) u+=m;
	return u;
}
ll garner(vector<P> rm,ll mod){		

	rm.pb(P(0,mod));
	int N=rm.size();
	vector<ll> as(N,1);		

	vector<ll> bs(N,0);		

	rep(i,N-1){
		ll v=(rm[i].fs-bs[i])*inv(as[i],rm[i].sc)%rm[i].sc;
		if(v<0) v+=rm[i].sc;
		for(int j=i+1;j<N;j++){
			(bs[j]+=as[j]*v)%=rm[j].sc;
			(as[j]*=rm[i].sc)%=rm[j].sc;
		}
	}
	return bs[N-1];
}

struct NTT{
	const int mod,g;
	NTT(int mod,int g) :mod(mod),g(g){}
	ll ex(ll x,ll p){
		ll a=1;
		while(p){
			if(p%2) a=a*x%mod;
			x=x*x%mod;
			p/=2;
		}
		return a;
	}
	ll inv(ll a){
		ll b=mod,u=1,v=0;
		while(b){
			ll t=a/b;
			swap(a-=t*b,b);
			swap(u-=t*v,v);
		}
		u%=mod;
		if(u<0) u+=mod;
		return u;
	}
	void ntt(vector<ll>& a,ll h){
		int N=a.size();
		for(int m=N;m>=2;m/=2){
			int mh=m/2;
			ll w=1;
			rep(i,mh){
				for(int j=i;j<N;j+=m){
					int k=j+mh;
					ll x=(a[j]-a[k]);
					a[j]+=a[k];
					if(a[j]>=mod) a[j]-=mod;
					a[k]=w*x%mod;
					if(a[k]<0) a[k]+=mod;
				}
				w=w*h%mod;
			}
			h=h*h%mod;
		}
		int i=0;
		rep1(j,N-2){
			for(int k=N/2;k>(i^=k);k/=2);
			if(j<i) swap(a[i],a[j]);
		}
	}
	vector<ll> conv(vector<ll> a,vector<ll> b){		

		for(auto& x:a) x%=mod;
		for(auto& x:b) x%=mod;
		int n=a.size()+b.size();
		int N=1;
		while(N<n) N*=2;
		a.resize(N),b.resize(N);
		assert((mod-1)%N==0);
		ll h=ex(g,(mod-1)/N);
		ntt(a,h),ntt(b,h);
		rep(i,N) (a[i]*=b[i])%=mod;
		h=inv(h);
		ntt(a,h);
		h=inv(N);
		rep(i,N) (a[i]*=h)%=mod;
		return a;
	}
};

const vector<ll> ms={167772161,469762049,1224736769},gs={3,3,3}; 
vector<mint> multiply_ntt(const vector<mint> &a_,const vector<mint> &b_){
	int mod = mint::mod;
	vector<ll> a(a_.size()),b(b_.size());
	rep(i,a.size()) a[i]=a_[i].v;
	rep(i,b.size()) b[i]=b_[i].v;
	vector<ll> vs[3];
	rep(i,3) vs[i]=NTT(ms[i],gs[i]).conv(a,b);
	int N=vs[0].size();
	vector<mint> ret(N);
	rep(i,N){
		vector<P> rm;
		rep(j,3) rm.pb(P(vs[j][i],ms[j]));
		ret[i]=garner(rm,mod);
	}
	return ret;
}

int bsr(int x) { return 31 - __builtin_clz(x); }
int bsr(ll x) { return 63 - __builtin_clzll(x); }
using D = double;
const D pi = acos(-1);
using Pc = complex<D>;

void fft(bool type, vector<Pc> &c){	

	static vector<Pc> buf[30];
	int N = c.size();
	int s = bsr(N);
	assert(1<<s == N);
	if(buf[s].empty()){
		buf[s]=vector<Pc>(N);
		rep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);
	}
	vector<Pc> a(N),b(N);
	copy(begin(c),end(c),begin(a));
	rep1(i,s){
		int W = 1<<(s-i);
		for(int y=0;y<N/2;y+=W){
			Pc now = buf[s][y];
			if(type) now = conj(now);
			rep(x,W){
				auto l =       a[y<<1 | x];
				auto r = now * a[y<<1 | x | W];
				b[y | x]        = l+r;
				b[y | x | N>>1] = l-r;
			}
		}
		swap(a,b);
	}
	copy(begin(a),end(a),begin(c));
}

template<class Mint>
vector<Mint> multiply_fft3(const vector<Mint>& x,const vector<Mint>& y){
	const int B = 10;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[3],b[3];
	rep(t,3){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,5){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-2,0); xt<=min(2,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft2(const vector<Mint>& x,const vector<Mint>& y){
	const int B = 15;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[2],b[2];
	rep(t,2){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,3){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-1,0); xt<=min(1,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft1(const vector<Mint>& x,const vector<Mint>& y){
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a(N),b(N);
	rep(i,x.size()) a[i] = Pc( x[i].v , 0 );
	rep(i,y.size()) b[i] = Pc( y[i].v , 0 );
	fft(false,a);
	fft(false,b);

	vector<Mint> z(S);
	vector<Pc> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	fft(true,c);
	rep(i,S){
		c[i] *= 1.0/N;
		z[i] = Mint(ll(round(c[i].real())));
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){
	return multiply_fft2(x,y);
}

template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	

	Poly(int N=0) : v(vector<D>(N)){}
	Poly(vector<D> v) : v(v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();	

		return *this;
	}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		

		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}

	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_fft(r);
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly operator%(const Poly &y) const{
		return rem_fast(y);


	}
	Poly operator<<(const int &n) const{	

		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	

		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}


	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(this->v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		vector<D> ret = multiply_fft(v,r.v);
		return Poly(ret);
	}

	Poly div_fast_with_inv(const Poly &inv, int B) const {
		return (*this * inv)>>(B-1);
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return Poly();
		int n = size();
		return div_fast_with_inv(y.inv(n),n);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast_with_inv(const Poly &y, const Poly &inv, int B) const{
		return *this - y * div_fast_with_inv(inv,B);
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly strip(int n) const {	

		vector<D> res = v;
		res.resize(min(n,size()));
		return Poly(res);
	}
	Poly rev(int n = -1) const {	

		vector<D> res = v;
		if(n!=-1) res.resize(n);
		reverse(all(res));
		return Poly(res);
	}
	Poly inv(int n) const{		

		int N = size();
		assert(N>=1);		

		assert(n>=N-1);		

		D coef = D(1)/at(N-1);
		Poly a = rev();
		Poly g(vector<D>(1,coef));
		for(int i=1; i+N-2<n; i*=2){		

			g *= (Poly(vector<D>{2})-a*g).strip(2*i);
		}
		return g.rev(n+1-N);
	}

	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};

template<class D>
Poly<D> nth_mod(long long n, const Poly<D> &mod){		

	int B = mod.size()*2 - 1;
	Poly<D> mod_inv = mod.inv(B);	

	Poly<D> a(vector<D>{1});
	int m = (!n) ? -1 : bsr(n);
	for(int i=m;i>=0;i--){
		if((n>>i)&1) a = (a<<1).rem_fast_with_inv(mod,mod_inv,B);
		if(i) a = (a*a).rem_fast_with_inv(mod,mod_inv,B);
	}
	return a;
}

template<class D>
Poly<D> berlekamp_massey(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}


int N,K;
const int MN = 10000;
mint diag[MN];
typedef pair<int,int> Pii;
vector<Pii> es;
void add_edge(int x,int y){


	if(x!=N-1){
		diag[x]+=1;
	}
	if(y!=N-1){
		diag[y]+=1;
	}
	if(x!=N-1&&y!=N-1){
		es.pb(P(x,y));
	}
}
int rand_range(int l,int r){
	static random_device rd;
	static mt19937 gen(rd());
	return uniform_int_distribution<int>(l,r)(gen);
}
vector<mint> rand_vector(int n){
	vector<mint> vec(n);
	rep(i,n) vec[i] = rand_range(1,mint(-1).v);
	return vec;
}
mint inprod(vector<mint>& a,vector<mint>& b){
	int N = a.size();
	mint ret;
	rep(i,N) ret+=a[i]*b[i];
	return ret;
}
vector<mint> prodAX(vector<mint>& a, const vector<mint>& X){	

	int N = a.size();
	vector<mint> ret(N);
	rep(i,N) a[i]*=X[i];
	rep(i,N) ret[i]+=a[i]*diag[i];
	for(Pii e:es){
		ret[e.fs]-=a[e.sc];
		ret[e.sc]-=a[e.fs];
	}
	return ret;
}
mint det(){
	int N = ::N-1;


		if(N==0) return 1;
		vector<mint> u(N*2);
		auto X = rand_vector(N);	

		auto l = rand_vector(N), r = rand_vector(N);
		rep(t,N*2){


			rep(i,N) u[t]+=l[i]*r[i];


			vector<mint> nr(N);
			rep(i,N) r[i]*=X[i];
			rep(i,N) nr[i]=r[i]*diag[i];
			for(auto e:es){
				nr[e.fs]-=r[e.sc];
				nr[e.sc]-=r[e.fs];
			}
			r=nr;
		}


		auto c = berlekamp_massey(u);
		mint AXdet = c.at(0); if(N%2==0) AXdet = -AXdet;


		if(!AXdet) return 0;


		mint Xdet = 1;
		rep(i,N) Xdet*=X[i];
		return AXdet/Xdet;


}
int main(){
	cin>>N>>K;
	rep(i,K) for(int j=i+1;j<K;j++) add_edge(i,j);
	rep(i,N-K){
		rep(j,K){
			int a;
			cin>>a;
			a--;
			add_edge(a,i+K);
		}
	}
	cout<<det()<<endl;
}