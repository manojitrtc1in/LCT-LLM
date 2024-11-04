
















namespace atcoder {

namespace internal {





int id7(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





constexpr int id8(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}





int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

}  


}  


namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id15 {
  public:
    id15() : id15(0) {}
    explicit id15(int n) : id15(std::vector<S>(n, e())) {}
    explicit id15(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id7(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  





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
static constexpr bool id2 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

} 


namespace suisen {
class id5 {
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

        id5(Graph &g, int root = 0) : n(g.size()), root(root), visit(n), leave(n), head(n), ord(n), siz(n), par(n) {
            dfs(g, root, -1);
            int time = 0;
            hld(g, root, -1, time);
        }
        int lca(int u, int v) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) return u;
            }
        }
        int la(int u, int k, int default_value = -1) {
            for (int h = head[u]; u >= 0; u = par[h], h = head[u]) {
                if (visit[u] - k >= visit[h]) return ord[visit[u] - k];
                k -= visit[u] - visit[h] + 1;
            }
            return default_value;
        }
        template <typename T, typename Q, typename F, constraints_t<is_range_fold_query<Q, T>, is_bin_op<F, T>> = nullptr>
        T fold_path(int u, int v, T identity, F bin_op, Q fold_query, bool id4 = false) {
            T res = identity;
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                res = bin_op(fold_query(visit[head[v]], visit[v] + 1), res);
            }
            return bin_op(fold_query(visit[u] + id4, visit[v] + 1), res);
        }
        template <
            typename T, typename Q1, typename Q2, typename F,
            constraints_t<is_range_fold_query<Q1, T>, is_range_fold_query<Q2, T>, is_bin_op<F, T>> = nullptr
        >
        T id3(int u, int v, T identity, F bin_op, Q1 fold_query, Q2 id12, bool id4 = false) {
            T res_u = identity, res_v = identity;
            

            

            while (head[u] != head[v]) {
                if (visit[u] < visit[v]) { 

                    res_v = bin_op(fold_query(visit[head[v]], visit[v] + 1), res_v);
                    v = par[head[v]];
                } else { 

                    res_u = bin_op(res_u, id12(visit[head[u]], visit[u] + 1));
                    u = par[head[u]];
                }
            }
            if (visit[u] < visit[v]) { 

                res_v = bin_op(fold_query(visit[u] + id4, visit[v] + 1), res_v);
            } else { 

                res_u = bin_op(res_u, id12(visit[v] + id4, visit[u] + 1));
            }
            return bin_op(res_u, res_v);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_path(int u, int v, Q update_query, bool id4 = false) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                update_query(visit[head[v]], visit[v] + 1);
            }
            update_query(visit[u] + id4, visit[v] + 1);
        }
        template <typename T, typename Q, constraints_t<is_range_fold_query<Q, T>> = nullptr>
        T id9(int u, Q fold_query, bool id4 = false) {
            return fold_query(visit[u] + id4, leave[u]);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void id16(int u, Q update_query, bool id4 = false) {
            update_query(visit[u] + id4, leave[u]);
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
    private:
        const int n, root;
        std::vector<int> visit, leave, head, ord, siz, par;
        int dfs(Graph &g, int u, int p) {
            par[u] = p;
            siz[u] = 1;
            int max_size = 0;
            for (int &v : g[u]) {
                if (v == p) continue;
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


constexpr int inf = std::numeric_limits<int>::max();

std::pair<int, int> id17(std::pair<int, int> x, std::pair<int, int> y) {
    return { std::min(x.first, y.first), std::max(x.second, y.second) };
}
std::pair<int, int> id1() {
    return { inf, -inf };
}
std::pair<int, int> id14(int f, std::pair<int, int> x) {
    return { f + x.first, f + x.second };
}
int composition_add(int f, int g) {
    return f + g;
}
int id_add() {
    return 0;
}

long long op_sum(long long x, long long y) {
    return x + y;
}
long long e_sum() {
    return 0;
}
long long id13(bool f, long long x) {
    return f ? -x : x;
}
bool id11(bool f, bool g) {
    return f xor g;
}
bool id10() {
    return false;
}

std::optional<std::vector<int>> max_matching(
    const int n,
    const std::vector<std::vector<std::pair<int, int>>> &g,
    const std::vector<bool> &is_active,
    const std::vector<int> &depth
) {
    const int id18 = std::accumulate(is_active.begin(), is_active.end(), 0);

    if (id18 & 1) return std::nullopt;

    std::vector<int> matching;
    std::vector count_color(n, std::array { 0, 0 });

    auto dfs = [&](auto dfs, int u, int p) -> bool {
        if (not is_active[u]) return true;

        ++count_color[u][depth[u]];

        for (const auto &[v, edge_id] : g[u]) {
            if (v == p) continue;
            if (not dfs(dfs, v, u)) return false;

            count_color[u][0] += count_color[v][0];
            count_color[u][1] += count_color[v][1];

            if ((count_color[v][0] + count_color[v][1]) & 1) {
                matching.push_back(edge_id);
            }
        }

        if (count_color[u][0] == count_color[u][1]) return true;
        if (count_color[u][0] == count_color[u][1] + 1) return depth[u] == 0;
        if (count_color[u][0] + 1 == count_color[u][1]) return depth[u] == 1;

        return false;
    };

    if (dfs(dfs, 0, -1)) {
        std::sort(matching.begin(), matching.end());
        return matching;
    } else {
        return std::nullopt;
    }
}

using RangeAddRangeMinmax = atcoder::id15<std::pair<int, int>, id17, id1, int,  id14, composition_add,    id_add   >;
using RangeNegateRangeSum = atcoder::id15<long long,           op_sum,    e_sum,    bool, id13, id11, id10>;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    std::vector<std::vector<int>> g2(n);
    for (int u = 0; u < n; ++u) {
        for (const auto &[v, edge_id] : g[u]) {
            g2[u].push_back(v);
        }
    }
    suisen::id5 hld(g2);

    std::vector<long long> weight(n);

    std::vector<bool> is_active(n, false);

    std::vector<int> depth(n, 0);
    auto dfs = [&](auto dfs, int u, int p, int d) -> void {
        depth[u] = d;
        for (const auto &edge : g[u]) {
            int v, edge_id;
            std::tie(v, edge_id) = edge;
            if (v == p) continue;
            dfs(dfs, v, u, d ^ 1);

            hld.update_point(v, [&](int v_id) { weight[v_id] = edge_id; });
        }
    };
    dfs(dfs, 0, -1, 0);

    int id18 = 0;
    long long answer_base = 0;

    RangeAddRangeMinmax id6(std::vector<std::pair<int, int>>(n, { 0, 0 }));
    RangeAddRangeMinmax id0(std::vector<std::pair<int, int>>(n, { 0, 0 }));
    RangeNegateRangeSum seg_sum(n);

    auto activate_vertex = [&](int vertex) {
        ++id18;
        is_active[vertex] = true;

        const int val = depth[vertex] ? +1 : -1;

        hld.update_point(
            vertex,
            [&](int v_id) {
                id0.set(v_id, { val, val });
                seg_sum.set(v_id, -weight[v_id]);
                answer_base += weight[v_id];
            }
        );

        hld.update_path(
            0, vertex,
            [&](int l, int r) {
                id6.apply(l, r, +val);
                id0.apply(l, r, -val);
            },
            false
        );

        hld.update_path(
            0, vertex,
            [&](int l, int r) {
                seg_sum.apply(l, r, true);
            },
            true
        );
    };

    activate_vertex(0);

    while (true) {
        int query_type;
        std::cin >> query_type;

        if (query_type == 0) break;

        if (query_type == 3) break;

        if (query_type == 2) {
            auto opt_matching = max_matching(n, g, is_active, depth);
            if (opt_matching.has_value()) {
                auto matching = std::move(*opt_matching);
                const int matching_size = matching.size();
                std::cout << matching_size;
                for (int i = 0; i < matching_size; ++i) {
                    std::cout << ' ' << matching[i];
                }
                std::cout << std::endl;
            } else {
                std::cout << 0 << std::endl;
            }
            continue;
        }

        int vertex;
        std::cin >> vertex;
        --vertex;

        activate_vertex(vertex);

        if (id18 & 1) {
            std::cout << 0 << std::endl;
            continue;
        }

        auto [min1, max1] = id6.all_prod();
        auto [min2, max2] = id0.all_prod();
        if (std::min(min1, min2) < -1 or std::max(max1, max2) > +1) {
            std::cout << 0 << std::endl;
            continue;
        }

        long long answer = (answer_base + seg_sum.all_prod()) / 2;
        std::cout << answer << std::endl;
    }

    return 0;
}

