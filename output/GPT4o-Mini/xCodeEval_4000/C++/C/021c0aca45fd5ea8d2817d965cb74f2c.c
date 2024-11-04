#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LOG 32

typedef struct {
    int X, Y;
} pii;

typedef struct {
    pii sp[MAX_LOG][MAX_N];
    int n;
} sparse;

int raz(int a, int b, int M) {
    int c = a - b;
    return c < 0 ? c + M : c;
}

int sum(int a, int b, int M) {
    int c = a + b;
    return c >= M ? c - M : c;
}

pii unite_seg(pii p1, pii p2, int n) {
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

void sparse_construct(sparse *s, pii *v, int n) {
    s->n = n;
    int r = 0;
    while ((1 << r) < n) r++;
    for (int i = 0; i < n; i++)
        s->sp[0][i] = v[i];
    for (int i = 1; i <= r; i++) {
        for (int j = 0; j < n; j++) {
            pii p1 = s->sp[i - 1][j];
            pii p2 = s->sp[i - 1][(j + (1 << (i - 1))) % n];
            s->sp[i][j] = unite_seg(p1, p2, n);
        }
    }
}

pii sparse_segment(sparse *s, int l, int r, int n) {
    if ((l == -1) || (r == -1))
        return (pii){-1, -1};
    int szz = raz(r, l, n);
    if (l == r)
        return s->sp[0][l];
    int g = 0;
    while ((1 << g) <= szz) g++;
    g--;
    return unite_seg(s->sp[g][l], s->sp[g][((r + 1 - (1 << g)) % n + n) % n], n);
}

int count_tro(int r) {
    return 32 - __builtin_clz(r);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int r[MAX_N];
    for (int i = 0; i < n; i++)
        scanf("%d", &r[i]);
    
    int zz = count_tro(n) + 1;
    sparse v[MAX_LOG];
    pii prs[MAX_N];

    for (int i = 0; i < n; i++) {
        if (r[i] >= n - 1)
            prs[i] = (pii){-1, -1};
        else
            prs[i] = unite_seg((pii){raz(i, r[i], n), i}, (pii){i, sum(i, r[i], n)}, n);
    }

    sparse_construct(&v[0], prs, n);

    for (int i = 1; i < zz; i++) {
        pii new_prs[MAX_N];
        for (int j = 0; j < n; j++) {
            pii pairr = sparse_segment(&v[i - 1], j, j, n);
            new_prs[j] = sparse_segment(&v[i - 1], pairr.X, pairr.Y, n);
        }
        sparse_construct(&v[i], new_prs, n);
    }

    for (int i = 0; i < n; i++) {
        pii my_pr = {i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = sparse_segment(&v[j], my_pr.X, my_pr.Y, n);
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
