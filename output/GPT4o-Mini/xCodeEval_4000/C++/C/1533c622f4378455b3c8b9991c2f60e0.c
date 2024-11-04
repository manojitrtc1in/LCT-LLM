#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXN 100000
#define pii struct PairInt
#define vpii struct VectorPairInt

struct PairInt {
    int X, Y;
};

struct VectorPairInt {
    struct PairInt *data;
    int size;
};

void init_vector_pair_int(struct VectorPairInt *v, int size) {
    v->data = (struct PairInt *)malloc(size * sizeof(struct PairInt));
    v->size = size;
}

void free_vector_pair_int(struct VectorPairInt *v) {
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

struct PairInt unite_seg(struct PairInt p1, struct PairInt p2, int n) {
    if ((p1.X == -1) || (p2.X == -1))
        return (struct PairInt){-1, -1};
    struct PairInt np1 = {0, raz(p1.Y, p1.X, n)};
    struct PairInt np2 = {raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)};
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1)
            return (struct PairInt){-1, -1};
        else
            return (struct PairInt){sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
    } else {
        if (np2.X <= np1.Y + 1)
            return (struct PairInt){-1, -1};
        else
            return (struct PairInt){sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
    }
}

struct Sparse {
    int n;
    struct VectorPairInt *sp;
};

void construct_sparse(struct Sparse *s, struct VectorPairInt *v) {
    s->n = v->size;
    int r = (int)(log2(s->n)) + 1;
    s->sp = (struct VectorPairInt *)malloc(r * sizeof(struct VectorPairInt));
    for (int i = 0; i < r; i++) {
        init_vector_pair_int(&s->sp[i], s->n);
    }
    for (int i = 0; i < s->n; i++)
        s->sp[0].data[i] = v->data[i];
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < s->n; j++) {
            struct PairInt p1 = s->sp[i - 1].data[j];
            struct PairInt p2 = s->sp[i - 1].data[(j + (1 << (i - 1))) % s->n];
            s->sp[i].data[j] = unite_seg(p1, p2, s->n);
        }
    }
}

struct PairInt segment(struct Sparse *s, int l, int r) {
    if ((l == -1) || (r == -1))
        return (struct PairInt){-1, -1};
    int szz = raz(r, l, s->n);
    if (l == r)
        return s->sp[0].data[l];
    int g = (int)(log2(szz));
    return unite_seg(s->sp[g].data[l], s->sp[g].data[((r + 1 - (1 << g)) % s->n + s->n) % s->n], s->n);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int *r = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    int zz = (int)(log2(n)) + 1;
    struct Sparse *v = (struct Sparse *)malloc(zz * sizeof(struct Sparse));
    struct VectorPairInt prs;
    init_vector_pair_int(&prs, n);

    for (int i = 0; i < n; i++) {
        if (r[i] >= n - 1)
            prs.data[i] = (struct PairInt){-1, -1};
        else
            prs.data[i] = unite_seg((struct PairInt){raz(i, r[i], n), i}, (struct PairInt){i, sum(i, r[i], n)}, n);
    }

    construct_sparse(&v[0], &prs);

    for (int i = 1; i < zz; i++) {
        struct VectorPairInt new_prs;
        init_vector_pair_int(&new_prs, n);
        for (int j = 0; j < n; j++) {
            struct PairInt pairr = segment(&v[i - 1], j, j);
            new_prs.data[j] = segment(&v[i - 1], pairr.X, pairr.Y);
        }
        construct_sparse(&v[i], &new_prs);
        free_vector_pair_int(&new_prs);
    }

    for (int i = 0; i < n; i++) {
        struct PairInt my_pr = {i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            struct PairInt new_pr = segment(&v[j], my_pr.X, my_pr.Y);
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");

    for (int i = 0; i < zz; i++) {
        free_vector_pair_int(&v[i].sp[0]);
        free(v[i].sp);
    }
    free(v);
    free(r);
    free_vector_pair_int(&prs);
    return 0;
}
