#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int c;
} int_abc;

typedef struct {
    int u;
    int v;
} int_uv;

void doit(const int *a, const int *b, const int *path, int_abc *res, int pos, int vol, int diff, int path_len) {
    if (pos + 1 >= path_len) return;
    int tgt = path[pos + 1];
    int before = (diff < vol - a[tgt]) ? diff : vol - a[tgt];
    int src = path[pos];
    if (before > 0) {
        res->a = src + 1;
        res->b = tgt + 1;
        res->c = before;
        res++;
    }
    doit(a, b, path, res, pos + 1, vol, diff, path_len);
    int after = diff - before;
    if (after > 0) {
        res->a = src + 1;
        res->b = tgt + 1;
        res->c = after;
        res++;
    }
}

void solve() {
    int n, vol, e;
    scanf("%d %d %d", &n, &vol, &e);

    int *a = (int*)malloc(n * sizeof(int));
    int *b = (int*)malloc(n * sizeof(int));
    int_uv *ee = (int_uv*)malloc(e * sizeof(int_uv));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &ee[i].u, &ee[i].v);
    }

    int **G = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        G[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < e; i++) {
        G[ee[i].u - 1][ee[i].v - 1] = 1;
        G[ee[i].v - 1][ee[i].u - 1] = 1;
    }

    int_uv *ee2 = (int_uv*)malloc(e * sizeof(int_uv));
    int *markers = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        markers[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] != b[j]) {
                int *path = (int*)malloc(n * sizeof(int));
                int path_len = 0;
                int src = i;
                int tgt = i;
                int diff = (a[src] - b[src] < 0) ? a[src] - b[src] : b[src] - a[src];
                while (src != tgt) {
                    path[path_len++] = tgt;
                    int found = 0;
                    for (int k = 0; k < n; k++) {
                        if (G[tgt][k] && (a[k] - b[k]) % (a[src] - b[src]) < 0) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("NO");
                        return;
                    }
                    if (a[path[0]] < b[path[0]]) {
                        for (int k = 0; k < path_len / 2; k++) {
                            int temp = path[k];
                            path[k] = path[path_len - k - 1];
                            path[path_len - k - 1] = temp;
                        }
                    }
                    doit(a, b, path, res, 0, vol, diff, path_len);
                    a[src] -= diff;
                    a[tgt] += diff;
                }
            }
        }
    }

    printf("%d\n", res - res_arr);
    for (int_abc *r = res_arr; r < res; r++) {
        printf("%d %d %d\n", r->a, r->b, r->c);
    }

    free(a);
    free(b);
    free(ee);
    for (int i = 0; i < n; i++) {
        free(G[i]);
    }
    free(G);
    free(ee2);
    free(markers);
}

int main() {
    solve();
    return 0;
}
