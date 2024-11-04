








using namespace std;





























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

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

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

constexpr long long id12(long long x, long long n, int m) {
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

constexpr bool id11(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id12(a, t, n);
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
template <int n> constexpr bool is_prime = id11(n);

constexpr std::pair<long long, long long> id4(long long a, long long b) {
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

constexpr int id7(int m) {
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
            if (id12(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id7(m);

unsigned long long id2(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

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
struct id9 : internal::static_modint_base {
    using mint = id9;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id9() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id9(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id9(T v) {
        _v = (unsigned int)(v % umod());
    }

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
            auto eg = internal::id4(_v, m);
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

template <int id> struct id8 : internal::modint_base {
    using mint = id8;

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

    id8() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id8(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id8(T v) {
        _v = (unsigned int)(v % mod());
    }

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
        auto eg = internal::id4(_v, mod());
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
template <int id> internal::barrett id8<id>::bt(998244353);

using modint998244353 = id9<998244353>;
using modint1000000007 = id9<1000000007>;
using modint = id8<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id8<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  










using namespace atcoder;

using ll= long long;
using ld= long double;
using ull= unsigned long long;
using i128= __int128;
using pll= std::pair<ll, ll>;
template <class T> using vec= std::vector<T>;
template <class T, class Container= std::vector<T>,
          class Compare= std::less<typename Container::value_type>>
using prique= std::priority_queue<T, Container, Compare>;
using vi= vec<int>;
using vl= vec<ll>;
using vd= vec<ld>;
using vs= vec<std::string>;
using vi128= vec<i128>;
using vpll= vec<pll>;
using vvi= vec<vi>;
using vvl= vec<vl>;
using vvd= vec<vd>;
using vvs= vec<vs>;
using vvi128= vec<vi128>;
using vvpll= vec<vpll>;


using mint= atcoder::modint1000000007;

using mint= atcoder::modint998244353;

using vm= vec<mint>;
using vvm= vec<vm>;


constexpr ll mod= 1e9 + 7;

constexpr ll mod= 998244353;















    std::sort(ALL(p)); \
    for(bool(p





template <class T> struct is_pair : std::false_type {};
template <class T1, class T2>
struct is_pair<std::pair<T1, T2>> : std::true_type {};
template <class T> inline constexpr bool is_pair_v= is_pair<T>::value;
template <class T> struct is_tuple : std::false_type {};
template <class... Ts> struct is_tuple<std::tuple<Ts...>> : std::true_type {};
template <class T> inline constexpr bool id0= is_tuple<T>::value;
template <class, class= void> inline constexpr bool has_iterator= false;
template <class T>
inline constexpr bool has_iterator<T, std::void_t<typename T::iterator>> = true;
template <class, class= void> inline constexpr bool id1= false;
template <class T>
inline constexpr bool id1<T, std::void_t<typename T::value_type>> =
    true;

template <class T>
inline constexpr bool is_modint_v= atcoder::internal::is_modint<T>::value;

template <class T> constexpr ll sz(const T &x) {
    return std::size(x);
}
constexpr ll topbit(const ll &t) {
    return (t == 0 ? -1 : 63 - __builtin_clzll(t));
}
constexpr ll bit(const ll &n) noexcept {
    return (1LL << n);
}
template <class T, class U> constexpr T ceil(const T &a, const U &b) {
    assert(b != 0);
    if((a < 0) == (b < 0)) {
        return (a + b - (b > 0) + (b < 0)) / b;
    } else {
        return a / b;
    }
}
template <class T, class U> constexpr T floor(const T &a, const U &b) {
    assert(b != 0);
    if((a < 0) == (b < 0)) {
        return a / b;
    } else {
        return (a - b + (b > 0) - (b < 0)) / b;
    }
}
template <class T> constexpr std::string YES(const T &n) noexcept {
    return (n ? "YES"s : "NO"s);
}
template <class T> constexpr std::string Yes(const T &n) noexcept {
    return (n ? "Yes"s : "No"s);
}
template <class T> constexpr std::string yes(const T &n) noexcept {
    return (n ? "yes"s : "no"s);
}
template <class T> constexpr void uniq(T &v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}
template <class T, class U> constexpr ll lb(const T &v, const U &x) {
    return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template <class T, class U, class Compare>
constexpr ll lb(const T &v, const U &x, Compare comp) {
    return std::distance(v.begin(),
                         std::lower_bound(v.begin(), v.end(), x, comp));
}
template <class T, class U> constexpr ll ub(const T &v, const U &x) {
    return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x));
}
template <class T, class U, class Compare>
constexpr ll ub(const T &v, const U &x, Compare comp) {
    return std::distance(v.begin(),
                         std::upper_bound(v.begin(), v.end(), x, comp));
}
template <class T, class U, class V>
constexpr ll er(const T &v, const U &x, const V &y) {
    return std::distance(std::lower_bound(v.begin(), v.end(), x),
                         std::upper_bound(v.begin(), v.end(), y));
}
template <class T, class U, class V, class Compare>
constexpr ll er(const T &v, const U &x, const V &y, Compare comp) {
    return std::distance(std::lower_bound(v.begin(), v.end(), x, comp),
                         std::upper_bound(v.begin(), v.end(), y, comp));
}
template <class T, class U> constexpr bool chmax(T &a, const U &b) noexcept {
    if(a < b) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T, class U, class Compare>
constexpr bool chmax(T &a, const U &b, Compare comp) noexcept {
    if(comp(a, b)) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T, class U> constexpr bool chmin(T &a, const U &b) noexcept {
    if(b < a) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T, class U, class Compare>
constexpr bool chmin(T &a, const U &b, Compare comp) noexcept {
    if(comp(b, a)) {
        a= b;
        return 1;
    }
    return 0;
}
template <class Container> typename Container::value_type sum(Container &c) {
    return std::accumulate(c.begin(), c.end(),
                           typename Container::value_type());
}
const vpll dx4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vpll dx8{{1, 0},  {1, 1},   {0, 1},  {-1, 1},
               {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
template <class F> struct rec {
    F f;
    rec(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
template <class T, class U>
constexpr std::pair<T, U> operator+(std::pair<T, U> p,
                                    const std::pair<T, U> &q) {
    p+= q;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> &operator+=(std::pair<T, U> &p,
                                      const std::pair<T, U> &q) {
    p.first+= q.first;
    p.second+= q.second;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> operator-(std::pair<T, U> p,
                                    const std::pair<T, U> &q) {
    p-= q;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> &operator-=(std::pair<T, U> &p,
                                      const std::pair<T, U> &q) {
    p.first-= q.first;
    p.second-= q.second;
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> operator+(const std::pair<T, U> &p) {
    return p;
}
template <class T, class U>
constexpr std::pair<T, U> operator-(const std::pair<T, U> &p) {
    return {-p.first, -p.second};
}
inline __int128 parse(std::string s) {
    std::reverse(s.begin(), s.end());
    __int128 ret= 0;
    bool minus= 0;
    if(s.back() == '-') {
        minus= 1;
        s.pop_back();
    }
    while(!s.empty()) {
        if('0' <= s.back() && s.back() <= '9') {
            ret= ret * 10 + s.back() - '0';
            s.pop_back();
        } else {
            break;
        }
    }
    std::reverse(s.begin(), s.end());
    if(minus) ret*= -1;
    return ret;
}
inline std::string to_string(__int128 val) {
    std::string ret= ""s;
    bool minus= 0;
    if(val < 0) {
        minus= 1;
        val*= -1;
    }
    do {
        char digit= '0' + static_cast<char>(val % 10);
        ret+= digit;
        val/= 10;
    } while(val != 0);
    if(minus) ret+= "-"s;
    std::reverse(ret.begin(), ret.end());
    return ret;
}
inline std::string to_string(unsigned __int128 val) {
    std::string ret= ""s;
    do {
        char digit= '0' + static_cast<char>(val % 10);
        ret+= digit;
        val/= 10;
    } while(val != 0);
    std::reverse(ret.begin(), ret.end());
    return ret;
}

    char id5; \
    input(id5)

    std::string id5; \
    input(id5)

    ll id5; \
    input(id5)

    ld id5; \
    input(id5)

    i128 id5; \
    input(id5)

    std::vector<id5> name(size); \
    input(name)

    std::vector name((h), std::vector<id5>(w)); \
    input(name)

int inline id6() {
    return _getchar_nolock();
}
void inline id10(char c) {
    _putchar_nolock(c);
}

inline void input_inner(char &a) {
    do {
        a= static_cast<char>(id6());
    } while(a == ' ' || a == '\n');
}
inline void input_inner(std::string &a) {
    a= ""s;
    int c;
    do { c= id6(); } while(c == ' ' || c == '\n');
    do {
        a+= static_cast<char>(c);
        c= id6();
    } while(c != EOF && c != ' ' && c != '\n');
    std::ungetc(c, stdin);
}
template <class T, std::enable_if_t<std::is_integral_v<T> ||
                                        std::is_same_v<__int128, T> ||
                                        std::is_same_v<unsigned __int128, T>,
                                    std::nullptr_t> = nullptr>
inline void input_inner(T &a) {
    int c;
    do { c= id6(); } while(c == ' ' || c == '\n');
    bool minus= 0;
    if(c == '-') {
        minus= 1;
        c= id6();
    }
    if(c < '0' || '9' < c) {
        std::ungetc(c, stdin);
        return;
    }
    a= 0;
    do {
        a*= 10;
        a+= c - '0';
        c= id6();
    } while(c != EOF && c != ' ' && c != '\n' && '0' <= c && c <= '9');
    std::ungetc(c, stdin);
    if(minus) a*= -1;
}
inline void input_inner(float &a) {
    std::scanf("%f", &a);
}
inline void input_inner(double &a) {
    std::scanf("%lf", &a);
}
inline void input_inner(long double &a) {
    std::scanf("%Lf", &a);
}
template <class T1, class T2> inline void input_inner(std::pair<T1, T2> &a) {
    input_inner(a.first);
    input_inner(a.second);
}
template <class T, std::enable_if_t<has_iterator<T>, std::nullptr_t> = nullptr>
inline void input_inner(T &a) {
    for(auto &&e : a) { input_inner(e); }
}
template <class... Args> inline void input(Args &&...args) {
    using swallow= std::initializer_list<ll>;
    swallow{(input_inner(args), 0)...};
}
template <class T> void print_inner(const T &a);
template <class T, std::size_t... Seq>
void id3(T &A, std::index_sequence<Seq...>) {
    print_inner(std::get<0>(A));
    using swallow= std::initializer_list<ll>;
    swallow{(id10(' '), print_inner(std::get<Seq + 1>(A)), 0)...};
}
template <class T> void print_inner(const T &a) {

    if constexpr(is_modint_v<T>) {
        std::printf("%u", a.val());
        return;
    }

    if constexpr(std::is_pointer_v<T>) {
        std::printf("%p", a);
    } else if constexpr(std::is_same_v<T, char>) {
        id10(a);
    } else if constexpr(std::is_array_v<T> &&
                        is_same_v<std::remove_extent_t<T>, char>) {
        std::printf("%s", a);
    } else if constexpr(std::is_same_v<T, std::string>) {
        std::printf("%s", a.c_str());
    } else if constexpr(std::is_same_v<T, bool>) {
        id10('0' + a);
    } else if constexpr(std::is_same_v<T, signed char>) {
        std::printf("%hhd", a);
    } else if constexpr(std::is_same_v<T, short>) {
        std::printf("%hd", a);
    } else if constexpr(std::is_same_v<T, int>) {
        std::printf("%d", a);
    } else if constexpr(std::is_same_v<T, long>) {
        std::printf("%ld", a);
    } else if constexpr(std::is_same_v<T, long long>) {
        std::printf("%lld", a);
    } else if constexpr(std::is_same_v<T, __int128>) {
        std::printf("%s", to_string(a).c_str());
    } else if constexpr(std::is_same_v<T, unsigned char>) {
        std::printf("%hhu", a);
    } else if constexpr(std::is_same_v<T, unsigned short>) {
        std::printf("%hu", a);
    } else if constexpr(std::is_same_v<T, unsigned int>) {
        std::printf("%u", a);
    } else if constexpr(std::is_same_v<T, unsigned long>) {
        std::printf("%lu", a);
    } else if constexpr(std::is_same_v<T, unsigned long long>) {
        std::printf("%llu", a);
    } else if constexpr(std::is_same_v<T, unsigned __int128>) {
        std::printf("%s", to_string(a).c_str());
    } else if constexpr(std::is_same_v<T, float>) {
        std::printf("%.15f", a);
    } else if constexpr(std::is_same_v<T, double>) {
        std::printf("%.15lf", a);
    } else if constexpr(std::is_same_v<T, long double>) {
        std::printf("%.15Lf", a);
    } else if constexpr(is_pair_v<T>) {
        print_inner(a.first);
        id10(' ');
        print_inner(a.second);
    } else if constexpr(id0<T>) {
        if constexpr(std::tuple_size_v<T> != 0) {
            id3(
                a, std::make_index_sequence<std::tuple_size_v<T> - 1>());
        }
    } else if constexpr(has_iterator<T>) {
        if(a.begin() == a.end()) return;
        print_inner(*(a.begin()));
        if constexpr(!id1<T> ||
                     !has_iterator<typename T::value_type>) {
            std::for_each(std::next(a.begin()), a.end(), [](const auto &value) {
                id10(' ');
                print_inner(value);
            });
        } else if constexpr(!id1<typename T::value_type> ||
                            !has_iterator<typename T::value_type::value_type>) {
            std::for_each(std::next(a.begin()), a.end(), [](const auto &value) {
                id10('\n');
                print_inner(value);
            });
        } else {
            std::for_each(std::next(a.begin()), a.end(), [](const auto &value) {
                id10('\n');
                id10('\n');
                print_inner(value);
            });
        }
    } else {
        std::printf("not supported");
    }
}
inline void print() {
    id10('\n');
}
template <class Head, class... Tail> inline void print(Head &&H, Tail &&...T) {
    print_inner(H);
    using swallow= std::initializer_list<ll>;
    swallow{(id10(' '), print_inner(T), 0)...};
    id10('\n');
}
inline void print_flush() {
    id10('\n');
    fflush(stdout);
}
template <class Head, class... Tail>
inline void print_flush(Head &&H, Tail &&...T) {
    print_inner(H);
    using swallow= std::initializer_list<ll>;
    swallow{(id10(' '), print_inner(T), 0)...};
    id10('\n');
    fflush(stdout);
}
template <class... Args> void debug(Args... args) {

    print_flush(args...);

}


signed main() {
    setvbuf(stdin, nullptr, _IOFBF, 1 << 17);
    setvbuf(stdout, nullptr, _IOFBF, 1 << 17);
    LL(T);
    REP(T) {
        LL(N, M);
        ll allor= 0;
        REP(M) {
            LL(L, R, X);
            allor|= X;
        }
        mint ans= 0;
        mint two= 2;
        REP(l, 30) {
            if(allor & bit(l)) { ans+= two.pow(l) * two.pow(N - 1); }
        }
        print(ans);
    }
}