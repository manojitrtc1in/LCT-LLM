

using ll                            = long long;
using uint                          = unsigned int;
using ull                           = unsigned long long;
using ld                            = long double;
template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
constexpr int popcount(const ull v) { return v ? __builtin_popcountll(v) : 0; }
constexpr int id0(const ull v) { return v ? 64 - __builtin_clzll(v) : 0; }
constexpr int id3(const ull v) { return __builtin_ffsll(v); }
constexpr int clog(const ull v) { return v ? id0(v - 1) : 0; }
constexpr ull ceil2(const ull v) { return 1ULL << clog(v); }
constexpr ull floor2(const ull v) { return v ? (1ULL << (id0(v) - 1)) : 0ULL; }
constexpr bool btest(const ull mask, const int ind) { return (mask >> ind) & 1ULL; }
template<typename T> void bset(T& mask, const int ind) { mask |= ((T)1 << ind); }
template<typename T> void breset(T& mask, const int ind) { mask &= ~((T)1 << ind); }
template<typename T> void bflip(T& mask, const int ind) { mask ^= ((T)1 << ind); }
template<typename T> void bset(T& mask, const int ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T, typename F, typename Merge, typename Compose, typename Apply>
class lazyseg
{
public:
    lazyseg(const std::vector<T>& vs,
            const Merge merge_,
            const T& e_,
            const Compose compose_,
            const F& id_,
            const Apply apply_) : m_size{(int)vs.size()}, m_depth{clog(m_size)}, m_half{1 << m_depth}, m_vals(m_half << 1, e_), m_ops(m_half << 1, id_), m_merge{merge_}, m_e{e_}, m_compose{compose_}, m_id{id_}, m_apply{apply_}
    {
        std::copy(vs.begin(), vs.end(), m_vals.begin() + m_half);
        for (int i = m_half - 1; i >= 1; i--) { up(i); }
    }
    T get(const int a) { return assert(a < m_size), fold(a, a + 1); }
    void set(int a, const T& v)
    {
        assert(0 <= a and a < m_size);
        top_down(a += m_half), top_down(a + 1), m_ops[a] = m_id, m_vals[a] = v;
        while (a >>= 1) { up(a); }
    }
    T fold(int l, int r)
    {
        assert(0 <= l and l <= r and r <= m_size);
        if (l >= r) { return m_e; }
        top_down(l += m_half), top_down(r += m_half);
        T accl = m_e, accr = m_e;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { accl = m_merge(accl, m_vals[l++]); }
            if (r & 1) { accr = m_merge(m_vals[--r], accr); }
        }
        return m_merge(accl, accr);
    }
    void act(int l, int r, const F& f)
    {
        assert(0 <= l and l <= r and r <= m_size);
        const int lin = l + m_half, rin = r + m_half;
        top_down(l += m_half), top_down(r += m_half);
        for (int ls = 1, rs = 1; l < r; l >>= 1, r >>= 1, ls <<= 1, rs <<= 1) {
            if (l & 1) { update(l++, f, ls); }
            if (r & 1) { update(--r, f, rs); }
        }
        bottom_up(lin), bottom_up(rin);
    }
    friend std::ostream& operator<<(std::ostream& os, const lazyseg& lseg)
    {
        auto id2 = lseg;
        os << "[";
        for (int i = 0; i < lseg.m_size; i++) { os << id2.get(i) << (i + 1 == id2.m_size ? "" : ","); }
        return (os << "]\n");
    }

private:
    void up(const int i) { m_vals[i] = m_merge(m_vals[i << 1], m_vals[i << 1 | 1]); }
    void update(const int a, const F& f, const int l) { m_ops[a] = m_compose(f, m_ops[a]), m_vals[a] = m_apply(f, m_vals[a], l); }
    void down(const int a, const int l) { update(a << 1, m_ops[a], l >> 1), update(a << 1 | 1, m_ops[a], l >> 1), m_ops[a] = m_id; }
    void top_down(const int a)
    {
        const int b = (a / (a & -a)) >> 1;
        for (int i = 0, l = m_half; i < m_depth; i++, l >>= 1) {
            const int v = a >> (m_depth - i);
            if (v > b) { break; }
            down(v, l);
        }
    }
    void bottom_up(int a)
    {
        a = (a / (a & -a)) >> 1;
        for (; a >= 1; a >>= 1) { up(a); }
    }
    const int m_size, m_depth, m_half;
    std::vector<T> m_vals;
    std::vector<F> m_ops;
    const Merge m_merge;
    const T m_e;
    const Compose m_compose;
    const F m_id;
    const Apply m_apply;
};


template<typename T = int>
struct edge
{
    using cost_type = T;
    int v;
    T c;
    edge(const int v_) : v{v_}, c{1} {}
    edge(const int v_, const T& c_) : v{v_}, c{c_} {}
    operator int() const { return v; }
    int to() const { return v; }
    T cost() const { return c; }
    friend std::ostream& operator<<(std::ostream& os, const edge& e) { return os << e.v << ":" << e.c; }
};
template<typename Edge>
class base_graph
{
public:
    base_graph(const int n) : sz{n}, es(n), res(n)
    {}
    void add_edge(const int u, const int v, const bool bi = false)
    {
        es[u].emplace_back(v);
        res[v].emplace_back(u);
        if (bi) {
            es[v].emplace_back(u);
            res[u].emplace_back(v);
        }
    }
    template<typename Cost>
    void add_edge(const int u, const int v, const Cost& c, const bool bi = false)
    {
        es[u].emplace_back(v, c);
        res[v].emplace_back(u, c);
        if (bi) {
            es[v].emplace_back(u, c);
            res[u].emplace_back(v, c);
        }
    }
    std::vector<Edge>& operator[](const int u) { return es[u]; }
    const std::vector<Edge>& operator[](const int u) const { return es[u]; }
    std::vector<Edge>& from(const int u) { return es[u]; }
    const std::vector<Edge>& from(const int u) const { return es[u]; }
    std::vector<Edge>& to(const int v) { return res[v]; }
    const std::vector<Edge>& to(const int v) const { return res[v]; }
    int size() const { return sz; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        for (int i = 0; i < g.sz; i++) {
            for (const auto& e : g.es[i]) { os << i << "->" << e << '\n'; }
        }
        return os;
    }

private:
    int sz;
    std::vector<std::vector<Edge>> es, res;
};
using graph = base_graph<edge<>>;
template<typename Cost>
using cost_graph = base_graph<edge<Cost>>;
template<typename Edge = edge<>>
class id1
{
public:
    id1(base_graph<Edge>& g, const int r = 0) : pars(g.size(), -1), tops{pars}, ins{pars}, rins{pars}, outs{pars}
    {
        const int n = g.size();
        std::vector<int> sz(n, 1);
        auto dfs1 = [&](auto&& self, const int s, const int p) -> int {
            pars[s]  = p;
            int maxi = -1, max = 0;
            for (int i = 0; i < (int)g[s].size(); i++) {
                const auto& e = g[s][i];
                const int to  = e.to();
                if (p == to) { continue; }
                sz[s] += self(self, to, s);
                if (max < sz[g[s][i].to()]) { max = sz[g[s][i].to()], maxi = i; }
            }
            if (maxi != -1) { std::swap(g[s][maxi], g[s][0]); }
            return sz[s];
        };
        dfs1(dfs1, r, -1);
        tops[r]   = r;
        auto dfs2 = [&](auto&& self, const int s, const int p, int& ind) -> void {
            ins[s] = ind++, rins[ins[s]] = s;
            for (const auto& e : g[s]) {
                const int to = e.to();
                if (to == p) { continue; }
                tops[to] = (to == g[s][0].to() ? tops[s] : to);
                self(self, to, s, ind);
            }
            outs[s] = ind;
        };
        int ind = 0;
        dfs2(dfs2, r, -1, ind);
    }
    int pos(const int v) const { return ins[v]; }
    int at(const int n) const { return rins[n]; }
    std::pair<int, int> sub(const int v) const { return {ins[v], outs[v]}; }
    std::vector<std::pair<int, int>> path(int u, int v) const
    {
        using P = std::pair<int, int>;
        std::vector<P> head, tail;
        for (int pu = tops[u], pv = tops[v]; pu != pv;) {
            if (ins[pu] < ins[pv]) {
                tail.push_back({ins[pv], ins[v]});
                v = pars[pv], pv = tops[v];
            } else {
                head.push_back({ins[u], ins[pu]});
                u = pars[pu], pu = tops[u];
            }
        }
        head.push_back({ins[u], ins[v]});
        std::reverse(tail.begin(), tail.end());
        for (const auto& p : tail) { head.push_back(p); }
        return head;
    }
    friend std::ostream& operator<<(std::ostream& os, const id1& hld)
    {
        os << "rins = {";
        for (const int v : hld.rins) { os << v << ","; }
        os << "}\ntops = {";
        for (const int v : hld.tops) { os << v << ","; }
        return os << "}";
    }

private:
    std::vector<int> pars, tops, ins, rins, outs;
};
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};
template<typename T> constexpr T TEN(const int n) { return n == 0 ? T{1} : TEN<T>(n - 1) * T{10}; }
template<typename F> struct fix : F
{
    fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args> auto operator()(Args&&... args) const { return F::operator()(*this, std::forward<Args>(args)...); }
};
template<typename T, int n, int i = 0>
auto nd_array(int const (&szs)[n], const T x = T{}) { if constexpr (i == n) { return x; } else { return std::vector(szs[i], nd_array<T, n, i + 1>(szs, x)); } }
class printer
{
public:
    printer(std::ostream& os_ = std::cout) : m_os{os_} { m_os << std::fixed << std::setprecision(15); }
    template<typename... Args> int ln(const Args&... args) { return dump(args...), m_os << '\n', 0; }
    template<typename... Args> int el(const Args&... args) { return dump(args...), m_os << std::endl, 0; }
    template<typename... Args> int fmt(const std::string& s, const Args&... args) { return rec(s, 0, args...); }
private:
    template<typename T> int dump(const T& v) { return m_os << v, 0; }
    template<typename T> int dump(const std::vector<T>& vs) { for (int i = 0; i < (int)vs.size(); i++) { m_os << (i ? " " : ""), dump(vs[i]); } return 0; }
    template<typename T> int dump(const std::vector<std::vector<T>>& vss) { for (int i = 0; i < (int)vss.size(); i++) { m_os << (0 <= i or i + 1 < (int)vss.size() ? "\n" : ""), dump(vss[i]); } return 0; }
    template<typename T, typename... Args> int dump(const T& v, const Args&... args) { return dump(v), m_os << ' ', dump(args...), 0; }
    int rec(const std::string& s, int index) { return m_os << s.substr(index, s.size()), 0; }
    template<typename T, typename... Args> int rec(const std::string& s, int index, const T& v, const Args&... args) { return index == s.size() ? 0 : s[index] == '%' ? (tdump(v), rec(s, index + 1, args...)) : (m_os << s[index], rec(s, index + 1, v, args...)); }
    std::ostream& m_os;
};
printer out;
class scanner
{
public:
    scanner(std::istream& is_ = std::cin) : m_is{is_} { m_is.tie(nullptr), std::ios::sync_with_stdio(false); }
    template<typename T> T val() { T v; return m_is >> v, v; }
    template<typename T> T val(const T offset) { return val<T>() - offset; }
    template<typename T> std::vector<T> vec(const int n) { return make_v<T>(n, [this]() { return val<T>(); }); }
    template<typename T> std::vector<T> vec(const int n, const T offset) { return make_v<T>(n, [this, offset]() { return val<T>(offset); }); }
  template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1) { return make_v<std::vector<T>>(n0, [this, n1]() { return vec<T>(n1); }); }
  template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1, const T offset) { return make_v<std::vector<T>>(n0, [this, n1, offset]() { return vec<T>(n1, offset); }); }
    template<typename... Args> auto tup() { return std::tuple<std::decay_t<Args>...>{val<Args>()...}; }
    template<typename... Args> auto tup(const Args&... offsets) { return std::tuple<std::decay_t<Args>...>{val<Args>(offsets)...}; }
private:
    template<typename T, typename F>
    std::vector<T> make_v(const int n, F f)
    {
        std::vector<T> ans;
        for (int i = 0; i < n; i++) { ans.push_back(f()); }
        return ans;
    }
    std::istream& m_is;
};
scanner in;

int main()
{
    const auto N = in.val<int>();
    std::vector<int> us(N - 1), vs(N - 1);
    std::vector<int> ts(N - 1);
    graph g(N);
    for (int i = 0; i < N - 1; i++) {
        std::tie(us[i], vs[i], ts[i]) = in.tup<int, int, int>(1, 1, 0);
        g.add_edge(us[i], vs[i], true);
    }
    std::vector<int> ds1(N, 0), ds2(N, 0);
    auto dfs1 = fix([&](auto dfs, const int s, const int p) -> void {
        for (const int to : g[s]) {
            if (to == p) { continue; }
            ds1[to] = ds1[s] + 1;
            dfs(to, s);
        }
    });
    dfs1(0, -1);
    const int s1 = std::max_element(ds1.begin(), ds1.end()) - ds1.begin();
    std::fill(ds1.begin(), ds1.end(), 0);
    dfs1(s1, -1);
    const int s2 = std::max_element(ds1.begin(), ds1.end()) - ds1.begin();
    auto dfs2    = fix([&](auto dfs, const int s, const int p) -> void {
        for (const int to : g[s]) {
            if (to == p) { continue; }
            ds2[to] = ds2[s] + 1;
            dfs(to, s);
        }
    });
    dfs2(s2, -1);
    SHOW(s1, s2);
    SHOW(ds1);
    SHOW(ds2);

    cost_graph<int> g1(N), g2(N);
    for (int i = 0; i < N - 1; i++) {
        const int u = us[i], v = vs[i];
        const int t = ts[i];
        if (ds1[u] < ds1[v]) {
            g1.add_edge(u, v, t);
        } else {
            g1.add_edge(v, u, t);
        }
        if (ds2[u] < ds2[v]) {
            g2.add_edge(u, v, t);
        } else {
            g2.add_edge(v, u, t);
        }
    }
    SHOW(g1);
    SHOW(g2);
    std::vector<int> ins1(N), outs1(N);
    std::vector<int> ins2(N), outs2(N);
    std::vector<int> vs1, vs2;
    std::vector<int> ps1(N, 0), ps2(N, 0);
    fix([&](auto dfs, const int s) -> void {
        ins1[s] = vs1.size();
        vs1.push_back(s);
        for (const auto [to, c] : g1[s]) {
            ps1[to] = ps1[s] ^ c;
            dfs(to);
        }
        outs1[s] = vs1.size();
    })(s1);
    fix([&](auto dfs, const int s) -> void {
        ins2[s] = vs2.size();
        vs2.push_back(s);
        for (const auto [to, c] : g2[s]) {
            ps2[to] = ps2[s] ^ c;
            dfs(to);
        }
        outs2[s] = vs2.size();
    })(s2);
    SHOW(vs1);
    SHOW(vs2);
    SHOW(ins1);
    SHOW(outs1);
    SHOW(ins2);
    SHOW(outs2);
    using pii = std::pair<int, int>;
    std::vector<pii> vals1, vals2;
    for (const int v1 : vs1) {
        if (ps1[v1]) {
            vals1.push_back({-inf_v<int>, ds1[v1]});
        } else {
            vals1.push_back({ds1[v1], -inf_v<int>});
        }
    }
    for (const int v2 : vs2) {
        if (ps2[v2]) {
            vals2.push_back({-inf_v<int>, ds2[v2]});
        } else {
            vals2.push_back({ds2[v2], -inf_v<int>});
        }
    }

    lazyseg seg1(
        vals1,
        [&](const pii& p1, const pii& p2) { return pii{std::max(p1.first, p2.first), std::max(p1.second, p2.second)}; },
        pii{-inf_v<int>, -inf_v<int>},
        [&](const bool f1, const bool f2) { return f1 ^ f2; },
        false,
        [&](const bool f, const pii& p, const int) {
            if (f) {
                return pii{p.second, p.first};
            } else {
                return p;
            }
        });
    lazyseg seg2(
        vals2,
        [&](const pii& p1, const pii& p2) { return pii{std::max(p1.first, p2.first), std::max(p1.second, p2.second)}; },
        pii{-inf_v<int>, -inf_v<int>},
        [&](const bool f1, const bool f2) { return f1 ^ f2; },
        false,
        [&](const bool f, const pii& p, const int) {
            if (f) {
                return pii{p.second, p.first};
            } else {
                return p;
            }
        });
    const auto M = in.val<int>();
    for (int i = 0; i < M; i++) {
        const int ei = in.val<int>(1);
        const int u = us[ei], v = vs[ei];
        const int w1 = (ds1[u] < ds1[v] ? v : u);
        const int w2 = (ds2[u] < ds2[v] ? v : u);
        SHOW(ei, u, v, w1, w2);
        const int l1 = ins1[w1], r1 = outs1[w1];
        SHOW(l1, r1);
        seg1.act(l1, r1, true);
        const int l2 = ins2[w2], r2 = outs2[w2];
        SHOW(l2, r2);
        seg2.act(l2, r2, true);
        SHOW(seg1);
        SHOW(seg2);
        int ans = -inf_v<int>;
        chmax(ans, seg1.fold(0, N).first);
        chmax(ans, seg2.fold(0, N).first);
        out.ln(ans);
    }
    return 0;
}
