#include <stdio.h>
#include <stdbool.h>

#define mod 998244353
#define G 3

void solve() {
    int n;
    scanf("%d", &n);
    bool g[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            g[i][j] = false;
        }
    }
    for (int m = ni(); m > 0; m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = g[y][x] = true;
    }
    for (int i = 0; i < 10; i++) {
        g[i][i] = true;
    }

    int njs[1 << 9][10];
    for (int j = 0; j < 1 << 9; j++) {
        for (int k = 0; k < 10; k++) {
            if (j << ~k >= 0) {
                int nj = j;
                for (int l = 0; l < 10; l++) {
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

    long dp[1 << 9];
    for (int i = 0; i < 1 << 9; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        long ndp[1 << 9];
        for (int j = 0; j < 1 << 9; j++) {
            ndp[j] = 0;
        }
        for (int j = 0; j < 1 << 9; j++) {
            for (int k = 0; k < 10; k++) {
                if (j << ~k >= 0) {
                    int nj = njs[j][k];
                    ndp[nj] += dp[j];
                    if (ndp[nj] >= mod) {
                        ndp[nj] -= mod;
                    }
                }
            }
        }
        for (int j = 0; j < 1 << 9; j++) {
            dp[j] = ndp[j];
        }
    }
    long ans = sum(dp) % mod;
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}
