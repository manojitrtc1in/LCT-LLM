#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define G 3
#define MAX_N 10
#define MAX_MASK (1 << 9)

long big = (LONG_MAX / MOD / MOD - 1) * MOD * MOD;

long njs[MAX_MASK][MAX_N];
long dp[MAX_MASK];

long sum(long* a, int size) {
    long ret = 0;
    for (int i = 0; i < size; i++) {
        ret += a[i];
    }
    return ret;
}

long* mul(long* a, long* b, int len_a, int len_b, int* result_len) {
    if (len_a == 0 && len_b == 0) {
        *result_len = 0;
        return NULL;
    }
    if (len_a + len_b >= 300) {
        // Call NTT convolution (not implemented here)
    } else {
        long* c = (long*)calloc(len_a + len_b - 1, sizeof(long));
        for (int i = 0; i < len_a; i++) {
            for (int j = 0; j < len_b; j++) {
                c[i + j] += a[i] * b[j];
                if (c[i + j] >= big) c[i + j] -= big;
            }
        }
        for (int i = 0; i < len_a + len_b - 1; i++) {
            c[i] %= MOD;
        }
        *result_len = len_a + len_b - 1;
        return c;
    }
    return NULL;
}

void solve() {
    int n;
    scanf("%d", &n);
    int g[MAX_N][MAX_N] = {0};
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = g[y][x] = 1;
    }
    for (int i = 0; i < MAX_N; i++) g[i][i] = 1;

    for (int j = 0; j < (1 << 9); j++) {
        for (int k = 0; k < MAX_N; k++) {
            if (j & (1 << k)) {
                int nj = j;
                for (int l = 0; l < MAX_N; l++) {
                    if (g[k][l]) {
                        if (k > l) {
                            nj |= 1 << l;
                        }
                    } else {
                        nj &= ~(1 << l);
                    }
                }
                njs[j][k] = nj;
            }
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        long ndp[MAX_MASK] = {0};
        for (int j = 0; j < (1 << 9); j++) {
            for (int k = 0; k < MAX_N; k++) {
                if (j & (1 << k)) {
                    int nj = njs[j][k];
                    ndp[nj] += dp[j];
                    if (ndp[nj] >= MOD) ndp[nj] -= MOD;
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    long ans = sum(dp, MAX_MASK) % MOD;
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}
