

















using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll MOD = 1000000007;
const ll INF = 1LL << 60;



template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (auto &v : vec)
        is >> v;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
    os << "deq[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
    os << "(" << pa.first << "," << pa.second << ")";
    return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
    os << "{";
    for (auto v : mp)
        os << v.first << "=>" << v.second << ",";
    os << "}";
    return os;
}


template <typename A, size_t N, typename T>

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

bool is_prime(ll x)
{
    if (x == 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


long long modinv(long long a, long long mod)
{
    return modpow(a, mod - 2, mod);
}

const ll MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

struct UnionFind
{
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y); 

        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};

struct BIT
{
    int n;
    vector<int> bit;
    BIT()
    {
        init();
    }
    BIT(int n) : n(n)
    {
        init();
    }
    void init()
    {
        bit.clear();
        bit.resize(n + 1, 0);
    }
    int sum(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    int sum(int x, int y)
    {
        return sum(y) - sum(x - 1);
    }
    void add(int i, int x)
    {
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    int lower_bound(int w)
    {
        if (w <= 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1)
        {
            if (x + k <= n && bit[x + k] < w)
            {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};


struct id0
{
    

    ll n;
    vector<ll> node, lazy;

    

    id0(vector<ll> v)
    {
        int sz = (int)v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    void eval(int k, int l, int r)
    {
        if (lazy[k] != 0)
        {
            node[k] += lazy[k];
            if (r - l > 1)
            {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b)
        {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else
        {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return 0;
        if (a <= l && r <= b)
            return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

ll digit_sum(ll v)
{
    ll ret = 0;
    while (v)
    {
        ret += (v % 10);
        v /= 10;
    }
    return ret;
}

template <typename T>
struct id4
{

    struct edge
    {
        ll from, to;
        T cost;
        ll used;
        edge() {}
        edge(ll from, ll to, T cost) : from(from), to(to), cost(cost), used(0) {}
        bool operator<(const edge &e) const
        {
            return cost < e.cost;
        }
    };

    ll n;
    vector<ll> p, r;
    vector<edge> edges;

    id4() {}
    id4(ll n) : n(n) {}

    void init(ll n)
    {
        r.assign(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    ll find(ll x)
    {
        return (x == p[x] ? x : p[x] = find(p[x]));
    }

    bool same(ll x, ll y)
    {
        return find(x) == find(y);
    }

    void unite(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (r[x] < r[y])
            swap(x, y);
        r[x] += r[y];
        p[y] = x;
    }

    void add_edge(ll u, ll v, T c)
    {
        edges.emplace_back(u, v, c);
    }

    T build()
    {
        sort(edges.begin(), edges.end());
        init(n);
        T res = 0;
        for (auto &e : edges)
        {
            if (!same(e.from, e.to))
            {
                res += e.cost;
                unite(e.from, e.to);
                e.used = 1;
            }
        }
        return res;
    }

    T build(ll k)
    {
        sort(edges.begin(), edges.end());
        init(n);
        T res = 0;
        ll cnt = 0;
        for (auto &e : edges)
        {
            if (!same(e.from, e.to))
            {
                res += e.cost;
                unite(e.from, e.to);
                e.used = 1;
                cnt++;
            }
            if (cnt == k)
            {
                break;
            }
        }
        return res;
    }
};

int LIS(int a[], int n)
{
    vector<int> A(n, 0x3f3f3f3f);
    for (int i = 0; i < n; i++)
        *lower_bound(A.begin(), A.end(), a[i]) = a[i];
    return find(A.begin(), A.end(), 0x3f3f3f3f) - A.begin();
}



ll maze[100][100];
ll id2(ll H, ll W, ll sx, ll sy, ll gx, ll gy)
{

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<ll>> dist(H, vector<ll>(W, -1));
    dist[sy][sx] = 0;

    queue<PL> q;
    q.push({sy, sx});
    while (!q.empty())
    {
        ll x, y;
        tie(y, x) = q.front();
        q.pop();
        if (y == gy && x == gx)
        {
            break;
        }
        for (int t = 0; t < 4; t++)
        {
            ll nx = x + dx[t], ny = y + dy[t];
            if (nx < 0 || ny < 0 || nx >= W || ny >= H || dist[ny][nx] != -1 || maze[ny][nx] == '
            {
                continue;
            }

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return dist[gy][gx];
}

vector<vector<ll>> id3(ll n, vector<vector<ll>> g, ll INF)
{
    


    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][k] == INF || g[k][j] == INF)
                    continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    return g;
}

struct Dijkstra
{

    ll n;
    vector<vector<pair<ll, ll>>> Edges;
    vector<ll> Dist;
    vector<ll> Prev;
    vector<ll> PathNum;

    Dijkstra(ll n) : n(n), Edges(n), Dist(n), Prev(n), PathNum(n)
    {
        Prev.assign(n, -1);
    };

    void add_edge(ll a, ll b, ll c, bool directed = true)
    {
        if (directed)
        {
            Edges[a].emplace_back(make_pair(b, c));
        }
        else
        {
            Edges[a].emplace_back(make_pair(b, c));
            Edges[b].emplace_back(make_pair(a, c));
        }
    }
    

    void build(int start)
    {
        priority_queue<P, vector<P>, greater<P>> queue;
        fill(Dist.begin(), Dist.end(), 1e+18); 

        fill(Prev.begin(), Prev.end(), -1); 

        Dist[start] = 0;
        PathNum[start] = 1;
        queue.push(PL(0, start));

        while (!queue.empty())
        {
            PL p = queue.top();
            queue.pop();
            int v = p.second;
            if (Dist[v] < p.first)
                continue;

            for (int i = 0; i < Edges[v].size(); i++)
            {
                PL e = Edges[v][i];
                if (Dist[e.first] > Dist[v] + e.second)
                {
                    Dist[e.first] = Dist[v] + e.second;
                    queue.push(P(Dist[e.first], e.first));

                    Prev[e.first] = v;

                    PathNum[e.first] = PathNum[v];
                }
                else if (Dist[e.first] == Dist[v] + e.second)
                {
                    PathNum[e.first] += PathNum[v];
                    PathNum[e.first] %= MOD;
                }
            }
        }
    }

    ll dist(ll t)
    {
        return Dist[t];
    }

    vector<ll> get_path(ll t)
    {
        vector<ll> path;
        for (; t != -1; t = Prev[t])
        {
            path.push_back(t);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    ll get_path_num(ll t)
    {
        return PathNum[t];
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

};

struct id1
{
    int H;
    int W;
    vector<vector<ll>> data;

    id1(int H, int W) : H(H), W(W), data(H + 1, vector<ll>(W + 1, 0LL)) {}

    void add(int x, int y, ll z)
    {
        data[x + 1][y + 1] += z;
    }

    void build()
    {
        for (int i = 1; i < data.size(); i++)
        {
            for (int j = 1; j < data[i].size(); j++)
            {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }

    void print()
    {

        for (int i = 0; i <= H; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    ll query(int sx, int sy, int gx, int gy)
    {
        return (data[gy][gx] - data[sy - 1][gx] - data[gy][sx - 1] + data[sy - 1][sx - 1]);
    }
};

struct LCA
{
   int n, h;
   vector<vector<int>> par;
   vector<vector<pair<int, int>>> v;
   vector<ll> depth, dis;
   LCA(int sz) : n(sz), v(n), depth(n), dis(n)
   {
      h = 1;
      while ((1 << h) < n)
         h++;
      par.assign(h, vector<int>(n, -1));
   }

   void add_edge(int x, int y, int z)
   {
      v[x].push_back({y, z});
      v[y].push_back({x, z});
   }

   void dfs(int x, int p, int d, ll di)
   {
      par[0][x] = p;
      depth[x] = d;
      dis[x] = di;
      for (auto to : v[x])
         if (to.first != p)
            dfs(to.first, x, d + 1, di + to.second);
   }

   void build()
   {
      dfs(0, -1, 0, 0);
      for (int i = 0; i < h - 1; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (par[i][j] < 0)
               par[i + 1][j] = -1;
            else
               par[i + 1][j] = par[i][par[i][j]];
         }
      }
   }

   int lca(int u, int v)
   {
      if (depth[u] > depth[v])
         swap(u, v);
      for (int i = 0; i < h; i++)
         if ((depth[v] - depth[u]) >> i & 1)
            v = par[i][v];
      if (u == v)
         return u;
      for (int i = h - 1; i >= 0; i--)
      {
         if (par[i][u] != par[i][v])
         {
            u = par[i][u];
            v = par[i][v];
         }
      }
      return par[0][u];
   }

   ll dist(int u, int v)
   {
      return dis[u] + dis[v] - 2 * dis[lca(u, v)];
   }

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   


   

   

};










ll a[101010];

ll cnk(ll n ,ll k){
    ll ret = 1;
    for(ll i=n-k+1; i <= n; i++){
        ret *= i;
    }
    for(int i=1; i <= k; i++){
        ret /= i;
    }
    return ret;
}
void solve()
{
    ll n , k;
    cin >> n >> k;
    if(k == 1){
        cout << 1 << endl;
        exit(0);
    }
    a[2] = 1;
    for(int i=3; i <= 10; i++){
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }

    ll ans = 1;
    for(int i=0; i < k; i++){
        ans += cnk(n, k - i) * a[k - i];
    }
    
    cout << ans << endl;
}

int main()
{
    cout.precision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
