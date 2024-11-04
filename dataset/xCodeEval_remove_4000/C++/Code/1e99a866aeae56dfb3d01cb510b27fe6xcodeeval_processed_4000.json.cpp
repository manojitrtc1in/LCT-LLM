
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







struct id5 {
    const int mxw = 20;
    vector<int> dep;
    vector<vector<int>> par;

    id5(const graph& g) : dep(g.n), par(g.n,vector<int>(mxw,-1)) {  

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







template <class S, S (*op)(S, S), S (*e)()> 
struct id4 {
  public:
    id4() : id4(0) {}
    id4(int n) : id4(std::vector<S>(n, e())) {}
    id4(const std::vector<S>& v) : _n(int(v.size())) {
        size = 1, log = 0, _ver = 0;
        while(size<_n) log++, size <<= 1;
        d = std::vector<vector<_node>>(2 * size,vector<_node>(1,{0,0,e()}));
        for(int i=0; i<_n; i++) d[i+size][0].s = v[i];
    }

    void build() {
        assert(!id6);
        id6 = true;
        for (int i = size - 1; i >= 1; i--) pull(i);
    }

    S& operator[] (int p) {
        assert(0 <= p && p < _n);
        assert(!id6);
        return d[p+size][0].s;
    }

    S get_latest(int p) {
        assert(0 <= p && p < _n);
        return d[p+size].back().s;
    }

    int update(int ver, int p, const S s) {
        assert(0 <= p && p < _n);
        assert(id6);
        assert(0 <= ver && ver <= _ver);
        p += size;

        d[1].push_back(d[1][ver]);
        for (int i = log - 1; i >= 0; i--) {
            int& it = ((p>>i) & 1) ? d[p>>(i+1)].back().itr : d[p>>(i+1)].back().itl;
            d[p>>i].push_back(d[p>>i][it]);
            it = d[p>>i].size() - 1;
        }
        d[p].back().s = s;
        for (int i = 1; i <= log; i++) pull(p >> i);
        return ++_ver;
    }

    S query(int ver, int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        assert(0 <= ver && ver <= _ver);
        assert(id6);
        if (l == r) return e();
        return query(1, ver, l, r, 0, size);
    }

    S queryall(int ver) { 
        assert(0 <= ver && ver <= _ver);
        assert(id6);
        return d[1][ver].s; 
    }
    


    

    template <bool (*f)(S)> int max_right(int ver, int l) {
        return max_right(ver, l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int ver, int l, F f) {
        assert(0 <= l && l <= _n);
        assert(0 <= ver && ver <= _ver);
        assert(id6);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;

        stack<int> its;
        int it = ver;
        for (int i = log; i >= 1; i--) {
            its.push(it);
            it = ((l >> (i-1)) & 1) ? d[l>>i][it].itr : d[l>>i][it].itl;
        }

        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1, it = its.top(), its.pop();
            if(!its.empty()) it = d[l>>1][its.top()].itr;
            
            if (!f(op(sm, d[l][it].s))) {
                while (l < size) {
                    its.push(it);
                    it = d[l][it].itl;
                    l = (2 * l);
                    if (f(op(sm, d[l][it].s))) {
                        sm = op(sm, d[l][it].s);
                        l++;
                        it = d[l>>1][its.top()].itr;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l][it].s);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <class F> int id3(vector<int> ver, int l, F f) {
        assert(0 <= l && l <= _n);
        int nver = ver.size();
        assert(nver>=1);
        for(int i = 0; i < nver; i++) assert(0 <= ver[i] && ver[i] <= _ver);
        assert(id6);
        assert(f(vector<S>(nver,e())));
        if (l == _n) return _n;
        l += size;
 
        vector<stack<int>> its(nver);
        vi it = ver;
        for (int i = log; i >= 1; i--) {
            for(int j = 0; j < nver; j++) {
                its[j].push(it[j]);
                it[j] = ((l >> (i-1)) & 1) ? d[l>>i][it[j]].itr : d[l>>i][it[j]].itl;
            }
        }

        vector<S> sm(nver,e()), opres(nver);
        do {
            while (l % 2 == 0) {
                l >>= 1;
                for(int i = 0; i < nver; i++) {
                    it[i] = its[i].top(); 
                    its[i].pop();
                }
            }
            for(int i = 0; i < nver; i++) {
                if(!its[i].empty()) it[i] = d[l>>1][its[i].top()].itr; 
                opres[i] = op(sm[i],d[l][it[i]].s);
            }
            if (!f(opres)) {

                while (l < size) {
                    for(int i = 0; i < nver; i++) {
                        its[i].push(it[i]);
                        it[i] = d[l][it[i]].itl;
                        opres[i] = op(sm[i],d[l<<1][it[i]].s);
                    }
                    l = (2 * l);
                    if (f(opres)) {
                        for(int i = 0; i < nver; i++) {
                            sm[i] = op(sm[i],d[l][it[i]].s);
                            it[i] = d[(l+1)>>1][its[i].top()].itr;
                        }
                        l++;
                    }
                }
                return l - size;
            }
            for(int i = 0; i < nver; i++) sm[i] = op(sm[i],d[l][it[i]].s);
            l++;
        } while ((l & -l) != l);
        return _n;
    }



  private:
    struct _node {
        int itl, itr;
        S s;
    };

    int _n, size, log, _ver;
    bool id6 = false;
    std::vector<vector<_node>> d;

    void pull(int k) {
        _node& target = d[k].back();
        target.s = op(d[2 * k][target.itl].s,d[2 * k + 1][target.itr].s);
    }

    S query(int k, int it, int l, int r, int u, int v) {
        if(l<=u && v<=r) return d[k][it].s;
        int mid = (u+v) / 2;
        S sm = e();
        if(l<mid) sm = op(sm,query(k<<1, d[k][it].itl, l, r, u, mid));
        if(mid<r) sm = op(sm,query(k<<1|1, d[k][it].itr, l, r, mid, v));
        return sm;
    }

};




namespace xorseg {
    struct node {
        ll val;
        node() : val(0) {}
        node(ll a) : val(a) {}
    };
    node op(node lhs, node rhs) { return node(lhs.val ^ rhs.val); }
    node e() { return node(0); }
    using seg = id4<node,op,e>;
}
using namespace xorseg;







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

    vi ver(n), par(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        par[u] = p;

        curfp[a[u]] ^= fp[a[u]];
        ver[u] = tree.update(p==-1 ? 0 : ver[p], a[u], curfp[a[u]]);
        for(auto [e,v] : g.edg[u]) {
            if(v==p) continue;
            dfs(v,u);
        }
        curfp[a[u]] ^= fp[a[u]];
    };

    dfs(0,-1);

    id5 bin(g);
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

        int r = tree.id3(vers, lq[i], func);
















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
