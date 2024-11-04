
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using f64 = double;
using f80 = long double;
using f128 = __float128;
constexpr i32 operator"" _i32(u64 v) { return v; }
constexpr u32 operator"" _u32(u64 v) { return v; }
constexpr i64 operator"" _i64(u64 v) { return v; }
constexpr u64 operator"" _u64(u64 v) { return v; }
constexpr f64 operator"" _f64(f80 v) { return v; }
constexpr f80 operator"" _f80(f80 v) { return v; }
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
constexpr bool LOCAL = false;
constexpr bool OJ = not LOCAL;
template<typename T>
static constexpr T OjLocal(T oj, T local)
{
    return LOCAL ? local : oj;
}
template<typename T>
constexpr T id12 = std::numeric_limits<T>::min();
template<typename T>
constexpr T id5 = std::numeric_limits<T>::max();
template<typename T>
constexpr T INF = (id5<T> - 1) / 2;
template<typename T>
constexpr T PI = T{3.141592653589793238462643383279502884};
template<typename T = u64>
constexpr T TEN(int n)
{
    return n == 0 ? T{1} : TEN<T>(n - 1) * T{10};
}
template<typename T>
constexpr Vec<T>& operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    return vs1.insert(vs1.end(), vs2.begin(), vs2.end()), vs1;
}
template<typename T>
constexpr Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    auto vs = vs1;
    vs += vs2;
    return vs;
}
template<typename T>
constexpr bool chmin(T& a, const T& b)
{
    return (a > b ? (a = b, true) : false);
}
template<typename T>
constexpr bool chmax(T& a, const T& b)
{
    return (a < b ? (a = b, true) : false);
}
template<typename T>
constexpr T floorDiv(T x, T y)
{
    assert(y != 0);
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T ceilDiv(T x, T y)
{
    assert(y != 0);
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? (x + y - 1) / y : x / y;
}
template<typename T, typename I>
constexpr T id8(T v, I n, const T& e)
{
    assert(n >= 0);
    T ans = e;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T powerInt(T v, I n)
{
    return id8(v, n, T{1});
}
template<typename Vs, typename V>
constexpr void fillAll(Vs& arr, const V& v)
{
    if constexpr (std::is_convertible<V, Vs>::value) {
        arr = v;
    } else {
        for (auto& subarr : arr) { fillAll(subarr, v); }
    }
}
template<typename Vs>
constexpr void sortAll(Vs& vs)
{
    std::sort(std::begin(vs), std::end(vs));
}
template<typename Vs, typename C>
constexpr void sortAll(Vs& vs, C comp)
{
    std::sort(std::begin(vs), std::end(vs), comp);
}
template<typename Vs>
constexpr void reverseAll(Vs& vs)
{
    std::reverse(std::begin(vs), std::end(vs));
}
template<typename V, typename Vs>
constexpr V sumAll(const Vs& vs)
{
    if constexpr (std::is_convertible<Vs, V>::value) {
        return static_cast<V>(vs);
    } else {
        V ans = 0;
        for (const auto& v : vs) { ans += sumAll<V>(v); }
        return ans;
    }
}
template<typename Vs>
constexpr int minInd(const Vs& vs)
{
    return std::min_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs>
constexpr int maxInd(const Vs& vs)
{
    return std::max_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs, typename V>
constexpr int lbInd(const Vs& vs, const V& v)
{
    return std::lower_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
constexpr int ubInd(const Vs& vs, const V& v)
{
    return std::upper_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
constexpr void plusAll(Vs& vs, const V& v)
{
    for (auto& v_ : vs) { v_ += v; }
}
template<typename T, typename F>
constexpr Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_insert_iterator(ans), n, gen);
    return ans;
}
template<typename T = int>
constexpr Vec<T> id6(int n, T offset = 0)
{
    Vec<T> ans(n);
    std::iota(ans.begin(), ans.end(), offset);
    return ans;
}
Ostream& operator<<(Ostream& os, i128 v)
{
    bool minus = false;
    if (v < 0) { minus = true, v = -v; }
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) { ans.push_back('0' + v % 10), v /= 10; }
    std::reverse(ans.begin(), ans.end());
    return os << (minus ? "-" : "") << ans;
}
Ostream& operator<<(Ostream& os, u128 v)
{
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) { ans.push_back('0' + v % 10), v /= 10; }
    std::reverse(ans.begin(), ans.end());
    return os << ans;
}
constexpr int popcount(u64 v) { return v ? __builtin_popcountll(v) : 0; }
constexpr int id2(u64 v) { return v ? 64 - __builtin_clzll(v) : 0; }
constexpr int id10(u64 v) { return __builtin_ffsll(v); }
constexpr int id3(u64 v) { return v ? id2(v - 1) : 0; }
constexpr u64 ceil2(u64 v)
{
    assert(v <= (1_u64 << 63));
    return 1_u64 << id3(v);
}
constexpr u64 floor2(u64 v) { return v ? (1_u64 << (id2(v) - 1)) : 0_u64; }
constexpr bool id7(u64 v) { return (v > 0) and ((v & (v - 1)) == 0); }
constexpr bool btest(u64 mask, int ind) { return (mask >> ind) & 1_u64; }
template<typename F>
struct Fix : F
{
    constexpr Fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args>
    constexpr auto operator()(Args&&... args) const
    {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
class irange
{
private:
    struct itr
    {
        constexpr itr(i64 start = 0, i64 step = 1) : m_cnt{start}, m_step{step} {}
        constexpr bool operator!=(const itr& it) const { return m_cnt != it.m_cnt; }
        constexpr i64 operator*() { return m_cnt; }
        constexpr itr& operator++() { return m_cnt += m_step, *this; }
        i64 m_cnt, m_step;
    };
    i64 m_start, m_end, m_step;
public:
    static constexpr i64 cnt(i64 start, i64 end, i64 step)
    {
        if (step == 0) { return -1; }
        const i64 d = (step > 0 ? step : -step);
        const i64 l = (step > 0 ? start : end);
        const i64 r = (step > 0 ? end : start);
        i64 n = (r - l) / d + ((r - l) % d ? 1 : 0);
        if (l >= r) { n = 0; }
        return n;
    }
    constexpr irange(i64 start, i64 end, i64 step = 1)
        : m_start{start}, m_end{m_start + step * cnt(start, end, step)}, m_step{step}
    {
        assert(step != 0);
    }
    constexpr itr begin() const { return itr{m_start, m_step}; }
    constexpr itr end() const { return itr{m_end, m_step}; }
};
constexpr irange rep(i64 end) { return irange(0, end, 1); }
constexpr irange per(i64 rend) { return irange(rend - 1, -1, -1); }
class Scanner
{
public:
    Scanner(Istream& is = std::cin) : m_is{is} { m_is.tie(nullptr)->sync_with_stdio(false); }
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
    Printer(Ostream& os = std::cout) : m_os{os} { m_os << std::fixed << std::setprecision(15); }
    template<typename... Args>
    int operator()(const Args&... args)
    {
        return dump(args...), 0;
    }
    template<typename... Args>
    int ln(const Args&... args)
    {
        return dump(args...), m_os << '\n', 0;
    }
    template<typename... Args>
    int el(const Args&... args)
    {
        return dump(args...), m_os << std::endl, 0;
    }
    int YES(bool b = true) { return ln(b ? "YES" : "NO"); }
    int NO(bool b = true) { return YES(not b); }
    int Yes(bool b = true) { return ln(b ? "Yes" : "No"); }
    int No(bool b = true) { return Yes(not b); }
private:
    template<typename T>
    void dump(const T& v)
    {
        m_os << v;
    }
    template<typename T>
    void dump(const Vec<T>& vs)
    {
        for (int i : rep(vs.size())) { m_os << (i ? " " : ""), dump(vs[i]); }
    }
    template<typename T>
    void dump(const Vec<Vec<T>>& vss)
    {
        for (int i : rep(vss.size())) { m_os << (i ? "\n" : ""), dump(vss[i]); }
    }
    template<typename T, typename... Ts>
    int dump(const T& v, const Ts&... args)
    {
        return dump(v), m_os << ' ', dump(args...), 0;
    }
    Ostream& m_os;
};
Printer out;
template<typename T, int n, int i = 0>
auto ndVec(int const (&szs)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(szs[i], ndVec<T, n, i + 1>(szs, x));
    }
}
template<typename T, typename F>
T binSearch(T ng, T ok, F check)
{
    while (std::abs(ok - ng) > 1) {
        const T mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    return ok;
}
template<u32 mod_, u32 root_, u32 id9>
class modint
{
    template<typename U = u32&>
    static U modRef()
    {
        static u32 s_mod = 0;
        return s_mod;
    }
    template<typename U = u32&>
    static U rootRef()
    {
        static u32 s_root = 0;
        return s_root;
    }
    template<typename U = u32&>
    static U id4()
    {
        static u32 id11 = 0;
        return id11;
    }
public:
    static constexpr bool isDynamic() { return (mod_ == 0); }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> mod()
    {
        return mod_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> mod()
    {
        return modRef();
    }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> root()
    {
        return root_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> root()
    {
        return rootRef();
    }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> id1()
    {
        return id9;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> id1()
    {
        return id4();
    }
    template<typename U = u32>
    static void setMod(std::enable_if_t<mod_ == 0, U> m)
    {
        modRef() = m;
    }
    template<typename U = u32>
    static void setRoot(std::enable_if_t<mod_ == 0, U> r)
    {
        rootRef() = r;
    }
    template<typename U = u32>
    static void id0(std::enable_if_t<mod_ == 0, U> m)
    {
        id4() = m;
    }
    constexpr modint() : m_val{0} {}
    constexpr modint(i64 v) : m_val{normll(v)} {}
    constexpr void setRaw(u32 v) { m_val = v; }
    constexpr modint operator-() const { return modint{0} - (*this); }
    constexpr modint& operator+=(const modint& m)
    {
        m_val = norm(m_val + m.val());
        return *this;
    }
    constexpr modint& operator-=(const modint& m)
    {
        m_val = norm(m_val + mod() - m.val());
        return *this;
    }
    constexpr modint& operator*=(const modint& m)
    {
        m_val = normll((i64)m_val * (i64)m.val() % (i64)mod());
        return *this;
    }
    constexpr modint& operator/=(const modint& m) { return *this *= m.inv(); }
    constexpr modint operator+(const modint& m) const
    {
        auto v = *this;
        return v += m;
    }
    constexpr modint operator-(const modint& m) const
    {
        auto v = *this;
        return v -= m;
    }
    constexpr modint operator*(const modint& m) const
    {
        auto v = *this;
        return v *= m;
    }
    constexpr modint operator/(const modint& m) const
    {
        auto v = *this;
        return v /= m;
    }
    constexpr bool operator==(const modint& m) const { return m_val == m.val(); }
    constexpr bool operator!=(const modint& m) const { return not(*this == m); }
    friend Istream& operator>>(Istream& is, modint& m)
    {
        i64 v;
        return is >> v, m = v, is;
    }
    friend Ostream& operator<<(Ostream& os, const modint& m) { return os << m.val(); }
    constexpr u32 val() const { return m_val; }
    template<typename I>
    constexpr modint pow(I n) const
    {
        return powerInt(*this, n);
    }
    constexpr modint inv() const { return pow(mod() - 2); }
    static modint sinv(u32 n)
    {
        static Vec<modint> is{1, 1};
        for (u32 i = (u32)is.size(); i <= n; i++) { is.push_back(-is[mod() % i] * (mod() / i)); }
        return is[n];
    }
    static modint fact(u32 n)
    {
        static Vec<modint> fs{1, 1};
        for (u32 i = (u32)fs.size(); i <= n; i++) { fs.push_back(fs.back() * i); }
        return fs[n];
    }
    static modint ifact(u32 n)
    {
        static Vec<modint> ifs{1, 1};
        for (u32 i = (u32)ifs.size(); i <= n; i++) { ifs.push_back(ifs.back() * sinv(i)); }
        return ifs[n];
    }
    static modint comb(int n, int k)
    {
        return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k) * ifact(k);
    }
private:
    static constexpr u32 norm(u32 x) { return x < mod() ? x : x - mod(); }
    static constexpr u32 normll(i64 x) { return norm(u32(x % (i64)mod() + (i64)mod())); }
    u32 m_val;
};
using modint_1000000007 = modint<1000000007, 5, 1>;
using modint_998244353 = modint<998244353, 3, 23>;
template<int id>
using modint_dynamic = modint<0, 0, id>;
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
        operator int() const { return to; }
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
    int v() const { return m_v; }
    int e() const { return m_e; }
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
template<typename T>
class id13
{
public:
    id13(const Vec<T>& vs) : m_size(vs.size()), m_cap{ceil2(m_size)}, m_vs(m_cap + 1, T{})
    {
        std::copy(vs.begin(), vs.end(), m_vs.begin() + 1);
        for (int x : irange(1, m_cap)) { m_vs[x + (x & -x)] += m_vs[x]; }
    }
    id13(int N, const T& v = T{}) : id13{Vec<T>(N, v)} {}
    void add(int i, const T& v)
    {
        assert(0 <= i and i < m_size);
        for (int ind = i + 1; ind <= m_cap; ind += ind & (-ind)) { m_vs[ind] += v; }
    }
    T sum(int i) const
    {
        assert(0 <= i and i <= m_size);
        T sum{};
        for (int ind = i; ind != 0; ind &= ind - 1) { sum += m_vs[ind]; }
        return sum;
    }
    T sum(int l, int r) const
    {
        assert(0 <= l and l <= r and r <= m_size);
        return sum(r) - sum(l);
    }
    template<typename F>
    int maxRight(F f)
    {
        assert(f(T{}));
        T sum = T{};
        int x = 0;
        for (int k = (m_cap >> 1); k >= 1; k >>= 1) {
            if (x + k <= m_size and f(sum + m_vs[x + k])) { sum += m_vs[x + k], x += k; }
        }
        return x;
    }
    friend Ostream& operator<<(Ostream& os, const id13& fw)
    {
        os << "[";
        for (int i : rep(fw.m_size)) { os << (i == 0 ? "" : ",") << fw.sum(i, i + 1); }
        return (os << "]\n");
    }
private:
    int m_size, m_cap;
    Vec<T> m_vs;
};
int main()
{
    const auto N = in.val<int>();
    const auto As = in.vec<i64>(N);
    if (N <= 2) {
        if (As[minInd(As)] < 0) {
            return out.ln(-1);
        } else {
            return out.ln(0);
        }
    }
    Vec<i64> Ss(N + 1, 0);
    for (int i : rep(N)) {
        Ss[i + 1] = Ss[i] + As[i];
    }
    for (int i : irange(1, N)) {
        if (Ss[i] < Ss[0]) { return out.ln(-1); }
        if (Ss[i] > Ss[N]) { return out.ln(-1); }
    }
    void(0);
    auto is = id6<int>(N - 1);
    sortAll(is, [&](int i, int j) {
        return Ss[i + 1] == Ss[j + 1] ? i < j : Ss[i + 1] < Ss[j + 1];
    });
    id13<i64> bit(N - 1);
    i64 ans = 0;
    for (int i : is) {
        ans += bit.sum(i, N - 1);
        bit.add(i, 1);
    }
    out.ln(ans);
    return 0;
}
