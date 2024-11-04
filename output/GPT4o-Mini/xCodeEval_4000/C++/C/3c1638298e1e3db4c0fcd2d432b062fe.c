#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define MAXN 2000005
#define MOD 998244353

typedef struct {
    int64_t r;
} Mint;

Mint fac[MAXN];

Mint mint_init(int64_t rr) {
    Mint m;
    m.r = rr % MOD;
    if (m.r < 0) m.r += MOD;
    return m;
}

Mint mint_inv(Mint x) {
    int64_t a = x.r, m = MOD, m0 = m, y = 0, x0 = 1;
    if (m == 1) return mint_init(0);
    while (a > 1) {
        int64_t q = a / m;
        int64_t t = m;
        m = a % m, a = t;
        t = y;
        y = x0 - q * y;
        x0 = t;
    }
    if (x0 < 0) x0 += m0;
    return mint_init(x0);
}

Mint mint_mul(Mint a, Mint b) {
    return mint_init(a.r * b.r);
}

Mint mint_div(Mint a, Mint b) {
    return mint_mul(a, mint_inv(b));
}

Mint C(int n, int m) {
    return mint_div(mint_div(fac[n], fac[m]), fac[n - m]);
}

Mint bpow(Mint x, int n) {
    Mint res = mint_init(1);
    while (n) {
        if (n % 2) res = mint_mul(res, x);
        x = mint_mul(x, x);
        n /= 2;
    }
    return res;
}

int main() {
    for (int i = 1; i < MAXN; i++) {
        fac[i] = mint_mul(fac[i - 1], mint_init(i));
    }
    
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (k >= n) {
        printf("0\n");
        return 0;
    }
    
    Mint ans = mint_init(0);
    for (int i = 0; i <= n - k; ++i) {
        ans = mint_init(ans.r + (n - k - i) % 2 == 0 ? 1 : -1 * C(n - k, i).r * bpow(mint_init(i), n).r);
    }
    
    printf("%lld\n", mint_mul(mint_init(1 + (k > 0)), mint_mul(ans, C(n, n - k))).r);
    return 0;
}
