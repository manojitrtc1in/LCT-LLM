#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

inline namespace lib {

struct disjoint_set_rollback {
    int N, S;
    vector<int> next;
    vector<pair<int, int>> history;

    explicit disjoint_set_rollback(int N = 0) : N(N), S(N), next(N, -1) {}

    void assign(int N) { *this = disjoint_set_rollback(N); }
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

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
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
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
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
struct spfa_deque {
    explicit spfa_deque(int N, const Compare& cmp = Compare())
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
struct pairing_int_heap {
    struct node_t {
        int parent = 0, child = 0, next = 0, prev = 0;
    }; 

    vector<node_t> node;
    int root = 0;
    Compare comp;

    explicit pairing_int_heap(int N = 0, const Compare& comp = Compare())
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
auto mincost_matroid_intersection(const vector<Cost>& cost, Matroid1 m1, Matroid2 m2) {
    assert(m1.ground_size() == m2.ground_size());

    static constexpr Cost inf = numeric_limits<Cost>::max();
    int n = m1.ground_size();

    vector<vector<int>> exchange_graph(n);
    vector<pair<Cost, int>> dist(n + 1);
    vector<int> prev(n + 1);
    vector<bool> inset(n);
    vector<int> X; 

    spfa_deque<less_container<vector<pair<Cost, int>>>> spfa(n, dist);

    

    vector<int> elems(n);
    iota(begin(elems), end(elems), 0);
    sort(begin(elems), end(elems), [&](int i, int j) { return cost[i] < cost[j]; });

    

    for (int u : elems) {
        if (m2.check(u) && m1.insert_check(u)) {
            X.push_back(u);
            m2.insert(u);
            inset[u] = true;
        } else if (!X.empty()) {
            break;
        }
    }

    auto m1_prepare = [&](int x) {
        if constexpr (!Matroid1::EXCHANGE) {
            m1.clear();
            for (int w : X) {
                if (x != w) {
                    m1.insert(w);
                }
            }
        }
    };
    auto m2_prepare = [&](int x) {
        if constexpr (!Matroid2::EXCHANGE) {
            m2.clear();
            for (int w : X) {
                if (x != w) {
                    m2.insert(w);
                }
            }
        }
    };
    auto m1_can_exchange = [&](int x, int y) {
        if constexpr (Matroid1::EXCHANGE) {
            return m1.exchange(x, y);
        } else {
            return (void)x, m1.check(y);
        }
    };
    auto m2_can_exchange = [&](int x, int y) {
        if constexpr (Matroid2::EXCHANGE) {
            return m2.exchange(x, y);
        } else {
            return (void)x, m2.check(y);
        }
    };

    while (true) {
        vector<int> Y; 

        int can_add_m2 = 0;

        fill(begin(dist), end(dist), make_pair(inf, n));
        fill(begin(prev), end(prev), -1);

        for (int u : elems) {
            exchange_graph[u].clear();
            if (!inset[u]) {
                Y.push_back(u);
            }
        }

        for (int y : Y) {
            if (m1.check(y)) {
                dist[y] = {cost[y], 0};
                prev[y] = n;
                spfa.push(y);
            }
            if (m2.check(y)) {
                exchange_graph[y].push_back(n);
                can_add_m2++;
            }
        }
        if (spfa.empty() || can_add_m2 == 0) {
            break;
        }

        

        for (int x : X) {
            m1_prepare(x);
            m2_prepare(x);
            for (int y : Y) {
                if (prev[y] == n || m1_can_exchange(x, y)) {
                    exchange_graph[x].push_back(y);
                }
                if (m2_can_exchange(x, y)) {
                    exchange_graph[y].push_back(x);
                }
            }
        }

        

        while (!spfa.empty()) {
            int u = spfa.pop();

            for (int v : exchange_graph[u]) {
                Cost weight = v < n ? inset[u] ? cost[v] : -cost[v] : 0;
                auto relax = make_pair(dist[u].first + weight, dist[u].second + 1);
                if (dist[v] > relax) {
                    dist[v] = relax;
                    prev[v] = u;
                    if (v != n) {
                        spfa.push(v);
                    }
                }
            }
        }

        

        if (prev[n] == -1) {
            break;
        }

        

        int u = prev[n];
        while (u != n) {
            inset[u] = !inset[u];
            u = prev[u];
        }

        X.clear(), m1.clear(), m2.clear();
        for (int v : elems) {
            if (inset[v]) {
                X.push_back(v);
                m1.insert(v);
                m2.insert(v);
            }
        }
    }

    vector<int> ans;
    Cost sum = 0;
    for (int u = 0; u < n; u++) {
        if (inset[u]) {
            ans.push_back(u);
            sum += cost[u];
        }
    }
    return make_pair(move(ans), sum);
}

template <typename Matroid1, typename Matroid2, typename Cost>
auto mincost_matroid_intersection_dijkstra(const vector<Cost>& cost, Matroid1 m1,
                                           Matroid2 m2) {
    assert(m1.ground_size() == m2.ground_size());

    static constexpr Cost inf = numeric_limits<Cost>::max();
    int n = m1.ground_size();

    vector<vector<int>> exchange_graph(n);
    vector<pair<Cost, int>> dist(n + 1);
    vector<int> prev(n + 1);
    vector<bool> inset(n);
    vector<int> X; 

    vector<Cost> pi(n);
    pairing_int_heap<less_container<vector<pair<Cost, int>>>> heap(n + 1, dist);

    

    vector<int> elems(n);
    iota(begin(elems), end(elems), 0);
    sort(begin(elems), end(elems), [&](int i, int j) { return cost[i] < cost[j]; });

    

    for (int u : elems) {
        if (m2.check(u) && m1.insert_check(u)) {
            X.push_back(u);
            m2.insert(u);
            inset[u] = true;
        } else if (!X.empty()) {
            break;
        }
    }

    auto m1_prepare = [&](int x) {
        if constexpr (!Matroid1::EXCHANGE) {
            m1.clear();
            for (int w : X) {
                if (x != w) {
                    m1.insert(w);
                }
            }
        }
    };
    auto m2_prepare = [&](int x) {
        if constexpr (!Matroid2::EXCHANGE) {
            m2.clear();
            for (int w : X) {
                if (x != w) {
                    m2.insert(w);
                }
            }
        }
    };
    auto m1_can_exchange = [&](int x, int y) {
        if constexpr (Matroid1::EXCHANGE) {
            return m1.exchange(x, y);
        } else {
            return (void)x, m1.check(y);
        }
    };
    auto m2_can_exchange = [&](int x, int y) {
        if constexpr (Matroid2::EXCHANGE) {
            return m2.exchange(x, y);
        } else {
            return (void)x, m2.check(y);
        }
    };

    while (true) {
        vector<int> Y; 

        int can_add_m2 = 0;

        fill(begin(dist), end(dist), make_pair(inf, n));
        fill(begin(prev), end(prev), -1);

        for (int u : elems) {
            exchange_graph[u].clear();
            if (!inset[u]) {
                Y.push_back(u);
            }
        }

        for (int y : Y) {
            if (m1.check(y)) {
                dist[y] = {cost[y] - pi[y], 0};
                prev[y] = n;
                heap.push(y);
            }
            if (m2.check(y)) {
                exchange_graph[y].push_back(n);
                can_add_m2++;
            }
        }
        if (heap.empty() || can_add_m2 == 0) {
            break;
        }

        

        for (int x : X) {
            m1_prepare(x);
            m2_prepare(x);
            for (int y : Y) {
                if (prev[y] == n || m1_can_exchange(x, y)) {
                    exchange_graph[x].push_back(y);
                }
                if (m2_can_exchange(x, y)) {
                    exchange_graph[y].push_back(x);
                }
            }
        }

        

        while (!heap.empty()) {
            int u = heap.pop();
            if (u == n) {
                break;
            }

            for (int v : exchange_graph[u]) {
                Cost w = v < n ? (inset[u] ? +1 : -1) * cost[v] + pi[u] - pi[v] : pi[u];
                assert(w >= 0);
                auto relax = make_pair(dist[u].first + w, dist[u].second + 1);
                if (dist[v] > relax) {
                    dist[v] = relax;
                    prev[v] = u;
                    heap.push_or_improve(v);
                }
            }
        }
        while (!heap.empty()) {
            heap.pop();
        }

        

        if (prev[n] == -1) {
            break;
        }

        

        int u = prev[n];
        while (u != n) {
            inset[u] = !inset[u];
            u = prev[u];
        }

        X.clear(), m1.clear(), m2.clear();
        for (int v : elems) {
            if (inset[v]) {
                X.push_back(v);
                m1.insert(v);
                m2.insert(v);
            }
        }

        u = prev[n];
        for (int v = 0; v < n; v++) {
            pi[v] += min(dist[u].first, dist[v].first);
        }
    }

    vector<int> ans;
    Cost sum = 0;
    for (int u = 0; u < n; u++) {
        if (inset[u]) {
            ans.push_back(u);
            sum += cost[u];
        }
    }
    return make_pair(move(ans), sum);
}

struct incremental_graphic_matroid {
    static constexpr bool EXCHANGE = false;
    vector<array<int, 2>> g;
    disjoint_set dsu, base;

    incremental_graphic_matroid(int V, const vector<array<int, 2>>& g,
                                const vector<array<int, 2>>& T)
        : g(g), base(V) {
        for (auto [u, v] : T) {
            base.join(u, v);
        }
        dsu = base;
    }

    int ground_size() const { return g.size(); }

    int num_vertices() const { return dsu.N; }

    bool check(int i) { return !dsu.same(g[i][0], g[i][1]); }

    bool insert_check(int i) { return dsu.join(g[i][0], g[i][1]); }

    void insert(int i) { dsu.join(g[i][0], g[i][1]); }

    void clear() { dsu = base; }
};

struct partition_matroid {
    static constexpr bool EXCHANGE = true;
    using Color = int16_t;
    using Limit = int16_t;
    vector<Color> color;
    vector<Limit> limit;
    vector<Limit> count;

    partition_matroid(const vector<Color>& color, const vector<Limit>& limit)
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
    disjoint_set bigdsu(N);
    for (auto [u, v] : rest) {
        if (bigdsu.join(u, v)) {
            ground_set.push_back({u, v});
        }
    }

    int G = ground_set.size();
    int E = special.size();
    int ans = INT_MAX;
    deg[K] = G;

    vector<int> ground_set_cost;
    for (auto [u, v] : ground_set) {
        ground_set_cost.push_back(weight[u][v]);
    }

    vector<int16_t> color(G);
    for (int i = 0; i < G; i++) {
        if (auto [u, v] = ground_set[i]; u < K) {
            color[i] = u;
        } else {
            color[i] = K;
        }
    }

    vector<array<int, 2>> T;
    disjoint_set_rollback dsu(K);

    y_combinator([&](auto self, int s, int Tcost) -> void {
        incremental_graphic_matroid M1(N, ground_set, T);
        partition_matroid M2(color, deg);
        auto [es, mcost] = mincost_matroid_intersection(ground_set_cost, M2, M1);

        if (es.size() + T.size() == size_t(N - 1)) {
            ans = min(ans, Tcost + mcost);
        }

        int t = dsu.time();
        for (int i = s; i < E; i++) {
            if (auto [u, v] = special[i]; !dsu.same(u, v) && deg[u] && deg[v]) {
                T.push_back({u, v});
                deg[u]--, deg[v]--;

                dsu.join(u, v);
                self(i + 1, Tcost + weight[u][v]);
                dsu.rollback(t);

                T.pop_back();
                deg[u]++, deg[v]++;
            }
        }
    })(0, 0);

    cout << ans << '\n';
    return 0;
}
