#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXN 100000
#define pii struct pii
#define mp(a, b) (struct pii){a, b}
#define sz(x) (sizeof(x) / sizeof(x[0]))

struct pii {
    int X, Y;
};

int count_tro(int r) {
    return 32 - __builtin_clz(r);
}

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
        return mp(-1, -1);
    pii np1 = mp(0, raz(p1.Y, p1.X, n));
    pii np2 = mp(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1)
            return mp(-1, -1);
        else
            return mp(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
    } else {
        if (np2.X <= np1.Y + 1)
            return mp(-1, -1);
        else
            return mp(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
    }
}

struct sparse {
    int n;
    pii sp[MAXN][20]; // Assuming a maximum of 20 levels for sparse table
    void construct(pii v[], int size) {
        n = size;
        int r = count_tro(n - 1);
        for (int i = 0; i < n; ++i)
            sp[0][i] = v[i];
        for (int i = 1; i < r; ++i) {
            for (int j = 0; j < n; ++j) {
                pii p1 = sp[i - 1][j];
                pii p2 = sp[i - 1][(j + (1 << (i - 1))) % n];
                sp[i][j] = unite_seg(p1, p2, n);
            }
        }
    }
    pii segment(int l, int r) {
        if ((l == -1) || (r == -1))
            return mp(-1, -1);
        int szz = raz(r, l, n);
        if (l == r)
            return sp[0][l];
        int g = count_tro(szz) - 1;
        return unite_seg(sp[g][l], sp[g][((r + 1 - (1 << g)) % n + n) % n], n);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int r[MAXN];
    for (int i = 0; i < n; ++i)
        scanf("%d", &r[i]);
    
    int zz = count_tro(n) + 1;
    struct sparse v[zz];
    pii prs[MAXN];

    for (int i = 0; i < n; ++i) {
        if (r[i] >= n - 1)
            prs[i] = mp(-1, -1);
        else
            prs[i] = unite_seg(mp(raz(i, r[i], n), i), mp(i, sum(i, r[i], n)), n);
    }

    v[0].construct(prs, n);

    for (int i = 1; i < zz; ++i) {
        pii new_prs[MAXN];
        for (int j = 0; j < n; ++j) {
            pii pairr = v[i - 1].segment(j, j);
            new_prs[j] = v[i - 1].segment(pairr.X, pairr.Y);
        }
        v[i].construct(new_prs, n);
    }

    for (int i = 0; i < n; ++i) {
        pii my_pr = mp(i, i);
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
    return 0;
}
