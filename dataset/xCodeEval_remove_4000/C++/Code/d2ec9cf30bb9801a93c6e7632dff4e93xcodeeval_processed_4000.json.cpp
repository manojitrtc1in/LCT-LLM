


using namespace std;


struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} id18;



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
template<class U> inline void id11(vector<U> &a, vector<U> &b) {
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
template<class U, class F> inline void id11(vector<U> &a, vector<U> &b, F f) {
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
template<class U, class F> inline void id7(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
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
template<class T> inline void id5(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
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
template<class T> string id20(vector<T> &a, ll W = inf) {
    stringstream ss;
    if (W == inf)W = min(sz(a), 12ll);
    if (sz(a) == 0)return ss.str();
    rep(i, W) { ss << a[i] << " "; }
    return ss.str();
}
template<class T> string id20(vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {
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

template<class T> string id20(vector<vector<vector<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {stringstream ss;    if (H == inf)H = 5;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << id20(a[i], W, U, i);    }       return ss.str();}
string id20(int a) {stringstream ss;ss << a;return ss.str();}
template<class T> string id20(T &a) {stringstream ss;ss << a;return ss.str();}

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
void id12(bool a) {
    if (a)cout << "id12" << endl;
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
template<class T> struct id8 {    const T *rrui;    id8(T *ru) : rrui(ru) {}     T operator()(ll l, ll r) {        assert(l >= r);        return rrui[r] - rrui[l];    }     T operator[](ll i) { return rrui[i]; }};
template<class T>ostream &operator<<(ostream &os, ruiC<T> a) {fora(v,a.rui)os<<v<<" ";return os;}
template<class T> vector<T> ruiv(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    return ret;}
template<class T> ruiC<T> ruic(vector<T> &a) {    vector<T> ret = ruiv(a);    return ruiC<T>(ret);}
vector<ll> ruiv(string &a) {    if (sz(a) == 0)return vi(1);    ll dec = ('0' <= a[0] && a[0] <= '9') ? '0' : 0;    vector<ll> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i] - dec;    return ret;}
ruiC<ll> ruic(string &a) {    vector<ll> ret = ruiv(a);    return ruiC<ll>(ret);}


template<class T, class U> vi ruiv(T &a, U k) {    vi ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + (a[i] == k);    return ret;}
template<class T, class U> ruiC<ll> ruic(T &a, U k) {    vi ret = ruiv(a, k);    return ruiC<ll>(ret);}


template<class T> struct id9 {    const vector<T> rui;    id9(vector<T> &ru) : rui(ru) {}    T operator()(ll l, ll r) {        if (l > r) {            cerr << "ruiXc ";            deb(l, r);            assert(0);        }        return rui[r] ^ rui[l];    }    T operator[](ll i) { return rui[i]; }    T back() { return rui.back(); }    ll size() { return rui.size(); }};
template<class T> vector<T> ruix(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] ^ a[i];    return ret;}
template<class T> id9<ll> id13(vector<T>  &a) {vi ret = ruix(a);return id9<ll>(ret);}
template<class T> vector<T> ruim(vector<T> &a) {    vector<T> res(a.size() + 1, 1);    rep(i, a.size())res[i + 1] = res[i] * a[i];    return res;}


template<class T> vector<T> ruimi(vector<T> &a) {    ll n = sz(a);    vector<T> ret(n + 1);    rep(i, 1, n) {        ret[i] = a[i - 1];        chmi(ret[i + 1], ret[i]);    }    return ret;}




template<class T> id8<T> rrui(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    rer(i, len - 1)res[i - 1] = res[i] + a[i];    return id8<T>(res);}


template<class T> T *id22(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    res[len - 1] = 1;    rer(i, len - 1)res[i - 1] = res[i] * a[i];    return res;}





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
template<typename T, typename F> bool id1(T &v, F f) { return f(v); }
template<typename T, typename F> bool id1(vector<T> &v, F f) {    rep(i, sz(v)) { if (!id1(v[i], f))return false; }    return true;}
template<typename T, typename F> bool id17(T &v, F f) { return f(v); }
template<typename T, typename F> bool id17(vector<T> &v, F f) {    rep(i, sz(v)) { if (id17(v[i], f))return true; }    return false;}
template<typename T, typename F> bool id3(T &v, F f) { return f(v); }
template<typename T, typename F> bool id3(vector<T> &v, F f) {    rep(i, sz(v)) { if (id3(v[i], f))return false; }    return true;}
template<typename T, typename F> bool id2(T &v, F f) { return f(v); }
template<typename T, typename F> ll id2(vector<T> &v, F f) {    rep(i, sz(v)) { if (id2(v[i], f))return i; }    return sz(v);}
template<typename T, typename F> bool id4(T &v, F f) { return f(v); }
template<typename T, typename F> ll id4(vector<T> &v, F f) {    rer(i, sz(v) - 1) { if (id4(v[i], f))return i; }    return -1;}
template<class T> bool contains(string &s, const T &v) { return s.find(v) != string::npos; }
template<typename T> bool contains(vector<T> &v, const T &val) { return std::find(v.begin(), v.end(), val) != v.end(); }
template<typename T, typename F> bool id21(vector<T> &v, F f) { return find_if(v.begin(), v.end(), f) != v.end(); }
template<typename T, typename F> ll id23(T &v, F f) { return f(v); }
template<typename T, typename F> ll id23(vector<T> &vec, F f) {    ll ret = 0;    fora(v, vec)ret += id23(v, f);    return ret;}
template<typename T, typename F> void id6(T &v, F f) { f(v); }
template<typename T, typename F> void id6(vector<T> &vec, F f) { fora(v, vec)id6(v, f); }
template<typename W> ll count_od(vector<W> &a) {return id23(a,[](ll v){return v&1 ;});}
template<typename W> ll count_ev(vector<W> &a) {return id23(a,[](ll v){return !(v&1) ;});}


template<typename T, typename F> int id10(vector<T> &v, F f) {vector<T> nv;int cou = 0;rep(i, sz(v)) {if (f(v[i])) {cou++;} else {nv.push_back(v[i]);}}v = nv;return cou;}
template<typename T, typename F> int id10(vector<vector<T>> &v, F f) {int cou = 0;rep(i, sz(v)) {cou += id10(v[i], f);}return cou;}





















int N, K, H, W;
vi A, B, C;

namespace pnumber_tools {

    class Eratosthenes { public:virtual void initialize() {} virtual void generate(const int64_t x) = 0; virtual void generate(const int64_t from, const int64_t to) = 0; virtual int64_t count() = 0; virtual bool prime(int x) = 0; virtual int32_t version() = 0; inline uint64_t PopCnt(uint64_t); inline int BitToIndex(uint8_t); };    uint64_t Eratosthenes::PopCnt(uint64_t bits) {        bits = (bits & 0x5555555555555555ULL) + ((bits >> 1) & 0x5555555555555555ULL);        bits = (bits & 0x3333333333333333ULL) + ((bits >> 2) & 0x3333333333333333ULL);        bits = (bits & 0x0f0f0f0f0f0f0f0fULL) + ((bits >> 4) & 0x0f0f0f0f0f0f0f0fULL);        return (bits * 0x0101010101010101ULL) >> (64 - 8);    }    int Eratosthenes::BitToIndex(uint8_t b) {        switch (b) {            case 1 << 0:                return 0;            case 1 << 1:                return 1;            case 1 << 2:                return 2;            case 1 << 3:                return 3;            case 1 << 4:                return 4;            case 1 << 5:                return 5;            case 1 << 6:                return 6;            case 1 << 7:                return 7;        }        return -1;    }    namespace {        constexpr uint64_t id14 = 1000000;        constexpr int32_t kMod30[] = {1, 7, 11, 13, 17, 19, 23, 29};        constexpr int C1[] = {6, 4, 2, 4, 2, 4, 6, 2};        constexpr int C0[][8] = {{0, 0, 0, 0, 0, 0, 0, 1},                             {1, 1, 1, 0, 1, 1, 1, 1},                             {2, 2, 0, 2, 0, 2, 2, 1},                             {3, 1, 1, 2, 1, 1, 3, 1},                             {3, 3, 1, 2, 1, 3, 3, 1},                             {4, 2, 2, 2, 2, 2, 4, 1},                             {5, 3, 1, 4, 1, 3, 5, 1},                             {6, 4, 2, 4, 2, 4, 6, 1},};        constexpr uint8_t kMask[][8] = {{0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f},                                    {0xfd, 0xdf, 0xef, 0xfe, 0x7f, 0xf7, 0xfb, 0xbf},                                    {0xfb, 0xef, 0xfe, 0xbf, 0xfd, 0x7f, 0xf7, 0xdf},                                    {0xf7, 0xfe, 0xbf, 0xdf, 0xfb, 0xfd, 0x7f, 0xef},                                    {0xef, 0x7f, 0xfd, 0xfb, 0xdf, 0xbf, 0xfe, 0xf7},                                    {0xdf, 0xf7, 0x7f, 0xfd, 0xbf, 0xfe, 0xef, 0xfb},                                    {0xbf, 0xfb, 0xf7, 0x7f, 0xfe, 0xef, 0xdf, 0xfd},                                    {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe},};        constexpr int64_t kSievedPrimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};        constexpr int64_t id16 = 7 * 11 * 13 * 17 * 19 * 23;        constexpr int imap[] = {-1, 0, -1, -1, -1, -1, -1, 1, -1, -1, -1, 2, -1, 3, -1, -1, -1, 4, -1, 5, -1, -1, -1, 6, -1, -1, -1, -1, -1, 7};        class Eratosthenes2 final                : public Eratosthenes {        public:            void generate(const int64_t x) override;            void generate(const int64_t, const int64_t) override { assert(false); }            bool prime(int x) override;            int64_t count() override;            int32_t version() override { return 2; }            std::vector<uint8_t> flags_;        };        void Eratosthenes2::generate(const int64_t x) {            flags_.clear();            if (x > 10000000000) return;            int64_t size = x / 30 + (x % 30 != 0);            flags_.resize(size, 0xff);            if (int r = x % 30) { if (r <= 1) flags_[size - 1] = 0x0; else if (r <= 7) flags_[size - 1] = 0x1; else if (r <= 11) flags_[size - 1] = 0x3; else if (r <= 13) flags_[size - 1] = 0x7; else if (r <= 17) flags_[size - 1] = 0xf; else if (r <= 19) flags_[size - 1] = 0x1f; else if (r <= 23) flags_[size - 1] = 0x3f; else if (r <= 29) flags_[size - 1] = 0x7f; }            flags_[0] = 0xfe;            const uint64_t sqrt_x = std::ceil(std::sqrt(x) + 0.1);            const uint64_t id15 = sqrt_x / 30 + 1;            for (uint64_t i = 0; i < id15; ++i) {                for (uint8_t flags = flags_[i]; flags; flags &= flags - 1) {                    uint8_t lsb = flags & (-flags);                    int ibit = BitToIndex(lsb);                    const int32_t m = kMod30[ibit];                    int32_t pm = 30 * i + 2 * m;                    for (uint64_t j = i * pm + (m * m) / 30, k = ibit; j < flags_.size(); j += i * C1[k] + C0[ibit][k], k = (k + 1) & 7) { flags_[j] &= kMask[ibit][k]; }                }            }        }        int64_t Eratosthenes2::count() {            if (flags_.empty()) return -1;            int64_t ret = 3;            for (uint8_t f : flags_) { ret += PopCnt(f); }            return ret;        }        inline bool Eratosthenes2::prime(int x) {            if (x == 2 || x == 3 || x == 5)return true; else if (!(x & 1) || x % 3 == 0 || x % 5 == 0)return false;            return (flags_[x / 30] >> imap[x % 30]) & 1;        }    }
    Eratosthenes2 era;
    int prime_len = 3e6;
    vector<int> primes;
    void setprime(int size = 3e6) {        prime_len = size;        era.generate(size);        primes = {2, 3, 5};        int nums[129] = {};        nums[1] = 1;        nums[2] = 7;        nums[4] = 11;        nums[8] = 13;        nums[16] = 17;        nums[32] = 19;        nums[64] = 23;        nums[128] = 29;                int j = 0;        int id19 = era.flags_.size();        int i30 = 0;        for (int i = 0; i < id19; i++, i30 += 30) {            uint8_t m = era.flags_[i];            while (m) {                j = m & -m;                primes.push_back(i30 + nums[j]);                m ^= j;            }        }    }
    using u32 = unsigned int;

    using u64 = unsigned long long;
    

    bool prime(const int &n) {        if (!sz(primes))setprime();                return era.prime(n);    }
    
    vi id0(int v) {        vi res;        dou lim = std::sqrt(v);        for (int i = 1; i <= lim; ++i) { if (v % i == 0) { res.push_back(i);            }}        rer(i, sz(res) - 1) { if (res[i] != v / res[i])res.push_back(v / res[i]); }        return res;    }
    vp factorization(int v) {        assert(v);        int tv = v;        vp res;        if (!sz(primes))setprime();        for (auto &&p :primes) {            if (v % p == 0)res.eb(p, 0);            while (v % p == 0) {                v /= p;                res.back().second++;            }            if (v == 1 || p * p > tv)break;        }        if (v > 1)res.eb(v, 1);        return res;    }
    

    

    

    struct dra { ll q, l, r, len; dra(ll q_, ll l_, ll r_) : q(q_), l(l_), r(r_), len(r_ - l_) {}};
    vector<dra> drange(ll n, ll l = 1, ll r = -1) {        if (r == -1)r = n + 1;        vector<dra> res;        for (ll x = l; x < r;) {            ll divisor = n / x;            ll e;            if (divisor == 0) { e = r; } else { e = min(r, n / divisor + 1); }            res.emplace_back(divisor, x, e);            x = e;        }        return res;    };
}
using namespace pnumber_tools;


signed main() {
    map<vp, int> S;
    din(N, K);
    int cou = 0;
    na(A, N);
    rep(i, N) {
        vp key = factorization(A[i]);
        fora(p, key)p.se %= K;
        vp need = key;
        fora(p, need)p.se = K - p.se;
        erase_if(key, .se %K ==0);
        erase_if(need, .se %K ==0);
        cou += S[need];
        S[key]++;
    }
    cout << cou << endl;
}