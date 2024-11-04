#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x&-x
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
#define GETPOS(c,x) (lower_bound(ALL(c),x)-c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x),0,sizeof((x)))
#define Rint register int
#define ls (u<<1)
#define rs (u<<1|1)
typedef unsigned int unit;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<pii> Vpii;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(ull &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi);putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=998244353,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=2e6+10,MAXM=1e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

template <int _P>
struct Modint
{
    static constexpr int P=_P;
private :
    int v;
public :
    Modint() : v(0){}
    Modint(ll _v){v=_v%P;if(v<0)v+=P;}
    explicit operator int() const {return v;}
    explicit operator long long() const {return v;}
    explicit operator bool() const {return v>0;}
    bool operator == (const Modint &o) const {return v==o.v;}
    bool operator != (const Modint &o) const {return v!=o.v;}
    Modint operator - () const {return Modint(v?P-v:0);}
    Modint operator + () const {return *this;}
    Modint & operator ++ (){v++;if(v==P)v=0;return *this;}
    Modint & operator -- (){if(v==0)v=P;v--;return *this;}
    Modint operator ++ (int){Modint r=*this;++*this;return r;}
    Modint operator -- (int){Modint r=*this;--*this;return r;}
    Modint & operator += (const Modint &o){v+=o.v;if(v>=P)v-=P;return *this;}
    Modint operator + (const Modint & o)const{return Modint(*this)+=o;}
    Modint & operator -= (const Modint & o){v-=o.v;if(v<0)v+=P;return *this;}
    Modint operator - (const Modint &o)const {return Modint(*this)-=o;}
    Modint & operator *=(const Modint & o){v=(int)(((ll)v)*o.v%P);return *this;}
    Modint operator * (const Modint & o)const {return Modint(*this)*=o;}
    Modint & operator /= (const Modint & o){return (*this)*=o.Inv();}
    Modint operator / (const Modint & o)const{return Modint(*this)/=o;}
    friend Modint operator + (const Modint &x,const ll &o) {return x+(Modint)o;}
    friend Modint operator + (const ll &o,const Modint &x) {return x+(Modint)o;}
    friend Modint operator - (const Modint &x,const ll &o) {return x-(Modint)o;}
    friend Modint operator - (const ll &o,const Modint &x) {return (Modint)o-x;}
    friend Modint operator * (const Modint &x,const ll &o) {return x*(Modint)o;}
    friend Modint operator * (const ll &o,const Modint &x) {return x*(Modint)o;}
    friend Modint operator / (const Modint &x,const ll &o) {Modint c=o;return x*c.Inv();}
    friend Modint operator / (const ll &o,const Modint &x) {Modint c=o;return c*x.Inv();}
    Modint operator ^ (ll o)const{Modint r=1,t=v;while(o){if(o&1)r*=t;t*=t;o>>=1;}return r;}
    Modint operator ~ (){return (*this)^(P-2);}
    Modint Inv() const{return (*this)^(P-2);}
};

using mi=Modint<MOD>;

template<int P>
void _W(Modint<P> x){printf("%d",(int)x);}

template<int P>
void _R(Modint<P> &x){ll t;scanf("%lld",&t);x=t;}

template <int Ntt_mod, int Ntt_root> class NTT
{
    static constexpr int ntt_mod=Ntt_mod;
    static constexpr int ntt_root=Ntt_root;
    using mi=Modint<ntt_mod>;
    using poly=vector<mi>;
    static const int maxbit=30;
    mi e[maxbit],ie[maxbit],sum_e[maxbit],sum_ie[maxbit];
public:
    NTT()
    {
        int cnt=__builtin_ctz(ntt_mod-1);
        mi w=mi(ntt_root)^((ntt_mod-1)>>cnt),iw=w.Inv();
        for(int i=cnt;~i;i--,w*=w,iw*=iw)e[i]=w,ie[i]=iw;
        w=1;iw=1;
        for(int i=0;i<=cnt-2;i++)
        {
            sum_e[i]=e[i+2]*w;w*=ie[i+2];
            sum_ie[i]=ie[i+2]*iw;iw*=e[i+2];
        }
    }
    void ntt(poly &f,int sig)
    {
        const int n=SZ(f);
        int h=0;
        while((unsigned)(1<<h)<(unsigned)n)h++;
        if(~sig)
        {
            for(int i=0;i<h;i++)
            {
                mi s=1;
                for(int j=0,t=1<<i,gap=1<<(h-i-1);j<t;j++)
                {
                    for(int k=j<<(h-i);k<(j<<(h-i))+gap;k++)
                    {
                        mi x=f[k],y=f[gap+k]*s;
                        f[k]=x+y,f[gap+k]=x-y;
                    }
                    s*=sum_e[__builtin_ctz(~(unsigned int)j)];
                }
            }
        }
        else
        {
            for(int i=h-1;~i;i--)
            {
                mi s=1;
                for(int j=0,t=1<<i,gap=1<<(h-i-1);j<t;j++)
                {
                    for(int k=j<<(h-i);k<(j<<(h-i))+gap;k++)
                    {
                        mi x=f[k],y=f[gap+k];
                        f[k]=x+y,f[gap+k]=(x-y)*s;
                    }
                    s*=sum_ie[__builtin_ctz(~(unsigned int)j)];
                }
            }
            mi iv=~((mi)(1<<h));
            for(int i=0;i<(1<<h);i++)f[i]*=iv;
        }
    }
    void ntttmd(poly &A,poly B)
    {
        int h=0,n=SZ(A),m=SZ(B);
        while((1<<h)<n+m)h++;
        A.resize(1<<h);B.resize(1<<h);
        ntt(A,1);ntt(B,1);
        for(int i=0;i<(1<<h);i++)A[i]*=B[i];
        ntt(A,-1);
        A.resize(n+m-1);
    }
    poly polymult(poly A,poly B)
    {
        ntttmd(A,B);
        return A;
    }
    poly dotmul (poly A,long long b)
    {
        b%=ntt_mod;
        poly r(SZ(A));
        for(int i=0;i<SZ(A);i++)r[i]=A[i]*b;
        return r;
    }
    poly polyinv(poly A)
    {
        int n=SZ(A);
        int h=1;
        while(h<n)h<<=1;
        A.resize(h);
        poly B(1,~A[0]);
        for(int t=2;t<=h;t<<=1)
        {
            int t2=t<<1;
            poly tmp(t2);
            for(int i=0;i<t;i++)tmp[i]=A[i];
            B.resize(t2);
            ntt(B,1);ntt(tmp,1);
            for(int i=0;i<t2;i++)B[i]*=(((mi)2)-(B[i]*tmp[i]));
            ntt(B,-1);
            for(int i=t;i<t2;i++)B[i]=0;
        }
        B.resize(n);
        return B;
    }
    poly polyint(poly A)
    {
        poly r(SZ(A)+1);
        for(int i=0;i<SZ(A);i++)r[i+1]=A[i]/(i+1);
        return r;
    }
    poly polydif(poly A)
    {
        poly r(SZ(A));
        for(int i=0;i<SZ(A)-1;i++)r[i]=A[i+1]*(i+1);
        return r;
    }
    poly polyln(poly A)
    {
        int n=SZ(A);
        poly B=polyinv(A);
        A=polydif(A);
        ntttmd(B,A);
        B.resize(n);
        B=polyint(B);
        B.resize(n);
        return B;
    }
    poly polyexp(poly A)
    {
        poly B(1,1);
        int n=SZ(A),h=1;
        while(h<n)h<<=1;
        A.resize(h*2);
        for(int t=2;t<=h;t<<=1)
        {
            int t2=t<<1;
            B.resize(t2);
            poly tmp=polyln(B);
            tmp[0]=A[0]+1-tmp[0];
            for(int i=1;i<t2;i++)tmp[i]=A[i]-tmp[i];
            ntttmd(B,tmp);
            for(int i=t;i<t2;i++)B[i]=0;
        }
        B.resize(n);
        return B;
    }
    poly polypow(poly A,long long b)
    {
        poly B=polyln(A);
        B=dotmul(B,b);
        return polyexp(B);
    }
    poly polydiv(poly A,poly B){
        if(A.size()<B.size())return poly(1,0);
        reverse(ALL(A));
        reverse(ALL(B));
        size_t size=SZ(A)-SZ(B)+1;
        A.resize(size,0);B.resize(size,0);
        auto K=polymult(move(A),polyinv(move(B)));
        K.resize(size);
        reverse(K.begin(),K.end());
        return K;
    }
    poly polyadd(poly A,poly B)
    {
        if(A.size()<B.size())swap(A,B);
        for(int i=0;i<SZ(B);i++)A[i]+=B[i];
        return A;
    }
    poly polysub(poly A,poly B){
        if(A.size()<B.size())A.resize(B.size(),0);
        for(size_t i=0;i<B.size();i++)A[i]-=B[i];
        return A;
    }
    pair<poly,poly> polymod(poly A,poly B){
        if(A.size()<B.size())return{poly(1,0),A};
        auto K=polydiv(A,B);
        size_t size=B.size()-1;
        auto R=polysub(move(A),polymult(K,move(B)));
        R.resize(size);
        return {K,R};
    }
    poly polymodpow(poly A,ll n,poly P){
        poly ret(1,1);
        while(n){
            if(n&1)ret=polymod(polymult(ret,A),P).second;
            A=polymod(polymult(A,A),P).second;
            n>>=1;
        }
        return ret;
    }
    mi fib(poly K,poly V,ll n){
        assert(K.size()<=V.size());
        reverse(ALL(K));
        for(auto &j:K)j=-j;
        K.pb(1);
        poly X(2,0);
        X[1]=1;
        K=polymodpow(X,n,K);
        mi ans=0;
        for(size_t i=0;i<K.size();i++)ans+=V[i]*K[i];
        return ans;
    }
    poly bluestein(poly f,mi g,int m) 

    {
        int n=SZ(f);
        poly fac(n+m),inc(n+m);
        fac[0]=inc[0]=1;
        fac[1]=g;inc[1]=~fac[1];
        for(int i=2;i<n+m;i++)
            fac[i]=fac[i-1]*fac[1],inc[i]=inc[i-1]*inc[1];
        for(int i=2;i<n+m;i++)
            fac[i]*=fac[i-1],inc[i]*=inc[i-1];
        for(int i=0;i<n;i++)f[i]*=inc[i];
        poly b(n+m);
        for(int i=0;i<n+m;i++)b[i]=fac[i];
        reverse(ALL(f));
        ntttmd(f,b);
        poly ans;
        for(int i=n-1;i<n+m-1;i++)
            ans.pb(f[i]*inc[i-n+1]);
        return ans;
    }
    poly polymi(poly &vec,int k1,int k2,ll L)

    {
        int t=0;
        while(t<SZ(vec)&&!vec[t])t++;
        if(L*t>=SZ(vec))return poly(SZ(vec),0);
        poly c;
        for(int i=t;i<SZ(vec);i++)c.pb(vec[i]);
        mi tmp=c[0];
        for(auto &j:c)j/=tmp;
        c=polypow(c,k1);
        tmp=tmp^k2;
        poly ret(L*t);
        for(auto j:c)if(SZ(ret)<SZ(vec))ret.pb(j*tmp);
        return ret;
    }
    poly polysqrt(poly vec)
    {
        poly ret(1,1);
        int n=SZ(vec);
        for(int len=1;len<n*2;len<<=1)
        {
            poly F(len*2);
            for(int i=0;i<min(len*2,SZ(vec));i++)F[i]=vec[i];
            poly tmp=polymult(F,polyinv(ret));
            tmp=polyadd(tmp,ret);
            tmp.resize(len*2);
            swap(ret,tmp);
            ret=dotmul(ret,inv2);
        }
        ret.resize(n);
        return ret;
    }
};
NTT<MOD,3> ntt;
using poly=vector<mi>;

int n;
Vi g[MAXN];
int deg[MAXN];

void dfs(int u,int f)
{
    for(auto v:g[u])if(v!=f)
    {
        deg[u]++;
        dfs(v,u);
    }
}

mi fac[MAXN],inc[MAXN];

void fac_pre(int n)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
    inc[n]=~fac[n];
    for(int i=n;i;i--)inc[i-1]=inc[i]*i;
}

mi c(int di,int gao)
{
    if(di<gao||gao<0||di<0)return 0;
    return fac[di]*inc[gao]*inc[di-gao];
}

poly dp[MAXN];
int cnt[MAXN];

void solve()
{
    R(n);
    for(int i=1;i<n;i++)
    {
        int u,v;R(u,v);g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)cnt[deg[i]]++;
    poly t(1,1);
    for(int i=n;~i;i--)if(cnt[i])
    {
        poly tmp(cnt[i]+1,1);
        mi cz=1;
        for(int j=1;j<=cnt[i];j++)tmp[j]=c(cnt[i],j)*(cz*=i);
        ntt.ntttmd(t,tmp);
    }
    mi ans=0,op=1;
    for(int i=0;i<n;i++)
    {
        ans+=fac[n-i]*op*t[i];
        op=-op;
    }
    W(ans);
}

int main()
{
    fac_pre(300000);
    

    int T=1;
    

    for(int kase=1;kase<=T;kase++)
    {
        

        solve();
    }
    return 0;
}
