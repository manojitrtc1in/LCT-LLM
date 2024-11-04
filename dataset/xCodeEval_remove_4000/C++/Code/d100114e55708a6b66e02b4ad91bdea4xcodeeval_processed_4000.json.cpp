




























                        

                        



using namespace std;    








template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
template <typename T>
bool chinc(T &v1, T &v2) { if (v1 > v2) return swap(v1, v2), true; return false; }
template <typename T>
bool chdec(T &v1, T &v2) { if (v1 < v2) return swap(v1, v2), true; return false; }
static const int id9 = INT32_MAX / 2;
static const int id2 = -id9;
static const int64_t id10 = INT64_MAX / 2;
static const int64_t id5 = -id10;








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
struct empty_type { };





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
Int id11(Int u, Int v, Int m) {
    Int r = u + v;
    if (r >= m) r -= m;
    return r;
}
template <typename Int>
Int id4(Int u, Int v, Int m) {
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














































template <int Alpha = 256, typename Attr = empty_type>
struct id7 : Attr {
     int p = 0;
     int cs[Alpha] = {}; 

     int fail = 0;
     id7() {
         fill(ALL(cs), 0);
     }
};
template <int Alpha, typename Attr = empty_type>
using trie = vector<id7<Alpha, Attr>>;
template <int Alpha, typename Attr>
int id8(trie<Alpha, Attr> &tr, int prev, int c, bool insert = false) {
    

    if (!insert || tr[prev].cs[c]) return tr[prev].cs[c];
    int cur = (int)tr.size();
    tr.push_back({});
    return tr[prev].cs[c] = cur;
}
template <int Alpha, typename Attr>
void id3(trie<Alpha, Attr> &tr) {
    deque<int> q; 

    for (int c = 0; c < Alpha; ++c)
        if (tr[0].cs[c]) q.push_back(tr[0].cs[c]);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (int c = 0; c < Alpha; ++c) {
            int v = tr[u].cs[c];
            if (v == 0) continue;
            q.push_back(v);
            int m = tr[u].fail;
            while (m > 0 && tr[m].cs[c] == 0) m = tr[m].fail;
            tr[v].fail = tr[m].cs[c];
        }
    }
}
template <int Alpha, typename Attr>
int id6(trie<Alpha, Attr> &tr, int u, int c) {
    while (u > 0 && tr[u].cs[c] == 0) u = tr[u].fail;
    return tr[u].cs[c];
}
struct Attr {
    int cost = 0;
};
static const int MOD = 1000000007;
int n, m, k;
trie<256, Attr> tr(1);
int trans[405][256]; 

int dp[205][405][505]; 





int solve_all(int tot, int d, int u, int cost) {
    assert(u == 0 && cost == 0);
    pr_debug("sola %d %d %d %d\n", tot, d, u, cost);
    if (cost > k) return 0;
    if (d == tot) return 1;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (i == 0) ADDM_MOD(ans, solve_all(tot, d + 1, u, cost));
        else {
            int v = trans[u][i];
            int new_cost = cost + tr[v].cost;
            FOR(rest_cost, 0, k - new_cost)
                ADDM_MOD(ans, dp[tot - 1 - d][v][rest_cost]);
        }
    }
    return ans;
}
int solve(const vector<int> &num, int d, int u, int cost, bool zero) { 

    assert(num[0] != 0);
    pr_debug("solve %d %d %d lead=%d\n", d, u, cost, zero);
    if (cost > k) return 0;
    if (d == (int)num.size()) return 1;
    int ans = 0;
    for (int i = 0; i < num[d]; ++i) {
        if (zero && i == 0) {
            assert(d == 0);
            ADDM_MOD(ans, solve_all((int)num.size(), d + 1, u, cost));
            pr_debug("sola = %d\n", solve_all((int)num.size(), d + 1, u, cost));
            continue;
        }
        int v = trans[u][i];
        int new_cost = cost + tr[v].cost;
        

        

        FOR(rest_cost, 0, k - new_cost)
            ADDM_MOD(ans, dp[num.size() - 1 - d][v][rest_cost]);
    }
    int i = num[d];
    int v = trans[u][i];
    int new_cost = cost + tr[v].cost;
    ADDM_MOD(ans, solve(num, d + 1, v, new_cost, false));
    return ans;
}
int main() {
    fin, n, m, k;
    int nl, nr;
    vector<int> ls, rs;
    fin, nl; ls.resize(nl);
    FOR0(i, nl) fin, ls[i];
    fin, nr; rs.resize(nr);
    FOR0(i, nr) fin, rs[i];
    FOR0(i, n) {
        int p = 0;
        int len; fin, len;
        FOR0(_, len) {
            int c; fin, c;
            p = id8(tr, p, c, true);
        }
        int v; fin, v;
        tr[p].cost += v;
    }
    

    id3(tr);
    {
        deque<int> q = {0};
        while (!q.empty()) {
            int u = q.front(); q.pop_front();
            for (int c = 0; c < m; ++c) {
                int v = tr[u].cs[c];
                if (v == 0) continue;
                q.push_back(v);
            }
            tr[u].cost += tr[tr[u].fail].cost;
        }
    }
    
    

    FOR0(i, (int)tr.size())
        FOR0(c, m) {
            trans[i][c] = id6(tr, i, c);
        }
    int nstate = (int)tr.size();
    assert(nstate < 400);
    

    FOR0(u, nstate)
        dp[0][u][0] = 1; 

    FOR(len, 1, nr + 1) FOR0(u, nstate) FOR(cost, 0, k) FOR0(c, m) {
        int v = trans[u][c];
        int new_cost = cost - tr[v].cost;
        if (new_cost >= 0) ADDM_MOD(dp[len][u][cost], dp[len - 1][v][new_cost]);
    }
    
    int ans = 0;
    ADDM_MOD(ans, solve(rs, 0, 0, 0, true));
    SUBM_MOD(ans, solve(ls, 0, 0, 0, true));
    

    {
        int cost = 0;
        int p = 0;
        for (int i = 0; i < nl; ++i) {
            p = trans[p][ls[i]];
            cost += tr[p].cost;
        }
        if (cost <= k) ADDM_MOD(ans, 1);
    }
    fout, ans, "\n";
    return 0;
}
