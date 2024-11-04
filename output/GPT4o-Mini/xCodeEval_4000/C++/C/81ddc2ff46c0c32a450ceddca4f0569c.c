#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned int _v;
} mint;

unsigned int mod;

void set_mod(int m) {
    mod = m;
}

unsigned int safe_mod(long long x) {
    x %= mod;
    if (x < 0) x += mod;
    return (unsigned int)x;
}

mint raw(int v) {
    mint x;
    x._v = safe_mod(v);
    return x;
}

mint add(mint lhs, mint rhs) {
    lhs._v += rhs._v;
    if (lhs._v >= mod) lhs._v -= mod;
    return lhs;
}

mint sub(mint lhs, mint rhs) {
    lhs._v += mod - rhs._v;
    if (lhs._v >= mod) lhs._v -= mod;
    return lhs;
}

mint mul(mint lhs, mint rhs) {
    unsigned long long z = lhs._v;
    z *= rhs._v;
    lhs._v = safe_mod(z);
    return lhs;
}

mint pow(mint x, long long n) {
    mint r = raw(1);
    while (n) {
        if (n & 1) r = mul(r, x);
        x = mul(x, x);
        n >>= 1;
    }
    return r;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    set_mod(m);

    mint *dp = (mint *)malloc((n + 1) * sizeof(mint));
    mint *p = (mint *)malloc((n + 1) * sizeof(mint));

    dp[n] = raw(1);
    p[n] = raw(1);
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = add(dp[i], p[i + 1]);

        for (unsigned int z = 2; 1U * z * i <= n; z++) {
            int r = i * z + z;
            int l = 1U * z * i;
            dp[i] = add(dp[i], p[l]);
            if (r <= n) dp[i] = sub(dp[i], p[r]);
        }

        p[i] = add(p[i + 1], dp[i]);
    }

    printf("%u\n", dp[1]._v);
    free(dp);
    free(p);
}

int main() {
    int _t = 1;
    while (_t--) solve();
    return 0;
}
