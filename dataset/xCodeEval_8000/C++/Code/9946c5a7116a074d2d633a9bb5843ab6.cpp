

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









template<class T> vector<T> imo(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];    return ret;}


template<class T, class U> vi imo(vector<T> &a, U k) {vector<T> ret = a;rep(i, sz(ret))ret[i] = a[i] == k;rep(i, sz(ret) - 1)ret[i + 1] += ret[i];return ret;}
template<class T> vector<T> imox(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] ^= ret[i];    return ret;}


template<class T> vector<T> imi(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)chmi(ret[i + 1], ret[i]);    return ret;}
template<class T> struct ruiC {    const vector<T> rui;    ruiC(vector<T> &ru) : rui(ru) {}    T operator()(ll l, ll r) {        if (l > r) {            cerr<<"ruic ";deb(l, r);assert(0);        }        return rui[r] - rui[l];    }    T operator[](ll i) { return rui[i]; }    T back() { return rui.back(); }    ll size() { return rui.size(); }};
template<class T> struct rruic {    const T *rrui;    rruic(T *ru) : rrui(ru) {}     T operator()(ll l, ll r) {        assert(l >= r);        return rrui[r] - rrui[l];    }     T operator[](ll i) { return rrui[i]; }};
template<class T>ostream &operator<<(ostream &os, ruiC<T> a) {fora(v,a.rui)os<<v<<" ";return os;}
template<class T> vector<T> ruiv(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    return ret;}
template<class T> ruiC<T> ruic(vector<T> &a) {    vector<T> ret = ruiv(a);    return ruiC<T>(ret);}
vector<ll> ruiv(string &a) {    if (sz(a) == 0)return vi(1);    ll dec = ('0' <= a[0] && a[0] <= '9') ? '0' : 0;    vector<ll> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i] - dec;    return ret;}
ruiC<ll> ruic(string &a) {    vector<ll> ret = ruiv(a);    return ruiC<ll>(ret);}


template<class T, class U> vi ruiv(T &a, U k) {    vi ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + (a[i] == k);    return ret;}
template<class T, class U> ruiC<ll> ruic(T &a, U k) {    vi ret = ruiv(a, k);    return ruiC<ll>(ret);}


template<class T> struct ruixC {    const vector<T> rui;    ruixC(vector<T> &ru) : rui(ru) {}    T operator()(ll l, ll r) {        if (l > r) {            cerr << "ruiXc ";            deb(l, r);            assert(0);        }        return rui[r] ^ rui[l];    }    T operator[](ll i) { return rui[i]; }    T back() { return rui.back(); }    ll size() { return rui.size(); }};
template<class T> vector<T> ruix(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] ^ a[i];    return ret;}
template<class T> ruixC<ll> ruixc(vector<T>  &a) {vi ret = ruix(a);return ruixC<ll>(ret);}
template<class T> vector<T> ruim(vector<T> &a) {    vector<T> res(a.size() + 1, 1);    rep(i, a.size())res[i + 1] = res[i] * a[i];    return res;}


template<class T> vector<T> ruimi(vector<T> &a) {    ll n = sz(a);    vector<T> ret(n + 1);    rep(i, 1, n) {        ret[i] = a[i - 1];        chmi(ret[i + 1], ret[i]);    }    return ret;}




template<class T> rruic<T> rrui(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    rer(i, len - 1)res[i - 1] = res[i] + a[i];    return rruic<T>(res);}


template<class T> T *rruim(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    res[len - 1] = 1;    rer(i, len - 1)res[i - 1] = res[i] * a[i];    return res;}





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
#define lam(right) [&](auto& p){return p right;}
template<typename W, typename H> void resize(vector<W> &vec, const H head) { vec.resize(head); }template<typename W, typename H, typename ... T> void resize(vector<W> &vec, const H &head, const T ... tail) {vec.resize(head);for (auto &v: vec)resize(v, tail...);}
template<typename T, typename F> bool all_of2(T &v, F f) { return f(v); }
template<typename T, typename F> bool all_of2(vector<T> &v, F f) {    rep(i, sz(v)) { if (!all_of2(v[i], f))return false; }    return true;}
template<typename T, typename F> bool any_of2(T &v, F f) { return f(v); }
template<typename T, typename F> bool any_of2(vector<T> &v, F f) {    rep(i, sz(v)) { if (any_of2(v[i], f))return true; }    return false;}
template<typename T, typename F> bool none_of2(T &v, F f) { return f(v); }
template<typename T, typename F> bool none_of2(vector<T> &v, F f) {    rep(i, sz(v)) { if (none_of2(v[i], f))return false; }    return true;}
template<typename T, typename F> bool find_if2(T &v, F f) { return f(v); }
template<typename T, typename F> ll find_if2(vector<T> &v, F f) {    rep(i, sz(v)) { if (find_if2(v[i], f))return i; }    return sz(v);}
template<typename T, typename F> bool rfind_if2(T &v, F f) { return f(v); }
template<typename T, typename F> ll rfind_if2(vector<T> &v, F f) {    rer(i, sz(v) - 1) { if (rfind_if2(v[i], f))return i; }    return -1;}
template<class T> bool contains(string &s, const T &v) { return s.find(v) != string::npos; }
template<typename T> bool contains(vector<T> &v, const T &val) { return std::find(v.begin(), v.end(), val) != v.end(); }
template<typename T, typename F> bool contains_if2(vector<T> &v, F f) { return find_if(v.begin(), v.end(), f) != v.end(); }
template<typename T, typename F> ll count_if2(T &v, F f) { return f(v); }
template<typename T, typename F> ll count_if2(vector<T> &vec, F f) {    ll ret = 0;    fora(v, vec)ret += count_if2(v, f);    return ret;}
template<typename T, typename F> void for_each2(T &v, F f) { f(v); }
template<typename T, typename F> void for_each2(vector<T> &vec, F f) { fora(v, vec)for_each2(v, f); }
template<typename W> ll count_od(vector<W> &a) {return count_if2(a,[](ll v){return v&1 ;});}
template<typename W> ll count_ev(vector<W> &a) {return count_if2(a,[](ll v){return !(v&1) ;});}


template<typename T, typename F> int erase_if2(vector<T> &v, F f) {vector<T> nv;int cou = 0;rep(i, sz(v)) {if (f(v[i])) {cou++;} else {nv.push_back(v[i]);}}v = nv;return cou;}
template<typename T, typename F> int erase_if2(vector<vector<T>> &v, F f) {int cou = 0;rep(i, sz(v)) {cou += erase_if2(v[i], f);}return cou;}
#define all_of(a,right) all_of2(a,lam(right))
#define all_of_f(a,f) all_of2(a,f)
#define any_of(a,right) any_of2(a,lam(right))
#define any_of_f(a,f) any_of2(a,f)
#define none_of(a,right) none_of2(a,lam(right))
#define none_of_f(a,f) none_of2(a,f)
#define find_if(a,right) find_if2(a,lam(right))
#define find_if_f(a,f) find_if2(a,f)
#define rfind_if(a,right) rfind_if2(a,lam(right))
#define rfind_if_f(a,f) rfind_if2(a,f)
#define contains_if(a,right) contains_if2(a,lam(right))
#define contains_if_f(a,f) contains_if2(a,f)
#define count_if(a, right) count_if2(a,lam(right))
#define count_if_f(a, f) count_if2(a,f)
#define for_each(a, right) do{fora(v,a){v right;}}while(0)
#define for_each_f(a, f) do{fora(v,a){f(v);}}while(0)
#define erase_if(a,right) erase_if2(a,lam(right))
#define erase_if_f(a,f) erase_if2(a,f)



int N, K, H, W;
vi A, B, C;

#define Int int
#define REP rep

void solve() {
    Int n;
    cin >> n;
    vp ps(n);
    rep(i, n){
        cin>>ps[i].fi>>ps[i].se;
    }
    sort(ps, fisd);


    int ini=1e16;
    vvi(dp, n + 1, n + 1, ini);
    dp[n][0] = 0;
    auto debu = [&]() {
        return ;
                REP(i, n + 1) {
                    REP(j, n + 1) {
                cout << dp[i][j] << " ";
            }
            cout << "" << endl;
        }
        cout << "" << endl;
    };
    debu();
    for (Int i = n - 1; i >= 0; i--) {
                REP (j, n + 1) {
            if (j + i >= ps[i].fi) {
                chmi(dp[i][j], dp[i + 1][j]);
                debu();
            }
            if (j + 1 <= n && j + i + 1 >= ps[i].fi) {
                chmi(dp[i][j + 1], dp[i + 1][j] + ps[i].se);
                debu();
            }
        }
    }
    cout << *min_element(all(dp[0])) << endl;
}
signed main() {
    Int T;
    cin >> T;
    while (T--) solve();
}