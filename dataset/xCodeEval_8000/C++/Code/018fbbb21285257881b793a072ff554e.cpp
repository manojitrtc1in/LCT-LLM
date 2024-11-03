



#ifdef _DEBUG
#include<cassert>
#include "bits_stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define r_ return
#define v_ vector
#define t_T template<class T>

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
#define over4(o1, o2, o3, o4, name, ...) name

#define int long long
#define ll long long
#define double long double
#define ull unsigned long long
using dou = double;
using itn = int;
using str = string;
using bo= bool;
#define au auto
using P = pair<ll, ll>;

#define fi first
#define se second
#define vec v_
#define beg begin
#define rbeg rbegin
#define con continue
#define bre break
#define brk break
#define is ==
using vi = v_<ll>;
using vb = v_<bool>;
using vs = v_<string>;
using vd = v_<double>;
using vc = v_<char>;
using vp = v_<P>;



#define vvt0(t) v_<v_<t>>
#define vvt1(t, a) v_<v_<t>>a
#define vvt2(t, a, b) v_<v_<t>>a(b)
#define vvt3(t, a, b, c) v_<v_<t>> a(b,v_<t>(c))
#define vvt4(t, a, b, c, d) v_<v_<t>> a(b,v_<t>(c,d))

#define vvi(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(ll,__VA_ARGS__)
#define vvb(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(bool,__VA_ARGS__)
#define vvs(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(string,__VA_ARGS__)
#define vvd(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(double,__VA_ARGS__)
#define vvc(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(char,__VA_ARGS__)
#define vvp(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(P,__VA_ARGS__)


#define v3i(a, b, c, d) v_<v_<vi>> a(b, v_<vi>(c, vi(d)))
#define v3d(a, b, c, d) v_<v_<vd>> a(b, v_<vd>(c, vd(d)))
#define v3m(a, b, c, d) v_<v_<vm>> a(b, v_<vm>(c, vm(d)))


#define PQ priority_queue<ll, v_<ll>, greater<ll> >
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
#define umap unordered_map
#define umapi unordered_map<int,int>
#define umapp unordered_map<P,int>
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

t_T T MAX() { r_ numeric_limits<T>::max(); }
t_T T MIN() { r_ numeric_limits<T>::min(); }
const int inf = (int) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
t_T T INF() { r_ MAX<T>() / 2; }
template<> signed INF() { r_ inf; }
template<> ll INF() { r_ linf; }
template<> double INF() { r_ (double) linf * linf; }

const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795029L;
ll ma = numeric_limits<ll>::min();
ll mi = numeric_limits<ll>::max();
const int y4[] = {-1, 1, 0, 0};
const int x4[] = {0, 0, -1, 1};
const int y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int x8[] = {1, 0, -1, 0, 1, -1, 1, -1};



#define sz(a) ((int)(a).size())
#define rs resize
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()


inline void sort(string &a) { sort(all(a)); }
t_T inline void sort(v_<T> &a) { sort(all(a)); };
t_T inline void rsort(v_<T> &a) { sort(all(a), greater<T>()); };
template<class U> inline void sortp(v_<U> &a, v_<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    sort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;;    }};



template<class U> inline void rsortp(v_<U> &a, v_<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    rsort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;    }};
template<typename V, typename T>
void fill(V &xx, const T vall) {xx = vall;}
template<typename V, typename T>
void fill(v_<V> &vecc, const T vall) {for (auto &&vx: vecc) fill(vx, vall);}



template<typename T = int> T _in() {T x;cin >> x;r_ (x);}
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
template<typename W, typename H> void resize(W &vec_, const H head) { vec_.resize(head); }
template<typename W, typename H, typename ... T> void resize(W &vec_, const H &head, const T ... tail) {vec_.resize(head);for (auto &v: vec_)resize(v, tail...);}


string sin() { r_ _in<string>(); }
ll lin() { r_ _in<ll>(); }
t_T void na(v_<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i];}
#define dna(a, n) vi a; na(a, n);
#define dnad(a, n) vi a; nad(a, n);
t_T void nad(v_<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i], a[i]--;}
template<class T, class U> void na2(v_<T> &a, v_<U> &b, ll n) {a.resize(n);b.resize(n);rep(i, n)cin >> a[i] >> b[i];}
#define dna2(a, b, n) vi a,b; na2(a,b,n);
template<class T, class U, class W> void na3(v_<T> &a, v_<U> &b, v_<W> &c, ll n) {a.resize(n);b.resize(n);c.resize(n);rep(i, n)cin >> a[i] >> b[i] >> c[i];}
#define nt(a, h, w) resize(a,h,w);rep(nthi,h)rep(ntwi,w) cin >> a[nthi][ntwi];
#define ntd(a, h, w) resize(a,h,w);rep(ntdhi,h)rep(ntdwi,w) cin >> a[ntdhi][ntdwi], a[ntdhi][ntdwi]--;
#define ntp(a, h, w) resize(a,h+2,w+2);fill(a,'#');rep(ntphi,1,h+1)rep(ntpwi,1,w+1) cin >> a[ntphi][ntpwi];
#define dnt(S, h, w) vvi(S,h,w);nt(S,h,w);
#define dntc(S, h, w) vvc(S,h,w);nt(S,h,w);
#define dnts(S, h, w) vvs(S,h,w);nt(S,h,w);



#define sp << " " <<
t_T string out_m2(v_<T> &a, ll W = inf) {    stringstream ss;    if (W == inf)W = min(sz(a), 20ll);    if (sz(a) == 0)r_ ss.str();    rep(i, W) {        ss << a[i];        if (typeid(a[i]) == typeid(P)) { ss << endl; } else { ss << " "; }    }    r_ ss.str();}
t_T string out_m2(v_<v_<T> > &a, vi H, vi W, int key = -1) {    stringstream ss;    ss << endl;    vi lens(sz(W));    fora(h, H) {        rep(wi, sz(W)) {            int v = a[h][W[wi]];            str s = tos(v);            if (abs(v) == inf || abs(v) == INF<T>())s = "e";            lens[wi] = max(lens[wi], sz(s) + 1);            lens[wi] = max(lens[wi], sz(tos(W[wi])) + 1);        }    }    if (key == -1)ss << " *|"; else ss << " " << key << "|";    int wi = 0;    fora(w, W) {        ss << std::right << std::setw(lens[wi]) << w;        wi++;    }    ss << "" << endl;    rep(i, sz(W))rep(_, lens[i]) ss << "_";    rep(i, 3)ss << "_";    ss << "" << endl;    fora(h, H) {        ss << std::right << std::setw(2) << h << "|";        int wi = 0;        fora(w, W) {            str s = tos(a[h][w]);            if (abs(a[h][w]) == inf || abs(a[h][w]) == INF<T>())s = "e";            ss << std::right << std::setw(lens[wi]) << s;            wi++;        }        ss << "" << endl;    }    r_ ss.str();}
t_T string out_m2(v_<v_<T> > &a, ll H = inf, ll W = inf, int key = -1) {    H = (H != inf) ? H : min({H, sz(a), 12ll});    W = min({W, sz(a[0]), 12ll});    vi hs, ws;    rep(h, H) { hs.push_back(h); }    rep(w, W) { ws.push_back(w); }    r_ out_m2(a, hs, ws, key);}
t_T string out_m2(v_<v_<v_<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {    stringstream ss;    if (H == inf)H = 12;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << out_m2(a[i], W, U, i);    }    r_ ss.str();}
string out_m2(int a) {    stringstream ss;    ss << a;    r_ ss.str();}
t_T string out_m2(T &a) {    stringstream ss;    ss << a;    r_ ss.str();}

#define debugName(VariableName) # VariableName

#define _deb1(x) cerr <<  debugName(x)<<" = "<<out_m2(x) << endl
#define _deb2(x, y) cerr <<  debugName(x)<<" = "<<out_m2(x)<<", "<< debugName(y)<<" = "<<out_m2(y)<< endl
#define _deb3(x, y, z) cerr <<  debugName(x)<<" = "<<out_m2(x)  << ", " <<  debugName(y)<<" = "<<out_m2(y) <<", " debugName(z)<<" = "<<out_m2(z) <<endl
#define _deb4(x, y, z, a) cerr <<  debugName(x)<<" = "<<out_m2(x) <<", " <<   debugName(y)<<" = "<<out_m2(y) <<", " <<  debugName(z)<<" = "<<out_m2(z) <<", " <<  debugName(a)<<" = "<<out_m2(a)<<endl
#define _deb5(x, y, z, a, b) cerr <<  debugName(x)<<" = "<<out_m2(x) <<", " <<   debugName(y)<<" = "<<out_m2(y) <<", " <<  debugName(z)<<" = "<<out_m2(z) <<", " <<  debugName(a)<<" = "<<out_m2(a)<<", " <<  debugName(b)<<" = "<<out_m2(b)<<endl


#define _overloadebug(_1, _2, _3, _4, _5, name, ...) name
#define debug(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#ifdef _DEBUG
#define deb(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#else
#define deb(...) ;
#endif


#define debugline(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n'


ll gcd(ll a, ll b) { r_ b ? gcd(b, a % b) : a; }
ll gcd(vi b) {ll res = b[0];for (auto &&v :b)res = gcd(v, res);r_ res;}
ll lcm(ll a, ll b) { r_ a / gcd(a, b) * b; }
ll rev(ll a) {    ll res = 0;    while (a) {        res *= 10;        res += a % 10;        a /= 10;    }    r_ res;}
t_T v_<T> rev(v_<T> &a) {    auto b = a;    reverse(all(b));    r_ b;}
str rev(str &a) {str s = a;reverse(all(s));r_ s;}
ll ceil(ll a, ll b) {if (b == 0) {cerr<<"ceil"<<endl;exit(1);r_ -1;} else r_ (a + b - 1) / b;}
ll sqrt(ll a) {    if (a < 0) {        cerr<<"sqrt"<<endl;        exit(1);    }    ll res = (ll) std::sqrt(a);    while (res * res < a)res++;    r_ res;}
double log(double e, double x) { r_ log(x) / log(e); }
ll sig(ll t) { r_ (1 + t) * t / 2; }
ll sig(ll s, ll t) { r_ (s + t) * (t - s + 1) / 2; }

vi divisors(int v) {    vi res;    double lim = std::sqrt(v);    rep(i, 1, lim+1){        if (v % i == 0) {            res.pb(i);            if (i != v / i)res.pb(v / i);        }    }    r_ res;}
vb isPrime;
vi primes;

void setPrime() {    int len = 4010101;    isPrime.resize(4010101);    fill(isPrime, true);    isPrime[0] = isPrime[1] = false;    for (int i = 2; i <= sqrt(len) + 5; ++i) {        if (!isPrime[i])continue;        for (int j = 2; i * j < len; ++j) {            isPrime[i * j] = false;        }    }    rep(i, len)if (isPrime[i])primes.pb(i);}

vi factorization(int v) {    int tv = v;    vi res;    if (isPrime.size() == 0)setPrime();    for (auto &&p :primes) {        if (v % p == 0)res.push_back(p);        while (v % p == 0) {            v /= p;        }        if (v == 1 || p * p > tv)break;    }    if (v > 1)res.pb(v);    r_ res;}
inline bool inside(int h, int w, int H, int W) { r_ h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { r_ l <= v && v < r; }


t_T v_<T> ruiv(v_<T> &a) {    v_<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    r_ ret;}




t_T v_<T> imo(v_<T> &v) {    v_<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];    r_ ret;}

#define ins inside
ll u0(ll a) { r_ a < 0 ? 0 : a; }
t_T v_<T> u(const v_<T> &a) {
    v_<T> ret = a;fora(v, ret)v = u0(v);r_ ret;}
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
    r_ a;
}
template<class T, class U> v_<T> &operator+=(v_<T> &a, U v) {
    a.pb(v);
    r_ a;
}
t_T T sum(v_<T> &v, int s = 0, int t = inf) {    T ret = 0;    rep(i, s, min(sz(v), t))ret += v[i];    r_ ret;}
void mod(int &a, int m) { a = (a % m + m) % m; }
template<class F> inline int mgr(int ok, int ng, F f) {
#define _mgrbody int mid = (ok + ng) / 2; if (f(mid))ok = mid; else ng = mid;
    if (ok < ng)while (ng - ok > 1) { _mgrbody } else while (ok - ng > 1) { _mgrbody }
    r_ ok;
}

template<class F> inline int mgr(int ok, int ng, int second, F f) {
#define _mgrbody2 int mid = (ok + ng) / 2; if (f(mid, second))ok = mid; else ng = mid;
    if (ok < ng) while (ng - ok > 1) { _mgrbody2 } else while (ok - ng > 1) { _mgrbody2 }
    r_ ok;
}
template<typename T> ostream &operator<<(ostream &os, v_<T> &m) {    for (auto &&v:m) os << v << " ";    r_ os;}
constexpr bool bget(ll m, int keta) { r_ (m >> keta) & 1; }
int bget(ll m, int keta, int sinsuu) {m /= (ll) pow(sinsuu, keta);r_ m % sinsuu;}
ll bit(int n) { r_ (1LL << (n)); }
ll bit(int n, int sinsuu) { r_ (ll) pow(sinsuu, n); }
int mask(int n) { r_ (1ll << n) - 1; }
#define bcou __builtin_popcountll
template<class T, class U> inline bool chma(T &a, const U &b) {if (a < b) {a = b;r_ true;}r_ false;}
template<class U> inline bool chma(const U &b) { r_ chma(ma, b); }
template<class T, class U> inline bool chmi(T &a, const U &b) {    if (b < a) {        a = b;        r_ true;    }    r_ false;}
template<class U> inline bool chmi(const U &b) { r_ chmi(mi, b); }
#define unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
int max(vi &a) {    int res = a[0];    fora(v, a) {        res = max(res, v);    }    r_ res;}
int min(vi &a) {    int res = a[0];    fora(v, a) {        res = min(res, v);    }    r_ res;}
template<typename T> class fixed_point        : T {public:    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { r_ T::operator()(*this, std::forward<Args>(args)...); }};template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { r_ fixed_point<T>{std::forward<T>(t)}; }
constexpr ll h4[] = {1, -1, 0, 0};
constexpr ll w4[] = {0, 0, -1, 1};
constexpr ll h8[] = {0, 1, 0, -1, -1, 1, 1, -1};
constexpr ll w8[] = {1, 0, -1, 0, 1, -1, 1, -1};
int mei_inc(int h, int w, int H, int W, int i) {while (++i < 4) { if (inside(h + h4[i], w + w4[i], H, W))r_ i; }r_ i;}
#define mei(nh, nw, h, w) for (int i = mei_inc(h, w, H, W, -1), nh = i<4? h + h4[i] : 0, nw = i<4? w + w4[i] : 0; i < 4; i=mei_inc(h,w,H,W,i), nh = h+h4[i], nw = w+w4[i])
int mei_inc8(int h, int w, int H, int W, int i) {    while (++i < 8) {        if (inside(h + h8[i], w + w8[i], H, W))r_ i;    }    r_ i;}
#define mei8(nh, nw, h, w) for (int i = mei_inc8(h, w, H, W, -1), nh = i<8? h + h8[i] : 0, nw = i<8? w + w8[i] : 0; i < 8; i=mei_inc8(h,w,H,W,i), nh = h+h8[i], nw = w+w8[i])
int mei_incv(int h, int w, int H, int W, int i, vp &p) {    while (++i < sz(p)) { if (inside(h + p[i].fi, w + p[i].se, H, W))r_ i; }    r_ i;}
#define meiv(nh, nw, h, w, p) for (int i = mei_incv(h, w, H, W, -1, p), nh = i<sz(p)? h + p[i].fi : 0, nw = i<sz(p)? w + p[i].se : 0; i < sz(p); i=mei_incv(h,w,H,W,i,p), nh = h+p[i].fi, nw = w+p[i].se)
vi compress(vi &A) {    vi B = A;    sort(B);    unique(B);    vi inds(sz(B));    rep(i, sz(A)) {        int ind = lower_bound(all(B), A[i]) - B.begin();        inds[ind] = A[i];        A[i] = ind;    }    return inds;}
vi compress(vi &A, umapi& map){    vi i_v = compress(A);    rep(i, sz(i_v)){        map[i_v[i]] = i;    }    return i_v;}

t_T void out2(T head) {    cout << head;}
template<class T, class... U> void out2(T head, U ... tail) {    cout << head << " ";      out2(tail...);}
template<class T, class... U> void out(T head, U ... tail) {    cout << head << " ";        out2(tail...);    cout << "" << endl;}
t_T void out(T head) {    cout << head << endl; }
t_T void out(const vector<T>& A) {    rep(i, sz(A)-1){        cout<<A[i]<<" ";    }    cout<<A[sz(A)-1]<< endl;}
void out() { cout << "" << endl; }
#define lowerIndex(a, v) (lower_bound(all(a),v)-a.begin())
#define upperIndex(a, v) (upper_bound(all(a),v)-a.begin())



int N, M, H, W;
vi A, B, C;

template<class M=int> struct seglmin {
    int n;
    int n2 ;
    vector<M> seg;
    vi lazy;

    M e = MAX<M>();
    vi arch;

    M f(M a, M b) { return a < b ? a : b; }
    seglmin(vector<M> a, M init_value = MAX<M>()) : e(init_value),n2(sz(a)) {        n = 1;        int asz = a.size();        while (n <= asz)n <<= 1;        seg.resize((n << 1), e);        lazy.resize((n << 1), 0);        rep(i, asz) seg[i + n - 1] = a[i];        rer(i, n - 2)seg[i] = f(seg[(i << 1) + 1], seg[(i << 1) + 2]);        int l = 1, v = n;    }
    seglmin(int N, M init_value = MAX<M>()) : e(init_value),n2(N) {        deb(e);        vi a(N, init_value);        n = 1;        int asz = a.size();        while (n <= asz)n <<= 1;        seg.resize((n << 1), e);        lazy.resize((n << 1), 0);        rep(i, asz) seg[i + n - 1] = a[i];        rer(i, n - 2)seg[i] = f(seg[(i << 1) + 1], seg[(i << 1) + 2]);        int l = 1, v = n;    }    void eval() {        rer(j, sz(arch) - 1) {            int i = arch[j];                                    int v = lazy[i - 1];            if (!v)continue;            lazy[(i << 1) - 1] += v;            lazy[(i << 1)] += v;            seg[(i << 1) - 1] += v;            seg[i << 1] += v;            lazy[i - 1] = 0;        }    }    void gindex(int l, int r) {        arch.clear();        l += n;        r += n;        int lm = (l / (l & -l)) >> 1;        int rm = (r / (r & -r)) >> 1;        while (l < r) {            if (r <= rm)arch.push_back(r);            if (l <= lm)arch.push_back(l);            l >>= 1;            r >>= 1;        }        while (l) {            arch.push_back(l);            l >>= 1;        }    }
    void add(int l, int r, int x) {        chmi(r,n-1);int L = l + n;        int R = r + n;        while (L < R) {            if (R & 1) {                R--;                lazy[R - 1] += x;                seg[R - 1] += x;            }            if (L & 1) {                lazy[L - 1] += x;                seg[L - 1] += x;                L++;            }            L >>= 1;            R >>= 1;        }        l += n;        r += n;        int lm = (l / (l & -l)) >> 1;        int rm = (r / (r & -r)) >> 1;        while (l < r) {            if (r <= rm) {                seg[r - 1] = f(seg[(r << 1) - 1], seg[(r << 1)]);                seg[r - 1] += lazy[r - 1];            }            if (l <= lm) {                seg[l - 1] = f(seg[(l << 1) - 1], seg[l << 1]);                seg[l - 1] += lazy[l - 1];            }            l >>= 1;            r >>= 1;        }        while (l) {            seg[l - 1] = f(seg[(l << 1) - 1], seg[l << 1]);            seg[l - 1] += lazy[l - 1];            l >>= 1;        }    }
    M get(int l, int r) { return get2(l, min(r, n - 1)); }
    M get(int r = inf) { return get2(0, min(r, n - 1)); }
    M getr(int l) { return get2(l, n - 1); }
    M operator[](int i) { return get(i, i + 1); }
    M operator()(int l, int r) { return get(l,r); }
    M operator()(int r = inf) { return get(r); }
    

    int most_l(M v) {        M d = get(0, n);        if (get(0, n) > v)return -1;        int l = 0, r = n;        while (r - l > 1) {            int m = (l + r) >> 1;            if (get(l,m) <= v) { r = m; } else { l = m; }        }        return l;    }
    

    int most_r(M v) {        if (get(0, n) > v)return -1;        int l = 0, r = n;        while (r - l > 1) {            int m = (l + r) >> 1;            if (get(m,r) <= v) { l = m; } else { r = m; }        }        return l;    }
    

    int most_l(int l, M v) {        M geta = v + 10;        int geta2 = get(0, l);        if (geta2 != e) geta -= geta2;        add(0, l, geta);        int res = most_l(v);        add(0, l, -geta);        return res;    }
    

    int most_r(int r, M v) {        M geta = v + 10;        int geta2 = get(r, n);        if (geta2 != e) geta -= geta2;        add(r, n2, geta);        int l = most_r(v);        add(r, n2, -geta);        return l;    }
#ifdef _DEBUG
    void debu(int len = 10) {        rep(i, min(n, min(len, n))) {            int v = get(i, i + 1);            if (v == e) { cerr << "e "; } else { cerr << v << " "; }        }        cerr << "" << endl;}
#else
    inline void debu(){;}
#endif
private :
    M get2(int l, int r) {        gindex(l, r);        eval();        int L = l + n;        int R = r + n;        M retl = e, retr = e;        while (L < R) {            if (R & 1) {                R--;                retr = f(seg[R - 1], retr);            }            if (L & 1) {                retl = f(retl, seg[L - 1]);                L++;            }            L >>= 1;            R >>= 1;        }        return f(retl, retr);    }
};



void solve() {
    in(N, M);
    vi len;
    na(len, M);
    int su_mi = M - 1 + len[M - 1];
    if (su_mi > N || sum(len) < N) {
        out(-1);
        exit(0);
    } else {
        vi rems(M);
        rep(i, M) {
            A+= i;
            rems[i] = N - (A[i] + len[i]);
        }
        seglmin<int> st(rems, linf);
        int add_base = 0;
        rep(i, 1, M) {
            int canl = len[i - 1] - 1;
            int canr = st(i, M);
            int can = min(canl, canr);
            if(can < 0) {
                out(-1);
                return;
            }
            st.add(i, M, -can);
            add_base += can;
            A[i] += add_base;
        }

        fora(a, A)a++;
        out(A);
    }


}


signed main() {
    solve();
    r_ 0;
}