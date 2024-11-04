















using namespace std;



template<class Fun> class id9 {
    Fun fun_;
public:
    template<class T> explicit id9(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) id4(Fun &&fun) { return id9<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }






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

template<typename T_weight>
struct id8 {
    struct edge {
        int node = -1;
        T_weight weight = 0;

        edge() {}

        edge(int _node, T_weight _weight) : node(_node), weight(_weight) {}
    };

    int n = 0;
    vector<vector<edge>> adj;
    vector<int> parent, depth, subtree_size;
    vector<T_weight> weighted_depth, up_weight;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, id7;
    vector<int> heavy_root;
    RMQ<int> rmq;
    bool built;

    id8(int _n = 0) {
        init(_n);
    }

    

    id8(const vector<vector<edge>> &_adj) {
        init(_adj);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        weighted_depth.resize(n);
        up_weight.assign(n, 0);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        postorder.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }

    

    void init(const vector<vector<edge>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }

    void add_edge(int a, int b, T_weight weight) {
        adj[a].emplace_back(b, weight);
        adj[b].emplace_back(a, weight);
    }

    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }

    void erase_edge(int from, int to) {
        for (edge &e : adj[from])
            if (e.node == to) {
                swap(e, adj[from].back());
                adj[from].pop_back();
                return;
            }
    }

    void dfs(int node, int par, T_weight weight) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;
        weighted_depth[node] = weight;

        

        erase_edge(node, par);

        for (edge &e : adj[node]) {
            up_weight[e.node] = e.weight;
            dfs(e.node, node, weight + e.weight);
            subtree_size[node] += subtree_size[e.node];
        }

        

        sort(adj[node].begin(), adj[node].end(), [&](const edge &a, const edge &b) {
            return subtree_size[a.node] > subtree_size[b.node];
        });
    }

    int tour, id1;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (edge &e : adj[node]) {
            tour_dfs(e.node, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }

        tour_end[node] = tour;
        postorder[node] = id1++;
    }

    void build(int root = -1, bool id2 = true) {
        parent.assign(n, -1);

        if (0 <= root && root < n)
            dfs(root, -1, 0);

        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
                dfs(i, -1, 0);

        tour = id1 = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                

                euler.push_back(-1);
            }

        id7 = tour_list;
        reverse(id7.begin(), id7.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> id5;
        id5.reserve(euler.size());

        for (int node : euler)
            id5.push_back(node < 0 ? node : depth[node]);

        if (id2)
            rmq.build(id5);

        built = true;
    }

    pair<T_weight, array<int, 2>> get_diameter() const {
        assert(built);

        

        

        pair<T_weight, int> u_max = {-1, -1};
        pair<T_weight, int> ux_max = {-1, -1};
        pair<T_weight, array<int, 2>> id10 = {-1, {-1, -1}};

        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {weighted_depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * weighted_depth[node], u_max.second});
            id10 = max(id10, {ux_max.first + weighted_depth[node], {ux_max.second, node}});
        }

        return id10;
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

    T_weight get_weighted_dist(int a, int b) const {
        return weighted_depth[a] + weighted_depth[b] - 2 * weighted_depth[get_lca(a, b)];
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

    

    

    int get_common_node(int a, int b, int c) const {
        

        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
        return x ^ y ^ z;
    }

    

    

    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&id3 = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), id3);
        int k = int(nodes.size());

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), id3);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), id3);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};


const int64_t INF64 = int64_t(2e18) + 5;
const char MIN_CHAR = 'A';

struct query {
    vector<int> pass, fine;
    int index;
};

template<typename T>
int id6(vector<T> &v, T x) {
    int index = int(v.size());
    v.push_back(x);

    while (index > 0 && x < v[index - 1]) {
        swap(v[index], v[index - 1]);
        index--;
    }

    return index;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);


    int N;
    cin >> N;
    id8<int64_t> lca(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        lca.add_edge(u, v, t);
    }

    lca.build(0, false);
    int K;
    string zone;
    cin >> K >> zone;
    assert(zone[0] == 'A');
    vector<int> pass(K), fine(K);

    for (auto &p : pass)
        cin >> p;

    for (auto &f : fine)
        cin >> f;

    int T, Q;
    cin >> T >> Q;
    vector<vector<query>> queries(N);
    int query_count = 0;

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            char z;
            int c;
            cin >> z >> c;
            pass[z - MIN_CHAR] = c;
        } else if (type == 2) {
            char z;
            int c;
            cin >> z >> c;
            fine[z - MIN_CHAR] = c;
        } else {
            int u;
            cin >> u;
            u--;
            query qry;
            qry.pass = pass;
            qry.fine = fine;
            qry.index = query_count++;
            queries[u].push_back(qry);
        }
    }

    vector<int64_t> answers(query_count, -1);

    id4([&](auto self, int node, vector<pair<int, int>> events, vector<int64_t> zone_count,
                     int start_mask, int64_t zone_start, char previous_zone) -> int64_t {
        int64_t depth = lca.weighted_depth[node];
        bool id0 = zone[node] != previous_zone;

        if (id0) {
            int64_t parent_depth = lca.weighted_depth[lca.parent[node]];
            int z = previous_zone - MIN_CHAR;
            int64_t previous_length = parent_depth - zone_start;
            zone_count[z] = previous_length / T;

            int before = int(zone_start % T);
            int after = int(parent_depth % T);

            pair<int, int> before_event = {before + 1, z};
            pair<int, int> after_event = {after + 1, z};
            id6(events, before_event);
            id6(events, after_event);

            if (after < before)
                start_mask |= 1 << z;

            zone_start = parent_depth;
            previous_zone = zone[node];
        }

        int index = int(lower_bound(events.begin(), events.end(), make_pair(int(depth % T + 1), 0)) - events.begin());
        int64_t event_mask = 1LL << index;

        for (id8<int64_t>::edge &e : lca.adj[node])
            event_mask |= self(e.node, events, zone_count, start_mask, zone_start, previous_zone);

        for (query &qry : queries[node]) {
            int current = zone[node] - MIN_CHAR;
            int mask = start_mask;
            int64_t cost = 0;

            auto eval_zone = [&](int z) -> int64_t {
                int64_t count = zone_count[z] + (mask >> z & 1);
                return count <= qry.pass[z] / qry.fine[z] ? qry.fine[z] * count : qry.pass[z];
            };

            for (int z = 0; z < current; z++)
                cost += eval_zone(z);

            int64_t best = INF64;

            for (int i = 0; i < int(events.size()); i++) {
                if (event_mask >> i & 1)
                    best = min(best, cost);

                int z = events[i].second;
                cost -= eval_zone(z);
                mask ^= 1 << z;
                cost += eval_zone(z);
            }

            if (event_mask >> events.size() & 1)
                best = min(best, cost);

            answers[qry.index] = best;
        }

        return id0 ? 0 : event_mask;
    })(0, vector<pair<int, int>>(), vector<int64_t>(K, 0), 0, 0, zone[0]);

    for (auto &ans : answers)
        cout << ans << '\n';
}
