#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int X;
    int Y;
} pii;

typedef struct {
    int n;
    pii** sp;
} sparse;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int abs(int a) {
    return (a < 0) ? -a : a;
}

int raz(int a, int b, int n) {
    int c = a - b;
    return (c < 0) ? c + n : c;
}

int sum(int a, int b, int n) {
    int c = a + b;
    return (c >= n) ? c - n : c;
}

int id17(int r) {
    int count = 0;
    while (r > 0) {
        r >>= 1;
        count++;
    }
    return 32 - count;
}

pii id1(pii p1, pii p2, int n) {
    if (p1.X == -1 || p2.X == -1) {
        return (pii) {-1, -1};
    }
    pii np1 = {0, raz(p1.Y, p1.X, n)};
    pii np2 = {raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)};
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            return (pii) {-1, -1};
        } else {
            return (pii) {sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            return (pii) {-1, -1};
        } else {
            return (pii) {sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
        }
    }
}

void construct(sparse* s, pii* v, int n) {
    s->n = n;
    int r = id17(n - 1);
    s->sp = (pii**) malloc(r * sizeof(pii*));
    for (int i = 0; i < r; i++) {
        s->sp[i] = (pii*) malloc(n * sizeof(pii));
    }
    for (int i = 0; i < n; i++) {
        s->sp[0][i] = v[i];
    }
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < n; j++) {
            pii p1 = s->sp[i - 1][j];
            pii p2 = s->sp[i - 1][(j + (1 << (i - 1))) % n];
            s->sp[i][j] = id1(p1, p2, n);
        }
    }
}

pii segment(sparse* s, int l, int r) {
    if (l == -1 || r == -1) {
        return (pii) {-1, -1};
    }
    int szz = raz(r, l, s->n);
    if (l == r) {
        return s->sp[0][l];
    }
    int g = id17(szz) - 1;
    return id1(s->sp[g][l], s->sp[g][((r + 1 - (1 << g)) % s->n + s->n) % s->n], s->n);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int* r = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    int zz = id17(n) + 1;
    sparse* v = (sparse*) malloc(zz * sizeof(sparse));
    for (int i = 0; i < zz; i++) {
        v[i].sp = NULL;
    }
    pii* prs = (pii*) malloc(n * sizeof(pii));
    for (int i = 0; i < n; i++) {
        if (r[i] >= n - 1) {
            prs[i] = (pii) {-1, -1};
        } else {
            prs[i] = id1((pii) {raz(i, r[i], n), i}, (pii) {i, sum(i, r[i], n)}, n);
        }
    }
    construct(&v[0], prs, n);
    for (int i = 1; i < zz; i++) {
        pii* id14 = (pii*) malloc(n * sizeof(pii));
        for (int j = 0; j < n; j++) {
            pii pairr = segment(&v[i - 1], j, j);
            id14[j] = segment(&v[i - 1], pairr.X, pairr.Y);
        }
        construct(&v[i], id14, n);
        free(id14);
    }
    for (int i = 0; i < n; i++) {
        pii my_pr = {i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; j--) {
            pii new_pr = segment(&v[j], my_pr.X, my_pr.Y);
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");
    free(r);
    for (int i = 0; i < zz; i++) {
        for (int j = 0; j < v[i].n; j++) {
            free(v[i].sp[j]);
        }
        free(v[i].sp);
    }
    free(v);
    free(prs);
    return 0;
}
