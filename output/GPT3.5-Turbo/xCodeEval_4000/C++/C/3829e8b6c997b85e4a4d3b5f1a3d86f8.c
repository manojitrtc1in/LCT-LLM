#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 32

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int arr[N][N];
} mat;

int MOD = 1000000007;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (a * (li)b) % MOD;
}

mat mat_mul(const mat *a, const mat *b) {
    mat c;
    int i, j, t;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c.arr[i][j] = 0;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (t = 0; t < N; t++) {
                c.arr[i][j] = add(c.arr[i][j], mul(a->arr[i][t], b->arr[t][j]));
            }
        }
    }
    return c;
}

mat amat[62][N];

void solve(li n, int k) {
    int i, j, d, r, sh, rem, ans;
    mat dp;
    int num[N];
    int pr[N][N];
    for (i = 0; i < N; i++) {
        num[i] = 0;
    }
    i = 0;
    while (n > 0) {
        num[i] = n % k;
        n /= k;
        i++;
    }
    for (d = 0; d < k; d++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                amat[0][d].arr[i][j] = 0;
            }
        }
        for (i = 0; i < N; i++) {
            amat[0][d].arr[i][i] = 1;
        }
        for (i = 0; i < N; i++) {
            amat[0][d].arr[i][d] = 1;
        }
    }
    for (r = 1; r < i; r++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                pr[0][i][j] = (i == j);
            }
        }
        for (i = 0; i < k; i++) {
            mat_mul(&pr[0], &amat[r - 1][i], &pr[1]);
            for (j = 0; j < N; j++) {
                for (t = 0; t < N; t++) {
                    pr[0][j][t] = pr[1][j][t];
                }
            }
        }
        for (sh = 0; sh < k; sh++) {
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    amat[r][sh].arr[i][j] = pr[0][i][j];
                }
            }
            for (i = 0; i < k - sh; i++) {
                mat_mul(&amat[r][sh], &amat[r - 1][(i + sh) % k], &pr[1]);
                for (j = 0; j < N; j++) {
                    for (t = 0; t < N; t++) {
                        amat[r][sh].arr[j][t] = pr[1][j][t];
                    }
                }
            }
            mat_mul(&amat[r][sh], &pr[sh], &pr[1]);
            for (j = 0; j < N; j++) {
                for (t = 0; t < N; t++) {
                    amat[r][sh].arr[j][t] = pr[1][j][t];
                }
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            dp.arr[i][j] = 0;
        }
    }
    dp.arr[0][k] = 1;
    rem = 0;
    for (i = r - 1; i >= 0; i--) {
        while (num[i] > 0) {
            mat_mul(&dp, &amat[i][rem], &dp);
            rem = (rem + 1) % k;
            num[i]--;
        }
    }
    ans = 0;
    for (i = 0; i < k + 1; i++) {
        ans = add(ans, dp.arr[0][i]);
    }
    printf("%d\n", ans);
}

int main() {
    li n;
    int k;
    while (scanf("%lld%d", &n, &k) == 2) {
        solve(n, k);
    }
    return 0;
}
