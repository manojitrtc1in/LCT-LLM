

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
#include <unistd.h>

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
template<class T> ostream& operator<< (ostream &out, const vector<T>& c){ for(const T& i : c) out << i << ' '; return out;}
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





    






















































































































































































































































































































































































































class segTree {
private:
    int size;
    

    void setUtil(int ind, int v, int x, int lx, int rx);
    int ansUtil(int l, int r, int x, int lx, int rx);
    static int sum(int a, int b) {return a + b;}
    vector<int> tree;
    int IDENTITY;
    int (*combine)(int, int);
public:
    segTree(int sz);
    segTree(int sz, int (*comb)(int, int), int IDE = 0);
    inline int getSize() { return size; }
    void set(int ind, int v);
    int ans(int l, int r);
};
segTree::segTree(int sz) {
    combine = sum;
    IDENTITY = 0;
    size = 1;
    while(size < sz) size *= 2;
    tree.assign(2*size, 0);
}
segTree::segTree(int sz, int (*comb)(int, int), int IDE ) {
    combine = comb;
    IDENTITY = IDE;
    size = 1;
    while(size < sz) size *= 2;
    tree.assign(2*size, 0);
}
void segTree::setUtil(int ind, int v, int x, int lx, int rx) {
    if(rx == lx + 1) {
        tree[x] = v;
        return;
    }
    int mid = (lx + rx) / 2;
    if(ind < mid) setUtil(ind, v, 2*x+1, lx, mid);
    else setUtil(ind, v, 2*x+2, mid, rx);
    tree[x] = min(tree[2*x+1], tree[2*x+2]);
}
void segTree::set(int ind, int v) {
    setUtil(ind, v, 0, 0, size);
}
int segTree::ansUtil(int l, int r, int x, int lx, int rx) {
    if(rx-1 < l || lx > r) return 0;
    if(lx >= l && rx-1 <= r) return tree[x];
    int mid = (lx + rx) / 2;
    return min(ansUtil(l, r, 2*x+1, lx, mid), ansUtil(l, r, 2*x+2, mid, rx));
}
int segTree::ans(int l, int r){
    return ansUtil(l, r, 0, 0, size);
}


























































































































vvi a;
int n,m;
int s,t;
const int M = 1e9+7;
pair<vi, vi> bfs(vvi& a, int s, int t, int b=0) {
    vi vis(a.size(), 0);
    vis[s] = 1;
    vi dis(a.size(), 1e9), num(a.size(), 0);
    dis[s] = 0; num[s] = 1;
    queue<int> q;
    q.push(s);
    int sub =0;
    while(!q.empty()){
        

        

        

        

        

        int cur = q.front();
        q.pop();
        for(int v : a[cur]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = 1;
                dis[v] = dis[cur] + 1;
                num[v] += num[cur];
            }
            else if(dis[cur] == dis[v] - 1) {
                num[v] += num[cur];
            }
            num[v] %= M;
        }
    }
    

    return {dis, num};
}
vvi glob;
void dfs(int cur, int t, int lft, vi& sub) {
    if(lft < 0) return;
    sub.pb(cur);
    if(cur == t) {
        glob.pb(sub);
        

        

    }
    for(int v : a[cur]) {
        dfs(v, t, lft-1, sub);
    }
    sub.pop_back();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    

    

    int _; cin>>_;
    while(_--){
    cin>>n>>m;
    cin>>s>>t;
    s--; t--;
    a.assign(n, vi());
    vii edges(m, {0,0});
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        a[u].pb(v); a[v].pb(u);
        edges[i] = {u, v};
    }
    

    

    

    

    auto [ds, ns] = bfs(a, s, t);
    auto [dt, nt] = bfs(a, t, s);
    int ans =0;
    

    

    for(int i=0;i<m;i++) {
        auto [u, v] = edges[i];
        int o = ans;
        if(ds[u] == ds[v]  and ds[u] + dt[v] == ds[t]) {
            

            ans += (ns[u] * nt[v])%M;
        }
        

        swap(u, v);
        if(ds[u] == ds[v] and ds[u] + dt[v] == ds[t]) {
            

            ans += (ns[u] * nt[v])%M;
        }
        ans%=M;
        

        

        

        

    }
    

    

    

    cout << (ans+ns[t])%M << endl;
    }
    

    return 0;
}
#pragma GCC diagnostic pop

