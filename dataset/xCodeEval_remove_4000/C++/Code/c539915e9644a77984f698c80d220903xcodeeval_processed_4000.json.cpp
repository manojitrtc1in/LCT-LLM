
namespace range_detail {
namespace lang {
namespace detail {
template <typename T> struct iter_base : std::iterator<std::input_iterator_tag, T> {
    T current, step_;
    iter_base(T current, T step = 1) : current(current), step_(step) {
    }
    T operator*() const {
        return current;
    }
    T const *operator->() const {
        return &current;
    }
    iter_base &operator++() {
        current += step_;
        return *this;
    }
    iter_base operator++(int) {
        auto copy = *this;
        ++*this;
        return copy;
    }
    bool operator==(iter_base const &other) const {
        return step_ > 0 ? current >= other.current : current <= other.current;
    }
    bool operator!=(iter_base const &other) const {
        return not(*this == other);
    }
};
}
template <typename T> struct id11 {
    using iterator = detail::iter_base<T>;
    id11(T begin, T end, T step = 1) : begin_(begin, step), end_(end, step) {
    }
    iterator begin() const {
        return begin_;
    }
    iterator end() const {
        return end_;
    }
    T step_size() const {
        return begin().step_;
    }
    T last() const {
        return *begin() + (size() - 1) * step_size();
    }
    std::size_t size() const {
        if (*end() >= *begin()) {
            if (step_size() < T{0})
                return 0;
        } else {
            if (step_size() > T{0})
                return 0;
        }
        return std::ceil(std::abs(static_cast<double>(*end() - *begin()) / step_size()));
    }
    id11<T> step(T nstep) const {
        return {*begin(), *end(), nstep};
    }
    id11<T> rev() const {
        return {last(), last() - static_cast<T>(size()) * step_size(), -step_size()};
    }
    id11<T> add(T x = 1) const {
        return {*begin() + x, *end() + x, step_size()};
    }
    bool has(T x) const {
        auto i = (x - *begin());
        auto q = i / step_size(), r = i % step_size();
        return r == 0 and 0 <= q and q < size();
    }
    std::vector<T> vec() const {
        std::vector<T> res(size());
        auto b = begin();
        auto e = end();
        size_t i = 0;
        while (b != e) {
            res[i++] = *b++;
        }
        return res;
    }
private:
    iterator begin_;
    iterator end_;
};
template <typename T> struct id15 {
    struct sentry {};
    struct iterator : detail::iter_base<T> {
        iterator(T current, T step) : detail::iter_base<T>(current, step) {
        }
        bool operator==(sentry const &) const {
            return false;
        }
        bool operator!=(sentry const &) const {
            return true;
        }
    };
    id15(T begin, T step) : begin_(begin, step) {
    }
    iterator begin() const {
        return begin_;
    }
    sentry end() const {
        return sentry{};
    }
    T step_size() const {
        return begin_.step_;
    }
    id15<T> rev() const {
        return {*begin(), -1 * step_size()};
    }
    id11<T> rep(T len) const {
        return {*begin(), *begin() + len * step_size(), step_size()};
    }
    id15<T> step(T nstep) const {
        return {*begin(), nstep};
    }
    id15<T> add(T x = 1) const {
        return {*begin() + x, step_size()};
    }
    bool has(T const &x) const {
        auto i = (x - *begin());
        auto q = i / begin_.step_, r = i % begin_.step_;
        return r == 0 and 0 <= q;
    }
private:
    iterator begin_;
};
template <typename T, typename U>
auto range(T begin, U end) -> id11<typename std::common_type<T, U>::type> {
    using C = typename std::common_type<T, U>::type;
    return {static_cast<C>(begin), static_cast<C>(end), static_cast<C>(1)};
}
template <typename T> auto range(T end) -> id11<T> {
    return range(static_cast<T>(0), end);
}
template <typename T> id15<T> irange(T begin) {
    return {begin, static_cast<T>(1)};
}
namespace traits {
template <typename C> struct has_size {
    template <typename T>
    static auto check(T *) ->
      typename std::is_integral<decltype(std::declval<T const>().size())>::type;
    template <typename> static auto check(...) -> std::false_type;
    using type = decltype(check<C>(0));
    static constexpr bool value = type::value;
};
}
template <typename C, typename = typename std::enable_if<traits::has_size<C>::value>>
auto indices(C const &cont) -> id11<decltype(cont.size())> {
    return {0, cont.size()};
}
template <typename T, std::size_t N> id11<std::size_t> indices(T (&)[N]) {
    return {0, N};
}
template <typename T>
id11<typename std::initializer_list<T>::size_type>
indices(std::initializer_list<T> &&cont) {
    return {0, cont.size()};
}
}
}
namespace range_detail {
namespace lang {
template <typename T> std::ostream &operator<<(std::ostream &out, id11<T> const &r) {
    using R = typename std::iterator_traits<decltype(r.begin())>::value_type;
    std::copy(r.begin(), r.end(), std::ostream_iterator<R>(out, " "));
    return out;
}
template <typename R> std::size_t id10(R const &range) {
    std::size_t size = 0;
    for (auto const &_ : range)
        ++size, (void)_;
    return size;
}
template <typename R> void id0(R const &range) {
    auto const real_size = id10(R{range});
    if (real_size == range.size()) {
        std::cout << range << ".size() = " << real_size << "\n";
    } else {
        std::cout << "ERROR: " << range << ".size() ≠ " << real_size << " (was " << range.size()
                  << ")!\n";
    }
}
}
}
namespace ns_range {
using range_detail::lang::indices;
using range_detail::lang::irange;
using range_detail::lang::range;
}
namespace util {
template <typename T, typename... Args> bool ckmax(T &a, const Args &... b) {
    return (a < std::max({b...})) ? (a = std::max({b...}), true) : false;
}
template <typename T, typename... Args> bool ckmin(T &a, const Args &... b) {
    return (a > std::min({b...})) ? (a = std::min({b...}), true) : false;
}
template <typename T> bool min_swap(T &a, T &b) {
    return (a > b ? std::swap(a, b), true : false);
}
template <typename T> bool max_swap(T &a, T &b) {
    return (a < b ? std::swap(a, b), true : false);
}
template <typename T> T div_floor(const T &a, const T &b) {
    return (a / b) - (!!(a % b) & ((a ^ b) < 0));
}
template <typename T> T id12(const T &a, const T &b) {
    return (a / b) + (!!(a % b) & ((a ^ b) > 0));
}
template<typename T, typename U> T safe_mod(T a, const U& mod) {
    return (a % mod + (!!(a < 0) * mod));
}
template <typename U> struct modulo {
    U n;
    modulo(U n) : n(n) {
    }
};
template <typename T, typename U> T operator%(T a, const modulo<U> &x) {
    return safe_mod(a, x.n);
}
template <typename T, typename U> T &operator%=(T &a, const modulo<U> &x) {
    return a = a % x;
}
template <typename T> int evenp(T p) {
    return 1 - 2 * (p & 1ULL);
}
template <typename T> int oddp(T p) {
    return -evenp(p);
}
template <typename B, typename Mult = std::multiplies<>>
B expo(B const &base, uint64_t power, Mult mult = Mult{}, B const &zero_p = 1) {
    B res = zero_p, x = base;
    for (; power; power >>= 1) {
        if (power & 1) { res = mult(res, x); }
        x = mult(x, x);
    }
    return res;
}
template <typename T> T rectify(T const &x) {
    return std::max(static_cast<T>(0), x);
}
template <typename T, typename V>
std::pair<T, V> intersect(std::pair<T, V> const &x, std::pair<T, V> const &y) {
    auto [p, q] = x;
    auto [r, s] = y;
    if (r > q or p > s) {
        return {0, 0};
    }
    return {std::max(p, r), std::min(q, s)};
}
}
namespace util {
namespace detail {
using std::begin;
using std::end;
template <typename T>
auto id1(int)
  -> decltype(begin(std::declval<T &>()) != end(std::declval<T &>()),
              void(),
              ++std::declval<decltype(begin(std::declval<T &>())) &>(),
              void(*begin(std::declval<T &>())),
              std::true_type{});
template <typename> std::false_type id1(...);
template <typename T> struct is_iterable
{
    using type = decltype(id1<T>(0));
    static constexpr bool value = type::value;
};
}
template <typename T, size_t X> void ctvl(T (&a)[X], const T &v) { std::fill_n(&a[0], X, v); }
template <typename T, size_t X, size_t Y> void ctvl(T (&a)[X][Y], const T &v) {
    std::fill_n(&a[0][0], X * Y, v);
}
template <typename T, size_t X, size_t Y, size_t Z> void ctvl(T (&a)[X][Y][Z], const T &v) {
    std::fill_n(&a[0][0][0], X * Y * Z, v);
}
template <typename T, size_t X, size_t Y, size_t Z, size_t W>
void ctvl(T (&a)[X][Y][Z][W], const T &v) {
    std::fill_n(&a[0][0][0][0], X * Y * Z * W, v);
}
template <typename T, typename V, std::enable_if_t<!detail::is_iterable<T>::value, bool> = false>
void ctvl(T &x, V const &value) {
    x = value;
}
template <typename T, typename V, std::enable_if_t<detail::is_iterable<T>::value, bool> = true>
void ctvl(T &x, V const &value) {
    for (auto &a : x) { ctvl(a, value); }
}
template <typename T> int dedup(std::vector<T> &x) {
    sort(x.begin(), x.end());
    return x.erase(std::unique(x.begin(), x.end()), x.end()) - x.begin();
}
template <typename T> auto id14(std::vector<T> x) {
    return dedup(x), x;
}
template <typename T, typename Compare = std::less<>>
void id4(std::vector<T> &x, int k, Compare cmp = Compare{}) {
    std::partial_sort(x.begin(), x.begin() + k, x.end(), cmp);
}
template <typename T, typename Compare = std::less<>>
int lb_index(std::vector<T> &ct, const T &val, Compare cmp = Compare{}) {
    return (int)(std::lower_bound(ct.begin(), ct.end(), val, cmp) - ct.begin());
}
template <typename T, typename Compare = std::less<>>
int ub_index(std::vector<T> &ct, const T &val, Compare cmp = Compare{}) {
    return (int)(std::upper_bound(ct.begin(), ct.end(), val, cmp) - ct.begin());
}
template <typename T, typename Compare = std::less<>>
int count(std::vector<T> &ct, const T &val, Compare cmp = Compare{}) {
    return ub_index(ct, val, cmp) - lb_index(ct, val, cmp);
}
}
namespace util {
template <typename T> T rel_error(const T &v, const T &cv) {
    return std::abs((v - cv) / cv);
}
template <typename T> T abs_error(const T &v, const T &cv) {
    return std::abs(v - cv);
}
template <typename T> bool float_eq(const T &v, const T &cv, const long double eps = 1e-9) {
    return (abs_error(v, cv) < eps) or (rel_error(v, cv) < eps);
}
}
namespace util {
template <typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T> using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
}
namespace util {
std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
std::vector<std::pair<int, int>> edirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1},
                                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
}
namespace util {
template <typename... Args> std::string fmt(const std::string &format, const Args &... args) {
    if constexpr (sizeof...(Args) == 0) {
        return format;
    } else {
        size_t size = snprintf(nullptr, 0, format.c_str(), args...) + 1;
        if (size <= 0) {
            throw std::runtime_error("Error during formatting.");
        }
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format.c_str(), args...);
        return std::string(buf.get(), buf.get() + size - 1);
    }
}
}
namespace util {
template <typename T> struct errable
{
    bool okay;
    T data;
    template <typename... Args>
    errable(bool _okay, Args const &... args) : okay{_okay}, data{args...} { }
    errable(bool _okay, T const &_data) : okay{_okay}, data{_data} { }
};
}
namespace util {
template <typename T> struct id3 {
    T t_;
    id3(T &&t) : t_(std::forward<T>(t)) {
    }
    template <typename... Args> decltype(auto) operator()(Args &&... args) const {
        return t_(std::ref(*this), std::forward<Args>(args)...);
    }
};
}
namespace util {
std::vector<std::string> split(std::string const &s, std::string const &delim) {
    std::vector<std::string> res;
    auto start = 0U;
    auto end = s.find(delim);
    while (end != std::string::npos) {
        res.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }
    res.push_back(s.substr(start, s.size() - start));
    return res;
}
std::vector<std::string> split(std::string const &s, char const &delim) {
    return split(s, std::string(1, delim));
}
}
namespace vector_util {
template <typename T, int D> struct vecnd {
    using value_type = typename vecnd < T, D - 1 >::type;
    using type = typename std::vector<value_type>;
};
template <typename T> struct vecnd<T, 0> {
    using type = T;
};
template <typename T, typename... Args>
typename vecnd<T, sizeof...(Args)>::type make_vector(size_t n, const Args &... args) {
    if constexpr (sizeof...(args) == 1) {
        return std::vector<T>(n, args...);
    }
    else {
        return typename vecnd<T, sizeof...(Args)>::type(n, make_vector<T>(args...));
    }
}
template <typename... Args> auto make_vector(size_t n, const Args &... args) {
    if constexpr (sizeof...(args) == 1) {
        return std::vector(n, args...);
    }
    else {
        return std::vector(n, make_vector(args...));
    }
}
}
namespace vector_util {
template <typename T, size_t I, size_t... J> struct arraynd {
    using value_type = typename arraynd<T, J...>::type;
    using type = std::array<value_type, I>;
};
template <typename T, size_t I> struct arraynd<T, I> {
    using value_type = T;
    using type = std::array<value_type, I>;
};
namespace detail {
template <typename T, std::size_t... Is>
constexpr std::array<T, sizeof...(Is)> id8(T val, std::index_sequence<Is...>) {
    return {{(static_cast<void>(Is), val)...}};
}
}
template <typename T, size_t I, size_t... J>
constexpr typename arraynd<T, I, J...>::type make_array(T const &val = T{}) {
    if constexpr (sizeof...(J)) {
        return detail::id8(make_array<T, J...>(val), std::make_index_sequence<I>());
    }
    else {
        return detail::id8(val, std::make_index_sequence<I>());
    }
}
}
namespace ndvector {
template <typename T> using vec1d = typename vector_util::vecnd<T, 1>::type;
template <typename T> using vec2d = typename vector_util::vecnd<T, 2>::type;
template <typename T> using vec3d = typename vector_util::vecnd<T, 3>::type;
template <typename T> using vec4d = typename vector_util::vecnd<T, 4>::type;
template <typename T, size_t... J> using arraynd = typename vector_util::arraynd<T, J...>::type;
using vector_util::make_array;
using vector_util::make_vector;
}
namespace fast_readner {
using namespace std;
static char ibuf[1 << 20], *p1 = ibuf, *p2 = ibuf;
bool advance() {
    return p2 = (p1 = ibuf) + fread(ibuf, 1, sizeof(ibuf), stdin), (p1 == p2);
}
char gc() {
    return (p1 == p2 && advance()) ? EOF : (*p1++);
}
void put_back() {
    p1--;
}
static bool isspace(char c) {
    return static_cast<unsigned char>(c - '\t') < 5 || c == ' ';
}
static bool isdigit(char c) {
    return static_cast<unsigned char>(c - '0') < 10;
}
static inline bool id5(char c, const char *str) {
    return strchr(str, c) != nullptr;
}
template <const char *str> static inline bool id5(char c) {
    return strchr(str, c) != nullptr;
}
template<typename UnsignedIntegral> UnsignedIntegral id13() {
    char ch = gc();
    while (!isdigit(ch)) {
        ch = gc();
    }
    UnsignedIntegral res = 0;
    while (isdigit(ch)) {
        res = res * 10 + (ch - '0'), ch = gc();
    }
    return res;
}
template<typename SignedIntegral> SignedIntegral read_ll() {
    char ch = gc();
    bool neg = false;
    while (!isdigit(ch)) {
        neg |= (ch == '-'), ch = gc();
    }
    SignedIntegral res = 0;
    while (isdigit(ch)) {
        res = res * 10 + (ch - '0'), ch = gc();
    }
    neg && (res = -res);
    return res;
}
template<typename FloatingPoint> FloatingPoint read_ld() {
    char ch = gc();
    bool neg = false;
    while (!isdigit(ch)) {
        neg |= (ch == '-'), ch = gc();
    }
    uint64_t integer_part = 0, id9 = 0, len = 0, base = 1;
    while (isdigit(ch)) {
        integer_part = integer_part * 10 + (ch - '0'), ch = gc();
    }
    if (ch == '.') {
        ch = gc();
        while (isdigit(ch)) {
            id9 = id9 * 10 + (ch - '0'), ch = gc(), len += 1;
        }
        while (len--)
            base *= 10;
    }
    FloatingPoint res = (FloatingPoint)integer_part + (FloatingPoint)id9 / base;
    neg && (res = -res);
    return res;
}
std::string id7(const char *str) {
    char ch = gc();
    while (id5(ch, str))
        ch = gc();
    std::string res;
    while (!id5(ch, str))
        res += ch, ch = gc();
    return res;
}
template <typename UnaryPredicate> std::string id7(UnaryPredicate predicate) {
    char ch = gc();
    while (predicate(ch))
        ch = gc();
    std::string res;
    while (!predicate(ch))
        res += ch, ch = gc();
    return res;
}
std::string read_line(char delim = '\n') {
    return id7([&](char ch) {
        return ch == delim;
    });
}
std::string read_string() {
    return id7(isspace);
}
char read_char() {
    return gc();
}
void id6() {
    char ch = gc();
    while (isspace(ch))
        ch = gc();
    put_back();
}
}
namespace fast_writener {
int id2(const char *x) { return printf("%s", x); }
int write_string(const std::string &x) { return id2(x.c_str()); }
int write_char(const char &x) { return printf("%c", x); }
template <typename IntegerType> int write_integer(const IntegerType &arg) {
    return printf("%lld", static_cast<long long>(arg));
}
template <typename FloatType>
int write_float(const FloatType &arg) {
    return printf("%.14lF", arg);
}
}
namespace io_detail {
struct IO
{
    template <typename T> inline IO &operator>>(T &x) {
        if constexpr (std::is_same_v<T, char>) {
            x = fast_readner::read_char();
        } else if constexpr (std::is_integral_v<T> and std::is_signed_v<T>) {
            x = fast_readner::read_ll<T>();
        } else if constexpr (std::is_integral_v<T> and std::is_unsigned_v<T>) {
            x = fast_readner::id13<T>();
        } else if constexpr (std::is_floating_point_v<T>) {
            x = fast_readner::read_ld<T>();
        } else if constexpr (std::is_same_v<std::string, T>) {
            x = fast_readner::read_string();
        }
        return *this;
    }
    template <typename T> inline IO &operator<<(T const &x) {
        if constexpr (std::is_same_v<T, char>) {
            fast_writener::write_char(x);
        } else if constexpr (std::is_integral_v<T> and std::is_signed_v<T>) {
            fast_writener::write_integer<T>(x);
        } else if constexpr (std::is_integral_v<T> and std::is_unsigned_v<T>) {
            fast_writener::write_integer<T>(x);
        } else if constexpr (std::is_floating_point_v<T>) {
            fast_writener::write_float<T>(x);
        } else if constexpr (std::is_same_v<std::string, T>) {
            fast_writener::write_string(x);
        } else {
            fast_writener::id2(x);
        }
        return *this;
    }
} ion;
}
namespace io_detail {
template <typename Tuple, size_t... I> auto &read_impl(Tuple &res, std::index_sequence<I...>) {
    ((io_detail::ion >> std::get<I>(res)), ...);
    if constexpr (sizeof...(I) == 1) {
        return std::get<0>(res);
    } else {
        return res;
    }
}
template <typename T> int write_impl(T const &args) {
    return io_detail::ion << args, 0;
}
}
namespace io_detail {
template <typename... Args> auto reads(Args &... args) {
    auto res = std::tie(args...);
    return read_impl(res, std::make_index_sequence<sizeof...(Args)>()), sizeof...(Args);
}
template <template <typename...> typename Tuple, typename... Args> auto reads(Tuple<Args...> &args) {
    return read_impl(args, std::make_index_sequence<sizeof...(Args)>()), sizeof...(Args);
}
template <template <typename, size_t> typename Array, typename T, size_t I> auto reads(Array<T, I> &args) {
    return read_impl(args, std::make_index_sequence<I>()), I;
}
template <typename... Args> auto read() {
    std::tuple<Args...> res;
    return read_impl(res, std::make_index_sequence<sizeof...(Args)>());
}
template <typename T, size_t I> auto read() {
    std::array<T, I> res;
    return read_impl(res, std::make_index_sequence<I>());
}
template <typename T, size_t I> auto read(int n, int s = 0) {
    std::vector<decltype(read<T, I>())> res(n + s);
    for (int i = 0; i < n; ++i) {
        reads(res[i + s]);
    }
    return res;
}
template <typename... Args> auto read(int n, int s = 0) {
    std::vector<decltype(read<Args...>())> res(n + s);
    for (int i = 0; i < n; ++i) {
        reads(res[i + s]);
    }
    return res;
}
template <typename... Args> int writeln(const Args &... args) {
    std::string sep = "";
    return ((write_impl(sep), write_impl(args), sep = " "), ...), write_impl("\n"), sizeof...(args);
}
template <typename... Args> int write(const Args &... args) {
    return ((write_impl(args)), ...), sizeof...(args);
}
template <typename... Args> int writes(const Args &... args) {
    std::string sep = "";
    return ((write_impl(sep), write_impl(args), sep = " "), ...), sizeof...(args);
}
}
namespace IO {
using io_detail::read;
using io_detail::reads;
using io_detail::write;
using io_detail::writeln;
using io_detail::writes;
}
using namespace IO;
using namespace util;
using namespace ns_range;
using namespace ndvector;
using i64 = long long;
using ld80 = long double;
const int N = 200'0'10;
using namespace std;
auto soln(int __tc) {
    auto [n, m, k] = read<int, 3>();
    writeln(k + 1 == n * m ? "YES" : "NO");
    return 0;
}
signed main() {
    int t = 1;
    std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);
    std::cout << std::setprecision(10) << std::fixed;
    t = read<int>();
    for (int i = 1; i <= t; ++i) { soln(i); }
    return 0;
}