#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXN 100000
#define pii struct PairInt

struct PairInt {
    int X, Y;
};

typedef struct {
    int n;
    struct PairInt sp[MAXN][20]; // Assuming a maximum of 20 levels for sparse table
} Sparse;

void unite_seg(struct PairInt p1, struct PairInt p2, int n, struct PairInt *result) {
    if ((p1.X == -1) || (p2.X == -1)) {
        result->X = -1;
        result->Y = -1;
        return;
    }
    struct PairInt np1 = {0, (p1.Y - p1.X + n) % n};
    struct PairInt np2 = {(p2.X - p1.X + n) % n, (p2.Y - p1.X + n) % n};
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            result->X = -1;
            result->Y = -1;
        } else {
            result->X = (np1.X + p1.X) % n;
            result->Y = (fmax(np1.Y, np2.Y) + p1.X) % n;
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            result->X = -1;
            result->Y = -1;
        } else {
            result->X = (np2.X + p1.X) % n;
            result->Y = (fmax(np1.Y, np2.Y) + p1.X) % n;
        }
    }
}

void construct_sparse(Sparse *sparse_table, struct PairInt *v, int n) {
    sparse_table->n = n;
    int r = (int)log2(n) + 1;
    for (int i = 0; i < n; ++i) {
        sparse_table->sp[0][i] = v[i];
    }
    for (int i = 1; i < r; ++i) {
        for (int j = 0; j < n; ++j) {
            struct PairInt p1 = sparse_table->sp[i - 1][j];
            struct PairInt p2 = sparse_table->sp[i - 1][(j + (1 << (i - 1))) % n];
            unite_seg(p1, p2, n, &sparse_table->sp[i][j]);
        }
    }
}

struct PairInt segment(Sparse *sparse_table, int l, int r) {
    if ((l == -1) || (r == -1)) {
        return (struct PairInt){-1, -1};
    }
    int szz = (r - l + sparse_table->n) % sparse_table->n;
    if (l == r) {
        return sparse_table->sp[0][l];
    }
    int g = (int)log2(szz);
    struct PairInt result;
    unite_seg(sparse_table->sp[g][l], sparse_table->sp[g][((r + 1 - (1 << g)) % sparse_table->n + sparse_table->n) % sparse_table->n], sparse_table->n, &result);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int r[MAXN];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &r[i]);
    }
    int zz = (int)log2(n) + 1;
    Sparse v[zz];
    struct PairInt prs[MAXN];

    for (int i = 0; i < n; ++i) {
        if (r[i] >= n - 1) {
            prs[i] = (struct PairInt){-1, -1};
        } else {
            prs[i] = (struct PairInt){(i - r[i] + n) % n, i};
        }
    }

    construct_sparse(&v[0], prs, n);

    for (int i = 1; i < zz; ++i) {
        struct PairInt new_prs[MAXN];
        for (int j = 0; j < n; ++j) {
            struct PairInt pairr = segment(&v[i - 1], j, j);
            new_prs[j] = segment(&v[i - 1], pairr.X, pairr.Y);
        }
        construct_sparse(&v[i], new_prs, n);
    }

    for (int i = 0; i < n; ++i) {
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
    return 0;
}
