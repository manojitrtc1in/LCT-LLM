




















    vector<type> name(size);                                                                                                                                   \
    IN(name)


    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)


    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(id1))))






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
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
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
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)

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
ll rndll(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng); }
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


template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;

struct Graph : vector<vector<int>> {
    using vector<vector<int>>::vector;
    Graph(int n, int m) : vector(n) { read(m); }
    inline void add(int a, int b, bool directed = false) {
        (*this)[a].emplace_back(b);

        if(!directed) (*this)[b].emplace_back(a);
    }
    void read(int n = -1, int offset = 1, bool directed = false) {

        if(n == -1) n = this->size() - 1;
        int a, b;
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset, directed);
        }
    }
};
template <typename T> struct WeightedGraph : vector<Edges<T>> {
    using vector<Edges<T>>::vector;
    inline void add(int a, int b, T c, bool directed = false) {
        (*this)[a].emplace_back(b, c);

        if(!directed) (*this)[b].emplace_back(a, c);
    }
    void read(int n = -1, int offset = 1) {

        if(n == -1) n = this->size() - 1;
        int a, b;
        T c;
        while(n--) {
            cin >> a >> b >> c;
            WeightedGraph::add(a - offset, b - offset, c);
        }
    }
};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;







template <typename T = long long> struct SegmentTree {
    using F = function<T(T, T)>;

    int sz;
    vector<T> seg;
    const F f;
    const T unit;

    SegmentTree(int n, const F f, const T &unit) : f(f), unit(unit), sz(n - 1 ? 1 << (32 - clz(n - 1)) : 1) { seg.assign(2 * sz, unit); }

    SegmentTree(vector<T> &a, const F f, const T &unit) : f(f), sz((int)a.size() > 1 ? 1 << (32 - clz(a.size() - 1)) : 1), unit(unit) {
        int n0 = a.size();
        seg.assign(2 * sz, unit);
        for(int i = 0; i < n0; ++i) seg[i + sz] = a[i];
        for(int i = sz - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
    }

    T query(int l, int r) {
        T x = unit;
        for(int d = r - l; d >= 1; d = r - l) {
            int L = l | ((1U << 31) >> clz(d));
            int k = __builtin_ctz(L);
            x = f(x, seg[(sz | l) >> k]);
            l += L & (-L);
        }
        return x;
    }

    void update(int i, T x) {
        int k = i + sz;
        seg[k] = x;
        for(k = k >> 1; k > 0; k >>= 1) { seg[k] = f(seg[k << 1], seg[(k << 1) | 1]); }
    }

    void add(int i, T x) {
        int k = i + sz;
        seg[k] = f(seg[k], x);
        for(k = k >> 1; k > 0; k >>= 1) { seg[k] = f(seg[k << 1], seg[(k << 1) | 1]); }
    }

    T operator[](int k) const { return seg[sz + k]; }
};
template <typename T> struct id2 {
    T data[401010];
    const int N;
    id2(int sz) : N(sz) {}

    T sum(int k) {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x) {
        for(++k; k < N + 1; k += k & -k) data[k] += x;
    }
};



struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    uint64_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};
bool used[505050];
main() {
    INT(n, k);
    vi x(n), y(n);
    vi xs, ys;
    __gnu_pbds::gp_hash_table<ll, vi, custom_hash> mp;
    vi Y;
    rep(i, n) cin >> x[i] >> y[i], xs.eb(x[i] - k + 1), xs.eb(x[i] + 1), ys.eb(y[i]), mp[x[i]].eb(y[i]), Y.eb(y[i] + 1), Y.eb(y[i] - k + 1);
    UNIQUE(Y);
    UNIQUE(xs);
    UNIQUE(ys);
    vll ans(n + 1);
    vll cnt(k);
    BIT<int> bit(ys.size() + 1);
    vpi mem(Y.size());
    rep(i, Y.size()) mem[i] = pii(lb(ys, Y[i]), lb(ys, Y[i] + k));
    auto get = [&](int &y) { return bit.sum(mem[y].se - 1) - bit.sum(mem[y].fi - 1); };
    vi check;
    for(auto i : xs) {
        for(auto &e : mp[i + k - 1]) {
            int l = ub(Y, e - k + 1) - 1, r = ub(Y, e) - 1;
            rep2(j, l, r) {
                if(!used[j]) check.eb(j), used[j] = true;
            }
        }
        for(auto &e : mp[i - 1]) {
            int l = ub(Y, e - k + 1) - 1, r = ub(Y, e) - 1;
            rep2(j, l, r) {
                if(!used[j]) check.eb(j), used[j] = true;
            }
        }
        for(auto &e : check) ans[get(e)] += i * (ll)(Y[e + 1] - Y[e]);
        for(auto &e : mp[i - 1]) bit.add(lb(ys, e), -1);
        for(auto &e : mp[i + k - 1]) bit.add(lb(ys, e), 1);
        for(auto &e : check) ans[get(e)] -= i * (ll)(Y[e + 1] - Y[e]);
        for(auto &e : check) used[e] = false;
        check.clear();
    }
    rep2(i, 1, n) cout << ans[i] << " ";
    cout << endl;
}