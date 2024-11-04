#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MOD 1000000007

typedef long long Mint;

Mint dp[7];
Mint new_dp[7];

void reset_dp() {
    for (int i = 0; i <= 6; i++) {
        dp[i] = new_dp[i] = 0;
    }
}

Mint add(Mint a, Mint b) {
    return (a + b) % MOD;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        long long m;
        scanf("%lld", &m);
        int d[123];
        int len = 0;
        while (m > 0) {
            d[len++] = (m & 1);
            m >>= 1;
        }
        reset_dp();
        dp[0] = 1;
        for (int it = len - 1; it >= 0; it--) {
            if (d[it] == 0) {
                new_dp[0] = add(add(add(dp[0], dp[1]), dp[2]), dp[3]);
                new_dp[1] = new_dp[2] = add(add(add(dp[1], dp[2]), dp[3]), dp[4]);
                new_dp[3] = new_dp[4] = add(add(add(dp[2], dp[3]), dp[4]), dp[5]);
                new_dp[5] = new_dp[6] = add(add(add(dp[3], dp[4]), dp[5]), dp[6]);
            } else {
                new_dp[0] = new_dp[1] = add(add(add(dp[0], dp[1]), dp[2]), dp[3]);
                new_dp[2] = new_dp[3] = add(add(add(dp[1], dp[2]), dp[3]), dp[4]);
                new_dp[4] = new_dp[5] = add(add(add(dp[2], dp[3]), dp[4]), dp[5]);
                new_dp[6] = add(add(add(dp[3], dp[4]), dp[5]), dp[6]);
            }
            memcpy(dp, new_dp, sizeof(dp));
        }
        printf("%lld\n", dp[0]);
    }
    return 0;
}
