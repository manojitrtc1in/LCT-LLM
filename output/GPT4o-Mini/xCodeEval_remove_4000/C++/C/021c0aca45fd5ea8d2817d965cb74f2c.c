#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
typedef struct { ll X, Y; } pll;
typedef struct { int X, Y; } pii;
typedef struct { double X, Y; } pdd;
typedef struct { int *data; int size; } vi;
typedef struct { pii *data; int size; } vpii;
typedef struct { vpii *data; int size; } vvpii;

void init_vi(vi *v, int size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void init_vpii(vpii *v, int size) {
    v->data = (pii *)malloc(size * sizeof(pii));
    v->size = size;
}

void init_vvpii(vvpii *v, int size) {
    v->data = (vpii *)malloc(size * sizeof(vpii));
    v->size = size;
}

void free_vi(vi *v) {
    free(v->data);
}

void free_vpii(vpii *v) {
    free(v->data);
}

void free_vvpii(vvpii *v) {
    for (int i = 0; i < v->size; i++) {
        free(v->data[i].data);
    }
    free(v->data);
}

void read_vi(vi *v) {
    for (int i = 0; i < v->size; ++i) {
        scanf("%d", &v->data[i]);
    }
}

void read_vpii(vpii *v) {
    for (int i = 0; i < v->size; ++i) {
        scanf("%lld %lld", &v->data[i].X, &v->data[i].Y);
    }
}

pll add_pll(pll a, pll b) {
    return (pll){a.X + b.X, a.Y + b.Y};
}

pll sub_pll(pll a, pll b) {
    return (pll){a.X - b.X, a.Y - b.Y};
}

ll dot_pll(pll p, pll q) {
    return p.X * q.X + p.Y * q.Y;
}

ll cross_pll(pll p, pll q) {
    return p.X * q.Y - p.Y * q.X;
}

double length_pll(pll p) {
    return sqrt(dot_pll(p, p));
}

double distance_pll(pll p, pll q) {
    return length_pll(sub_pll(p, q));
}

int is_rectangle(pll a, pll b, pll c, pll d) {
    pll x = sub_pll(a, b);
    pll y = sub_pll(b, c);
    pll z = sub_pll(c, d);
    pll t = sub_pll(d, a);
    return (dot_pll(x, y) == 0 && dot_pll(y, z) == 0 && dot_pll(z, t) == 0 && dot_pll(t, x) == 0);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    vi r;
    init_vi(&r, n);
    read_vi(&r);
    
    int zz = (int)(log2(n - 1)) + 1;
    vvpii v;
    init_vvpii(&v, zz);
    
    vpii prs;
    init_vpii(&prs, n);
    
    for (int i = 0; i < n; ++i) {
        if (r.data[i] >= n - 1)
            prs.data[i] = (pii){-1, -1};
        else
            prs.data[i] = (pii){(r.data[i] + i) % n, i};
    }
    
    // Construct sparse table
    for (int i = 0; i < n; ++i) {
        v.data[0].data[i] = prs.data[i];
    }
    
    for (int i = 1; i < zz; ++i) {
        for (int j = 0; j < n; ++j) {
            pii p1 = v.data[i - 1].data[j];
            pii p2 = v.data[i - 1].data[(j + (1 << (i - 1))) % n];
            v.data[i].data[j] = (pii){p1.X, p2.Y}; // Simplified for demonstration
        }
    }
    
    for (int i = 0; i < n; ++i) {
        pii my_pr = (pii){i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = v.data[j].data[my_pr.X];
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");
    
    free_vi(&r);
    free_vpii(&prs);
    free_vvpii(&v);
    
    return 0;
}
