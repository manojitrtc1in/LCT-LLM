














using namespace std;
using ll = long long;
template<class T>using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD=1000000007;
const int MOD2=998244353;
const int INF=1<<30;
const ll INF2=(ll)1<<60;


void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T,class L>void scan(pair<T, L>& p){scan(p.first);scan(p.second);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}


void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T,class L>void print(const pair<T, L>& p){print(p.first);putchar(' ');print(p.second);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}


template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll modinv(ll a, ll m) {ll b = m, u = 1, v = 0;while (b) {ll t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}
ll updivide(ll a,ll b){if(a%b==0) return a/b;else return (a/b)+1;}
template<class T> void chmax(T &a,const T b){if(b>a)a=b;}
template<class T> void chmin(T &a,const T b){if(b<a)a=b;}

namespace internal {
constexpr long long safe_mod(long long x, long long m) {x %= m;if (x < 0) x += m;return x;}
struct barrett {
    unsigned int _m;
    unsigned long long im;
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned long long)(z)*im));

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};
constexpr long long id7(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}
constexpr bool id6(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id7(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {y = y * y % n;t <<= 1;}
        if (y != n - 1 && t % 2 == 0) {return false;}
    }
    return true;
}
template <int n> constexpr bool is_prime = id6(n);
constexpr std::pair<long long, long long> id1(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {long long u = s / t;s -= t * u;m0 -= m1 * u;auto tmp = s;s = t;t = tmp;tmp = m0;m0 = m1;m1 = tmp;}
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
constexpr int id2(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {divs[cnt++] = i;while (x % i == 0) {x /= i;}}
    }
    if (x > 1) {divs[cnt++] = x;}
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id7(g, (m - 1) / divs[i], m) == 1) {ok = false;break;}
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id2(m);
unsigned long long id0(unsigned long long n,unsigned long long m,unsigned long long a,unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {ans += n * (n - 1) / 2 * (a / m);a %= m;}
        if (b >= m) {ans += n * (b / m);b %= m;}
        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}
template <class T> using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;
template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}  

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id4 : internal::static_modint_base {
    using mint = id4;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {mint x;x._v = v;return x;}
    id4() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id4(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();_v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id4(T v) {_v = (unsigned int)(v % umod());}
    unsigned int val() const { return _v; }
    mint& operator++() {_v++;if (_v == umod()) _v = 0;return *this;}
    mint& operator--() {if (_v == 0) _v = umod();_v--;return *this;}
    mint operator++(int) {mint result = *this;++*this;return result;}
    mint operator--(int) {mint result = *this;--*this;return result;}
    mint& operator+=(const mint& rhs) {_v += rhs._v;if (_v >= umod()) _v -= umod();return *this;}
    mint& operator-=(const mint& rhs) {_v -= rhs._v;if (_v >= umod()) _v += umod();return *this;}
    mint& operator*=(const mint& rhs) {unsigned long long z = _v;z *= rhs._v;_v = (unsigned int)(z % umod());return *this;}
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {assert(0 <= n);mint x = *this, r = 1;while (n) {if (n & 1) r *= x;x *= x;n >>= 1;}return r;}
    mint inv() const {if (prime) {assert(_v);return pow(umod() - 2);} else {auto eg = internal::id1(_v, m);assert(eg.first == 1);return eg.second;}}
    friend mint operator+(const mint& lhs, const mint& rhs) {return mint(lhs) += rhs;}
    friend mint operator-(const mint& lhs, const mint& rhs) {return mint(lhs) -= rhs;}
    friend mint operator*(const mint& lhs, const mint& rhs) {return mint(lhs) *= rhs;}
    friend mint operator/(const mint& lhs, const mint& rhs) {return mint(lhs) /= rhs;}
    friend bool operator==(const mint& lhs, const mint& rhs) {return lhs._v == rhs._v;}
    friend bool operator!=(const mint& lhs, const mint& rhs) {return lhs._v != rhs._v;}
    

    friend istream& operator>>(istream& os,mint& rhs) noexcept {
        long long v;
        rhs = mint{(os >> v, v)};
        return os;
    }
    friend constexpr ostream& operator << (ostream &os, const mint& rhs) noexcept {
        return os << rhs._v;
    }
  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};
using mint=id4<1000000007>;
using mint2=id4<998244353>;

template <class S, S (*op)(S, S), S (*e)()> struct id5 {
  public:
    id5() : id5(0) {}
    id5(int n) : id5(std::vector<S>(n, e())) {}
    id5(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
    const S operator[](int p) const { return get(p); }
    S operator[](int p) { return get(p); }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

int op(int lhs, int rhs){
    return min(lhs, rhs);
}

int e(){
    return INF;
}

template <class T> struct id3 {
    using U = T;

  public:
    id3() : _n(0) {}
    id3(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};



int main(){
    INT(n);
    vector<int> a(n);
    in(a);
    rep(i,n){
        a[i] -= i + 1;
    }
    vector<vector<pair<int,int>>> tb(n + 1);
    vector<vector<ll>> s(n + 1);
    vector<ll> s2(n + 1), tb2(n + 1);
    id5<int, op, e> seg(a);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int r = seg.max_right(i, [&](int v){return (v >= -i);});
        int r2 = seg.max_right(min(n, r + 1), [&](int v){return (v >= -i);});
        tb[r].emplace_back(i, r2 - r);
        tb2[i] = r;
        s2[i + 1] = s2[i] + r;
        ans += r - i;
        s[i].resize(tb[i].size() + 1);
        for(int j = 0; j < tb[i].size(); j++){
            s[i][j + 1] = s[i][j] + tb[i][j].second;
        }
        a[i] += i + 1;
    }
    codefor{
        INT(p, x);
        p--;
        if(x == a[p]){
            out(ans);
            continue;
        }
        ll v = ans;
        if(x > a[p]){
            int c = x - (p + 1);
            int ng = -1, ok = tb[p].size();
            while(ng + 1 < ok){
                int mid = (ng + ok) / 2;
                if(tb[p][mid].first >= -c)ok = mid;
                else ng = mid;
            }
            v += s[p].back() - s[p][ok];
        }else{
            int c = x - (p + 1);
            int l = a[p] - (p + 1);
            

            

            

            

            l *= -1;
            c *= -1;
            int ng = -1, ok = p;
            while(ng + 1 < ok){
                int mid = (ok + ng) / 2;
                if(tb2[mid] >= p)ok = mid;
                else ng = mid;
            }
            c = min(p, max(ok, c));
            l = min(p, max(ok, l));
            v -= s2[c] - s2[l];
            v += (ll)(c - l) * (ll)(p);
        }
        out(v);
    }
}