#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
    } else {
        int* v = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            v[i]--;
        }
        int* q = (int*)calloc(n, sizeof(int));
        int* qq = (int*)calloc(n, sizeof(int));
        int mx_val = 0;
        int mx_idx = 0;
        for (int i = 0; i < n; i++) {
            q[v[i]]++;
            if (q[v[i]] > mx_val) {
                mx_val = q[v[i]];
                mx_idx = v[i];
            }
        }
        int p = mx_idx;
        int** u = (int**)malloc((n + 1) * sizeof(int*));
        for (int i = 0; i <= n; i++) {
            u[i] = NULL;
        }
        for (int i = 0; i < n; i++) {
            if (i != p) {
                u[q[i]] = (int*)realloc(u[q[i]], (qq[q[i]] + 1) * sizeof(int));
                u[q[i]][qq[q[i]]] = i;
                qq[q[i]]++;
            }
        }
        int* uu = (int*)malloc(n * sizeof(int));
        int uu_idx = 0;
        for (int i = n; i >= 0; i--) {
            if (qq[i] > 0) {
                uu[uu_idx] = i;
                uu_idx++;
            }
        }
        int last = 0;
        int** leftmost = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            leftmost[i] = (int*)malloc((q[i] + 1) * sizeof(int));
            for (int j = 0; j <= q[i]; j++) {
                leftmost[i][j] = n + 1;
            }
            leftmost[i][0] = 0;
        }
        int ans = 0;
        for (int y = 0; y < n && y < 100; y++) {
            if (y != p) {
                int* g = (int*)malloc((n + 1) * sizeof(int));
                for (int i = 0; i <= n; i++) {
                    g[i] = -1;
                }
                int b = 0;
                for (int i = 0; i < n; i++) {
                    if (v[i] == p) {
                        ans = ans > (i - g[n - b - 1] - 1) ? ans : (i - g[n - b - 1] - 1);
                        if (b > 0) {
                            b--;
                        } else {
                            g[n - b] = i;
                        }
                    } else if (v[i] == y) {
                        b++;
                    }
                }
                ans = ans > (n - g[n - b - 1] - 1) ? ans : (n - g[n - b - 1] - 1);
                free(g);
            }
        }
        printf("%d\n", ans);
        free(v);
        free(q);
        free(qq);
        for (int i = 0; i <= n; i++) {
            free(u[i]);
        }
        free(u);
        free(uu);
        for (int i = 0; i < n; i++) {
            free(leftmost[i]);
        }
        free(leftmost);
    }
    return 0;
}
