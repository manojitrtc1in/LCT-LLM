#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
typedef struct {
    ll X, Y;
} pll;
typedef struct {
    int X, Y;
} pii;
typedef struct {
    pii* data;
    int size;
} vpii;
typedef struct {
    pll* data;
    int size;
} vpll;
typedef struct {
    ll* data;
    int size;
} vl;
typedef struct {
    int* data;
    int size;
} vi;

void read_vector(vi* v) {
    for (int i = 0; i < v->size; ++i) {
        scanf("%d", &v->data[i]);
    }
}

void read_pair(pll* p) {
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

int are_parallel(pll a, pll b) {
    return cross_product(a, b) == 0;
}

int id15(pll a, pll b) {
    return are_parallel(a, b) && (dot_product(a, b) >= 0);
}

int id3(pll a, pll b, pll c, pll d) {
    return id15(a, b) && id15(c, d);
}

int id1(pii p1, pii p2, int n) {
    if (p1.X == -1 || p2.X == -1) return -1;
    pii np1 = {0, (p1.Y - p1.X + n) % n};
    pii np2 = {(p2.X - p1.X + n) % n, (p2.Y - p1.X + n) % n};
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) return -1;
        return (np1.X + p1.X) % n + max(np1.Y, np2.Y);
    } else {
        if (np2.X <= np1.Y + 1) return -1;
        return (np2.X + p1.X) % n + max(np1.Y, np2.Y);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    vi r;
    r.data = (int*)malloc(n * sizeof(int));
    r.size = n;
    read_vector(&r);

    int zz = 32 - __builtin_clz(n + 1) - 1;
    vpii prs;
    prs.data = (pii*)malloc(n * sizeof(pii));
    prs.size = n;

    for (int i = 0; i < n; ++i) {
        if (r.data[i] >= n - 1)
            prs.data[i] = (pii){-1, -1};
        else
            prs.data[i] = (pii){(i - r.data[i] + n) % n, (i + r.data[i]) % n};
    }

    // Sparse table construction and other logic would go here...

    for (int i = 0; i < n; ++i) {
        pii my_pr = {i, i};
        int ans = 0;
        // Logic for calculating ans would go here...
        printf("%d ", ans + 1);
    }
    printf("\n");

    free(r.data);
    free(prs.data);
    return 0;
}
