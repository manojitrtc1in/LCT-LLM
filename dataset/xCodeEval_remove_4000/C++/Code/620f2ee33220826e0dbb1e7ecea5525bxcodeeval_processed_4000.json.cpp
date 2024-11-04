

using ll                            = long long;
using uint                          = unsigned int;
using ull                           = unsigned long long;
using ld                            = long double;
template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
constexpr int popcount(const ull v) { return v ? __builtin_popcountll(v) : 0; }
constexpr int id1(const ull v) { return v ? 64 - __builtin_clzll(v) : 0; }
constexpr int id4(const ull v) { return __builtin_ffsll(v); }
constexpr int clog(const ull v) { return v ? id1(v - 1) : 0; }
constexpr ull ceil2(const ull v) { return 1ULL << clog(v); }
constexpr ull floor2(const ull v) { return v ? (1ULL << (id1(v) - 1)) : 0ULL; }
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
template<typename T, int n, int i = 0>
auto nd_array(int const (&szs)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(szs[i], nd_array<T, n, i + 1>(szs, x));
    }
}
class printer
{
public:
    printer(std::ostream& os_ = std::cout) : os{os_} { os << std::fixed << std::setprecision(15); }
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
        std::vector<T> vs(n);
        for (auto& v : vs) { v = val<T>(); }
        return vs;
    }
    template<typename T> std::vector<T> vec(const int n, const T offset)
    {
        std::vector<T> vs(n);
        for (auto& v : vs) { v = val<T>(offset); }
        return vs;
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1)
    {
        std::vector<std::vector<T>> vss(n0);
        for (auto& vs : vss) { vs = vec<T>(n1); }
        return vss;
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1, const T offset)
    {
        std::vector<std::vector<T>> vss(n0);
        for (auto& vs : vss) { vs = vec<T>(n1, offset); }
        return vss;
    }
    template<typename... Args> auto tup() { return std::tuple<std::decay_t<Args>...>{val<Args>()...}; }
    template<typename... Args> auto tup(const Args&... offsets) { return std::tuple<std::decay_t<Args>...>{val<Args>(offsets)...}; }

private:
    std::istream& is;
};
scanner in;



template<typename T>
constexpr std::pair<T, T> id2(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto g = std::gcd(a, b), da = std::abs(b) / g;
    const auto p = id2(b, a % b);
    const auto x = (da + p.second % da) % da, y = (g - a * x) / b;
    return {x, y};
}
template<typename T> constexpr T inverse(const T a, const T mod) { return id2(a, mod).first; }
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
    explicit operator int() const { return v; }
    explicit operator uint() const { return v; }
    explicit operator ll() const { return v; }
    explicit operator ull() const { return v; }
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
    static id5 fact(const int n)
    {
        auto& fact_ = fact_ref();
        if (n < (int)fact_.size()) { return fact_[n]; }
        for (int i = (int)fact_.size(); i <= n; i++) { fact_.push_back(fact_.back() * i); }
        return fact_.back();
    }
    static id5 inv_fact(const int n)
    {
        auto& id3 = inv_fact_ref();
        if (n < (int)id3.size()) { return id3[n]; }
        for (int i = id3.size(); i <= n; i++) { id3.push_back(id3.back() * id5::small_inv(i)); }
        return id3.back();
    }
    static id5 perm(const int n, const int k) { return k > n ? id5{0} : fact(n) * inv_fact(n - k); }
    static id5 comb(const int n, const int k) { return k > n ? id5{0} : fact(n) * inv_fact(n - k) * inv_fact(k); }
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
    static id5 small_inv(const int n)
    {
        auto& inv_ = inv_ref();
        if (n < (int)inv_.size()) { return inv_[n]; }
        for (int i = inv_.size(); i <= n; i++) { inv_.push_back(-inv_[id5::mod() % i] * (id5::mod() / i)); }
        return inv_.back();
    }
    static id5 inv(const ll v) { return v <= 2000000 ? small_inv(static_cast<int>(v)) : id5{inverse(v, static_cast<ll>(mod()))}; }
    static std::vector<id5>& inv_ref()
    {
        static std::vector<id5> inv_{1, 1};
        return inv_;
    }
    static std::vector<id5>& fact_ref()
    {
        static std::vector<id5> fact_{1, 1};
        return fact_;
    }
    static std::vector<id5>& inv_fact_ref()
    {
        static std::vector<id5> id3{1, 1};
        return id3;
    }

    uint v;
};
template<uint mod>
using modint = id5<mod, false>;
template<uint id>
using dynamic_modint = id5<id, true>;
int main()
{
    const auto K = in.val<int>();
    auto as      = in.vec<ll>(K);
    std::sort(as.begin(), as.end());
    if (as.back() == 1) { return out.ln("0/1"); }
    constexpr uint MOD = 1000000007;
    using mint         = modint<MOD>;
    ll A               = 1;
    ll A2              = 1;
    for (const ll a : as) {
        A  = (id0)A * (id0)a % (id0)(MOD - 1);
        A2 = (id0)A2 * (id0)a % (id0)(2);
    }
    SHOW(A, A2);
    const mint q = (mint(2) ^ A);
    const mint p = (q + mint(A2 % 2 == 0 ? 2 : -2)) / 3 / 2;
    SHOW(p, q / 2);
    std::cout << p << "/" << (q / 2) << std::endl;
    return 0;
}
