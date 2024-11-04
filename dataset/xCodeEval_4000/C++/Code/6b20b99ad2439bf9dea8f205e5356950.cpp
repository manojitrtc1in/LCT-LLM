
 
 
 
#include <bits/stdc++.h>
#define gc getchar
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define rep2(i, a, b) for(int i=a;i>=b;--i)
#define wipe(a, b) memset(a, b, sizeof a);
#define pb push_back
#define ff first
#define ss second
#define int int64_t

using namespace std;

typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
const int maxl = 22;
int n;
vector<pii> grafo[maxn];
int a[maxn], depth[maxn], nivel[maxn];
int tab[maxn][maxl];
 
inline int scan(){
    int n=0, x=gc(), s=1;
    for(;x<'0'||x>'9';x=gc()) if(x=='-') s=-1;
    for(;x>='0'&&x<='9';x=gc()) n = 10*n + x - '0';
    return n*s;
}
 
int gcd(int a, int b){
    return (b?gcd(b, a%b):a);
}
int pai[maxn];
int ini[maxn], fim[maxn], chain[maxn], sz[maxn], pos[maxn], what[maxn], pref[maxn], head[maxn];
int c, tam;
 
void dfs(int u) {
    sz[u] = 1;
    for(auto [v, d] : grafo[u]) {
        depth[v] = depth[u] + d;
        nivel[v] = nivel[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
}
 
void hld(int u, bool nc = true) {
    if(nc) ini[++c] = ++tam, chain[tam] = u, pos[u] = tam, what[u] = c, head[u] = u;
    else chain[++tam] = u, pos[u] = tam, what[u] = c, head[u] = head[pai[u]];
 
    int m = -1, l=-1;
    for(auto [v, d] : grafo[u]) {
        if(sz[v] > m) {
            m = sz[v];
            l = v;
        }
    }
 
    if(l != -1) hld(l, false);
    else fim[c] = tam;
 
    for(auto [v, d] : grafo[u])
        if(v != l) hld(v, true);
}
 
void mount_table() {
    for (int u = 2; u <= n; u++)
        tab[u][0] = pai[u];
 
    for (int j = 1; j < maxl; j++) {
        for (int i = 1; i <= n; i++) {
            if(tab[i][j-1] != -1) tab[i][j] = tab[ tab[i][j-1] ][j-1];
        }
    }
}
 
int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u, v);
 
    for(int i=maxl-1;i>=0;i--)
        if(nivel[ tab[u][i] ] >= nivel[ tab[v][i] ]);
 
    if(u == v) return u;
 
    for(int i=maxl-1;i>=0;i--) {
        if(tab[u][i] != -1 && tab[u][i] != tab[v][i]) {
            u = tab[u][i];
            v = tab[v][i];
        } 
    }
 
    return pai[u];
}
 
int get_v(int u) {
    int f = depth[u] - a[u];
    for(int i=maxl-1;i>=0;i--) {
        if(tab[u][i] != -1 && f <= depth[tab[u][i]])
            u = tab[u][i];
    }
 
    return u;
}
 
int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0);
    memset(tab, -1, sizeof tab);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i=2;i<=n;i++) {
        int p, x;
        cin >> p >> x;
        grafo[p].push_back({i, x});
        pai[i] = p;
    }
    dfs(1);
    hld(1);
    mount_table();
 
    for(int u=1;u<=n;u++) {
        int i = u;
        int x = get_v(i);
        if(x == i) continue;
        

        

        

        while(head[i] != head[x]) {
            pref[pos[ head[i] ]]++;
            if(i != u) pref[pos[ i ] + 1]--;
            else pref[pos[i]]--;
            i = pai[head[i]];
            

        }
        if(i == u) pref[pos[i]]--;
        else pref[pos[i]+1]--;
        pref[pos[x]]++;
    }
 
    for(int i=1;i<=c;i++) {
        for(int j=ini[i]+1;j<=fim[i];j++)
            pref[j] += pref[j-1];
    }
 
    

    

    

    

 
    

    

    

    

    

    

    for(int i=1;i<=n;i++)
        cout << pref[pos[i]] << " \n"[i==n];
    return 0;
}