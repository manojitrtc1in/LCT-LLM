
using namespace std;





template<class Fun> class id6 {
    Fun fun_;
public:
    template<class T> explicit id6(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) id0(Fun &&fun) { return id6<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int highest_bit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

struct segment_change {
    int64_t to_set;

    

    segment_change(int64_t _to_set = -1) : to_set(_to_set) {}

    void reset() {
        to_set = -1;
    }

    bool has_change() const {
        return to_set != -1;
    }

    

    segment_change combine(const segment_change &other) const {
        return segment_change(other.to_set);
    }
};

struct segment {
    int64_t sum;

    

    segment(int64_t _sum = 0) : sum(_sum) {}

    bool empty() const {
        return sum == 0;
    }

    

    void apply(int length, const segment_change &change) {
        if(change.has_change()) {
            sum = change.to_set;
        }
    }

    void join(const segment &other) {
        sum = max(sum, other.sum);
    }

    

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    

    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void apply_and_combine(int position, int length, const segment_change &change) {
        tree[position].apply(length, change);
        if (position < tree_n) changes[position] = changes[position].combine(change);
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            apply_and_combine(2 * position, length / 2, changes[position]);
            apply_and_combine(2 * position + 1, length / 2, changes[position]);
            changes[position].reset();
        }
    }

    

    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = highest_bit(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    

    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            apply_and_combine(position, length, change);
        });
    }

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> highest_bit(i));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
    }

    void update_single(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;

        for (int up = highest_bit(tree_n); up > 0; up--)
            push_down(position >> up, 1 << up);

        tree[position] = seg;

        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    

    template<typename T_bool>
    int id3(T_bool &&should_join, int n, int first = 0) {
        assert(0 <= first && first <= n);
        segment current;

        

        if (!should_join(current, current))
            return first - 1;

        return id0([&](auto search, int position, int start, int end) -> int {
            if (end <= first) {
                return end;
            } else if (first <= start && end <= n && should_join(current, tree[position])) {
                current.join(tree[position]);
                return end;
            } else if (end - start == 1) {
                return start;
            }

            push_down(position, end - start);
            int mid = (start + end) / 2;
            int left = search(2 * position, start, mid);
            return left < mid ? left : search(2 * position + 1, mid, end);
        })(1, 0, tree_n);
    }
};
 


struct heavy_light_decomposition {
    vector<int> heavy_child, parent, head, depth, id5, label, order;
    vector<vector<int>> adj;
    vector<pair<int,int>> id4;
    seg_tree tree;
    int N;
 
    void init(int n) {
        N = n;
        heavy_child = vector<int>(n);
        parent = vector<int>(n);
        head = vector<int>(n);
        id5 = vector<int>(n, 1);
        label = vector<int>(n);
        depth = vector<int>(n);
        id4 = vector<pair<int,int>>(n);
        adj = vector<vector<int>>(n, vector<int>());
        iota(head.begin(), head.end(), 0);
        iota(parent.begin(), parent.end(), 0);
        tree.init(n);
    }
 
    

    void add_bidirectional_edge(const int &from, const int &to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
 
    

    void find_heavy_child(int node, int par) {
        parent[node] = par;
        int id1 = 0;
        heavy_child[node] = node;
 
        for(int child: adj[node]) {
            if(child == par) {
                continue;
            }
            depth[child] = depth[node] + 1;
            find_heavy_child(child, node);
            
            if(id5[child] > id1) {
                id1 = id5[child];
                heavy_child[node] = child;
            }
            id5[node] += id5[child];
        }
    }
 
    

    

    void accumulate_heavy_segments_and_relabel(int node) {
        order.push_back(node);
        label[node] = int(order.size()) - 1;
        id4[node].first = label[node];
        head[heavy_child[node]] = head[node];
        if(heavy_child[node] != node)
            accumulate_heavy_segments_and_relabel(heavy_child[node]);
 
        for(int child: adj[node]) {
            if(child != heavy_child[node] && child != parent[node]) {
                accumulate_heavy_segments_and_relabel(child);
            }
        }
        id4[node].second = int(order.size());
    }
 
 
    
    void build(vector<int> roots, const vector<int64_t> &values) {
        assert(int(values.size()) == N);
        if(roots.empty()) {
            for(int i = 0; i < N; i++) {
                if(parent[i] == i) {
                    find_heavy_child(i, i);
                    accumulate_heavy_segments_and_relabel(i);
                }
            }
            
        } else {
            for(int root: roots) {
                find_heavy_child(root, root);
                accumulate_heavy_segments_and_relabel(root);
            }
        }
        
        
        

        vector<segment> id2(int(values.size()));
        for(int i=0;i<N;i++) {
            id2[i] = segment(values[order[i]]);
        }
 
        tree.build(id2);
    }
 
    

    

    int64_t query (int u, int v) {
        segment res;
        while(true) {
            int x = head[u];
            int y = head[v];
            if(x == y) {
                int label1 = label[u];
                int label2 = label[v];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                segment tmp;
                

                

                tmp = tree.query(label1 + 1, label2 + 1);
                res.join(tmp);
                break;
            }
 
            if(depth[x] > depth[y]) {
                int label1 = label[u];
                int label2 = label[x];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                segment tmp = tree.query(label1, label2 + 1);
                res.join(tmp);
                u = parent[x];
            } else {
                int label1 = label[v];
                int label2 = label[y];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                segment tmp = tree.query(label1, label2 + 1);
                res.join(tmp);
                v = parent[y];
            }
        }
        return res.sum;
    }
 
    

    

    void update(int u, int v, const int64_t &val) {
        while(true) {
            int x = head[u];
            int y = head[v];
            if(x == y) {
                int label1 = label[u];
                int label2 = label[v];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                

                

                tree.update(label1 + 1, label2 + 1, segment_change(val));
                break;
            }
 
            if(depth[x] > depth[y]) {
                int label1 = label[u];
                int label2 = label[x];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                tree.update(label1, label2 + 1, segment_change(val));
                u = parent[x];
            } else {
                int label1 = label[v];
                int label2 = label[y];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                tree.update(label1, label2 + 1, segment_change(val));
                v = parent[y];
            }
        }
    }
 
    void update_entire_subtree(int node, const int64_t &val) {
        tree.update(id4[node].first, id4[node].second, segment_change(val));
    }
};

class DSU {
    public:
    vector<int> p;
    int n;
 
    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
 
    inline int find(int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
 
    inline bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

void run_cases() {
    int N, Q;
    cin >> N >> Q;

    vector<array<int, 4>> tree_edges, cycle_edges;
    DSU dsu(N);
    heavy_light_decomposition tree;
    tree.init(N);

    for(int i = 0; i < Q; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        if(dsu.find(u) == dsu.find(v)) {
            cycle_edges.push_back({u, v, x, i});
        } else {
            tree.add_bidirectional_edge(u, v);
            tree_edges.push_back({u, v, x, i});
            dsu.unite(u, v);
        }
    }

    vector<string> ans(Q);
    vector<int> depth(N);
    vector<int64_t> values(N);
    vector<int> xor_vals(N);

    vector<vector<int>> adj(N);
    for(auto edges: tree_edges) {
        int u = edges[0];
        int v = edges[1];
        int index = edges[3];

        adj[u].push_back(v);
        adj[v].push_back(u);
        ans[index] = "YES";
    }

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        if(par != -1) {
            depth[node] = depth[par] + 1;
        }
        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);
            }
        }
    };

    function<void(int,int)> dfs2 = [&](int node, int par) -> void {
        if(par != -1) {
            xor_vals[node] ^= xor_vals[par];
        }
        for(int child: adj[node]) {
            if(child != par) {
                dfs2(child, node);
            }
        }
    };

    vector<int> roots;
    for(int i = 0; i < N; i++) {
        if(dsu.find(i) == i) {
            roots.push_back(i);
            dfs(i, -1);
        }
    }

    for(auto edges: tree_edges) {
        int u = edges[0];
        int v = edges[1];
        int x = edges[2];

        if(depth[u] > depth[v]) {
            swap(u, v);
        }

        values[v] = x;
        xor_vals[v] = x;
    }

    for(int root: roots) {
        dfs2(root, -1);
    }

    tree.build(roots, values);

    for(auto edges: cycle_edges) {
        int u = edges[0];
        int v = edges[1];
        int x = edges[2];
        int index = edges[3];
        bool ok = false;

        int id7 = xor_vals[u] ^ xor_vals[v] ^ x;

        if(id7 == 1 && tree.query(u, v) <= 1) {
            ok = true;
            tree.update(u, v, 2);
        }

        ans[index] = ok ? "YES" : "NO";
    }

    for(auto u: ans) {
        cout << u << '\n';
    }

    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    


    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}