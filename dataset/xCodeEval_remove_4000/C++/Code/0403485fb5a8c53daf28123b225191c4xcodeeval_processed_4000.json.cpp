






using namespace std;

inline namespace lib {

struct id7 {
    int N, S;
    vector<int> next;
    vector<pair<int, int>> history;

    explicit id7(int N = 0) : N(N), S(N), next(N, -1) {}

    void assign(int N) { *this = id7(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return next[i] == -1; }
    bool root(int i) { return next[i] < 0; }
    int size(int i) { return -next[i]; }
    int time() const { return history.size(); }

    void rollback(int t) {
        int i = time();
        while (i > t) {
            i--, next[history[i].first] = history[i].second;
            i--, next[history[i].first] = history[i].second;
            S++;
        }
        history.resize(t);
    }

    int find(int i) {
        while (next[i] >= 0) {
            i = next[i];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size(i) < size(j)) {
                swap(i, j);
            }
            history.emplace_back(i, next[i]);
            history.emplace_back(j, next[j]);
            next[i] += next[j];
            next[j] = i, S--;
            return true;
        }
        return false;
    }
};

struct id6 {
    int N, S;
    vector<int> next, size;

    explicit id6(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = id6(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (u != find(u)) {
            size[u] = size[find(u)];
            next[u] = next[find(u)] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

template <typename Fun>
class id2 {
    Fun fun_;

  public:
    template <typename T>
    explicit id2(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto id5(Fun&& fun) {
    return id2<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename Container>
struct less_container {
    const Container* cont = nullptr;
    less_container() = default;
    less_container(const Container& cont) : cont(&cont) {}
    inline bool operator()(int u, int v) const {
        return tie((*cont)[u], u) < tie((*cont)[v], v);
    }
};

template <typename Compare>
struct id9 {
    explicit id9(int N, const Compare& cmp = Compare())
        : cmp(cmp), in(N), data(N), N(N) {}

    void push(int u) {
        if (!in[u]) {
            if (S > 0 && !cmp(data[i], u) && coind(rng)) {
                i = i == 0 ? N - 1 : i - 1, data[i] = u; 

            } else {
                data[j] = u, j = j + 1 == N ? 0 : j + 1; 

            }
            S++, in[u] = true;
        }
    }
    int pop() {
        int u = data[i];
        S--, in[u] = false, i = i == N - 1 ? 0 : i + 1;
        return u;
    }

    bool empty() const { return S == 0; }
    int size() const { return S; }
    int universe() const { return N; }
    void clear() { i = j = S = 0; }

    static inline mt19937 rng = mt19937(random_device{}());
    static inline bernoulli_distribution coind = bernoulli_distribution(0.73);

  private:
    Compare cmp;
    vector<bool> in;
    vector<int> data;
    int N = 0, i = 0, j = 0, S = 0;
};

template <typename Compare>
struct id4 {
    struct node_t {
        int parent = 0, child = 0, next = 0, prev = 0;
    }; 

    vector<node_t> node;
    int root = 0;
    Compare comp;

    explicit id4(int N = 0, const Compare& comp = Compare())
        : node(N + 1), comp(comp) {}

    bool empty() const { return root == 0; }
    bool contains(int u) const { return u++, node[u].parent != 0; }
    int top() const { return root - 1; }

    void push(int u) {
        assert(!contains(u)), u++;
        node[u].parent = -1;
        root = safe_meld(root, u);
    }
    int pop() {
        assert(!empty());
        int u = root;
        root = two_pass_pairing(u);
        node[root].parent = -1;
        node[u] = node_t();
        return u - 1;
    }
    void improve(int u) {
        assert(!empty() && contains(u)), u++;
        if (u != root && do_comp(u, node[u].parent)) {
            take(u), root = meld(root, u);
        }
    }
    void push_or_improve(int u) {
        if (contains(u)) {
            improve(u);
        } else {
            push(u);
        }
    }
    void adjust(int u) {
        erase(u);
        push(u);
    }
    void erase(int u) {
        assert(contains(u)), u++;
        if (u == root) {
            pop();
        } else {
            take(u);
            int v = two_pass_pairing(u);
            root = safe_meld(root, v);
            node[root].parent = -1;
            node[u] = node_t();
        }
    }
    void clear() {
        if (!empty()) {
            clear_rec(root), root = 0;
        }
    }
    void fill() {
        for (int u = 1, N = node.size() - 1; u <= N; u++) {
            if (!contains(u)) {
                push(u);
            }
        }
    }

  private:
    bool do_comp(int u, int v) const { return comp(u - 1, v - 1); }
    int meld(int u, int v) { return do_comp(u, v) ? splice(u, v) : splice(v, u); }
    int safe_meld(int u, int v) {
        if (u == 0 || v == 0 || u == v)
            return u ? u : v;
        return meld(u, v);
    }
    int splice(int u, int v) {
        node[node[u].child].prev = v;
        node[v].next = node[u].child, node[u].child = v;
        return node[v].prev = node[v].parent = u;
    }
    void take(int u) {
        assert(node[u].parent > 0);
        if (node[node[u].parent].child == u) {
            node[node[u].parent].child = node[u].next;
        } else {
            node[node[u].prev].next = node[u].next;
        }
        node[node[u].next].prev = node[u].prev;
    }
    int two_pass_pairing(int n) {
        if (node[n].child == 0)
            return 0;
        int u = node[n].child, v = node[u].next, w;
        while (v && node[v].next) {
            w = node[node[v].next].next;
            u = node[u].next = v = meld(v, node[v].next);
            v = node[v].next = w;
        }
        u = node[n].child, v = node[u].next;
        while (v) {
            w = node[v].next, u = meld(u, v), v = w;
        }
        return u;
    }
    void clear_rec(int u) {
        for (int v = node[u].child, w = node[v].next; v; v = w, w = node[v].next) {
            clear_rec(v);
        }
        node[u] = node_t();
    }
};

} 




template <typename Matroid1, typename Matroid2, typename Cost>
auto id3(vector<Cost> cost, Matroid1 m1, Matroid2 m2) {
    static_assert(Matroid1::EXCHANGE && Matroid2::EXCHANGE);
    assert(m1.ground_size() == m2.ground_size());

    static constexpr Cost inf = numeric_limits<Cost>::max() / 2;
    int n = m1.ground_size();

    vector<pair<Cost, int>> dist(n);
    vector<array<Cost, 2>> pi(n);
    vector<int> prev(n + 1), X[2];
    vector<bool> in(n), reach(n);
    id4<less_container<vector<pair<Cost, int>>>> heap(n, dist);

    while (true) {
        X[0].clear(), X[1].clear();
        fill(begin(dist), end(dist), make_pair(inf, n + 1));
        fill(begin(prev), end(prev), -1);
        fill(begin(reach), end(reach), false);

        for (int u = 0; u < n; u++) {
            X[in[u]].push_back(u);
        }
        for (int u : X[0]) {
            reach[u] = m2.check(u);
            if (m1.check(u)) {
                dist[u] = {cost[u] + pi[u][0] - pi[u][1], 0};
                heap.push(u);
            }
        }

        while (!heap.empty() && !reach[heap.top()]) {
            int u = heap.pop();
            bool b = in[u];

            for (int v : X[!b]) {
                if (b ? m1.exchange(u, v) : m2.exchange(v, u)) {
                    Cost w = cost[v] + pi[u][!b] - pi[v][b];
                    auto relax = make_pair(dist[u].first + w, dist[u].second + 1);
                    assert(w >= 0);
                    if (dist[v] > relax) {
                        dist[v] = relax;
                        prev[v] = u;
                        heap.push_or_improve(v);
                    }
                }
            }
        }
        if (heap.empty()) {
            break;
        }

        int u = heap.top();
        heap.clear();

        for (int v = 0; v < n; v++) {
            Cost w = cost[v] + pi[v][in[v]] - pi[v][!in[v]];
            pi[v][in[v]] += min(dist[v].first - w, dist[u].first);
            pi[v][!in[v]] += min(dist[v].first, dist[u].first);
        }
        for (int v = u; v != -1; v = prev[v]) {
            in[v].flip();
            cost[v] = -cost[v];
        }

        m1.clear(), m2.clear();
        for (int v = 0; v < n; v++) {
            if (in[v]) {
                m1.insert(v);
                m2.insert(v);
            }
        }
    }

    vector<int> ans;
    Cost costsum = 0;
    for (int u = 0; u < n; u++) {
        if (in[u]) {
            ans.push_back(u);
            costsum += cost[u];
        }
    }
    return make_pair(move(ans), -costsum);
}

struct id0 {
    static constexpr bool EXCHANGE = true;
    vector<array<int, 2>> g;
    vector<array<int, 2>> T;
    vector<vector<int>> set;
    vector<int> tin, tout;
    id6 dsu;
    bool needs_refresh = false;

    id0(int V, vector<array<int, 2>> g, const vector<array<int, 2>>& T)
        : g(move(g)), T(T), set(V), tin(V), tout(V), dsu(V) {
        add_edges();
    }

    int ground_size() const { return g.size(); }

    int num_vertices() const { return dsu.N; }

    bool check(int i) { return !dsu.same(g[i][0], g[i][1]); }

    bool insert_check(int i) { return check(i) ? insert(i), true : false; }

    void insert(int i) {
        auto [u, v] = g[i];
        dsu.join(u, v), needs_refresh = true;
        set[u].push_back(v), set[v].push_back(u);
    }

    bool exchange(int i, int j) {
        auto [u, v] = g[i];
        auto [a, b] = g[j];
        if (!dsu.same(a, b)) {
            return true;
        }
        refresh();
        int w = tin[u] < tin[v] ? v : u;
        return ancestor(w, a) != ancestor(w, b);
    }

    void clear() {
        for (int u = 0; u < dsu.N; u++) {
            set[u].clear();
        }
        dsu.assign(dsu.N);
        add_edges();
        needs_refresh = false;
    }

  private:
    void add_edges() {
        for (auto [u, v] : T) {
            set[u].push_back(v), set[v].push_back(u), dsu.join(u, v);
        }
    }

    bool ancestor(int i, int j) { return tin[i] <= tin[j] && tout[j] <= tout[i]; }

    void refresh() {
        if (needs_refresh) {
            needs_refresh = false;
            fill(begin(tin), end(tin), -1);
            for (int u = 0, timer = 0; u < dsu.N; u++) {
                if (tin[u] == -1) {
                    dfs(u, timer);
                }
            }
        }
    }

    void dfs(int u, int& timer) {
        tin[u] = timer++;
        for (int v : set[u]) {
            if (tin[v] == -1) {
                dfs(v, timer);
            }
        }
        tout[u] = timer++;
    }
};

struct id8 {
    static constexpr bool EXCHANGE = true;
    using Color = int16_t;
    using Limit = int16_t;
    vector<Color> color;
    vector<Limit> limit;
    vector<Limit> count;

    id8(const vector<Color>& color, const vector<Limit>& limit)
        : color(color), limit(limit), count(this->limit) {}

    int ground_size() const { return color.size(); }

    int num_colors() const { return limit.size(); }

    bool check(int i) { return count[color[i]] > 0; }

    bool insert_check(int i) { return check(i) ? insert(i), true : false; }

    void insert(int i) { count[color[i]]--; }

    bool exchange(int i, int j) { return color[i] == color[j] || check(j); }

    void clear() { copy(begin(limit), end(limit), begin(count)); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    vector<int16_t> deg(K + 1);
    for (int i = 0; i < K; i++) {
        cin >> deg[i];
    }

    vector<vector<int>> weight(N, vector<int>(N));
    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N; v++) {
            cin >> weight[u][v];
            weight[v][u] = weight[u][v];
        }
    }

    vector<array<int, 2>> special, ground_set, rest;
    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N; v++) {
            if (u < K && v < K) {
                special.push_back({u, v});
            } else if (u < K && v >= K) {
                ground_set.push_back({u, v});
            } else {
                rest.push_back({u, v});
            }
        }
    }

    sort(begin(rest), end(rest), [&](auto&& a, auto&& b) {
        return weight[a[0]][a[1]] < weight[b[0]][b[1]]; 

    });
    id6 id1(N);
    for (auto [u, v] : rest) {
        if (id1.join(u, v)) {
            ground_set.push_back({u, v});
        }
    }

    int G = ground_set.size();
    int E = special.size();
    deg[K] = G;

    vector<int> cost;
    vector<int16_t> color;
    for (auto [u, v] : ground_set) {
        cost.push_back(weight[u][v]);
        color.push_back(u < K ? u : K);
    }

    vector<array<int, 2>> T;
    id7 dsu(K);
    int ans = INT_MAX;

    id5([&](auto self, int s, int special_cost) -> void {
        id0 M1(N, ground_set, T);
        id8 M2(color, deg);
        auto [more, mcost] = id3(cost, M1, M2);

        if (more.size() + T.size() == size_t(N - 1)) {
            ans = min(ans, special_cost + mcost);
        }

        int t = dsu.time();
        for (int i = s; i < E; i++) {
            if (auto [u, v] = special[i]; !dsu.same(u, v) && deg[u] && deg[v]) {
                T.push_back({u, v});
                deg[u]--, deg[v]--;
                dsu.join(u, v);

                self(i + 1, special_cost + weight[u][v]);

                dsu.rollback(t);
                deg[u]++, deg[v]++;
                T.pop_back();
            }
        }
    })(0, 0);

    cout << ans << '\n';
    return 0;
}
