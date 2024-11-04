



























using namespace std;
template <typename T>
using vc = vector<T>;
template <typename T>
using vvc = vc<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <typename T>
using PQ = priority_queue<T, vc<T>, greater<T>>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;


using vi = vc<int>;
using vl = vc<ll>;
using vd = vc<double>;
using vb = vc<bool>;


    vector<type> name(size);  \
    IN(name)


    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)


    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(id0))))


















const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }

    int id0; \
    IN(id0)

    ll id0; \
    IN(id0)

    string id0; \
    IN(id0)

    char id0; \
    IN(id0)

    double id0; \
    IN(id0)
int scan()
{
    return getchar();
}
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T>
void scan(vector<T> &a)
{
    for (auto &i : a)
        scan(i);
}
void out(int &a) { cout << a << endl; }
void out(ll &a) { cout << a << endl; }
void out(char &a) { cout << a << endl; }
void out(double &a) { cout << a << endl; }
void out(string &a) { cout << a << endl; }
template <class T, class S>
void out(pair<T, S> &p) { cout << p.fi << " " << p.se << endl; }
template <class T>
void out(vector<T> &a)
{
    for (auto &i : a)
        out(i);
}
template <class T>
void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail)
{
    scan(head);
    IN(tail...);
}
template <class T>
void vout(vector<T> &a)
{
    rep(i, si(a))
    {
        if (i > 0)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}
template <class T>
void vvout(vvc<T> &a)
{
    for (auto x : a)
        vout(x);
}
ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
ll allbit(ll n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool id1(int i) { return i && (i & -i) == i; }
template <class T>
pair<T, T> operator-(const pair<T, T> &x, const pair<T, T> &y) { return pair<T, T>(x.fi - y.fi, x.se - y.se); }
template <class T>
pair<T, T> operator+(const pair<T, T> &x, const pair<T, T> &y) { return pair<T, T>(x.fi + y.fi, x.se + y.se); }
template <class T>
ll operator*(const pair<T, T> &x, const pair<T, T> &y) { return (ll)x.fi * y.fi + (ll)x.se * y.se; }
template <class T1, class T2, class Pred = std::less<T2>>
struct sort_pair_second
{
    

    bool operator()(const std::pair<T1, T2> &left, const std::pair<T1, T2> &right)
    {
        Pred p;
        return p(left.second, right.second);
    }
};
bool valid(ll h, ll w, ll mh, ll mw)
{
    return h >= 0 && h < mh && w >= 0 && w < mw;
}
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
int MOD = 1e9 + 7;
double EPS = 1e-6;
int INF = 2000000005;
long long INFF = 4000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
int rdx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int rdy[8] = {0, 1, 1, 1, 0, -1, -1, -1};





const int mod = MOD;
const int MX = 400000;
using uint = unsigned;
using ull = unsigned long long;
struct mint
{
    uint x;
    mint() : x(0) {}
    mint(ll x) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(0) - *this; }
    mint operator~() const { return mint(1) / *this; }
    mint &operator+=(const mint &a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint &a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint &a)
    {
        x = (ull)x * a.x % mod;
        return *this;
    }
    mint &operator/=(const mint &a)
    {
        x = (ull)x * a.pow(mod - 2).x % mod;
        return *this;
    }
    mint operator+(const mint &a) const { return mint(*this) += a; }
    mint operator-(const mint &a) const { return mint(*this) -= a; }
    mint operator*(const mint &a) const { return mint(*this) *= a; }
    mint operator/(const mint &a) const { return mint(*this) /= a; }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint res = pow(t / 2);
        res *= res;
        return (t & 1) ? res * x : res;
    }
    bool operator<(const mint &a) const { return x < a.x; }
    bool operator==(const mint &a) const { return x == a.x; }
    bool operator!=(const mint &a) const { return x != a.x; }
};

istream &operator>>(istream &i, mint &a)
{
    i >> a.x;
    return i;
}
ostream &operator<<(ostream &o, const mint &a)
{
    o << a.x;
    return o;
}

ll modpow(ll a, ll b, ll Mod)
{
    ll res = 1;
    for (a %= Mod; b; a = a * a % Mod, b >>= 1)
        if (b & 1)
            res = res * a % Mod;
    return res;
}












































vector<int> ps, pf;




void sieve(int mx)
{
    pf = vector<int>(mx + 1);
    rep(i, mx + 1)
        pf[i] = i;
    for (int i = 2; i <= mx; ++i)
    {
        if (pf[i] == i)
            ps.push_back(i);
        for (int j = 0; j < si(ps) && ps[j] <= pf[i]; ++j)
        {
            int x = ps[j] * i;
            if (x > mx)
                break;
            pf[x] = ps[j];
        }
    }
}
vc<pi> factor(int x)
{
    if (x == 1)
        return {};
    vector<pi> res(1, pi(pf[x], 0));
    while (x != 1)
    {
        if (res.back().first == pf[x])
            res.back().second++;
        else
            res.push_back(pi(pf[x], 1));
        x /= pf[x];
    }
    

    

    

    

    return res;
}

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}
    edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnweightedGraph = vector<vector<int>>;


UnweightedGraph graph(int N, int M = -1, bool id2 = false,
                      bool id3 = true)
{
    UnweightedGraph g(N);
    if (M == -1)
        M = N - 1;
    for (int _ = 0; _ < M; _++)
    {
        int x, y;
        cin >> x >> y;
        if (id3)
            x--, y--;
        g[x].push_back(y);
        if (!id2)
            g[y].push_back(x);
    }
    return g;
}


template <typename T>
WeightedGraph<T> wgraph(int N, int M = -1, bool id2 = false,
                        bool id3 = true)
{
    WeightedGraph<T> g(N);
    if (M == -1)
        M = N - 1;
    for (int _ = 0; _ < M; _++)
    {
        int x, y;
        cin >> x >> y;
        T c;
        cin >> c;
        if (id3)
            x--, y--;
        g[x].emplace_back(x, y, c);
        if (!id2)
            g[y].emplace_back(y, x, c);
    }
    return g;
}
vector<ll> dijkstra(WeightedGraph<ll> &g, int start = 0)
{
    using P = pair<ll, int>;
    int N = (int)g.size();
    vector<ll> d(N, INFF);
    priority_queue<P, vector<P>, greater<P>> Q;
    d[start] = 0;
    Q.emplace(0, start);
    while (!Q.empty())
    {
        P p = Q.top();
        Q.pop();
        int cur = p.second;
        if (d[cur] < p.first)
            continue;
        for (auto dst : g[cur])
        {
            if (d[dst] == INFF || d[cur] + dst.cost < d[dst])
            {
                d[dst] = d[cur] + dst.cost;
                Q.emplace(d[dst], dst);
            }
        }
    }
    return d;
}

void rvs(vl &A, int idx)
{
    rep(i, idx + 1)
    {
        if (i >= idx - i)
            break;
        swap(A[i], A[idx - i]);
    }
}

void solve()
{
    INT(N);
    VEC(ll, A, N);
    for (int i = 1; i < N; i += 2)
    {
        if (A[i] % 2 == 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    vl B(N);
    rep(i, N) B[i] = i + 1;
    vl ans;
    auto rvs = [&](int idx)
    {
        ans.pb(idx);
        reverse(A.begin(), A.begin() + idx);
    };

    rep3(i, N - 1, 1)
    {
        int idx, idx2;

        rep(j, i + 1) if (A[j] == B[i])
        {
            idx2 = j;
            break;
        }
        rvs(idx2 + 1);
        rep(j, i + 1) if (B[i - 1] == A[j])
        {
            idx = j;
            break;
        }
        if (idx == 1)
        {
            rvs(i + 1);
            i--;
            continue;
        }
        rvs(idx);
        rvs(idx + 2);
        rvs(3);
        rvs(i + 1);
        i--;
    }
    

    cout << si(ans) << endl;
    if (si(ans))
        vout(ans);
    cout.flush();
}

int main()
{
    cout.tie(nullptr);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    INT(T);
    while (T--)
        solve();
}