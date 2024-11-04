





















using namespace std;



































typedef    long long        LL;
typedef    pair<int,int>    PII;
typedef    pair<LL,LL>      PLL;
typedef    vector<char>     VB;
typedef    vector<int>      VI;
typedef    vector<LL>       VL;
typedef    vector<PII>      VII;
typedef    vector<PLL>      VLL;
const int       dx[]={ 0, 1, 0,-1, 0, 1,-1, 1,-1};
const int       dy[]={-1, 0, 1, 0,-1, 1,-1,-1, 1};
const LL        LINF=0xfcfcfcfcfcfcfcfll;
const int       MOD=1000000007;
const int       fftmod=998244353;
const int       INF=0x3f3f3f3f;
const double    eps=0.00000001;
const double    ee=2.718281828459;
const double    pi=3.14159265358979323846l;
inline int myrand(int mod) { return ((LL)rand()<<32^(LL)rand()<<16^rand())%mod; }
inline int rand(int a,int b) { return a+myrand(b-a+1); }
template<class T>inline T _max(T a,T b) { return a>b?a:b; }
template<class T>inline T _min(T a,T b) { return a<b?a:b; }
template<class T>inline T _max(T a,T b,T c) { return _max(a,_max(b,c)); }
template<class T>inline T _min(T a,T b,T c) { return _min(a,_min(b,c)); }
template<class T>inline T _max(T a,T b,T c,T d) { return _max(a,_max(b,c,d)); }
template<class T>inline T _min(T a,T b,T c,T d) { return _min(a,_min(b,c,d)); }
inline char gtc() { static char bfi[Buff],*ci=bfi-1,*cl=ci; return ci==cl&&(cl=(ci=bfi-1)+fread(bfi,1,Buff,stdin),ci==cl)?EOF:*++ci; }
void readbit(double &ret,double bit=0.1,char chr=0) { if(chr=gtc(),isdigit(chr))ret+=(chr^'0')*bit,readbit(ret,bit*0.1); }
inline char _read(int &res,char flag=0,int sum=0,char chr=0) { while(chr=gtc(),!(isdigit(chr)||(chr^'-'?0:(chr=gtc(),flag=1)))) if(!~chr) return 0; while(isdigit(chr))sum=(sum+(sum<<2)<<1)+(chr^'0'),chr=gtc(); return (res=flag?-sum:sum,1); }
inline char _read(LL &res,char flag=0,LL sum=0,char chr=0) { while(chr=gtc(),!(isdigit(chr)||(chr^'-'?0:(chr=gtc(),flag=1)))) if(!~chr) return 0; while(isdigit(chr))sum=(sum+(sum<<2)<<1)+(chr^'0'),chr=gtc(); return (res=flag?-sum:sum,1); }
inline char _read(double &ret,char flag=0,LL sum=0,char chr=0) { while(chr=gtc(),!(isdigit(chr)||(chr^'-'?0:(chr=gtc(),flag=1)))) if(!~chr) return 0; while((isdigit(chr)))sum=(sum+(sum<<2)<<1)+(chr^'0'),chr=gtc(); if(ret=sum,!(chr^'.'))readbit(ret); return (ret=flag?-ret:ret,1); }
inline char _read(char &ch,char chr=0) { while(chr=gtc(),!(chr^' ')||!(chr^'\n')||!~chr) if(!~chr) return 0; return ch=chr; }
inline char _read(char *p,char chr=0) { while(chr=gtc(),!(chr^' ')||!(chr^'\n')||!~chr) if(!~chr) return 0; while(chr^'\n'&&~chr)*p++=chr,chr=gtc(); return !(*p=0); }
template<class T,class U>inline char _read(pair<T,U> &res) { return _read(res.ff),_read(res.ss); }
inline void ptc(char ch=0) { static char bfo[Buff],*co=bfo-1,*coe=co+Buff; if(!ch||(*++co=ch,co==coe))fwrite(bfo,1,co-bfo+1,stdout),co=bfo-1; }
inline void _out(bool x) { ptc(x?'1':'0'); }
void _out(int x) { if(x<0)ptc('-'),x=-x; if(x>9)_out(x/10); ptc(x%10^'0'); }
void _out(LL x) { if(x<0)ptc('-'),x=-x; if(x>9)_out(x/10); ptc(x%10^'0'); }
inline void _out(double x,int n=6) { if(x<0)ptc('-'),x=-x; _out((LL)x),x-=(LL)x,ptc('.'); while(n--)x*=10; _out(LL(x+0.5)); }
inline void _out(const char ch) { ptc(ch); }
inline void _out(const char *p) { while(*p)ptc(*p++); }
template<class T,class U>inline void _out(pair<T,U> x) { _out(x.ff),_out(' '),_out(x.ss); }


inline char _scan(int &res) { return scanf("%d%*c",&res)>0; }
inline char _scan(LL &res) { return scanf("%lld%*c",&res)>0; }
inline char _scan(double &ret) { return scanf("%lf%*c",&ret)>0; }
inline char _scan(char &ch) { return scanf("%c%*c",&ch)>0; }
inline char _scan(char *p) { return scanf("%s%*c",p)>0; }
template<class T,class U>inline char _scan(pair<T,U> &res) { return _scan(res.ff),_scan(res.ss); }
inline void _debug_() {}
inline void _debug(bool x) { _out(x); }
inline void _debug(int x) { _out(x); }
inline void _debug(LL x) { _out(x); }
inline void _debug(double x) { _out(x); }
inline void _debug(const char ch) { _out(ch); }
inline void _debug(const char *p) { _out(p); }
template<class T,class U>inline void _debug(pair<T,U> x) { _out('('),_out(x.ff),_out(','),_out(x.ss),_out(')'); }
template<class T,class ...U>void _debug_(T head,U ...tail) { _out(' '),_debug(head),_debug_(tail...); }
template<class ...T>inline void debug(T ...tail) { static int cnt=0; _debug_("





















struct Read { template<class T>Read operator >> (T &x) { _read(x); return *this; } template<class T>Read operator >> (T *x) { _read(x); return *this; } }read;
struct OUT { template<class T> OUT operator << (T x) { return _out(x^'\n'?(_out(' '),x):'\n'),*this; } }Out;
struct out { template<class T> OUT operator << (T x) { return _out(x),Out; } }out;
template<class T,class U>inline istream&operator>>(istream&os,pair<T,U>&p) { return os>>p.first>>p.second; }
template<class T,class U>inline pair<T,U>operator+(const pair<T,U>&p1,const pair<T,U>&p2) { return mp(p1.ff+p2.ff,p1.ss+p2.ss); }
template<class T,class U>inline pair<T,U>&operator+=(pair<T,U>&p1,const pair<T,U>&p2) { p1.ff+=p2.ff,p1.ss+=p2.ss; return p1; }
template<class T,class U>inline pair<T,U>operator-(const pair<T,U>&p1,const pair<T,U>&p2) { return mp(p1.ff-p2.ff,p1.ss-p2.ss); }
template<class T,class U>inline pair<T,U>&operator-=(pair<T,U>&p1,const pair<T,U>&p2) { p1.ff-=p2.ff,p1.ss-=p2.ss; return p1; }
constexpr LL power(LL x, int p) { return p?(x*power(x,p-1)):1; }
inline void normmod(LL &x,LL mod) { x%=mod; if(x<0)x+=mod; }

inline LL mulmod(LL x,LL n,LL mod,LL res=0) { for(normmod(x,mod),normmod(n,mod); n; x<<=1,res>=mod?res-=mod:0,x>=mod?x-=mod:0,n>>=1)n&1?res+=x:0; return res; }

inline LL mulmod(LL x,LL n,LL mod) { return __int128(x)*n%mod; }

inline LL pmod(LL x,LL n,LL mod=MOD,LL res=1) { for(normmod(x,mod); n; x=mod?x*x%mod:x*x,n>>=1)n&1?res=mod?res*x%mod:res*x:0; return res; }
inline LL id0(LL x,LL n,LL mod=MOD,LL res=1) { for(normmod(x,mod); n; x=mulmod(x,x,mod),n>>=1)n&1?res=mulmod(res,x,mod):0; return res; }
template<class T>inline T gcd(T a,T b) { while(b) { T t=a%b;a=b;b=t; } return a; }
template<class T>inline T id1(T u,T v,int sh1=0) {
    for(T eu,ev,d,dif; u&&v&&u^v; u-=d&~dif,v-=d&dif)
        eu=u&1,u>>=eu^1,ev=v&1,v>>=ev^1,sh1+=~(eu|ev)&1,d=u&v&1?u+v>>1:0,dif=u-v>>(sizeof(T)<<3)-1;
    return max(u,v)<<sh1;
}
template<class T>inline T lcm(T a,T b) { return a/gcd(a,b)*b; }
template<class T>inline T gcd(T a,T b,T c) { return gcd(gcd(a,b),c); }
template<class T>inline bool isprime(T x) {
    if(x<=4||!(x&1)||x%3==0)
        return x==2||x==3;
    for(T i=5; i*i<=x; i+=6)
        if(x%i==0||x%(i+2)==0)
            return 0;
    return 1;
}
inline bool id2(LL n) {
    if (n <= 1000) return isprime(n);
    LL s=n-1;int t=0;while(s%2==0)s/=2,++t;
    for(int a:{2,325,9375,28178,450775,9780504,1795265022}){if(!(a%=n))return 1;
        LL f=id0(a,s,n);if(f==1||f==n-1)continue;
        FOR(i,1,t-1)if((f=mulmod(f,f,n))==n-1)goto nextp;
        return 0;nextp:;
    }return 1;
}

int teble();
int main() {








    teble();
    ptc();
    return 0;
}











const int N=55;
char a[N][N];
int G[N][N];
int b[N],c[N];
int n,m,ans;

void dfs(int cnt,int flag,int s) {




    if(flag&1) {
        b[s]=cnt;
        FOR(i,1,m) {
            if(a[s][i]=='
                G[s][i]=cnt;
                dfs(cnt,!flag,i);
            }
        }
    }
    else {
        c[s]=cnt;
        FOR(i,1,n) {
            if(a[i][s]=='
                G[i][s]=cnt;
                dfs(cnt,!flag,i);
            }
        }
    }
}

int teble() {
    cin>>n>>m;
    FOR(i,1,n)cin>>a[i]+1;
    FOR(i,1,n) {
        if(b[i]==0)dfs(++ans,1,i);
    }
    FOR(i,1,n)FOR(j,1,m) {
        if(b[i]&&c[j]&&b[i]==c[j]&&a[i][j]=='.')return 0*puts("No");
    }
    puts("Yes");
    return 0;
}








