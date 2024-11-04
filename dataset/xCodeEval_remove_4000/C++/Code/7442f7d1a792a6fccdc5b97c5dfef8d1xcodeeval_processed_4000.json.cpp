


























using namespace std;




























const int inf = ~0U >> 1;
const long long linf = (long long)1e18;
const double eps = 1e-6;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef vector<int>::iterator eit;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int> > tri;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef set<int>::iterator sit;
typedef map<int, int> mii;
typedef map<int, int>::iterator mit;
typedef istringstream ISS;
typedef ostringstream OSS;
template<class T> string tostr(T a)
{
    OSS out;
    out << a;
    return out.str();
}
struct debugger
{
    template<typename T> debugger &operator , (const T &x)
    {
        cerr << x << endl;
        return *this;
    }
} dbg;
namespace fastIO
{



    

    bool IOerror = 0;
    inline char nc()
    {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend)
        {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if (pend == p1)
            {
                IOerror = 1;
                return -1;
            }
            

        }
        return *p1++;
    }
    inline bool blank(char ch)
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x)
    {
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        if (ch == '-')sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
        if (sign)x = -x;
    }
    inline void read(ll &x)
    {
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        if (ch == '-')sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
        if (sign)x = -x;
    }
    inline void read(double &x)
    {
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        if (ch == '-')sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
        if (ch == '.')
        {
            double tmp = 1;
            ch = nc();
            for (; ch >= '0' && ch <= '9'; ch = nc())tmp /= 10.0, x += tmp * (ch - '0');
        }
        if (sign)x = -x;
    }
    inline void read(char *s)
    {
        char ch = nc();
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        for (; !blank(ch) && !IOerror; ch = nc()) * s++ = ch;
        *s = 0;
    }
    inline void read(char &c)
    {
        for (c = nc(); blank(c); c = nc());
        if (IOerror)
        {
            c = -1;
            return;
        }
    }
    

    inline void read1(int &x)
    {
        char ch;
        int bo = 0;
        x = 0;
        for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())if (ch == '-')bo = 1;
        for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
        if (bo)x = -x;
    }
    inline void read1(ll &x)
    {
        char ch;
        int bo = 0;
        x = 0;
        for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())if (ch == '-')bo = 1;
        for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
        if (bo)x = -x;
    }
    inline void read1(double &x)
    {
        char ch;
        int bo = 0;
        x = 0;
        for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())if (ch == '-')bo = 1;
        for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
        if (ch == '.')
        {
            double tmp = 1;
            for (ch = getchar(); ch >= '0' && ch <= '9'; tmp /= 10.0, x += tmp * (ch - '0'), ch = getchar());
        }
        if (bo)x = -x;
    }
    inline void read1(char *s)
    {
        char ch = getchar();
        for (; blank(ch); ch = getchar());
        for (; !blank(ch); ch = getchar()) * s++ = ch;
        *s = 0;
    }
    inline void read1(char &c)
    {
        for (c = getchar(); blank(c); c = getchar());
    }
    

    inline void read2(int &x)
    {
        scanf("%d", &x);
    }
    inline void read2(ll &x)
    {

        scanf("%I64d", &x);


        scanf("%lld", &x);

        puts("error:can't recognize the system!");


    }
    inline void read2(double &x)
    {
        scanf("%lf", &x);
    }
    inline void read2(char *s)
    {
        scanf("%s", s);
    }
    inline void read2(char &c)
    {
        scanf(" %c", &c);
    }
    inline void id5(char *s)
    {
        gets(s);
    }
    

    struct id1
    {
        char *buf, *p1, *pend;
        id1()
        {
            buf = new char[BUF_SIZE];
            p1 = buf;
            pend = buf + BUF_SIZE;
        }
        void out(char ch)
        {
            if (p1 == pend)
            {
                fwrite(buf, 1, BUF_SIZE, stdout);
                p1 = buf;
            }
            *p1++ = ch;
        }
        void print(int x)
        {
            static char s[15], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while(x)*s1++ = x % 10 + '0', x /= 10;
            while(s1-- != s)out(*s1);
        }
        void println(int x)
        {
            static char s[15], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while(x)*s1++ = x % 10 + '0', x /= 10;
            while(s1-- != s)out(*s1);
            out('\n');
        }
        void print(ll x)
        {
            static char s[25], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while(x)*s1++ = x % 10 + '0', x /= 10;
            while(s1-- != s)out(*s1);
        }
        void println(ll x)
        {
            static char s[25], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while(x)*s1++ = x % 10 + '0', x /= 10;
            while(s1-- != s)out(*s1);
            out('\n');
        }
        void print(double x, int y)
        {
            static ll mul[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,
                               1000000000, 10000000000LL, 100000000000LL, 1000000000000LL, 10000000000000LL,
                               100000000000000LL, 1000000000000000LL, 10000000000000000LL, 100000000000000000LL
                              };
            if (x < -1e-7)out('-'), x = -x;
            x *= mul[y];
            ll x1 = (ll)floor(x);
            if (x - floor(x) >= 0.5)++x1;
            ll x2 = x1 / mul[y];
            print(x2);
            if (y > 0)
            {
                out('.');
                print(x1 - x2 * mul[y]);
            }
        }
        void println(double x, int y)
        {
            print(x, y);
            out('\n');
        }
        void print(char *s)
        {
            while (*s)out(*s++);
        }
        void println(char *s)
        {
            while (*s)out(*s++);
            out('\n');
        }
        void flush()
        {
            if (p1 != buf)
            {
                fwrite(buf, 1, p1 - buf, stdout);
                p1 = buf;
            }
        }
        ~id1()
        {
            flush();
        }
    } Ostream;
    inline void print(int x)
    {
        Ostream.print(x);
    }
    inline void println(int x)
    {
        Ostream.println(x);
    }
    inline void print(char x)
    {
        Ostream.out(x);
    }
    inline void println(char x)
    {
        Ostream.out(x);
        Ostream.out('\n');
    }
    inline void print(ll x)
    {
        Ostream.print(x);
    }
    inline void println(ll x)
    {
        Ostream.println(x);
    }
    inline void print(double x, int y)
    {
        Ostream.print(x, y);
    }
    inline void println(double x, int y)
    {
        Ostream.println(x, y);
    }
    inline void print(char *s)
    {
        Ostream.print(s);
    }
    inline void println(char *s)
    {
        Ostream.println(s);
    }
    inline void println()
    {
        Ostream.out('\n');
    }
    inline void flush()
    {
        Ostream.flush();
    }
    

    char Out[OUT_SIZE], *o = Out;
    inline void print1(int x)
    {
        static char buf[15];
        char *p1 = buf;
        if (!x)*p1++ = '0';
        if (x < 0)*o++ = '-', x = -x;
        while(x)*p1++ = x % 10 + '0', x /= 10;
        while(p1-- != buf)*o++ = *p1;
    }
    inline void println1(int x)
    {
        print1(x);
        *o++ = '\n';
    }
    inline void print1(ll x)
    {
        static char buf[25];
        char *p1 = buf;
        if (!x)*p1++ = '0';
        if (x < 0)*o++ = '-', x = -x;
        while(x)*p1++ = x % 10 + '0', x /= 10;
        while(p1-- != buf)*o++ = *p1;
    }
    inline void println1(ll x)
    {
        print1(x);
        *o++ = '\n';
    }
    inline void print1(char c)
    {
        *o++ = c;
    }
    inline void println1(char c)
    {
        *o++ = c;
        *o++ = '\n';
    }
    inline void print1(char *s)
    {
        while (*s)*o++ = *s++;
    }
    inline void println1(char *s)
    {
        print(s);
        *o++ = '\n';
    }
    inline void println1()
    {
        *o++ = '\n';
    }
    inline void flush1()
    {
        if (o != Out && *(o - 1) == '\n')*--o = 0;
        puts(Out);
    }
    struct puts_write
    {
        ~puts_write()
        {
            flush1();
        }
    };
    inline void print2(int x)
    {
        printf("%d", x);
    }
    inline void println2(int x)
    {
        printf("%d\n", x);
    }
    inline void print2(char x)
    {
        printf("%c", x);
    }
    inline void println2(char x)
    {
        printf("%c\n", x);
    }
    inline void print2(ll x)
    {

        printf("%I64d", x);


        printf("%lld", x);

        puts("error:can't recognize the system!");


    }
    inline void println2(ll x)
    {
        print2(x);
        printf("\n");
    }
    inline void println2()
    {
        printf("\n");
    }



};
using namespace fastIO;
string name = "", in = ".in", out = ".out";


set <int> x,y;
int a[N][N],n,m,sum,c[2]; char s[N];
bool rev(int x1,int x2,int y1,int y2,int &c)
{
    for (int i=x1;i<=x2;i++){
        if (!a[i][y1] || !a[i][y2]) return 0;
        c+=a[i][y1]>0,a[i][y1]*=-1,c+=a[i][y2]>0,a[i][y2]*=-1;
    }
    for (int j=y1+1;j<y2;j++){
        if (!a[x1][j] || !a[x2][j]) return 0;
        c+=a[x1][j]>0,a[x1][j]*=-1,c+=a[x2][j]>0,a[x2][j]*=-1;
    }
    return 1;
}
bool check(int t)
{
    if (t>1){if (c[0]+c[1]==sum) return puts("YES"),1; return 0;}
    for (set<int>::iterator id4=x.begin();id4!=x.end();++id4) for (set<int>::iterator id3=x.begin();id3!=x.end();++id3){
            int x1=*id4,x2=*id3;
            if (x2-x1>1)
                for (set<int>::iterator id2=y.begin();id2!=y.end();++id2)
                    for (set<int>::iterator id0=y.begin();id0!=y.end();++id0){
                        int y1=*id2,y2=*id0;
                        if (y2-y1>1){
                            if (rev(x1,x2,y1,y2,c[t])) if (check(t+1))
                                {printf("%d %d %d %d\n",x1,y1,x2,y2); return 1;}
                            rev(x1,x2,y1,y2,c[t]),c[t]=0;
                        }
                    }
        }
    return 0;
}
int main()
{

	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);

    read(n);read(m);
    for (int i=1;i<=n;i++){
        read(s+1);
        for (int j=1;j<=m;j++){
            if (s[j]=='
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) if (a[i][j]){
                if (a[i][j-1] && a[i][j+1]) x.insert(i);
                if (a[i-1][j] && a[i+1][j]) y.insert(j);
            }
    if (x.size()>4) x.erase(++++x.begin(),----x.end());
    if (y.size()>4) y.erase(++++y.begin(),----y.end());
    if (check(0))return 0;
    //system("pause");for (;;);
    return puts("NO"),0;
}


