



#ifdef _DEBUG
#include<cassert>
#include "bits_stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define t_T template<class T>

using namespace std;


struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(3);
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



#define vvt0(t) vector<vector<t>>
#define vvt1(t, a) vector<vector<t>>a
#define vvt2(t, a, b) vector<vector<t>>a(b)
#define vvt3(t, a, b, c) vector<vector<t>> a(b,vector<t>(c))
#define vvt4(t, a, b, c, d) vector<vector<t>> a(b,vector<t>(c,d))

#define vvi(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(ll,__VA_ARGS__)
#define vvb(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(bool,__VA_ARGS__)
#define vvs(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(string,__VA_ARGS__)
#define vvd(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(double,__VA_ARGS__)
#define vvc(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(char,__VA_ARGS__)
#define vvp(...) over4(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(P,__VA_ARGS__)


#define v3i(a, b, c, d) vector<vector<vi>> a(b, vector<vi>(c, vi(d)))
#define v3d(a, b, c, d) vector<vector<vd>> a(b, vector<vd>(c, vd(d)))
#define v3m(a, b, c, d) vector<vector<vm>> a(b, vector<vm>(c, vm(d)))


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

t_T T MAX() { return numeric_limits<T>::max(); }
t_T T MIN() { return numeric_limits<T>::min(); }
const int inf = (int) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
t_T T INF() { return MAX<T>() / 2; }
template<> signed INF() { return inf; }
template<> ll INF() { return linf; }
template<> double INF() { return (double) linf * linf; }

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
#define mt make_tuple
#define pb push_back
#define pf push_front
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()


inline void sort(string &a) { sort(all(a)); }
t_T inline void sort(vector<T> &a) { sort(all(a)); };
t_T inline void rsort(vector<T> &a) { sort(all(a), greater<T>()); };
template<class U> inline void sortp(vector<U> &a, vector<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    sort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;;    }};



template<class U> inline void rsortp(vector<U> &a, vector<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    rsort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;    }};
template<typename V, typename T>
void fill(V &xx, const T vall) {xx = vall;}
template<typename V, typename T>
void fill(vector<V> &vecc, const T vall) {for (auto &&vx: vecc) fill(vx, vall);}



template<typename T = int> T _in() {T x;cin >> x;return (x);}
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


string sin() { return _in<string>(); }
ll lin() { return _in<ll>(); }
t_T void na(vector<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i];}
#define dna(a, n) vi a; na(a, n);
#define dnad(a, n) vi a; nad(a, n);
t_T void nad(vector<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i], a[i]--;}
template<class T, class U> void na2(vector<T> &a, vector<U> &b, ll n) {a.resize(n);b.resize(n);rep(i, n)cin >> a[i] >> b[i];}
#define dna2(a, b, n) vi a,b; na2(a,b,n);
template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {a.resize(n);b.resize(n);c.resize(n);rep(i, n)cin >> a[i] >> b[i] >> c[i];}
#define nt(a, h, w) resize(a,h,w);rep(nthi,h)rep(ntwi,w) cin >> a[nthi][ntwi];
#define ntd(a, h, w) resize(a,h,w);rep(ntdhi,h)rep(ntdwi,w) cin >> a[ntdhi][ntdwi], a[ntdhi][ntdwi]--;
#define ntp(a, h, w) resize(a,h+2,w+2);fill(a,'#');rep(ntphi,1,h+1)rep(ntpwi,1,w+1) cin >> a[ntphi][ntpwi];
#define dnt(S, h, w) vvi(S,h,w);nt(S,h,w);
#define dntc(S, h, w) vvc(S,h,w);nt(S,h,w);
#define dnts(S, h, w) vvs(S,h,w);nt(S,h,w);



#define sp << " " <<
constexpr int DEB_LEN =20;
constexpr int DEB_LEN_H =12;
string deb_tos(const int &v) { if (abs(v) == inf || abs(v) == linf)return "e"; else return to_string(v); }
template<class T> string deb_tos(const T &a) {stringstream ss;ss << a;return ss.str();}
template<class T> string deb_tos(const vector<T> &a, ll W = inf) {    stringstream ss;    if (W == inf)W = min(sz(a), DEB_LEN);    if (sz(a) == 0)return ss.str();    rep(i, W) {        ss << deb_tos(a[i]);        if (typeid(a[i]) == typeid(P)) { ss << endl; } else { ss << " "; }    }    return ss.str();}
template<class T> string deb_tos(const vector<vector<T> > &a, vi H, vi W, int key = -1) {    stringstream ss;    ss << endl;    vi lens(sz(W));    fora(h, H) {        rep(wi, sz(W)) {            lens[wi] = max(lens[wi], sz(deb_tos(a[h][W[wi]])) + 1);            lens[wi] = max(lens[wi], sz(deb_tos(W[wi])) + 1);        }    }    if (key == -1)ss << " *|"; else ss << " " << key << "|";    int wi = 0;    fora(w, W) {        ss << std::right << std::setw(lens[wi]) << w;        wi++;    }    ss << "" << endl;    rep(i, sz(W))rep(_, lens[i]) ss << "_";    rep(i, 3)ss << "_";    ss << "" << endl;    fora(h, H) {        ss << std::right << std::setw(2) << h << "|";        int wi = 0;        fora(w, W) {            ss << std::right << std::setw(lens[wi]) << deb_tos(a[h][w]);            wi++;        }        ss << "" << endl;    }    return ss.str();}
template<class T> string deb_tos(const vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {    H = (H != inf) ? H : min({H, sz(a), DEB_LEN_H});    W = min({W, sz(a[0]), DEB_LEN_H});    vi hs, ws;    rep(h, H) { hs.push_back(h); }    rep(w, W) { ws.push_back(w); }    return deb_tos(a, hs, ws, key);}
template<class T> string deb_tos(const vector<vector<vector<T> > > &a, ll H = inf) {    stringstream ss;    if (H == inf)H = DEB_LEN_H;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << deb_tos(a[i], inf, inf, i);    }    return ss.str();}
template<class T, size_t A> string deb_tos(T (&a)[A]) { return deb_tos(vector<T>(begin(a), end(a))); }
template<class T, size_t A, size_t B> string deb_tos(T (&a)[A][B]) { return deb_tos(vector<vector<T> >(begin(a), end(a))); }
template<class T, size_t A, size_t B, size_t C> string deb_tos(T (&a)[A][B][C]) { return deb_tos(vector<vector<vector<T> > >(begin(a), end(a))); }

#define debugName(VariableName) # VariableName

#define _deb1(x) cerr <<  debugName(x)<<" = "<<deb_tos(x) << endl
#define _deb2(x, y) cerr <<  debugName(x)<<" = "<<deb_tos(x)<<", "<< debugName(y)<<" = "<<deb_tos(y)<< endl
#define _deb3(x, y, z) cerr <<  debugName(x)<<" = "<<deb_tos(x)  << ", " <<  debugName(y)<<" = "<<deb_tos(y) <<", " debugName(z)<<" = "<<deb_tos(z) <<endl
#define _deb4(x, y, z, a) cerr <<  debugName(x)<<" = "<<deb_tos(x) <<", " <<   debugName(y)<<" = "<<deb_tos(y) <<", " <<  debugName(z)<<" = "<<deb_tos(z) <<", " <<  debugName(a)<<" = "<<deb_tos(a)<<endl
#define _deb5(x, y, z, a, b) cerr <<  debugName(x)<<" = "<<deb_tos(x) <<", " <<   debugName(y)<<" = "<<deb_tos(y) <<", " <<  debugName(z)<<" = "<<deb_tos(z) <<", " <<  debugName(a)<<" = "<<deb_tos(a)<<", " <<  debugName(b)<<" = "<<deb_tos(b)<<endl


#define _overloadebug(_1, _2, _3, _4, _5, name, ...) name
#define debug(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#ifdef _DEBUG
#define deb(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#else
#define deb(...) ;
#endif


#define debugline(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n'


ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll gcd(vi b) {ll res = b[0];for (auto &&v :b)res = gcd(v, res);return res;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll rev(ll a) {    ll res = 0;    while (a) {        res *= 10;        res += a % 10;        a /= 10;    }    return res;}
template<class T> auto rev(const T &v, int i) {return v[sz(v) - 1 - i];}
t_T vector<T> rev(vector<T> &a) {    auto b = a;    reverse(all(b));    return b;}
str rev(str &a) {str s = a;reverse(all(s));return s;}
ll ceil(ll a, ll b) {if (b == 0) {cerr<<"ceil"<<endl;exit(1);return -1;} else return (a + b - 1) / b;}
ll sqrt(ll a) {    if (a < 0) {        cerr<<"sqrt"<<endl;        exit(1);    }    ll res = (ll) std::sqrt(a);    while (res * res < a)res++;    return res;}
double log(double e, double x) { return log(x) / log(e); }
ll sig(ll t) { return (1 + t) * t / 2; }
ll sig(ll s, ll t) { return (s + t) * (t - s + 1) / 2; }

vi divisors(int v) {    vi res;    double lim = std::sqrt(v);    rep(i, 1, lim+1){        if (v % i == 0) {            res.pb(i);            if (i != v / i)res.pb(v / i);        }    }    return res;}
vb isPrime;
vi primes;

void setPrime() {    int len = 4010101;    isPrime.resize(4010101);    fill(isPrime, true);    isPrime[0] = isPrime[1] = false;    for (int i = 2; i <= sqrt(len) + 5; ++i) {        if (!isPrime[i])continue;        for (int j = 2; i * j < len; ++j) {            isPrime[i * j] = false;        }    }    rep(i, len)if (isPrime[i])primes.pb(i);}

vi factorization(int v) {    int tv = v;    vi res;    if (isPrime.size() == 0)setPrime();    for (auto &&p :primes) {        if (v % p == 0)res.push_back(p);        while (v % p == 0) {            v /= p;        }        if (v == 1 || p * p > tv)break;    }    if (v > 1)res.pb(v);    return res;}
inline bool inside(int h, int w, int H, int W) { return h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { return l <= v && v < r; }


t_T vector<T> ruiv(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    return ret;}




t_T vector<T> imo(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];    return ret;}

#define ins inside
ll u0(ll a) { return a < 0 ? 0 : a; }
t_T vector<T> u(const vector<T> &a) {
    vector<T> ret = a;fora(v, ret)v = u0(v);return ret;}
#define MIN(a) numeric_limits<a>::min()
#define MAX(a) numeric_limits<a>::max()
template<class T, class U> pair<T,U> operator+(const pair<T,U> &a, const pair<T,U> & b) {return pair<T,U>(a.fi+b.fi,a.se+b.se);}

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
    a.push_back(v);
    return a;
}
template<class T> vector<T>& operator+=(vector<T> & a,const vector<T> & b){
    rep(i, sz(b))a += b[i];
    return a;
}
t_T T sum(vector<T> &v, int s = 0, int t = inf) {    T ret = 0;    rep(i, s, min(sz(v), t))ret += v[i];    return ret;}
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
template<typename T> ostream &operator<<(ostream &os, vector<T> &m) {    rep(i, sz(m)){os << m[i];if(i < sz(m)-1)os<<" ";}   return os;}
ostream &operator<<(ostream &os, vector<char> &m) {rep(i, sz(m)){os << m[i];}   return os;}
template<typename T> ostream &operator<<(ostream &os, vector<vector<T>> &m) {rep(i, sz(m)){os << m[i]; if(i < sz(m)-1)os << endl;}   return os;}
constexpr bool bget(ll m, int keta) { return (m >> keta) & 1; }
int bget(ll m, int keta, int sinsuu) {m /= (ll) pow(sinsuu, keta);return m % sinsuu;}
ll bit(int n) { return (1LL << (n)); }
ll bit(int n, int sinsuu) { return (ll) pow(sinsuu, n); }
int mask(int n) { return (1ll << n) - 1; }
#define bcou __builtin_popcountll
template<class T, class U> inline bool chma(T &a, const U &b) {if (a < b) {a = b;return true;}return false;}
template<class U> inline bool chma(const U &b) { return chma(ma, b); }
template<class T, class U> inline bool chmi(T &a, const U &b) {    if (b < a) {        a = b;        return true;    }    return false;}
template<class U> inline bool chmi(const U &b) { return chmi(mi, b); }
#define unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
int max(vi &a) {    int res = a[0];    fora(v, a) {        res = max(res, v);    }    return res;}
int min(vi &a) {    int res = a[0];    fora(v, a) {        res = min(res, v);    }    return res;}
template<typename T> class fixed_point        : T {public:    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }};template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }
constexpr ll h4[] = {1, -1, 0, 0};
constexpr ll w4[] = {0, 0, -1, 1};
constexpr ll h8[] = {0, 1, 0, -1, -1, 1, 1, -1};
constexpr ll w8[] = {1, 0, -1, 0, 1, -1, 1, -1};
int mei_inc(int h, int w, int H, int W, int i) {while (++i < 4) { if (inside(h + h4[i], w + w4[i], H, W))return i; }return i;}
#define mei(nh, nw, h, w) for (int i = mei_inc(h, w, H, W, -1), nh = i<4? h + h4[i] : 0, nw = i<4? w + w4[i] : 0; i < 4; i=mei_inc(h,w,H,W,i), nh = h+h4[i], nw = w+w4[i])
int mei_inc8(int h, int w, int H, int W, int i) {    while (++i < 8) {        if (inside(h + h8[i], w + w8[i], H, W))return i;    }    return i;}
#define mei8(nh, nw, h, w) for (int i = mei_inc8(h, w, H, W, -1), nh = i<8? h + h8[i] : 0, nw = i<8? w + w8[i] : 0; i < 8; i=mei_inc8(h,w,H,W,i), nh = h+h8[i], nw = w+w8[i])
int mei_incv(int h, int w, int H, int W, int i, vp &p) {    while (++i < sz(p)) { if (inside(h + p[i].fi, w + p[i].se, H, W))return i; }    return i;}
#define meiv(nh, nw, h, w, p) for (int i = mei_incv(h, w, H, W, -1, p), nh = i<sz(p)? h + p[i].fi : 0, nw = i<sz(p)? w + p[i].se : 0; i < sz(p); i=mei_incv(h,w,H,W,i,p), nh = h+p[i].fi, nw = w+p[i].se)
vi compress(vi &A) {    vi B = A;    sort(B);    unique(B);    vi inds(sz(B));    rep(i, sz(A)) {        int ind = lower_bound(all(B), A[i]) - B.begin();        inds[ind] = A[i];        A[i] = ind;    }    return inds;}
vi compress(vi &A, umapi& map){    vi i_v = compress(A);    rep(i, sz(i_v)){        map[i_v[i]] = i;    }    return i_v;}

t_T void out2(T head) {    cout << head;}
template<class T, class... U> void out2(T head, U ... tail) {    cout << head << " ";      out2(tail...);}
template<class T, class... U> void out(T head, U ... tail) {    cout << head << " ";        out2(tail...);    cout << "" << endl;}
t_T void out(T head) {    cout << head << endl; }
void out() { cout << "" << endl; }
#define lowerIndex(a, v) (lower_bound(all(a),v)-a.begin())
#define upperIndex(a, v) (uppereturnbound(all(a),v)-a.begin())
template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }
#define vni(name, ...) auto name = make_v<ll>(__VA_ARGS__)
#define vnb(name, ...) auto name = make_v<bool>(__VA_ARGS__)
#define vns(name, ...) auto name = make_v<string>(__VA_ARGS__)
#define vnd(name, ...) auto name = make_v<double>(__VA_ARGS__)
#define vnc(name, ...) auto name = make_v<char>(__VA_ARGS__)
#define vnp(name, ...) auto name = make_v<P>(__VA_ARGS__)
#define vn(type, name, ...) auto name = make_v<type>(__VA_ARGS__)
#define VEC vector


int N, M, H, W;
vi A, B, C;


void solve() {
    din(Q);
    while (Q--) {
        in(N);
        din(K);
        string S;
        in(S);
        vi cou('z' + 1);
        fora(s, S)cou[s]++;
        string res;
        

        if ([&]() {
            int su = 0;
            rep(c, 'a', 'z' + 1) {
                int psu = su;
                su += cou[c];
                if (su < K)continue;
                

                if (psu > 0) {
                    out((char) c);
                    return true;
                    

                } else {
                    cou[c] -= K;
                    res = c;
                    return false;
                    

                }
            }
            return false;
        }()) {
            continue;
        }
        if (sum(cou) == 0) {
            out(res);
            continue;
        }
        int lim = sum(cou) + 2;
        deb(lim);
        

        deb(cou['a']);
        deb(cou['b']);
        deb(cou['c']);
        int l = find_if(all(cou), [&](int v) { return v > 0; }) - cou.begin();
        int r = find_if(cou.begin() + l + 1, cou.end(), [&](int v) { return v > 0; }) - cou.begin();
        

        if (r == 'z' + 1) {
            int len = ceil(cou[l], K);
            res += str(len, l);
            out(res);
        } else {
            rep(c, 'a', 'z' + 1) {
                res += str(cou[c], c);
            }
            out(res);
        }
    }
}

signed main() {
    solve();
    return 0;
}
