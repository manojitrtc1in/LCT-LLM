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

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }

        if (number != 0 || length == 0)
            write_char(char(number + '0'));

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        

        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}

using splay_key = pair<int, int>;

struct splay_node {
    splay_node *parent = nullptr, *child[2] = {nullptr, nullptr};
    splay_key key;
    int size = 1;

    


    friend int get_size(splay_node *x) {
        return x == nullptr ? 0 : x->size;
    }

    

    

    


    int parent_index() const {
        return parent == nullptr ? -1 : int(this == parent->child[1]);
    }

    void set_child(int index, splay_node *x) {
        child[index] = x;

        if (x != nullptr)
            x->parent = this;
    }

    void join() {
        size = get_size(child[0]) + get_size(child[1]) + 1;
        

    }
};

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 splay_rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
int64_t splay_count = 0;

struct splay_tree {
    static const int POOL_SIZE = 10000;
    static vector<splay_node*> node_pool;
    static vector<splay_node*> pointers_to_delete;

    static splay_node* new_node(const splay_key &key) {
        if (node_pool.empty()) {
            splay_node *ptr = new splay_node[POOL_SIZE];
            pointers_to_delete.push_back(ptr);
            node_pool.reserve(POOL_SIZE);

            for (int i = POOL_SIZE - 1; i >= 0; i--)
                node_pool.push_back(ptr + i);
        }

        splay_node *node = node_pool.back();
        node_pool.pop_back();
        *node = splay_node();
        node->key = key;
        node->join();
        return node;
    }

    static bool _exit_delete_setup;

    static void _delete_pointers() {
        for (splay_node *node : pointers_to_delete)
            delete[] node;

        pointers_to_delete.clear();
    }

    ~splay_tree() {
        if (!_exit_delete_setup) {
            atexit(_delete_pointers);
            _exit_delete_setup = true;
        }
    }

    splay_node *root = nullptr;

    splay_tree(const vector<splay_key> &keys = {}) {
        init(keys);
    }

    splay_node *construct(const vector<splay_key> &keys, int start, int end) {
        if (start >= end)
            return nullptr;

        if (end - start == 1)
            return new_node(keys[start]);

        int mid = (start + end) / 2;
        splay_node *current = new_node(keys[mid]);
        current->set_child(0, construct(keys, start, mid));
        current->set_child(1, construct(keys, mid + 1, end));
        current->join();
        return current;
    }

    

    void init(vector<splay_key> keys) {
        if (!is_sorted(keys.begin(), keys.end()))
            sort(keys.begin(), keys.end());

        set_root(construct(keys, 0, int(keys.size())));
    }

    bool empty() const {
        return root == nullptr;
    }

    int size() const {
        return get_size(root);
    }

    splay_node *set_root(splay_node *x) {
        if (x != nullptr)
            x->parent = nullptr;

        return root = x;
    }

    void rotate_up(splay_node *x, bool x_join = true) {
        splay_node *p = x->parent, *gp = p->parent;
        int index = x->parent_index();

        if (gp == nullptr)
            set_root(x);
        else
            gp->set_child(p->parent_index(), x);

        p->set_child(index, x->child[!index]);
        x->set_child(!index, p);
        p->join();

        if (x_join)
            x->join();
    }

    void splay(splay_node *x) {
        splay_count++;

        while (x != root) {
            splay_node *p = x->parent;

            if (p != root)
                rotate_up(x->parent_index() == p->parent_index() ? p : x, false);

            rotate_up(x, false);
        }

        x->join();
    }

    static constexpr double SPLAY_RNG_RANGE = double(splay_rng.max()) + 1.0;
    static constexpr double LOG_CONSTANT = 2.0;
    static constexpr double SPLAY_PROB = 0.25;
    static const int SIZE_CUTOFF = 400;

    void check_splay(splay_node *x, int depth) {
        assert(x != nullptr);
        int n = size(), log_n = 32 - __builtin_clz(n);

        

        if (depth > LOG_CONSTANT * log_n || (n <= SIZE_CUTOFF && double(splay_rng()) < SPLAY_PROB * SPLAY_RNG_RANGE))
            splay(x);
    }

    pair<splay_node*, int> insert(const splay_key &key, bool require_unique = false) {
        return insert(new_node(key), require_unique);
    }

    

    pair<splay_node*, int> insert(splay_node *x, bool require_unique = false) {
        if (root == nullptr)
            return {set_root(x), 0};

        splay_node *current = root, *previous = nullptr;
        int below = 0, depth = 0;

        while (current != nullptr) {
            previous = current;
            depth++;

            if (current->key < x->key) {
                below += get_size(current->child[0]) + 1;
                current = current->child[1];
            } else {
                

                if (require_unique && !(x->key < current->key)) {
                    below += get_size(current->child[0]);
                    check_splay(current, depth);
                    return {current, below};
                }

                current = current->child[0];
            }
        }

        previous->set_child(int(previous->key < x->key), x);
        check_splay(x, depth);

        for (splay_node *node = x; node != nullptr; node = node->parent)
            node->join();

        return {x, below};
    }

    splay_node *begin() {
        if (root == nullptr)
            return nullptr;

        splay_node *x = root;
        int depth = 0;

        while (x->child[0] != nullptr) {
            x = x->child[0];
            depth++;
        }

        check_splay(x, depth);
        return x;
    }

    

    

    splay_node *successor(splay_node *x) const {
        if (x == nullptr)
            return nullptr;

        if (x->child[1] != nullptr) {
            x = x->child[1];

            while (x->child[0] != nullptr)
                x = x->child[0];

            return x;
        }

        while (x->parent_index() == 1)
            x = x->parent;

        return x->parent;
    }

    splay_node *predecessor(splay_node *x) const {
        if (x == nullptr)
            return nullptr;

        if (x->child[0] != nullptr) {
            x = x->child[0];

            while (x->child[1] != nullptr)
                x = x->child[1];

            return x;
        }

        while (x->parent_index() == 0)
            x = x->parent;

        return x->parent;
    }

    splay_node *last() {
        if (root == nullptr)
            return nullptr;

        splay_node *x = root;
        int depth = 0;

        while (x->child[1] != nullptr) {
            x = x->child[1];
            depth++;
        }

        check_splay(x, depth);
        return x;
    }

    void clear() {
        vector<splay_node*> nodes;
        nodes.reserve(size());

        for (splay_node *node = begin(); node != nullptr; node = successor(node))
            nodes.push_back(node);

        for (splay_node *node : nodes) {
            

            *node = splay_node();
            node_pool.push_back(node);
        }

        set_root(nullptr);
    }

    void erase(splay_node *x) {
        splay_node *new_x = nullptr, *fix_node = nullptr;

        if (x->child[0] == nullptr || x->child[1] == nullptr) {
            new_x = x->child[int(x->child[0] == nullptr)];
            fix_node = x->parent;
        } else {
            splay_node *next = successor(x);
            assert(next != nullptr && next->child[0] == nullptr);
            new_x = next;
            fix_node = next->parent == x ? next : next->parent;

            next->parent->set_child(next->parent_index(), next->child[1]);
            next->set_child(0, x->child[0]);
            next->set_child(1, x->child[1]);
        }

        if (x == root)
            set_root(new_x);
        else
            x->parent->set_child(x->parent_index(), new_x);

        int depth = 0;

        for (splay_node *node = fix_node; node != nullptr; node = node->parent) {
            node->join();
            depth++;
        }

        if (fix_node != nullptr)
            check_splay(fix_node, depth);

        

        *x = splay_node();
        node_pool.push_back(x);
    }

    

    pair<splay_node*, int> lower_bound(const splay_key &key) {
        splay_node *current = root, *previous = nullptr, *answer = nullptr;
        int below = 0, depth = 0;

        while (current != nullptr) {
            previous = current;
            depth++;

            if (current->key < key) {
                below += get_size(current->child[0]) + 1;
                current = current->child[1];
            } else {
                answer = current;
                current = current->child[0];
            }
        }

        if (previous != nullptr)
            check_splay(previous, depth);

        return make_pair(answer, below);
    }

    bool contains(const splay_key &key) {
        splay_node *node = lower_bound(key).first;
        return node != nullptr && node->key == key;
    }

    bool erase(const splay_key &key) {
        splay_node *x = lower_bound(key).first;

        if (x == nullptr || x->key != key)
            return false;

        erase(x);
        return true;
    }

    splay_node *node_at_index(int index) {
        if (index < 0 || index >= size())
            return nullptr;

        splay_node *current = root;
        int depth = 0;

        while (current != nullptr) {
            int left_size = get_size(current->child[0]);
            depth++;

            if (index == left_size) {
                check_splay(current, depth);
                return current;
            }

            if (index < left_size) {
                current = current->child[0];
            } else {
                current = current->child[1];
                index -= left_size + 1;
            }
        }

        assert(false);
    }

    

    splay_node *query_prefix_key(const splay_key &key) {
        splay_node *node = lower_bound(key).first;

        if (node == nullptr)
            return root;

        splay(node);
        return node->child[0];
    }

    

    splay_node *query_prefix_count(int count) {
        if (count <= 0)
            return nullptr;
        else if (count >= size())
            return root;

        splay_node *node = node_at_index(count);
        splay(node);
        return node->child[0];
    }

    

    splay_node *query_suffix_key(const splay_key &key) {
        splay_node *node = lower_bound(key).first;

        if (node == nullptr)
            return nullptr;

        node = predecessor(node);

        if (node == nullptr)
            return root;

        splay(node);
        return node->child[1];
    }

    

    splay_node *query_suffix_count(int count) {
        if (count >= size())
            return root;
        else if (count <= 0)
            return nullptr;

        int index = size() - count;
        splay_node *node = node_at_index(index - 1);
        splay(node);
        return node->child[1];
    }

    

    splay_node *query_range(int start, int end) {
        if (start >= end)
            return nullptr;
        else if (start <= 0)
            return query_prefix_count(end);
        else if (end >= size())
            return query_suffix_count(size() - start);

        splay_node *before = node_at_index(start - 1);
        splay_node *after = node_at_index(end);
        splay(after);
        splay(before);

        if (after->parent != before)
            rotate_up(after);

        assert(before->child[1] == after);
        return after->child[0];
    }

    

    splay_node *query_range_key(const splay_key &lower, const splay_key &upper) {
        return query_range(lower_bound(lower).second, lower_bound(upper).second);
    }
};

bool splay_tree::_exit_delete_setup = false;
vector<splay_node*> splay_tree::node_pool;
vector<splay_node*> splay_tree::pointers_to_delete;

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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        IO::write_int(v[i] + (add_one ? 1 : 0), i < end - 1 ? ' ' : '\n');
}


struct query {
    int v, l, k, index;
};

void run_case() {
    int N, Q;
    IO::read_int(N, Q);
    vector<int> A(N);

    for (auto &a : A)
        IO::read_int(a);

    LCA lca(N);

    for (int i = 1; i < N; i++) {
        int p;
        IO::read_int(p);
        p--;
        lca.add_edge(p, i);
    }

    lca.build(0, false);
    vector<vector<query>> queries(N);

    for (int q = 0; q < Q; q++) {
        query qry;
        IO::read_int(qry.v, qry.l, qry.k);
        qry.v--; qry.k--;
        qry.index = q;
        queries[qry.v].push_back(qry);
    }

    vector<int> answers(Q, -1);
    splay_tree tree;
    vector<int> freq(N + 1, 0);

    y_combinator([&](auto dfs, int node) -> void {
        int a = A[node];
        tree.erase(make_pair(freq[a], a));
        tree.insert(make_pair(++freq[a], a));

        for (query &qry : queries[node]) {
            int start = int(tree.lower_bound(make_pair(qry.l, 0)).second);
            int want = start + qry.k;
            answers[qry.index] = want >= int(tree.size()) ? -1 : tree.node_at_index(want)->key.second;
        }

        for (int child : lca.adj[node])
            dfs(child);

        tree.erase(make_pair(freq[a], a));

        if (--freq[a] > 0)
            tree.insert(make_pair(freq[a], a));
    })(0);

    output_vector(answers);
}

int main() {
    IO::init();
    int tests;
    IO::read_int(tests);

    while (tests-- > 0)
        run_case();
}
