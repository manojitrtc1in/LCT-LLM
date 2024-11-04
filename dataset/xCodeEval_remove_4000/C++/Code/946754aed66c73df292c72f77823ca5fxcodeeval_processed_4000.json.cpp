


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
template<class U> inline void id10(vector<U> &a, vector<U> &b) {
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
template<class U, class F> inline void id10(vector<U> &a, vector<U> &b, F f) {
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
template<class U, class F> inline void id6(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
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
template<class T> inline void id4(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
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
template<class T> string id15(vector<T> &a, ll W = inf) {
    stringstream ss;
    if (W == inf)W = min(sz(a), 12ll);
    if (sz(a) == 0)return ss.str();
    rep(i, W) { ss << a[i] << " "; }
    return ss.str();
}
template<class T> string id15(vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {
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

template<class T> string id15(vector<vector<vector<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {stringstream ss;    if (H == inf)H = 5;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << id15(a[i], W, U, i);    }       return ss.str();}
string id15(int a) {stringstream ss;ss << a;return ss.str();}
template<class T> string id15(T &a) {stringstream ss;ss << a;return ss.str();}

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
void id11(bool a) {
    if (a)cout << "id11" << endl;
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
vp run_length(vi &a) {    vp ret;    ret.eb(a[0], 1);    rep(i, 1, sz(a)) { if (ret.back().fi == a[i]) { ret.back().se++; } else { ret.eb(a[i], 1); }}    return ret;}
vector<pair<char, ll>> run_length(string &a) {    vector<pair<char, ll>> ret;    ret.eb(a[0], 1);    rep(i, 1, sz(a)) { if (ret.back().fi == a[i]) { ret.back().se++; } else { ret.eb(a[i], 1); }}    return ret;}

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










template<class T> vector<T> imo(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];    return ret;}


template<class T, class U> vi imo(vector<T> &a, U k) {vector<T> ret = a;rep(i, sz(ret))ret[i] = a[i] == k;rep(i, sz(ret) - 1)ret[i + 1] += ret[i];return ret;}
template<class T> vector<T> imox(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] ^= ret[i];    return ret;}


template<class T> vector<T> imi(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)chmi(ret[i + 1], ret[i]);    return ret;}
template<class T> struct ruiC {    const vector<T> rui;    ruiC(vector<T> &ru) : rui(ru) {}    T operator()(ll l, ll r) {        if (l > r) {            cerr<<"ruic ";deb(l, r);assert(0);        }        return rui[r] - rui[l];    }    T operator[](ll i) { return rui[i]; }    T back() { return rui.back(); }    ll size() { return rui.size(); }};
template<class T> struct id7 {    const T *rrui;    id7(T *ru) : rrui(ru) {}     T operator()(ll l, ll r) {        assert(l >= r);        return rrui[r] - rrui[l];    }     T operator[](ll i) { return rrui[i]; }};
template<class T>ostream &operator<<(ostream &os, ruiC<T> a) {fora(v,a.rui)os<<v<<" ";return os;}
template<class T> vector<T> ruiv(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    return ret;}
template<class T> ruiC<T> ruic(vector<T> &a) {    vector<T> ret = ruiv(a);    return ruiC<T>(ret);}
vector<ll> ruiv(string &a) {    if (sz(a) == 0)return vi(1);    ll dec = ('0' <= a[0] && a[0] <= '9') ? '0' : 0;    vector<ll> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i] - dec;    return ret;}
ruiC<ll> ruic(string &a) {    vector<ll> ret = ruiv(a);    return ruiC<ll>(ret);}


template<class T, class U> vi ruiv(T &a, U k) {    vi ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + (a[i] == k);    return ret;}
template<class T, class U> ruiC<ll> ruic(T &a, U k) {    vi ret = ruiv(a, k);    return ruiC<ll>(ret);}


template<class T> struct id8 {    const vector<T> rui;    id8(vector<T> &ru) : rui(ru) {}    T operator()(ll l, ll r) {        if (l > r) {            cerr << "ruiXc ";            deb(l, r);            assert(0);        }        return rui[r] ^ rui[l];    }    T operator[](ll i) { return rui[i]; }    T back() { return rui.back(); }    ll size() { return rui.size(); }};
template<class T> vector<T> ruix(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] ^ a[i];    return ret;}
template<class T> id8<ll> id12(vector<T>  &a) {vi ret = ruix(a);return id8<ll>(ret);}
template<class T> vector<T> ruim(vector<T> &a) {    vector<T> res(a.size() + 1, 1);    rep(i, a.size())res[i + 1] = res[i] * a[i];    return res;}


template<class T> vector<T> ruimi(vector<T> &a) {    ll n = sz(a);    vector<T> ret(n + 1);    rep(i, 1, n) {        ret[i] = a[i - 1];        chmi(ret[i + 1], ret[i]);    }    return ret;}




template<class T> id7<T> rrui(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    rer(i, len - 1)res[i - 1] = res[i] + a[i];    return id7<T>(res);}


template<class T> T *id17(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    res[len - 1] = 1;    rer(i, len - 1)res[i - 1] = res[i] * a[i];    return res;}





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

template<typename W, typename H> void resize(vector<W> &vec, const H head) { vec.resize(head); }template<typename W, typename H, typename ... T> void resize(vector<W> &vec, const H &head, const T ... tail) {vec.resize(head);for (auto &v: vec)resize(v, tail...);}
template<typename T, typename F> bool id0(T &v, F f) { return f(v); }
template<typename T, typename F> bool id0(vector<T> &v, F f) {    rep(i, sz(v)) { if (!id0(v[i], f))return false; }    return true;}
template<typename T, typename F> bool id13(T &v, F f) { return f(v); }
template<typename T, typename F> bool id13(vector<T> &v, F f) {    rep(i, sz(v)) { if (id13(v[i], f))return true; }    return false;}
template<typename T, typename F> bool id2(T &v, F f) { return f(v); }
template<typename T, typename F> bool id2(vector<T> &v, F f) {    rep(i, sz(v)) { if (id2(v[i], f))return false; }    return true;}
template<typename T, typename F> bool id1(T &v, F f) { return f(v); }
template<typename T, typename F> ll id1(vector<T> &v, F f) {    rep(i, sz(v)) { if (id1(v[i], f))return i; }    return sz(v);}
template<typename T, typename F> bool id3(T &v, F f) { return f(v); }
template<typename T, typename F> ll id3(vector<T> &v, F f) {    rer(i, sz(v) - 1) { if (id3(v[i], f))return i; }    return -1;}
template<class T> bool contains(string &s, const T &v) { return s.find(v) != string::npos; }
template<typename T> bool contains(vector<T> &v, const T &val) { return std::find(v.begin(), v.end(), val) != v.end(); }
template<typename T, typename F> bool id16(vector<T> &v, F f) { return find_if(v.begin(), v.end(), f) != v.end(); }
template<typename T, typename F> ll id18(T &v, F f) { return f(v); }
template<typename T, typename F> ll id18(vector<T> &vec, F f) {    ll ret = 0;    fora(v, vec)ret += id18(v, f);    return ret;}
template<typename T, typename F> void id5(T &v, F f) { f(v); }
template<typename T, typename F> void id5(vector<T> &vec, F f) { fora(v, vec)id5(v, f); }
template<typename W> ll count_od(vector<W> &a) {return id18(a,[](ll v){return v&1 ;});}
template<typename W> ll count_ev(vector<W> &a) {return id18(a,[](ll v){return !(v&1) ;});}


template<typename T, typename F> int id9(vector<T> &v, F f) {vector<T> nv;int cou = 0;rep(i, sz(v)) {if (f(v[i])) {cou++;} else {nv.push_back(v[i]);}}v = nv;return cou;}
template<typename T, typename F> int id9(vector<vector<T>> &v, F f) {int cou = 0;rep(i, sz(v)) {cou += id9(v[i], f);}return cou;}





















int N, K, H, W;
vi A, B, C;


signed main() {
    din(Q);
    while (Q--) {
        in(N);
        vi A, V;
        na2(A, V, N);
        sortp(A, V, fisd);
        

        vvi(dp, N + 1, N + 1, linf);
        dp[N][0] = 0;
        rer(i, N - 1) {
            rep(j, N + 1) {
                int a = A[i], v = V[i];
                

                if (i + j >= a) {
                    chmi(dp[i][j], dp[i + 1][j]);
                }
                

                if (j + 1 <= N) {
                    chmi(dp[i][j + 1], dp[i + 1][j] + v);
                }
            }
        }
        cout << min(dp[0 ]) << endl;
    }

}