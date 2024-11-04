#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAXN 100000
#define MOD 998244353

typedef long long ll;
typedef struct {
    int x;
} mint;

mint create_mint(long long x_) {
    mint m;
    m.x = (x_ % MOD + MOD) % MOD;
    return m;
}

int mint_val(mint m) {
    return m.x;
}

mint mint_add(mint a, mint b) {
    a.x += b.x;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

mint mint_sub(mint a, mint b) {
    a.x -= b.x;
    if (a.x < 0) a.x += MOD;
    return a;
}

mint mint_mul(mint a, mint b) {
    a.x = (ll)a.x * b.x % MOD;
    return a;
}

mint mint_pow(mint a, ll n) {
    mint ret = create_mint(1);
    while (n > 0) {
        if (n & 1) ret = mint_mul(ret, a);
        a = mint_mul(a, a);
        n >>= 1;
    }
    return ret;
}

mint mint_inv(mint a) {
    int b = MOD, u = 1, v = 0, t;
    while (b > 0) {
        t = a.x / b;
        a.x -= t * b; 
        u -= t * v;
        if (a.x < 0) a.x += MOD;
        if (u < 0) u += MOD;
        t = a.x; a.x = b; b = t;
        t = v; v = u; u = t;
    }
    return create_mint(u);
}

mint mint_div(mint a, mint b) {
    return mint_mul(a, mint_inv(b));
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int h[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    h[n] = h[0];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] == h[i + 1]) cnt++;
    }
    int d = n - cnt;

    mint res = mint_pow(create_mint(k), cnt);
    mint sum = create_mint(0);

    mint f[2 * d + 1];
    f[0] = create_mint(1);
    f[1] = create_mint(k - 2);
    f[2] = create_mint(1);

    for (int i = 3; i <= 2 * d; i++) {
        f[i] = mint_add(f[i - 1], mint_mul(f[i - 2], create_mint(k - 2)));
    }

    for (int i = d + 1; i <= 2 * d; i++) {
        sum = mint_add(sum, f[i]);
    }

    printf("%d\n", mint_val(mint_mul(res, sum)));
    return 0;
}
