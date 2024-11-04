#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MOD 1000000007

typedef struct {
    int64_t value;
} Mint;

Mint normalize(int64_t x) {
    Mint result;
    if (x < 0) {
        result.value = (x % MOD + MOD) % MOD;
    } else {
        result.value = x % MOD;
    }
    return result;
}

Mint add(Mint a, Mint b) {
    return normalize(a.value + b.value);
}

Mint multiply(Mint a, Mint b) {
    return normalize(a.value * b.value);
}

Mint power(Mint a, int64_t b) {
    Mint result = {1};
    while (b > 0) {
        if (b & 1) {
            result = multiply(result, a);
        }
        a = multiply(a, a);
        b >>= 1;
    }
    return result;
}

int d[123];
Mint dp[7];
Mint new_dp[7];

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int64_t m;
        scanf("%lld", &m);
        int len = 0;
        while (m > 0) {
            d[len++] = (m & 1);
            m >>= 1;
        }
        for (int i = 0; i <= 6; i++) {
            dp[i] = (Mint){0};
            new_dp[i] = (Mint){0};
        }
        dp[0] = (Mint){1};
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
                new_dp[6] = add(dp[3], add(dp[4], add(dp[5], dp[6])));
            }
            for (int i = 0; i <= 6; i++) {
                dp[i] = new_dp[i];
            }
        }
        printf("%lld\n", dp[0].value);
    }
    return 0;
}
