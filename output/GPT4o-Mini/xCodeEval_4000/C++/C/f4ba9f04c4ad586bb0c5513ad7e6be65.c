#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define CR 7
#define BITS 15
#define MOD (1000000007)

typedef long long li;
typedef struct {
    int val;
} Mint;

Mint dp[CR][BITS + 1][CR][1 << BITS];
Mint cnt[CR][CR][1 << BITS];

void mint_init(Mint *m, int64_t v) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    m->val = (int)v;
}

Mint mint_add(Mint a, Mint b) {
    Mint result;
    result.val = (a.val + b.val) % MOD;
    return result;
}

Mint mint_mul(Mint a, Mint b) {
    Mint result;
    result.val = (int)(((int64_t)a.val * b.val) % MOD);
    return result;
}

void precalc() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < CR; i++) {
        mint_init(&dp[i][0][i][0], 1);
    }
    for (int cs = 0; cs < CR; cs++) {
        for (int i = 0; i < BITS; i++) {
            for (int ct = 0; ct < CR; ct++) {
                for (int x = 0; x < (1 << BITS); x++) {
                    if (dp[cs][i][ct][x].val != 0) {
                        for (int cc = 0; cc < CR + 1; cc++) {
                            dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x] = mint_add(dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x], dp[cs][i][ct][x]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < CR; i++) {
        for (int j = 0; j < CR; j++) {
            for (int x = 0; x < (1 << BITS); x++) {
                cnt[i][j][x] = dp[i][BITS][j][x];
            }
        }
    }
}

Mint dp2[5][CR];

void solve(li n) {
    memset(dp2, 0, sizeof(dp2));
    mint_init(&dp2[0][0], 1);
    for (int i = 0; i < 4; i++) {
        int x = (n & ((1 << BITS) - 1));
        n >>= BITS;
        for (int j = 0; j < CR; j++) {
            for (int k = 0; k < CR; k++) {
                dp2[i + 1][k] = mint_add(dp2[i + 1][k], mint_mul(dp2[i][j], cnt[j][k][x]));
            }
        }
    }
    printf("%d\n", dp2[4][0].val);
}

int main() {
    precalc();
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        li n;
        scanf("%lld", &n);
        solve(n);
    }
    return 0;
}
