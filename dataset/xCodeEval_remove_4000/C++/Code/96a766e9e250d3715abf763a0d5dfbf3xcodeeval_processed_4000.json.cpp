























using namespace std;
using str = string;
using ll = __int128_t;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
mt19937 rnd(timeStamp().time_since_epoch().count());
mt19937_64 rndll(timeStamp().time_since_epoch().count());
template<typename T, typename U> bool chmin(T& a, const U& b) {return b < a ? a = b, 1 : 0;}
template<typename T, typename U> bool chmax(T& a, const U& b) {return b > a ? a = b, 1 : 0;}
constexpr inline uint id2(const uint x) {return 1u << __lg(x);}
constexpr inline ull id3(const ull x) {return 1ull << __lg(x);}
constexpr inline uint id0(const uint x) {return x & (x - 1) ? 2u << __lg(x) : x;}
constexpr inline ull id4(const ull x) {return x & (x - 1) ? 2ull << __lg(x) : x;}
constexpr inline ll sqd(const pll p1, const pll p2) {return (p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S);}
constexpr inline ll sqd(const ll x1, const ll y1, const ll x2, const ll y2) {return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}
struct custom_hash {static uint64_t xs(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);} template<typename T> size_t operator()(T x) const {static const uint64_t C = timeStamp().time_since_epoch().count(); return xs(hash<T> {}(x) + C);}};
template<typename K> using uset = unordered_set<K, custom_hash>;
template<typename K> using umset = unordered_multiset<K, custom_hash>;
template<typename K, typename V> using umap = unordered_map<K, V, custom_hash>;


template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.F << ' ' << x.S;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.F >> x.S;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for (auto &x : a) in >> x; return in;}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for (int q = 0; q < a.size(); ++q) {out << a[q]; if (q + 1 < a.size()) out << ' ';} return out;}
template<typename T, auto K> istream& operator>>(istream& in, array<T, K>& a) {for (auto &x : a) in >> x; return in;}
template<typename T, auto K> ostream& operator<<(ostream& out, array<T, K>& a) {for (int q = 0; q < a.size(); ++q) {out << a[q]; if (q + 1 < a.size()) out << ' ';} return out;}

const ll mod = 998244353;

template<typename Data>
struct edge {
    int to;
    Data data;

    edge() {}

    edge(int _to) : to(_to) {}
    edge(int _to, Data _data) : to(_to), data(_data) {}

    bool operator<(const edge &other) const {
        return to < other.to;
    }

    bool operator==(const edge &other) const {
        return to == other.to;
    }
};

template<>
struct edge<void> {
    int to;

    edge() {}

    edge(int _to) : to(_to) {}

    bool operator<(const edge &other) const {
        return to < other.to;
    }

    bool operator==(const edge &other) const {
        return to == other.to;
    }
};

template<typename Edge>
struct graph {

    int V = -1, E;
    vec<Edge> store;
    vec<int> fir;
    vec<pair<int, Edge>> acc_edge;
    bool id6 = 0;

    graph() = default;
    graph(int V) : V(V) {}
    graph(int V, int E) : V(V) { if (E != -1) acc_edge.reserve(E); }

    void prepare() {
        assert(V != -1);
        E = acc_edge.size();
        store.resize(E);
        vec<int> deg_cnt(V + 1);
        for (const auto &p : acc_edge) ++deg_cnt[p.F + 1];
        partial_sum(all(deg_cnt), deg_cnt.begin());
        fir = deg_cnt;
        for (const auto &p : acc_edge) store[deg_cnt[p.F]++] = p.S;
        acc_edge.clear();
        acc_edge.shrink_to_fit();
        id6 = 1;
    }

    inline void add_edge(int x, Edge e, const bool is_dir) {
        acc_edge.pb({x, e});
        if (!is_dir) {
            swap(x, e.to);
            acc_edge.pb({x, e});
        }
    }

    struct edge_range {
        __gnu_cxx::__normal_iterator<const Edge *, vector<Edge>> first, last;
        [[nodiscard]] auto begin() const { return first; }
        [[nodiscard]] auto end() const { return last; }
    };

    edge_range operator[](const int v) const {assert(id6); return {store.begin() + fir[v], store.begin() + fir[v + 1]};}

    [[nodiscard]] inline int deg(const int v) const {assert(id6); return fir[v + 1] - fir[v];}
    vec<int> get_nums_of_inv_edges() const {assert(id6); vec<int> ans(E, -1); vec<bool> us(V); umap<ll, int> mp(E); for (int v = 0; v < V; ++v) {for (int i = fir[v]; i < fir[v + 1]; ++i) {const auto& e = store[i]; ll hs = 1ll * v * V + e.to; ll ihs = 1ll * e.to * V + v; if (mp.count(ihs)) {int ips = mp[ihs]; mp.erase(ihs); ans[i] = ips; ans[ips] = i;} else mp[hs] = i;}} assert(mp.empty()); assert(count(all(ans), -1) == 0); return ans;}
    int count_connected_components() const {assert(id6); vec<bool> us(V); auto dfs = [&](auto && dfs, int v) -> void {us[v] = 1; for (const auto &h : (*this)[v]) if (!us[h.to]) dfs(dfs, h.to);}; int ans = 0; for (int q = 0; q < V; ++q) if (!us[q]) dfs(dfs, q), ++ans; return ans;}
    vec<int> get_cutpoints() const {assert(id6); vec<bool> us(V); vec<int> is_cp(V), tin(V), fup(V); auto dfs = [&](auto && dfs, int v, int p = -1) -> void {static int T = 0; us[v] = 1; tin[v] = fup[v] = T++; int chd = 0; for (const auto &h : (*this)[v]) {if (h.to == p) continue; if (!us[h.to]) {++chd; dfs(dfs, h.to, v); chmin(fup[v], fup[h.to]); is_cp[v] |= p == -1 ? chd > 1 : fup[h.to] >= tin[v];} else chmin(fup[v], tin[h.to]);}}; for (int q = 0; q < V; ++q) if (!us[q]) dfs(dfs, q); vec<int> ans; for (int q = 0; q < V; ++q) if (is_cp[q]) ans.pb(q); return ans;}
    vec<vec<int>> get_edge_biconnected_components() const {assert(id6); vec<bool> is_bridge(E), us(V); vec<int> tin(V), fup(V); auto dfs = [&](auto dfs, int v, int p = -1) -> int {static int T = 0; us[v] = 1; tin[v] = fup[v] = T++; int cnt_par = 0, ie = -1; for (int i = fir[v]; i < fir[v + 1]; ++i) {const auto& h = store[i]; if (h.to == p) {if (++cnt_par > 1) {chmin(fup[v], tin[h.to]);} else ie = i;} else if (!us[h.to]) {int inv_edge = dfs(dfs, h.to, v); chmin(fup[v], fup[h.to]); is_bridge[i] = is_bridge[inv_edge] = fup[h.to] > tin[v];} else chmin(fup[v], tin[h.to]);} return ie;}; int cnt_cmp = 0; for (int q = 0; q < V; ++q) if (!us[q]) dfs(dfs, q), ++cnt_cmp; int id5 = count(all(is_bridge), true) / 2; int id1 = cnt_cmp + id5; vec<vec<int>> ans(id1); fill(all(us), false); auto go = [&](auto && go, int v, int nc) -> void {us[v] = 1; assert(nc < id1); ans[nc].pb(v); for (int i = fir[v]; i < fir[v + 1]; ++i) {const auto& h = store[i]; if (!us[h.to] && !is_bridge[i]) go(go, h.to, nc);}}; for (int q = 0, nc = 0; q < V; ++q) if (!us[q]) go(go, q, nc++); return ans;}
    vec<int> get_bridges_nums() const {assert(id6); vec<bool> is_bridge(E), us(V); vec<int> tin(V), fup(V); auto dfs = [&](auto dfs, int v, int p = -1) -> int {static int T = 0; us[v] = 1; tin[v] = fup[v] = T++; int cnt_par = 0, ie = -1; for (int i = fir[v]; i < fir[v + 1]; ++i) {const auto& h = store[i]; if (h.to == p) {if (++cnt_par > 1) {chmin(fup[v], tin[h.to]);} else ie = i;} else if (!us[h.to]) {int inv_edge = dfs(dfs, h.to, v); chmin(fup[v], fup[h.to]); is_bridge[i] = is_bridge[inv_edge] = fup[h.to] > tin[v];} else chmin(fup[v], tin[h.to]);} return ie;}; for (int q = 0; q < V; ++q) if (!us[q]) dfs(dfs, q); int id5 = count(all(is_bridge), true) / 2; vec<int> ans(id5); for (int q = 0, j = 0; q < V; ++q) {for (int i = fir[q]; i < fir[q + 1]; ++i) {const auto &h = store[i]; if (is_bridge[i] && q < h.to) ans[j++] = h.data;}} return ans;}

    bool is_tree() const {return E == V - 1 && is_connected();}
    bool is_connected() const {return count_connected_components() == 1;}
    bool is_bipartite() const {assert(id6); vec<int> col(V, -1); bool fl = 1; auto dfs = [&](auto && dfs, int v, int c) -> void {col[v] = c; for (const auto &h : (*this)[v]) {if (col[h.to] == -1) dfs(dfs, h.to, c ^ 1); else fl &= col[h.to] != c;}}; for (int q = 0; q < V; ++q) if (col[q] == -1) dfs(dfs, q, 0); return fl;}
    bool has_self_edges() const {assert(id6); for (int v = 0; v < V; ++v) {for (const auto &h : (*this)[v]) {if (v == h.to) return true;}} return false;}
    bool has_multiple_edges() const {assert(id6); for (int v = 0; v < V; ++v) {uset<int> s(deg(v)); for (const auto &h : (*this)[v]) {if (s.count(h.to)) return true; s.insert(h.to);}} return false;}
    bool is_simple() const {return !has_self_edges() && !has_multiple_edges();}
    bool is_functional() const {assert(id6); for (int q = 0; q < V; ++q) if (deg(q) > 1) return false; return true;}
    bool is_acyclic_dir() const {assert(id6); vec<int> state(V); auto dfs = [&](auto && dfs, int v) -> bool{state[v] = 1; for (const auto &h : (*this)[v]) {if (state[h.to] == 1) return false; if (state[h.to] == 0 && !dfs(dfs, h.to)) return false;} state[v] = 2; return true;}; for (int q = 0; q < V; ++q) {if (state[q] == 0 && !dfs(dfs, q)) return false;} return true;}
    bool is_acyclic_undir() const {assert(id6); vec<int> state(V); auto dfs = [&](auto && dfs, int v, int p = -1) -> bool{state[v] = 1; int cnt_par = 0; for (const auto &h : (*this)[v]) {if (h.to == p) {if (++cnt_par == 1) continue;} if (state[h.to] == 1) return false; if (state[h.to] == 0 && !dfs(dfs, h.to, v)) return false;} state[v] = 2; return true;}; for (int q = 0; q < V; ++q) if (state[q] == 0 && !dfs(dfs, q)) return false; return true;}

    vec<int> get_any_dir_cycle_vertex_nums() const {assert(id6); assert(!is_acyclic_dir()); vec<int> state(V), ans; auto dfs = [&](auto && dfs, int v) -> int{state[v] = 1; int ret = -1; for (const auto &h : (*this)[v]) {if (state[h.to] == 1) return h.to; int res = dfs(dfs, h.to); if (res == -1) continue; if (res == -2) {ret = -2; break;} ans.pb(h.to); if (v == res) ans.pb(v); return v != res ? res : -2;} state[v] = 2; return ret;}; for (int q = 0; q < V && ans.empty(); ++q) if (state[q] == 0) dfs(dfs, q); assert(!ans.empty()); reverse(all(ans)); return ans;}
    vec<int> get_any_dir_cycle_edge_nums() const {assert(id6); assert(!is_acyclic_dir()); vec<int> state(V), ans; auto dfs = [&](auto && dfs, int v) -> int{state[v] = 1; int ret = -1; for (const auto &h : (*this)[v]) {if (state[h.to] == 1) {ans.pb(h.data); return h.to;} int res = dfs(dfs, h.to); if (res == -1) continue; if (res == -2) {ret = -2; break;} ans.pb(h.data); return v != res ? res : -2;} state[v] = 2; return ret;}; for (int q = 0; q < V && ans.empty(); ++q) if (state[q] == 0) dfs(dfs, q); assert(!ans.empty()); reverse(all(ans)); return ans;}
    vec<vec<int>> get_vertex_biconnected_components() const {assert(id6); vec<bool> us(V); vec<int> tin(V), fup(V), stq; vec<vec<int>> ans; ans.reserve(V); stq.reserve(V); auto dfs = [&](auto && dfs, int v, int p = -1) -> void {static int T = 0; stq.pb(v); us[v] = 1; tin[v] = fup[v] = T++; int chd = 0; for (const auto &h : (*this)[v]) {if (h.to == p) continue; if (!us[h.to]) {++chd; int stop_sz = stq.size(); dfs(dfs, h.to, v); chmin(fup[v], fup[h.to]); if ((p == -1 && chd > 1) || (p != -1 && fup[h.to] >= tin[v])) {ans.pb({v}); ans.back().reserve(stq.size() - stop_sz + 1); for (; stq.size() > stop_sz;) {ans.back().pb(stq.back()); stq.pop_back();}}} else chmin(fup[v], tin[h.to]);}}; for (int q = 0; q < V; ++q) {if (!us[q]) {dfs(dfs, q); ans.pb(stq); stq.clear();}} return ans;}

    

    


    vec<int> topsort() {
        assert(is_acyclic_dir());
        vec<bool> us(V);
        vec<int> ans; ans.reserve(V);
        auto dfs = [&](auto && dfs, int v) -> void {
            us[v] = 1;
            for (const auto& e : (*this)[v]) {
                if (!us[e.to]) dfs(dfs, e.to);
            }
            ans.pb(v);
        };
        for (int q = 0; q < V; ++q) {
            if (!us[q]) dfs(dfs, q);
        }
        reverse(all(ans));
        return ans;
    }
};

int main() {
    fast;
    int z; cin >> z;
    for (; z--;) {
        int a, k; cin >> a >> k;
        vec<ll> m(a);
        for (int q = 0; q < a; ++q) {
            long long x; cin >> x;
            m[q] = x;
        }
        graph<edge<void>> g(a, k);
        for (int q = 0; q < k; ++q) {
            int x, y; cin >> x >> y; --x, --y;
            g.add_edge(x, y, 1);
        }
        g.prepare();
        vec<int> ts = g.topsort();
        reverse(all(ts));
        auto calc_delta = [&](vec<int> &dd) -> void {
            fill(all(dd), 0);
            for (int q = 0; q < a; ++q) {
                if (m[q]) {
                    --dd[q];
                    for (const auto &h : g[q]) ++dd[h.to];
                }
            }
        };
        ll o = 0;
        auto go = [&](ll t = 1) -> void {
            o += t;
            for (int v : ts) {
                if (m[v]) {
                    m[v] -= t;
                    

                    for (const auto &h : g[v]) m[h.to] += t;
                }
            }
        };
        vec<int> d1(a), d2(a);
        calc_delta(d1);
        if (*min_element(all(d1)) == 0) {
            cout << '0' << '\n';
            continue;
        }
        for (;;) {
            if (*max_element(all(m)) == 0) break;
            for (;;) {
                

                go();
                calc_delta(d2);
                if (d1 == d2) break;
                swap(d1, d2);
            }
            if (*min_element(all(d1)) == 0) {
                --o;
                break;
            }
            ll mn = numeric_limits<ll>::max();
            for (int q = 0; q < a; ++q) {
                if (d1[q] == -1) chmin(mn, m[q]);
            }
            go(mn);
        }
        cout << (long long)((o + mod) % mod) << '\n';
    }
}
