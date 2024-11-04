#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long LL;

LL ncr[40][40];
LL ans[30][30];

int main() {
    LL R, C;
    scanf("%lld %lld", &R, &C);
    char str[R+C];
    scanf("%s", str);
    LL n = R + C;
    LL blockarea[n][n];
    LL totalarea[n+1][n+1];
    for(LL a = 0; a < n; a++) {
        for(LL b = 0; b < n; b++) {
            if(b > a) {
                blockarea[a][b] = 0;
                continue;
            }
            if(b == 0 || b == a) {
                blockarea[a][b] = 1;
                continue;
            }
            blockarea[a][b] = ncr[a][R-1] * ncr[b][R-1];
        }
    }
    LL revarea[n+1][n+1];
    for(LL a = 0; a <= n; a++) {
        for(LL b = 0; b <= n; b++) {
            totalarea[a][b] = 0;
            if(a == 0 || b == 0) continue;
            totalarea[a][b] = totalarea[a][b-1] + totalarea[a-1][b] - totalarea[a-1][b-1];
            totalarea[a][b] += blockarea[a-1][b-1];
        }
    }
    for(LL a = 0; a <= n; a++) {
        for(LL b = 0; b <= n; b++) {
            revarea[a][b] = totalarea[n][n] - totalarea[n-a][n] - totalarea[n][n-b] + totalarea[n-a][n-b];
        }
    }
    LL d = (2 * n - 1) < (n + R - 2) ? (2 * n - 1) : (n + R - 2);
    LL dp[n+1][n+1][revarea[n][n] + 1];
    LL bp[n+1][n+1][revarea[n][n] + 1];
    memset(dp, 0, sizeof(dp));
    memset(bp, 0, sizeof(bp));
    dp[0][0][0] = 1;
    bp[0][0][0] = 1;
    LL best = ans[R][C];
    LL m1 = (-best + totalarea[n][n]) / 2;
    LL m2 = totalarea[n][n] - m1;
    LL bestfreq = 0;
    for(LL x = 0; x <= n; x++) {
        for(LL y = 0; y < n; y++) {
            if(x + y + 1 <= d && str[x+y] != 'B') {
                for(LL i = 0; i <= revarea[n][y+1]; i++) {
                    dp[x][y+1][i] += dp[x][y][i];
                }
            }
            if(x + y + 1 <= 2 * n - d && str[n-x+n-y-1] != 'B') {
                for(LL i = 0; i <= revarea[n][n] - revarea[n-x][n-(y+1)]; i++) {
                    bp[x][y+1][i] += bp[x][y][i];
                }
            }
        }
        if(x == n) continue;
        for(LL y = 0; y <= n; y++) {
            if(x + y + 1 <= d && str[x+y] != 'A') {
                LL newarea = totalarea[x+1][y] - totalarea[x][y];
                for(LL i = 0; i <= revarea[x+1][n] - revarea[x][n]; i++) {
                    dp[x+1][y][i + newarea] += dp[x][y][i];
                }
            }
            if(x + y + 1 <= 2 * n - d && str[n-x+n-y-1] != 'A') {
                LL id0 = totalarea[n-x][n-y] - totalarea[n-x-1][n-y];
                for(LL i = 0; i <= revarea[n-x][n-y] - revarea[n-x-1][n-y]; i++) {
                    bp[x+1][y][i + id0] += bp[x][y][i];
                }
            }
            if(x + y + 1 <= d) memset(dp[x][y], 0, sizeof(dp[x][y]));
            if(x + y + 1 <= 2 * n - d) memset(bp[x][y], 0, sizeof(bp[x][y]));
        }
    }
    for(LL x = 0; x <= n; x++) {
        LL y = d - x;
        if(y < 0 || y > n) continue;
        for(LL i = 0; i <= revarea[n][y]; i++) {
            for(LL j = 0; j <= revarea[n][n] - revarea[n-x][n-y]; j++) {
                bestfreq += dp[x][y][i] * bp[n-x][n-y][m1-i-j];
                if(m1 != m2) bestfreq += dp[x][y][i] * bp[n-x][n-y][m2-i-j];
            }
        }
    }
    printf("%lld\n", bestfreq);
    return 0;
}
