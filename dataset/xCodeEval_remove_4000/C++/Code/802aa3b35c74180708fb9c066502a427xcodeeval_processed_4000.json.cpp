

using namespace std;




typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
std::ostream& operator << (std::ostream& os, const vector<T>& a) {
    for (const T& x : a) {
        os << x << ' ';
    }
    return os;
}


const int INF = (int)2e9 + 9;


const int MAX_N = (int)3e5 + 5;
const int MAX_LOG = 19;

namespace Fast {
    template <int N, int LOG>
    struct Jumper {
        int depth[N];
        int jump[N][LOG];
        int mx[N][LOG];
        
        Jumper(int root) {
            depth[root] = 0;
            for (int i = 0; i < LOG; ++i) {
                jump[root][i] = root;
                mx[root][i] = -1;
            }
        }
        
        void add(int v, int p, int weight) {
            

            depth[v] = depth[p] + 1;
            jump[v][0] = p;
            mx[v][0] = weight;
            for (int k = 1; k < LOG; ++k) {
                jump[v][k] = jump[jump[v][k - 1]][k - 1];
                mx[v][k] = max(mx[v][k - 1], mx[jump[v][k - 1]][k - 1]);
            }
        }
        int jump_by(int v, int d) {
            for (int k = LOG - 1; k >= 0; --k) {
                if (d >= (1 << k)) {
                    v = jump[v][k];
                    d -= 1 << k;
                }
            }
            return v;
        }
        int get_lca(int u, int v) {
            if (depth[u] < depth[v]) {
                v = jump_by(v, depth[v] - depth[u]);
            } else {
                u = jump_by(u, depth[u] - depth[v]);
            }
            if (u == v) {
                return v;
            }
            for (int k = LOG - 1; k >= 0; --k) {
                if (jump[v][k] != jump[u][k]) {
                    v = jump[v][k];
                    u = jump[u][k];
                }
            }
            return jump[v][0];
        }
        int get_maxp(int v, int p) {
            int res = -1;
            int dist = depth[v] - depth[p];
            

            for (int k = LOG - 1; k >= 0; --k) {
                if (dist >= (1 << k)) {
                    dist ^= 1 << k;
                    res = max(res, mx[v][k]);
                    v = jump[v][k];
                }
            }
            

            return res;
        }
        int get_max(int u, int v) {
            int lca = get_lca(u, v);
            return max(get_maxp(u, lca), get_maxp(v, lca));
        }
        int get_dist(int u, int v) {
            return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
        }
    };
    
    struct DSU {
        int n;
        vector<int> par;
        vector<vector<int>> elements;
     
        DSU(int _size) {
            n = _size;
            par.resize(n);
            iota(all(par), 0);
            elements.resize(n);
            for (int v = 0; v < n; ++v) {
                elements[v] = {v};
            }
        }
        int getPar(int v) {
            if (v == par[v]) {
                return v;
            }
            return par[v] = getPar(par[v]);
        }
        bool uniSet(int u, int v) {
            u = getPar(u);
            v = getPar(v);
            if (u == v) {
                return false;
            }
            if (sz(elements[u]) > sz(elements[v])) {
                swap(u, v);
            }
            for (int i : elements[u]) {
                elements[v].push_back(i);
            }
            elements[u].clear();
            par[u] = v;
            return true;
        }
    };
    
    struct SegmentTree {
        struct Node {
            int tag = -1;
            int mn = INF;
            int id0;
            int mx = -1;
            int id2;
            Node *l = nullptr, *r = nullptr;
            int tl, tr;
            
            Node() {}
            Node(int L, int R, const vector<int>& p): tl(L), tr(R) {
                if (tr - tl == 1) {
                    id0 = p[tl];
                    id2 = p[tl];
                } else {
                    int tm = (tl + tr) / 2;
                    l = new Node(tl, tm, p);
                    r = new Node(tm, tr, p);
                    id0 = min(l->id0, r->id0);
                    id2 = max(l->id2, r->id2);
                }
            }
            
            void put_tag(int _tag) {
                tag = _tag;
                if (tag == 0) {
                    mn = INF;
                    mx = -1;
                } else {
                    mn = id0;
                    mx = id2;
                }
            }
            void push() {
                if (tag != -1) {
                    if (l) l->put_tag(tag);
                    if (r) r->put_tag(tag);
                    tag = -1;
                }
            }
            void update() {
                mn = min(l->mn, r->mn);
                mx = max(l->mx, r->mx);
            }
         
            int get_min(int ql, int qr) {
                push();
                
                if (qr <= tl || tr <= ql) {
                    return 0;
                }
                if (ql <= tl && tr <= qr) {
                    return mn;
                }
         
                int ansL = l->get_min(ql, qr);
                int ansR = r->get_min(ql, qr);
                
                return min(ansL, ansR);
            }
            int get_max(int ql, int qr) {
                push();
                
                if (qr <= tl || tr <= ql) {
                    return 0;
                }
                if (ql <= tl && tr <= qr) {
                    return mx;
                }
         
                int ansL = l->get_max(ql, qr);
                int ansR = r->get_max(ql, qr);
                
                return max(ansL, ansR);
            }
            void modify(int ql, int qr, int value) {
                push();
                
                if (qr <= tl || tr <= ql) {
                    return;
                }
                if (ql <= tl && tr <= qr) {
                    put_tag(value);
                    return;
                }
         
                l->modify(ql, qr, value);
                r->modify(ql, qr, value);
                
                update();
            }
        };
        
        int n;
        Node root;
        
        SegmentTree(const vector<int>& p) {
            n = p.size();
            root = Node(0, n, p);
        }
        
        int get_min() {
            return root.get_min(0, n);
        }
        int get_max() {
            return root.get_max(0, n);
        }
        void modify(int l, int r, int value) {
            return root.modify(l, r + 1, value);
        }
    };
    
    
    vector<int> solve(int n, int q, vector<pair<int, pii>> input_edges, vector<pair<int, pii>> queries) {
        vector<vector<pii>> g(n);
        vector<pair<int, pii>> edges;
        
        for (auto [w, edge] : input_edges) {
            auto [u, v] = edge;
            --u; --v;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            edges.push_back({w, {u, v}});
        }
        
        
        Jumper<MAX_N, MAX_LOG> jumper(0);
        
        function<void(int, int)> dfs = [&](int v, int p) {
            for (auto [u, w] : g[v]) {
                if (u == p) {
                    continue;
                }
                jumper.add(u, v, w);
                dfs(u, v);
            }
        };
        
        dfs(0, -1);
        
        sort(all(edges));
        DSU tree(n);
        
        for (const auto& [w, edge] : edges) {
            const auto& [v, u] = edge;
            tree.uniSet(u, v);
        }
        
        
        vector<int> permutation = tree.elements[tree.getPar(0)];
        
        

        
        vector<int> id1(n);
        for (int i = 0; i < n; ++i) {
            id1[permutation[i]] = i;
        }
        
        

        
        SegmentTree seg_tree(id1);
        

        
        
        vector<int> answers;
        
        

        for (const auto& [type, stuff] : queries) {
            if (type == 1) {
                auto [l, r] = stuff;
                --l; --r;
                seg_tree.modify(l, r, 1);
                

                

            }
            if (type == 2) {
                auto [l, r] = stuff;
                --l; --r;
                seg_tree.modify(l, r, 0);
                

                

            }
            if (type == 3) {
                int x = stuff.first;
                --x;
                

                int mi = seg_tree.get_min();
                int ma = seg_tree.get_max();
                int max_value;
                if (ma == -1) {
                    max_value = -1;
                } else {
                    int u = permutation[mi];
                    int v = permutation[ma];
                    

                    max_value = max(jumper.get_max(u, x), jumper.get_max(v, x));
                }
                answers.push_back(max_value);
                

            }
        }
        

        
        return answers;
    }
}


namespace Stupid {
    template <int N, int LOG>
    struct Jumper {
        int depth[N];
        int jump[N][LOG];
        int mx[N][LOG];
        
        Jumper(int root) {
            depth[root] = 0;
            for (int i = 0; i < LOG; ++i) {
                jump[root][i] = root;
                mx[root][i] = -1;
            }
        }
        
        void add(int v, int p, int weight) {
            depth[v] = depth[p] + 1;
            jump[v][0] = p;
            mx[v][0] = weight;
            for (int k = 1; k < LOG; ++k) {
                jump[v][k] = jump[jump[v][k - 1]][k - 1];
                mx[v][k] = max(mx[v][k - 1], mx[jump[v][k - 1]][k - 1]);
            }
        }
        int jump_by(int v, int d) {
            for (int k = LOG - 1; k >= 0; --k) {
                if (d >= (1 << k)) {
                    v = jump[v][k];
                    d -= 1 << k;
                }
            }
            return v;
        }
        int get_lca(int u, int v) {
            if (depth[u] < depth[v]) {
                v = jump_by(v, depth[v] - depth[u]);
            } else {
                u = jump_by(u, depth[u] - depth[v]);
            }
            if (u == v) {
                return v;
            }
            for (int k = LOG - 1; k >= 0; --k) {
                if (jump[v][k] != jump[u][k]) {
                    v = jump[v][k];
                    u = jump[u][k];
                }
            }
            return jump[v][0];
        }
        int get_maxp(int v, int p) {
            int res = -1;
            int dist = depth[v] - depth[p];
            

            while (v != p) {
                res = max(res, mx[v][0]);
                v = jump[v][0];
            }
            

            return res;
        }
        int get_max(int u, int v) {
            int lca = get_lca(u, v);
            return max(get_maxp(u, lca), get_maxp(v, lca));
        }
    };
    
    struct DSU {
        int n;
        vector<int> par;
        vector<vector<int>> elements;
     
        DSU(int _size) {
            n = _size;
            par.resize(n);
            iota(all(par), 0);
            elements.resize(n);
            for (int v = 0; v < n; ++v) {
                elements[v] = {v};
            }
        }
        int getPar(int v) {
            if (v == par[v]) {
                return v;
            }
            return par[v] = getPar(par[v]);
        }
        bool uniSet(int u, int v) {
            u = getPar(u);
            v = getPar(v);
            if (u == v) {
                return false;
            }
            if (sz(elements[u]) > sz(elements[v])) {
                swap(u, v);
            }
            for (int i : elements[u]) {
                elements[v].push_back(i);
            }
            elements[u].clear();
            par[u] = v;
            return true;
        }
    };
    
    struct SegmentTree {
        int n;
        vector<int> a;
        vector<int> p;
        
        SegmentTree(const vector<int>& _p): p(_p) {
            n = p.size();
            a.resize(n);
        }
        
        int get_min() {
            int mn = INF;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 1) {
                    mn = min(mn, p[i]);
                }
            }
            return mn;
        }
        int get_max() {
            int mx = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 1) {
                    mx = max(mx, p[i]);
                }
            }
            return mx;
        }
        void modify(int l, int r, int value) {
            for (int i = l; i <= r; ++i) {
                a[i] = value;
            }
        }
    };
    
    
    vector<int> solve(int n, int q, vector<pair<int, pii>> input_edges, vector<pair<int, pii>> queries) {
        vector<vector<pii>> g(n);
        vector<pair<int, pii>> edges;
        
        for (auto [w, edge] : input_edges) {
            auto [u, v] = edge;
            --u; --v;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            edges.push_back({w, {u, v}});
        }
        
        
        
        
        Jumper<MAX_N, MAX_LOG> jumper(0);
        
        function<void(int, int)> dfs = [&](int v, int p) {
            for (auto [u, w] : g[v]) {
                if (u == p) {
                    continue;
                }
                jumper.add(u, v, w);
                dfs(u, v);
            }
        };
        
        dfs(0, -1);
        
        sort(all(edges));
        DSU tree(n);
        
        for (const auto& [w, edge] : edges) {
            const auto& [v, u] = edge;
            tree.uniSet(u, v);
        }
        
        
        vector<int> permutation = tree.elements[tree.getPar(0)];
        
        

        
        vector<int> id1(n);
        for (int i = 0; i < n; ++i) {
            id1[permutation[i]] = i;
        }
        
        

        
        SegmentTree seg_tree(id1);
        

        
        
        vector<int> answers;
        
        

        for (const auto& [type, stuff] : queries) {
            if (type == 1) {
                auto [l, r] = stuff;
                --l; --r;
                seg_tree.modify(l, r, 1);
                

                

            }
            if (type == 2) {
                auto [l, r] = stuff;
                --l; --r;
                seg_tree.modify(l, r, 0);
                

                

            }
            if (type == 3) {
                int x = stuff.first;
                --x;
                

                int mi = seg_tree.get_min();
                int ma = seg_tree.get_max();
                int max_value;
                if (ma == -1) {
                    max_value = -1;
                } else {
                    int u = permutation[mi];
                    int v = permutation[ma];
                    

                    max_value = max(jumper.get_max(u, x), jumper.get_max(v, x));
                }
                answers.push_back(max_value);
                

            }
        }
        

        
        return answers;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    

    int n, q;
    cin >> n >> q;
    vector<pair<int, pii>> edges;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    
    vector<pair<int, pii>> queries;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            queries.push_back({type, {l, r}});
        }
        if (type == 2) {
            int l, r;
            cin >> l >> r;
            queries.push_back({type, {l, r}});
        }
        if (type == 3) {
            int x;
            cin >> x;
            queries.push_back({type, {x, -1}});
        }
    }
    
    
    
    
    

    auto fast_res = Fast::solve(n, q, edges, queries);
    

    cout << fast_res << '\n';
    
    
    

    
    
    
    return 0;
}
