












using namespace std;


struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(3);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} id8;









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

























using mapi = map<int, int>;
using mapd = map<dou, int>;
using mapc = map<char, int>;
using maps = map<str, int>;
using seti = set<int>;
using setd = set<dou>;
using setc = set<char>;
using sets = set<str>;
using qui = queue<int>;





























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














inline void sort(string &a) { sort(all(a)); }
t_T inline void sort(vector<T> &a) { sort(all(a)); };
t_T inline void rsort(vector<T> &a) { sort(all(a), greater<T>()); };
template<class U> inline void sortp(vector<U> &a, vector<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    sort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;;    }};



template<class U> inline void id5(vector<U> &a, vector<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    rsort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;    }};
template<typename V, typename T>
void fill(V &xx, const T vall) {xx = vall;}
template<typename V, typename T>
void fill(vector<V> &vecc, const T vall) {for (auto &&vx: vecc) fill(vx, vall);}



template<typename T = int> T _in() {T x;cin >> x;return (x);}





















template<typename W, typename H> void resize(W &vec_, const H head) { vec_.resize(head); }
template<typename W, typename H, typename ... T> void resize(W &vec_, const H &head, const T ... tail) {vec_.resize(head);for (auto &v: vec_)resize(v, tail...);}


string sin() { return _in<string>(); }
ll lin() { return _in<ll>(); }
t_T void na(vector<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i];}


t_T void nad(vector<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i], a[i]--;}
template<class T, class U> void na2(vector<T> &a, vector<U> &b, ll n) {a.resize(n);b.resize(n);rep(i, n)cin >> a[i] >> b[i];}

template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {a.resize(n);b.resize(n);c.resize(n);rep(i, n)cin >> a[i] >> b[i] >> c[i];}










constexpr int id3 =20;
constexpr int id2 =12;
string id1(const int &v) { if (abs(v) == inf || abs(v) == linf)return "e"; else return to_string(v); }
template<class T> string id1(const T &a) {stringstream ss;ss << a;return ss.str();}
template<class T> string id1(const vector<T> &a, ll W = inf) {    stringstream ss;    if (W == inf)W = min(sz(a), id3);    if (sz(a) == 0)return ss.str();    rep(i, W) {        ss << id1(a[i]);        if (typeid(a[i]) == typeid(P)) { ss << endl; } else { ss << " "; }    }    return ss.str();}
template<class T> string id1(const vector<vector<T> > &a, vi H, vi W, int key = -1) {    stringstream ss;    ss << endl;    vi lens(sz(W));    fora(h, H) {        rep(wi, sz(W)) {            lens[wi] = max(lens[wi], sz(id1(a[h][W[wi]])) + 1);            lens[wi] = max(lens[wi], sz(id1(W[wi])) + 1);        }    }    if (key == -1)ss << " *|"; else ss << " " << key << "|";    int wi = 0;    fora(w, W) {        ss << std::right << std::setw(lens[wi]) << w;        wi++;    }    ss << "" << endl;    rep(i, sz(W))rep(_, lens[i]) ss << "_";    rep(i, 3)ss << "_";    ss << "" << endl;    fora(h, H) {        ss << std::right << std::setw(2) << h << "|";        int wi = 0;        fora(w, W) {            ss << std::right << std::setw(lens[wi]) << id1(a[h][w]);            wi++;        }        ss << "" << endl;    }    return ss.str();}
template<class T> string id1(const vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {    H = (H != inf) ? H : min({H, sz(a), id2});    W = min({W, sz(a[0]), id2});    vi hs, ws;    rep(h, H) { hs.push_back(h); }    rep(w, W) { ws.push_back(w); }    return id1(a, hs, ws, key);}
template<class T> string id1(const vector<vector<vector<T> > > &a, ll H = inf) {    stringstream ss;    if (H == inf)H = id2;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << id1(a[i], inf, inf, i);    }    return ss.str();}
template<class T, size_t A> string id1(T (&a)[A]) { return id1(vector<T>(begin(a), end(a))); }
template<class T, size_t A, size_t B> string id1(T (&a)[A][B]) { return id1(vector<vector<T> >(begin(a), end(a))); }
template<class T, size_t A, size_t B, size_t C> string id1(T (&a)[A][B][C]) { return id1(vector<vector<vector<T> > >(begin(a), end(a))); }






















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

vi id0(int v) {    vi res;    double lim = std::sqrt(v);    rep(i, 1, lim+1){        if (v % i == 0) {            res.pb(i);            if (i != v / i)res.pb(v / i);        }    }    return res;}
vb isPrime;
vi primes;

void setPrime() {    int len = 4010101;    isPrime.resize(4010101);    fill(isPrime, true);    isPrime[0] = isPrime[1] = false;    for (int i = 2; i <= sqrt(len) + 5; ++i) {        if (!isPrime[i])continue;        for (int j = 2; i * j < len; ++j) {            isPrime[i * j] = false;        }    }    rep(i, len)if (isPrime[i])primes.pb(i);}

vi factorization(int v) {    int tv = v;    vi res;    if (isPrime.size() == 0)setPrime();    for (auto &&p :primes) {        if (v % p == 0)res.push_back(p);        while (v % p == 0) {            v /= p;        }        if (v == 1 || p * p > tv)break;    }    if (v > 1)res.pb(v);    return res;}
inline bool inside(int h, int w, int H, int W) { return h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { return l <= v && v < r; }


t_T vector<T> ruiv(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    return ret;}




t_T vector<T> imo(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];    return ret;}


ll u0(ll a) { return a < 0 ? 0 : a; }
t_T vector<T> u(const vector<T> &a) {
    vector<T> ret = a;fora(v, ret)v = u0(v);return ret;}


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
void id6(bool a) {
    if (a)cout << "id6" << endl;
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

    if (ok < ng)while (ng - ok > 1) { _mgrbody } else while (ok - ng > 1) { _mgrbody }
    return ok;
}

template<class F> inline int mgr(int ok, int ng, int second, F f) {

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

template<class T, class U> inline bool chma(T &a, const U &b) {if (a < b) {a = b;return true;}return false;}
template<class U> inline bool chma(const U &b) { return chma(ma, b); }
template<class T, class U> inline bool chmi(T &a, const U &b) {    if (b < a) {        a = b;        return true;    }    return false;}
template<class U> inline bool chmi(const U &b) { return chmi(mi, b); }

int max(vi &a) {    int res = a[0];    fora(v, a) {        res = max(res, v);    }    return res;}
int min(vi &a) {    int res = a[0];    fora(v, a) {        res = min(res, v);    }    return res;}
template<typename T> class fixed_point        : T {public:    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }};template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }
constexpr ll h4[] = {1, -1, 0, 0};
constexpr ll w4[] = {0, 0, -1, 1};
constexpr ll h8[] = {0, 1, 0, -1, -1, 1, 1, -1};
constexpr ll w8[] = {1, 0, -1, 0, 1, -1, 1, -1};
int mei_inc(int h, int w, int H, int W, int i) {while (++i < 4) { if (inside(h + h4[i], w + w4[i], H, W))return i; }return i;}

int id7(int h, int w, int H, int W, int i) {    while (++i < 8) {        if (inside(h + h8[i], w + w8[i], H, W))return i;    }    return i;}

int id4(int h, int w, int H, int W, int i, vp &p) {    while (++i < sz(p)) { if (inside(h + p[i].fi, w + p[i].se, H, W))return i; }    return i;}

vi compress(vi &A) {    vi B = A;    sort(B);    unique(B);    vi inds(sz(B));    rep(i, sz(A)) {        int ind = lower_bound(all(B), A[i]) - B.begin();        inds[ind] = A[i];        A[i] = ind;    }    return inds;}
vi compress(vi &A, umapi& map){    vi i_v = compress(A);    rep(i, sz(i_v)){        map[i_v[i]] = i;    }    return i_v;}

t_T void out2(T head) {    cout << head;}
template<class T, class... U> void out2(T head, U ... tail) {    cout << head << " ";      out2(tail...);}
template<class T, class... U> void out(T head, U ... tail) {    cout << head << " ";        out2(tail...);    cout << "" << endl;}
t_T void out(T head) {    cout << head << endl; }
void out() { cout << "" << endl; }


template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }










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
