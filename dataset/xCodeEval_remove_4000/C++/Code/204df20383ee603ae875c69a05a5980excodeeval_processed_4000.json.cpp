






using namespace std;


using namespace __gnu_pbds;

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    

    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        int levels = largest_bit(n) + 1;
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
        int level = largest_bit(b - a);
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
    vector<int> tour_start, tour_end, tour_list, postorder;
    vector<int> heavy_root;
    RMQ<int> rmq;

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
        tour_list.resize(n);
        postorder.resize(n);
        heavy_root.resize(n);
    }

    

    void init(const vector<vector<int>> &_adj) {
        init(_adj.size());
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
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

    int tour, id1;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = euler.size();
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
        postorder[node] = id1++;
    }

    void build() {
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0)
                dfs(i, -1);

        tour = id1 = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                

                euler.push_back(-1);
            }

        assert((int) euler.size() == 2 * n);
        vector<int> id4;
        id4.reserve(euler.size());

        for (int node : euler)
            id4.push_back(node < 0 ? node : depth[node]);

        rmq.build(id4);
    }

    pair<int, int> find_farthest(int node, int par, int path) const {
        pair<int, int> current = {path, node};

        for (int neighbor : adj[node])
            if (neighbor != par)
                current = max(current, find_farthest(neighbor, node, path + 1));

        return current;
    }

    

    pair<int, pair<int, int>> get_diameter() const {
        int u = find_farthest(0, -1, 0).second;
        pair<int, int> id6 = find_farthest(u, -1, 0);
        int v = id6.second;
        return {id6.first, {u, v}};
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

    

    

    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&id2 = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), id2);
        int k = nodes.size();

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin(), nodes.end(), id2);
        nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < (int) nodes.size(); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};

template<typename T>
struct id5 {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    id5(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }

    

    template<typename T_array>
    void build(const T_array &initial) {
        assert((int) initial.size() == tree_n);
        tree_sum = 0;

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    

    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    

    T query(int count) const {
        assert(count <= tree_n);
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    

    T query_suffix(int start) const {
        return tree_sum - query(start);
    }

    

    T query(int a, int b) const {
        return query(b) - query(a);
    }

    

    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;

        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }

        return sum;
    }

    bool set(int index, T value) {
        assert(0 <= index && index < tree_n);
        T current = get(index);

        if (current == value)
            return false;

        update(index, value - current);
        return true;
    }

    

    

    

    

    

    

    

    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};

template<typename T>
struct id7 {
    LCA &lca;
    int n = 0;
    bool vertex_mode;
    vector<T> values;
    id5<T> tour_tree, postorder_tree;
    T tree_sum = 0;

    

    id7(LCA &_lca) : lca(_lca) {}

    

    void init(bool _vertex_mode) {
        vertex_mode = _vertex_mode;
        n = lca.n;
        values.assign(n, 0);
        tour_tree.init(n);
        postorder_tree.init(n);
    }

    void update_node(int node, T change) {
        values[node] += change;
        tree_sum += change;
        tour_tree.update(lca.tour_start[node], change);
        postorder_tree.update(lca.postorder[node], change);
    }

    void update_edge(int a, int b, T change) {
        

        if (lca.parent[a] == b)
            swap(a, b);

        assert(a == lca.parent[b]);
        update_node(b, change);
    }

    

    T query_root_path(int node) const {
        

        

        return tour_tree.query(lca.tour_end[node]) - postorder_tree.query(lca.postorder[node]);
    }

    

    T query_path(int u, int v, int ancestor = -1) const {
        if (ancestor < 0)
            ancestor = lca.get_lca(u, v);

        return query_root_path(u) + query_root_path(v) - 2 * query_root_path(ancestor) + (vertex_mode ? values[ancestor] : 0);
    }

    

    T query_subtree(int node) const {
        return tour_tree.query(lca.tour_start[node], lca.tour_end[node]) - (vertex_mode ? 0 : values[node]);
    }
};


const int MOD = 1e9 + 7;

int64_t mod_pow(int64_t a, int64_t p, int64_t m = MOD) {
    int64_t result = 1;

    while (p > 0) {
        if (p & 1)
            result = result * a % m;

        a = a * a % m;
        p >>= 1;
    }

    return result;
}

vector<int> id0;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    id0.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {2};

    for (int p = 2; p <= maximum; p += 2) {
        prime[p] = p == 2;
        id0[p] = 2;
    }

    for (int p = 3; p * p <= maximum; p += 2)
        if (prime[p])
            for (int i = p * p; i <= maximum; i += 2 * p)
                if (prime[i]) {
                    prime[i] = false;
                    id0[i] = p;
                }

    for (int p = 3; p <= maximum; p += 2)
        if (prime[p]) {
            id0[p] = p;
            primes.push_back(p);
        }
}

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    unsigned operator()(unsigned x) const {
        static const unsigned id3 = hash32(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return hash32(x ^ id3);
    }
};

const int AX_MAX = 1e7 + 5;

struct query {
    int u, v, ancestor, answer;
};

int main() {
    sieve(AX_MAX);

    int N, Q;
    scanf("%d", &N);
    LCA lca(N);
    id7<int> solver(lca);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        lca.add_edge(u, v);
    }

    lca.build();
    solver.init(true);
    gp_hash_table<int, vector<pair<int, int>>, safe_hash32> prime_nodes, prime_queries;

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);

        while (a > 1) {
            int p = id0[a];
            int power = 0;

            do {
                a /= p;
                power++;
            } while (a % p == 0);

            prime_nodes[p].emplace_back(power, i);
        }
    }

    scanf("%d", &Q);
    vector<query> queries(Q);

    for (int q = 0; q < Q; q++) {
        int x;
        scanf("%d %d %d", &queries[q].u, &queries[q].v, &x);
        queries[q].u--; queries[q].v--;
        queries[q].ancestor = solver.lca.get_lca(queries[q].u, queries[q].v);
        queries[q].answer = 1;

        while (x > 1) {
            int p = id0[x];
            int power = 0;

            do {
                x /= p;
                power++;
            } while (x % p == 0);

            prime_queries[p].emplace_back(power, q);
        }
    }

    for (auto &pq : prime_queries) {
        int p = pq.first;
        vector<pair<int, int>> &p_nodes = prime_nodes[p];
        vector<pair<int, int>> &p_queries = pq.second;
        sort(p_queries.begin(), p_queries.end());
        sort(p_nodes.rbegin(), p_nodes.rend());
        vector<pair<int, int>> node_updates;
        int power = 0;

        for (pair<int, int> &p_query : p_queries) {
            int q_power = p_query.first, q_index = p_query.second;

            if (q_power > power) {
                for (pair<int, int> &p_node : p_nodes) {
                    int n_power = p_node.first, n_index = p_node.second;

                    if (n_power < power)
                        break;

                    int change = min(q_power, n_power) - power;
                    solver.update_node(n_index, change);
                    node_updates.emplace_back(n_index, change);
                }

                power = q_power;
            }

            int exponent = solver.query_path(queries[q_index].u, queries[q_index].v, queries[q_index].ancestor);
            queries[q_index].answer = (int64_t) queries[q_index].answer * mod_pow(p, exponent) % MOD;
        }

        

        for (pair<int, int> &update : node_updates)
            solver.update_node(update.first, -update.second);
    }

    for (int q = 0; q < Q; q++)
        printf("%d\n", queries[q].answer);
}
