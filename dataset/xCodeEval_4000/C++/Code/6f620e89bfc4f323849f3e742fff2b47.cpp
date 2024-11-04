#include <bits/stdc++.h>


#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"

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


template<typename Cost = usize>
struct edge
{
    using cost_type = Cost;
    usize u, v;
    Cost c;
    edge(const usize u, const usize v) : u{u}, v{v}, c{1} {}
    edge(const usize u, const usize v, const Cost& c) : u{u}, v{v}, c{c} {}
    operator usize() const { return v; }
    usize from() const { return u; }
    usize to() const { return v; }
    Cost cost() const { return c; }
    friend std::ostream& operator<<(std::ostream& os, const edge& e) { return os << e.u << "->" << e.v << ":" << e.c; }
};
template<typename Edge>
class base_graph
{
public:
    base_graph(const usize n) : v{n}, es(n), res(n) {}
    void add_edge(const usize u, const usize v, const bool bi = false)
    {
        es[u].emplace_back(u, v), res[v].emplace_back(v, u);
        if (bi) { es[v].emplace_back(v, u), res[u].emplace_back(u, v); }
    }
    template<typename Cost>
    void add_edge(const usize u, const usize v, const Cost& c, const bool bi = false)
    {
        es[u].emplace_back(u, v, c), res[v].emplace_back(v, u, c);
        if (bi) { es[v].emplace_back(v, u, c), res[u].emplace_back(u, v, c); }
    }
    std::vector<Edge>& operator[](const usize u) { return es[u]; }
    const std::vector<Edge>& operator[](const usize u) const { return es[u]; }
    std::vector<Edge>& from(const usize u) { return es[u]; }
    const std::vector<Edge>& from(const usize u) const { return es[u]; }
    std::vector<Edge>& to(const usize v) { return res[v]; }
    const std::vector<Edge>& to(const usize v) const { return res[v]; }
    usize size() const { return v; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        for (usize i = 0; i < g.v; i++) {
            for (const auto& e : g.es[i]) { os << e << '\n'; }
        }
        return os;
    }

private:
    usize v;
    std::vector<std::vector<Edge>> es, res;
};
template<typename Edge>
using base_tree = base_graph<Edge>;
using graph     = base_graph<edge<>>;
using tree      = base_graph<edge<>>;
template<typename Cost>
using cost_graph = base_graph<edge<Cost>>;
template<typename Cost>
using cost_tree = base_graph<edge<Cost>>;
template<typename Edge = edge<>>
class hl_decomp
{
public:
    hl_decomp(base_tree<Edge>& tree, const usize r = 0) : par(tree.size(), tree.size()), top{par}, in{par}, rin{par}, out{par}
    {
        const usize n = tree.size();
        std::vector<usize> sz(n, 1);
        auto dfs1 = [&](auto&& self, const usize s, const usize p) -> usize {
            par[s] = p;
            for (auto& e : tree[s]) {
                const usize to = e.to();
                if (p == to) { continue; }
                sz[s] += self(self, to, s);
                if (sz[to] > sz[tree[s][0].to()]) { std::swap(e, tree[s].front()); }
            }
            return sz[s];
        };
        dfs1(dfs1, r, n);
        top[r]    = r;
        auto dfs2 = [&](auto&& self, const usize s, const usize p, usize& ind) -> void {
            in[s] = ind++, rin[in[s]] = s;
            for (const auto& e : tree[s]) {
                const usize to = e.to();
                if (to == p) { continue; }
                top[to] = (to == tree[s][0].to() ? top[s] : to);
                self(self, to, s, ind);
            }
            out[s] = ind;
        };
        usize ind = 0;
        dfs2(dfs2, r, n, ind);
    }
    usize pos(const usize v) const { return in[v]; }
    usize at(const usize n) const { return rin[n]; }
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
    friend std::ostream& operator<<(std::ostream& os, const hl_decomp& hld)
    {
        os << "{";
        for (const usize v : hld.rin) { os << v << ","; }
        return os << "}";
    }

private:
    std::vector<usize> par, top, in, rin, out;
};

template<typename ValueMonoid>
class segtree
{
public:
    using value_monoid_type = ValueMonoid;
    using value_type        = typename value_monoid_type::value_type;
    segtree(const usize sz, const value_type initial = value_monoid_type::id()) : sz{sz}, half{ceil2(sz)}, val(half << 1, value_monoid_type::id())
    {
        if (initial != value_monoid_type::id()) {
            std::fill(val.begin() + half, val.end(), initial);
            for (usize i = half - 1; i >= 1; i--) { up(i); }
        }
    }
    template<typename InIt>
    segtree(const InIt first, const InIt last) : sz{static_cast<usize>(std::distance(first, last))}, half{ceil2(sz)}, val(half << 1, value_monoid_type::id())
    {
        std::copy(first, last, val.begin() + half);
        for (usize i = half - 1; i >= 1; i--) { up(i); }
    }
    value_type get(const usize a) const { return assert(a < sz), val[a + half]; }
    void set(usize a, const value_type& v)
    {
        assert(a < sz);
        val[a += half] = v;
        while (a >>= 1) { up(a); }
    }
    value_type fold(usize l, usize r) const
    {
        assert(l < r), assert(r <= sz);
        value_type accl = value_monoid_type::id(), accr = value_monoid_type::id();
        for (l += half, r += half; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { accl = value_monoid_type::merge(accl, val[l++]); }
            if (r & 1) { accr = value_monoid_type::merge(val[--r], accr); }
        }
        return value_monoid_type::merge(accl, accr);
    }
    usize size() const { return sz; }
    friend std::ostream& operator<<(std::ostream& os, const segtree& seg)
    {
        os << "[";
        for (usize i = seg.half; i < seg.half + seg.sz; i++) { os << seg.val[i] << (i + 1 == seg.half + seg.sz ? "" : ","); }
        return (os << "]\n");
    }

private:
    void up(const usize i) { val[i] = value_monoid_type::merge(val[i << 1], val[i << 1 | 1]); }
    const usize sz, half;
    std::vector<value_type> val;
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
int main()
{
    const auto [N, Q] = in_t<int, int>();
    const auto as     = in_v<ll>({N});
    graph g(N);
    for (int i = 0; i < N - 1; i++) {
        const auto u = in<int>() - 1, v = in<int>() - 1;
        g.add_edge(u, v, true);
    }
    std::vector<ll> coeff(N, 1);
    mfp([&](auto&& self, const int s, const int p) -> void {
        for (const int to : g[s]) {
            if (to == p) { continue; }
            coeff[to] = -coeff[s];
            self(self, to, s);
        }
    })(0, -1);
    hl_decomp hld(g);
    segtree<sum<ll>> seg(N, 0LL);
    for (int i = 0; i < Q; i++) {
        const auto t = in<int>();
        if (t == 1) {
            const auto x  = in<int>() - 1;
            const auto v  = in<ll>();
            const int pos = hld.pos(x);
            seg.set(pos, seg.get(pos) + coeff[x] * v);
        } else {
            const auto x  = in<int>() - 1;
            const auto ps = hld.path(x, 0);
            ll sum        = 0;
            for (const auto& p : ps) {
                int l = p.first, r = p.second;
                if (l > r) { std::swap(l, r); }
                r++;
                sum += seg.fold(l, r);
            }
            outln(sum * coeff[x]+as[x]);
        }
    }
    return 0;
}
