#include <bits/stdc++.h>



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

template<typename T> T gcd(const T& a, const T& b) { return a < 0 ? gcd(-a, b) : b < 0 ? gcd(a, -b) : (a > b ? gcd(b, a) : a == 0 ? b : gcd(b % a, a)); }
template<typename T> T lcm(const T& a, const T& b) { return a / gcd(a, b) * b; }
template<typename T>
constexpr std::pair<T, T> extgcd(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto g = gcd(a, b), da = std::abs(b) / g;
    const auto p = extgcd(b, a % b);
    const auto x = (da + p.second % da) % da, y = (g - a * x) / b;
    return {x, y};
}
template<typename T>
constexpr T inverse(const T a, const T mod) { return extgcd(a, mod).first; }
template<uint mod_value, bool dynamic = false>
class modint_base
{
public:
    template<typename UInt = uint>
    static std::enable_if_t<dynamic, const UInt> mod() { return mod_ref(); }
    template<typename UInt = uint>
    static constexpr std::enable_if_t<not dynamic, const UInt> mod() { return mod_value; }
    template<typename UInt = uint>
    static void set_mod(const std::enable_if_t<dynamic, const UInt> mod) { mod_ref() = mod, inv_ref() = {1, 1}; }
    modint_base() : v{0} {}
    modint_base(const ll val) : v{norm(static_cast<uint>(val % static_cast<ll>(mod()) + static_cast<ll>(mod())))} {}
    modint_base(const modint_base& n) : v{n()} {}
    explicit operator bool() const { return v != 0; }
    bool operator!() const { return not static_cast<bool>(*this); }
    modint_base& operator=(const modint_base& m) { return v = m(), (*this); }
    modint_base& operator=(const ll val) { return v = norm(uint(val % static_cast<ll>(mod()) + static_cast<ll>(mod()))), (*this); }
    friend modint_base operator+(const modint_base& m) { return m; }
    friend modint_base operator-(const modint_base& m) { return make(norm(mod() - m.v)); }
    friend modint_base operator+(const modint_base& m1, const modint_base& m2) { return make(norm(m1.v + m2.v)); }
    friend modint_base operator-(const modint_base& m1, const modint_base& m2) { return make(norm(m1.v + mod() - m2.v)); }
    friend modint_base operator*(const modint_base& m1, const modint_base& m2) { return make(static_cast<uint>(static_cast<ll>(m1.v) * static_cast<ll>(m2.v) % static_cast<ll>(mod()))); }
    friend modint_base operator/(const modint_base& m1, const modint_base& m2) { return m1 * inv(m2.v); }
    friend modint_base operator+(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) + val}; }
    friend modint_base operator-(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) - val}; }
    friend modint_base operator*(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend modint_base operator/(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) * inv(val)}; }
    friend modint_base operator+(const ll val, const modint_base& m) { return modint_base{static_cast<ll>(m.v) + val}; }
    friend modint_base operator-(const ll val, const modint_base& m) { return modint_base{-static_cast<ll>(m.v) + val}; }
    friend modint_base operator*(const ll val, const modint_base& m) { return modint_base{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend modint_base operator/(const ll val, const modint_base& m) { return modint_base{val * inv(static_cast<ll>(m.v))}; }
    friend modint_base& operator+=(modint_base& m1, const modint_base& m2) { return m1 = m1 + m2; }
    friend modint_base& operator-=(modint_base& m1, const modint_base& m2) { return m1 = m1 - m2; }
    friend modint_base& operator*=(modint_base& m1, const modint_base& m2) { return m1 = m1 * m2; }
    friend modint_base& operator/=(modint_base& m1, const modint_base& m2) { return m1 = m1 / m2; }
    friend modint_base& operator+=(modint_base& m, const ll val) { return m = m + val; }
    friend modint_base& operator-=(modint_base& m, const ll val) { return m = m - val; }
    friend modint_base& operator*=(modint_base& m, const ll val) { return m = m * val; }
    friend modint_base& operator/=(modint_base& m, const ll val) { return m = m / val; }
    friend modint_base operator^(const modint_base& m, const ll n) { return power(m.v, n); }
    friend modint_base& operator^=(modint_base& m, const ll n) { return m = m ^ n; }
    friend bool operator==(const modint_base& m1, const modint_base& m2) { return m1.v == m2.v; }
    friend bool operator!=(const modint_base& m1, const modint_base& m2) { return not(m1 == m2); }
    friend bool operator==(const modint_base& m, const ll val) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const modint_base& m, const ll val) { return not(m == val); }
    friend bool operator==(const ll val, const modint_base& m) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const ll val, const modint_base& m) { return not(m == val); }
    friend std::istream& operator>>(std::istream& is, modint_base& m)
    {
        ll v;
        return is >> v, m = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modint_base& m) { return os << m(); }
    uint operator()() const { return v; }
    static modint_base small_inv(const usize n)
    {
        auto& in = inv_ref();
        if (n < in.size()) { return in[n]; }
        for (usize i = in.size(); i <= n; i++) { in.push_back(-in[modint_base::mod() % i] * (modint_base::mod() / i)); }
        return in.back();
    }

private:
    template<typename UInt = uint>
    static std::enable_if_t<dynamic, UInt&> mod_ref()
    {
        static UInt mod = 0;
        return mod;
    }
    static uint norm(const uint x) { return x < mod() ? x : x - mod(); }
    static modint_base make(const uint x)
    {
        modint_base m;
        return m.v = x, m;
    }
    static modint_base power(modint_base x, ull n)
    {
        modint_base ans = 1;
        for (; n; n >>= 1, x *= x) {
            if (n & 1) { ans *= x; }
        }
        return ans;
    }
    static modint_base inv(const ll v) { return v < 1000000 ? small_inv(static_cast<usize>(v)) : modint_base{inverse(v, static_cast<ll>(mod()))}; }
    static std::vector<modint_base>& inv_ref()
    {
        static std::vector<modint_base> in{1, 1};
        return in;
    }
    uint v;
};
template<uint mod>
using modint = modint_base<mod, false>;
template<uint id>
using dynamic_modint = modint_base<id, true>;
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"

template<typename T> constexpr T popcount(const T u) { return u ? static_cast<T>(__builtin_popcountll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T log2p1(const T u) { return u ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T msbp1(const T u) { return log2p1(u); }
template<typename T> constexpr T lsbp1(const T u) { return __builtin_ffsll(u); }
template<typename T> constexpr T clog(const T u) { return u ? log2p1(u - 1) : static_cast<T>(u); }
template<typename T> constexpr bool ispow2(const T u) { return u and (static_cast<u64>(u) & static_cast<u64>(u - 1)) == 0; }
template<typename T> constexpr T ceil2(const T u) { return static_cast<T>(1) << clog(u); }
template<typename T> constexpr T floor2(const T u) { return u == 0 ? static_cast<T>(0) : static_cast<T>(1) << (log2p1(u) - 1); }
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
        

    }
} hogechan;

template<typename T>
int out(const T& v) { return std::cout << v, 0; }
template<typename T>
int out(const std::vector<T>& v)
{
    for (usize i = 0; i < v.size(); i++) {
        if (i > 0) { std::cout << ' '; }
        out(v[i]);
    }
    return std::cout << "\n", 0;
}
template<typename T1, typename T2>
int out(const std::pair<T1, T2>& v) { return out(v.first), std::cout << ' ', out(v.second), 0; }
template<typename T, typename... Args>
int out(const T& v, const Args... args) { return out(v), std::cout << ' ', out(args...), 0; }
template<typename... Args>
int outln(const Args... args) { return out(args...), std::cout << '\n', 0; }
template<typename... Args>
void outel(const Args... args) { return out(args...), std::cout << std::endl, 0; }
#    define SHOW(...) static_cast<void>(0)
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
int main()
{
    constexpr uint mod = 998244353;
    using mint         = modint<mod>;
    const auto [n, m]  = in_t<int, int>();
    const auto a       = in_v<bool>({n});
    const auto w       = in_v<int>({n});
    int zw = 0, ow = 0;
    for (int i = 0; i < n; i++) { (a[i] ? ow : zw) += w[i]; }
    const int s = zw + ow;
    std::vector<mint> inv(2 * m + 1);
    for (int d = -m; d <= m; d++) {
        if (s + d > 0) { inv[d + m] = mint(1) / (s + d); }
    }
    auto dp = make_v({m + 1, 2}, mint(0));
    dp[0]   = {1, 1};
    for (int i = 0; i < m; i++) {
        auto ndp = make_v({m + 1, 2}, mint(0));
        for (int z = 0; z <= i; z++) {
            const int o  = i - z;
            const int wz = zw - z;
            const int wo = ow + o;
            if (wz < 0) { continue; }
            for (int dz = -1; dz <= 0; dz++) {
                const int nwz = wz + dz;
                const int nz  = z + (-dz);
                if (nwz < 0) { continue; }
                const mint eps = inv[wz + wo - s + m];
                const mint p   = mint(dz == -1 ? wz : wo) * eps;
                ndp[nz][-dz] += dp[z][-dz] * p;
                ndp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * dp[z][1 + dz];
            }
        }
        dp = ndp;
    }
    mint cz = 0, co = 0;
    for (int i = 0; i <= m; i++) { cz += dp[i][0], co += dp[i][1]; }
    for (int i = 0; i < n; i++) { outln(w[i] * (a[i] == 0 ? cz : co)); }
    return 0;
}
