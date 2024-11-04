#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned int uint;
typedef size_t usize;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MOD 998244353

typedef struct {
    uint v;
} modint;

modint make(uint x) {
    modint m;
    m.v = x % MOD;
    return m;
}

modint add(modint m1, modint m2) {
    return make(m1.v + m2.v);
}

modint sub(modint m1, modint m2) {
    return make(m1.v + MOD - m2.v);
}

modint mul(modint m1, modint m2) {
    return make((ll)m1.v * m2.v % MOD);
}

modint inv(ll v) {
    if (v < 1000000) {
        // Small inverse logic can be implemented here if needed
        return make(1); // Placeholder
    }
    // Extended Euclidean algorithm for modular inverse
    ll a = v, m = MOD, m0 = m, y = 0, x = 1;
    if (m == 1) return make(0);
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return make(x);
}

modint power(modint x, ull n) {
    modint ans = make(1);
    while (n) {
        if (n & 1) ans = mul(ans, x);
        x = mul(x, x);
        n >>= 1;
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    bool *a = malloc(n * sizeof(bool));
    int *w = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    int zw = 0, ow = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) ow += w[i];
        else zw += w[i];
    }
    
    int s = zw + ow;
    modint *inv = malloc((2 * m + 1) * sizeof(modint));
    
    for (int d = -m; d <= m; d++) {
        if (s + d > 0) inv[d + m] = inv(s + d);
    }
    
    modint **dp = malloc((m + 1) * sizeof(modint *));
    for (int i = 0; i <= m; i++) {
        dp[i] = malloc(2 * sizeof(modint));
        dp[i][0] = make(0);
        dp[i][1] = make(0);
    }
    dp[0][0] = make(1);
    
    for (int i = 0; i < m; i++) {
        modint **ndp = malloc((m + 1) * sizeof(modint *));
        for (int j = 0; j <= m; j++) {
            ndp[j] = malloc(2 * sizeof(modint));
            ndp[j][0] = make(0);
            ndp[j][1] = make(0);
        }
        
        for (int z = 0; z <= i; z++) {
            int o = i - z;
            int wz = zw - z;
            int wo = ow + o;
            if (wz < 0) continue;
            for (int dz = -1; dz <= 0; dz++) {
                int nwz = wz + dz;
                int nz = z + (-dz);
                if (nwz < 0) continue;
                modint eps = inv[wz + wo - s + m];
                modint p = mul(dz == -1 ? make(wz) : make(wo), eps);
                ndp[nz][-dz] = add(ndp[nz][-dz], mul(dp[z][-dz], p));
                ndp[nz][1 + dz] = add(ndp[nz][1 + dz], add(p, mul(make(2 * dz + 1), eps)));
            }
        }
        for (int j = 0; j <= m; j++) {
            free(dp[j]);
        }
        free(dp);
        dp = ndp;
    }
    
    modint cz = make(0), co = make(0);
    for (int i = 0; i <= m; i++) {
        cz = add(cz, dp[i][0]);
        co = add(co, dp[i][1]);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%lld\n", (a[i] == 0 ? cz.v : co.v) * w[i]);
    }
    
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    free(inv);
    free(a);
    free(w);
    
    return 0;
}
