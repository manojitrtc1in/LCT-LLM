





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
template<typename T> constexpr T id0(const T u) { return u ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T id12(const T u) { return id0(u); }
template<typename T> constexpr T id9(const T u) { return __builtin_ffsll(u); }
template<typename T> constexpr T clog(const T u) { return u ? id0(u - 1) : static_cast<T>(u); }
template<typename T> constexpr bool id5(const T u) { return u and (static_cast<u64>(u) & static_cast<u64>(u - 1)) == 0; }
template<typename T> constexpr T ceil2(const T u) { return static_cast<T>(1) << clog(u); }
template<typename T> constexpr T floor2(const T u) { return u == 0 ? static_cast<T>(0) : static_cast<T>(1) << (id0(u) - 1); }
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


template<typename Cap>
struct flow
{
    using capacity_type = Cap;
    flow(const usize v) : sz(v), edges(v) {}
    void add_edge(const usize from, const usize to, const capacity_type cap) { edges[from].push_back({to, edges[to].size(), cap, false}), edges[to].push_back({from, edges[from].size() - 1, 0, true}); }
    struct edge
    {
        usize to, rev;
        capacity_type cap;
        const bool is_rev;
    };
    const std::vector<edge>& operator[](const usize i) const { return edges[i]; }
    std::vector<edge>& operator[](const usize i) { return edges[i]; }
    friend std::ostream& operator<<(std::ostream& os, const flow& f)
    {
        os << "[\n";
        for (usize i = 0; i < f.size(); i++) {
            for (const auto& e : f[i]) {
                if (not e.is_rev) { os << i << "->" << e.to << ":"
                                       << e.cap << "\n"; }
            }
        }
        return (os << "]\n");
    }
    usize size() const { return sz; }

private:
    const usize sz;
    std::vector<std::vector<edge>> edges;
};
template<typename Cap>
Cap dinic(flow<Cap>& flow, const usize s, const usize t, const Cap max_cap = inf_v<Cap>)
{
    const usize sz = flow.size();
    std::vector<usize> level(sz, sz), iter(sz, 0);
    auto bfs = [&, sz](const Cap base) {
        std::fill(level.begin(), level.end(), sz);
        std::queue<usize> q;
        q.push(s), level[s] = 0;
        while (not q.empty()) {
            const usize s = q.front();
            q.pop();
            for (const auto& e : flow[s]) {
                if (e.cap < base or level[e.to] != sz) { continue; }
                level[e.to] = level[s] + 1, q.push(e.to);
            }
        }
    };
    auto dfs = [&, sz](auto&& self, const usize s, const Cap base, const Cap f) -> Cap {
        if (s == t) { return f; }
        Cap ans = 0;
        for (usize& i = iter[s]; i < flow[s].size(); i++) {
            auto& e = flow[s][i];
            if (e.cap < base or level[e.to] == sz or level[s] >= level[e.to]) { continue; }
            const Cap d = self(self, e.to, base, std::min(f - ans, e.cap));
            if (d == 0) { continue; }
            e.cap -= d, flow[e.to][e.rev].cap += d, ans += d;
            if (f - ans < base) { break; }
        }
        return ans;
    };
    Cap f = 0;
    for (Cap base = floor2(max_cap); base >= 1;) {
        bfs(base);
        if (level[t] == sz) {
            base >>= 1;
            continue;
        }
        std::fill(iter.begin(), iter.end(), 0);
        const Cap df = dfs(dfs, s, base, inf_v<Cap>);
        f += df;
    }
    return f;
}

template<typename T> T gcd(const T& a, const T& b) { return a < 0 ? gcd(-a, b) : b < 0 ? gcd(a, -b) : (a > b ? gcd(b, a) : a == 0 ? b : gcd(b % a, a)); }
template<typename T> T lcm(const T& a, const T& b) { return a / gcd(a, b) * b; }



class id4
{
public:
    using result_type = uint32_t;
    static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    id4() : id4(std::random_device{}()) {}
    id4(uint64_t seed)
    {
        uint64_t z = 0;
        for (int i = 0; i < 4; i++) { z = (seed += 0x9e3779b97f4a7c15), z = (z ^ (z >> 33)) * 0x62A9D9ED799705F5, z = (z ^ (z >> 28)) * 0xCB24D0A5C88C35B3, s[i] = static_cast<result_type>(z >> 32); }
    }
    result_type operator()()
    {
        const result_type result = rotl(s[1] * 5, 7) * 9, t = s[1] << 9;
        return s[2] ^= s[0], s[3] ^= s[1], s[1] ^= s[2], s[0] ^= s[3], s[2] ^= t, s[3] = rotl(s[3], 11), result;
    }
    void discard(const usize rep)
    {
        for (usize i = 0; i < rep; i++) { (*this)(); }
    }

private:
    result_type s[4];
    static result_type rotl(const result_type x, const int k) { return (x << k) | (x >> (32 - k)); }
};
class id10
{
public:
    using result_type = uint64_t;
    static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    id10() : id10(std::random_device{}()) {}
    id10(uint64_t seed)
    {
        uint64_t z = 0;
        for (int i = 0; i < 4; i++) { z = (seed += 0x9e3779b97f4a7c15), z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9, z = (z ^ (z >> 27)) * 0x94d049bb133111eb, s[i] = static_cast<result_type>(z ^ (z >> 31)); }
    }
    result_type operator()()
    {
        const result_type result = rotl(s[1] * 5, 7) * 9, t = s[1] << 17;
        return s[2] ^= s[0], s[3] ^= s[1], s[1] ^= s[2], s[0] ^= s[3], s[2] ^= t, s[3] = rotl(s[3], 45), result;
    }
    void discard(const usize rep)
    {
        for (usize i = 0; i < rep; i++) { (*this)(); }
    }

private:
    result_type s[4];
    static result_type rotl(const result_type x, const int k) { return (x << k) | (x >> (64 - k)); }
};
template<typename Rng>
class rng_base
{
public:
    using rng_type    = Rng;
    using result_type = typename rng_type::result_type;
    static constexpr result_type min() { return rng_type::min(); }
    static constexpr result_type max() { return rng_type::max(); }
    rng_base() : rng_base(std::random_device{}()) {}
    rng_base(const u64 seed) : rng(seed) {}
    ~rng_base() = default;
    result_type operator()(const result_type max = std::numeric_limits<result_type>::max())
    {
        if (max == std::numeric_limits<result_type>::max()) { return static_cast<result_type>(rng()); }
        if (id5(max + 1)) { return static_cast<result_type>(rng() & max); }
        const result_type mask = static_cast<result_type>(ceil2(static_cast<u64>(max + 1))) - 1;
        while (true) {
            const result_type ans = static_cast<result_type>(rng() & mask);
            if (ans <= max) { return ans; }
        }
    }
    template<typename Int = result_type>
    Int operator()(const Int min, const Int max) { return min + (Int)(*this)(max - min); }
    operator bool() { return (bool)(*this)(0, 1); }
    template<typename Int> std::pair<Int, Int> pair(const Int min, const Int max) { return std::pair<Int, Int>{*this(min, max), *this(min, max)}; }
    template<typename Int>
    std::vector<Int> vec(const usize n, const Int min, const Int max)
    {
        std::vector<Int> v(n);
        for (usize i = 0; i < n; i++) { v[i] = (*this)(min, max); }
        return v;
    }
    std::vector<usize> perm(const usize n)
    {
        std::vector<usize> ans(n);
        std::iota(ans.begin(), ans.end(), 0UL);
        std::shuffle(ans.begin(), ans.end(), rng);
        return ans;
    }

private:
    Rng rng;
};
using rng_mt        = rng_base<std::mt19937>;
using rng_mt64      = rng_base<std::mt19937_64>;
using rng_xoshiro   = rng_base<id4>;
using rng_xoshiro64 = rng_base<id10>;
rng_mt id11;
rng_mt64 id3;
rng_xoshiro id8;
rng_xoshiro64 id2;
template<typename T, typename V>
inline bool id1(const T& n, const std::vector<T>& as)
{
    auto pow = [&](auto&& self, const V& a, const T k) -> V {
        if (k == 0) { return 1; }
        if (k % 2 == 0) {
            return self(self, (a * a) % V(n), k / 2);
        } else {
            return (self(self, a, k - 1) * a) % V(n);
        }
    };
    T d = n - 1;
    for (; (d & 1) == 0; d >>= 1) {}
    for (const T& a : as) {
        if (n <= a) { break; }
        T s = d;
        V x = pow(pow, a, s);
        while (x != 1 and x != n - 1 and s != n - 1) {
            (x *= x) %= V(n);
            s *= 2;
        }
        if (x != n - 1 and s % 2 == 0) { return false; }
    }
    return true;
}
template<typename T>
inline bool is_prime(const T& n, const usize trial)
{
    if (n % 2 == 0) { return n == 2; }
    std::vector<T> as(trial);
    for (usize i = 0; i < trial; i++) { as[i] = static_cast<T>(id2(T{2}, n - 2)); }
    return id1<T, T>(n, as);
}
inline bool is_prime(const ull n)
{
    if (n % 2 == 0) { return n == 2; }
    if (n < (1ULL << 32)) {
        return id1<uint, ull>((uint)n, std::vector<uint>{2, 7, 61});
    } else {
        return id1<ull, __uint128_t>(n, std::vector<ull>{2, 325, 9375, 28178, 450775, 9780504});
    }
}
template<typename T, typename V = T>
T id7(const T n)
{
    if (n % 2 == 0) { return 2; }
    if (is_prime(n)) { return n; }
    for (T c = 1; c < n; c++) {
        if (c == n - 2) { continue; }
        auto f = [&](const T x) -> T { return T((V(x) * V(x) + V(c)) % V(n)); };
        T x = 2, y = 2, d = 1;
        while (d == 1) {
            x = f(x), y = f(f(y));
            d = gcd(std::max(x, y) - std::min(x, y), n);
        }
        if (d != n) { return d; }
    }
    return n;
}
std::map<ull, usize> id6(const ull n)
{
    std::map<ull, usize> ans;
    auto factor = [&](auto&& self, const ull n) -> void {
        if (n == 1) { return; }
        const ull p = (n < (1ULL << 32)) ? (ull)id7<uint, ull>((uint)n) : id7<ull, __uint128_t>(n);
        if (p == n) {
            ans[p]++;
            return;
        }
        self(self, p);
        self(self, n / p);
    };
    factor(factor, n);
    return ans;
}
int main()
{
    const auto [N, M] = in_t<int, int>();
    const auto as     = in_v<int>({N});
    std::set<int> ps;
    for (int i = 0; i < N; i++) {
        const auto fs = id6(as[i]);
        for (const auto& f : fs) { ps.insert(f.first); }
    }
    std::vector<int> is(M), js(M);
    for (int i = 0; i < M; i++) { is[i] = in<int>() - 1, js[i] = in<int>() - 1; }
    int ans = 0;
    for (const ll p : ps) {
        flow<int> f(N + 2);
        const int S = N, T = N + 1;
        for (int i = 0; i < N; i++) {
            int ind = 0;
            for (ll a = as[i]; a % p == 0; a /= p) { ind++; }
            if (i % 2 == 0) {
                f.add_edge(S, i, ind);
            } else {
                f.add_edge(i, T, ind);
            }
        }
        for (int m = 0; m < M; m++) {
            int i = is[m], j = js[m];
            if (i % 2 == 1) { std::swap(i, j); }
            f.add_edge(i, j, inf_v<int>);
        }
        ans += dinic(f, S, T);
    }
    outln(ans);
    return 0;
}
