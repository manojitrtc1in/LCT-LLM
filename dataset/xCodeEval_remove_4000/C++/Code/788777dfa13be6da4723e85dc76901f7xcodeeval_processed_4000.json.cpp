




using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using uint = unsigned int;
using usize = std::size_t;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename T> constexpr T popcount(const T u) { return u ? static_cast<T>(__builtin_popcountll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T id0(const T u) { return u ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T id5(const T u) { return id0(u); }
template<typename T> constexpr T id3(const T u) { return __builtin_ffsll(u); }
template<typename T> constexpr T clog(const T u) { return u ? id0(u - 1) : static_cast<T>(u); }
template<typename T> constexpr bool id2(const T u) { return u and (static_cast<u64>(u) & static_cast<u64>(u - 1)) == 0; }
template<typename T> constexpr T ceil2(const T u) { return static_cast<T>(1) << clog(u); }
template<typename T> constexpr T floor2(const T u) { return u == 0 ? static_cast<T>(0) : static_cast<T>(1) << (id0(u) - 1); }
template<typename T> constexpr bool btest(const T mask, const usize ind) { return ((static_cast<u64>(mask) >> ind) & static_cast<u64>(1)); }
template<typename T> constexpr T bcut(const T mask, const usize ind) { return ind == 0 ? static_cast<T>(0) : static_cast<T>((static_cast<u64>(mask) << (64 - ind)) >> (64 - ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
constexpr unsigned int mod                  = 1000000007;
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};
template<typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template<typename T>
std::vector<T> read_vec(const std::size_t size)
{
    std::vector<T> v(size);
    for (auto& e : v) { std::cin >> e; }
    return v;
}

template<typename T>
std::vector<T> make_v(const std::size_t size, T v) { return std::vector<T>(size, v); }
template<class... Args>
auto make_v(const std::size_t size, Args... args) { return std::vector<decltype(make_v(args...))>(size, make_v(args...)); }


template<typename Cost>
class base_graph
{
public:
    using cost_type = Cost;
    base_graph(const usize sz) : sz{sz}, edges(sz), rev_edges(sz) {}
    void add_edge(const usize from, const usize to, const Cost cost, const bool bi = false)
    {
        assert(from < sz), assert(to < sz);
        edges[from].push_back(edge{from, to, cost}), rev_edges[to].push_back(edge(to, from, cost));
        if (bi) { add_edge(to, from, cost, false); }
    }
    struct edge
    {
        edge(const usize from, const usize to, const Cost cost) : from{from}, to{to}, cost{cost} {}
        const usize from, to;
        const Cost cost;
        bool operator<(const edge& e) const { return cost != e.cost ? cost < e.cost : to < e.to; }
    };
    const std::vector<edge>& operator[](const usize i) const { return assert(i < sz), edges[i]; }
    std::vector<edge>& operator[](const usize i) { return assert(i < sz), edges[i]; }
    const std::vector<std::vector<edge>>& rev_edge() const { return rev_edges; }
    std::vector<std::vector<edge>>& rev_edge() { return rev_edges; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        os << "[\n";
        for (usize i = 0; i < g.V; i++) {
            for (const auto& e : g.edges[i]) { os << i << "->" << e.to << ":" << e.cost << "\n"; }
        }
        return (os << "]\n");
    }
    static usize to(const edge& e) { return e.to; }
    usize size() const { return sz; }

private:
    const usize sz;
    std::vector<std::vector<edge>> edges, rev_edges;
};
template<>
class base_graph<void>
{
public:
    base_graph(const usize sz) : sz{sz}, edges(sz), rev_edges(sz) {}
    void add_edge(const usize from, const usize to, const bool bi = false)
    {
        assert(from < sz), assert(to < sz);
        edges[from].push_back(to), rev_edges[to].push_back(from);
        if (bi) { add_edge(to, from, false); }
    }
    const std::vector<usize>& operator[](const usize i) const { return assert(i < sz), edges[i]; }
    std::vector<usize>& operator[](const usize i) { return assert(i < sz), edges[i]; }
    const std::vector<std::vector<usize>>& rev_edge() const { return rev_edges; }
    std::vector<std::vector<usize>>& rev_edge() { return rev_edges; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        os << "[\n";
        for (usize i = 0; i < g.sz; i++) {
            for (const usize to : g.edges[i]) { os << i << "->" << to << "\n"; }
        }
        return (os << "]\n");
    }
    static usize to(const usize e) { return e; }
    usize size() const { return sz; }

private:
    const usize sz;
    std::vector<std::vector<usize>> edges, rev_edges;
};
using graph = base_graph<void>;
using tree  = graph;
template<typename Cost>
using cost_graph = base_graph<Cost>;
template<typename Cost>
using cost_tree = cost_graph<Cost>;
template<typename Cost>
class lowlink
{
private:
    using P = std::pair<usize, usize>;
    const usize sz;
    std::vector<P> bs;
    std::vector<usize> ord, low, as;
    std::vector<bool> is_a;
    std::vector<std::vector<usize>> dfs_tree;

public:
    lowlink(const base_graph<Cost>& g) : sz(g.size()), ord(sz, sz), low(sz, sz), is_a(sz, false), dfs_tree(sz)
    {
        usize num = 0;
        auto dfs  = [&](auto&& self, const usize s, const usize p) -> void {
            ord[s] = low[s] = num++;
            usize back      = 0;
            for (const auto& e : g[s]) {
                const usize to = base_graph<Cost>::to(e);
                if (ord[to] == sz) {
                    dfs_tree[s].push_back(to), self(self, to, s), low[s] = std::min(low[s], low[to]);
                } else {
                    if (p == to) { back++; }
                    if (p != to or back > 1) { low[s] = std::min(low[s], ord[to]); }
                }
            }
        };
        auto dfs2 = [&](auto&& self, const usize s) -> void {
            usize max = 0;
            for (const usize to : dfs_tree[s]) {
                max = std::max(max, low[to]);
                if (is_bridge(s, to)) { bs.push_back({s, to}); }
                self(self, to);
            }
            is_a[s] = ord[s] <= max and (s != 0 or dfs_tree[s].size() > 1);
            if (is_a[s]) { as.push_back(s); }
        };
        for (usize i = 0; i < sz; i++) {
            if (ord[i] != sz) { continue; }
            dfs(dfs, i, sz), dfs2(dfs2, i);
        }
    }
    bool is_art(const usize i) const { return is_a[i]; }
    bool is_bridge(const usize i, const usize j) const { return (ord[i] < ord[j]) ? ord[i] < low[j] : ord[j] < low[i]; }
    const std::vector<P>& bridges() const { return bs; }
    const std::vector<usize>& arts() const { return as; }
};
template<typename Cost>
class bcc
{
public:
    bcc(const base_graph<Cost>& g) : sz{g.size()}, cmp(sz, sz), link{g}
    {
        auto dfs = [&](auto&& self, const usize s) -> void {
            cmp[s] = cnum;
            for (const usize to : g[s]) {
                if (cmp[to] != sz or link.is_bridge(s, to)) { continue; }
                self(self, to);
            }
        };
        for (usize i = 0; i < sz; i++) {
            if (cmp[i] != sz) { continue; }
            dfs(dfs, i), cnum++;
        }
    }
    usize operator[](const usize v) { return assert(v < sz), cmp[v]; }
    usize comp_num() const { return cnum; }

private:
    const usize sz;
    usize cnum = 0;
    std::vector<usize> cmp;
    const lowlink<Cost> link;
};


template<typename T> T gcd(const T& a, const T& b) { return (a > b ? gcd(b, a) : a == 0 ? b : gcd(b % a, a)); }
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
class id4
{
public:
    template<typename UInt = uint>
    static std::enable_if_t<dynamic, const UInt> mod() { return mod_ref(); }
    template<typename UInt = uint>
    static constexpr std::enable_if_t<not dynamic, const UInt> mod() { return mod_value; }
    template<typename UInt = uint>
    static void set_mod(const std::enable_if_t<dynamic, const UInt> mod) { mod_ref() = mod, inv_ref() = {1, 1}; }
    id4() : v{0} {}
    id4(const ll val) : v{norm(static_cast<uint>(val % static_cast<ll>(mod()) + static_cast<ll>(mod())))} {}
    id4(const id4& n) : v{n()} {}
    explicit operator bool() const { return v != 0; }
    bool operator!() const { return not static_cast<bool>(*this); }
    id4& operator=(const id4& m) { return v = m(), (*this); }
    id4& operator=(const ll val) { return v = norm(uint(val % static_cast<ll>(mod()) + static_cast<ll>(mod()))), (*this); }
    friend id4 operator+(const id4& m) { return m; }
    friend id4 operator-(const id4& m) { return make(norm(mod() - m.v)); }
    friend id4 operator+(const id4& m1, const id4& m2) { return make(norm(m1.v + m2.v)); }
    friend id4 operator-(const id4& m1, const id4& m2) { return make(norm(m1.v + mod() - m2.v)); }
    friend id4 operator*(const id4& m1, const id4& m2) { return make(static_cast<uint>(static_cast<ll>(m1.v) * static_cast<ll>(m2.v) % static_cast<ll>(mod()))); }
    friend id4 operator/(const id4& m1, const id4& m2) { return m1 * inv(m2.v); }
    friend id4 operator+(const id4& m, const ll val) { return id4{static_cast<ll>(m.v) + val}; }
    friend id4 operator-(const id4& m, const ll val) { return id4{static_cast<ll>(m.v) - val}; }
    friend id4 operator*(const id4& m, const ll val) { return id4{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend id4 operator/(const id4& m, const ll val) { return id4{static_cast<ll>(m.v) * inv(val)}; }
    friend id4 operator+(const ll val, const id4& m) { return id4{static_cast<ll>(m.v) + val}; }
    friend id4 operator-(const ll val, const id4& m) { return id4{-static_cast<ll>(m.v) + val}; }
    friend id4 operator*(const ll val, const id4& m) { return id4{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend id4 operator/(const ll val, const id4& m) { return id4{val * inv(static_cast<ll>(m.v))}; }
    friend id4& operator+=(id4& m1, const id4& m2) { return m1 = m1 + m2; }
    friend id4& operator-=(id4& m1, const id4& m2) { return m1 = m1 - m2; }
    friend id4& operator*=(id4& m1, const id4& m2) { return m1 = m1 * m2; }
    friend id4& operator/=(id4& m1, const id4& m2) { return m1 = m1 / m2; }
    friend id4& operator+=(id4& m, const ll val) { return m = m + val; }
    friend id4& operator-=(id4& m, const ll val) { return m = m - val; }
    friend id4& operator*=(id4& m, const ll val) { return m = m * val; }
    friend id4& operator/=(id4& m, const ll val) { return m = m / val; }
    friend id4 operator^(const id4& m, const ll n) { return power(m.v, n); }
    friend id4& operator^=(id4& m, const ll n) { return m = m ^ n; }
    friend bool operator==(const id4& m1, const id4& m2) { return m1.v == m2.v; }
    friend bool operator!=(const id4& m1, const id4& m2) { return not(m1 == m2); }
    friend bool operator==(const id4& m, const ll val) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const id4& m, const ll val) { return not(m == val); }
    friend bool operator==(const ll val, const id4& m) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const ll val, const id4& m) { return not(m == val); }
    friend std::istream& operator>>(std::istream& is, id4& m)
    {
        ll v;
        return is >> v, m = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, const id4& m) { return os << m(); }
    uint operator()() const { return v; }
    static id4 small_inv(const usize n)
    {
        auto& in = inv_ref();
        if (n < in.size()) { return in[n]; }
        for (usize i = in.size(); i <= n; i++) { in.push_back(-in[id4::mod() % i] * (id4::mod() / i)); }
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
    static id4 make(const uint x)
    {
        id4 m;
        return m.v = x, m;
    }
    static id4 power(id4 x, ull n)
    {
        id4 ans = 1;
        for (; n; n >>= 1, x *= x) {
            if (n & 1) { ans *= x; }
        }
        return ans;
    }
    static id4 inv(const ll v) { return v < 1000 ? small_inv(static_cast<usize>(v)) : id4{inverse(v, static_cast<ll>(mod()))}; }
    static std::vector<id4>& inv_ref()
    {
        static std::vector<id4> in{1, 1};
        return in;
    }
    uint v;
};
template<uint mod>
using modint = id4<mod, false>;
template<uint id>
using dynamic_modint = id4<id, true>;

template<typename Value = ll>
struct bfft
{
    using value_type = Value;
    bfft()           = delete;
    static void fzt(std::vector<value_type>& a, const bool upper)
    {
        const usize sz = a.size();
        assert(id2(sz));
        for (usize i = 1; i < sz; i <<= 1) {
            for (usize j = 0; j < sz; j++) {
                if ((j & i) == 0) { (upper ? a[j] : a[j | i]) += (upper ? a[j | i] : a[j]); }
            }
        }
    }
    static void fmt(std::vector<value_type>& a, const bool upper)
    {
        const usize sz = a.size();
        assert(id2(sz));
        for (usize i = 1; i < sz; i <<= 1) {
            for (usize j = 0; j < sz; j++) {
                if ((j & i) == 0) { (upper ? a[j] : a[j | i]) -= (upper ? a[j | i] : a[j]); }
            }
        }
    }
    static void fwt(std::vector<value_type>& a, const bool rev)
    {
        const usize sz = a.size();
        assert(id2(sz));
        for (usize i = 1; i < sz; i <<= 1) {
            for (usize j = 0; j < sz; j++) {
                if ((j & i) == 0) {
                    const value_type x = a[j], y = a[j | i];
                    a[j] = (rev ? (x + y) / value_type(2) : x + y), a[j | i] = (rev ? (x - y) / value_type(2) : x - y);
                }
            }
        }
    }
    static std::vector<value_type> and_convolute(const std::vector<value_type>& a, const std::vector<value_type>& b)
    {
        const usize sz = id2(std::max(a.size(), b.size())) ? a.size() : ceil2(std::max(a.size(), b.size()));
        std::vector<value_type> A(sz), B(sz);
        for (usize i = 0; i < a.size(); i++) { A[i] = a[i]; }
        for (usize i = 0; i < b.size(); i++) { B[i] = b[i]; }
        fzt(A, true), fzt(B, true);
        for (usize i = 0; i < sz; i++) { A[i] *= B[i]; }
        return fmt(A, true), A;
    }
    static std::vector<value_type> or_convolute(const std::vector<value_type>& a, const std::vector<value_type>& b)
    {
        const usize sz = id2(std::max(a.size(), b.size())) ? a.size() : ceil2(std::max(a.size(), b.size()));
        std::vector<value_type> A(sz), B(sz);
        for (usize i = 0; i < a.size(); i++) { A[i] = a[i]; }
        for (usize i = 0; i < b.size(); i++) { B[i] = b[i]; }
        fzt(A, false), fzt(B, false);
        for (usize i = 0; i < sz; i++) { A[i] *= B[i]; }
        return fmt(A, false), A;
    }
    static std::vector<value_type> xor_convolute(const std::vector<value_type>& a, const std::vector<value_type>& b)
    {
        const usize sz = id2(std::max(a.size(), b.size())) ? a.size() : ceil2(std::max(a.size(), b.size()));
        std::vector<value_type> A(sz), B(sz);
        for (usize i = 0; i < a.size(); i++) { A[i] = a[i]; }
        for (usize i = 0; i < b.size(); i++) { B[i] = b[i]; }
        fwt(A, false), fwt(B, false);
        for (usize i = 0; i < sz; i++) { A[i] *= B[i]; }
        return fwt(A, true), A;
    }
};
int main()
{
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);
    constexpr uint mod1 = 1000000007, mod2 = 1000000009;
    using mint1  = modint<mod1>;
    using mint2  = modint<mod2>;
    const auto n = read<int>(), m = read<int>();
    graph g(n);
    int x = 0;
    std::vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        std::cin >> u[i] >> v[i] >> w[i], u[i]--, v[i]--;
        g.add_edge(u[i], v[i], true), x ^= w[i];
    }
    bcc b(g);
    std::vector<int> num(n, 0);
    for (int i = 0; i < n; i++) { num[b[i]]++; }
    std::vector<bool> isc(n);
    for (int i = 0; i < n; i++) { isc[i] = (num[i] >= 2); }
    std::vector<std::vector<int>> c(n);
    for (int i = 0; i < m; i++) {
        if (b[u[i]] == b[v[i]] and isc[b[u[i]]]) { c[b[u[i]]].push_back(w[i]); }
    }
    constexpr int max = 1 << 17;
    std::vector<mint1> dp1(max, 0);
    std::vector<mint2> dp2(max, 0);
    dp1[0] = 1, dp2[0] = 1;
    bfft<mint1>::fwt(dp1, false), bfft<mint2>::fwt(dp2, false);
    std::vector<mint1> v1(max, 0);
    std::vector<mint2> v2(max, 0);
    for (int i = 0; i < n; i++) {
        if (c[i].empty()) { continue; }
        std::fill(v1.begin(), v1.end(), 0), std::fill(v2.begin(), v2.end(), 0);
        for (const int w : c[i]) { v1[w] += 1, v2[w] += 1; }
        bfft<mint1>::fwt(v1, false), bfft<mint2>::fwt(v2, false);
        for (usize i = 0; i < max; i++) { dp1[i] *= v1[i], dp2[i] *= v2[i]; }
    }
    bfft<mint1>::fwt(dp1, true), bfft<mint2>::fwt(dp2, true);
    for (int i = 0; i < max; i++) {
        if (dp1[i ^ x] == 0 and dp2[x ^ i] == 0) { continue; }
        std::cout << i << " " << dp1[x ^ i] << "\n";
        break;
    }
    return 0;
}