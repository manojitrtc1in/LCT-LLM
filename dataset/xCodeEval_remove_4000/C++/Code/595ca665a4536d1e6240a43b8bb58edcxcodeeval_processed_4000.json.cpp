
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








template<class T> bool divc(T a, T b) { return (a + b - 1) / b; }
template<class T> bool mmin(T& a, const T& b) { return b<a?a=b,1:0; }
template<class T> bool mmax(T& a, const T& b) { return a<b?a=b,1:0; }
void put() {}
template<class T, class... Args> void put(T a, Args... args) { cout << a << ' '; put(args...); }
template<class... Args> void putn(Args... args) { put(args...); cout << endl; }
template<class It> void put_each(It first, It last) { for_each(first,last,put<decltype(*first)>); }
template<class It> void id0(It first, It last) { put_each(first,last); putn(); }
void yesno(bool c) { putn(c?"YES":"NO"); }
void yes() { yesno(true); } void no() { yesno(false); }
void imp() { putn("-1"); }
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;

int flag = 0;



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

    virtual void reserve(int m) {
        from.reserve(m);
        to.reserve(m);
    }

    virtual void resize(int n) {
        edg.resize(n);
        this->n = n;
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

    void resize(int n) {
        out.resize(n);
        in.resize(n);
        G::resize(n);
    }
    using is_directed_t = void;
};

template <typename T, typename = void> struct is_directed : std::false_type {};
template <typename T> struct is_directed<T, typename T::is_directed_t> : std::true_type {};
using dir_graph = directed<graph>;




template<class G>
struct adj : public G {

    adj(int n) : G(n), _adj(n) {}
    adj(const G& g) : G(g), _adj(g.n) {}

    int add(int a, int b) {
        int e = G::add(a,b);
        _adj[a][b] = e;
        if(!is_directed<G>::value) _adj[b][a] = e;
        return e;
    }

    int get_e(int a, int b) {
        if(_adj[a].count(b)) return _adj[a][b];
        else return -1;
    }

    void resize(int n) {
        _adj.resize(n);
        G::resize(n);
    }
    using has_adj_t = void;
  private:
    vector<unordered_map<int,int>> _adj;
};

template <typename T, typename = void> struct has_adj : std::false_type {};
template <typename T> struct has_adj<T, typename T::has_adj_t> : std::true_type {};
using adj_graph = adj<graph>;
using adj_dir_graph = adj<dir_graph>;




template<class W, class G> 
struct weighted : public G {
    vector<W> w;

    weighted(int n) : G(n) {}
    weighted(const G& g) : G(g), w(g.ecnt) {}

    int add(int a, int b, W ww = W()) {
        w.push_back(ww);
        return G::add(a,b);
    }

    void reserve(int m) {
        G::reserve(m);
        w.reserve(m);
    }
    using is_weighted_t = void;
    using weight_t = W;
};

template <typename T, typename = void> struct is_weighted : std::false_type {};
template <typename T> struct is_weighted<T, typename T::is_weighted_t> : std::true_type {};
template <typename T> using weight_t = enable_if_t<is_weighted<T>::value, typename T::weight_t>;

template<class T> using wdir_graph = weighted<T,dir_graph>;
template<class T> using wgraph = weighted<T,graph>;
template<class T> using wadj_dir_graph = weighted<T,adj_dir_graph>;
template<class T> using wadj_graph = weighted<T,adj_graph>;




void readin(graph& g, int m, int offset = 1) {
    g.reserve(m);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset;
        b -= offset;
        g.add(a,b);
    }
}

template<class G>
void id1(G& g, int m, int offset = 1) {
    static_assert(is_weighted<G>::value==true);
    g.reserve(m);
    for(int i=0; i<m; i++) {
        int a, b; 
        weight_t<G> w = 0;
        cin >> a >> b >> w;
        a -= offset;
        b -= offset;
        g.add(a,b,w);
    }
}

void id2(graph& g, int offset = 1) {
    g.reserve(g.n-1);
    for(int i=2; i<=g.n; i++) {
        int p; cin >> p;
        int a = i-offset;
        p -= offset;
        g.add(a,p);
    }
}







struct id4 {
    const int mxw = 20;
    vector<int> dep;
    vector<vector<int>> par;

    id4(const graph& g) : dep(g.n), par(g.n,vector<int>(mxw,-1)) {  

        function<void(int,int,int)> dfs = [&](int u, int p, int d) {
            dep[u] = d;
            int pp = p;
            for(int k=0; k<mxw && pp>=0; k++) {
                par[u][k] = pp;
                pp = par[pp][k];
            }

            for(auto [e,v] : g.edg[u]) 
                if(v!=p) dfs(v,u,d+1);
        };
        dfs(0,-1,0);
    }

    int walkup(int u, int h) {
        assert(h<=dep[u]);
        int i = 0;
        while(h) {
            if(h&1) u = par[u][i];
            i++;
            h = h>>1;
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

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
};






template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id6 {
  public:
    id6() : id6(0) {}
    id6(int n) : id6(std::vector<S>(n, e())) {}
    id6(const std::vector<S>& v) : _n(int(v.size())), _ver(0), root(1,1) {
        size = 1;
        while(size<_n) size <<= 1;
        d = vector<_node>(2*size);
        for(int i=0; i<2*size; i++) d[i].orig_i = i;
        for(int i=0; i<size; i++) {
            d[i].l = i<<1;
            d[i].r = i<<1|1;
        }
        for(int i=0; i<_n; i++) {
            d[i+size].s = v[i];
        }
    }




    void build() {
        assert(!id5);
        id5 = true;
        for(int i = size-1; i>=1; i--) pull(i);
    }

    S& operator[] (int p) {
        assert(0 <= p && p < _n);
        assert(!id5);
        return d[p+size].s;
    }




    S query(int ver, int l, int r) {
        assert_params(ver,l,r);
        if (l == r) return e();
        return query(root[ver], l, r, 0, size);
    }

    int lazy_update(int ver, int l, int r, F f) {
        assert_params(ver,l,r);
        root.push_back(copy(root[ver],++_ver));
        lazy_update(root[_ver],l,r,0,size,f);
        return _ver;
    }

    

    vector<int> segment_ids(int ver, int l, int r) {
        assert_params(ver,l,r);
        vector<int> ans;
        if(l<r) segment_ids(root[ver], l, r, 0, size, ans);
        return ans;
    }




    S get_s(int i) { return d[i].s; }
    int get_l(int i) { return d[i].l; }
    int get_r(int i) { return d[i].r; }
    int get_orig_i(int i) { return d[i].orig_i; }




    

    template <bool (*f)(S)> int max_right(int ver, int l) {
        return max_right(ver, l, [](S x) { return f(x); });
    }
    template <class G> int max_right(int ver, int l, G f) {
        assert_params(ver,l,f);
        if(l==_n) return _n;

        

        vector<int> ids = segment_ids(ver, l, _n);
        S sm = e();
        int j = 0;
        while(j<ids.size() && f(op(sm,get_s(ids[j])))) 
            sm = op(sm,get_s(ids[j++]));
        if(j==ids.size()) return _n;

        

        int i = ids[j];
        while(1) {
            push(i);
            if(get_l(i)==-1) break;
            S new_sm = op(sm,get_s(get_l(i)));
            i = f(new_sm) ? (sm = new_sm, get_r(i)) : get_l(i);
        }
        return get_orig_i(i) - size;
    }

    template <class G> int id3(vector<int> vers, int l, G f) {
        int vn = vers.size();
        for(int k=0; k<vn; k++)
            assert_params(vers[k],l,l);
        if(l==_n) return _n;

        

        vector<vector<int>> ids(vn);
        for(int k=0; k<vn; k++)
            ids[k] = segment_ids(vers[k], l, _n);

        vector<S> sm(vn,e());
        int j = 0;
        while(j<(int)ids[0].size()) {
            vector<S> nx_sm(vn);
            for(int k=0; k<vn; k++) nx_sm[k] = op(sm[k],get_s(ids[k][j]));
            if(!f(nx_sm)) break;
            else sm = nx_sm, j++;
        }
        if(j==(int)ids[0].size()) return _n;

        

        vector<int> badi;
        for(int k=0; k<vn; k++) badi.push_back(ids[k][j]);
        while(1) {
            for(int k=0; k<vn; k++) push(badi[k]);
            if(get_l(badi[0])==-1) break;
            vector<S> nx_sm(vn);
            for(int k=0; k<vn; k++) {
                nx_sm[k] = op(sm[k],get_s(get_l(badi[k])));
            }
            if(f(nx_sm)) {
                sm = nx_sm;
                for(int k=0; k<vn; k++) badi[k] = get_r(badi[k]);
            } else for(int k=0; k<vn; k++) badi[k] = get_l(badi[k]);
        }
        return get_orig_i(badi[0]) - size;
    }


    

    template <bool (*f)(S)> int min_left(int ver, int l) {
        return min_left(ver, l, [](S x) { return f(x); });
    }
    template <class G> int min_left(int ver, int r, G f) {
        assert_params(ver,r,f);
        if(r==0) return 0;

        

        vector<int> ids = segment_ids(ver, 0, r);
        S sm = e();
        int j = ids.size()-1;
        while(j>=0 && f(op(get_s(ids[j]),sm))) 
            sm = op(get_s(ids[j--]),sm);
        if(j==-1) return 0;

        

        int i = ids[j];
        while(1) {
            push(i);
            if(get_l(i)==-1) break;
            S new_sm = op(sm,get_s(get_r(i)));
            i = f(new_sm) ? (sm = new_sm, get_l(i)) : get_r(i);
        }
        return get_orig_i(i) - size + 1;
    }



    struct _node {
        int orig_i = -1, ver = 0;
        int l = -1, r = -1;
        S s;
        F lz;
        bool has_lz = false;
        _node() : s(e()), lz(id()) {};
    };

    int _n, size, _ver;
    bool id5 = false;
    vector<_node> d;
    vector<int> root;

    int copy(int i, int nver) {
        d.push_back(d[i]);
        d.back().ver = nver;
        return d.size()-1;
    }

    void pull(int i) { d[i].s = op(d[d[i].l].s,d[d[i].r].s); }

    void lazy_apply(int i, F f) {
        d[i].s = mapping(f,d[i].s);
        if(d[i].orig_i < size) {
            d[i].lz = composition(f,d[i].lz);
            d[i].has_lz = true;
        }
    }

    void extend_version_l(int i) {
        if(d[i].ver != d[d[i].l].ver) d[i].l = copy(d[i].l, d[i].ver);        
    }

    void extend_version_r(int i) {
        if(d[i].ver != d[d[i].r].ver) d[i].r = copy(d[i].r, d[i].ver);        
    }

    void push(int i) {
        if(!d[i].has_lz) return;
        extend_version_l(i);
        extend_version_r(i);
        lazy_apply(d[i].l,d[i].lz);
        lazy_apply(d[i].r,d[i].lz);
        d[i].lz = id();
        d[i].has_lz = false;
    }

    void segment_ids(int i, int l, int r, int u, int v, vector<int>& ids) {
        if(l<=u && v<=r) return ids.push_back(i);
        push(i);
        int mid = (u+v) / 2;
        if(l<mid) segment_ids(d[i].l, l, r, u, mid, ids);
        if(mid<r) segment_ids(d[i].r, l, r, mid, v, ids);
    }


    S query(int i, int l, int r, int u, int v) {
        if(l<=u && v<=r) return d[i].s;
        push(i);
        int mid = (u+v) / 2;
        S sm = e();
        if(l<mid) sm = op(sm,query(d[i].l, l, r, u, mid));
        if(mid<r) sm = op(sm,query(d[i].r, l, r, mid, v));
        return sm;
    }

    void lazy_update(int i, int l, int r, int u, int v, F f) {
        if(l<=u && v<=r) return lazy_apply(i,f);


        push(i);
        int mid = (u+v) / 2;
        if(l<mid) extend_version_l(i), lazy_update(d[i].l, l, r, u, mid, f);
        if(mid<r) extend_version_r(i), lazy_update(d[i].r, l, r, mid, v, f);
        pull(i);
    }

    void assert_params(int ver, int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        assert(0 <= ver && ver <= _ver);
        assert(id5);
    }

    template<class G> void assert_params(int ver, int l, G f) {
        assert(0 <= l && l <= _n);
        assert(0 <= ver && ver <= _ver);
        assert(id5);
        assert(f(e()));
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
    using seg = id6<node,op,e,lzadd,mapping,composition,id>;
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
    using seg = id6<node,op,e,lzadd,mapping,composition,id>;
}



namespace sumseg {
    struct node {
        ll val;
        int range;
        node() : node(0) {};
        node(ll a) : node(a,1) {};
        node(ll a, int ran) : val(a), range(ran) {};
    };
    struct lzadd {
        ll val;
        lzadd(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return node(lhs.val + rhs.val, lhs.range+rhs.range); }
    node e() { return node(0,1); }
    lzadd composition(lzadd lhs, lzadd rhs) { return lzadd(lhs.val+rhs.val); }
    lzadd id() { return lzadd(0); }
    node mapping(lzadd a, node n) { return node(n.val + n.range*a.val, n.range); }
    using seg = id6<node,op,e,lzadd,mapping,composition,id>;
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
    using seg = id6<node,op,e,lzset,mapping,composition,id>;
}



namespace xorseg {
    struct node {
        ll val;
        node() : val(0) {}
        node(ll a) : val(a) {}
    };
    

    struct lzadd {
        ll val;
        lzadd(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return node(lhs.val ^ rhs.val); }
    node e() { return node(0); }
    lzadd composition(lzadd lhs, lzadd rhs) { return lzadd(lhs.val+rhs.val); }
    lzadd id() { return lzadd(0); }
    node mapping(lzadd a, node n) { return node(n.val+a.val); }
    using seg = id6<node,op,e,lzadd,mapping,composition,id>;
}



namespace xorsetseg {
    struct node {
        ll val;
        node() : val(0) {}
        node(ll a) : val(a) {}
    };
    

    struct lzset {
        ll val;
        lzset(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return node(lhs.val ^ rhs.val); }
    node e() { return node(0); }
    lzset composition(lzset newlz, lzset oldlz) { 
        if(newlz.val==-1) return oldlz;
        return newlz; 
    }
    lzset id() { return lzset(-1); }
    node mapping(lzset a, node n) { 
        if(a.val==-1) return n;
        return node(a.val); 
    }
    using seg = id6<node,op,e,lzset,mapping,composition,id>;
}
using namespace xorsetseg;







struct randll {
    mt19937 rng;
    uniform_int_distribution<long long> rg;

    randll(long long from, long long to) : rng(std::chrono::high_resolution_clock::now().time_since_epoch().count()), rg(from,to) {}

    long long getll() {
        return rg(rng);
    }
};




void solve() {
    int n,q; cin >> n >> q;
    vi a(n);
    forn(i,n) cin >> a[i];




    graph g(n);
    readin(g,n-1);

    vi uq(q),vq(q),lq(q),rq(q);
    forn(i,q) cin >> uq[i] >> vq[i] >> lq[i] >> rq[i];
    forn(i,q) {
        uq[i]--;
        vq[i]--;
    }

    randll ran(0,infl);
    vl fp(n+1), curfp(n+1);
    fora(i,1,n) fp[i] = ran.getll();

    seg tree(n+1);
    tree.build();

    if(flag) {
        cout << "beg " << tree.size << " " << tree.d.size() << endl;
    }

    vi ver(n), par(n);
    int cc = 0;
    function<void(int,int)> dfs = [&](int u, int p) {
        par[u] = p;
        cc++;

        curfp[a[u]] ^= fp[a[u]];
        ver[u] = tree.lazy_update(p==-1 ? 0 : ver[p], a[u], a[u]+1, curfp[a[u]]);
        if(flag && tree.d.size() > 12*tree.size){
            cout << "sz: " << tree.size << " " << tree.d.size() << " " << cc << endl;
            return;
        }
        for(auto [e,v] : g.edg[u]) {
            if(v==p) continue;
            dfs(v,u);
        }
        curfp[a[u]] ^= fp[a[u]];
    };

    dfs(0,-1);


    id4 bin(g);
    forn(i,q) {
        int lca = bin.lca(uq[i],vq[i]);

        auto func = [&](vector<node> sm) {
            ll val = 0;
            int nver = sm.size();
            forn(i,nver) val ^= sm[i].val;
            return val==0;
        };

        vi vers = { ver[uq[i]], ver[vq[i]], ver[lca]};
        if(lca>0) vers.push_back(ver[par[lca]]);

        int r = 0;


            r = tree.id3(vers, lq[i], func);


















            if(rq[i] < r) imp();
            else putn(r);


    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1; 

    while(tc--) solve();

    return 0;
}
