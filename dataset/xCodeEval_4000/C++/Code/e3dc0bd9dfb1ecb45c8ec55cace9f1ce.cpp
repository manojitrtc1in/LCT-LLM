#include<algorithm>
#include<assert.h>
#include<bitset>
#include<complex>
#include<ctype.h>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits.h>
#include<list>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<time.h>
#include<utility>
#include<vector>


using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
#define For(i,l,r) for(int i=l;i<=r;++i)
#define foreach(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();++i)
#define all(x) x.begin(),x.end()
#define SORT(x) sort(all(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SZ(x) ((int)(x.size()))
#define DREP(x) sort(all(x));x.erase(unique(x.begin(),x.end()),x.end())
#define INDEX(arr,index) (lower_bound(arr.begin(),arr.end(),index)-arr.begin())
#define Debug(x) cout<<#x<<"="<<x<<endl
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define tri(a,b,c) make_pair((a),make_pair((b),(c)))
#define XX first
#define YY second.first
#define ZZ second.second
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define abS(x) ((x)<0?-(x):(x))
const int inf=~0U>>1;
const long long linf=(long long)1e18;
const double eps=1e-6;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef vector<int>::iterator eit;
typedef pair<int,int> pi;
typedef pair<int,pair<int,int> > tri;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef set<int>::iterator sit;
typedef map<int,int> mii;
typedef map<int,int>::iterator mit;
typedef istringstream ISS;
typedef ostringstream OSS;
template<class T> string tostr(T a){
    OSS out;out<<a;return out.str();
}
struct debugger{
    template<typename T> debugger& operator ,(const T &x)
    {
        cerr<<x<<endl;
        return *this;
    }
}dbg;
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    

    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            

        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(bool &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    

    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    

    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    

    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-7)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; ll x2=x1/mul[y];
            print(x2);if (y>0){out('.');print(x1-x2*mul[y]);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    

    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++; }
    inline void println1(char *s){print(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out&&*(o-1)=='\n')*--o=0;puts(Out);}
    struct puts_write{
        ~puts_write(){flush1();}
    };
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
string name="", in=".in", out=".out";
#define J (")
#define N 2005
#define L 700005
bool a[N][N],visit[N][N];
int cx[L],cy[L],c1,n,cnt,cntC,cntS;
double dist[L],Ox,Oy;
void dfs(int x,int y){
    if (visit[x][y])return;
    visit[x][y]=1;++cnt;
    bool bo=0;Ox+=x;Oy+=y;
    for (int dx=-1;dx<=1;++dx)
        for (int dy=-1;dy<=1;++dy){
            int x1=x+dx,y1=y+dy;
            if (!a[x1][y1])++bo;
            else dfs(x1,y1);
        }
    if (bo)++c1,cx[c1]=x,cy[c1]=y;
}
void genMap(){
    static bool tmp[N][N];
    memcpy(tmp,a,sizeof(a));
    memset(a,0,sizeof(a));
    for (int i=4;i+3<=n;++i)
        for (int j=4;j+3<=n;++j){
            int cnt=0;
            for (int dx=-3;dx<=3;++dx)
                for (int dy=-3;dy<=3;++dy)cnt+=tmp[i+dx][j+dy];
            if (cnt>=23)a[i][j]=1;else a[i][j]=0;
        }
}
int main()
{
    //freopen("hard_1.in","r",stdin);
    //freopen("1.out","w",stdout);
    read(n);
    memset(visit,1,sizeof(visit));
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)read(a[i][j]),visit[i][j]=0;
    genMap();
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)if (!visit[i][j]&&a[i][j]){
            c1=0;cnt=0;Ox=0;Oy=0;
            dfs(i,j);
            if (cnt<130)continue;
            double max_d=0;int c1_pre=c1;
            Ox/=cnt;Oy/=cnt;
            //printf("O=(%.5lf,%.5lf)\n",Ox,Oy);
            for (int k=1;k<=c1;++k)
                dist[k]=sqrt((Ox-cx[k])*(Ox-cx[k])+(Oy-cy[k])*(Oy-cy[k]));
            for (int k=1;k<=c1;++k)max_d=max(max_d,dist[k]);
            for (int k=1;k<=c1;++k)dist[k]/=max_d;
            //for (int k=1;k<=c1;++k)printf("%.5lf\n",dist[k]);
            double ave=accumulate(dist+1,dist+c1+1,0.0)/c1,sum=0;
            for (int k=1;k<=c1;++k)sum+=(dist[k]-ave)*(dist[k]-ave);
            sum/=c1;sum=sqrt(sum);
            //printf("sum/ave=%.5lf sum=%.5lf ave=%.5lf sum=%d border=%d\n",sum/ave,sum,ave,cnt,c1);
            double div=sum/ave;
            if (div>0.045&&div<0.055)
            //if (div>0.035&&div<0.080)
            {
                printf("div=%.5lf cnt=%d\n",div,cnt);
                while (1);
            }
            if (div<0.060)++cntC;  //0.087
            else ++cntS;
            //goto end;
        }
    end:;
    printf("%d %d\n",cntC,cntS);
    //system("pause");for (;;);
    return 0;
}


