








using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

int V, Q;
vector<ii> g[100000];
vector<int> q[100000];
map<ii, int> lca;
int ans[99999], d[100000], dsu[100000], lcaClass[100000];
bool vis[100000];

int find(const int &x) {
    return (dsu[x] == x ? x : dsu[x] = find(dsu[x]));
}

void dfs1(const int &v) {
    vis[v] = true;
    lcaClass[v] = v;
    for(const ii &to : g[v]) {
        if(!vis[to.X]) {
            dfs1(to.X);
            lcaClass[(dsu[find(v)] = find(to.X))] = v;
        }
    }
    for(const int &u : q[v])
        if(vis[u]) {
            lca[{u, v}] = lcaClass[find(u)];
            lca[{v, u}] = lcaClass[find(u)];
        }
}

void dfs2(const int &v, const int &p = -1) {
    for(const ii &to : g[v]) {
        if(to.X != p) {
            dfs2(to.X, v);
            d[v] += d[to.X];
            ans[to.Y] = d[to.X];
        }
    }
}

void solve() {
    scanf("%d", &V);
    for(int i = 0;i < V - 1;i++) {
        dsu[i] = i;
        int u, v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[v].push_back(ii(u, i));
        g[u].push_back(ii(v, i));
    }
    dsu[V - 1] = V - 1;
    scanf("%d", &Q);
    for(int i = 0;i < Q;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;b--;
        q[a].push_back(b);
        q[b].push_back(a);
    }
    dfs1(0);
    for(int a = 0;a < V;a++) {
        for(const int &b : q[a]) {
            d[a]++;
            d[b]++;
            d[lca[{a, b}]] -= 2;
        }
    }
    dfs2(0);
    for(int i = 0;i < V - 1;i++)
        printf("%d ", ans[i] / 2);
}

int main() {
    if(ONLINE_JUDGE) { 

    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}