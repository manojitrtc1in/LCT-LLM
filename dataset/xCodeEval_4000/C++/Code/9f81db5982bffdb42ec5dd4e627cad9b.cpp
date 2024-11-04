#include <bits/stdc++.h>
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using f64 = double;
using f80 = long double;
using f128 = __float128;
constexpr i32 operator"" _i32(u64 v)
{
    return v;
}
constexpr i32 operator"" _u32(u64 v)
{
    return v;
}
constexpr i64 operator"" _i64(u64 v)
{
    return v;
}
constexpr u64 operator"" _u64(u64 v)
{
    return v;
}
constexpr f64 operator"" _f64(f80 v)
{
    return v;
}
constexpr f80 operator"" _f80(f80 v)
{
    return v;
}
using Istream = std::istream;
using Ostream = std::ostream;
using Str = std::string;
template<typename T>
using Lt = std::less<T>;
template<typename T>
using Gt = std::greater<T>;
template<typename T>
using IList = std::initializer_list<T>;
template<int n>
using BSet = std::bitset<n>;
template<typename T1, typename T2>
using Pair = std::pair<T1, T2>;
template<typename... Ts>
using Tup = std::tuple<Ts...>;
template<typename T, int N>
using Arr = std::array<T, N>;
template<typename... Ts>
using Deq = std::deque<Ts...>;
template<typename... Ts>
using Set = std::set<Ts...>;
template<typename... Ts>
using MSet = std::multiset<Ts...>;
template<typename... Ts>
using USet = std::unordered_set<Ts...>;
template<typename... Ts>
using UMSet = std::unordered_multiset<Ts...>;
template<typename... Ts>
using Map = std::map<Ts...>;
template<typename... Ts>
using MMap = std::multimap<Ts...>;
template<typename... Ts>
using UMap = std::unordered_map<Ts...>;
template<typename... Ts>
using UMMap = std::unordered_multimap<Ts...>;
template<typename... Ts>
using Vec = std::vector<Ts...>;
template<typename... Ts>
using Stack = std::stack<Ts...>;
template<typename... Ts>
using Queue = std::queue<Ts...>;
template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, Vec<T>, Gt<T>>;
using NSec = std::chrono::nanoseconds;
using USec = std::chrono::microseconds;
using MSec = std::chrono::milliseconds;
using Sec = std::chrono::seconds;
template<typename T>
constexpr T LIMMIN = std::numeric_limits<T>::min();
template<typename T>
constexpr T LIMMAX = std::numeric_limits<T>::max();
template<typename T>
constexpr T INF = (LIMMAX<T> - 1) / 2;
template<typename T>
constexpr T PI = T{3.141592653589793238462643383279502884};
template<typename T = u64>
constexpr T TEN(const int n)
{
    return n == 0 ? T{1} : TEN<T>(n - 1) * T{10};
}
Ostream& operator<<(Ostream& os, i128 v)
{
    bool minus = false;
    if (v < 0) { minus = true, v = -v; }
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) {
        ans.push_back('0' + v % 10), v /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return os << (minus ? "-" : "") << ans;
}
Ostream& operator<<(Ostream& os, u128 v)
{
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) {
        ans.push_back('0' + v % 10), v /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return os << ans;
}
template<typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
constexpr T floorDiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T ceilDiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? (x + y - 1) / y : x / y;
}
template<typename T, typename I>
constexpr T modPower(T v, I n, T mod)
{
    T ans = 1 % mod;
    for (; n > 0; n >>= 1, (v *= v) %= mod) {
        if (n % 2 == 1) { (ans *= v) %= mod; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n)
{
    T ans = 1;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n, const T& e)
{
    T ans = e;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T>
Vec<T>& operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    vs1.insert(vs1.end(), vs2.begin(), vs2.end());
    return vs1;
}
template<typename T>
Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    auto vs = vs1;
    vs += vs2;
    return vs;
}
template<typename Vs, typename V>
void fillAll(Vs& arr, const V& v)
{
    if constexpr (std::is_convertible<V, Vs>::value) {
        arr = v;
    } else {
        for (auto& subarr : arr) {
            fillAll(subarr, v);
        }
    }
}
template<typename Vs>
void sortAll(Vs& vs)
{
    std::sort(std::begin(vs), std::end(vs));
}
template<typename Vs, typename C>
void sortAll(Vs& vs, C comp)
{
    std::sort(std::begin(vs), std::end(vs), comp);
}
template<typename Vs>
void reverseAll(Vs& vs)
{
    std::reverse(std::begin(vs), std::end(vs));
}
template<typename V, typename Vs>
V sumAll(const Vs& vs)
{
    if constexpr (std::is_convertible<Vs, V>::value) {
        return static_cast<V>(vs);
    } else {
        V ans = 0;
        for (const auto& v : vs) {
            ans += sumAll<V>(v);
        }
        return ans;
    }
}
template<typename Vs>
int minInd(const Vs& vs)
{
    return std::min_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs>
int maxInd(const Vs& vs)
{
    return std::max_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs, typename V>
int lbInd(const Vs& vs, const V& v)
{
    return std::lower_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
int ubInd(const Vs& vs, const V& v)
{
    return std::upper_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
bool contains(const Vs& vs, const V& v)
{
    const int li = lbInd(vs, v);
    return (li < std::size(vs) and vs[li] == v);
}
template<typename Vs, typename V>
void plusAll(Vs& vs, const V& v)
{
    for (auto& v_ : vs) {
        v_ += v;
    }
}
template<typename T, typename F>
Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_insert_iterator(ans), n, gen);
    return ans;
}
template<typename T = int>
Vec<T> iotaVec(int n, T offset = 0)
{
    Vec<T> ans(n);
    std::iota(ans.begin(), ans.end(), offset);
    return ans;
}
constexpr int popcount(const u64 v)
{
    return v ? __builtin_popcountll(v) : 0;
}
constexpr int log2p1(const u64 v)
{
    return v ? 64 - __builtin_clzll(v) : 0;
}
constexpr int lsbp1(const u64 v)
{
    return __builtin_ffsll(v);
}
constexpr int ceillog(const u64 v)
{
    return v ? log2p1(v - 1) : 0;
}
constexpr u64 ceil2(const u64 v)
{
    const int l = ceillog(v);
    return (l == 64) ? 0_u64 : (1_u64 << l);
}
constexpr u64 floor2(const u64 v)
{
    return v ? (1_u64 << (log2p1(v) - 1)) : 0_u64;
}
constexpr bool ispow2(const u64 v)
{
    return (v > 0) and ((v & (v - 1)) == 0);
}
constexpr bool btest(const u64 mask, const int ind)
{
    return (mask >> ind) & 1_u64;
}
template<typename F>
struct Fix : F
{
    Fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args>
    auto operator()(Args&&... args) const
    {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
class irange
{
private:
    struct itr
    {
        itr(i64 start = 0, i64 step = 1) : m_cnt{start}, m_step{step} {}
        bool operator!=(const itr& it) const
        {
            return m_cnt != it.m_cnt;
        }
        i64 operator*()
        {
            return m_cnt;
        }
        itr& operator++()
        {
            m_cnt += m_step;
            return *this;
        }
        i64 m_cnt, m_step;
    };
    i64 m_start, m_end, m_step;
public:
    irange(i64 start, i64 end, i64 step = 1)
    {
        assert(step != 0);
        const i64 d = std::abs(step);
        const i64 l = (step > 0 ? start : end);
        const i64 r = (step > 0 ? end : start);
        i64 n = (r - l) / d + ((r - l) % d ? 1 : 0);
        if (l >= r) { n = 0; }
        m_start = start;
        m_end = start + step * n;
        m_step = step;
    }
    itr begin() const
    {
        return itr{m_start, m_step};
    }
    itr end() const
    {
        return itr{m_end, m_step};
    }
};
irange rep(i64 end)
{
    return irange(0, end, 1);
}
irange per(i64 rend)
{
    return irange(rend - 1, -1, -1);
}

namespace xoshiro_impl {
u64 x;
u64 next()
{
    uint64_t z = (x += 0x9e3779b97f4a7c15);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
    return z ^ (z >> 31);
}
} 

class Xoshiro32
{
public:
    using result_type = u32;
    using T = result_type;
    Xoshiro32(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return LIMMIN<T>;
    }
    static constexpr T max()
    {
        return LIMMAX<T>;
    }
    T operator()()
    {
        return next();
    }
private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (32 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 9;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 11);
        return ans;
    }
    T s[4];
};
class Xoshiro64
{
public:
    using result_type = u64;
    using T = result_type;
    Xoshiro64(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return LIMMIN<T>;
    }
    static constexpr T max()
    {
        return LIMMAX<T>;
    }
    T operator()()
    {
        return next();
    }
private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (64 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 17;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 45);
        return ans;
    }
    T s[4];
};
template<typename Rng>
class RNG
{
public:
    using result_type = typename Rng::result_type;
    using T = result_type;
    static constexpr T min()
    {
        return Rng::min();
    }
    static constexpr T max()
    {
        return Rng::max();
    }
    RNG() : RNG(std::random_device{}()) {}
    RNG(T seed) : m_rng(seed) {}
    T operator()()
    {
        return m_rng();
    }
    template<typename T>
    T val(T min, T max)
    {
        return std::uniform_int_distribution<T>(min, max)(m_rng);
    }
    template<typename T>
    Pair<T, T> pair(T min, T max)
    {
        return std::minmax({val<T>(min, max), val<T>(min, max)});
    }
    template<typename T>
    Vec<T> vec(int n, T min, T max)
    {
        return genVec<T>(n, [&]() { return val<T>(min, max); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, T min, T max)
    {
        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });
    }
private:
    Rng m_rng;
};
RNG<std::mt19937> rng;
RNG<std::mt19937_64> rng64;
RNG<Xoshiro32> rng_xo;
RNG<Xoshiro64> rng_xo64;
class Scanner
{
public:
    Scanner(Istream& is = std::cin) : m_is{is}
    {
        m_is.tie(nullptr)->sync_with_stdio(false);
    }
    template<typename T>
    T val()
    {
        T v;
        return m_is >> v, v;
    }
    template<typename T>
    T val(T offset)
    {
        return val<T>() - offset;
    }
    template<typename T>
    Vec<T> vec(int n)
    {
        return genVec<T>(n, [&]() { return val<T>(); });
    }
    template<typename T>
    Vec<T> vec(int n, T offset)
    {
        return genVec<T>(n, [&]() { return val<T>(offset); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, const T offset)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m, offset); });
    }
    template<typename... Args>
    auto tup()
    {
        return Tup<Args...>{val<Args>()...};
    }
    template<typename... Args>
    auto tup(const Args&... offsets)
    {
        return Tup<Args...>{val<Args>(offsets)...};
    }
private:
    Istream& m_is;
};
Scanner in;
class Printer
{
public:
    Printer(Ostream& os = std::cout) : m_os{os}
    {
        m_os << std::fixed << std::setprecision(15);
    }
    template<typename... Args>
    int operator()(const Args&... args)
    {
        dump(args...);
        return 0;
    }
    template<typename... Args>
    int ln(const Args&... args)
    {
        dump(args...), m_os << '\n';
        return 0;
    }
    template<typename... Args>
    int el(const Args&... args)
    {
        dump(args...), m_os << std::endl;
        return 0;
    }
private:
    template<typename T>
    void dump(const T& v)
    {
        m_os << v;
    }
    template<typename T>
    void dump(const Vec<T>& vs)
    {
        for (const int i : rep(vs.size())) {
            m_os << (i ? " " : ""), dump(vs[i]);
        }
    }
    template<typename T>
    void dump(const Vec<Vec<T>>& vss)
    {
        for (const int i : rep(vss.size())) {
            m_os << (i ? "\n" : ""), dump(vss[i]);
        }
    }
    template<typename T, typename... Ts>
    int dump(const T& v, const Ts&... args)
    {
        dump(v), m_os << ' ', dump(args...);
        return 0;
    }
    Ostream& m_os;
};
Printer out;
template<typename T = int>
class Graph
{
    struct Edge
    {
        Edge() = default;
        Edge(int i, int t, T c) : id{i}, to{t}, cost{c} {}
        int id;
        int to;
        T cost;
        operator int() const
        {
            return to;
        }
    };
public:
    Graph(int n) : m_v{n}, m_edges(n) {}
    void addEdge(int u, int v, bool bi = false)
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        m_edges[u].emplace_back(m_e, v, 1);
        if (bi) { m_edges[v].emplace_back(m_e, u, 1); }
        m_e++;
    }
    void addEdge(int u, int v, const T& c, bool bi = false)
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        m_edges[u].emplace_back(m_e, v, c);
        if (bi) { m_edges[v].emplace_back(m_e, u, c); }
        m_e++;
    }
    const Vec<Edge>& operator[](const int u) const
    {
        assert(0 <= u and u < m_v);
        return m_edges[u];
    }
    Vec<Edge>& operator[](const int u)
    {
        assert(0 <= u and u < m_v);
        return m_edges[u];
    }
    int v() const
    {
        return m_v;
    }
    int e() const
    {
        return m_e;
    }
    friend Ostream& operator<<(Ostream& os, const Graph& g)
    {
        for (int u : rep(g.v())) {
            for (const auto& [id, v, c] : g[u]) {
                os << "[" << id << "]: ";
                os << u << "->" << v << "(" << c << ")\n";
            }
        }
        return os;
    }
    Vec<T> sizes(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ss(N, 1);
        Fix([&](auto dfs, int u, int p) -> void {
            for ([[maybe_unused]] const auto& [_temp_name_0, v, c] : m_edges[u]) {
                if (v == p) { continue; }
                dfs(v, u);
                ss[u] += ss[v];
            }
        })(root, -1);
        return ss;
    }
    Vec<T> depths(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ds(N, 0);
        Fix([&](auto dfs, int u, int p) -> void {
            for ([[maybe_unused]] const auto& [_temp_name_1, v, c] : m_edges[u]) {
                if (v == p) { continue; }
                ds[v] = ds[u] + c;
                dfs(v, u);
            }
        })(root, -1);
        return ds;
    }
    Vec<int> parents(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<int> ps(N, -1);
        Fix([&](auto dfs, int u, int p) -> void {
            for ([[maybe_unused]] const auto& [_temp_name_2, v, c] : m_edges[u]) {
                if (v == p) { continue; }
                ps[v] = u;
                dfs(v, u);
            }
        })(root, -1);
        return ps;
    }
private:
    int m_v;
    int m_e = 0;
    Vec<Vec<Edge>> m_edges;
};
class LevelAncestor
{
public:
    template<typename T>
    LevelAncestor(const Graph<T>& g, int r = 0)
        : m_v(g.v()), m_ds(m_v, 0), m_ps(m_v)
    {
        Fix([&](auto dfs, int u, int p) -> void {
            for (int k = 1; (1 << k) <= m_ds[u]; k++) {
                m_ps[u].push_back(m_ps[m_ps[u][k - 1]][k - 1]);
            }
            for (int v : g[u]) {
                if (v == p) { continue; }
                m_ds[v] = m_ds[u] + 1;
                m_ps[v].push_back(u);
                dfs(v, u);
            }
        })(r, -1);
    };
    int lca(int u, int v) const
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        if (m_ds[u] > m_ds[v]) { std::swap(u, v); }
        v = (*this)(v, m_ds[v] - m_ds[u]);
        if (u == v) { return u; }
        while (true) {
            if (m_ps[u][0] == m_ps[v][0]) { return m_ps[u][0]; }
            for (int i = m_ps[u].size() - 1; i >= 0; i--) {
                const int nu = m_ps[u][i], nv = m_ps[v][i];
                if (nu != nv) {
                    u = nu, v = nv;
                    break;
                }
            }
        }
    }
    int operator()(int v, int d) const
    {
        assert(0 <= v and v < m_v);
        for (int k = (int)log2p1(d); k >= 0; k--) {
            if (btest(d, k)) { v = m_ps[v][k]; }
        }
        return v;
    }
private:
    int m_v;
    Vec<int> m_ds;
    Vec<Vec<int>> m_ps;
};
class DisjointSetUnion
{
public:
    DisjointSetUnion(int n) : m_v{n}, m_roots{iotaVec(n)}, m_sizes(m_v, 1) {}
    int leader(int i)
    {
        if (m_roots[i] == i) {
            return i;
        } else {
            return m_roots[i] = leader(m_roots[i]);
        }
    }
    bool merge(int i, int j)
    {
        i = leader(i), j = leader(j);
        if (i == j) { return false; }
        if (size(i) > size(j)) { std::swap(i, j); }
        m_roots[i] = j;
        m_sizes[j] += m_sizes[i];
        return true;
    }
    bool same(int i, int j)
    {
        return leader(i) == leader(j);
    }
    int size(int i)
    {
        return m_sizes[leader(i)];
    }
    Vec<Vec<int>> groups()
    {
        Vec<Vec<int>> iss(m_v);
        for (const int i : rep(m_v)) {
            iss[leader(i)].push_back(i);
        }
        return iss;
    }
private:
    int m_v;
    Vec<int> m_roots;
    Vec<int> m_sizes;
};
int main()
{
    const auto [N, M] = in.tup<int, int>();
    Graph g(N);
    DisjointSetUnion dsu(N);
    Vec<int> us(M), vs(M);
    Vec<int> es;
    for (int i : rep(M)) {
        const auto [u, v] = in.tup<int, int>(1, 1);
        us[i] = u, vs[i] = v;
        if (dsu.same(u, v)) {
            es.push_back(i);
        } else {
            dsu.merge(u, v);
            g.addEdge(u, v, true);
        }
    }
    const auto ds = g.depths();
    const auto la = LevelAncestor(g);
    Vec<int> imos(N, 0);
    for (int i : es) {
        auto u = us[i], v = vs[i];
        const int l = la.lca(u, v);
        if (l == u or l == v) {
            if (ds[u] < ds[v]) { std::swap(u, v); }
            const int D = ds[u] - ds[v];
            const int w = D == 1 ? u : la(u, D - 1);
            imos[0]++;
            imos[u]++;
            imos[w]--;
        } else {
            imos[u]++;
            imos[v]++;
        }
    }
    Fix([&](auto dfs, int u, int p) -> void {
        for (int v : g[u]) {
            if (v == p) { continue; }
            imos[v] += imos[u];
            dfs(v, u);
        }
    })(0, -1);
    Str ans(N, '0');
    for (int i : rep(N)) {
        if (imos[i] == (int)es.size()) { ans[i] = '1'; }
    }
    out.ln(ans);
    return 0;
}

 								 		   		 	    		   			