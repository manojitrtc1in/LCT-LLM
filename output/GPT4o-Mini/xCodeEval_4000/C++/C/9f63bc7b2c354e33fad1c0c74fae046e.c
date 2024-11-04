#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef unsigned int uint;

typedef struct {
    uint _v;
} mint;

static uint mod;

void set_mod(int m) {
    assert(1 <= m);
    mod = m;
}

uint safe_mod(long long x) {
    x %= mod;
    if (x < 0) x += mod;
    return (uint)x;
}

uint mul(uint a, uint b) {
    unsigned long long z = a;
    z *= b;
    return safe_mod(z);
}

uint pow_mod(uint x, long long n) {
    if (mod == 1) return 0;
    uint r = 1;
    uint y = safe_mod(x);
    while (n) {
        if (n & 1) r = mul(r, y);
        y = mul(y, y);
        n >>= 1;
    }
    return r;
}

uint inv(uint a) {
    uint m0 = mod, t, q;
    uint x0 = 0, x1 = 1;

    if (mod == 1) return 0;

    while (a > 1) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

uint get(int i, int z) {
    uint l1 = (uint)(1U * i * z);
    uint r1 = (uint)(1U * (i + i) * z);
    uint ans = l1;

    while (l1 <= r1) {
        uint m = (l1 + r1) / 2;
        if (m / z > i) {
            r1 = m - 1;
        } else {
            ans = (ans > m) ? ans : m;
            l1 = m + 1;
        }
    }

    return ans;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    set_mod(m);

    mint *dp = (mint *)malloc((n + 1) * sizeof(mint));
    mint *p = (mint *)malloc((n + 1) * sizeof(mint));

    dp[n]._v = 1;
    p[n]._v = 1;

    for (int i = n - 1; i >= 1; i--) {
        dp[i]._v += p[i + 1]._v;

        for (int z = 2; z * i <= n; z++) {
            int r = get(i, z) + 1;
            int l = z * i;
            dp[i]._v += p[l]._v;
            if (r <= n) dp[i]._v -= p[r]._v;
        }

        p[i]._v = p[i + 1]._v + dp[i]._v;
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
