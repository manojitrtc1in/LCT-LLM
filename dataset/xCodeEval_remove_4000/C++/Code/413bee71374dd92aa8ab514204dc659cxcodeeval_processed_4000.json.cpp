
using namespace std;






typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<string> vs;
template<typename... Args> using vecvec = vector<vector<Args...>>;
typedef vecvec<int> vvi;
typedef vecvec<ll> vvl;
template<typename T> vector<T> table(int n, T val){ return vector<T>(n, val); }
template<typename... Args> auto table(int n, Args... args){ auto val = table(args...); return vector<decltype(val)>(n, move(val)); }
template<typename... Args> using umap = unordered_map<Args...>;
template<typename... Args> using uset = unordered_set<Args...>;
typedef umap<ll,ll> umapl;








template<class T> bool mmin(T& a, const T& b) { return b<a?a=b,1:0; }
template<class T> bool mmax(T& a, const T& b) { return a<b?a=b,1:0; }
void put() {}
template<class T, class... Args> void put(T a, Args... args) { cout << a; if(sizeof...(args)) cout << ' '; put(args...); }
template<class... Args> void putn(Args... args) { put(args...); cout << endl; }
template<class... Args> void putb(Args... args) { put(args...); cout << ' '; }
template<class It> void put_each(It first, It last) { while(first!=last) { put(*first); if(++first!=last) putb(); } }
template<class It> void id1(It first, It last) { put_each(first,last); putn(); }
template<class It> void id2(It first, It last) { put_each(first,last); putb(); }
void yesno(bool c) { putn(c?"YES":"NO"); }
void yes() { yesno(true); } void no() { yesno(false); }
void imp() { putn("-1"); }
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;



struct graph {
    int n, ecnt = 0;
    vector<int> from,to;
    vector<vector<pair<int,int>>> edg;

    graph(int n) : n(n), edg(n) {}

    virtual int add(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        from.push_back(a); to.push_back(b);
        edg[a].push_back({ecnt,b});
        edg[b].push_back({ecnt,a});
        return ecnt++;
    }

    virtual const vector<pair<int,int>>& neigh(int u) const { return edg[u]; }

    virtual void reserve_edges(int m) {
        from.reserve(m);
        to.reserve(m);
    }
};




template<class G>
struct directed : public G {
    vector<vector<pair<int,int>>> out,in;

    directed(int n) : G(n), out(n), in(n) {}

    int add(int a, int b) {
        int e = G::add(a,b);
        out[a].push_back({e,b});
        in[b].push_back({e,a});
        return e;
    }

    const vector<pair<int,int>>& neigh(int u) const { return out[u]; }

    using is_directed_t = void;
};

template <typename T, typename = void> struct is_directed : std::false_type {};
template <typename T> struct is_directed<T, typename T::is_directed_t> : std::true_type {};
using dir_graph = directed<graph>;




template<class W, class G> 
struct weighted : public G {
    vector<W> w;

    weighted(int n) : G(n) {}
    weighted(const G& g) : G(g), w(g.ecnt) {}

    int add(int a, int b) { 
        return add(a,b,W{0}); 
    }

    int add(int a, int b, W ww) {
        w.push_back(ww);
        return G::add(a,b);
    }

    void reserve_edges(int m) {
        G::reserve_edges(m);
        w.reserve(m);
    }

    using weight_t = W;
};



template <typename T> using weight_t = typename T::weight_t;


template <typename T, typename = void> struct is_weighted : std::false_type {};
template <typename T> struct is_weighted<T, void_t<weight_t<T>>> : std::true_type {};



template <typename T> struct type_t { using type = T; };
template <typename T, typename W, typename = void> struct weight_t_else : type_t<W> {};
template <typename T, typename W> struct weight_t_else<T, W, void_t<weight_t<T>>> : type_t<weight_t<T>> {};
template <typename T, typename W> using weight_t_else_t = typename weight_t_else<T,W>::type;

template<class T> using wdir_graph = weighted<T,dir_graph>;
template<class T> using wgraph = weighted<T,graph>;




void readin(graph& g, int m, int offset = 1) {
    g.reserve_edges(m);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset;
        b -= offset;
        g.add(a,b);
    }
}

template<class G>
void id3(G& g, int m, int offset = 1) {
    static_assert(is_weighted<G>::value==true);
    g.reserve_edges(m);
    for(int i=0; i<m; i++) {
        int a, b; 
        weight_t<G> w = 0;
        cin >> a >> b >> w;
        a -= offset;
        b -= offset;
        g.add(a,b,w);
    }
}

void id6(graph& g, int offset = 1) {
    g.reserve_edges(g.n-1);
    for(int i=2; i<=g.n; i++) {
        int p; cin >> p;
        int a = i-offset;
        p -= offset;
        g.add(a,p);
    }
}




template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id10 {
    using node_type = S;
    using func_type = F;

    static S do_op(S lhs, S rhs) { return op(lhs,rhs); }
    static S get_e() { return e(); }

    id10() : id10(0) {}
    id10(int n) : id10(std::vector<S>(n, e())) {}
    id10(const std::vector<S>& v) : _n(int(v.size())) {
        size = 1, log = 0;
        while(size<_n) log++, size <<= 1;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
    }

    void build() {
        for (int i = size - 1; i >= 1; i--) pull(i);
    }

    void pushall() {
        for (int i = 1; i < size; i++) push(i);
    }

    S& operator[] (int p) {
        assert(0 <= p && p < _n);
        return d[p+size];
    }

    void update(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = 1; i <= log; i++) pull(p >> i);
    }

    void pushthru(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
    }

    S query(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S queryall() { return d[1]; }

    template <void (*g)(S)> void id5(int l, int r) {
        return id5(l, r, [](S x) { return g(x); });
    }
    template <class G> void id5(int l, int r, G g) {
        assert(0 <= l && l <= r && r <= _n);
        if(l==r) return;
        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        while (l < r) {
            if (l & 1) g(d[l++]);
            if (r & 1) g(d[--r]);
            l >>= 1;
            r >>= 1;
        }
    }

    void lazy_update(int p, F f) {
        assert(0 <= p && p < _n);
        pushthru(p);
        d[p+size] = mapping(f, d[p+size]);
        update(p);
    }
    void lazy_update(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) lazy_apply(l++, f);
                if (r & 1) lazy_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) pull(l >> i);
            if (((r >> i) << i) != r) pull((r - 1) >> i);
        }
    }

    

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void pull(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void lazy_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        lazy_apply(2 * k, lz[k]);
        lazy_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};




namespace maxseg {
    struct node {
        ll val;
        node() : val(0) {}
        node(ll a) : val(a) {}
    };
    struct lzadd {
        ll val;
        lzadd(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return node(max(lhs.val,rhs.val)); }
    node e() { return node(0); }
    lzadd composition(lzadd lhs, lzadd rhs) { return lzadd(lhs.val+rhs.val); }
    lzadd id() { return lzadd(0); }
    node mapping(lzadd a, node n) { return node(n.val+a.val); }
    using seg = id10<node,op,e,lzadd,mapping,composition,id>;
}



namespace minseg {
    struct node {
        ll val;
        node() : val(0) {}
        node(ll a) : val(a) {}
    };
    struct lzadd {
        ll val;
        lzadd(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return node(min(lhs.val,rhs.val)); }
    node e() { return node(infl); }
    lzadd composition(lzadd lhs, lzadd rhs) { return lzadd(lhs.val+rhs.val); }
    lzadd id() { return lzadd(0); }
    node mapping(lzadd a, node n) { return node(n.val+a.val); }
    using seg = id10<node,op,e,lzadd,mapping,composition,id>;
}



namespace sumseg {
    struct node {
        ll val;
        int range;
        node() : node(0) {};
        node(ll a) : node(a,1) {};
        node(ll a, int ran) : val(a), range(ran) {};

        node& operator+=(const node& rhs) { val+=rhs.val; range+=rhs.range; return *this; }
        node& operator-=(const node& rhs) { val-=rhs.val; range-=rhs.range; return *this; }
        node operator+() { return *this; }
        node operator-() { return node() - *this; }
        friend node operator+(const node& a,const node& b) { return node(a) += b; }
        friend node operator-(const node& a,const node& b) { return node(a) -= b; }
    };
    struct lzadd {
        ll val;
        lzadd(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return lhs + rhs; }
    node e() { return node(0,1); }
    lzadd composition(lzadd lhs, lzadd rhs) { return lzadd(lhs.val + rhs.val); }
    lzadd id() { return lzadd(0); }
    node mapping(lzadd a, node n) { return node(n.val + n.range*a.val, n.range); }
    using seg = id10<node,op,e,lzadd,mapping,composition,id>;
}



namespace sumsetseg {
    struct node {
        ll val;
        int range;
        node() : node(0) {};
        node(ll a) : node(a,1) {};
        node(ll a, int ran) : val(a), range(ran) {};
    };
    struct lzset {
        ll val;
        lzset(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return node(lhs.val + rhs.val, lhs.range+rhs.range); }
    node e() { return node(0,1); }
    lzset composition(lzset newlz, lzset oldlz) { 
        if(newlz.val==-1) return oldlz;
        return newlz; 
    }
    lzset id() { return lzset(-1); }            

    node mapping(lzset a, node n) { 
        if(a.val==-1) return n;
        return node(n.range*a.val, n.range); 
    }
    using seg = id10<node,op,e,lzset,mapping,composition,id>;
}









template<class G>
struct id7 {
    const int mxw = 20;
    int _n;
    vector<int> dep;
    vector<vector<int>> par;
    vector<int> label, max_label;
    vector<weight_t_else_t<G,int>> w;

    id7() : _n(0), dep(1,0), par(1,vector<int>(mxw,-1)), label(1), max_label(1), w(0) {}

    id7(const G& g) : _n(g.n), dep(g.n), par(g.n,vector<int>(mxw,-1)), label(g.n), max_label(g.n), w(g.n) {  

        int label_count = 0;
        function<void(int,int,int)> dfs = [&](int u, int p, int d) {
            max_label[u] = label[u] = label_count++;
            dep[u] = d;
            int pp = p;
            for(int k=0; k<mxw && pp>=0; k++) {
                par[u][k] = pp;
                pp = par[pp][k];
            }

            for(auto [e,v] : g.edg[u]) {
                if(v!=p) {
                    if constexpr (is_weighted<G>::value) w[v] = w[u] + g.w[e];
                    dfs(v,u,d+1);
                    max_label[u] = max(max_label[u],max_label[v]);
                }
            }
        };
        for(int u=0; u<g.n; u++) if(!dep[u]) dfs(u,-1,0);
    }

    

    void add_node(int p) {
        _n++;
        int u = dep.size();
        dep.push_back(dep[p]+1);
        par.push_back(vector<int>(mxw,-1));

        int pp = p;
        for(int k=0; k<mxw && pp>=0; k++) {
            par[u][k] = pp;
            pp = par[pp][k];
        }
    }

    bool is_ancestor(int hi, int lo) {
        return label[hi] <= label[lo] && label[lo] <= max_label[hi];
    }

    bool is_on_path(int a, int b, int y) {
        return (is_ancestor(y, a) || is_ancestor(y, b)) && is_ancestor(lca(a, b), y);
    }

    

    int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

    

    int dist_to_path(int a, int b, int y) {
        return (dist(y,b) + dist(y,a) - dist(a,b)) / 2;
    }

    

    int path_weight(int a, int b) { return w[a] + w[b] - 2 * w[lca(a,b)]; }

    

    int closest_index_on_path(int a, int b, int y) {
        return dist_to_path(y,b,a);;
    }
    
    vector<int> subtree_sizes_of_path(int a, int b) {
        vector<int> sub(dist(a,b)+1);
        for(int i=0; i<_n; i++) {
            int k = closest_index_on_path(a,b,i);
            sub[k]++;
        }
        return sub;
    }

    int common_node(int a, int b, int c) {
        int x = lca(a, b);
        int y = lca(b, c);
        int z = lca(c, a);
        if(dep[y]>dep[x]) x = y;
        if(dep[z]>dep[x]) x = z;
        return x;
    }

    vector<int> path_to_ancestor(int a, int anc) {
        assert(is_ancestor(anc,a));
        vector<int> ans;
        while(a!=anc) ans.push_back(a), a = par[a][0];
        return ans;
    }

    

    vector<int> path(int a, int b) {
        int lc = lca(a,b);
        vector<int> ans = path_to_ancestor(a,lc), path2 = path_to_ancestor(b,lc);
        ans.push_back(lc);
        ans.insert(ans.end(),path2.rbegin(),path2.rend());
        return ans;
    }

    int kth_node_on_path(int a, int b, int k) {
        int lc = lca(a, b);
        int ldist = dep[a] - dep[lc];
        int rdist = dep[b] - dep[lc];
        assert(0 <= k && k <= ldist + rdist);

        if(k<ldist) return walkup(a, k);
        else return walkup(b, ldist + rdist - k);
    }

    int walkup(int u, int h) {
        assert(h<=dep[u]);
        int i = 0;
        while(h) {
            if(h&1) u = par[u][i];
            i++;
            h >>= 1;
        }
        return u;
    }

    int lca(int a, int b) {
        if(dep[a]<dep[b])
            swap(a,b);
        a = walkup(a,dep[a]-dep[b]);
        if(a==b) return a;

        for(int i=mxw-1; i>=0; i--) {
            if(par[a][i]!=par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
        }
        return par[a][0];
    }

    int get_child_in_direction(int hi, int lo) {
        assert(dep[hi] < dep[lo]);
        int ans = walkup(lo, dep[lo] - dep[hi] - 1);
        assert(par[ans][0]==hi);       

        return ans;
    }

    

    

    

    

    template<class F> 
    int id9(int u, F f) {
        if(!f(u)) return -1;
        for(int i=mxw-1; i>=0; i--) {
            if(par[u][i]>=0 && f(par[u][i]))
                u = par[u][i];
        }
        return u;
    }

    vector<vector<int>> levels() {
        int mx_dep = 0;
        for(int d : dep) mx_dep = max(mx_dep,d);

        vector<vector<int>> levels(mx_dep+1);
        for(int i=0; i<(int)dep.size(); i++) 
            levels[dep[i]].push_back(i);
        return levels;
    }

    
};




struct heavy_light {
    vector<int> heavy;      

                            


    heavy_light(const graph& g) : heavy(g.n,-1) {
        function<int(int,int)> dfs = [&](int u, int p) {
            int size = 1, id8 = 0;
            for (auto [ee,v] : g.edg[u]) {
                if(v == p) continue;
                int c_size = dfs(v,u);
                size += c_size;
                if (c_size > id8)
                    id8 = c_size, heavy[u] = v;
            }
            return size;
        };
        dfs(0,-1);
    }
};










template<class LazySeg>
struct id0 : heavy_light {
    using Node = typename LazySeg::node_type;
    using F = typename LazySeg::func_type;
    
    LazySeg tree;
    vector<int> par, dep, head, pos;    

    int cur_pos = 0;                    


    id0(const graph& g) : heavy_light(g), tree(g.n), par(g.n), 
            dep(g.n), head(g.n), pos(g.n) {
        function<void(int)> dfs = [&](int u) {      

            for (auto [ee,v] : g.edg[u]) {
                if (v != par[u]) {
                    par[v] = u, dep[v] = dep[u] + 1;
                    dfs(v);
                }
            }
        };

        function<void(int,int)> decompose = [&](int u, int hd) {    

            head[u] = hd, pos[u] = cur_pos++;
            if (heavy[u] != -1)
                decompose(heavy[u], hd);
            for (auto [ee,v] : g.edg[u]) {
                if (v != par[u] && v != heavy[u])
                    decompose(v, v);
            }
        };

        for(int u=0; u<g.n; u++) if(!dep[u]) {
            dfs(u);
            decompose(u,u);            
        }
    }

    Node& operator[](int u) { return tree[pos[u]]; }
    void build() { tree.build(); }

    void update_path(int u, int v, const F& f) { update_path(u,v,f,true); }
    Node query_path(int u, int v) { return query_path(u,v,true); }

    void update_path_no_lca(int u, int v, const F& f) { update_path(u,v,f,false); }
    Node query_path_no_lca(int u, int v) { return query_path(u,v,false); }

  private:
    void update_path(int u, int v, const F& f, bool id4) {
        process_path(u, v, [this, &f](int l, int r) { tree.lazy_update(l, r, f); }, id4);
    }
    
    Node query_path(int u, int v, bool id4) {
        Node ans = LazySeg::get_e();
        process_path(u, v, [this, &ans](int l, int r) { ans = LazySeg::do_op(ans, tree.query(l,r)); }, id4);
        return ans;
    }

    template <class Op> void process_path(int u, int v, Op path_op, bool id4) {
        for (; head[u] != head[v]; v = par[head[v]]) {
            if (dep[head[u]] > dep[head[v]]) swap(u, v);
            path_op(pos[head[v]], pos[v] + 1);
        }
        if (dep[u] > dep[v]) swap(u, v);
        path_op(pos[u] + !id4, pos[v] + 1);
    }
};
using hld_sum = id0<sumseg::seg>;




struct dsu {
    int _n;
    

    

    vector<int> parent_or_size;        


    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    vector<vector<int>> groups() {
        vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            remove_if(result.begin(), result.end(),
                           [&](const vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
};




void solve() {
    int n,m; cin >> n >> m;
    vi a(m), b(m), w(m);
    forn(i,m) cin >> a[i] >> b[i] >> w[i];
    forn(i,m) { a[i]--; b[i]--; }

    wgraph<int> g(n);
    dsu d(n);
    vi ok(m);
    forn(i,m) {
        if(d.same(a[i],b[i])) continue;
        g.add(a[i],b[i],w[i]);
        d.merge(a[i],b[i]);
        ok[i] = 1;
    }

    id7 bin(g);
    hld_sum hld(g);

    forn(i,m) {
        if(ok[i]) {
            yes();
            continue;
        }
        ll sm = hld.query_path_no_lca(a[i],b[i]).val;
        if(sm) {
            no();
        } else {        
            ll pw = bin.path_weight(a[i],b[i]);
            pw += w[i];
            if(pw%2) {
                yes();
                hld.update_path_no_lca(a[i],b[i],1);
            } else {
                no();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1; 

    while(tc--) solve();

    return 0;
}
