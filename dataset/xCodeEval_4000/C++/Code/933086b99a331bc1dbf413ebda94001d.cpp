#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4")


#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pdd;

#define xx first
#define yy second

#define I inline








template<typename T> I T max(T a,T b){return a>b?a:b;}
template<typename T> I T min(T a,T b){return a<b?a:b;}
template<typename T> I T abs(T a){return a>0?a:-a;}
template<typename T> I bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> I bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> I T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> I T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define smp(a,b) ((a<b)? std::make_pair(a,b) : std::make_pair(b,a))
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;
































using std::cout; using std::cin;
const int N = 2e5 + 7;
lf ht, a, b;


int n,q;




lf left[N], right[N];
lf sum[N];
struct { double x,y; } ps[N];

I lf project(const pii po, int s) {
    return lf(po.xx - s) * ht / po.yy + s;
}
I pdd project(const pii po, const pii fe) {
    return pdd(project(po,fe.xx), project(po,fe.yy));
}

I lf rproject(const pdd po, lf a) {
    

    

    

    

    return -ht * (po.xx - a) / (po.yy - ht) + a;
}
I pdd rproject(const pdd po) {
    return pdd(rproject(po,a), rproject(po,b));
}

I lf overlap(const pdd range) {
    return max(0., min(b+0.,range.yy) - max(a+0.,range.xx));
}


template <class T = int> inline T readInt();                        
inline double readDouble();
inline int readUInt();                   
inline int readChar(); 

inline void readWord( char *s ); 
inline bool readLine( char *s ); 

inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt( T x, char end = 0, int len = -1 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();



static const int buf_size = 4096; 
static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return 1;
    }
    return 0;
}

inline int getChar() { 
    return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() { 
    return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() { 
    int c;
    while ((c = peekChar()) != -1 && c <= 32)
        buf_pos++;
    return c == -1;
}

inline void skipBlanks() {
    while (!isEof() && buf[buf_pos] <= 32U)
        buf_pos++;
}

inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}

inline int readUInt() {
    int c = readChar(), x = 0;
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return x;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

inline double readDouble() {
    int s = 1, c = readChar();
    double x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    if (c == '.') {
        c = getChar();
        double coef = 1;
        while ('0' <= c && c <= '9')
            x += (c - '0') * (coef *= 1e-1), c = getChar();
    }
    return s == 1 ? x : -x;
}

inline void readWord( char *s ) { 
    int c = readChar();
    while (c > 32)
        *s++ = c, c = getChar();
    *s = 0;
}

inline bool readLine( char *s ) { 
    int c = getChar();
    while (c != '\n' && c != -1)
        *s++ = c, c = getChar();
    *s = 0;
    return c != -1;
}






static int write_buf_pos = 0;
static char write_buf[buf_size];


static struct buffer_flusher_t {
    ~buffer_flusher_t() {
        flush();
    }
} buffer_flusher;

inline void writeChar( int x ) {
    if (write_buf_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
    write_buf[write_buf_pos++] = x;
}

inline void flush() {
    if (write_buf_pos) {
        fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
        fflush(stdout);
    }
}

template <class T> 
inline void writeInt( T x, char end, int output_len ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
    if (x < 0)
        writeChar('-'), x = -x;
    int t = (long long)x;
    writeInt<long long>(t), x -= t;
    writeChar('.');
    for (int i = output_len - 1; i > 0; i--) {
        x *= 10;
        t = std::min(9, (int)x);
        writeChar('0' + t), x -= t;
    }
    x *= 10;
    t = std::min(9, (int)(x + 0.5));
    writeChar('0' + t);
}




int main() {
    int tx,ty;
    double x,y;
    std::ios::sync_with_stdio(false);
    

    

    

    ht = readInt(); a = readInt(); b = readInt();
    n = readInt();
    

    

    

    fo1(i,n) {
        left[i] = readInt(); right[i] = readInt();
        

        

        

    }
    fd1(i,n) {
        sum[i] = sum[i+1] + (right[i] - left[i]);
    }
    left[0] = right[0] = -2e9;
    left[n+1] = right[n+1] = 2e9;
    

    

    q = readInt();
    

    

    fo1(i,q) {
        ps[i].x = readInt(); ps[i].y = readInt();
        

    }
    fo1(i,q) {
        double res = 0;
        x = ps[i].x, y = ps[i].y;
        

        

    

        lf xx,yy;
        xx = ht * (a - x) / (y - ht) + a;
        yy = ht * (b - x) / (y - ht) + b;
        if (xx >= right[n] || yy <= left[1]) {
            

            

        }
        int l = n+1;
        int tx,ty;
        for (tx = 1; tx < l; ) {
            ty = (tx + l) >> 1;
            

            if (xx <= right[ty]) l = ty;
            else tx = ty + 1;
        }
        int r = n+1;
        for (tx = l-1; tx < r; ) {
            ty = (tx + r) >> 1;
            if (yy < left[ty]) r = ty;
            else tx = ty + 1;
        }
        --r;
        

        

        if (r < l) {}
        else {
            res = sum[l] - sum[r+1];
            if (xx > left[l]) res -= (xx - left[l]);
            if (right[r] > yy) res -= (right[r] - yy);
            res *= (y - ht) / y;
        }
        ps[i].x = res;
        

        

        

    }
    

    fo1(i,q) {
        writeDouble(ps[i].x,15); writeChar('\n');
        

    }
}













