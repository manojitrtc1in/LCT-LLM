


















    vector<type> name(size);                                                                                                                                   \
    IN(name)


    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)







using namespace std;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


    int id1;                                                                                                                                           \
    IN(id1)

    ll id1;                                                                                                                                            \
    IN(id1)

    ull id1;                                                                                                                                           \
    IN(id1)

    string id1;                                                                                                                                        \
    IN(id1)

    char id1;                                                                                                                                          \
    IN(id1)

    double id1;                                                                                                                                        \
    IN(id1)

    ld id1;                                                                                                                                            \
    IN(id1)
int scan() { return getchar(); }
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(vector<T> &);
template <class T, size_t size> void scan(array<T, size> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T, size_t size> void scan(T (&)[size]);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(deque<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T, size_t size> void scan(array<T, size> &a) {
    for(auto &i : a) scan(i);
}
template <class T, class L> void scan(pair<T, L> &p) {
    scan(p.first);
    scan(p.second);
}
template <class T, size_t size> void scan(T (&a)[size]) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
string stin() {
    string s;
    cin >> s;
    return s;
}
template <class T, class S> inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <class T> void UNIQUE(vector<T> &x) {
    sort(all(x));
    x.erase(unique(all(x)), x.end());
}
int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}
void print() { putchar(' '); }
void print(bool a) { cout << a; }
void print(int a) { cout << a; }
void print(long long a) { cout << a; }
void print(char a) { cout << a; }
void print(string &a) { cout << a; }
void print(double a) { cout << a; }
template <class T> void print(const vector<T> &);
template <class T, size_t size> void print(const array<T, size> &);
template <class T, class L> void print(const pair<T, L> &p);
template <class T, size_t size> void print(const T (&)[size]);
template <class T> void print(const vector<T> &a) {
    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
    cout << endl;
}
template <class T> void print(const deque<T> &a) {
    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, size_t size> void print(const array<T, size> &a) {
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, class L> void print(const pair<T, L> &p) {
    cout << '(';
    print(p.first);
    cout << ",";
    print(p.second);
    cout << ')';
}
template <class T> void print(set<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T> void print(multiset<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T, size_t size> void print(const T (&a)[size]) {
    print(a[0]);
    for(auto i = a; ++i != end(a);) {
        cout << " ";
        print(*i);
    }
}
template <class T> void print(const T &a) { cout << a; }
int out() {
    putchar('\n');
    return 0;
}
template <class T> int out(const T &t) {
    print(t);
    putchar('\n');
    return 0;
}
template <class Head, class... Tail> int out(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
    return 0;
}
ll gcd(ll a, ll b) {
    while(b) {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}
ll lcm(ll a, ll b) {
    if(!a || !b) return 0;
    return a * b / gcd(a, b);
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
vector<int> divisor(int x) {
    vector<int> ans;
    for(int i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    sort(all(y));
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
int popcount(ll x) { return __builtin_popcountll(x); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }
template <typename T> void shuffle(vector<T> &v) {
    rep3(i, v.size() - 1, 1) { swap(v[i], v[rnd(i)]); }
}

vector<string> YES{"NO", "YES"};
vector<string> Yes{"No", "Yes"};
vector<string> yes{"no", "yes"};




    cout << 
    print(x);                                                                                                                                                  \
    cout << endl;
void err() {}
template <class T> void err(const T &t) {
    print(t);
    cout << " ";
}
template <class Head, class... Tail> void err(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
}


template <class... T> void err(const T &...) {}



























































































struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;



template <typename T = int> struct UnionFind {
    vector<int> data;
    vector<T> sz;
    bool is_default;

    UnionFind(int n) {
        data.assign(n, -1);
        sz.assign(n, 1);
        is_default = true;
    }

    UnionFind(int n, vector<T> &a) {
        data.assign(n, -1);
        sz = a;
        is_default = false;
    }
    UnionFind() = default;

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        if(!is_default) sz[x] += sz[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if(data[x] < 0) return x;
        return (data[x] = find(data[x]));
    }

    T size(int x) { return (is_default ? -data[find(x)] : sz[find(x)]); }
};
template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

    operator int() const { return to; }
};

template <typename T = int> struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {}

    size_t size() const { return g.size(); }

    void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if(weighted) cin >> c;
            if(directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

template <typename T = int> using Edges = vector<Edge<T>>;


template <typename T = int> struct StronglyConnectedComponents : Graph<T> {
  public:
    using Graph<T>::Graph;
    using Graph<T>::g;
    vector<int> comp;
    Graph<T> dag;
    vector<vector<int>> group;

    void build() {
        rg = Graph<T>(g.size());
        for(int i = 0; i < g.size(); i++) {
            for(auto &e : g[i]) { rg.add_directed_edge(e.to, e.from, e.cost); }
        }
        comp.assign(g.size(), -1);
        used.assign(g.size(), 0);
        for(int i = 0; i < g.size(); i++) dfs(i);
        reverse(begin(order), end(order));
        int ptr = 0;
        for(int i : order)
            if(comp[i] == -1) rdfs(i, ptr), ptr++;
        dag = Graph<T>(ptr);
        for(int i = 0; i < g.size(); i++) {
            for(auto &e : g[i]) {
                int x = comp[e.from], y = comp[e.to];
                if(x == y) continue;
                dag.add_directed_edge(x, y, e.cost);
            }
        }
        group.resize(ptr);
        for(int i = 0; i < g.size(); i++) { group[comp[i]].emplace_back(i); }
    }

    int operator[](int k) const { return comp[k]; }

  private:
    vector<int> order, used;
    Graph<T> rg;

    void dfs(int idx) {
        if(exchange(used[idx], true)) return;
        for(auto &to : g[idx]) dfs(to);
        order.push_back(idx);
    }

    void rdfs(int idx, int cnt) {
        if(comp[idx] != -1) return;
        comp[idx] = cnt;
        for(auto &to : rg.g[idx]) rdfs(to, cnt);
    }
};


struct id0 : StronglyConnectedComponents<bool> {
  public:
    using StronglyConnectedComponents<bool>::g;
    using StronglyConnectedComponents<bool>::comp;
    using StronglyConnectedComponents<bool>::add_edge;
    size_t sz;
    UnionFind<int> uf;
    explicit id0(size_t v) : sz(v), StronglyConnectedComponents<bool>(v + v), uf(v + v) {}

    void add_if(int u, int v) {
        

        add_directed_edge(u, v);
        add_directed_edge(rev(v), rev(u));
    }

    void add_or(int u, int v) {
        

        add_if(rev(u), v);
        uf.unite(rev(u), v);
    }

    void add_nand(int u, int v) {
        

        add_if(u, rev(v));
    }

    void set_true(int u) {
        

        add_directed_edge(rev(u), u);
    }

    void set_false(int u) {
        

        add_directed_edge(u, rev(u));
    }

    inline int rev(int x) {
        if(x >= sz) return x - sz;
        return x + sz;
    }

    vector<int> solve() {
        StronglyConnectedComponents<bool>::build();
        vector<int> ret(sz);
        for(int i = 0; i < sz; i++) {
            if(comp[i] == comp[rev(i)]) return {};
            ret[i] = comp[i] > comp[rev(i)];
        }
        return ret;
    }
};
main() {
    INT(T);
    while(T--) {
        INT(n);
        VEC(int, a, n);
        VEC(int, b, n);
        vi cnt(n + 1);
        cnt[0] = 2;
        rep(i, n) cnt[a[i]]++, cnt[b[i]]++;
        if(cnt != vi(n + 1, 2)) {
            cout << -1 << endl;
            continue;
        }
        vv(int, p, n + 1);
        rep(i, n) {
            p[a[i]].eb(i + 1);
            p[b[i]].eb(-i - 1);
        }
        id0 two(n);
        UnionFind uf(n);
        rep2(i, 1, n) {
            rep(_, 2) {
                int x = p[i][0], y = p[i][1];
                if(_) x = -x, y = -y;
                if(x < 0)
                    x = two.rev(-x - 1);
                else
                    x--;
                if(y < 0)
                    y = two.rev(-y - 1);
                else
                    --y;
                two.add_or(x, y);
            }
            uf.unite(abs(p[i][0]) - 1, abs(p[i][1]) - 1);
        }
        auto ret = two.solve();
        if(ret.empty()) {
            cout << -1 << endl;
        } else {
            

            vi ans;
            vector<vi> bel(n);
            rep(i, n) { bel[uf.find(i)].eb(i); }
            rep(i, n) {
                if(bel[i].empty()) continue;
                int c = 0;
                vi tmp;
                for(auto e : bel[i]) {
                    if(!ret[e]) c++, tmp.eb(e + 1);
                }
                if(bel[i].size() - c < c) {
                    tmp.clear();
                    for(auto e : bel[i]) {
                        if(ret[e]) tmp.eb(e + 1);
                    }
                }
                for(auto e : tmp) ans.eb(e);
            }
            cout << ans.size() << endl;
            print(ans);
        }
    }
}