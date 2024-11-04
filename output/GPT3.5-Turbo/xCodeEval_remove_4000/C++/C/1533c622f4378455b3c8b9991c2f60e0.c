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

pii make_pii(int x, int y) {
    pii* p = (pii*)malloc(sizeof(pii));
    p->X = x;
    p->Y = y;
    return *p;
}

sparse* make_sparse(int n) {
    sparse* s = (sparse*)malloc(sizeof(sparse));
    s->n = n;
    s->sp = (pii**)malloc(n * sizeof(pii*));
    for (int i = 0; i < n; i++) {
        s->sp[i] = (pii*)malloc(n * sizeof(pii));
    }
    return s;
}

void construct(sparse* s, pii* v, int n) {
    int r = 0;
    int temp = n - 1;
    while (temp) {
        r++;
        temp >>= 1;
    }
    for (int i = 0; i < n; i++) {
        s->sp[0][i] = v[i];
    }
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < n; j++) {
            pii p1 = s->sp[i - 1][j];
            pii p2 = s->sp[i - 1][(j + (1 << (i - 1))) % n];
            s->sp[i][j] = make_pii(-1, -1);
            if (p1.X != -1 && p2.X != -1) {
                int np1X = 0;
                int np1Y = p1.Y - p1.X;
                int np2X = p2.X - p1.X;
                int np2Y = p2.Y - p1.X;
                if (np2X <= np2Y) {
                    if (np2Y != n - 1) {
                        s->sp[i][j].X = (np1X + p1.X) % n;
                        s->sp[i][j].Y = max(np1Y, np2Y) + p1.X;
                    }
                }
                else {
                    if (np2X > np1Y + 1) {
                        s->sp[i][j].X = (np2X + p1.X) % n;
                        s->sp[i][j].Y = max(np1Y, np2Y) + p1.X;
                    }
                }
            }
        }
    }
}

pii segment(sparse* s, int l, int r) {
    if (l == -1 || r == -1) {
        return make_pii(-1, -1);
    }
    int szz = (r - l + s->n) % s->n;
    if (l == r) {
        return s->sp[0][l];
    }
    int g = 0;
    int temp = szz;
    while (temp) {
        g++;
        temp >>= 1;
    }
    int new_r = (r + 1 - (1 << g) + s->n) % s->n;
    return make_pii(s->sp[g][l].X, s->sp[g][new_r].Y);
}

int id17(int r) {
    int ans = 0;
    while (r) {
        ans++;
        r >>= 1;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int* r = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    int zz = id17(n - 1) + 1;
    sparse** v = (sparse**)malloc(zz * sizeof(sparse*));
    for (int i = 0; i < zz; i++) {
        v[i] = make_sparse(n);
    }
    pii* prs = (pii*)malloc(n * sizeof(pii));
    for (int i = 0; i < n; i++) {
        if (r[i] >= n - 1) {
            prs[i] = make_pii(-1, -1);
        }
        else {
            prs[i] = segment(v[0], (i - r[i] + n) % n, i);
        }
    }
    construct(v[0], prs, n);
    for (int i = 1; i < zz; i++) {
        pii* id14 = (pii*)malloc(n * sizeof(pii));
        for (int j = 0; j < n; j++) {
            id14[j] = segment(v[i - 1], j, j);
        }
        construct(v[i], id14, n);
    }
    for (int i = 0; i < n; i++) {
        pii my_pr = make_pii(i, i);
        int ans = 0;
        for (int j = zz - 1; j >= 0; j--) {
            pii new_pr = segment(v[j], my_pr.X, my_pr.Y);
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
