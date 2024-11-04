

#include <bits/stdc++.h>
using namespace std;


struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} __initon;


#define ws ___ws
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
#define int long long
#define ll long long
#define double long double
#define pow powl
#define ull unsigned long long
using dou = double;
using itn = int;
using str = string;
using bo= bool;
#define au auto
using P = pair<ll, ll>;

#define fi first
#define se second
#define vec vector
#define beg begin
#define rbeg rbegin
#define con continue
#define bre break
#define brk break
#define is ==








using vi = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vc = vector<char>;
using vp = vector<P>;
using vt = vector<T>;

#define vec vector
#define o_vvt(o1, o2, o3, o4, name, ...) name
#define vvt0(t) vec<vec<t>>
#define vvt1(t, a) vec<vec<t>>a
#define vvt2(t, a, b) vec<vec<t>>a(b)
#define vvt3(t, a, b, c) vec<vec<t>> a(b,vec<t>(c))
#define vvt4(t, a, b, c, d) vec<vec<t>> a(b,vec<t>(c,d))

#define vvi(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(ll,__VA_ARGS__)
#define vvb(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(bool,__VA_ARGS__)
#define vvs(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(string,__VA_ARGS__)
#define vvd(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(double,__VA_ARGS__)
#define vvc(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(char,__VA_ARGS__)
#define vvp(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(P,__VA_ARGS__)
#define vvt(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(T,__VA_ARGS__)

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }
#define vni(name, ...) auto name = make_v<ll>(__VA_ARGS__)
#define vnb(name, ...) auto name = make_v<bool>(__VA_ARGS__)
#define vns(name, ...) auto name = make_v<string>(__VA_ARGS__)
#define vnd(name, ...) auto name = make_v<double>(__VA_ARGS__)
#define vnc(name, ...) auto name = make_v<char>(__VA_ARGS__)
#define vnp(name, ...) auto name = make_v<P>(__VA_ARGS__)

#define v3i(a, b, c, d) vector<vector<vi>> a(b, vector<vi>(c, vi(d)))
#define v3d(a, b, c, d) vector<vector<vd>> a(b, vector<vd>(c, vd(d)))
#define v3m(a, b, c, d) vector<vector<vm>> a(b, vector<vm>(c, vm(d)))

#define _vvi vector<vi>
#define _vvl vector<vl>
#define _vvb vector<vb>
#define _vvs vector<vs>
#define _vvd vector<vd>
#define _vvc vector<vc>
#define _vvp vector<vp>

#define PQ priority_queue<ll, vector<ll>, greater<ll> >
#define tos to_string
using mapi = map<int, int>;
using mapd = map<dou, int>;
using mapc = map<char, int>;
using maps = map<str, int>;
using seti = set<int>;
using setd = set<dou>;
using setc = set<char>;
using sets = set<str>;
using qui = queue<int>;
#define bset bitset
#define uset unordered_set
#define mset multiset






#define mmap multimap



#define _overloadrep(_1, _2, _3, _4, name, ...) name
# define _rep(i, n) for(int i = 0,_lim=n; i < _lim ; i++)
#define repi(i, m, n) for(int i = m,_lim=n; i < _lim ; i++)
#define repadd(i, m, n, ad) for(int i = m,_lim=n; i < _lim ; i+= ad)
#define rep(...) _overloadrep(__VA_ARGS__,repadd,repi,_rep,)(__VA_ARGS__)
#define _rer(i, n) for(int i = n; i >= 0 ; i--)
#define reri(i, m, n) for(int i = m,_lim=n; i >= _lim ; i--)
#define rerdec(i, m, n, dec) for(int i = m,_lim=n; i >= _lim ; i-=dec)
#define rer(...) _overloadrep(__VA_ARGS__,rerdec,reri,_rer,)(__VA_ARGS__)
#define fora(a, b) for(auto&& a : b)



#define k3 1010
#define k4 10101
#define k5 101010
#define k6 1010101
#define k7 10101010
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



#define arsz(a) (sizeof(a)/sizeof(a[0]))
#define sz(a) ((int)(a).size())
#define rs resize
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()


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
template<class U> inline void rsortp(vector<U> &a, vector<U> &b) {
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
template<class U, class F> inline void rsortp(vector<U> &a, vector<U> &b, F f) {
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
template<class U, class F> inline void rsortt(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
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
template<class T> inline void rsort2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
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
#define _overloadin(_1, _2, _3, _4, name, ...) name
#define in0() _in()
#define in1(a) cin>>a
#define in2(a, b) cin>>a>>b
#define in3(a, b, c) cin>>a>>b>>c
#define in4(a, b, c, d) cin>>a>>b>>c>>d
#define in(...) _overloadin(__VA_ARGS__,in4,in3,in2 ,in1,in0)(__VA_ARGS__)

#define _overloaddin(_1, _2, _3, _4, name, ...) name
#define din1(a) int a;cin>>a
#define din2(a, b) int a,b;cin>>a>>b
#define din3(a, b, c) int a,b,c;cin>>a>>b>>c
#define din4(a, b, c, d) int a,b,c,d;cin>>a>>b>>c>>d
#define din(...) _overloadin(__VA_ARGS__,din4,din3,din2 ,din1)(__VA_ARGS__)

#define _overloaddind(_1, _2, _3, _4, name, ...) name
#define din1d(a) int a;cin>>a;a--
#define din2d(a, b) int a,b;cin>>a>>b;a--,b--
#define din3d(a, b, c) int a,b,c;cin>>a>>b>>c;a--,b--,c--
#define din4d(a, b, c, d) int a,b,c,d;cin>>a>>b>>c>>d;;a--,b--,c--,d--
#define dind(...) _overloaddind(__VA_ARGS__,din4d,din3d,din2d ,din1d)(__VA_ARGS__)


string sin() { return _in<string>(); }
ll lin() { return _in<ll>(); }
#define na(a, n) a.resize(n); rep(nai,n) cin >> a[nai];
#define nao(a, n) a.resize(n+1); rep(i,n) cin >> a[i+1];
#define nad(a, n) a.resize(n); rep(i,n){ cin >> a[i]; a[i]--;}
#define na2(a, b, n) a.resize(n),b.resize(n);rep(i, n)cin >> a[i] >> b[i];
#define na2d(a, b, n) a.resize(n),b.resize(n);rep(i, n){cin >> a[i] >> b[i];a[i]--,b[i]--;}
#define na3(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n)cin >> a[i] >> b[i] >> c[i];
#define na3d(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n){cin >> a[i] >> b[i] >> c[i];a[i]--,b[i]--,c[i]--;}
#define nt(a, h, w) a.resize(h);rep(i,h)a[i].resize(w); rep(hi,h)rep(wi,w) cin >> a[hi][wi];
#define ntd(a, h, w) rs(a,h,w);rep(hi,h)rep(wi,w) cin >> a[hi][wi], a[hi][wi]--;
#define ntp(a, h, w) fill(a,'#');rep(hi,1,h+1)rep(wi,1,w+1) cin >> a[hi][wi];

#ifdef _DEBUG
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
template<class T> string out_m2(vector<T> &a, ll W = inf) {
    stringstream ss;
    if (W == inf)W = min(sz(a), 12ll);
    if (sz(a) == 0)return ss.str();
    rep(i, W) { ss << a[i] << " "; }
    return ss.str();
}
template<class T> string out_m2(vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {
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

template<class T> string out_m2(vector<vector<vector<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {stringstream ss;    if (H == inf)H = 5;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << out_m2(a[i], W, U, i);    }       return ss.str();}
string out_m2(int a) {stringstream ss;ss << a;return ss.str();}
template<class T> string out_m2(T &a) {stringstream ss;ss << a;return ss.str();}

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
#else
template<class T> void outv(vector<T> &a, ll W = inf) {
    rep(i, min(W, sz(a))) { cout << a[i] << " "; }
    cout << "" << endl;
}
template<class T> void outv(vector<vector<T> > &a, ll H = linf, ll W = linf, int key = -1) { rep(i, min(H, sz(a))) { outv(a[i], W); }}
template<class T> void outv(vector<vector<vector<T> > > &a, ll H = linf, ll W = linf, ll U = linf) { ; }
#define err(...);
#endif

#define debugName(VariableName) # VariableName

#define deb1(x)  debugName(x)<<" = "<<out_m2(x)
#define deb2(x, ...) deb1(x) <<", "<< deb1(__VA_ARGS__)
#define deb3(x, ...) deb1(x) <<", "<< deb2(__VA_ARGS__)
#define deb4(x, ...) deb1(x) <<", "<< deb3(__VA_ARGS__)
#define deb5(x, ...) deb1(x) <<", "<< deb4(__VA_ARGS__)
#define deb6(x, ...) deb1(x) <<", "<< deb5(__VA_ARGS__)
#define deb7(x, ...) deb1(x) <<", "<< deb6(__VA_ARGS__)
#define deb8(x, ...) deb1(x) <<", "<< deb7(__VA_ARGS__)
#define deb9(x, ...) deb1(x) <<", "<< deb8(__VA_ARGS__)
#define deb10(x, ...) deb1(x) <<", "<< deb9(__VA_ARGS__)

#define o_ebug(o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, name, ...) name

#ifdef _DEBUG
#define deb(...)  cerr<< o_ebug(__VA_ARGS__,deb10,deb9,deb8,deb7,deb6,deb5,deb4,deb3,deb2,deb1)(__VA_ARGS__) <<endl
#else
#define deb(...) ;
#endif
#define debugline(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n'
void ole() {
#ifdef _DEBUG
    debugline("ole");
    exit(0);
#endif
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
#define ins inside
ll u(ll a) { return a < 0 ? 0 : a; }
template<class T> vector<T> u(const vector<T> &a) {
    vector<T> ret = a;
    fora(v, ret)v = u(v);
    return ret;
}
#define MIN(a) numeric_limits<a>::min()
#define MAX(a) numeric_limits<a>::max()

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
void POSSIBLE(bool a) {
    if (a)cout << "POSSIBLE" << endl;
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
#define _mgrbody int mid = (ok + ng) / 2; if (f(mid))ok = mid; else ng = mid;
    if (ok < ng)while (ng - ok > 1) { _mgrbody } else while (ok - ng > 1) { _mgrbody }
    return ok;
}

template<class F> inline int mgr(int ok, int ng, int second, F f) {
#define _mgrbody2 int mid = (ok + ng) / 2; if (f(mid, second))ok = mid; else ng = mid;
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
#define bcou __builtin_popcountll
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
#define unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
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

namespace pnumber_tools {

    class Eratosthenes { public:virtual void initialize() {} virtual void generate(const int64_t x) = 0; virtual void generate(const int64_t from, const int64_t to) = 0; virtual int64_t count() = 0; virtual bool prime(int x) = 0; virtual int32_t version() = 0; inline uint64_t PopCnt(uint64_t); inline int BitToIndex(uint8_t); };    uint64_t Eratosthenes::PopCnt(uint64_t bits) {        bits = (bits & 0x5555555555555555ULL) + ((bits >> 1) & 0x5555555555555555ULL);        bits = (bits & 0x3333333333333333ULL) + ((bits >> 2) & 0x3333333333333333ULL);        bits = (bits & 0x0f0f0f0f0f0f0f0fULL) + ((bits >> 4) & 0x0f0f0f0f0f0f0f0fULL);        return (bits * 0x0101010101010101ULL) >> (64 - 8);    }    int Eratosthenes::BitToIndex(uint8_t b) {        switch (b) {            case 1 << 0:                return 0;            case 1 << 1:                return 1;            case 1 << 2:                return 2;            case 1 << 3:                return 3;            case 1 << 4:                return 4;            case 1 << 5:                return 5;            case 1 << 6:                return 6;            case 1 << 7:                return 7;        }        return -1;    }    namespace {        constexpr uint64_t kSegmentSize = 1000000;        constexpr int32_t kMod30[] = {1, 7, 11, 13, 17, 19, 23, 29};        constexpr int C1[] = {6, 4, 2, 4, 2, 4, 6, 2};        constexpr int C0[][8] = {{0, 0, 0, 0, 0, 0, 0, 1},                             {1, 1, 1, 0, 1, 1, 1, 1},                             {2, 2, 0, 2, 0, 2, 2, 1},                             {3, 1, 1, 2, 1, 1, 3, 1},                             {3, 3, 1, 2, 1, 3, 3, 1},                             {4, 2, 2, 2, 2, 2, 4, 1},                             {5, 3, 1, 4, 1, 3, 5, 1},                             {6, 4, 2, 4, 2, 4, 6, 1},};        constexpr uint8_t kMask[][8] = {{0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f},                                    {0xfd, 0xdf, 0xef, 0xfe, 0x7f, 0xf7, 0xfb, 0xbf},                                    {0xfb, 0xef, 0xfe, 0xbf, 0xfd, 0x7f, 0xf7, 0xdf},                                    {0xf7, 0xfe, 0xbf, 0xdf, 0xfb, 0xfd, 0x7f, 0xef},                                    {0xef, 0x7f, 0xfd, 0xfb, 0xdf, 0xbf, 0xfe, 0xf7},                                    {0xdf, 0xf7, 0x7f, 0xfd, 0xbf, 0xfe, 0xef, 0xfb},                                    {0xbf, 0xfb, 0xf7, 0x7f, 0xfe, 0xef, 0xdf, 0xfd},                                    {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe},};        constexpr int64_t kSievedPrimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};        constexpr int64_t kInitialSize = 7 * 11 * 13 * 17 * 19 * 23;        constexpr int imap[] = {-1, 0, -1, -1, -1, -1, -1, 1, -1, -1, -1, 2, -1, 3, -1, -1, -1, 4, -1, 5, -1, -1, -1, 6, -1, -1, -1, -1, -1, 7};        class Eratosthenes2 final                : public Eratosthenes {        public:            void generate(const int64_t x) override;            void generate(const int64_t, const int64_t) override { assert(false); }            bool prime(int x) override;            int64_t count() override;            int32_t version() override { return 2; }            std::vector<uint8_t> flags_;        };        void Eratosthenes2::generate(const int64_t x) {            flags_.clear();            if (x > 10000000000) return;            int64_t size = x / 30 + (x % 30 != 0);            flags_.resize(size, 0xff);            if (int r = x % 30) { if (r <= 1) flags_[size - 1] = 0x0; else if (r <= 7) flags_[size - 1] = 0x1; else if (r <= 11) flags_[size - 1] = 0x3; else if (r <= 13) flags_[size - 1] = 0x7; else if (r <= 17) flags_[size - 1] = 0xf; else if (r <= 19) flags_[size - 1] = 0x1f; else if (r <= 23) flags_[size - 1] = 0x3f; else if (r <= 29) flags_[size - 1] = 0x7f; }            flags_[0] = 0xfe;            const uint64_t sqrt_x = std::ceil(std::sqrt(x) + 0.1);            const uint64_t sqrt_xi = sqrt_x / 30 + 1;            for (uint64_t i = 0; i < sqrt_xi; ++i) {                for (uint8_t flags = flags_[i]; flags; flags &= flags - 1) {                    uint8_t lsb = flags & (-flags);                    int ibit = BitToIndex(lsb);                    const int32_t m = kMod30[ibit];                    int32_t pm = 30 * i + 2 * m;                    for (uint64_t j = i * pm + (m * m) / 30, k = ibit; j < flags_.size(); j += i * C1[k] + C0[ibit][k], k = (k + 1) & 7) { flags_[j] &= kMask[ibit][k]; }                }            }        }        int64_t Eratosthenes2::count() {            if (flags_.empty()) return -1;            int64_t ret = 3;            for (uint8_t f : flags_) { ret += PopCnt(f); }            return ret;        }        inline bool Eratosthenes2::prime(int x) {            if (x == 2 || x == 3 || x == 5)return true; else if (!(x & 1) || x % 3 == 0 || x % 5 == 0)return false;            return (flags_[x / 30] >> imap[x % 30]) & 1;        }    }
    Eratosthenes2 era;
    int prime_len = 3e6;
    vector<int> primes;
    void setprime(int size = 3e6) {        prime_len = size;        era.generate(size);        primes = {2, 3, 5};        int nums[129] = {};        nums[1] = 1;        nums[2] = 7;        nums[4] = 11;        nums[8] = 13;        nums[16] = 17;        nums[32] = 19;        nums[64] = 23;        nums[128] = 29;                int j = 0;        int sflim = era.flags_.size();        int i30 = 0;        for (int i = 0; i < sflim; i++, i30 += 30) {            uint8_t m = era.flags_[i];            while (m) {                j = m & -m;                primes.push_back(i30 + nums[j]);                m ^= j;            }        }    }
    using u32 = unsigned int;

    using u64 = unsigned long long;


    

    bool prime(const int &n) {
        if (!sz(primes))setprime();        
        return era.prime(n);

    }
#define isprime prime
    vi divisors(int v) {
        vi res;
        dou lim = std::sqrt(v);
        for (int i = 1; i <= lim; ++i) { if (v % i == 0) { res.push_back(i);            }}
        rer(i, sz(res) - 1) { if (res[i] != v / res[i])res.push_back(v / res[i]); }
        return res;
    }
    vp factorization(int v) {
        assert(v);
        int tv = v;
        vp res;
        if (!sz(primes))setprime();
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
    

    



    

    struct dra { ll q, l, r, len; dra(ll q_, ll l_, ll r_) : q(q_), l(l_), r(r_), len(r_ - l_) {}};
    vector<dra> drange(ll n, ll l = 1, ll r = -1) {
        if (r == -1)r = n + 1;
        vector<dra> res;
        for (ll x = l; x < r;) {
            ll divisor = n / x;
            ll e;
            if (divisor == 0) { e = r; } else { e = min(r, n / divisor + 1); }
            res.emplace_back(divisor, x, e);
            x = e;
        }
        return res;
    };
}
using namespace pnumber_tools;

signed main() {
    

    map<vp, int> s;
    

    din(N, K);
    na(A, N);
    int cou = 0;
    rep(i, N) {
        auto ve_ = factorization(A[i]);
        rep(j, sz(ve_)) {
            ve_[j].se %= K;
        }
        vp ve;
        rep(j, sz(ve_)) {
            int ad = (ve_[j].se) % K;
            if (ad)ve += ve_[j];
        }
        vp ne;


        rep(j, sz(ve)) {
            int ad = (K - ve[j].se) % K;
            if (ad)ne += mp(ve[j].fi, ad);
        }

        cou += s[ne];
        s[ve]++;
    }
    cout << cou << endl;
}