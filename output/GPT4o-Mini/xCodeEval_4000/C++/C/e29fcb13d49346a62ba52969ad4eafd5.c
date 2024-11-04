#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MOD 998244353

typedef struct {
    uint32_t v;
} modint;

modint make_modint(uint32_t x) {
    modint m;
    m.v = x % MOD;
    return m;
}

modint modint_add(modint m1, modint m2) {
    return make_modint(m1.v + m2.v);
}

modint modint_sub(modint m1, modint m2) {
    return make_modint(m1.v + MOD - m2.v);
}

modint modint_mul(modint m1, modint m2) {
    return make_modint((uint64_t)m1.v * m2.v % MOD);
}

modint modint_div(modint m1, modint m2) {
    // Using Fermat's Little Theorem for modular inverse
    uint32_t inv = 1; // Placeholder for modular inverse calculation
    for (uint32_t i = 1; i < MOD - 2; i++) {
        inv = modint_mul(inv, m2).v; // This is a simplification
    }
    return modint_mul(m1, make_modint(inv));
}

modint modint_inv(uint32_t v) {
    // Placeholder for modular inverse calculation
    return make_modint(1); // Simplified
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
        if (a[i]) {
            ow += w[i];
        } else {
            zw += w[i];
        }
    }
    
    int s = zw + ow;
    modint *inv = malloc((2 * m + 1) * sizeof(modint));
    
    for (int d = -m; d <= m; d++) {
        if (s + d > 0) {
            inv[d + m] = modint_div(make_modint(1), make_modint(s + d));
        }
    }
    
    modint **dp = malloc((m + 1) * sizeof(modint *));
    for (int i = 0; i <= m; i++) {
        dp[i] = malloc(2 * sizeof(modint));
        dp[i][0] = make_modint(0);
        dp[i][1] = make_modint(0);
    }
    dp[0][0] = make_modint(1);
    
    for (int i = 0; i < m; i++) {
        modint **ndp = malloc((m + 1) * sizeof(modint *));
        for (int j = 0; j <= m; j++) {
            ndp[j] = malloc(2 * sizeof(modint));
            ndp[j][0] = make_modint(0);
            ndp[j][1] = make_modint(0);
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
                modint p = modint_mul(dz == -1 ? make_modint(wz) : make_modint(wo), eps);
                
                ndp[nz][-dz] = modint_add(ndp[nz][-dz], modint_mul(dp[z][-dz], p));
                ndp[nz][1 + dz] = modint_add(ndp[nz][1 + dz], modint_mul(modint_add(p, modint_mul(make_modint(2 * dz + 1), eps)), dp[z][1 + dz]));
            }
        }
        
        for (int j = 0; j <= m; j++) {
            free(dp[j]);
        }
        free(dp);
        dp = ndp;
    }
    
    modint cz = make_modint(0);
    modint co = make_modint(0);
    
    for (int i = 0; i <= m; i++) {
        cz = modint_add(cz, dp[i][0]);
        co = modint_add(co, dp[i][1]);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", w[i] * (a[i] == 0 ? cz.v : co.v));
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
