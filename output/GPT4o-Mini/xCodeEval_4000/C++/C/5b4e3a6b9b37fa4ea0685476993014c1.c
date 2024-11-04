#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MOD 1000000007

typedef struct {
    int value;
} Mint;

Mint normalize(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    Mint m;
    m.value = x;
    return m;
}

Mint add(Mint a, Mint b) {
    return normalize(a.value + b.value);
}

Mint multiply(Mint a, Mint b) {
    return normalize((int64_t)a.value * b.value % MOD);
}

Mint power(Mint a, int b) {
    Mint res = {1}, x = a;
    while (b > 0) {
        if (b & 1) res = multiply(res, x);
        x = multiply(x, x);
        b >>= 1;
    }
    return res;
}

int d[123];
Mint dp[7];
Mint new_dp[7];

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        long long m;
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
                new_dp[6] = add(add(add(dp[3], dp[4]), dp[5]), dp[6]);
            }
            for (int i = 0; i <= 6; i++) {
                dp[i] = new_dp[i];
            }
        }
        printf("%d\n", dp[0].value);
    }
    return 0;
}
