




using namespace std;

constexpr int mod = (int)1e9 + 7; 

constexpr int N = (int)1e5 + 5;
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













    auto dbout = [](auto&& ... args) -> void { ((cerr << args << ", "), ...); };




    ifstream fin("CF_data.in");
    ofstream fout("CF_data.out");
    


    




    ll operator%(const string& s, const ll p) { ll res = 0; for (auto& v : s) res = (res * 10 + v - 48) % p; return res; }
    

    ll POW(ll a, ll b, const ll p) { a %= p; if (a == 0) return 0LL; ll r = 1; for (; b > 0; a = a * a % p, b >>= 1) if (b & 1) r = r * a % p; return r; }
    ll gcd(ll a, ll b) { if (a < b) swap(a, b); if (b != 0) while (b ^= a ^= b ^= a %= b); return a; }
    int gcd(int a, int b) { if (a < b) swap(a, b); if (b != 0) while (b ^= a ^= b ^= a %= b); return a; }
    ll gcd(const vi& a) { int g = a[0]; for (auto& v : a) g = gcd(g, v); return g; }
    

    ll id0(ll a, ll b, ll& x, ll& y) { ll d = a; if (b != 0) d = id0(b, a % b, y, x), y -= (a / b) * x; else x = 1, y = 0; return d; }
    ll id1(ll a, ll p) { ll x, y; id0(a, p, x, y); return (x % p + p) % p; }
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


struct edge
{
    int to, ne;
}e[N * 2];
int ecnt, head[N * 2], dep[N * 2], siz[N * 2], son[N * 2], top[N * 2], f[N * 2];


int ans[N];
int n, m, cnt, tot; 

int fa[N * 2];
int val[N];
int q;

struct node	

{
    int l, r;
    int val;
}t[N * 4];

inline void myadd(int x, int y)
{
    e[++ecnt].to = y; e[ecnt].ne = head[x]; head[x] = ecnt;
}

void push_up(node& rt, const node& ls, const node& rs)

{
    rt.val = max(ls.val, rs.val);
}

void build(int k, int l, int r)
{
    if (l == r)

    {
        t[k] = { l, r,ans[l] };
        return;
    }
    int mid = (l + r) / 2;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    push_up(t[k], t[k << 1], t[k << 1 | 1]);
    

    t[k].l = l, t[k].r = r;
}

int query(int k, int x, int y)
{
    if (x <= t[k].l && t[k].r <= y) return t[k].val;
    int mid = (t[k].l + t[k].r) / 2;
    if (y <= mid) return query(k << 1, x, y);
    else if (x > mid) return query(k << 1 | 1, x, y);
    else return max(query(k << 1, x, y), query(k << 1 | 1, x, y));
}


    


void id3(int n)
{
    ecnt = 0;
    fill(head, head + n + 1, 0);
    fill(son, son + n + 1, 0);
}
void dfs1(int x)
{
    siz[x] = 1;
    dep[x] = dep[f[x]] + 1;
    for (int i = head[x]; i; i = e[i].ne)
    {
        int dd = e[i].to;
        if (dd == f[x]) continue;
        f[dd] = x;
        dfs1(dd);
        siz[x] += siz[dd];
        if (!son[x] || siz[son[x]] < siz[dd])
            son[x] = dd;
    }
}
void dfs2(int x, int tv)
{
    top[x] = tv;
    if (son[x]) dfs2(son[x], tv);
    for (int i = head[x]; i; i = e[i].ne)
    {
        int dd = e[i].to;
        if (dd == f[x] || dd == son[x])continue;
        dfs2(dd, dd);
    }
}
int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] >= dep[top[y]])x = f[top[x]];
        else y = f[top[y]];
    }
    return dep[x] < dep[y] ? x : y;
}



int find(int x)
{
    if (fa[x] == x) return fa[x];
    else return fa[x] = find(fa[x]);
}

void init()
{
    cnt = n; tot = 0; ecnt = 0;
    iota(fa, fa + 2 * n + 1, 0);
    cnt = n + 1; tot = 0;
    for (int i = 0; i <= n * 2; i++)
    {
        fa[i] = i;
        
    }
    
}

void id2()
{
    

    for (int i = 1, x, y; i <= m; i++)
    {
        

        cin >> x >> y;
        x += n; y += n;
        int fax = find(x); int fay = find(y);
        if (fax == fay) continue;
        cnt--;

        myadd(cnt, fax);
        myadd(cnt, fay);
        fa[fa[x]] = fa[fa[y]] = cnt;
        val[cnt] = i;
    }
}


int getans(int L, int R)
{
    if (L == R) return 0;
    return query(1, L, R - 1);
}



void solve()
{
    cin >> n >> m >> q;
    init();
    id3(2 * n);
    id2();
    dfs1(cnt);
    dfs2(cnt, cnt);
    for (int i = 1; i < n; i++)
    {
        ans[i] = val[lca(i + n, i + n + 1)];
    }
    build(1, 1, n - 1);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << getans(x, y) << ' ';
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

    clock_t time_start = clock();

    myinit();
    while (T_T--) solve();
    


    fin.close(); fout.close();
    clock_t time_end = clock();
    debug(time_end - time_start);

    return 0;
}
