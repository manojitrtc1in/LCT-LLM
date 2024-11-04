#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;



template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T, bool maximum_mode = false>
struct RMQ {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    

    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    

    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, rev_tour_list;
    vector<int> heavy_root;
    RMQ<int> rmq;
    bool built;

    LCA(int _n = 0) {
        init(_n);
    }

    

    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        postorder.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }

    

    void init(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        

        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        

        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }

    int tour, post_tour;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }

        tour_end[node] = tour;
        postorder[node] = post_tour++;
    }

    void build(int root = -1, bool build_rmq = true) {
        parent.assign(n, -1);

        if (0 <= root && root < n)
            dfs(root, -1);

        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
                dfs(i, -1);

        tour = post_tour = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                

                euler.push_back(-1);
            }

        rev_tour_list = tour_list;
        reverse(rev_tour_list.begin(), rev_tour_list.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        if (build_rmq)
            rmq.build(euler_depths);

        built = true;
    }

    pair<int, array<int, 2>> get_diameter() const {
        assert(built);

        

        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};

        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            uxv_max = max(uxv_max, {ux_max.first + depth[node], {ux_max.second, node}});
        }

        return uxv_max;
    }

    

    array<int, 2> get_center() const {
        pair<int, array<int, 2>> diam = get_diameter();
        int length = diam.first, a = diam.second[0], b = diam.second[1];
        return {get_kth_node_on_path(a, b, length / 2), get_kth_node_on_path(a, b, (length + 1) / 2)};
    }

    

    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];

        if (a > b)
            swap(a, b);

        return euler[rmq.query_index(a, b + 1)];
    }

    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }

    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    

    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));

        

        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(parent[child] == a);
        assert(is_ancestor(child, b));
        return child;
    }

    int get_kth_ancestor(int a, int k) const {
        if (k > depth[a])
            return -1;

        while (a >= 0) {
            int root = heavy_root[a];

            if (depth[root] <= depth[a] - k)
                return tour_list[tour_start[a] - k];

            k -= depth[a] - depth[root] + 1;
            a = parent[root];
        }

        return a;
    }

    int get_kth_node_on_path(int a, int b, int k) const {
        int anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];
        assert(0 <= k && k <= first_half + second_half);

        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }

    

    

    int get_common_node(int a, int b, int c) const {
        

        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
        return x ^ y ^ z;
    }

    

    

    

    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = int(nodes.size());

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};

struct bipartite_union_find {
    vector<int> parent;
    vector<int> size;
    vector<bool> bipartite;
    vector<bool> edge_parity;
    int components = 0;

    bipartite_union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        bipartite.assign(n + 1, true);
        edge_parity.assign(n + 1, false);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        int root = find(parent[x]);
        edge_parity[x] = edge_parity[x] ^ edge_parity[parent[x]];
        return parent[x] = root;
    }

    

    bool query_component(int x, int y) {
        return find(x) == find(y);
    }

    

    bool query_parity(int x, int y) {
        assert(query_component(x, y));
        return edge_parity[x] ^ edge_parity[y];
    }

    

    pair<bool, bool> unite(int x, int y, bool different = true) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            bool consistent = !(edge_parity[x] ^ edge_parity[y] ^ different);
            bipartite[x_root] = bipartite[x_root] && consistent;
            return {false, consistent};
        }

        bool needed_parity = edge_parity[x] ^ edge_parity[y] ^ different;
        x = x_root;
        y = y_root;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        bipartite[x] = bipartite[x] && bipartite[y];
        edge_parity[y] = needed_parity;
        components--;
        return {true, true};
    }

    

    pair<bool, bool> add_different_edge(int x, int y) {
        return unite(x, y, true);
    }

    

    pair<bool, bool> add_same_edge(int x, int y) {
        return unite(x, y, false);
    }
};


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<array<int, 2>> edge_list(M);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        if (u > v)
            swap(u, v);

        edge_list[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(N, -1);
    vector<int> depth(N, -1);
    vector<bool> visited(N, false);
    LCA lca(N);

    auto dfs = y_combinator([&](auto self, int node) -> void {
        visited[node] = true;
        depth[node] = parent[node] < 0 ? 0 : depth[parent[node]] + 1;

        for (int neigh : adj[node])
            if (!visited[neigh] && neigh != parent[node]) {
                parent[neigh] = node;
                lca.add_edge(node, neigh);
                dbg(node + 1, neigh + 1);
                self(neigh);
            }
    });

    dfs(0);
    lca.build();

    auto remove_and_output = [&](int u, int v) -> void {
        dbg("remove", u + 1, v + 1);

        if (u > v)
            swap(u, v);

        bipartite_union_find UF(N);

        for (int e = 0; e < M; e++) {
            int a = edge_list[e][0], b = edge_list[e][1];

            if (a != u || b != v)
                UF.add_different_edge(a, b);
        }

        for (int i = 0; i < N; i++)
            assert(UF.bipartite[UF.find(i)]);

        vector<bool> solution(N);

        for (int i = 0; i < N; i++)
            solution[i] = UF.query_parity(0, i);

        if (u >= 0 && !solution[u]) {
            for (int i = 0; i < N; i++)
                solution[i] = !solution[i];
        }

        cout << "YES" << '\n';

        for (int i = 0; i < N; i++)
            cout << solution[i];

        cout << '\n';
    };

    vector<int> bad_edges;

    for (int e = 0; e < M; e++) {
        int u = edge_list[e][0], v = edge_list[e][1];

        if (depth[u] % 2 == depth[v] % 2)
            bad_edges.push_back(e);
    }

    if (bad_edges.empty()) {
        remove_and_output(-1, -1);
        return;
    }

    if (bad_edges.size() == 1) {
        remove_and_output(edge_list[bad_edges[0]][0], edge_list[bad_edges[0]][1]);
        return;
    }

    int low = -1, up = -1;

    for (int i = 0; i < int(bad_edges.size()); i++) {
        int u = edge_list[bad_edges[i]][0];
        int v = edge_list[bad_edges[i]][1];

        if (depth[u] > depth[v])
            swap(u, v);

        if (i == 0) {
            low = v;
            up = depth[v] - depth[u];
            continue;
        }

        int common = lca.get_lca(low, v);
        up = min(up - (depth[low] - depth[common]), depth[common] - depth[u]);
        low = common;
    }

    if (up <= 0) {
        cout << "NO" << '\n';
        return;
    }

    dbg(low + 1, up);
    vector<int> delta(up + 1, 0);

    for (int e = 0; e < M; e++) {
        int u = edge_list[e][0];
        int v = edge_list[e][1];

        if (depth[u] > depth[v])
            swap(u, v);

        if (depth[u] % 2 != depth[v] % 2 && u != parent[v]) {
            int common = lca.get_lca(low, v);
            int mark = min(up - (depth[low] - depth[common]), depth[common] - depth[u]);

            if (mark > 0) {
                int start = depth[low] - depth[common];
                delta[start]++;
                delta[start + mark]--;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < up; i++) {
        sum += delta[i];

        if (sum == 0) {
            remove_and_output(lca.get_kth_ancestor(low, i), lca.get_kth_ancestor(low, i + 1));
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
