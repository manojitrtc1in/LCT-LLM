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

    int_uv *ee2 = (int_uv*)malloc(e * sizeof(int_uv));
    int *markers = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        ee2[i].u = ee[i].u + 1;
        ee2[i].v = ee[i].v + 1;
        markers[i] = 0;
    }

    int *path = (int*)malloc(n * sizeof(int));
    int path_len = 0;

    for (int q = 0; q < n; q++) {
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                path_len = 0;
                markers[i] = 1;
                path[path_len++] = i;
                int v = i;
                while (1) {
                    int found = 0;
                    for (int j = 0; j < e; j++) {
                        if (ee2[j].u == v && (a[ee2[j].v - 1] - b[ee2[j].v - 1]) % (a[i] - b[i]) < 0) {
                            v = ee2[j].v - 1;
                            markers[v] = 1;
                            path[path_len++] = v;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        break;
                    }
                }
                if (a[path[0]] < b[path[0]]) {
                    for (int j = 0; j < path_len / 2; j++) {
                        int temp = path[j];
                        path[j] = path[path_len - j - 1];
                        path[path_len - j - 1] = temp;
                    }
                }
                int src = path[0];
                int tgt = path[path_len - 1];
                int diff = (a[src] - b[src] < a[tgt] - b[tgt]) ? a[src] - b[src] : a[tgt] - b[tgt];
                int_abc *res = (int_abc*)malloc(n * sizeof(int_abc));
                doit(a, b, path, res, 0, vol, diff, path_len);
                a[src] -= diff;
                a[tgt] += diff;
                free(res);
            }
        }
    }

    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", res[i].a, res[i].b, res[i].c);
    }

    free(a);
    free(b);
    free(ee);
    free(ee2);
    free(markers);
    free(path);
}

int main() {
    solve();
    return 0;
}
