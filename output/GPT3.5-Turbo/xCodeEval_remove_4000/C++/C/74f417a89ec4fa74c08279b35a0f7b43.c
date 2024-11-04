#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 40

typedef long long LL;

LL ncr[MAX_N][MAX_N];
LL ans[30][30];

int main() {
    LL R, C;
    scanf("%lld %lld", &R, &C);
    char str[R + C];
    scanf("%s", str);

    for (LL a = 0; a < 40; a++) {
        for (LL b = 0; b < 40; b++) {
            if (b > a) {
                ncr[a][b] = 0;
                continue;
            }
            if (b == 0 || b == a) {
                ncr[a][b] = 1;
                continue;
            }
            ncr[a][b] = ncr[a - 1][b - 1] + ncr[a - 1][b];
        }
    }

    LL n = R + C;
    LL blockarea[n][n];
    LL totalarea[n + 1][n + 1];
    for (LL a = 0; a < n; a++) {
        for (LL b = 0; b < n; b++) {
            blockarea[a][b] = ncr[a][R - 1] * ncr[b][R - 1];
        }
    }
    LL revarea[n + 1][n + 1];
    for (LL a = 0; a <= n; a++) {
        for (LL b = 0; b <= n; b++) {
            totalarea[a][b] = 0;
            if (a == 0 || b == 0) continue;
            totalarea[a][b] = totalarea[a][b - 1] + totalarea[a - 1][b] - totalarea[a - 1][b - 1];
            totalarea[a][b] += blockarea[a - 1][b - 1];
        }
    }
    for (LL a = 0; a <= n; a++) {
        for (LL b = 0; b <= n; b++) {
            revarea[a][b] = totalarea[n][n] - totalarea[n - a][n] - totalarea[n][n - b] + totalarea[n - a][n - b];
        }
    }

    LL d = n;

    LL best = ans[R][C];
    LL m1 = (-best + totalarea[n][n]) / 2;
    LL m2 = totalarea[n][n] - m1;
    LL bestfreq = 0;

    for (LL x = 0; x <= n; x++) {
        for (LL y = 0; y < n; y++) {
            if (x + y + 1 <= d && str[x + y] != 'B') {
                for (LL it = 0; it < MAX_N; it++) {
                    LL area2 = it + totalarea[n][y + 1] - totalarea[x][y + 1];
                    if (area2 > m2) continue;
                    dp[x][y + 1][it] += dp[x][y][it];
                }
            }
            if (x + y + 1 <= 2 * n - d && str[n - x + n - y - 1] != 'B') {
                for (LL it = 0; it < MAX_N; it++) {
                    LL area2 = totalarea[n][n] - it - totalarea[n - x][n - (y + 1)];
                    if (area2 > m2) continue;
                    bp[x][y + 1][it] += bp[x][y][it];
                }
            }
        }
        if (x == n) continue;
        for (LL y = 0; y <= n; y++) {
            if (x + y + 1 <= d && str[x + y] != 'A') {
                LL newarea = totalarea[x + 1][y] - totalarea[x][y];
                for (LL it = 0; it < MAX_N; it++) {
                    LL c = it + newarea;
                    LL area2 = totalarea[x + 1][n] - c;
                    if (area2 > m2) continue;
                    dp[x + 1][y][it + newarea] += dp[x][y][it];
                }
            }
            if (x + y + 1 <= 2 * n - d && str[n - x + n - y - 1] != 'A') {
                LL newarea = totalarea[n - x][n - y] - totalarea[n - x - 1][n - y];
                for (LL it = 0; it < MAX_N; it++) {
                    if (it + newarea > m2) continue;
                    bp[x + 1][y][it + newarea] += bp[x][y][it];
                }
            }
            if (x + y + 1 <= d) memset(dp[x][y], 0, sizeof(dp[x][y]));
            if (x + y + 1 <= 2 * n - d) memset(bp[x][y], 0, sizeof(bp[x][y]));
        }
    }

    for (LL x = 0; x <= n; x++) {
        LL y = d - x;
        if (y < 0 || y > n) continue;

        for (LL it1 = 0; it1 < MAX_N; it1++) {
            for (LL it2 = 0; it2 < MAX_N; it2++) {
                LL c = it1;
                LL freq = dp[x][y][it1];

                bestfreq += freq * bp[n - x][n - y][m1 - c];
                if (m1 != m2) bestfreq += freq * bp[n - x][n - y][m2 - c];
            }
        }
    }

    printf("%lld\n", bestfreq);

    return 0;
}
