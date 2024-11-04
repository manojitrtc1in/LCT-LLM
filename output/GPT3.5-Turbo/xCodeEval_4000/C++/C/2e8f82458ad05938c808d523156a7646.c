#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int X;
    int Y;
} Pair;

typedef struct {
    int X;
    int Y;
} Pii;

typedef struct {
    int X;
    int Y;
} Vpii;

typedef struct {
    int X;
    int Y;
} Vvpii;

typedef struct {
    double X;
    double Y;
} Pdd;

typedef struct {
    int X;
    int Y;
} Vi;

typedef struct {
    int X;
    int Y;
} Vvi;

typedef struct {
    int X;
    int Y;
} Vb;

typedef struct {
    int X;
    int Y;
} Vvb;

typedef struct {
    long long X;
    long long Y;
} Pll;

typedef struct {
    long long X;
    long long Y;
} Vpll;

typedef struct {
    long long X;
    long long Y;
} Pbl;

typedef struct {
    long long X;
    long long Y;
} Vpbl;

typedef struct {
    double X;
    double Y;
} Pd;

typedef struct {
    double X;
    double Y;
} Vd;

typedef struct {
    double X;
    double Y;
} Vpdd;

typedef struct {
    int n;
    Vvpii sp;
} Sparse;

int count_tro(int r) {
    return 32 - __builtin_clz(r);
}

Pii unite_seg(Pii p1, Pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1))
        return (Pii) {-1, -1};
    Pii np1 = (Pii) {0, raz(p1.Y, p1.X, n)};
    Pii np2 = (Pii) {raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)};
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1)
            return (Pii) {-1, -1};
        else
            return (Pii) {sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
    } else {
        if (np2.X <= np1.Y + 1)
            return (Pii) {-1, -1};
        else
            return (Pii) {sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)};
    }
}

Sparse construct_sparse(Vpii v) {
    Sparse s;
    s.n = v.size();
    int r = count_tro(s.n - 1);
    s.sp.resize(r, Vpii(s.n));
    for (int i = 0; i < s.n; ++i)
        s.sp.front()[i] = v[i];
    for (int i = 1; i < r; ++i) {
        for (int j = 0; j < s.n; ++j) {
            Pii p1 = s.sp[i - 1][j];
            Pii p2 = s.sp[i - 1][(j + (1 << (i - 1))) % s.n];
            s.sp[i][j] = unite_seg(p1, p2, s.n);
        }
    }
    return s;
}

Pii segment(Sparse s, int l, int r) {
    if ((l == -1) || (r == -1))
        return (Pii) {-1, -1};
    int szz = raz(r, l, s.n);
    if (l == r)
        return s.sp[0][l];
    int g = count_tro(szz) - 1;
    return unite_seg(s.sp[g][l], s.sp[g][((r + 1 - (1 << g)) % s.n + s.n) % s.n], s.n);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    Vi r;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        r.push_back(x);
    }
    int zz = count_tro(n + 1) - 1;
    Vpii prs;
    for (int i = 0; i < n; ++i) {
        if (r[i] >= n - 1)
            prs.push_back((Pii) {-1, -1});
        else
            prs.push_back(unite_seg((Pii) {raz(i, r[i], n), i}, (Pii) {i, sum(i, r[i], n)}, n));
    }
    Sparse v[zz];
    v[0] = construct_sparse(prs);
    for (int i = 1; i < zz; ++i) {
        Vpii new_prs;
        for (int j = 0; j < n; ++j) {
            Pii pairr = segment(v[i - 1], j, j);
            new_prs.push_back(segment(v[i - 1], pairr.X, pairr.Y));
        }
        v[i] = construct_sparse(new_prs);
    }
    for (int i = 0; i < n; ++i) {
        Pii my_pr = (Pii) {i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            Pii new_pr = segment(v[j], my_pr.X, my_pr.Y);
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
