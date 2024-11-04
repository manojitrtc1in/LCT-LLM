#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <iostream>
#include <sstream>
#include <algorithm>

#define pr_debug(...) fprintf(stderr, __VA_ARGS__)
#define pr_line() fprintf(stderr, "%s: %d\n", __FILE__, __LINE__)

template <typename T>
bool chmax(T *m, const T *v) {
    if (*v > *m) {
        *m = *v;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T *m, const T *v) {
    if (*v < *m) {
        *m = *v;
        return true;
    }
    return false;
}

template <typename T>
bool chinc(T *v1, T *v2) {
    if (*v1 > *v2) {
        T temp = *v1;
        *v1 = *v2;
        *v2 = temp;
        return true;
    }
    return false;
}

template <typename T>
bool chdec(T *v1, T *v2) {
    if (*v1 < *v2) {
        T temp = *v1;
        *v1 = *v2;
        *v2 = temp;
        return true;
    }
    return false;
}

static const int HMAX32 = INT32_MAX / 2;
static const int HMIN32 = -HMAX32;
static const int64_t HMAX64 = INT64_MAX / 2;
static const int64_t HMIN64 = -HMAX64;

#define ALL(x) begin(x), end(x)
#define FOR0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define FOR1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define FOR(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define FOD0(i,n) for(int i=(n)-1;~i;i--)
#define FOD1(i,n) for(int i=n;i;i--)
#define FOD(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define FORE(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;

template<typename T> inline T abs(T a){return a>0?a:-a;}

struct Cg{inline char operator()(){return (char)getchar();}};
struct Cp{inline void operator()(char x){putchar(x);}};
struct Cpe{inline void operator()(char x){putc(x,stderr);}};
inline bool IS(char x){return x==10||x==13||x==' ';}
template<typename T>struct Fr{T P;inline Fr&operator,(int &x)
{x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(f)x=-x;return *this;}inline operator int(){int x;*this,x;return x;}inline Fr&operator,(ll &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(f)x=-x;return *this;}inline operator ll(){ll x;*this,x;return x;}inline Fr&operator,(char &x)
{for(x=P();IS(x);x=P())continue;return *this;}inline operator char(){char x;*this,x;return x;}inline Fr&operator,(char *x){char t=P();for(;IS(t);t=P())continue;if(~t){for(;!IS(t)&&~t;t=P())*x++=t;}*x++=0;return *this;}inline Fr&operator,(lf &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x;return *this;}inline operator lf(){lf x;*this,x;return x;}inline Fr&operator,(llf &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x;return *this;}inline operator llf()
{llf x;*this,x;return x;}inline Fr&operator,(uint &x){x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';return *this;}inline operator uint(){uint x;*this,x;return x;}inline Fr&operator,(ull &x){x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';return *this;}inline operator ull(){ull x;*this,x;return x;}};
template<typename T>struct Fw{T P;inline Fw&operator,(int x){if(x){if(x<0)P('-'),x=-x;char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()(int x){if(x){if(x<0)P('-'),x=-x;char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(uint x){if(x){char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}
inline Fw&operator()(uint x){if(x){char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(ll x){if(x){if(x<0)P('-'),x=-x;char s[19];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()(ll x){if(x){if(x<0)P('-'),x=-x;char s[19];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(ull x){if(x){char s[20];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()
(ull x){if(x){char s[20];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(char x){P(x);return *this;}inline Fw&operator()(char x){P(x);return *this;}inline Fw&operator,(const char *x){while(*x)P(*x++);return *this;}
inline Fw&operator()(const char *x){while(*x)P(*x++);return *this;}inline Fw&operator()(lf x,int y){if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);;return *this;}inline Fw&operator()(llf x,int y){if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);;return *this;}};

int gcd(int a, int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * (int64_t)b;
}

int extended_gcd(int a, int b, int64_t *x, int64_t *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int g = extended_gcd(b, a % b, y, x);
    *y -= (a / b) * *x;
    return g;
}

int mul_mod(int a, int b, int m) {
    int64_t p = a;
    p = (p * b) % m;
    return (int)p;
}

int pow_mod(int a, int p, int m) {
    int r;
    a %= m;
    for (r = 1; p; p >>= 1) {
        if (p & 1)
            r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
    }
    return r;
}

int inv_mod(int a, int m) {
    int64_t x, y;
    extended_gcd(a, m, &x, &y);
    if (x < 0)
        return x + m;
    return x;
}

int addx_mod(int u, int v, int m) {
    int r = u + v;
    if (r >= m)
        r -= m;
    return r;
}

int subx_mod(int u, int v, int m) {
    int r = u - v;
    if (r < 0)
        r += m;
    return r;
}

int div_mod(int u, int v, int m) {
    int g = gcd(v, m);
    assert(u % g == 0);
    int mm = m / g;
    return mul_mod(u / g, inv_mod(v / g, mm), mm);
}

int div_pos_r(int a, int b, int *r) {
    int q = a / b;
    *r = a % b;
    if (*r < 0) {
        if (b < 0)
            q += 1, *r -= b;
        else
            q -= 1, *r += b;
    }
    return q;
}

#define INV_MOD(x)      inv_mod((x), MOD)
#define MUL_MOD(x, y)   mul_mod((x), (y), MOD)
#define MULM_MOD(x, y)  (x) = mul_mod((x), (y), MOD)
#define POW_MOD(x, y)   pow_mod((x), (y), MOD)
#define ADDX_MOD(x, y)  addx_mod((x), (y), MOD)
#define ADDM_MOD(x, y)  (x) = addx_mod((x), (y), MOD)
#define SUBX_MOD(x, y)  subx_mod((x), (y), MOD)
#define SUBM_MOD(x, y)  (x) = subx_mod((x), (y), MOD)

static const int MOD = 1000000007;
static const int maxn = 100005;

int n;
int pts[maxn][2];
bool visit[maxn * 2];
std::vector<int> g[maxn * 2];

std::pair<int, int> dfs(int u) {
    std::pair<int, int> ret = {1, (int)g[u].size()};
    visit[u] = true;
    for (int v : g[u]) {
        if (!visit[v]) {
            std::pair<int, int> p = dfs(v);
            ret.first += p.first;
            ret.second += p.second;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);

    std::map<int, int> trans[2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i][0], &pts[i][1]);
        for (int j = 0; j < 2; j++) {
            trans[j][pts[i][j]] = 0;
        }
    }
    int cnt = 0;
    for (int j = 0; j < 2; j++) {
        for (auto &p : trans[j]) {
            p.second = cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = trans[0][pts[i][0]];
        int y = trans[1][pts[i][1]];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 1;
    for (int i = 0; i < cnt; i++) {
        if (!visit[i]) {
            std::pair<int, int> p = dfs(i);
            int vers = p.first;
            int edgs = p.second / 2;
            if (edgs == vers - 1) {
                MULM_MOD(ans, SUBX_MOD(POW_MOD(2, vers), 1));
            } else {
                MULM_MOD(ans, POW_MOD(2, vers));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
