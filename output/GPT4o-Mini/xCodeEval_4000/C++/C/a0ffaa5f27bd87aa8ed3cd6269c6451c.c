#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    unsigned int first;
    unsigned int second;
} Pair;

typedef struct {
    unsigned int _v;
} Mint;

unsigned int mod;

unsigned int safe_mod(long long x) {
    x %= mod;
    if (x < 0) x += mod;
    return (unsigned int)x;
}

unsigned int binomial_coefficient(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    unsigned int res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void set_mod(int m) {
    mod = m;
}

Mint mint_raw(int v) {
    Mint x;
    x._v = safe_mod(v);
    return x;
}

Mint mint_add(Mint a, Mint b) {
    Mint res;
    res._v = safe_mod(a._v + b._v);
    return res;
}

Mint mint_mul(Mint a, Mint b) {
    Mint res;
    res._v = (unsigned long long)a._v * b._v % mod;
    return res;
}

Mint mint_pow(Mint a, long long n) {
    assert(n >= 0);
    Mint res = mint_raw(1);
    while (n) {
        if (n & 1) res = mint_mul(res, a);
        a = mint_mul(a, a);
        n >>= 1;
    }
    return res;
}

unsigned long long g[1001];

void compute_g(int n) {
    for (int i = 0; i <= n; i++) {
        g[i] = (unsigned long long)i * (i + 1) / 2;
    }
}

int main() {
    int n, m;
    scanf("%d %d %d", &n, &m, &mod);
    set_mod(mod);

    Mint C[1001][1001];
    C[0][0] = mint_raw(1);
    for (int i = 1; i <= n; i++) {
        C[i][0] = mint_raw(1);
        for (int j = 1; j <= i; j++) {
            C[i][j] = mint_add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }

    compute_g(n);

    Pair f[1001];
    f[0] = (Pair){1, 0};

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            Mint z = mint_mul(mint_mul(f[j].first, f[i - 1 - j].first), C[i - 1][j]);
            f[i].first = mint_add(f[i].first, mint_mul(z, mint_raw(i + 1)));
            f[i].second = mint_add(f[i].second, mint_mul(z, mint_raw(g[j] + g[i - 1 - j])));
            f[i].second = mint_add(f[i].second, mint_mul(mint_add(mint_mul(f[i - 1 - j].first, f[j].second), mint_mul(f[j].first, f[i - 1 - j].second)), mint_mul(C[i - 1][j], mint_raw(i + 1))));
        }
    }

    Pair dp[1002][1001];
    dp[0][0] = (Pair){1, 0};
    for (int l = 0; l <= n; l++) {
        for (int r = l + 1; r <= n + 1; r++) {
            int di = r - l - 1;
            for (int i = 0; i + di <= m; i++) {
                Mint z = mint_mul(dp[l][i].first, f[di].first);
                dp[r][i + di].first = mint_add(dp[r][i + di].first, mint_mul(z, C[i + di][di]));
                dp[r][i + di].second = mint_add(dp[r][i + di].second, mint_add(mint_mul(dp[l][i].second, f[di].first), mint_mul(dp[l][i].first, f[di].second)));
                dp[r][i + di].second = mint_add(dp[r][i + di].second, mint_mul(mint_mul(C[i + di][di], mint_raw(i + 1)), z));
            }
        }
    }

    printf("%u\n", dp[n + 1][m].second);
    return 0;
}
