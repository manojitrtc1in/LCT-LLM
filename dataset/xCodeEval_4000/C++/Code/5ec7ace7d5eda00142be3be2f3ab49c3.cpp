#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <algorithm>
#include <deque>
#include <stdio.h>
#include <vector>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T power(T base,T index,T mod){return((index<=1)?(index?base:1):(power(base*base%mod,index>>1,mod)*power(base,index&1,mod)))%mod;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T exgcd(T a,T b,T&x,T&y){if(!b)return y=0,x=1,a;T ans=exgcd(b,a%b,y,x);y-=a/b*x;return ans;}
template<const ullt p=998244353>
class mod_ullt
{
    private:
        ullt v;
        inline ullt chg(ullt w){return(w<p)?w:w-p;}
        inline mod_ullt _chg(ullt w){mod_ullt ans;ans.v=(w<p)?w:w-p;return ans;}
    public:
        mod_ullt():v(0){}
        mod_ullt(ullt v):v(v%p){}
        bol empty(){return!v;}
        inline ullt val(){return v;}
        friend bol operator<(mod_ullt a,mod_ullt b){return a.v<b.v;}
        friend bol operator>(mod_ullt a,mod_ullt b){return a.v>b.v;}
        friend bol operator<=(mod_ullt a,mod_ullt b){return a.v<=b.v;}
        friend bol operator>=(mod_ullt a,mod_ullt b){return a.v>=b.v;}
        friend bol operator==(mod_ullt a,mod_ullt b){return a.v==b.v;}
        friend bol operator!=(mod_ullt a,mod_ullt b){return a.v!=b.v;}
        inline friend mod_ullt operator+(mod_ullt a,mod_ullt b){return a._chg(a.v+b.v);}
        inline friend mod_ullt operator-(mod_ullt a,mod_ullt b){return a._chg(a.v+a.chg(p-b.v));}
        inline friend mod_ullt operator*(mod_ullt a,mod_ullt b){return a.v*b.v;}
        friend mod_ullt operator/(mod_ullt a,mod_ullt b){return b._power(p-2)*a.v;}
        inline mod_ullt operator-(){return _chg(p-v);}
        mod_ullt sqrt()
        {
            if(power(v,(p-1)>>1,p)!=1)return 0;
            mod_ullt b=1;do b++;while(b._power((p-1)>>1)==1);
            ullt t=p-1,s=0,k=1;while(!(t&1))s++,t>>=1;
            mod_ullt x=_power((t+1)>>1),e=_power(t);
            while(k<s)
            {
                if(e._power(1llu<<(s-k-1))!=1)x*=b._power((1llu<<(k-1))*t);
                e=_power(p-2)*x*x,k++;
            }
            return _min(x,-x),x;
        }
        mod_ullt inv(){return _power(p-2);}
        mod_ullt _power(ullt index){mod_ullt ans(1),w(v);while(index){if(index&1)ans*=w;w*=w,index>>=1;}return ans;}
        voi read(){v=0;chr c;do c=getchar();while(c>'9'||c<'0');do v=(c-'0'+v*10)%p,c=getchar();while(c>='0'&&c<='9');v%=p;}
        voi print()
        {
        	static chr C[20];uint tp=0;
        	ullt w=v;do C[tp++]=w%10+'0',w/=10;while(w);
        	while(tp--)putchar(C[tp]);
        }
        voi println(){print(),putchar('\n');}
        mod_ullt operator++(int){mod_ullt ans=*this;return v=chg(v+1),ans;}
    public:
        inline ullt&operator()(){return v;}
        inline mod_ullt&operator+=(mod_ullt b){return*this=_chg(v+b.v);}
        inline mod_ullt&operator-=(mod_ullt b){return*this=_chg(v+chg(p-b.v));}
        inline mod_ullt&operator*=(mod_ullt b){return*this=v*b.v;}
        mod_ullt&operator/=(mod_ullt b){return*this=b._power(p-2)*v;}
        mod_ullt&operator++(){return v=chg(v+1),*this;}
};
template<const ullt p=998244353,const ullt g=3>
class poly_NTT
{
    public:
		typedef mod_ullt<p>modint;
	private:
		std::vector<modint>V;
	public:
		class NTT
		{
			private:
				uint n;uint*T;modint*G;
			public:
				NTT():n(0),T(NULL),G(NULL){}
				NTT(uint len)
				{
					n=1;while(n<len)n<<=1;
                    T=new uint[n],G=new modint[n],T[0]=0,G[0]=1;
					for(uint i=1;i<n;i++)T[i]=((i&1)?n|T[i>>1]:T[i>>1])>>1;
                    modint w=power(g,(p-1)/n,p),*End=G+n;
                    for(modint*_G=G+1;_G<End;_G++)*_G=_G[-1]*w;
				}
				~NTT(){if(T!=NULL)delete[]T,delete[]G,T=NULL,G=NULL;}
				inline uint size(){return n;}
				voi bzr(uint len)
				{
					n=1;while(n<len)n<<=1;
                    if(T!=NULL)delete[]T,delete[]G;
                    T=new uint[n],G=new modint[n],T[0]=0,G[0]=1;
					for(uint i=1;i<n;i++)T[i]=((i&1)?n|T[i>>1]:T[i>>1])>>1;
                    modint w=power(g,(p-1)/n,p),*End=G+n;
                    for(modint*_G=G+1;_G<End;_G++)*_G=_G[-1]*w;
				}
				voi ntt(std::vector<modint>&x,bol op)
				{
					if(x.size()<n)x.resize(n);
                    for(uint i=0;i<n;i++)if(T[i]<i)std::swap(x[i],x[T[i]]);
					for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)
					{
						modint*w=G;
						for(uint k=0;k<i;k++,w+=n/(2*i))
						{
							modint t=x[i+j+k]*(*w);
							x[i+j+k]=x[j+k]-t,x[j+k]+=t;
						}
					}
					if(op)
					{
						for(uint i=1;i*2<n;i++)std::swap(x[i],x[n-i]);
						modint t=modint(n).inv();for(uint i=0;i<n;i++)x[i]*=t;
					}
				}
				inline modint Omega(uint n){return G[n%size()];}
				NTT&operator=(NTT b)
				{
					if(T!=NULL)delete[]T,delete[]G,T=NULL,G=NULL;
					if(b.T==NULL)return*this;
					T=new uint[n],G=new modint[n=b.n];
					for(uint i=0;i<n;i++)T[i]=b.T[i],G[i]=b.G[i];
					return*this;
				}
		};
		class DIFDIT
		{
			private:
				uint n;modint*G;
			public:
				DIFDIT():n(0),G(NULL){}
				DIFDIT(uint len)
				{
					n=1;while(n<len)n<<=1;
                    G=new modint[n],G[0]=1;
                    modint w=power(g,(p-1)/n,p),*End=G+n;
                    for(modint*_G=G+1;_G<End;_G++)*_G=_G[-1]*w;
				}
				~DIFDIT(){if(G!=NULL)delete[]G,G=NULL;}
				inline uint size(){return n;}
				voi bzr(uint len)
				{
					n=1;while(n<len)n<<=1;
                    if(G!=NULL)delete[]G;
                    G=new modint[n],G[0]=1;
                    modint w=power(g,(p-1)/n,p),*End=G+n;
                    for(modint*_G=G+1;_G<End;_G++)*_G=_G[-1]*w;
				}
				voi dif(std::vector<modint>&x)
				{
					if(x.size()<n)x.resize(n);
					for(uint i=n>>1;i;i>>=1)for(uint j=0;j<n;j+=i<<1) 
					{
						modint*w=G;
						for(uint k=0;k<i;k++,w+=n/(2*i))
						{
							modint u=x[j+k],t=x[i+j+k];
							x[j+k]=u+t,x[i+j+k]=(u-t)*(*w);
						}
					}
				}
				voi dit(std::vector<modint>&x)
				{
					if(x.size()<n)x.resize(n);
					for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)
					{
						modint*w=G;
						for(uint k=0;k<i;k++,w+=n/(2*i))
						{
							modint t=x[i+j+k]*(*w);
							x[i+j+k]=x[j+k]-t,x[j+k]+=t;
						}
					}
					for(uint i=1;i*2<n;i++)std::swap(x[i],x[n-i]);
					modint t=modint(n).inv();for(uint i=0;i<n;i++)x[i]*=t;
				} 
				DIFDIT&operator=(DIFDIT b)
				{
					if(G!=NULL)delete[]G,G=NULL;
					if(b.G==NULL)return*this;
					G=new modint[n=b.n];
					for(uint i=0;i<n;i++)G[i]=b.G[i];
					return*this;
				}
		};
	public:
		poly_NTT(){}
		poly_NTT(uint n){V.resize(n);}
		poly_NTT(std::vector<modint>V):V(V){}
		inline voi bzr(){V.clear();}
		inline voi push(modint v){V.push_back(v);}
		inline voi pop(){V.pop_back();}
		inline voi cut_zero(){while(!V.empty()&&V.back().empty())V.pop_back();}
		inline voi chg_siz(uint n){V.resize(n);}
		inline voi chg_deg(uint n){V.resize(n+1);}
		inline bol empty(){return cut_zero(),V.empty();}
		inline uint size(){return V.size();}
		inline uint deg(){return V.size()-1;}
		inline modint val(uint n){return(n<size())?V[n]:0;}
        inline std::vector<modint>GET(){return V;}
        poly_NTT reverse()
        {
            poly_NTT ans;for(uint i=size()-1;~i;i--)ans.push(V[i]);
            return ans;
        }
		friend poly_NTT operator+(poly_NTT a,poly_NTT b)
		{
			if(a.size()<b.size())a.chg_siz(b.size());
			for(uint i=0;i<b.size();i++)a[i]+=b[i];
			a.cut_zero();return a;
		}
		friend poly_NTT operator+(poly_NTT a,modint v)
		{
			if(!a.size())a.chg_siz(1);
			a[0]+=v;return a;
		}
		friend poly_NTT operator+(modint v,poly_NTT a)
		{
			if(!a.size())a.chg_siz(1);
			a[0]+=v;return a;
		}
		friend poly_NTT operator-(poly_NTT a){return a*modint(p-1);}
		friend poly_NTT operator-(poly_NTT a,poly_NTT b)
		{
			if(a.size()<b.size())a.chg_siz(b.size());
			for(uint i=0;i<b.size();i++)a[i]-=b[i];
			a.cut_zero();return a;
		}
		friend poly_NTT operator-(poly_NTT a,modint v)
		{
			if(!a.size())a.chg_siz(1);
			a[0]-=v;return a;
		}
		friend poly_NTT operator-(modint v,poly_NTT a)
		{
			if(!a.size())a.chg_siz(1);
			a[0]-=v;return-a;
		}
		friend poly_NTT operator*(poly_NTT a,poly_NTT b)
		{
            std::vector<modint>&A=a.V,&B=b.V;DIFDIT s(A.size()+B.size());
            s.dif(A),s.dif(B);for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.dit(A),a.cut_zero();return a;
		}
        friend poly_NTT operator*(poly_NTT A,modint b)
        {
            for(auto&s:A.V)s*=b;
            return A;
        }
        friend poly_NTT operator*(modint b,poly_NTT A)
        {
            for(auto&s:A.V)s*=b;
            return A;
        }
        friend poly_NTT operator<<(poly_NTT a,uint k)
        {
        	poly_NTT ans;ans.chg_siz(k);for(auto v:a.V)ans.push(v);
        	return ans;
        }
        friend poly_NTT operator>>(poly_NTT a,uint k)
        {
        	poly_NTT ans;for(uint i=k;i<a.size();i++)ans.push(a[i]);
        	return ans;
        }
        friend poly_NTT sub_mul(poly_NTT a,poly_NTT b)
        {
            uint len=(a=a.reverse()).size();
            std::vector<modint>&A=a.V,&B=b.V;
            DIFDIT s(len+B.size());
            s.dif(A),s.dif(B);for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.dit(A),a.chg_siz(len),a=a.reverse();return a;
        }
        poly_NTT inv(){return inv(size());}
        poly_NTT inv(uint prec)
        {
            std::vector<modint>ans;DIFDIT s;ans.push_back(V[0].inv());
            for(uint tp=1;tp<prec;tp<<=1)
            {
                std::vector<modint>f(tp<<1),t=ans;
                for(uint i=0;i<(tp<<1);++i)f[i]=val(i);
                s.bzr(tp<<1),s.dif(f),s.dif(t);
                for(uint i=0;i<(tp<<1);++i)f[i]=1-f[i]*t[i];
                s.dit(f);
                for(uint i=0;i<tp;++i)f[i]=f[i+tp],f[i+tp]=0;
                s.dif(f);
                for(uint i=(tp<<1)-1;~i;--i)f[i]*=t[i];
                s.dit(f),ans.resize(tp<<1);
            	for(uint i=0;i<tp;++i)ans[i+tp]=f[i];
            }
            ans.resize(prec);return ans;
        }
        poly_NTT diff()
        {
            poly_NTT ans;for(uint i=1;i<size();i++)ans.push(i*V[i]);
            return ans;
        }
        poly_NTT inte()
        {
            if(!size())return*this;
            poly_NTT ans(size()+1);ans[1]=1;
            for(uint i=2;i<=size();i++)ans[i]=-ans[p%i]*(p/i);
            for(uint i=1;i<=size();i++)ans[i]*=V[i-1];
            return ans;
        }
        poly_NTT ln(){return ln(size());}
        poly_NTT ln(uint prec)
        {
            poly_NTT a=this->diff()*this->inv(prec);a.chg_siz(prec),a=a.inte(),a.chg_siz(prec);return a;
        }
        poly_NTT exp(){return exp(size());}
        poly_NTT exp(uint prec)
        {
            poly_NTT ans;std::vector<modint>Inv;ans.push(1),Inv.push_back(1);
            for(uint tp=1;tp<prec;tp<<=1)
            {
                std::vector<modint>f,ff=ans.diff().V;
                for(uint i=0;i<(tp<<1);i++)f.push_back(val(i));
                f[0]=1;DIFDIT s(tp<<2);s.dif(ans.V),s.dif(Inv);
                for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                s.dit(Inv),Inv.resize(tp);s.dif(Inv);
                for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                s.dit(Inv),Inv.resize(tp<<1);s.dif(Inv);s.dif(ff);
                for(uint i=0;i<(tp<<2);i++)ff[i]*=Inv[i];
                s.dit(ff);f=(f-poly_NTT(ff).inte()).V;s.dif(f);
                for(uint i=0;i<(tp<<2);i++)ans[i]*=f[i];
                s.dit(Inv),s.dit(ans.V),ans.chg_siz(tp<<1);
            }
            ans.chg_siz(prec);return ans;
        }
        friend poly_NTT operator/(poly_NTT a,poly_NTT b)
        {
            a.cut_zero(),b.cut_zero();if(a.size()<b.size())return poly_NTT();
            poly_NTT ans=a.reverse()*b.reverse().inv(a.size()-b.size()+1);
            ans.chg_siz(a.size()-b.size()+1);return ans.reverse();
        }
        friend poly_NTT operator%(poly_NTT a,poly_NTT b){return a-a/b*b;}
	public:
		inline modint&operator[](uint n){return V[n];};
        poly_NTT&operator+=(poly_NTT b)
        {
			if(size()<b.size())chg_siz(b.size());
			for(uint i=0;i<b.size();i++)V[i]+=b[i];
			cut_zero();return*this;
        }
        inline poly_NTT&operator+=(modint v)
        {
        	if(!size())chg_siz(1);
        	V[0]+=v;return*this;
        }
        poly_NTT&operator-=(poly_NTT b)
        {
			if(size()<b.size())chg_siz(b.size());
			for(uint i=0;i<b.size();i++)V[i]-=b[i];
			cut_zero();return*this;
        }
        inline poly_NTT&operator-=(modint v)
        {
        	if(!size())chg_siz(1);
        	V[0]-=v;return*this;
        }
        poly_NTT&operator*=(poly_NTT b)
        {
            std::vector<modint>&A=V,&B=b.V;
            DIFDIT s(A.size()+B.size());
            s.dif(A),s.dif(B);
            for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.dit(A),cut_zero();return*this;
        }
        poly_NTT&operator*=(modint v)
        {
        	for(auto&t:V)t*=v;
			return*this;
        }
        poly_NTT&operator/=(poly_NTT b){return*this=*this/b;}
        poly_NTT&operator%=(poly_NTT b){return*this=*this%b;}
        poly_NTT&operator<<=(uint v){return*this=*this<<v;}
        poly_NTT&operator>>=(uint v){return*this=*this>>v;}
};
template<const ullt p=998244353,const ullt g=3>
class poly_eval
{
    public:
		typedef mod_ullt<p>modint;typedef poly_NTT<p,g>poly;
    private:
        std::vector<poly>G,User;std::vector<modint>X;
        voi mult_eval_dfs1(uint u,uint l,uint r)
        {
            if(l+1==r){G[u].push(1),G[u].push(-X[l]);return;}
            uint mid=(l+r)/2;mult_eval_dfs1(u<<1,l,mid),mult_eval_dfs1(u<<1|1,mid,r),G[u]=G[u<<1]*G[u<<1|1];
        }
        voi mult_eval_dfs2(uint u,uint l,uint r)
        {
            User.back().chg_siz(r-l);
            if(l+1==r){X[l]=User.back().val(0);return;}
            uint mid=(l+r)/2;
            User.push_back(sub_mul(User.back(),G[u<<1|1])),mult_eval_dfs2(u<<1,l,mid);
            User.back()=sub_mul(User[User.size()-2],G[u<<1]),mult_eval_dfs2(u<<1|1,mid,r);
            User.pop_back();
        }
    public:
        voi mult_eval(poly P,std::vector<modint>&X)
        {
            if(X.empty())return;
            G.resize(X.size()<<2),User.clear(),this->X=X;
            mult_eval_dfs1(1,0,X.size());
            User.push_back(sub_mul(P,G[1].inv(std::max<uint>(P.size(),X.size())+1)));
            mult_eval_dfs2(1,0,X.size());
            G.clear(),User.clear(),X=this->X,this->X.clear();
        }
};
template<const ullt p=998244353,const ullt g=3>
class poly_inter
{
    public:
		typedef mod_ullt<p>modint;typedef poly_NTT<p,g>poly;typedef poly_eval<p,g>eval;
    private:
        std::vector<poly>Lim,F,G;eval E;std::vector<modint>X,H;
        voi dfs(uint l,uint r)
        {
            if(l+1==r)
            {
                F.push_back(poly()),F.back().push(H[l]),G.push_back(poly()),G.back().push(-X[l]),G.back().push(1);return;
            }
            uint mid=(l+r)>>1;dfs(l,mid),dfs(mid,r);
            F[F.size()-2]=F[F.size()-2]*G.back()+F.back()*G[G.size()-2],F.pop_back(),G[G.size()-2]*=G.back(),G.pop_back();
        }
    public:
        poly fast_inter(std::vector<modint>X,std::vector<modint>Y)
        {
            uint n=std::min(X.size(),Y.size());if(!n)return poly();
            X.resize(n),Y.resize(n),this->X=X;poly P;Lim.clear();
            for(uint i=0;i<n;i++)
            {
                P.bzr(),P.push(-X[i]),P.push(1);
                uint w=lowbit(i+1);while(w>>=1)P*=Lim.back(),Lim.pop_back();
                Lim.push_back(P);
            }
            P=Lim.back(),Lim.pop_back();while(Lim.size())P*=Lim.back(),Lim.pop_back();
            E.mult_eval(P.diff(),X),H.resize(n);for(uint i=0;i<n;i++)H[i]=Y[i]/X[i];
            F.clear(),G.clear(),dfs(0,n);
            poly ans=F.back();F.clear(),G.clear(),this->X.clear(),H.clear();return ans;
        }
};
const ullt Mod=998244353,g=3;
typedef mod_ullt<Mod>modint;
typedef poly_NTT<Mod,g>poly;
typedef poly_eval<Mod,g>eval;
typedef poly_inter<Mod,g>inter;
#include <bits/stdc++.h>
uint W[100005],A[100005][5],Ans[6][6];
std::vector<uint>QAQ;
typedef std::pair<uint,uint>Pair;
Pair P[6][6];
uint m;
uint lcs(uint a,uint b)
{
    for(uint i=0;i<m;i++)for(uint j=0;j<m;j++)
        if(A[a][i]==A[b][j])Ans[i+1][j+1]=Ans[i][j]+1,P[i+1][j+1]=Pair(i,j);
        else Ans[i+1][j+1]=std::max(Ans[i+1][j],Ans[i][j+1]),P[i+1][j+1]=Ans[i+1][j]>Ans[i][j+1]?Pair(i+1,j):Pair(i,j+1);
    QAQ.clear();
    Pair now=Pair(m,m);
    while(now!=Pair())
    {
        if(P[now.first][now.second].first<now.first&&P[now.first][now.second].second<now.second)QAQ.push_back(A[a][now.first]);
        now=P[now.first][now.second];
    }
    return Ans[m][m];
}
uint Id[100005],Now[100005],cnt=0;
const uint Lim[]={0,1,5,15,40,100};
int main()
{
    uint n;uint ans=-1;
    scanf("%u%u",&n,&m);
    for(uint i=0;i<n;i++)
    {
        for(uint j=0;j<m;j++)scanf("%u",A[i]+j);
        scanf("%u",W+i);
        std::sort(A[i],A[i]+m);
        Id[i]=i;
    }
    std::sort(Id,Id+n,[&](uint a,uint b){return W[a]<W[b];});
    for(uint i=0;i<n;i++)
    {
        uint p=Id[i];
        std::map<std::vector<uint>,uint>LCNT;
        for(uint j=0;j<cnt;j++)
        {
            uint c=lcs(p,Now[j]);
            LCNT[QAQ]++;
            if(!c)_min(ans,W[p]+W[Now[j]]);
        }
        bol b=true;
        for(auto p:LCNT)if(p.second>Lim[m-p.first.size()]){b=false;break;}
        if(b)Now[cnt++]=p;
    }
    printf("%d\n",(int)ans);
    return 0;
}