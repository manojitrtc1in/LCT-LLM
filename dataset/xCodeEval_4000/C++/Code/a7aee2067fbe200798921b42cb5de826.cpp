



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
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} __initon;


#define ws ___ws
#define over4(o1, o2, o3, o4, name, ...) name

using sig_dou = double;
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
#define ALL(a) (a).begin(),(a).end()
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
#define all_of(S, right) all_of(ALL(S), [&](auto& v){return v right;})
template<class T> vector<T> geth(vector<vector<T>> &S, int w) {    assert(w < sz(S[0]));    vector<T> ret(sz(S));    rep(h, sz(S)) { ret[h] = S[h][w]; }    return ret;}

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
template<class V, class K>int count(const V &range, const K &k) {    int cou = 0;    fora(v, range) {        cou += v == k;    }    return cou;}


int N, M, H, W;
vi A, B, C;

void query() {
    vvi(res, 151, 10);
    res[0][0] = 0;
    res[0][1] = -1;
    res[0][2] = -1;
    res[0][3] = -1;
    res[0][4] = -1;
    res[0][5] = -1;
    res[0][6] = -1;
    res[0][7] = -1;
    res[0][8] = -1;
    res[0][9] = -1;
    res[1][0] = 1;
    res[1][1] = 0;
    res[1][2] = -1;
    res[1][3] = -1;
    res[1][4] = -1;
    res[1][5] = -1;
    res[1][6] = -1;
    res[1][7] = -1;
    res[1][8] = -1;
    res[1][9] = -1;
    res[2][0] = 2;
    res[2][1] = -1;
    res[2][2] = -1;
    res[2][3] = -1;
    res[2][4] = -1;
    res[2][5] = -1;
    res[2][6] = -1;
    res[2][7] = -1;
    res[2][8] = -1;
    res[2][9] = -1;
    res[3][0] = 3;
    res[3][1] = 1;
    res[3][2] = 0;
    res[3][3] = -1;
    res[3][4] = -1;
    res[3][5] = -1;
    res[3][6] = -1;
    res[3][7] = -1;
    res[3][8] = -1;
    res[3][9] = -1;
    res[4][0] = 4;
    res[4][1] = -1;
    res[4][2] = -1;
    res[4][3] = -1;
    res[4][4] = -1;
    res[4][5] = -1;
    res[4][6] = -1;
    res[4][7] = -1;
    res[4][8] = -1;
    res[4][9] = -1;
    res[5][0] = 5;
    res[5][1] = 2;
    res[5][2] = -1;
    res[5][3] = -1;
    res[5][4] = -1;
    res[5][5] = -1;
    res[5][6] = -1;
    res[5][7] = -1;
    res[5][8] = -1;
    res[5][9] = -1;
    res[6][0] = 6;
    res[6][1] = -1;
    res[6][2] = 1;
    res[6][3] = 0;
    res[6][4] = -1;
    res[6][5] = -1;
    res[6][6] = -1;
    res[6][7] = -1;
    res[6][8] = -1;
    res[6][9] = -1;
    res[7][0] = 7;
    res[7][1] = 3;
    res[7][2] = -1;
    res[7][3] = -1;
    res[7][4] = -1;
    res[7][5] = -1;
    res[7][6] = -1;
    res[7][7] = -1;
    res[7][8] = -1;
    res[7][9] = -1;
    res[8][0] = 8;
    res[8][1] = -1;
    res[8][2] = -1;
    res[8][3] = -1;
    res[8][4] = -1;
    res[8][5] = -1;
    res[8][6] = -1;
    res[8][7] = -1;
    res[8][8] = -1;
    res[8][9] = -1;
    res[9][0] = 9;
    res[9][1] = 4;
    res[9][2] = 2;
    res[9][3] = -1;
    res[9][4] = -1;
    res[9][5] = -1;
    res[9][6] = -1;
    res[9][7] = -1;
    res[9][8] = -1;
    res[9][9] = -1;
    res[10][0] = 19;
    res[10][1] = 9;
    res[10][2] = -1;
    res[10][3] = 1;
    res[10][4] = 0;
    res[10][5] = -1;
    res[10][6] = -1;
    res[10][7] = -1;
    res[10][8] = -1;
    res[10][9] = -1;
    res[11][0] = 29;
    res[11][1] = 5;
    res[11][2] = -1;
    res[11][3] = -1;
    res[11][4] = -1;
    res[11][5] = -1;
    res[11][6] = -1;
    res[11][7] = -1;
    res[11][8] = -1;
    res[11][9] = -1;
    res[12][0] = 39;
    res[12][1] = 19;
    res[12][2] = 3;
    res[12][3] = -1;
    res[12][4] = -1;
    res[12][5] = -1;
    res[12][6] = -1;
    res[12][7] = -1;
    res[12][8] = -1;
    res[12][9] = -1;
    res[13][0] = 49;
    res[13][1] = 6;
    res[13][2] = -1;
    res[13][3] = -1;
    res[13][4] = -1;
    res[13][5] = -1;
    res[13][6] = -1;
    res[13][7] = -1;
    res[13][8] = -1;
    res[13][9] = -1;
    res[14][0] = 59;
    res[14][1] = 29;
    res[14][2] = -1;
    res[14][3] = 2;
    res[14][4] = -1;
    res[14][5] = -1;
    res[14][6] = -1;
    res[14][7] = -1;
    res[14][8] = -1;
    res[14][9] = -1;
    res[15][0] = 69;
    res[15][1] = 7;
    res[15][2] = 4;
    res[15][3] = 9;
    res[15][4] = 1;
    res[15][5] = 0;
    res[15][6] = -1;
    res[15][7] = -1;
    res[15][8] = -1;
    res[15][9] = -1;
    res[16][0] = 79;
    res[16][1] = 39;
    res[16][2] = -1;
    res[16][3] = -1;
    res[16][4] = -1;
    res[16][5] = -1;
    res[16][6] = -1;
    res[16][7] = -1;
    res[16][8] = -1;
    res[16][9] = -1;
    res[17][0] = 89;
    res[17][1] = 8;
    res[17][2] = -1;
    res[17][3] = -1;
    res[17][4] = -1;
    res[17][5] = -1;
    res[17][6] = -1;
    res[17][7] = -1;
    res[17][8] = -1;
    res[17][9] = -1;
    res[18][0] = 99;
    res[18][1] = 49;
    res[18][2] = 5;
    res[18][3] = 3;
    res[18][4] = -1;
    res[18][5] = -1;
    res[18][6] = -1;
    res[18][7] = -1;
    res[18][8] = -1;
    res[18][9] = -1;
    res[19][0] = 199;
    res[19][1] = 18;
    res[19][2] = -1;
    res[19][3] = 19;
    res[19][4] = 9;
    res[19][5] = -1;
    res[19][6] = -1;
    res[19][7] = -1;
    res[19][8] = -1;
    res[19][9] = -1;
    res[20][0] = 299;
    res[20][1] = 59;
    res[20][2] = -1;
    res[20][3] = 8;
    res[20][4] = 2;
    res[20][5] = -1;
    res[20][6] = -1;
    res[20][7] = -1;
    res[20][8] = -1;
    res[20][9] = -1;
    res[21][0] = 399;
    res[21][1] = 28;
    res[21][2] = 6;
    res[21][3] = -1;
    res[21][4] = -1;
    res[21][5] = 1;
    res[21][6] = 0;
    res[21][7] = -1;
    res[21][8] = -1;
    res[21][9] = -1;
    res[22][0] = 499;
    res[22][1] = 69;
    res[22][2] = -1;
    res[22][3] = 4;
    res[22][4] = -1;
    res[22][5] = -1;
    res[22][6] = -1;
    res[22][7] = -1;
    res[22][8] = -1;
    res[22][9] = -1;
    res[23][0] = 599;
    res[23][1] = 38;
    res[23][2] = -1;
    res[23][3] = 29;
    res[23][4] = 8;
    res[23][5] = -1;
    res[23][6] = -1;
    res[23][7] = -1;
    res[23][8] = -1;
    res[23][9] = -1;
    res[24][0] = 699;
    res[24][1] = 79;
    res[24][2] = 7;
    res[24][3] = 18;
    res[24][4] = 19;
    res[24][5] = 9;
    res[24][6] = -1;
    res[24][7] = -1;
    res[24][8] = -1;
    res[24][9] = -1;
    res[25][0] = 799;
    res[25][1] = 48;
    res[25][2] = -1;
    res[25][3] = 7;
    res[25][4] = 3;
    res[25][5] = -1;
    res[25][6] = -1;
    res[25][7] = -1;
    res[25][8] = -1;
    res[25][9] = -1;
    res[26][0] = 899;
    res[26][1] = 89;
    res[26][2] = -1;
    res[26][3] = 5;
    res[26][4] = -1;
    res[26][5] = -1;
    res[26][6] = -1;
    res[26][7] = -1;
    res[26][8] = -1;
    res[26][9] = -1;
    res[27][0] = 999;
    res[27][1] = 58;
    res[27][2] = 17;
    res[27][3] = 39;
    res[27][4] = 7;
    res[27][5] = 2;
    res[27][6] = -1;
    res[27][7] = -1;
    res[27][8] = -1;
    res[27][9] = -1;
    res[28][0] = 1999;
    res[28][1] = 189;
    res[28][2] = -1;
    res[28][3] = 28;
    res[28][4] = 18;
    res[28][5] = -1;
    res[28][6] = 1;
    res[28][7] = 0;
    res[28][8] = -1;
    res[28][9] = -1;
    res[29][0] = 2999;
    res[29][1] = 68;
    res[29][2] = -1;
    res[29][3] = 17;
    res[29][4] = 29;
    res[29][5] = -1;
    res[29][6] = -1;
    res[29][7] = -1;
    res[29][8] = -1;
    res[29][9] = -1;
    res[30][0] = 3999;
    res[30][1] = 289;
    res[30][2] = 27;
    res[30][3] = 6;
    res[30][4] = 4;
    res[30][5] = 7;
    res[30][6] = 9;
    res[30][7] = -1;
    res[30][8] = -1;
    res[30][9] = -1;
    res[31][0] = 4999;
    res[31][1] = 78;
    res[31][2] = -1;
    res[31][3] = 49;
    res[31][4] = 6;
    res[31][5] = -1;
    res[31][6] = -1;
    res[31][7] = -1;
    res[31][8] = -1;
    res[31][9] = -1;
    res[32][0] = 5999;
    res[32][1] = 389;
    res[32][2] = -1;
    res[32][3] = 38;
    res[32][4] = 17;
    res[32][5] = -1;
    res[32][6] = 8;
    res[32][7] = -1;
    res[32][8] = -1;
    res[32][9] = -1;
    res[33][0] = 6999;
    res[33][1] = 88;
    res[33][2] = 37;
    res[33][3] = 27;
    res[33][4] = 28;
    res[33][5] = 3;
    res[33][6] = -1;
    res[33][7] = -1;
    res[33][8] = -1;
    res[33][9] = -1;
    res[34][0] = 7999;
    res[34][1] = 489;
    res[34][2] = -1;
    res[34][3] = 16;
    res[34][4] = 39;
    res[34][5] = -1;
    res[34][6] = 7;
    res[34][7] = -1;
    res[34][8] = -1;
    res[34][9] = -1;
    res[35][0] = 8999;
    res[35][1] = 98;
    res[35][2] = -1;
    res[35][3] = 59;
    res[35][4] = 5;
    res[35][5] = -1;
    res[35][6] = 2;
    res[35][7] = -1;
    res[35][8] = -1;
    res[35][9] = -1;
    res[36][0] = 9999;
    res[36][1] = 589;
    res[36][2] = 47;
    res[36][3] = 48;
    res[36][4] = 16;
    res[36][5] = 5;
    res[36][6] = 6;
    res[36][7] = 1;
    res[36][8] = 0;
    res[36][9] = -1;
    res[37][0] = 19999;
    res[37][1] = 198;
    res[37][2] = -1;
    res[37][3] = 37;
    res[37][4] = 27;
    res[37][5] = -1;
    res[37][6] = 19;
    res[37][7] = 9;
    res[37][8] = -1;
    res[37][9] = -1;
    res[38][0] = 29999;
    res[38][1] = 689;
    res[38][2] = -1;
    res[38][3] = 26;
    res[38][4] = 38;
    res[38][5] = -1;
    res[38][6] = 5;
    res[38][7] = 8;
    res[38][8] = -1;
    res[38][9] = -1;
    res[39][0] = 39999;
    res[39][1] = 298;
    res[39][2] = 57;
    res[39][3] = 69;
    res[39][4] = 49;
    res[39][5] = 4;
    res[39][6] = 18;
    res[39][7] = 7;
    res[39][8] = -1;
    res[39][9] = -1;
    res[40][0] = 49999;
    res[40][1] = 789;
    res[40][2] = -1;
    res[40][3] = 58;
    res[40][4] = 15;
    res[40][5] = -1;
    res[40][6] = 4;
    res[40][7] = 6;
    res[40][8] = -1;
    res[40][9] = -1;
    res[41][0] = 59999;
    res[41][1] = 398;
    res[41][2] = -1;
    res[41][3] = 47;
    res[41][4] = 26;
    res[41][5] = -1;
    res[41][6] = 17;
    res[41][7] = 5;
    res[41][8] = -1;
    res[41][9] = -1;
    res[42][0] = 69999;
    res[42][1] = 889;
    res[42][2] = 67;
    res[42][3] = 36;
    res[42][4] = 37;
    res[42][5] = 15;
    res[42][6] = 3;
    res[42][7] = 4;
    res[42][8] = -1;
    res[42][9] = -1;
    res[43][0] = 79999;
    res[43][1] = 498;
    res[43][2] = -1;
    res[43][3] = 79;
    res[43][4] = 48;
    res[43][5] = -1;
    res[43][6] = 16;
    res[43][7] = 3;
    res[43][8] = -1;
    res[43][9] = -1;
    res[44][0] = 89999;
    res[44][1] = 989;
    res[44][2] = -1;
    res[44][3] = 68;
    res[44][4] = 59;
    res[44][5] = -1;
    res[44][6] = 29;
    res[44][7] = 2;
    res[44][8] = -1;
    res[44][9] = -1;
    res[45][0] = 99999;
    res[45][1] = 598;
    res[45][2] = 77;
    res[45][3] = 57;
    res[45][4] = 25;
    res[45][5] = 14;
    res[45][6] = 15;
    res[45][7] = 19;
    res[45][8] = 1;
    res[45][9] = 0;
    res[46][0] = 199999;
    res[46][1] = 1989;
    res[46][2] = -1;
    res[46][3] = 46;
    res[46][4] = 36;
    res[46][5] = -1;
    res[46][6] = 28;
    res[46][7] = 18;
    res[46][8] = -1;
    res[46][9] = 1;
    res[47][0] = 299999;
    res[47][1] = 698;
    res[47][2] = -1;
    res[47][3] = 89;
    res[47][4] = 47;
    res[47][5] = -1;
    res[47][6] = 14;
    res[47][7] = 17;
    res[47][8] = -1;
    res[47][9] = 2;
    res[48][0] = 399999;
    res[48][1] = 2989;
    res[48][2] = 87;
    res[48][3] = 78;
    res[48][4] = 58;
    res[48][5] = 25;
    res[48][6] = 27;
    res[48][7] = 16;
    res[48][8] = -1;
    res[48][9] = 3;
    res[49][0] = 499999;
    res[49][1] = 798;
    res[49][2] = -1;
    res[49][3] = 67;
    res[49][4] = 69;
    res[49][5] = -1;
    res[49][6] = 13;
    res[49][7] = 15;
    res[49][8] = -1;
    res[49][9] = 4;
    res[50][0] = 599999;
    res[50][1] = 3989;
    res[50][2] = -1;
    res[50][3] = 56;
    res[50][4] = 35;
    res[50][5] = -1;
    res[50][6] = 26;
    res[50][7] = 14;
    res[50][8] = -1;
    res[50][9] = 5;
    res[51][0] = 699999;
    res[51][1] = 898;
    res[51][2] = 97;
    res[51][3] = 189;
    res[51][4] = 46;
    res[51][5] = 24;
    res[51][6] = 39;
    res[51][7] = 13;
    res[51][8] = -1;
    res[51][9] = 6;
    res[52][0] = 799999;
    res[52][1] = 4989;
    res[52][2] = -1;
    res[52][3] = 88;
    res[52][4] = 57;
    res[52][5] = -1;
    res[52][6] = 25;
    res[52][7] = 12;
    res[52][8] = -1;
    res[52][9] = 7;
    res[53][0] = 899999;
    res[53][1] = 998;
    res[53][2] = -1;
    res[53][3] = 77;
    res[53][4] = 68;
    res[53][5] = -1;
    res[53][6] = 38;
    res[53][7] = 29;
    res[53][8] = -1;
    res[53][9] = 8;
    res[54][0] = 999999;
    res[54][1] = 5989;
    res[54][2] = 197;
    res[54][3] = 66;
    res[54][4] = 79;
    res[54][5] = 35;
    res[54][6] = 24;
    res[54][7] = 28;
    res[54][8] = 11;
    res[54][9] = 9;
    res[55][0] = 1999999;
    res[55][1] = 1998;
    res[55][2] = -1;
    res[55][3] = 289;
    res[55][4] = 45;
    res[55][5] = -1;
    res[55][6] = 37;
    res[55][7] = 27;
    res[55][8] = -1;
    res[55][9] = 10;
    res[56][0] = 2999999;
    res[56][1] = 6989;
    res[56][2] = -1;
    res[56][3] = 188;
    res[56][4] = 56;
    res[56][5] = -1;
    res[56][6] = 23;
    res[56][7] = 26;
    res[56][8] = -1;
    res[56][9] = 11;
    res[57][0] = 3999999;
    res[57][1] = 2998;
    res[57][2] = 297;
    res[57][3] = 87;
    res[57][4] = 67;
    res[57][5] = 34;
    res[57][6] = 36;
    res[57][7] = 25;
    res[57][8] = -1;
    res[57][9] = 12;
    res[58][0] = 4999999;
    res[58][1] = 7989;
    res[58][2] = -1;
    res[58][3] = 76;
    res[58][4] = 78;
    res[58][5] = -1;
    res[58][6] = 49;
    res[58][7] = 24;
    res[58][8] = -1;
    res[58][9] = 13;
    res[59][0] = 5999999;
    res[59][1] = 3998;
    res[59][2] = -1;
    res[59][3] = 389;
    res[59][4] = 89;
    res[59][5] = -1;
    res[59][6] = 35;
    res[59][7] = 23;
    res[59][8] = -1;
    res[59][9] = 14;
    res[60][0] = 6999999;
    res[60][1] = 8989;
    res[60][2] = 397;
    res[60][3] = 288;
    res[60][4] = 55;
    res[60][5] = 45;
    res[60][6] = 48;
    res[60][7] = 22;
    res[60][8] = -1;
    res[60][9] = 15;
    res[61][0] = 7999999;
    res[61][1] = 4998;
    res[61][2] = -1;
    res[61][3] = 187;
    res[61][4] = 66;
    res[61][5] = -1;
    res[61][6] = 34;
    res[61][7] = 39;
    res[61][8] = -1;
    res[61][9] = 16;
    res[62][0] = 8999999;
    res[62][1] = 9989;
    res[62][2] = -1;
    res[62][3] = 86;
    res[62][4] = 77;
    res[62][5] = -1;
    res[62][6] = 47;
    res[62][7] = 38;
    res[62][8] = -1;
    res[62][9] = 17;
    res[63][0] = 9999999;
    res[63][1] = 5998;
    res[63][2] = 497;
    res[63][3] = 489;
    res[63][4] = 88;
    res[63][5] = 44;
    res[63][6] = 33;
    res[63][7] = 37;
    res[63][8] = 21;
    res[63][9] = 18;
    res[64][0] = 19999999;
    res[64][1] = 19989;
    res[64][2] = -1;
    res[64][3] = 388;
    res[64][4] = 189;
    res[64][5] = -1;
    res[64][6] = 46;
    res[64][7] = 36;
    res[64][8] = -1;
    res[64][9] = 19;
    res[65][0] = 29999999;
    res[65][1] = 6998;
    res[65][2] = -1;
    res[65][3] = 287;
    res[65][4] = 65;
    res[65][5] = -1;
    res[65][6] = 59;
    res[65][7] = 35;
    res[65][8] = -1;
    res[65][9] = 20;
    res[66][0] = 39999999;
    res[66][1] = 29989;
    res[66][2] = 597;
    res[66][3] = 96;
    res[66][4] = 76;
    res[66][5] = 55;
    res[66][6] = 45;
    res[66][7] = 34;
    res[66][8] = -1;
    res[66][9] = 21;
    res[67][0] = 49999999;
    res[67][1] = 7998;
    res[67][2] = -1;
    res[67][3] = 589;
    res[67][4] = 87;
    res[67][5] = -1;
    res[67][6] = 58;
    res[67][7] = 33;
    res[67][8] = -1;
    res[67][9] = 22;
    res[68][0] = 59999999;
    res[68][1] = 39989;
    res[68][2] = -1;
    res[68][3] = 488;
    res[68][4] = 188;
    res[68][5] = -1;
    res[68][6] = 44;
    res[68][7] = 32;
    res[68][8] = -1;
    res[68][9] = 23;
    res[69][0] = 69999999;
    res[69][1] = 8998;
    res[69][2] = 697;
    res[69][3] = 387;
    res[69][4] = 289;
    res[69][5] = 54;
    res[69][6] = 57;
    res[69][7] = 49;
    res[69][8] = -1;
    res[69][9] = 24;
    res[70][0] = 79999999;
    res[70][1] = 49989;
    res[70][2] = -1;
    res[70][3] = 196;
    res[70][4] = 75;
    res[70][5] = -1;
    res[70][6] = 43;
    res[70][7] = 48;
    res[70][8] = -1;
    res[70][9] = 25;
    res[71][0] = 89999999;
    res[71][1] = 9998;
    res[71][2] = -1;
    res[71][3] = 689;
    res[71][4] = 86;
    res[71][5] = -1;
    res[71][6] = 56;
    res[71][7] = 47;
    res[71][8] = -1;
    res[71][9] = 26;
    res[72][0] = 99999999;
    res[72][1] = 59989;
    res[72][2] = 797;
    res[72][3] = 588;
    res[72][4] = 187;
    res[72][5] = 65;
    res[72][6] = 69;
    res[72][7] = 46;
    res[72][8] = 31;
    res[72][9] = 27;
    res[73][0] = 199999999;
    res[73][1] = 19998;
    res[73][2] = -1;
    res[73][3] = 487;
    res[73][4] = 288;
    res[73][5] = -1;
    res[73][6] = 55;
    res[73][7] = 45;
    res[73][8] = -1;
    res[73][9] = 28;
    res[74][0] = 299999999;
    res[74][1] = 69989;
    res[74][2] = -1;
    res[74][3] = 296;
    res[74][4] = 389;
    res[74][5] = -1;
    res[74][6] = 68;
    res[74][7] = 44;
    res[74][8] = -1;
    res[74][9] = 29;
    res[75][0] = 399999999;
    res[75][1] = 29998;
    res[75][2] = 897;
    res[75][3] = 789;
    res[75][4] = 85;
    res[75][5] = 64;
    res[75][6] = 54;
    res[75][7] = 43;
    res[75][8] = -1;
    res[75][9] = 30;
    res[76][0] = 499999999;
    res[76][1] = 79989;
    res[76][2] = -1;
    res[76][3] = 688;
    res[76][4] = 186;
    res[76][5] = -1;
    res[76][6] = 67;
    res[76][7] = 42;
    res[76][8] = -1;
    res[76][9] = 31;
    res[77][0] = 599999999;
    res[77][1] = 39998;
    res[77][2] = -1;
    res[77][3] = 587;
    res[77][4] = 287;
    res[77][5] = -1;
    res[77][6] = 53;
    res[77][7] = 59;
    res[77][8] = -1;
    res[77][9] = 32;
    res[78][0] = 699999999;
    res[78][1] = 89989;
    res[78][2] = 997;
    res[78][3] = 396;
    res[78][4] = 388;
    res[78][5] = 75;
    res[78][6] = 66;
    res[78][7] = 58;
    res[78][8] = -1;
    res[78][9] = 33;
    res[79][0] = 799999999;
    res[79][1] = 49998;
    res[79][2] = -1;
    res[79][3] = 889;
    res[79][4] = 489;
    res[79][5] = -1;
    res[79][6] = 79;
    res[79][7] = 57;
    res[79][8] = -1;
    res[79][9] = 34;
    res[80][0] = 899999999;
    res[80][1] = 99989;
    res[80][2] = -1;
    res[80][3] = 788;
    res[80][4] = 95;
    res[80][5] = -1;
    res[80][6] = 65;
    res[80][7] = 56;
    res[80][8] = -1;
    res[80][9] = 35;
    res[81][0] = 999999999;
    res[81][1] = 59998;
    res[81][2] = 1997;
    res[81][3] = 687;
    res[81][4] = 286;
    res[81][5] = 74;
    res[81][6] = 78;
    res[81][7] = 55;
    res[81][8] = 41;
    res[81][9] = 36;
    res[82][0] = 1999999999;
    res[82][1] = 199989;
    res[82][2] = -1;
    res[82][3] = 496;
    res[82][4] = 387;
    res[82][5] = -1;
    res[82][6] = 64;
    res[82][7] = 54;
    res[82][8] = -1;
    res[82][9] = 37;
    res[83][0] = 2999999999;
    res[83][1] = 69998;
    res[83][2] = -1;
    res[83][3] = 989;
    res[83][4] = 488;
    res[83][5] = -1;
    res[83][6] = 77;
    res[83][7] = 53;
    res[83][8] = -1;
    res[83][9] = 38;
    res[84][0] = 3999999999;
    res[84][1] = 299989;
    res[84][2] = 2997;
    res[84][3] = 888;
    res[84][4] = 589;
    res[84][5] = 85;
    res[84][6] = 63;
    res[84][7] = 52;
    res[84][8] = -1;
    res[84][9] = 39;
    res[85][0] = 4999999999;
    res[85][1] = 79998;
    res[85][2] = -1;
    res[85][3] = 787;
    res[85][4] = 195;
    res[85][5] = -1;
    res[85][6] = 76;
    res[85][7] = 69;
    res[85][8] = -1;
    res[85][9] = 40;
    res[86][0] = 5999999999;
    res[86][1] = 399989;
    res[86][2] = -1;
    res[86][3] = 596;
    res[86][4] = 386;
    res[86][5] = -1;
    res[86][6] = 89;
    res[86][7] = 68;
    res[86][8] = -1;
    res[86][9] = 41;
    res[87][0] = 6999999999;
    res[87][1] = 89998;
    res[87][2] = 3997;
    res[87][3] = 1989;
    res[87][4] = 487;
    res[87][5] = 84;
    res[87][6] = 75;
    res[87][7] = 67;
    res[87][8] = -1;
    res[87][9] = 42;
    res[88][0] = 7999999999;
    res[88][1] = 499989;
    res[88][2] = -1;
    res[88][3] = 988;
    res[88][4] = 588;
    res[88][5] = -1;
    res[88][6] = 88;
    res[88][7] = 66;
    res[88][8] = -1;
    res[88][9] = 43;
    res[89][0] = 8999999999;
    res[89][1] = 99998;
    res[89][2] = -1;
    res[89][3] = 887;
    res[89][4] = 689;
    res[89][5] = -1;
    res[89][6] = 74;
    res[89][7] = 65;
    res[89][8] = -1;
    res[89][9] = 44;
    res[90][0] = 9999999999;
    res[90][1] = 599989;
    res[90][2] = 4997;
    res[90][3] = 696;
    res[90][4] = 295;
    res[90][5] = 185;
    res[90][6] = 87;
    res[90][7] = 64;
    res[90][8] = 51;
    res[90][9] = 45;
    res[91][0] = 19999999999;
    res[91][1] = 199998;
    res[91][2] = -1;
    res[91][3] = 2989;
    res[91][4] = 486;
    res[91][5] = -1;
    res[91][6] = 73;
    res[91][7] = 63;
    res[91][8] = -1;
    res[91][9] = 46;
    res[92][0] = 29999999999;
    res[92][1] = 699989;
    res[92][2] = -1;
    res[92][3] = 1988;
    res[92][4] = 587;
    res[92][5] = -1;
    res[92][6] = 86;
    res[92][7] = 62;
    res[92][8] = -1;
    res[92][9] = 47;
    res[93][0] = 39999999999;
    res[93][1] = 299998;
    res[93][2] = 5997;
    res[93][3] = 987;
    res[93][4] = 688;
    res[93][5] = 94;
    res[93][6] = 189;
    res[93][7] = 79;
    res[93][8] = -1;
    res[93][9] = 48;
    res[94][0] = 49999999999;
    res[94][1] = 799989;
    res[94][2] = -1;
    res[94][3] = 796;
    res[94][4] = 789;
    res[94][5] = -1;
    res[94][6] = 85;
    res[94][7] = 78;
    res[94][8] = -1;
    res[94][9] = 49;
    res[95][0] = 59999999999;
    res[95][1] = 399998;
    res[95][2] = -1;
    res[95][3] = 3989;
    res[95][4] = 395;
    res[95][5] = -1;
    res[95][6] = 188;
    res[95][7] = 77;
    res[95][8] = -1;
    res[95][9] = 50;
    res[96][0] = 69999999999;
    res[96][1] = 899989;
    res[96][2] = 6997;
    res[96][3] = 2988;
    res[96][4] = 586;
    res[96][5] = 285;
    res[96][6] = 84;
    res[96][7] = 76;
    res[96][8] = -1;
    res[96][9] = 51;
    res[97][0] = 79999999999;
    res[97][1] = 499998;
    res[97][2] = -1;
    res[97][3] = 1987;
    res[97][4] = 687;
    res[97][5] = -1;
    res[97][6] = 187;
    res[97][7] = 75;
    res[97][8] = -1;
    res[97][9] = 52;
    res[98][0] = 89999999999;
    res[98][1] = 999989;
    res[98][2] = -1;
    res[98][3] = 896;
    res[98][4] = 788;
    res[98][5] = -1;
    res[98][6] = 83;
    res[98][7] = 74;
    res[98][8] = -1;
    res[98][9] = 53;
    res[99][0] = 99999999999;
    res[99][1] = 599998;
    res[99][2] = 7997;
    res[99][3] = 4989;
    res[99][4] = 889;
    res[99][5] = 194;
    res[99][6] = 186;
    res[99][7] = 73;
    res[99][8] = 61;
    res[99][9] = 54;
    res[100][0] = 199999999999;
    res[100][1] = 1999989;
    res[100][2] = -1;
    res[100][3] = 3988;
    res[100][4] = 495;
    res[100][5] = -1;
    res[100][6] = 289;
    res[100][7] = 72;
    res[100][8] = -1;
    res[100][9] = 55;
    res[101][0] = 299999999999;
    res[101][1] = 699998;
    res[101][2] = -1;
    res[101][3] = 2987;
    res[101][4] = 686;
    res[101][5] = -1;
    res[101][6] = 185;
    res[101][7] = 89;
    res[101][8] = -1;
    res[101][9] = 56;
    res[102][0] = 399999999999;
    res[102][1] = 2999989;
    res[102][2] = 8997;
    res[102][3] = 996;
    res[102][4] = 787;
    res[102][5] = 385;
    res[102][6] = 288;
    res[102][7] = 88;
    res[102][8] = -1;
    res[102][9] = 57;
    res[103][0] = 499999999999;
    res[103][1] = 799998;
    res[103][2] = -1;
    res[103][3] = 5989;
    res[103][4] = 888;
    res[103][5] = -1;
    res[103][6] = 184;
    res[103][7] = 87;
    res[103][8] = -1;
    res[103][9] = 58;
    res[104][0] = 599999999999;
    res[104][1] = 3999989;
    res[104][2] = -1;
    res[104][3] = 4988;
    res[104][4] = 989;
    res[104][5] = -1;
    res[104][6] = 287;
    res[104][7] = 86;
    res[104][8] = -1;
    res[104][9] = 59;
    res[105][0] = 699999999999;
    res[105][1] = 899998;
    res[105][2] = 9997;
    res[105][3] = 3987;
    res[105][4] = 595;
    res[105][5] = 294;
    res[105][6] = 93;
    res[105][7] = 85;
    res[105][8] = -1;
    res[105][9] = 60;
    res[106][0] = 799999999999;
    res[106][1] = 4999989;
    res[106][2] = -1;
    res[106][3] = 1996;
    res[106][4] = 786;
    res[106][5] = -1;
    res[106][6] = 286;
    res[106][7] = 84;
    res[106][8] = -1;
    res[106][9] = 61;
    res[107][0] = 899999999999;
    res[107][1] = 999998;
    res[107][2] = -1;
    res[107][3] = 6989;
    res[107][4] = 887;
    res[107][5] = -1;
    res[107][6] = 389;
    res[107][7] = 83;
    res[107][8] = -1;
    res[107][9] = 62;
    res[108][0] = 999999999999;
    res[108][1] = 5999989;
    res[108][2] = 19997;
    res[108][3] = 5988;
    res[108][4] = 988;
    res[108][5] = 485;
    res[108][6] = 285;
    res[108][7] = 82;
    res[108][8] = 71;
    res[108][9] = 63;
    res[109][0] = 1999999999999;
    res[109][1] = 1999998;
    res[109][2] = -1;
    res[109][3] = 4987;
    res[109][4] = 1989;
    res[109][5] = -1;
    res[109][6] = 388;
    res[109][7] = 189;
    res[109][8] = -1;
    res[109][9] = 64;
    res[110][0] = 2999999999999;
    res[110][1] = 6999989;
    res[110][2] = -1;
    res[110][3] = 2996;
    res[110][4] = 695;
    res[110][5] = -1;
    res[110][6] = 284;
    res[110][7] = 188;
    res[110][8] = -1;
    res[110][9] = 65;
    res[111][0] = 3999999999999;
    res[111][1] = 2999998;
    res[111][2] = 29997;
    res[111][3] = 7989;
    res[111][4] = 886;
    res[111][5] = 394;
    res[111][6] = 387;
    res[111][7] = 187;
    res[111][8] = -1;
    res[111][9] = 66;
    res[112][0] = 4999999999999;
    res[112][1] = 7999989;
    res[112][2] = -1;
    res[112][3] = 6988;
    res[112][4] = 987;
    res[112][5] = -1;
    res[112][6] = 193;
    res[112][7] = 186;
    res[112][8] = -1;
    res[112][9] = 67;
    res[113][0] = 5999999999999;
    res[113][1] = 3999998;
    res[113][2] = -1;
    res[113][3] = 5987;
    res[113][4] = 1988;
    res[113][5] = -1;
    res[113][6] = 386;
    res[113][7] = 185;
    res[113][8] = -1;
    res[113][9] = 68;
    res[114][0] = 6999999999999;
    res[114][1] = 8999989;
    res[114][2] = 39997;
    res[114][3] = 3996;
    res[114][4] = 2989;
    res[114][5] = 585;
    res[114][6] = 489;
    res[114][7] = 184;
    res[114][8] = -1;
    res[114][9] = 69;
    res[115][0] = 7999999999999;
    res[115][1] = 4999998;
    res[115][2] = -1;
    res[115][3] = 8989;
    res[115][4] = 795;
    res[115][5] = -1;
    res[115][6] = 385;
    res[115][7] = 183;
    res[115][8] = -1;
    res[115][9] = 70;
    res[116][0] = 8999999999999;
    res[116][1] = 9999989;
    res[116][2] = -1;
    res[116][3] = 7988;
    res[116][4] = 986;
    res[116][5] = -1;
    res[116][6] = 488;
    res[116][7] = 92;
    res[116][8] = -1;
    res[116][9] = 71;
    res[117][0] = 9999999999999;
    res[117][1] = 5999998;
    res[117][2] = 49997;
    res[117][3] = 6987;
    res[117][4] = 1987;
    res[117][5] = 494;
    res[117][6] = 384;
    res[117][7] = 289;
    res[117][8] = 81;
    res[117][9] = 72;
    res[118][0] = 19999999999999;
    res[118][1] = 19999989;
    res[118][2] = -1;
    res[118][3] = 4996;
    res[118][4] = 2988;
    res[118][5] = -1;
    res[118][6] = 487;
    res[118][7] = 288;
    res[118][8] = -1;
    res[118][9] = 73;
    res[119][0] = 29999999999999;
    res[119][1] = 6999998;
    res[119][2] = -1;
    res[119][3] = 9989;
    res[119][4] = 3989;
    res[119][5] = -1;
    res[119][6] = 293;
    res[119][7] = 287;
    res[119][8] = -1;
    res[119][9] = 74;
    res[120][0] = 39999999999999;
    res[120][1] = 29999989;
    res[120][2] = 59997;
    res[120][3] = 8988;
    res[120][4] = 895;
    res[120][5] = 685;
    res[120][6] = 486;
    res[120][7] = 286;
    res[120][8] = -1;
    res[120][9] = 75;
    res[121][0] = 49999999999999;
    res[121][1] = 7999998;
    res[121][2] = -1;
    res[121][3] = 7987;
    res[121][4] = 1986;
    res[121][5] = -1;
    res[121][6] = 589;
    res[121][7] = 285;
    res[121][8] = -1;
    res[121][9] = 76;
    res[122][0] = 59999999999999;
    res[122][1] = 39999989;
    res[122][2] = -1;
    res[122][3] = 5996;
    res[122][4] = 2987;
    res[122][5] = -1;
    res[122][6] = 485;
    res[122][7] = 284;
    res[122][8] = -1;
    res[122][9] = 77;
    res[123][0] = 69999999999999;
    res[123][1] = 8999998;
    res[123][2] = 69997;
    res[123][3] = 19989;
    res[123][4] = 3988;
    res[123][5] = 594;
    res[123][6] = 588;
    res[123][7] = 283;
    res[123][8] = -1;
    res[123][9] = 78;
    res[124][0] = 79999999999999;
    res[124][1] = 49999989;
    res[124][2] = -1;
    res[124][3] = 9988;
    res[124][4] = 4989;
    res[124][5] = -1;
    res[124][6] = 484;
    res[124][7] = 192;
    res[124][8] = -1;
    res[124][9] = 79;
    res[125][0] = 89999999999999;
    res[125][1] = 9999998;
    res[125][2] = -1;
    res[125][3] = 8987;
    res[125][4] = 995;
    res[125][5] = -1;
    res[125][6] = 587;
    res[125][7] = 389;
    res[125][8] = -1;
    res[125][9] = 80;
    res[126][0] = 99999999999999;
    res[126][1] = 59999989;
    res[126][2] = 79997;
    res[126][3] = 6996;
    res[126][4] = 2986;
    res[126][5] = 785;
    res[126][6] = 393;
    res[126][7] = 388;
    res[126][8] = 91;
    res[126][9] = 81;
    res[127][0] = 199999999999999;
    res[127][1] = 19999998;
    res[127][2] = -1;
    res[127][3] = 29989;
    res[127][4] = 3987;
    res[127][5] = -1;
    res[127][6] = 586;
    res[127][7] = 387;
    res[127][8] = -1;
    res[127][9] = 82;
    res[128][0] = 299999999999999;
    res[128][1] = 69999989;
    res[128][2] = -1;
    res[128][3] = 19988;
    res[128][4] = 4988;
    res[128][5] = -1;
    res[128][6] = 689;
    res[128][7] = 386;
    res[128][8] = -1;
    res[128][9] = 83;
    res[129][0] = 399999999999999;
    res[129][1] = 29999998;
    res[129][2] = 89997;
    res[129][3] = 9987;
    res[129][4] = 5989;
    res[129][5] = 694;
    res[129][6] = 585;
    res[129][7] = 385;
    res[129][8] = -1;
    res[129][9] = 84;
    res[130][0] = 499999999999999;
    res[130][1] = 79999989;
    res[130][2] = -1;
    res[130][3] = 7996;
    res[130][4] = 1995;
    res[130][5] = -1;
    res[130][6] = 688;
    res[130][7] = 384;
    res[130][8] = -1;
    res[130][9] = 85;
    res[131][0] = 599999999999999;
    res[131][1] = 39999998;
    res[131][2] = -1;
    res[131][3] = 39989;
    res[131][4] = 3986;
    res[131][5] = -1;
    res[131][6] = 584;
    res[131][7] = 383;
    res[131][8] = -1;
    res[131][9] = 86;
    res[132][0] = 699999999999999;
    res[132][1] = 89999989;
    res[132][2] = 99997;
    res[132][3] = 29988;
    res[132][4] = 4987;
    res[132][5] = 885;
    res[132][6] = 687;
    res[132][7] = 292;
    res[132][8] = -1;
    res[132][9] = 87;
    res[133][0] = 799999999999999;
    res[133][1] = 49999998;
    res[133][2] = -1;
    res[133][3] = 19987;
    res[133][4] = 5988;
    res[133][5] = -1;
    res[133][6] = 493;
    res[133][7] = 489;
    res[133][8] = -1;
    res[133][9] = 88;
    res[134][0] = 899999999999999;
    res[134][1] = 99999989;
    res[134][2] = -1;
    res[134][3] = 8996;
    res[134][4] = 6989;
    res[134][5] = -1;
    res[134][6] = 686;
    res[134][7] = 488;
    res[134][8] = -1;
    res[134][9] = 89;
    res[135][0] = 999999999999999;
    res[135][1] = 59999998;
    res[135][2] = 199997;
    res[135][3] = 49989;
    res[135][4] = 2995;
    res[135][5] = 794;
    res[135][6] = 789;
    res[135][7] = 487;
    res[135][8] = 191;
    res[135][9] = 90;
    res[136][0] = 1999999999999999;
    res[136][1] = 199999989;
    res[136][2] = -1;
    res[136][3] = 39988;
    res[136][4] = 4986;
    res[136][5] = -1;
    res[136][6] = 685;
    res[136][7] = 486;
    res[136][8] = -1;
    res[136][9] = 181;
    res[137][0] = 2999999999999999;
    res[137][1] = 69999998;
    res[137][2] = -1;
    res[137][3] = 29987;
    res[137][4] = 5987;
    res[137][5] = -1;
    res[137][6] = 788;
    res[137][7] = 485;
    res[137][8] = -1;
    res[137][9] = 182;
    res[138][0] = 3999999999999999;
    res[138][1] = 299999989;
    res[138][2] = 299997;
    res[138][3] = 9996;
    res[138][4] = 6988;
    res[138][5] = 985;
    res[138][6] = 684;
    res[138][7] = 484;
    res[138][8] = -1;
    res[138][9] = 183;
    res[139][0] = 4999999999999999;
    res[139][1] = 79999998;
    res[139][2] = -1;
    res[139][3] = 59989;
    res[139][4] = 7989;
    res[139][5] = -1;
    res[139][6] = 787;
    res[139][7] = 483;
    res[139][8] = -1;
    res[139][9] = 184;
    res[140][0] = 5999999999999999;
    res[140][1] = 399999989;
    res[140][2] = -1;
    res[140][3] = 49988;
    res[140][4] = 3995;
    res[140][5] = -1;
    res[140][6] = 593;
    res[140][7] = 392;
    res[140][8] = -1;
    res[140][9] = 185;
    res[141][0] = 6999999999999999;
    res[141][1] = 89999998;
    res[141][2] = 399997;
    res[141][3] = 39987;
    res[141][4] = 5986;
    res[141][5] = 894;
    res[141][6] = 786;
    res[141][7] = 589;
    res[141][8] = -1;
    res[141][9] = 186;
    res[142][0] = 7999999999999999;
    res[142][1] = 499999989;
    res[142][2] = -1;
    res[142][3] = 19996;
    res[142][4] = 6987;
    res[142][5] = -1;
    res[142][6] = 889;
    res[142][7] = 588;
    res[142][8] = -1;
    res[142][9] = 187;
    res[143][0] = 8999999999999999;
    res[143][1] = 99999998;
    res[143][2] = -1;
    res[143][3] = 69989;
    res[143][4] = 7988;
    res[143][5] = -1;
    res[143][6] = 785;
    res[143][7] = 587;
    res[143][8] = -1;
    res[143][9] = 188;
    res[144][0] = 9999999999999999;
    res[144][1] = 599999989;
    res[144][2] = 499997;
    res[144][3] = 59988;
    res[144][4] = 8989;
    res[144][5] = 1985;
    res[144][6] = 888;
    res[144][7] = 586;
    res[144][8] = 291;
    res[144][9] = 189;
    res[145][0] = 19999999999999999;
    res[145][1] = 199999998;
    res[145][2] = -1;
    res[145][3] = 49987;
    res[145][4] = 4995;
    res[145][5] = -1;
    res[145][6] = 784;
    res[145][7] = 585;
    res[145][8] = -1;
    res[145][9] = 190;
    res[146][0] = 29999999999999999;
    res[146][1] = 699999989;
    res[146][2] = -1;
    res[146][3] = 29996;
    res[146][4] = 6986;
    res[146][5] = -1;
    res[146][6] = 887;
    res[146][7] = 584;
    res[146][8] = -1;
    res[146][9] = 281;
    res[147][0] = 39999999999999999;
    res[147][1] = 299999998;
    res[147][2] = 599997;
    res[147][3] = 79989;
    res[147][4] = 7987;
    res[147][5] = 994;
    res[147][6] = 693;
    res[147][7] = 583;
    res[147][8] = -1;
    res[147][9] = 282;
    res[148][0] = 49999999999999999;
    res[148][1] = 799999989;
    res[148][2] = -1;
    res[148][3] = 69988;
    res[148][4] = 8988;
    res[148][5] = -1;
    res[148][6] = 886;
    res[148][7] = 492;
    res[148][8] = -1;
    res[148][9] = 283;
    res[149][0] = 59999999999999999;
    res[149][1] = 399999998;
    res[149][2] = -1;
    res[149][3] = 59987;
    res[149][4] = 9989;
    res[149][5] = -1;
    res[149][6] = 989;
    res[149][7] = 689;
    res[149][8] = -1;
    res[149][9] = 284;
    res[150][0] = 69999999999999999;
    res[150][1] = 899999989;
    res[150][2] = 699997;
    res[150][3] = 39996;
    res[150][4] = 5995;
    res[150][5] = 2985;
    res[150][6] = 885;
    res[150][7] = 688;
    res[150][8] = -1;
    res[150][9] = 285;


    din(Q);
    rep(_, Q) {
        din(N, K);
        out(res[N][K]);
    }

}
void solve() {

    query();

}

signed main() {
    solve();
    return 0;
}