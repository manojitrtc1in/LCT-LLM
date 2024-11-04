





using namespace std;



template<typename T>
using pbds_pq = __gnu_pbds::priority_queue<T, less<T>>;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }









template<char MIN_CHAR = 'a'>
struct id1 {
    struct node {
        

        

        

        

        

        

        

        

        

        int suff = -1, dict = -1, depth = 0;
        int word_index = -1, word_count = 0;
        int first_child = -1;
        unsigned child_mask = 0;

        int get_child(char c) const {
            int bit = c - MIN_CHAR;

            if ((child_mask >> bit & 1) == 0)
                return -1;

            assert(first_child >= 0);
            return first_child + __builtin_popcount(child_mask & ((1 << bit) - 1));
        }
    };

    vector<node> nodes;
    int W;
    vector<string> words;
    vector<int> word_location;
    vector<int> word_indices_by_depth;
    vector<int> defer;

    id1(const vector<string> &_words = {}) {
        if (!_words.empty())
            build(_words);
    }

    

    vector<vector<int>> build_suffix_adj() const {
        vector<vector<int>> adj(nodes.size());

        for (int i = 1; i < int(nodes.size()); i++)
            adj[nodes[i].suff].push_back(i);

        return adj;
    }

    int get_or_add_child(int current, char c) {
        int bit = c - MIN_CHAR;

        if (nodes[current].child_mask >> bit & 1)
            return nodes[current].get_child(c);

        assert(nodes[current].child_mask >> bit == 0);
        int index = int(nodes.size());
        nodes[current].child_mask |= 1 << bit;

        if (nodes[current].first_child < 0)
            nodes[current].first_child = index;

        nodes.emplace_back();
        nodes.back().depth = nodes[current].depth + 1;
        return index;
    }

    

    

    int get_suffix_link(int location, char c) const {
        int child;

        while (location >= 0 && (child = nodes[location].get_child(c)) < 0)
            location = nodes[location].suff;

        return location < 0 ? 0 : child;
    }

    void build(const vector<string> &_words) {
        nodes = {node()};
        words = _words;
        W = int(words.size());
        stable_sort(words.begin(), words.end());
        word_location.assign(W, 0);
        vector<int> remaining(W);
        int n_rem = W;

        for (int i = 0; i < W; i++)
            remaining[i] = i;

        for (int depth = 0; n_rem > 0; depth++) {
            int id0 = 0;

            for (int i = 0; i < n_rem; i++) {
                int word = remaining[i];
                int &location = word_location[word];
                location = get_or_add_child(location, words[word][depth]);

                if (depth == int(words[word].size()) - 1) {
                    if (nodes[location].word_index < 0)
                        nodes[location].word_index = word;

                    nodes[location].word_count++;
                } else {
                    remaining[id0++] = word;
                }
            }

            n_rem = id0;
        }

        int max_depth = 0;
        defer.resize(W);

        for (int i = 0; i < W; i++) {
            max_depth = max(max_depth, int(words[i].size()));
            defer[i] = nodes[word_location[i]].word_index;
        }

        

        word_indices_by_depth.resize(W);
        vector<int> depth_freq(max_depth + 1, 0);

        for (int i = 0; i < W; i++)
            depth_freq[words[i].size()]++;

        for (int i = max_depth - 1; i >= 0; i--)
            depth_freq[i] += depth_freq[i + 1];

        for (int i = 0; i < W; i++)
            word_indices_by_depth[--depth_freq[words[i].size()]] = i;

        

        for (int i = 0; i < int(nodes.size()); i++) {
            unsigned child_mask = nodes[i].child_mask;

            while (child_mask != 0) {
                int bit = __builtin_ctz(child_mask);
                char c = char(MIN_CHAR + bit);
                int index = nodes[i].get_child(c);
                child_mask ^= 1 << bit;

                

                int suffix_parent = get_suffix_link(nodes[i].suff, c);
                nodes[index].suff = suffix_parent;
                nodes[index].word_count += nodes[suffix_parent].word_count;
                nodes[index].dict = nodes[suffix_parent].word_index < 0 ? nodes[suffix_parent].dict : suffix_parent;
            }
        }
    }

    

    vector<int> count_matches(const string &text) const {
        vector<int> matches(W, 0);
        int current = 0;

        for (char c : text) {
            current = get_suffix_link(current, c);
            int dict_node = nodes[current].word_index < 0 ? nodes[current].dict : current;

            if (dict_node >= 0)
                matches[nodes[dict_node].word_index]++;
        }

        

        for (int word_index : word_indices_by_depth) {
            int location = word_location[word_index];
            int dict_node = nodes[location].dict;

            if (dict_node >= 0)
                matches[nodes[dict_node].word_index] += matches[word_index];
        }

        for (int i = 0; i < W; i++)
            matches[i] = matches[defer[i]];

        return matches;
    }

    

    vector<int> count_matches_by_position(const string &text) const {
        vector<int> matches(text.size());
        int current = 0;

        for (int i = 0; i < int(text.size()); i++) {
            current = get_suffix_link(current, text[i]);
            matches[i] = nodes[current].word_count;
        }

        return matches;
    }

    

    int64_t count_total_matches(const string &text) const {
        int64_t matches = 0;
        int current = 0;

        for (char c : text) {
            current = get_suffix_link(current, c);
            matches += nodes[current].word_count;
        }

        return matches;
    }
};


struct segment_change {
    

    static const int id2 = numeric_limits<int>::lowest();

    int to_set;

    segment_change(int _to_set = id2) : to_set(_to_set) {}

    bool has_set() const {
        return to_set != id2;
    }

    void reset() {
        to_set = id2;
    }

    bool has_change() const {
        return has_set();
    }

    

    segment_change combine(const segment_change &other) const {
        return other.has_set() ? other : *this;
    }
};

struct segment {
    int maximum;

    segment(int _maximum = -1) : maximum(_maximum) {}

    void apply(int, const segment_change &change) {
        if (change.has_set())
            maximum = change.to_set;
    }

    void join(const segment &other) {
        maximum = max(maximum, other.maximum);
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

        if (position < tree_n)
            changes[position] = changes[position].combine(change);
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

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
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
};


struct heavy_light {
    int n = 0;
    bool vertex_mode;

    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;

    vector<int> chain_root, chain_size;
    vector<seg_tree> chain_tree;

    heavy_light() {}

    heavy_light(int _n, bool _vertex_mode) {
        init(_n, _vertex_mode);
    }

    void init(int _n, bool _vertex_mode) {
        n = _n;
        vertex_mode = _vertex_mode;

        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);

        chain_root.resize(n);
        chain_size.assign(n, 0);
        chain_tree.assign(n, {});
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

    void chain_dfs(int node, bool heavy) {
        chain_root[node] = heavy ? chain_root[parent[node]] : node;
        chain_size[chain_root[node]]++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            chain_dfs(child, heavy_child);
            heavy_child = false;
        }
    }

    void build(const segment &initial) {
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                dfs(i, -1);
                chain_dfs(i, false);
            }

        for (int i = 0; i < n; i++)
            if (chain_root[i] == i) {
                chain_tree[i].init(chain_size[i]);
                chain_tree[i].build(vector<segment>(chain_size[i], initial));
            }
    }

    template<typename T_tree_op>
    void process_path(int u, int v, T_tree_op &&op) {
        while (chain_root[u] != chain_root[v]) {
            

            if (depth[chain_root[u]] > depth[chain_root[v]])
                swap(u, v);

            int root = chain_root[v];
            op(chain_tree[root], 0, depth[v] - depth[root] + 1);
            v = parent[root];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        

        int root = chain_root[v];
        op(chain_tree[root], depth[u] - depth[root] + (vertex_mode ? 0 : 1), depth[v] - depth[root] + 1);
    }

    segment query_path(int u, int v) {
        segment answer;

        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            answer.join(tree.query(a, b));
        });

        return answer;
    }

    void update_path(int u, int v, const segment_change &change) {
        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            tree.update(a, b, change);
        });
    }
};


int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);


    int N, M;
    cin >> N >> M;
    vector<string> names(N);

    for (auto &name : names)
        cin >> name;

    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int a, int b) {
        return names[a] < names[b];
    });

    vector<int> sorted_location(N);

    for (int i = 0; i < N; i++)
        sorted_location[order[i]] = i;

    id1 AC(names);
    int A = int(AC.nodes.size());
    vector<vector<int>> adj = AC.build_suffix_adj();
    assert(int(adj.size()) == A);
    heavy_light HLD(A, true);

    for (int i = 0; i < A; i++)
        for (int child : adj[i])
            HLD.add_edge(i, child);

    HLD.build(segment(-1));
    assert(int(AC.word_location.size()) == N);

    for (int loc : AC.word_location)
        HLD.update_path(loc, loc, segment_change(0));

    vector<pbds_pq<int>> same(A);
    vector<pbds_pq<int>::point_iterator> its(N);

    for (int i = 0; i < N; i++)
        its[i] = same[AC.word_location[i]].push(0);

    for (int q = 0; q < M; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int who, x;
            cin >> who >> x;
            who--;
            who = sorted_location[who];
            int node = AC.word_location[who];
            same[node].modify(its[who], x);
            HLD.update_path(node, node, segment_change(same[node].top()));
        } else {
            string str;
            cin >> str;
            int current = 0, answer = -1;

            for (auto &ch : str) {
                current = AC.get_suffix_link(current, ch);
                answer = max(answer, HLD.query_path(current, 0).maximum);
            }

            cout << answer << '\n';
        }
    }
}
