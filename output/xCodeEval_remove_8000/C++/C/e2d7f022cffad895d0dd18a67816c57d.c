#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 309

typedef struct {
    int u, v, d;
} Op;

int adj[MAX_N][MAX_N];
int A[MAX_N], B[MAX_N], t[MAX_N];
int n, e, UP;
Op op[MAX_N*MAX_N];
int op_idx = 0;

int dfs(int u, int *path, int path_idx, int *vis) {
    if (vis[u]) return 0;
    vis[u] = 1;
    path[path_idx] = u;
    path_idx++;
    if (A[u] < B[u]) return 1;
    for (int i = 0; i < n; i++) {
        if (adj[u][i] == 1) {
            if (dfs(i, path, path_idx, vis)) return 1;
        }
    }
    path_idx--;
    return 0;
}

int main() {
    freopen("in.txt", "r", stdin);

    scanf("%d %d %d", &n, &UP, &e);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < e; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    int path[MAX_N];
    int vis[MAX_N];
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        memset(path, 0, sizeof(path));
        if (!dfs(i, path, 0, vis)) {
            printf("NO\n");
            return 0;
        }

        int f = A[i] - B[i];
        for (int j = 0; j < n-1; j++) {
            int u = path[j];
            int v = path[j+1];
            int d = f < B[v] - A[v] ? f : B[v] - A[v];
            t[j] = f - d;
            if (d > 0) {
                op[op_idx].u = u;
                op[op_idx].v = v;
                op[op_idx].d = d;
                op_idx++;
            }
        }
        for (int j = n-2; j >= 0; j--) {
            int u = path[j];
            int v = path[j+1];
            int d = t[j];
            if (d > 0) {
                op[op_idx].u = u;
                op[op_idx].v = v;
                op[op_idx].d = d;
                op_idx++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("%d\n", op_idx);
    for (int i = 0; i < op_idx; i++) {
        printf("%d %d %d\n", op[i].u, op[i].v, op[i].d);
    }

    return 0;
}
