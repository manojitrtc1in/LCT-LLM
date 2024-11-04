





























using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } id2;





template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int id10(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa);

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }

template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }

template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }

const string COLOR_RESET = "\033[0m", id12 = "\033[1;32m", id14 = "\033[1;31m", id11 = "\033[1;36m", id7 = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", id9 = "\033[0;2m";















struct id1 {
    int V;
    std::vector<std::vector<int>> to; 

    std::vector<int> dist;            

    std::vector<int> match;           

    std::vector<int> used, vv;
    std::vector<int> color; 


    id1() = default;
    id1(int V_) : V(V_), to(V_), match(V_, -1), used(V_), color(V_, -1) {}

    void add_edge(int u, int v) {
        assert(u >= 0 and u < V and v >= 0 and v < V and u != v);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    void _bfs() {
        dist.assign(V, -1);
        std::vector<int> q;
        int lq = 0;
        for (int i = 0; i < V; i++) {
            if (!color[i] and !used[i]) q.push_back(i), dist[i] = 0;
        }

        while (lq < int(q.size())) {
            int now = q[lq++];
            for (auto nxt : to[now]) {
                int c = match[nxt];
                if (c >= 0 and dist[c] == -1) q.push_back(c), dist[c] = dist[now] + 1;
            }
        }
    }

    bool _dfs(int now) {
        vv[now] = true;
        for (auto nxt : to[now]) {
            int c = match[nxt];
            if (c < 0 or (!vv[c] and dist[c] == dist[now] + 1 and _dfs(c))) {
                match[nxt] = now, match[now] = nxt;
                used[now] = true;
                return true;
            }
        }
        return false;
    }

    bool _color_bfs(int root) {
        color[root] = 0;
        std::vector<int> q{root};
        int lq = 0;
        while (lq < int(q.size())) {
            int now = q[lq++], c = color[now];
            for (auto nxt : to[now]) {
                if (color[nxt] == -1) {
                    color[nxt] = !c, q.push_back(nxt);
                } else if (color[nxt] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    int solve() {
        for (int i = 0; i < V; i++) {
            if (color[i] == -1 and !_color_bfs(i)) return -1;
        }
        int ret = 0;
        while (true) {
            _bfs();
            vv.assign(V, false);
            int flow = 0;
            for (int i = 0; i < V; i++) {
                if (!color[i] and !used[i] and _dfs(i)) flow++;
            }
            if (!flow) break;
            ret += flow;
        }
        return ret;
    }

    template <class OStream> friend OStream &operator<<(OStream &os, const id1 &bm) {
        os << "{N=" << bm.V << ':';
        for (int i = 0; i < bm.V; i++) {
            if (bm.match[i] > i) os << '(' << i << '-' << bm.match[i] << "),";
        }
        return os << '}';
    }
};







struct id6 {
    int V; 

    std::vector<std::vector<int>> to, from;
    std::vector<int> used; 

    std::vector<int> vs;
    std::vector<int> cmp;
    int id13 = -1;

    id6(int V = 0) : V(V), to(V), from(V), cmp(V) {}

    void _dfs(int v) {
        used[v] = true;
        for (auto t : to[v])
            if (!used[t]) _dfs(t);
        vs.push_back(v);
    }
    void _rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto t : from[v])
            if (!used[t]) _rdfs(t, k);
    }

    void add_edge(int from_, int to_) {
        assert(from_ >= 0 and from_ < V and to_ >= 0 and to_ < V);
        to[from_].push_back(to_);
        from[to_].push_back(from_);
    }

    

    

    int FindStronglyConnectedComponents() {
        used.assign(V, false);
        vs.clear();
        for (int v = 0; v < V; v++)
            if (!used[v]) _dfs(v);
        used.assign(V, false);
        id13 = 0;
        for (int i = (int)vs.size() - 1; i >= 0; i--)
            if (!used[vs[i]]) _rdfs(vs[i], id13++);
        return id13;
    }

    

    

    

    int _c, _init;
    std::vector<int> _ret_cycle;
    bool _dfs_detectcycle(int now, bool b0) {
        if (now == _init and b0) return true;
        for (auto nxt : to[now])
            if (cmp[nxt] == _c and !used[nxt]) {
                _ret_cycle.emplace_back(nxt), used[nxt] = 1;
                if (_dfs_detectcycle(nxt, true)) return true;
                _ret_cycle.pop_back();
            }
        return false;
    }
    std::vector<int> DetectCycle() {
        int ns = FindStronglyConnectedComponents();
        if (ns == V) return {};
        std::vector<int> cnt(ns);
        for (auto x : cmp) cnt[x]++;
        _c = std::find_if(cnt.begin(), cnt.end(), [](int x) { return x > 1; }) - cnt.begin();
        _init = std::find(cmp.begin(), cmp.end(), _c) - cmp.begin();
        used.assign(V, false);
        _ret_cycle.clear();
        _dfs_detectcycle(_init, false);
        return _ret_cycle;
    }

    

    

    id6 GenerateTopologicalGraph() {
        id6 newgraph(id13);
        for (int s = 0; s < V; s++)
            for (auto t : to[s]) {
                if (cmp[s] != cmp[t]) newgraph.add_edge(cmp[s], cmp[t]);
            }
        return newgraph;
    }
};











struct id3 : id6 {
    int id8;
    std::vector<int> solution;
    id3(int nb_variables = 0)
        : id6(nb_variables * 2), id8(nb_variables), solution(id8) {}
    void add_x_or_y_constraint(bool id0, int x, bool id5, int y) {
        assert(x >= 0 and x < id8);
        assert(y >= 0 and y < id8);
        if (!id0) x += id8;
        if (!id5) y += id8;
        add_edge((x + id8) % (id8 * 2), y);
        add_edge((y + id8) % (id8 * 2), x);
    }
    

    

    bool run() {
        FindStronglyConnectedComponents();
        for (int i = 0; i < id8; i++) {
            if (cmp[i] == cmp[i + id8]) return false;
            solution[i] = cmp[i] > cmp[i + id8];
        }
        return true;
    }
};























std::vector<std::pair<std::vector<int>, std::vector<int>>>
id4(int L, int R, const std::vector<std::pair<int, int>> &edges) {
    for (auto p : edges) {
        assert(0 <= p.first and p.first < L);
        assert(0 <= p.second and p.second < R);
    }

    id1 bm(L + R);
    for (auto p : edges) bm.add_edge(p.first, L + p.second);
    bm.solve();

    id6 scc(L + R);
    for (auto p : edges) scc.add_edge(p.first, L + p.second);
    for (int l = 0; l < L; ++l) {
        if (bm.match[l] >= L) scc.add_edge(bm.match[l], l);
    }

    int nscc = scc.FindStronglyConnectedComponents();
    std::vector<int> cmp_map(nscc, -2);

    std::vector<int> vis(L + R);
    std::vector<int> st;
    for (int c = 0; c < 2; ++c) {
        std::vector<std::vector<int>> to(L + R);
        auto color = [&L](int x) { return x >= L; };
        for (auto p : edges) {
            int u = p.first, v = L + p.second;
            if (color(u) != c) std::swap(u, v);
            to[u].push_back(v);
            if (bm.match[u] == v) to[v].push_back(u);
        }
        for (int i = 0; i < L + R; ++i) {
            if (bm.match[i] >= 0 or color(i) != c or vis[i]) continue;
            vis[i] = 1, st = {i};
            while (!st.empty()) {
                int now = st.back();
                cmp_map[scc.cmp[now]] = c - 1;
                st.pop_back();
                for (int nxt : to[now]) {
                    if (!vis[nxt]) vis[nxt] = 1, st.push_back(nxt);
                }
            }
        }
    }

    int nset = 1;
    for (int n = 0; n < nscc; ++n) {
        if (cmp_map[n] == -2) cmp_map[n] = nset++;
    }
    for (auto &x : cmp_map) {
        if (x == -1) x = nset;
    }
    nset++;

    std::vector<std::pair<std::vector<int>, std::vector<int>>> groups(nset);

    for (int l = 0; l < L; ++l) {
        if (bm.match[l] < 0) continue;
        int c = cmp_map[scc.cmp[l]];
        groups[c].first.push_back(l);
        groups[c].second.push_back(bm.match[l] - L);
    }
    for (int l = 0; l < L; ++l) {
        if (bm.match[l] >= 0) continue;
        int c = cmp_map[scc.cmp[l]];
        groups[c].first.push_back(l);
    }
    for (int r = 0; r < R; ++r) {
        if (bm.match[L + r] >= 0) continue;
        int c = cmp_map[scc.cmp[L + r]];
        groups[c].second.push_back(r);
    }

    return groups;
}

int main() {
    int L, R, M, Q;
    cin >> L >> R >> M >> Q;
    vector<pint> edges;
    map<pint, int> id15;
    REP(e, M) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
        id15[pint(u, v)] = e + 1;
    }
    auto dm = id4(L, R, edges);
    dbg(dm);

    vector<pint> match;
    int nmatch = 0;
    lint wmatch = 0;
    for (auto [l, r] : dm) {
        REP(i, min(l.size(), r.size())) {
            int lid = l.at(i) + 1;
            int rid = -(r.at(i) + 1);
            int eid = id15.at(pint(l.at(i), r.at(i)));
            if (l.size() <= r.size()) match.emplace_back(lid, eid);
            else {
                match.emplace_back(rid, eid);
            }
            ++nmatch;
            wmatch += eid;
        }
    }
    dbg(nmatch);
    dbg(wmatch);
    dbg(match);

    while (Q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            auto [vid, eid] = match.back();
            match.pop_back();
            --nmatch;
            wmatch -= eid;
            cout << "1\n" << vid << '\n' << wmatch << endl;
        } else {
            cout << match.size() << '\n';
            for (auto [vid, eid] : match) cout << eid << ' ';
            cout << endl;
        }
    }
}
