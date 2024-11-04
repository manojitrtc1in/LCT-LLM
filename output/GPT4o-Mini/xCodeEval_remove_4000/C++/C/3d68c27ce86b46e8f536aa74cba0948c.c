#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <algorithm>

#define MAX_N 2000000

typedef long long ll;
typedef unsigned long long ul;
typedef struct {
    int X, Y;
} pii;

typedef struct {
    int *v;
    std::set<pii> q;
    int p;
    int z;
} popu;

void add(popu *p, int t) {
    pii element = {p->v[t], t};
    p->q.insert(element);
}

void remove(popu *p, int t) {
    pii element = {p->v[t], t};
    p->q.erase(element);
}

popu create_popu(int n, int p) {
    popu p;
    p.v = (int *)malloc(n * sizeof(int));
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
    auto it = p->q.end();
    --it;
    return it->Y;
}

int is_popu(popu *p) {
    return p->v[max_el(p)] >= p->z;
}

int change(popu *p, int t, int val) {
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
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            v[i]--;
        }
        int *q = (int *)calloc(n, sizeof(int));
        pii mx = {0, 0};
        for (int i = 0; i < n; ++i) {
            ++q[v[i]];
            if (q[v[i]] > mx.X) {
                mx = (pii){q[v[i]], v[i]};
            }
        }
        int p = mx.Y;
        int **u = (int **)malloc((n + 1) * sizeof(int *));
        for (int i = 0; i <= n; ++i) {
            u[i] = (int *)malloc((n + 1) * sizeof(int));
        }
        for (int i = 0; i < n; ++i) {
            if (i != p) {
                u[q[i]][i] = i;
            }
        }
        int *uu = (int *)malloc((n + 1) * sizeof(int));
        int last = 0;
        for (int i = n; i >= 0; --i) {
            if (u[i] != NULL) {
                uu[last++] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] != p) {
                ++q[v[i]];
            }
        }
        for (int y = 0; y < std::min(n, 100); ++y) {
            if (y != p) {
                int *g = (int *)malloc((n + 1) * sizeof(int));
                memset(g, -1, (n + 1) * sizeof(int));
                int b = 0;
                for (int i = 0; i < n; ++i) {
                    if (v[i] == p) {
                        ans = std::max(ans, i - g[std::size(g) - b - 1] - 1);
                        if (b > 0) {
                            --b;
                        } else {
                            g[std::size(g)] = i;
                        }
                    } else if (v[i] == y) {
                        ++b;
                    }
                }
                ans = std::max(ans, n - g[std::size(g) - b - 1] - 1);
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
    }
    return 0;
}

int main() {
    int AMR = another_main();
    return AMR;
}
