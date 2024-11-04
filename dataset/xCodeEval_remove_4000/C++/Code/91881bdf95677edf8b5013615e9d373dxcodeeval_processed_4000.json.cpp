

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
constexpr int id0(const ull v) { return v ? 64 - __builtin_clzll(v) : 0; }
constexpr int id4(const ull v) { return __builtin_ffsll(v); }
constexpr int clog(const ull v) { return v ? id0(v - 1) : 0; }
constexpr ull ceil2(const ull v) { return 1ULL << clog(v); }
constexpr ull floor2(const ull v) { return v ? (1ULL << (id0(v) - 1)) : 0ULL; }
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
template<typename F> std::vector<int> id1(const int n, F comp = F{}, const int offset = 0) { return sorted(ioted(n, offset), comp); }
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


template<typename T, typename Int, int n, int i> auto make_v(typename std::enable_if<(i == n), c_arr<Int, n>>::type, const T& v = T{}) { return v; }
template<typename T, typename Int, int n, int i> auto make_v(typename std::enable_if<(i < n), c_arr<Int, n>>::type szs, const T& v = T{}) { return std::vector<decltype(make_v<T, Int, n, i + 1>(szs, v))>(szs[i], make_v<T, Int, n, i + 1>(szs, v)); }
template<typename T, typename Int, int n> auto make_v(c_arr<Int, n> szs, const T& t = T{}) { return make_v<T, Int, n, 0>(szs, t); }


template<typename T, typename F>
class ds_table
{
public:
    ds_table(const std::vector<T>& vs, F merge_) : sz{(int)vs.size()}, lg{(int)id0(sz)}, vss(lg, vs), merge{merge_}
    {
        for (int d = 0; d < lg; d++) {
            const int width = 1 << (lg - d - 1);
            for (int i = 1; i * width < sz; i += 2) {
                int l = i * width - 1, r = i * width;
                for (int j = 1; j < width; j++) {
                    vss[d][l - j] = merge(vs[l - j], vss[d][l - j + 1]);
                    if (r + j < sz) { vss[d][r + j] = merge(vs[r + j], vss[d][r + j - 1]); }
                }
            }
        }
    }
    T fold(const int l, int r) const
    {
        assert(0 <= l and l < r and r <= sz);
        if (r - l == 1) { return vss.back()[l]; }
        r--;
        const int d = lg - id0(l ^ r);
        return merge(vss[d][l], vss[d][r]);
    }

private:
    const int sz, lg;
    std::vector<std::vector<T>> vss;
    F merge;
};
template<typename T, typename F = std::less<T>, typename B = ull>
class id6
{
    static inline auto min_f = [](const auto& c) { return [c](const auto& x1, const auto& x2) { return std::min(x1, x2, c); }; };

public:
    id6(const std::vector<T>& vs, F comp_ = F{})
        : sz{(int)vs.size()}, bn{wind(sz + bs - 1)}, vals{vs}, bucket_vals([&]() {
              std::vector<T> ans(bn);
              for (int i = 0; i < sz; i++) { ans[wind(i)] = i % bs == 0 ? vals[i] : std::min(ans[wind(i)], vals[i], comp_); }
              return ans;
          }()),
          masks(sz, 0),
          st(bucket_vals, min_f(comp_)),
          comp{comp_}
    {
        for (int i = 0; i < bn; i++) {
            std::vector<int> g(bs, sz);
            std::stack<int> stack;
            for (int j = 0; j < bs and ind(i, j) < sz; j++) {
                for (; not stack.empty() and not comp(vals[stack.top()], vals[ind(i, j)]); stack.pop()) {}
                g[j] = stack.empty() ? sz : stack.top(), stack.push(ind(i, j));
            }
            for (int j = 0; j < bs and ind(i, j) < sz; j++) { masks[ind(i, j)] = g[j] == sz ? static_cast<B>(0) : (masks[g[j]] | static_cast<B>(1) << (g[j] - i * bs)); }
        }
    }
    T fold(const int l, const int r) const
    {
        assert(0 <= l and l < r and r <= sz);
        const int lb = (l + bs - 1) / bs, rb = r / bs;
        if (lb > rb) {
            return brmq(l, r);
        } else {
            return lb < rb
                       ? (l < bs * lb
                              ? (bs * rb < r
                                     ? std::min({st.fold(lb, rb), brmq(l, bs * lb), brmq(bs * rb, r)}, comp)
                                     : std::min(st.fold(lb, rb), brmq(l, bs * lb), comp))
                              : (bs * rb < r
                                     ? std::min(st.fold(lb, rb), brmq(bs * rb, r), comp)
                                     : st.fold(lb, rb)))
                       : (l < bs * lb
                              ? (bs * rb < r
                                     ? std::min(brmq(l, bs * lb), brmq(bs * rb, r), comp)
                                     : brmq(l, bs * lb))
                              : (bs * rb < r
                                     ? brmq(bs * rb, r)
                                     : T{}));
        }
    }

private:
    static constexpr int bs    = sizeof(B) * 8;
    static constexpr int bslog = id0(bs) - 1;
    static constexpr uint wind(const uint n) { return n >> (bslog); }
    static constexpr uint bind(const uint n) { return n ^ (wind(n) << bslog); }
    static constexpr uint ind(const uint w, const uint b) { return (w << bslog) | b; }
    T brmq(const int l, int r) const
    {
        r--;
        const B w = masks[r] >> (l % bs);
        return w == 0 ? vals[r] : vals[l + id4(w) - 1];
    }

    const int sz, bn;
    std::vector<T> vals, bucket_vals;
    std::vector<B> masks;
    ds_table<T, decltype(min_f(F{}))> st;
    F comp;
};


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
        if (n < fact_.size()) { return fact_[n]; }
        for (int i = fact_.size(); i <= n; i++) { fact_.push_back(fact_.back() * i); }
        return fact_.back();
    }
    static id5 inv_fact(const int n)
    {
        auto& id3 = inv_fact_ref();
        if (n < id3.size()) { return id3[n]; }
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
    const auto [N, M] = in.tup<int, int>();
    const auto as     = in.vec<ll>(N);
    const auto bs     = in.vec<ll>(M);
    if (N < M) { return out.ln(0); }
    const auto rmq = id6(as);
    using mint     = modint<998244353>;
    mint ans       = 1;
    int R          = N;
    for (int i = M - 1; i >= 0; i--) {
        int Rmin;
        {
            int inf = -1, sup = R;
            while (sup - inf > 1) {
                const int mid              = (inf + sup) / 2;
                const ll min               = rmq.fold(mid, R);
                (min >= bs[i] ? sup : inf) = mid;
            }
            Rmin = sup;
            if (sup >= R or rmq.fold(sup, R) != bs[i]) { return out.ln(0); }
        }
        int Rmax;
        {
            int inf = Rmin - 1, sup = R;
            while (sup - inf > 1) {
                const int mid             = (inf + sup) / 2;
                const ll min              = rmq.fold(mid, R);
                (min > bs[i] ? sup : inf) = mid;
            }
            Rmax = inf;
            if (inf <= -1 or rmq.fold(inf, R) != bs[i]) { return out.ln(0); }
        }
        if (i == 0 and Rmin > 0) { return out.ln(0); }
        SHOW(i, R, Rmin, Rmax);
        ans *= (i == 0 ? 1 : (Rmax - Rmin + 1));
        R = Rmax;
    }
    out.ln(ans);
    return 0;
}
