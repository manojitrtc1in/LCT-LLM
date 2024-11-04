
 #include<complex>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <time.h>
#include <cstdio>
#include <numeric>
#define mp make_pair
#define LL long long
#define LD long double
#define rei(x) scanf("%d",&x)
#define reii(x,y) scanf("%d%d",&x,&y)
#define reiii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second

#define rel(x) scanf("%I64d",&x);

#define ref(x) scanf("%lf",&x)
#define rec(x) scanf("%c",&x)
#define res(x) scanf("%s",x)
#define reli(x) scanf("%[^\n]s", x)
#define pb push_back
#define f(i, a, b) for(int i = a; i <= b; i++)
#define ms(Arr) memset(Arr,0,sizeof(Arr));
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
#define bit(a , b) (((a)>>(b))&1)
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define fout1 freopen("out1.txt","w",stdout)
#define ftest freopen("in.txt","w",stdout)
#define mul_con int _;rei(_);f(i,1,_)
using namespace std;
const int INF = 0x3f3f3f3f;
const LL mod = 1000000007;
const double e = 2.718281828459;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;




LL gcd(LL a, LL b)
{
    if (!b)return a;
    return gcd(b, a%b);
}

LL gcd1(int a, int b)
{
    if (!b)return a;
    return gcd(b, a%b);
}


LL pow_mod(LL a, LL b, LL c)
{
    LL ans = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}


int pow_int(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = ans * a;
        b = b / 2;
        a = a * a;
    }
    return ans;
}

LL pow_llong(LL a, LL b)
{
    LL ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = ans * a;
        b = b / 2;
        a = a * a;
    }
    return ans;
}


int Scan()
{
    int res = 0, flag = 0;
    char ch;
    if ((ch = getchar()) == '-')
    {
        flag = 1;
    }
    else if (ch >= '0' && ch <= '9')
    {
        res = ch - '0';
    }
    while ((ch = getchar()) >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
    }
    return flag ? -res : res;
}

void Out(int a)
{
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
        Out(a / 10);
    }
    putchar(a % 10 + '0');
}

LL jc_mod(LL a, LL b, LL mod)
{
    LL ans = 1;
    b = max(b, a - b);
    for (LL i = a; i > b; i--)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

double lg(double a)
{
    return (log(a) / log(10.0));
}

















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
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
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
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
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
















#define MAXNN 100010
void lisan(int *x, int n) {


    int data[MAXNN];
    f(i, 1, n)data[i] = x[i];
    sort(data + 1, data + 1 + n);

    int o = unique(data + 1, data + 1 + n) - data - 1;

    f(i, 1, n)x[i] = lower_bound(data + 1, data + 1 + o, x[i]) - data;

}
















LL calc(int M)
{
    return 1;
}
int sanfen(int L, int R)
{
    int M, RM;
    while (L + 1 < R)
    {
        M = (L + R) / 2;
        RM = (M + R) / 2;
        if (calc(M) < calc(RM)) 

            R = RM;
        else
            L = M;
    }
    return L;
}







int CaculateWeekDay(int y, int m, int d)
{
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return iWeek;
}




LL inv[2000022];
void init_inverse() {
    inv[1] = 1;
    for (int i = 2; i < 2000022; i++)
        inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
}













LL c[20][6];
int len[20];
LL ans = 0;
int I = 0;
void cc(int C,int z)
{
    

    if(C == 4)
    {
        if(z > I)
        {
            ans++;
        }
        return;
    }
    if(z > I)
    {
        ans = ans +  len[1] + 1;
        return;
    }
    if(len[I-z+1] > 0)
        for(int i = 0;i + C <= 3;i++)
            ans = ans + c[I-z][i];
    

    for(int j = 1;j < len[I-z+1];j++)
    {
        for(int i = 0;i + C + 1<= 3;i++)
            ans = ans + c[I-z][i];
    }
   

    if(len[I-z+1])
        cc(C+1,z+1);
    else
        cc(C,z+1);
}

LL cont(LL x)
{
    ans = 0;
    I = 0;
    ms(len);
    while(x)
    {
        len[++I] = x % 10;
        x /= 10;
    }
    
    

    cc(0,1);
    return ans;
}
int main()
{
    c[1][1] = 9;
    c[1][0] = 1;
    f(i,2,18)
    {
        c[i][0] = c[i-1][0];
        f(j,0,4)
        {
            c[i][j] = c[i-1][j];
            c[i][j] = c[i][j] + c[i-1][j-1] * 9;
        }
    }
    
    int rr;
    rei(rr); 
    f(i,1,rr)
    {
        LL l,r;
        rel(l);
        rel(r);
        LL ll = cont(l-1);
        LL rr = cont(r);
       

        printf("%I64d\n",rr-ll);
    }
    return 0;
} 









