#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MOD 1000000007

typedef struct {
    int value;
} Mint;

Mint create_mint(int x) {
    Mint m;
    m.value = (x % MOD + MOD) % MOD;
    return m;
}

Mint mint_add(Mint a, Mint b) {
    return create_mint(a.value + b.value);
}

Mint mint_mul(Mint a, Mint b) {
    return create_mint((int64_t)a.value * b.value % MOD);
}

Mint mint_pow(Mint base, int exp) {
    Mint result = create_mint(1);
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mint_mul(result, base);
        }
        base = mint_mul(base, base);
        exp /= 2;
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
        long long m;
        scanf("%lld", &m);
        int len = 0;
        while (m > 0) {
            d[len++] = (m & 1);
            m >>= 1;
        }
        for (int i = 0; i <= 6; i++) {
            dp[i] = create_mint(0);
            new_dp[i] = create_mint(0);
        }
        dp[0] = create_mint(1);
        for (int it = len - 1; it >= 0; it--) {
            if (d[it] == 0) {
                new_dp[0] = mint_add(mint_add(mint_add(dp[0], dp[1]), dp[2]), dp[3]);
                new_dp[1] = new_dp[2] = mint_add(mint_add(mint_add(dp[1], dp[2]), dp[3]), dp[4]);
                new_dp[3] = new_dp[4] = mint_add(mint_add(mint_add(dp[2], dp[3]), dp[4]), dp[5]);
                new_dp[5] = new_dp[6] = mint_add(mint_add(mint_add(dp[3], dp[4]), dp[5]), dp[6]);
            } else {
                new_dp[0] = new_dp[1] = mint_add(mint_add(mint_add(dp[0], dp[1]), dp[2]), dp[3]);
                new_dp[2] = new_dp[3] = mint_add(mint_add(mint_add(dp[1], dp[2]), dp[3]), dp[4]);
                new_dp[4] = new_dp[5] = mint_add(mint_add(mint_add(dp[2], dp[3]), dp[4]), dp[5]);
                new_dp[6] = mint_add(mint_add(mint_add(dp[3], dp[4]), dp[5]), dp[6]);
            }
            for (int i = 0; i <= 6; i++) {
                dp[i] = new_dp[i];
            }
        }
        printf("%d\n", dp[0].value);
    }
    return 0;
}
