


using namespace std;


struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} id7;



struct T {
    int f, s, t;
    T() { f = -1, s = -1, t = -1; }
    T(int f, int s, int t) : f(f), s(s), t(t) {}
    bool operator<(const T &r) const {
        return f != r.f ? f < r.f : s != r.s ? s < r.s : t < r.t;
        

    }
    bool operator>(const T &r) const {
        return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t;
        

    }
    bool operator==(const T &r) const {
        return f == r.f && s == r.s && t == r.t;
    }
    bool operator!=(const T &r) const {
        return f != r.f || s != r.s || t != r.t;
    }
    int operator[](int i) {
        assert(i < 3);
        return i == 0 ? f : i == 1 ? s : t;
    }
};





using dou = double;
using itn = int;
using str = string;
using bo= bool;

using P = pair<ll, ll>;


















using vi = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vc = vector<char>;
using vp = vector<P>;
using vt = vector<T>;

















template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }





















using mapi = map<int, int>;
using mapd = map<dou, int>;
using mapc = map<char, int>;
using maps = map<str, int>;
using seti = set<int>;
using setd = set<dou>;
using setc = set<char>;
using sets = set<str>;
using qui = queue<int>;































const int inf = (int) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795029L;
ll ma = numeric_limits<ll>::min();
ll mi = numeric_limits<ll>::max();
const int y4[] = {-1, 1, 0, 0};
const int x4[] = {0, 0, -1, 1};
const int y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int x8[] = {1, 0, -1, 0, 1, -1, 1, -1};














inline void sort(string &a) { sort(a.begin(), a.end()); }
template<class T> inline void sort(vector<T> &a) { sort(a.begin(), a.end()); };
template<class T> inline void sort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len); };
template<class T, class F> inline void sort(vector<T> &a, F f) { sort(a.begin(), a.end(), [&](T l, T r) { return f(l) < f(r); }); };
enum ___pcomparator {
    fisi, fisd, fdsi, fdsd, sifi, sifd, sdfi, sdfd
};
inline void sort(vector<P> &a, ___pcomparator type) {
    switch (type) {
        case fisi:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi < r.fi : l.se < r.se; });
            break;
        case fisd:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi < r.fi : l.se > r.se; });
            break;
        case fdsi:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi > r.fi : l.se < r.se; });
            break;
        case fdsd:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi > r.fi : l.se > r.se; });
            break;
        case sifi:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se < r.se : l.fi < r.fi; });
            break;
        case sifd:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se < r.se : l.fi > r.fi; });
            break;
        case sdfi:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se > r.se : l.fi < r.fi; });
            break;
        case sdfd:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se > r.se : l.fi > r.fi; });
            break;
    }
};
inline void sort(vector<T> &a, ___pcomparator type) {
    switch (type) {
        case fisi:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f < r.f : l.s < r.s; });
            break;
        case
            fisd:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f < r.f : l.s > r.s; });
            break;
        case
            fdsi:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f > r.f : l.s < r.s; });
            break;
        case
            fdsd:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f > r.f : l.s > r.s; });
            break;
        case
            sifi:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s < r.s : l.f < r.f; });
            break;
        case
            sifd:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s < r.s : l.f > r.f; });
            break;
        case
            sdfi:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s > r.s : l.f < r.f; });
            break;
        case
            sdfd:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s > r.s : l.f > r.f; });
            break;
    }
};
template<class T> inline void rsort(vector<T> &a) { sort(a.begin(), a.end(), greater<T>()); };
template<class T> inline void rsort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len, greater<T>()); };
template<class U, class F> inline void rsort(vector<U> &a, F f) { sort(a.begin(), a.end(), [&](U l, U r) { return f(l) > f(r); }); };
template<class U> inline void sortp(vector<U> &a, vector<U> &b) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;;
    }
};




template<class U, class F> inline void sortp(vector<U> &a, vector<U> &b, F f) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c, f);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U, class F> inline void sortp(vector<U> &a, vector<U> &b, char type) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c, type);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U> inline void id4(vector<U> &a, vector<U> &b) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    rsort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U, class F> inline void id4(vector<U> &a, vector<U> &b, F f) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    rsort(c, f);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U> inline void sortt(vector<U> &a, vector<U> &b, vector<U> &c) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    sort(r);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class U, class F> inline void sortt(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    sort(r, f);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class U, class F> inline void id2(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    rsort(r, f);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class T> inline void sort2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)sort(a[i]); }
template<class T> inline void id1(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
template<typename A, size_t N, typename T> void fill(A (&a)[N], const T &v) { rep(i, N)a[i] = v; }
template<typename A, size_t N, size_t O, typename T> void fill(A (&a)[N][O], const T &v) { rep(i, N)rep(j, O)a[i][j] = v; }
template<typename A, size_t N, size_t O, size_t P, typename T> void fill(A (&a)[N][O][P], const T &v) { rep(i, N)rep(j, O)rep(k, P)a[i][j][k] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, typename T> void fill(A (&a)[N][O][P][Q], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)a[i][j][k][l] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, typename T> void fill(A (&a)[N][O][P][Q][R], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)a[i][j][k][l][m] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S, typename T> void fill(A (&a)[N][O][P][Q][R][S], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)rep(n, S)a[i][j][k][l][m][n] = v; }

template<typename V, typename T>
void fill(V &xx, const T vall) {
    xx = vall;
}
template<typename V, typename T>
void fill(vector<V> &vecc, const T vall) {
    for (auto &&vx: vecc) fill(vx, vall);
}



template<typename T = int> T _in() {
    T x;
    cin >> x;
    return (x);
}























string sin() { return _in<string>(); }
ll lin() { return _in<ll>(); }












template<class T> void err2(T &&head) { cerr << head; }
template<class T, class... U> void err2(T &&head, U &&... tail) {
    cerr << head << " ";
    err2(tail...);
}
template<class T, class... U> void err(T &&head, U &&... tail) {
    cerr << head << " ";
    err2(tail...);
    cerr << "" << endl;
}
template<class T> void err(T &&head) { cerr << head << endl; }
void err() { cerr << "" << endl; }
template<class T> string id8(vector<T> &a, ll W = inf) {
    stringstream ss;
    if (W == inf)W = min(sz(a), 12ll);
    if (sz(a) == 0)return ss.str();
    rep(i, W) { ss << a[i] << " "; }
    return ss.str();
}
template<class T> string id8(vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {
    H = min({H, sz(a), 12ll});
    W = min({W, sz(a[0]), 12ll});
    stringstream ss;
    ss << endl;
    if (key == -1)ss << " *|"; else ss << " " << key << "|";
    rep(w, W)ss << std::right << std::setw(4) << w;
    ss << "" << endl;
    rep(w, W * 4 + 3)ss << "_";
    ss << "" << endl;
    rep(h, H) {
        ss << std::right << std::setw(2) << h << "|";
        rep(w, min(sz(a[h]), 12ll)) { if (abs(a[h][w]) == linf) ss << "   e" << ""; else ss << std::right << std::setw(4) << a[h][w]; }
        ss << "" << endl;
    }
    return ss.str();
}

template<class T> string id8(vector<vector<vector<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {stringstream ss;    if (H == inf)H = 5;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << id8(a[i], W, U, i);    }       return ss.str();}
string id8(int a) {stringstream ss;ss << a;return ss.str();}
template<class T> string id8(T &a) {stringstream ss;ss << a;return ss.str();}

template<class T> string out_m(vector<T> &a, ll W = inf) {stringstream ss;    if (W == inf)W = min(sz(a), 12ll);   if(sz(a)==0)return ss.str();   rep(i, W) { ss << a[i] << " "; }    ss << "" << endl;    return ss.str();}
template<class T> string out_m(vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {
    H = min({H, sz(a), 12ll});
    W = min({W, sz(a[0]), 12ll});
    stringstream ss;
    ss << endl;
    if (key == -1)ss << " *|"; else ss << " " << key << "|";
    rep(w, W)ss << std::right << std::setw(4) << w;
    ss << "" << endl;
    rep(w, W * 4 + 3)ss << "_";
    ss << "" << endl;
    rep(h, H) {
        ss << std::right << std::setw(2) << h << "|";
        rep(w, min(sz(a[h]),12ll)) { if (abs(a[h][w]) == linf) ss << "   e" << ""; else ss << std::right << std::setw(4) << a[h][w]; }
        ss << "" << endl;
    }
    ss << endl;
    return ss.str();
}

template<class T> string out_m(vector<vector<vector<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {stringstream ss;    if (H == inf)H = 5;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << out_m(a[i], W, U, i);    }    ss << endl;    return ss.str();}
string out_m(int a) {stringstream ss;ss << a << endl;return ss.str();}
template<class T> string out_m(T &a) {stringstream ss;ss << a << endl;return ss.str();}
template<class T> void outv(vector<T> &a, ll W=inf) {cout << out_m(a,W) << endl;}
template<class T> void outv(vector<vector<T> > &a, ll H = linf, ll W = linf,int key=-1) {    cout << out_m(a,H,W,key) << endl;}
template<class T> void outv(vector<vector<vector<T> > > &a, ll H = linf, ll W = linf,ll U = linf) {cout << out_m(a,H,W,U)<< endl;}

template<class T> void outv(vector<T> &a, ll W = inf) {
    rep(i, min(W, sz(a))) { cout << a[i] << " "; }
    cout << "" << endl;
}
template<class T> void outv(vector<vector<T> > &a, ll H = linf, ll W = linf, int key = -1) { rep(i, min(H, sz(a))) { outv(a[i], W); }}
template<class T> void outv(vector<vector<vector<T> > > &a, ll H = linf, ll W = linf, ll U = linf) { ; }
























void ole() {

    debugline("ole");
    exit(0);

    string a = "a";
    rep(i, 30)a += a;
    rep(i, 1 << 17)cout << a << endl;
    cout << "OLE 出力長制限超過" << endl;
    exit(0);
}
void tle() { while (inf)cout << inf << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll gcd(vi b) {
    ll res = b[0];
    for (auto &&v :b)res = gcd(v, res);
    return res;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll rev(ll a) {
    ll res = 0;
    while (a) {
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
}
template<class T> void rev(vector<T> &a) {
    reverse(all(a));
}
void rev(string &a) {
    reverse(all(a));
}
ll ceil(ll a, ll b) {
    if (b == 0) {
        debugline("ceil");
        deb(a, b);
        ole();
        return -1;
    } else return (a + b - 1) / b;
}
ll sqrt(ll a) {
    if (a < 0) {
        debugline("sqrt");
        deb(a);
        ole();
    }
    ll res = (ll) std::sqrt(a);
    while (res * res < a)res++;
    return res;
}
double log(double e, double x) { return log(x) / log(e); }
ll sig(ll t) { return (1 + t) * t / 2; }
ll sig(ll s, ll t) { return (s + t) * (t - s + 1) / 2; }

vi id0(int v) {
    vi res;
    double lim = std::sqrt(v);
    for (int i = 1; i <= lim; ++i) {
        if (v % i == 0) {
            res.pb(i);
            if (i != v / i)res.pb(v / i);
        }
    }
    return res;
}

vb isPrime;
vi primes;

void setPrime() {
    int len = 4010101;
    isPrime.resize(4010101);
    fill(isPrime, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(len) + 5; ++i) {
        if (!isPrime[i])continue;
        for (int j = 2; i * j < len; ++j) {
            isPrime[i * j] = false;
        }
    }
    rep(i, len)if (isPrime[i])primes.pb(i);
}

vi factorization(int v) {
    int tv = v;
    vi res;
    if (isPrime.size() == 0)setPrime();
    for (auto &&p :primes) {
        if (v % p == 0)res.push_back(p);
        while (v % p == 0) {
            v /= p;
        }
        if (v == 1 || p * p > tv)break;
    }
    if (v > 1)res.pb(v);
    return res;
}

vp id6(int v) {


    int tv = v;
    vp res;
    if (!sz(primes))setPrime();
    for (auto &&p :primes) {
        if (v % p == 0)res.eb(p, 0);
        while (v % p == 0) {
            v /= p;
            res.back().second++;
        }
        if (v == 1 || p * p > tv)break;
    }
    if (v > 1)res.eb(v, 1);
    return res;
}

inline bool inside(int h, int w, int H, int W) { return h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { return l <= v && v < r; }

ll u(ll a) { return a < 0 ? 0 : a; }
template<class T> vector<T> u(const vector<T> &a) {
    vector<T> ret = a;
    fora(v, ret)v = u(v);
    return ret;
}



void yn(bool a) {
    if (a)cout << "yes" << endl;
    else cout << "no" << endl;
}
void Yn(bool a) {
    if (a)cout << "Yes" << endl;
    else cout << "No" << endl;
}
void YN(bool a) {
    if (a)cout << "YES" << endl;
    else cout << "NO" << endl;
}
void fyn(bool a) {
    if (a)cout << "yes" << endl;
    else cout << "no" << endl;
    exit(0);
}
void fYn(bool a) {
    if (a)cout << "Yes" << endl;
    else cout << "No" << endl;
    exit(0);
}
void fYN(bool a) {
    if (a)cout << "YES" << endl;
    else cout << "NO" << endl;
    exit(0);
}
void Possible(bool a) {
    if (a)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    exit(0);
}
void id5(bool a) {
    if (a)cout << "id5" << endl;
    else cout << "IMPOSSIBLE" << endl;
    exit(0);
}
template<class T, class U> set<T> &operator+=(set<T> &a, U v) {
    a.insert(v);
    return a;
}
template<class T, class U> vector<T> &operator+=(vector<T> &a, U v) {
    a.pb(v);
    return a;
}
template<class T> T sum(vector<T> &v, int s = 0, int t = inf) {
    T ret = 0;
    rep(i, s, min(sz(v), t))ret += v[i];
    return ret;
}
void mod(int &a, int m) { a = (a % m + m) % m; }
template<class F> inline int mgr(int ok, int ng, F f) {

    if (ok < ng)while (ng - ok > 1) { _mgrbody } else while (ok - ng > 1) { _mgrbody }
    return ok;
}

template<class F> inline int mgr(int ok, int ng, int second, F f) {

    if (ok < ng) while (ng - ok > 1) { _mgrbody2 } else while (ok - ng > 1) { _mgrbody2 }
    return ok;
}
template<typename T> ostream &operator<<(ostream &os, vector<T> &m) {
    for (auto &&v:m) os << v << " ";
    return os;
}
constexpr bool bget(ll m, int keta) { return (m >> keta) & 1; }
int bget(ll m, int keta, int sinsuu) {
    m /= (ll) pow(sinsuu, keta);
    return m % sinsuu;
}
ll bit(int n) { return (1LL << (n)); }
ll bit(int n, int sinsuu) { return (ll) pow(sinsuu, n); }
int mask(int n) { return (1ll << n) - 1; }

template<class T> vector<T> ruiv(vector<T> &a) {
    vector<T> ret(a.size() + 1);
    rep(i, a.size())ret[i + 1] = ret[i] + a[i];
    return ret;
}
template<class T, class U> inline bool chma(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class U> inline bool chma(const U &b) { return chma(ma, b); }
template<class T, class U> inline bool chmi(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<class U> inline bool chmi(const U &b) { return chmi(mi, b); }

int max(vi &a) {
    int res = a[0];
    fora(v, a) {
        res = max(res, v);
    }
    return res;
}
int min(vi &a) {
    int res = a[0];
    fora(v, a) {
        res = min(res, v);
    }
    return res;
}
template<typename T> class fixed_point        : T {public:    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }};template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }



int N, K, H, W;
vi A, B, C;


struct xorshift {    static uint64_t splitmix64(uint64_t x) {        x += 0x9e3779b97f4a7c15;        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;        return x ^ (x >> 31);    }    size_t operator()(uint64_t x) const {        static const uint64_t id3 = chrono::steady_clock::now().time_since_epoch().count();        return splitmix64(x + id3);    }    size_t operator()(std::pair<ll, ll> x) const {        ll v=((x.first) << 32) | x.second;        static const uint64_t id3 = chrono::steady_clock::now().time_since_epoch().count();        return splitmix64(v + id3);    }};

signed main() {
    

    map<vp, int> s;
    

    din(N, K);
    na(A,N);
    int cou=0;
    rep(i, N){
        auto ve_ = id6(A[i]);
        rep(j,sz(ve_)){
            ve_[j].se %= K;
        }
        vp ve;
        rep(j,sz(ve_)){
            int ad = (ve_[j].se)%K;
            if(ad)ve += ve_[j];
        }
        vp ne;


        rep(j,sz(ve)){
            int ad = (K -ve[j].se)%K ;
            if(ad)ne += mp(ve[j].fi,ad);
        }

        cou += s[ne];
        s[ve]++;
    }
    cout << cou << endl;
}