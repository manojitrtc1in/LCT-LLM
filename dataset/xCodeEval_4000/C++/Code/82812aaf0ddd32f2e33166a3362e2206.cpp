#define _USE_MATH_DEFINES
#pragma GCC optimize("O3")







#include <bits/stdc++.h>
using namespace std;

#define LSB(i) ((i) & -(i)) 


#define OPEN(a) freopen(a, "r", stdin)
#define F first
#define S second
#define PB push_back
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ALL(i) begin((i)), end((i))
#define SZ(i) ((int)i.size())
#define SORT(a) sort(ALL(a))

using LL = long long;
using LD = long double;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using PLD = pair<LD, LD>;
using VI = vector<int>;
using VLL = vector<LL>;
using VLD = vector<LD>;
using VPII = vector<PII>;
using VPLL = vector<PLL>;
using VPLD = vector<PLD>;
using VVI = vector<VI>;

#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define __FOR3(i, a, n, inc) for(int i = (a); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define __FOR2(i, a, n) __FOR3(i, a, n, 1)
#define __FOR1(i, n) __FOR2(i, 0, n)
#define FOR(...) GET_MACRO(__VA_ARGS__, __FOR3, __FOR2, __FOR1)(__VA_ARGS__)

#define REV(a,b) for(int a= b; a >= 0; --a)
#define FRU(a,b) for(const auto& a: b)
#define FRUM(a,b) for(auto& a : b)

const int inf = 1e9 + 7;
const int MOD = 998244353;
const LL INF = 1e18 + 7;
const long double PI = acos(-1);
const LD EPS = 1e-9;

int read()
{
    int x=0; char ch=getchar();
    while(ch<'0'||ch>'9')   ch=getchar();
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x;
}

namespace input {
    template< class T> istream& operator>>(istream& st, vector<T> & container) { for (auto& u : container) st >> u; return st; }
    template< class T, size_t N> istream& operator>>(istream& st, array<T, N> & container) { for (auto& u : container) st >> u; return st; }
    template <class T, class U> istream& operator>>(istream& st, pair<T, U> & p) { st >> p.first >> p.second; return st; }

    void re() {}
    template<typename T, typename... TArgs> void re(T& x, TArgs&... rest) { x = read(); re(rest...); };
}
using namespace input;



#define RE(...)   int __VA_ARGS__; re(__VA_ARGS__);
#define RELL(...) LL __VA_ARGS__; re(__VA_ARGS__);
#define RELD(...) LD __VA_ARGS__; re(__VA_ARGS__);


namespace output
{
    template< class T> ostream& operator<<(ostream& st, const vector<T> & container) { for (auto& u : container) st << u << ' '; return st; }
    template< class T, size_t N> ostream& operator<<(ostream& st, const array<T, N> & container) { for (auto& u : container) st << u << ' '; return st; }
    template <class T, class U> ostream& operator<<(ostream& st, pair<T, U> p) { st << p.first << ' ' << p.second; return st; }

    void pr() {}
    template <typename T> void pr(const T& x) { cout << x; }
    template <typename T, typename... TArgs> void pr(const T& x, const TArgs&... rest) { cout << x << ' '; pr(rest...); }
    template <typename... TArgs> void prln(const TArgs&... args) { pr(args...); cout << '\n'; }
}
using namespace output;

namespace pairs
{
    template<class T, class U, class V> pair<T, U> operator* (pair<T, U>p, V val) { return{ p.first * val, p.second * val }; }
    template<class T, class U, class V> pair<T, U> operator/ (pair<T, U>p, V val) { return{ p.first / val, p.second / val }; }
    template<class T, class U>  pair<T, U> operator- (pair<T, U> a, pair<T, U> b) { return{ a.first - b.first, a.second - b.second }; }
    template<class T, class U>  pair<T, U> operator+ (pair<T, U> a, pair<T, U> b) { return{ a.first + b.first, a.second + b.second }; }
}
using namespace pairs;

namespace triples
{
#define TT1T2T3 template<class T1, class T2, class T3>
#define TT1T2T3T4 template<class T1, class T2, class T3, class T4>
#define TRT1T2T3  triple<T1, T2, T3>
    TT1T2T3 struct triple { T1 x; T2 y; T3 z; triple() : x(T1()), y(T2()), z(T3()) {}; triple(T1 _x, T2 _y, T3 _z) :x(_x), y(_y), z(_z) {} };
    TT1T2T3 bool operator<(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.x != t2.x)return t1.x < t2.x; if (t1.y != t2.y) return t1.y < t2.y; else return t1.z < t2.z; }
    TT1T2T3 bool operator>(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.x != t2.x)return t1.x > t2.x; if (t1.y != t2.y) return t1.y > t2.y; else return t1.z > t2.z; }
    TT1T2T3 bool operator==(const TRT1T2T3&t1, const TRT1T2T3&t2) { return (t1.x == t2.x && t1.y == t2.y && t1.z == t2.z); }
    TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.x >> t.y >> t.y; }
    TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t) { return os << t.x << " " << t.y << " " << t.z; }

    TT1T2T3 TRT1T2T3 operator+(TRT1T2T3 a, TRT1T2T3 b) { return { a.x + b.x, a.y + b.y, a.z + b.z }; }
    TT1T2T3 TRT1T2T3 operator-(TRT1T2T3 a, TRT1T2T3 b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }
    TT1T2T3T4 TRT1T2T3 operator*(TRT1T2T3 a, T4 val) { return { a.x * val, a.y * val, a.z * val }; }
    TT1T2T3T4 TRT1T2T3 operator/(TRT1T2T3 a, T4 val) { return { a.x / val, a.y / val, a.z / val }; }

#undef TT1T2T3T4
#undef TRT1T2T3
#undef TT1T2T3
    using TRII = triple<int, int, int>;
    using TRLL = triple<LL, LL, LL>;
    using TRLD = triple<LD, LD, LD>;
    using VTRII = vector<TRII>;
    using VTRLL = vector<TRLL>;
    using VTRLD = vector<TRLD>;
}
using namespace triples;

namespace geo
{
    template<class T> T dotProduct(pair<T, T> a, pair<T, T> b) { return a.first*b.first + a.second* b.second; }
    template<class T> T crossProduct(pair<T, T>a, pair<T, T> b) { return a.first * b.second - a.second * b.first; }
    template<class T> T lengthPow(pair<T, T> a) { return a.first*1ll*a.first + a.second*1ll*a.second; }
    template<class T> LD length(pair<T, T> a) { return sqrt(lengthPow(a)); }


    template<class T> T dotProduct(triple<T, T, T> a, triple<T, T, T> b) { return a.x*b.x + a.y* b.y + a.z*b.z; }
    template<class T> T crossProduct(triple<T, T, T> a, triple<T, T, T> b) { return { a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x }; }
    template<class T> T lengthPow(triple<T, T, T> a) { return a.x*1ll*a.x + a.y*1ll*a.y + a.z*1ll*a.z; }
    template<class T> LD length(triple<T, T, T> a) { return sqrt(lengthPow(a)); }
}
using namespace geo;

template <class T> T invGeneral(T a, T b) { 

    a %= b;
    if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b, a);
    return x == -1 ? -1 : ((1 - (LL)b * x) / a + b) % b;
}

template<class T> struct modular {
    T val;
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const LL& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }

    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend void pr(const modular& a) { pr(a.val); }
    friend void re(modular& a) { LL x; re(x); a = modular(x); }

    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (LL)val*m.val%MOD; return *this; }
    friend modular pow(modular a, LL p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) {
        auto i = invGeneral(a.val, MOD); assert(i != -1);
        return i;
    } 

    modular& operator/=(const modular& m) { return (*this) *= inv(m); }

    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

using MI = modular<int>;
using PMI = pair<MI, MI>;
using VMI = vector<MI>;
using VPMI = vector<PMI>;


namespace debug {
    template < typename _T > inline void _debug(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
    template < typename _T, typename... args > void _debug(const char *s, _T x, args... a) { while (*s != ',') cerr << *s++; cerr << " = " << x << ','; _debug(s + 1, a...); }

#if 1 && defined(LOCAL)
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 1999
#define cerr if(0) cout
#endif
}
using namespace debug;

template <class T> bool setMax(T& v, T newV) { if (v < newV) { v = newV; return true; } return false; }
template <class T> bool setMin(T& v, T newV) { if (v > newV) { v = newV;    return true; } return false; }
LL sq(LL a) {return a*a;}



const int N = 2e5 + 7;

int w[N]; 

VPII g[N];  

int c[N];
bitset<N> choosen;

namespace lifting
{
    int pre[20][N];
    int dep[N];
    int cost[20][N];
    void dfs(int v, int pr = 0, int d = 0, int prID = N - 1)
    {
        dep[v] = d;
        pre[0][v] = pr;
        cost[0][v] = prID;

        for(auto [u, id]: g[v])
        {
            if(u != pr)
            {
                dfs(u,v,d+1, id);
            }
        }
    }

    void preCalc(int n)
    {
        w[N - 1] = -inf;
        dfs(0);

        for(int i = 1; i < 20; ++i)
        {
            for(int j=0 ;j < n; ++j)
            {
                int v= pre[i-1][j];
                pre[i][j] = pre[i-1][v];

                if(w[cost[i-1][v]] < w[cost[i-1][j]])
                    cost[i][j] = cost[i-1][j];
                else 
                    cost[i][j] = cost[i-1][v];
            }
        }

    }

    int getLCA(int u, int v)
    {
        if(u == v)
            return u;

        if(dep[u] > dep[v])
            swap(u,v);


        for(int i = 19; i >= 0; --i)
        {
            if(dep[pre[i][v]] >= dep[u])
                v = pre[i][v];
        }

        if(u == v)
            return u;

        for(int i = 19; i >= 0; --i)
        {
            if(pre[i][u] != pre[i][v])
            { 
                u = pre[i][u];
                v = pre[i][v];
            }
        }
        return pre[0][u];
    }
    
    int getMid(int u, int v, int dist)  

    {
        if(dep[u] > dep[v])
            swap(u,v);

        dist /=2;

        for(int i = 19; i >=0; --i)
        {
            if((1<<i) <= dist)
            {
                v = pre[i][v];
                dist -= 1 <<i;
            }
        }
        return v;
    }

    PII getMax(int u, int v)
    {
        int lca = getLCA(u,v);

        int maxi = -inf;
        int maxID = -1;
        for(int i = 19; i >= 0; --i)
        {
            if(dep[pre[i][v]] >= dep[lca])
            {
                if(setMax(maxi, w[cost[i][v]]))
                    maxID = cost[i][v];
                v = pre[i][v];
            }
            if(dep[pre[i][u]] >= dep[lca])
            {
                if(setMax(maxi, w[cost[i][u]]))
                    maxID = cost[i][u];
                u = pre[i][u];
            }
        }
        return {maxi, maxID};

    }


}



namespace DSU
{

    int tab[N];
    void preCalc(int n)
    {
        FOR(i, n)
            tab[i] = i;
    }
    int Find(int a)
    {
        if(tab[a] != a)
            tab[a] = Find(tab[a]);
        return tab[a];
    }
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        tab[a] = b;
    }
}

auto solve()
{
    int n, m;
    re(n, m);

    DSU::preCalc(n);

    FOR(i, m)
        re(w[i]);
    FOR(i, m)
        re(c[i]);

    vector<pair<PII,PII> >  vec(m);
    FOR(i, m)
    {
        int a, b;
        re(a, b);
        --a, --b;
        vec[i] = { {w[i], i}, {a, b} };
    }

    int s;
    re(s);
    SORT(vec);
    LL cost = 0;
    FRU(e, vec)
    {
        auto[t1, t2] = e;
        auto[w, id] = t1;
        auto[a, b] = t2;
        if(DSU::Find(a) != DSU::Find(b))
        {
            cost += w;
            choosen[id] = 1;
            DSU::Union(a, b);
            g[a].push_back({b, id});
            g[b].push_back({a, id});
            debug(id, a, b, w);
        }
    }
    lifting::preCalc(n);

    LL best = cost + 1;
    LL bestID = -1;
    LL bestEra = -1;
    FRU(e, vec)
    {
        auto[t1, t2] = e;
        auto[w, id] = t1;
        auto[a, b] = t2;
        
        int ile = s / c[id];
        if(choosen[id])
        {
            LL newCost = cost - ile;
            if(setMin(best, newCost))
            {
                bestID = id;
                bestEra = -1;
            }
        }
        else
        {
            auto[val, idM] = lifting::getMax(a,b);
            LL newCost = cost -  val + w - ile;
            if(setMin(best, newCost))
            {
                bestID = id;
                bestEra = idM;
            }
        }
    }

    prln(best);
    debug(bestID, bestEra);

    if(bestEra != -1)
        choosen[bestEra] = 0;

    choosen[bestID] = 1;
    w[bestID] -= s / c[bestID];

    FOR(i, m)
    {
        if(choosen[i])
            prln(i + 1, w[i]);
    }
}

int main()
{   
    

        

        

    



    BOOST;
    cout << fixed << setprecision(10);
    int t = 1;
    

    while (t--)
    {
        solve();
    }
    return 0;
} 