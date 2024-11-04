#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MOD 1000000007
#define MAX_LEN 123
#define MAX_DP 7

typedef struct {
    int64_t value;
} Modular;

Modular create_modular(int64_t x) {
    Modular m;
    m.value = (x % MOD + MOD) % MOD;
    return m;
}

Modular add(Modular a, Modular b) {
    return create_modular(a.value + b.value);
}

Modular multiply(Modular a, Modular b) {
    return create_modular(a.value * b.value);
}

Modular power(Modular a, int64_t b) {
    assert(b >= 0);
    Modular res = create_modular(1);
    while (b > 0) {
        if (b & 1) res = multiply(res, a);
        a = multiply(a, a);
        b >>= 1;
    }
    return res;
}

int d[MAX_LEN];
Modular dp[MAX_DP];
Modular new_dp[MAX_DP];

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
        for (int i = 0; i < MAX_DP; i++) {
            dp[i] = create_modular(0);
            new_dp[i] = create_modular(0);
        }
        dp[0] = create_modular(1);
        for (int it = len - 1; it >= 0; it--) {
            if (d[it] == 0) {
                new_dp[0] = add(add(add(dp[0], dp[1]), dp[2]), dp[3]);
                new_dp[1] = add(add(add(dp[1], dp[2]), dp[3]), dp[4]);
                new_dp[3] = add(add(add(dp[2], dp[3]), dp[4]), dp[5]);
                new_dp[5] = add(add(add(dp[3], dp[4]), dp[5]), dp[6]);
            } else {
                new_dp[0] = new_dp[1] = add(add(add(dp[0], dp[1]), dp[2]), dp[3]);
                new_dp[2] = new_dp[3] = add(add(add(dp[1], dp[2]), dp[3]), dp[4]);
                new_dp[4] = new_dp[5] = add(add(add(dp[2], dp[3]), dp[4]), dp[5]);
                new_dp[6] = add(add(add(dp[3], dp[4]), dp[5]), dp[6]);
            }
            for (int i = 0; i < MAX_DP; i++) {
                dp[i] = new_dp[i];
            }
        }
        printf("%lld\n", dp[0].value);
    }
    return 0;
}
