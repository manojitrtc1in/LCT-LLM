










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
static constexpr bool id9 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long int> { using type = __uint128_t; };
template <>
struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

template <typename T, typename = void>
struct rec_value_type {
    using type = T;
};
template <typename T>
struct rec_value_type<T, std::void_t<typename T::value_type>> {
    using type = typename rec_value_type<typename T::value_type>::type;
};
template <typename T>
using rec_value_type_t = typename rec_value_type<T>::type;

} 




using i128 = __int128_t;
using u128 = __uint128_t;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;
































template <class T, class... Args>
void debug_internal(const char* s, T&& first, Args&&... args) {
    constexpr const char* prefix = "[\033[32mDEBUG\033[m] ";
    constexpr const char* open_brakets = sizeof...(args) == 0 ? "" : "(";
    constexpr const char* close_brakets = sizeof...(args) == 0 ? "" : ")";
    std::cerr << prefix << open_brakets << s << close_brakets << ": " << open_brakets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brakets << "\n";
}










std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}


std::ostream& operator<<(std::ostream& dest, __uint128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[value % 10];
            value /= 10;
        } while (value != 0);
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}



template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& a) {
    return out << a.first << ' ' << a.second;
}


template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& a) {
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
std::ostream& operator<<(std::ostream& out, const std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}


template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail &...tails) {
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

__int128_t id32(std::string& s) {
    __int128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    if (s[0] == '-') ret = -ret;
    return ret;
}
__uint128_t id15(std::string& s) {
    __uint128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    return ret;
}


std::istream& operator>>(std::istream& in, __int128_t& v) {
    std::string s;
    in >> s;
    v = id32(s);
    return in;
}


std::istream& operator>>(std::istream& in, __uint128_t& v) {
    std::string s;
    in >> s;
    v = id15(s);
    return in;
}


template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& a) {
    return in >> a.first >> a.second;
}


template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...>& a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}


template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}


template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    (std::cin >> ... >> args);
}






template <typename T>
constexpr inline int id7(T n) {
    return -(n & 1) | 1;
}


template <>
constexpr inline int id7<bool>(bool n) {
    return -int(n) | 1;
}



template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + id7(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + id7(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u64(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id30(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id30(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id30(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id18(const T x) { return suisen::bit_num<T> -1 - id19(x); }
template <typename T>
constexpr inline int id27(const T x) { return id18(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id34(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id21(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable& iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}
template <typename T>
auto id8(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id8(T n) {
    return id8(0, n);
}

template <typename T>
void id29(std::vector<T>& a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto id5(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto id5(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()) {
    id5(c.begin(), c.end(), f);
}






template <typename T>
inline bool chmin(T& x, const T& y) {
    if (y >= x) return false;
    x = y;
    return true;
}


template <typename T>
inline bool chmax(T& x, const T& y) {
    if (y <= x) return false;
    x = y;
    return true;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::string bin(T val, int bit_num = -1) {
    std::string res;
    if (bit_num >= 0) {
        for (int bit = bit_num; bit-- > 0;) res += '0' + ((val >> bit) & 1);
    } else {
        for (; val; val >>= 1) res += '0' + (val & 1);
        std::reverse(res.begin(), res.end());
    }
    return res;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> id28(T val, T base = 10) {
    std::vector<T> res;
    for (; val; val /= base) res.push_back(val % base);
    if (res.empty()) res.push_back(T{ 0 });
    return res;
}
template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> id16(T val, T base = 10) {
    auto res = id28(val, base);
    std::reverse(res.begin(), res.end());
    return res;
}

template <typename T>
std::string join(const std::vector<T>& v, const std::string& sep, const std::string& end) {
    std::ostringstream ss;
    for (auto it = v.begin(); it != v.end();) {
        ss << *it;
        if (++it != v.end()) ss << sep;
    }
    ss << end;
    return ss.str();
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
} id6{};
















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







constexpr long long id33(long long x, long long n, int m) {
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









constexpr bool id26(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id33(a, t, n);
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
template <int n> constexpr bool is_prime = id26(n);





constexpr std::pair<long long, long long> id3(long long a, long long b) {
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







constexpr int id20(int m) {
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
            if (id33(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id20(m);







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
struct id24 : internal::static_modint_base {
    using mint = id24;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id24() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id24(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id24(T v) {
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
            auto eg = internal::id3(_v, m);
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

template <int id> struct id22 : internal::modint_base {
    using mint = id22;

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

    id22() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id22(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id22(T v) {
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
        auto eg = internal::id3(_v, mod());
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
template <int id> internal::barrett id22<id>::bt(998244353);

using modint998244353 = id24<998244353>;
using modint1000000007 = id24<1000000007>;
using modint = id22<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id22<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  


using mint = atcoder::modint998244353;

std::istream& operator>>(std::istream& in, mint& a) {
    long long e; in >> e; a = e;
    return in;
}

std::ostream& operator<<(std::ostream& out, const mint& a) {
    out << a.val();
    return out;
}

constexpr int M = 200000;







namespace suisen {
    template <typename T, T(*op)(T, T), T(*e)()>
    struct SparseTable {
        SparseTable() = default;
        SparseTable(std::vector<T>&& a) : n(a.size()), log(id18(n)), table(log + 1), flog(n + 1, 0) {
            build_table(std::move(a));
            build_flog_table();
        }
        SparseTable(const std::vector<T>& a) : SparseTable(std::vector<T>(a)) {}
        T operator()(int l, int r) const {
            if (l >= r) return e();
            int i = flog[r - l];
            return op(table[i][l], table[i][r - (1 << i)]);
        }
        T prod(int l, int r) const {
            return (*this)(l, r);
        }
    private:
        int n;
        int log;
        std::vector<std::vector<T>> table;
        std::vector<int> flog;

        void build_table(std::vector<T>&& a) {
            table[0] = std::move(a);
            for (int i = 0; i < log; ++i) {
                int lmax = n - (1 << (i + 1));
                table[i + 1].resize(lmax + 1);
                for (int l = 0; l <= lmax; ++l) table[i + 1][l] = op(table[i][l], table[i][l + (1 << i)]);
            }
        }
        void build_flog_table() {
            for (int l = 0; l < log; ++l) {
                std::fill(flog.begin() + (1 << l), flog.begin() + (1 << (l + 1)), l);
            }
            std::fill(flog.begin() + (1 << log), flog.end(), log);
        }
        static int id18(int i) {
            return 31 - __builtin_clz(i);
        }
    };
} 


namespace suisen {

    template <bool id25 = true>
    class id10 {
        static constexpr typename std::conditional_t<id25, std::less<std::pair<int, int>>, std::greater<std::pair<int, int>>> comp{};
        static constexpr typename std::conditional_t<id25, std::less<int>, std::greater<int>> comp_val{};

        static constexpr std::pair<int, int> op(std::pair<int, int> x, std::pair<int, int> y) {
            return comp(x, y) ? x : y;
        }
        static constexpr std::pair<int, int> e() {
            if constexpr (id25) {
                return { std::numeric_limits<int>::max(), -1 };
            } else {
                return { std::numeric_limits<int>::min(), -1 };
            }
        }

        static constexpr int LOG = 4;
        static constexpr int SIZE = 1 << LOG;

        static constexpr class S {
        public:
            int prd[1 << id10<id25>::SIZE];
            int arg[1 << id10<id25>::SIZE];
            constexpr S() : prd(), arg(), sum() {
                prd[id25] = sum[id25] = -1, prd[not id25] = sum[not id25] = 1;
                arg[id25] = arg[not id25] = 0;
                for (int n = 2; n <= id10<id25>::SIZE; n <<= 1) {
                    for (int s = (1 << n) - 1; s >= 0; --s) merge(s, n >> 1);
                }
            }
        private:
            int sum[1 << id10<id25>::SIZE];
            constexpr void merge(int s, int half) {
                int upper = s >> half, lower = s ^ (upper << half);
                if (id10<id25>::comp_val(prd[lower], sum[lower] + prd[upper])) {
                    prd[s] = prd[lower];
                    arg[s] = arg[lower];
                } else {
                    prd[s] = sum[lower] + prd[upper];
                    arg[s] = half + arg[upper];
                }
                sum[s] = sum[lower] + sum[upper];
            }
        } tabs{};

    public:
        id10(std::vector<int>&& x) : n(x.size()), m((n + SIZE - 1) >> LOG), a(std::move(x)), b(m, 0), tabl(build()) {}
        id10(const std::vector<int>& x) : id10(std::vector<int>(x)) {}

        std::pair<int, int> operator()(int l, int r) const {
            if (l >= r) return e();
            static constexpr int MASK = SIZE - 1;
            auto f = [this](int l, int r) -> std::pair<int, int> {
                if (l >= r) return e();
                int idx = cut(b[l >> LOG], l & MASK, ((r - 1) & MASK) + 1);
                return { a[l] + tabs.prd[idx], l + tabs.arg[idx] };
            };
            if (l >> LOG == (r - 1) >> LOG) return f(l, r);
            int spl = (l + SIZE - 1) >> LOG, spr = r >> LOG;
            return op(op(f(l, spl << LOG), f(spr << LOG, r)), tabl(spl, spr));
        }

    private:
        int n, m;
        std::vector<int> a;
        std::vector<std::uint16_t> b;
        SparseTable<std::pair<int, int>, op, e> tabl;

        std::vector<std::pair<int, int>> build() {
            std::vector<std::pair<int, int>> c(m, e());
            if (n == 0) return c;
            std::pair<int, int> p{ a[0] - 1, -1 };
            for (int i = 0; i < n; p = { a[i], i }, ++i) {
                std::pair<int, int> q{ a[i], i };
                int outer = i >> LOG;
                c[outer] = op(c[outer], q);
                b[outer] |= comp(q, p) << (i & (SIZE - 1));
            }
            a.insert(a.begin(), a[0] - 1);
            assert(std::adjacent_find(a.begin(), a.end(), [](int x, int y) { return std::abs(x - y) != 1; }) == a.end());
            return c;
        }

        static constexpr std::uint16_t cut(const std::uint16_t bits, const int l, const int r) {
            return std::uint16_t(bits << (SIZE - r)) >> (SIZE - r + l);
        }
    };
} 


namespace suisen {
class id12 {
    public:
        id12(const std::vector<std::vector<int>> &g, int root = 0) : idx(g.size()), dep(2 * g.size() - 1), tour(2 * g.size() - 1), rmq(dfs(g, root)) {}

        int lca(int u, int v) const { return idx[u] <= idx[v] ? tour[rmq(idx[u], idx[v] + 1).second] : lca(v, u); }
        int dist(int u, int v) const { return dep[idx[u]] + dep[idx[v]] - 2 * dep[idx[operator()(u, v)]]; }
        int operator()(int u, int v) const { return lca(u, v); }
    private:
        std::vector<int> idx, dep, tour;
        id10<true> rmq;

        std::vector<int>& dfs(const std::vector<std::vector<int>> &g, int root) {
            int k = 0;
            auto rec = [&](auto self, int u, int p, int d) -> void {
                dep[k] = d, tour[idx[u] = k++] = u;
                for (int v : g[u]) if (v != p) self(self, v, u, d + 1);
                if (p >= 0) {
                    dep[k] = d - 1, tour[idx[p] = k++] = p;
                }
            };
            rec(rec, root, -1, 0);
            return dep;
        }
};
} 




namespace suisen {

template <unsigned int N>
class id4 {
    public:
        id4() {
            mpf.fill(0);
            dat.fill(1);
            for (long long p = 2; p <= N; ++p) {
                if (mpf[p]) continue;
                mpf[p] = p;
                dat[p] = -1;
                for (long long q = p * 2; q <= N; q += p) {
                    if (not mpf[q]) mpf[q] = p;
                    dat[q] = q % (p * p) ? -dat[q] : 0;
                }
            }
        }
        

        int operator()(unsigned int n) const {
            assert(0 < n and n <= N);
            return dat[n];
        }
        

        int operator[](unsigned int n) const {
            return (*this)(n);
        }
        

        int mobius(unsigned int n) const {
            return (*this)(n);
        }
        

        int min_prime_factor(unsigned int n) const {
            assert(2 <= n and n <= N);
            return mpf[n];
        }
        
        std::vector<std::pair<int, int>> factorize(unsigned int n) const {
            assert(0 < n and n <= N);
            std::vector<std::pair<int, int>> id1;
            while (n > 1) {
                int p = mpf[n], c = 0;
                do { n /= p, ++c; } while (n % p == 0);
                id1.emplace_back(p, c);
            }
            return id1;
        }
        bool is_prime(unsigned int n) const {
            assert(n <= N);
            return 2 <= n and mpf[n] == n;
        }
    private:
        std::array<int, N + 1> mpf;
        std::array<int, N + 1> dat;
};
} 


namespace suisen {
    namespace default_operator {
        template <typename T>
        auto zero() -> decltype(T { 0 }) { return T { 0 }; }
        template <typename T>
        auto one()  -> decltype(T { 1 }) { return T { 1 }; }
        template <typename T>
        auto add(const T &x, const T &y) -> decltype(x + y) { return x + y; }
        template <typename T>
        auto sub(const T &x, const T &y) -> decltype(x - y) { return x - y; }
        template <typename T>
        auto mul(const T &x, const T &y) -> decltype(x * y) { return x * y; }
        template <typename T>
        auto div(const T &x, const T &y) -> decltype(x / y) { return x / y; }
        template <typename T>
        auto mod(const T &x, const T &y) -> decltype(x % y) { return x % y; }
        template <typename T>
        auto neg(const T &x) -> decltype(-x) { return -x; }
        template <typename T>
        auto inv(const T &x) -> decltype(one<T>() / x)  { return one<T>() / x; }
    } 

    namespace default_operator_noref {
        template <typename T>
        auto zero() -> decltype(T { 0 }) { return T { 0 }; }
        template <typename T>
        auto one()  -> decltype(T { 1 }) { return T { 1 }; }
        template <typename T>
        auto add(T x, T y) -> decltype(x + y) { return x + y; }
        template <typename T>
        auto sub(T x, T y) -> decltype(x - y) { return x - y; }
        template <typename T>
        auto mul(T x, T y) -> decltype(x * y) { return x * y; }
        template <typename T>
        auto div(T x, T y) -> decltype(x / y) { return x / y; }
        template <typename T>
        auto mod(T x, T y) -> decltype(x % y) { return x % y; }
        template <typename T>
        auto neg(T x) -> decltype(-x) { return -x; }
        template <typename T>
        auto inv(T x) -> decltype(one<T>() / x)  { return one<T>() / x; }
    } 

} 


namespace suisen::multiple_transform {
    

    template <typename T, auto add = default_operator::add<T>>
    void zeta(std::vector<T> &f) {
        const int n = f.size();
        std::vector<char> is_prime(n, true);
        auto cum = [&](const int p) {
            const int qmax = (n - 1) / p, rmax = qmax * p;
            for (int q = qmax, pq = rmax; q >= 1; --q, pq -= p) {
                f[q] = add(f[q], f[pq]);
                is_prime[pq] = false;
            }
        };
        for (int p = 2; p < n; ++p) if (is_prime[p]) cum(p);
    }
    

    template <typename T, auto sub = default_operator::sub<T>>
    void mobius(std::vector<T> &f) {
        const int n = f.size();
        std::vector<char> is_prime(n, true);
        auto diff = [&](const int p) {
            for (int q = 1, pq = p; pq < n; ++q, pq += p) {
                f[q] = sub(f[q], f[pq]);
                is_prime[pq] = false;
            }
        };
        for (int p = 2; p < n; ++p) if (is_prime[p]) diff(p);
    }
} 


namespace suisen {
class id14 {
    public:
        template <typename Q>
        using is_point_update_query = std::is_invocable<Q, int>;
        template <typename Q>
        using is_range_update_query = std::is_invocable<Q, int, int>;
        template <typename Q, typename T>
        using is_point_get_query  = std::is_same<std::invoke_result_t<Q, int>, T>;
        template <typename Q, typename T>
        using is_range_fold_query = std::is_same<std::invoke_result_t<Q, int, int>, T>;

        using Graph = std::vector<std::vector<int>>;

        id14() = default;
        id14(Graph &g) : n(g.size()), visit(n), leave(n), head(n), ord(n), siz(n), par(n, -1), dep(n, 0) {
            for (int i = 0; i < n; ++i) if (par[i] < 0) dfs(g, i, -1);
            int time = 0;
            for (int i = 0; i < n; ++i) if (par[i] < 0) hld(g, i, -1, time);
        }
        int size() const {
            return n;
        }
        int lca(int u, int v) const {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) return u;
            }
        }
        int la(int u, int k, int default_value = -1) const {
            if (k < 0) return default_value;
            while (u >= 0) {
                int h = head[u];
                if (visit[u] - k >= visit[h]) return ord[visit[u] - k];
                k -= visit[u] - visit[h] + 1;
                u = par[h];
            }
            return default_value;
        }
        int jump(int u, int v, int d, int default_value = -1) const {
            if (d < 0) return default_value;
            const int w = lca(u, v);
            int uw = dep[u] - dep[w];
            if (d <= uw) return la(u, d);
            int vw = dep[v] - dep[w];
            return d <= uw + vw ? la(v, (uw + vw) - d) : default_value;
        }
        int dist(int u, int v) const {
            return dep[u] + dep[v] - 2 * dep[lca(u, v)];
        }
        template <typename T, typename Q, typename F, constraints_t<is_range_fold_query<Q, T>, is_bin_op<F, T>> = nullptr>
        T fold_path(int u, int v, T identity, F bin_op, Q fold_query, bool id13 = false) const {
            T res = identity;
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                res = bin_op(fold_query(visit[head[v]], visit[v] + 1), res);
            }
            return bin_op(fold_query(visit[u] + id13, visit[v] + 1), res);
        }
        template <
            typename T, typename Q1, typename Q2, typename F,
            constraints_t<is_range_fold_query<Q1, T>, is_range_fold_query<Q2, T>, is_bin_op<F, T>> = nullptr
        >
        T id11(int u, int v, T identity, F bin_op, Q1 fold_query, Q2 id23, bool id13 = false) const {
            T res_u = identity, res_v = identity;
            

            

            while (head[u] != head[v]) {
                if (visit[u] < visit[v]) { 

                    res_v = bin_op(fold_query(visit[head[v]], visit[v] + 1), res_v);
                    v = par[head[v]];
                } else { 

                    res_u = bin_op(res_u, id23(visit[head[u]], visit[u] + 1));
                    u = par[head[u]];
                }
            }
            if (visit[u] < visit[v]) { 

                res_v = bin_op(fold_query(visit[u] + id13, visit[v] + 1), res_v);
            } else { 

                res_u = bin_op(res_u, id23(visit[v] + id13, visit[u] + 1));
            }
            return bin_op(res_u, res_v);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_path(int u, int v, Q update_query, bool id13 = false) const {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                update_query(visit[head[v]], visit[v] + 1);
            }
            update_query(visit[u] + id13, visit[v] + 1);
        }
        template <typename T, typename Q, constraints_t<is_range_fold_query<Q, T>> = nullptr>
        T id17(int u, Q fold_query, bool id13 = false) const {
            return fold_query(visit[u] + id13, leave[u]);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void id31(int u, Q update_query, bool id13 = false) const {
            update_query(visit[u] + id13, leave[u]);
        }
        template <typename T, typename Q, constraints_t<is_point_get_query<Q, T>> = nullptr>
        T get_point(int u, Q get_query) const {
            return get_query(visit[u]);
        }
        template <typename Q, constraints_t<is_point_update_query<Q>> = nullptr>
        void update_point(int u, Q update_query) const {
            update_query(visit[u]);
        }
        std::vector<int> inv_ids() const {
            std::vector<int> inv(n);
            for (int i = 0; i < n; ++i) inv[visit[i]] = i;
            return inv;
        }
        int get_visit_time(int u) const {
            return visit[u];
        }
        int get_leave_time(int u) const {
            return leave[u];
        }
        int get_head(int u) const {
            return head[u];
        }
        int get_kth_visited(int k) const {
            return ord[k];
        }
        int get_subtree_size(int u) const {
            return siz[u];
        }
        int get_parent(int u) const {
            return par[u];
        }
        int get_depth(int u) const {
            return dep[u];
        }
        std::vector<int> get_roots() const {
            std::vector<int> res;
            for (int i = 0; i < n; ++i) if (par[i] < 0) res.push_back(i);
            return res;
        }
    private:
        int n;
        std::vector<int> visit, leave, head, ord, siz, par, dep;
        int dfs(Graph &g, int u, int p) {
            par[u] = p;
            siz[u] = 1;
            int max_size = 0;
            for (int &v : g[u]) {
                if (v == p) continue;
                dep[v] = dep[u] + 1;
                siz[u] += dfs(g, v, u);
                if (max_size < siz[v]) {
                    max_size = siz[v];
                    std::swap(g[u].front(), v);
                }
            }
            return siz[u];
        }
        void hld(Graph &g, int u, int p, int &time) {
            visit[u] = time, ord[time] = u, ++time;
            head[u] = p >= 0 and g[p].front() == u ? head[p] : u;
            for (int v : g[u]) {
                if (v != p) hld(g, v, u, time);
            }
            leave[u] = time;
        }
};
} 


namespace suisen {
    struct id0 {
        id0() = default;
        id0(const id14& hld) : _n(hld.size()), _aux(_n), _hld(hld) {}

        const std::vector<int>& operator[](int u) const {
            return _aux[u];
        }

        template <typename LCA>
        void build(std::vector<int> vs, const LCA &lca) {
            const int k = vs.size();
            for (int v : _upd) _aux[v].clear();
            _upd.clear();

            std::copy(vs.begin(), vs.end(), std::back_inserter(_upd));

            std::vector<int> st{ vs[0] };
            for (int i = 0; i < k - 1; ++i) {
                const int w = lca(vs[i], vs[i + 1]);

                if (w != vs[i]) {
                    _upd.push_back(w);
                    int last = st.back();
                    st.pop_back();
                    while (st.size() and _hld.get_depth(w) < _hld.get_depth(st.back())) {
                        int u = st.back();
                        _aux[u].push_back(last);
                        _aux[last].push_back(u);
                        last = st.back();
                        st.pop_back();
                    }

                    if (st.empty() or st.back() != w) {
                        st.push_back(w);
                        vs.push_back(w);
                        _aux[w].push_back(last);
                        _aux[last].push_back(w);
                    } else {
                        _aux[w].push_back(last);
                        _aux[last].push_back(w);
                    }
                }

                st.push_back(vs[i + 1]);
            }
            const int siz = st.size();
            for (int i = 0; i < siz - 1; ++i) {
                _aux[st[i]].push_back(st[i + 1]);
                _aux[st[i + 1]].push_back(st[i]);
            }
        }

        const id14& get_hld() const {
            return _hld;
        }
    private:
        int _n;
        std::vector<std::vector<int>> _aux;
        id14 _hld;
        std::vector<int> _upd;
    };
} 


int main() {
    id4<M> mobius;

    input(int, n);
    vector<int> a(n);
    read(a);

    vector<vector<int>> g(n);
    rep(i, n - 1) {
        input(int, u, v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    id12 lca(g);
    id14 hld(g);

    vector<vector<int>> div(M + 1);
    rep(i, 1, M + 1) {
        rep(j, i, M + 1, i) {
            div[j].push_back(i);
        }
    }

    vector<vector<int>> ids(M + 1);
    rep(i, n) {
        int v = hld.get_kth_visited(i);
        for (int d : div[a[v]]) {
            ids[d].push_back(v);
        }
    }

    id0 at(hld);

    vector<mint> f(M + 1);

    vector<int> sub(n);
    rep(g, 1, M + 1) {
        if (ids[g].empty() or mobius[g] == 0) continue;
        int siz = ids[g].size();

        at.build(ids[g], lca);
        auto dfs = [&](auto dfs, int u, int p, int d) -> void {
            sub[u] = a[u] % g == 0;
            for (int v : at[u]) if (v != p) {
                int a = lca(u, v);
                int d = hld.get_depth(u) + hld.get_depth(v) - 2 * hld.get_depth(a);
                dfs(dfs, v, u, d);
                sub[u] += sub[v];
            }
            if (p == -1) return;
            long long k = siz - sub[u];
            long long l = sub[u];
            f[g] += d * mint((k * l * (l - 1) + l * k * (k - 1)) >> 1);
        };
        dfs(dfs, ids[g][0], -1, -1);
    }
    multiple_transform::mobius(f);

    vector<int> pf_num(M + 1);
    vector<int> val(M + 1);
    iota(all(val), 0);
    rep(p, 2, M + 1) {
        if (val[p] != p) continue;
        rep(q, p, M + 1, p) {
            ++pf_num[q];
            do val[q] /= p; while (val[q] % p == 0);
        }
    }

    mint ans = 0;
    rep(i, 1, M + 1) {
        ans += f[i] * pf_num[i];
    }
    print(ans);

    return 0;
}

