const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;



using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;





















int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

int ok(int x, int n)
{
    return 0 <= x && x < n;
}

ll log10(ll x)
{
    if (x < 10) re 1;
    re 1 + log10(x / 10);
}

ll ds(ll x)
{
    if (x < 10) return x;
    re x % 10 + ds(x / 10);
}

double sqr(double x)
{
    return x * x;
}

bool inmask(int bit, int mask)
{
    return (mask & (1 << bit)) > 0;
}

void Del(vector<int> &v, int pos)
{
    swap(v[pos], v[v.size() - 1]);
    v.pop_back();
}

long long g(vector<long long> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

int g(vector<int> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

ll binpow(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = binpow(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return binpow(x, MOD - 2);
}

int id9 = 0;
vector<ll> __fact, __ufact, __rev;

inline void id10(int __n)
{
    if (id9 >= __n)
        return;
    __fact.resize(__n);
    __ufact.resize(__n);
    __rev.resize(__n);
    __rev[1] = 1;
    for (int i = max(2, id9); i < __n; i++)
        __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = max(1, id9); i < __n; i++)
        __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
    id9 = __n;
}

ll fact(int x)
{
    if (id9 <= x)
        id10(x + 1);
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (id9 <= n)
        id10(n + 1);
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

ll inq(ll x, ll y, ll mod)
{
    if (y == 0) return 1 % mod;
    ll l = inq(x, y / 2, mod);
    if (y % 2) return l * l % mod * x % mod;
    return l * l % mod;
}

ll id7(ll a, ll b, ll &x, ll &y)
{
    

    

    

    

    

    

    

    

    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll g = id7(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

pair<ll, ll> crt(vector<ll> r, vector<ll> m)
{
    

    

    

    

    

    

    

    int n = r.size();
    for (int i = 0; i < n; i++) r[i] %= m[i];
    ll r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++)
    {
        ll r1 = r[i], m1 = m[i];
        if (m0 < m1)
        {
            swap(m0, m1);
            swap(r0, r1);
        }
        if (m0 % m1 == 0)
        {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        ll x, y;
        ll g = id7(m0, m1, x, y);
        ll u = m1 / g;
        if ((r0 - r1) % g != 0)
            return {0, 0};
        ll z = (r1 - r0) / g % u * x % u;
        r0 += z * m0;
        m0 *= u;
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

struct dsu
{
    vector<int> root;
    vector<int> sz;

    dsu(int _n)
    {
        root.resize(_n);
        iota(all(root), 0);
        sz.resize(_n, 1);
    }

    dsu()
    {
        dsu(0);
    }

    void Reset(int _n)
    {
        root.resize(_n);
        sz.resize(_n);
        for (int i = 0; i < (int)root.size(); i++)
        {
            root[i] = i;
            sz[i] = 1;
        }
    }

    void Reset()
    {
        Reset(root.size());
    }

    int Root(int x)
    {
        if (x == root[x]) return x;
        return root[x] = Root(root[x]);
    }

    void Merge(int v, int u)
    {
        v = Root(v), u = Root(u);
        if (v == u) return;
        if (sz[v] < sz[u])
        {
            sz[u] += sz[v];
            root[v] = u;
        }
        else
        {
            sz[v] += sz[u];
            root[u] = v;
        }
    }
};

struct id3
{
    vector<int> root;
    vector<int> sz;
    stack<int> cuts;

    id3(int _n)
    {
        root.resize(_n);
        iota(all(root), 0);
        sz.resize(_n, 1);
    }

    id3()
    {
        id3(0);
    }

    void Cut()
    {
        if (!cuts.size()) return;
        int v = cuts.top();
        sz[root[v]] -= sz[v];
        root[v] = v;
        cuts.pop();
    }

    void Reset(int _n)
    {
        root.resize(_n);
        sz.resize(_n);
        for (int i = 0; i < (int)root.size(); i++)
        {
            root[i] = i;
            sz[i] = 1;
        }
    }

    void Reset()
    {
        if (cuts.size() < root.size())
        {
            while (cuts.size())
            {
                Cut();
            }
        }
        else
        {
            Reset(root.size());
        }
    }

    int Root(int x)
    {
        if (x == root[x]) return x;
        return Root(root[x]);
    }

    void Merge(int v, int u)
    {
        v = Root(v), u = Root(u);
        if (v == u) return;
        if (sz[v] < sz[u])
        {
            sz[u] += sz[v];
            root[v] = u;
            cuts.push(v);
        }
        else
        {
            sz[v] += sz[u];
            root[u] = v;
            cuts.push(u);
        }
    }
};

void bfs(int v, vi &dist, vector<vi> &graph)
{
    fill(all(dist), -1);
    dist[v] = 0;
    vi q = {v};
    for (int i = 0; i < (int)q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
}

vector<int> z_func(string &s)
{
    

    

    

    

    

    

    vector<int> z(s.size());
    z[0] = s.size();
    int L = 0, R = 0;
    for (int i = 1; i < (int)s.size(); i++)
    {
        z[i] = max(0, min(z[i - L], R - i));
        while (i + z[i] < (int)s.size() && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > R)
        {
            R = i + z[i];
            L = i;
        }
    }
    return z;
}

vector<int> p_func(string &s)
{
    

    

    

    vector<int> p(s.size());
    for (int i = 1; i < (int)s.size(); i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

vector<int> id8(string &s)
{
    

    

    

    vector<int> d1(s.size());
    int L = 0, R = -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d1[R - i + L]);
        while (i + k < (int)s.size() && i - k >= 0 && s[i - k] == s[i + k])
            k++;
        d1[i] = k--;
        if (i + k > R)
        {
            L = i - k;
            R = i + k;
        }
    }
    return d1;
}

vector<int> id1(string &s)
{
    

    

    

    vector<int> d2(s.size());
    int L = 0, R = -1;
    for (int i = 1; i < (int)s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d2[R - i + L + 1]);
        while (i + k < (int)s.size() && i - k - 1 >= 0 && s[i - k - 1] == s[i + k])
            k++;
        d2[i] = k--;
        if (i + k > R)
        {
            L = i - k - 1;
            R = i + k;
        }
    }
    return d2;
}

template<class T> void add(int pos, T x, vector<T> &fenw)
{
    

    

    

    

    

    while (pos < (int)fenw.size())
    {
        fenw[pos] += x;
        pos |= (pos + 1);
    }
}

template<class T> T get(int pos, vector<T> &fenw)
{
    

    

    

    

    

    ll res = 0;
    while (pos >= 0)
    {
        res += fenw[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

template<class T> vector<int> id5(vector<T> a, vector<int> l, vector<int> r)
{
    

    

    

    

    

    map<T, int> lst;
    vector<int> ans(l.size());
    vector<vector<int> > ends(a.size());
    vector<int> fenw(a.size());
    for (int i = 0; i < (int)l.size(); i++)
    {
        ends[r[i]].push_back(i);
    }
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (lst.find(a[i]) != lst.end())
        {
            add(lst[a[i]], -1, fenw);
        }
        lst[a[i]] = i;
        add(i, 1, fenw);
        for (auto q : ends[i])
        {
            ans[q] = get(i, fenw) - get(l[q] - 1, fenw);
        }
    }
    return ans;
}

struct id11{
    

    

    

    

    

    

    

    

    

    

    

    

    

    int n, m;
    id3 dcp;
    vector<int> ans;
    void solve(int l, int r, vi &v, vi &u, vi &t, vi &L, vi &R)
    {
        if (l >= r) return;
        if (l + 1 == r)
        {
            if (t[l] == -1)
            {
                ans[l] = n - dcp.cuts.size();
            }
            if (t[l] == 1)
            {
                ans[l] = dcp.Root(v[l]) == dcp.Root(u[l]);
            }
            return;
        }
        int m = (l + r) / 2;
        int ss = dcp.cuts.size();
        for (int i = l; i < m; i++)
        {
            if (R[i] >= r) dcp.Merge(v[i], u[i]);
        }
        solve(m, r, v, u, t, L, R);
        while ((int)dcp.cuts.size() > ss) dcp.Cut();
        for (int i = r - 1; i >= m; i--)
        {
            if (L[i] < l) dcp.Merge(v[i], u[i]);
        }
        solve(l, m, v, u, t, L, R);
        while ((int)dcp.cuts.size() > ss) dcp.Cut();
    }
    id11(int _n, int _m, vi v, vi u, vi t)
    {
        n = _n, m = _m;
        dcp.Reset(n);
        ans.resize(m, -1);
        map<pair<int, int>, int> mm;
        vi L(m, INF), R(m, -INF);
        for (int i = 0; i < m; i++)
        {
            if (t[i] != 0) continue;
            if (v[i] > u[i]) swap(v[i], u[i]);
            if (mm.find({v[i], u[i]}) == mm.end())
            {
                mm[{v[i], u[i]}] = i;
            }
            else
            {
                int t = mm[{v[i], u[i]}];
                R[t] = i;
                L[i] = t;
                mm.erase({v[i], u[i]});
            }
        }
        while (mm.size())
        {
            t.push_back(0);
            ans.push_back(-1);
            L.push_back(INF);
            R.push_back(-INF);
            auto it = mm.begin();
            pair<int, int> s = (*it).first;
            int t = (*it).second;
            R[t] = m;
            L[m] = t;
            v.push_back(s.first);
            u.push_back(s.second);
            mm.erase(mm.begin());
            m++;
        }
        solve(0, m, v, u, t, L, R);
    }
};

template<class T> struct id6{
    

    

    

    

    

    

    

    vector<vector<T> > sp;
    vector<int> H;
    T get(int l, int r)
    {
        int h = H[r - l + 1];
        return min(sp[h][l], sp[h][r - (1 << h) + 1]);
    }
    id6(vector<T> a)
    {
        int n = a.size();
        H = vector<int>(n + 1);
        for (int i = 3; i < n + 1; i++)
        {
            H[i] = H[i - 1] + (((i - 1) & (i - 2)) == 0);
        }
        int s = 0;
        while ((1 << s) < n) s++;
        sp = vector<vector<T>>(s, vector<T>(n));
        for (int i = 0; i < n; i++)
        {
            sp[0][i] = a[i];
        }
        for (int j = 1; j < s; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                sp[j][i] = get(i, i + (1 << j) - 1);
            }
        }
    }
};

template<class T> struct id2{
    

    

    

    

    

    

    

    vector<vector<T> > sp;
    vector<int> H;
    T get(int l, int r)
    {
        int h = H[r - l + 1];
        return max(sp[h][l], sp[h][r - (1 << h) + 1]);
    }
    id2(vector<T> a)
    {
        int n = a.size();
        H = vector<int>(n + 1);
        for (int i = 3; i < n + 1; i++)
        {
            H[i] = H[i - 1] + (((i - 1) & (i - 2)) == 0);
        }
        int s = 0;
        while ((1 << s) < n) s++;
        sp = vector<vector<T>>(s, vector<T>(n));
        for (int i = 0; i < n; i++)
        {
            sp[0][i] = a[i];
        }
        for (int j = 1; j < s; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                sp[j][i] = get(i, i + (1 << j) - 1);
            }
        }
    }
};

struct id4{
    

    

    

    

    

    int n;
    vector<vector<int> > graph;
    vector<vector<int> > inv_graph;
    vector<int> fr, to;
    vector<int> fn;
    vector<int> vis;
    vector<int> component;
    int col;
    void inv_dfs(int v)
    {
        vis[v] = 1;
        for (auto id : inv_graph[v])
        {
            int u = fr[id];
            if (!vis[u])
            {
                inv_dfs(u);
            }
        }
        fn.push_back(v);
    }
    void dfs(int v)
    {
        component[v] = col;
        for (auto id : graph[v])
        {
            int u = to[id];
            if (component[u] == -1)
            {
                dfs(u);
            }
        }
    }
    id4(int _n)
    {
        n = _n;
        graph = vector<vector<int> >(n);
        inv_graph = vector<vector<int> >(n);
    }
    void add_edge(int v, int u)
    {
        graph[v].push_back(fr.size());
        inv_graph[u].push_back(fr.size());
        fr.push_back(v);
        to.push_back(u);
    }
    vector<vector<int> > scc()
    {
        vis = vector<int>(n);
        component = vector<int>(n, -1);
        fn = {};
        col = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                inv_dfs(i);
            }
        }
        reverse(fn.begin(), fn.end());
        for (auto i : fn)
        {
            if (component[i] == -1)
            {
                dfs(i);
                col++;
            }
        }
        vector<vector<int> > res(col);
        for (int i = 0; i < n; i++)
        {
            res[component[i]].push_back(i);
        }
        return res;
    }
};

struct id0{
    

    

    

    

    

    

    

    

    

    

    int n;
    vector<vector<int> > graph;
    vector<int> v;
    vector<int> u;
    vector<int> isbridge;
    vector<int> in, out, up;
    vector<int> color;
    vector<int> par;
    int T;
    void dfs(int V, int P, int edge_in)
    {
        par[V] = P;
        in[V] = up[V] = T++;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (in[t] == -1)
            {
                dfs(t, V, id);
                up[V] = min(up[V], up[t]);
            }
            else if (id != edge_in)
            {
                up[V] = min(up[V], in[t]);
            }
        }
        out[V] = T++;
    }
    void dfs_dlc(int V)
    {
        color[V] = T;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (!isbridge[id] && color[t] == -1)
            {
                dfs_dlc(t);
            }
        }
    }
    id0(int _n)
    {
        n = _n;
        graph = vector<vector<int> >(n);
    }
    void add_edge(int V, int U)
    {
        graph[V].push_back(v.size());
        graph[U].push_back(v.size());
        v.push_back(V);
        u.push_back(U);
    }
    void mark_bridges()
    {
        in = vector<int>(n, -1);
        out = vector<int>(n, -1);
        up = vector<int>(n, -1);
        par = vector<int>(n, -1);
        isbridge = vector<int>(v.size(), 0);
        T = 0;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == -1)
            {
                dfs(i, -1, -1);
            }
        }
        int m = v.size();
        for (int i = 0; i < m; i++)
        {
            if (par[u[i]] == v[i] && up[u[i]] == in[u[i]])
            {
                isbridge[i] = 1;
            }
            if (par[v[i]] == u[i] && up[v[i]] == in[v[i]])
            {
                isbridge[i] = 1;
            }
        }
    }
    vector<vector<int> > dlc()
    {
        mark_bridges();
        color = vector<int>(n, -1);
        T = 0;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                dfs_dlc(i);
                T++;
            }
        }
        vector<vector<int> > res(T);
        for (int i = 0; i < n; i++)
        {
            res[color[i]].push_back(i);
        }
        return res;
    }
};

struct graph_AP{
    

    

    

    

    

    

    

    

    

    

    int n;
    vector<vector<int> > graph;
    vector<int> v;
    vector<int> u;
    vector<int> isAP;
    vector<int> in, out, up;
    vector<int> par;
    vector<int> color;
    vector<int> vis;
    int T, rd;
    int maxColor;
    void dfs(int V, int P)
    {
        par[V] = P;
        in[V] = up[V] = T++;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (in[t] == -1)
            {
                if (P == -1)
                    rd++;
                dfs(t, V);
                up[V] = min(up[V], up[t]);
            }
            else if (t != P)
            {
                up[V] = min(up[V], in[t]);
            }
        }
        out[V] = T++;
    }
    void dfs_blocks(int V, int P, int c)
    {
        vis[V] = 1;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (t == P)
            {
                continue;
            }
            if (!vis[t])
            {
                if (up[t] >= in[V])
                {
                    maxColor++;
                    color[id] = maxColor - 1;
                    dfs_blocks(t, V, maxColor - 1);
                }
                else
                {
                    color[id] = c;
                    dfs_blocks(t, V, c);
                }
            }
            else
            {
                if (in[t] < in[V])
                {
                    color[id] = c;
                }
            }
        }
    }
    graph_AP(int _n)
    {
        n = _n;
        graph = vector<vector<int> >(n);
    }
    void add_edge(int V, int U)
    {
        graph[V].push_back(v.size());
        graph[U].push_back(v.size());
        v.push_back(V);
        u.push_back(U);
    }
    void mark_AP()
    {
        in = vector<int>(n, -1);
        out = vector<int>(n, -1);
        up = vector<int>(n, -1);
        par = vector<int>(n, -1);
        isAP = vector<int>(n, 0);
        T = 0;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == -1)
            {
                rd = 0;
                dfs(i, -1);
                if (rd > 1)
                    isAP[i] = 1;
                else
                    isAP[i] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (isAP[i] == 0)
            {
                for (auto id : graph[i])
                {
                    int t = v[id] + u[id] - i;
                    if (par[t] == i && in[i] <= up[t])
                        isAP[i] = 1;
                }
            }
            else
            {
                if (isAP[i] == -1)
                {
                    isAP[i] = 0;
                }
            }
        }
    }
    vector<vector<int> > blocks()
    {
        mark_AP();
        color = vector<int>(v.size(), -1);
        vis = vector<int>(n, 0);
        maxColor = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs_blocks(i, -1, maxColor);
                maxColor++;
            }
        }
        vector<vector<int> > res = vector<vector<int> >(maxColor);
        for (int i = 0; i < (int)v.size(); i++)
        {
            res[color[i]].push_back(i);
        }
        vector<vector<int> > res2;
        for (int i = 0; i < (int)res.size(); i++)
        {
            if (res[i].size())
            {
                res2.push_back(res[i]);
            }
        }
        return res2;
    }
};

struct fft_runner{
    

    

    

    

    

    

    const int G = 3;
    const int G_REV = binpow(G, MOD - 2);
    vector<vector<vector<int> > > wes;
    int bitreverse(int x, int lg)
    {
        int y = 0;
        for (int i = 0; i < lg; i++)
        {
            y = 2 * y + (((1 << i) & x) > 0);
        }
        return y;
    }
    vector<int> dft(vector<int> a, int fl, int lg)
    {
        for (int i = 0; i < (int)a.size(); i++)
        {
            int j = bitreverse(i, lg);
            if (i < j)
                swap(a[i], a[j]);
        }
        for (int len = 2, io = 1; len <= (int)a.size(); len <<= 1, io++)
        {
            for (int i = 0; i < (int)a.size(); i += len)
            {
                for (int j = 0; j < len / 2; j++)
                {
                    int v = a[i + j], u = 1ll * a[i + j + len / 2] * wes[fl == 1 ? 1 : 0][io][j] % MOD;
                    a[i + j] = v + u >= MOD ? v + u - MOD : v + u;
                    a[i + j + len / 2] = v - u < 0 ? v - u + MOD : v - u;
                }
            }
        }
        return a;
    }

    void simulate_dft(int lg, int fl)
    {
        for (int len = 2, io = 1; len <= (1 << lg); len <<= 1, io++)
        {
            ll wlen = fl == 1 ? G : G_REV;
            wlen = binpow(wlen, (MOD - 1) / len);
            ll w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                wes[fl == 1 ? 1 : 0][io][j] = w;
                w = w * wlen % MOD;
            }
        }
    }

    vector<int> fft(vector<int> &a, vector<int> &b)
    {
        if (max(a.size(), b.size()) <= 1000)
        {
            vector<int> c(a.size() + b.size() - 1);
            for (int i = 0; i < (int)a.size(); i++)
            {
                for (int j = 0; j < (int)b.size(); j++)
                {
                    c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % MOD;
                }
            }
            return c;
        }
        ll sz = a.size() + b.size() - 1;
        ll dg = 1, z = 0;
        while (dg < sz)
            dg *= 2, z++;
        vector<int> a0(dg), b0(dg);
        for (int i = 0; i < (int)a.size(); i++)
            a0[i] = a[i];
        for (int i = 0; i < (int)b.size(); i++)
            b0[i] = b[i];
        a0 = dft(a0, 1, z);
        b0 = dft(b0, 1, z);
        for (int i = 0; i < (int)a0.size(); i++)
            a0[i] = 1ll * a0[i] * b0[i] % MOD;
        a0 = dft(a0, -1, z);
        int x = binpow(dg, MOD - 2) % MOD;
        for (int i = 0; i < (int)a0.size(); i++)
            a0[i] = 1ll * a0[i] * x % MOD;
        while ((int)a0.size() != sz)
            a0.pop_back();
        return a0;
    }

    fft_runner(int lg)
    {
        wes = vector<vector<vector<int> > >(2, vector<vector<int> >(lg + 1, vector<int>(1 << (lg - 1))));
        simulate_dft(lg, 1);
        simulate_dft(lg, -1);
    }
};

struct Matrix{
    

    

    

    

    

    int n, m;
    vector<vector<long long> > a;
    Matrix(int _n, int _m)
    {
        n = _n, m = _m;
        a = vector<vector<long long> > (n, vector<long long>(m));
    }
};

Matrix operator * (Matrix A, Matrix B)
{
    assert(A.m == B.n);
    Matrix C(A.n, B.m);
    for (int k = 0; k < A.m; k++)
    {
        for (int i = 0; i < A.n; i++)
        {
            for (int j = 0; j < B.m; j++)
            {
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix binpow(Matrix A, long long d)
{
    if (d == 0)
    {
        Matrix B(A.n, A.m);
        for (int i = 0; i < A.n; i++)
            B.a[i][i] = 1;
        return B;
    }
    Matrix B = binpow(A, d / 2);
    B = B * B;
    if (d % 2) B = B * A;
    return B;
}








void dfs(int v, int col, vector<int> &vis, vvi &g)
{
    vis[v] = col;
    for (auto u : g[v]) if (vis[u] == 0)
    {
        dfs(u, col, vis, g);
    }
}

void dfs2(int v, int pa, vi &ch, vvi &G, vi &p, vi &q, int &cur)
{
    if (G[v].size() == 1 && v != pa)
        return;
    for (auto u : G[v]) if (u != pa)
    {
        dfs2(u, v, ch, G, p, q, cur);
    }
    vector<int> f;
    for (auto u : G[v]) if (u != pa && ch[u] == 0)
    {
        f.push_back(u);
    }
    f.push_back(v);
    if (f.size() == 1) return;
    for (auto e : f) ch[e] = 1;
    for (int i = 0; i < f.size(); i++)
    {
        q[f[i]] = cur++;
    }
    for (int i = 0; i < f.size(); i++)
    {
        p[f[i]] = q[f[(i + 1) % f.size()]];
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    vector<vector<int> > g(n);
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        g[l[i]].push_back(r[i]);
        g[r[i]].push_back(l[i]);
    }
    vector<int> vis(n);
    int col = 1;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, col, vis, g);
            col++;
        }
    }
    if (col > 2)
    {
        vector<int> p(n), q(n);
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 1)
                p[i] = cur++;
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] != 1)
                p[i] = cur++;
        }
        cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] != 1)
                q[i] = cur++;
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 1)
                q[i] = cur++;
        }
        for (int i = 0; i < n; i++) cout << p[i] + 1 << " "; cout << "\n";
        for (int i = 0; i < n; i++) cout << q[i] + 1 << " "; cout << "\n";

        for (int i = 0; i < m; i++)
        {
            int x = p[l[i]] - p[r[i]];
            int y = q[l[i]] - q[r[i]];
            assert(1ll * x * y > 0);
        }
        for (int i = 0; i < n; i++)
        {
            assert(p[i] != q[i]);
        }

        return;
    }
    else
    {
        


        
        int cur = 0;
        vector<int> p(n), q(n);
        for (int i = 0; i < n; i++)
        {
            if (g[i].size() == n - 1)
            {
                p[i] = q[i] = cur++;
            }
        }
        dsu D(n);
        vvi G(n);
        set<pii> S;
        for (int i = 0; i < n; i++)
        {
            if (g[i].size() != n - 1)
            {
                int exp = 0;
                sort(all(g[i]));
                for (int j = 0; j < g[i].size(); j++)
                {
                    while (exp == i) exp++;
                    if (g[i][j] != exp)
                    {
                        break;
                    }
                    exp++;
                    while (exp == i) exp++;
                }
                if (D.Root(exp) != D.Root(i))
                {
                    D.Merge(exp, i);
                    G[exp].push_back(i);
                    G[i].push_back(exp);
                    

                }
            }
        }
        vector<int> isleaf(n);
        forn(i, n) if (G[i].size() == 1) isleaf[i] = 1;
        vector<int> ch(n);
        for (int i = 0; i < n; i++)
        {
            int fl = 0;
            for (auto u : G[i]) if (isleaf[u]) fl = 1;
            if (g[i].size() != n - 1 && ch[i] == 0 && fl)
            {
                

                dfs2(i, i, ch, G, p, q, cur);
            }
        }

        for (int i = 0; i < n; i++) cout << p[i] + 1 << " "; cout << "\n";
        for (int i = 0; i < n; i++) cout << q[i] + 1 << " "; cout << "\n";






















        return;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}


