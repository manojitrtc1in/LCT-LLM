#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    ll X, Y;
} pll;
typedef struct {
    int X, Y;
} pii;
typedef struct {
    pii *data;
    int size;
} vpii;
typedef struct {
    pll *data;
    int size;
} vpll;
typedef struct {
    ll *data;
    int size;
} vl;
typedef struct {
    double X, Y;
} pdd;

void read_vector(vpii *v) {
    for (int i = 0; i < v->size; ++i) {
        scanf("%d %d", &v->data[i].X, &v->data[i].Y);
    }
}

void read_pair(pll *p) {
    scanf("%lld %lld", &p->X, &p->Y);
}

pll add_pll(pll a, pll b) {
    return (pll){a.X + b.X, a.Y + b.Y};
}

pll subtract_pll(pll a, pll b) {
    return (pll){a.X - b.X, a.Y - b.Y};
}

ll dot_product(pll p, pll q) {
    return p.X * q.X + p.Y * q.Y;
}

ll cross_product(pll p, pll q) {
    return p.X * q.Y - p.Y * q.X;
}

double length(pll p) {
    return sqrt(dot_product(p, p));
}

double distance(pll p, pll q) {
    return length(subtract_pll(p, q));
}

bool is_rectangle(pll a, pll b, pll c, pll d) {
    pll x = subtract_pll(a, b);
    pll y = subtract_pll(b, c);
    pll z = subtract_pll(c, d);
    pll t = subtract_pll(d, a);
    return (dot_product(x, y) == 0 && dot_product(y, z) == 0 && dot_product(z, t) == 0 && dot_product(t, x) == 0);
}

bool are_parallel(pll a, pll b) {
    return (cross_product(a, b) == 0);
}

bool on_segment(pll a, pll b, pll c) {
    return (dot_product(subtract_pll(b, a), subtract_pll(c, b)) <= 0);
}

void construct_sparse(vpii *v, int n, vpii *sp) {
    int r = (int)log2(n);
    sp->data = (pii *)malloc(r * sizeof(pii));
    sp->size = n;
    for (int i = 0; i < n; ++i) {
        sp->data[i] = v->data[i];
    }
    for (int i = 1; i < r; ++i) {
        for (int j = 0; j < n; ++j) {
            pii p1 = sp[i - 1].data[j];
            pii p2 = sp[i - 1].data[(j + (1 << (i - 1))) % n];
            sp[i].data[j] = (pii){-1, -1}; // Placeholder for id1(p1, p2, n);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    vpii r;
    r.size = n;
    r.data = (pii *)malloc(n * sizeof(pii));
    read_vector(&r);

    int zz = (int)log2(n);
    vpii *v = (vpii *)malloc(zz * sizeof(vpii));
    for (int i = 0; i < zz; ++i) {
        v[i].data = (pii *)malloc(n * sizeof(pii));
        v[i].size = n;
    }

    vpii prs;
    prs.size = n;
    prs.data = (pii *)malloc(n * sizeof(pii));

    for (int i = 0; i < n; ++i) {
        if (r.data[i].Y >= n - 1) {
            prs.data[i] = (pii){-1, -1};
        } else {
            prs.data[i] = (pii){0, 0}; // Placeholder for id1(pii(raz(i, r[i], n), i), pii(i, sum(i, r[i], n)), n);
        }
    }

    construct_sparse(&prs, n, &v[0]);

    for (int i = 1; i < zz; ++i) {
        vpii id14;
        id14.size = n;
        id14.data = (pii *)malloc(n * sizeof(pii));
        for (int j = 0; j < n; ++j) {
            pii pairr = v[i - 1].data[j];
            id14.data[j] = v[i - 1].data[pairr.X]; // Placeholder for segment(pairr.X, pairr.Y);
        }
        construct_sparse(&id14, n, &v[i]);
        free(id14.data);
    }

    for (int i = 0; i < n; ++i) {
        pii my_pr = (pii){i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = v[j].data[my_pr.X]; // Placeholder for segment(my_pr.X, my_pr.Y);
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");

    for (int i = 0; i < zz; ++i) {
        free(v[i].data);
    }
    free(v);
    free(r.data);
    free(prs.data);
    return 0;
}
