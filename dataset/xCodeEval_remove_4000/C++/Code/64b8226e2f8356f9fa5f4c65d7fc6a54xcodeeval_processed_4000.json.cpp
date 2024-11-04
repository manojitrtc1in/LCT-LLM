





using namespace __gnu_pbds;
using namespace std;






























































using ll = long long;
using db = double;
using ld = long double;
using ull = unsigned long long;
using str = string;

using vs = vector<string>;
using vb = vector<bool>;

using vi = vector<int>;
using vd = vector<double>;
using vl = vector<long long>;
using vld = vector<long double>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvd = vector<vector<double>>;
using vvld = vector<vector<long double>>;

using pi = pair<int, int>;
using pl = pair<long long, long long>;
using pd = pair<double, double>;
using pld = pair<long double, long double>;

using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;
using vpd = vector<pair<double, double>>;
using vpld = vector<pair<long double, long double>>;

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using pq = std::priority_queue<T>;
tcT > using pqg = std::priority_queue<T, V<T>, greater<T>>;
tcT > using Q = queue<T>;

tcT > bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
tcT > bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
tcT > T cdiv(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
tcT > T fdiv(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }
tcT > void remDup(V<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }

tcTU > bool ckerase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    else
        t.erase(it);
    return true;
}
tcTU > T fstTrue(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

template <class Fun>
class id11 {
    Fun fun_;

public:
    template <class T>
    explicit id11(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) id4(Fun &&fun) { return id11<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int p2(int x) { return 1 << x; }
constexpr int id6(int x) { return p2(x) - 1; }
constexpr int id8(int a) { return a ? (8 * sizeof(a)) - 1 - __builtin_clz(a) : -1; } 

constexpr int id12(int a) { return a > 0 ? 1 << id8(2 * a - 1) : 0; }          




tcT > void re(complex<T> &c);
tcTU > void re(pair<T, U> &p);
tcT > void re(V<T> &v);
tcT, size_t SZ > void re(AR<T, SZ> &a);

tcT > void re(T &x) { cin >> x; }
void re(db &d) {
    str t;
    re(t);
    d = stod(t);
}
void re(ld &d) {
    str t;
    re(t);
    d = stold(t);
}
tcTUU > void re(T &t, U &...u) {
    re(t);
    re(u...);
}
tcT > void re(complex<T> &c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > void re(V<T> &x) { each(a, x) re(a); }
tcT, size_t SZ > void re(AR<T, SZ> &x) { each(a, x) re(a); }
tcT > void rv(int n, V<T> &x) {
    x.rsz(n);
    re(x);
}



str ts(char c) { return str(1, c); }
str ts(const char *s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {

    return b ? "true" : "false";

    return ts((int)b);

}
tcT > str ts(complex<T> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(V<bool> v) {
    str res = "{";
    f0r(i, sz(v))
        res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
str ts(bitset<SZ> b) {
    str res = "";
    f0r(i, SZ)
        res += char('0' + b[i]);
    return res;
}
tcTU > str ts(pair<T, U> p);
tcT > str ts(T v) { 


    bool fst = 1;
    str res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;

    bool fst = 1;
    str res = "";
    for (const auto &x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;


}
tcTU > str ts(pair<T, U> p) {

    return "(" + ts(p.f) + ", " + ts(p.s) + ")";

    return ts(p.f) + " " + ts(p.s);

}



tcT > void pr(T x) { cout << ts(x); }
tcTUU > void pr(const T &t, const U &...u) { 

    pr(t);
    pr(u...);
}

void ps() { pr("\n"); }
tcTUU > void ps(const T &t, const U &...u) { 

    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}



void DBG() { cerr << "]" << endl; }
tcTUU > void DBG(const T &t, const U &...u) {
    cerr << ts(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}




    if (!(id7)) cerr << "Line(" << __LINE__ << ") -> function(" << __FUNCTION__ << ") -> CHK FAILED: (" << 





template <int MOD, int RT>
struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } 

    int v;
    explicit operator int() const { return v; } 

    mint() { v = 0; }
    mint(ll _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
    friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
    friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
    friend void re(mint &a) {
        ll x;
        re(x);
        a = mint(x);
    }
    friend str ts(mint a) { return ts(a.v); }

    mint &operator+=(const mint &m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        v = (ll)v * m.v % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1) ans *= a;
        return ans;
    }
    friend mint inv(const mint &a) {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    mint operator-() const { return mint(-v); }
    mint &operator++() { return *this += 1; }
    mint &operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
};

const int MOD = 1e9 + 007; 

typedef mint<MOD, 5> mi;   

typedef vector<mi> vmi;
typedef pair<mi, mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; 

void genComb(int SZ) {
    scmb.assign(SZ, vmi(SZ));
    scmb[0][0] = 1;
    f1r(i, 1, SZ - 1) f0r(j, i + 1)
        scmb[i][j] = scmb[i - 1][j] + (j ? scmb[i - 1][j - 1] : 0);
}

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id3 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id3);
    }
};

tcTU, typename Hash = splitmix64_hash > using hash_map = gp_hash_table<T, U, Hash>;
tcT, typename Hash = splitmix64_hash > using hash_set = hash_map<T, null_type, Hash>;
tcT > using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

tcT > using id10 = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); 



const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long double eps = 1e-7;
const long double PI = 3.14159265358979323846L;
const long long lINF = 1e18L + 007;
const int iINF = 1e9 + 007;

template <typename T, bool maximum_mode = false>
struct RMQ {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    

    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    

    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, id9;
    vector<int> heavy_root;
    RMQ<int> rmq;
    bool built;

    LCA(int _n = 0) {
        init(_n);
    }

    

    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        postorder.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }

    

    void init(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        

        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        

        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }

    int tour, id0;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }

        tour_end[node] = tour;
        postorder[node] = id0++;
    }

    void build(int root = -1, bool id1 = true) {
        parent.assign(n, -1);

        if (0 <= root && root < n)
            dfs(root, -1);

        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
                dfs(i, -1);

        tour = id0 = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                

                euler.push_back(-1);
            }

        id9 = tour_list;
        reverse(id9.begin(), id9.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> id5;
        id5.reserve(euler.size());

        for (int node : euler)
            id5.push_back(node < 0 ? node : depth[node]);

        if (id1)
            rmq.build(id5);

        built = true;
    }

    pair<int, array<int, 2>> get_diameter() const {
        assert(built);

        

        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> id13 = {-1, {-1, -1}};

        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            id13 = max(id13, {ux_max.first + depth[node], {ux_max.second, node}});
        }

        return id13;
    }

    

    array<int, 2> get_center() const {
        pair<int, array<int, 2>> diam = get_diameter();
        int length = diam.first, a = diam.second[0], b = diam.second[1];
        return {get_kth_node_on_path(a, b, length / 2), get_kth_node_on_path(a, b, (length + 1) / 2)};
    }

    

    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];

        if (a > b)
            swap(a, b);

        return euler[rmq.query_index(a, b + 1)];
    }

    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }

    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    

    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));

        

        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(parent[child] == a);
        assert(is_ancestor(child, b));
        return child;
    }

    int get_kth_ancestor(int a, int k) const {
        while (a >= 0) {
            int root = heavy_root[a];

            if (depth[root] <= depth[a] - k)
                return tour_list[tour_start[a] - k];

            k -= depth[a] - depth[root] + 1;
            a = parent[root];
        }

        return a;
    }

    int get_kth_node_on_path(int a, int b, int k) const {
        int anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];
        assert(0 <= k && k <= first_half + second_half);

        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }

    

    

    int get_common_node(int a, int b, int c) const {
        

        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
        return x ^ y ^ z;
    }

    

    

    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&id2 = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), id2);
        int k = int(nodes.size());

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), id2);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), id2);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};

const int _ = 1e6 + 007;

void solve() {
    int n, k;
    re(n, k);
    vi f(k);
    vvi g(n);
    vb vis(n);
    re(f);
    f0r(i, n - 1) {
        int x, y;
        re(x, y), x--, y--, g[x].pb(y), g[y].pb(x);
    }
    LCA L(g);
    hash_set<int> h;
    L.build(0, 0);
    vi guard(k);
    each(one, f) {
        int d = L.depth[one-1];
        h.ins(L.get_kth_ancestor(one-1, d / 2));
    }
    int cnt = 0;
    bool xit = id4([&](auto dfs, int node) -> bool {
        if (h.find(node) != h.end()) {
            cnt++;
            return false;
        }
        if (L.adj[node].empty()) return true;
        each(c, L.adj[node]) {
            if(dfs(c))return true;
        }
        return false;
    })(0);
    if (xit) ps(-1);
    else
        ps(cnt);
}

int main() {


    auto begin = chrono::high_resolution_clock::now();


    vamos;


    cin.tie(nullptr);


    fix(15);

    int TT = 1;
    cin >> TT;
    f1r(TC, 1, TT)
        solve();


    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;


    return 0;
}