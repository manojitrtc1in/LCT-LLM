#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

typedef long long li;
typedef long double ld;
typedef struct {
    int x, y;
} pt;

#define N 70
#define INF (int)(1e9)
#define INF64 (li)(1e18)
#define MOD (INF + 7)
#define EPS 1e-9
#define PI acos(-1.0)

int x, k, n, q;
int c[N];
pt a[N];

int read() {
    if (scanf("%d%d%d%d", &x, &k, &n, &q) != 4)
        return 0;
    for (int i = 0; i < k; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].x--;
    }
    return 1;
}

typedef li mat[N][N];

int cnt;

void mat_mult(mat a, mat b, mat c) {
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            c[i][j] = INF64;
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            for (int k = 0; k < cnt; k++)
                if (a[i][k] + b[k][j] < c[i][j])
                    c[i][j] = a[i][k] + b[k][j];
}

void mat_binpow(mat a, int b, mat res) {
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            res[i][j] = (i == j) ? 0 : INF64;
    while (b) {
        if (b & 1) {
            mat_mult(res, a, res);
        }
        mat_mult(a, a, a);
        b >>= 1;
    }
}

int num[1 << 8];

void get(int pos, int *mx, mat res) {
    *mx = n - x - pos;
    int pr[N] = {0};
    for (int i = 0; i < q; i++) {
        if (pos < a[i].x) {
            if (a[i].x <= pos + k) {
                pr[a[i].x - pos - 1] = a[i].y;
                *mx = 1;
            } else {
                *mx = fmin(*mx, a[i].x - (pos + k));
            }
        }
    }
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            res[i][j] = INF64;
    for (int mask = 0; mask < (1 << k); mask++) {
        if (__builtin_popcount(mask) == x) {
            if (mask & 1) {
                for (int i = 1; i <= k; i++) {
                    if (!((mask >> i) & 1))
                        res[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1];
                }
            } else {
                res[num[mask]][num[mask >> 1]] = 0;
            }
        }
    }
}

void solve() {
    cnt = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        if (__builtin_popcount(mask) == x)
            num[mask] = cnt++;
    }

    mat cur, tmp;
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            cur[i][j] = (i == j) ? 0 : INF64;
    qsort(a, q, sizeof(pt), (int (*)(const void *, const void *))compare);

    for (int i = 0; i < n - x;) {
        int mx;
        get(i, &mx, tmp);
        i += mx;
        mat_binpow(tmp, mx, tmp);
        mat_mult(cur, tmp, cur);
    }

    printf("%lld\n", cur[0][0]);
}

int compare(const void *a, const void *b) {
    return ((pt *)a)->x - ((pt *)b)->x;
}

int main() {
    freopen("input.txt", "r", stdin);
    int tt = clock();
    while (read()) {
        solve();
        fprintf(stderr, "TIME = %d\n", clock() - tt);
        tt = clock();
    }
    return 0;
}
