























































#include <map>
#include <numeric>
#include <complex>
#include <set>
#include <iomanip>
#include <algorithm> 
#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define pb push_back 
#define all(v) (v).begin(),(v).end()
#define sz(v) int(v.size())
#define watch(x) cout << (#x) << " = " << x << '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<int> vi;
typedef vector<vi> vvi;
template<typename IT>
ostream &print(IT b, IT e, string sep = " ", ostream &stream = cout){
    for(IT it = b; it != e; ++it){
        stream << *it;
        if(it+1 != e) stream << sep;
    } 
    return stream;
}
template<typename IT> istream &read(IT b, IT e, istream &stream = cin){
    for(IT it = b; it != e; ++it)
        stream >> *it; 
    return stream;
}
template<typename T> ostream &operator<<(ostream &stream, vector<T> &t){
    return print(all(t)," ",stream);
}
template<typename T> ostream &operator<<(ostream &stream, vector<T> &&t){
    return print(all(t)," ",stream);
}
template<typename T> istream &operator>>(istream &stream, vector<T> &t){
    return read(all(t),stream);
}
template<typename F, typename S> ostream &operator<<(ostream &stream, const pair<F,S> t){
    return stream << t.first << ' ' << t.second;
}
template<typename F, typename S> istream &operator>>(istream &stream, pair<F,S> &t){
    return stream >> t.first >> t.second;
}
template <typename T> 
void print(T x, string end = "\n"){
    cout << x << end;
}
template <typename t> 
void print(vector<t> arr,string sep=" "){
    if(arr.empty()){
        return;
    }
    print(arr.begin(),arr.end(),sep);
    cout << '\n';
}
template <typename T> 
void print(vector<vector<T> > arr){
    for(int i = 0; i < sz(arr); ++i){
        cout << "[" << arr[i] << "]";
        if(i+1 < sz(arr))
            cout << ", ";
    }
    cout << '\n';
}
struct DSU{
    vi par;
    int n;
    DSU(int _n):n(_n){
        par.resize(n+1);
        iota(all(par),0);
    }
    int getpar(int u){
        if(par[par[u]] == par[u])
            return par[u];
        return par[u] = getpar(par[u]);
    }
    bool unite(int u, int v){
        u = getpar(u);
        v = getpar(v);
        if(u == v)
            return false;
        par[u] = v; 
        return true;
    }
};
template<typename T>
vector<T> filter_size(const vector<T> &arr, int l = 1, int r = int(1e9)){
    vector<T> ans;
    for(auto &cur : arr)
        if(l <= sz(cur) && sz(cur) <= r)
            ans.pb(cur);
    return ans;
}
template<typename T, typename F>
vector<bool> pos_mask(vector<T> &&arr, F pred){
    vector<bool> ans;
    for(auto &cur : arr)
        ans.pb(pred(cur));
    return ans;
}
template<typename T, typename F>
vector<bool> pos_mask(vector<T> &arr, F pred){
    vector<bool> ans;
    for(auto &cur : arr)
        ans.pb(pred(cur));
    return ans;
}
template<typename F>
vector<bool> pos_mask(string &s, F pred){
    vector<char> tmp(all(s));
    return pos_mask(tmp,pred);
}
template<typename T>
struct _has_value{
    T compares_with;
    _has_value (T _compares_with):compares_with(_compares_with){
    }
    bool operator()(T x)const{
        return compares_with == x;
    }
};
template<typename T>
_has_value<T> has_value(T x){
    return _has_value<T>(x);
}
template<typename T>
T _();
const ll MOD = 1e9+7;
template<typename T>
vector<T> operator+(const vector<T> &lhs, const vector<T> &rhs){
    vector<T> ans(lhs);
    assert(ans.size() == rhs.size());
    for(int i = 0; i < rhs.size(); ++i)
        ans[i] += rhs[i];
    return ans;
}
template<typename T>
vector<T> operator+=(vector<T> &lhs, const vector<T> &rhs){
    return lhs = lhs+rhs;
    

    

    

    

    

}
template<typename T>
vector<T> operator-(const vector<T> lhs, const vector<T> rhs){
    vector<T> ans(all(lhs));
    assert(ans.size() == rhs.size());
    for(int i = 0; i < rhs.size(); ++i)
        ans[i] -= rhs[i];
    return ans;
}
template<typename T>
vector<T> operator-=(vector<T> &lhs, const vector<T> &rhs){
    return lhs = lhs-rhs;
    

    

    

    

    

}
template<typename T>
vector<T> append(vector<T> &lhs, const vector<T> rhs){
    lhs.insert(lhs.end(),all(rhs));
    return lhs;
    

    

    

    

    

}
template<typename T>
T max(const vector<T> arr){
    assert(!arr.empty());
    T ans = arr[0];
    for(auto &cur : arr)
        ans = max(ans,cur);
    return ans;
}
template<typename T>
T min(const vector<T> arr){
    assert(!arr.empty());
    T ans = arr[0];
    for(auto &cur : arr)
        ans = min(ans,cur);
    return ans;
}
template<typename T>
T max(const set<T> s){
    assert(!s.empty());
    return *--s.end();
}
template<typename T>
T min(const set<T> s){
    assert(!s.empty());
    return *s.begin();
}
template <typename T>
T rhash(const vector<T> &arr){
    T result = arr[0];
    const ll R = 1e9+7, P = 1e9+9;
    ll mult = R;
    for(int i = 1; i < sz(arr); ++i){
        mult = (mult*R)%P;
        result += T(mult)*arr[i];
        if(result >= P)
            result -= P;
    }
    return result;
}
template<typename T>
T rhash(const vector<complex<T> > &arr){
    T result = 0;
    ll R = 1e9+7, P = 1e9+9;
    ll mult = R;
    for(auto &cur : arr){
        mult = (mult*R)%P;
        result += T(mult)*cur.real();
        if(result >= P)
            result -= P;
        mult = (mult*R)%P;
        result += T(mult)*cur.imag();
        if(result >= P)
            result -= P;
    }
    return result;
}
#ifndef M_PI
#define M_PI 3.141592653589793238462643383279
#endif
namespace FFT{
    typedef double ld;
    typedef complex<ld> base;
    typedef pair<vector<ld>,vector<ld> > ID;
    map<ld,vector<base> > save;
    void fft (vector<base> & a, bool invert, bool save_previous = false) {
        int n = (int) a.size();
        ld id;
        if(save_previous){
            id = rhash(a);
            if(save.count(id)){
                a = save[id];
                return;
            }
        }
        for (int i=1, j=0; i<n; ++i) {
            int bit = n >> 1;
            for (; j>=bit; bit>>=1)
                j -= bit;
            j += bit;
            if (i < j)
                swap (a[i], a[j]);
        }

        for (int len=2; len<=n; len<<=1) {
            double ang = 2*M_PI/len * (invert ? -1 : 1);
            base wlen (cos(ang), sin(ang));
            for (int i=0; i<n; i+=len) {
                base w (1);
                for (int j=0; j<len/2; ++j) {
                    base u = a[i+j],  v = a[i+j+len/2] * w;
                    a[i+j] = u + v;
                    a[i+j+len/2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert)
            for (int i=0; i<n; ++i)
                a[i] /= n;
        if(save_previous){
            save[id] = a;
        }
    }
    template<typename T>
        vector<ll> multiply(const vector<T> & a, const vector<T> & b, bool save = false) {
            vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
            size_t n = 1;
            while (n < max (a.size(), b.size()))  n <<= 1;
            n <<= 1;
            fa.resize (n),  fb.resize (n);

            fft (fa, false, save),  fft (fb, false, save);
            for (size_t i=0; i<n; ++i)
                fa[i] *= fb[i];
            fft (fa, true, save);

            vector<ll> res(n);
            for (size_t i=0; i<n; ++i)
                res[i] =  floor(fa[i].real() + 0.5);
            return res;
        }
}
template<typename T>
vl fft_mult(vector<T> a, vector<T> b, bool save = false){
    if(a.empty() || b.empty())
        return vl();
    vl _a,_b;
    _a.reserve(a.size());
    _b.reserve(b.size());
    for(auto cur : a) _a.pb(cur);
    for(auto cur : b) _b.pb(cur);
    return FFT::multiply(_a,_b,save);
}
template<typename T>
vl bounded_mult(vector<T> a, vector<T> b, bool save = false){
    vl ans = fft_mult(a,b,save);
    return vl(ans.begin()+min(a.size(),b.size())-1,ans.begin()+max(a.size(),b.size()));
}
template<typename T, typename G>
vector<T> set_max(vector<T> &base, const vector<G> &comp){
    assert(base.size() == comp.size());
    for(int i = 0; i < (int)comp.size(); ++i)
        base[i] = max(base[i],comp[i]);
    return base;
}
template <typename T>
vector<T> unique(vector<T> &arr){
    sort(all(arr));
    arr.erase(unique(all(arr)),arr.end());
    return arr;
}
struct UGraph{
    struct Edge{
        int u,v,id;
        int nxt(int from){
            return from==u?v:u;
        }
    };
    vector<Edge> edges;
    int n,m;
    vvi conn;
    UGraph(){
        m = -1;
    }
    UGraph(int nsize) : UGraph() {
        n = nsize;
        conn.resize(n+1);
    }
    UGraph(int nsize, int _m) : UGraph(nsize){
        m = _m;
    }
    void add_edge(int u, int v, int id = -1) {
        if(id == -1)
            id = sz(edges);
        conn[u].pb(id);
        conn[v].pb(id);
        edges.pb({u,v,id});
    }
    vi bfs_dist(int u){
        vb visited(n+1);
        visited[u] = true;
        vi bfs(1,u),dist(n+1,-1);
        dist[u] = 0;
        for(int i = 0; i < bfs.size(); ++i){
            int u = bfs[i];
            for(int _v : conn[u]){
                int v = edges[_v].nxt(u);
                if(!visited[v]){
                    visited[v] = true;
                    dist[v] = dist[u]+1;
                    bfs.pb(v);
                }
            }
        }
        return dist;
    }
    void _bridges_dfs(int u, int p, int &timer, vi &tin, vi &fup, vb &used, vi &ans){
        used[u] = true;
        tin[u] = fup[u] = timer++;
        for (int i = 0; i < sz(conn[u]); ++i) {
            if (edges[conn[u][i]].id == p)  continue;
            int v = edges[conn[u][i]].nxt(u);
            if (used[v])
                fup[u] = min (fup[u], tin[v]);
            else {
                _bridges_dfs(v, edges[conn[u][i]].id,timer,tin,fup,used,ans);
                fup[u] = min (fup[u], fup[v]);
                if (fup[v] > tin[u]){
                    ans.pb(edges[conn[u][i]].id);
                }
            }
        }
    }
    vi bridges(){

        vi tin(n+1),fup(n+1);
        vb used(n+1);
        int timer = 0;
        for (int i = 1; i <= n; ++i)
            used[i] = false;
        vi ans;
        for (int i = 1; i <= n; ++i)
            if (!used[i])
                _bridges_dfs(i,-1,timer,tin,fup,used,ans);
        sort(all(ans));
        return ans;
    }
    void _sz_below(int u, int p, int &timer, vl &sz, vi &tin, vb &used, vl &weight){
        vl ans;
        used[u] = true;
        tin[u] = timer++;
        sz[u] = weight[u];
        for (int i = 0; i < sz(conn[u]); ++i) {
            if (edges[conn[u][i]].id == p) continue;
            int v = edges[conn[u][i]].nxt(u);
            if(!used[v]){
                _sz_below(v, edges[conn[u][i]].id,timer,sz,tin,used,weight);
                sz[u] += sz[v];
            }
        }
    }
    vpll bridge_sep_sizes(vl weight = vl()){

        if(weight.empty())
            weight = vl(n+1,1);
        vb used(n+1,false);
        int timer = 0;
        vl sz;
        vi tin(n+1);
        sz.resize(n+1);
        for (int i = 1; i <= n; ++i)
            if (!used[i])
                _sz_below(i,-1,timer,sz,tin,used,weight);
        vi br = bridges();
        vpll ans;
        for(auto cur : br){
            int u = edges[cur].u;
            int v = edges[cur].v;
            if(tin[u] > tin[v])
                swap(u,v);
            ans.pb({cur,sz[v]});
        }
        return ans;
    }
    vi non_bridges(){

        vi br = bridges();
        reverse(all(br));
        vi nbr;
        for(int i = 0; i < sz(edges); ++i)
            if(!br.empty() && i == br.back())
                br.pop_back();
            else
                nbr.pb(i);
        return nbr;
    }
    vvi conn_comp(){
        DSU dsu(n);
        for(auto cur : edges)
            dsu.unite(cur.u,cur.v);
        vvi comp(n+1);
        for(int i = 1; i <= n; ++i)
            comp[dsu.getpar(i)].pb(i);
        return filter_size(comp);
    }
    vvi bridge_conn_comp(){
        vi br = bridges();
        DSU dsu(n);
        for(auto cur : br)
            dsu.unite(edges[cur].u,edges[cur].v);
        vvi comp(n+1);
        for(int i = 1; i <= n; ++i)
            comp[dsu.getpar(i)].pb(i);
        return filter_size(comp);
    }
    vvi non_bridge_conn_comp(){
        vi nbr = non_bridges();
        DSU dsu(n);
        for(auto cur : nbr)
            dsu.unite(edges[cur].u,edges[cur].v);
        vvi comp(n+1);
        for(int i = 1; i <= n; ++i)
            comp[dsu.getpar(i)].pb(i);
        return filter_size(comp);
    }
    vi _cut_points_dfs(int u, int p, int &timer, vi &tin, vi &fup, vb &visited, vi &ans) {
        visited[u] = true;
        tin[u] = fup[u] = timer++;
        int children=0;
        for(int i = 0; i < sz(conn[u]); ++i){
            if (conn[u][i] == p) continue;
            int v = edges[conn[u][i]].nxt(u);
            if (visited[v]) {
                fup[u] = min(fup[u], tin[v]);
            } else {
                _cut_points_dfs(v, conn[u][i],timer,tin,fup,visited,ans);
                fup[u] = min(fup[u], fup[v]);
                if (fup[v] >= tin[u] && p!=-1)
                    ans.pb(u);
                ++children;
            }
        }
        if(p == -1 && children > 1)
            ans.pb(u);
        return ans;
    }
    vi cut_points(){
        vector<bool> visited(n+1);
        vector<int> tin(n+1,-1), fup(n+1,-1);
        int timer = 0;
        vi ans;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                _cut_points_dfs(i,-1,timer,tin,fup,visited,ans);
        }
        unique(ans);
        return ans;
    }
    void _biconn_comp_dfs(int u, int p, int &timer, vi &tin, vi &fup, vb &visited, vb &edge_visited, vi &stk, vvi &ans) {
        

        

        visited[u] = true;
        tin[u] = fup[u] = timer++;
        int children=0;
        for(int i = 0; i < sz(conn[u]); ++i){
                

            if(conn[u][i] == p)
                continue;
            int v = edges[conn[u][i]].nxt(u);
            if(!edge_visited[conn[u][i]])
                stk.pb(edges[conn[u][i]].id);
            edge_visited[conn[u][i]] = true;
            if (visited[v]) {
                fup[u] = min(fup[u], tin[v]);
            } else {
                _biconn_comp_dfs(v, conn[u][i],timer,tin,fup,visited,edge_visited,stk,ans);
                fup[u] = min(fup[u], fup[v]);
                if (fup[v] >= tin[u] && p!=-1){
                    

                    

                    

                    

                    

                    if(!stk.empty()){
                        vi cur;
                        while(!stk.empty() && edges[stk.back()].id != edges[conn[u][i]].id){
                            cur.pb(stk.back());
                            stk.pop_back();
                        }
                        cur.pb(stk.back());
                        stk.pop_back();
                        

                            

                            

                        

                        

                        

                        ans.pb(cur);
                    }
                }
                ++children;
                if(p == -1 && sz(stk)){
                    sort(all(stk));
                    ans.pb(stk);
                    stk.clear();
                }
            }
        }
        if(p == -1 && sz(stk)){
            

            sort(all(stk));
            ans.pb(stk);
            

            stk.clear();
        }
    }
    vvi biconn_comp_edges(){
        vb visited(n+1),edge_visited(sz(edges));
        

            

        vi tin(n+1,-1), fup(n+1,-1),stk;
        int timer = 0;
        vvi ans;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                _biconn_comp_dfs(i,-1,timer,tin,fup,visited,edge_visited,stk,ans);
        }
        return ans;
    }
    vi induced_sub(vi edge_ids){
        vi ans;
        for(auto cur : edge_ids){
            ans.pb(edges[cur].u);
            ans.pb(edges[cur].v);
        }
        unique(ans);
        return ans;
    }
    vvi biconn_comp(){
        vvi edges = biconn_comp_edges();
        

        vvi ans;
        for(auto cur : edges)
            ans.pb(induced_sub(cur));
        return ans;
    }
};
istream &operator>>(istream &stream, UGraph &g){
    if(g.m == -1){
        stream >> g.n >> g.m;
        g = UGraph(g.n,g.m);
    }
    for(int i = 0; i < g.m; ++i){
        int u,v;
        stream >> u >> v;
        g.add_edge(u,v);
    }
    return stream;
}
ostream &operator<<(ostream &stream, const UGraph g){
    stream << g.n << ' ' << g.m << '\n';
    for(auto cur : g.edges)
        stream << cur.u << " " << cur.v << '\n';
    return stream;
}
vl _(){
    string s,t;
    cin >> s >> t;
    reverse(all(t));
    map<char,map<char,vl> > match;
    for(char c1 : "abcdef")
        for(char c2 : "abcdef")
            if(c1 != c2)
                match[c1][c2] = bounded_mult(pos_mask(s,has_value(c1)),pos_mask(t,has_value(c2)),1);
    int sz = match['a']['b'].size();
    vl ans(sz);
    for(int i = 0; i < sz; ++i){
        UGraph g(6);
        for(int j = 1; j <= 6; ++j)
            for(int k = 1; k <= 6; ++k)
                if(j != k)
                    if(match[j+'a'-1][k+'a'-1][i])
                        g.add_edge(j,k);
        ans[i] = 6-sz(g.conn_comp());
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(12);
    cout << _() << '\n';
}
