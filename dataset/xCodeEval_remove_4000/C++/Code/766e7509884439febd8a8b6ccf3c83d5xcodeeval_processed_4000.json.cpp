





























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
int id5(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <class T1, class T2> T1 floor_div(T1 num, T2 den) { return (num > 0 ? num / den : -((-num + den - 1) / den)); }
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

const string COLOR_RESET = "\033[0m", id8 = "\033[1;32m", id10 = "\033[1;31m", id7 = "\033[1;36m", id2 = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", id4 = "\033[0;2m";



















struct id3 {
    int V;
    int k;
    int id1;
    std::vector<std::vector<int>> e;
    std::vector<int> par;         

    std::vector<int> depth;       

    std::vector<int> subtree_sz;  

    std::vector<int> heavy_child; 

    std::vector<int> tree_id;     

    std::vector<int> aligned_id,
        aligned_id_inv;    

    std::vector<int> head; 

    std::vector<int> head_ids;      

    std::vector<int> heavy_path_id; 


    id3(int sz = 0)
        : V(sz), k(0), id1(0), e(sz), par(sz), depth(sz), subtree_sz(sz), heavy_child(sz),
          tree_id(sz, -1), aligned_id(sz), aligned_id_inv(sz), head(sz), heavy_path_id(sz, -1) {}
    void add_edge(int u, int v) {
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    void _build_dfs(int root) {
        std::stack<std::pair<int, int>> st;
        par[root] = -1;
        depth[root] = 0;
        st.emplace(root, 0);
        while (!st.empty()) {
            int now = st.top().first;
            int &i = st.top().second;
            if (i < (int)e[now].size()) {
                int nxt = e[now][i++];
                if (nxt == par[now]) continue;
                par[nxt] = now;
                depth[nxt] = depth[now] + 1;
                st.emplace(nxt, 0);
            } else {
                st.pop();
                int id9 = 0;
                subtree_sz[now] = 1;
                heavy_child[now] = -1;
                for (auto nxt : e[now]) {
                    if (nxt == par[now]) continue;
                    subtree_sz[now] += subtree_sz[nxt];
                    if (id9 < subtree_sz[nxt])
                        id9 = subtree_sz[nxt], heavy_child[now] = nxt;
                }
            }
        }
    }

    void _build_bfs(int root, int id11) {
        std::queue<int> q({root});
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            head_ids.emplace_back(h);
            for (int now = h; now != -1; now = heavy_child[now]) {
                tree_id[now] = id11;
                aligned_id[now] = k++;
                aligned_id_inv[aligned_id[now]] = now;
                heavy_path_id[now] = id1;
                head[now] = h;
                for (int nxt : e[now])
                    if (nxt != par[now] and nxt != heavy_child[now]) q.push(nxt);
            }
            id1++;
        }
    }

    void build(std::vector<int> roots = {0}) {
        int id11 = 0;
        for (auto r : roots) {
            _build_dfs(r);
            _build_bfs(r, id11++);
        }
    }

    template <typename Monoid>
    std::vector<Monoid> id6(const std::vector<Monoid> &data) const {
        assert(int(data.size()) == V);
        std::vector<Monoid> ret;
        ret.reserve(V);
        for (int i = 0; i < V; i++) ret.emplace_back(data[aligned_id_inv[i]]);
        return ret;
    }

    

    void
    for_each_vertex(int u, int v, const std::function<void(int ancestor, int descendant)> &f) const {
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            f(std::max(aligned_id[head[v]], aligned_id[u]), aligned_id[v]);
            if (head[u] == head[v]) break;
            v = par[head[v]];
        }
    }

    void for_each_vertex_noncommutative(
        int from, int to, const std::function<void(int ancestor, int descendant)> &fup,
        const std::function<void(int ancestor, int descendant)> &fdown) const {
        int u = from, v = to;
        const int lca = lowest_common_ancestor(u, v), dlca = depth[lca];
        while (u >= 0 and depth[u] > dlca) {
            const int p = (depth[head[u]] > dlca ? head[u] : lca);
            fup(aligned_id[p] + (p == lca), aligned_id[u]), u = par[p];
        }
        std::vector<std::pair<int, int>> lrs;
        while (v >= 0 and depth[v] >= dlca) {
            const int p = (depth[head[v]] >= dlca ? head[v] : lca);
            lrs.emplace_back(p, v), v = par[p];
        }
        std::reverse(lrs.begin(), lrs.end());
        for (const auto &lr : lrs) fdown(aligned_id[lr.first], aligned_id[lr.second]);
    }

    

    void for_each_edge(int u, int v, const std::function<void(int, int)> &f) const {
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            if (head[u] != head[v]) {
                f(aligned_id[head[v]], aligned_id[v]);
                v = par[head[v]];
            } else {
                if (u != v) f(aligned_id[u] + 1, aligned_id[v]);
                break;
            }
        }
    }

    

    int lowest_common_ancestor(int u, int v) const {
        assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int distance(int u, int v) const {
        assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
        return depth[u] + depth[v] - 2 * depth[lowest_common_ancestor(u, v)];
    }
};



template <class T> struct BIT {
    int n;
    std::vector<T> data;
    BIT(int len = 0) : n(len), data(len) {}
    void reset() { std::fill(data.begin(), data.end(), T(0)); }
    void add(int pos, T v) { 

        pos++;
        while (pos > 0 and pos <= n) data[pos - 1] += v, pos += pos & -pos;
    }
    T sum(int k) const { 

        T res = 0;
        while (k > 0) res += data[k - 1], k -= k & -k;
        return res;
    }

    T sum(int l, int r) const { return sum(r) - sum(l); } 


    template <class OStream> friend OStream &operator<<(OStream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.n; i++) {
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
};


const int D = 21;

int main() {
    int N;
    cin >> N;

    id3 hld(N);

    REP(_, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        hld.add_edge(a, b);
    }
    hld.build();

    vector<BIT<int>> bits(D, BIT<int>(N + 1));

    int M;
    cin >> M;

    vector pointwise(D, vector<int>(N));

    auto getter = [&](int v) -> int {
        int ret = 0;
        for (int d = 0; d < D and v >= 0; ++d, v = hld.par.at(v)) {
            ret += bits.at(d).sum(0, hld.aligned_id.at(v) + 1) + pointwise.at(d).at(v);
        }
        return ret;
    };

    while (M--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int v;
            cin >> v;
            --v;
            cout << getter(v) << '\n';
        } else {
            int u, v, k, d;
            cin >> u >> v >> k >> d;
            --u, --v;

            hld.for_each_vertex(u, v, [&](int l, int r) { bits.at(d).add(l, k), bits.at(d).add(r + 1, -k); });

            const int l = hld.lowest_common_ancestor(u, v);

            if (d) {
                pointwise.at(d - 1).at(l) += k;
            }

            if (l == 0) {
                REP(e, d - 1) pointwise.at(e).at(0) += k;
            } else {
                for (int cur = hld.par.at(l), dep = d - 1; dep >= 0 and cur >= 0; --dep, cur = hld.par.at(cur)) {
                    if (cur == 0) {
                        REP(e, dep + 1) pointwise.at(e).at(0) += k;
                    } else {
                        pointwise.at(dep).at(cur) += k;
                        if (dep) pointwise.at(dep - 1).at(cur) += k;
                    }
                }
            }
        }
    }
}
