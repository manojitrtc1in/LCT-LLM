





using i32   = int32_t;
using i64   = int64_t;
using u32   = uint32_t;
using u64   = uint64_t;
using uint  = unsigned int;
using usize = std::size_t;
using ll    = long long;
using ull   = unsigned long long;
using ld    = long double;
template<typename T, usize n>
using arr = T (&)[n];
template<typename T, usize n>
using c_arr = const T (&)[n];
template<typename T>
using max_heap = std::priority_queue<T>;
template<typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T> constexpr T popcount(const T u) { return u ? static_cast<T>(__builtin_popcountll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T id0(const T u) { return u ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T id6(const T u) { return id0(u); }
template<typename T> constexpr T id3(const T u) { return __builtin_ffsll(u); }
template<typename T> constexpr T clog(const T u) { return u ? id0(u - 1) : static_cast<T>(u); }
template<typename T> constexpr bool id2(const T u) { return u and (static_cast<u64>(u) & static_cast<u64>(u - 1)) == 0; }
template<typename T> constexpr T ceil2(const T u) { return static_cast<T>(1) << clog(u); }
template<typename T> constexpr T floor2(const T u) { return u == 0 ? static_cast<T>(0) : static_cast<T>(1) << (id0(u) - 1); }
template<typename T> constexpr bool btest(const T mask, const usize ind) { return static_cast<bool>((static_cast<u64>(mask) >> ind) & static_cast<u64>(1)); }
template<typename T> void bset(T& mask, const usize ind) { mask |= (static_cast<T>(1) << ind); }
template<typename T> void breset(T& mask, const usize ind) { mask &= ~(static_cast<T>(1) << ind); }
template<typename T> void bflip(T& mask, const usize ind) { mask ^= (static_cast<T>(1) << ind); }
template<typename T> void bset(T& mask, const usize ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T> constexpr T bcut(const T mask, const usize ind) { return ind == 0 ? static_cast<T>(0) : static_cast<T>((static_cast<u64>(mask) << (64 - ind)) >> (64 - ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
constexpr unsigned int mod                  = 1000000007;
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};
auto mfp = [](auto&& f) { return [=](auto&&... args) { return f(f, std::forward<decltype(args)>(args)...); }; };

template<typename T>
T in()
{
    T v;
    return std::cin >> v, v;
}
template<typename T, typename Uint, usize n, usize i>
T in_v(typename std::enable_if<(i == n), c_arr<Uint, n>>::type) { return in<T>(); }
template<typename T, typename Uint, usize n, usize i>
auto in_v(typename std::enable_if<(i < n), c_arr<Uint, n>>::type& szs)
{
    const usize s = (usize)szs[i];
    std::vector<decltype(in_v<T, Uint, n, i + 1>(szs))> ans(s);
    for (usize j = 0; j < s; j++) { ans[j] = in_v<T, Uint, n, i + 1>(szs); }
    return ans;
}
template<typename T, typename Uint, usize n>
auto in_v(c_arr<Uint, n> szs) { return in_v<T, Uint, n, 0>(szs); }
template<typename... Types>
auto in_t() { return std::tuple<std::decay_t<Types>...>{in<Types>()...}; }
struct io_init
{
    io_init()
    {
        std::cin.tie(nullptr), std::ios::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(20);
    }
    void clear()
    {
        std::cin.tie(), std::ios::sync_with_stdio(true);
    }
} io_setting;

int out() { return 0; }
template<typename T>
int out(const T& v) { return std::cout << v, 0; }
template<typename T>
int out(const std::vector<T>& v)
{
    for (usize i = 0; i < v.size(); i++) {
        if (i > 0) { std::cout << ' '; }
        out(v[i]);
    }
    return 0;
}
template<typename T1, typename T2>
int out(const std::pair<T1, T2>& v) { return out(v.first), std::cout << ' ', out(v.second), 0; }
template<typename T, typename... Args>
int out(const T& v, const Args... args) { return out(v), std::cout << ' ', out(args...), 0; }
template<typename... Args>
int outln(const Args... args) { return out(args...), std::cout << '\n', 0; }
template<typename... Args>
int outel(const Args... args) { return out(args...), std::cout << std::endl, 0; }

constexpr ull TEN(const usize n) { return n == 0 ? 1ULL : TEN(n - 1) * 10ULL; }

template<typename T, typename Uint, usize n, usize i>
auto make_v(typename std::enable_if<(i == n), c_arr<Uint, n>>::type, const T& v = T{}) { return v; }
template<typename T, typename Uint, usize n, usize i>
auto make_v(typename std::enable_if<(i < n), c_arr<Uint, n>>::type szs, const T& v = T{})
{
    const usize s = (usize)szs[i];
    return std::vector<decltype(make_v<T, Uint, n, i + 1>(szs, v))>(s, make_v<T, Uint, n, i + 1>(szs, v));
}
template<typename T, typename Uint, usize n>
auto make_v(c_arr<Uint, n> szs, const T& t = T{}) { return make_v<T, Uint, n, 0>(szs, t); }



template<typename T> T gcd(const T& a, const T& b) { return a < 0 ? gcd(-a, b) : b < 0 ? gcd(a, -b) : (a > b ? gcd(b, a) : a == 0 ? b : gcd(b % a, a)); }
template<typename T> T lcm(const T& a, const T& b) { return a / gcd(a, b) * b; }
template<typename T>
constexpr std::pair<T, T> id1(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto g = gcd(a, b), da = std::abs(b) / g;
    const auto p = id1(b, a % b);
    const auto x = (da + p.second % da) % da, y = (g - a * x) / b;
    return {x, y};
}
template<typename T>
constexpr T inverse(const T a, const T mod) { return id1(a, mod).first; }
template<uint mod_value, bool dynamic = false>
class id5
{
public:
    template<typename UInt = uint>
    static std::enable_if_t<dynamic, const UInt> mod() { return mod_ref(); }
    template<typename UInt = uint>
    static constexpr std::enable_if_t<not dynamic, const UInt> mod() { return mod_value; }
    template<typename UInt = uint>
    static void set_mod(const std::enable_if_t<dynamic, const UInt> mod) { mod_ref() = mod, inv_ref() = {1, 1}; }
    id5() : v{0} {}
    id5(const ll val) : v{norm(static_cast<uint>(val % static_cast<ll>(mod()) + static_cast<ll>(mod())))} {}
    id5(const id5& n) : v{n()} {}
    explicit operator bool() const { return v != 0; }
    bool operator!() const { return not static_cast<bool>(*this); }
    id5& operator=(const id5& m) { return v = m(), (*this); }
    id5& operator=(const ll val) { return v = norm(uint(val % static_cast<ll>(mod()) + static_cast<ll>(mod()))), (*this); }
    friend id5 operator+(const id5& m) { return m; }
    friend id5 operator-(const id5& m) { return make(norm(mod() - m.v)); }
    friend id5 operator+(const id5& m1, const id5& m2) { return make(norm(m1.v + m2.v)); }
    friend id5 operator-(const id5& m1, const id5& m2) { return make(norm(m1.v + mod() - m2.v)); }
    friend id5 operator*(const id5& m1, const id5& m2) { return make(static_cast<uint>(static_cast<ll>(m1.v) * static_cast<ll>(m2.v) % static_cast<ll>(mod()))); }
    friend id5 operator/(const id5& m1, const id5& m2) { return m1 * inv(m2.v); }
    friend id5 operator+(const id5& m, const ll val) { return id5{static_cast<ll>(m.v) + val}; }
    friend id5 operator-(const id5& m, const ll val) { return id5{static_cast<ll>(m.v) - val}; }
    friend id5 operator*(const id5& m, const ll val) { return id5{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend id5 operator/(const id5& m, const ll val) { return id5{static_cast<ll>(m.v) * inv(val)}; }
    friend id5 operator+(const ll val, const id5& m) { return id5{static_cast<ll>(m.v) + val}; }
    friend id5 operator-(const ll val, const id5& m) { return id5{-static_cast<ll>(m.v) + val}; }
    friend id5 operator*(const ll val, const id5& m) { return id5{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend id5 operator/(const ll val, const id5& m) { return id5{val * inv(static_cast<ll>(m.v))}; }
    friend id5& operator+=(id5& m1, const id5& m2) { return m1 = m1 + m2; }
    friend id5& operator-=(id5& m1, const id5& m2) { return m1 = m1 - m2; }
    friend id5& operator*=(id5& m1, const id5& m2) { return m1 = m1 * m2; }
    friend id5& operator/=(id5& m1, const id5& m2) { return m1 = m1 / m2; }
    friend id5& operator+=(id5& m, const ll val) { return m = m + val; }
    friend id5& operator-=(id5& m, const ll val) { return m = m - val; }
    friend id5& operator*=(id5& m, const ll val) { return m = m * val; }
    friend id5& operator/=(id5& m, const ll val) { return m = m / val; }
    friend id5 operator^(const id5& m, const ll n) { return power(m.v, n); }
    friend id5& operator^=(id5& m, const ll n) { return m = m ^ n; }
    friend bool operator==(const id5& m1, const id5& m2) { return m1.v == m2.v; }
    friend bool operator!=(const id5& m1, const id5& m2) { return not(m1 == m2); }
    friend bool operator==(const id5& m, const ll val) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const id5& m, const ll val) { return not(m == val); }
    friend bool operator==(const ll val, const id5& m) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const ll val, const id5& m) { return not(m == val); }
    friend std::istream& operator>>(std::istream& is, id5& m)
    {
        ll v;
        return is >> v, m = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, const id5& m) { return os << m(); }
    uint operator()() const { return v; }
    static id5 small_inv(const usize n)
    {
        auto& in = inv_ref();
        if (n < in.size()) { return in[n]; }
        for (usize i = in.size(); i <= n; i++) { in.push_back(-in[id5::mod() % i] * (id5::mod() / i)); }
        return in.back();
    }
    std::pair<ll, ll> quad() const
    {
        const auto ans = quad_r(v, mod());
        ll x = std::get<0>(ans), y = std::get<1>(ans);
        if (y < 0) { x = -x, y = -y; }
        return {x, y};
    }

private:
    static std::tuple<ll, ll, ll> quad_r(const ll r, const ll p)  

    {
        if (std::abs(r) <= 1000) { return {r, 1, 0}; }
        ll nr = p % r, q = p / r;
        if (nr * 2LL >= r) { nr -= r, q++; }
        if (nr * 2LL <= -r) { nr += r, q--; }
        const auto sub = quad_r(nr, r);
        const ll x = std::get<0>(sub), z = std::get<1>(sub), y = std::get<2>(sub);
        return {x, y - q * z, z};
    }

    template<typename UInt = uint>
    static std::enable_if_t<dynamic, UInt&> mod_ref()
    {
        static UInt mod = 0;
        return mod;
    }
    static uint norm(const uint x) { return x < mod() ? x : x - mod(); }
    static id5 make(const uint x)
    {
        id5 m;
        return m.v = x, m;
    }
    static id5 power(id5 x, ull n)
    {
        id5 ans = 1;
        for (; n; n >>= 1, x *= x) {
            if (n & 1) { ans *= x; }
        }
        return ans;
    }
    static id5 inv(const ll v) { return v <= 2000000 ? small_inv(static_cast<usize>(v)) : id5{inverse(v, static_cast<ll>(mod()))}; }
    static std::vector<id5>& inv_ref()
    {
        static std::vector<id5> in{1, 1};
        return in;
    }
    uint v;
};
template<uint mod>
using modint = id5<mod, false>;
template<uint id>
using dynamic_modint = id5<id, true>;
template<uint mod_value, bool dynamic = false>
class id4
{
public:
    using value_type = id5<mod_value, dynamic>;
    id4()   = delete;
    static void set_mod(const uint mod) { value_type::set_mod(mod), fact_ref() = {1, 1}, inv_fact_ref() = {1, 1}; }
    static value_type fact(const usize n)
    {
        auto& f = fact_ref();
        if (n < f.size()) { return f[n]; }
        for (usize i = f.size(); i <= n; i++) { f.push_back(f.back() * i); }
        return f.back();
    }
    static value_type inv_fact(const usize n)
    {
        auto& invf = inv_fact_ref();
        if (n < invf.size()) { return invf[n]; }
        for (usize i = invf.size(); i <= n; i++) { invf.push_back(invf.back() * value_type::small_inv(i)); }
        return invf.back();
    }
    static value_type perm(const usize n, const usize k) { return k > n ? value_type{0} : fact(n) * inv_fact(n - k); }
    static value_type comb(const usize n, const usize k) { return k > n ? value_type{0} : fact(n) * inv_fact(n - k) * inv_fact(k); }

private:
    static std::vector<value_type>& fact_ref()
    {
        static std::vector<value_type> f{1, 1};
        return f;
    }
    static std::vector<value_type>& inv_fact_ref()
    {
        static std::vector<value_type> invf{1, 1};
        return invf;
    }
};
template<uint mod>
using modcomb = id4<mod, false>;
template<uint id>
using dynamic_modcomb = id4<id, true>;
int main()
{
    using mint           = modint<mod>;
    using moc            = modcomb<mod>;
    const auto [H, W, N] = in_t<int, int, int>();
    std::vector<int> rs(N + 2, H - 1), cs(N + 2, W - 1);
    for (int i = 1; i <= N; i++) { rs[i] = in<int>() - 1, cs[i] = in<int>() - 1; }
    rs[0] = cs[0] = 0;
    std::vector<int> is(N + 2);
    std::iota(is.begin(), is.end(), 0);
    std::sort(is.begin(), is.end(), [&](int i, int j) { return rs[i] + cs[i] < rs[j] + cs[j]; });
    auto dp  = make_v<mint>({N + 2, 2}, 0);  

    dp[0][1] = 1;
    for (int ii = 1; ii < N + 2; ii++) {
        const int i = is[ii];
        for (int jj = 0; jj < ii; jj++) {
            const int j = is[jj];
            if (rs[j] > rs[i] and cs[j] > cs[i]) { continue; }
            for (int k = 0; k < 2; k++) { dp[ii][k] += dp[jj][1 - k] * moc::comb(rs[i] - rs[j] + cs[i] - cs[j], rs[i] - rs[j]); }
        }
    }
    outln(dp[N + 1][0] - dp[N + 1][1]);
    return 0;
}