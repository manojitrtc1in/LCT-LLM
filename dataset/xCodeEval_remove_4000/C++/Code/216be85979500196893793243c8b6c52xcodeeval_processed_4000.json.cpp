














using namespace std;



template<class Fun> class id10 {
    Fun fun_;
public:
    template<class T> explicit id10(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) id3(Fun &&fun) { return id10<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }






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
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    

    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
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
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, id5;
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

    int tour, id0;

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
        postorder[node] = id0++;
    }

    void build(int root = -1, bool id1 = true) {
        parent.assign(n, -1);

        if (0 <= root && root < n)
            dfs(root, -1);

        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
                dfs(i, -1);

        tour = id0 = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                

                euler.push_back(-1);
            }

        id5 = tour_list;
        reverse(id5.begin(), id5.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> id4;
        id4.reserve(euler.size());

        for (int node : euler)
            id4.push_back(node < 0 ? node : depth[node]);

        if (id1)
            rmq.build(id4);

        built = true;
    }

    pair<int, array<int, 2>> get_diameter() const {
        assert(built);

        

        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> id11 = {-1, {-1, -1}};

        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            id11 = max(id11, {ux_max.first + depth[node], {ux_max.second, node}});
        }

        return id11;
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

    

    

    int get_common_node(int a, int b, int c) const {
        

        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
        x = depth[y] > depth[x] ? y : x;
        x = depth[z] > depth[x] ? z : x;
        return x;
    }

    

    

    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&id2 = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), id2);
        int k = int(nodes.size());

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), id2);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), id2);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};

using hash_t = uint32_t;

struct segment_change {
    hash_t to_xor;

    segment_change(hash_t id9 = 0) : to_xor(id9) {}
};

struct segment {
    hash_t hash;

    segment(hash_t _hash = 0) : hash(_hash) {}

    void apply(int length, const segment_change &change) {
        assert(length == 1);
        hash ^= change.to_xor;
    }

    void join(const segment &other) {
        hash ^= other.hash;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct id8 {
    struct node {
        segment seg;
        int left = -1, right = -1;
    };

    int tree_n = 0;
    vector<node> tree;
    int reserve_size = id7;

    id8(int n = -1, int max_updates = 0) {
        if (n >= 0)
            init(n, max_updates);
    }

    void init(int n, int max_updates = 0) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        reserve_size = id7;

        if (max_updates > 0) {
            int tree_height = 32 - __builtin_clz(tree_n);
            reserve_size = 2 * tree_n + max_updates * tree_height;
            tree.reserve(reserve_size);
        }

        tree.assign(2 * tree_n, node());

        for (int i = 1; i < tree_n; i++) {
            tree[i].left = 2 * i;
            tree[i].right = 2 * i + 1;
        }
    }

    int left(int position) const { return tree[position].left; }
    int right(int position) const { return tree[position].right; }
    segment& seg(int position) { return tree[position].seg; }
    const segment& seg(int position) const { return tree[position].seg; }

    

    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            seg(tree_n + i) = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            seg(position).join(seg(left(position)), seg(right(position)));
    }

    int make_copy(int position) {
        assert(0 <= position && position < int(tree.size()));
        tree.push_back(tree[position]);
        assert(int(tree.size()) <= reserve_size);
        return int(tree.size()) - 1;
    }

    void _query_tree(int position, int start, int end, int a, int b, segment &answer) const {
        if (a <= start && end <= b) {
            answer.join(seg(position));
            return;
        }

        if (left(position) < 0 || right(position) < 0)
            return;

        int mid = (start + end) / 2;
        if (a < mid) _query_tree(left(position), start, mid, a, b, answer);
        if (b > mid) _query_tree(right(position), mid, end, a, b, answer);
    }

    segment query(int root, int a, int b) const {
        assert(root > 0 && 0 <= a && a <= b && b <= tree_n);
        segment answer;
        _query_tree(root, 0, tree_n, a, b, answer);
        return answer;
    }

    

    

    void set_left(int position, int result) { tree[position].left = result; }
    void set_right(int position, int result) { tree[position].right = result; }

    template<typename T_range_op>
    int _update_tree(int position, int start, int end, int index, T_range_op &&range_op) {
        position = make_copy(position);

        if (end - start == 1 && start == index) {
            range_op(position, end - start);
            return position;
        }

        if (left(position) < 0 || right(position) < 0)
            return position;

        int mid = (start + end) / 2;

        if (index < mid)
            set_left(position, _update_tree(left(position), start, mid, index, range_op));
        else
            set_right(position, _update_tree(right(position), mid, end, index, range_op));

        seg(position).join(seg(left(position)), seg(right(position)));
        return position;
    }

    int update(int root, int index, const segment_change &change) {
        assert(root > 0 && 0 <= index && index < tree_n);

        return _update_tree(root, 0, tree_n, index, [&](int position, int length) {
            seg(position).apply(length, change);
        });
    }

    int update(int root, int index, const segment &new_seg) {
        assert(root > 0 && 0 <= index && index < tree_n);

        return _update_tree(root, 0, tree_n, index, [&](int position, int) {
            seg(position) = new_seg;
        });
    }

    

    void undo_updates(int root) {
        assert(root >= 2 * tree_n && root <= int(tree.size()));
        tree.resize(root);
    }

    vector<segment> to_array(int root) const {
        assert(root > 0);
        vector<int> level = {root};

        while (left(level.front()) >= 0) {
            vector<int> new_level;
            new_level.reserve(2 * level.size());

            for (int x : level) {
                new_level.push_back(left(x));
                new_level.push_back(right(x));
            }

            swap(level, new_level);
        }

        vector<segment> segs(level.size());

        for (int i = 0; i < int(level.size()); i++)
            segs[i] = seg(level[i]);

        return segs;
    }

    

    template<typename T_bool>
    int id6(array<int, 2> roots, T_bool &&should_join, int n, int first = 0) const {
        assert(roots[0] > 0 && roots[1] > 0 && 0 <= first && first <= n);
        segment current;

        

        if (!should_join(current, current))
            return first - 1;

        return id3([&](auto search, array<int, 2> position, int start, int end) -> int {
            if (end <= first)
                return end;
            else if (first <= start && end <= n && should_join(seg(position[0]), seg(position[1])))
                return end;
            else if (end - start == 1)
                return start;

            int mid = (start + end) / 2;
            int x = search(array<int, 2>{left(position[0]), left(position[1])}, start, mid);
            return x < mid ? x : search(array<int, 2>{right(position[0]), right(position[1])}, mid, end);
        })(roots, 0, tree_n);
    }
};


auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);


    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);

    for (auto &a : A) {
        cin >> a;
        a--;
    }

    LCA lca(N);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        lca.add_edge(x, y);
    }

    lca.build();
    vector<hash_t> weights(N);

    for (auto &w : weights)
        w = hash_t(rng());

    id8 tree(N, N + 1);
    tree.build(vector<segment>(N));
    vector<int> roots(N, -1);

    for (int node : lca.tour_list) {
        roots[node] = lca.parent[node] < 0 ? 1 : roots[lca.parent[node]];
        roots[node] = tree.update(roots[node], A[node], segment_change(weights[A[node]]));
    }

    for (int q = 0; q < Q; q++) {
        int u, v, L, R;
        cin >> u >> v >> L >> R;
        u--; v--; L--;
        int u_root = roots[u], v_root = roots[v];
        int anc = lca.get_lca(u, v);
        u_root = tree.update(u_root, A[anc], segment_change(weights[A[anc]]));

        int answer = tree.id6({u_root, v_root}, [&](const segment &a, const segment &b) {
            return a.hash == b.hash;
        }, N, L);

        cout << (answer >= R ? -1 : answer + 1) << '\n';
        tree.undo_updates(u_root);
    }
}
