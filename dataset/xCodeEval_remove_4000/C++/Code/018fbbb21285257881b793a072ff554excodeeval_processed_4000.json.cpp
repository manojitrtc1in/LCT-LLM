














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









using dou = double;
using itn = int;
using str = string;
using bo= bool;

using P = pair<ll, ll>;










using vi = v_<ll>;
using vb = v_<bool>;
using vs = v_<string>;
using vd = v_<double>;
using vc = v_<char>;
using vp = v_<P>;
























using mapi = map<int, int>;
using mapd = map<dou, int>;
using mapc = map<char, int>;
using maps = map<str, int>;
using seti = set<int>;
using setd = set<dou>;
using setc = set<char>;
using sets = set<str>;
using qui = queue<int>;





























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













inline void sort(string &a) { sort(all(a)); }
t_T inline void sort(v_<T> &a) { sort(all(a)); };
t_T inline void rsort(v_<T> &a) { sort(all(a), greater<T>()); };
template<class U> inline void sortp(v_<U> &a, v_<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    sort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;;    }};



template<class U> inline void id3(v_<U> &a, v_<U> &b) {    vp c;    int n = sz(a);    assert(n == sz(b));    rep(i, n)c.eb(a[i], b[i]);    rsort(c);    rep(i, n) {        a[i] = c[i].first;        b[i] = c[i].second;    }};
template<typename V, typename T>
void fill(V &xx, const T vall) {xx = vall;}
template<typename V, typename T>
void fill(v_<V> &vecc, const T vall) {for (auto &&vx: vecc) fill(vx, vall);}



template<typename T = int> T _in() {T x;cin >> x;r_ (x);}





















template<typename W, typename H> void resize(W &vec_, const H head) { vec_.resize(head); }
template<typename W, typename H, typename ... T> void resize(W &vec_, const H &head, const T ... tail) {vec_.resize(head);for (auto &v: vec_)resize(v, tail...);}


string sin() { r_ _in<string>(); }
ll lin() { r_ _in<ll>(); }
t_T void na(v_<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i];}


t_T void nad(v_<T> &a, ll n) {a.resize(n);rep(i, n)cin >> a[i], a[i]--;}
template<class T, class U> void na2(v_<T> &a, v_<U> &b, ll n) {a.resize(n);b.resize(n);rep(i, n)cin >> a[i] >> b[i];}

template<class T, class U, class W> void na3(v_<T> &a, v_<U> &b, v_<W> &c, ll n) {a.resize(n);b.resize(n);c.resize(n);rep(i, n)cin >> a[i] >> b[i] >> c[i];}










t_T string id8(v_<T> &a, ll W = inf) {    stringstream ss;    if (W == inf)W = min(sz(a), 20ll);    if (sz(a) == 0)r_ ss.str();    rep(i, W) {        ss << a[i];        if (typeid(a[i]) == typeid(P)) { ss << endl; } else { ss << " "; }    }    r_ ss.str();}
t_T string id8(v_<v_<T> > &a, vi H, vi W, int key = -1) {    stringstream ss;    ss << endl;    vi lens(sz(W));    fora(h, H) {        rep(wi, sz(W)) {            int v = a[h][W[wi]];            str s = tos(v);            if (abs(v) == inf || abs(v) == INF<T>())s = "e";            lens[wi] = max(lens[wi], sz(s) + 1);            lens[wi] = max(lens[wi], sz(tos(W[wi])) + 1);        }    }    if (key == -1)ss << " *|"; else ss << " " << key << "|";    int wi = 0;    fora(w, W) {        ss << std::right << std::setw(lens[wi]) << w;        wi++;    }    ss << "" << endl;    rep(i, sz(W))rep(_, lens[i]) ss << "_";    rep(i, 3)ss << "_";    ss << "" << endl;    fora(h, H) {        ss << std::right << std::setw(2) << h << "|";        int wi = 0;        fora(w, W) {            str s = tos(a[h][w]);            if (abs(a[h][w]) == inf || abs(a[h][w]) == INF<T>())s = "e";            ss << std::right << std::setw(lens[wi]) << s;            wi++;        }        ss << "" << endl;    }    r_ ss.str();}
t_T string id8(v_<v_<T> > &a, ll H = inf, ll W = inf, int key = -1) {    H = (H != inf) ? H : min({H, sz(a), 12ll});    W = min({W, sz(a[0]), 12ll});    vi hs, ws;    rep(h, H) { hs.push_back(h); }    rep(w, W) { ws.push_back(w); }    r_ id8(a, hs, ws, key);}
t_T string id8(v_<v_<v_<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {    stringstream ss;    if (H == inf)H = 12;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << id8(a[i], W, U, i);    }    r_ ss.str();}
string id8(int a) {    stringstream ss;    ss << a;    r_ ss.str();}
t_T string id8(T &a) {    stringstream ss;    ss << a;    r_ ss.str();}






















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

vi id0(int v) {    vi res;    double lim = std::sqrt(v);    rep(i, 1, lim+1){        if (v % i == 0) {            res.pb(i);            if (i != v / i)res.pb(v / i);        }    }    r_ res;}
vb isPrime;
vi primes;

void setPrime() {    int len = 4010101;    isPrime.resize(4010101);    fill(isPrime, true);    isPrime[0] = isPrime[1] = false;    for (int i = 2; i <= sqrt(len) + 5; ++i) {        if (!isPrime[i])continue;        for (int j = 2; i * j < len; ++j) {            isPrime[i * j] = false;        }    }    rep(i, len)if (isPrime[i])primes.pb(i);}

vi factorization(int v) {    int tv = v;    vi res;    if (isPrime.size() == 0)setPrime();    for (auto &&p :primes) {        if (v % p == 0)res.push_back(p);        while (v % p == 0) {            v /= p;        }        if (v == 1 || p * p > tv)break;    }    if (v > 1)res.pb(v);    r_ res;}
inline bool inside(int h, int w, int H, int W) { r_ h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { r_ l <= v && v < r; }


t_T v_<T> ruiv(v_<T> &a) {    v_<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    r_ ret;}




t_T v_<T> imo(v_<T> &v) {    v_<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];    r_ ret;}


ll u0(ll a) { r_ a < 0 ? 0 : a; }
t_T v_<T> u(const v_<T> &a) {
    v_<T> ret = a;fora(v, ret)v = u0(v);r_ ret;}



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
void id4(bool a) {
    if (a)cout << "id4" << endl;
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

    if (ok < ng)while (ng - ok > 1) { _mgrbody } else while (ok - ng > 1) { _mgrbody }
    r_ ok;
}

template<class F> inline int mgr(int ok, int ng, int second, F f) {

    if (ok < ng) while (ng - ok > 1) { _mgrbody2 } else while (ok - ng > 1) { _mgrbody2 }
    r_ ok;
}
template<typename T> ostream &operator<<(ostream &os, v_<T> &m) {    for (auto &&v:m) os << v << " ";    r_ os;}
constexpr bool bget(ll m, int keta) { r_ (m >> keta) & 1; }
int bget(ll m, int keta, int sinsuu) {m /= (ll) pow(sinsuu, keta);r_ m % sinsuu;}
ll bit(int n) { r_ (1LL << (n)); }
ll bit(int n, int sinsuu) { r_ (ll) pow(sinsuu, n); }
int mask(int n) { r_ (1ll << n) - 1; }

template<class T, class U> inline bool chma(T &a, const U &b) {if (a < b) {a = b;r_ true;}r_ false;}
template<class U> inline bool chma(const U &b) { r_ chma(ma, b); }
template<class T, class U> inline bool chmi(T &a, const U &b) {    if (b < a) {        a = b;        r_ true;    }    r_ false;}
template<class U> inline bool chmi(const U &b) { r_ chmi(mi, b); }

int max(vi &a) {    int res = a[0];    fora(v, a) {        res = max(res, v);    }    r_ res;}
int min(vi &a) {    int res = a[0];    fora(v, a) {        res = min(res, v);    }    r_ res;}
template<typename T> class fixed_point        : T {public:    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { r_ T::operator()(*this, std::forward<Args>(args)...); }};template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { r_ fixed_point<T>{std::forward<T>(t)}; }
constexpr ll h4[] = {1, -1, 0, 0};
constexpr ll w4[] = {0, 0, -1, 1};
constexpr ll h8[] = {0, 1, 0, -1, -1, 1, 1, -1};
constexpr ll w8[] = {1, 0, -1, 0, 1, -1, 1, -1};
int mei_inc(int h, int w, int H, int W, int i) {while (++i < 4) { if (inside(h + h4[i], w + w4[i], H, W))r_ i; }r_ i;}

int id5(int h, int w, int H, int W, int i) {    while (++i < 8) {        if (inside(h + h8[i], w + w8[i], H, W))r_ i;    }    r_ i;}

int id2(int h, int w, int H, int W, int i, vp &p) {    while (++i < sz(p)) { if (inside(h + p[i].fi, w + p[i].se, H, W))r_ i; }    r_ i;}

vi compress(vi &A) {    vi B = A;    sort(B);    unique(B);    vi inds(sz(B));    rep(i, sz(A)) {        int ind = lower_bound(all(B), A[i]) - B.begin();        inds[ind] = A[i];        A[i] = ind;    }    return inds;}
vi compress(vi &A, umapi& map){    vi i_v = compress(A);    rep(i, sz(i_v)){        map[i_v[i]] = i;    }    return i_v;}

t_T void out2(T head) {    cout << head;}
template<class T, class... U> void out2(T head, U ... tail) {    cout << head << " ";      out2(tail...);}
template<class T, class... U> void out(T head, U ... tail) {    cout << head << " ";        out2(tail...);    cout << "" << endl;}
t_T void out(T head) {    cout << head << endl; }
t_T void out(const vector<T>& A) {    rep(i, sz(A)-1){        cout<<A[i]<<" ";    }    cout<<A[sz(A)-1]<< endl;}
void out() { cout << "" << endl; }





int N, M, H, W;
vi A, B, C;

template<class M=int> struct id6 {
    int n;
    int n2 ;
    vector<M> seg;
    vi lazy;

    M e = MAX<M>();
    vi arch;

    M f(M a, M b) { return a < b ? a : b; }
    id6(vector<M> a, M init_value = MAX<M>()) : e(init_value),n2(sz(a)) {        n = 1;        int asz = a.size();        while (n <= asz)n <<= 1;        seg.resize((n << 1), e);        lazy.resize((n << 1), 0);        rep(i, asz) seg[i + n - 1] = a[i];        rer(i, n - 2)seg[i] = f(seg[(i << 1) + 1], seg[(i << 1) + 2]);        int l = 1, v = n;    }
    id6(int N, M init_value = MAX<M>()) : e(init_value),n2(N) {        deb(e);        vi a(N, init_value);        n = 1;        int asz = a.size();        while (n <= asz)n <<= 1;        seg.resize((n << 1), e);        lazy.resize((n << 1), 0);        rep(i, asz) seg[i + n - 1] = a[i];        rer(i, n - 2)seg[i] = f(seg[(i << 1) + 1], seg[(i << 1) + 2]);        int l = 1, v = n;    }    void eval() {        rer(j, sz(arch) - 1) {            int i = arch[j];                                    int v = lazy[i - 1];            if (!v)continue;            lazy[(i << 1) - 1] += v;            lazy[(i << 1)] += v;            seg[(i << 1) - 1] += v;            seg[i << 1] += v;            lazy[i - 1] = 0;        }    }    void gindex(int l, int r) {        arch.clear();        l += n;        r += n;        int lm = (l / (l & -l)) >> 1;        int rm = (r / (r & -r)) >> 1;        while (l < r) {            if (r <= rm)arch.push_back(r);            if (l <= lm)arch.push_back(l);            l >>= 1;            r >>= 1;        }        while (l) {            arch.push_back(l);            l >>= 1;        }    }
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

    void debu(int len = 10) {        rep(i, min(n, min(len, n))) {            int v = get(i, i + 1);            if (v == e) { cerr << "e "; } else { cerr << v << " "; }        }        cerr << "" << endl;}

    inline void debu(){;}

private :
    M get2(int l, int r) {        gindex(l, r);        eval();        int L = l + n;        int R = r + n;        M retl = e, retr = e;        while (L < R) {            if (R & 1) {                R--;                retr = f(seg[R - 1], retr);            }            if (L & 1) {                retl = f(retl, seg[L - 1]);                L++;            }            L >>= 1;            R >>= 1;        }        return f(retl, retr);    }
};



void solve() {
    in(N, M);
    vi len;
    na(len, M);
    int id1 = M - 1 + len[M - 1];
    if (id1 > N || sum(len) < N) {
        out(-1);
        exit(0);
    } else {
        vi rems(M);
        rep(i, M) {
            A+= i;
            rems[i] = N - (A[i] + len[i]);
        }
        id6<int> st(rems, linf);
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