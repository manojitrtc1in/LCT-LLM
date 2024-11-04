#include <bits/stdc++.h>

using ll   = long long;
using uint = unsigned int;
using ull  = unsigned long long;
using ld   = long double;
template<typename T, int n>
using arr = T (&)[n];
template<typename T, int n>
using c_arr = const T (&)[n];
template<typename T>
using max_heap = std::priority_queue<T>;
template<typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
constexpr int popcount(const ull v) { return v ? __builtin_popcountll(v) : 0; }
constexpr int log2p1(const ull v) { return v ? 64 - __builtin_clzll(v) : 0; }
constexpr int lsbp1(const ull v) { return __builtin_ffsll(v); }
constexpr int clog(const ull v) { return v ? log2p1(v - 1) : 0; }
constexpr ull ceil2(const ull v) { return 1ULL << clog(v); }
constexpr ull floor2(const ull v) { return v ? (1ULL << (log2p1(v) - 1)) : 0ULL; }
constexpr bool btest(const ull mask, const int ind) { return (mask >> ind) & 1ULL; }
template<typename T> void bset(T& mask, const int ind) { mask |= ((T)1 << ind); }
template<typename T> void breset(T& mask, const int ind) { mask &= ~((T)1 << ind); }
template<typename T> void bflip(T& mask, const int ind) { mask ^= ((T)1 << ind); }
template<typename T> void bset(T& mask, const int ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }

template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};
constexpr ull TEN(const int n) { return n == 0 ? 1ULL : TEN(n - 1) * 10ULL; }
template<typename F> struct fix : F
{
    fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args> auto operator()(Args&&... args) const { return F::operator()(*this, std::forward<Args>(args)...); }
};
class printer
{
public:
    printer(std::ostream& os_ = std::cout) : os{os_} {}
    template<typename T> int operator()(const T& v) { return os << v, 0; }
    template<typename T> int operator()(const std::vector<T>& vs)
    {
        for (int i = 0; i < (int)vs.size(); i++) { os << (i ? " " : ""), this->operator()(vs[i]); }
        return 0;
    }
    template<typename T> int operator()(const std::vector<std::vector<T>>& vss)
    {
        for (int i = 0; i < (int)vss.size(); i++) { os << (0 <= i or i + 1 < (int)vss.size() ? "\n" : ""), this->operator()(vss[i]); }
        return 0;
    }
    template<typename T, typename... Args> int operator()(const T& v, const Args&... args) { return this->operator()(v), os << ' ', this->operator()(args...), 0; }
    template<typename... Args> int ln(const Args&... args) { return this->operator()(args...), os << '\n', 0; }
    template<typename... Args> int el(const Args&... args) { return this->operator()(args...), os << std::endl, 0; }
    template<typename... Args> int fmt(const std::string& s, const Args&... args) { return rec(s, 0, args...); }

private:
    int rec(const std::string& s, int index) { return os << s.substr(index, s.size()), 0; }
    template<typename T, typename... Args> int rec(const std::string& s, int index, const T& v, const Args&... args) { return index == s.size() ? 0 : s[index] == '%' ? (this->operator()(v), rec(s, index + 1, args...)) : (os << s[index], rec(s, index + 1, v, args...)); }
    std::ostream& os;
};
printer out;

template<typename T, typename F> std::vector<T> generated(const int n, F f)
{
    std::vector<T> ans(n);
    return std::generate(ans.begin(), ans.end(), f), ans;
}
std::vector<int> ioted(const int n, const int offset = 0)
{
    std::vector<int> ans(n);
    return std::iota(ans.begin(), ans.end(), offset), ans;
}
template<typename Vs> Vs reversed(const Vs& vs)
{
    auto ans = vs;
    return std::reverse(ans.begin(), ans.end()), ans;
}
template<typename T, typename F = std::less<T>> std::vector<T> sorted(const std::vector<T>& vs, F comp = F{})
{
    auto ans = vs;
    return std::sort(ans.begin(), ans.end(), comp), ans;
}
template<typename F> std::vector<int> sorted_iota(const int n, F comp = F{}, const int offset = 0) { return sorted(ioted(n, offset), comp); }
class scanner
{
public:
    scanner(std::istream& is_ = std::cin) : is{is_} { is.tie(nullptr), std::ios::sync_with_stdio(false); }
    template<typename T> T val()
    {
        static T v;
        return is >> v, v;
    }
    template<typename T> T val(const T offset) { return val<T>() - offset; }
    template<typename T> std::vector<T> vec(const int n)
    {
        return generated<T>(n, [&] { return val<T>(); });
    }
    template<typename T> std::vector<T> vec(const int n, const T offset)
    {
        return generated<T>(n, [&] { return val<T>(offset); });
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1)
    {
        return generated<std::vector<T>>(n0, [&] { return vec<T>(n1); });
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1, const T offset)
    {
        return generated<std::vector<T>>(n0, [&] { return vec<T>(n1, offset); });
    }
    template<typename... Args> auto tup() { return std::tuple<std::decay_t<Args>...>{val<Args>()...}; }
    template<typename... Args> auto tup(const Args&... offsets) { return std::tuple<std::decay_t<Args>...>{val<Args>(offsets)...}; }

private:
    std::istream& is;
};
scanner in;
#    define SHOW(...) static_cast<void>(0)

template<typename T, typename Int, int n, int i> auto make_v(typename std::enable_if<(i == n), c_arr<Int, n>>::type, const T& v = T{}) { return v; }
template<typename T, typename Int, int n, int i> auto make_v(typename std::enable_if<(i < n), c_arr<Int, n>>::type szs, const T& v = T{}) { return std::vector<decltype(make_v<T, Int, n, i + 1>(szs, v))>(szs[i], make_v<T, Int, n, i + 1>(szs, v)); }
template<typename T, typename Int, int n> auto make_v(c_arr<Int, n> szs, const T& t = T{}) { return make_v<T, Int, n, 0>(szs, t); }


template<typename T>
constexpr std::pair<T, T> extgcd(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto g = std::gcd(a, b), da = std::abs(b) / g;
    const auto p = extgcd(b, a % b);
    const auto x = (da + p.second % da) % da, y = (g - a * x) / b;
    return {x, y};
}
template<typename T> constexpr T inverse(const T a, const T mod) { return extgcd(a, mod).first; }
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
    explicit operator int() const { return v; }
    explicit operator uint() const { return v; }
    explicit operator ll() const { return v; }
    explicit operator ull() const { return v; }
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
    static modint_base fact(const int n)
    {
        auto& fact_ = fact_ref();
        if (n < fact_.size()) { return fact_[n]; }
        for (int i = fact_.size(); i <= n; i++) { fact_.push_back(fact_.back() * i); }
        return fact_.back();
    }
    static modint_base inv_fact(const int n)
    {
        auto& inv_fact_ = inv_fact_ref();
        if (n < inv_fact_.size()) { return inv_fact_[n]; }
        for (int i = inv_fact_.size(); i <= n; i++) { inv_fact_.push_back(inv_fact_.back() * modint_base::small_inv(i)); }
        return inv_fact_.back();
    }
    static modint_base perm(const int n, const int k) { return k > n ? modint_base{0} : fact(n) * inv_fact(n - k); }
    static modint_base comb(const int n, const int k) { return k > n ? modint_base{0} : fact(n) * inv_fact(n - k) * inv_fact(k); }
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
    static modint_base small_inv(const int n)
    {
        auto& inv_ = inv_ref();
        if (n < (int)inv_.size()) { return inv_[n]; }
        for (int i = inv_.size(); i <= n; i++) { inv_.push_back(-inv_[modint_base::mod() % i] * (modint_base::mod() / i)); }
        return inv_.back();
    }
    static modint_base inv(const ll v) { return v <= 2000000 ? small_inv(static_cast<int>(v)) : modint_base{inverse(v, static_cast<ll>(mod()))}; }
    static std::vector<modint_base>& inv_ref()
    {
        static std::vector<modint_base> inv_{1, 1};
        return inv_;
    }
    static std::vector<modint_base>& fact_ref()
    {
        static std::vector<modint_base> fact_{1, 1};
        return fact_;
    }
    static std::vector<modint_base>& inv_fact_ref()
    {
        static std::vector<modint_base> inv_fact_{1, 1};
        return inv_fact_;
    }

    uint v;
};
template<uint mod>
using modint = modint_base<mod, false>;
template<uint id>
using dynamic_modint = modint_base<id, true>;
int main()
{
    using mint        = modint<1000000007>;
    const auto [N, K] = in.tup<ll, int>();
    auto coeffs       = make_v<mint>({K + 1, K + 1}, 0);
    coeffs[0][0]      = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= K; j++) {
            if (j > 0) { coeffs[i + 1][j] += coeffs[i][j - 1]; }
            coeffs[i + 1][j] -= coeffs[i][j] * i;
        }
    }
    SHOW(coeffs);
    std::vector<mint> as(K + 1);
    std::vector<mint> res(K + 1, 0);
    res[K] = 1;
    for (int i = K; i >= 0; i--) {
        as[i] = res[i];
        for (int j = 0; j <= K; j++) { res[j] -= coeffs[i][j] * as[i]; }
    }
    SHOW(as);
    mint ans = 0;
    mint c   = 1;
    for (int i = 0; i <= K; i++) {
        if (c == 0) { continue; }
        ans += as[i] * c * (mint(2) ^ (N - i));
        c *= (N - i);
    }
    out.ln(ans);
    return 0;
}
