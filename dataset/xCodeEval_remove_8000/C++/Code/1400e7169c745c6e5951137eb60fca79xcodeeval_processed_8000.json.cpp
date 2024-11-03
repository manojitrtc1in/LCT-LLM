






using namespace std;


struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} id8;






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















using vi = vector<int>;

using vb = vector<bool>;

using vs = vector<string>;

using vl = vector<ll>;

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






























const int inf = (int) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795029L;
const int y4[] = {-1, 1, 0, 0};
const int x4[] = {0, 0, -1, 1};
const int y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int x8[] = {1, 0, -1, 0, 1, -1, 1, -1};




















namespace std_vector_bounds_checking {
    using namespace std;
    template<class T, class A = std::allocator<T>> struct vector : std::vector<T, A> {
        using std::vector<T, A>::vector;
        typename std::vector<T>::reference operator[](typename std::vector<T>::size_type n) {
            return this->at(n);
        }
    };
}
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
template<typename T> ostream &operator<<(ostream &os, vector <T> &vec) {
    for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    return os;
}
template<typename V, typename H> void resize(vector<V> &vec, const H head) {  

    vec.resize(head);
}
template<typename V, typename H, typename ... T> void resize(vector<V> &vec, const H &head, const T ... tail) {
    vec.resize(head);
    for (auto &v: vec) resize(v, tail...);
}
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
template<class T> inline void sort(vector<T> &a) { sort(a.begin(), a.end()); };
template<class T> inline void sort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len); };
template<class T, class F> inline void sort(vector<T> &a, F f) { sort(a.begin(), a.end(), [&](T l, T r) { return f(l) < f(r); }); };
template<class T> inline void rsort(vector<T> &a) { sort(a.begin(), a.end(), greater<T>()); };
template<class T> inline void rsort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len, greater<T>()); };
template<class T, class F> inline void rsort(vector<T> &a, F f) { sort(a.begin(), a.end(), greater<T>(), [&](T l, T r) { return f(l) > f(r); }); };
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
template<class U, class F> inline void id5(vector<U> &a, vector<U> &b, F f) {
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
template<class T> inline void sort2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)sort(a[i]); }
template<class T> inline void id1(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
template<typename A, size_t N, typename T> void fill(A (&a)[N], const T &v) { rep(i, N)a[i] = v; }
template<typename A, size_t N, size_t O, typename T> void fill(A (&a)[N][O], const T &v) { rep(i, N)rep(j, O)a[i][j] = v; }
template<typename A, size_t N, size_t O, size_t P, typename T> void fill(A (&a)[N][O][P], const T &v) { rep(i, N)rep(j, O)rep(k, P)a[i][j][k] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, typename T> void fill(A (&a)[N][O][P][Q], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)a[i][j][k][l] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, typename T> void fill(A (&a)[N][O][P][Q][R], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)a[i][j][k][l][m] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S, typename T> void fill(A (&a)[N][O][P][Q][R][S], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)rep(n, S)a[i][j][k][l][m][n] = v; }

template<typename V, typename T>
void fill(V &xx, const T &vall) {
    xx = vall;
}
template<typename V, typename T>
void fill(vector<V> &vecc, const T &vall) {
    for (auto &vx: vecc) fill(vx, vall);
}



template<typename T = int> T in() {
    T x;
    cin >> x;
    return (x);
}
string sin() { return in<string>(); }
double din() { return in<double>(); }
ll lin() { return in<ll>(); }













template<class T> void out(T x) { typeid(x) == typeid(double) ? cout << fixed << setprecision(10) << x << endl : cout << x << endl; }





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
            int r = p.F;
            res[i].push_back(r);
            for (auto &&v:p.S) {
                if (r == v)continue;
                res[i].push_back(v);
            }
            i++;
        }
        return res;
    }
};



ll MOD = (int) 1e9 + 7;
class mint {
public:
    int x;
    mint() : x(0) {}
    mint(signed y) : x(y >= 0 ? y % MOD : MOD - (-y) % MOD) {}
    mint(int y) : x(y >= 0 ? y % MOD : MOD - (-y) % MOD) {}
    static int _mpow(int v, ll a) {
        ll x = v, n = a, res = 1;
        while (n) {
            if (n & 1)res = (res * x) % MOD;
            x = (x * x) % MOD;
            n >>= 1;
        }
        return res;
    }

    

    mint &operator+=(mint that) {
        if ((x += that.x) >= MOD) x -= MOD;
        return *this;
    }
    mint &operator-=(mint that) {
        if ((x += MOD - that.x) >= MOD) x -= MOD;
        return *this;
    }
    mint &operator*=(mint that) {
        x = 1LL * x * that.x % MOD;
        return *this;
    }
    mint &operator/=(const mint &that);
    mint &operator^=(const mint &that) {
        this->x = _mpow(x, that.x);
        return *this;
    }
    mint &operator%=(mint that) {
        x %= that.x;
        return *this;
    }

    mint &operator+=(const int that) { return *this += mint(that); }
    mint &operator-=(const int that) { return *this -= mint(that); }
    mint &operator*=(const int that) { return *this *= mint(that); }
    mint &operator/=(const int that);
    mint &operator^=(const int that) {
        this->x = _mpow(x, that);
        return *this;
    }
    mint &operator%=(const int that) { return *this %= mint(that); }

    mint &operator+=(const signed that) { return *this += mint(that); }
    mint &operator-=(const signed that) { return *this -= mint(that); }
    mint &operator*=(const signed that) { return *this *= mint(that); }
    mint &operator/=(const signed that);
    mint &operator^=(const signed that) {
        this->x = _mpow(x, that);
        return *this;
    }
    mint &operator%=(const signed that) { return *this %= mint(that); }

    

    bool operator<(mint that) { return x < that.x; }
    bool operator>(mint that) { return x > that.x; }
    bool operator<=(mint that) { return x <= that.x; }
    bool operator>=(mint that) { return x >= that.x; }
    bool operator!=(mint that) { return x != that.x; }
    bool operator==(mint that) { return x == that.x; }
    bool operator!=(int that) { return x != that; }
    bool operator==(int that) { return x == that; }
    bool operator!=(signed that) { return x != that; }
    bool operator==(signed that) { return x == that; }

    

    unsigned getval() const { return x; }
    operator int() { return x; }
    mint operator+(mint that) const { return mint(*this) += that; }
    mint operator-(mint that) const { return mint(*this) -= that; }
    mint operator*(mint that) const { return mint(*this) *= that; }
    mint operator%(mint that) const { return mint(*this) %= that; }
    mint operator+(const int that) const { return mint(*this) += that; }
    mint operator-(const int that) const { return mint(*this) -= that; }
    mint operator*(const int that) const { return mint(*this) *= that; }
    mint operator%(const int that) const { return mint(*this) %= that; }
    mint operator=(const int that) { return *this = mint(that); }
    mint operator+(const signed that) const { return mint(*this) += that; }
    mint operator-(const signed that) const { return mint(*this) -= that; }
    mint operator*(const signed that) const { return mint(*this) *= that; }
    mint operator%(const signed that) const { return mint(*this) %= that; }
    mint operator=(const signed that) { return *this = mint(that); }
    mint operator++() {
        x++;
        return *this;
    }
    mint operator++(signed) {
        auto ret = *this;
        x++;
        return ret;
    }
    friend void operator+=(ll &a, const mint &b) { a = mint(a % MOD + b.x); }
    friend void operator-=(ll &a, const mint &b) { a = mint(a % MOD - b.x); }
    friend void operator*=(ll &a, const mint &b) { a = mint(a % MOD * b.x); }
    friend void operator/=(ll &a, const mint &b);
    friend mint operator+(const ll a, const mint &b) { return mint(a % MOD + b.x); }
    friend mint operator-(const ll a, const mint &b) { return mint(a % MOD - b.x); }
    friend mint operator*(const ll a, const mint &b) { return mint(a % MOD * b.x); }
    friend mint operator^(const ll a, const mint &b) { return _mpow(a, b.x); }
};
const int id3 = 510000;
mint fac[id3], finv[id3], inv[id3];
void setMod(int m = MOD) {
    MOD = m;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < id3; i++) {
        fac[i] = fac[i - 1].x * i % MOD;
        inv[i] = MOD - inv[MOD % i].x * (MOD / i) % MOD;
        finv[i] = finv[i - 1].x * inv[i].x % MOD;
    }
}
mint mpow(int v, ll a) {
    return mint::_mpow(v, a);
}
mint com(ll n, ll r) {
    if (n < r || n < 0 || r < 0)return 0;
    if (fac[0] == 0)setMod();
    return fac[n] * finv[r] * finv[n - r];
}
mint ncr(ll n, ll r) { return com(n, r); }
mint nhr(ll n, ll r) { return com(n + r - 1, r); }



mint minv(ll a) {
    if (fac[0] == 0)setMod();
    if (a < id3) return inv[a];
    a %= MOD;
    ll b = MOD, x = 1, y = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        x -= t * y;
        swap(x, y);
    }
    return x;
}
mint &mint::operator/=(const mint &that) { return *this *= minv(that.x); }
mint &mint::operator/=(const ll a) { return *this *= minv(a); }
mint &mint::operator/=(const signed a) { return *this *= minv(a); }
void operator/=(ll &a, const mint &b) { a = (a * minv(b.x)).x; }
using vm=vector<mint>;

using PM = pair<mint, mint>;
bool isPrime[4010101];
vi primes;

void setPrime() {
    fill(isPrime, true);
    int len = sizeof(isPrime) / sizeof(isPrime[0]);
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

C rot(C &a, dou th) {
    return a * C(cos(th), sin(th));
}

dou inpro(C &a, C &b) {
    return real(a * conj(b));
}



bool line(C a, C b, C c) {
    C ab = b - a;
    C ac = c - a;
    

    ab *= C(0, 1);
    return eq(inpro(ab, ac), 0);
}
bool line(P a, P b, P c) {
    return line(C(a.F, a.S), C(b.F, b.S), C(c.F, c.S));
}

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
    return rand() % (max + 1 - min) + min;
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
void iota(vector<int> ve, int s, int n) {
    ve.resize(n);
    iota(all(ve), s);
}
void ole() {
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
ll reverse(ll a) {
    ll res = 0;
    while (a) {
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
}
template<class T> void reverse(vector<T> &a) {
    reverse(all(a));
}
ll ceil(ll a, ll b) {
    if (b == 0) {
        ole();
        return -1;
    } else return (a + b - 1) / b;
}
ll sqrt(ll a) {
    if (a < 0)ole();
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
    if (!isPrime[2])setPrime();
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

unordered_map<int, int> id2(int v) {
    int tv = v;
    unordered_map<int, int> res;
    if (!isPrime[2])setPrime();
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

template<class T> void imo(vector<T> &v) {
    int n = v.size();
    rep(i, n - 1)v[i + 1] += v[i];
}



template<class T, class U> vector<T> keys(vector<pair<T, U>> a) {
    vector<T> res;
    for (auto &&k :a)res.pb(k.F);
    return res;
}
template<class T, class U> vector<U> keys(map<T, U> a) {
    vector<U> res;
    for (auto &&k :a)res.pb(k.F);
    return res;
}

template<class T, class U> vector<U> keys(umap<T, U> a) {
    vector<U> res;
    for (auto &&k :a)res.pb(k.F);
    return res;
}

template<class T, class U> vector<U> values(vector<pair<T, U>> a) {
    vector<U> res;
    for (auto &&k :a)res.pb(k.S);
    return res;
}

template<class T, class U> vector<T> values(map<T, U> a) {
    vector<T> res;
    for (auto &&k :a)res.pb(k.S);
    return res;
}

template<class T, class U> vector<T> values(umap<T, U> a) {
    vector<T> res;
    for (auto &&k :a)res.pb(k.S);
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

template<class T, class U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T> T min(T a, signed b) {
    return a < b ? a : b;
}

template<class T> T max(T a, signed b) {
    return a < b ? b : a;
}

template<class T> T min(T a, T b, T c) {
    return a >= b ? b >= c ? c : b : a >= c ? c : a;
}
template<class T> T max(T a, T b, T c) {
    return a <= b ? b <= c ? c : b : a <= c ? c : a;
}

template<class T> T min(vector<T> a) {
    return *min_element(all(a));
}
template<class T> T min(vector<T> a, int n) {
    return *min_element(a.begin(), a.begin() + min(n, sz(a)));
}
template<class T> T min(vector<T> a, int s, int n) {
    return *min_element(a.begin() + s, a.begin() + min(n, sz(a)));
}
template<class T> T max(vector<T> a) {
    return *max_element(all(a));
}
template<class T> T max(vector<T> a, int n) {
    return *max_element(a.begin(), a.begin() + min(n, sz(a)));
}
template<class T> T max(vector<T> a, int s, int n) {
    return *max_element(a.begin() + s, a.begin() + min(n, sz(a)));
}
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
        res.F += v[i].F;
        res.S += v[i].S;
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
template<class T> T *id4(int h, int w) {
    double **dummy1 = new double *[2 * h + 1];
    double *dummy2 = new double[(2 * h + 1) * (2 * w + 1)];
    dummy1[0] = dummy2 + w;
    for (int i = 1; i <= 2 * h + 1; i++) {
        dummy1[i] = dummy1[i - 1] + 2 * w + 1;
    }
    double **a = dummy1 + h;
}

template<class T> vector<T> ruiv(vector<T> &a) {
    vector<T> res(a.size() + 1);
    rep(i, a.size())res[i + 1] = res[i] + a[i];
    return res;
}

template<class T> vector<T> ruim(vector<T> &a) {
    vector<T> res(a.size() + 1, 1);
    rep(i, a.size())res[i + 1] = res[i] * a[i];
    return res;
}


template<class T> T *rrui(vector<T> &a) {
    int len = a.size();
    T *body = (T *) malloc((len + 1) * sizeof(T));
    T *res = body + 1;
    rer(i, len - 1)res[i - 1] = res[i] + a[i];
    return res;
}


template<class T> T *id10(vector<T> &a) {
    int len = a.size();
    T *body = (T *) malloc((len + 1) * sizeof(T));
    T *res = body + 1;
    res[len - 1] = 1;
    rer(i, len - 1)res[i - 1] = res[i] * a[i];
    return res;
}
template<class T> void plus(vector<T> &a, T v = 1) { for (auto &&u :a)u += v; }
template<class T> void minu(vector<T> &a, T v = 1) { for (auto &&u :a)u -= v; }
template<class T> void minus(vector<T> &a, T v = 1) { for (auto &&u :a)u -= v; }
inline bool inside(int y, int x, int H, int W) { return y >= 0 && x >= 0 && y < H && x < W; }
ll u(ll a) { return a < 0 ? 0 : a; }


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
int bcou(ll m) { return __builtin_popcount(m & 0xFFFFFFFF) + __builtin_popcount(m >> 32); }


ll nextComb(ll &mask, int n, int r) {
    if (!mask)return mask = (1LL << r) - 1;
    ll x = mask & -mask; 

    ll y = mask + x; 

    ll res = ((mask & ~y) / x >> 1) | y;
    if (bget(res, n))return mask = 0;
    else return mask = res;
}



vl id6(int n, int r) {
    vl res;
    int m = 0;
    while (nextComb(m, n, r)) {
        res.pb(m);
    }
    return res;
}


int id9(char c) {
    if ('A' <= c && c <= 'Z')return c - 'A';
    return c - 'a' + 26;
}
char id7(int i) {
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
    if (sz(v) > 18)ole();
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
    reverse(res);
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
    int n, root = -1;
    graph(int n) : n(n) { g.resize(n), _used.resize(n); }
    void clear() { g.clear(), edges.clear(); }
    void resize(int n) {
        this->n = n;
        g.resize(n);
        _used.resize(n);
    }
    int size() { return g.size(); }
    bool isleaf(int v) {
        assert(root != -1);
        return g[v].size() == 1 && g[v][0].from != root;
    }
    vector<edge<T> > &operator[](int i) { return g[i]; }
    virtual void add(int from, int to, T cost, int ty) = 0;
    virtual bool used(edge<T> &e) = 0;
    virtual bool used(int id) = 0;
    virtual void del(edge<T> &e) = 0;
    virtual void del(int id) = 0;
};

template<class T=int> class undigraph : public graph<T> {
public:
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::_used;
    undigraph(int n) : graph<T>(n) {
    }
    void add(int f, int t, T cost = 1, int ty = -1) {
        if (!(0 <= f && f < n && 0 <= t && t < n))ole();
        int id = edges.size();
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

template<typename T =ll> class digraph : public graph<T> {
public:
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::_used;

    digraph(int n) : graph<T>(n) {}
    void add(int f, int t, T cost = 1, int ty = -1) {
        if (!(0 <= f && f < n && 0 <= t && t < n))ole();
        int id = edges.size();
        g[f].emplace_back(f, t, cost, ty, id);
        edges.emplace_back(f, t, cost, ty, id);
    }
    bool used(edge<T> &e) { return _used[e.id]; }
    bool used(int id) { return _used[id]; }
    void del(edge<T> &e) { _used[e.id] = _used[e.id ^ 1] = 1; }
    void del(int id) { _used[id] = _used[id ^ 1] = 1; }
};

template<class T> bool nibu(const graph<T> &g) {
    UnionFind uf(g.n * 2);
    for (auto &&e :g.edges)uf.unite(e.f, e.t + g.n), uf.unite(e.f + g.n, e.t);
    return !uf.same(0, g.n);
}
template<class T> vector<T> dijkstra(const graph<T> &g, int s) {
    if (!(0 <= s && s < g.n))ole();
    T initValue = MAX(T);
    vector<T> dis(g.n, initValue);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    dis[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
        T nowc = q.top().F;
        int i = q.top().S;
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
    

    for (auto &&d :dis) if (d == initValue)d = -1;
    return dis;
}



vp vtop(vi &a, vi &b) {
    vp res(sz(a));
    rep(i, sz(a))res[i] = mp(a[i], b[i]);
    return res;
}
void ptov(vp &p, vi &a, vi &b) {
    a.resize(sz(p));
    b.resize(sz(p));
    rep(i, sz(p))a[i] = p[i].F, b[i] = p[i].S;
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
template<class T> vector<T> &operator+=(vector<T> &a, vector <T> &b) {
    a.pb(b);
    return a;
}
template<class T, class U> vector<T> &operator+=(vector<T> &a, initializer_list<U> v) {
    for (auto &&va :v)a.pb(va);
    return a;
}
template<class T> vector<T> &operator-=(vector<T> &a, vector <T> &b) {
    if (sz(a) != sz(b))ole();
    rep(i, sz(a))a[i] -= b[i];
    return a;
}
template<class T> vector<T> &operator-(vector<T> &a, vector <T> &b) {
    if (sz(a) != sz(b))ole();
    vector<T> res;
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
template<typename T> void insert(vector<T> &v, unsigned int i, T t) { v.insert(v.begin() + i, t); }
template<typename T> void insert(vector<T> &v, unsigned int i, vector<T> list) {
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


ll ma = numeric_limits<ll>::min();
ll mi = numeric_limits<ll>::max();


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


int n, m, k, d, H, W, x, y, z, q;
int cou;
vi a, b, c;
vvi (s, 0, 0);
vvc (ba, 0, 0);
vp p;
undigraph<> g(2 * k5);
vvi(fa, k5 * 2, 0);
mapi dp[k5 * 2];
void ds(int i, int p) {
    fora(v, fa[i])dp[i][v] = 1;
    fort(gi, g[i]) {
        ds(t, i);
        fora(v,fa[i]){
            chmax(ma,dp[i][v]+dp[t ][v]);
            chmax(dp[i][v],dp[t ][v]+1);
        }
    }
}
void solve() {
    cin >> n;
    na(a, n);
    rep(i, n - 1) {
        int f, s;
        cin >> f >> s;
        --f, --s;
        g.add(f, s);
    }
    rep(i, n)fa[i] = factorization(a[i]);
    chmax(ma,0);
    ds(0, -1);
    rep(i,n)fora(p,fa[i])chmax(ma,dp[i][p]);
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
        int n = rand(2, 5);
        int m = rand(2, 5);
        int k = rand(2, 5);
        vi a = ranv(n, 1, 10);
        vi b = ranv(n, 1, 10);

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
