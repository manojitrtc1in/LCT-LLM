












int bsr(unsigned int x) { return 31 - __builtin_clz(x); }
int bsr(unsigned long long x) { return 63 - __builtin_clzll(x); }

template <class D> struct id2 {
    using C = typename std::make_unsigned<decltype(D().key)>::type;
    static int bsr1(C x) { return (x == 0) ? 0 : bsr(x) + 1; }
    size_t sz = 0, cnt = 0;
    C last = 0;
    std::vector<std::vector<D>> v =
        std::vector<std::vector<D>>(sizeof(C) * 8 + 1);
    id2() {}
    void clear() {
        sz = 0;
        cnt = 0;
        last = 0;
        for (auto& x: v) x.clear();
    }
    void push(D x) {
        assert(decltype(x.key)(last) <= x.key);
        sz++;
        v[bsr1(x.key ^ last)].push_back(x);
    }
    void pull() {
        if (cnt < v[0].size()) return;
        int i = 1;
        while (v[i].empty()) i++;
        last = min_element(v[i].begin(), v[i].end(), [&](D l, D r) {
                   return l.key < r.key;
               })->key;
        for (D x : v[i]) {
            v[bsr1(x.key ^ last)].push_back(x);
        }
        v[i].clear();
    }
    D top() {
        pull();
        return v[0][cnt];
    }
    void pop() {
        pull();
        sz--;
        cnt++;
    }
    size_t size() const { return sz; }
    bool empty() const { return sz == 0; }
};
















namespace atcoder {

namespace internal {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr() {}
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
}  


template <class Cap, class Cost> struct id0 {
  public:
    id0() {}
    id0(int n) : _n(n), deg(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(pos.size());
        int from_id = deg[from];
        int to_id = deg[to];
        if (from == to) to_id++;
        pos.push_back({from, from_id});
        deg[from]++;
        deg[to]++;
        _edges.push_back({from, _edge{to, to_id, cap, cost}});
        _edges.push_back({to, _edge{from, from_id, 0, -cost}});
        return m;
    }

    int add_multi_edge_cost0(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        int from_id = deg[from];
        int to_id = deg[to];
        if (from == to) to_id++;
        pos.push_back({from, from_id});
        deg[from]++;
        deg[to]++;
        _edges.push_back({from, _edge{to, to_id, cap, 0}});
        _edges.push_back({to, _edge{from, from_id, cap, 0}});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g.elist[g.start[pos[i].first] + pos[i].second];
        auto _re = g.elist[g.start[_e.to] + _e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
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
        g = internal::csr<_edge>(_n, _edges);
        

        

        

        std::vector<Cost> dual(_n, 0), dist(_n);
        std::vector<int> pv(_n), pe(_n);
        std::vector<bool> vis(_n);
        

        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        id2<Q> que;
        auto dual_ref = [&]() {
            std::fill(dist.begin(), dist.end(),
                      std::numeric_limits<Cost>::max());
            std::fill(pv.begin(), pv.end(), -1);
            std::fill(pe.begin(), pe.end(), -1);
            std::fill(vis.begin(), vis.end(), false);
            

            que.clear();
            

            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty()) {
                int v = que.top().to;
                que.pop();
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                

                

                

                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto e = g.elist[i];
                    if (vis[e.to] || !e.cap) continue;
                    

                    

                    Cost cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost) {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i - g.start[v];
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                

                

                

                

                

                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, id1 = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g.elist[g.start[pv[v]] + pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g.elist[g.start[pv[v]] + pe[v]];
                e.cap -= c;
                g.elist[g.start[v] + e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (id1 == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            id1 = d;
            if (d >= 1'000'000'000) break;
        }
        return result;
    }

  private:
    int _n;

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<int, int>> pos;
    std::vector<int> deg;
    // std::vector<std::vector<_edge>> g;

    std::vector<std::pair<int, _edge>> _edges;
    internal::csr<_edge> g;
};

}  // namespace atcoder

using namespace atcoder;

























using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;



struct Scanner {
    int fd = -1;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += ::read(fd, line + ed, (1 << 15) - ed);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) {
            bool sep = false;
            for (size_t i = st; i < ed; i++) {
                if (isspace(line[i])) {
                    sep = true;
                    break;
                }
            }
            if (!sep) reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] & 0xf);
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    int id3() { return 0; }
    template <class H, class... T> int id3(H& h, T&... t) {
        bool f = read_single(h);
        if (!f) return 0;
        return 1 + id3(t...);
    }
    Scanner(FILE* fp) : fd(fileno(fp)) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char(0x30 | (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(__int128 val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char(0x30 | (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }

    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
    int n;
    sc.read(n);
    

    VV<ll> g(n, V<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sc.read(g[i][j]);
            


            
        }
    }

    

    

    id0<int, ll> mg(n * n + 2);
    int sv = n * n, tv = sv + 1;
    auto id = [&](int r, int c) { return r * n + c; };
    const ll INF = TEN(9);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                mg.add_edge(sv, id(i, j), 1, g[i][j]);
                mg.add_edge(id(i, j), tv, 1, INF - g[i][j]);
                

            }

            if (i + 1 < n && (j != 0 && j != n - 1) && g[i][j] != -1 &&
                g[i + 1][j] != -1) {
                

                

                 mg.add_multi_edge_cost0(id(i, j), id(i + 1, j), 1);
            }
            if (j + 1 < n && (i != 0 && i != n - 1) && g[i][j] != -1 &&
                g[i][j + 1] != -1) {
                

                

                mg.add_multi_edge_cost0(id(i, j), id(i, j + 1), 1);
            }
        }
    }

    


    

    auto sl = mg.slope(sv, tv);
    ll ans = 0;
    for (auto p : sl) {
        ans = max(ans, INF * p.first - p.second);
    }
    for (int i = 0; i < n - 1; i++) {
        ans += abs(g[0][i] - g[0][i + 1]);
        ans += abs(g[n - 1][i] - g[n - 1][i + 1]);
        ans += abs(g[i][0] - g[i + 1][0]);
        ans += abs(g[i][n - 1] - g[i + 1][n - 1]);
    }
    pr.writeln(ans);
    return 0;
}