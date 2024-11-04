#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 40

long long ncr[MAX_SIZE][MAX_SIZE];
long long ans[30][30];

int main() {
    for (int a = 0; a < MAX_SIZE; a++) {
        for (int b = 0; b < MAX_SIZE; b++) {
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

    long long R, C;
    scanf("%lld %lld", &R, &C);
    char str[R + C];
    scanf("%s", str);

    long long n = R + C;
    long long blockarea[n][n];
    long long totalarea[n + 1][n + 1];
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            blockarea[a][b] = ncr[a][R - 1] * ncr[b][R - 1];
        }
    }

    long long revarea[n + 1][n + 1];
    for (int a = 0; a <= n; a++) {
        for (int b = 0; b <= n; b++) {
            totalarea[a][b] = 0;
            if (a == 0 || b == 0) continue;
            totalarea[a][b] = totalarea[a][b - 1] + totalarea[a - 1][b] - totalarea[a - 1][b - 1];
            totalarea[a][b] += blockarea[a - 1][b - 1];
        }
    }

    for (int a = 0; a <= n; a++) {
        for (int b = 0; b <= n; b++) {
            revarea[a][b] = totalarea[n][n] - totalarea[n - a][n] - totalarea[n][n - b] + totalarea[n - a][n - b];
        }
    }

    long long d = (2 * n - 1) < (n + R - 2) ? (2 * n - 1) : (n + R - 2);

    long long dp[n + 1][n + 1][revarea[n][n] + 1];
    long long bp[n + 1][n + 1][revarea[n][n] + 1];
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            for (int z = 0; z <= revarea[n][n]; z++) {
                dp[x][y][z] = 0;
                bp[x][y][z] = 0;
            }
        }
    }

    dp[0][0][0] = 1;
    bp[0][0][0] = 1;

    long long best = ans[R][C];
    long long m1 = (-best + totalarea[n][n]) / 2;
    long long m2 = totalarea[n][n] - m1;
    long long bestfreq = 0;

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y < n; y++) {
            if (x + y + 1 <= d && str[x + y] != 'B') {
                for (int z = 0; z <= revarea[n][y + 1]; z++) {
                    dp[x][y + 1][z] += dp[x][y][z];
                }
            }
            if (x + y + 1 <= 2 * n - d && str[n - x + n - y - 1] != 'B') {
                for (int z = 0; z <= revarea[n][y + 1]; z++) {
                    bp[x][y + 1][z] += bp[x][y][z];
                }
            }
        }
        if (x == n) continue;
        for (int y = 0; y <= n; y++) {
            if (x + y + 1 <= d && str[x + y] != 'A') {
                for (int z = 0; z <= revarea[x + 1][y] - revarea[x][y]; z++) {
                    dp[x + 1][y][z + revarea[x][y]] += dp[x][y][z];
                }
            }
            if (x + y + 1 <= 2 * n - d && str[n - x + n - y - 1] != 'A') {
                for (int z = 0; z <= revarea[n - x][n - y] - revarea[n - x - 1][n - y]; z++) {
                    bp[x + 1][y][z + revarea[n - x - 1][n - y]] += bp[x][y][z];
                }
            }
            if (x + y + 1 <= d) {
                for (int z = 0; z <= revarea[n][n]; z++) {
                    dp[x][y][z] = 0;
                }
            }
            if (x + y + 1 <= 2 * n - d) {
                for (int z = 0; z <= revarea[n][n]; z++) {
                    bp[x][y][z] = 0;
                }
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        int y = d - x;
        if (y < 0 || y > n) continue;
        for (int z1 = 0; z1 <= revarea[n][y]; z1++) {
            for (int z2 = 0; z2 <= revarea[n][n]; z2++) {
                bestfreq += dp[x][y][z1] * bp[n - x][n - y][m1 - z1];
                if (m1 != m2) bestfreq += dp[x][y][z1] * bp[n - x][n - y][m2 - z1];
            }
        }
    }

    printf("%lld\n", bestfreq);

    return 0;
}
