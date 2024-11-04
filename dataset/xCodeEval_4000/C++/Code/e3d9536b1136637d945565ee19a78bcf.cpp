#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
template <class T, class I> auto gath(const T &a, const vector<I> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
#endif
template <class T, class C> void sort(T &a, C c) { sort(rang(a), c); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...) << '\n'; }
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
namespace graphic_matroid {
struct static_tree {
    int n, root, block_size, num_blocks;
    vector<vector<int>> to, st, block_min;
    vector<int> level, tour_index, closest_size, block_type, tour;
    static_tree(int _n, int _root = 0)
        : n(_n), root(_root), block_size(0), to(n), level(n), tour_index(n) {}
    void add_edge(int u, int v) { to[u].push_back(v), to[v].push_back(u); }
    void build_tour(int u, int p) {
        tour_index[u] = int(tour.size()), tour.push_back(u);
        for (auto v : to[u])
            if (v != p) {
                level[v] = level[u] + 1;
                build_tour(v, u), tour_index[u] = int(tour.size());
                tour.push_back(u);
            }
    }
    int get_min(int a, int b) { return level[a] < level[b] ? a : b; }
    void build_st() {
        block_size = max(1, int(log2(tour.size()) / 2));
        num_blocks =
            int(tour.size()) / block_size + bool(tour.size() % block_size);
        closest_size.resize(num_blocks + 1, 0);
        for (int i = 2; i <= num_blocks; ++i) {
            closest_size[i] = closest_size[i - 1];
            if ((1 << (closest_size[i] + 1)) <= i)
                ++closest_size[i];
        }
        st = vector<vector<int>>(closest_size[num_blocks] + 1,
                                 vector<int>(num_blocks));
        for (int h = 0; h <= closest_size[num_blocks]; ++h)
            for (int i = 0; i < num_blocks; ++i) {
                int &t = st[h][i];
                if (!h) {
                    t = tour[i * block_size];
                    for (int j = i * block_size;
                         j < (i + 1) * block_size && j < int(tour.size()); ++j)
                        t = get_min(t, tour[j]);
                } else if (i + (1 << (h - 1)) >= num_blocks)
                    t = st[h - 1][i];
                else
                    t = get_min(st[h - 1][i], st[h - 1][i + (1 << (h - 1))]);
            }
    }
    void build_block() {
        block_type.resize(num_blocks);
        for (int i = 0; i < num_blocks; ++i) {
            int m = 0;
            for (int j = i * block_size + 1; j < (i + 1) * block_size; ++j) {
                m <<= 1;
                if (j < int(tour.size()) && level[tour[j]] > level[tour[j - 1]])
                    ++m;
            }
            block_type[i] = m;
        }
        block_min = vector<vector<int>>(1 << (block_size - 1),
                                        vector<int>(block_size * block_size));
        for (int m = 0; m < (1 << (block_size - 1)); ++m) {
            for (int i = 0; i < block_size; ++i) {
                pair<int, int> t(0, i);
                int v = 0, k = i * block_size;
                block_min[m][k + i] = i;
                for (int j = i + 1; j < block_size; ++j) {
                    if ((m >> (block_size - 1 - j)) & 1)
                        ++v;
                    else
                        --v;
                    if (v < t.first)
                        t = make_pair(v, j);
                    block_min[m][k + j] = t.second;
                }
            }
        }
    }
    void build() {
        tour.reserve(2 * n - 1), build_tour(root, -1), build_st(),
            build_block();
    }
    int lca(int u, int v) {
        int l = tour_index[u], r = tour_index[v];
        if (l > r)
            swap(l, r);
        int b_l = l / block_size, i_l = l % block_size, b_r = r / block_size,
            i_r = r % block_size;
        if (b_l == b_r)
            return tour[(l - i_l) +
                        block_min[block_type[b_l]][i_l * block_size + i_r]];
        u = tour[l - i_l +
                 block_min[block_type[b_l]][i_l * block_size + block_size - 1]];
        v = tour[r - i_r + block_min[block_type[b_r]][i_r]];
        if (level[v] < level[u])
            u = v;
        if (++b_l <= --b_r) {
            int s = closest_size[b_r - b_l + 1];
            v = get_min(st[s][b_l], st[s][b_r - (1 << s) + 1]);
            if (level[v] < level[u])
                u = v;
        }
        return u;
    }
};
struct bfs_forest {
    vector<vector<int>> to;
    vector<bool> visited;
    vector<int> depth, component;
    int component_number;
    bfs_forest(int n)
        : to(n), visited(n), depth(n), component(n, -1), component_number(0) {}
    void add_edge(int u, int v) {
        to.at(u).push_back(v), to.at(v).push_back(u);
    }
    void bfs_single(int s) {
        if (!visited[s]) {
            queue<int> q;
            q.push(s), visited[s] = true, ++component_number;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : to[u])
                    if (!visited[v])
                        visited[v] = true, q.push(v), depth[v] = depth[u] + 1,
                        component[v] = component_number - 1;
            }
        }
    }
    void bfs_all() {
        for (int s = 0; s < int(to.size()); ++s)
            bfs_single(s);
    }
};
struct union_find_set {
    int n;
    vector<int> p;
    void init(int _n) {
        n = _n, p.resize(n);
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void link(int x, int y) {
        assert(find(x) != find(y));
        p[find(x)] = y;
    }
};
struct graphic_matroid {
    graphic_matroid(const vector<pair<int, int>> &_edge)
        : n(_edge.size()), m(0), edge(_edge), in_current(n), modified(true),
          tree(0) {
        for (auto &e : edge) {
            assert(e.first >= 0 && e.second >= 0);
            m = max(max(m, e.first + 1), e.second + 1), ufs.init(m);
        }
    }
    ~graphic_matroid() {
        if (tree)
            delete tree;
    }
    bool can_greedily_add(int u) {
        return ufs.find(edge[u].first) != ufs.find(edge[u].second);
    }
    void greedily_add(int u) {
        ufs.link(edge[u].first, edge[u].second), modify(u, true);
    }
    auto current_elements() {
        vector<int> t;
        for (int i = 0; i < n; ++i)
            if (in_current[i])
                t.push_back(i);
        return t;
    }
    auto free_elements() {
        repair();
        vector<int> t;
        for (int i = 0; i < n; ++i)
            if (!in_current[i] && tree->lca(edge[i].first, edge[i].second) == m)
                t.push_back(i);
        return t;
    }
    bool can_exchange(int u, int v) {
        repair();
        assert(in_current[u] && !in_current[v]);
        int p1 = edge[v].first, p2 = edge[v].second, p3 = tree->lca(p1, p2),
            q1 = edge[u].first, q2 = edge[u].second;
        if (p3 == m)
            return true;
        if (tree->level[q2] + 1 == tree->level[q1])
            swap(q1, q2);
        if (tree->lca(q1, p3) != p3)
            return false;
        return tree->lca(q2, p1) == q2 || tree->lca(q2, p2) == q2;
    }
    void repair() {
        if (modified) {
            modified = false;
            if (tree)
                delete tree;
            tree = new static_tree(m + 1, m);
            bfs_forest bfs(m);
            for (int i = 0; i < n; ++i)
                if (in_current[i]) {
                    auto &e = edge[i];
                    bfs.add_edge(e.first, e.second);
                    tree->add_edge(e.first, e.second);
                }
            bfs.bfs_all();
            vector<bool> connected(bfs.component_number);
            for (int i = 0; i < m; ++i)
                if (bfs.component[i] != -1 && !connected[bfs.component[i]])
                    tree->add_edge(i, m), connected[bfs.component[i]] = true;
            tree->build();
        }
    }
    void modify(int u, bool t) {
        assert(t ^ in_current[u]), in_current[u] = t, modified = true;
    }
    int n, m;
    vector<pair<int, int>> edge;
    vector<bool> in_current;
    bool modified;
    static_tree *tree;
    union_find_set ufs;
};
} 

namespace matroid_intersection {
template <class A, class B> vector<int> matroid_intersection(A &m1, B &m2) {
    assert(m1.n == m2.n);
    int n = m1.n;
    vector<int> greedy_targets(n);
    for (int i = 0; i < n; ++i)
        greedy_targets[i] = i;
    random_shuffle(begin(greedy_targets), end(greedy_targets));
    for (auto u : greedy_targets)
        if (m1.can_greedily_add(u) && m2.can_greedily_add(u))
            m1.greedily_add(u), m2.greedily_add(u);
    vector<int> parent(n);
    vector<bool> in_y1(n), in_y2(n);
    while (true) {
        fill(begin(parent), end(parent), -2);
        fill(begin(in_y1), end(in_y1), 0), fill(begin(in_y2), end(in_y2), 0);
        queue<int> qu;
        int target = -1;
        for (int u : m1.free_elements())
            in_y1[u] = true, qu.push(u), parent[u] = -1;
        for (int u : m2.free_elements()) {
            if (in_y1[u]) {
                target = u;
                break;
            }
            in_y2[u] = true;
        }
        while (target == -1 && qu.size()) {
            int u = qu.front();
            qu.pop();
            if (in_y2[u]) {
                target = u;
                break;
            }
            for (int v = 0; v < n; ++v) {
                if (parent[v] == -2 &&
                    ((m1.in_current[u] && !m1.in_current[v] &&
                      m1.can_exchange(u, v)) ||
                     (!m1.in_current[u] && m1.in_current[v] &&
                      m2.can_exchange(v, u)))) {
                    parent[v] = u;
                    if (in_y2[v]) {
                        target = v;
                        break;
                    }
                    qu.push(v);
                }
            }
        }
        if (target == -1)
            break;
        for (int i = 1, j = target; j != -1; ++i, j = parent[j])
            if (i % 2 == 0)
                m1.modify(j, 0), m2.modify(j, 0);
        for (int i = 1, j = target; j != -1; ++i, j = parent[j])
            if (i % 2)
                m1.modify(j, 1), m2.modify(j, 1);
    }
    return m1.current_elements();
}
} 

namespace partition_matroid {
struct partition_matroid {
    partition_matroid(const vector<int> &_color, const vector<int> &_limit)
        : n(int(_color.size())),
          m(*max_element(begin(_color), end(_color)) + 1), color(_color),
          limit(_limit), cnt_in_current(m), in_current(n) {
        assert(*min_element(begin(_color), end(_color)) >= 0);
    }
    bool can_greedily_add(int u) {
        return cnt_in_current[color[u]] < limit[color[u]];
    }
    void greedily_add(int u) { modify(u, true); }
    auto current_elements() {
        vector<int> t;
        for (int i = 0; i < n; ++i)
            if (in_current[i])
                t.push_back(i);
        return t;
    }
    auto free_elements() {
        vector<int> t;
        for (int i = 0; i < n; ++i)
            if (!in_current[i] && cnt_in_current[color[i]] < limit[color[i]])
                t.push_back(i);
        return t;
    }
    bool can_exchange(int u, int v) {
        assert(in_current[u] && !in_current[v]);
        return color[u] == color[v] ||
               cnt_in_current[color[v]] < limit[color[v]];
    }
    void modify(int u, bool t) {
        assert(t ^ in_current[u]), in_current[u] = t;
        int &c = cnt_in_current[color[u]];
        assert(!t || c < limit[color[u]]);
        c += 2 * t - 1;
    }
    int n, m;
    vector<int> color, limit, cnt_in_current;
    vector<bool> in_current;
};
} 

namespace grid_graph {


auto convert(int x, int y, int n, int m, bool from_zero_indexed,
             bool to_zero_indexed) {
    if (from_zero_indexed)
        assert(x >= 0 && x < n && y >= 0 && y < m);
    else
        assert(x > 0 && x <= n && y >= 0 && y < m);
    return (x - !from_zero_indexed) * m + y + from_zero_indexed -
           to_zero_indexed;
}


auto convert(int i, int n, int m, bool from_zero_indexed,
             bool to_zero_indexed) {
    if (from_zero_indexed) {
        assert(i >= 0 && i < n * m);
        return make_pair(i / m + !to_zero_indexed, i % m + !to_zero_indexed);
    }
    assert(i > 0 && i <= n * m);
    return make_pair((i - 1) / m + 1 - to_zero_indexed,
                     (i - 1) % m + 1 - to_zero_indexed);
}
auto valid(int x, int y, int n, int m, bool zero_indexed) {
    if (zero_indexed)
        return x >= 0 && x < n && y >= 0 && y < m;
    return x > 0 && x <= n && y > 0 && y <= m;
}
template <class T> auto at(const T &a, const pair<int, int> &p) {
    return a[p.first][p.second];
}
auto neighbours(int x, int y, int n, int m, bool zero_indexed,
                int connectivity) {
    static int d_4[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}},
               d_8[8][2] = {{-1, 0}, {1, 0},  {0, 1}, {0, -1},
                            {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    auto d = connectivity == 4 ? d_4 : d_8;
    vector<pair<int, int>> r;
    for (int i = 0; i < connectivity; ++i)
        if (valid(x + d[i][0], y + d[i][1], n, m, zero_indexed))
            r.push_back(make_pair(x + d[i][0], y + d[i][1]));
    return r;
}
} 

namespace union_find_set {
struct union_find_set {
    int n;
    vector<int> p;
    union_find_set(int _n) : n(_n), p(n) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void link(int x, int y) {
        assert(find(x) != find(y));
        p[find(x)] = y;
    }
};
} 

int main() {
    fast, prec(12);
    many {
        int n, m;
        in(n, m);
        vector<string> a(n);
        cin >> a;
        vvi node_index(n, vi(m));
        int num_nodes = 0;
        lp(i, 0, n - 1) lp(j, 0, m - 1) {
            if (a[i][j] == 'O') {
                node_index[i][j] = num_nodes++;
            } else {
                node_index[i][j] = -1;
            }
        }
        vpii edges, alledges;
        vi color;
        vi limit(num_nodes, 2);
        int num_colors = 0;
        set<pii> vis;
        lp(i, 0, n - 1) lp(j, 0, m - 1) {
            for (auto [ii, jj] : grid_graph::neighbours(i, j, n, m, 1, 4)) {
                if (a[i][j] == 'O' && a[ii][jj] == 'O') {
                    int u = node_index[i][j], v = node_index[ii][jj];
                    alledges.emplace_back(u, v);
                    if (u == 0 || v == 0)
                        continue;
                    if (vis.count({u, v}))
                        continue;
                    vis.insert({u, v});
                    vis.insert({v, u});
                    edges.emplace_back(node_index[i][j], node_index[ii][jj]);
                    int c;
                    if ((i + j) % 2 == 0) {
                        c = node_index[i][j];
                    } else
                        c = node_index[ii][jj];
                    color.push_back(c);
                    

                }
            }
            if ((i + j) % 2 == 0 && i + j != 0 && a[i][j] == 'O')
                ++num_colors;
        }
        vi chosen;
        if (edges.size()) {
            graphic_matroid::graphic_matroid m1(edges);
            partition_matroid::partition_matroid m2(color, limit);
            chosen = matroid_intersection::matroid_intersection(m1, m2);
        }
        set<pii> c2;
        if (chosen.size() != 2 * num_colors) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            union_find_set::union_find_set ufs(num_nodes);
            for (auto [u, v] : gath(edges, chosen)) {
                assert(ufs.find(u) != ufs.find(v));
                ufs.link(u, v);
                c2.insert({u, v});
                c2.insert({v, u});
            }
            for (auto [u, v] : alledges) {
                if (ufs.find(u) != ufs.find(v)) {
                    ufs.link(u, v);
                    c2.insert({u, v});
                    c2.insert({v, u});
                }
            }
            vector<string> ans(2 * n - 1, string(2 * m - 1, ' '));
            lp(i, 1, n) lp(j, 1, m) {
                ans[2 * i - 1 - 1][2 * j - 1 - 1] = a[i - 1][j - 1];
            }
            lp(i, 1, n) lp(j, 1, m - 1) {
                int u = node_index[i - 1][j - 1], v = node_index[i - 1][j];
                if (u == -1 || v == -1 || !c2.count({u, v})) {
                    ans[2 * i - 1 - 1][2 * j - 1] = ' ';
                } else {
                    ans[2 * i - 1 - 1][2 * j - 1] = '-';
                }
            }
            lp(i, 1, n - 1) lp(j, 1, m) {
                int u = node_index[i - 1][j - 1], v = node_index[i][j - 1];
                if (u == -1 || v == -1 || !c2.count({u, v})) {
                    ans[2 * i - 1][2 * j - 1 - 1] = ' ';
                } else {
                    ans[2 * i - 1][2 * j - 1 - 1] = '|';
                }
            }
            for (auto s : ans)
                cout << s << endl;
        }
    }
    return 0;
}