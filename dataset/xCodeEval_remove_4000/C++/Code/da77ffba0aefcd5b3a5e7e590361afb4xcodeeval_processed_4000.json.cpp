







namespace suisen {


template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}



template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;



template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool id11 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

} 




using i128 = __int128_t;
using u128 = __uint128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec <T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;


































template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U> &a) {
    return out << a.first << ' ' << a.second;
}


template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return out;
    } else {
        out << std::get<N>(a);
        if constexpr (N + 1 < std::tuple_size_v<std::tuple<Args...>>) {
            out << ' ';
        }
        return operator<<<N + 1>(out, a);
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}


template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head &head, const Tail &...tails) {
    std::cout << head;
    if (sizeof...(tails)) std::cout << ' ';
    print(tails...);
}
template <typename Iterable>
auto print_all(const Iterable& v, std::string sep = " ", std::string end = "\n") -> decltype(std::cout << *v.begin(), void()) {
    for (auto it = v.begin(); it != v.end();) {
        std::cout << *it;
        if (++it != v.end()) std::cout << sep;
    }
    std::cout << end;
}



template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U> &a) {
    return in >> a.first >> a.second;
}


template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}


template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}


template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    ( std::cin >> ... >> args );
}






template <typename T>
constexpr inline int id8(T n) {
    return -(n & 1) | 1;
}


template <>
constexpr inline int id8<bool>(bool n) {
    return -int(n) | 1;
}



template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + id8(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + id8(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id23(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id23(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id23(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id37(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id37(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id37(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id19(const T x) { return suisen::bit_num<T> - 1 - id23(x); }
template <typename T>
constexpr inline int id35(const T x)  { return id19(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id39(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id31 {
        const int s; int t;
        constexpr id31(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id31(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id28(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable &iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}
template <typename T>
auto id10(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id10(T n) {
    return id10(0, n);
}

template <typename T>
void id36(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto id5(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto id5(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()){
    id5(c.begin(), c.end(), f);
}






template <typename T>
inline bool chmin(T &x, const T &y) {
    if (y >= x) return false;
    x = y;
    return true;
}


template <typename T>
inline bool chmax(T &x, const T &y) {
    if (y <= x) return false;
    x = y;
    return true;
}

namespace suisen {}
using namespace suisen;
using namespace std;

struct io_setup {
    io_setup(int precision = 20) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(precision);
    }
} id7 {};
















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







constexpr long long id38(long long x, long long n, int m) {
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









constexpr bool id34(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id38(a, t, n);
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
template <int n> constexpr bool is_prime = id34(n);





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







constexpr int id24(int m) {
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
            if (id38(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id24(m);







unsigned long long id3(unsigned long long n,
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
struct id33 : internal::static_modint_base {
    using mint = id33;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id33() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id33(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id33(T v) {
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

template <int id> struct id30 : internal::modint_base {
    using mint = id30;

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

    id30() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id30(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id30(T v) {
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
template <int id> internal::barrett id30<id>::bt(998244353);

using modint998244353 = id33<998244353>;
using modint1000000007 = id33<1000000007>;
using modint = id30<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id30<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  


using mint = atcoder::modint998244353;

std::istream& operator>>(std::istream& in, mint &a) {
    long long e; in >> e; a = e;
    return in;
}

std::ostream& operator<<(std::ostream& out, const mint &a) {
    out << a.val();
    return out;
}




namespace atcoder {









struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    

    

    std::vector<int> parent_or_size;
};

}  







namespace atcoder {

namespace internal {





int id14(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





constexpr int id15(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
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

template <class mint,
          int g = internal::primitive_root<mint::mod()>,
          internal::is_static_modint_t<mint>* = nullptr>
struct fft_info {
    static constexpr int rank2 = id15(mint::mod() - 1);
    std::array<mint, rank2 + 1> root;   

    std::array<mint, rank2 + 1> iroot;  


    std::array<mint, std::max(0, rank2 - 2 + 1)> rate2;
    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;

    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;
    std::array<mint, std::max(0, rank2 - 3 + 1)> irate3;

    fft_info() {
        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
        iroot[rank2] = root[rank2].inv();
        for (int i = rank2 - 1; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }

        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 2; i++) {
                rate2[i] = root[i + 2] * prod;
                irate2[i] = iroot[i + 2] * iprod;
                prod *= iroot[i + 2];
                iprod *= root[i + 2];
            }
        }
        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 3; i++) {
                rate3[i] = root[i + 3] * prod;
                irate3[i] = iroot[i + 3] * iprod;
                prod *= iroot[i + 3];
                iprod *= root[i + 3];
            }
        }
    }
};

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id6(std::vector<mint>& a) {
    int n = int(a.size());
    int h = internal::id14(n);

    static const fft_info<mint> info;

    int len = 0;  

    while (len < h) {
        if (h - len == 1) {
            int p = 1 << (h - len - 1);
            mint rot = 1;
            for (int s = 0; s < (1 << len); s++) {
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * rot;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate2[bsf(~(unsigned int)(s))];
            }
            len++;
        } else {
            

            int p = 1 << (h - len - 2);
            mint rot = 1, imag = info.root[2];
            for (int s = 0; s < (1 << len); s++) {
                mint rot2 = rot * rot;
                mint rot3 = rot2 * rot;
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto mod2 = 1ULL * mint::mod() * mint::mod();
                    auto a0 = 1ULL * a[i + offset].val();
                    auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
                    auto id20 =
                        1ULL * mint(a1 + mod2 - a3).val() * imag.val();
                    auto na2 = mod2 - a2;
                    a[i + offset] = a0 + a2 + a1 + a3;
                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
                    a[i + offset + 2 * p] = a0 + na2 + id20;
                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - id20);
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate3[bsf(~(unsigned int)(s))];
            }
            len += 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id27(std::vector<mint>& a) {
    int n = int(a.size());
    int h = internal::id14(n);

    static const fft_info<mint> info;

    int len = h;  

    while (len) {
        if (len == 1) {
            int p = 1 << (h - len);
            mint irot = 1;
            for (int s = 0; s < (1 << (len - 1)); s++) {
                int offset = s << (h - len + 1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] =
                        (unsigned long long)(mint::mod() + l.val() - r.val()) *
                        irot.val();
                    ;
                }
                if (s + 1 != (1 << (len - 1)))
                    irot *= info.irate2[bsf(~(unsigned int)(s))];
            }
            len--;
        } else {
            

            int p = 1 << (h - len);
            mint irot = 1, iimag = info.iroot[2];
            for (int s = 0; s < (1 << (len - 2)); s++) {
                mint id22 = irot * irot;
                mint id21 = id22 * irot;
                int offset = s << (h - len + 2);
                for (int i = 0; i < p; i++) {
                    auto a0 = 1ULL * a[i + offset + 0 * p].val();
                    auto a1 = 1ULL * a[i + offset + 1 * p].val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val();

                    auto id16 =
                        1ULL *
                        mint((mint::mod() + a2 - a3) * iimag.val()).val();

                    a[i + offset] = a0 + a1 + a2 + a3;
                    a[i + offset + 1 * p] =
                        (a0 + (mint::mod() - a1) + id16) * irot.val();
                    a[i + offset + 2 * p] =
                        (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) *
                        id22.val();
                    a[i + offset + 3 * p] =
                        (a0 + (mint::mod() - a1) + (mint::mod() - id16)) *
                        id21.val();
                }
                if (s + 1 != (1 << (len - 2)))
                    irot *= info.irate3[bsf(~(unsigned int)(s))];
            }
            len -= 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> id29(const std::vector<mint>& a,
                                    const std::vector<mint>& b) {
    int n = int(a.size()), m = int(b.size());
    std::vector<mint> ans(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    }
    return ans;
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> id9(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    int z = 1 << internal::id14(n + m - 1);
    a.resize(z);
    internal::id6(a);
    b.resize(z);
    internal::id6(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::id27(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

}  


template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint>&& a, std::vector<mint>&& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) return id29(a, b);
    return internal::id9(a, b);
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(const std::vector<mint>& a,
                              const std::vector<mint>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) return id29(a, b);
    return internal::id9(a, b);
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = id33<mod>;
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

std::vector<long long> id17(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  

    static constexpr unsigned long long MOD2 = 167772161;  

    static constexpr unsigned long long MOD3 = 469762049;  

    static constexpr unsigned long long id2 = MOD2 * MOD3;
    static constexpr unsigned long long id26 = MOD1 * MOD3;
    static constexpr unsigned long long id1 = MOD1 * MOD2;
    static constexpr unsigned long long id25 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::id4(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::id4(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::id4(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * id2;
        x += (c2[i] * i2) % MOD2 * id26;
        x += (c3[i] * i3) % MOD3 * id1;
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, id25, 2 * id25, 3 * id25};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  




namespace suisen {
template <typename mint>
class id12 {
    public:
        id12() {}
        id12(int n) { ensure(n); }
        const mint& operator[](int i) const {
            ensure(i);
            return invs[i];
        }
        static void ensure(int n) {
            int sz = invs.size();
            if (sz < 2) invs = {0, 1}, sz = 2;
            if (sz < n + 1) {
                invs.resize(n + 1);
                for (int i = sz; i <= n; ++i) invs[i] = mint(mod - mod / i) * invs[mod % i];
            }
        }
    private:
        static std::vector<mint> invs;
        static constexpr int mod = mint::mod();
};
template <typename mint>
std::vector<mint> id12<mint>::invs{};
}

namespace suisen {

template <typename mint>
using convolution_t = std::vector<mint> (*)(const std::vector<mint> &, const std::vector<mint> &);

template <typename mint>
class FPS : public std::vector<mint> {
    public:
        using std::vector<mint>::vector;

        FPS(const std::initializer_list<mint> l) : std::vector<mint>::vector(l) {}

        static void set_multiplication(convolution_t<mint> multiplication) {
            FPS<mint>::mult = multiplication;
        }

        inline FPS& operator=(const std::vector<mint> &&f) & noexcept {
            std::vector<mint>::operator=(std::move(f));
            return *this;
        }
        inline FPS& operator=(const std::vector<mint>  &f) & {
            std::vector<mint>::operator=(f);
            return *this;
        }

        inline const mint  operator[](int n) const noexcept { return n <= deg() ? unsafe_get(n) : 0; }
        inline       mint& operator[](int n)       noexcept { ensure_deg(n); return unsafe_get(n); }

        inline int size() const noexcept { return std::vector<mint>::size(); }
        inline int deg()  const noexcept { return size() - 1; }
        inline int normalize() {
            while (this->size() and this->back() == 0) this->pop_back();
            return deg();
        }
        inline FPS& pre_inplace(int max_deg) noexcept {
            if (deg() > max_deg) this->resize(std::max(0, max_deg + 1));
            return *this;
        }
        inline FPS pre(int max_deg) const noexcept { return FPS(*this).pre_inplace(max_deg); }

        inline FPS operator+() const { return FPS(*this); }
        FPS operator-() const {
            FPS f(*this);
            for (auto &e : f) e = mint::mod() - e;
            return f;
        }
        inline FPS& operator++() { ++(*this)[0]; return *this; }
        inline FPS& operator--() { --(*this)[0]; return *this; }
        inline FPS& operator+=(const mint x) { (*this)[0] += x; return *this; }
        inline FPS& operator-=(const mint x) { (*this)[0] -= x; return *this; }
        FPS& operator+=(const FPS &g) {
            ensure_deg(g.deg());
            for (int i = 0; i <= g.deg(); ++i) unsafe_get(i) += g.unsafe_get(i);
            return *this;
        }
        FPS& operator-=(const FPS &g) {
            ensure_deg(g.deg());
            for (int i = 0; i <= g.deg(); ++i) unsafe_get(i) -= g.unsafe_get(i);
            return *this;
        }
        inline FPS& operator*=(const FPS  &g) { return *this = FPS<mint>::mult(*this, g); }
        inline FPS& operator*=(      FPS &&g) { return *this = FPS<mint>::mult(*this, g); }
        inline FPS& operator*=(const mint x) {
            for (auto &e : *this) e *= x;
            return *this;
        }
        FPS& operator/=(FPS &&g) {
            const int fd = normalize(), gd = g.normalize();
            assert(gd >= 0);
            if (fd < gd) { this->clear(); return *this; }
            if (gd == 0) return *this *= g.unsafe_get(0).inv();
            static constexpr int id32 = 256;
            if (gd <= id32) {
                *this = std::move(naive_div_inplace(std::move(g), gd).first);
                return *this;
            }
            std::reverse(this->begin(), this->end()), std::reverse(g.begin(), g.end());
            const int k = fd - gd;
            *this *= g.inv_inplace(k), this->resize(k + 1);
            std::reverse(this->begin(), this->end());
            return *this;
        }
        FPS& operator%=(FPS &&g) {
            int fd = normalize(), gd = g.normalize();
            assert(gd >= 0);
            if (fd < gd) return *this;
            if (gd == 0) { this->clear(); return *this; }
            static constexpr int id13 = 256;
            if (gd <= id13) return naive_div_inplace(std::move(g), gd).second;
            *this -= g * (*this / g);
            return pre_inplace(gd - 1);
        }
        inline FPS& operator/=(const FPS &g) { return *this /= FPS(g); }
        inline FPS& operator%=(const FPS &g) { return *this %= FPS(g); }
        FPS& operator<<=(const int shamt) {
            this->insert(this->begin(), shamt, 0);
            return *this;
        }
        FPS& operator>>=(const int shamt) {
            if (shamt > size()) this->clear();
            else this->erase(this->begin(), this->begin() + shamt);
            return *this;
        }

        inline FPS operator+(FPS &&g) const { return FPS(*this) += std::move(g); }
        inline FPS operator-(FPS &&g) const { return FPS(*this) -= std::move(g); }
        inline FPS operator*(FPS &&g) const { return FPS(*this) *= std::move(g); }
        inline FPS operator/(FPS &&g) const { return FPS(*this) /= std::move(g); }
        inline FPS operator%(FPS &&g) const { return FPS(*this) %= std::move(g); }
        inline FPS operator+(const FPS &g) const { return FPS(*this) += g; }
        inline FPS operator+(const mint x) const { return FPS(*this) += x; }
        inline FPS operator-(const FPS &g) const { return FPS(*this) -= g; }
        inline FPS operator-(const mint x) const { return FPS(*this) -= x; }
        inline FPS operator*(const FPS &g) const { return FPS(*this) *= g; }
        inline FPS operator*(const mint x) const { return FPS(*this) *= x; }
        inline FPS operator/(const FPS &g) const { return FPS(*this) /= g; }
        inline FPS operator%(const FPS &g) const { return FPS(*this) %= g; }
        inline friend FPS operator*(const mint x, const FPS  &f) { return f * x; }
        inline friend FPS operator*(const mint x,       FPS &&f) { return f *= x; }
        inline FPS operator<<(const int shamt) { return FPS(*this) <<= shamt; }
        inline FPS operator>>(const int shamt) { return FPS(*this) >>= shamt; }

        friend bool operator==(const FPS &f, const FPS &g) {
            int n = f.size(), m = g.size();
            if (n < m) return g == f;
            for (int i = 0; i < m; ++i) if (f.unsafe_get(i) != g.unsafe_get(i)) return false;
            for (int i = m; i < n; ++i) if (f.unsafe_get(i) != 0) return false;
            return true;
        }

        FPS& diff_inplace() {
            if (this->size() == 0) return *this;
            for (int i = 1; i <= deg(); ++i) unsafe_get(i - 1) = unsafe_get(i) * i;
            this->pop_back();
            return *this;
        }
        FPS& intg_inplace() {
            int d = deg();
            ensure_deg(d + 1);
            for (int i = d; i >= 0; --i) unsafe_get(i + 1) = unsafe_get(i) * invs[i + 1];
            unsafe_get(0) = 0;
            return *this;
        }
        FPS& inv_inplace(const int max_deg) {
            FPS res { unsafe_get(0).inv() };
            for (int k = 1; k <= max_deg; k *= 2) {
                FPS tmp(this->pre(k * 2) * (res * res));
                res *= 2, res -= tmp.pre_inplace(2 * k);
            }
            return *this = std::move(res), pre_inplace(max_deg);
        }
        FPS& log_inplace(const int max_deg) {
            FPS f_inv = inv(max_deg);
            diff_inplace(), *this *= f_inv, pre_inplace(max_deg - 1), intg_inplace();
            return *this;
        }
        FPS& exp_inplace(const int max_deg) {
            FPS res {1};
            for (int k = 1; k <= max_deg; k *= 2) res *= ++(pre(k * 2) - res.log(k * 2)), res.pre_inplace(k * 2);
            return *this = std::move(res), pre_inplace(max_deg);
        }
        FPS& pow_inplace(const long long k, const int max_deg) {
            int tlz = 0;
            while (tlz <= deg() and unsafe_get(tlz) == 0) ++tlz;
            if (tlz * k > max_deg) { this->clear(); return *this; }
            *this >>= tlz;
            mint base = (*this)[0];
            *this *= base.inv(), log_inplace(max_deg), *this *= k, exp_inplace(max_deg), *this *= base.pow(k);
            return *this <<= tlz * k, pre_inplace(max_deg);
        }
        inline FPS diff() const { return FPS(*this).diff_inplace(); }
        inline FPS intg() const { return FPS(*this).intg_inplace(); }
        inline FPS inv(const int max_deg) const { return FPS(*this).inv_inplace(max_deg); }
        inline FPS log(const int max_deg) const { return FPS(*this).log_inplace(max_deg); }
        inline FPS exp(const int max_deg) const { return FPS(*this).exp_inplace(max_deg); }
        inline FPS pow(const long long k, const int max_deg) const { return FPS(*this).pow_inplace(k, max_deg); }

    private:
        static id12<mint> invs;
        static convolution_t<mint> mult;
        inline void ensure_deg(int d) { if (deg() < d) this->resize(d + 1, 0); }
        inline const mint& unsafe_get(int i) const { return std::vector<mint>::operator[](i); }
        inline       mint& unsafe_get(int i)       { return std::vector<mint>::operator[](i); }

        std::pair<FPS, FPS&> naive_div_inplace(FPS &&g, const int gd) {
            const int k = deg() - gd;
            mint head_inv = g.unsafe_get(gd).inv();
            FPS q(k + 1);
            for (int i = k; i >= 0; --i) {
                mint div = this->unsafe_get(i + gd) * head_inv;
                q.unsafe_get(i) = div;
                for (int j = 0; j <= gd; ++j) this->unsafe_get(i + j) -= div * g.unsafe_get(j);
            }
            return {q, pre_inplace(gd - 1)};
        }
};

template <typename mint>
convolution_t<mint> FPS<mint>::mult = [](const auto &, const auto &) {
    std::cerr << "convolution function is not available." << std::endl;
    assert(false);
    return std::vector<mint>{};
};

} 


template <typename mint>
auto sqrt(suisen::FPS<mint> a) -> decltype(mint::mod(), suisen::FPS<mint>{})  {
    assert(false);
}
template <typename mint>
auto log(suisen::FPS<mint> a) -> decltype(mint::mod(), suisen::FPS<mint>{}) {
    return a.log(a.deg());
}
template <typename mint>
auto exp(suisen::FPS<mint> a) -> decltype(mint::mod(), mint()) {
    return a.exp(a.deg());
}
template <typename mint, typename T>
auto pow(suisen::FPS<mint> a, T b) -> decltype(mint::mod(), mint()) {
    return a.pow(b, a.deg());
}
template <typename mint>
auto inv(suisen::FPS<mint> a) -> decltype(mint::mod(), suisen::FPS<mint>{})  {
    return a.inv(a.deg());
}

int main() {
    suisen::FPS<mint>::set_multiplication([](const auto &a, const auto &b) { return atcoder::convolution(a, b); });

    input(int, n, m, k);

    vector<vector<int>> g(k), h(k);

    loop(n) {
        input(int, c);
        vector<int> a(c);
        read(a);
        for (auto &e : a) --e;
        rep(i, c - 1) {
            int fr = a[i], to = a[i + 1];
            g[fr].push_back(to);
            h[to].push_back(fr);
        }
    }

    rep(i, k) {
        id36(g[i]);
        id36(h[i]);
    }

    atcoder::dsu uf(k);

    rep(i, k) {
        for (int j : g[i]) uf.merge(i, j);
    }

    FPS<mint> f { 1 };
    for (auto group : uf.groups()) {
        bool self_loop = false;
        bool exists_start = false;

        bool id0 = true;
        bool id18 = true;

        for (int v : group) {
            self_loop |= find(all(g[v]), v) != g[v].end();
            exists_start |= h[v].empty();

            id0 &= h[v].size() <= 1;
            id18 &= g[v].size() <= 1;
        }

        if (id0 and id18 and not self_loop and exists_start) {
            --f[group.size()];
        }
    }
    print(f.inv(m)[m]);

    return 0;
}
