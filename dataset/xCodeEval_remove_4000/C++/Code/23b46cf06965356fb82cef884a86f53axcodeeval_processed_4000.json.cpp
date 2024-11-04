


















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


template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedTree = vector<Edges<T>>;
template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
template <typename T> using Matrix = vector<vector<T>>;
using Graph = vector<vector<int>>;
using tree = vector<vector<int>>;

tree getTree(int n, int offset = 1) {
    tree res(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset, b -= offset;
        res[a].emplace_back(b);
        res[b].emplace_back(a);
    }
    return res;
}
template <typename T> WeightedTree<T> id4(int n, int offset = 1) {
    WeightedTree<T> res(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset, b -= offset;
        T c;
        cin >> c;
        res[a].emplace_back(b, c);
        res[b].emplace_back(a, c);
    }
    return res;
}

Graph getGraph(int n, int m, int offset = 1) {
    Graph res(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a -= offset, b -= offset;
        res[a].emplace_back(b);
        res[b].emplace_back(a);
    }
    return res;
}

template <typename T> WeightedGraph<T> id3(int n, int m, int offset = 1) {
    WeightedGraph<T> res(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        T c;
        cin >> c;
        res[a].emplace_back(b, c);
        res[b].emplace_back(a, c);
    }
}
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;




template <typename OperatorMonoid> struct id0 {
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int sz, height;
    vector<OperatorMonoid> lazy;
    const H h;
    const OperatorMonoid OM0;

    id0(int n, const H h, const OperatorMonoid OM0) : h(h), OM0(OM0) {
        sz = 1;
        height = 0;
        while(sz < n) sz <<= 1, height++;
        lazy.assign(2 * sz, OM0);
    }

    inline void propagate(int k) {
        if(lazy[k] != OM0) {
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            lazy[k] = OM0;
        }
    }

    inline void thrust(int k) {
        for(int i = height; i > 0; i--) propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid &x) {
        thrust(a += sz);
        thrust(b += sz - 1);
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lazy[l] = h(lazy[l], x), ++l;
            if(r & 1) --r, lazy[r] = h(lazy[r], x);
        }
    }

    OperatorMonoid operator[](int k) {
        thrust(k += sz);
        return lazy[k];
    }
};

template <typename T, typename E> struct id2 {
    typedef function<T(T, T)> F;
    typedef function<T(T, E)> G;
    typedef function<E(E, E)> H;
    typedef function<E(E, int)> P;
    int n;
    F f;
    G g;
    H h;
    P p;
    T d1;
    E d0;
    vector<T> dat;
    vector<E> laz;
    id2(
        int n_, F _f, G _g, H _h, T _d1, E _d0, vector<T> v = vector<T>(), P _p = [](E a, int b) { return a; })
        : f(_f), g(_g), h(_h), d1(_d1), d0(_d0), p(_p) {
        init(n_);
        if(n_ == (int)v.size()) build(n_, v);
    }
    void init(int n_) {
        n = 1;
        while(n < n_) n *= 2;
        dat.clear();
        dat.resize(2 * n - 1, d1);
        laz.clear();
        laz.resize(2 * n - 1, d0);
    }
    void build(int n_, vector<T> v) {
        for(int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
        for(int i = n - 2; i >= 0; i--) dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    inline void eval(int len, int k) {
        if(laz[k] == d0) return;
        if(k * 2 + 1 < n * 2 - 1) {
            laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
            laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = d0;
    }
    T update(int a, int b, E x, int k, int l, int r) {
        eval(r - l, k);
        if(r <= a || b <= l) return dat[k];
        if(a <= l && r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2), update(a, b, x, k * 2 + 2, (l + r) / 2, r));
    }
    T update(int a, int b, E x) { return update(a, b, x, 0, 0, n); }
    T query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if(r <= a || b <= l) return d1;
        if(a <= l && r <= b) return dat[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }
    void print(int x) {
        rep(i, x) { cout << query(i, i + 1) << " "; }
        cout << endl;
    }
};

constexpr int N = 301000;












main() {
    INT(n);
    VEC(ll, a, n);
    int u = 0, d = 0;
    auto f = plus<ll>();
    id0<ll> seg(n, f, 0), ld(n, f, 0), lu(n, f, 0), rd(n, f, 0), ru(n, f, 0);
    id2<int, int> ans(
        n, [](int x, int y) { return max(x, y); }, plus<int>(), plus<int>(), 0, 0);
    rep(i, n - 1) {
        if(a[i] < a[i + 1])
            u++, d = 0;
        else if(a[i] > a[i + 1])
            d++, u = 0;
        else
            u = 0, d = 0;
        lu.update(i + 1, i + 2, d);
        ld.update(i + 1, i + 2, u);
    }
    d = u = 0;
    rep3(i, n - 2, 0) {
        if(a[i] < a[i + 1])
            d++, u = 0;
        else if(a[i] > a[i + 1])
            d = 0, u++;
        else
            d = u = 0;
        ru.update(i, i + 1, d);
        rd.update(i, i + 1, u);
    }
    vi v;
    rep(i, n) v.emplace_back(ld[i] + rd[i] + 1);
    ans.build(n, v);
    rep(i, n) seg.update(i, i + 1, a[i]);
    INT(Q);
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    while(Q--) {
        INT(l, r, d);
        l--;
        bool rch = false, lch = false;
        bool req = false, leq = false;
        if(l and seg[l - 1] >= seg[l] and seg[l - 1] < seg[l] + d) lch = true;
        if(l and seg[l - 1] > seg[l] and seg[l - 1] == seg[l] + d) leq = true;
        if(r != n and seg[r] >= seg[r - 1] and seg[r] < seg[r - 1] + d) rch = true;
        if(r != n and seg[r] > seg[r - 1] and seg[r] == seg[r - 1] + d) req = true;
        seg.update(l, r, d);
        int sub2, right, add2, st, en, ne, jf, fj;
        if(lch or leq) {
            int sub = rd[l - 1];
            int left = l - 1 - lu[l - 1];
            lu.update(l, l + rd[l] + 1, -lu[l]);
            rd.update(left, l, -sub);
            ans.update(left, l, -sub);
            int add = ld[l - 1] + 1;
            if(lch) {
                ld.update(l, l + 1 + ru[l], add);
                ans.update(l, l + 1 + ru[l], add);
                ru.update(l - 1 - ld[l - 1], l, ru[l] + 1);
            }
        }
        if(rch or req) {
            jf = r - 1 - ld[r - 1];
            fj = -ru[r - 1];
            sub2 = ld[r];
            right = r + ru[r];
            add2 = rd[r] + 1;
            st = r - 1 - lu[r - 1];
            en = r + rd[r] + 1;
            ne = lu[r - 1];
        }
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        if(rch or req) {
            ru.update(jf, r, fj);
            ld.update(r, right + 1, -sub2);
            ans.update(r, right + 1, -sub2);
            if(rch) {
                rd.update(st, r, add2);
                ans.update(st, r, add2);
                lu.update(r, en, ne + 1);
            }
        }
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        cout << ans.query(0, ans.n) << endl;
    }
}