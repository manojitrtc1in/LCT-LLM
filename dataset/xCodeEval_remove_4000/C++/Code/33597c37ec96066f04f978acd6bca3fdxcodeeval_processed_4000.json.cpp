
using namespace std;

using ll = long long;
using ld = long double;




struct id6 {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> matching;

    id6(int n = 0) : n(n), g(n), matching(n, -1) {}

    int size() const {
        return n;
    }

    void add(int v, int u) {
        assert(0 <= v && v < n);
        assert(0 <= u && u < n);
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int solve(bool id4 = false) {
        auto id5 = [&]() {
            std::vector<int> id9(n), id7(n, 1);
            std::iota(id9.begin(), id9.end(), 0);

            struct edge {
                int initial_v, initial_u, v, u;
            };
            std::vector<std::vector<edge>> id2(n);
            std::vector<std::vector<int>> log(n);

            auto root = [&](int v) {
                if (v == -1)
                    return -1;

                while (id9[v] != v)
                    v = id9[v];

                return v;
            };

            std::queue<int> que;
            std::vector<int> type(n);
            std::vector<std::pair<int, int>> id0(n, {-1, -1});
            for (int i = 0; i < n; i++)
                if (matching[i] == -1) {
                    type[i] = 1;
                    que.push(i);
                }

            std::vector<int> id3(n);
            int id10 = 0;

            auto lca = [&](int v, int u) {
                assert(id9[v] == v);
                assert(id9[u] == u);

                id10++;
                assert(v != u);
                id3[v] = id3[u] = id10;

                while (true) {
                    int v_root = root(id0[v].first);
                    int u_root = root(id0[u].first);
                    if (v_root == -1 && u_root == -1)
                        return -1;

                    for (int rot = 0; rot < 2; rot++, std::swap(v, u), std::swap(v_root, u_root))
                        if (v_root != -1) {
                            if (id3[v_root] == id10)
                                return v_root;

                            v = v_root;
                            id3[v] = id10;
                        }
                }
                assert(false);
            };

            auto get_path = [&](int from, int to) {
                assert(id9[from] == from);
                assert(to == -1 || id9[to] == to);
                std::vector<edge> edges;
                while (from != to) {
                    edges.push_back({id0[from].second, id0[from].first, from, root(id0[from].first)});
                    from = edges.back().u;
                }
                return edges;
            };

            while (!que.empty()) {
                int v = que.front();
                que.pop();

                for (int u : g[v]) {
                    int v_root = root(v), u_root = root(u);
                    if (u_root == v_root)
                        continue;

                    if (type[u] == 0) {
                        assert(matching[u] != -1);
                        int w = matching[u];
                        if (type[w] == 1)
                            continue;

                        assert(id9[w] == w);
                        assert(id0[w].first == -1 && id0[u_root].first == -1);

                        id0[w] = {u, w};
                        id0[u_root] = {v, u};
                        type[w] = 1;
                        que.push(w);
                    } else {
                        int w = lca(v_root, u_root);
                        std::vector<edge> path_v = get_path(v_root, w);
                        std::vector<edge> path_u = get_path(u_root, w);
                        std::reverse(path_v.begin(), path_v.end());
                        for (edge &e : path_v) {
                            std::swap(e.initial_v, e.initial_u);
                            std::swap(e.v, e.u);
                        }

                        auto add_path = [&](std::vector<edge> &path) {
                            for (edge &e : path_v)
                                path.push_back(e);

                            path.push_back({v, u, v_root, u_root});
                            for (edge &e : path_u)
                                path.push_back(e);
                        };

                        if (w == -1) {
                            std::vector<edge> path;
                            add_path(path);

                            std::vector<int> last_changed(n, -1);
                            std::queue<int> id1;

                            auto process_edge = [&](const edge &e) {
                                id1.push(e.v);
                                id1.push(e.u);
                                matching[e.initial_v] = e.initial_u;
                                matching[e.initial_u] = e.initial_v;
                                assert(last_changed[e.v] == -1);
                                assert(last_changed[e.u] == -1);
                                last_changed[e.v] = e.initial_v;
                                last_changed[e.u] = e.initial_u;
                            };

                            for (int i = 1; i < int(path.size()) - 1; i += 2)
                                process_edge(path[i]);

                            while (!id1.empty()) {
                                int v = id1.front();
                                id1.pop();
                                if (log[v].empty())
                                    continue;

                                assert(last_changed[v] != -1);
                                int u = last_changed[v];
                                last_changed[v] = -1;
                                int pos = log[v].back();
                                log[v].pop_back();

                                for (int i = pos; i < int(id2[v].size()); i++)
                                    for (int x : {id2[v][i].v, id2[v][i].u})
                                        id9[x] = x;
                                
                                int u_root = root(u);
                                bool found = false;
                                for (int i = pos + 1; i < int(id2[v].size()); i += 2) {
                                    if (id2[v][i].v == u_root) {
                                        assert(!found);
                                        found = true;
                                        assert((int(id2[v].size()) - i) % 2 == 0);

                                        last_changed[id2[v][i].v] = u;
                                        id1.push(id2[v][i].v);
                                        for (int j = i + 1; j < int(id2[v].size()); j += 2)
                                            process_edge(id2[v][j]);
                                    }
                                    
                                    if (id2[v][i].u == u_root) {
                                        assert(!found);
                                        found = true;
                                        assert((i - pos) % 2 == 1);

                                        last_changed[id2[v][i].u] = u;
                                        id1.push(id2[v][i].u);
                                        for (int j = i - 1; j >= pos; j -= 2)
                                            process_edge(id2[v][j]);
                                    }
                                }

                                if (!found) {
                                    id1.push(id2[v][pos].v);
                                    last_changed[id2[v][pos].v] = u;
                                }
                                id2[v].resize(pos);
                            }
                            return true;
                        }

                        assert(path_v.size() % 2 == 0);
                        assert(path_u.size() % 2 == 0);

                        auto process_vertex = [&](int v) {
                            assert(type[v] == 0);
                            assert(id9[v] == v);
                            type[v] = 1;
                            que.push(v);
                        };

                        for (int i = 0; i < int(path_v.size()); i += 2) {
                            assert(path_v[i].initial_u == path_v[i].u);
                            process_vertex(path_v[i].u);
                        }

                        for (int i = 0; i < int(path_u.size()); i += 2) {
                            assert(path_u[i].initial_u == path_u[i].u);
                            process_vertex(path_u[i].u);
                        }

                        std::vector<int> vertices;
                        vertices.reserve(path_v.size() + path_u.size() + 1);
                        for (edge &e : path_v)
                            vertices.push_back(e.v);

                        vertices.push_back(v_root);
                        for (edge &e : path_u)
                            vertices.push_back(e.v);

                        int new_root = vertices[0];
                        for (int i = 1; i < int(vertices.size()); i++)
                            if (id7[new_root] < id7[vertices[i]])
                                new_root = vertices[i];

                        id0[new_root] = id0[w];
                        for (int v : vertices) {
                            if (v == new_root)
                                continue;

                            assert(type[v] == 1);
                            id9[v] = new_root;
                            id7[new_root] += id7[v];
                        }

                        log[new_root].push_back(id2[new_root].size());
                        add_path(id2[new_root]);
                    }
                }
            }
            return false;
        };

        int pairs = 0;
        for (int v = 0; v < n; v++)
            pairs += matching[v] > v;

        std::vector<int> order(n);
        std::iota(order.begin(), order.end(), 0);
        if (id4)
            std::shuffle(order.begin(), order.end(), std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count()));

        for (int v : order)
            for (int u : g[v])
                if (matching[v] == -1 && matching[u] == -1) {
                    matching[v] = u;
                    matching[u] = v;
                    pairs++;
                }

        while (id5())
            pairs++;

        return pairs;
    }
};

struct matching {
    int n, m;
    std::vector<std::vector<int>> g;
    std::vector<int> p_left, p_right;

    matching(int n = 0, int m = 0) :
        n(n), m(m), g(n), p_left(n, -1), p_right(m, -1)
    {}

    std::pair<int, int> size() const {
        return {n, m};
    }

    void add(int left, int right) {
        g[left].push_back(right);
    }

    std::vector<int> used;
    int timer;

    bool khun(int v) {
        if (used[v] == timer)
            return false;

        used[v] = timer;
        for (auto u : g[v])
            if (p_right[u] == -1) {
                p_right[u] = v;
                p_left[v] = u;
                return true;
            }

        for (auto u : g[v])
            if (khun(p_right[u])) {
                p_right[u] = v;
                p_left[v] = u;
                return true;
            }

        return false;
    }

    int solve(bool id4 = false) {
        std::fill(p_left.begin(), p_left.end(), -1);
        std::fill(p_right.begin(), p_right.end(), -1);
        used.assign(n, 0);
        timer = 0;

        std::vector<int> order(n);
        std::iota(order.begin(), order.end(), 0);
        if (id4)
            std::shuffle(order.begin(), order.end(), std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count()));

        int pairs = 0;
        for (int v : order) {
            timer++;
            pairs += khun(v);
        }
        return pairs;
    }

    void dfs(int v) {
        if (used[v])
            return;

        used[v] = 1;
        for (auto u : g[v])
            if (u != p_left[v])
                dfs(p_right[u]);
    }

    std::pair<std::vector<int>, std::vector<int>> minimum_vertex_covering() {
        int pairs = solve();
        used.assign(n, 0);

        for (int i = 0; i < n; i++)
            if (p_left[i] == -1)
                dfs(i);

        std::vector<int> left;
        std::vector<bool> used_right(m);

        for (int i = 0; i < n; i++)
            if (!used[i]) {
                left.push_back(i);
            } else if (p_left[i] != -1) {
                for (auto j : g[i])
                    used_right[j] = true;
            }

        std::vector<int> right;
        for (int i = 0; i < m; i++)
            if (used_right[i])
                right.push_back(i);

        assert(int(left.size() + right.size()) == pairs);
        return std::make_pair(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;

    vector<bool> used(n), good(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) continue;
        used[a[i]] = true;
        if (i + 1 < n && a[i] == a[i + 1]) {
            good[a[i]] = true;
        }
    }

    int id = 0;
    vector<int> num(n, -1), values;
    for (int i = 0; i < n; i++) {
        if (!good[i]) {
            num[i] = id++;
            values.push_back(i);
        }
    }

    vector<pair<int, int>> segs;
    for (int i = 0, j = 0; i < n; i = j) {
        if (a[i] != -1) {
            j = i + 1;
            continue;
        }   
        while (j < n && a[j] == -1) j++;
        segs.emplace_back(i, j);
    }

    id6 g(id);
    map<pair<int, int>, int> mp_even, id8;
    vector<pair<int, int>> free_pairs;

    for (int pos = 0, cur = id; pos < len(segs); pos++) {
        auto [i, j] = segs[pos];
        int left = i == 0 ? -1 : num[a[i - 1]];
        int right = j == n ? -1 : num[a[j]];

        int x = min(left, right), y = max(left, right);
        if ((j - i) % 2 == 0) {
            if (mp_even[{x, y}] >= 1) {
                for (int k = i; k < j; k += 2) {
                    free_pairs.emplace_back(k, k + 1);
                }
                continue;
            }
            mp_even[{x, y}]++;

            if (left != -1 && right != -1) g.add(left, right);
        } else {
            if (id8[{x, y}] >= 2) {
                for (int k = i; k < j - 1; k += 2) {
                    free_pairs.emplace_back(k, k + 1);
                }
                continue;
            }
            id8[{x, y}]++;

            g.g.push_back({});
            g.matching.push_back(-1);
            g.n++;
            if (left != -1) g.add(left, cur);
            if (right != -1) g.add(cur, right);
            cur++;
        }
    }

    matching mat(id, len(segs));
    for (int i = 0; i < id; i++) {
        for (int j : g.g[i]) {
            if (j >= id) mat.add(i, j - id);
        }
    }
    mat.solve();
    for (int i = 0; i < id; i++) {
        if (mat.p_left[i] == -1) continue;
        g.matching[i] = id + mat.p_left[i];
        g.matching[id + mat.p_left[i]] = i;
    }

    g.solve();
    set<pair<int, int>> edges;
    for (int v = 0; v < len(g); v++) {
        if (g.matching[v] > v) edges.emplace(v, g.matching[v]);
    }

    mp_even.clear();
    id8.clear();
    for (int pos = 0, cur = id; pos < len(segs); pos++) {
        auto [i, j] = segs[pos];
        int left = i == 0 ? -1 : num[a[i - 1]];
        int right = j == n ? -1 : num[a[j]];

        int x = min(left, right), y = max(left, right);
        if ((j - i) % 2 == 0) {
            if (mp_even[{x, y}] >= 1) continue;
            mp_even[{x, y}]++;

            if (edges.count({x, y})) {
                edges.erase({x, y});
                if (left != -1) {
                    a[i] = values[left];
                    good[a[i]] = true;
                }
                if (right != -1) {
                    a[j - 1] = values[right];
                    good[a[j - 1]] = true;
                }
                for (int k = i + 1; k < j - 2; k += 2) {
                    free_pairs.emplace_back(k, k + 1);
                }
            } else {
                for (int k = i; k < j; k += 2) {
                    free_pairs.emplace_back(k, k + 1);
                }
            }
        } else {
            if (id8[{x, y}] >= 2) continue;
            id8[{x, y}]++;

            if (g.matching[cur] == left) {
                if (left != -1) {
                    a[i] = values[left];
                    good[a[i]] = true;
                }
                for (int k = i + 1; k < j; k += 2) {
                    free_pairs.emplace_back(k, k + 1);
                }
            } else {
                if (right != -1) {
                    a[j - 1] = values[right];
                    good[a[j - 1]] = true;
                }
                for (int k = i; k < j - 1; k += 2) {
                    free_pairs.emplace_back(k, k + 1);
                }
            }
            cur++;
        }
    }

    for (int i = 0; i < n && !free_pairs.empty(); i++) {
        if (good[i]) continue;
        good[i] = true;
        a[free_pairs.back().first] = i;
        a[free_pairs.back().second] = i;
        free_pairs.pop_back();
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) a[i] = 0;
        cout << a[i] + 1 << " \n"[i == n - 1];
    }
}
