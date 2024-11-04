






using namespace std;

template <typename Node>
struct id5 {
    int n = 0;
    vector<Node> node;

    id5() = default;
    id5(int N, Node init) { assign(N, init); }
    template <typename T>
    id5(int N, const vector<T>& arr, int s = 0) {
        assign(N, arr, s);
    }

    void assign(int N, Node init) {
        n = N;
        node.assign(2 * next_two(N), init);
        build_init_dfs(1, 0, n);
    }

    template <typename T>
    void assign(int N, const vector<T>& arr, int s = 0) {
        assert(int(arr.size()) >= N + s);
        n = N;
        node.resize(2 * next_two(N));
        id4(1, s, s + n, arr);
    }

    template <typename... Us>
    void update_point(int i, Us&&... update) {
        static thread_local vector<int> dfs;
        assert(0 <= i && i < n);
        int u = 1, L = 0, R = n;
        while (L + 1 < R) {
            pushdown(u, R - L);
            dfs.push_back(u);
            int M = (L + R) / 2;
            if (i < M) {
                u = u << 1, R = M;
            } else {
                u = u << 1 | 1, L = M;
            }
        }
        apply(u, 1, update...);
        for (int B = dfs.size(), i = B - 1; i >= 0; i--) {
            pushup(dfs[i]);
        }
        dfs.clear();
    }

    template <typename... Us>
    void update_range(int l, int r, Us&&... update) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            id18(1, 0, n, l, r, update...);
        }
    }

    template <typename... Us>
    void id10(int l, int r, Us&&... update) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            id7(1, 0, n, l, r, update...);
        }
    }

    template <typename Vis>
    void id3(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            id8(1, 0, n, l, r, vis);
        }
    }

    auto query_point(int i) {
        assert(0 <= i && i < n);
        int u = 1, L = 0, R = n;
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            if (i < M) {
                u = u << 1, R = M;
            } else {
                u = u << 1 | 1, L = M;
            }
        }
        return node[u];
    }

    auto query_range(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return l == r ? Node() : query_range_dfs(1, 0, n, l, r);
    }

    auto query_all() { return node[1]; }

    template <typename Vis>
    auto id21(int i, Vis&& vis) {
        assert(0 <= i && i < n);
        return id12(1, 0, n, i, vis);
    }

    template <typename Vis>
    auto id17(int i, Vis&& vis) {
        assert(0 <= i && i < n);
        return id16(1, 0, n, i, vis);
    }

    template <bool rootpath, typename Vis>
    void id19(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            id9<rootpath>(1, 0, n, l, r, vis);
        }
    }

    template <bool rootpath, typename Vis>
    void id1(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            id6<rootpath>(1, 0, n, l, r, vis);
        }
    }

    

    

    

    template <typename Bs>
    auto id20(Bs&& bs) {
        int u = 1, L = 0, R = n;
        Node prefix = Node();
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            Node v = combine(prefix, node[u << 1]);
            if (bs(v)) {
                u = u << 1, R = M;
            } else {
                prefix = move(v);
                u = u << 1 | 1, L = M;
            }
        }
        Node v = combine(prefix, node[u]);
        return bs(v) ? make_pair(L, move(prefix)) : make_pair(R, move(v));
    }

    

    

    

    template <typename Bs>
    auto id15(Bs&& bs) {
        int u = 1, L = 0, R = n;
        Node suffix = Node();
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            Node v = combine(node[u << 1 | 1], suffix);
            if (bs(v)) {
                suffix = move(v);
                u = u << 1, R = M;
            } else {
                u = u << 1 | 1, L = M;
            }
        }
        Node v = combine(node[u], suffix);
        return bs(v) ? make_pair(L, move(v)) : make_pair(R, move(suffix));
    }

    

    

    

    template <typename Bs>
    auto id11(int l, int r, Bs&& bs) {
        assert(0 <= l && l <= r && r <= n);
        return l == r ? make_pair(r, Node())
                      : id2(1, 0, n, l, r, Node(), bs);
    }

    

    

    

    template <typename Bs>
    auto id0(int l, int r, Bs&& bs) {
        assert(0 <= l && l <= r && r <= n);
        return l == r ? make_pair(r, Node())
                      : id14(1, 0, n, l, r, Node(), bs);
    }

  private:
    static int next_two(int N) {
        return 1 << (N > 1 ? 8 * sizeof(int) - __builtin_clz(N - 1) : 0);
    }

    static Node combine(const Node& x, const Node& y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }

    template <typename... Us>
    inline bool can_break(int u, int s, Us&&... update) const {
        if constexpr (Node::RANGES) {
            return node[u].can_break(update..., s);
        } else {
            return node[u].can_break(update...);
        }
    }
    template <typename... Us>
    inline bool can_update(int u, int s, Us&&... update) const {
        if (s == 1) {
            return true;
        } else if constexpr (Node::RANGES) {
            return node[u].can_update(update..., s);
        } else {
            return node[u].can_update(update...);
        }
    }

    template <typename... Us>
    inline void apply(int u, int s, Us&&... update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update..., s);
        } else {
            node[u].apply(update...);
        }
    }

    inline void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }

    inline void pushdown(int u, int s) {
        if constexpr (!Node::LAZY) {
            return;
        } else if constexpr (Node::RANGES) {
            node[u].pushdown(node[u << 1], node[u << 1 | 1], s / 2, (s + 1) / 2);
        } else {
            node[u].pushdown(node[u << 1], node[u << 1 | 1]);
        }
    }

    template <typename T>
    void id4(int u, int L, int R, const vector<T>& arr) {
        if (L + 1 == R) {
            node[u] = arr[L];
        } else {
            int M = (L + R) / 2;
            id4(u << 1, L, M, arr);
            id4(u << 1 | 1, M, R, arr);
            pushup(u);
        }
    }

    void build_init_dfs(int u, int L, int R) {
        if (L + 1 < R) {
            int M = (L + R) / 2;
            build_init_dfs(u << 1, L, M);
            build_init_dfs(u << 1 | 1, M, R);
            pushup(u);
        }
    }

    template <typename... Us>
    void id18(int u, int L, int R, int ql, int qr, Us&&... update) {
        if (ql <= L && R <= qr) {
            apply(u, R - L, update...);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            id18(u << 1, L, M, ql, qr, update...);
        } else if (M <= ql) {
            id18(u << 1 | 1, M, R, ql, qr, update...);
        } else {
            id18(u << 1, L, M, ql, M, update...);
            id18(u << 1 | 1, M, R, M, qr, update...);
        }
        pushup(u);
    }

    template <typename... Us>
    void id7(int u, int L, int R, int ql, int qr, Us&&... update) {
        if (can_break(u, R - L, update...)) {
            return;
        }
        if (ql <= L && R <= qr && can_update(u, R - L, update...)) {
            apply(u, R - L, update...);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            id7(u << 1, L, M, ql, qr, update...);
        } else if (M <= ql) {
            id7(u << 1 | 1, M, R, ql, qr, update...);
        } else {
            id7(u << 1, L, M, ql, M, update...);
            id7(u << 1 | 1, M, R, M, qr, update...);
        }
        pushup(u);
    }

    template <typename Vis>
    void id8(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if (ql <= L && R <= qr && vis(u, R - L)) {
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            id8(u << 1, L, M, ql, qr, vis);
        } else if (M <= ql) {
            id8(u << 1 | 1, M, R, ql, qr, vis);
        } else {
            id8(u << 1, L, M, ql, M, vis);
            id8(u << 1 | 1, M, R, M, qr, vis);
        }
        pushup(u);
    }

    auto query_range_dfs(int u, int L, int R, int ql, int qr) {
        if (ql <= L && R <= qr) {
            return node[u];
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            return query_range_dfs(u << 1, L, M, ql, qr);
        } else if (M <= ql) {
            return query_range_dfs(u << 1 | 1, M, R, ql, qr);
        } else {
            return combine(query_range_dfs(u << 1, L, M, ql, M),
                           query_range_dfs(u << 1 | 1, M, R, M, qr));
        }
    }

    template <typename Vis>
    void id12(int u, int L, int R, int q, Vis&& vis) {
        if (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            q < M ? id12(u << 1, L, M, q, vis)
                  : id12(u << 1 | 1, M, R, q, vis);
            pushup(u);
            vis(node[u], L, R);
        } else {
            vis(node[u], L, R);
        }
    }

    template <typename Vis>
    void id16(int u, int L, int R, int q, Vis&& vis) {
        if (L + 1 < R) {
            pushdown(u, R - L);
            vis(node[u], L, R);
            int M = (L + R) / 2;
            q < M ? id16(u << 1, L, M, q, vis)
                  : id16(u << 1 | 1, M, R, q, vis);
            pushup(u);
        } else {
            vis(node[u], L, R);
        }
    }

    template <bool rootpath, typename Vis>
    void id9(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if constexpr (rootpath)
            vis(node[u], L, R);
        if (ql <= L && R <= qr) {
            if constexpr (!rootpath)
                vis(node[u], L, R);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            id9(u << 1, L, M, ql, qr, vis);
        } else if (M <= ql) {
            id9(u << 1 | 1, M, R, ql, qr, vis);
        } else {
            id9(u << 1, L, M, ql, M, vis);
            id9(u << 1 | 1, M, R, M, qr, vis);
        }
        pushup(u);
    }

    template <bool rootpath, typename Vis>
    void id6(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if constexpr (rootpath)
            vis(node[u], L, R);
        if (ql <= L && R <= qr) {
            if constexpr (!rootpath)
                vis(node[u], L, R);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            id6(u << 1, L, M, ql, qr, vis);
        } else if (M <= ql) {
            id6(u << 1 | 1, M, R, ql, qr, vis);
        } else {
            id6(u << 1 | 1, M, R, M, qr, vis);
            id6(u << 1, L, M, ql, M, vis);
        }
        pushup(u);
    }

    template <typename Bs>
    auto id2(int u, int L, int R, int ql, int qr, Node prefix, Bs&& bs) {
        if (ql <= L && R <= qr) {
            Node extra = combine(prefix, node[u]);
            if (bs(extra)) {
                while (L + 1 < R) {
                    pushdown(u, R - L);
                    int M = (L + R) / 2;
                    Node v = combine(prefix, node[u << 1]);
                    if (bs(v)) {
                        u = u << 1, R = M;
                    } else {
                        prefix = move(v);
                        u = u << 1 | 1, L = M;
                    }
                }
                Node v = combine(prefix, node[u]);
                return bs(v) ? make_pair(L, move(prefix)) : make_pair(R, move(v));
            } else {
                return make_pair(R, move(extra));
            }
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        if (qr <= M) {
            return id2(u << 1, L, M, ql, qr, move(prefix), bs);
        } else if (M <= ql) {
            return id2(u << 1 | 1, M, R, ql, qr, move(prefix), bs);
        }
        tie(x, prefix) = id2(u << 1, L, M, ql, M, move(prefix), bs);
        if (x < M) {
            return make_pair(x, move(prefix));
        } else {
            return id2(u << 1 | 1, M, R, M, qr, move(prefix), bs);
        }
    }

    template <typename Bs>
    auto id14(int u, int L, int R, int ql, int qr, Node suffix, Bs&& bs) {
        if (ql <= L && R <= qr) {
            Node extra = combine(node[u], suffix);
            if (!bs(extra)) {
                while (L + 1 < R) {
                    pushdown(u, R - L);
                    int M = (L + R) / 2;
                    Node v = combine(node[u << 1 | 1], suffix);
                    if (bs(v)) {
                        suffix = move(v);
                        u = u << 1, R = M;
                    } else {
                        u = u << 1 | 1, L = M;
                    }
                }
                Node v = combine(node[u], suffix);
                return bs(v) ? make_pair(L, move(v)) : make_pair(R, move(suffix));
            } else {
                return make_pair(L, move(extra));
            }
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        if (qr <= M) {
            return id14(u << 1, L, M, ql, qr, move(suffix), bs);
        } else if (M <= ql) {
            return id14(u << 1 | 1, M, R, ql, qr, move(suffix), bs);
        }
        tie(x, suffix) = id14(u << 1 | 1, M, R, M, qr, move(suffix), bs);
        if (x > M) {
            return make_pair(x, move(suffix));
        } else {
            return id14(u << 1, L, M, ql, M, move(suffix), bs);
        }
    }
};

constexpr int64_t NINF = INT64_MIN / 4;

struct Segnode {
    static constexpr bool LAZY = false, RANGES = false;
    int64_t a = NINF; 

    int64_t b = NINF; 

    int64_t c = NINF; 


    Segnode() = default;
    Segnode(pair<int64_t, int64_t> ab) : a(ab.first), b(ab.second), c(a + b) {}

    void pushup(const Segnode& lhs, const Segnode& rhs) {
        a = max(lhs.a, rhs.a);
        b = max(lhs.b, rhs.b);
        c = max({lhs.c, rhs.c, lhs.a + rhs.b});
    }

    void apply(int64_t A) { a = max(a, A), c = a + b; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> top(N + 1), mid(N + 1), bot(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> top[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> mid[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> bot[i];
    }

    vector<int64_t> top_pref(N + 1), id13(N + 2), mid_pref(N + 1);
    for (int i = 1; i <= N; i++) {
        top_pref[i] = top[i] + top_pref[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        mid_pref[i] = mid[i] + mid_pref[i - 1];
    }
    for (int i = N; i >= 1; i--) {
        id13[i] = bot[i] + id13[i + 1];
    }

    

    

    

    vector<pair<int64_t, int64_t>> init(N + 1);
    init[0] = {NINF, NINF};
    for (int i = 1; i <= N; i++) {
        init[i] = {top_pref[i] - mid_pref[i - 1], mid_pref[i] + id13[i]};
    }

    id5<Segnode> seg(N + 1, init);

    vector<array<int, 3>> ranges(Q);
    for (auto& [l, r, k] : ranges) {
        cin >> l >> r >> k, r++;
    }
    sort(begin(ranges), end(ranges),
         [&](auto x, auto y) { return make_pair(x[1], x[0]) < make_pair(y[1], y[0]); });

    for (auto [l, r, k] : ranges) {
        auto a = seg.query_range(l, r).a;
        if (r <= N) {
            seg.update_point(r, a - k);
        }
    }

    

    int64_t ans = NINF;
    for (auto [l, r, k] : ranges) {
        auto c = seg.query_range(l, r).c;
        ans = max(ans, c - k);
    }

    cout << ans << '\n';
    return 0;
}
