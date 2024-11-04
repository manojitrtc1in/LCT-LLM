





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




#define int long long
#define ll long long
#define double long double
#define ull unsigned long long
using dou = double;
using itn = int;
using str = string;
using bo= bool;
using P = pair<ll, ll>;
#define F first
#define fi first
#define S second
#define se second
#define vec vector
#define beg begin
#define rbeg rbegin
#define con continue
#define bre break
#define brk break
#define is ==




using vi = vector<int>;
#define vvi(a, b, c) vec<vi> a(b,vi(c))
using vb = vector<bool>;
#define vvb(a, b, c) vec<vb> a(b,vb(c))
using vs = vector<string>;
#define vvs(a, b, c) vec<vs> a(b,vs(c))
using vl = vector<ll>;
#define vvl(a, b, c) vec<vl> a(b,vl(c))
using vd = vector<double>;
#define vvd(a, b, c) vec<vd> a(b,vd(c))
using vc=vector<char>;
#define vvc(a, b, c) vec<vc> a(b,vc(c))
using vp = vector<P>;
#define vvp(a, b, c) vec<vp> a(b,vp(c))
using vt = vector<T>;
#define vvt(a, b, c) vec<vt> a(b,vt(c))
#define v3i(a, b, c, d) vector<vector<vi>> a(b, vector<vi>(c, vi(d)))
#define v3d(a, b, c, d) vector<vector<vd>> a(b, vector<vd>(c, vd(d)))
#define v3m(a, b, c, d) vector<vector<vm>> a(b, vector<vm>(c, vm(d)))
#define PQ priority_queue<ll, vector<ll>, greater<ll> >
using seti = set<int>;
#define uset unordered_set
#define mset multiset
#define umap unordered_map
#define mmap multimap



#define _overloadrep(_1, _2, _3, name, ...) name
# define _rep(i, n) for(int i = 0,_lim=n; i < _lim ; i++)
#define repi(i, m, n) for(int i = m,_lim=n; i < _lim ; i++)
#define rep(...) _overloadrep(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rer(i, n) for(int i = n; i >= 0 ; i--)
#define reri(i, m, n) for(int i = m,_lim=n; i >= _lim ; i--)
#define rer(...) _overloadrep(__VA_ARGS__,reri,_rer,)(__VA_ARGS__)
#define fora(a, b) for(auto&& a : b)
#define forg(gi, ve) if (ve.size())for (int gi = 0, f = ve[gi].from, t = ve[gi].to, c = ve[gi].cost; gi < ve.size(); gi++,f = ve[gi].from, t = ve[gi].to, c = ve[gi].cost)



#define k4 10101
#define k5 101010
#define k6 1010101
#define k7 10101010
const int inf = (int) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
const double eps = 1e-9;
const int y4[] = {-1, 1, 0, 0};
const int x4[] = {0, 0, -1, 1};
const int y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int x8[] = {1, 0, -1, 0, 1, -1, 1, -1};



#define arsz(a) (sizeof(a)/sizeof(a[0]))
#define s(a) (a.size())
#define rs(a) (a.resize())
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()








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
template<class T> inline void rsort(vector<T> &a) { sort(a.begin(), a.end(), greater<T>()); };
template<class T> inline void sort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len); };
template<class T> inline void rsort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len, greater<T>()); };
template<class U> inline void sortp(vector<U> &a, vector<U> &b) {
    vp c;
    int n = s(a);
    assert(n == s(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U> inline void rsortp(vector<U> &a, vector<U> &b) {
    vp c;
    int n = s(a);
    assert(n == s(b));
    rep(i, n)c.eb(a[i], b[i]);
    rsort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
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
#define na(a, n) a.resize(n); rep(i,n) cin >> a[i];
#define nad(a, n) a.resize(n); rep(i,n) cin >> a[i], a[i]--;
#define na2(a, b, n) a.resize(n),b.resize(n);rep(i, n)cin >> a[i] >> b[i];
#define na2d(a, b, n) a.resize(n),b.resize(n);rep(i, n)cin >> a[i] >> b[i],a[i]--,b[i]--;
#define na3(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n)cin >> a[i] >> b[i] >> c[i];
#define na3d(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n)cin >> a[i] >> b[i] >> c[i],a[i]--,b[i]--,c[i]--;
#define nt(a, h, w) resize(a,h,w);rep(hi,h)rep(wi,w) cin >> a[hi][wi];
#define ntd(a, h, w) rs(a,h,w);rep(hi,h)rep(wi,w) cin >> a[hi][wi], a[hi][wi]--;
#define ntp(a, h, w) fill(a,'#');rep(hi,1,h+1)rep(wi,1,w+1) cin >> a[hi][wi];



template<class T> void out(T x) { typeid(x) == typeid(double) ? cout << fixed << setprecision(10) << x << endl : cout << x << endl; }


#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';


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
    friend void operator+=(ll &a, const mint &b) { a = mint(a % MOD + b.x); }
    friend void operator-=(ll &a, const mint &b) { a = mint(a % MOD - b.x); }
    friend void operator*=(ll &a, const mint &b) { a = mint(a % MOD * b.x); }
    friend void operator/=(ll &a, const mint &b);
    friend mint operator+(const ll a, const mint &b) { return mint(a % MOD + b.x); }
    friend mint operator-(const ll a, const mint &b) { return mint(a % MOD - b.x); }
    friend mint operator*(const ll a, const mint &b) { return mint(a % MOD * b.x); }
    friend mint operator^(const ll a, const mint &b) { return _mpow(a, b.x); }
};
const int setModMax = 510000;
mint fac[setModMax], finv[setModMax], inv[setModMax];
void setMod() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < setModMax; i++) {
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
    if (a < setModMax) return inv[a];
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
#define vvm(a, b, c) vec<vm> a(b,vm(c))
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
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool equal(double a, double b) { return fabs(a - b) < eps; }
ll reverse(ll a) {
    ll res = 0;
    while (a) {
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
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

vi divisors(int v) {
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

unordered_map<int, int> factorizationMap(int v) {
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

template<class T> T min(vector<T> a) {
    return *min_element(all(a));
}
template<class T> T min(vector<T> a, int n) {
    return *min_element(a.begin(), a.begin() + min(n, s(a)));
}
template<class T> T min(vector<T> a, int s, int n) {
    return *min_element(a.begin() + s, a.begin() + min(n, s(a)));
}
template<class T> T max(vector<T> a) {
    return *max_element(all(a));
}
template<class T> T max(vector<T> a, int n) {
    return *max_element(a.begin(), a.begin() + min(n, s(a)));
}
template<class T> T max(vector<T> a, int s, int n) {
    return *max_element(a.begin() + s, a.begin() + min(n, s(a)));
}

template<class T> T min(T a[]) {
    T res = a[0];
    rep(i, arsz(a))chmin(res, a[i]);
    return res;
}

template<class T> T max(T a[]) {
    T res = a[0];
    rep(i, arsz(a))chmax(res, a[i]);
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
template<class T> T *negarr2(int h, int w) {
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


template<class T> T *rruim(vector<T> &a) {
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
#define MIN(a) numeric_limits<a>::min()
#define MAX(a) numeric_limits<a>::max()
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



vl bitCombList(int n, int r) {
    vl res;
    int m = 0;
    while (nextComb(m, n, r)) {
        res.pb(m);
    }
    return res;
}


int altoiaZ(char c) {
    if ('A' <= c && c <= 'Z')return c - 'A';
    return c - 'a' + 26;
}
char itoalaZ(int i) {
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
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

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


#define binarySearch(a, v) (binary_search(all(a),v))
#define lowerIndex(a, v) (lower_bound(all(a),v)-a.begin())
#define lowerBound(a, v) (*lower_bound(all(a),v))
#define upperIndex(a, v) (upper_bound(all(a),v)-a.begin())
#define upperBound(a, v) (*upper_bound(all(a),v))
#define ans(a) cout<<a<<endl;continue;
#define poll(a) q.front();q.pop()
#define dpoll(a) q.front();q.pop_front()
#define pollLast(a) q.back();q.pop_back()
#define pollBack(a) q.back();q.pop_back()
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
template<class T> vector<T> &dijkstra(const graph<T> &g, int s) {
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

template<class T, class U> vector<T> &operator+=(vector<T> &a, U &v) {
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
    if (s(a) != s(b))ole();
    rep(i, s(a))a[i] -= b[i];
    return a;
}
template<class T> vector<T> &operator-(vector<T> &a, vector <T> &b) {
    if (s(a) != s(b))ole();
    vector<T> res;
    rep(i, s(a))res[i] = a[i] - b[i];
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
string s;
vi a, b, c;
vvi (S, 0, 0);
vp p;
int dp[k6][5][5];
void solve(int n_, vi a_) {
    cin >> n >> m;
    na(b, n);
    a.resize(m + 10);
    rep(i, n)a[b[i]]++;
    fill(dp, -1);
    dp[0][0][0] = 0;
    vi r(3);
    

    rep(i, m + 1) {
        rep(u, 5) {
            rep(v, 5) {
                rep(d, 3) {
                    if (dp[i][u][v] < 0)continue;
                    int f = a[i] - u - d;
                    int t = a[i + 1] - v - d;
                    int s = a[i + 2] - d;
                    if (min(f, t, s) < 0)continue;
                    

                    

                    

                    chmax(dp[i + 1][v + d][d], dp[i][u][v] + d + f / 3);
                }
            }
        }
    }
    cout << dp[m + 1][0][0] << endl;
}
int my(int n, vi a) {
    return 0;
}
int sister(int n, vi a) {
    return 0;
}

signed main() {
    solve(0, vi(1));








#ifdef _DEBUG
    for (int i = 0, ok = 1; i < k5 && ok; i++) {
        int n = rand(2, 5);
        int m = rand(2, 5);
        int k = rand(2, 5);
        vi a = ranv(n, 1, 10);
        vi b = ranv(n, 1, 10);
#define _arg n,a
        

        int myres = my(_arg);
        int res = sister(_arg);
        ok = myres == res;
        if (!ok) {
            cout << n << endl;
            cout << a << endl;
            cout << "正解 : " << res << endl;
            cout << "出力 : " << myres << endl;
        }
    }
#endif
    return 0;
};
