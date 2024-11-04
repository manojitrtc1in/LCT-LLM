

using namespace std;

const int N = 3e3 + 5;


struct edge {
    int v;
    edge *next;
} pool[3 * N], *h[N];

int n, m, top;
int a[N], size[N];
pil f[N][N], tmp_f[N], nil = make_pair(0, -0x3f3f3f3f3f3f3f3fll);

void addedge(int u, int v) {
    edge *tmp = &pool[++top];
    tmp -> v = v; tmp -> next = h[u]; h[u] = tmp;
}

inline pil operator + (pil x, pil y) {
    return make_pair(x.first + y.first, x.second + y.second);
}

void dfs(int u, int pre) {
    size[u] = 1;
    f[u][1] = make_pair(0, 1ll * a[u]);
    for(edge *tmp = h[u]; tmp; tmp = tmp -> next) {
        int v = tmp -> v;
        if(v == pre) continue;
        dfs(v, u);
        for(int i = 1; i <= size[u]; i++) tmp_f[i] = f[u][i], f[u][i] = make_pair(0, -0x3f3f3f3f3f3f3f3fll);
        for(int i = 1; i <= size[u]; i++) {
            for(int j = 1; j <= size[v]; j++) {
                if(i + j - 1 > m) break;
                f[u][i + j] = max(f[u][i + j], tmp_f[i] + f[v][j] + make_pair(f[v][j].second > 0, -f[v][j].second));
                f[u][i + j - 1] = max(f[u][i + j - 1], tmp_f[i] + f[v][j]);
            }
        }
        size[u] += size[v];
    }   
}

void init() {
    int x, y;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[i] = x - a[i];
    }
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    for(int i = 1; i <= n + 1; i++) for(int j = 1; j <= m + 1; j++) f[i][j] = nil;
    dfs(1, 0);
    printf("%d\n", f[1][m].first + (f[1][m].second > 0));
    top = -1;
    for(int i = 1; i <= n + 1; i++) h[i] = NULL;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) init();
    return 0;
}

