#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define MOD 998244353

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned int uint;
typedef size_t usize;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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
    return make((uint)((ull)m1.v * m2.v % MOD));
}

modint inv(ll v) {
    if (v < 1000000) {
        // Small inverse logic can be implemented here if needed
    }
    // Extended Euclidean algorithm for modular inverse
    ll a = v, b = MOD, x0 = 0, x1 = 1;
    while (a > 1) {
        ll q = a / b;
        ll t = b;
        b = a % b, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    return make((x1 + MOD) % MOD);
}

modint divide(modint m1, modint m2) {
    return mul(m1, inv(m2.v));
}

void read_array(bool* a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void read_weights(int* w, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    bool* a = (bool*)malloc(n * sizeof(bool));
    int* w = (int*)malloc(n * sizeof(int));
    read_array(a, n);
    read_weights(w, n);
    
    int zw = 0, ow = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            ow += w[i];
        } else {
            zw += w[i];
        }
    }
    
    int s = zw + ow;
    modint* inv = (modint*)malloc((2 * m + 1) * sizeof(modint));
    
    for (int d = -m; d <= m; d++) {
        if (s + d > 0) {
            inv[d + m] = divide(make(1), make(s + d));
        }
    }
    
    modint** dp = (modint**)malloc((m + 1) * sizeof(modint*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (modint*)malloc(2 * sizeof(modint));
        dp[i][0] = make(0);
        dp[i][1] = make(0);
    }
    dp[0][0] = make(1);
    
    for (int i = 0; i < m; i++) {
        modint** ndp = (modint**)malloc((m + 1) * sizeof(modint*));
        for (int j = 0; j <= m; j++) {
            ndp[j] = (modint*)malloc(2 * sizeof(modint));
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
    
    free(a);
    free(w);
    free(inv);
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return 0;
}
