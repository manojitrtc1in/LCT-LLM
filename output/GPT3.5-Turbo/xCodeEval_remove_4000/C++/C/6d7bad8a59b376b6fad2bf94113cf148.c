#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 70

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    li arr[N][N];
} mat;

int x, k, n, q;
int c[N];
pt a[N];

int cnt;

mat mat_multiply(mat a, mat b) {
    mat c;
    int i, j, k;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < cnt; j++) {
            c.arr[i][j] = INF64;
        }
    }
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < cnt; j++) {
            for (k = 0; k < cnt; k++) {
                c.arr[i][j] = fmin(c.arr[i][j], a.arr[i][k] + b.arr[k][j]);
            }
        }
    }
    return c;
}

mat mat_binpow(mat a, int b) {
    mat res;
    int i, j;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < cnt; j++) {
            res.arr[i][j] = (i == j) ? 0 : INF64;
        }
    }
    while (b) {
        if (b & 1) {
            res = mat_multiply(res, a);
        }
        a = mat_multiply(a, a);
        b >>= 1;
    }
    return res;
}

mat get(int pos, int *mx) {
    *mx = n - x - pos;
    int i, j;
    int pr[N] = {0};
    for (i = 0; i < q; i++) {
        if (pos < a[i].x) {
            if (a[i].x <= pos + k) {
                pr[a[i].x - pos - 1] = a[i].y;
                *mx = 1;
            } else {
                *mx = fmin(*mx, a[i].x - (pos + k));
            }
        }
    }
    mat res;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < cnt; j++) {
            res.arr[i][j] = INF64;
        }
    }
    for (int mask = 0; mask < (1 << k); mask++) {
        if (__builtin_popcount(mask) == x) {
            if (mask & 1) {
                for (i = 1; i <= k; i++) {
                    if (!((mask >> i) & 1)) {
                        res.arr[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1];
                    }
                }
            } else {
                res.arr[num[mask]][num[mask >> 1]] = 0;
            }
        }
    }
    return res;
}

void solve() {
    cnt = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        if (__builtin_popcount(mask) == x) {
            num[mask] = cnt++;
        }
    }

    mat cur;
    int i, j;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < cnt; j++) {
            cur.arr[i][j] = (i == j) ? 0 : INF64;
        }
    }
    for (i = 0; i < n - x;) {
        int mx;
        mat tmp = get(i, &mx);
        i += mx;
        cur = mat_multiply(cur, mat_binpow(tmp, mx));
    }

    printf("%lld\n", cur.arr[0][0]);
}

int main() {
    freopen("input.txt", "r", stdin);

    int tt = clock();

    while (scanf("%d%d%d%d", &x, &k, &n, &q) == 4) {
        int i;
        for (i = 0; i < k; i++) {
            scanf("%d", &c[i]);
        }
        for (i = 0; i < q; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
            a[i].x--;
        }
        solve();
    }

    return 0;
}
