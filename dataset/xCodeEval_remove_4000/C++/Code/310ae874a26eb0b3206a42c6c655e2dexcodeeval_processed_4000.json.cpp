


















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








template <typename Monoid> struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) { seg[k + sz] = x; }

    void build() {
        for(int k = sz - 1; k > 0; k--) { seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]); }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) { seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]); }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const { return seg[k + sz]; }

    template <typename C> int id0(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if(check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    

    template <typename C> int find_first(int a, const C &check) {
        Monoid L = M1;
        if(a <= 0) {
            if(check(f(L, seg[1]))) return id0(1, check, L, false);
            return -1;
        }
        int b = sz;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                Monoid nxt = f(L, seg[a]);
                if(check(nxt)) return id0(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    

    template <typename C> int find_last(int b, const C &check) {
        Monoid R = M1;
        if(b >= sz) {
            if(check(f(seg[1], R))) return id0(1, check, R, true);
            return -1;
        }
        int a = sz;
        for(b += sz; a < b; a >>= 1, b >>= 1) {
            if(b & 1) {
                Monoid nxt = f(seg[--b], R);
                if(check(nxt)) return id0(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
    void print(int n) {
        for(int i = 0; i < n; i++) { cerr << seg[i + sz] << " "; }
        cerr << endl;
    }
};

constexpr int N = 500010;



SegmentTree<int> seg(
    N, [](int x, int y) { return min(x, y); }, INT_MAX);
struct SuffixArray {
    vector<int> SA;
    const string s;

    SuffixArray(const string &str) : s(str) {
        SA.resize(s.size());
        iota(begin(SA), end(SA), 0);
        sort(begin(SA), end(SA), [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });
        vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for(int len = 1; len < s.size(); len <<= 1) {
            for(int i = 0; i < s.size(); i++) {
                if(i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
                    classes[SA[i]] = classes[SA[i - 1]];
                } else {
                    classes[SA[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(SA), end(SA), begin(c));
            for(int i = 0; i < s.size(); i++) {
                int s1 = c[i] - len;
                if(s1 >= 0) SA[cnt[classes[s1]]++] = s1;
            }
            classes.swap(c);
        }
    }

    int operator[](int k) const { return SA[k]; }

    size_t size() const { return s.size(); }

    bool lt_substr(const string &t, int si = 0, int ti = 0) {
        int sn = (int)s.size(), tn = (int)t.size();
        while(si < sn && ti < tn) {
            if(s[si] < t[ti]) return true;
            if(s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn && ti < tn;
    }

    int lower_bound(const string &t) {
        int low = -1, high = (int)SA.size();
        while(high - low > 1) {
            int mid = (low + high) / 2;
            if(lt_substr(t, SA[mid]))
                low = mid;
            else
                high = mid;
        }
        return high;
    }

    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx - 1, high = (int)SA.size();
        t.back()++;
        while(high - low > 1) {
            int mid = (low + high) / 2;
            if(lt_substr(t, SA[mid]))
                low = mid;
            else
                high = mid;
        }
        t.back()--;
        return {idx, high};
    }

    void output() {
        for(int i = 0; i < size(); i++) { cout << i << ": " << s.substr(SA[i]) << endl; }
    }
};
struct id2 {
    const SuffixArray &SA;
    vector<int> LCP, rank;

    id2(const SuffixArray &SA) : SA(SA), LCP(SA.size()) {
        rank.resize(SA.size());
        for(int i = 0; i < SA.size(); i++) { rank[SA[i]] = i; }
        for(int i = 0, h = 0; i < SA.size(); i++) {
            if(rank[i] + 1 < SA.size()) {
                for(int j = SA[rank[i] + 1]; max(i, j) + h < SA.size() && SA.s[i + h] == SA.s[j + h]; ++h)
                    ;
                LCP[rank[i] + 1] = h;
                if(h > 0) --h;
            }
        }
    }

    int operator[](int k) const { return LCP[k]; }

    size_t size() const { return LCP.size(); }

    void output() {
        for(int i = 0; i < size(); i++) { cout << i << ": " << LCP[i] << " " << SA.s.substr(SA[i]) << endl; }
    }
};

main() {
    INT(n);
    STR(s);
    vector<vi> v(N * 2);
    int now = 0;
    rep(i, n + 1) {
        seg.set(i, now);
        v[now + N].eb(i);
        if(i == n) break;
        if(s[i] == '(')
            now++;
        else
            now--;
    }
    seg.set(n + 1, -INT_MAX);
    seg.build();
    SuffixArray sa(s);
    id2 lcp(sa);
    ll ans = 0;
    now = 0;
    rep(i, n) {
        int j = sa.SA[i];
        int d = lcp[i];
        int r = seg.find_first(j, [&](int x) { return x < seg[j]; });
        if(j + d >= r) continue;
        ans += ub(v[seg[j] + N], r) - ub(v[seg[j] + N], j + d);
    }
    cout << ans << endl;
    

    

    

    

    

    

    

    

    

    

}