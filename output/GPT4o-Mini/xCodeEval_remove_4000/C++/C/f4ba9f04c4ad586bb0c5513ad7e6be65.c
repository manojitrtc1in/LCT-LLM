#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define CR 7
#define BITS 15
#define MOD (1000000007)
#define INF (1000000000)
#define EPS (1e-9)
#define PI (acos(-1.0))

typedef long long li;
typedef long double ld;

li n;

typedef struct {
    int val;
} Mint;

Mint create_mint(int64_t v) {
    Mint m;
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    m.val = (int)v;
    return m;
}

Mint mint_add(Mint a, Mint b) {
    a.val += b.val;
    if (a.val >= MOD) a.val -= MOD;
    return a;
}

Mint mint_sub(Mint a, Mint b) {
    a.val -= b.val;
    if (a.val < 0) a.val += MOD;
    return a;
}

Mint mint_mul(Mint a, Mint b) {
    a.val = (int)(((int64_t)a.val * b.val) % MOD);
    return a;
}

Mint mint_inv(Mint a) {
    int g = MOD, r = a.val, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; 
        int temp = g; g = r; r = temp;
        x -= q * y; 
        temp = x; x = y; y = temp;
    }
    return create_mint(x < 0 ? x + MOD : x);
}

Mint mint_div(Mint a, Mint b) {
    return mint_mul(a, mint_inv(b));
}

Mint dp[CR][BITS + 1][CR][1 << BITS];
Mint cnt[CR][CR][1 << BITS];

void precalc() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < CR; i++) dp[i][0][i][0] = create_mint(1).val;

    for (int cs = 0; cs < CR; cs++) {
        for (int i = 0; i < BITS; i++) {
            for (int ct = 0; ct < CR; ct++) {
                for (int x = 0; x < (1 << BITS); x++) {
                    if (dp[cs][i][ct][x] != 0) {
                        for (int cc = 0; cc < CR + 1; cc++) {
                            dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x] = mint_add(dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x], dp[cs][i][ct][x]).val;
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

void solve() {
    memset(dp2, 0, sizeof(dp2));
    dp2[0][0] = create_mint(1).val;

    for (int i = 0; i < 4; i++) {
        int x = (n & ((1 << BITS) - 1));
        n >>= BITS;
        for (int j = 0; j < CR; j++) {
            for (int k = 0; k < CR; k++) {
                dp2[i + 1][k] = mint_add(dp2[i + 1][k], mint_mul(dp2[i][j], cnt[j][k][x])).val;
            }
        }
    }
    printf("%d\n", dp2[4][0].val);
}

int read() {
    return scanf("%lld", &n) == 1;
}

int main() {
    ios_sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    clock_t tt = clock();
    precalc();

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        if (read()) {
            while (read()) {
                solve();
                fprintf(stderr, "TIME = %ld\n", clock() - tt);
                tt = clock();
            }
        }
    }
    return 0;
}
