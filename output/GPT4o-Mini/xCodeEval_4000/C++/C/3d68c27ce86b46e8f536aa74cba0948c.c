#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int x, y;
} pii;

typedef struct {
    int *v;
    int *q;
    int p;
    int z;
} popu;

void add(popu *p, int t) {
    p->q[t] = p->v[t];
}

void remove(popu *p, int t) {
    p->q[t] = -1; // Mark as removed
}

popu create_popu(int n, int p) {
    popu p;
    p.v = (int *)malloc(n * sizeof(int));
    p.q = (int *)malloc(n * sizeof(int));
    p.p = p;
    p.z = 0;
    for (int i = 0; i < n; ++i) {
        if (i != p) {
            add(&p, i);
        }
    }
    return p;
}

int max_el(popu *p) {
    int max_idx = 0;
    for (int i = 1; i < MAX_N; ++i) {
        if (p->q[i] > p->q[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

bool is_popu(popu *p) {
    return p->v[max_el(p)] >= p->z;
}

void change(popu *p, int t, int val) {
    if (t == p->p) {
        p->z += val;
    } else {
        remove(p, t);
        p->v[t] += val;
        add(p, t);
    }
}

int another_main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
    } else {
        int *v = (int *)malloc(n * sizeof(int));
        int *q = (int *)calloc(n, sizeof(int));
        pii mx = {0, 0};
        
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            --v[i];
            ++q[v[i]];
            if (q[v[i]] > mx.x) {
                mx.x = q[v[i]];
                mx.y = v[i];
            }
        }
        
        int p = mx.y;
        int **u = (int **)malloc((n + 1) * sizeof(int *));
        for (int i = 0; i <= n; ++i) {
            u[i] = (int *)malloc(n * sizeof(int));
        }
        
        for (int i = 0; i < n; ++i) {
            if (i != p) {
                u[q[i]][i] = i;
            }
        }
        
        int *uu = (int *)malloc(n * sizeof(int));
        int uu_size = 0;
        for (int i = n; i >= 0; --i) {
            if (u[i][0] != 0) {
                uu[uu_size++] = i;
            }
        }
        
        int last = 0;
        int **leftmost = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; ++i) {
            leftmost[i] = (int *)malloc((q[i] + 1) * sizeof(int));
            leftmost[i][0] = n + 1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] != p) {
                ++q[v[i]];
            }
        }
        
        for (int y = 0; y < (n < 100 ? n : 100); ++y) {
            if (y != p) {
                int *g = (int *)malloc((n + 1) * sizeof(int));
                memset(g, -1, (n + 1) * sizeof(int));
                int b = 0;
                for (int i = 0; i < n; ++i) {
                    if (v[i] == p) {
                        ans = fmax(ans, i - g[n - b - 1] - 1);
                        if (b > 0) {
                            --b;
                        } else {
                            g[n + 1] = i;
                        }
                    } else if (v[i] == y) {
                        ++b;
                    }
                }
                ans = fmax(ans, n - g[n - b - 1] - 1);
                free(g);
            }
        }
        
        printf("%d\n", ans);
        free(v);
        free(q);
        for (int i = 0; i <= n; ++i) {
            free(u[i]);
        }
        free(u);
        free(uu);
        for (int i = 0; i < n; ++i) {
            free(leftmost[i]);
        }
        free(leftmost);
    }
    return 0;
}

int main() {
    int AMR = another_main();
    return AMR;
}
