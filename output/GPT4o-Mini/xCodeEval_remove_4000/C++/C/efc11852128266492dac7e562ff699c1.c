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
    int* data;
    int size;
} vi;
typedef struct {
    pii* data;
    int size;
} vpii;
typedef struct {
    vpii* data;
    int size;
} vvpii;

void init_vi(vi* v, int size) {
    v->data = (int*)malloc(size * sizeof(int));
    v->size = size;
}

void init_vpii(vpii* v, int size) {
    v->data = (pii*)malloc(size * sizeof(pii));
    v->size = size;
}

void init_vvpii(vvpii* v, int size) {
    v->data = (vpii*)malloc(size * sizeof(vpii));
    for (int i = 0; i < size; i++) {
        init_vpii(&v->data[i], 0);
    }
    v->size = size;
}

void free_vi(vi* v) {
    free(v->data);
}

void free_vpii(vpii* v) {
    free(v->data);
}

void free_vvpii(vvpii* v) {
    for (int i = 0; i < v->size; i++) {
        free_vpii(&v->data[i]);
    }
    free(v->data);
}

int raz(int a, int b, int M) {
    int c = a - b;
    return c < 0 ? c + M : c;
}

int sum(int a, int b, int M) {
    int c = a + b;
    return c >= M ? c - M : c;
}

int id17(int r) {
    return 32 - __builtin_clz(r);
}

pii id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1))
        return (pii){-1, -1};
    pii np1 = {0, raz(p1.Y, p1.X, n)};
    pii np2 = {raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)};
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1)
            return (pii){-1, -1};
        else
            return (pii){sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
    } else {
        if (np2.X <= np1.Y + 1)
            return (pii){-1, -1};
        else
            return (pii){sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
    }
}

struct sparse {
    int n;
    vvpii sp;
    void construct(vpii v) {
        n = v.size;
        int r = id17(n - 1);
        init_vvpii(&sp, r);
        for (int i = 0; i < n; i++)
            sp.data[0].data[i] = v.data[i];
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < n; j++) {
                pii p1 = sp.data[i - 1].data[j];
                pii p2 = sp.data[i - 1].data[(j + (1 << (i - 1))) % n];
                sp.data[i].data[j] = id1(p1, p2, n);
            }
        }
    }
    pii segment(int l, int r) {
        if ((l == -1) || (r == -1))
            return (pii){-1, -1};
        int szz = raz(r, l, n);
        if (l == r)
            return sp.data[0].data[l];
        int g = id17(szz) - 1;
        return id1(sp.data[g].data[l], sp.data[g].data[((r + 1 - (1 << g)) % n + n) % n], n);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    vi r;
    init_vi(&r, n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &r.data[i]);
    }
    int zz = id17(n) - 1;
    sparse* v = (sparse*)malloc(zz * sizeof(sparse));
    vpii prs;
    init_vpii(&prs, n);

    for (int i = 0; i < n; i++) {
        if (r.data[i] >= n - 1)
            prs.data[i] = (pii){-1, -1};
        else
            prs.data[i] = id1((pii){raz(i, r.data[i], n), i}, (pii){i, sum(i, r.data[i], n)}, n);
    }

    v[0].construct(prs);

    for (int i = 1; i < zz; i++) {
        vpii id14;
        init_vpii(&id14, n);
        for (int j = 0; j < n; j++) {
            pii pairr = v[i - 1].segment(j, j);
            id14.data[j] = v[i - 1].segment(pairr.X, pairr.Y);
        }
        v[i].construct(id14);
        free_vpii(&id14);
    }

    for (int i = 0; i < n; i++) {
        pii my_pr = {i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = v[j].segment(my_pr.X, my_pr.Y);
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");

    free_vi(&r);
    for (int i = 0; i < zz; i++) {
        free_vvpii(&v[i].sp);
    }
    free(v);
    return 0;
}
