


















using ld = long double;
using ll = long long;
using ull = unsigned long long;
std::mt19937 mt{std::random_device{}()};
template <typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
template <typename T>
constexpr T MOD = static_cast<T>(1000000007);
template <typename F>
constexpr F PI() { return 3.1415926535897932385; }

struct has_debugPrint_impl
{
    template <class T>
    static auto check(T&& x) -> decltype(x.debugPrint(), std::true_type{});
    template <class T>
    static auto check(...) -> std::false_type;
};
template <class T>
class has_debugPrint : public decltype(has_debugPrint_impl::check<T>(std::declval<T>()))
{
};
template <bool>
struct HogeHogeDump
{
    template <typename T>
    static void dump(const T& x) { x.debugPrint(); }
};
template <>
struct HogeHogeDump<false>
{
    template <typename T>
    static void dump(const T& x) { std::cerr << x; }
};
void id2() { ; }
template <typename T>
void id2(const T& x) { HogeHogeDump<has_debugPrint<T>::value>::dump(x); }
template <typename T, typename... Args>
void id2(const T& x, Args... args) { HogeHogeDump<has_debugPrint<T>::value>::dump(x), std::cerr << ",", id2(args...); }
template <typename T>
bool chmin(T& a, const T& b) { return a = std::min(a, b), a == b; }
template <typename T>
bool chmax(T& a, const T& b) { return a = std::max(a, b), a == b; }
template <typename T, typename F>
void For(const T s, const T t, const F f)
{
    for (T i = s; i != t; i += T(s < t ? 1 : -1)) { f(i); }
}
template <typename T, typename F>
void Rep(const T N, const F f) { For<T, F>(0, N, f); }
template <typename T, typename F>
void RRep(const T N, const F f) { For<T, F>(N - 1, -1, f); }
template <typename T>
std::vector<T> Vec(const std::size_t n, T v) { return std::vector<T>(n, v); }
template <class... Args>
auto Vec(const std::size_t n, Args... args) { return std::vector<decltype(Vec(args...))>(n, Vec(args...)); }
template <typename T>
constexpr T PopCount(const T u)
{
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = (v & 0x5555555555555555ULL) + (v >> 1 & 0x5555555555555555ULL), v = (v & 0x3333333333333333ULL) + (v >> 2 & 0x3333333333333333ULL), v = (v + (v >> 4)) & 0x0F0F0F0F0F0F0F0FULL, static_cast<T>(v * 0x0101010101010101ULL >> 56 & 0x7f);
}
template <typename T>
constexpr T id0(const T u)
{
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = static_cast<unsigned long long>(v), v |= (v >> 1), v |= (v >> 2), v |= (v >> 4), v |= (v >> 8), v |= (v >> 16), v |= (v >> 32), PopCount(v);
}
template <typename T>
constexpr bool id4(const T v) { return (v << 1) == (T(1) << (id0(v))); }
template <typename T>
constexpr T ceil2(const T v) { return id4(v) ? v : T(1) << id0(v); }
template <typename T>
constexpr T floor2(const T v) { return v == 0 ? T(0) : id4(v) ? v : T(1) << (id0(v) - 1); }
template <typename T>
struct Accum
{
    template <typename InIt>
    Accum(const InIt first, const InIt last) : accum(std::size_t(std::distance(first, last))) { std::partial_sum(first, last, accum.begin()); }
    T sum(const std::size_t i) const { return i == 0 ? T(0) : accum[i - 1]; }
    T sum(const std::size_t l, const std::size_t r) const { return sum(r) - sum(l); }
    std::vector<T> accum;
};
template <typename T>
struct id3
{
    id3(const std::vector<std::vector<T>>& t) : accum{t}
    {
        for (std::size_t i = 0; i < accum.size(); i++) {
            for (std::size_t j = 1; j < accum[i].size(); j++) { accum[i][j] += accum[i][j - 1]; }
        }
        for (std::size_t i = 1; i < accum.size(); i++) {
            for (std::size_t j = 0; j < accum[i].size(); j++) { accum[i][j] += accum[i - 1][j]; }
        }
    }
    T sum(const std::size_t y, const std::size_t x) const { return y == 0 or x == 0 ? T(0) : accum[y - 1][x - 1]; }
    T sum(const std::size_t ymin, const std::size_t ysup, const std::size_t xmin, const std::size_t xsup) const { return sum(ysup, xsup) - sum(ymin, xmin); }
    std::vector<std::vector<T>> accum;
};
template <typename T>
struct Zip
{
    template <typename InIt>
    Zip(const InIt first, const InIt last) : unzip(std::size_t(std::distance(first, last)))
    {
        std::copy(first, last, unzip), std::sort(unzip.begin(), unzip.end()), unzip.erase(std::unique(unzip.begin(), unzip.end()), unzip.end());
        for (std::size_t i = 0; i < unzip.size(); i++) { zip[unzip[i]] = i; }
    }
    std::vector<T> unzip;
    std::map<T, std::size_t> zip;
};
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename T, typename A>
std::ostream& operator<<(std::ostream& os, const std::deque<T, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename K, typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::multimap<K, T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::multiset<T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename K, typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::map<K, T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& v) { return (os << "<" << v.first << "," << v.second << ">"); }
template <typename T1, typename T2, typename T3>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<T1, T2, T3>& v)
{
    auto q = v;
    os << "[";
    while (not q.empty()) { os << q.top() << ",", q.pop(); }
    return os << "]\n";
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::queue<T1>& v)
{
    auto q = v;
    os << "[";
    while (not q.empty()) { os << q.front() << ",", q.pop(); }
    return os << "]\n";
}
template <typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::set<T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::stack<T1>& v)
{
    auto q = v;
    os << "[";
    while (not q.empty()) { os << q.top() << ",", q.pop(); }
    return os << "]\n";
}
template <typename K, typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<K, T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename K, typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename T, typename A>
std::ostream& operator<<(std::ostream& os, const std::vector<T, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}




















struct Graph
{
    Graph(const std::size_t v) : V{v}, edge(v), rev_edge(v) {}
    void addEdge(const std::size_t from, const std::size_t to) { edge[from].push_back(to), rev_edge[to].push_back(from); }
    const std::vector<std::size_t>& operator[](const std::size_t i) const { return edge[i]; }
    void debugPrint() const
    {
        std::cerr << "[\n";
        for (std::size_t i = 0; i < V; i++) {
            for (const std::size_t to : edge[i]) { std::cerr << i << "->" << to << "\n"; }
        }
        std::cerr << "]\n";
    }
    const std::size_t V;
    std::vector<std::vector<std::size_t>> edge, rev_edge;
};
















class Centroid
{
public:
    Centroid(const Graph& g) : centros(g.V)
    {
        const std::size_t N = g.V;
        std::vector<std::size_t> sub(N, 1);
        std::vector<bool> used(N, false);
        auto size = [&](auto&& self, const std::size_t s, const std::size_t p) -> std::size_t {
            sub[s] = 1;
            for (const std::size_t to : g.edge[s]) {
                if (to == p or used[to]) { continue; }
                sub[s] += self(self, to, s);
            }
            return sub[s];
        };
        auto search = [&](auto&& self, const std::size_t s, const std::size_t p, const std::size_t tot) -> std::size_t {
            for (const std::size_t to : g[s]) {
                if (p == to or used[to]) { continue; }
                if (sub[to] * 2 > tot) { return self(self, to, s, tot); }
            }
            return s;
        };
        auto build = [&](auto&& self, const std::size_t s, const std::size_t pc) -> std::size_t {
            const std::size_t tot = size(size, s, N), c = search(search, s, N, tot);
            used[c] = true;
            if (pc != N) { centros.addEdge(pc, c); }
            for (const std::size_t to : g[c]) {
                if (not used[to]) { self(self, to, c); }
            }
            return c;
        };
        build(build, 0, N);
    }
    const Graph& getCentros() const { return centros; }

private:
    Graph centros;
};




















template <typename Base>
class SparseTable
{
public:
    using T = typename Base::T;
    using SemiLattice = Base;
    template <typename InIt>
    SparseTable(const InIt first, const InIt last) : size(std::distance(first, last)), lg2(size + 1, 0)
    {
        std::vector<T> val{first, last};
        for (std::size_t i = 2; i <= size; i++) { lg2[i] = lg2[i / 2] + 1; }
        table.resize(size, std::vector<T>(lg2[size] + 1));
        for (std::size_t i = 0; i < size; i++) { table[i][0] = val[i]; }
        for (std::size_t j = 0; j < lg2[size]; j++) {
            for (std::size_t i = 0, w = 1 << j; i <= size - (w << 1); i++) { table[i][j + 1] = op(table[i][j], table[i + w][j]); }
        }
    }
    T accumulate(const std::size_t l, const std::size_t r) const
    {
        const std::size_t j = lg2[r - l];
        return op(table[l][j], table[r - (1 << j)][j]);
    }

private:
    const std::size_t size;
    std::vector<std::size_t> lg2;
    std::vector<std::vector<T>> table;
    const SemiLattice op{};
};
















template <typename Type, std::size_t L = 12>
class id1
{
public:
    template <typename InIt>
    id1(const InIt first, const InIt last) : N{std::size_t(std::distance(first, last))}, M{(N + L - 1) / L}, v(N), blocks(M), masks(N, 0)
    {
        for (std::size_t i = 0; i < (1 << L); i++) {
            for (std::size_t j = 0; j < L; j++) {
                if (i & (1 << j)) {
                    LSB[i] = j;
                    break;
                }
            }
        }
        std::copy(first, last, v.begin());
        for (std::size_t i = 0; i < N; i++) { blocks[i / L] = i % L == 0 ? v[i] : std::min(blocks[i / L], v[i]); }
        for (std::size_t i = 0; i < M; i++) {
            std::vector<std::size_t> g(L, N);
            std::stack<std::size_t> stack;
            for (std::size_t j = 0; j < L and i * L + j < N; j++) {
                for (; not stack.empty() and v[stack.top()] >= v[i * L + j]; stack.pop()) {}
                g[j] = stack.empty() ? N : stack.top(), stack.push(i * L + j);
            }
            for (std::size_t j = 0; j < L and i * L + j < N; j++) { masks[i * L + j] = g[j] == N ? 0 : (masks[g[j]] | 1 << (g[j] - i * L)); }
        }
    }
    Type accumulate(const std::size_t l, const std::size_t r) const
    {
        static const SparseTable<Min> stable(blocks.begin(), blocks.end());
        const std::size_t LB = (l + L - 1) / L, RB = r / L;
        using P = std::pair<bool, Type>;
        P ans{true, Type{}};
        return LB > RB ? internal(l, r) : std::min({P{LB >= RB, LB >= RB ? Type{} : stable.accumulate(LB, RB)}, P{l >= L * LB, l >= L * LB ? Type{} : internal(l, L * LB)}, P{L * RB >= r, L * RB >= r ? Type{} : internal(L * RB, r)}}).second;
    }

private:
    struct Min
    {
        using T = Type;
        T operator()(const T& a, const T& b) const { return std::min(a, b); }
    };
    Type internal(const std::size_t l, std::size_t r) const
    {
        r--;
        const std::size_t w = masks[r] >> (l % L);
        return w == 0 ? v[r] : v[l + LSB[w]];
    }
    const std::size_t N, M;
    std::vector<Type> v, blocks;
    std::vector<std::size_t> masks;
    std::size_t LSB[1 << L];
};
















template <typename X = ll>
struct Min
{
    using T = X;
    T operator()(const T& a, const T& b) const { return std::min(a, b); }
    static constexpr T id() { return INF<T>; }
};
















class LCA
{
public:
    LCA(const Graph& g, const std::size_t root = 0) : left(g.V, 0)
    {
        std::vector<bool> used(g.V, false);
        auto dfs = [&](auto&& self, const std::pair<std::size_t, std::size_t>& s) -> void {
            const std::size_t pos = s.second;
            used[pos] = true, left[pos] = depth.size(), depth.push_back(s);
            for (const std::size_t to : g.edge[pos]) {
                if (used[to]) { continue; }
                self(self, {s.first + 1, to}), depth.push_back(s);
            }
        };
        dfs(dfs, {0, root});
    }
    std::size_t getLCA(const std::size_t u, const std::size_t v) const
    {
        static const id1<std::pair<std::size_t, std::size_t>, 20> st{depth.begin(), depth.end()};
        const std::size_t ul = left[u], vl = left[v];
        return st.accumulate(std::min(ul, vl), std::max(ul, vl) + 1).second;
    }

private:
    std::vector<std::size_t> left;
    std::vector<std::pair<std::size_t, std::size_t>> depth;
};
















int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    Graph g(N);
    for (int i = 0, u, v; i < N - 1; i++) { std::cin >> u >> v, u--, v--, g.addEdge(u, v), g.addEdge(v, u); }
    std::vector<std::size_t> depth(N, 0);
    auto dfs = [&](auto&& self, const std::size_t s, const std::size_t p) -> void {
        depth[s] = p == N ? 0 : depth[p] + 1;
        for (const std::size_t to : g[s]) {
            if (to == p) { continue; }
            self(self, to, s);
        }
    };
    dfs(dfs, 0, N);
    const LCA lca(g);
    auto dis = [&](const std::size_t u, const std::size_t v) { return depth[u] + depth[v] - 2 * depth[lca.getLCA(u, v)]; };
    const Centroid cen(g);
    const auto& cg = cen.getCentros();
    std::vector<std::size_t> prev(N, N);
    std::vector<std::size_t> ans(N, N);
    auto paint = [&](const std::size_t v) {
        for (std::size_t p = v;; p = cg.rev_edge[p].back()) {
            chmin(ans[p], dis(v, p));
            if (cg.rev_edge[p].empty()) { break; }
        }
    };
    auto query = [&](const std::size_t v) {
        std::size_t min = N;
        for (std::size_t p = v;; p = cg.rev_edge[p].back()) {
            chmin(min, ans[p] + dis(v, p));
            if (cg.rev_edge[p].empty()) { break; }
        }
        return min;
    };
    paint(0);
    for (int q = 0, t, v; q < Q; q++) {
        std::cin >> t >> v, v--;
        if (t == 1) {
            paint(v);
        } else {
            std::cout << query(v) << "\n";
        }
    };
    return 0;
}
