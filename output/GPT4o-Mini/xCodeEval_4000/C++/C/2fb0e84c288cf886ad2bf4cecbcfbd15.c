#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned int _v;
} mint;

static unsigned int mod;

void set_mod(int m) {
    mod = m;
}

unsigned int safe_mod(long long x) {
    x %= mod;
    if (x < 0) x += mod;
    return (unsigned int)x;
}

mint mint_raw(int v) {
    mint x;
    x._v = safe_mod(v);
    return x;
}

mint mint_add(mint lhs, mint rhs) {
    lhs._v += rhs._v;
    if (lhs._v >= mod) lhs._v -= mod;
    return lhs;
}

mint mint_sub(mint lhs, mint rhs) {
    lhs._v += mod - rhs._v;
    if (lhs._v >= mod) lhs._v -= mod;
    return lhs;
}

mint mint_mul(mint lhs, mint rhs) {
    unsigned long long z = lhs._v;
    z *= rhs._v;
    lhs._v = safe_mod(z);
    return lhs;
}

mint mint_inv(mint a) {
    long long m0 = mod, t, q;
    long long x0 = 0, x1 = 1;

    if (mod == 1) return mint_raw(0);
    if (a._v == 0) return mint_raw(0);

    while (a._v > 1) {
        q = a._v / m0;
        t = m0;
        m0 = a._v % m0;
        a._v = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += mod;

    return mint_raw(x1);
}

int get(int i, int z) {
    int l = i * z;
    int r = (i + i) * z;
    int ans = l;

    while (l <= r) {
        int m = (l + r) / 2;
        if (m / z > i) {
            r = m - 1;
        } else {
            ans = (ans > m) ? ans : m;
            l = m + 1;
        }
    }

    return ans;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    set_mod(m);

    mint *dp = (mint *)malloc((n + 1) * sizeof(mint));
    mint *p1 = (mint *)malloc((n + 1) * sizeof(mint));

    dp[n] = mint_raw(1);
    p1[n] = mint_raw(1);
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = mint_add(dp[i], p1[i + 1]);

        for (int z = 2; z * i <= n; z++) {
            int r = get(i, z) + 1;
            int l = z * i;
            dp[i] = mint_add(dp[i], p1[l]);
            if (r <= n) dp[i] = mint_sub(dp[i], p1[r]);
        }

        p1[i] = mint_add(p1[i + 1], dp[i]);
    }

    printf("%u\n", dp[1]._v);
    free(dp);
    free(p1);
}

int main() {
    int _t = 1;
    while (_t--) solve();
    return 0;
}
