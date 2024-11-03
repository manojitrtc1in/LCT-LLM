





using namespace std;


struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} id14;






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
struct F {
    int a, b, c, d;
    F() { a = -1, b = -1, c = -1, d = -1; }
    F(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    bool operator<(const F &r) const {
        return a != r.a ? a < r.a : b != r.b ? b < r.b : c != r.c ? c < r.c : d < r.d;


    }
    bool operator>(const F &r) const {
        return a != r.a ? a > r.a : b != r.b ? b > r.b : c != r.c ? c > r.c : d > r.d;


    }
    bool operator==(const F &r) const {
        return a == r.a && b == r.b && c == r.c && d == r.d;
    }
    bool operator!=(const F &r) const {
        return a != r.a || b != r.b || c != r.c || d != r.d;
    }
    int operator[](int i) {
        assert(i < 4);
        return i == 0 ? a : i == 1 ? b : i == 2 ? c : d;
    }
};

T mt(int a, int b, int c) {
    return T(a, b, c);
}







using dou = double;
using itn = int;
using str = string;
using bo= bool;

using P = pair<ll, ll>;















using vi = vector<int>;









using vl = vector<ll>;







using vb = vector<bool>;







using vs = vector<string>;







using vd = vector<double>;







using vc=vector<char>;







using vp = vector<P>;






using vt = vector<T>;




















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


















namespace std {
    template<> class hash<std::pair<signed, signed>> {
    public:
        size_t operator()(const std::pair<signed, signed> &x) const {
            return hash<ll>()(((ll) x.first << 32) + x.second);
        }
    };
    template<> class hash<std::pair<ll, ll>> {
    public:
        

        size_t operator()(const std::pair<ll, ll> &x) const {
            return hash<ll>()(((ll) x.first << 32) + x.second);
        }
    };
}
istream &operator>>(istream &iss, P &a) {
    iss >> a.first >> a.second;
    return iss;
}
template<typename T> istream &operator>>(istream &iss, vector<T> &vec) {
    for (T &x: vec) iss >> x;
    return iss;
}
ostream &operator<<(ostream &os, P p) {
    os << p.fi << " " << p.se << endl;
    return os;
}
ostream &operator<<(ostream &os, T p) {
    os << p.f << " " << p.s << " " << p.t;
    return os;
}
ostream &operator<<(ostream &os, F p) {
    os << p.a << " " << p.b << " " << p.c << " " << p.d;
    return os;
}
template<typename T> ostream &operator<<(ostream &os, vector <T> &vec) {
    for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    return os;
}
template<typename T> ostream &operator<<(ostream &os, vector <vector<T>> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            os << vec[i][j];
        }
        os << endl;
    }
    return os;
}
template<typename V, typename H> void resize(vector<V> &vec, const H head) { vec.resize(head); }
template<typename V, typename H, typename ... T> void resize(vector<V> &vec, const H &head, const T ... tail) {
    vec.resize(head);
    for (auto &v: vec) resize(v, tail...);
}
template<typename T, typename _Pr> bool all_of(const vector<T> &vec, _Pr pred) { return std::all_of(vec.begin(), vec.end(), pred); }
template<typename T, typename _Pr> bool any_of(const vector<T> &vec, _Pr pred) { return std::any_of(vec.begin(), vec.end(), pred); }
template<typename T, typename _Pr> bool none_of(const vector<T> &vec, _Pr pred) { return std::none_of(vec.begin(), vec.end(), pred); }
template<typename T, typename _Pr> const typename vector<T>::const_iterator find_if(const vector<T> &vec, _Pr pred) { return std::find_if(vec.begin(), vec.end(), pred); }
template<typename T> bool contains(const vector<T> &vec, const T &val) { return std::find(vec.begin(), vec.end(), val) != vec.end(); }
template<typename T, typename _Pr> bool contains_if(const vector<T> &vec, _Pr pred) { return std::find_if(vec.begin(), vec.end(), pred) != vec.end(); }
template<class T> void replace(vector<T> &a, T key, T v) { replace(a.begin(), a.end(), key, v); }
template<class T> bool includes(vector<T> &a, vector<T> &b) {
    vi c = a;
    vi d = b;
    sort(all(c));
    sort(all(d));
    return includes(all(c), all(d));
}
template<class T> bool id17(vector<T> &a, vector<T> &b) { return id17(all(a), all(b)); }
template<class T> bool id11(vector<T> &a) { return id11(all(a)); }

template<class T> T pop(set<T> &set) {
    T res = *set.begin();
    set.erase(set.find(res));
    return res;
}
template<class T> T pop(mset<T> &set) {
    T res = *set.begin();
    set.erase(set.find(res));
    return res;
}
template<class T> T popBack(set<T> &set) {
    T res = *set.rbegin();
    set.erase(set.find(res));
    return res;
}
template<class T> T popBack(mset<T> &set) {
    T res = *set.rbegin();
    set.erase(set.find(res));
    return res;
}
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
template<class U> inline void id8(vector<U> &a, vector<U> &b) {
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
template<class U, class F> inline void id8(vector<U> &a, vector<U> &b, F f) {
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
template<class U, class F> inline void id3(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
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
template<class T> inline void id2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
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

































class UnionFind {
public:
    vi par, rank, sizes;
    int n, trees;
    UnionFind(int n) : n(n), trees(n) {
        par.resize(n), rank.resize(n), sizes.resize(n);
        rep(i, n)par[i] = i, sizes[i] = 1;
    }
    int root(int x) {
        if (par[x] == x)return x;
        else return par[x] = root(par[x]);
    }
    int find(int x) { return root(x); }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)return;
        if (rank[x] < rank[y])swap(x, y);
        trees--;
        par[y] = x;
        sizes[x] += sizes[y];
        if (rank[x] == rank[y])rank[x]++;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return sizes[root(x)]; }
    

    vec<vi> sets() {
        vec<vi> res(trees);
        umap<int, vi> map;
        rep(i, n) map[root(i)].push_back(i);
        int i = 0;
        for (auto &&p:map) {
            int r = p.fi;
            res[i].push_back(r);
            for (auto &&v:p.se) {
                if (r == v)continue;
                res[i].push_back(v);
            }
            i++;
        }
        return res;
    }
};


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


bool eq(double a, double b) { return fabs(a - b) < eps; }
using C =complex<double>;
C rot(C &a, dou th) { return a * C(cos(th), sin(th)); }
dou inpro(C &a, C &b) { return real(a * conj(b)); }



bool line(C a, C b, C c) {
    C ab = b - a;
    C ac = c - a;
    

    ab *= C(0, 1);
    return eq(inpro(ab, ac), 0);
}
bool line(P a, P b, P c) { return line(C(a.fi, a.se), C(b.fi, b.se), C(c.fi, c.se)); }

bool line(int xa, int ya, int xb, int yb, int xc, int yc) {
    C a = C(xa, ya);
    C b = C(xb, yb);
    C c = C(xc, yc);
    return line(a, b, c);
}





char ranc() {
    return (char) ('a' + rand() % 26);
}
int rand(int min, int max) {
    assert(min <= max);
    if (min >= 0 && max >= 0) {
        return rand() % (max + 1 - min) + min;
    } else if (max < 0) {
        return -rand(-max, -min);
    } else {
        

        if (rand() % 2) {
            return rand(0, max);
            

        } else {
            return -rand(0, -min);
        }
    }
}
vi ranv(int n, int min, int max) {
    vi v(n);
    rep(i, n)v[i] = rand(min, max);
    return v;
}


vi ranvi(int n, int min, int max) {
    vi v(n);
    bool bad = 1;
    while (bad) {
        bad = 0;
        v.resize(n);
        rep(i, n) {
            if (i && min > max - v[i - 1]) {
                bad = 1;
                break;
            }
            if (i)v[i] = v[i - 1] + rand(min, max - v[i - 1]);
            else v[i] = rand(min, max);
        }
    }
    return v;
}
void id9(int n, int min, int max, vi &l, vi &r) {
    l.resize(n);
    r.resize(n);
    rep(i, n) {
        l[i] = rand(min, max);
        r[i] = l[i] + rand(0, max - l[i]);
    }
}




string smax(str &a, str b) {
    if (sz(a) < sz(b)) {
        return b;
    } else if (sz(a) > sz(b)) {
        return a;
    } else {
        rep(i, sz(a)) {
            if (a[i] < b[i]) {
                return b;
            } else if (a[i] > b[i])return a;
        }
    }
    return a;
}


string smin(str &a, str b) {
    if (sz(a) < sz(b)) {
        return a;
    } else if (sz(a) > sz(b)) {
        return b;
    } else {
        rep(i, sz(a)) {
            if (a[i] < b[i]) {
                return a;
            } else if (a[i] > b[i])return b;
        }
    }
    return a;
}
template<typename V, typename T> int find(vector<V> &a, const T key) {
    rep(i, sz(a))if (a[i] == key)return i;
    return -1;
}
template<typename V, typename T> P find(vector<vector<V>> &a, const T key) {
    rep(i, sz(a)) rep(j, sz(a[0]))if (a[i][j] == key)return mp(i, j);
    return mp(-1, -1);
}
template<typename V, typename U> T find(vector<vector<vector<V>>> &a, const U key) {
    rep(i, sz(a))rep(j, sz(a[0]))rep(k, sz(a[0][0]))if (a[i][j][k] == key)return mt(i, j, k);
    return mt(-1, -1, -1);
}

template<typename V, typename T> int count(V &a, const T k) { return a == k; }
template<typename V, typename T> int count(vector<V> &a, const T k) {
    int ret = 0;
    fora(v, a)ret += count(v, k);
    return ret;
}
template<typename V> int id1(V &a) { return a % 2; }
template<typename V> int id1(vector<V> &a) {
    int ret = 0;
    fora(v, a)ret += id1(v);
    return ret;
}
template<typename V> int count_even(V &a) { return a % 2 == 0; }
template<typename V> int count_even(vector<V> &a) {
    int ret = 0;
    fora(v, a)ret += count_even(v);
    return ret;
}


void iota(vector<int> &ve, int s, int n) {
    ve.resize(n);
    iota(all(ve), s);
}
vi iota(int s, int n) {
    vi ve(n);
    iota(all(ve), s);
    return ve;
}


int mod(int a, int m) { return (a % m + m) % m; }
int pow(int a) { return a * a; };
ll fact(int v) { return v <= 1 ? 1 : v * fact(v - 1); }
ll comi(int n, int r) {
    assert(n < 100);
    static vvi(pas, 100, 100);
    if (pas[0][0])return pas[n][r];
    pas[0][0] = 1;
    rep(i, 1, 100) {
        pas[i][0] = 1;
        rep(j, 1, i + 1)pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
    }
    return pas[n][r];
}
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
template<class T> vector<T> rev(vector<T> &a) {
    vector<T> ret = a;
    reverse(all(ret));
    return ret;
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
    for (int i = 1; i <= sqrt(v); ++i) {
        if (v % i == 0) {
            res.pb(i);
            if (i != v / i)res.pb(v / i);
        }
    }
    return res;
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

unordered_map<int, int> id6(int v) {
    int tv = v;
    unordered_map<int, int> res;
    if (isPrime.size() == 0)setPrime();
    for (auto &&p :primes) {
        while (v % p == 0) {
            res[p]++;
            v /= p;
        }
        if (v == 1 || p * p > tv)break;
    }
    if (v > 1)res[v]++;
    return res;
}
int get(int a, int keta) { return (a / (int) pow(10, keta)) % 10; }
int keta(int v) {
    int cou = 0;
    while (v) { cou++, v %= 10; }
    return cou;
}
int dsum(int v) {
    int ret = 0;
    for (; v; v /= 10)ret += v % 10;
    return ret;
}
int sumd(int v) { return dsum(v); }


template<class T, class U> vector<T> keys(vector<pair<T, U>> a) {
    vector<T> res;
    for (auto &&k :a)res.pb(k.fi);
    return res;
}
template<class T, class U> vector<U> keys(map<T, U> a) {
    vector<U> res;
    for (auto &&k :a)res.pb(k.fi);
    return res;
}

template<class T, class U> vector<U> keys(umap<T, U> a) {
    vector<U> res;
    for (auto &&k :a)res.pb(k.fi);
    return res;
}

template<class T, class U> vector<U> values(vector<pair<T, U>> a) {
    vector<U> res;
    for (auto &&k :a)res.pb(k.se);
    return res;
}

template<class T, class U> vector<T> values(map<T, U> a) {
    vector<T> res;
    for (auto &&k :a)res.pb(k.se);
    return res;
}

template<class T, class U> vector<T> values(umap<T, U> a) {
    vector<T> res;
    for (auto &&k :a)res.pb(k.se);
    return res;
}

vi list(int a) {
    vi res;
    while (a) {
        res.insert(res.begin(), a % 10);
        a /= 10;
    }
    return res;
}

template<class T, class U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class U> bool chmax(const U &b) { return chmax(ma, b); }
template<class T, class U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<class U> bool chmin(const U &b) { return chmin(mi, b); }


template<class T> T min(T a, signed b) { return a < b ? a : b; }
template<class T> T max(T a, signed b) { return a < b ? b : a; }
template<class T> T min(T a, T b, T c) { return a >= b ? b >= c ? c : b : a >= c ? c : a; }
template<class T> T max(T a, T b, T c) { return a <= b ? b <= c ? c : b : a <= c ? c : a; }
template<class T> T min(vector<T> a) { return *min_element(all(a)); }
template<class T> T min(vector<T> a, int n) { return *min_element(a.begin(), a.begin() + min(n, sz(a))); }
template<class T> T min(vector<T> a, int s, int n) { return *min_element(a.begin() + s, a.begin() + min(n, sz(a))); }
template<class T> T max(vector<T> a) { return *max_element(all(a)); }
template<class T> T max(vector<T> a, int n) { return *max_element(a.begin(), a.begin() + min(n, sz(a))); }
template<class T> T max(vector<T> a, int s, int n) { return *max_element(a.begin() + s, a.begin() + min(n, sz(a))); }
template<typename A, size_t N> A max(A (&a)[N]) {
    A res = a[0];
    rep(i, N)res = max(res, a[i]);
    return res;
}
template<typename A, size_t N, size_t O> A max(A (&a)[N][O]) {
    A res = max(a[0]);
    rep(i, N)res = max(res, max(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P> A max(A (&a)[N][O][P]) {
    A res = max(a[0]);
    rep(i, N)res = max(res, max(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q> A max(A (&a)[N][O][P][Q], const T &v) {
    A res = max(a[0]);
    rep(i, N)res = max(res, max(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R> A max(A (&a)[N][O][P][Q][R]) {
    A res = max(a[0]);
    rep(i, N)res = max(res, max(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S> A max(A (&a)[N][O][P][Q][R][S]) {
    A res = max(a[0]);
    rep(i, N)res = max(res, max(a[i]));
    return res;
}
template<typename A, size_t N> A min(A (&a)[N]) {
    A res = a[0];
    rep(i, N)res = min(res, a[i]);
    return res;
}
template<typename A, size_t N, size_t O> A min(A (&a)[N][O]) {
    A res = min(a[0]);
    rep(i, N)res = min(res, max(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P> A min(A (&a)[N][O][P]) {
    A res = min(a[0]);
    rep(i, N)res = min(res, min(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q> A min(A (&a)[N][O][P][Q], const T &v) {
    A res = min(a[0]);
    rep(i, N)res = min(res, min(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R> A min(A (&a)[N][O][P][Q][R]) {
    A res = min(a[0]);
    rep(i, N)res = min(res, min(a[i]));
    return res;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S> A min(A (&a)[N][O][P][Q][R][S]) {
    A res = min(a[0]);
    rep(i, N)res = min(res, min(a[i]));
    return res;
}


template<class T> T sum(vector<T> v, int len = -1) {
    if (len == -1)len = v.size();
    T res = 0;
    chmin(len, v.size());
    rep(i, len)res += v[i];
    return res;
}
template<class T> T sum(vector<vector<T>> &v, int h = -1, int w = -1) {
    if (h == -1)h = v.size();
    if (w == -1)w = v[0].size();
    T res = 0;
    chmin(h, v.size());
    chmin(w, v[0].size());
    rep(i, h)rep(j, w)res += v[i][j];
    return res;
}

P sump(vp &v, int len = -1) {
    if (len == -1)len = v.size();
    P res = {0, 0};
    chmin(len, v.size());
    rep(i, len) {
        res.fi += v[i].fi;
        res.se += v[i].se;
    }
    return res;
}



template<class T> T mul(vector<T> &v, int len = -1) {
    if (len == -1)len = v.size();
    T res = 1;
    chmin(len, v.size());
    rep(i, len)res *= v[i];
    return res;
}
void clear(PQ &q) { while (q.size())q.pop(); }
template<class T> void clear(queue<T> &q) { while (q.size())q.pop(); }
template<class T> T *negarr(int size) {
    T *body = (T *) malloc((size * 2 + 1) * sizeof(T));
    return body + size;
}
template<class T> T *id7(int h, int w) {
    double **dummy1 = new double *[2 * h + 1];
    double *dummy2 = new double[(2 * h + 1) * (2 * w + 1)];
    dummy1[0] = dummy2 + w;
    for (int i = 1; i <= 2 * h + 1; i++) {
        dummy1[i] = dummy1[i - 1] + 2 * w + 1;
    }
    double **a = dummy1 + h;
}




template<class T> vector<T> imo(vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];
    return ret;
}
template<class T> vector<T> imomi(vector<T> &v) {
    vector<T> ret = v;
    rep(i, sz(ret) - 1)chmin(ret[i + 1], ret[i]);
    return ret;
}
template<class T> struct ruiC {
    const vector<T> rui;
    ruiC(vector<T> &ru) : rui(ru) {}
    T operator()(int l, int r) {
        assert(l <= r);
        return rui[r] - rui[l];
    }
    T operator[](int i) {
        return rui[i];
    }
};

template<class T> struct id5 {
    const T *rrui;
    id5(T *ru) : rrui(ru) {}
    

    T operator()(int l, int r) {
        assert(l >= r);
        return rrui[r] - rrui[l];
    }
    T operator[](int i) {
        return rrui[i];
    }
};
template<class T> vector<T> ruiv(vector<T> &a) {
    vector<T> ret(a.size() + 1);
    rep(i, a.size())ret[i + 1] = ret[i] + a[i];
    return ret;
}
template<class T> ruiC<T> ruic(vector<T> &a) {
    vector<T> ret = ruiv(a);
    return ruiC<T>(ret);
}
template<class T> vector<T> ruim(vector<T> &a) {
    vector<T> res(a.size() + 1, 1);
    rep(i, a.size())res[i + 1] = res[i] * a[i];
    return res;
}




template<class T> id5<T> rrui(vector<T> &a) {
    int len = a.size();
    T *body = (T *) malloc((len + 1) * sizeof(T));
    T *res = body + 1;
    rer(i, len - 1)res[i - 1] = res[i] + a[i];
    return id5<T>(res);
}


template<class T> T *id19(vector<T> &a) {
    int len = a.size();
    T *body = (T *) malloc((len + 1) * sizeof(T));
    T *res = body + 1;
    res[len - 1] = 1;
    rer(i, len - 1)res[i - 1] = res[i] * a[i];
    return res;
}
template<class T, class U> void inc(T &a, U v = 1) { a += v; }
template<class T, class U> void inc(vector<T> &a, U v = 1) { for (auto &u :a)inc(u, v); }
template<class T> void inc(vector<T> &a) { for (auto &u :a)inc(u, 1); }
template<class T, class U> void plus(T &a, U v = 1) { a += v; }
template<class T, class U> void plus(vector<T> &a, U v = 1) { for (auto &u :a)inc(u, v); }
template<class T> void plus(vector<T> &a) { for (auto &u :a)inc(u, 1); }
template<class T, class U> void dec(T &a, U v = 1) { a -= v; }
template<class T, class U> void dec(vector<T> &a, U v = 1) { for (auto &u :a)dec(u, v); }
template<class T> void dec(vector<T> &a) { for (auto &u :a)dec(u, 1); }
template<class T, class U> void minu(T &a, U v = 1) { a -= v; }
template<class T, class U> void minu(vector<T> &a, U v = 1) { for (auto &u :a)dec(u, v); }
template<class T> void minu(vector<T> &a) { for (auto &u :a)dec(u, 1); }
inline bool inside(int h, int w, int H, int W) { return h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { return l <= v && v < r; }

ll u(ll a) { return a < 0 ? 0 : a; }
template<class T> vector<T> u(const vector<T> &a) {
    vector<T> ret = a;
    fora(v, ret)v = u(v);
    return ret;
}


ll goldd(ll left, ll right, function<ll(ll)> calc) {
    double GRATIO = 1.6180339887498948482045868343656;
    ll lm = left + (ll) ((right - left) / (GRATIO + 1.0));
    ll rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));
    ll fl = calc(lm);
    ll fr = calc(rm);
    while (right - left > 10) {
        if (fl < fr) {
            right = rm;
            rm = lm;
            fr = fl;
            lm = left + (ll) ((right - left) / (GRATIO + 1.0));
            fl = calc(lm);
        } else {
            left = lm;
            lm = rm;
            fl = fr;
            rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));
            fr = calc(rm);
        }
    }
    ll minScore = MAX(ll);
    ll resIndex = left;
    for (ll i = left; i < right + 1; i++) {
        ll score = calc(i);
        if (minScore > score) {
            minScore = score;
            resIndex = i;
        }
    }
    return resIndex;
}
ll goldt(ll left, ll right, function<ll(ll)> calc) {
    double GRATIO = 1.6180339887498948482045868343656;
    ll lm = left + (ll) ((right - left) / (GRATIO + 1.0));
    ll rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));
    ll fl = calc(lm);
    ll fr = calc(rm);
    while (right - left > 10) {
        if (fl > fr) {
            right = rm;
            rm = lm;
            fr = fl;
            lm = left + (ll) ((right - left) / (GRATIO + 1.0));
            fl = calc(lm);
        } else {
            left = lm;
            lm = rm;
            fl = fr;
            rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));
            fr = calc(rm);
        }
    }
    if (left > right) {
        ll l = left;
        left = right;
        right = l;
    }
    ll maxScore = MIN(ll);
    ll resIndex = left;
    for (ll i = left; i < right + 1; i++) {
        ll score = calc(i);
        if (maxScore < score) {
            maxScore = score;
            resIndex = i;
        }
    }
    return resIndex;
}
template<class T> T min(vector<vector<T>> &a) {
    T res = MAX(T);
    rep(i, a.size())chmin(res, *min_element(all(a[i])));
    return res;
}
template<class T> T max(vector<vector<T>> &a) {
    T res = MIN(T);
    rep(i, a.size())chmax(res, *max_element(all(a[i])));
    return res;
}

bool bget(ll m, int keta) { return (m >> keta) & 1; }
int bget(ll m, int keta, int sinsuu) {
    m /= (ll) pow(sinsuu, keta);
    return m % sinsuu;
}
inline ll bit(int n) { return (1LL << (n)); }
inline ll bit(int n, int sinsuu) { return (ll) pow(sinsuu, n); }





int lbit(int n) {
    return n & -n;
}


int hbit(int n) {
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    n |= (n >> 32);
    return n - (n >> 1);
}


ll nextComb(ll &mask, int n, int r) {
    if (!mask)return mask = (1LL << r) - 1;
    ll x = mask & -mask; 

    ll y = mask + x; 

    ll res = ((mask & ~y) / x >> 1) | y;
    if (bget(res, n))return mask = 0;
    else return mask = res;
}



vl id12(int n, int r) {
    vl res;
    int m = 0;
    while (nextComb(m, n, r)) {
        res.pb(m);
    }
    return res;
}


int id18(char c) {
    if ('A' <= c && c <= 'Z')return c - 'A';
    return c - 'a' + 26;
}
char id13(int i) {
    if (i < 26)return 'A' + i;
    return 'a' + i - 26;
}


int altoi(char c) {
    if ('A' <= c && c <= 'Z')return c - 'A';
    return c - 'a';
}
char itoal(int i) {
    return 'a' + i;
}
int ctoi(char c) { return c - '0'; }
char itoc(int i) { return i + '0'; }
int vtoi(vi &v) {
    int res = 0;
    if (sz(v) > 18) {
        debugline("vtoi");
        deb(sz(v));
        ole();
    }
    rep(i, sz(v)) {
        res *= 10;
        res += v[i];
    }
    return res;
}
vi itov(int i) {
    vi res;
    while (i) {
        res.pb(i % 10);
        i /= 10;
    }
    rev(res);
    return res;
}
vector<vector<int>> ctoi(vector<vector<char>> s, char c) {
    int n = sz(s), m = sz(s[0]);
    vector<vector<int>> res(n, vector<int>(m));
    rep(i, n)rep(j, m)res[i][j] = s[i][j] == c;
    return res;
}


void compress(vi &a) {
    vi b;
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        b.push_back(a[i]);
    }
    sort(b);
    UNIQUE(b);
    for (int i = 0; i < len; ++i) {
        a[i] = lower_bound(all(b), a[i]) - b.begin();
    }
}

void compress(int a[], int len) {
    vi b;
    for (int i = 0; i < len; ++i) {
        b.push_back(a[i]);
    }
    sort(b);
    UNIQUE(b);
    for (int i = 0; i < len; ++i) {
        a[i] = lower_bound(all(b), a[i]) - b.begin();
    }
}












template<class T> inline void fin(T s) { cout << s << endl, exit(0); }

template<class T> struct edge {
    int from, to;
    T cost;
    int id;
    int type;
    edge(int f, int t, T c = 1, int id = -1, int ty = -1) : from(f), to(t), cost(c), id(id), type(ty) {}
    bool operator<(const edge &b) const { return cost < b.cost; }
    bool operator>(const edge &b) const { return cost > b.cost; }
};

template<typename T> class graph {
protected:
    vector<bool> _used;
public :
    vector<vector<edge<T>>> g;
    vector<edge<T>> edges;
    int n;
    graph(int n) : n(n) { g.resize(n), _used.resize(n); }
    void clear() { g.clear(), edges.clear(); }
    void resize(int n) {
        this->n = n;
        g.resize(n);
        _used.resize(n);
    }
    int size() { return g.size(); }
    vector<edge<T> > &operator[](int i) { return g[i]; }
    virtual void add(int from, int to, T cost, int id, int ty) = 0;
    virtual bool used(edge<T> &e) = 0;
    virtual bool used(int id) = 0;
    virtual void del(edge<T> &e) = 0;
    virtual void del(int id) = 0;
};
template<typename T =ll> class digraph : public graph<T> {
public:
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::_used;

    digraph(int n) : graph<T>(n) {}
    void add(int f, int t, T cost = 1, int id = -1, int ty = -1) {
        if (!(0 <= f && f < n && 0 <= t && t < n)) {
            debugline("digraph add");
            deb(f, t, cost, id, ty);
            ole();
        }
        if (id == -1)id = edges.size();
        g[f].emplace_back(f, t, cost, id, ty);
        edges.emplace_back(f, t, cost, id, ty);
    }
    bool used(edge<T> &e) { return _used[e.id]; }
    bool used(int id) { return _used[id]; }
    void del(edge<T> &e) { _used[e.id] = _used[e.id ^ 1] = 1; }
    void del(int id) { _used[id] = _used[id ^ 1] = 1; }
};
template<class T=int> class undigraph : public graph<T> {
public:
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::_used;
    undigraph(int n) : graph<T>(n) {
    }
    void add(int f, int t, T cost = 1, int id = -1, int ty = -1) {
        if (!(0 <= f && f < n && 0 <= t && t < n)) {
            debugline("undigraph add");
            deb(f, t, cost, id, ty);
            ole();
        }
        if (id == -1)id = edges.size();
        g[f].emplace_back(f, t, cost, id, ty);
        g[t].emplace_back(t, f, cost, id + 1, ty);
        edges.emplace_back(f, t, cost, id, ty);
        edges.emplace_back(t, f, cost, id + 1, ty);
    }
    void add(edge<T> &e) {
        int f = e.from, t = e.to, ty = e.type;
        T cost = e.cost;
        add(f, t, cost, ty);
    }
    bool used(edge<T> &e) { return _used[e.id]; }
    bool used(int id) { return _used[id]; }
    void del(edge<T> &e) { _used[e.id] = _used[e.id ^ 1] = 1; }
    void del(int id) { _used[id] = _used[id ^ 1] = 1; }
};
template<class T> vector<T> dijkstra(const graph<T> &g, int s, int id16 = -1) {
    if (!(0 <= s && s < g.n)) {
        debugline("dijkstra");
        deb(s, g.n);
        ole();
    }
    T initValue = MAX(T);
    vector<T> dis(g.n, initValue);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    dis[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
        T nowc = q.top().fi;
        int i = q.top().se;
        q.pop();
        if (dis[i] != nowc)continue;
        for (auto &&e  : g.g[i]) {
            int to = e.to;
            T cost = nowc + e.cost;
            if (dis[to] > cost) {
                dis[to] = cost;
                q.emplace(dis[to], to);
            }
        }
    }
    

    if (id16 == -1)for (auto &&d :dis) if (d == initValue)d = -1;
    return dis;
}
template<class T> vector<vector<T>> warshall(const graph<T> &g, int id16 = -1) {
    int n = g.n;
    vector<vector<T> > dis(n, vector<T>(n, linf));
    fora(e, g.edges) chmin(dis[e.from][e.to], e.cost);
    rep(i, n)dis[i][i] = 0;
    rep(k, n)rep(i, n)rep(j, n)chmin(dis[i][j], dis[i][k] + dis[k][j]);
    

    if (id16 == -1)rep(i, n)rep(j, n) if (dis[i][j] == linf)dis[i][j] = -1;
    return dis;
}

template<class T=int> class tree : public undigraph<T> {
public:
    using undigraph<T>::g;
    using undigraph<T>::n;
    using undigraph<T>::edges;
    using undigraph<T>::_used;
    vi dep;
    vi disv;
private:
    bool never = 1;
    int root = -1;
    vector<vector<int>> par;
    bool id15;
    void dfs(int v, int p, int d) {
        dep[v] = d;
        par[0][v] = p;
        int lim = (*this)[v].size();
        for (int i = 0; i < lim; i++) {
            int t = g[v][i].to;
            if (t == p)con;
            dfs(t, v, d + 1);
        }
    }
    void built() {
        never = 0;
        n = g.size();
        par.assign(30, vi(n));
        dep.resize(n);
        id15 = 1;
        fora(e, edges)if (e.cost != 1)id15 = 0;
        dfs(root, -1, 0);
        rep(k, par.size() - 1) {
            rep(i, n) {
                if (par[k][i] == -1)par[k + 1][i] = -1;
                else par[k + 1][i] = par[k][par[k][i]];
            }
        }
        if (id15)disv = dep;
        else disv = dijkstra(*this, root);
    }
    int _lca(int u, int v) {
        if (dep[u] > dep[v])swap(u, v);
        rep(k, par.size()) {
            if ((dep[u] - dep[v]) >> k & 1) {
                v = par[k][v];
            }
        }
        if (u == v)return u;
        rer(k, par.size() - 1) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }
    int _dis(int u, int v) {
        int p = _lca(u, v);
        return disv[u] + disv[v] - disv[p] * 2;
    }
public:
    tree(int n, int root = 0) : undigraph<T>(n), root(root) {}
    bool leaf(int v) {
        return sz(g[v]) == 1 && v != root;
    }
    int dis(int u, int v) {
        if (never) {
            built();
        }
        return _dis(u, v);
    }
    int lca(int u, int v) {
        if (never) {
            built();
        }
        return _lca(u, v);
    }
};











template<class T=int> class id10 : public undigraph<T> {
public:
    using undigraph<T>::g;
    using undigraph<T>::n;
    using undigraph<T>::edges;
    using undigraph<T>::_used;
    int H, W;
    int eid = 0;
    void add(int f, int t, T cost = 1, int id = -1, int ty = -1) {
        if (!(0 <= f && f < n && 0 <= t && t < n)) {
            debugline("id10 add");
            deb(f, t, cost, id, ty);
            ole();
        }
        g[f].emplace_back(f, t, cost, eid++, ty);
        g[t].emplace_back(t, f, cost, eid++, ty);
    }
    int getid(int h, int w) {
        if (!inside(h, w, H, W))return -1;
        return W * h + w;
    }
    P get2(int id) {
        return mp(id / W, id % W);
    }
    P operator()(int id) {
        return get2(id);
    }
    int operator()(int h, int w) {
        return getid(h, w);
    }
    id10(int H, int W) : H(H), W(W), undigraph<T>(H * W) {
        rep(h, H) {
            rep(w, W) {
                int f = getid(h, w);
                if (w + 1 < W) add(f, getid(h, w + 1));
                if (h + 1 < H)add(f, getid(h + 1, w));
            }
        }
    }
    id10(_vvc ba, char wall = '
        rep(h, H) {
            rep(w, W) {
                if (ba[h][w] == wall)con;
                int f = getid(h, w);
                if (w + 1 < W && ba[h][w + 1] != wall) {
                    add(f, getid(h, w + 1));
                }
                if (h + 1 < H && ba[h + 1][w] != wall) {
                    add(f, getid(h + 1, w));
                }
            }
        }
    }
    void add(int fh, int fw, int th, int tw) {
        add(getid(fh, fw), getid(th, tw));
    }
};


template<class T=int> class id4 : public digraph<T> {
public:
    using digraph<T>::g;
    using digraph<T>::n;
    using digraph<T>::edges;
    using digraph<T>::_used;
    int H, W;
    int eid = 0;
    void add(int f, int t, T cost = 1, int id = -1, int ty = -1) {
        if (!(0 <= f && f < n && 0 <= t && t < n)) {
            debugline("id4 add");
            deb(f, t, cost, id, ty);
            ole();
        }
        g[f].emplace_back(f, t, cost, eid++, ty);
    }
    int getid(int h, int w) {
        if (!inside(h, w, H, W))return -1;
        return W * h + w;
    }
    P get2(int id) {
        return mp(id / W, id % W);
    }
    P operator()(int id) {
        return get2(id);
    }
    int operator()(int h, int w) {
        return getid(h, w);
    }
    id4(int H, int W) : H(H), W(W), digraph<T>(H * W) {
        rep(h, H) {
            rep(w, W) {
                int f = getid(h, w);
                if (w + 1 < W) add(f, getid(h, w + 1));
                if (h + 1 < H)add(f, getid(h + 1, w));
            }
        }
    }
    id4(_vvc ba, char wall = '
        rep(h, H) {
            rep(w, W) {
                if (ba[h][w] == wall)con;
                int f = getid(h, w);
                if (w + 1 < W && ba[h][w + 1] != wall) {
                    add(f, getid(h, w + 1));
                }
                if (h + 1 < H && ba[h + 1][w] != wall) {
                    add(f, getid(h + 1, w));
                }
            }
        }
    }
    void add(int fh, int fw, int th, int tw) {
        add(getid(fh, fw), getid(th, tw));
    }
};
template<class T> bool nibu(const graph<T> &g) {
    if (g.edges.size() == 0)return true;
    UnionFind uf(g.n * 2);
    for (auto &&e :g.edges)uf.unite(e.from, e.to + g.n), uf.unite(e.from + g.n, e.to);
    rep(i, g.n)if (uf.same(i, i + g.n))return 0;
    return 1;
}


template<class T> vp id20(graph<T> &g) {
    vp cg;
    if (!nibu(g)) {
        debugline("nibu");
        ole();
    }
    int _n = g.size();
    vb _was(_n);
    queue<P> q;
    rep(i, _n) {
        if (_was[i])continue;
        q.push(mp(i, 1));
        _was[i] = 1;
        int red = 0;
        int coun = 0;
        while (q.size()) {
            int now = q.front().fi;
            int col = q.front().se;
            red += col;
            coun++;
            q.pop();
            forg(gi, g[now]) {
                if (_was[t])continue;
                q.push(mp(t, col ^ 1));
                _was[t] = 1;
            }
        }
        cg.push_back(mp(red, coun - red));
    }
    return cg;

}




vp vtop(vi &a, vi &b) {
    vp res(sz(a));
    rep(i, sz(a))res[i] = mp(a[i], b[i]);
    return res;
}
void ptov(vp &p, vi &a, vi &b) {
    a.resize(sz(p));
    b.resize(sz(p));
    rep(i, sz(p))a[i] = p[i].fi, b[i] = p[i].se;
}
template<typename _CharT, typename _Traits, typename _Alloc>
basic_string<_CharT, _Traits, _Alloc>
operator+(const basic_string<_CharT, _Traits, _Alloc> &__lhs, const int __rv) {
    basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
    __str.append(to_string(__rv));
    return __str;
}
template<typename _CharT, typename _Traits, typename _Alloc>
void operator+=(basic_string<_CharT, _Traits, _Alloc> &__lhs, const int __rv) {
    __lhs += to_string(__rv);
}
template<typename _CharT, typename _Traits, typename _Alloc>
basic_string<_CharT, _Traits, _Alloc>
operator+(const basic_string<_CharT, _Traits, _Alloc> &__lhs, const signed __rv) {
    basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
    __str.append(to_string(__rv));
    return __str;
}
template<typename _CharT, typename _Traits, typename _Alloc>
void operator+=(basic_string<_CharT, _Traits, _Alloc> &__lhs, const signed __rv) {
    __lhs += to_string(__rv);
}
template<class T, class U> void operator+=(queue<T> &a, U v) {
    a.push(v);
}
template<class T, class U>
priority_queue<T, vector<T>, greater<T> > &operator+=(priority_queue<T, vector<T>, greater<T> > &a, U v) {
    a.push(v);
    return a;
}
template<class T, class U> priority_queue<T> &operator+=(priority_queue<T> &a, U v) {
    a.push(v);
    return a;
}
template<class T, class U> set<T> &operator+=(set<T> &a, U v) {
    a.insert(v);
    return a;
}
template<class T, class U> set<T, greater<T>> &operator+=(set<T, greater<T>> &a, U v) {
    a.insert(v);
    return a;
}
template<class T, class U> vector<T> &operator+=(vector<T> &a, U v) {
    a.pb(v);
    return a;
}
template<class T, class U> vector<T> operator+(const vector <T> &a, U v) {
    vector<T> ret = a;
    ret += v;
    return ret;
}
template<class T, class U> vector<T> operator+(U v, const vector <T> &a) {
    vector<T> ret = a;
    ret.insert(ret.begin(), v);
    return ret;
}
template<class T> vector<T> &operator+=(vector<T> &a, vector <T> &b) {
    fora(v, b)a += v;
    return a;
}
template<class T, class U> vector<T> &operator+=(vector<T> &a, initializer_list<U> v) {
    for (auto &&va :v)a.pb(va);
    return a;
}
template<class T> vector<T> &operator-=(vector<T> &a, vector <T> &b) {
    if (sz(a) != sz(b)) {
        debugline("vector<T> operator-=");
        deb(a);
        deb(b);
        ole();
    }
    rep(i, sz(a))a[i] -= b[i];
    return a;
}
template<class T> vector<T> operator-(vector<T> &a, vector <T> &b) {
    if (sz(a) != sz(b)) {
        debugline("vector<T> operator-");
        deb(a);
        deb(b);
        ole();
    }
    vector<T> res(sz(a));
    rep(i, sz(a))res[i] = a[i] - b[i];
    return res;
}


template<typename T> void remove(vector<T> &v, unsigned int i) { v.erase(v.begin() + i); }
template<typename T> void remove(vector<T> &v, unsigned int s, unsigned int e) {
    v.erase(v.begin() + s, v.begin() + e);
}
template<typename T> void removen(vector<T> &v, unsigned int s, unsigned int n) {
    v.erase(v.begin() + s, v.begin() + s + n);
}
template<typename T> void erase(vector<T> &v, unsigned int i) { v.erase(v.begin() + i); }
template<typename T> void erase(vector<T> &v, unsigned int s, unsigned int e) {
    v.erase(v.begin() + s, v.begin() + e);
}
template<typename T> void erasen(vector<T> &v, unsigned int s, unsigned int n) {
    v.erase(v.begin() + s, v.begin() + s + n);
}
template<typename T, typename U> void insert(vector<T> &v, unsigned int i, U t) { v.insert(v.begin() + i, t); }
template<typename T, typename U> void push_front(vector<T> &v, U t) { v.insert(v.begin(), t); }
template<typename T, typename U> void insert(vector<T> &v, unsigned int i, vector<T> list) {
    for (auto &&va :list)v.insert(v.begin() + i++, va);
}
template<typename T, typename U> void insert(vector<T> &v, initializer_list<U> list) {
    for (auto &&va :list)v.pb(va);
}
template<typename T, typename U> void insert(vector<T> &v, unsigned int i, initializer_list<U> list) {
    for (auto &&va :list)v.insert(v.begin() + i++, va);
}
template<typename T> void insert(set<T> &v, vector<T> list) {
    for (auto &&va :list)v.insert(va);
}
template<typename T> void insert(set<T> &v, initializer_list<T> list) {
    for (auto &&va :list)v.insert(va);
}




bool topo(vi &res, digraph<int> &g) {
    int n = g.g.size();
    vi nyu(n);
    rep(i, n)for (auto &&e :g[i])nyu[e.to]++;
    queue<int> st;
    rep(i, n)if (nyu[i] == 0)st.push(i);
    while (st.size()) {
        int v = st.front();
        st.pop();
        res.pb(v);
        fora(e, g[v]) if (--nyu[e.to] == 0)st.push(e.to);
    }
    return res.size() == n;
}


bool topos(vi &res, digraph<int> &g) {
    int n = g.g.size();
    vi nyu(n);
    rep(i, n)for (auto &&e :g[i])nyu[e.to]++;
    

    priority_queue<int, vector<int>, greater<int> > q;
    rep(i, n)if (nyu[i] == 0)q.push(i);
    while (q.size()) {
        int i = q.top();
        q.pop();
        res.pb(i);
        fora(e, g[i])if (--nyu[e.to] == 0)q.push(e.to);
    }
    return res.size() == n;
}
vector<string> split(const string a, const char deli) {
    string b = a + deli;
    int l = 0, r = 0, n = b.size();
    vector<string> res;
    rep(i, n) {
        if (b[i] == deli) {
            r = i;
            if (l < r)res.push_back(b.substr(l, r - l));
            l = i + 1;
        }
    }
    return res;
}
vector<string> split(const string a, const string deli) {
    string b = a + deli;
    int l = 0, r = 0, n = b.size(), dn = deli.size();
    vector<string> res;
    rep(i, n) {
        if (i + dn <= n && b.substr(i, i + dn) == deli) {
            r = i;
            if (l < r)res.push_back(b.substr(l, r - l));
            i += dn - 1;
            l = i + 1;
        }
    }
    return res;
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

int n, m, k, d, H, W, x, y, z, q;
int cou;
vi a, b, c;
vvi (s, 0, 0);
vvc (ba, 0, 0);
vp p;
undigraph<> g(2 * k5);
_vvi fa(k5*2);
umapi dp[k5 * 2];

void solve() {
    cin >> n;
    na(a, n);
    rep(i, n - 1) {
        int f, t;
        cin >> f >> t;
        --f, --t;
        g.add(f, t);
    }
    rep(i, n)fa[i] = factorization(a[i]);

    function<void(int, int)> ds = [&](int i, int p) {
        fora(v, fa[i]){
            dp[i][v] = 1;
            chma(dp[i][v]);
        }
        fort(gi, g[i]) {
                ds(t, i);
                fora(f, fa[i]) {
                    chma(dp[i][f] + dp[t][f]);
                    chma(dp[i][f], dp[t][f] + 1);
                }
            }
    };
    ds(0, -1);
    chma(0);
    cout << ma << endl;
}
int my(int n, vi a) {
    return 0;
}
int sister(int n, vi a) {
    return 0;
}

signed main() {
    solve();


    

    

    

    


    bool bad = 0;
    for (int i = 0, ok = 1; i < k5 && ok; i++) {
        int n = rand(1, 3);
        vi a = ranv(m, 1, 10);
        int myres = my(_arg);
        int res = sister(_arg);
        ok = myres == res;
        if (!ok) {
            cout << n << endl;
            cout << a << endl;
            cout << "正解 : " << res << endl;
            cout << "出力 : " << myres << endl;
            bad = 1;
            break;
        }
    }


    return 0;
};
