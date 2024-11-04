













































       
namespace atcoder {
namespace internal {
int id8(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}
int bsf(unsigned int n) {
    return __builtin_ctz(n);
}
}
}
namespace atcoder {
namespace internal {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
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
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};
constexpr long long id22(long long x, long long n, int m) {
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
constexpr bool id20(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id22(a, t, n);
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
template <int n> constexpr bool is_prime = id20(n);
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
constexpr int id12(int m) {
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
            if (id22(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id12(m);
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
template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};
}
}
namespace atcoder {
namespace internal {
struct id14 {
  public:
    explicit id14(int n) : _n(n) {}
    int num_vertices() { return _n; }
    void add_edge(int from, int to) { edges.push_back({from, {to}}); }
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }
    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }
  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
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
template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
}
}
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using ld80 = long double;
namespace bitops {
template <typename T> int popcount(const T &n) {
    return __builtin_popcountll(static_cast<uint64_t>(n));
}
template <typename T, size_t correction = 8 * (sizeof(uint64_t) - sizeof(T))>
int id11(const T &n) {
    return __builtin_clzll(static_cast<uint64_t>(n)) - correction;
}
template <typename T> int id5(const T &n) {
    return __builtin_ctzll(static_cast<uint64_t>(n));
}
template <typename T> int id15(const T &n) { return 8 * sizeof(n) - 1 - id11(n); }
template <typename T> int id16(const T &n) {
    return 8 * sizeof(n) - 1 - id11(n) + !!(n & (n - 1));
}
uint64_t set_bit(int i) { return (1ULL << i); }
template <typename T> T set_bit(T n, int i) { return n | set_bit(i); }
template <typename T> T clear_bit(T n, int i) { return n & ~set_bit(i); }
template <typename T> bool get_bit(const T &n, int i) { return (n & set_bit(i)) >> i; }
template <typename T> std::vector<T> id19(const T &mask) {
    std::vector<T> res;
    for (auto s = mask; s; s = (s - 1) & mask) { res.push_back(res); }
    return res;
}
}
using namespace bitops;
namespace number_theory {
std::vector<int> sieve(int num) {
    std::vector<int> primes;
    std::vector<bool> is_prime(num, true);
    for (int i = 2; i <= (int)std::sqrt(num); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < num; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < num; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
std::map<int, int> id9(int num, const std::vector<int> &primes) {
    std::map<int, int> pdf;
    for (auto &p : primes) {
        if (p > std::sqrt(num) + 1) {
            break;
        }
        while (num % p == 0) {
            num /= p;
            pdf[p] += 1;
        }
    }
    if (num != 1) {
        pdf[num] += 1;
    }
    return pdf;
}
std::set<int> id0(int num, const std::vector<int> &primes) {
    auto pdf = id9(num, primes);
    std::set<int> res{1};
    for (auto &[a, k] : pdf) {
        std::vector<int> z;
        int pw = a;
        for (int j = 1; j <= k; ++j) {
            for (auto &d : res) {
                z.push_back(d * pw);
            }
            pw *= a;
        }
        for (auto &d : z) {
            res.insert(d);
        }
    }
    return res;
}
}
using number_theory::sieve;
using number_theory::id9;
using number_theory::id0;
       
namespace fast_scanner {
using namespace std;
auto read_int() {
    int n;
    cin >> n;
    return n;
}
auto read_ld() {
    long double n;
    cin >> n;
    return n;
}
auto read_ll() {
    long long n;
    cin >> n;
    return n;
}
auto gc() {
    char n;
    cin >> n;
    return n;
}
auto id10() {
}
auto read_string() {
    string s;
    cin >> s;
    return s;
}
auto read_line(char delim = '\n') {
    string s;
    while (s.size() == 0) {
        getline(cin, s, delim);
    }
    return s;
}
}
namespace ns_io_util {
using namespace std;
template <typename T> T scan();
template <> int scan<int>() {
    return fast_scanner::read_int();
}
template <> long scan<long>() {
    return (long)fast_scanner::read_ll();
}
template <> long long scan<long long>() {
    return fast_scanner::read_ll();
}
template <> long double scan<long double>() {
    return fast_scanner::read_ld();
}
template <> double scan<double>() {
    return (double)fast_scanner::read_ld();
}
template <> string scan<string>() {
    return fast_scanner::read_string();
}
template <> char scan<char>() {
    return fast_scanner::gc();
}
template<char delim = '\n'> string scan() {
    return fast_scanner::read_line(delim);
}
template<char delim = '\n'> vector<string> scan(int n) {
    vector<string> res(n);
    for(int i = 0; i < n; ++i) {
        res[i] = fast_scanner::read_line(delim);
    }
    return res;
}
template <typename A, typename B> pair<A, B> scan() {
    auto a = scan<A>();
    auto b = scan<B>();
    return make_pair(a, b);
}
template <typename A, typename B, typename C> tuple<A, B, C> scan() {
    auto a = scan<A>();
    auto b = scan<B>();
    auto c = scan<C>();
    return make_tuple(a, b, c);
}
template <typename A, typename B, typename C, typename D, typename... Args>
tuple<A, B, C, D, Args...> scan() {
    auto a = make_tuple(scan<A>());
    auto b = scan<B, C, D, Args...>();
    return tuple_cat(a, b);
}
template <typename T, size_t U> array<T, U> scan() {
    array<T, U> res;
    for (size_t i = 0; i < U; ++i)
        res[i] = scan<T>();
    return res;
}
template <typename T> vector<T> scan(int n, int s = 0) {
    vector<T> res(n + s);
    for (int i = 0; i < n; ++i) {
        res[i + s] = scan<T>();
    }
    return res;
}
template <typename A, typename B> vector<pair<A, B>> scan(int n, int s = 0) {
    vector<pair<A, B>> res(n + s);
    for (int i = 0; i < n; ++i) {
        res[i + s] = scan<A, B>();
    }
    return res;
}
template <typename A, typename B, typename C, typename... Args>
vector<tuple<A, B, C, Args...>> scan(int n, int s = 0) {
    vector<tuple<A, B, C, Args...>> res(n + s);
    for (int i = 0; i < n; ++i) {
        res[i + s] = scan<A, B, C, Args...>();
    }
    return res;
}
template <typename T, size_t U> vector<array<T, U>> scan(int n, int s = 0) {
    vector<array<T, U>> res(n + s);
    for (int i = 0; i < n; ++i)
        res[i + s] = scan<T, U>();
    return res;
}
}
namespace ns_io_util {
template<typename T> int print(T const& x) { return cout << x, 0; }
}
namespace ns_io_util {
template <typename... Args> int writeln(const Args &... args) {
    return ((print(args), print(" ")), ...), print("\n"), sizeof...(args);
}
template <typename... Args> int write(const Args &... args) {
    return ((print(args)), ...), sizeof...(args);
}
template <typename... Args> int writes(const Args &... args) {
    return ((print(args), print(" ")), ...), sizeof...(args);
}
}
namespace ns_io {
using ns_io_util::scan;
using ns_io_util::write;
using ns_io_util::writeln;
using ns_io_util::writes;
}
       
namespace range_util {
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
template <typename T> struct id17 {
    using iterator = detail::iter_base<T>;
    id17(T begin, T end, T step = 1) : begin_(begin, step), end_(end, step) {
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
    id17<T> step(T nstep) const {
        return {*begin(), *end(), nstep};
    }
    id17<T> rev() const {
        return {last(), last() - static_cast<T>(size()) * step_size(), -step_size()};
    }
    id17<T> add(T x = 1) const {
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
template <typename T> struct id21 {
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
    id21(T begin, T step) : begin_(begin, step) {
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
    id21<T> rev() const {
        return {*begin(), -1 * step_size()};
    }
    id17<T> rep(T len) const {
        return {*begin(), *begin() + len * step_size(), step_size()};
    }
    id21<T> step(T nstep) const {
        return {*begin(), nstep};
    }
    id21<T> add(T x = 1) const {
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
auto range(T begin, U end) -> id17<typename std::common_type<T, U>::type> {
    using C = typename std::common_type<T, U>::type;
    return {static_cast<C>(begin), static_cast<C>(end), static_cast<C>(1)};
}
template <typename T> auto range(T end) -> id17<T> {
    return range(static_cast<T>(0), end);
}
template <typename T> id21<T> irange(T begin) {
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
auto indices(C const &cont) -> id17<decltype(cont.size())> {
    return {0, cont.size()};
}
template <typename T, std::size_t N> id17<std::size_t> indices(T (&)[N]) {
    return {0, N};
}
template <typename T>
id17<typename std::initializer_list<T>::size_type>
indices(std::initializer_list<T> &&cont) {
    return {0, cont.size()};
}
}
}
namespace range_util {
namespace lang {
template <typename T> std::ostream &operator<<(std::ostream &out, id17<T> const &r) {
    using R = typename std::iterator_traits<decltype(r.begin())>::value_type;
    std::copy(r.begin(), r.end(), std::ostream_iterator<R>(out, " "));
    return out;
}
template <typename R> std::size_t id13(R const &range) {
    std::size_t size = 0;
    for (auto const &_ : range)
        ++size, (void)_;
    return size;
}
template <typename R> void id1(R const &range) {
    auto const real_size = id13(R{range});
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
using range_util::lang::indices;
using range_util::lang::irange;
using range_util::lang::range;
}
       
namespace ns_util {
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
template <typename T> T id18(const T &a, const T &b) {
    return (a / b) + (!!(a % b) & ((a ^ b) > 0));
}
template <typename T> struct modulo {
    T n;
    modulo(T n) : n(n) {
    }
};
template <typename T, typename U> U operator%(U a, const modulo<T> &x) {
    return (a % x.n + x.n) % x.n;
}
template <typename T, typename U> U &operator%=(U &a, const modulo<T> &x) {
    return a = a % x;
}
template <typename T> int evenp(T p) {
    return 1 - 2 * (p & 1ULL);
}
template <typename T> int oddp(T p) {
    return -evenp(p);
}
template <typename T, typename U,
          typename std::enable_if<std::is_integral<U>::value, int *>::type = nullptr>
T expo(T const &base, U power) {
    T res = static_cast<T>(1), x = base, one = static_cast<T>(1);
    while (power) {
        if (power & one) {
            (res *= x);
        }
        (x *= x);
        power >>= 1;
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
namespace ns_util {
namespace detail {
using std::begin;
using std::end;
template <typename T>
auto id2(int)
  -> decltype(begin(std::declval<T &>()) != end(std::declval<T &>()),
              void(),
              ++std::declval<decltype(begin(std::declval<T &>())) &>(),
              void(*begin(std::declval<T &>())),
              std::true_type{});
template <typename> std::false_type id2(...);
template <typename T> struct is_iterable {
    using type = decltype(id2<T>(0));
    static constexpr bool value = type::value;
};
}
template <typename T, size_t X> void ctvl(T (&a)[X], const T &v) {
    std::fill_n(&a[0], X, v);
}
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
    for (auto &a : x) {
        ctvl(a, value);
    }
}
template <typename T> void dedup(std::vector<T> &x) {
    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());
}
template <typename T, typename Compare = std::less<>> void id7(std::vector<T> &x, int k, Compare const& cmp = Compare{}) {
    std::partial_sort(x.begin(), x.begin() + k, x.end(), cmp);
}
template <typename T> int lbi(std::vector<T> &ct, const T &val) {
    return (int)(std::lower_bound(ct.begin(), ct.end(), val) - ct.begin());
}
template <typename T> int ubi(std::vector<T> &ct, const T &val) {
    return (int)(std::upper_bound(ct.begin(), ct.end(), val) - ct.begin());
}
}
namespace ns_util {
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
namespace ns_util {
template <typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T> using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
}
namespace ns_util {
std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
std::vector<std::pair<int, int>> edirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1},
                                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
}
namespace ns_util {
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
namespace ns_util {
template <typename T> struct id6 {
    T t_;
    id6(T &&t) : t_(std::forward<T>(t)) {
    }
    template <typename... Args> decltype(auto) operator()(Args &&... args) const {
        return t_(std::ref(*this), std::forward<Args>(args)...);
    }
};
}
       
namespace vector_util {
template <int D, typename T> struct vecnd {
    using value_type = typename vecnd<D - 1, T>::type;
    using type = typename std::vector<value_type>;
};
template <typename T> struct vecnd<0, T> { using type = T; };
template <typename T, typename... Args>
typename vecnd<sizeof...(Args), T>::type make_vector(size_t n, const Args &... args) {
    if constexpr (sizeof...(args) == 1)
        return std::vector<T>(n, args...);
    else
        return typename vecnd<sizeof...(Args), T>::type(n, make_vector<T>(args...));
}
template <typename... Args> auto make_vector(size_t n, const Args &... args) {
    if constexpr (sizeof...(args) == 1)
        return std::vector(n, args...);
    else
        return std::vector(n, make_vector(args...));
}
}
namespace ns_vector {
template <typename T> using vec1d = typename vector_util::vecnd<1, T>::type;
template <typename T> using vec2d = typename vector_util::vecnd<2, T>::type;
template <typename T> using vec3d = typename vector_util::vecnd<3, T>::type;
template <typename T> using vec4d = typename vector_util::vecnd<4, T>::type;
using vector_util::make_vector;
}
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace ns_io;
using namespace ns_util;
using namespace ns_range;
using namespace ns_vector;
using namespace std;
       
       
const int N = 200'0'10;
vector<int> primes, spf;
int n, q;
bool check(map<int, int> &p, map<int, int> &q) {
    for (auto &[e, r] : p) {
        if (q.find(e) != q.end()) return false;
    }
    for (auto &[e, r] : q) {
        if (p.find(e) != p.end()) return false;
    }
    return true;
}
void add(map<int, int> &p, map<int, int> const &q) {
    for (auto &[e, r] : q) { p[e] += r; }
}
void sub(map<int, int> &p, map<int, int> const &q) {
    for (auto &[e, r] : q) {
        p[e] -= r;
        if (p[e] == 0) p.erase(e);
    }
}
vector<int> get_right(vector<int> const &a) {
    int n = (int)a.size();
    vector<int> right(n + 1, n);
    vector<int> last(N, n);
    for(int i : range(n).rev()) {
        auto pf = id9(a[i], primes);
        if(i < n- 1) right[i] = right[i + 1];
        for(auto &[e, r] : pf) {
            ckmin(right[i], last[e]);
            last[e] = i;
        }
    }
    return right;
}
auto soln(int __tc) {
    primes = sieve(sqrt(N));
    42;
    tie(n, q) = scan<int, int>();
    auto a = scan<int>(n);
    42;
    auto x = get_right(a);
    int m = id16(n);
    auto jumps = make_vector(m + 1, n + 1, n);
    42;
    jumps[0] = x;
    42;
    for (int i : range(m).add()) {
        for (int j : range(n)) { jumps[i][j] = jumps[i - 1][jumps[i - 1][j]]; }
    }
    42;
    for (int __ : range(q)) {
        auto [l, r] = scan<int, int>();
        l -= 1;
        int ans = 1;
        for (int i : range(m).rev()) {
            while (l < r and jumps[i][l] < r) {
                ans += (1ULL << (i));
                l = jumps[i][l];
            }
        }
        writeln(ans);
    }
    return 0;
}
signed main() {
    int t = 1;
    std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);
    std::cout << std::setprecision(10) << std::fixed;
    for (int i = 1; i <= t; ++i) {
        auto duration = [&] { auto start_time = chrono::high_resolution_clock::now(); soln(i); auto duration = chrono::duration_cast<chrono::nanoseconds>( chrono::high_resolution_clock::now() - start_time); return duration; }();;
    }
    return 0;
}
