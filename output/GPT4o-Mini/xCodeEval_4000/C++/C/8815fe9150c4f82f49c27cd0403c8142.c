#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define MOD 998244353

typedef struct {
    uint32_t v;
} modint;

modint make(uint32_t x) {
    modint m;
    m.v = x % MOD;
    return m;
}

modint modint_add(modint m1, modint m2) {
    return make(m1.v + m2.v);
}

modint modint_sub(modint m1, modint m2) {
    return make(m1.v + MOD - m2.v);
}

modint modint_mul(modint m1, modint m2) {
    return make((uint64_t)m1.v * m2.v % MOD);
}

modint modint_div(modint m1, modint m2) {
    // Implementing modular inverse using Fermat's Little Theorem
    uint32_t inv = 1;
    for (uint32_t i = 1; i < MOD - 1; i++) {
        if (i * m2.v % MOD == 1) {
            inv = i;
            break;
        }
    }
    return modint_mul(m1, make(inv));
}

modint inv[200000];

void precompute_inv() {
    inv[1] = make(1);
    for (uint32_t i = 2; i < 200000; i++) {
        inv[i] = modint_div(make(1), make(i));
    }
}

int main() {
    precompute_inv();
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    bool a[n];
    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    int zw = 0, ow = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            ow += w[i];
        } else {
            zw += w[i];
        }
    }
    
    int s = zw + ow;
    modint dp[m + 1][2];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = make(0);
        dp[i][1] = make(0);
    }
    dp[0][0] = make(1);
    
    for (int i = 0; i < m; i++) {
        modint ndp[m + 1][2];
        for (int j = 0; j <= m; j++) {
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
                modint p = modint_mul(dz == -1 ? make(wz) : make(wo), eps);
                
                ndp[nz][-dz] = modint_add(ndp[nz][-dz], modint_mul(dp[z][-dz], p));
                ndp[nz][1 + dz] = modint_add(ndp[nz][1 + dz], modint_mul(modint_add(p, modint_mul(make(2 * dz + 1), eps)), dp[z][1 + dz]));
            }
        }
        for (int j = 0; j <= m; j++) {
            dp[j][0] = ndp[j][0];
            dp[j][1] = ndp[j][1];
        }
    }
    
    modint cz = make(0), co = make(0);
    for (int i = 0; i <= m; i++) {
        cz = modint_add(cz, dp[i][0]);
        co = modint_add(co, dp[i][1]);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%u\n", (a[i] == 0 ? cz.v : co.v) * w[i]);
    }
    
    return 0;
}
