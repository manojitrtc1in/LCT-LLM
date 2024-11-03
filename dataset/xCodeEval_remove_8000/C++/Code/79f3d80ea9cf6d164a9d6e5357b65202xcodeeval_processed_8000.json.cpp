










namespace suisen {


template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}



template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;



template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool id5 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long int> { using type = __uint128_t; };
template <>
struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

template <typename T, typename = void>
struct rec_value_type {
    using type = T;
};
template <typename T>
struct rec_value_type<T, std::void_t<typename T::value_type>> {
    using type = typename rec_value_type<typename T::value_type>::type;
};
template <typename T>
using rec_value_type_t = typename rec_value_type<T>::type;

} 




using i128 = __int128_t;
using u128 = __uint128_t;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;
































template <class T, class... Args>
void debug_internal(const char* s, T&& first, Args&&... args) {
    constexpr const char* prefix = "[\033[32mDEBUG\033[m] ";
    constexpr const char* open_brakets = sizeof...(args) == 0 ? "" : "(";
    constexpr const char* close_brakets = sizeof...(args) == 0 ? "" : ")";
    std::cerr << prefix << open_brakets << s << close_brakets << ": " << open_brakets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brakets << "\n";
}










std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}


std::ostream& operator<<(std::ostream& dest, __uint128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[value % 10];
            value /= 10;
        } while (value != 0);
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}



template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& a) {
    return out << a.first << ' ' << a.second;
}


template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return out;
    } else {
        out << std::get<N>(a);
        if constexpr (N + 1 < std::tuple_size_v<std::tuple<Args...>>) {
            out << ' ';
        }
        return operator<<<N + 1>(out, a);
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}


template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail &...tails) {
    std::cout << head;
    if (sizeof...(tails)) std::cout << ' ';
    print(tails...);
}
template <typename Iterable>
auto print_all(const Iterable& v, std::string sep = " ", std::string end = "\n") -> decltype(std::cout << *v.begin(), void()) {
    for (auto it = v.begin(); it != v.end();) {
        std::cout << *it;
        if (++it != v.end()) std::cout << sep;
    }
    std::cout << end;
}

__int128_t id21(std::string& s) {
    __int128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    if (s[0] == '-') ret = -ret;
    return ret;
}
__uint128_t id9(std::string& s) {
    __uint128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    return ret;
}


std::istream& operator>>(std::istream& in, __int128_t& v) {
    std::string s;
    in >> s;
    v = id21(s);
    return in;
}


std::istream& operator>>(std::istream& in, __uint128_t& v) {
    std::string s;
    in >> s;
    v = id9(s);
    return in;
}


template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& a) {
    return in >> a.first >> a.second;
}


template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...>& a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}


template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}


template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    (std::cin >> ... >> args);
}






template <typename T>
constexpr inline int id2(T n) {
    return -(n & 1) | 1;
}


template <>
constexpr inline int id2<bool>(bool n) {
    return -int(n) | 1;
}



template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + id2(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + id2(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u64(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id12(const T x) { return suisen::bit_num<T> -1 - id13(x); }
template <typename T>
constexpr inline int id16(const T x) { return id12(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id22(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id14(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable& iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}
template <typename T>
auto id4(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id4(T n) {
    return id4(0, n);
}

template <typename T>
void id18(std::vector<T>& a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto id0(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto id0(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()) {
    id0(c.begin(), c.end(), f);
}






template <typename T>
inline bool chmin(T& x, const T& y) {
    if (y >= x) return false;
    x = y;
    return true;
}


template <typename T>
inline bool chmax(T& x, const T& y) {
    if (y <= x) return false;
    x = y;
    return true;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::string bin(T val, int bit_num = -1) {
    std::string res;
    if (bit_num >= 0) {
        for (int bit = bit_num; bit-- > 0;) res += '0' + ((val >> bit) & 1);
    } else {
        for (; val; val >>= 1) res += '0' + (val & 1);
        std::reverse(res.begin(), res.end());
    }
    return res;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> id17(T val, T base = 10) {
    std::vector<T> res;
    for (; val; val /= base) res.push_back(val % base);
    if (res.empty()) res.push_back(T{ 0 });
    return res;
}
template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> id10(T val, T base = 10) {
    auto res = id17(val, base);
    std::reverse(res.begin(), res.end());
    return res;
}

template <typename T>
std::string join(const std::vector<T>& v, const std::string& sep, const std::string& end) {
    std::ostringstream ss;
    for (auto it = v.begin(); it != v.end();) {
        ss << *it;
        if (++it != v.end()) ss << sep;
    }
    ss << end;
    return ss.str();
}

namespace suisen {}
using namespace suisen;
using namespace std;

struct io_setup {
    io_setup(int precision = 20) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(precision);
    }
} id1{};








namespace atcoder {









struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    

    

    std::vector<int> parent_or_size;
};

}  


auto id3(const vector<vector<int>>& g, int u, int v) {
    vector<int> res;
    auto dfs = [&](auto dfs, int cur, int par) -> bool {
        res.push_back(cur);
        if (cur == v) return true;
        for (int nxt : g[cur]) if (nxt != par and dfs(dfs, nxt, cur)) return true;
        res.pop_back();
        return false;
    };
    dfs(dfs, u, -1);
    return res;
}

constexpr int inf = numeric_limits<int>::max() / 2;

vector<pair<int, int>> solve(vector<vector<int>> g) {
    const int n = g.size();

    set<pair<int, int>> edges_g;
    rep(i, n) for (int j : g[i]) edges_g.insert(minmax(i, j));

    vector dp(2, vector<int>(n, inf));
    vector<int> par(n, -1);
    auto dfs = [&](auto dfs, int u, int p) -> void {
        par[u] = p;

        const int d = g[u].size() & 1;

        vector<int> vs, ws;
        for (int v : g[u]) if (v != p) {
            dfs(dfs, v, u);
            vs.push_back(dp[0][v]);
            ws.push_back(dp[1][v]);
        }
        int l = vs.size();
        vector<int> psum(l + 1), ssum(l + 1);
        rep(i, l) psum[i + 1] = psum[i] + vs[i];
        rrep(i, l) ssum[i] = ssum[i + 1] + vs[i];

        rep(i, l) {
            chmin(dp[0][u], psum[i] + ssum[i + 1] + ws[i] + (d ^ 1));
        }
        chmin(dp[0][u], psum[l] + d);

        if (p >= 0) {
            chmin(dp[1][u], psum[l] + (d ^ 1));
        }
    };
    dfs(dfs, 0, -1);

    vector<int> col(n, 0);
    col[0] = -1;

    vector<int> ttt(n, -1);

    auto dfs2 = [&](auto dfs2, int u, int p, int state) -> void {
        const int d = g[u].size() & 1;

        vector<int> vs, ws;
        for (int v : g[u]) if (v != p) {
            vs.push_back(dp[0][v]);
            ws.push_back(dp[1][v]);
        }
        int l = vs.size();
        vector<int> psum(l + 1), ssum(l + 1);
        rep(i, l) psum[i + 1] = psum[i] + vs[i];
        rrep(i, l) ssum[i] = ssum[i + 1] + vs[i];

        if (state == 0) {
            bool found = false;
            int i = 0;
            for (int v : g[u]) if (v != p) {
                if (dp[0][u] == psum[i] + ssum[i + 1] + ws[i] + (d ^ 1)) {
                    col[v] = 1;

                    ttt[u] = v;
                    ttt[v] = u;

                    found = true;
                    break;
                }
                ++i;
            }
            if (not found) {
                assert(dp[0][u] == psum[l] + d);
            }
        } else {
            for (int v : g[u]) if (v != p) {
                col[v] = 0;
            }
        }
        for (int v : g[u]) if (v != p) {
            dfs2(dfs2, v, u, col[v]);
        }
    };
    dfs2(dfs2, 0, -1, dp[1][0] < dp[0][0]);

    vector<set<int>> edges(n);
    rep(i, n) if (col[i] == 0) {
        int p = par[i];
        assert(0 <= p and p < n);
        edges[i].insert(p);
        edges[p].insert(i);
    }
    set<int> st;
    rep(i, n) if (edges[i].size() == 1) {
        st.insert(i);
    }

    vector<pair<int, int>> ans;
    while (st.size()) {
        auto it = st.begin();
        int u = *it;
        st.erase(it);

        auto dfs = [&](auto dfs, int u) -> int {
            if (edges[u].size()) {
                auto it2 = edges[u].begin();
                int v = *it2;
                edges[u].erase(it2);
                edges[v].erase(u);
                if (edges[u].size() == 1) st.insert(u);
                return dfs(dfs, v);
            } else {
                return u;
            }
        };
        int v = dfs(dfs, u);
        st.erase(v);
        if (edges_g.count(minmax(u, v))) {
            bool ok = false;
            if (not ok) {
                int w = ttt[u];
                if (w >= 0) {
                    ok = true;
                    ans.emplace_back(v, w);
                }
            }
            if (not ok) {
                int w = ttt[v];
                if (w >= 0) {
                    ok = true;
                    ans.emplace_back(u, w);
                }
            }
            assert(ok);
        } else {
            ans.emplace_back(u, v);
        }
    }
    return ans;
}

namespace suisen {
class id8 {
    public:
        template <typename Q>
        using is_point_update_query = std::is_invocable<Q, int>;
        template <typename Q>
        using is_range_update_query = std::is_invocable<Q, int, int>;
        template <typename Q, typename T>
        using is_point_get_query  = std::is_same<std::invoke_result_t<Q, int>, T>;
        template <typename Q, typename T>
        using is_range_fold_query = std::is_same<std::invoke_result_t<Q, int, int>, T>;

        using Graph = std::vector<std::vector<int>>;

        id8() = default;
        id8(Graph &g) : n(g.size()), visit(n), leave(n), head(n), ord(n), siz(n), par(n, -1), dep(n, 0) {
            for (int i = 0; i < n; ++i) if (par[i] < 0) dfs(g, i, -1);
            int time = 0;
            for (int i = 0; i < n; ++i) if (par[i] < 0) hld(g, i, -1, time);
        }
        int size() const {
            return n;
        }
        int lca(int u, int v) const {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) return u;
            }
        }
        int la(int u, int k, int default_value = -1) const {
            if (k < 0) return default_value;
            while (u >= 0) {
                int h = head[u];
                if (visit[u] - k >= visit[h]) return ord[visit[u] - k];
                k -= visit[u] - visit[h] + 1;
                u = par[h];
            }
            return default_value;
        }
        int jump(int u, int v, int d, int default_value = -1) const {
            if (d < 0) return default_value;
            const int w = lca(u, v);
            int uw = dep[u] - dep[w];
            if (d <= uw) return la(u, d);
            int vw = dep[v] - dep[w];
            return d <= uw + vw ? la(v, (uw + vw) - d) : default_value;
        }
        int dist(int u, int v) const {
            return dep[u] + dep[v] - 2 * dep[lca(u, v)];
        }
        template <typename T, typename Q, typename F, constraints_t<is_range_fold_query<Q, T>, is_bin_op<F, T>> = nullptr>
        T fold_path(int u, int v, T identity, F bin_op, Q fold_query, bool id7 = false) const {
            T res = identity;
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                res = bin_op(fold_query(visit[head[v]], visit[v] + 1), res);
            }
            return bin_op(fold_query(visit[u] + id7, visit[v] + 1), res);
        }
        template <
            typename T, typename Q1, typename Q2, typename F,
            constraints_t<is_range_fold_query<Q1, T>, is_range_fold_query<Q2, T>, is_bin_op<F, T>> = nullptr
        >
        T id6(int u, int v, T identity, F bin_op, Q1 fold_query, Q2 id15, bool id7 = false) const {
            T res_u = identity, res_v = identity;
            

            

            while (head[u] != head[v]) {
                if (visit[u] < visit[v]) { 

                    res_v = bin_op(fold_query(visit[head[v]], visit[v] + 1), res_v);
                    v = par[head[v]];
                } else { 

                    res_u = bin_op(res_u, id15(visit[head[u]], visit[u] + 1));
                    u = par[head[u]];
                }
            }
            if (visit[u] < visit[v]) { 

                res_v = bin_op(fold_query(visit[u] + id7, visit[v] + 1), res_v);
            } else { 

                res_u = bin_op(res_u, id15(visit[v] + id7, visit[u] + 1));
            }
            return bin_op(res_u, res_v);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_path(int u, int v, Q update_query, bool id7 = false) const {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                update_query(visit[head[v]], visit[v] + 1);
            }
            update_query(visit[u] + id7, visit[v] + 1);
        }
        template <typename T, typename Q, constraints_t<is_range_fold_query<Q, T>> = nullptr>
        T id11(int u, Q fold_query, bool id7 = false) const {
            return fold_query(visit[u] + id7, leave[u]);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void id20(int u, Q update_query, bool id7 = false) const {
            update_query(visit[u] + id7, leave[u]);
        }
        template <typename T, typename Q, constraints_t<is_point_get_query<Q, T>> = nullptr>
        T get_point(int u, Q get_query) const {
            return get_query(visit[u]);
        }
        template <typename Q, constraints_t<is_point_update_query<Q>> = nullptr>
        void update_point(int u, Q update_query) const {
            update_query(visit[u]);
        }
        std::vector<int> inv_ids() const {
            std::vector<int> inv(n);
            for (int i = 0; i < n; ++i) inv[visit[i]] = i;
            return inv;
        }
        int get_visit_time(int u) const {
            return visit[u];
        }
        int get_leave_time(int u) const {
            return leave[u];
        }
        int get_head(int u) const {
            return head[u];
        }
        int get_kth_visited(int k) const {
            return ord[k];
        }
        int get_subtree_size(int u) const {
            return siz[u];
        }
        int get_parent(int u) const {
            return par[u];
        }
        int get_depth(int u) const {
            return dep[u];
        }
        std::vector<int> get_roots() const {
            std::vector<int> res;
            for (int i = 0; i < n; ++i) if (par[i] < 0) res.push_back(i);
            return res;
        }
    private:
        int n;
        std::vector<int> visit, leave, head, ord, siz, par, dep;
        int dfs(Graph &g, int u, int p) {
            par[u] = p;
            siz[u] = 1;
            int max_size = 0;
            for (int &v : g[u]) {
                if (v == p) continue;
                dep[v] = dep[u] + 1;
                siz[u] += dfs(g, v, u);
                if (max_size < siz[v]) {
                    max_size = siz[v];
                    std::swap(g[u].front(), v);
                }
            }
            return siz[u];
        }
        void hld(Graph &g, int u, int p, int &time) {
            visit[u] = time, ord[time] = u, ++time;
            head[u] = p >= 0 and g[p].front() == u ? head[p] : u;
            for (int v : g[u]) {
                if (v != p) hld(g, v, u, time);
            }
            leave[u] = time;
        }
};
} 


int main() {
    while (true) {
        input(int, n, num_path);
        if (n == 0 and num_path == 0) break;

        atcoder::dsu uf(n);
        vector<pair<int, int>> edges;

        set<pair<int, int>> st;
        vector<vector<int>> g0(n);
        loop(num_path) {
            input(int, k);
            vector<int> p(k);
            read(p);
            for (auto& e : p) --e;

            rep(i, k - 1) {
                int u = p[i], v = p[i + 1];
                debug(u, v);
                if (not uf.same(u, v)) {
                    uf.merge(u, v);
                    g0[u].push_back(v);
                    g0[v].push_back(u);
                    st.insert(minmax(u, v));
                } else {
                    edges.emplace_back(u, v);
                }
            }
        }

        id8 hld(g0);

        for (const auto& [u, v] : edges) {
            int prv = u;
            while (prv != v) {
                int nxt = hld.jump(prv, v, 1);
                st.erase(minmax(prv, nxt));
                prv = nxt;
            }
        }

        vector<vector<int>> g(n);
        for (const auto& [u, v] : st) {
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<pair<int, int>> ans;

        vector<int> ids(n);
        vector<int8_t> seen(n, false);
        rep(i, n) if (not seen[i]) {
            vector<int> id_inv;
            vector<vector<int>> sub;
            auto dfs = [&](auto dfs, int u, int p) -> void {
                seen[u] = true;
                int id = id_inv.size();
                id_inv.push_back(u);
                ids[u] = id;
                sub.emplace_back();
                for (int v : g[u]) if (v != p) {
                    dfs(dfs, v, u);
                    sub[ids[u]].push_back(ids[v]);
                    sub[ids[v]].push_back(ids[u]);
                }
            };
            dfs(dfs, i, -1);

            for (auto [u, v] : solve(sub)) {
                ans.emplace_back(id_inv[u] + 1, id_inv[v] + 1);
            }
        }

        print(ans.size());
        for (auto [u, v] : ans) {
            print(u, v);
        }
    }
    return 0;
}
