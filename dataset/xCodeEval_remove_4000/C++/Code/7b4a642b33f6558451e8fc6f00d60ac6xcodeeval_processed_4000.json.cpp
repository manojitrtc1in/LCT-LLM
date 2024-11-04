

using namespace std;































template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename T>
string to_string(stack<T> st);
template <typename T>
string to_string(queue<T> q);
string to_string(char c) { return string(1, c); }
string to_string(const string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v)
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}


template <size_t S>
string to_string(bitset<S> b)
{
    string res;
    res += '{';
    bool f = true;
    for (int i = 0; i < S; ++i)
    {
        if (!f)
        {
            res += ',';
        }
        f = false;
        res += char('0' + b[i]);
    }
    res += '}';
    return res;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename T>
string to_string(stack<T> st)
{
    bool first = true;
    string res = "{";
    while (!st.empty())
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(st.top());
        st.pop();
    }
    res += "}";
    return res;
}
template <typename T>
string to_string(queue<T> q)
{
    bool first = true;
    string res = "{";
    while (!q.empty())
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;
}
template <typename T>
string to_string(T pq, bool ispq)
{
    assert(ispq);
    bool first = true;
    string res = "{";
    while (!pq.empty())
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
}


void DBG() { cerr << " ]"
                  << "\n"; }
template <typename Head, typename... Tail>
void DBG(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    if (sizeof...(T))
    {
        cerr << ", ";
    }
    DBG(T...);
}












using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename key, typename value, typename cmp = std::less<key>>
using omap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;












void read(char &x) { cin >> x; }
void read(int &x) { cin >> x; }
void read(ll &x) { cin >> x; }
void read(double &x) { cin >> x; }
void read(string &s) { cin >> s; }


template <typename T1, typename T2>
void read(pair<T1, T2> &p) { cin >> p.first >> p.second; }
template <typename T>
void read(T &A)
{
    for (auto &x : A)
    {
        read(x);
    }
}
template <typename T>
void assign_offset(T &A, int off = -1)
{
    for (auto &x : A)
    {
        x += off;
    }
}
template <class H, class... T>
void read(H &h, T &... t)
{
    read(h);
    read(t...);
}






template <typename T>
void out(T &A, int offset = 0)
{
    for (auto &x : A)
    {
        x += offset;
        cout << x << " ";
    }
    cout << "\n";
}





    {                                        \
        ll lo = lo_val, hi = hi_val, mid;    \
        while (lo <= hi)                     \
        {                                    \
            mid = lo + (hi - lo) / 2;        \
            if (valid(mid))                  \
            {                                \
                ansi = mid;                  \
                hi = mid - 1;                \
            }                                \
            else                             \
            {                                \
                lo = mid + 1;                \
            }                                \
        }                                    \
    }

    {                                        \
        ll lo = lo_val, hi = hi_val, mid;    \
        while (lo <= hi)                     \
        {                                    \
            mid = lo + (hi - lo) / 2;        \
            if (valid(mid))                  \
            {                                \
                ansi = mid;                  \
                lo = mid + 1;                \
            }                                \
            else                             \
            {                                \
                hi = mid - 1;                \
            }                                \
        }                                    \
    }

    {                                              \
        ll lo = lo_val, hi = hi_val, m1, m2;       \
        const int id6 = 7;                   \
        while (hi - lo > id6)                \
        {                                          \
            m1 = lo + (hi - lo) / 3;               \
            m2 = hi - (hi - lo) / 3;               \
            if (gv(m1) < gv(m2))                   \
            {                                      \
                lo = m1;                           \
            }                                      \
            else                                   \
            {                                      \
                hi = m2;                           \
            }                                      \
        }                                          \
        ansi = lo;                                 \
        ansv = gv(lo);                             \
        for (int i = lo + 1; i <= hi; ++i)         \
        {                                          \
            if (a_max(ansv, gv(i)))                \
            {                                      \
                ansi = i;                          \
            }                                      \
        }                                          \
    }

    {                                              \
        ll lo = lo_val, hi = hi_val, m1, m2;       \
        const int id6 = 7;                   \
        while (hi - lo > id6)                \
        {                                          \
            m1 = lo + (hi - lo) / 3;               \
            m2 = hi - (hi - lo) / 3;               \
            if (gv(m1) > gv(m2))                   \
            {                                      \
                lo = m1;                           \
            }                                      \
            else                                   \
            {                                      \
                hi = m2;                           \
            }                                      \
        }                                          \
        ansi = lo;                                 \
        ansv = gv(lo);                             \
        for (int i = lo + 1; i <= hi; ++i)         \
        {                                          \
            if (a_min(ansv, gv(i)))                \
            {                                      \
                ansi = i;                          \
            }                                      \
        }                                          \
    }

    {                                                 \
        double lo = lo_val, hi = hi_val, m1, m2;      \
        const double eps = 1e-9;                      \
        while (hi - lo > eps)                         \
        {                                             \
            m1 = lo + (hi - lo) / 3;                  \
            m2 = hi - (hi - lo) / 3;                  \
            if (gv(m1) < gv(m2))                      \
            {                                         \
                lo = m1;                              \
            }                                         \
            else                                      \
            {                                         \
                hi = m2;                              \
            }                                         \
        }                                             \
        double ansi = lo;                             \
        double ansv = gv(lo);                         \
    }

    {                                                 \
        double lo = lo_val, hi = hi_val, m1, m2;      \
        const double eps = 1e-9;                      \
        while (hi - lo > eps)                         \
        {                                             \
            m1 = lo + (hi - lo) / 3;                  \
            m2 = hi - (hi - lo) / 3;                  \
            if (gv(m1) > gv(m2))                      \
            {                                         \
                lo = m1;                              \
            }                                         \
            else                                      \
            {                                         \
                hi = m2;                              \
            }                                         \
        }                                             \
        double ansi = lo;                             \
        double ansv = gv(lo);                         \
    }


mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand_m(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(mt_rng); }


template <typename T>
bool a_min(T &a, const T &b) { return (b < a) ? (a = b), 1 : 0; }


template <typename T>
bool a_max(T &a, const T &b) { return (b > a) ? (a = b), 1 : 0; }


ll ceil(ll m, ll n) { return (m + n - 1) / n; }




template <typename T>
ll gv(int i, int j, vector<T> &pre)
{
    if (i > j || (j < 0))
    {
        return 0LL;
    }
    ll val = pre[j];
    if (i - 1 >= 0)
    {
        val -= pre[i - 1];
    }
    return val;
}


template <typename T>
ll gpv(int i, vector<T> &pre) { return gv(0, i, pre); }


template <typename T>
ll gsv(int i, vector<T> &suf)
{
    int n = sz(suf);
    if (i >= n)
    {
        return 0LL;
    }
    return suf[i];
}


template <typename T>
void assign_pre(vector<T> &pre, vector<T> &A)
{
    int n = sz(A);
    for (int i = 0; i < n; ++i)
    {
        pre[i] = A[i];
        if (i)
        {
            pre[i] += pre[i - 1];
        }
    }
}


template <typename T>
void id3(vector<T> &suf, vector<T> &A)
{
    int n = sz(A);
    for (int i = n - 1; i >= 0; --i)
    {
        suf[i] = A[i];
        if (i + 1 < n)
        {
            suf[i] += suf[i + 1];
        }
    }
}


template <typename T>
int sorted_range(const vector<T> &A, int l, int r)
{
    int n = A.size();
    if (r < l)
    {
        return 0;
    }
    return ubi(A, r) - ubi(A, l - 1);
}


template <typename T>
void remove_dup(vector<T> &v)
{
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}


constexpr int ppcnt(int x) { return __builtin_popcount(x); }
constexpr int ppcnt(ll x) { return __builtin_popcountll(x); }


constexpr int id4(int x) { return 31 - __builtin_clz(x); }
constexpr int id4(ll x) { return 63 - __builtin_clzll(x); }






auto start = std::chrono::system_clock::now();




const ld PI = acos((ld)-1);
const ll inf = 2e18;
const ll ninf = -2e18;

const int M = 1e9 + 7;




    cout << "Good" \
         << "\n";  \
    return;

    cout << "Bad" \
         << "\n"; \
    return;



bool id8 = 0;

bool id1 = 0;












struct id5
{

    int n;
    vector<vector<ar<int, 2>>> adj;
    bool id9 = false;
    int id7;
    int diam_len = 0;
    vector<int> parent_d;
    vector<int> parent;
    vector<int> diam_path;
    vector<int> depths, tin, out_time, subs;

    int time = 0;

    void init_others()
    {
        parent.resize(n, -1);
        parent_d.resize(n, -1);
        depths.resize(n);
        tin.resize(n);
        out_time.resize(n);
        subs.resize(n);
    }
    id5(vector<vector<ar<int, 2>>> &_adj)
    {

        adj = _adj;
        n = sz(adj);
        init_others();
    }

    id5(int _n, int id2, bool id0)
    {
        n = _n;
        adj.resize(n);
        init_others();
        id7 = id2;
        id9 = id0;
        read_graph();
    }

    vector<ll> dijkstra(int s, int d)
    {

        vector<ll> dist(n, inf);

        priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty())
        {

            auto top = pq.top();
            pq.pop();

            ll d = top[0];
            int u = top[1];

            if (d > dist[u])
            {
                continue;
            }

            for (auto p : adj[u])
            {
                int v = p[0];
                int d = p[1];

                if (a_min(dist[v], dist[u] + d))
                {
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    void read_graph()
    {

        int m = id7;

        int u, v;

        int w;

        for (int i = 0; i < m; ++i)
        {

            cin >> u >> v;

            --u;
            --v;

            if (id9)
            {
                cin >> w;
            }
            else
            {
                w = 1;
            }

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    ar<int, 2> dfs_d1(int i, int p, int d, vector<int> &par)
    {

        ar<int, 2> cur = {d, i};

        par[i] = p;

        for (auto j : adj[i])
        {
            if (j[0] == p)
            {
                continue;
            }

            cur = max(cur, dfs_d1(j[0], i, d + 1, par));
        }

        return cur;
    }

    

    void set_diameter_path()
    {

        vector<int> par = vector<int>(n, -1);

        ar<int, 2> st = dfs_d1(0, -1, 1, par);

        par = vector<int>(n, -1);

        ar<int, 2> en = dfs_d1(st[1], -1, 1, par);

        diam_len = en[0];

        int u = st[1];
        int v = en[1];

        parent_d = par;
        while (v != u)
        {
            diam_path.push_back(v);
            v = par[v];
        }

        diam_path.push_back(u);
    }

    void set_others(int i, int p, int d)
    {
        depths[i] = d;

        parent[i] = p;

        int sum = 1;

        tin[i] = time;
        for (auto j : adj[i])
        {
            if (j[0] == p)
            {
                continue;
            }
            ++time;
            set_others(j[0], i, d + 1);
            sum += subs[i];
        }
        out_time[i] = time;
        subs[i] = sum;
    }
};

void solve()
{

    int n, m, k;

    cin >> n >> m >> k;

    id5 g(n, m, true);

    vector<vector<ll>> dist(n);

    for (int i = 0; i < n; ++i)
    {
        dist[i] = g.dijkstra(i, i);
    }

    


    vector<ar<int, 2>> A(k);

    int u, v;
    for (int i = 0; i < k; ++i)
    {
        cin >> u >> v;
        --u;
        --v;
        A.push_back({u, v});
    }

    ll ans = 2e9;
    for (int x = 0; x < n; ++x)
    {
        for (auto p : g.adj[x])
        {
            int y = p[0];
            ll cur = 0;

            for (auto e : A)
            {
                int a = e[0], b = e[1];

                cur += min({dist[a][b], dist[a][x] + dist[y][b], dist[a][y] + dist[x][b]});
            }

            ans = min(ans, cur);
        }
    }

    cout << ans << "\n";
}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

    if (id8)
    {
        id1 = true;
    }

    if (id1)
    {
        cin >> T;
    }

    for (int t = 1; t <= T; ++t)
    {
        if (t == 1)
        {

            start = std::chrono::system_clock::now();

        }
        if (id8)
            cout << "Case 
        solve();
    }


    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cerr << "Elapsed time: " << elapsed_seconds.count() << "s\n";


    return 0;
}

