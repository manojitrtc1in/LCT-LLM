




























                        

                        



using namespace std;    








template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
template <typename T>
bool chinc(T &v1, T &v2) { if (v1 > v2) return swap(v1, v2), true; return false; }
template <typename T>
bool chdec(T &v1, T &v2) { if (v1 < v2) return swap(v1, v2), true; return false; }
static const int id5 = INT32_MAX / 2;
static const int id2 = -id5;
static const int64_t id6 = INT64_MAX / 2;
static const int64_t id4 = -id6;








namespace fio {
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
template<typename T> inline T abs(T a){return a>0?a:-a;}
struct Cg{inline char operator()(){return (char)getchar();}};
struct Cp{inline void operator()(char x){putchar(x);}};
struct Cpe{inline void operator()(char x){putc(x,stderr);}};
inline bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;inline Fr&operator,(int &x)
{x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(f)x=-x;return *this;}inline operator int(){int x;*this,x;return x;}inline Fr&operator,(ll &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(f)x=-x;return *this;}inline operator ll(){ll x;*this,x;return x;}inline Fr&operator,(char &x)
{for(x=P();IS(x);x=P())continue;return *this;}inline operator char(){char x;*this,x;return x;}inline Fr&operator,(char *x){char t=P();for(;IS(t);t=P())continue;if(~t){for(;!IS(t)&&~t;t=P())*x++=t;}*x++=0;return *this;}inline Fr&operator,(lf &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x;return *this;}inline operator lf(){lf x;*this,x;return x;}inline Fr&operator,(llf &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x;return *this;}inline operator llf()
{llf x;*this,x;return x;}inline Fr&operator,(uint &x){x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';return *this;}inline operator uint(){uint x;*this,x;return x;}inline Fr&operator,(ull &x){x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';return *this;}inline operator ull(){ull x;*this,x;return x;}};
template<typename T>struct Fw{T P;inline Fw&operator,(int x){if(x){if(x<0)P('-'),x=-x;char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()(int x){if(x){if(x<0)P('-'),x=-x;char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(uint x){if(x){char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}
inline Fw&operator()(uint x){if(x){char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(ll x){if(x){if(x<0)P('-'),x=-x;char s[19];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()(ll x){if(x){if(x<0)P('-'),x=-x;char s[19];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(ull x){if(x){char s[20];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()
(ull x){if(x){char s[20];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(char x){P(x);return *this;}inline Fw&operator()(char x){P(x);return *this;}inline Fw&operator,(const char *x){while(*x)P(*x++);return *this;}
inline Fw&operator()(const char *x){while(*x)P(*x++);return *this;}inline Fw&operator()(lf x,int y){if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);;return *this;}inline Fw&operator()(llf x,int y){if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);;return *this;}};
}
fio::Fw<fio::Cp> fout;
fio::Fw<fio::Cpe> ferr;
fio::Fr<fio::Cg> fin;





template <typename Int>
Int gcd(Int a, Int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}
template <typename Int, typename RInt = Int>
Int lcm(Int a, Int b) {
    return a / gcd(a, b) * static_cast<RInt>(b);
}
template <typename Int, typename XInt>
Int id1(Int a, Int b, XInt &x, XInt &y) {
    static_assert(std::numeric_limits<XInt>::is_signed,
            "x, y must be signed");
    

    

    

    

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    Int g = id1(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
template <typename Int, typename TInt = int64_t>
Int mul_mod(Int a, Int b, Int m) {
    TInt p = a;
    p = (p * b) % m;
    return (Int)p;
}
template <typename Int, typename PInt, typename TInt = int64_t>
Int pow_mod(Int a, PInt p, Int m) {
    Int r;
    a %= m;
    for (r = 1; p; p >>= 1) {
        if (p & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
    }
    return r;
}
template <typename Int,
          typename XInt = typename std::make_signed<Int>::type>
Int inv_mod(Int a, Int m) {
    

    XInt x, y;
    id1(a, m, x, y);
    if (x < 0)
        return x + m;
    return x;
}
template <typename Int>
Int id7(Int u, Int v, Int m) {
    Int r = u + v;
    if (r >= m) r -= m;
    return r;
}
template <typename Int>
Int id3(Int u, Int v, Int m) {
    Int r = u - v;
    if (r < 0) r += m;
    return r;
}
template <typename Int>
Int div_mod(Int u, Int v, Int m) {
    

    

    

    

    

    

    

    

    

    Int g = gcd(v, m);
    assert(u % g == 0);
    Int mm = m / g;
    return mul_mod(u / g, inv_mod(v / g, mm), mm);
}
template <typename Int>
Int id0(Int a, Int b, Int &r) {
    

    

    

    

    

    

    

    Int q = a / b;
    r = a % b;
    if (r < 0) {
        if (b < 0)
            q += 1, r -= b;
        else
            q -= 1, r += b;
    }
    return q;
}

















static const int MOD = 1000000007;
static const int maxn = 100005;
int n;
int pts[maxn][2];
bool visit[maxn * 2]; 

bool ve[maxn * 2]; 

vector<pair<int, int>> g[maxn * 2]; 

int x_start, y_start, now = 0;
pair<int, int> dfs(int u) { 

    pair<int, int> ret = {1, 0};
    visit[u] = true;
    for (auto vv : g[u])  {
        if (ve[vv.second]) continue;
        ++ret.second;
        ve[vv.second] = true;
        if (visit[vv.first]) continue;
        auto p = dfs(vv.first);
        ret.first += p.first;
        ret.second += p.second;
    }
    return ret;
}
int main() {
    fin, n;
    

    map<int, int> trans[2];
    FOR0(i, n) {
        fin, pts[i][0], pts[i][1];
        FOR0(j, 2) {
            if (trans[j].count(pts[i][j]) == 0) {
                int s = (int)trans[j].size();
                trans[j][pts[i][j]] = s;
            }
            pts[i][j] = trans[j][pts[i][j]];
        }
        

    }
    

    x_start = now; now += trans[0].size();
    y_start = now; now += trans[1].size();
    assert(now < maxn * 2);
    FOR0(i, n) {
        int x = x_start + pts[i][0];
        int y = y_start + pts[i][1];
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }
    int ans = 1;
    FOR0(i, now) if (!visit[i]) {
        pair<int, int> p = dfs(i);
        int k = p.first;
        pr_debug("dfs %d %d\n", p.first, p.second);
        if (p.second < p.first) {
            MULM_MOD(ans, SUBX_MOD(POW_MOD(2, k), 1));
        } else {
            MULM_MOD(ans, POW_MOD(2, k));
        }
    }
    fout, ans, '\n';
    return 0;
}
