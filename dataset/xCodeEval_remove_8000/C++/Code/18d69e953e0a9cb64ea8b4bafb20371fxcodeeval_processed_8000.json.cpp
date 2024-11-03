














































































using namespace std;
using ll = long long;
using ull = unsigned long long int;
using i128 = __int128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
template <typename T> using vc = vector<T>;
template <typename T> using vvc = vector<vc<T>>;
template <typename T> using vvvc = vector<vvc<T>>;
using vi = vc<int>;
using vl = vc<ll>;
using vpi = vc<pii>;
using vpl = vc<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T> int si(const T &x) { return x.size(); }
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    return iota(a.begin(), a.end(), 0), a;
}
template <typename T> vi iota(const vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}






































template <typename T = ll, typename S> T SUM(const S &v) { return accumulate(all(v), T(0)); }







    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(id3))))
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

namespace yesno_impl {
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
const string firstsecond[2] = {"second", "first"};
const string FirstSecond[2] = {"Second", "First"};
const string possiblestr[2] = {"impossible", "possible"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
void first(bool t = 1) { cout << firstsecond[t] << endl; }
void First(bool t = 1) { cout << FirstSecond[t] << endl; }
void possible(bool t = 1) { cout << possiblestr[t] << endl; }
}; 

using namespace yesno_impl;


    int id3;                                                                                                                                           \
    IN(id3)

    ll id3;                                                                                                                                            \
    IN(id3)

    string id3;                                                                                                                                        \
    IN(id3)

    char id3;                                                                                                                                          \
    IN(id3)

    double id3;                                                                                                                                        \
    IN(id3)

    vector<type> name(size);                                                                                                                                   \
    IN(name)

    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])

    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])

    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}

template <typename T, typename S> T ceil(T x, S y) {
    assert(y);
    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}

template <typename T, typename S> T floor(T x, S y) {
    assert(y);
    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
    x %= mod;
    for(; n; n >>= 1, x = x * x % mod)
        if(n & 1) res = res * x % mod;
    return res;
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
    UNIQUE(y);
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> vector<S> zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
    return v;
}
template <typename T> vector<T> RUI(const vector<T> &v) {
    vector<T> res(v.size() + 1);
    for(int i = 0; i < v.size(); i++) res[i + 1] = res[i] + v[i];
    return res;
}


template <typename T> void rot(vector<vector<T>> &v) {
    if(empty(v)) return;
    int n = v.size(), m = v[0].size();
    vector res(m, vector<T>(n));
    rep(i, n) rep(j, m) res[m - 1 - j][i] = v[i][j];
    v.swap(res);
}


template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }

constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }


ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }


constexpr ll mask(int n) { return (1LL << n) - 1; }




int popcount(uint64_t t) { return __builtin_popcountll(t); }
static inline uint64_t id4(uint64_t x) {
    uint64_t m1 = 0x5555555555555555ll;
    uint64_t m2 = 0x3333333333333333ll;
    uint64_t m4 = 0x0F0F0F0F0F0F0F0Fll;
    uint64_t h01 = 0x0101010101010101ll;

    x -= (x >> 1) & m1;
    x = (x & m2) + ((x >> 2) & m2);
    x = (x + (x >> 4)) & m4;

    return (x * h01) >> 56;
}
bool id5(int i) { return i && (i & -i) == i; }

ll rnd(ll l, ll r) { 


    static mt19937_64 gen;

    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

    return uniform_int_distribution<ll>(l, r - 1)(gen);
}
ll rnd(ll n) { return rnd(0, n); }

template <class t> void random_shuffle(vc<t> &a) { rep(i, si(a)) swap(a[i], a[rnd(0, i + 1)]); }

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

template <class T, class S> pair<T, S> operator-(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi - y.fi, x.se - y.se); }
template <class T, class S> pair<T, S> operator+(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi + y.fi, x.se + y.se); }
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }
template <class T, class S> pair<T, S> operator+=(pair<T, S> &l, const pair<T, S> &r) { return l = l + r; }
template <class T, class S> pair<T, S> operator-=(pair<T, S> &l, const pair<T, S> &r) { return l = l - r; }
template <class T> bool intersect(const pair<T, T> &l, const pair<T, T> &r) { return (l.se < r.se ? r.fi < l.se : l.fi < r.se); }

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    constexpr bool operator<(const edge<T> &rhs) const noexcept { return cost < rhs.cost; }
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
    friend ostream operator<<(ostream &os, edge &e) { return os << e.to; }
};
template <typename T> using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return res;
}
Graph id2(int n, int margin = 1) {
    Graph res(n);
    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        res[a - margin].emplace_back(i);
    }
    return res;
}
template <class T> Wgraph<T> id8(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        scan(a), scan(b), scan(c);
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return res;
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S, class T> void add(Wgraph<S> &G, int x, int y, T c) { G[x].eb(y, c), G[y].eb(x, c); }


    INT(testcases);                                                                                                                                            \
    while(testcases--)

istream &operator>>(istream &is, i128 &v) {
    string s;
    is >> s;
    v = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(isdigit(s[i])) { v = v * 10 + s[i] - '0'; }
    }
    if(s[0] == '-') { v *= -1; }
    return is;
}

ostream &operator<<(ostream &os, const i128 &v) {
    if(v == 0) { return (os << "0"); }
    i128 num = v;
    if(v < 0) {
        os << '-';
        num = -num;
    }
    string s;
    for(; num > 0; num /= 10) { s.push_back((char)(num % 10) + '0'); }
    reverse(s.begin(), s.end());
    return (os << s);
}
namespace aux {
template <typename T, unsigned N, unsigned L> struct tp {
    static void output(std::ostream &os, const T &v) {
        os << std::get<N>(v) << (&os == &cerr ? ", " : " ");
        tp<T, N + 1, L>::output(os, v);
    }
};
template <typename T, unsigned N> struct tp<T, N, N> {
    static void output(std::ostream &os, const T &v) { os << std::get<N>(v); }
};
} 

template <typename... Ts> std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
    if(&os == &cerr) { os << '('; }
    aux::tp<std::tuple<Ts...>, 0, sizeof...(Ts) - 1>::output(os, t);
    if(&os == &cerr) { os << ')'; }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    if(&os == &cerr) { return os << "(" << p.first << ", " << p.second << ")"; }
    return os << p.first << " " << p.second;
}
template <class Ch, class Tr, class Container> std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, const Container &x) {
    bool f = true;
    if(&os == &cerr) os << "[";
    for(auto &y : x) {
        if(&os == &cerr)
            os << (f ? "" : ", ") << y;
        else
            os << (f ? "" : " ") << y;
        f = false;
    }
    if(&os == &cerr) os << "]";
    return os;
}



void debug() { cerr << endl; }
void debug(bool) { cerr << endl; }
template <class Head, class... Tail> void debug(bool is_front, Head head, Tail... tail) {
    if(!is_front) cerr << ", ";
    cerr << head;
    debug(false, tail...);
}


    {                                                                                                                                                          \
        vector<string> _debug = _split(
        err(true, begin(_debug), args);                                                                                                                        \
    }

vector<string> _split(const string &s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while(getline(ss, x, c)) {
        if(empty(v))
            v.eb(x);
        else {
            bool flag = false;
            for(auto [c, d] : {pair('(', ')'), pair('[', ']'), pair('{', '}')}) {
                if(count(all(v.back()), c) != count(all(v.back()), d)) flag = true;
            }
            if(flag)
                v.back() += "," + x;
            else
                v.eb(x);
        }
    }
    return move(v);
}

void err(bool, vector<string>::iterator) { cerr << endl; }
template <typename T, typename... Args> void err(bool is_front, vector<string>::iterator it, T a, Args... args) {
    if(!is_front) cerr << ", ";
    cerr << it->substr((*it)[0] == ' ', (*it).size()) << " = " << a, err(false, ++it, args...);
}







void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    cout << head;
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;

template <class F> struct REC {
    F f;
    REC(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...); }
};

template <class S> vector<pair<S, int>> runLength(const vector<S> &v) {
    vector<pair<S, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}
vector<pair<char, int>> runLength(const string &v) {
    vector<pair<char, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}

int toint(const char &c, const char start = 'a') { return c - start; }
int toint(const char &c, const string &chars) { return find(all(chars), c) - begin(chars); }
int id6(const char &c) { return (islower(c) ? c - 'a' : c - 'A' + 26); }
template <typename T> auto toint(const T &v, const char &start = 'a') {
    vector<decltype(toint(v[0]))> ret;
    ret.reserve(v.size());
    for(auto &&e : v) ret.emplace_back(toint(e, start));
    return ret;
}
template <typename T> auto toint(const T &v, const string &start) {
    vector<decltype(toint(v[0]))> ret;
    ret.reserve(v.size());
    for(auto &&e : v) ret.emplace_back(toint(e, start));
    return ret;
}


template <typename T> auto id6(const T &s) {
    vector<decltype(id6(s[0]))> res;
    res.reserve(s.size());
    for(auto &&e : s) { res.emplace_back(id6(e)); }
    return res;
}

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while(abs(ok - ng) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class T, class F> T id9(T ok, T ng, const F &f, int iter = 80) {
    while(iter--) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(11);
    }
} setup_io;



template <class T, class F> struct id1 {
    vector<T> data;
    vector<int> sz;
    int num;
    const F f;
    T unit;

    id1(int n, const F &f = plus<T>(), const T &unit = T()) : num(n), f(f), unit(unit), sz(n, -1), data(n, unit) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        num--;
        if(-sz[x] < -sz[y]) swap(x, y);
        f(data[x], data[y]);
        sz[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if(sz[x] < 0) return x;
        return (sz[x] = find(sz[x]));
    }
    int size(int x) { return -sz[find(x)]; }
    T &get(int x) { return data[find(x)]; }
    const int operator[](const int k) { return find(k); }
    vector<vector<int>> belong() {
        vector<vector<int>> res(data.size());
        for(int i = 0; i < data.size(); i++) res[find(i)].emplace_back(i);
        return res;
    }
};

struct UnionFind {
    vector<int> data;
    int num;

    UnionFind(int n) : num(n) { data.assign(n, -1); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        num--;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if(data[x] < 0) return x;
        return (data[x] = find(data[x]));
    }
    int size(int x) { return -data[find(x)]; }
    const int operator[](const int k) { return find(k); }
    vector<vector<int>> belong() {
        vector<vector<int>> res(data.size());
        for(int i = 0; i < data.size(); i++) res[find(i)].emplace_back(i);
        return res;
    }
    void reset() {
        num = data.size();
        data.assign(num, -1);
    }
};











template <const int D = 6> struct FastSet {
    int n;
    using u64 = uint64_t;
    vector<u64> a[D];
    FastSet(int n_ = (1 << std::min(31, D * 6))) : n(n_) {
        for(int i = 0; i < D; i++) {
            n_ = (n_ + 63) >> 6;
            a[i].assign(n_, 0);
        }
    }
    bool empty() const { return !a[D - 1][0]; }
    bool contains(int x) const { return (a[0][x >> 6] >> (x & 63)) & 1; }
    void insert(int x) {
        for(int i = 0; i < D; i++) {
            const int y = x & 63;
            x >>= 6;
            a[i][x] |= 1ULL << y;
        }
    }
    void erase(int x) {
        for(int i = 0; i < D; i++) {
            const int y = x & 63;
            x >>= 6;
            if((a[i][x] &= ~(1ULL << y))) break;
        }
    }
    int next(int x) const {
        for(int i = 0; i < D; i++) {
            const int k = x >> 6, y = x & 63;
            if(k >= a[i].size()) return n;
            const u64 top = a[i][k] >> y;
            if(top) {
                x += __builtin_ctzll(top);
                for(int j = i - 1; j >= 0; --j) x = x << 6 | __builtin_ctzll(a[j][x]);
                return x;
            }
            x = k + 1;
        }
        return n;
    }
    int prev(int x) const {
        for(int i = 0; i < D; ++i) {
            if(x < 0) return -1;
            const int k = x >> 6, y = x & 63;
            const u64 bot = a[i][k] << (63 - y);
            if(bot) {
                x -= __builtin_clzll(bot);
                for(int j = i - 1; j >= 0; --j) x = x << 6 | (63 - __builtin_clzll(a[j][x]));
                return x;
            }
            x = k - 1;
        }
        return -1;
    }
    int max() const { return prev(n); }
    int min() const { return next(0); }
};

template <typename T> struct id0 {
    

    int Q;
    vector<T> ok, ng, mid;
    vector<int> idx, nidx;
    id0(int Q, T OK, T NG) : Q(Q), ok(Q, OK), ng(Q, NG), mid(Q), idx(Q), nidx(Q) { iota(begin(idx), end(idx), 0); }

    

    

    

    

    

    

    

    template <typename EVENT, typename P, typename F, typename INIT>
    vector<T> build(const vector<EVENT> &v, const P &p, const F &f, const INIT &init, bool greater = false) {
        while(true) {
            bool done = true;
            for(int i = 0; i < Q; i++)
                if(abs(ok[i] - ng[i]) > 1) done = false;
            if(done) return ok;
            for(int i = 0; i < Q; i++) mid[i] = (ok[i] + ng[i]) >> 1;

            init();
            int pos = 0;
            for(int i = 0; i < Q; i++) {
                while(pos < v.size() and v[pos] < mid[idx[i]]) { p(v[pos++]); }
                int j = i;
                while(j < Q and ok[idx[i]] == ok[idx[j]] and ng[idx[i]] == ng[idx[j]]) j++;
                int l = i, r = j;
                for(int k = i; k < j; k++) {
                    bool can = f(idx[k], mid[idx[k]]);
                    if(can ^ (ng[idx[k]] < ok[idx[k]]) ^ greater)
                        nidx[--r] = idx[k];
                    else
                        nidx[l++] = idx[k];
                    (can ? ok[idx[k]] : ng[idx[k]]) = mid[idx[k]];
                }
                bool flag = true;
                i = j - 1;
            }
            swap(idx, nidx);
        }
    }
};










using namespace std;

namespace fastio {
static constexpr int SZ = 1 << 17;
char inbuf[SZ], outbuf[SZ];
int in_left = 0, in_right = 0, out_right = 0;

struct Pre {
    char num[40000];
    constexpr Pre() : num() {
        for(int i = 0; i < 10000; i++) {
            int n = i;
            for(int j = 3; j >= 0; j--) {
                num[i * 4 + j] = n % 10 + '0';
                n /= 10;
            }
        }
    }
} constexpr pre;

inline void load() {
    int len = in_right - in_left;
    memmove(inbuf, inbuf + in_left, len);
    in_right = len + fread(inbuf + len, 1, SZ - len, stdin);
    in_left = 0;
}

inline void flush() {
    fwrite(outbuf, 1, out_right, stdout);
    out_right = 0;
}

inline void skip_space() {
    if(in_left + 32 > in_right) load();
    while(inbuf[in_left] <= ' ') in_left++;
}

inline void rd(char &c) {
    if(in_left + 32 > in_right) load();
    c = inbuf[in_left++];
}
template <typename T> inline void rd(T &x) {
    if(in_left + 32 > in_right) load();
    char c;
    do c = inbuf[in_left++];
    while(c < '-');
    [[maybe_unused]] bool minus = false;
    if constexpr(is_signed<T>::value == true) {
        if(c == '-') minus = true, c = inbuf[in_left++];
    }
    x = 0;
    while(c >= '0') {
        x = x * 10 + (c & 15);
        c = inbuf[in_left++];
    }
    if constexpr(is_signed<T>::value == true) {
        if(minus) x = -x;
    }
}
inline void rd() {}
template <typename Head, typename... Tail> inline void rd(Head &head, Tail &...tail) {
    rd(head);
    rd(tail...);
}

inline void wt(char c) {
    if(out_right > SZ - 32) flush();
    outbuf[out_right++] = c;
}
inline void wt(bool b) {
    if(out_right > SZ - 32) flush();
    outbuf[out_right++] = b ? '1' : '0';
}
template <typename T> inline void wt(T x) {
    if(out_right > SZ - 32) flush();
    if(!x) {
        outbuf[out_right++] = '0';
        return;
    }
    if constexpr(is_signed<T>::value == true) {
        if(x < 0) outbuf[out_right++] = '-', x = -x;
    }
    int i = 12;
    char buf[16];
    while(x >= 10000) {
        memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
        x /= 10000;
        i -= 4;
    }
    if(x < 100) {
        if(x < 10) {
            outbuf[out_right] = '0' + x;
            ++out_right;
        } else {
            uint32_t q = (uint32_t(x) * 205) >> 11;
            uint32_t r = uint32_t(x) - q * 10;
            outbuf[out_right] = '0' + q;
            outbuf[out_right + 1] = '0' + r;
            out_right += 2;
        }
    } else {
        if(x < 1000) {
            memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);
            out_right += 3;
        } else {
            memcpy(outbuf + out_right, pre.num + (x << 2), 4);
            out_right += 4;
        }
    }
    memcpy(outbuf + out_right, buf + i + 4, 12 - i);
    out_right += 12 - i;
}
inline void wt() {}
template <typename Head, typename... Tail> inline void wt(Head &&head, Tail &&...tail) {
    wt(head);
    wt(forward<Tail>(tail)...);
}
template <typename... Args> inline void wtn(Args &&...x) {
    wt(forward<Args>(x)...);
    wt('\n');
}

struct Dummy {
    Dummy() { atexit(flush); }
} dummy;

} 

using fastio::rd;
using fastio::skip_space;
using fastio::wt;
using fastio::wtn;





namespace HashMapImpl {
using u32 = uint32_t;
using u64 = uint64_t;

template <typename Key, typename Data> struct id7;

template <typename Key, typename Data> struct itrB : iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data *, Data &> {
    using base = iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data *, Data &>;
    using ptr = typename base::pointer;
    using ref = typename base::reference;

    u32 i;
    id7<Key, Data> *p;

    explicit constexpr itrB() : i(0), p(nullptr) {}
    explicit constexpr itrB(u32 _i, id7<Key, Data> *_p) : i(_i), p(_p) {}
    explicit constexpr itrB(u32 _i, const id7<Key, Data> *_p) : i(_i), p(const_cast<id7<Key, Data> *>(_p)) {}
    friend void swap(itrB &l, itrB &r) { swap(l.i, r.i), swap(l.p, r.p); }
    friend bool operator==(const itrB &l, const itrB &r) { return l.i == r.i; }
    friend bool operator!=(const itrB &l, const itrB &r) { return l.i != r.i; }
    const ref operator*() const { return const_cast<const id7<Key, Data> *>(p)->data[i]; }
    ref operator*() { return p->data[i]; }
    ptr operator->() const { return &(p->data[i]); }

    itrB &operator++() {
        assert(i != p->cap && "itr::operator++()");
        do {
            i++;
            if(i == p->cap) break;
            if(p->flag[i] == true && p->dflag[i] == false) break;
        } while(true);
        return (*this);
    }
    itrB operator++(int) {
        itrB it(*this);
        ++(*this);
        return it;
    }
    itrB &operator--() {
        do {
            i--;
            if(p->flag[i] == true && p->dflag[i] == false) break;
            assert(i != 0 && "itr::operator--()");
        } while(true);
        return (*this);
    }
    itrB operator--(int) {
        itrB it(*this);
        --(*this);
        return it;
    }
};

template <typename Key, typename Data> struct id7 {
    using u32 = uint32_t;
    using u64 = uint64_t;
    using iterator = itrB<Key, Data>;
    using itr = iterator;

  protected:
    template <typename K> inline u64 randomized(const K &key) const { return u64(key) ^ r; }

    template <typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr, enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
    inline u32 inner_hash(const K &key) const {
        return (randomized(key) * 11995408973635179863ULL) >> shift;
    }
    template <typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr, enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,
              enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>
    inline u32 inner_hash(const K &key) const {
        u64 a = randomized(key.first), b = randomized(key.second);
        a *= 11995408973635179863ULL;
        b *= 10150724397891781847ULL;
        return (a + b) >> shift;
    }
    template <typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
              enable_if_t<is_integral<typename K::value_type>::value, nullptr_t> = nullptr>
    inline u32 inner_hash(const K &key) const {
        static constexpr u64 mod = (1LL << 61) - 1;
        static constexpr u64 base = 950699498548472943ULL;
        u64 res = 0;
        for(auto &elem : key) {
            __uint128_t x = __uint128_t(res) * base + (randomized(elem) & mod);
            res = (x & mod) + (x >> 61);
        }
        __uint128_t x = __uint128_t(res) * base;
        res = (x & mod) + (x >> 61);
        if(res >= mod) res -= mod;
        return res >> (shift - 3);
    }

    template <typename D = Data, enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr> inline u32 hash(const D &dat) const { return inner_hash(dat); }
    template <typename D = Data, enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr> inline u32 hash(const D &dat) const {
        return inner_hash(dat.first);
    }

    template <typename D = Data, enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr> inline Key dtok(const D &dat) const { return dat; }
    template <typename D = Data, enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr> inline Key dtok(const D &dat) const {
        return dat.first;
    }

    void reallocate(u32 ncap) {
        vector<Data> ndata(ncap);
        vector<bool> nf(ncap);
        shift = 64 - __lg(ncap);
        for(u32 i = 0; i < cap; i++) {
            if(flag[i] == true && dflag[i] == false) {
                u32 h = hash(data[i]);
                while(nf[h]) h = (h + 1) & (ncap - 1);
                ndata[h] = move(data[i]);
                nf[h] = true;
            }
        }
        data.swap(ndata);
        flag.swap(nf);
        cap = ncap;
        dflag.resize(cap);
        fill(std::begin(dflag), std::end(dflag), false);
    }

    inline bool extend_rate(u32 x) const { return x * 2 >= cap; }

    inline bool shrink_rate(u32 x) const { return HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap; }

    inline void extend() { reallocate(cap << 1); }

    inline void shrink() { reallocate(cap >> 1); }

  public:
    u32 cap, s;
    vector<Data> data;
    vector<bool> flag, dflag;
    u32 shift;
    static u64 r;
    static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;

    explicit id7() : cap(HASHMAP_DEFAULT_SIZE), s(0), data(cap), flag(cap), dflag(cap), shift(64 - __lg(cap)) {}

    itr begin() const {
        u32 h = 0;
        while(h != cap) {
            if(flag[h] == true && dflag[h] == false) break;
            h++;
        }
        return itr(h, this);
    }
    itr end() const { return itr(this->cap, this); }

    friend itr begin(const id7 &h) { return h.begin(); }
    friend itr end(const id7 &h) { return h.end(); }

    itr find(const Key &key) const {
        u32 h = inner_hash(key);
        while(true) {
            if(flag[h] == false) return this->end();
            if(dtok(data[h]) == key) {
                if(dflag[h] == true) return this->end();
                return itr(h, this);
            }
            h = (h + 1) & (cap - 1);
        }
    }

    bool contain(const Key &key) const { return find(key) != this->end(); }

    itr insert(const Data &d) {
        u32 h = hash(d);
        while(true) {
            if(flag[h] == false) {
                if(extend_rate(s + 1)) {
                    extend();
                    h = hash(d);
                    continue;
                }
                data[h] = d;
                flag[h] = true;
                ++s;
                return itr(h, this);
            }
            if(dtok(data[h]) == dtok(d)) {
                if(dflag[h] == true) {
                    data[h] = d;
                    dflag[h] = false;
                    ++s;
                }
                return itr(h, this);
            }
            h = (h + 1) & (cap - 1);
        }
    }

    

    

    itr erase(itr it, bool get_next = true) {
        if(it == this->end()) return this->end();
        s--;
        if(shrink_rate(s)) {
            Data d = data[it.i];
            shrink();
            it = find(dtok(d));
        }
        int ni = (it.i + 1) & (cap - 1);
        if(this->flag[ni]) {
            this->dflag[it.i] = true;
        } else {
            this->flag[it.i] = false;
        }
        if(get_next) ++it;
        return it;
    }

    itr erase(const Key &key) { return erase(find(key)); }

    bool empty() const { return s == 0; }

    int size() const { return s; }

    void clear() {
        fill(std::begin(flag), std::end(flag), false);
        fill(std::begin(dflag), std::end(dflag), false);
        s = 0;
    }

    void reserve(int n) {
        if(n <= 0) return;
        n = 1 << min(23, __lg(n) + 2);
        if(cap < u32(n)) reallocate(n);
    }
};

template <typename Key, typename Data>
uint64_t id7<Key, Data>::r = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();

} 





template <typename Key> struct HashSet : HashMapImpl::id7<Key, Key> { using HashMapImpl::id7<Key, Key>::id7; };



int main() {
    int test;
    rd(test);
    

    rep(test) {
        int n, m;
        rd(n, m);
        

        vector<edge<int>> v;
        vector<edge<int>> w;
        UnionFind uf(n);

        HashSet<pii> E;

        rep(i, m) {
            int x, y, k;
            rd(x, y, k);
            v.eb(x - 1, y - 1, k);
        }
        auto mv = v;
        SORT(mv);
        fore(e, mv) {
            if(uf.unite(e.from, e.to)) w.eb(e);
            E.insert(minmax(e.from, e.to));
        }
        SORT(w);

        vector<edge<int>> s;

        vvc<int> mem(n + 10);
        FastSet<3> fs(n);

        auto merge = [&](vi &v, vi &w) {
            if(si(v) < si(w)) swap(v, w);
            fore(e, w) v.eb(e);
        };

        int cost;
        vi vx, wx;
        auto f = [&](vvc<int> &x, vvc<int> &y) {
            if(si(x) < si(y)) swap(x, y);
            int bi = 0;
            vx.clear(), wx.clear();
            fore(b, y) {
                vx.clear();
                int i = 0;
                fore(a, x) {
                    bool found = false;
                    fore(bb, b) {
                        fore(aa, a) {
                            if(!E.contain(minmax(bb, aa))) {
                                found = true;
                                break;
                            }
                        }
                        if(found) break;
                    }
                    if(found) vx.eb(i);
                    i++;
                }
                if(empty(vx))
                    wx.eb(bi);
                else {
                    per(j, si(vx), 1) {
                        merge(x[vx[0]], x[vx[j]]);
                        s.eb(x[vx[0]][0], x[vx[j]][0], cost);

                        merge(mem[vx[0]], mem[vx[j]]);
                        mem[vx[j]].clear();
                        fs.erase(vx[j]);

                        if(vx[j] != si(x) - 1) {
                            swap(x[vx[j]], x.back());
                            swap(mem[vx[j]], mem[si(x) - 1]);
                            if(fs.contains(si(x) - 1)) {
                                fs.erase(si(x) - 1);
                                fs.insert(vx[j]);
                            }
                        }
                        x.pop_back();
                    }
                    fs.insert(vx[0]);
                    mem[vx[0]].eb(bi);
                }
                bi++;
                dump(b);
            }
            while(fs.min() != n) {
                int k = fs.min();
                dump(k);
                fs.erase(k);
                dump(x);
                fore(e, mem[k]) {
                    merge(x[k], y[e]);
                    s.eb(x[k][0], y[e][0], cost);
                    dump(x[k], y[e], cost);
                }
                mem[k].clear();
            }
            fore(e, wx) {
                x.eb(vi());
                swap(x.back(), y[e]);
            }
        };

        id1 uf2(n, f, vvc<int>());
        rep(i, n) uf2.get(i) = {{(int)i}};
        SORT(w);
        fore(e, w) {
            cost = e.cost;
            uf2.unite(e.from, e.to);

        }

        struct EVENT {
            int s, t, c;
            bool operator<(int x) const { return c <= x; }
        };

        vector<EVENT> ev;
        fore(e, s) ev.pb(EVENT{e.from, e.to, e.cost});
        auto init = [&] { uf.reset(); };
        auto p = [&](const EVENT &e) { uf.unite(e.s, e.t); };
        auto ff = [&](int i, int x) { return uf.same(v[i].from, v[i].to); };

        id0<int> pb(m, cost, 0);
        auto res = pb.build(ev, p, ff, init, false);
        rep(i, si(res)) {
            wt(res[i]);
            wt(i == si(res) - 1 ? '\n' : ' ');
        }
    }
    

}