
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

typedef pair<int,int> Pii;






















typedef string::const_iterator State;
class ParseError {};


const ll mod = 998244353;


const ll inf = 4100000000000000000ll;
const ld eps = ld(0.00000000000001);
const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T,class K>void vcin(vector<T> &n,vector<K> &m){for(int i=0;i<int(n.size());i++) cin>>n[i]>>m[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
template<class T>void vcin(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cin>>n[i][j];}}}
template<class T>void vcout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<endl;}cout<<endl;}
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void id7(bool a){ cout<<(a?"id7":"IMPOSSIBLE")<<endl; }
template<class T>void print(T a){cout<<a<<endl;}
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
ll id11(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}

void id8() {
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(20);
}
class UnionFind{
public:
  vector<ll> par;
  vector<ll> siz;
  UnionFind(ll sz_):par(sz_),siz(sz_,1ll){
    for(int i=0;i<sz_;i++) par[i]=i;
  }
  void init(ll sz_){
    par.resize(sz_);
    siz.assign(sz_,1ll);
    for(int i=0;i<sz_;i++) par[i]=i;
  }
  ll root(ll x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool merge(ll x,ll y){
    x=root(x);
    y=root(y);
    if(x==y) return false;
    if(siz[x]<siz[y]) swap(x,y);
    siz[x]+=siz[y];
    par[y]=x;
    return true;
  }
  bool issame(ll x,ll y){
    return root(x)==root(y);
  }
  ll size(ll x){
    return siz[root(x)];
  }
};
namespace atcoder {

namespace internal {





int id5(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

}  


}  

namespace atcoder {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}







struct barrett {
    unsigned int _m;
    unsigned long long im;

    

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

    unsigned int umod() const { return _m; }

    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        


        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id17(long long x, long long n, int m) {
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









constexpr bool id16(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id17(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = id16(n);





constexpr std::pair<long long, long long> id2(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  


        

        

        

        


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}







constexpr int id9(int m) {
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
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id17(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id9(m);

}  


}  

namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



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



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id15 : internal::static_modint_base {
    using mint = id15;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id15() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id15(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id15(T v) {
        _v = (unsigned int)(v % umod());
    }
    id15(bool v) { _v = ((unsigned int)(v) % umod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::id2(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct id14 : internal::modint_base {
    using mint = id14;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id14() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id14(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id14(T v) {
        _v = (unsigned int)(v % mod());
    }
    id14(bool v) { _v = ((unsigned int)(v) % mod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::id2(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett id14<id>::bt = 998244353;

using modint998244353 = id15<998244353>;
using modint1000000007 = id15<1000000007>;
using modint = id14<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id14<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  

namespace atcoder {

namespace internal {

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id3(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::id5(n);

    static bool first = true;
    static mint sum_e[30];  

    if (first) {
        first = false;
        mint es[30], ies[30];  

        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            

            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[bsf(~(unsigned int)(s))];
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id13(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::id5(n);

    static bool first = true;
    static mint sum_ie[30];  

    if (first) {
        first = false;
        mint es[30], ies[30];  

        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            

            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] =
                    (unsigned long long)(mint::mod() + l.val() - r.val()) *
                    inow.val();
            }
            inow *= sum_ie[bsf(~(unsigned int)(s))];
        }
    }
}

}  


template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        if (n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mint> ans(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
        return ans;
    }
    int z = 1 << internal::id5(n + m - 1);
    a.resize(z);
    internal::id3(a);
    b.resize(z);
    internal::id3(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::id13(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = id15<mod>;
    std::vector<mint> a2(n), b2(m);
    for (int i = 0; i < n; i++) {
        a2[i] = mint(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b2[i] = mint(b[i]);
    }
    auto c2 = convolution(move(a2), move(b2));
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        c[i] = c2[i].val();
    }
    return c;
}

std::vector<long long> id6(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  

    static constexpr unsigned long long MOD2 = 167772161;  

    static constexpr unsigned long long MOD3 = 469762049;  

    static constexpr unsigned long long id1 = MOD2 * MOD3;
    static constexpr unsigned long long id12 = MOD1 * MOD3;
    static constexpr unsigned long long id0 = MOD1 * MOD2;
    static constexpr unsigned long long id10 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::id2(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::id2(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::id2(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * id1;
        x += (c2[i] * i2) % MOD2 * id12;
        x += (c3[i] * i3) % MOD3 * id0;
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, id10, 2 * id10, 3 * id10};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  

using namespace atcoder;
template<class T>
vector<T> id4(vector<vector<T>> a){
  ll n=a.size();
  queue<ll> q;
  for(int i=0;i<n;i++) q.push(i);
  while(q.size()>1){
    ll x=q.front();
    q.pop();
    ll y=q.front();
    q.pop();
    a[x]=convolution(a[x],a[y]);
    q.push(x);
  }
  return a[q.front()];
}
constexpr ll MAX = 1000010;
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
ll binom(ll n,ll k){
  if(n<k) return 0;
  if(n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
ll HOM(ll n,ll k){
  if(n==0&&k==0) return 1;
  return binom(n+k-1,k);
}
ll POM(ll n,ll k){
  if(n<k) return 0;
  return fac[n]*finv[n-k]%mod;
}
using mint = modint998244353;
int main() {
  id8();
  COMinit();
  ll t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n>>k;
    vector<vector<mint>> d(n);
    vector<ll> p(n);
    vcin(p);
    bool f=true;
    for(int i=n-1;i>=n-k;i--){
      if(p[i]==-1){
        p[i]=0;
      }
      else if(p[i]>0){
        cout<<0<<endl;
        f=false;
        break;
      }
    }
    if(!f) continue;
    for(int i=0;i<n;i++){
      if(p[i]==-1){
        d[i].resize(2);
        d[i][0]=mint(i);
        d[i][1]=1;
      }
      else if(p[i]==0){
        d[i].resize(2);
        d[i][1]=1;
      }
      else{
        d[i].resize(1);
        d[i][0]=1;
      }
    }
    vector<mint> v=id4(d);
    mint ans=0;
    mint c=fac[k+1];
    for(int i=k+1;i<v.size();i++){
      ans+=c*v[i];
      c*=k+1;
    }
    cout<<ans.val()<<endl;
  }
}