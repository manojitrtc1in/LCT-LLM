







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
static constexpr bool id4 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
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

} 




using i128 = __int128_t;
using u128 = __uint128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec <T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;


































template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U> &a) {
    return out << a.first << ' ' << a.second;
}


template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...> &a) {
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
std::ostream& operator<<(std::ostream& out, const std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}


template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head &head, const Tail &...tails) {
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



template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U> &a) {
    return in >> a.first >> a.second;
}


template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}


template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}


template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    ( std::cin >> ... >> args );
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
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id10(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id10(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id10(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id17(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id17(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id17(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id9(const T x) { return suisen::bit_num<T> - 1 - id10(x); }
template <typename T>
constexpr inline int id15(const T x)  { return id9(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id19(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id13 {
        const int s; int t;
        constexpr id13(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id13(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id12(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable &iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}
template <typename T>
auto id3(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id3(T n) {
    return id3(0, n);
}

template <typename T>
void id16(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto id0(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto id0(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()){
    id0(c.begin(), c.end(), f);
}






template <typename T>
inline bool chmin(T &x, const T &y) {
    if (y >= x) return false;
    x = y;
    return true;
}


template <typename T>
inline bool chmax(T &x, const T &y) {
    if (y <= x) return false;
    x = y;
    return true;
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
} id1 {};










namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  


}  


namespace atcoder {
namespace internal {







struct id11 {
  public:
    explicit id11(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  


}  


namespace atcoder {









struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::id11 scc;
};

}  


namespace suisen {
class id7 {
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

        id7() = default;
        id7(Graph &g) : n(g.size()), visit(n), leave(n), head(n), ord(n), siz(n), par(n, -1), dep(n, 0) {
            for (int i = 0; i < n; ++i) if (par[i] < 0) dfs(g, i, -1);
            int time = 0;
            for (int i = 0; i < n; ++i) if (par[i] < 0) hld(g, i, -1, time);
        }
        int lca(int u, int v) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) return u;
            }
        }
        int la(int u, int k, int default_value = -1) {
            if (k < 0) return default_value;
            while (u >= 0) {
                int h = head[u];
                if (visit[u] - k >= visit[h]) return ord[visit[u] - k];
                k -= visit[u] - visit[h] + 1;
                u = par[h];
            }
            return default_value;
        }
        int move_to(int u, int v, int d, int default_value = -1) {
            if (d < 0) return default_value;
            const int w = lca(u, v);
            int uw = dep[u] - dep[w];
            if (d <= uw) return la(u, d);
            int vw = dep[v] - dep[w];
            return d <= uw + vw ? la(v, (uw + vw) - d) : default_value;
        }
        int dist(int u, int v) {
            return dep[u] + dep[v] - 2 * dep[lca(u, v)];
        }
        template <typename T, typename Q, typename F, constraints_t<is_range_fold_query<Q, T>, is_bin_op<F, T>> = nullptr>
        T fold_path(int u, int v, T identity, F bin_op, Q fold_query, bool id6 = false) {
            T res = identity;
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                res = bin_op(fold_query(visit[head[v]], visit[v] + 1), res);
            }
            return bin_op(fold_query(visit[u] + id6, visit[v] + 1), res);
        }
        template <
            typename T, typename Q1, typename Q2, typename F,
            constraints_t<is_range_fold_query<Q1, T>, is_range_fold_query<Q2, T>, is_bin_op<F, T>> = nullptr
        >
        T id5(int u, int v, T identity, F bin_op, Q1 fold_query, Q2 id14, bool id6 = false) {
            T res_u = identity, res_v = identity;
            

            

            while (head[u] != head[v]) {
                if (visit[u] < visit[v]) { 

                    res_v = bin_op(fold_query(visit[head[v]], visit[v] + 1), res_v);
                    v = par[head[v]];
                } else { 

                    res_u = bin_op(res_u, id14(visit[head[u]], visit[u] + 1));
                    u = par[head[u]];
                }
            }
            if (visit[u] < visit[v]) { 

                res_v = bin_op(fold_query(visit[u] + id6, visit[v] + 1), res_v);
            } else { 

                res_u = bin_op(res_u, id14(visit[v] + id6, visit[u] + 1));
            }
            return bin_op(res_u, res_v);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_path(int u, int v, Q update_query, bool id6 = false) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                update_query(visit[head[v]], visit[v] + 1);
            }
            update_query(visit[u] + id6, visit[v] + 1);
        }
        template <typename T, typename Q, constraints_t<is_range_fold_query<Q, T>> = nullptr>
        T id8(int u, Q fold_query, bool id6 = false) {
            return fold_query(visit[u] + id6, leave[u]);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void id18(int u, Q update_query, bool id6 = false) {
            update_query(visit[u] + id6, leave[u]);
        }
        template <typename T, typename Q, constraints_t<is_point_get_query<Q, T>> = nullptr>
        T get_point(int u, Q get_query) {
            return get_query(visit[u]);
        }
        template <typename Q, constraints_t<is_point_update_query<Q>> = nullptr>
        void update_point(int u, Q update_query) {
            update_query(visit[u]);
        }
        std::vector<int> inv_ids() const {
            std::vector<int> inv(n);
            for (int i = 0; i < n; ++i) inv[visit[i]] = i;
            return inv;
        }
        int get_head(int u) const {
            return head[u];
        }
        int get_parent(int u) const {
            return par[u];
        }
        int get_subtree_size(int u) const {
            return siz[u];
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
    input(int, n, q);
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        input(int, u, v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    id7 hld(g);

    auto path = [&](int i, int j) {
        int a = hld.lca(i, j);
        vector<int> la, ra;
        while (i != a) la.push_back(i), i = hld.get_parent(i);
        while (j != a) ra.push_back(j), j = hld.get_parent(j);
        la.push_back(a);
        copy(ra.rbegin(), ra.rend(), back_inserter(la));
        return la;
    };

    vector<set<char>> cand(n);

    vector<tuple<int, int, string>> qs(q);
    rep(i, q) {
        input(int, x, y);
        input(string, s);
        --x, --y;
        qs[i] = { x, y, s };
        auto p = path(x, y);

        int siz = s.size();
        rep(j, siz) {
            char c1 = s[j], c2 = s[siz - 1 - j];

            if (cand[p[j]].empty()) {
                cand[p[j]].insert(c1);
                cand[p[j]].insert(c2);
            } else {
                bool b1 = cand[p[j]].count(c1);
                bool b2 = cand[p[j]].count(c2);
                if (b1 and b2) {

                } else if (b1) {
                    cand[p[j]] = { c1 };
                } else if (b2) {
                    cand[p[j]] = { c2 };
                } else {
                    print("NO");
                    return 0;
                }
            }
        }
    }

    map<pair<int, int>, int> id;

    int next_id = q;
    rep(i, n) {
        for (char c : cand[i]) {
            id[{ i, c - 'a' }] = next_id++;
        }
    }

    atcoder::two_sat sat(next_id);

    auto imply = [&](int x, bool f, int y, bool g) {
        sat.add_clause(x, not f, y, g);
    };

    rep(i, q) {
        const auto &[x, y, s] = qs[i];
        int siz = s.size();
        auto p = path(x, y);
        assert(siz == int(p.size()));
        rep(j, siz) {
            int c = s[j] - 'a';
            if (id.count({ p[j], c })) {
                imply(i, 0, id[{ p[j], c }], 1);
            } else {
                sat.add_clause(i, 1, i, 1);
            }
        }
        reverse(all(p));
        rep(j, siz) {
            int c = s[j] - 'a';
            if (id.count({ p[j], c })) {
                imply(i, 1, id[{ p[j], c }], 1);
            } else {
                sat.add_clause(i, 0, i, 0);
            }
        }
    }

    rep(i, n) {
        if (cand[i].size() == 2) {
            auto it = cand[i].begin();
            int x = *it++ - 'a';
            int y = *it++ - 'a';
            imply(id[{ i, x }], 1, id[{ i, y }], 0);
            imply(id[{ i, y }], 1, id[{ i, x }], 0);
        }
    }

    if (not sat.satisfiable()) {
        print("NO");
        return 0;
    }

    auto ans = sat.answer();

    string res;
    rep(i, n) {
        bool add = false;
        for (char c : cand[i]) {
            if (ans[id[{ i, c - 'a' }]]) {
                res += c;
                add = true;
            }
        }
        if (not add) {
            res += 'a';
        }
    }
    print("YES");
    print(res);
    return 0;
}

