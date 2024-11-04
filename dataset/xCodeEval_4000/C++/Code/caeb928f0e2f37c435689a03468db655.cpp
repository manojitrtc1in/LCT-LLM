

#pragma GCC optimize("unroll-loops", "omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#define dbg(...)
#define db(...)
#include "bits/stdc++.h"
using namespace std;using ll = long long;using ld = long double;

#define _(_1, _2, _3, _4, NAME, ...) NAME
#define f3(i, a, n, inc) for(int i = (a); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define f2(i, a, n) f3(i, a, n, 1 - 2*(a > n))
#define f1(i, n) f2(i, 0, n)
#define f0(i) f2(i, 0, n)
#define fr(...) _(__VA_ARGS__, f3, f2, f1 , f0)(__VA_ARGS__)
#define trav(i,x) for(auto& i: x)
#define sz(x) ((int)x.size())
#define len(x) ((int)x.length())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) begin(x),end(x)
const ll MOD = 1e9+7;   


const ll INF = 1e18 + 10;

namespace amit{ 

    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    inline bool blank(char c){ return (c == ' ' || c== '\t' || c== '\r' || c== '\n'); }; 
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    void re(int& x) { scanf("%d",&x);} void re(long& x) { scanf("%ld",&x);} 
    void re(ll& x) { scanf("%lld",&x);} void re(unsigned& x) { scanf("%u",&x);} 
    void re(unsigned long& x) { scanf("%lu",&x);} void re(unsigned long long& x) { scanf("%llu",&x); } 
    void re(float& x) { scanf("%f",&x);} void re(double& x) { scanf("%lf",&x);} 
    void re(ld& x) { scanf("%llf",&x);} bool re(char& x) { if(scanf("%c",&x)==EOF) return false; if(blank(x)) re(x); return true;} 
    bool red(char& x) { if(scanf("%c",&x)==EOF) return false; return true; } 
    void re(string& x) { char c; if(!re(c)) return; while(!blank(c)){ x+=c ; if(!red(c)) break;}} 
    template<class T, class... Ts> void re(T& t, Ts&... ts) { re(t); re(ts...);} 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; } 
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.ff,p.ss); } 
    template<class T> void re(vector<T>& a) { fr(i,sz(a)) re(a[i]); } 
    template<class T, size_t SZ> void re(array<T,SZ>& a) { fr(i,SZ) re(a[i]); }
    void pr(int x) { printf("%d",x ); } void pr(long x) { printf("%ld",x ); } 
    void pr(ll x) { printf("%lld",x ); } void pr(unsigned x) { printf("%u",x ); } 
    void pr(unsigned long x) { printf("%lu",x ); } void pr(unsigned long long x) { printf("%llu",x ); } 
    void pr(float x) { printf("%.3f",x ); } void pr(double x) { printf("%.5lf",x ); } 
    void pr(ld x) { printf("%.10llf",x ); } void pr(char x) { printf("%c",x ); } 
    void pr(const char* x) { printf("%s",x ); } void pr(const string& x) { printf("%s",x.c_str()); } 
    void pr(bool x) { pr(x ? "true" : "false"); } template<class T> void pr(const complex<T>& x) { cout << x; } 
    template<class T1, class T2> void pr(const pair<T1,T2>& x); template<class T> void pr(const T& x); 
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts){pr(t); pr(ts...); } 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("(",x.ff,", ",x.ss,")"); } 
    template<class T> void pr(const T& x) { pr("{");bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; pr("}");} 
    void ps() { pr("\n"); } template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); } 
    void pc() { pr("]\n"); } template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
    template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } 
    template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 
    vector<ll> fact; vector<ll> inv; ll mod = MOD;
    ll power(ll x, ll n) { ll res = 1; while (n > 0) { if (n & 1) res = res * x % mod; x = x * x % mod; n >>= 1; } return res; } 
    ll mod_inv(ll x) {  return power(x, mod - 2); } 
    ll nCr(ll n, ll r) { return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod; } 
    ll nPr(ll n, ll r) { return (fact[n] * inv[n - r]) % mod; } 
    ll nHr(ll n, ll r) { return nCr(r + n - 1, r); } 
    void comb_init(ll n, ll _mod = MOD) { mod = _mod; fact.resize(n + 1); fact[0] = 1; fr(i, n) { fact[i + 1] = (fact[i] * (i + 1LL)) % mod; } inv.resize(n + 1); inv[n] = mod_inv(fact[n]); for (int i = n; i > 0; i--) { inv[i - 1] = inv[i] * i % mod; } } 
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll rnd(ll x=0, ll y=INF) {return (rng() % (y-x +1)) + x;};
};using namespace amit; 
const int MX = 2e5 + 10;

template<class T, class BO1, class BO2, class BO3>
struct lazyseg{
    lazyseg *l = 0, *r = 0;
    int low, high;
    BO1 &lop;       

    BO2 &qop;       

    BO3 &aop;       

    vector<T> &id;  

    T lset, lazy, val;
    lazyseg(int low, int high, BO1 &lop, BO2 &qop, BO3 &aop, vector<T> &id)
    : low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
        lazy = id[0], val = id[1], lset = id[2];
    }
    lazyseg(const vector<T> &arr, int low, int high, BO1 &lop, BO2 &qop, BO3 &aop, vector<T> &id)
    : low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
        lazy = id[0], lset = id[2];
        if(high - low > 1){
            int mid = low + (high - low) / 2;
            l = new lazyseg(arr, low, mid, lop, qop, aop, id);
            r = new lazyseg(arr, mid, high, lop, qop, aop, id);
            val = qop(l->val, r->val);
        }
        else val = arr[low];
    }
    void push(){
        if(!l){
            int mid = low + (high - low) / 2;
            l = new lazyseg(low, mid, lop, qop, aop, id);
            r = new lazyseg(mid, high, lop, qop, aop, id);
        }
        if(lset != id[2]){
            l->set(low, high, lset);
            r->set(low, high, lset);
            lset = id[2];
        }
        else if(lazy != id[0]){
            l->update(low, high, lazy);
            r->update(low, high, lazy);
            lazy = id[0];
        }
    }
    void set(int ql, int qr, T x){
        if(qr <= low || high <= ql) return;
        if(ql <= low && high <= qr){
            lset = x;
            lazy = id[0];
            val = aop(id[1], x, high - low);
        }
        else{
            push();
            l->set(ql, qr, x);
            r->set(ql, qr, x);
            val = qop(l->val, r->val);
        }
    }
    void update(int ql, int qr, T x){
        if(qr <= low || high <= ql) return;
        if(ql <= low && high <= qr){
            if(lset !=  id[2]) lset = lop(lset, x);
            else lazy = lop(lazy, x);
            val = aop(val, x, high - low);
        }
        else{
            push(), l->update(ql, qr, x), r->update(ql, qr, x);
            val = qop(l->val, r->val);
        }
    }
    T query(int ql, int qr){
        if(qr <= low || high <= ql) return id[1];
        if(ql <= low && high <= qr) return val;
        push();
        return qop(l->query(ql, qr), r->query(ql, qr));
    }
};
template<class DS, class BO, class T, int VALS_IN_EDGES = 0>
struct HLD{
    int N, root;
    vector<vector<int>> adj;
    vector<int> par, size, depth, next, pos, rpos;
    DS &tree;
    BO bin_op;
    const T id;
    HLD(int N, int root, DS &tree, BO bin_op, T id):
    N(N), root(root), adj(N), par(N, -1), size(N, 1), depth(N), next(N), pos(N), tree(tree), bin_op(bin_op), id(id){
        this->root = next[root] = root;
    }
    void insert(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs_sz(int u){
        if(par[u] != -1) adj[u].erase(find(all(adj[u]), par[u]));
        for(auto &v: adj[u]){
            par[v] = u, depth[v] = depth[u] + 1;
            dfs_sz(v);
            size[u] += size[v];
            if(size[v] > size[adj[u][0]]) swap(v, adj[u][0]);
        }
    }
    void dfs_hld(int u){
        static int t = 0;
        pos[u] = t ++;
        rpos.push_back(u);
        for(auto &v: adj[u]){
            next[v] = (v == adj[u][0] ? next[u] : v);
            dfs_hld(v);
        }
    }
    void init(){
        dfs_sz(root), dfs_hld(root);
    }
    template<class Action>
    void processpath(int u, int v, Action act){
        for(; next[u] != next[v]; v = par[next[v]]){
            if(depth[next[u]] > depth[next[v]]) swap(u, v);

            act(pos[next[v]], pos[v] + 1);
        }
        if(depth[u] > depth[v]) swap(u, v);
        act(pos[u] + VALS_IN_EDGES, pos[v] + 1);
    }
    void updatepath(int u, int v, T val, int is_update = true){
        if(is_update) processpath(u, v, [this, &val](int l, int r){tree.update(l, r, val);});
        else processpath(u, v, [this, &val](int l, int r){tree.set(l, r, val);});
    }
    void updatesubtree(int u, T val, int is_update = true){
        if(is_update) tree.update(pos[u] + VALS_IN_EDGES, pos[u] + size[u], val);
        else tree.set(pos[u] + VALS_IN_EDGES, pos[u] + size[u], val);
    }
    T querypath(int u, int v){
        T res = id;
        processpath(u, v, [this, &res](int l, int r){res = bin_op(res, tree.query(l, r));});
        return res;
    }
    T querysubtree(int u){
        return tree.query(pos[u] + VALS_IN_EDGES, pos[u] + size[u]);
    }
};
 
struct binarylift: vector<vector<int>>{
    int n, root, lg;
    vector<vector<int>> up;
    vector<int> depth;
    binarylift(int n, int root):
        n(n), root(root), lg(ceil(log2(n))), depth(n), up(n, vector<int>(lg + 1)){
        this->resize(n);
    }
    void insert(int u, int v){
        (*this)[u].push_back(v);
        (*this)[v].push_back(u);
    }
    void init(){
        dfs(root, root);
    }
    void dfs(int u, int p){
        up[u][0] = p;
        for(int i = 1; i <= lg; i ++){
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for(auto &v: (*this)[u]) if(v != p){
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    int lca(int u, int v){
        if(depth[u] < depth[v]){
            std::swap(u, v);
        }
        u = trace_up(u, depth[u] - depth[v]);
        for(int d = lg; d >= 0; d --){
            if(up[u][d] != up[v][d]){
                u = up[u][d], v = up[v][d];
            }
        }
        return u == v ? u : up[u][0];
    }
    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    int trace_up(int u, int dist){
        if(dist >= depth[u] - depth[root]){
            return root;
        }
        for(int d = lg; d >= 0; d --){
            if(dist & (1 << d)) u = up[u][d];
        }
        return u;
    }
};
const int mx = 200010;
int wt[mx],p[mx];
int n,m,q;
void solve(){
    re(n);
    m = n-1;
    fr(i,m) re(p[i]);
    fr(i,n) re(wt[i]);
    binarylift lift(n, 0);
    auto lop = [&](int x, int y){ return x^y;}; 

    auto qop = [&](int x, int y){ return x+ y;}; 

    auto aop = [&](int x, int y, int z){ return z - x;}; 

    vector<int> ID{0, 0, 0};
    lazyseg tree{0, n, lop, qop, aop, ID};
    HLD hld(n, 0, tree, qop, 0);
    fr(i,m) {
        int u = i+1;
        int v = --p[i];
        dbg(u,v);
        hld.insert(u, v);
        lift.insert(u, v);
    }
    hld.init();
    lift.init();
    fr(u,n)
        if(wt[u])
        hld.updatepath(u , u  , 1 , 1);
    re(q);
    string type ;int node;
    fr(i,q){
        re(type,node);
        node--;
        if(type[0]=='g'){
            ps(hld.querysubtree(node));
        }
        else{
            hld.updatesubtree(node,1,1);
        }
        type = "";
    }
}
int main() {
    

    solve();
}
