





























using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } id0;





template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int id8(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <class T1, class T2> std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first + r.first, l.second + r.second); }
template <class T1, class T2> std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first - r.first, l.second - r.second); }
template <class T> std::vector<T> sort_unique(std::vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <class T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <class T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <class IStream, class T> IStream &operator>>(IStream &is, std::vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec);
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr);
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const pair<T, U> &pa);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa);
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp);
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp);
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl);

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }

template <class... T> std::istream &operator>>(std::istream &is, std::tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }

template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }

const string COLOR_RESET = "\033[0m", id13 = "\033[1;32m", id15 = "\033[1;31m", id11 = "\033[1;36m", id4 = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", id6 = "\033[0;2m";



















template <class Cap, class Cost> struct id3 {
    template <class E> struct csr {
        std::vector<int> start;
        std::vector<E> elist;
        explicit csr(int n, const std::vector<std::pair<int, E>> &edges)
            : start(n + 1), elist(edges.size()) {
            for (auto e : edges) { start[e.first + 1]++; }
            for (int i = 1; i <= n; i++) { start[i] += start[i - 1]; }
            auto counter = start;
            for (auto e : edges) { elist[counter[e.first]++] = e.second; }
        }
    };

public:
    id3() {}
    explicit id3(int n) : _n(n) {
        static_assert(std::numeric_limits<Cap>::max() > 0, "max() must be greater than 0");
    }

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(_edges.size());
        _edges.push_back({from, to, cap, 0, cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(_edges.size());
        assert(0 <= i && i < m);
        return _edges[i];
    }
    std::vector<edge> edges() { return _edges; }

    std::pair<Cap, Cost> flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        int m = int(_edges.size());
        std::vector<int> edge_idx(m);

        auto g = [&]() {
            std::vector<int> degree(_n), id2(m);
            std::vector<std::pair<int, _edge>> elist;
            elist.reserve(2 * m);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] = degree[e.from]++;
                id2[i] = degree[e.to]++;
                elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
                elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
            }
            auto _g = csr<_edge>(_n, elist);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] += _g.start[e.from];
                id2[i] += _g.start[e.to];
                _g.elist[edge_idx[i]].rev = id2[i];
                _g.elist[id2[i]].rev = edge_idx[i];
            }
            return _g;
        }();

        auto result = slope(g, s, t, flow_limit);

        for (int i = 0; i < m; i++) {
            auto e = g.elist[edge_idx[i]];
            _edges[i].flow = _edges[i].cap - e.cap;
        }

        return result;
    }

private:
    int _n;
    std::vector<edge> _edges;

    

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<Cap, Cost>> slope(csr<_edge> &g, int s, int t, Cap flow_limit) {
        

        

        


        

        std::vector<std::pair<Cost, Cost>> dual_dist(_n);
        std::vector<int> prev_e(_n);
        std::vector<bool> vis(_n);
        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        std::vector<int> que_min;
        std::vector<Q> que;
        auto dual_ref = [&]() {
            for (int i = 0; i < _n; i++) {
                dual_dist[i].second = std::numeric_limits<Cost>::max();
            }
            std::fill(vis.begin(), vis.end(), false);
            que_min.clear();
            que.clear();

            

            size_t heap_r = 0;

            dual_dist[s].second = 0;
            que_min.push_back(s);
            while (!que_min.empty() || !que.empty()) {
                int v;
                if (!que_min.empty()) {
                    v = que_min.back();
                    que_min.pop_back();
                } else {
                    while (heap_r < que.size()) {
                        heap_r++;
                        std::push_heap(que.begin(), que.begin() + heap_r);
                    }
                    v = que.front().to;
                    std::pop_heap(que.begin(), que.end());
                    que.pop_back();
                    heap_r--;
                }
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                

                

                

                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto e = g.elist[i];
                    if (!e.cap) continue;
                    

                    

                    Cost cost = e.cost - dual_dist[e.to].first + dual_v;
                    if (dual_dist[e.to].second - dist_v > cost) {
                        Cost dist_to = dist_v + cost;
                        dual_dist[e.to].second = dist_to;
                        prev_e[e.to] = e.rev;
                        if (dist_to == dist_v) {
                            que_min.push_back(e.to);
                        } else {
                            que.push_back(Q{dist_to, e.to});
                        }
                    }
                }
            }
            if (!vis[t]) { return false; }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                

                

                

                

                

                dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, id7 = -1;
        std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
            }
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                auto &e = g.elist[prev_e[v]];
                e.cap += c;
                g.elist[e.rev].cap -= c;
            }
            Cost d = -dual_dist[s].first;
            flow += c;
            cost += c * d;
            if (id7 == d) { result.pop_back(); }
            result.push_back({flow, cost});
            id7 = d;
        }
        return result;
    }
};





template <class Cap> struct mf_graph {
    struct simple_queue_int {
        std::vector<int> payload;
        int pos = 0;
        void reserve(int n) { payload.reserve(n); }
        int size() const { return int(payload.size()) - pos; }
        bool empty() const { return pos == int(payload.size()); }
        void push(const int &t) { payload.push_back(t); }
        int &front() { return payload[pos]; }
        void clear() {
            payload.clear();
            pos = 0;
        }
        void pop() { pos++; }
    };

    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) { result.push_back(get_edge(i)); }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto &_e = g[pos[i].first][pos[i].second];
        auto &_re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    std::vector<int> level, iter;
    simple_queue_int que;

    void _bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        level[s] = 0;
        que.clear();
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto e : g[v]) {
                if (e.cap == 0 || level[e.to] >= 0) continue;
                level[e.to] = level[v] + 1;
                if (e.to == t) return;
                que.push(e.to);
            }
        }
    }
    Cap _dfs(int v, int s, Cap up) {
        if (v == s) return up;
        Cap res = 0;
        int level_v = level[v];
        for (int &i = iter[v]; i < int(g[v].size()); i++) {
            _edge &e = g[v][i];
            if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
            Cap d = _dfs(e.to, s, std::min(up - res, g[e.to][e.rev].cap));
            if (d <= 0) continue;
            g[v][i].cap += d;
            g[e.to][e.rev].cap -= d;
            res += d;
            if (res == up) return res;
        }
        level[v] = _n;
        return res;
    }

    Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        level.assign(_n, 0), iter.assign(_n, 0);
        que.clear();

        Cap flow = 0;
        while (flow < flow_limit) {
            _bfs(s, t);
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = _dfs(t, s, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        simple_queue_int que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

    void dump_graphviz(std::string filename = "maxflow") const {
        std::ofstream ss(filename + ".DOT");
        ss << "digraph{\n";
        for (int i = 0; i < _n; i++) {
            for (const auto &e : g[i]) {
                if (e.cap > 0) ss << i << "->" << e.to << "[label=" << e.cap << "];\n";
            }
        }
        ss << "}\n";
        ss.close();
        return;
    }

    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};


struct custom_hash {
    

    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id5 =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id5);
    }
};







int main() {
    int N;
    cin >> N;

    set<lint> occupied;

    vector<int> A(N);
    cin >> A;
    sort(ALL(A));

    

    


    N = A.size();

    dbg(A);
    int id10 = A[0];
    for (auto a : A) id10 = __gcd(id10, a);
    for (auto &x : A) x /= id10;

    vector<int> free_as;
    for (auto a : A) {
        if (occupied.count(a)) {
            free_as.push_back(a);
        } else {
            occupied.insert(a);
        }
    }

    const vector<lint> fixed_as(ALL(occupied));

    vector<int> adict = sort_unique(free_as);
    vector<int> adc(adict.size());

    for (auto a : free_as) {
        adc.at(arglb(adict, a))++;
    }
    vector<lint> id1;
    for (auto a : adict) {
        lint r = a;
        while (binary_search(ALL(adict), r)) {
            r += a;
        }
        id1.push_back(r);
    }

    vector<lint> id12;

    REP(t, free_as.size()) {

        REP(i, id1.size()) {
            while (binary_search(ALL(id12), id1[i]) or binary_search(ALL(fixed_as), id1[i])) id1[i] += adict[i];
        }

        auto id14 = sort_unique(id1);
        int ilo = -1, ihi = id14.size() - 1;
        dbg(id1);
        while (ihi - ilo > 1) {
            const int ic = (ilo + ihi) / 2;
            const lint hi = id14.at(ic);

            const int gs = adict.size() + id12.size() + 1, gt = gs + 1;
            mf_graph<int> graph(gt + 1);
            REP(i, adict.size()) {
                graph.add_edge(gs, i, adc.at(i));
                REP(j, id12.size()) {
                    if (id12.at(j) % adict.at(i) == 0) graph.add_edge(i, adict.size() + j, 1);
                }
                

                

                

                if (hi >= id1.at(i)) graph.add_edge(i, adict.size() + id12.size(), 1);
            }
            REP(j, id12.size()) {
                graph.add_edge(adict.size() + j, gt, 1);
            }
            graph.add_edge(adict.size() + id12.size(), gt, 1);
            

            

            


            (graph.flow(gs, gt) >= t + 1 ? ihi : ilo) = ic;
        }
        

        lint id9 = id14.at(ihi);
        id12.push_back(id9);
        id12 = sort_unique(id12);
        dbg(id12);

        

        occupied.insert(id9);
    }

    dbg(occupied);
    cout << accumulate(occupied.begin(), occupied.end(), 0LL) * id10 << endl;
}
