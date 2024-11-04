#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007

typedef long long ll;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        ll m;
        scanf("%lld", &m);
        int d[123];
        int len = 0;
        while (m > 0) {
            d[len++] = (m & 1);
            m >>= 1;
        }
        ll dp[7];
        ll new_dp[7];
        for (int i = 0; i <= 6; i++) {
            dp[i] = new_dp[i] = 0;
        }
        dp[0] = 1;
        for (int it = len - 1; it >= 0; it--) {
            if (d[it] == 0) {
                new_dp[0] = (dp[0] + dp[1] + dp[2] + dp[3]) % MOD;
                new_dp[1] = new_dp[2] = (dp[1] + dp[2] + dp[3] + dp[4]) % MOD;
                new_dp[3] = new_dp[4] = (dp[2] + dp[3] + dp[4] + dp[5]) % MOD;
                new_dp[5] = new_dp[6] = (dp[3] + dp[4] + dp[5] + dp[6]) % MOD;
            } else {
                new_dp[0] = new_dp[1] = (dp[0] + dp[1] + dp[2] + dp[3]) % MOD;
                new_dp[2] = new_dp[3] = (dp[1] + dp[2] + dp[3] + dp[4]) % MOD;
                new_dp[4] = new_dp[5] = (dp[2] + dp[3] + dp[4] + dp[5]) % MOD;
                new_dp[6] = (dp[3] + dp[4] + dp[5] + dp[6]) % MOD;
            }
            for (int i = 0; i <= 6; i++) {
                dp[i] = new_dp[i];
            }
        }
        printf("%lld\n", dp[0]);
    }
    return 0;
}
