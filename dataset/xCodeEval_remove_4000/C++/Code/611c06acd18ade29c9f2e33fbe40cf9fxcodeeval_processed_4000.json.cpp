    
    
    
    
    
    

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
                id19(1, 0, n, l, r, update...);
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
        auto id22(int i, Vis&& vis) {
            assert(0 <= i && i < n);
            return id12(1, 0, n, i, vis);
        }

        template <typename Vis>
        auto id18(int i, Vis&& vis) {
            assert(0 <= i && i < n);
            return id17(1, 0, n, i, vis);
        }

        template <bool rootpath, typename Vis>
        void id20(int l, int r, Vis&& vis) {
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
        auto id21(Bs&& bs) {
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
        auto id16(Bs&& bs) {
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
                        : id15(1, 0, n, l, r, Node(), bs);
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
        void id19(int u, int L, int R, int ql, int qr, Us&&... update) {
            if (ql <= L && R <= qr) {
                apply(u, R - L, update...);
                return;
            }
            pushdown(u, R - L);
            int M = (L + R) / 2;
            if (qr <= M) {
                id19(u << 1, L, M, ql, qr, update...);
            } else if (M <= ql) {
                id19(u << 1 | 1, M, R, ql, qr, update...);
            } else {
                id19(u << 1, L, M, ql, M, update...);
                id19(u << 1 | 1, M, R, M, qr, update...);
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
        void id17(int u, int L, int R, int q, Vis&& vis) {
            if (L + 1 < R) {
                pushdown(u, R - L);
                vis(node[u], L, R);
                int M = (L + R) / 2;
                q < M ? id17(u << 1, L, M, q, vis)
                    : id17(u << 1 | 1, M, R, q, vis);
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
            if (L + 1 == R) {
                Node full = combine(prefix, node[u]);
                return bs(full) ? make_pair(L, move(prefix)) : make_pair(R, move(full));
            }
            pushdown(u, R - L);
            int x, M = (L + R) / 2;
            if (ql <= L && R <= qr) {
                Node middle = combine(prefix, node[u << 1]);
                if (bs(middle)) {
                    return id2(u << 1, L, M, ql, qr, move(prefix), bs);
                } else {
                    return id2(u << 1 | 1, M, R, ql, qr, move(middle), bs);
                }
            }
            if (qr <= M) {
                return id2(u << 1, L, M, ql, qr, move(prefix), bs);
            } else if (M <= ql) {
                return id2(u << 1 | 1, M, R, ql, qr, move(prefix), bs);
            }
            tie(x, prefix) = id2(u << 1, L, M, ql, qr, move(prefix), bs);
            if (x < M) {
                return make_pair(x, move(prefix));
            } else {
                return id2(u << 1 | 1, M, R, M, qr, move(prefix), bs);
            }
        }

        template <typename Bs>
        auto id15(int u, int L, int R, int ql, int qr, Node suffix, Bs&& bs) {
            if (L + 1 == R) {
                Node full = combine(node[u], suffix);
                return bs(full) ? make_pair(L, move(full)) : make_pair(R, move(suffix));
            }
            pushdown(u, R - L);
            int x, M = (L + R) / 2;
            if (ql <= L && R <= qr) {
                Node middle = combine(node[u << 1 | 1], suffix);
                if (bs(middle)) {
                    return id15(u << 1, L, M, ql, qr, move(middle), bs);
                } else {
                    return id15(u << 1 | 1, M, R, ql, qr, move(suffix), bs);
                }
            }
            if (qr <= M) {
                return id15(u << 1, L, M, ql, qr, move(suffix), bs);
            } else if (M <= ql) {
                return id15(u << 1 | 1, M, R, ql, qr, move(suffix), bs);
            }
            tie(x, suffix) = id15(u << 1 | 1, M, R, M, qr, move(suffix), bs);
            if (x > M) {
                return make_pair(x, move(suffix));
            } else {
                return id15(u << 1, L, M, ql, M, move(suffix), bs);
            }
        }
    };

    struct Segnode {
        static constexpr bool LAZY = false, RANGES = false;
        static constexpr int MAX = INT_MAX, MIN = INT_MIN;
        int lo = MAX, hi = MIN;

        Segnode() = default;
        Segnode(int v) : lo(v), hi(v) {}
        Segnode(array<int, 2> a) : lo(min(a[0], a[1])), hi(max(a[0], a[1])) {}

        auto get() const { return array<int, 2>{lo, hi}; }

        void pushup(const Segnode& lhs, const Segnode& rhs) {
            lo = min(lhs.lo, rhs.lo);
            hi = max(lhs.hi, rhs.hi);
        }

        void apply(int v) { lo = hi = v; }
    };

    int main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int N, Q;
        cin >> N >> Q;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i], a[i]--;
            assert(0 <= a[i] && a[i] < N);
        }
        if (N == 1) {
            while (Q--) {
                int l, r;
                cin >> l >> r;
                cout << 0 << '\n';
            }
            return 0;
        }
        const int B = 36;
        array<id5<Segnode>, B> id13, id14;
        {
            vector<int> loop = a;
            id13[0].assign(N, loop);
            for (int b = 1; b < B; b++) {
                vector<int> nxt(N);
                for (int i = 0; i < N; i++) {
                    nxt[i] = loop[loop[i]];
                }
                swap(loop, nxt);
                id13[b].assign(N, loop);
            }
        }
        {
            vector<array<int, 2>> val(N - 1);
            for (int i = 0; i < N - 1; i++) {
                val[i] = {min(a[i], a[i + 1]), max(a[i], a[i + 1])};
            }
            id14[0].assign(N - 1, val);
            for (int b = 1; b < B; b++) {
                vector<array<int, 2>> nxt(N - 1);
                for (int i = 0; i < N - 1; i++) {
                    auto [l, r] = val[i];
                    if (l == r) {
                        nxt[i] = id13[b - 1].query_point(l).get();
                    } else {
                        nxt[i] = id14[b - 1].query_range(l, r).get();
                    }
                }
                swap(val, nxt);
                id14[b].assign(N - 1, val);
            }
        }
        const int FULL = N - 1;
        while (Q--) {
            int l, r;
            cin >> l >> r, l--, r--;
            if (r - l == 0) {
                cout << -1 << '\n';
                continue;
            } else if (r - l == FULL) {
                cout << 0 << '\n';
                continue;
            }
            int64_t ans = 0;
            for (int b = B - 1; b >= 0; b--) {
                auto [L, R] = id14[b].query_range(l, r).get();
                if (R - L == FULL) {
                    continue;
                } else if (b == B - 1) {
                    ans = -2;
                    break;
                } else {
                    ans += 1LL << b;
                    l = L, r = R;
                }
            }
            cout << ans + 1 << '\n';
        }
        return 0;
    }
