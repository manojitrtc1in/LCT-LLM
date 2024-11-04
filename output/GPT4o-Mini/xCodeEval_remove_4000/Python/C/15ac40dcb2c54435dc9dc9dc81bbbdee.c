#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);

    int M = (int)(sqrt(n)) + 10;
    long long *dp = (long long *)calloc(n + 1, sizeof(long long));
    long long *imos = (long long *)calloc(n + 1, sizeof(long long));
    dp[1] = 1;

    for (int i = 1; i < n; i++) {
        imos[i] = (imos[i] + imos[i - 1]) % MOD;
        dp[i] = (dp[i] + imos[i]) % MOD;

        imos[i + 1] = (imos[i + 1] + dp[i]) % MOD;

        for (int j = 2; i * j <= n; j++) {
            imos[i * j] = (imos[i * j] + dp[i]) % MOD;
            if ((i + 1) * j <= n) {
                imos[(i + 1) * j] = (imos[(i + 1) * j] - dp[i] + MOD) % MOD;
            }
        }
    }

    long long res = (dp[n] + imos[n] + imos[n - 1]) % MOD;
    printf("%lld\n", res);

    free(dp);
    free(imos);
    return 0;
}
