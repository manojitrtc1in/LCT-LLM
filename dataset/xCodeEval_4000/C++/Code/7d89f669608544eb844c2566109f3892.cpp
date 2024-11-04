#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <stdio.h>
#include <unordered_map>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC diagnostic ignored "-Wunused-const-variable"


using namespace std;

#ifndef __clang__
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#endif

#define ll long long
#define int long long
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define MP make_pair
int max(int a, int b) { return (a>b) ? a : b;}
int min(int a, int b) { return (a<b) ? a : b;}
double max(double a, double b) { return (a>b) ? a : b;}
double min(double a, double b) { return (a<b) ? a : b;}
void ain(vi &a) { for(int i=0;i<a.size();i++) cin>>a[i]; }
int Ceil(double d) { return ((int)d == d) ? d : d+1; }
int gcd(int a, int b) { return (a==0) ? b : gcd(b%a, a); }

template<class T, class V> ostream& operator<< (ostream& out, const pair<T, V>& p) {out << p.first << ", " << p.second; return out;}
template<class T> ostream& operator<< (ostream &out, const vector<T>& c){ for(int i : c) out << i << ' '; return out;}
template<class T, class V> ostream& operator<< (ostream& out, const map<T, V> m) {out << "{"; for(auto p : m) out << p.first << ": " << p.second <<", "; out << "}"; return out; }
template<class T> ostream& operator<< (ostream& out, const set<T> m) {out << "{"; for(T p : m) out << p <<", "; out << "}"; return out; }



int power(long long x, int y, int p){
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


vi sieve(int n) {
    vi prime(n+1, 1);
    

    prime[0] = prime[1] = 0;
    for(int i=2;i<=n;i++) {
        if(prime[i]) {
            for(int j=i*i;j<=n;j+=i) {prime[j] = 0;}
        }
    }
    return prime;
}

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.assign(n + 1, -1);
        size.assign(n + 1, -1);
        for(int i=0;i<n+1;i++){
            make_set(i);
        }
    }

    void make_set(int u){
        parent[u] = u;
        size[u] = 1;
    }

    int find_set(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find_set(parent[u]);
    }

    void union_sets(int u, int v){
        int leader_u = find_set(u);
        int leader_v = find_set(v);

        if(leader_u != leader_v){
            if(size[leader_u] < size[leader_v]){
                swap(leader_u, leader_v);
            }
            parent[leader_v] = leader_u;
            size[leader_u] += size[leader_v];
        }
    }
};





    







































































































































































































class lazySegtree {
    int size;
    vector<int> tree, lazy;
public:
    lazySegtree(int sz, int initVal);
    
    void propogate(int x, int lx, int rx);

    void update(int l, int r, int v, int x, int lx, int rx);
    void update(int l, int r, int v);

    int query(int l, int r, int x, int lx, int rx);
    int query(int l, int r);
    void printTree();
    void build(vector<int>& a, int x, int lx, int rx, int initVal);
};

lazySegtree::lazySegtree(int sz, int initVal = 0) {
    size = 1;
    while(size < sz) size *= 2;
    tree.assign(2*size, initVal);
    lazy.assign(2*size, initVal);
}

void lazySegtree::build(vector<int>& a, int x, int lx, int rx, int initVal = 0){
    size = 1;
    while(size < a.size()) size *= 2;
    tree.assign(2*size, initVal);
    lazy.assign(2*size, initVal);
    if(lx + 1 == rx) {
        tree[x] = a[lx];
        return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2*x + 1, lx, mid);
    build(a, 2*x + 2, mid, rx);
    tree[x] = tree[2*x + 1] + tree[2*x + 2];   
}

void lazySegtree::propogate(int x, int lx, int rx) {
    tree[x] += lazy[x] * (rx - lx);
    if(rx != lx + 1) {
        lazy[2*x + 1] += lazy[x];
        lazy[2*x + 2] += lazy[x];
    }
    lazy[x] = 0;
}

void lazySegtree::update(int l, int r, int v, int x, int lx, int rx) {
    propogate(x, lx, rx);
    if (lx >= r || rx <= l) return;
    if (lx >= l && rx <= r) {
        tree[x] += v * (rx - lx);
        if (rx - lx != 1) {
            lazy[2*x + 1] += v;
            lazy[2*x + 2] += v;
        }
        return;
    }
    int mid = (rx + lx) / 2;
    update(l, r, v, 2 * x + 1, lx, mid);
    update(l, r, v, 2 * x + 2, mid, rx);
    tree[x] = tree[2*x + 1] + tree[2*x + 2];
}

int lazySegtree::query(int l, int r, int x, int lx, int rx) {
    propogate(x, lx, rx);
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r)
        return tree[x];
    
    int mid = (rx + lx) / 2;
    int ans = query(l, r, 2 * x + 1, lx, mid);
    ans += query(l, r, 2 * x + 2, mid, rx);
    return ans;
}

int lazySegtree::query(int l, int r) {
    return query(l, r+1, 0, 0, size);
}

void lazySegtree::update(int l, int r, int v) {
    update(l, r+1, v, 0, 0, size);
}
void lazySegtree::printTree() {
    for(int i=0;i<2*size;i++) {
        cout << tree[i] << ' ';
    }
    cout << endl;
}

class HeavyLightDecomposition {
public:
    vector<int> parent, head, depth, heavy, pos;
    const int Log = 20;
    vvi par;
    vector<vector<int> > a; 

    lazySegtree ST;
    int cc_pos;

    int dfs(int c) {
        int size = 1, max_child_size = 0;
        

        if(c){
            par[c][0] = parent[c];
            for(int i=1;i<=Log;i++) {
                par[c][i] = par[par[c][i-1]][i-1];
            }
        }
        for(int v : a[c]) {
            if(v == parent[c]) continue;
            parent[v] = c; depth[v] = depth[c] + 1;
            int child_size = dfs(v);
            size += child_size;
            if (child_size > max_child_size) {
                max_child_size = child_size;
                heavy[c] = v;
            }
        }
        return size;
    }

    void decompose(int c, int h) {
        head[c] = h;
        pos[c] = cc_pos++;
        if (heavy[c] != -1)
            decompose(heavy[c], h);
        for(int v : a[c]) {
            if(v!=parent[c] && v!=heavy[c]) {
                decompose(v, v);
            }
        }
    }

    void init(vector<vector<int> >& a){
        cc_pos = 0;
        int n = a.size();
        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        pos.assign(n, 0);
        head.assign(n, 0);
        par.assign(n, vi(Log+1, 0));
        

        

        dfs(0);
        

        decompose(0, 0);
    }

    HeavyLightDecomposition(vector<vector<int> >& a) : a(a), ST(a.size() + 1) {
        init(a);
    }

    int query(int a, int b) {
        int res = 0;
        for(; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[b]] < depth[head[a]]) swap(a, b);
            

            res += ST.query(pos[head[b]], pos[b]);

            

        }
        if(depth[a] > depth[b]) swap(a, b);
        

        

        res += ST.query(pos[a], pos[b]);
        return res;
    }

    void update(int a, int b, int v) {
        for(; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[b]] < depth[head[a]]) swap(a, b);
            ST.update(pos[head[b]], pos[b], v);

        }
        if(depth[a] > depth[b]) swap(a, b);
        ST.update(pos[a], pos[b], v);
    }
    int lca(int a, int b) {
        for(; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[b]] < depth[head[a]]) swap(a, b);
            

        }
        if(depth[a] > depth[b]) swap(a, b);
        return a;
        

    }
};





#include <cmath>
const int N = 6010;
vi fac, rfac;
const int M = 998244353;
void buildFac(int n = N){
    fac.assign(n, 0); rfac.assign(n, 0);
    fac[0] = rfac[0] = 1;
    for(int i=1;i<n;i++){
        fac[i] = (i*fac[i-1]) % M;
        rfac[i] = power(fac[i], M-2, M);
    }
}

int nCr(int n, int r){
    if(r < 0 || n < 0 || r > n) return 0;
    return (((fac[n]*rfac[r])%M)*rfac[n-r])%M;
}
int n,k;
string s;
vi pre, P;
int dp[N];
bool pos =0;
int f(int ind) {
    

    

    

    

    if(P[ind] == n) {
        int options = n-ind+1;
        if(pre[n] - pre[ind-1] == k) pos = 1;
        return nCr(options, pre[n] - pre[ind-1]) % M;
    }
    if(dp[ind] != -1) return dp[ind];
    int ans = f(ind + 1) % M;
    if(s[ind] == '1') {
        int num1 = k; 

        int options = P[ind] - ind;
        ans += nCr(options, num1);
        ans %= M;
    }
    else {
        int num1 =  k-1; 

        int options = P[ind] - ind;
        ans += nCr(options, num1);
        ans %= M;
    }
    return dp[ind] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    buildFac();
    
    

    

    memset(dp, -1, sizeof(dp));
    cin>>n>>k;
    cin>>s;
    s = "#" + s;
    

    pre.assign(n+1, 0);
    for(int i=1;i<=n;i++) {
        pre[i] = pre[i-1];
        if(s[i] == '1') pre[i]++;
    }
    if(pre[n] < k || k==0) {
        cout << 1 << endl; return 0;
    }
    int ptr = 1;
    P.assign(n+1, 0);
    for(int i=1;i<=n;i++) {
        while(ptr <= n and pre[ptr]-pre[i-1]<=k) ptr++;
        P[i] = ptr-1;
    }
    vi d(n+1,0);
    int sum =0;
    for(int i=1;i<=n;i++) {
        if(P[i] == n) {
            sum += nCr(P[i] - i+1, k);
            sum%=M;
            break;
        }
        else {
            int n1 = (s[i] == '1'?k:k-1);
            sum += nCr(P[i] - i, n1);
            sum%=M;
        }
    }
    cout << sum << endl;
    

    

    

    

    

    

    

    

    

    

    return 0;
}
#pragma GCC diagnostic pop

