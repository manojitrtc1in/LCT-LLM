#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3005
#define pil struct Pair
#define MAX_LL 0x3f3f3f3f3f3f3f3fLL

pil {
    int first;
    long long second;
};

struct edge {
    int v;
    struct edge *next;
} pool[3 * N], *h[N];

int n, m, top;
int a[N], size[N];
pil f[N][N], tmp_f[N], nil = {0, -MAX_LL};

void addedge(int u, int v) {
    struct edge *tmp = &pool[++top];
    tmp->v = v;
    tmp->next = h[u];
    h[u] = tmp;
}

pil add(pil x, pil y) {
    pil result;
    result.first = x.first + y.first;
    result.second = x.second + y.second;
    return result;
}

void dfs(int u, int pre) {
    size[u] = 1;
    f[u][1] = (pil){0, 1LL * a[u]};
    for (struct edge *tmp = h[u]; tmp; tmp = tmp->next) {
        int v = tmp->v;
        if (v == pre) continue;
        dfs(v, u);
        for (int i = 1; i <= size[u]; i++) {
            tmp_f[i] = f[u][i];
            f[u][i] = nil;
        }
        for (int i = 1; i <= size[u]; i++) {
            for (int j = 1; j <= size[v]; j++) {
                if (i + j - 1 > m) break;
                f[u][i + j] = add(f[u][i + j], tmp_f[i]);
                f[u][i + j].second += (f[v][j].second > 0) ? 1 : 0;
                f[u][i + j - 1] = add(f[u][i + j - 1], tmp_f[i]);
            }
        }
        size[u] += size[v];
    }
}

void init() {
    int x, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
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
            f[i][j] = nil;
        }
    }
    dfs(1, 0);
    printf("%d\n", f[1][m].first + (f[1][m].second > 0));
    top = -1;
    for (int i = 1; i <= n + 1; i++) h[i] = NULL;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) init();
    return 0;
}
