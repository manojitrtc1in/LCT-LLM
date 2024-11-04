










using namespace std;
















namespace _Template_ {
    
    struct cww {
        cww() {
            CIN_ONLY {
                ios::sync_with_stdio(false);
                cin.tie(0);
            }
        }
    } star;
    
    template <typename T>
    inline bool chmin(T& l, T r) {
        bool a = l > r;
        if (a) l = r;
        return a;
    }
    
    template <typename T>
    inline bool chmax(T& l, T r) {
        bool a = l < r;
        if (a) l = r;
        return a;
    }
    
    template <typename T>
    istream& operator>>(istream& is, vector<T>& v) {
        for (auto& it : v) is >> it;
        return is;
    }
    
    class reverse_range {
      private:
        struct I {
            int x;
            int operator*() { return x - 1; }
            bool operator!=(I& lhs) { return x > lhs.x; }
            void operator++() { --x; }
        };
        I i, n;

      public:
        reverse_range(int n) : i({0}), n({n}) {}
        reverse_range(int i, int n) : i({i}), n({n}) {}
        I& begin() { return n; }
        I& end() { return i; }
    };
    
    class range {
      private:
        struct I {
            int x;
            int operator*() { return x; }
            bool operator!=(I& lhs) { return x < lhs.x; }
            void operator++() { ++x; }
        };
        I i, n;

      public:
        range(int n) : i({0}), n({n}) {}
        range(int i, int n) : i({i}), n({n}) {}
        I& begin() { return i; }
        I& end() { return n; }
        reverse_range operator!() { return reverse_range(*i, *n); }
    };
    
    template <typename T>
    inline T& unused_var(T& v) {
        return v;
    }
    using LL = long long;
} 

using namespace _Template_;



namespace _Graph_ {
    
    struct Edge {
        int id, a, b;
        
        Edge(int id = 0, int a = 0, int b = 0) : id(id), a(a), b(b) {}
        
        inline int versus(const int v) const { return a ^ b ^ v; }
    };

    
    template <typename COST_TYPE>
    struct WeightedEdge {
        int id, a, b;
        COST_TYPE cost;

        WeightedEdge(int id = 0, int a = 0, int b = 0, int cost = 0)
            : id(id), a(a), b(b), cost(cost) {}
        
        inline int versus(const int v) const { return a ^ b ^ v; }
    };
    
    template <typename E = Edge>
    class Graph {
      private:
        

        vector<E> edges;
        

        vector<vector<int>> g;

      public:
        
        Graph(int id0 = 1, int id1 = -1) {
            g.reserve(id0);
            edges.reserve(max(id0, id1));
        }

        
        inline int size() { return g.size(); }

        
        inline int degree(const int v) { return g[v].size(); }

        
        inline int degree() { return edges.size(); }

        
        inline void resize(const int n) { g.resize(n); }

        
        template <typename... Ts>
        inline void add_edge(int a, int b, Ts&&... params) {
            const int id = edges.size();
            if ((int)g.size() <= max(a, b)) {
                g.resize(max(a, b) + 1);
            }
            g[a].emplace_back(id);
            g[b].emplace_back(id);
            edges.emplace_back(id, a, b, forward<Ts>(params)...);
        }

        


        
        inline void add_edge(E e) {
            e.id = edges.size();
            if ((int)g.size() <= max(e.a, e.b)) {
                g.resize(max(e.a, e.b) + 1);
            }
            g[e.a].emplace_back(e.id);
            g[e.b].emplace_back(e.id);
            edges.emplace_back(e);
        }

        
        template <typename... Ts>
        inline void add_arc(int a, int b, Ts&&... params) {
            const int id = edges.size();
            if ((int)g.size() <= max(a, b)) {
                g.resize(max(a, b) + 1);
            }
            g[a].emplace_back(id);
            edges.emplace_back(id, a, b, forward<Ts>(params)...);
        }

        
        inline void add_arc(E e) {
            e.id = edges.size();
            if ((int)g.size() <= max(e.a, e.b)) {
                g.resize(max(e.a, e.b) + 1);
            }
            g[e.a].emplace_back(e.id);
            edges.emplace_back(e);
        }

        
        inline vector<int> Ns(const int v) {
            vector<int> ns(g[v].size());
            for (int i = 0; i < degree(v); i++) {
                ns[i] = edges[g[v][i]].versus(v);
            }
            return ns;
        }

        
        inline const vector<int>& operator[](const int v) { return g[v]; }

        
        inline E& i2e(const int edge_id) { return edges[edge_id]; }
    };
} 

using namespace _Graph_;




namespace _GraphUtil_ {

    
    template <typename E, typename COST_TYPE>
    vector<COST_TYPE> dijkstra(Graph<E>& g, COST_TYPE inf, const int s = 0) {
        

        priority_queue<pair<COST_TYPE, int>> que;
        vector<COST_TYPE> d(g.size(), inf);

        

        d[s] = 0;
        que.push(make_pair((COST_TYPE)0, s));

        while (!que.empty()) {
            const int v       = que.top().second;
            const COST_TYPE c = -que.top().first;
            que.pop();
            if (d[v] < c) continue;
            for (const int eid : g[v]) {
                E& e        = g.i2e(eid);
                const int u = e.versus(v);
                if (chmin(d[u], c + e.cost)) {
                    que.push(make_pair(-(c + e.cost), u));
                }
            }
        }
        return d;
    }
} 

using namespace _GraphUtil_;




constexpr LL inf = 1e17;
constexpr int sz = 212345 * 2;
int bv[sz];
int ev[sz];
int bg[sz];
int ed[sz];
LL ct[sz];
int edge_set[sz];
int vertex_set[sz];

vector<int> B[sz];
vector<int> E[sz];
int N, M, Q;

Graph<WeightedEdge<LL>> g(sz, sz);

vector<int> id2(vector<LL> d) {
    vector<int> path;
    int v = N - 1;
    while (v != 0) {
        for (int eid : g[v]) {
            auto edge   = g.i2e(eid);
            const int u = edge.versus(v);
            if (d[u] + edge.cost == d[v]) {
                path.push_back(eid);
                edge_set[eid] = 1;
                vertex_set[v] = 1;
                vertex_set[u] = 1;
                v             = u;
                break;
            }
        }
    }
    reverse(ALL(path));
    return path;
}

auto assign_ps(vector<LL> d, int* ps) {
    vector<int> order(N);
    iota(ALL(order), 0);
    sort(ALL(order), [&](int l, int r) { return d[l] < d[r]; });
    for (const int v : order) {
        if (vertex_set[v]) {
            ps[v] = v;
        }
        else {
            for (int eid : g[v]) {
                auto e      = g.i2e(eid);
                const int u = e.versus(v);
                if (d[u] + e.cost == d[v]) {
                    ps[v] = ps[u];
                    break;
                }
            }
        }
        

    }
}

int qe[sz];
LL qc[sz];
LL ret[sz];
int main() {
    cin >> N >> M >> Q;
    for (int i : range(M)) {
        unused_var(i);
        int a, b;
        LL w;
        cin >> a >> b >> w;
        a--;
        b--;
        g.add_edge(a, b, w);
    }
    auto d    = dijkstra(g, inf, 0);
    auto r    = dijkstra(g, inf, N - 1);
    auto path = id2(d);
    assign_ps(d, bv);
    assign_ps(r, ev);
    for (int i : range(M)) {
        if (edge_set[i]) continue;
        auto e = g.i2e(i);
        int v  = e.a;
        int u  = e.b;
        if (d[bv[v]] >= d[ev[u]]) swap(v, u);
        bg[i] = bv[v];
        ed[i] = ev[u];
        
        if (d[bg[i]] < d[ed[i]]) {
            ct[i] = d[v] + r[u] + e.cost;
            B[bg[i]].push_back(i);
            E[ed[i]].push_back(i);
        }
    }
    vector<int> qo;
    for (int i : range(Q)) {
        cin >> qe[i] >> qc[i];
        qe[i]--;
        if (edge_set[qe[i]]) {
            qo.push_back(i);
        }
        else {
            auto e          = g.i2e(qe[i]);
            auto candidates = {d.back(), d[e.a] + qc[i] + r[e.b],
                               d[e.b] + qc[i] + r[e.a]};
            ret[i]          = *min_element(ALL(candidates));
        }
    }
    sort(ALL(qo), [&](int l, int r) {
        auto el = g.i2e(qe[l]);
        auto er = g.i2e(qe[r]);
        LL dl   = min(d[el.a], d[el.b]);
        LL dr   = min(d[er.a], d[er.b]);
        return dl < dr;
    });
    int itr = 0;
    set<pair<LL, int>> S;
    auto update = [&](int v) {
        for (int ej : B[v]) {
            S.insert({ct[ej], ej});
            
        }
        for (int ej : E[v]) {
            S.erase({ct[ej], ej});
            
        }
    };
    update(0);
    for (int qi : qo) {
        int ei = qe[qi];
        while (path[itr] != ei) {
            auto e = g.i2e(path[itr]);
            int v  = d[e.a] < d[e.b] ? e.a : e.b;
            int u  = e.versus(v);
            update(u);
            itr++;
        }
        {
            auto e  = g.i2e(ei);
            int v   = d[e.a] < d[e.b] ? e.a : e.b;
            int u   = e.versus(v);
            ret[qi] = min((S.size() == 0u ? inf : S.begin()->first),
                          d[v] + qc[qi] + r[u]);
        }
    }

    for (int i : range(Q)) {
        cout << ret[i] << "\n";
    }
    return 0;
}