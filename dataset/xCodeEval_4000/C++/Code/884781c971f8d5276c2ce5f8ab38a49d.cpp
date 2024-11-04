#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "../../debug.h"
#else
#define DEB(...)
#endif
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(a) ((int)(a).size())
#define forn(i,n) for(int i=0; i<(n); i++)
#define forne(i,n) for(int i=0; i<(n) || (cout << endl,0) ; i++) 
#define fora(i,a,b) for(int i=a; i<=(b); i++)
#define ford(i,a,b) for(int i=a; i>=(b); i--)
#define endl '\n'
#define muniq(x) sort(all(x)), x.erase(unique(all(x)), x.end())
template<class T> bool mmin(T& a, const T& b) { return b<a?a=b,1:0; }
template<class T> bool mmax(T& a, const T& b) { return a<b?a=b,1:0; }
template<class T> void puts(T a) { cout << a << ' '; }
template<class T> void put(T a) { cout << a << endl; }
template<class T> void put(T ita, T itb) { while(ita!=itb) puts(*ita++); cout << endl; }
void yesno(bool c) { put(c?"YES":"NO"); }
void yes() { yesno(true); } void no() { yesno(false); }
void imp() { put("-1"); }
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;




struct base_graph {
    int n, ecnt = 0;
    vector<int> from,to;

    base_graph(int n) : n(n) {}

    void reserve(int m) {
        from.reserve(m);
        to.reserve(m);
    }

    virtual int add(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        from.push_back(a); to.push_back(b);
        return ecnt++;
    }
};

struct dir_graph : public base_graph {
    vector<vector<pair<int,int>>> out,in;

    dir_graph(int n) : base_graph(n), out(n), in(n) {}

    int add(int a, int b) {
        int e = base_graph::add(a,b);
        out[a].push_back({e,b});
        in[b].push_back({e,a});
        return e;
    }
};

struct undir_graph : public base_graph {
    vector<vector<pair<int,int>>> edg;

    undir_graph(int n) : base_graph(n), edg(n) {}

    int add(int a, int b)  {
        if(b>a) swap(a,b);
        int e = base_graph::add(a,b);
        edg[a].push_back({e,b});
        edg[b].push_back({e,a});
        return e;
    }
};




template<class T, class G> 
struct weightable : public G {
    vector<T> w;

    weightable(int n) : G(n) {}

    using G::add;

    int add(int a, int b, T ww) {
        w.push_back(ww);
        return G::add(a,b);
    }

    void reserve(int m) {
        G::reserve(m);
        w.reserve(m);
    }
};

template<class T> using wdir_graph = weightable<T,dir_graph>;
template<class T> using wundir_graph = weightable<T,undir_graph>;




void readin(base_graph& g, int m, int offset = 1) {
    g.reserve(m);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset;
        b -= offset;
        g.add(a,b);
    }
}

template<class T, class G>
void readinw(weightable<T,G>& g, int m, int offset = 1) {
    g.reserve(m);
    for(int i=0; i<m; i++) {
        int a, b; T ww = 0;
        cin >> a >> b >> ww;
        a -= offset;
        b -= offset;
        g.add(a,b,ww);
    }
}

void readin_tree_format(base_graph& g, int offset = 1) {
    int m = g.n-1;
    g.reserve(m);
    for(int i=2; i<=m; i++) {
        int p; cin >> p;
        int a = i-offset;
        g.add(a,p);
    }
}








struct binary_lifting {
    const int mxw = 20;
    vector<int> dep;
    vector<vector<int>> par;

    binary_lifting(undir_graph& g) : dep(g.n), par(g.n,vector<int>(mxw,-1)) {  

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




    int fast_bin_search(int u, bool (*f)(int v)) {
        for(int i=mxw-1; i>=0; i--) {
            if(par[u][i] && f(par[u][i]))
                u = par[u][i];
        }

        

        

        

        


        return u;
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
};






template <class S, S (*op)(S, S), S (*e)()> 
struct pers_segtree {
  public:
    pers_segtree() : pers_segtree(0) {}
    pers_segtree(int n) : pers_segtree(std::vector<S>(n, e())) {}
    pers_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = 1, log = 0, _ver = 0;
        while(size<_n) log++, size <<= 1;
        d = std::vector<vector<_node>>(2 * size,vector<_node>(1,{0,0,e()}));
        for(int i=0; i<_n; i++) d[i+size][0].s = v[i];
    }

    void build() {
        assert(!is_built);
        is_built = true;
        for (int i = size - 1; i >= 1; i--) pull(i);
    }

    S& operator[] (int p) {
        assert(0 <= p && p < _n);
        assert(!is_built);
        return d[p+size][0].s;
    }

    S get_latest(int p) {
        assert(0 <= p && p < _n);
        return d[p+size].back().s;
    }

    int update(int ver, int p, const S s) {
        assert(0 <= p && p < _n);
        assert(is_built);
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
        assert(is_built);
        if (l == r) return e();
        return query(1, ver, l, r, 0, size);
    }

    S queryall(int ver) { 
        assert(0 <= ver && ver <= _ver);
        assert(is_built);
        return d[1][ver].s; 
    }
    


    

    template <bool (*f)(S)> int max_right(int ver, int l) {
        return max_right(ver, l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int ver, int l, F f) {
        assert(0 <= l && l <= _n);
        assert(0 <= ver && ver <= _ver);
        assert(is_built);
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

    template <class F> int max_right_parallel(vector<int> ver, int l, F f) {
        assert(0 <= l && l <= _n);
        int nver = ver.size();
        assert(nver>=1);
        for(int i = 0; i < nver; i++) assert(0 <= ver[i] && ver[i] <= _ver);
        assert(is_built);
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
    bool is_built = false;
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
    using seg = pers_segtree<node,op,e>;
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

    undir_graph g(n);
    readin(g,n-1);

    vi uq(q),vq(q),lq(q),rq(q);
    forn(i,q) cin >> uq[i] >> vq[i] >> lq[i] >> rq[i];
    forn(i,q) {
        uq[i]--;
        vq[i]--;
    }

    binary_lifting bin(g);

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

        int r = tree.max_right_parallel(vers, lq[i], func);
        DEB(r);
        if(rq[i] < r) imp();
        else put(r);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1; 

    while(tc--) solve();

    return 0;
}
