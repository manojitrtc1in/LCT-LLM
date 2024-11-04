#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAXN 100000
#define MOD 1000000007

long dp[MAXN + 1];

void solve() {
    int n;
    long mod;
    scanf("%d %ld", &n, &mod);

    dp[n] = 1;

    for (int i = n - 1; i > 0; i--) {
        dp[i] += dp[i + 1];
        dp[i] %= mod;

        for (long div = 1; div * i <= n; div++) {
            int lb = (int)(div * i);
            int ub = (int)fmin((div * (i + 1) - 1), n);
            long segSum = dp[lb];
            if (ub + 1 <= n)
                segSum -= dp[ub + 1];
            dp[i] += segSum;
            dp[i] %= mod;
        }

        dp[i] += dp[i + 1];
        dp[i] %= mod;
    }

    printf("%ld\n", (dp[1] - dp[2] + mod) % mod);
}

int main() {
    int t = 1; // number of test cases
    for (int tc = 0; tc < t; tc++) {
        solve();
    }
    return 0;
}
