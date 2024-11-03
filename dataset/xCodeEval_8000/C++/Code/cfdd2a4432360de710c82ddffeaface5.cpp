#include <algorithm>
#include <stdio.h>
#include <vector>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T exgcd(T a,T b,T&x,T&y){if(b!=0){T ans=exgcd(b,a%b,y,x);y-=a/b*x;return ans;}else return y=0,x=1,a;}
template<typename T>T power(T base,T index,T mod)
{
    T ans=1%mod;
    while(index)
    {
        if(index&1)ans=ans*base%mod;
        base=base*base%mod,index>>=1;
    }
    return ans;
}
namespace ConstMod
{
    template<const ullt p>
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
            friend mod_ullt operator^(mod_ullt a,ullt b){return a._power(b);}
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
            mod_ullt&operator^=(ullt b){return*this=_power(b);}
            mod_ullt&operator/=(mod_ullt b){return*this=b._power(p-2)*v;}
            mod_ullt&operator++(){return v=chg(v+1),*this;}
    };
}
namespace NTT_POLY
{
    template<const ullt p,const ullt g>
    class poly_NTT
    {
        public:
            typedef ConstMod::mod_ullt<p>modint;
            typedef std::vector<modint>modvec;
        private:
            modvec V;
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
                    voi ntt(modvec&x,bol op)
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
                    voi dif(modvec&x)
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
                    voi dit(modvec&x)
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
            poly_NTT(modvec V):V(V){}
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
            inline modvec GET(){return V;}
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
                modvec&A=a.V,&B=b.V;DIFDIT s(A.size()+B.size());
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
                modvec&A=a.V,&B=b.V;
                DIFDIT s(len+B.size());
                s.dif(A),s.dif(B);for(uint i=0;i<s.size();i++)A[i]*=B[i];
                s.dit(A),a.chg_siz(len),a=a.reverse();return a;
            }
            poly_NTT inv(){return inv(size());}
            poly_NTT inv(uint prec)
            {
                modvec ans;DIFDIT s;ans.push_back(V[0].inv());
                for(uint tp=1;tp<prec;tp<<=1)
                {
                    modvec f(tp<<1),t=ans;
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
            poly_NTT sqrt(){return sqrt(size());}
            poly_NTT sqrt(uint prec)
            {
                modvec ans,Inv;ans.push_back(val(0).sqrt()),Inv.push_back(ans[0].inv());
                DIFDIT s;
                modint w=modint(2).inv();
                for(uint tp=1;tp<prec;tp<<=1)
                {
                    s.bzr(tp<<2);
                    modvec f(tp<<1);for(uint i=0;i<(tp<<1);i++)f[i]=val(i);
                    s.dif(Inv);s.dif(ans);
                    for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                    s.dit(Inv),Inv.resize(tp);s.dif(Inv);
                    for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                    s.dit(Inv),Inv.resize(tp<<1);
                    modvec user=Inv;s.dif(Inv),s.dif(f);
                    for(uint i=0;i<(tp<<2);i++)ans[i]=(ans[i]+Inv[i]*f[i])*w;
                    s.dit(ans),Inv=user,ans.resize(tp<<1);
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
                poly_NTT ans;modvec Inv;ans.push(1),Inv.push_back(1);
                for(uint tp=1;tp<prec;tp<<=1)
                {
                    modvec f,ff=ans.diff().V;
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
                modvec&A=V,&B=b.V;
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
    template<const ullt p,const ullt g>
    class poly_eval
    {
        public:
            typedef ConstMod::mod_ullt<p>modint;
            typedef std::vector<modint>modvec;
            typedef poly_NTT<p,g>poly;
        private:
            std::vector<poly>G,User;modvec X;
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
            voi operator()(poly P,modvec&X)
            {
                if(X.empty())return;
                G.resize(X.size()<<2),User.clear(),this->X=X;
                mult_eval_dfs1(1,0,X.size());
                User.push_back(sub_mul(P,G[1].inv(std::max<uint>(P.size(),X.size())+1)));
                mult_eval_dfs2(1,0,X.size());
                G.clear(),User.clear(),X=this->X,this->X.clear();
            }
    };
    template<const ullt p,const ullt g>
    class poly_inter
    {
        public:
            typedef ConstMod::mod_ullt<p>modint;
            typedef std::vector<modint>modvec;
            typedef poly_NTT<p,g>poly;
            typedef poly_eval<p,g>eval;
        private:
            std::vector<poly>Lim,F,G;modvec X,H;
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
            poly operator()(modvec X,modvec Y)
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
                eval()(P.diff(),X),H.resize(n);for(uint i=0;i<n;i++)H[i]=Y[i]/X[i];
                F.clear(),G.clear(),dfs(0,n);
                poly ans=F.back();F.clear(),G.clear(),this->X.clear(),H.clear();return ans;
            }
    };
    template<const ullt p,const ullt g>
    class poly_cpd
    {
        public:
            typedef ConstMod::mod_ullt<p>modint;
            typedef std::vector<modint>modvec;
            typedef poly_NTT<p,g>poly;
            modvec Turn(std::vector<llt>QAQ)
            {
                modvec ans;
                for(uint i=0;i<QAQ.size();i++)ans.push_back((QAQ[i]%(llt)p+p)%p);
                return ans;
            }
            modint point_eval(poly P,modint x)
            {
                modint ans;
                for(uint i=P.deg();~i;i--)ans=ans*x+P[i];
                return ans;
            }
            poly z_npow(poly P,uint n)
            {
                if(P.empty())return P;
                poly ans(P.deg()*n+1);
                for(uint i=0;i<P.size();i++)ans[i*n]+=P[i];
                return ans;
            }
            poly z_npow(poly P,uint n,uint prec)
            {
                poly ans(prec);
                for(uint i=0;i<P.size()&&i*n<prec;i++)ans[i*n]+=P[i];
                return ans;
            }
            poly z_mul_k(poly P,modint k)
            {
                modint t(1);
                for(uint i=0;i<P.size();i++)P[i]*=t,t*=k;
                return P;
            }
            poly z_add_v(poly P,modint v)
            {
                uint n=P.size();if(!n)return P;
                modvec A(n),B(n);
                A[0]=1;for(uint i=1;i<n;i++)A[i]=A[i-1]*i;
                B[n-1]=A[n-1].inv();for(uint i=n-1;i;i--)B[i-1]=B[i]*i;
                poly User(n);modint w(1);
                for(uint i=0;i<n;i++)P[i]*=A[i],User[i]=w*B[i],w*=v;
                P=sub_mul(P,User),P.chg_siz(n);
                for(uint i=0;i<n;i++)P[i]*=B[i];
                return P;
            }
            poly chg_siz(poly P,uint siz){P.chg_siz(siz);return P;}
            poly PolyaInv(poly P,uint prec){return(modint(1)-P).inv(prec);}
            poly PolyaExp(poly P,uint prec)
            {
                modvec inv(prec);
                inv[1]=1;for(uint i=2;i<prec;i++)inv[i]=(p/i)*-inv[p%i];
                poly ans(prec);
                for(uint i=1;i<prec;i++)for(uint j=1;i*j<prec&&j<P.size();j++)ans[i*j]+=P[j]*inv[i];
                return ans.exp(prec);
            }
            poly PolyaInv(poly P){return PolyaInv(P,P.size());}
            poly PolyaExp(poly P){return PolyaExp(P,P.size());}
            voi println(poly P,uint n)
            {
                for(uint i=0;i<n;i++){
                    if(i)putchar(' ');
                    P.val(i).print();
                }
                putchar('\n');
            }
            voi println(poly P){println(P,P.size());}
    };
    template<const ullt p,const ullt g>
    class poly_nums
    {
        public:
            typedef ConstMod::mod_ullt<p>modint;
            typedef std::vector<modint>modvec;
            typedef poly_NTT<p,g>poly;
            typedef poly_cpd<p,g>cpd;
            modvec PowSum(uint n,uint m)
            {
                modvec P(n+2),Q(n+2);
                P[0]=1;for(uint i=1;i<=n+1;i++)P[i]=P[i-1]*i;
                Q[n+1]=P[n+1].inv();for(uint i=n+1;i;i--)Q[i-1]=Q[i]*i;
                poly A(n+1);for(uint i=0;i<=n;i++)A[i]=Q[i+1];
                A=A.inv();
                poly B(n+1);modint v(1);for(uint i=0;i<=n;i++)B[i]=v*Q[i],v*=m;
                B=(B*A-A)>>1;B.chg_siz(n);
                for(uint i=0;i<n;i++)B[i]*=P[i];
                return B.GET();
            }
            modvec S1R(uint n)
            {
                if(!n)return modvec({modint(1)});
                if(n&1)return(S1R(n-1)*poly(modvec({n-1,1}))).GET();
                poly P=S1R(n>>1);P*=cpd().z_add_v(P,n>>1);return P.GET();
            }
            modvec S1C(uint n,uint prec)
            {
                if(n>=prec)return modvec(prec);
                modvec P(prec+1),Q(prec+1);
                P[0]=1;for(uint i=1;i<=prec;i++)P[i]=P[i-1]*i;
                Q[prec]=P[prec].inv();for(uint i=prec;i;i--)Q[i-1]=Q[i]*i;
                poly ans;
                for(uint i=1;i<=prec-n;i++)ans.push(Q[i]*P[i-1]);
                ans=(ans.ln(prec-n)*modint(n)).exp(prec-n)<<n;
                modint v=1;
                for(uint i=1;i<=n;i++)v*=i;
                ans=ans*v.inv();
                for(uint i=n;i<prec;i++)ans[i]*=P[i];
                return ans.GET();
            }
            modvec S2R(uint n)
            {
                modvec P(n+1),Q(n+1);
                P[0]=1;for(uint i=1;i<=n;i++)P[i]=P[i-1]*i;
                Q[n]=P[n].inv();for(uint i=n;i;i--)Q[i-1]=Q[i]*i;
                poly A(n+1),B(n+1);
                A[0]=!n;if(n)A[1]=1;
                std::vector<uint>Prime;
                std::vector<bol>Gone(n+1);
                for(uint i=2;i<=n;i++)
                {
                    if(!Gone[i]){Prime.push_back(i);modint v=modint(i)._power(n);for(ullt j=i;j<=n;j*=i)A[j]=v*A[j/i],Gone[j]=true;}
                    for(auto w:Prime)if(i*w<=n&&i%w){for(ullt j=w;i*j<=n;j*=w)A[i*j]=A[i]*A[j],Gone[i*j]=true;}else break;
                }
                for(uint i=0;i<=n;i++)A[i]*=Q[i],B[i]=(i&1?p-1:1)*Q[i];
                A*=B,A.chg_deg(n);
                return A.GET();
            }
            modvec S2C(uint n,uint prec)
            {
                if(n>=prec)return modvec(prec);
                modvec P(prec+1),Q(prec+1);
                P[0]=1;for(uint i=1;i<=prec;i++)P[i]=P[i-1]*i;
                Q[prec]=P[prec].inv();for(uint i=prec;i;i--)Q[i-1]=Q[i]*i;
                poly ans=PowSum(prec-n,n+1);
                ans[0]=0;for(uint i=1;i<prec-n;i++)ans[i]*=Q[i]*P[i-1];
                ans=ans.exp(prec-n)<<n;
                return ans.GET();
            }
    };
}
namespace FWT_MODINT
{
    template<const ullt p>
    class FWT_Mod
    {
        public:
            typedef ConstMod::mod_ullt<p>modint;
            typedef std::vector<modint>modvec;
        private:
            uint n;
        public:
            FWT_Mod():n(0){}
            voi bzr(uint len){n=1;while(n<len)n<<=1;}
            uint size(){return n;}
            voi OR(modvec&x,bol op)
            {
                if(x.size()<n)x.resize(n);
                for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
                    op?x[i+j+k]-=x[j+k]:x[i+j+k]+=x[j+k];
            }
            voi AND(modvec&x,bol op)
            {
                if(x.size()<n)x.resize(n);
                for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
                    op?x[j+k]-=x[i+j+k]:x[j+k]+=x[i+j+k];
            }
            voi XOR(modvec&x,bol op)
            {
                if(x.size()<n)x.resize(n);
                for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
                {
                    modint u=x[j+k],t=x[i+j+k];x[j+k]=u+t,x[i+j+k]=u-t;
                }
                if(op){modint v=modint(n).inv();for(uint i=0;i<n;i++)x[i]*=v;}
            }
    };
}
const ullt Mod=998244353,g=3;
typedef ConstMod::mod_ullt<Mod>modint;
typedef std::vector<modint>modvec;
typedef NTT_POLY::poly_NTT<Mod,g>poly;
typedef NTT_POLY::poly_eval<Mod,g>eval;
typedef NTT_POLY::poly_inter<Mod,g>inter;
typedef NTT_POLY::poly_cpd<Mod,g>cpd;
typedef NTT_POLY::poly_nums<Mod,g>nums;
typedef FWT_MODINT::FWT_Mod<Mod>FWT;
modint P[300005],Q[300005];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#endif
    P[0]=1;for(uint i=1;i<=300000;i++)P[i]=P[i-1]*i;
    Q[300000]=P[300000].inv();for(uint i=300000;i;i--)Q[i-1]=Q[i]*i;
    poly A;
    {
        poly X,Y;
        for(uint i=0;i<=150000;i++)X.push(Q[i]/(modint(2)^i)),X.push(0);
        for(uint i=0;i<=300000;i++)Y.push(Q[i]);
        A=X*Y;
    }
    uint t;scanf("%u",&t);
    while(t--)
    {
        uint n;scanf("%u",&n);
        modint ans;
        for(uint i=0;i*4<=n;i++)
            ans+=P[n-i*2]*Q[i]*A[n-i*4];
        ans.println();
    }
    return 0;
}
