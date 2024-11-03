#include <algorithm>
#include <array>
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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif



template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

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

template<typename T, bool maximum_mode = false>
struct block_RMQ {
    

    static const int BLOCK = 8;
    using mask_t = uint8_t;
    using index_t = uint8_t;

    int n = 0;
    vector<T> values;
    vector<index_t> block_index;
    vector<mask_t> block_mask;
    RMQ<T, maximum_mode> rmq;

    block_RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int largest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    static int get_block_start(int index) {
        return index - index % BLOCK;
    }

    

    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        block_mask.assign(n + 1, 0);
        int mask = 0;

        for (int i = 0; i < n; i++) {
            if (i % BLOCK == 0)
                mask = 0;

            int block_start = get_block_start(i);

            while (mask != 0 && better_index(block_start + largest_bit(mask), i) == i)
                mask -= 1 << largest_bit(mask);

            mask |= 1 << (i - block_start);
            block_mask[i + 1] = mask_t(mask);
        }

        block_index.resize(n / BLOCK);
        vector<T> block_values(n / BLOCK);

        for (int i = 0; i < n / BLOCK; i++) {
            int block_start = BLOCK * i, best = block_start;

            for (int j = block_start + 1; j < block_start + BLOCK; j++)
                best = better_index(best, j);

            block_values[i] = values[best];
            block_index[i] = index_t(best - block_start);
        }

        rmq.build(block_values);
    }

    

    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int answer = a;
        int a_block_start = get_block_start(a);

        

        if (a_block_start == get_block_start(b - 1))
            return a + __builtin_ctz(block_mask[b] >> (a - a_block_start));

        if (a != a_block_start)
            answer = a + __builtin_ctz(block_mask[a_block_start + BLOCK] >> (a - a_block_start));

        int a_block = (a + BLOCK - 1) / BLOCK, b_block = b / BLOCK;

        if (a_block < b_block) {
            int rmq_index = rmq.query_index(a_block, b_block);
            answer = better_index(answer, BLOCK * rmq_index + block_index[rmq_index]);
        }

        int b_block_start = get_block_start(b);

        if (b != b_block_start)
            answer = better_index(answer, b_block_start + __builtin_ctz(block_mask[b]));

        return answer;
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
    block_RMQ<int> rmq;
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

template<const unsigned &MOD>
struct _m_uint {
    unsigned val;

    _m_uint(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = unsigned(v);
    }

    _m_uint(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = unsigned(v);
    }

    _m_uint(int v) : _m_uint(int64_t(v)) {}
    _m_uint(unsigned v) : _m_uint(uint64_t(v)) {}

    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_uint& operator+=(const _m_uint &other) {
        val = val < MOD - other.val ? val + other.val : val - (MOD - other.val);
        return *this;
    }

    _m_uint& operator-=(const _m_uint &other) {
        val = val < other.val ? val + (MOD - other.val) : val - other.val;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        

        

        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_uint& operator*=(const _m_uint &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_uint& operator/=(const _m_uint &other) {
        return *this *= other.inv();
    }

    friend _m_uint operator+(const _m_uint &a, const _m_uint &b) { return _m_uint(a) += b; }
    friend _m_uint operator-(const _m_uint &a, const _m_uint &b) { return _m_uint(a) -= b; }
    friend _m_uint operator*(const _m_uint &a, const _m_uint &b) { return _m_uint(a) *= b; }
    friend _m_uint operator/(const _m_uint &a, const _m_uint &b) { return _m_uint(a) /= b; }

    _m_uint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_uint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_uint operator++(int) { _m_uint before = *this; ++*this; return before; }
    _m_uint operator--(int) { _m_uint before = *this; --*this; return before; }

    _m_uint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _m_uint &a, const _m_uint &b) { return a.val == b.val; }
    friend bool operator!=(const _m_uint &a, const _m_uint &b) { return a.val != b.val; }
    friend bool operator<(const _m_uint &a, const _m_uint &b) { return a.val < b.val; }
    friend bool operator>(const _m_uint &a, const _m_uint &b) { return a.val > b.val; }
    friend bool operator<=(const _m_uint &a, const _m_uint &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_uint &a, const _m_uint &b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_uint save_inv[SAVE_INV];

    static void prepare_inv() {
        

        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_uint inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_uint product = 1;
        unsigned v = val;

        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }

        return product * save_inv[v];
    }

    _m_uint pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_uint a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_uint &m) {
        return os << m.val;
    }
};

template<const unsigned &MOD> _m_uint<MOD> _m_uint<MOD>::save_inv[_m_uint<MOD>::SAVE_INV];

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));



extern const unsigned HASH_P = unsigned(-13337);
using hash_int = _m_uint<HASH_P>;

const uint64_t HASH_P2 = uint64_t(HASH_P) * HASH_P;
const int HASH_COUNT = 1;



uniform_int_distribution<unsigned> MULT_DIST(unsigned(0.1 * HASH_P), unsigned(0.9 * HASH_P));
const hash_int HASH_MULT[] = {MULT_DIST(rng), MULT_DIST(rng)};
const hash_int HASH_INV[] = {1 / HASH_MULT[0], 1 / HASH_MULT[1]};

vector<hash_int> hash_pow[] = {{1}, {1}};

const int INF = int(1e9) + 5;

template<typename T_string = string>
struct string_hash {
    static const bool BUILD_REVERSE = false;

    static uint64_t hash(const T_string &str) {
        uint64_t result = 0;

        for (int h = 0; h < HASH_COUNT; h++) {
            uint64_t value = 1;

            for (const auto &x : str)
                value = (uint64_t(HASH_MULT[h]) * value + x) % HASH_P;

            result += value << (32 * h);
        }

        return result;
    }

    T_string str;
    vector<hash_int> _prefix[HASH_COUNT];
    vector<hash_int> _inv_prefix[HASH_COUNT];

    string_hash() {
        build({});
    }

    string_hash(const T_string &_str) {
        build(_str);
    }

    int length() const {
        return int(_prefix[0].size()) - 1;
    }

    template<typename T_char>
    void add_char(const T_char &c) {
        str.push_back(c);

        for (int h = 0; h < HASH_COUNT; h++) {
            _prefix[h].push_back(HASH_MULT[h] * _prefix[h].back() + c);

            if (hash_pow[h].size() < _prefix[h].size())
                hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back());

            if (BUILD_REVERSE)
                _inv_prefix[h].push_back((_inv_prefix[h].back() + c) * HASH_INV[h]);
        }
    }

    void pop_char() {
        str.pop_back();

        for (int h = 0; h < HASH_COUNT; h++) {
            _prefix[h].pop_back();

            if (BUILD_REVERSE)
                _inv_prefix[h].pop_back();
        }
    }

    void build(const T_string &_str) {
        str = {};
        str.reserve(_str.size());

        for (int h = 0; h < HASH_COUNT; h++) {
            hash_pow[h].reserve(_str.size() + 1);
            _prefix[h] = {0};
            _prefix[h].reserve(_str.size() + 1);

            if (BUILD_REVERSE) {
                _inv_prefix[h] = {0};
                _inv_prefix[h].reserve(_str.size() + 1);
            }
        }

        for (auto &c : _str)
            add_char(c);
    }

    uint64_t _single_hash(int h, int start, int end) const {
        

        uint64_t power = uint64_t(hash_pow[h][end - start]);
        return (power + uint64_t(_prefix[h][end]) + HASH_P2 - uint64_t(_prefix[h][start]) * power) % HASH_P;
    }

    uint64_t substring_hash(int start, int end) const {
        assert(0 <= start && start <= end && end <= length());
        return _single_hash(0, start, end) + (HASH_COUNT > 1 ? _single_hash(1, start, end) << 32 : 0);
    }

    uint64_t complete_hash() const {
        return substring_hash(0, length());
    }

    uint64_t _reverse_single_hash(int h, int start, int end) const {
        

        uint64_t power = uint64_t(hash_pow[h][end - start]);
        return (power + uint64_t(_inv_prefix[h][end]) * power + HASH_P - uint64_t(_inv_prefix[h][start])) % HASH_P;
    }

    uint64_t reverse_substring_hash(int start, int end) const {
        assert(0 <= start && start <= end && end <= length());
        return _reverse_single_hash(0, start, end) + (HASH_COUNT > 1 ? _reverse_single_hash(1, start, end) << 32 : 0);
    }

    uint64_t reverse_complete_hash() const {
        return reverse_substring_hash(0, length());
    }

    bool equal(int start1, int start2, int length) const {
        return substring_hash(start1, start1 + length) == substring_hash(start2, start2 + length);
    }

    bool is_palindrome(int start, int end) const {
        return substring_hash(start, end) == reverse_substring_hash(start, end);
    }

    int compare(int start1, int start2, int max_length = INF) const;
};

uint64_t concat_hashes(uint64_t hash1, uint64_t hash2, int len2) {
    uint64_t hash1_low = hash1 & unsigned(-1);
    uint64_t hash2_low = hash2 & unsigned(-1);
    uint64_t power = uint64_t(hash_pow[0][len2]);
    uint64_t combined = (hash1_low * power + hash2_low + HASH_P - power) % HASH_P;

    if (HASH_COUNT > 1) {
        hash1 >>= 32;
        hash2 >>= 32;
        power = uint64_t(hash_pow[1][len2]);
        combined += (hash1 * power + hash2 + HASH_P - power) % HASH_P << 32;
    }

    return combined;
}

template<typename T_string>
int first_mismatch(const string_hash<T_string> &hash1, int start1,
                   const string_hash<T_string> &hash2, int start2, int max_length = INF) {
    max_length = min({max_length, hash1.length() - start1, hash2.length() - start2});

    static const int FIRST = 5;
    int first = min(max_length, FIRST);

    for (int i = 0; i < first; i++)
        if (hash1.str[start1 + i] != hash2.str[start2 + i])
            return i;

    if (hash1.substring_hash(start1, start1 + max_length) == hash2.substring_hash(start2, start2 + max_length))
        return max_length;

    static const int MANUAL = 15;
    int low = first, high = max_length - 1;

    while (high - low > MANUAL) {
        int mid = (low + high + 1) / 2;

        if (hash1.substring_hash(start1, start1 + mid) == hash2.substring_hash(start2, start2 + mid))
            low = mid;
        else
            high = mid - 1;
    }

    for (int i = low; i < high; i++)
        if (hash1.str[start1 + i] != hash2.str[start2 + i])
            return i;

    return high;
}

template<typename T_string>
int hash_compare(const string_hash<T_string> &hash1, int start1,
                 const string_hash<T_string> &hash2, int start2, int max_length = INF) {
    int mismatch = first_mismatch(hash1, start1, hash2, start2, max_length);
    int length1 = min(hash1.length() - start1, max_length);
    int length2 = min(hash2.length() - start2, max_length);

    if (mismatch == min(length1, length2))
        return length1 == length2 ? 0 : (length1 < length2 ? -1 : +1);

    if (hash1.str[start1 + mismatch] == hash2.str[start2 + mismatch])
        return 0;

    return hash1.str[start1 + mismatch] < hash2.str[start2 + mismatch] ? -1 : +1;
}

template<typename T_string>
int string_hash<T_string>::compare(int start1, int start2, int max_length) const {
    return hash_compare(*this, start1, *this, start2, max_length);
}


struct segment_change {
    bool to_flip;

    segment_change(bool _to_flip = false) : to_flip(_to_flip) {}
};

struct segment {
    uint32_t hash;
    int length;

    segment(uint32_t _hash = 0, int _length = 0) : hash(_hash), length(_length) {}

    void apply(int len, const segment_change &change) {
        assert(len == 1 && length == 1);

        if (change.to_flip) {
            hash = '0' + '1' - hash;
        }
    }

    void join(const segment &other) {
        if (length == 0) {
            *this = other;
            return;
        }

        if (other.length == 0)
            return;

        hash = uint32_t((hash * uint64_t(hash_pow[0][other.length]) + other.hash) % HASH_P);
        length += other.length;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

segment segment_for_char(char ch) {
    return segment(ch, 1);
};

struct persistent_basic_seg_tree {
    struct node {
        segment seg;
        int left = -1, right = -1;
    };

    int tree_n = 0;
    vector<node> tree;
    int64_t reserve_size = INT64_MAX;

    persistent_basic_seg_tree(int n = -1, int64_t max_updates = 0) {
        if (n >= 0)
            init(n, max_updates);
    }

    void init(int n, int64_t max_updates = 0) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        reserve_size = INT64_MAX;

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

        for (int h = 0; h < HASH_COUNT; h++) {
            hash_pow[h].reserve(tree_n + 1);

            while (int(hash_pow[h].size()) <= tree_n)
                hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back());
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
        assert(int64_t(tree.size()) <= reserve_size);
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

    int _update_tree(int position, int start, int end, int index, const segment_change &change) {
        position = make_copy(position);

        if (end - start == 1 && start == index) {
            seg(position).apply(end - start, change);
            return position;
        }

        if (left(position) < 0 || right(position) < 0)
            return position;

        int mid = (start + end) / 2;

        if (index < mid)
            set_left(position, _update_tree(left(position), start, mid, index, change));
        else
            set_right(position, _update_tree(right(position), mid, end, index, change));

        seg(position).join(seg(left(position)), seg(right(position)));
        return position;
    }

    int update(int root, int index, const segment_change &change) {
        assert(root > 0 && 0 <= index && index < tree_n);
        return _update_tree(root, 0, tree_n, index, change);
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
    int find_last_prefix(int root, int n, T_bool &&should_join) const;
};

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    static int largest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }

    

    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
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
        count = min(count, tree_n);
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

        for (int k = largest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


vector<hash_int> inv_hash_pow[] = {{1}, {1}};

struct hash_fenwick_tree {
    fenwick_tree<hash_int> tree[HASH_COUNT];

    hash_fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        for (int h = 0; h < HASH_COUNT; h++) {
            hash_pow[h].reserve(n + 1);
            inv_hash_pow[h].reserve(n + 1);

            while (int(hash_pow[h].size()) <= n)
                hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back());

            hash_int inv_mult = HASH_MULT[h].inv();

            while (int(inv_hash_pow[h].size()) <= n)
                inv_hash_pow[h].push_back(inv_mult * inv_hash_pow[h].back());

            tree[h].init(n);
        }
    }

    

    template<typename T_array>
    void build(const T_array &initial) {
        for (int h = 0; h < HASH_COUNT; h++) {
            vector<hash_int> values(initial.begin(), initial.end());

            for (int i = 0; i < int(values.size()); i++)
                values[i] *= inv_hash_pow[h][i + 1];

            tree[h].build(values);
        }
    }

    void set(int index, hash_int value) {
        for (int h = 0; h < HASH_COUNT; h++)
            tree[h].set(index, value * inv_hash_pow[h][index + 1]);
    }

    uint64_t query_hash(int start, int end) const {
        uint64_t result = 0;

        for (int h = 0; h < HASH_COUNT; h++) {
            hash_int value = tree[h].query(start, end) * hash_pow[h][end];
            result += uint64_t(value) << (32 * h);
        }

        return result;
    }
};


struct query {
    int u, v, L, R, index;
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    IO::init();

    int N, Q;
    IO::read_int(N, Q);
    vector<int> A(N);

    for (auto &a : A) {
        IO::read_int(a);
        a--;
    }

    LCA lca(N);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        IO::read_int(x, y);
        x--; y--;
        lca.add_edge(x, y);
    }

    lca.build();
    persistent_basic_seg_tree tree(N, N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment_for_char('0');

    tree.build(initial);
    vector<int> roots(N, -1);

    y_combinator([&](auto dfs, int node, int parent, int root) -> void {
        root = tree.update(root, A[node], segment_change(true));
        roots[node] = root;

        for (int neigh : lca.adj[node]) {
            assert(neigh != parent);
            dfs(neigh, node, root);
        }
    })(0, -1, 1);

    vector<int> answers(Q, -1);
    vector<vector<query>> queries(N);

    for (int q = 0; q < Q; q++) {
        int u, v, L, R;
        IO::read_int(u, v, L, R);
        u--; v--; L--;
        queries[u].push_back((query) {u, v, L, R, q});
    }

    hash_fenwick_tree hash_tree(N);
    hash_tree.build(string(N, '0'));
    string values(N, '0');

    y_combinator([&](auto dfs, int u, int parent) -> void {
        values[A[u]] ^= 1;
        hash_tree.set(A[u], values[A[u]]);

        for (query &qry : queries[u]) {
            int v = qry.v, L = qry.L, R = qry.R, index = qry.index;
            int anc = lca.get_lca(u, v);
            values[A[anc]] ^= 1;
            hash_tree.set(A[anc], values[A[anc]]);
            int low = L + 1, high = R + 1;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (hash_tree.query_hash(L, mid) == tree.query(roots[v], L, mid).hash)
                    low = mid + 1;
                else
                    high = mid;
            }

            answers[index] = low > R ? -1 : low;
            values[A[anc]] ^= 1;
            hash_tree.set(A[anc], values[A[anc]]);
        }

        for (int neigh : lca.adj[u]) {
            assert(neigh != parent);
            dfs(neigh, u);
        }

        values[A[u]] ^= 1;
        hash_tree.set(A[u], values[A[u]]);
    })(0, -1);

    for (int ans : answers)
        IO::write_int(ans, '\n');
}
