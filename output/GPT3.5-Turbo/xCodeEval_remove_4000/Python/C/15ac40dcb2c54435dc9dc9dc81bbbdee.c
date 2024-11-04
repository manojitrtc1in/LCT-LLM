#include <stdio.h>

int main() {
    int n, mod;
    scanf("%d %d", &n, &mod);

    int M = (int)sqrt(n) + 10;

    int dp[n+1];
    int imos[n+1];
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        imos[i] = (imos[i] + imos[i-1]) % mod;
        dp[i] += imos[i];
        dp[i] %= mod;

        imos[i+1] += dp[i];
        imos[i+1] %= mod;

        for (int j = 2; j <= n; j++) {
            if (i*j > n) {
                break;
            }

            imos[i*j] += dp[i];
            imos[i*j] %= mod;
            if ((i+1)*j <= n) {
                imos[(i+1)*j] -= dp[i];
                imos[(i+1)*j] %= mod;
            }
        }
    }

    int res = dp[n] + imos[n] + imos[n-1];
    res %= mod;
    printf("%d\n", res);

    return 0;
}
