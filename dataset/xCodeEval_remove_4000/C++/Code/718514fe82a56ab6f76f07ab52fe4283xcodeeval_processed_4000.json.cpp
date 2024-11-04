






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
        if (n > 0) {
            build_init_dfs(1, 0, n);
        }
    }

    template <typename T>
    void assign(int N, const vector<T>& arr, int s = 0) {
        assert(int(arr.size()) >= N + s);
        n = N;
        node.resize(2 * next_two(N));
        if (n > 0) {
            id4(1, s, s + n, arr);
        }
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
        for (int B = dfs.size(), j = B - 1; j >= 0; j--) {
            pushup(dfs[j]);
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
                      : id13(1, 0, n, l, r, Node(), bs);
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
            node[u].apply(update...), (void)s;
        }
    }

    inline void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }

    inline void pushdown(int u, int s) {
        if constexpr (!Node::LAZY) {
            return;
        } else if constexpr (Node::RANGES) {
            node[u].pushdown(node[u << 1], node[u << 1 | 1], s / 2, (s + 1) / 2);
        } else {
            node[u].pushdown(node[u << 1], node[u << 1 | 1]), (void)s;
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
        if (ql <= L && R <= qr && vis(node[u], R - L)) {
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
    auto id13(int u, int L, int R, int ql, int qr, Node suffix, Bs&& bs) {
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
            return id13(u << 1, L, M, ql, qr, move(suffix), bs);
        } else if (M <= ql) {
            return id13(u << 1 | 1, M, R, ql, qr, move(suffix), bs);
        }
        tie(x, suffix) = id13(u << 1 | 1, M, R, M, qr, move(suffix), bs);
        if (x > M) {
            return make_pair(x, move(suffix));
        } else {
            return id13(u << 1, L, M, ql, M, move(suffix), bs);
        }
    }
};

struct id14 {
    using V = double;
    static constexpr bool LAZY = false, RANGES = false;
    static constexpr V inf = numeric_limits<V>::lowest() / 2;
    static constexpr int M = 3;
    static inline double x, y;
    using Mat = array<array<V, M>, M>;
    Mat A = {};

    static constexpr V add(V a, V b) { return max(a, b); }
    static constexpr V mul(V a, V b) { return a + b; }
    static void init(Mat& A) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                A[i][j] = inf;
    }

    static Mat make(V a) {
        V z = x + y;
        return Mat{{
            {0.0, a / z, a / x},
            {0.0, a / z, inf},
            {0.0, inf, inf},
        }};
    }

    id14() { init(A); }
    id14(Mat A) : A(A) {}
    id14(int b) : A(make(b)) {}

    void pushup(const id14& lhs, const id14& rhs) {
        init(A);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                for (int k = 0; k < M; k++)
                    A[i][j] = add(A[i][j], mul(lhs.A[i][k], rhs.A[k][j]));
    }

    void apply(Mat B) { A = B; }

    void apply(int b) { A = make(b); }

    auto get() const { return max({A[0][0], A[0][1], A[0][2]}); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << setprecision(11) << showpoint << fixed;
    int N, Q;
    auto& x = id14::x;
    auto& y = id14::y;
    cin >> N >> Q >> x >> y;
    if (x < y) {
        swap(x, y);
    }
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    id5<id14> seg(N, b);
    while (Q--) {
        if (int t; cin >> t, t == 1) {
            int i, v;
            cin >> i >> v, i--;
            seg.update_point(i, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r, l--;
            cout << seg.query_range(l, r).get() << '\n';
        } else {
            assert(false);
        }
    }
    return 0;
}
