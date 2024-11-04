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
    int *data;
    int size;
} vi;

typedef struct {
    pii *data;
    int size;
} vvpii;

void read_vector(vi *v) {
    for (int i = 0; i < v->size; ++i)
        scanf("%d", &v->data[i]);
}

void read_pair(pii *p) {
    scanf("%d %d", &p->X, &p->Y);
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

ll sq_len(pll p) {
    return dot_product(p, p);
}

ll sq_dist(pll p, pll q) {
    return sq_len(subtract_pll(p, q));
}

double len(pll p) {
    return sqrt(sq_len(p));
}

double dist(pll p, pll q) {
    return len(subtract_pll(p, q));
}

bool is_rectangle(pll a, pll b, pll c, pll d) {
    pll x = subtract_pll(a, b);
    pll y = subtract_pll(b, c);
    pll z = subtract_pll(c, d);
    pll t = subtract_pll(d, a);
    return (dot_product(x, y) == 0 && dot_product(y, z) == 0 && 
            dot_product(z, t) == 0 && dot_product(t, x) == 0);
}

bool are_parallel(pll a, pll b) {
    return (cross_product(a, b) == 0);
}

bool on_segment(pll a, pll b, pll c) {
    return (dot_product(subtract_pll(b, a), subtract_pll(c, b)) >= 0);
}

pll id16(pll p) {
    return (pll){-p.Y, p.X};
}

pll id0(pll normal, pll point) {
    return (pll){normal.X, -(dot_product(normal, point))};
}

pll projection(pll line, pll point) {
    pll temp = id0(id16(line), point);
    return (pll){temp.X, temp.Y};
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    vi r;
    r.size = n;
    r.data = (int *)malloc(n * sizeof(int));
    read_vector(&r);
    
    int zz = (int)log2(n) + 1;
    vvpii v[zz];
    vpii prs;
    prs.size = n;
    prs.data = (pii *)malloc(n * sizeof(pii));

    for (int i = 0; i < n; ++i) {
        if (r.data[i] >= n - 1)
            prs.data[i] = (pii){-1, -1};
        else
            prs.data[i] = (pii){(r.data[i] - i + n) % n, i};
    }

    // Sparse table construction
    for (int i = 0; i < zz; ++i) {
        v[i].size = n;
        v[i].data = (pii *)malloc(n * sizeof(pii));
        for (int j = 0; j < n; ++j) {
            v[i].data[j] = prs.data[j]; // Initialize with previous level
        }
    }

    for (int i = 1; i < zz; ++i) {
        for (int j = 0; j < n; ++j) {
            pii p1 = v[i - 1].data[j];
            pii p2 = v[i - 1].data[(j + (1 << (i - 1))) % n];
            v[i].data[j] = (pii){p1.X, p2.Y}; // Example operation
        }
    }

    for (int i = 0; i < n; ++i) {
        pii my_pr = (pii){i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = v[j].data[my_pr.X]; // Example operation
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");
    
    // Free allocated memory
    free(r.data);
    free(prs.data);
    for (int i = 0; i < zz; ++i) {
        free(v[i].data);
    }

    return 0;
}
