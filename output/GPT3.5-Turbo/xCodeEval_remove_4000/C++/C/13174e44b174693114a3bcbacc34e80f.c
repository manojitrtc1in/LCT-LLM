#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int X;
    int Y;
} pii;

pii id1(const pii* p1, const pii* p2, const int* n) {
    if ((p1->X == -1) || (p2->X == -1))
        return (pii){-1, -1};
    pii np1 = {0, raz(p1->Y, p1->X, n)};
    pii np2 = {raz(p2->X, p1->X, n), raz(p2->Y, p1->X, n)};
    if (np2.X <= np2.Y) {
        if (np2.Y == *n - 1)
            return (pii){-1, -1};
        else
            return (pii){sum(np1.X, p1->X, n), sum(max(np1.Y, np2.Y), p1->X, n)};
    } else {
        if (np2.X <= np1.Y + 1)
            return (pii){-1, -1};
        else
            return (pii){sum(np2.X, p1->X, n), sum(max(np1.Y, np2.Y), p1->X, n)};
    }
}

void construct(vpii* sp, int* n, int* r, int* idx, int* h) {
    int i, j, g;
    for (i = 0; i < *n; ++i)
        sp[0][i] = r[i];
    for (i = 1; i < *r; ++i) {
        for (j = 0; j < *n; ++j) {
            pii p1 = sp[i - 1][j];
            pii p2 = sp[i - 1][(j + (1 << (i - 1))) % *n];
            sp[i][j] = id1(&p1, &p2, n);
        }
    }
    for (i = 0; i < *n; ++i)
        h[i] = idx[i];
    for (i = 1; i < *r; ++i) {
        for (j = 0; j < *n; ++j) {
            if (sz(h) >= 2) {
                if (are_parallel(a[h.back()], *temp))
                    h.pop_back();
                while ((sz(h) >= 3) && npocs(a[h[sz(h) - 2]], a[h.back()], *temp))
                    h.pop_back();
            }
            h.push_back(*it);
        }
    }
}

void segment(pii* sp, int* l, int* r, int* n, int* szz, int* g) {
    if ((*l == -1) || (*r == -1))
        return (pii){-1, -1};
    *szz = raz(*r, *l, *n);
    if (*l == *r)
        return sp[0][*l];
    *g = id17(*szz) - 1;
    return id1(&sp[*g][*l], &sp[*g][((*r + 1 - (1 << *g)) % *n + *n) % *n], *n);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int zz = id17(n);
    vpii v(zz);
    vpii prs(n);
    int r[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &r[i]);
        if (r[i] >= n - 1)
            prs[i] = (pii){-1, -1};
        else
            prs[i] = id1((pii){raz(i, r[i], n), i}, (pii){i, sum(i, r[i],n)}, n);
    }
    construct(prs, &n, &zz, r, v);
    for (int i = 0; i < n; ++i) {
        pii my_pr = {i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = segment(v[j], &my_pr.X, &my_pr.Y, &n, &szz, &g);
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
