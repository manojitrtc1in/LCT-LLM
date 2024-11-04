#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3005
#define MAX_LL 0x3f3f3f3f3f3f3f3fll

typedef struct edge {
    int v;
    struct edge *next;
} edge;

edge pool[3 * N];
edge *h[N];
int n, m, top;
int a[N], size[N];
long long f[N][N][2], tmp_f[N][2], nil[2] = {0, -MAX_LL};

void addedge(int u, int v) {
    edge *tmp = &pool[++top];
    tmp->v = v;
    tmp->next = h[u];
    h[u] = tmp;
}

void dfs(int u, int pre) {
    size[u] = 1;
    f[u][1][0] = 0;
    f[u][1][1] = 1LL * a[u];
    
    for (edge *tmp = h[u]; tmp; tmp = tmp->next) {
        int v = tmp->v;
        if (v == pre) continue;
        dfs(v, u);
        
        for (int i = 1; i <= size[u]; i++) {
            tmp_f[i][0] = f[u][i][0];
            tmp_f[i][1] = f[u][i][1];
            f[u][i][0] = 0;
            f[u][i][1] = -MAX_LL;
        }
        
        for (int i = 1; i <= size[u]; i++) {
            for (int j = 1; j <= size[v]; j++) {
                if (i + j - 1 > m) break;
                f[u][i + j][0] = f[u][i + j][0] > (tmp_f[i][0] + f[v][j][0] + (f[v][j][1] > 0)) ? f[u][i + j][0] : (tmp_f[i][0] + f[v][j][0] + (f[v][j][1] > 0));
                f[u][i + j][1] = f[u][i + j][1] > (tmp_f[i][1] + f[v][j][1]) ? f[u][i + j][1] : (tmp_f[i][1] + f[v][j][1]);
                f[u][i + j - 1][0] = f[u][i + j - 1][0] > (tmp_f[i][0] + f[v][j][0]) ? f[u][i + j - 1][0] : (tmp_f[i][0] + f[v][j][0]);
                f[u][i + j - 1][1] = f[u][i + j - 1][1] > (tmp_f[i][1] + f[v][j][1]) ? f[u][i + j - 1][1] : (tmp_f[i][1] + f[v][j][1]);
            }
        }
        size[u] += size[v];
    }
}

void init() {
    int x, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[i] = x - a[i];
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            f[i][j][0] = nil[0];
            f[i][j][1] = nil[1];
        }
    }
    dfs(1, 0);
    printf("%lld\n", f[1][m][0] + (f[1][m][1] > 0));
    top = -1;
    for (int i = 1; i <= n + 1; i++) {
        h[i] = NULL;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        init();
    }
    return 0;
}
