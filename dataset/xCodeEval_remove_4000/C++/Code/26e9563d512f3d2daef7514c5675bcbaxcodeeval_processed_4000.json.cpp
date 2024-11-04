


using namespace std;
template<typename T>
class graph {
public:
    struct edge {
        int from;
        int to;
        T cost;
    };
    vector<edge> edges;
    vector<vector<int>> l;
    int n;
    graph(int _n) : n(_n) { l.resize(n); }
    virtual int add(int from, int to, T cost) = 0;
};

template<typename T>
class undigraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::l;
    using graph<T>::n;
    undigraph(int _n) : graph<T>(_n) {}
    int add(int from, int to, T cost = 1) {
        int id = (int) edges.size();
        l[from].push_back(id);
        l[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
};

template<typename T>
class digraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::l;
    using graph<T>::n;
    digraph(int _n) : graph<T>(_n) {}
    int add(int from, int to, T cost = 1) {
        int id = (int) edges.size();
        l[from].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
    digraph<T> reverse() const {
        digraph<T> rev(n);
        for (auto &e : edges) {
            rev.add(e.to, e.from, e.cost);
        }
        return rev;
    }
};

template <typename T>
class tree : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::l;
    using graph<T>::n;

    tree(int _n) : graph<T>(_n) {
    }

    int add(int from, int to, T cost = 1) {
        int id = (int) edges.size();
        l[from].push_back(id);
        l[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
};

template <typename T>
class dfs_tree : public tree<T> {
public:
    using tree<T>::edges;
    using tree<T>::l;
    using tree<T>::n;

    vector<int> pv;
    vector<int> pe;
    vector<int> order;
    vector<int> pos;
    vector<int> end;
    vector<int> sz;
    vector<int> root;
    vector<int> depth;
    vector<T> dist;

    dfs_tree(int _n) : tree<T>(_n) {
    }

    void init() {
        pv = vector<int>(n, -1);
        pe = vector<int>(n, -1);
        order.clear();
        pos = vector<int>(n, -1);
        end = vector<int>(n, -1);
        sz = vector<int>(n, 0);
        root = vector<int>(n, -1);
        depth = vector<int>(n, -1);
        dist = vector<T>(n);
    }

    void clear() {
        pv.clear();
        pe.clear();
        order.clear();
        pos.clear();
        end.clear();
        sz.clear();
        root.clear();
        depth.clear();
        dist.clear();
    }

private:
    void do_dfs(int v) {
        pos[v] = (int) order.size();
        order.push_back(v);
        sz[v] = 1;
        for (int id : l[v]) {
            if (id == pe[v]) {
                continue;
            }
            auto &e = edges[id];
            int to = e.from ^ e.to ^ v;
            depth[to] = depth[v] + 1;
            dist[to] = dist[v] + e.cost;
            pv[to] = v;
            pe[to] = id;
            root[to] = (root[v] != -1 ? root[v] : to);
            do_dfs(to);
            sz[v] += sz[to];
        }
        end[v] = (int) order.size() - 1;
    }

    void do_dfs_from(int v) {
        depth[v] = 0;
        dist[v] = T{};
        root[v] = v;
        pv[v] = pe[v] = -1;
        do_dfs(v);
    }

public:
    void dfs(int v, bool clear_order = true) {
        if (pv.empty()) {
            init();
        } else {
            if (clear_order) {
                order.clear();
            }
        }
        do_dfs_from(v);
    }

    void dfs_all() {
        init();
        for (int v = 0; v < n; v++) {
            if (depth[v] == -1) {
                do_dfs_from(v);
            }
        }
        assert((int) order.size() == n);
    }
};

template <typename T>
class id2 : public dfs_tree<T> {
public:
    using dfs_tree<T>::edges;
    using dfs_tree<T>::l;
    using dfs_tree<T>::n;
    using dfs_tree<T>::pv;
    using dfs_tree<T>::pos;
    using dfs_tree<T>::end;
    using dfs_tree<T>::depth;

    int h;
    vector<vector<int>> pr;

    id2(int _n) : dfs_tree<T>(_n) {
    }

    inline void build_lca() {
        assert(!pv.empty());
        int max_depth = 0;
        for (int i = 0; i < n; i++) {
            max_depth = max(max_depth, depth[i]);
        }
        h = 1;
        while ((1 << h) <= max_depth) {
            h++;
        }
        pr.resize(n);
        for (int i = 0; i < n; i++) {
            pr[i].resize(h);
            pr[i][0] = pv[i];
        }
        for (int j = 1; j < h; j++) {
            for (int i = 0; i < n; i++) {
                pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
            }
        }
    }

    inline bool anc(int x, int y) {
        return (pos[x] <= pos[y] && end[y] <= end[x]);
    }

    inline int go_up(int x, int up) {
        assert(!pr.empty());
        up = min(up, (1 << h) - 1);
        for (int j = h - 1; j >= 0; j--) {
            if (up & (1 << j)) {
                x = pr[x][j];
                if (x == -1) {
                    break;
                }
            }
        }
        return x;
    }

    inline int lca(int x, int y) {
        assert(!pr.empty());
        if (anc(x, y)) {
            return x;
        }
        if (anc(y, x)) {
            return y;
        }
        for (int j = h - 1; j >= 0; j--) {
            if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
                x = pr[x][j];
            }
        }
        return pr[x][0];
    }
};

template <typename T>
class id0 : public undigraph<T> {
public:
    using undigraph<T>::edges;
    using undigraph<T>::l;
    using undigraph<T>::n;

    vector<int> pv;
    vector<int> pe;
    vector<int> order;
    vector<int> pos;
    vector<int> end;
    vector<int> sz;
    vector<int> root;
    vector<int> depth;
    vector<int> min_depth;
    vector<T> dist;
    vector<int> was;
    int attempt;

    id0(int _n) : undigraph<T>(_n) {
    }

    void init() {
        pv = vector<int>(n, -1);
        pe = vector<int>(n, -1);
        order.clear();
        pos = vector<int>(n, -1);
        end = vector<int>(n, -1);
        sz = vector<int>(n, 0);
        root = vector<int>(n, -1);
        depth = vector<int>(n, -1);
        min_depth = vector<int>(n, -1);
        dist = vector<T>(n);
        was = vector<int>(n, -1);
        attempt = 0;
    }

    void clear() {
        pv.clear();
        pe.clear();
        order.clear();
        pos.clear();
        end.clear();
        sz.clear();
        root.clear();
        depth.clear();
        min_depth.clear();
        dist.clear();
        was.clear();
    }

private:
    void do_dfs(int v) {
        was[v] = attempt;
        pos[v] = (int) order.size();
        order.push_back(v);
        sz[v] = 1;
        min_depth[v] = depth[v];
        for (int id : l[v]) {
            if (id == pe[v]) {
                continue;
            }
            auto &e = edges[id];
            int to = e.from ^ e.to ^ v;
            if (was[to] == attempt) {
                min_depth[v] = min(min_depth[v], depth[to]);
                continue;
            }
            depth[to] = depth[v] + 1;
            dist[to] = dist[v] + e.cost;
            pv[to] = v;
            pe[to] = id;
            root[to] = (root[v] != -1 ? root[v] : to);
            do_dfs(to);
            sz[v] += sz[to];
            min_depth[v] = min(min_depth[v], min_depth[to]);
        }
        end[v] = (int) order.size() - 1;
    }

    void do_dfs_from(int v) {
        ++attempt;
        depth[v] = 0;
        dist[v] = T{};
        root[v] = v;
        pv[v] = pe[v] = -1;
        do_dfs(v);
    }

public:
    void dfs(int v, bool clear_order = true) {
        if (pv.empty()) {
            init();
        } else {
            if (clear_order) {
                order.clear();
            }
        }
        do_dfs_from(v);
    }

    void dfs_all() {
        init();
        for (int v = 0; v < n; v++) {
            if (depth[v] == -1) {
                do_dfs_from(v);
            }
        }
        assert((int) order.size() == n);
    }
};

template <typename T>
vector<int> id1(id0<T> &g, int &cnt) {
    g.dfs_all();
    vector<int> vertex_comp(g.n);
    cnt = 0;
    for (int i : g.order) {
        if (g.pv[i] == -1 || g.min_depth[i] == g.depth[i]) {
            vertex_comp[i] = cnt++;
        } else {
            vertex_comp[i] = vertex_comp[g.pv[i]];
        }
    }
    return vertex_comp;
}

template <typename T>
vector<vector<int>> find_cycles(const graph<T> &g, int bound_cnt = 1 << 30, int bound_size = 1 << 30) {
    vector<int> was(g.n, -1);
    vector<int> st;
    vector<vector<int>> cycles;
    int total_size = 0;
    function<void(int, int)> dfs = [&](int v, int pe) {
        if ((int) cycles.size() >= bound_cnt || total_size >= bound_size) {
            return;
        }
        was[v] = (int) st.size();
        for (int id : g.g[v]) {
            if (id == pe) {
                continue;
            }
            auto &e = g.edges[id];
            int to = e.from ^ e.to ^ v;
            if (was[to] >= 0) {
                vector<int> cycle(1, id);
                for (int j = was[to]; j < (int) st.size(); j++) {
                    cycle.push_back(st[j]);
                }
                cycles.push_back(cycle);
                total_size += (int) cycle.size();
                if ((int) cycles.size() >= bound_cnt || total_size >= bound_size) {
                    return;
                }
                continue;
            }
            if (was[to] == -1) {
                st.push_back(id);
                dfs(to, id);
                st.pop_back();
            }
        }
        was[v] = -2;
    };
    for (int i = 0; i < g.n; i++) {
        if (was[i] == -1) {
            dfs(i, -1);
        }
    }
    return cycles;
    

    

    

    

}

template <typename T>
vector<int> id3(const graph<T> &g, const vector<int> &edge_cycle) {
    int sz = (int) edge_cycle.size();
    vector<int> vertex_cycle;
    if (sz <= 2) {
        vertex_cycle.push_back(g.edges[edge_cycle[0]].from);
        if (sz == 2) {
            vertex_cycle.push_back(g.edges[edge_cycle[0]].to);
        }
    } else {
        for (int i = 0; i < sz; i++) {
            int j = (i + 1) % sz;
            auto &e = g.edges[edge_cycle[i]];
            auto &other = g.edges[edge_cycle[j]];
            if (other.from == e.from || other.to == e.from) {
                vertex_cycle.push_back(e.to);
            } else {
                vertex_cycle.push_back(e.from);
            }
        }
    }
    return vertex_cycle;
    

}


class CUncleBogdanAndCountryHappiness {
public:
    static constexpr int kStressCount = 0;
    static void generateTest(ostream& test) {}
	void solve(istream& cin, ostream& cout) {
        int n,m;
        cin>>n>>m;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin>>p[i];
        }
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin>>h[i];
        }
        dfs_tree<int> tree(n);


        for (int i = 0; i < n - 1; i++) {
            int a,b;
            cin>>a>>b;
            a--;b--;
            tree.add(a,b);


        }
        tree.dfs(0);


















        vector<int> dist(n,0);




















        function<void(int)> dd=[&](int po){
            int s=p[po];
            for (auto i : tree.l[po]) {
                int to=tree.edges[i].to^tree.edges[i].from^po;
                if (tree.depth[po]>tree.depth[to]) continue;
                dd(to);
                s+=dist[to];
            }
            dist[po]=s;
        };
        dd(0);










        vector<pair<int,int>> hs(n);
        for (int i = 0; i < n; i++) {
            if ((dist[i]+h[i])%2) {
                cout<<"NO"<<"\n";
                return;
            }
            int a=(dist[i]+h[i])/2;
            int b=(dist[i]-h[i])/2;
            if (a<0 || b<0 ){
                cout<<"NO"<<"\n";
                return;
            }
            hs[i] = make_pair(a, b);
        }








        for (int i = 0; i < n; i++) {
            int s=0;


            for (auto j : tree.l[i]) {
                int to=tree.edges[j].to^tree.edges[j].from^i;
                if (tree.depth[i]>tree.depth[to]) continue;




                s+=hs[to].second;


            }
            if (hs[i].second>s+p[i]){
                cout<<"NO"<<"\n";
                return;
            }
        }












        cout<<"YES"<<"\n";
	}
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    istream &in(cin);
    ostream &out(cout);
    out << fixed;
    out.precision(20);
    CUncleBogdanAndCountryHappiness solver;
    int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

}
