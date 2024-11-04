































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
int id6(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
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

const string COLOR_RESET = "\033[0m", id12 = "\033[1;32m", id15 = "\033[1;31m", id10 = "\033[1;36m", id3 = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", id5 = "\033[0;2m";











template <class Cap, int id1 = 5, bool id13 = true>
struct id8 {
    struct pque_ {
        std::vector<std::pair<int, int>> even_, odd_;
        int se, so;
        void init(int n) { even_.resize(n), odd_.resize(n), se = so = 0; };
        void clear() { se = so = 0; }
        bool empty() const { return se + so == 0; }
        void push(int i, int h) { (h & 1 ? odd_.at(so++) : even_.at(se++)) = {i, h}; }
        int highest() const {
            int a = se ? even_.at(se - 1).second : -1, b = so ? odd_.at(so - 1).second : -1;
            return a > b ? a : b;
        }
        int pop() {
            if (!se or (so and odd_.at(so - 1).second > even_.at(se - 1).second))
                return odd_.at(--so).first;
            return even_.at(--se).first;
        }
    } pque;
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::vector<_edge>> g;
    std::vector<std::pair<int, int>> pos;
    id8(int n) : _n(n), g(n) {
        static_assert(id1 >= 0, "Global relabel parameter must be nonnegative.");
    }
    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from and from < _n);
        assert(0 <= to and to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.emplace_back(from, int(g.at(from).size()));
        int from_id = g.at(from).size(), to_id = g.at(to).size() + (from == to);
        g.at(from).push_back({to, to_id, cap});
        g.at(to).push_back({from, from_id, Cap(0)});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) const {
        int m = int(pos.size());
        assert(0 <= i and i < m);
        auto e = g[pos[i].first][pos[i].second], re = g[e.to][e.rev];
        return edge{pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    std::vector<edge> edges() const {
        std::vector<edge> ret(pos.size());
        for (int i = 0; i < int(pos.size()); i++) ret[i] = get_edge(i);
        return ret;
    }

    std::vector<int> dist;
    std::vector<int> dcnt;
    std::vector<Cap> excess;
    int gap;
    void global_relabeling(int t) {
        dist.assign(_n, _n), dist.at(t) = 0;
        static std::vector<int> q;
        if (q.empty()) q.resize(_n);
        q.at(0) = t;
        int qb = 0, qe = 1;
        pque.clear();
        if (id13) gap = 1, dcnt.assign(_n + 1, 0);

        while (qb < qe) {
            int now = q.at(qb++);
            if (id13) gap = dist.at(now) + 1, dcnt.at(dist.at(now))++;
            if (excess.at(now) > 0) pque.push(now, dist.at(now));
            for (const auto &e : g.at(now)) {
                if (g.at(e.to).at(e.rev).cap and dist.at(e.to) == _n) {
                    dist.at(e.to) = dist.at(now) + 1;

                    while (q.size() <= qe) q.push_back(0);

                    q.at(qe++) = e.to;
                }
            }
        }
    }
    Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max(), true); }
    Cap flow(int s, int t, Cap flow_limit, bool retrieve = true) {
        assert(0 <= s and s < _n);
        assert(0 <= t and t < _n);
        assert(s != t);
        excess.resize(_n, 0);
        excess[s] += flow_limit, excess[t] -= flow_limit;
        dist.assign(_n, 0);
        dist[s] = _n;
        if (id13) gap = 1, dcnt.assign(_n + 1, 0), dcnt[0] = _n - 1;
        pque.init(_n);
        for (auto &e : g[s]) _push(s, e);
        _run(t);
        Cap ret = excess[t] + flow_limit;
        excess[s] += excess[t], excess[t] = 0;
        if (retrieve) {
            global_relabeling(s);
            _run(s);
            assert(excess == std::vector<Cap>(_n, 0));
        }
        return ret;
    }
    void _run(int t) {
        if (id1) global_relabeling(t);
        int tick = pos.size() * id1;
        while (!pque.empty()) {
            int i = pque.pop();
            if (id13 and dist[i] > gap) continue;
            int dnxt = _n * 2 - 1;
            for (auto &e : g[i]) {
                if (!e.cap) continue;
                if (dist[e.to] == dist[i] - 1) {
                    _push(i, e);
                    if (excess[i] == 0) break;
                } else {
                    if (dist[e.to] + 1 < dnxt) dnxt = dist[e.to] + 1;
                }
            }
            if (excess[i] > 0) {
                if (id13) {
                    if (dnxt != dist[i] and dcnt[dist[i]] == 1 and dist[i] < gap) gap = dist[i];
                    if (dnxt == gap) gap++;
                    while (pque.highest() > gap) pque.pop();
                    if (dnxt > gap) dnxt = _n;
                    if (dist[i] != dnxt) dcnt[dist[i]]--, dcnt[dnxt]++;
                }
                dist[i] = dnxt;
                if (!id13 or dist[i] < gap) pque.push(i, dist[i]);
            }
            if (id1 and --tick == 0) {
                tick = pos.size() * id1, global_relabeling(t);
            }
        }
        return;
    }

    void _push(int i, _edge &e) {
        Cap delta = e.cap < excess[i] ? e.cap : excess[i];
        excess[i] -= delta, e.cap -= delta;
        excess[e.to] += delta, g[e.to][e.rev].cap += delta;
        if (excess[e.to] > 0 and excess[e.to] <= delta) {
            if (!id13 or dist[e.to] <= gap) pque.push(e.to, dist[e.to]);
        }
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
        pos.push_back({from, int(g.at(from).size())});
        int from_id = int(g.at(from).size());
        int to_id = int(g.at(to).size());
        if (from == to) to_id++;
        g.at(from).push_back(_edge{to, to_id, cap});
        g.at(to).push_back(_edge{from, from_id, 0});
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
        static const uint64_t id4 =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id4);
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
    int id9 = A[0];
    for (auto a : A) id9 = __gcd(id9, a);
    for (auto &x : A) x /= id9;

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
    vector<lint> id2;
    for (auto a : adict) {
        lint r = a;
        while (binary_search(ALL(adict), r)) {
            r += a;
        }
        id2.push_back(r);
    }

    vector<lint> id11;

    REP(t, free_as.size()) {
        dbg(t);

        REP(i, id2.size()) {
            while (binary_search(ALL(id11), id2[i]) or binary_search(ALL(fixed_as), id2[i])) id2[i] += adict[i];
        }

        auto id14 = sort_unique(id2);
        dbg(id2);

        const int gs = adict.size() + id11.size(), gt = gs + 1;
        id8<int> graph(gt + 1);
        REP(i, adict.size()) {
            graph.add_edge(gs, i, adc[i]);
        }
        REP(i, adict.size()) {
            REP(j, id11.size()) {
                if (id11[j] % adict[i] == 0) graph.add_edge(i, adict.size() + j, 1);
            }
        }
        REP(j, id11.size()) graph.add_edge(adict.size() + j, gt, 1);

        for (auto e : graph.edges()) {
            dbg(make_tuple(e.from, e.to, e.cap, e.flow));
        }
        dbg("Gen graph");
        dbg(gt);

        assert(graph.flow(gs, gt, t, true) == t);
        vector<vector<int>> to(gt + 1);
        for (auto e : graph.edges()) {
            dbg(make_tuple(e.from, e.to, e.cap, e.flow));
            if (e.from == gs) {
                if (e.flow < e.cap) to[e.from].push_back(e.to);
            } else if (e.from < int(adict.size())) {
                if (e.to >= adict.size()) {
                    if (!e.flow) to.at(e.from).push_back(e.to);
                    if (e.flow) to.at(e.to).push_back(e.from);
                }
            }
        }
        vector<int> reach(gt + 1);
        reach.at(gs) = 1;
        vector<int> st{gs};
        while (st.size()) {
            int now = st.back();
            st.pop_back();
            for (auto nxt : to.at(now)) {
                if (chmax(reach.at(nxt), 1)) st.push_back(nxt);
            }
        }
        lint id7 = 1LL << 60;
        REP(i, adict.size()) if (reach.at(i)) chmin(id7, id2.at(i));

        id11.push_back(id7);
        id11 = sort_unique(id11);
        dbg(id11);

        occupied.insert(id7);
    }

    cout << accumulate(occupied.begin(), occupied.end(), 0LL) * id9 << endl;
}
