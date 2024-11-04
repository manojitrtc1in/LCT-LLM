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

mint subtract(mint lhs, mint rhs) {
    lhs._v += mod - rhs._v;
    if (lhs._v >= mod) lhs._v -= mod;
    return lhs;
}

mint multiply(mint lhs, mint rhs) {
    unsigned long long z = lhs._v;
    z *= rhs._v;
    lhs._v = safe_mod(z);
    return lhs;
}

mint pow(mint x, long long n) {
    mint r = raw(1);
    while (n) {
        if (n & 1) r = multiply(r, x);
        x = multiply(x, x);
        n >>= 1;
    }
    return r;
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

    mint dp[n + 1];
    mint p1[n + 1];

    dp[n] = raw(1);
    p1[n] = raw(1);
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = add(dp[i], p1[i + 1]);

        for (int z = 2; z * i <= n; z++) {
            int r = get(i, z) + 1;
            int l = z * i;
            dp[i] = add(dp[i], p1[l]);
            if (r <= n) dp[i] = subtract(dp[i], p1[r]);
        }

        p1[i] = add(p1[i + 1], dp[i]);
    }

    printf("%u\n", dp[1]._v);
}

int main() {
    int _t = 1;

    while (_t--) solve();
    return 0;
}
