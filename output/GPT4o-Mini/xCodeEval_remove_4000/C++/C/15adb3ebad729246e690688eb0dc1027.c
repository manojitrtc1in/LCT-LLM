#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MOD ((int)1e9 + 7)
#define BUFFER_SIZE (1 << 12)
#define MAX_LENGTH (1 << 7)

int dp[61][8];
long long n = 0;

void read(long long *arg) {
    scanf("%lld", arg);
}

void writeln(int arg) {
    printf("%d\n", arg);
}

void solve() {
    read(&n);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (long long i = 0; i < 60; ++i) {
        bool bit = ((1LL << i) & n);
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

    writeln(dp[60][0]);
}

int main() {
    int tests;
    read((long long *)&tests);
    while (tests--)
        solve();
    return 0;
}
