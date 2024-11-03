
using namespace std;
using ll = long long;
using grid = vector<vector<char>>;




constexpr ll MOD = 998244353;

constexpr ll INF = 1050000000;
constexpr ll LONGINF = 1050000000000000000;
struct all_init {
    all_init() {
        cout.tie(nullptr);
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(11);
    };
} ALL_INIT;
struct edge {
 
    int from, to;
    ll cost;
    ll capa;
 
    edge(int s, int d) : from(s), to(d) {
        cost = 0;
        capa = 0;
    }
    edge(int s, int d, ll w) : from(s), to(d), cost(w) { capa = 0; }
    edge(int s, int d, ll x, ll y) : from(s), to(d), cost(x), capa(y) {}
 
    bool operator<(const edge& x) const { return cost < x.cost; }
};
using graph = vector<vector<edge>>;
 

  for (int loop = 0; loop < n; loop++) { \
    cin >> vector_array_etc[loop];       \
  }

  for (int LOOP = 0; LOOP < n; LOOP++) {                            \
    cout << vector_array_etc[LOOP] << (LOOP == n - 1 ? '\n' : ' '); \
  }







 
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& Vec) {
    for (T& x : Vec) {
        is >> x;
    }
    return is;
}
template <typename V, typename H>
void resize(vector<V>& vec, const H head) {
    vec.resize(head);
}
template <typename V, typename H, typename... T>
void resize(vector<V>& vec, const H& head, const T... tail) {
    vec.resize(head);
    for (auto& v : vec) {
        resize(v, tail...);
    }
}
template <ll mod>
struct ModInt {
    long long val;
    constexpr ModInt(long long v = 0) noexcept : val(v% mod) {
        if (val < 0) val += mod;
    }
    constexpr int getmod() { return mod; }
    constexpr ModInt operator-() const noexcept { return val ? mod - val : 0; }
    constexpr ModInt operator+(const ModInt& r) const noexcept {
        return ModInt(*this) += r;
    }
    constexpr ModInt operator-(const ModInt& r) const noexcept {
        return ModInt(*this) -= r;
    }
    constexpr ModInt operator*(const ModInt& r) const noexcept {
        return ModInt(*this) *= r;
    }
    constexpr ModInt operator/(const ModInt& r) const noexcept {
        return ModInt(*this) /= r;
    }
    constexpr ModInt& operator+=(const ModInt& r) noexcept {
        val += r.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& r) noexcept {
        val -= r.val;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& r) noexcept {
        val = val * r.val % mod;
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& r) noexcept {
        long long a = r.val, b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % mod;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr bool operator==(const ModInt& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!=(const ModInt& r) const noexcept {
        return this->val != r.val;
    }
    friend ostream& operator<<(ostream& os, const ModInt<mod>& x) noexcept {
        return os << x.val;
    }
    friend istream& operator>>(istream& is, ModInt<mod>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr ModInt<mod> modpow(const ModInt<mod>& a,
        long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
template <class T>
struct id7 {
    vector<T> fact_, inv_, finv_;
    constexpr id7() {}
    constexpr id7(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        ll MOD = 1000000007;
        for (ll i = 2; i < n; i++) {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[MOD % i] * (MOD / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr T com(ll n, ll k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};
 
int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  

int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
 
ll PowMod(ll n, ll k, ll mod) {
    ll r = 1;
 
    for (; k > 0; k >>= 1) {
        if (k & 1) {
            r = (r * n) % mod;
        }
        n = (n * n) % mod;
    }
    return r;
}
ll Gcd(ll a, ll b) {
    return b != 0 ? Gcd(b, a % b) : a;
}
ll Lcm(ll a, ll b) {
    return a / Gcd(a, b) * b;
}
vector<string> Split(string s, string t) {
    vector<string> v;
    int p = s.find(t);
    while (p != s.npos) {
        v.emplace_back(s.substr(0, p));
        s = s.substr(p + (int)t.size());
        p = s.find(t);
    }
    v.emplace_back(s);
    return v;
}
vector<int> Lis(const vector<int>& a) {
    


  distance(as.begin(), upper_bound(as.begin(), as.end(), x))
    const int n = a.size();
    vector<int> A(n, INF);
    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        id[i] = Index_of(A, a[i]);
        A[id[i]] = a[i];
    }
    int m = *max_element(id.begin(), id.end());
    vector<int> b(m + 1);
    for (int i = n - 1; i >= 0; --i)
        if (id[i] == m) b[m--] = a[i];
    return b;
}
string ReplaceString(string s, string target, string id11) {
    string::size_type Pos(s.find(target));
 
    while (Pos != string::npos) {
        s.replace(Pos, target.length(), id11);
        Pos = s.find(target, Pos + id11.length());
    }
 
    return s;
}
string id4(string a, string b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
 
    int n = a.size(), m = b.size();
 
    vector<string> dp(m + 1);
 
    for (int i = 0; i < n; i++) {
        vector<string> to(m + 1);
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                to[j + 1] = dp[j] + a[i];
            }
            else {
                if (to[j].size() > dp[j + 1].size()) {
                    to[j + 1] = to[j];
                }
                else if (to[j].size() < dp[j + 1].size()) {
                    to[j + 1] = dp[j + 1];
                }
                else if (to[j] < dp[j + 1]) {
                    to[j + 1] = to[j];
                }
                else {
                    to[j + 1] = dp[j + 1];
                }
            }
        }
        dp.swap(to);
    }
    return dp[m];
}
string Lcs(const string& s, const string& t) {
    int dp[3001][3001];
    int n = s.size();
    int m = t.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";
    int i = s.size(), j = t.size();
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> id16(const vector<int>& a, const vector<int>& b) {

  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
    struct node {
        int value;
        node* next;
        node(int value, node* next) : value(value), next(next) {}
    };
    const int n = a.size(), m = b.size();
    map<int, vector<int>> M;
    for (int j = m - 1; j >= 0; --j) M[b[j]].push_back(j);
    vector<int> xs(n + 1, INF);
    xs[0] = -INF;
    vector<node*> link(n + 1);
    for (int i = 0; i < n; ++i) {
        if (M.count(a[i])) {
            vector<int> ys = M[a[i]];
            for (int j = 0; j < (int)ys.size(); ++j) {
                int k = index_of(xs, ys[j]);
                xs[k] = ys[j];
                link[k] = new node(b[ys[j]], link[k - 1]);
            }
        }
    }
    vector<int> c;
    int l = index_of(xs, INF - 1) - 1;
    for (node* p = link[l]; p; p = p->next) c.push_back(p->value);
    reverse(c.begin(), c.end());
    return c;
}
bool IsPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (!(n % i)) return false;
    return true;
}
vector<ll> id17(int n) {
    vector<ll> res;
    vector<bool> Prime(n + 1, true);
    Prime[0] = Prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (Prime[i]) {
            for (int j = 2; i * j <= n; j++) {
                Prime[i * j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (Prime[i]) {
            res.emplace_back(i);
        }
    }
    return res;
}
ll id2(vector<ll> a,int left,int right) {
    

    int size=a.size(); 
    ll id10 = -LONGINF, id3 = 0; 
  
    for (int i = left; i < right; i++) { 
        id3 = id3 + a[i]; 
        if (id10 < id3) {
            id10 = id3; 
        }
  
        if (id3 < 0) {
            id3 = 0; 
        }
    } 
    return id10; 
} 
ll MergeCount(vector<int>& a) {
    ll count = 0;
    int n = a.size();
    if (n > 1) {
        vector<int> b(a.begin(), a.begin() + n / 2);
        vector<int> c(a.begin() + n / 2, a.end());
        count += MergeCount(b);
        count += MergeCount(c);
        for (int i = 0, j = 0, k = 0; i < n; ++i)
            if (k == (int)c.size())
                a[i] = b[j++];
            else if (j == (int)b.size())
                a[i] = c[k++];
            else if (b[j] <= c[k])
                a[i] = b[j++];
            else {
                a[i] = c[k++];
                count += n / 2 - j;
            }
    }
    return count;
}
bool id23(vector<vector<ll>>& c) {
    int V = c.size();
    for (int i = 0; i < V; i++) {
        c[i][i] = 0;
    }
 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                if (c[j][k] > c[j][i] + c[i][k]) {
                    if(c[j][i] != INF && c[i][k] != INF){
                        c[j][k] = c[j][i] + c[i][k];
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < V; i++) {
        if (c[i][i] < 0) {
            return false;
        }
    }
 
    return true;
}
vector<ll> Dijkstra(int i, vector<vector<edge>> graph) {
    int n = graph.size();
    vector<ll> d(n, LONGINF);
    d[i] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        q;
    q.push(make_pair(0, i));
    while (!q.empty()) {
        pair<ll, int> p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }
        for (auto x : graph[v]) {
            if (d[x.to] > d[v] + x.cost) {
                d[x.to] = d[v] + x.cost;
                q.push(make_pair(d[x.to], x.to));
            }
        }
    }
    return d;
}
bool id21(int start, int V, int E, vector<edge> Edge, vector<ll>& d) {
    resize(d, V);
    fill(d.begin(), d.end(), LONGINF);
    d[start] = 0;
    vector<bool> t(V, false);
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            edge e = Edge[j];
            if (d[e.from] == LONGINF) {
                continue;
            }
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            edge e = Edge[j];
            if (d[e.from] == LONGINF) {
                continue;
            }
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                t[e.to] = true;
                
            }
            if (t[e.from]) {
                t[e.to] = true;
            }
        }
    }
 
    if (t[V - 1]) {
        return false;
    }
 
    return true;
}
bool id9(const vector<vector<edge>>& g, vector<int>& ans) {
    int n = g.size(), k = 0;
    vector<int> ord(n), in(n);
    for (auto& es : g) {
        for (auto& e : es) {
            in[e.to]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ord[k++] = v;
        for (auto& e : g[v]) {
            if (--in[e.to] == 0) q.push(e.to);
        }
    }
    ans = ord;
    if (*max_element(in.begin(), in.end()) == 0) {
        return true;
    }
    return false;
}
vector<int> id15(const vector<vector<edge>>& g) {
    int n = g.size(), idx;
    vector<int> low(n), ord(n), art;
    function<void(int)> DFS = [&](int v) {
        low[v] = ord[v] = ++idx;
        for (auto& e : g[v]) {
            int w = e.to;
            if (ord[w] == 0) {
                DFS(w);
                low[v] = min(low[v], low[w]);
                if ((ord[v] == 1 && ord[w] != 2) || (ord[v] != 1 && low[w] >= ord[v])) {
                    art.push_back(v);
                }
            }
            else {
                low[v] = min(low[v], ord[w]);
            }
        }
    };
    for (int u = 0; u < n; u++) {
        if (ord[u] == 0) {
            idx = 0;
            DFS(u);
        }
    }
 
    sort(art.begin(), art.end());
    art.erase(unique(art.begin(), art.end()),
        art.end());
 
    return art;
}
vector<vector<edge>> id13(const vector<vector<edge>>& g, int r) {
    int n = g.size();
    vector<vector<edge>> G(n);
    vector<int> ord(n, -1);
 
    queue<int> q;
 
    q.push(r);
    int k = 0;
 
    while (q.size()) {
        int u = q.front();
        q.pop();
 
        for (auto& e : g[u]) {
            int v = e.to;
            if (ord[v] == -1) {
                ord[v] = k;
                k++;
                q.push(v);
                G[u].emplace_back(e);
            }
        }
    }
 
    return G;
}
edge TreeDiameter(const vector<vector<edge>>& g) {
 
    int start = 0;
 
    static const auto bfs = [](const vector<vector<edge>>& g, int s,
        queue<int>& q, vector<ll>& dist) {
            while (!q.empty()) {
                q.pop();
            }
            q.push(s);
            int n = g.size();
            dist.assign(n, LONGINF);
            dist[s] = 0;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto& e : g[u]) {
                    int v = e.to;
                    if (dist[v] == LONGINF) {
                        dist[v] = dist[u] + e.cost;
                        q.push(v);
                    }
                }
            }
            return dist;
    };
    vector<ll> dist;
    queue<int> q;
    bfs(g, start, q, dist);
    int n = g.size(), u = -1, v = -1;
    for (int i = 0; i < n; i++)
        if (dist[i] != LONGINF && (u == -1 || dist[i] > dist[u])) u = i;
    bfs(g, u, q, dist);
    for (int i = 0; i < n; i++)
        if (dist[i] != LONGINF && (v == -1 || dist[i] > dist[v])) v = i;
    ll d = dist[v];
    if (u > v) swap(u, v);
    return edge(u, v, d);
}
void add_edge(vector<vector<edge>>& g, int a, int b, ll cost, ll cap) {
    g[a].emplace_back(a, b, cost, cap);
    g[b].emplace_back(b, a, cost, cap);
}
pair<vector<int>, vector<edge>> bridge(const vector<vector<edge>>& g) {
    const int n = g.size();
    int idx = 0, s = 0, t = 0, k = 0;
    vector<int> ord(n, -1), onS(n), stk(n), roots(n), cmp(n);
    vector<edge> brdg;
    function<void(int, int)> dfs = [&](int v, int u) {
        ord[v] = idx++;
        stk[s++] = v;
        onS[v] = true;
        roots[t++] = v;
        for (auto& e : g[v]) {
            int w = e.to;
            if (ord[w] == -1) {
                dfs(w, v);
            }
            else if (u != w && onS[w]) {
                while (ord[roots[t - 1]] > ord[w]) {
                    --t;
                }
            }
        }
        if (v == roots[t - 1]) {
            brdg.emplace_back(u, v, 0);
            while (1) {
                int w = stk[--s];
                onS[w] = false;
                cmp[w] = k;
                if (v == w) break;
            }
            --t;
            ++k;
        }
    };
    for (int u = 0; u < n; u++) {
        if (ord[u] == -1) {
            dfs(u, n);
            brdg.pop_back();
        }
    }
    return make_pair(cmp, brdg);
}
 
class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> height;
    std::vector<int> m_size;
    int forest_num;
 
public:
    UnionFind(int size_) : parent(size_), height(size_, 0), m_size(size_, 1) {
        forest_num = size_;
        for (int i = 0; i < size_; ++i) parent[i] = i;
    }
    void init(int size_) {
        parent.resize(size_);
        height.resize(size_, 0);
        m_size.resize(size_, 1);
        forest_num = size_;
        for (int i = 0; i < size_; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        int t = size(x) + size(y);
        m_size[x] = m_size[y] = t;
        if (height[x] < height[y])
            parent[x] = y;
        else
            parent[y] = x;
        if (height[x] == height[y]) ++height[x];
        forest_num--;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) {
        if (parent[x] == x) return m_size[x];
        return size(parent[x] = find(parent[x]));
    }
    int forest() { return forest_num; }

};
class Dinic {
private:
    int n, s, t;
    vector<int> level, prog, que;
    vector<vector<ll>> cap, flow;
    vector<vector<int>> g;
    ll inf;
 
public:
    Dinic(const vector<vector<edge>>& graph)
        : n(graph.size()),
        cap(n, vector<ll>(n)),
        flow(n, vector<ll>(n)),
        g(n, vector<int>()),
        inf(LONGINF) {
        for (int i = 0; i < n; i++) {
            for (auto& e : graph[i]) {
                int u = e.from, v = e.to;
                ll c = e.capa;
                cap[u][v] += c;
                cap[v][u] += c;
                flow[v][u] += c;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }
    inline ll residue(int u, int v) { return cap[u][v] - flow[u][v]; }
    ll solve(int s_, int t_) {
        this->t = t_, this->s = s_;
        que.resize(n + 1);
        ll res = 0;
        while (levelize()) {
            prog.assign(n, 0);
            res += augment(s, inf);
        }
        return res;
    }
    bool levelize() {
        int l = 0, r = 0;
        level.assign(n, -1);
        level[s] = 0;
        que[r++] = s;
        while (l != r) {
            int v = que[l++];
            if (v == t) break;
            for (const int& d : g[v])
                if (level[d] == -1 && residue(v, d) != 0) {
                    level[d] = level[v] + 1;
                    que[r++] = d;
                }
        }
        return level[t] != -1;
    }
    ll augment(int v, ll lim) {
        ll res = 0;
        if (v == t) return lim;
        for (int& i = prog[v]; i < (int)g[v].size(); i++) {
            const int& d = g[v][i];
            if (residue(v, d) == 0 || level[v] >= level[d]) continue;
            const ll aug = augment(d, min(lim, residue(v, d)));
            flow[v][d] += aug;
            flow[d][v] -= aug;
            res += aug;
            lim -= aug;
            if (lim == 0) break;
        }
        return res;
    }
};
class id19 {
private:
    using Flow = ll;
    using Cost = ll;
    struct Edge {
        int d;
        Flow c, f;
        Cost w;
        int r, is_r;
        Edge(int d_, Flow c_, Flow f_, Cost w_, int r_, bool id20)
            : d(d_), c(c_), f(f_), w(w_), r(r_), is_r(id20) {}
    };
    int n;
    vector<vector<Edge>> g;
 
public:
    id19(int n_) : n(n_), g(vector<vector<Edge>>(n_)) {}
 
    void add_edge(int src, int dst, Cost cost,Flow cap) {
        int rsrc = g[dst].size();
        int rdst = g[src].size();
        g[src].emplace_back(dst, cap, 0, cost, rsrc, false);
        g[dst].emplace_back(src, cap, cap, -cost, rdst, true);
    }
 
    Cost solve(int s, int t, Flow f) {
        Cost res = 0;
 
        vector<Cost> h(n + 10), dist(n);
        vector<int> prevv(n + 10), preve(n + 10);
 
        using pcv = pair<Cost, int>;
        priority_queue<pcv, vector<pcv>, greater<pcv>> q;
        fill(h.begin(), h.end(), 0);
        while (f > 0) {
            fill(dist.begin(), dist.end(), LONGINF);
            dist[s] = 0;
            q.emplace(0, s);
            while (q.size()) {
                Cost cd;
                int v;
                tie(cd, v) = q.top();
                q.pop();
                if (dist[v] < cd) continue;
                for (int i = 0; i < (int)(g[v].size()); ++i) {
                    Edge& e = g[v][i];
                    if (residue(e) == 0) continue;
                    if (dist[e.d] + h[e.d] > cd + h[v] + e.w) {
                        dist[e.d] = dist[v] + e.w + h[v] - h[e.d];
                        prevv[e.d] = v;
                        preve[e.d] = i;
                        q.emplace(dist[e.d], e.d);
                    }
                }
            }
 
            if (dist[t] == LONGINF) return -1;
 
            for (int i = 0; i < n; ++i) h[i] += dist[i];
            Flow d = f;
            for (int v = t; v != s; v = prevv[v]) {
                chmin(d, residue(g[prevv[v]][preve[v]]));
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge& e = g[prevv[v]][preve[v]];
                e.f += d;
                g[v][e.r].f -= d;
            }
        }
        return res;
    }
 
    Flow residue(const Edge& e) { return e.c - e.f; }
 
    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)(g[i].size()); ++j) {
                Edge& e = g[i][j];
                if (e.is_r) continue;
                cout << i << "->" << e.d << "(flow:" << e.f << ")" << endl;
            }
        }
    }
};
class id0 {
private:
    int V;
    vector<int> match;
    vector<bool> used;
    vector<vector<int>> g;
    vector<pair<int, int>> match_pair;
 
    bool dfs(int v) {
        used[v] = true;
        for (int i = 0; i < (int)g[v].size(); i++) {
            int u = g[v][i];
            int w = match[u];
            if (w < 0 || !used[w] && dfs(w)) {
                match[v] = u;
                match[u] = v;
                match_pair.emplace_back(make_pair(u, v));
                return true;
            }
        }
        return false;
    }
 
public:
    id0(int n) {
        V = n;
        resize(match, n);
        resize(used, n);
        resize(g, n);
    }
 
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
 
    int MatchingSolve() {
        int res = 0;
        fill(match.begin(), match.end(), -1);
 
        for (int v = 0; v < V; v++) {
            if (match[v] < 0) {
                fill(used.begin(), used.end(), false);
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }
 
    vector<pair<int, int>> get_pair() {
        for (auto x : match_pair) {
            cout << x.first << "  " << x.second << endl;
        }
        return match_pair;
    }
};
class Lca {
private:
    int n;
    int id6;
    vector<vector<int>> parent;
    vector<int> depth;
    
    void dfs(const vector<vector<edge>>& g, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto& e : g[v]) {
            if (e.to != p) {
                dfs(g, e.to, v, d + 1);
            }
        }
    }
 
public:
    Lca(const vector<vector<edge>>& g, int root) {
        n = g.size();
        id6 = (int)log2(n) + 1;
        resize(parent, id6, n);
        resize(depth, n);
 
        dfs(g, root, -1, 0);
 
        for (int k = 0; k + 1 < id6; k++) {
            for (int v = 0; v < (int)g.size(); v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                }
                else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }
 
    int get_lca(int u, int v) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
 
        for (int k = 0; k < id6; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) {
            return u;
        }
 
        for (int k = id6 - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
 
    int get_depth(int v) { return depth[v]; }
};
class DAG {
private:
    int n;
    vector<vector<edge>> g;
    vector<int> visited;
    vector<int> dp;
    vector<int> topological;
 
    int dfs(int s) {
        if ((int)g[s].size() == 0) {
            return 1;
        }
        if (dp[s] > 0) {
            return dp[s];
        }
 
        int mx = 1;
        for (auto j : g[s]) {
            if (visited[j.to] == 0) {
                visited[j.to] = 1;
                int l = 0;
                l = dfs(j.to);
                chmax(mx, l);
            }
            else {
                chmax(mx, dp[j.to]);
            }
        }
        return dp[s] = mx + 1;
    }
 
public:
    DAG(const vector<vector<edge>>& f) {
        g = f;
        n = f.size();
        resize(visited, n + 1);
        fill(visited.begin(), visited.end(), 0);
        resize(dp, n + 1);
        fill(dp.begin(), dp.end(), -1);
        resize(topological, n);
    }
    DAG(int x) {
        n = x;
        resize(g, n);
        resize(visited, n + 1);
        fill(visited.begin(), visited.end(), 0);
        resize(dp, n + 1);
        fill(dp.begin(), dp.end(), -1);
    }
 
    void add_edge(int a, int b) { g[a].emplace_back(a, b); }
    void add_edge(int a, int b, ll c) { g[a].emplace_back(a, b, c); }
    void add_edge(int a, int b, ll c, ll d) { g[a].emplace_back(a, b, c, d); }
 
    int longest_path() {
        int mx = -1;
        for (int i = 0; i < n; i++) {
            int h = 0;
            if (visited[i] == 0) {
                h = dfs(i);
                chmax(mx, h);
            }
        }
        return mx - 1;
    }
 
    bool id9() {
        int k = 0;
        vector<int> ord(n), in(n);
        for (auto& es : g) {
            for (auto& e : es) {
                in[e.to]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ord[k++] = v;
            for (auto& e : g[v]) {
                if (--in[e.to] == 0) {
                    q.push(e.to);
                }
            }
        }
        topological = ord;
        if (*max_element(in.begin(), in.end()) == 0) {
            return true;
        }
        return false;
    }

    vector<int> getTopologicalArray(){
        return topological;
    }
};
class id18 {
private:
    int n;
    ll inf = (1LL << 31) - 1;  

    vector<ll> dat, lazy;
 
    void eval(int len, int k) {
        if (lazy[k] == inf) return;
        if (k * 2 + 1 < n * 2 - 1) {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }
        dat[k] = lazy[k];
        lazy[k] = inf;
    }
 
public:
    id18() {}
    id18(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat.assign(n * 2, inf);
        lazy.assign(n * 2, inf);
    }
 
    

    ll update(int a, int b, ll x, int k, int l, int r) {
        eval(r - l, k);
        if (b <= l || r <= a) return dat[k];
        if (a <= l && r <= b) {
            lazy[k] = x;
            return lazy[k];
        }
        return dat[k] = min(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
            update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }
    ll update(int a, int b, ll x) { return update(a, b, x, 0, 0, n); }
 
    

    ll query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) return dat[k];
        ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
    ll query(int a, int b) { return query(a, b, 0, 0, n); }
};
class id1 {
private:
    struct Node {
        Node* left, * right;
        ll v;
 
        Node() : left(nullptr), right(nullptr), v(0) {}
    };
    Node* root;
    ll n, n0;
    ll query(ll a, ll b, Node* n, ll l, ll r) {
        if (a <= l && r <= b) {
            return n->v;
        }
        if (r <= a || b <= l) {
            return 0;
        }
 
        ll lv = n->left ? query(a, b, n->left, l, (l + r) >> 1) : 0;
        ll rv = n->right ? query(a, b, n->right, (l + r) >> 1, r) : 0;
        return (lv + rv) % MOD;
    }
 
public:
    id1(ll n) : n(n) {
        n0 = 1;
        while (n0 < n) n0 <<= 1;
        root = new Node();
    }
    ~id1() {
        delete root;
        root = nullptr;
    }
 
    void update(ll k, ll x) {
        Node* n = root;
        ll l = 0, r = n0;
        n->v = (n->v + x) % MOD;
        while (r - l > 1) {
            ll m = (l + r) >> 1;
            if (k < m) {
                if (!n->left) n->left = new Node();
                n = n->left;
 
                r = m;
            }
            else {
                if (!n->right) n->right = new Node();
                n = n->right;
 
                l = m;
            }
            n->v = (n->v + x) % MOD;
        }
    }
 
    ll query(ll a, ll b) { return query(a, b, root, 0, n0); }
 
    ll lquery(ll b) { return query(0, b, root, 0, n0); }
 
    ll rquery(ll a) { return query(a, n0, root, 0, n0); }
};
class id8 {
public:
    struct Node {
        int location;
        int p, l, r;
        Node() {}
    };
    struct Point {
        int id, x, y;
        Point() {}
        Point(int i, int a, int b) {
            id = i;
            x = a;
            y = b;
        }
        bool operator<(const Point& p) const { return id < p.id; }
        void print() { cout << id << endl; }
    };
    static const ll NIL = -1;
    static bool lessX(const Point& p1, const Point& p2) { return p1.x < p2.x; }
    static bool lessY(const Point& p1, const Point& p2) { return p1.y < p2.y; }
 
    int N;
    vector<Point> P;
    vector<Node> T;
    int np;
 
    id8() {}
    id8(int N) { init(N); }
 
    void init(int n) {
        N = n;
        P.clear();
        T.clear();
        resize(P, N);
        resize(T, N);
        np = 0;
    }
 
    int makeKDTree(int l, int r, int depth) {
        if (l >= r) {
            return NIL;
        }
        int mid = (l + r) / 2;
        int t = np++;
        if (depth & 1) {
            sort(P.begin() + l, P.begin() + r, lessY);
        }
        else {
            sort(P.begin() + l, P.begin() + r, lessX);
        }
        T[t].location = mid;
        T[t].l = makeKDTree(l, mid, depth + 1);
        T[t].r = makeKDTree(mid + 1, r, depth + 1);
        return t;
    }
    void find(int v, int sx, int tx, int sy, int ty, int depth,
        vector<Point>& ans) {
        int x = P[T[v].location].x;
        int y = P[T[v].location].y;
        if (sx <= x && x <= tx && sy <= y && y <= ty) {
            ans.push_back(P[T[v].location]);
        }
        if (depth % 2 == 0) {
            if (T[v].l != NIL) {
                if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
            }
            if (T[v].r != NIL) {
                if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
            }
        }
        else {
            if (T[v].l != NIL) {
                if (sy <= y) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
            }
            if (T[v].r != NIL) {
                if (y <= ty) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
            }
        }
    }
    void add_point(int i, int x, int y) {
        P[i].id = i;
        P[i].x = x;
        P[i].y = y;
        T[i].l = T[i].r = T[i].p = NIL;
    }
};
class id5 {
private:
    int n;
    vector<ll> data;
 
public:
    id5() {}
    id5(int N) {
        n = N;
        resize(data, n + 1);
        fill(data.begin(), data.end(), 0);
    }
 
    void add(int i, ll x) {
        while (i) {
            data[i] += x;
            i -= (i & -i);
        }
    }
    void add(int i, int j, ll x) {
        add(j, x);
        add(i - 1, -x);
    }
 
    ll get(int i) {
        ll res = 0;
        while (i <= n) {
            res += data[i];
            i += (i & -i);
        }
        return res;
    }
};
class id24 {
private:
    vector<ll> bit0, bit1;
    int n;
 
    ll sum(const vector<ll>& b, int i) {
        ll s = 0;
        while (i > 0) {
            s += b[i];
            i -= (i & -i);
        }
        return s;
    }
 
    void add(vector<ll>& b, int i, ll v) {
        while (i <= n) {
            b[i] += v;
            i += (i & -i);
        }
    }
 
public:
    id24() {}
    id24(int N) {
        n = N;
        resize(bit0, n + 1);
        resize(bit1, n + 1);
        fill(bit0.begin(), bit0.end(), 0);
        fill(bit1.begin(), bit1.end(), 0);
    }
 
    void update(int l, int r, ll x) {
        add(bit0, l, -x * (l - 1));
        add(bit1, l, x);
        add(bit0, r + 1, x * r);
        add(bit1, r + 1, -x);
    }
 
    ll query(int l, int r) {
        ll res = 0;
        res += sum(bit0, r) + sum(bit1, r) * r;
        res -= sum(bit0, l - 1) + sum(bit1, l - 1) * (l - 1);
        return res;
    }
};



long double cross(const complex<long double> &a, const complex<long double> &b) { return a.real() * b.imag() - a.imag() * b.real(); }
long double dot(const complex<long double> &a, const complex<long double> &b) { return a.real() * b.real() + a.imag() * b.imag(); }

pair<long double,complex<long double>> id14(vector<complex<long double>> ps){
    const long double pi = 3.1415926535897932384626;
    static const long double eps = 1e-10;
    static const long double inf = 1e12;

    
    

    using circle = pair<complex<long double>, long double>;

    auto c3 = [](const complex<long double> &a, const complex<long double> &b, const complex<long double> &c){
        long double A = norm(b - c);
        long double B = norm(c - a);
        long double C = norm(a - b);
        long double S = abs(cross(b - a, c - a));
        complex<long double> p = (A*(B+C-A)*a + B*(C+A-B)*b + C*(A+B-C)*c) / (4*S*S);
        long double r = abs(p - a);
        return make_pair(r, p);
    };

    auto c2 = [](const complex<long double> &a, const complex<long double> &b){
        complex<long double> c = (a + b) / (long double)2;
        long double r = abs(a - c);
        return make_pair(r, c);
    };

    auto in_circle = [](const complex<long double> &a, const pair<long double, complex<long double>> &c){
        return norm(a - c.pnt) <= c.rad*c.rad + eps;
    };

    int n = ps.size();
    random_shuffle(ps.begin(), ps.end());
    pair<long double, complex<long double>> c = c2(ps[0], ps[1]);
    for(int i = 2; i < n; ++i){
        if(!in_circle(ps[i], c)){
            c = c2(ps[0], ps[i]);
            for(int j = 1; j < i; ++j){
                if(!in_circle(ps[j], c)){
                    c = c2(ps[j], ps[i]);
                    for(int k = 0; k < j; ++k){
                        if(!in_circle(ps[k], c)){
                            c = c3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}

pair<ll, vector<edge>> id22(const vector<vector<edge>> &g, int r,int K) {
  int n = g.size();
  vector<edge> T;
  ll total = 0;

  vector<bool> visited(n);
  priority_queue<edge> Q;
  Q.push( edge(-1, r, 0,0));
  ll ans=0;
  int k=0;
  while (!Q.empty()) {
    edge e = Q.top(); Q.pop();
    if (visited[e.to]) continue;
    T.push_back(e);
    total += e.cost;
    ans=max(ans,-e.cost);
    k++;
    if(k==K){
        break;
    }
    visited[e.to] = true;
    for(auto f:g[e.to]) if (!visited[f.to]) Q.push(f);
  }
  return pair<ll, vector<edge>>(ans, T);
}







bool id12(const vector<vector<edge>> &g, int v, int c,vector<int> &colors) {
    colors[v] = c;
    COUT(colors,colors.size());
    for (auto u: g[v]) {
        if (colors[u.to] == c) {
            return false;
        }
        if (colors[u.to] == 0 && !id12(g, u.to, -c,colors)) {
            return false;
        }
    }
    return true;
}



 
void dfs(const vector<vector<int>> &G, int v,vector<bool> &visited, int d,vector<int> &odd,vector<int> &even) { 
    if(d % 2 == 0)even.push_back(v+1);
    else odd.push_back(v+1);
    visited[v]=true;
 
	for (auto nv : G[v]) {
		if (visited[nv]){continue;}
		dfs(G, nv, visited, d+1,odd,even);
	}
}


int main() {
    int t;cin>>t;

    for(int xx=0;xx<t;xx++){
        int n,m;cin>>n>>m;
        vector<vector<int>> g(n);
        
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            a--,b--;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        vector<int> odd, even;
        vector<bool> visited(n,false);
        dfs(g, 0,visited, 0,odd,even);
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        if(odd.size()<even.size()){
            cout<<odd.size()<<endl;
            COUT(odd,odd.size());
        }
        else{
            cout<<even.size()<<endl;
            COUT(even,even.size());
        }
    }

    
    ;
    return 0;
}