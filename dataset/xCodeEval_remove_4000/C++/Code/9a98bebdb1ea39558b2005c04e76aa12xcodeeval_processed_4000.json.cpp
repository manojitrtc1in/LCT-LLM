
using namespace std;
typedef unsigned long long ull;
const int N=(1<<21)+20;
const int mod=998244353;
typedef vector<int> vec;

inline int add(int x,int y){return (x+y>=mod)?x+y-mod:x+y;}
inline int dec(int x,int y){return (x-y<0)?x-y+mod:x-y;}
inline void inc(int &x,int y){x=add(x,y);}
inline void rec(int &x,int y){x=dec(x,y);}
inline int ksm(int x,int y){
	int ret=1;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) ret=1ll*ret*x%mod;
	return ret; 
}

namespace IO {
	inline char nc(){
		static char buf[500005],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,500000,stdin),p1==p2)?EOF:*p1++;
	}
	char out[500005],*pout=out,*eout=out+500000;
	inline void flush() { fwrite(out,1,pout-out,stdout),pout=out; }
	inline void pc(char c) { pout==eout&&(fwrite(out,1,500000,stdout),pout=out); (*pout++)=c; }
	template<typename T> inline void put(T x,char suf) {
		static char stk[65];int top=0; while(x) stk[top++]=x%10,x/=10;
		!top?pc('0'),0:0; while(top--) pc(stk[top]+'0'); pc(suf);
	}
	inline int read(){
		char ch=nc(); int sum=0; for(;ch<'0'||ch>'9';ch=nc());
		while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
		return sum;
	}
}

using IO::put;
using IO::nc;
namespace Prep{
	int Wn[N<<1],lg[N],p2,mx=1,r[N],tot;
	inline void init_poly(int n){
		int p=1;while(p<=n)p<<=1;
		for(int i=2;i<=p;++i) lg[i]=lg[i>>1]+1;
		for(int i=1;i<p;i<<=1){
			int wn=ksm(3,(mod-1)/(i<<1));
			Wn[++tot]=1;
			for(int j=1;j<i;++j) ++tot,Wn[tot]=1ll*Wn[tot-1]*wn%mod;
		}
	}
	inline void init(int lim){
		int len=lg[lim]-1;
		for(int i=0;i<lim;++i) r[i]=(r[i>>1]>>1)|((i&1)<<len);
	}
	int iv[N],tp;
	inline void init_inv(int n){
		if(!tp){tp=2;iv[0]=iv[1]=1;}
		for(;tp<=n;++tp) iv[tp]=1ll*(mod-mod/tp)*iv[mod%tp]%mod;
	}
}
using namespace Prep;

namespace Cipolla{
	int I,fl=0;
	mt19937 rnd(time(0));
	struct pt{
		int a,b;
		pt(int _a=0,int _b=0){a=_a;b=_b;}
	};
	inline pt operator *(pt x,pt y){
		pt ret;
		ret.a=add(1ll*x.a*y.a%mod,1ll*x.b*y.b%mod*I%mod);
		ret.b=add(1ll*x.a*y.b%mod,1ll*x.b*y.a%mod);
		return ret;
	}
	inline bool check(int x){
		return ksm(x,(mod-1)/2)==1;
	}
	inline int random(){return rnd()%mod;}
	inline pt qpow(pt a,int b){
		pt ret=pt(1,0);
		for(;b;a=a*a,b>>=1) if(b&1) ret=ret*a;
		return ret;
	}
	inline int cipolla(int n){
		if(!check(n)) return 0;
		int a=random();
		while(!a||check(dec(1ll*a*a%mod,n))) a=random();
		I=dec(1ll*a*a%mod,n);
		int ans=qpow(pt(a,1),(mod+1)/2).a;
		return min(ans,(int)mod-ans);
	}
}
using namespace Cipolla;

namespace Poly{
	struct poly{
		vec v;
		
		inline poly(int w=0):v(1){v[0]=w;}
		inline poly(const vec&w):v(w){}
		
		inline int operator [](int x)const{return x>=v.size()?0:v[x];}
		inline int& operator [](int x){
			if(x>=v.size()) v.resize(x+1);
			return v[x];
		}
		inline int size(){return v.size();}
		inline void resize(int x){v.resize(x);}
		inline void read(int n){v.resize(n);for(int i=0;i<n;++i) v[i]=Rint;}
		inline void print(int n)const{for(int i=0;i<n-1;++i) put(operator[](i),' ');put(operator[](n-1),'\n');}
		
		inline poly slice(int len)const{
			if(len<=v.size()) return vec(v.begin(),v.begin()+len);
			vec ret(v);ret.resize(len);
			return ret;
		}
		
		inline poly operator *(const int &x)const{
			poly ret(v);
			for(int i=0;i<v.size();++i) ret[i]=1ll*ret[i]*x%mod; 
			return ret;
		}
		inline poly operator -()const{
			poly ret(v);
			for(int i=0;i<v.size();++i) ret[i]=dec(0,ret[i]);
			return ret;
		}
		
		inline poly operator*(const poly &g)const;
		inline poly operator/(const poly &g)const;
		inline poly operator%(const poly &g)const;
		inline poly der()const{
			vec ret(v);
			for(int i=0;i<ret.size()-1;++i) ret[i]=1ll*ret[i+1]*(i+1)%mod;
			ret.pop_back();
			return ret; 
		}
		inline poly jifen()const{
			vec ret(v);
			init_inv(ret.size());ret.push_back(0);
			for(int i=ret.size()-1;i;--i) ret[i]=1ll*ret[i-1]*iv[i]%mod;ret[0]=0;
			return ret;
		}
		inline poly rev()const{
			vec ret(v);
			reverse(ret.begin(),ret.end());
			return ret;
		}
		
		inline poly inv()const;
		inline poly div(const poly &FF)const;
		inline poly ln()const;
		inline poly exp()const;
		inline poly pow(int k)const;
		inline poly sqrt()const;
	};
	
	inline poly operator +(const poly &x,const poly &y){
		vec v(max(x.v.size(),y.v.size()));
		for(int i=0;i<v.size();++i) v[i]=add(x[i],y[i]);
		return v;
	}
	inline poly operator -(const poly &x,const poly &y){
		vec v(max(x.v.size(),y.v.size()));
		for(int i=0;i<v.size();++i) v[i]=dec(x[i],y[i]);
		return v;
	}
	
	ull fr[N];
	const ull Mod=998244353;
	inline void NTT(poly& f,int lim,int tp){
		for(int i=0;i<lim;++i) fr[i]=f[r[i]];
		for(int mid=1;mid<lim;mid<<=1){
			for(int len=mid<<1,l=0;l+len-1<lim;l+=len){
				for(int k=l;k<l+mid;++k){
					ull w1=fr[k],w2=fr[k+mid]*Wn[mid+k-l]%Mod;
					fr[k]=w1+w2;fr[k+mid]=w1+Mod-w2; 
				}
			}
		}
		for(int i=0;i<lim;++i) fr[i]>=Mod?fr[i]%=Mod:0;
		if(!tp){
			reverse(fr+1,fr+lim);
			int iv=ksm(lim,mod-2);
			for(int i=0;i<lim;++i) fr[i]=fr[i]*iv%mod;
		}
		for(int i=0;i<lim;++i) f[i]=fr[i];
	}
	
	inline poly poly::operator *(const poly &G)const{
		poly f(v),g=G;
		int rec=f.size()+g.size()-1,d=max(f.size(),g.size());
		int len=lg[rec],lim=1<<len+1;
		init(lim);
		NTT(f,lim,1);NTT(g,lim,1);
		for(int i=0;i<lim;++i) f[i]=1ll*f[i]*g[i]%mod;
		NTT(f,lim,0);
		return f.slice(rec);
	}
	
	inline poly poly::inv()const{
		poly g,g0,d;
		g[0]=ksm(v[0],mod-2);
		for(int lim=2;(lim>>1)<v.size();lim<<=1){
			g0=g;d=slice(lim);
			init(lim);
			NTT(g0,lim,1);NTT(d,lim,1);
			for(int i=0;i<lim;++i) d[i]=1ll*g0[i]*d[i]%mod;
			NTT(d,lim,0);
			fill(d.v.begin(),d.v.begin()+(lim>>1),0);
			NTT(d,lim,1);
			for(int i=0;i<lim;++i) d[i]=1ll*d[i]*g0[i]%mod;
			NTT(d,lim,0);
			for(int i=lim>>1;i<lim;++i) g[i]=dec(g[i],d[i]);
		}
		return g.slice(v.size());
	}

	
	inline poly poly::div(const poly &FF)const{
		if(v.size()==1) return 1ll*v[0]*ksm(FF[0],mod-2)%mod;	
		int len=lg[v.size()],lim=1<<len+1,nlim=lim>>1;
		poly F=FF,G0=FF.slice(nlim);	
		G0=G0.inv();
		poly H0=slice(nlim),Q0;
		
		init(lim);
		NTT(G0,lim,1);NTT(H0,lim,1);
		for(int i=0;i<lim;++i) Q0[i]=1ll*G0[i]*H0[i]%mod;
		NTT(Q0,lim,0);Q0.resize(nlim);
		
		poly ret=Q0;
		NTT(Q0,lim,1);NTT(F,lim,1);
		for(int i=0;i<lim;++i) Q0[i]=1ll*Q0[i]*F[i]%mod;
		NTT(Q0,lim,0);
		fill(Q0.v.begin(),Q0.v.begin()+nlim,0);
		for(int i=nlim;i<lim&&i<v.size();++i) Q0[i]=dec(Q0[i],v[i]);
		NTT(Q0,lim,1);
		for(int i=0;i<lim;++i) Q0[i]=1ll*Q0[i]*G0[i]%mod;
		NTT(Q0,lim,0);
		for(int i=nlim;i<lim;++i) ret[i]=dec(ret[i],Q0[i]); 
		return ret.slice(v.size());
	}
	
	inline poly poly::ln()const{
		return der().div(*this).jifen(); 
	}

	
	const int logB=4;
	const int B=16;
	namespace EXP{
		poly g[30][B];
		inline void exp(const poly &f,poly &ret,int lim,int l,int r){
			if(r-l<=128){
				for(int i=l;i<r;++i){
					ret[i]=(!i)?1:1ll*ret[i]*iv[i]%mod;
					for(int j=i+1;j<r;++j)	ret[j]=(ret[j]+1ll*ret[i]*f[j-i]%mod*(j-i))%mod;
				}
				return ;
			}
			int k=(r-l)/B;
			vector<unsigned long long> bl[16];
			poly T;
			for(int i=0;i<B;++i) bl[i].resize(k<<1);
			int len=1<<lim-logB+1;
			for(int i=0;i<B;++i){
				if(i>0){
					init(len);
					for(int j=0;j<(k<<1);++j) T[j]=bl[i][j]%mod;
					NTT(T,len,0);
					for(int j=0;j<k;++j)
						inc(ret[l+i*k+j],T[j+k]);
				}
				exp(f,ret,lim-logB,l+i*k,l+(i+1)*k);
				if(i<B-1){
					for(int j=0;j<k;++j) T[j+k]=0,T[j]=ret[j+l+i*k];
					init(len);NTT(T,len,1);
					for(int j=i+1;j<B;++j)
						for(int t=0;t<(k<<1);++t) 
							bl[j][t]+=1ll*T[t]*g[lim][j-i-1][t]; 
				}
			}
		}
	}
	
	inline poly poly::exp()const{
		poly f(v);
		int mx=lg[v.size()]+1;
		init_inv(1<<mx);
		poly ret;ret.resize(1<<mx);
		for(int lim=mx;lim>=8;lim-=logB){
			int bl=1<<(lim-logB),tot=0,ll=1<<(lim-logB+1);
			init(ll);
			for(int i=0;i<B-1;++i){
				EXP::g[lim][i].resize(bl<<1);
				for(int j=0;j<(bl<<1);++j) 
					EXP::g[lim][i][j]=1ll*f[j+bl*i]*(j+bl*i)%mod;
				NTT(EXP::g[lim][i],ll,1);
			}
		}
		EXP::exp(*this,ret,mx,0,1<<mx);
		return ret.slice(v.size());
	}
	
	
	inline poly poly::pow(int k)const{
		return ((*this).ln()*k).exp();
	}
	
	inline poly poly::operator /(const poly &Q)const{
		if(v.size()<Q.v.size()) return 0;
		int p=v.size()-Q.v.size()+1;
		poly fr=rev(),qr=Q.rev();
		fr.resize(p);qr.resize(p);
		return fr.div(qr).rev();
	} 
	inline poly poly::operator %(const poly &Q)const{
		poly F(v);
		return 	(F-(Q*(F/Q))).slice(Q.v.size()-1);
	} 
	inline poly poly::sqrt()const{
		poly g,h,gf,F1,F2,F3,f(v);
		g[0]=cipolla(operator[](0));
		h[0]=ksm(g[0],mod-2);
		gf[0]=g[0];gf[1]=g[0];
		int iv=(mod+1)/2; 
		init(1);
		for(int lim=1;lim<v.size();lim<<=1){
			for(int i=0;i<lim;++i) F1[i]=1ll*gf[i]*gf[i]%mod;
			NTT(F1,lim,0);
			for(int i=0;i<lim;++i) F1[i+lim]=dec(F1[i],f[i]),F1[i]=0;
				
			int nlim=lim<<1;init(nlim);
			for(int i=lim;i<nlim;++i) rec(F1[i],f[i]);
			F2=h;F2.resize(lim);
			NTT(F1,nlim,1);NTT(F2,nlim,1);
			
			for(int i=0;i<nlim;++i) F1[i]=1ll*F1[i]*F2[i]%mod;
			NTT(F1,nlim,0);
			for(int i=lim;i<nlim;++i) g[i]=dec(0,1ll*F1[i]*iv%mod); 
			
			if(nlim<v.size()){
				gf=g;
				NTT(gf,nlim,1);
				for(int i=0;i<nlim;++i) F3[i]=1ll*gf[i]*F2[i]%mod;
				NTT(F3,nlim,0);
				fill(F3.v.begin(),F3.v.begin()+lim,0);
				NTT(F3,nlim,1);
				for(int i=0;i<nlim;++i) F3[i]=1ll*F3[i]*F2[i]%mod;
				NTT(F3,nlim,0);
				for(int i=lim;i<nlim;++i) rec(h[i],F3[i]);
			}
		}
		return g.slice(v.size());
	}
}
using namespace Poly;

int n,m,a[N],sf[N],sg[N];poly f,g,h;
inline void solve(int l,int r){
	if(l==r) return ;
	int mid=(l+r)>>1;
	poly ff,gg;ff.resize(mid-l+1);gg.resize(r-mid);
	for(int i=l,j=0;i<=mid;++i,++j) ff[j]=f[i];
	for(int i=mid+1,j=0;i<=r;++i,++j) gg[j]=g[i];
	ff=ff*gg;
	for(int i=0;i<ff.size()&&i+l+mid+1<=(n<<1);++i) inc(h[i+l+mid+1],ff[i]);
	solve(l,mid);solve(mid+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,x;i<=m;++i) scanf("%d",&x),f[x]=g[x]=1;
	for(int i=1;i<=n;++i) f[i]+=f[i-1];
	for(int i=n;i>=1;--i) g[i]+=g[i+1];
	for(int i=1;i<=n;++i) f[i]=ksm(2,f[i]),sf[i]=add(sf[i-1],f[i]);
	for(int i=n;i>=1;--i) g[i]=ksm(2,g[i]),sg[i]=add(sg[i+1],g[i]);
	init_poly((n+1)<<1);
	solve(1,n);
	int ans=0;
	for(int i=1;i<=n;++i){
		int ret=0;
		if(i+i<=n) inc(ret,sg[i+i]);
		if(2*i>n+1) inc(ret,sf[2*i-n-1]);
		inc(ret,n-max(i-1,n-i));
		inc(ret,h[i<<1]);
		inc(ans,1ll*dec(ret,n)*a[i]%mod);
	}
	printf("%d\n",1ll*ans*ksm(dec(ksm(2,m),1),mod-2)%mod);
	return 0;
}
