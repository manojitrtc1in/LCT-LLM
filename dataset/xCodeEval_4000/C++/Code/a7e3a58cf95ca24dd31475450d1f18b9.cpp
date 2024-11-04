#include <bits/stdc++.h>


#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"

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

template<typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template<typename T, typename... Args>
auto read(const usize size, Args... args)
{
    std::vector<decltype(read<T>(args...))> ans(size);
    for (usize i = 0; i < size; i++) { ans[i] = read<T>(args...); }
    return ans;
}
template<typename... Types>
auto reads() { return std::tuple<std::decay_t<Types>...>{read<Types>()...}; }
#    define SHOW(...) static_cast<void>(0)

template<typename T>
std::vector<T> make_v(const usize size, const T v) { return std::vector<T>(size, v); }
template<typename... Args>
auto make_v(const usize size, Args... args) { return std::vector<decltype(make_v(args...))>(size, make_v(args...)); }


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
        usize from, to;
        Cost cost;
        bool operator<(const edge& e) const { return cost != e.cost ? cost < e.cost : to < e.to; }
    };
    std::vector<edge>& operator[](const usize i) { return assert(i < sz), edges[i]; }
    const std::vector<edge>& operator[](const usize i) const { return assert(i < sz), edges[i]; }
    const std::vector<std::vector<edge>>& rev_edge() const { return rev_edges; }
    std::vector<std::vector<edge>>& rev_edge() { return rev_edges; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        os << "[\n";
        for (usize i = 0; i < g.sz; i++) {
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
    std::vector<usize>& operator[](const usize i) { return assert(i < sz), edges[i]; }
    const std::vector<usize>& operator[](const usize i) const { return assert(i < sz), edges[i]; }
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
class hld
{
public:
    hld(cost_tree<Cost>& tree, const usize r = 0) : par(tree.size(), tree.size()), top{par}, in{par}, rin{par}, out{par}
    {
        const usize n = tree.size();
        std::vector<usize> sz(n, 1);
        auto dfs1 = [&](auto&& self, const usize s, const usize p) -> usize {
            par[s] = p;
            for (auto& e : tree[s]) {
                const usize to = base_graph<Cost>::to(e);
                if (p == to) { continue; }
                sz[s] += self(self, to, s);
                if (sz[to] > sz[tree[s][0]]) { std::swap(e, tree[s][0]); }
            }
            return sz[s];
        };
        dfs1(dfs1, r, n);
        top[r]    = r;
        auto dfs2 = [&](auto&& self, const usize s, const usize p, usize& ind) -> void {
            in[s] = ind++, rin[in[s]] = s;
            for (const auto& e : tree[s]) {
                const usize to = base_graph<Cost>::to(e);
                if (to == p) { continue; }
                top[to] = (to == tree[s][0] ? top[s] : to);
                self(self, to, s, ind);
            }
            out[s] = ind;
        };
        usize ind = 0;
        dfs2(dfs2, r, n, ind);
    }
    usize ord(const usize v) const { return in[v]; }
    usize at(const usize v) const { return rin[v]; }
    std::pair<usize, usize> sub(const usize v) const { return {in[v], out[v]}; }
    std::vector<std::pair<usize, usize>> path(usize u, usize v, const bool edgeWeight = false) const
    {
        using P = std::pair<usize, usize>;
        std::vector<P> head, tail;
        for (usize pu = top[u], pv = top[v]; pu != pv;) {
            if (in[pu] < in[pv]) {
                tail.push_back({in[pv], in[v]});
                v = par[pv], pv = top[v];
            } else {
                tail.push_back({in[u], in[pu]});
                u = par[pu], pu = top[u];
            }
        }
        if (edgeWeight) {
            if (std::abs((int)in[u] - (int)in[v]) >= 1) { head.push_back(in[u] < in[v] ? P{in[u] + 1, in[v]} : P{in[u], in[v] + 1}); }
        } else {
            head.push_back({in[u], in[v]});
        }
        std::reverse(tail.begin(), tail.end());
        for (const auto& p : tail) { head.push_back(p); }
        return head;
    }

private:
    std::vector<usize> par, top, in, rin, out;
};

template<typename MonoidAct>
class lazyseg
{
public:
    using monoid_act_type      = MonoidAct;
    using value_monoid_type    = typename monoid_act_type::value_monoid_type;
    using operator_monoid_type = typename monoid_act_type::operator_monoid_type;
    using value_type           = typename value_monoid_type::value_type;
    using operator_type        = typename operator_monoid_type::operator_type;
    lazyseg(const usize sz, const value_type initial = value_monoid_type::id()) : sz{sz}, depth{clog(sz)}, half{static_cast<usize>(1) << depth}, val(half << 1, value_monoid_type::id()), op(half << 1, operator_monoid_type::id())
    {
        if (initial != value_monoid_type::id()) {
            std::fill(val.begin() + half, val.end(), initial);
            for (usize i = half - 1; i >= 1; i--) { up(i); }
        }
    }
    template<typename InIt>
    lazyseg(const InIt first, const InIt last) : sz{static_cast<usize>(std::distance(first, last))}, depth{clog(sz)}, half{static_cast<usize>(1) << depth}, val(half << 1, value_monoid_type::id()), op(half << 1, operator_monoid_type::id())
    {
        std::copy(first, last, val.begin() + half);
        for (usize i = half - 1; i >= 1; i--) { up(i); }
    }
    value_type get(const usize a) { return assert(a < sz), fold(a, a + 1); }
    void set(usize a, const value_type& v)
    {
        assert(a < sz);
        top_down(a += half), top_down(a + 1), op[a] = operator_monoid_type::id(), val[a] = v;
        while (a >>= 1) { up(a); }
    }
    value_type fold(usize l, usize r)
    {
        assert(l < r), assert(r <= sz);
        top_down(l += half), top_down(r += half);
        value_type accl = value_monoid_type::id(), accr = value_monoid_type::id();
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { accl = value_monoid_type::merge(accl, val[l++]); }
            if (r & 1) { accr = value_monoid_type::merge(val[--r], accr); }
        }
        return value_monoid_type::merge(accl, accr);
    }
    void act(usize l, usize r, const operator_type& f)
    {
        assert(l < r), assert(r <= sz);
        const usize lin = l + half, rin = r + half;
        top_down(l += half), top_down(r += half);
        for (usize ls = 1, rs = 1; l < r; l >>= 1, r >>= 1, ls <<= 1, rs <<= 1) {
            if (l & 1) { update(l++, f, ls); }
            if (r & 1) { update(--r, f, rs); }
        }
        bottom_up(lin), bottom_up(rin);
    }
    friend std::ostream& operator<<(std::ostream& os, const lazyseg& lseg)
    {
        auto lseg2 = lseg;
        os << "[";
        for (usize i = 0; i < lseg.sz; i++) { os << lseg2.get(i) << (i + 1 == lseg2.sz ? "" : ","); }
        return (os << "]\n");
    }

private:
    void up(const usize i) { val[i] = value_monoid_type::merge(val[i << 1], val[i << 1 | 1]); }
    void update(const usize a, const operator_type& f, const usize l) { op[a] = operator_monoid_type::compose(f, op[a]), val[a] = monoid_act_type::apply(f, val[a], l); }
    void down(const usize a, const usize l) { update(a << 1, op[a], l >> 1), update(a << 1 | 1, op[a], l >> 1), op[a] = operator_monoid_type::id(); }
    void top_down(const usize a)
    {
        const usize b = (a / (a & -a)) >> 1;
        for (usize i = 0, l = half; i < depth; i++, l >>= 1) {
            const usize v = a >> (depth - i);
            if (v > b) { break; }
            down(v, l);
        }
    }
    void bottom_up(usize a)
    {
        a = (a / (a & -a)) >> 1;
        for (; a >= 1; a >>= 1) { up(a); }
    }
    const usize sz, depth, half;
    std::vector<value_type> val;
    std::vector<operator_type> op;
};
template<typename Element>
struct plus
{
    using element_type  = Element;
    using operator_type = element_type;
    plus()              = delete;
    static operator_type compose(const operator_type& a, const operator_type& b) { return a + b; }
    static constexpr operator_type id() { return operator_type{}; }
};
template<typename Element>
struct sum
{
    using element_type = Element;
    using value_type   = element_type;
    sum()              = delete;
    static value_type merge(const value_type& a, const value_type& b) { return a + b; }
    static constexpr value_type id() { return value_type{}; }
};
template<typename ValueElement, typename OperatorElement>
struct sum_plus
{
    using value_element_type    = ValueElement;
    using operator_element_type = OperatorElement;
    using value_monoid_type     = sum<value_element_type>;
    using operator_monoid_type  = plus<operator_element_type>;
    using value_type            = typename value_monoid_type::value_type;
    using operator_type         = typename operator_monoid_type::operator_type;
    sum_plus()                  = delete;
    template<typename Ind>
    static value_type apply(const operator_type& f, const value_type& x, const Ind l) { return x + static_cast<value_type>(l) * static_cast<value_type>(f); }
};
int main()
{
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);
    using mint  = modint<mod>;
    const int n = read<int>();
    std::vector<int> ls(n), rs(n);
    for (int i = 0; i < n; i++) { std::cin >> ls[i] >> rs[i], rs[i]++; }
    graph g(n);
    for (int i = 0; i < n - 1; i++) {
        const int u = read<int>() - 1, v = read<int>() - 1;
        g.add_edge(u, v, true);
    }
    hld{g, 0};  


    std::vector<int> depth(n, 0);
    {
        auto dfs = [&](auto&& self, const int s, const int p) -> void {
            for (const int to : g[s]) {
                if (to == p) { continue; }
                depth[to] = depth[s] + 1;
                self(self, to, s);
            }
        };
        dfs(dfs, 0, -1);
    }

    constexpr int NUM = 100000;
    std::vector<mint> invs(n, 0);
    for (int i = 0; i < n; i++) { invs[i] = mint(1) / (rs[i] - ls[i]); }
    lazyseg<sum_plus<mint, mint>> num(NUM + 1);
    std::vector<mint> sum(NUM + 2, 0);
    std::vector<mint> ssum(n, 0);
    std::vector<std::vector<int>> subs(n);
    auto dfs = [&](auto&& self, const int s, const int p, const bool keep) -> void {
        const int cn = g[s].size();
        for (int i = 1; i < cn; i++) {
            const int to = g[s][i];
            if (to == p) { continue; }
            self(self, to, s, false);
        }
        if (g[s][0] != p) {
            const int to = g[s][0];
            self(self, to, s, true);
            std::swap(subs[to], subs[s]);
            ssum[s] = ssum[to];
        }
        subs[s].push_back(s);
        const mint fold = num.fold(ls[s], rs[s]);
        const mint d    = invs[s];
        ssum[s] += fold * d * 2 + d * d * (rs[s] - ls[s]);
        num.act(ls[s], rs[s], d);
        sum[ls[s]] += (depth[s] + 1) * d;
        sum[rs[s]] -= (depth[s] + 1) * d;
        for (int i = 1; i < cn; i++) {
            const int to = g[s][i];
            if (to == p) { continue; }
            for (const int u : subs[to]) {
                const mint fold = num.fold(ls[u], rs[u]);
                const mint d    = invs[u];
                ssum[s] += fold * d * 2 + d * d * (rs[u] - ls[u]);
                num.act(ls[u], rs[u], d);
                subs[s].push_back(u);
            }
        }
        if (not keep) {
            for (const int u : subs[s]) {
                num.act(ls[u], rs[u], -invs[u]);
            }
        }
    };
    dfs(dfs, 0, -1, true);
    for (int i = 1; i <= NUM; i++) { sum[i] += sum[i - 1]; }
    mint ans = 0;
    for (int i = 0; i < n; i++) { ans -= ssum[i]; }
    for (int i = 0; i <= NUM; i++) { ans += num.get(i) * sum[i]; }
    for (int i = 0; i < n; i++) { ans *= (rs[i] - ls[i]); }
    std::cout << ans << std::endl;
}
