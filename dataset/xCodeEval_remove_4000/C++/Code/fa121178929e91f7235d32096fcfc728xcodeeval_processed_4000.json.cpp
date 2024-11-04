


















    vector<type> name(size);                                                                                                                                   \
    IN(name)


    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)







using namespace std;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


    int id2;                                                                                                                                           \
    IN(id2)

    ll id2;                                                                                                                                            \
    IN(id2)

    ull id2;                                                                                                                                           \
    IN(id2)

    string id2;                                                                                                                                        \
    IN(id2)

    char id2;                                                                                                                                          \
    IN(id2)

    double id2;                                                                                                                                        \
    IN(id2)

    ld id2;                                                                                                                                            \
    IN(id2)
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

struct Graph : vector<vector<int>> {
    using vector<vector<int>>::vector;
    inline void add(int a, int b, bool directed = false) {
        (*this)[a].emplace_back(b);
        if(!directed) (*this)[b].emplace_back(a);
    }
    void read(int n = -1, int offset = 1) {
        if(n == -1) n = this->size() - 1;
        int a, b;
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset);
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
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset);
        }
    }
};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;





template <class T> struct id0 {
    vector<vector<T>> data;

    id0(int W, int H) : data(W + 1, vector<int>(H + 1, 0)) {}

    void add(int x, int y, T z) {
        ++x, ++y;
        if(x >= data.size() || y >= data[0].size()) return;
        data[x][y] += z;
    }

    void build() {
        for(int i = 1; i < data.size(); i++) {
            for(int j = 1; j < data[i].size(); j++) { data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1]; }
        }
    }

    T query(int sx, int sy, int gx, int gy) { return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]); }
};
template <typename T = int, const int LLOG = 12, bool ismin = true> struct id1 {
    vector<vector<T>> dat[LLOG][LLOG];
    int LOG;
    vector<int> lookup;
    int H, W;
    id1(int H, int W) : H(H), W(W) {
        LOG = 0;
        while(1 << LOG <= max(H, W)) LOG++;
        for(int i = 0; i < LOG; i++)
            for(int j = 0; j < LOG; j++) dat[i][j].assign(H, vector<T>(W));
    }
    id1(vector<vector<T>> &a) {
        LOG = 0;
        while((1 << LOG) <= max(a.size(), a[0].size())) LOG++;
        H = W = (1 << LOG);
        for(int i = 0; i < LOG; i++)
            for(int j = 0; j < LOG; j++) dat[i][j].assign(H, vector<T>(W));
        for(int i = 0; i < a.size(); ++i)
            for(int j = 0; j < a[0].size(); ++j) dat[0][0][i][j] = a[i][j];
        build();
    }
    void set(int i, int j, T x) { dat[0][0][i][j] = x; }
    void build() {
        lookup.resize(max(H, W) + 1);
        for(int i = 2; i < lookup.size(); ++i) lookup[i] = lookup[i >> 1] + 1;
        assert(H == (1 << LOG));
        assert(W == (1 << LOG));
        for(int k = 0; k < LOG; ++k) {
            for(int l = 0; l < LOG; ++l) {
                if(!k and !l) continue;
                for(int i = 0; i + (1 << k) <= H; ++i)
                    for(int j = 0; j + (1 << l) <= W; ++j) {
                        if(k) {
                            if(ismin)
                                dat[k][l][i][j] = min(dat[k - 1][l][i][j], dat[k - 1][l][i + (1 << (k - 1))][j]);
                            else
                                dat[k][l][i][j] = max(dat[k - 1][l][i][j], dat[k - 1][l][i + (1 << (k - 1))][j]);
                        } else {
                            if(ismin)
                                dat[k][l][i][j] = min(dat[k][l - 1][i][j], dat[k][l - 1][i][j + (1 << (l - 1))]);
                            else
                                dat[k][l][i][j] = max(dat[k][l - 1][i][j], dat[k][l - 1][i][j + (1 << (l - 1))]);
                        }
                    }
            }
        }
    }
    inline T query(int i, int j, int ii, int jj) {
        int b = lookup[ii - i], bb = lookup[jj - j];
        if(ismin)
            return min({dat[b][bb][i][j], dat[b][bb][ii - (1 << b)][j], dat[b][bb][i][jj - (1 << bb)], dat[b][bb][ii - (1 << b)][jj - (1 << bb)]});
        else
            return max({dat[b][bb][i][j], dat[b][bb][ii - (1 << b)][j], dat[b][bb][i][jj - (1 << bb)], dat[b][bb][ii - (1 << b)][jj - (1 << bb)]});
    }
};

main() {
    INT(n, m);
    VV(int, a, n, m);
    id0<int> c(n, m);
    rep(i, n) rep(j, m) if(a[i][j]) c.add(i, j, 1);
    c.build();
    vv(int, b, n, m);
    rep(i, n) rep(j, m) {
        if(!a[i][j]) {
            b[i][j] = 0;
            continue;
        }
        int l = 1, r = min(n - i, m - j) + 1;
        while(l < r - 1) {
            int mid = (l + r) >> 1;
            if(c.query(i, j, i + mid, j + mid) == mid * mid)
                l = mid;
            else
                r = mid;
        }
        b[i][j] = l;
    }
    id1<int, 12, false> sp(b);
    INT(Q);
    while(Q--) {
        INT(x1, y1, x2, y2);
        x1--, y1--;
        int r = min(x2 - x1, y2 - y1) + 1;
        int l = 0;
        while(l < r - 1) {
            int mid = (l + r) / 2;
            if(sp.query(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid)
                l = mid;
            else
                r = mid;
        }
        cout << l << endl;
    }
}