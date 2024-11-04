#line 2 "header.hpp"





#ifndef HEADER_H
#define HEADER_H



using namespace std;
#include <bits/stdc++.h>



const long long INF = 1e18;
template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }
template <class T, class U> inline void chmin(T &a, const U &b) { if ((a) > (b)) (a) = (b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }

#define cdiv(a, b) (((a) + (b)-1) / (b))
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef long double ld;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif

#endif 


#line 2 "combined.cpp"
template<class T=ll> using vec = vector<T>;
struct Fast { Fast() { std::cin.tie(0); ios::sync_with_stdio(false); } } fast;



template <typename X> struct SegmentTree {  

    private:
        using F = function<X(X, X)>;
        using index = int;
        int n;  

        int N;  

        vector<X> node;
        F merge;
        X identity;

    public:
        SegmentTree() {}
        SegmentTree(vector<X> a, F f, X id) : merge(f), identity(id) {
            n = a.size();
            N = 1;
            while (N < n) N *= 2;
            node.resize(2 * N - 1, identity);
            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];
            for (int i = N - 2; i >= 0; i--)
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
        }
        SegmentTree(int sz, F f, X id) : SegmentTree(vector<X>(sz, id), f, id) {}

        X& operator[](index i) { return node[i + N - 1]; }

        void set(index i, X val) {
            i += (N - 1);
            node[i] = val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        void add(index i, X val) {
            i += (N - 1);
            node[i] += val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        

        X query(index a, index b, int k = 0, index l = 0, index r = -1) {
            if (r < 0) r = N;
            if (r <= a || b <= l) return identity;
            if (a <= l && r <= b) return node[k];

            X vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            X vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }

        index find_most_left(index l, const function<bool(X)>& is_ok){
            

            

            

            

            index res = _find_most_left(l, is_ok, 0, 0, N, identity).first;
            assert(l <= res);
            return res;
        }
        pair<index, X> _find_most_left(index a, const function<bool(X)>& is_ok, int k, index l, index r, X left_value){
            

            

            

            

            


            if (r <= a) return {n, identity};  

            else if (a <= l && !is_ok(merge(left_value, node[k]))) return {n, merge(left_value, node[k])};
            else if (k >= N-1) return {k - (N-1), merge(left_value, node[k])};
            else{
                auto [vl, xl] = _find_most_left(a, is_ok, 2 * k + 1, l, (l + r) / 2, left_value);
                if (vl != n) return {vl, xl};
                auto [vr, xr] = _find_most_left(a, is_ok, 2 * k + 2, (l + r) / 2, r, xl);
                return {vr, xr};
            }
        }

        index find_most_right(index r, const function<bool(X)>& is_ok){
            

            

            

            

            index res = _find_most_right(r+1, is_ok, 0, 0, N, identity).first;
            assert(res <= r);
            return res;
        }
        pair<index, X> _find_most_right(index b, const function<bool(X)>& is_ok, int k, index l, index r, X right_value){
            if (b <= l) return {-1, identity};  

            else if (r <= b && !is_ok(merge(node[k], right_value))) return {-1, merge(node[k], right_value)};
            else if (k >= N-1) return {k - (N-1), merge(node[k], right_value)};
            else{
                auto [vr, xr] = _find_most_right(b, is_ok, 2 * k + 2, (l + r) / 2, r, right_value);
                if (vr != -1) return {vr, xr};
                auto [vl, xl] = _find_most_right(b, is_ok, 2 * k + 1, l, (l + r) / 2, xr);
                return {vl, xl};
            }
        }

#if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream& os, SegmentTree<X>& sg) {  

            os << "[";
            for (int i = 0; i < sg.n; i++) {
                os << sg[i] << (i == sg.n - 1 ? "]\n" : ", ");
            }
            return os;
        }
#endif
};




































template<class Cost=ll>
struct Edge {
    int from, to;
    Cost cost;
    int idx;
    Edge(){};
    Edge(int from, int to, Cost cost, int idx)
        : from(from), to(to), cost(cost), idx(idx) {}

    friend ostream& operator<<(ostream& os, const Edge& e) {
        

        os << "(" << e.from << "," << e.to << ")";
        return os;
    }
};





struct UnionFind {
    vector<int> par;   

    int gcount;         


    UnionFind() {}
    UnionFind(int _n) : par(_n, -1), gcount(_n) {}
    bool merge(int x, int y) { 
        x = root(x);
        y = root(y);
        if (x != y) {
            if (par[y] < par[x]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
            gcount--;
        }
        return x != y;
    } 
    int root(int x) {
        if (is_root(x)){
            return x;
        }
        else{
            return par[x] = root(par[x]);  

            

        }
    }
    bool is_root(int x) { return par[x] < 0; }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }

#if defined(PCM) || defined(LOCAL)  

    friend ostream& operator<<(ostream& os, UnionFind& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i); }
        os << endl;
        each(g, group) { os << g << endl; }
        return os;
    }
#endif  

};





template<class Cost=ll>
struct tree { 
    int n;
    int root;
    vector<int> par;   

    vector<Cost> cost;  

    vector<int> dfstrv;  

    vector<int> ord;    

    vector<int> end;    

    vector<int> psize;  

    

    

    vector<int> depth;   

    vector<Cost> ldepth;  

    vector<vector<Edge<Cost>>> adj_list;       

    auto operator[](int pos) const { return adj_list[pos]; }
    vector<vector<int>> children;
    vector<int> euler_tour;
    vector<int> et_fpos;    

    SegmentTree<int> _seg;  

    vector<int> head_of_comp;
    int _counter = 0;

    tree(){};
    tree(int n)
        : n(n),
        par(n),
        cost(n),
        ord(n),
        end(n),
        psize(n),
        depth(n),
        ldepth(n),
        adj_list(n),
        children(n),
        et_fpos(n),
        head_of_comp(n){};
    void add_edge(int u, int v, Cost cost, int idx=-1) { 
        adj_list[u].emplace_back(u, v, cost, idx);
        adj_list[v].emplace_back(v, u, cost, idx);
    }                             
    void add_edge(int u, int v) { 
        adj_list[u].emplace_back(u, v, 1, -1);
        adj_list[v].emplace_back(v, u, 1, -1);
    }                      
    void build(int _root) { 
        root = _root;
        _counter = 0;
        par[root] = -1;
        

        _dfs_psize(root, -1);
        _dfs_tree(root, -1, root);
        _dfs_et(root);
        vector<int> ini(2 * n - 1);
        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(
                ini, [](auto a, auto b) { return min(a, b); }, numeric_limits<int>().max());
    }                                
    int _dfs_psize(int u, int pre) { 
        psize[u] = 1;
        each(edge, adj_list[u]) {
            if (edge.to == pre) continue;
            psize[u] += _dfs_psize(edge.to, u);
        }
        return psize[u];
    }                                               
    void _dfs_tree(int u, int pre, int head_node) { 
        dfstrv.pb(u);
        ord[u] = _counter;
        if (pre != -1) {
            depth[u] = depth[pre] + 1;
            ldepth[u] = ldepth[pre] + cost[u];
        }

        _counter++;
        {
            

            int max_psize = 0;
            int most_heavy_i = -1;
            rep(i, sz(adj_list[u])) {
                if (adj_list[u][i].to == pre) continue;
                if (psize[adj_list[u][i].to] > max_psize) {
                    most_heavy_i = i;
                    max_psize = psize[adj_list[u][i].to];
                }
            }
            if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i], adj_list[u][0]);
        }

        head_of_comp[u] = head_node;
        rep(i, sz(adj_list[u])) {
            int v = adj_list[u][i].to;
            if (v == pre) continue;

            children[u].pb(v);
            par[v] = u;
            cost[v] = adj_list[u][i].cost;

            if (i == 0)
                _dfs_tree(v, u, head_node);  

            else
                _dfs_tree(v, u, v);  

        }
        end[u] = _counter;
    }                     
    void _dfs_et(int u) { 
        et_fpos[u] = euler_tour.size();
        euler_tour.pb(u);
        each(v, children[u]) {
            _dfs_et(v);
            euler_tour.pb(u);
        }
    }                       
    int lca(int u, int v) { 
        if (u == v) return u;
        if (et_fpos[u] > et_fpos[v]) swap(u, v);
        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
    }                        
    int dist(int u, int v) { 
        int p = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[p];
    }                          
    Cost ldist(int u, int v) {  

        int p = lca(u, v);
        return ldepth[u] + ldepth[v] - 2 * ldepth[p];
    }                           
    pair<int, int> diameter() { 
        int u, v;
        Cost max_len = *max_element(all(ldepth));
        rep(i, n) {
            if (ldepth[i] == max_len) {
                u = i;
                break;
            }
        }
        Cost md = -1;
        rep(i, n) {
            Cost d = ldist(u, i);
            if (d > md) {
                v = i;
                md = d;
            }
        }
        return mp(u, v);
    }                                                
    vector<pair<int, int>> hld_path(int u, int v, bool for_edge=true) {  

        

        vector<pair<int, int>> res;
        while (head_of_comp[u] != head_of_comp[v]) {
            if (depth[head_of_comp[u]] < depth[head_of_comp[v]]) {
                res.push_back({ord[head_of_comp[v]], ord[v]});
                v = par[head_of_comp[v]];
            } else {
                res.push_back({ord[head_of_comp[u]], ord[u]});
                u = par[head_of_comp[u]];
            }
        }
        res.push_back({min(ord[u], ord[v]) + (for_edge?1:0), max(ord[u], ord[v])});
        return res;
    }                              

#if defined(PCM) || defined(LOCAL) 
    friend ostream& operator<<(ostream& os, const tree& tr) {
        os << endl;
        os << "par:         " << tr.par << endl;
        os << "cost:        " << tr.cost << endl;
        os << "dfstrv:      " << tr.dfstrv << endl;
        os << "ord:         " << tr.ord << endl;
        os << "end:         " << tr.end << endl;
        os << "depth:       " << tr.depth << endl;
        os << "children:    " << tr.children << endl;
        os << "euler_tour:  " << tr.euler_tour << endl;
        os << "et_fpos:     " << tr.et_fpos << endl;
        os << "head_of_comp:" << tr.head_of_comp << endl;
        return os;
    }
#endif 
}; 





template<class Cost=ll>
struct Graph {
    using Pos = int;  


    int n;  

    vector<vector<Edge<Cost>>> adj_list;
    auto operator[](Pos pos) const { return adj_list[pos]; }
    vector<Edge<Cost>> edges;
    tree<Cost> tr;
    Pos root;
    vector<int> _used_in_dfs;
    vector<int> lowlink;
    Cost zerocost;
    Cost infcost;

    Graph() {}
    Graph(int _n) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n), zerocost(0LL), infcost(INF) { }
    Graph(int _n, Cost zc, Cost ic) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n), zerocost(zc), infcost(ic) { }

    void add_edge(Pos from, Pos to, Cost cost, int idx=-1) {
        adj_list[from].emplace_back(from, to, cost, idx);
        edges.emplace_back(from, to, cost, idx);
    }
    void add_edge(Pos from, Pos to) {  

        adj_list[from].emplace_back(from, to, 1, -1);
        edges.emplace_back(from, to, 1, -1);
    }

    void build_tree(Pos _root) {
        root = _root;
        _dfs_tree(root);
        tr.build(root);
        _make_lowlink();
    }

    vector<int> make_bipartite() {
        UnionFind buf(2 * n);
        rep(u, n) {
            each(e, adj_list[u]) {
                buf.merge(u, e.to + n);
                buf.merge(e.to, u + n);
            }
        }

        vector<int> res(n, -1);
        rep(u, n) {
            if (buf.same(u, u + n)) return res;
        }
        rep(u, n) {
            if (buf.same(0, u)) res[u] = 0;
            else res[u] = 1;
        }
        return res;
    }

    void _dfs_tree(Pos u) {
        _used_in_dfs[u] = 1;
        each(e, adj_list[u]) {
            if (_used_in_dfs[e.to]) continue;
            tr.add_edge(u, e.to, e.cost);
            _dfs_tree(e.to);
        }
    }

    void _make_lowlink() {
        lowlink = vector<Pos>(n, numeric_limits<Pos>().max());
        r_rep(i, n) {
            Pos u = tr.dfstrv[i];
            chmin(lowlink[u], tr.ord[u]);

            each(e, adj_list[u]) {
                if (e.to == tr.par[u])
                    continue;
                else if (tr.ord[e.to] < tr.ord[u]) {
                    chmin(lowlink[u], tr.ord[e.to]);
                } else {
                    chmin(lowlink[u], lowlink[e.to]);
                }
            }
        }
    }

    vector<Pos> get_articulation_points() {
        if (sz(lowlink) == 0) throw("make_lowlik() beforehand");

        vector<Pos> res;
        if (sz(tr.children[root]) > 1) {
            res.push_back(root);
        }
        rep(u, 0, n) {
            if (u == root) continue;
            bool is_kan = false;
            each(v, tr.children[u]) {
                if (tr.ord[u] <= lowlink[v]) {
                    is_kan = true;
                }
            }
            if (is_kan) res.push_back(u);
        }
        return res;
    }

    vector<Edge<Cost>> get_bridges() {
        if (sz(lowlink) == 0) throw("make_lowlik() beforehand");
        vector<Edge<Cost>> res;
        each(edge, edges){
            if (tr.ord[edge.from] < lowlink[edge.to]) res.push_back(edge);
        }
        return res;
    }

    vector<Edge<Cost>> kruskal_tree() {
        

        vector<Edge<Cost>> res;
        sort(all(edges), [](auto l, auto r) { return l.cost < r.cost; });
        UnionFind uf(n);

        Cost total_cost = zerocost;
        each(e, edges) {
            if (uf.same(e.from, e.to)) continue;
            uf.merge(e.from, e.to);
            total_cost = total_cost + e.cost;
            res.pb(e);
        }
        


        return res;
    }

    vector<Cost> dijkstra(vector<Pos> starts) {  

        vector<Cost> dist(n, infcost);           

        PQ<pair<Cost, Pos>> pq;
        each(start, starts) {
            dist[start] = zerocost;
            pq.push(make_pair(zerocost, start));
        }
        while (!pq.empty()) {
            auto cp = pq.top();
            pq.pop();
            auto [cost, u] = cp;
            for (const auto& edge : adj_list[u]) {
                Cost new_cost = cost + edge.cost;  

                if (new_cost < dist[edge.to]) {
                    dist[edge.to] = new_cost;
                    pq.push(make_pair(new_cost, edge.to));
                }
            }
        }
        return dist;
    };

    vector<Cost> dijkstra(Pos start) {  

        vector<Pos> starts = {start};
        return dijkstra(starts);
    };
};



int solve() {
    ll m,n;cin>>m>>n;
    vector<ll> a(m);
    rep(i, m) { cin>>a[i]; }
    vector<ll> b(n);
    rep(j, n) { cin>>b[j]; }

    Graph g(n+m);
    ll sum = 0;
    rep(i, m){
        int s;cin>>s;
        rep(j, s){
            int v;cin>>v;
            v--;
            g.add_edge(i, v+m, -(a[i]+b[v]));
            g.add_edge(v+m, i, -(a[i]+b[v]));
            sum += a[i] + b[v];
        }
    }
    auto edges = g.kruskal_tree();
    dump(sz(edges));
    dump(edges);

    ll dec = 0;
    for (auto e : edges){
        dec += e.cost;
    }
    cout << sum + dec << endl;

    return 0; 
}


int main(){
    solve();
    check_input();
    return 0;
}
