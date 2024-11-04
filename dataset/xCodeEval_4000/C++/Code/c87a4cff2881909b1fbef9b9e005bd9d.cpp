#include <bits/stdc++.h>




using namespace std;

constexpr int mod = (int)1e9 + 7; 

constexpr int N = (int)2e5 + 30 + 5;
int T_T = 1;

namespace CF
{
    namespace NUM
    {
        constexpr int P = mod; 

        template<class T> T power(T a, long long b) { T r = 1; for (; b > 0; b >>= 1, a *= a) if (b & 1) r *= a; return r; }
        inline int norm(int x) { if (x < 0) x += P; else if (x >= P) x -= P; return x; }
        struct Z
        {
            int x;
            Z(int x = 0) : x(norm(x)) {}
            int val() const { return x; }
            Z operator-() const { return Z(norm(P - x)); }
            Z inv() const { assert(x != 0); return power(*this, P - 2); }
            Z& operator+=(const Z& rhs) { x = norm(x + rhs.x); return *this; }
            Z& operator-=(const Z& rhs) { x = norm(x - rhs.x); return *this; }
            Z& operator*=(const Z& rhs) { x = 1LL * x * rhs.x % P; return *this; }
            Z& operator/=(const Z& rhs) { return *this *= rhs.inv(); }
            friend Z operator+(const Z& lhs, const Z& rhs) { Z res = lhs; res += rhs; return res; }
            friend Z operator-(const Z& lhs, const Z& rhs) { Z res = lhs; res -= rhs; return res; }
            friend Z operator*(const Z& lhs, const Z& rhs) { Z res = lhs; res *= rhs; return res; }
            friend Z operator/(const Z& lhs, const Z& rhs) { Z res = lhs; res /= rhs; return res; }
            bool operator== (const Z& rhs) { return x == rhs.x; }
            bool operator!= (const Z& rhs) { return x != rhs.x; }
            

            

        };
        istream& operator>>(istream& is, Z& z) { is >> z.x; z.x = norm(z.x); return is; }
        ostream& operator<<(ostream& os, const Z& z) { os << z.x; return os; }
    }
    using NUM::Z;                           using vz = vector<Z>;
    using ll = long long;                   using vcs = vector<string>;
    using ull = unsigned long long;         using vb = vector<bool>;
    using pzz = pair<Z, Z>;                 using vpzz = vector<pzz>;
    using pii = pair<int, int>;             using vpii = vector<pii>;
    using piii = pair<pii, int>;            using vpiii = vector<piii>;
    using pll = pair<ll, ll>;               using vpll = vector<pll>;
    using pdd = pair<double, double>;       using vpdd = vector<pdd>;
    using vl = vector<ll>;                  using vi = vector<int>;
    using vvl = vector<vl>;                 using vvi = vector<vi>;
    using vvvl = vector<vvl>;               using vvvi = vector<vvi>;
    using vvvvl = vector<vvvl>;             using vvvvi = vector<vvvi>;
    

    template <class T> using vc = vector<T>;
    template <class T> using vvc = vector<vc<T> >;
    template <class T> using pq = priority_queue<T, vector<T>, less<T> >;
    template <class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
    template<typename T1, typename T2> pair<T1, T2>& operator+=(pair<T1, T2>& p1, const pair<T1, T2>& p2) { p1.first += p2.first, p1.second += p2.second; return p1; }
    template<typename T1, typename T2> pair<T1, T2>& operator-=(pair<T1, T2>& p1, const pair<T1, T2>& p2) { p1.first -= p2.first, p1.second -= p2.second; return p1; }
    template<typename T1, typename T2> pair<T1, T2> operator+(pair<T1, T2> p1, const pair<T1, T2>& p2) { return p1 += p2; }
    template<typename T1, typename T2> pair<T1, T2> operator-(pair<T1, T2> p1, const pair<T1, T2>& p2) { return p1 -= p2; }
    template<typename T> T operator*(const pair<T, T>& p1, const pair<T, T>& p2) { return 1LL * p1.first * p2.first + 1LL * p1.second * p2.second; }
    template<typename T> T operator^(const pair<T, T>& p1, const pair<T, T>& p2) { return 1LL * p1.first * p2.second - 1LL * p2.first * p1.second; }
    template<typename T> pair<T, T>& operator*=(pair<T, T>& p1, const T& p2) { p1.first *= p2; p1.second *= p2; return p1; }
    template<typename T> pair<T, T> operator*(pair<T, T> p1, const T& p2) { return p1 *= p2; }
    template<typename T> T mo(const pair<T, T>& p) { return p * p; }
    template<typename T> double sqmo(const pair<T, T>& p) { return sqrt(mo(p)); }

    template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.first << ' ' << p.second; }
    template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2>& p) { is >> p.first >> p.second; return is; }
    template<typename T> ostream& operator<<(ostream& os, const vc<T>& a) { for (auto v : a) os << (v) << ' '; return os; }
    template<typename T> istream& operator>>(istream& is, vc<T>& a) { for (auto& v : a) is >> v; return is; }
    template<typename T> ostream& operator<<(ostream& os, const vc<vc<T>>& a) { for (auto& v : a) os << v << '\n'; return os; }

    

    template<typename T> ostream& operator<<(ostream& os, const set<T>& a) { for (auto& v : a) os << v << ' '; return os; }
    template<typename T> ostream& operator<<(ostream& os, const set<T, greater<T>>& a) { for (auto& v : a) os << v << ' '; return os; }
    template<typename T> ostream& operator<<(ostream& os, const multiset<T>& a) { for (auto& v : a) os << v << ' '; return os; }
    

    

    template<typename T1, typename T2> ostream& operator<<(ostream& os, const map<T1, T2>& a) { for (auto& [v1, v2] : a) os << endl << setw(15) << v1 << " : " << v2 << ' '; return os; }

    template<typename T> vc<T>& operator+=(vc<T>& a, const vc<T>& b) { a.insert(a.end(), b.begin(), b.end()); return a; }

    const int IOS = []() { ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

#define endl ('\n')
#define MP(x,y) make_pair(x,y)
#define all(a) begin(a), end(a)
#define SUM(a) accumulate(all(a), 0LL)
#define MIN(a) (*min_element(all(a)))
#define MAX(a) (*max_element(all(a)))
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define ub(a, x) distance(begin(a), upper_bound(all(a), (x)))
#define lbex(l, r, x) distance(l, lower_bound(l,r,(x)))
#define ubex(l, r, x) distance(l, upper_bound(l,r,(x)))
#define toset(a) (sort(all(a)), a.erase(unique(all(a)), a.end()), a.size())
#ifdef CF_DEBUG
    auto dbout = [](auto&& ... args) -> void { ((cerr << args << ", "), ...); };
#define debug(...) cerr << "( "<< #__VA_ARGS__ << " ) = ( ", dbout(__VA_ARGS__), cerr << ")\n"  
#define debugt(x) cerr << "( "<< #x<<" ) = [ "; apply(dbout, x); cerr << "]\n";
#define cin fin
#define cout fout
    ifstream fin("CF_data.in");
    ofstream fout("CF_data.out");
    

#else
    

#define debug(...) (0)
#define debugt(x) (0)
#endif
    ll operator%(const string& s, const ll p) { ll res = 0; for (auto& v : s) res = (res * 10 + v - 48) % p; return res; }
    

    ll POW(ll a, ll b, const ll p) { a %= p; if (a == 0) return 0LL; ll r = 1; for (; b > 0; a = a * a % p, b >>= 1) if (b & 1) r = r * a % p; return r; }
    ll gcd(ll a, ll b) { if (a < b) swap(a, b); if (b != 0) while (b ^= a ^= b ^= a %= b); return a; }
    int gcd(int a, int b) { if (a < b) swap(a, b); if (b != 0) while (b ^= a ^= b ^= a %= b); return a; }
    ll gcd(const vi& a) { int g = a[0]; for (auto& v : a) g = gcd(g, v); return g; }
    

    ll exgcd(ll a, ll b, ll& x, ll& y) { ll d = a; if (b != 0) d = exgcd(b, a % b, y, x), y -= (a / b) * x; else x = 1, y = 0; return d; }
    ll NIY_exgcd(ll a, ll p) { ll x, y; exgcd(a, p, x, y); return (x % p + p) % p; }
    ll LCM(ll a, ll b) { return a / gcd(a, b) * b; }
    ll fast_mul(ll a, ll b, ll mod) { return ((a * b - (ll)((ll)((long double)a / mod * b + 1e-3) * mod)) % mod + mod) % mod; }
    vi discrete(vi& a) { vi b(a); toset(b); for (auto& v : a) v = lb(b, v); return b; }
    vl discrete(vl& a) { vl b(a); toset(b); for (auto& v : a) v = lb(b, v); return b; }
    vi discrete(vpii& a) { vi b; for (auto& [x, y] : a) b.emplace_back(x), b.emplace_back(y); toset(b); for (auto& [x, y] : a) x = lb(b, x), y = lb(b, y); return b; }

    inline int sgn(ll x) { if (x == 0) return 0; return x > 0 ? 1 : -1; }
    string YN(bool flag) { return (flag ? "Yes" : "No"); }
    const double PI = acos(-1);
    constexpr int inf = 0x3f3f3f3f;
    constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
    

}
using namespace CF;



void solve1()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    if (MAX(a) <= k) return void(cout << 0 << endl);

    n = toset(a);
    vvi f(n);

    for (int i = 0; i < n; i++)
    {
        for (int l = 1, r = 0; l <= a[i] && l <= k; l = r + 1)
        {
            r = a[i] / (a[i] / l);
            f[i].emplace_back(a[i] / l);
        }
    }
    


    auto check = [&](int L, int R)
    {
        for (auto& v : f)
        {
            bool flag = false;
            for (auto& x : v)
            {
                if (L <= x and x <= R) flag = true;
            }
            if (!flag) return false;
        }
        return true;
    };
    int l = 0, r = MAX(a) - MIN(a);
    int m = MAX(a);
    while (l < r)
    {
        int mid = (l + r) / 2;
        bool can = false;
        for (int L = 1, R = mid + 1; R <= m && !can; L++, R++)
            if (check(L, R)) can = true;
        if (can) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

namespace LCAST
{

    constexpr int N = 4e5 + 5, LG = 22;
    vi E[N];
    int a[N * 2], pos[N], dep[N], dfn, st[N * 2][LG], lg[N * 2];
    

    void init(int n)
    {
        dfn = 0; lg[1] = 0;
        for (int i = 0; i <= n; i++) E[i].clear();
        for (int i = 2; i <= n * 2; ++i) lg[i] = lg[i - 1] + ((1 << (lg[i - 1] + 1)) == i);
    }
    inline void add(const int& u, const int& v) { E[u].emplace_back(v); }
    void dfs(int u, int fu)
    {
        dep[u] = dep[fu] + 1;
        a[++dfn] = u; pos[u] = dfn;
        for (auto& v : E[u]) if (v != fu)
        {
            dfs(v, u);
            a[++dfn] = u;
        }
    }
    inline int getmin(const int& x, const int& y)
    {
        return dep[x] < dep[y] ? x : y;
    }
    void getst()
    {
        for (int i = 1; i <= dfn; i++) st[i][0] = a[i];

        for (int k = 1; k <= lg[dfn]; k++)
            for (int i = 1, L = (1 << k); i + L - 1 <= dfn; i++)
                st[i][k] = getmin(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
    }

    int lca(int x, int y)
    {
        x = pos[x]; y = pos[y];
        if (x > y) swap(x, y);
        int k = lg[y - x + 1], len = 1 << k;
        return getmin(st[x][k], st[y - len + 1][k]);
    }
}

namespace B
{

#define INFI (int)1e9 + (int)1e5
#define MAXN 200100
#define MAXM 100100 * 4
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]

    int cnt = 0;
    int n, m;
    struct Tedge
    {
        int x, y, w;
        bool operator < (const Tedge& rhs) const
        {
            return w < rhs.w;
        }
    }edge[MAXM];
    int tot = 0;

    inline void add(int x, int y, int w) { edge[++tot] = { x, y, w }; }

    int fa[MAXN] = { 0 };


    int find(int x)
    {
        if (fa[x] == x) return fa[x];
        else return fa[x] = find(fa[x]);
    }

    int val[MAXM] = { 0 };
    int f[MAXN][21] = { 0 };
    int ch[MAXN][2] = { 0 };
    void init()
    {
        cnt = n; tot = 0;
        for (int i = 0; i <= n * 2; i++) fa[i] = i;
        for (int i = 1; i <= n; i++) val[i] = 0;
    }

    void kruskal()
    {
        sort(edge + 1, edge + tot + 1);
        for (int i = 1; i <= m; i++)
        {
            int x = edge[i].x; int y = edge[i].y;
            int fax = find(x); int fay = find(y);
            if (fax == fay) continue;
            cnt++;
            ls(cnt) = fax; rs(cnt) = fay;
            fa[fa[x]] = fa[fa[y]] = f[fa[x]][0] = f[fa[y]][0] = cnt;
            val[cnt] = edge[i].w;
        }
    }
    int dep[MAXN] = { 0 };
    void prework(int x)
    {
        if (!ls(x) and !rs(x)) return;
        dep[ls(x)] = dep[rs(x)] = dep[x] + 1;
        prework(ls(x));
        prework(rs(x));
    }
    int st[MAXN][LCAST::LG - 1];
    void read()
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            add(x, y, i);
        }
        kruskal();
        LCAST::init(cnt);
        for (int i = n + 1; i <= cnt; i++)
        {
            if (ls(i)) LCAST::add(i, ls(i));
            if (rs(i)) LCAST::add(i, rs(i));
        }
        LCAST::dep[cnt] = 0;
        LCAST::dfs(cnt, 0);
        LCAST::getst();

        using LCAST::lca;

        for (int i = 1; i <= n; i++) st[i][0] = i;

        for (int k = 1; k <= LCAST::lg[n]; k++)
            for (int i = 1, L = (1 << k); i + L - 1 <= n; i++)
                st[i][k] = lca(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
    }
    int getans(int L, int R)
    {
        int k = LCAST::lg[R - L + 1], len = 1 << k;
        return val[LCAST::lca(st[L][k], st[R - len + 1][k])];
    }
}
void solve()
{
    int q;
    cin >> B::n >> B::m >> q;
    B::read();
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << B::getans(x, y) << ' ';
    }
    cout << endl;
}

void myinit()
{
    cin >> T_T;
    return;
}





int main()
{
#ifdef CF_DEBUG
    clock_t time_start = clock();
#endif 
    myinit();
    while (T_T--) solve();
    

#ifdef CF_DEBUG
    fin.close(); fout.close();
    clock_t time_end = clock();
    debug(time_end - time_start);
#endif 
    return 0;
}
