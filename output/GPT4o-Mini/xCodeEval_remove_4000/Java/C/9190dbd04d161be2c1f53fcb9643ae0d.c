#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define MAXN 10
#define MAXMASK (1 << 9)

long dp[MAXMASK];
long njs[MAXMASK][MAXN];
int g[MAXN][MAXN];

long sum(long *a, int size) {
    long ret = 0;
    for (int i = 0; i < size; i++) {
        ret += a[i];
    }
    return ret;
}

void solve() {
    int n;
    scanf("%d", &n);
    
    memset(g, 0, sizeof(g));
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = g[y][x] = 1;
    }
    for (int i = 0; i < MAXN; i++) g[i][i] = 1;

    for (int j = 0; j < MAXMASK; j++) {
        for (int k = 0; k < MAXN; k++) {
            if (j & (1 << k)) {
                int nj = j;
                for (int l = 0; l < MAXN; l++) {
                    if (g[k][l]) {
                        if (k > l) {
                            nj |= (1 << l);
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
        long ndp[MAXMASK] = {0};
        for (int j = 0; j < MAXMASK; j++) {
            for (int k = 0; k < MAXN; k++) {
                if (j & (1 << k)) {
                    int nj = njs[j][k];
                    ndp[nj] += dp[j];
                    if (ndp[nj] >= MOD) ndp[nj] -= MOD;
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    long ans = sum(dp, MAXMASK) % MOD;
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}
