#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 309
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int u, v, d;
} Op;

int A[MAX_N], B[MAX_N], t[MAX_N];
int adj[MAX_N][MAX_N], n, e, UP;
Op op[MAX_N * MAX_N];
int op_count = 0;

int dfs(int u, int vis[], int path[], int *path_size) {
    if (vis[u]) return 0;
    vis[u] = 1;
    path[(*path_size)++] = u;
    if (A[u] < B[u]) return 1;

    for (int i = 0; i < n; i++) {
        if (adj[u][i]) {
            int v = i;
            if (dfs(v, vis, path, path_size)) return 1;
        }
    }
    (*path_size)--;
    return 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%d %d %d", &n, &UP, &e);

    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    for (int i = 0; i < e; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        while (A[i] > B[i]) {
            int vis[MAX_N] = {0};
            int path[MAX_N], path_size = 0;

            if (!dfs(i, vis, path, &path_size)) {
                puts("NO");
                return 0;
            }

            int f = MIN(A[i] - B[i], B[path[path_size - 1]] - A[path[path_size - 1]]);

            for (int j = 0; j < path_size - 1; j++) {
                int u = path[j], v = path[j + 1];
                int d = MIN(f, A[u], UP - A[v]);
                t[j] = f - d;
                if (d) {
                    op[op_count++] = (Op){u, v, d};
                }
            }
            for (int j = path_size - 2; j >= 0; j--) {
                int u = path[j], v = path[j + 1];
                int d = t[j];
                if (d) {
                    op[op_count++] = (Op){u, v, d};
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] != B[i]) {
            puts("NO");
            return 0;
        }
    }

    printf("%d\n", op_count);
    for (int i = 0; i < op_count; i++) {
        printf("%d %d %d\n", op[i].u, op[i].v, op[i].d);
    }

    return 0;
}
