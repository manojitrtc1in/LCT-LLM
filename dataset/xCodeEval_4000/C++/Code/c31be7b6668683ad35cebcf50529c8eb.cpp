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
        ullt chg(ullt w){return(w<p)?w:w-p;}
        mod_ullt _chg(ullt w){mod_ullt ans;ans.v=(w<p)?w:w-p;return ans;}
        voi _print(ullt v){if(v>=10)_print(v/10);putchar('0'+v%10);}
    public:
        mod_ullt():v(0){}
        mod_ullt(ullt v):v(v%p){}
        bol empty(){return!v;}
        ullt val(){return v;}
        bol friend operator<(mod_ullt a,mod_ullt b){return a.v<b.v;}
        bol friend operator>(mod_ullt a,mod_ullt b){return a.v>b.v;}
        bol friend operator<=(mod_ullt a,mod_ullt b){return a.v<=b.v;}
        bol friend operator>=(mod_ullt a,mod_ullt b){return a.v>=b.v;}
        bol friend operator==(mod_ullt a,mod_ullt b){return a.v==b.v;}
        bol friend operator!=(mod_ullt a,mod_ullt b){return a.v!=b.v;}
        mod_ullt friend operator+(mod_ullt a,mod_ullt b){return a._chg(a.v+b.v);}
        mod_ullt friend operator-(mod_ullt a,mod_ullt b){return a._chg(a.v+a.chg(p-b.v));}
        mod_ullt friend operator*(mod_ullt a,mod_ullt b){return a.v*b.v;}
        mod_ullt friend operator/(mod_ullt a,mod_ullt b){return b._power(p-2)*a.v;}
        mod_ullt friend operator-(mod_ullt a){return a._chg(p-a.v);}
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
        voi print(){_print(v);}
        voi println(){_print(v),putchar('\n');}
        mod_ullt operator++(int){mod_ullt ans=*this;return v=chg(v+1),ans;}
    public:
        ullt&operator()(){return v;}
        mod_ullt&operator+=(mod_ullt b){return*this=_chg(v+b.v);}
        mod_ullt&operator-=(mod_ullt b){return*this=_chg(v+chg(p-b.v));}
        mod_ullt&operator*=(mod_ullt b){return*this=v*b.v;}
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
				std::vector<uint>T;std::vector<modint>G;
			public:
				uint size(){return T.size();}
				voi bzr(uint len)
				{
					uint n=1;while(n<len)n<<=1;
                    modint w=power(g,(p-1)/n,p);T.resize(n),G.resize(n),T[0]=0,G[0]=1;
					for(uint i=1;i<n;i++)T[i]=((i&1)?n|T[i>>1]:T[i>>1])>>1,G[i]=G[i-1]*w;
				}
				voi ntt(std::vector<modint>&x,bol op)
				{
					uint n=size();if(x.size()<n)x.resize(n);
                    for(uint i=0;i<n;i++)if(T[i]<i)std::swap(x[i],x[T[i]]);
					for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
					{
						modint t=x[i+j+k]*G[n/(2*i)*k];x[i+j+k]=x[j+k]-t,x[j+k]+=t;
					}
					if(op)
					{
						for(uint i=1;i*2<n;i++)std::swap(x[i],x[n-i]);
						modint t=modint(n).inv();for(uint i=0;i<n;i++)x[i]*=t;
					}
				}
		};
	public:
		poly_NTT(){}
		poly_NTT(uint n){V.resize(n);}
		poly_NTT(std::vector<modint>V):V(V){}
		voi bzr(){V.clear();}
		voi push(modint v){V.push_back(v);}
		voi pop(){V.pop_back();}
		voi cut_zero(){while(!V.empty()&&V.back().empty())V.pop_back();}
		voi chg_siz(uint n){V.resize(n);}
		voi chg_deg(uint n){V.resize(n+1);}
		bol empty(){return cut_zero(),V.empty();}
		uint size(){return V.size();}
		uint deg(){return V.size()-1;}
		modint val(uint n){return(n<size())?V[n]:0;}
        poly_NTT reverse()
        {
            poly_NTT ans;for(uint i=size()-1;~i;i--)ans.push(V[i]);
            return ans;
        }
		friend poly_NTT operator+(poly_NTT a,poly_NTT b)
		{
			if(a.size()<b.size())a.chg_siz(b.size());
			for(uint i=0;i<b.size();i++)a[i]+=b[i];
			a.cut_zero();
			return a;
		}
		friend poly_NTT operator-(poly_NTT a,poly_NTT b)
		{
			if(a.size()<b.size())a.chg_siz(b.size());
			for(uint i=0;i<b.size();i++)a[i]-=b[i];
			a.cut_zero();
			return a;
		}
		friend poly_NTT operator*(poly_NTT a,poly_NTT b)
		{
            std::vector<modint>&A=a.V,&B=b.V;
            NTT s;s.bzr(A.size()+B.size());
            s.ntt(A,0),s.ntt(B,0);
            for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.ntt(A,1),a.cut_zero();
			return a;
		}
        friend poly_NTT sub_mul(poly_NTT a,poly_NTT b)
        {
            uint len=(a=a.reverse()).size();
            std::vector<modint>&A=a.V,&B=b.V;
            NTT s;s.bzr(len+B.size());
            s.ntt(A,0),s.ntt(B,0);
            for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.ntt(A,1),a.chg_siz(len),a=a.reverse();
            return a;
        }
        poly_NTT inv(){return inv(size());}
        poly_NTT inv(uint prec)
        {
            std::vector<modint>ans;NTT s;ans.push_back(V[0].inv());
            for(uint tp=1;tp<=prec;tp<<=1)
            {
                std::vector<modint>f(tp<<1),t=ans;for(uint i=0;i<(tp<<1);++i)f[i]=val(i);
                s.bzr(tp<<1),s.ntt(f,0),s.ntt(t,0);for(uint i=0;i<(tp<<1);++i)f[i]=-f[i]*t[i]+1;
                s.ntt(f,1);for(uint i=0;i<tp;++i)f[i]=f[i+tp],f[i+tp]=0;
                s.ntt(f,0);for(uint i=(tp<<1)-1;~i;--i)f[i]*=t[i];
                s.ntt(f,1),ans.resize(tp<<1);for(uint i=0;i<tp;++i)ans[i+tp]=f[i];
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
            poly_NTT a=this->diff()*this->inv(prec);
            a.chg_siz(prec),a=a.inte(),a.chg_siz(prec);return a;
        }
        poly_NTT exp(){return exp(size());}
        poly_NTT exp(uint prec)
        {
            poly_NTT ans;std::vector<modint>Inv;ans.push(1),Inv.push_back(1);
            for(uint tp=1;tp<=prec;tp<<=1)
            {
                std::vector<modint>f,ff=ans.diff().V;
                for(uint i=0;i<(tp<<1);i++)f.push_back(val(i));
                f[0]=1;NTT s;s.bzr(tp<<2);s.ntt(ans.V,0),s.ntt(Inv,0);
                for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                s.ntt(Inv,1),Inv.resize(tp);s.ntt(Inv,0);
                for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                s.ntt(Inv,1),Inv.resize(tp<<1);s.ntt(Inv,0);s.ntt(ff,0);
                for(uint i=0;i<(tp<<2);i++)ff[i]*=Inv[i];
                s.ntt(ff,1);f=(f-poly_NTT(ff).inte()).V;s.ntt(f,0);
                for(uint i=0;i<(tp<<2);i++)ans[i]*=f[i];
                s.ntt(Inv,1),s.ntt(ans.V,1),ans.chg_siz(tp<<1);
            }
            ans.chg_siz(prec);
            return ans;
        }
	public:
		modint&operator[](uint n){return V[n];};
        poly_NTT&operator+=(poly_NTT b)
        {
			if(size()<b.size())chg_siz(b.size());
			for(uint i=0;i<b.size();i++)V[i]+=b[i];
			cut_zero();
			return*this;
        }
        poly_NTT&operator-=(poly_NTT b)
        {
			if(size()<b.size())chg_siz(b.size());
			for(uint i=0;i<b.size();i++)V[i]-=b[i];
			cut_zero();
			return*this;
        }
        poly_NTT&operator*=(poly_NTT b)
        {
            std::vector<modint>&A=V,&B=b.V;
            NTT s;s.bzr(A.size()+B.size());
            s.ntt(A,0),s.ntt(B,0);
            for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.ntt(A,1),cut_zero();
			return*this;
        }
};
template<const ullt p=998244353,const ullt g=3>
class poly_eval
{
    public:
		typedef mod_ullt<p>modint;
        typedef poly_NTT<p,g>poly;
    private:
        std::vector<poly>G,User;
        std::vector<modint>X;
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
		typedef mod_ullt<p>modint;
        typedef poly_NTT<p,g>poly;
        typedef poly_eval<p,g>eval;
    private:
        std::vector<poly>Lim;eval E;
        std::vector<modint>X,H;
        std::vector<poly>F,G;
        voi dfs(uint l,uint r)
        {
            if(l+1==r)
            {
                F.push_back(poly()),F.back().push(H[l]);
                G.push_back(poly()),G.back().push(-X[l]),G.back().push(1);
                return;
            }
            uint mid=(l+r)>>1;dfs(l,mid),dfs(mid,r);
            F[F.size()-2]=F[F.size()-2]*G.back()+F.back()*G[G.size()-2],F.pop_back();
            G[G.size()-2]*=G.back(),G.pop_back();
        }
    public:
        poly fast_inter(std::vector<modint>X,std::vector<modint>Y)
        {
            uint n=std::min(X.size(),Y.size());
            if(!n)return poly();
            X.resize(n),Y.resize(n),this->X=X;poly P;Lim.clear();
            for(uint i=0;i<n;i++)
            {
                P.bzr(),P.push(-X[i]),P.push(1);
                uint w=lowbit(i+1);
                while(w>>=1)P*=Lim.back(),Lim.pop_back();
                Lim.push_back(P);
            }
            P=Lim.back(),Lim.pop_back();while(Lim.size())P*=Lim.back(),Lim.pop_back();
            E.mult_eval(P.diff(),X),H.resize(n);for(uint i=0;i<n;i++)H[i]=Y[i]/X[i];
            F.clear(),G.clear(),dfs(0,n);
            poly ans=F.back();F.clear(),G.clear(),this->X.clear(),H.clear();return ans;
        }
};
const ullt Mod=998244353;
typedef mod_ullt<Mod>modint;
typedef poly_NTT<Mod,3>poly;
typedef poly_eval<Mod,3>eval;
typedef poly_inter<Mod,3>inter;
chr C[100005][3];
bol equal(chr c1,chr c2){return c1=='?'||c2=='?'||c1==c2;}
bol equal(chr*c1,const chr*c2){return equal(c1[0],c2[0])&&equal(c1[1],c2[1]);}
uint P[3][3][3];
int main()
{
    uint n;scanf("%u",&n);
    modint v(1);
    bol b1=true,b2=true;
    for(uint i=0;i<n;i++)
    {
        scanf("%s",C[i]);
        poly a;
        a.bzr(),a.chg_siz(3);
        if(equal(C[i],"BB"))a[0]=1;
        if(equal(C[i],"WW"))a[2]=1;
        if(equal(C[i],"BW"))a[1]=1;else b1=false;
        if(equal(C[i],"WB"))a[1]++;else b2=false;
        v*=a[1];
        P[a[0]()][a[1]()][a[2]()]++;
    }
    poly::NTT s;
    s.bzr(n<<1);
    std::vector<modint>User(s.size());
    for(uint i=0;i<s.size();i++)User[i]=1;
    for(uint i=0;i<2;i++)for(uint j=0;j<3;j++)for(uint k=0;k<2;k++)if(P[i][j][k])
    {
        std::vector<modint>V;
        V.push_back(i),V.push_back(j),V.push_back(k),V.resize(s.size());
        s.ntt(V,0);
        for(uint p=0;p<s.size();p++)User[p]*=V[p]._power(P[i][j][k]);
    }
    s.ntt(User,1);
    (User[n]-v+b1+b2).println();
    return 0;
}
