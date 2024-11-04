#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif


template <typename T, T INF = std::numeric_limits<T>::max() / 2, int INVALID = -1> struct ShortestPath {
    int V, E;
    bool single_positive_weight;
    T wmin, wmax;
    std::vector<std::vector<std::pair<int, T>>> to;

    ShortestPath(int V = 0) : V(V), E(0), single_positive_weight(true), wmin(0), wmax(0), to(V) {}
    void add_edge(int s, int t, T w) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);
        to[s].emplace_back(t, w);
        E++;
        if (w > 0 and wmax > 0 and wmax != w) single_positive_weight = false;
        wmin = std::min(wmin, w);
        wmax = std::max(wmax, w);
    }

    std::vector<T> dist;
    std::vector<int> prev;

    

    

    void Dijkstra(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            T d;
            int v;
            std::tie(d, v) = pq.top();
            pq.pop();
            if (dist[v] < d) continue;
            for (auto nx : to[v]) {
                T dnx = d + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    pq.emplace(dnx, nx.first);
                }
            }
        }
    }

    

    void DijkstraVquad(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        std::vector<char> fixed(V, false);
        while (true) {
            int r = INVALID;
            T dr = INF;
            for (int i = 0; i < V; i++) {
                if (!fixed[i] and dist[i] < dr) r = i, dr = dist[i];
            }
            if (r == INVALID) break;
            fixed[r] = true;
            int nxt;
            T dx;
            for (auto p : to[r]) {
                std::tie(nxt, dx) = p;
                if (dist[nxt] > dist[r] + dx) dist[nxt] = dist[r] + dx, prev[nxt] = r;
            }
        }
    }

    

    

    bool BellmanFord(int s, int nb_loop) {
        assert(0 <= s and s < V);
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        for (int l = 0; l < nb_loop; l++) {
            bool upd = false;
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF) continue;
                for (auto nx : to[v]) {
                    T dnx = dist[v] + nx.second;
                    if (dist[nx.first] > dnx) dist[nx.first] = dnx, prev[nx.first] = v, upd = true;
                }
            }
            if (!upd) return true;
        }
        return false;
    }

    

    

    

    void SPFA(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        prev.assign(V, INVALID);
        std::deque<int> q;
        std::vector<char> in_queue(V);
        dist[s] = 0;
        q.push_back(s), in_queue[s] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop_front(), in_queue[now] = 0;
            for (auto nx : to[now]) {
                T dnx = dist[now] + nx.second;
                int nxt = nx.first;
                if (dist[nxt] > dnx) {
                    dist[nxt] = dnx;
                    if (!in_queue[nxt]) {
                        if (q.size() and dnx < dist[q.front()]) { 

                            q.push_front(nxt);
                        } else {
                            q.push_back(nxt);
                        }
                        prev[nxt] = now, in_queue[nxt] = 1;
                    }
                }
            }
        }
    }

    void ZeroOneBFS(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        std::deque<int> que;
        que.push_back(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop_front();
            for (auto nx : to[v]) {
                T dnx = dist[v] + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    if (nx.second) {
                        que.push_back(nx.first);
                    } else {
                        que.push_front(nx.first);
                    }
                }
            }
        }
    }

    bool dag_solver(int s) {
        assert(0 <= s and s < V);
        std::vector<int> indeg(V, 0);
        std::queue<int> que;
        que.push(s);
        while (que.size()) {
            int now = que.front();
            que.pop();
            for (auto nx : to[now]) {
                indeg[nx.first]++;
                if (indeg[nx.first] == 1) que.push(nx.first);
            }
        }
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        que.push(s);
        while (que.size()) {
            int now = que.front();
            que.pop();
            for (auto nx : to[now]) {
                indeg[nx.first]--;
                if (dist[nx.first] > dist[now] + nx.second)
                    dist[nx.first] = dist[now] + nx.second, prev[nx.first] = now;
                if (indeg[nx.first] == 0) que.push(nx.first);
            }
        }
        return *max_element(indeg.begin(), indeg.end()) == 0;
    }

    

    

    std::vector<int> retrieve_path(int goal) const {
        assert(int(prev.size()) == V);
        assert(0 <= goal and goal < V);
        if (dist[goal] == INF) return {};
        std::vector<int> ret{goal};
        while (prev[goal] != INVALID) {
            goal = prev[goal];
            ret.push_back(goal);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    void solve(int s) {
        if (wmin >= 0) {
            if (single_positive_weight) {
                ZeroOneBFS(s);
            } else {
                if ((long long)V * V < (E << 4)) {
                    DijkstraVquad(s);
                } else {
                    Dijkstra(s);
                }
            }
        } else {
            BellmanFord(s, V);
        }
    }

    

    

    std::vector<std::vector<T>> dist2d;
    void WarshallFloyd() {
        dist2d.assign(V, std::vector<T>(V, INF));
        for (int i = 0; i < V; i++) {
            dist2d[i][i] = 0;
            for (auto p : to[i]) dist2d[i][p.first] = std::min(dist2d[i][p.first], p.second);
        }
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                if (dist2d[i][k] == INF) continue;
                for (int j = 0; j < V; j++) {
                    if (dist2d[k][j] == INF) continue;
                    dist2d[i][j] = std::min(dist2d[i][j], dist2d[i][k] + dist2d[k][j]);
                }
            }
        }
    }

    void dump_graphviz(std::string filename = "shortest_path") const {
        std::ofstream ss(filename + ".DOT");
        ss << "digraph{\n";
        for (int i = 0; i < V; i++) {
            for (const auto &e : to[i]) ss << i << "->" << e.first << "[label=" << e.second << "];\n";
        }
        ss << "}\n";
        ss.close();
        return;
    }
};



struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

using Element = int;
using State = vector<bool>;



template <class T_M1, class T_M2, class T = int> State MatroidIntersection(T_M1 matroid1, T_M2 matroid2, std::vector<T> weights = {}) {
    assert(matroid1.M == matroid2.M);
    const int M = matroid1.M;
    if (weights.empty()) weights.assign(M, 0);

    const Element gs = M, gt = M + 1;
    State I(M);

    while (true) {
        ShortestPath<T> sssp(M + 2);
        matroid1.set_state(I);
        matroid2.set_state(I);
        for (int e = 0; e < M; e++) {
            if (I[e]) continue;
            std::vector<Element> c1 = matroid1.circuit(e), c2 = matroid2.circuit(e);
            if (c1.empty()) sssp.add_edge(e, gt, 0);
            for (Element f : c1) sssp.add_edge(e, f, -(weights[f] * M) + 1);
            if (c2.empty()) sssp.add_edge(gs, e, (weights[e] * M) + 1);
            for (Element f : c2) sssp.add_edge(f, e, (weights[e] * M) + 1);
        }
        sssp.solve(gs);
        auto aug_path = sssp.retrieve_path(gt);
        if (aug_path.empty()) break;
        for (auto e : aug_path) {
            if (e != gs and e != gt) I[e] = !I[e];
        }
    }
    return I;
}



struct GraphMatroid {
    using Vertex = int;
    int M;
    int V; 

    vector<vector<pair<Vertex, Element>>> to;
    vector<pair<Vertex, Vertex>> edges;
    GraphMatroid() = default;
    GraphMatroid(int V, vector<pair<Vertex, Vertex>> edges_) : M(edges_.size()), V(V), to(V), edges(edges_) {
        for (size_t e = 0; e < edges_.size(); e++) {
            assert(edges_[e].first < V and edges_[e].second < V);
            to[edges_[e].first].emplace_back(edges_[e].second, e);
            to[edges_[e].second].emplace_back(edges_[e].first, e);
        }
    }
    State I;
    std::vector<Element> backtrack;
    std::vector<Vertex> vprev;
    std::vector<int> depth;
    UnionFind uf;
    void set_state(State I_) {
        assert(int(I_.size()) == M);
        I = I_;
        backtrack.assign(V, -1);
        vprev.resize(V);
        depth.assign(V, -1);
        uf = UnionFind(V);
        static std::vector<Vertex> que(V);
        int qb, qe;
        for (Vertex i = 0; i < V; i++) {
            if (backtrack.at(i) >= 0) continue;
            que[qb = 0] = i, qe = 1, depth[i] = 0;
            while (qb < qe) {
                Vertex now = que[qb++];
                for (auto nxt : to[now]) {
                    if (depth[nxt.first] < 0 and I[nxt.second]) {
                        backtrack[nxt.first] = nxt.second;
                        vprev[nxt.first] = now;
                        depth[nxt.first] = depth[now] + 1;
                        uf.unite(now, nxt.first);
                        que[qe++] = nxt.first;
                    }
                }
            }
        }
    }
    std::vector<Element> circuit(Element e) {
        assert(0 <= e and e < M);
        if (I.at(e)) return {};
        Vertex s = edges[e].first, t = edges[e].second;
        if (!uf.same(s, t)) return {};
        std::vector<Element> ret;
        auto step = [&](Vertex &i) {
            assert(i >= 0);
            ret.push_back(backtrack.at(i)), i = vprev.at(i);
            assert(i >= 0);
        };
        while (depth.at(s) > depth.at(t)) {
            step(s);
            assert(s >= 0);
        }
        while (depth.at(t) > depth.at(s)) {
            step(t);
            assert(t >= 0);
        }
        while (s != t) {
            assert(s >= 0);
            assert(t >= 0);
            step(s), step(t);
        }
        return ret;
    }
};



struct PartitionMatroid {
    int M;
    vector<vector<Element>> parts;
    vector<int> belong;
    vector<int> maxi;
    PartitionMatroid() = default;
    

    

    PartitionMatroid(int M, const vector<vector<int>> &parts, const vector<int> &maxi)
        : M(M), parts(parts), belong(M, -1), maxi(maxi) {
        assert(parts.size() == maxi.size());
        for (size_t i = 0; i < parts.size(); i++) {
            for (Element x : parts[i]) belong[x] = i;
        }
        for (Element e = 0; e < M; e++) {
            

            if (belong[e] == -1) {
                belong[e] = this->parts.size();
                this->parts.emplace_back(vector<int>{e});
                this->maxi.push_back(1);
            }
        }
    }

    State I;
    void set_state(const State &I_) {
        assert(int(I_.size()) == M);
        I = I_;
    }

    std::vector<Element> circuit(Element e) {
        assert(0 <= e and  e < M);
        if (I[e]) return {};
        std::vector<Element> ret;
        int p = belong[e];
        int cnt = 0;
        for (Element x : parts[p]) cnt += I[x];
        if (cnt == maxi[p]) {
            for (Element x : parts[p])
                if (I[x]) ret.push_back(x);
        }
        return ret;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> D(K);
    cin >> D;
    vector W(N, vector<int>(N));
    REP(i, N) FOR(j, i + 1, N) {
        int w;
        cin >> w;
        W[i][j] = W[j][i] = w;
    }

    constexpr int INF = 1 << 29;
    vector<tuple<int, int, int>> special_edges;
    REP(i, K) REP(j, i) special_edges.emplace_back(W[i][j], i, j);
    vector<int> W_outer;
    vector<pint> edges_outer;

    {
        vector<tuple<int, int, int>> outer_edges;
        FOR(i, K, N) FOR(j, K, i) outer_edges.emplace_back(W[i][j], i, j);
        std::sort(outer_edges.begin(), outer_edges.end());

        

        UnionFind uf(N);
        for (auto [w, u, v] : outer_edges) {
            if (uf.unite(u, v)) {
                W_outer.push_back(w);
                edges_outer.emplace_back(u, v);
            }
        }
    }

    int ret = INF;
    for (int s = 0; s < (1 << special_edges.size()); s++) {
        int wnow = 0;
        UnionFind uf(N);
        auto deg_upper = D;
        for (int se = 0; se < int(special_edges.size()); se++) {
            auto [w, u, v] = special_edges[se];
            if ((s >> se) & 1 and uf.unite(u, v)) wnow += w, deg_upper[u]--, deg_upper[v]--;
        }
        if (*min_element(ALL(deg_upper)) < 0) continue;

        vector<int> ws = W_outer;
        vector<pair<int, int>> edges = edges_outer;
        vector<vector<int>> partitions(K);
        REP(i, K) FOR(j, K, N) {
            if (!deg_upper[i]) continue;
            int eid = ws.size();
            ws.push_back(W[i][j]);
            edges.emplace_back(uf.find(i), j);
            partitions[i].push_back(eid);
        }
        GraphMatroid mat1(N, edges);
        PartitionMatroid mat2(edges.size(), partitions, deg_upper);
        auto sol = MatroidIntersection(mat1, mat2, ws);
        auto deg_upper_origin = deg_upper;
        REP(e, sol.size()) if (sol[e]) {
            uf.unite(edges[e].first, edges[e].second);
            if (edges[e].first < K) deg_upper[edges[e].first]--;
            wnow += ws[e];
        }
        if (uf.count(0) == N) chmin(ret, wnow);
    }
    cout << ret << '\n';
}
