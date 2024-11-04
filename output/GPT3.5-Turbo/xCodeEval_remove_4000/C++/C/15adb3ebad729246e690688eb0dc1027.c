#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int dp[61][8];

long long n = 0;

void solve() {
    scanf("%lld", &n);

    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (long long i = 0; i < 60; ++i) {
        int bit = ((1LL << i) & n) ? 1 : 0;

        for (int j = 0; j < (1 << 3); ++j) {
            if (dp[i][j] == 0)
                continue;

            for (int k = ((j % 2) ^ bit); k < 8; k += 2) {
                int lol = (j + k);

                dp[i + 1][lol / 2] += dp[i][j];
                if (dp[i + 1][lol / 2] >= MOD)
                    dp[i + 1][lol / 2] -= MOD;
            }
        }
    }

    printf("%d\n", dp[60][0]);
}

int main() {
    int tests = 0;
    scanf("%d", &tests);

    while (tests--)
        solve();

    return 0;
}
