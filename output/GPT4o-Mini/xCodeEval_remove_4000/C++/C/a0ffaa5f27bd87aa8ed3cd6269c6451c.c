#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned int uint;
typedef long long ll;

typedef struct {
    unsigned int _v;
} mint;

typedef struct {
    mint first;
    mint second;
} P;

typedef struct {
    mint **data;
    int rows;
    int cols;
} VV;

VV create_vv(int rows, int cols) {
    VV vv;
    vv.rows = rows;
    vv.cols = cols;
    vv.data = (mint **)malloc(rows * sizeof(mint *));
    for (int i = 0; i < rows; i++) {
        vv.data[i] = (mint *)malloc(cols * sizeof(mint));
    }
    return vv;
}

void free_vv(VV vv) {
    for (int i = 0; i < vv.rows; i++) {
        free(vv.data[i]);
    }
    free(vv.data);
}

void set_mod(int mod) {
    // Set the modulus for mint operations (not implemented)
}

mint raw(int v) {
    mint x;
    x._v = v;
    return x;
}

mint add(mint a, mint b) {
    mint result;
    result._v = (a._v + b._v) % 1000000007; // Example modulus
    return result;
}

mint mul(mint a, mint b) {
    mint result;
    result._v = (a._v * b._v) % 1000000007; // Example modulus
    return result;
}

mint pow(mint a, ll n) {
    mint result = raw(1);
    while (n) {
        if (n & 1) result = mul(result, a);
        a = mul(a, a);
        n >>= 1;
    }
    return result;
}

int main() {
    int n, m, mod;
    scanf("%d %d %d", &n, &m, &mod);
    set_mod(mod);

    VV C = create_vv(n + 1, n + 1);
    C.data[0][0] = raw(1);
    for (int i = 1; i <= n; i++) {
        C.data[i][0] = raw(1);
        for (int j = 1; j <= n; j++) {
            C.data[i][j] = add(C.data[i - 1][j - 1], C.data[i - 1][j]);
        }
    }

    mint *g = (mint *)malloc((n + 1) * sizeof(mint));
    for (int i = 0; i <= n; i++) {
        g[i] = raw(i * (i + 1) / 2);
    }

    P *f = (P *)malloc((n + 1) * sizeof(P));
    f[0] = (P){raw(1), raw(0)};

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            mint z = mul(mul(f[j].first, f[i - 1 - j].first), C.data[i - 1][j]);
            f[i].first = add(f[i].first, mul(z, raw(i + 1)));
            f[i].second = add(f[i].second, mul(z, add(g[j], g[i - 1 - j])));
            f[i].second = add(f[i].second, mul(add(mul(f[i - 1 - j].first, f[j].second), mul(f[j].first, f[i - 1 - j].second)), mul(C.data[i - 1][j], raw(i + 1))));
        }
    }

    VV dp = create_vv(n + 2, m + 1);
    dp.data[0][0] = (P){raw(1), raw(0)};
    for (int l = 0; l <= n; l++) {
        for (int r = l + 1; r <= n + 1; r++) {
            int di = r - l - 1;
            for (int i = 0; i + di <= m; i++) {
                mint z = mul(dp.data[l][i].first, f[di].first);
                dp.data[r][i + di].first = add(dp.data[r][i + di].first, mul(z, C.data[i + di][di]));
                dp.data[r][i + di].second = add(dp.data[r][i + di].second, mul(add(mul(dp.data[l][i].second, f[di].first), mul(dp.data[l][i].first, f[di].second)), C.data[i + di][di]));
            }
        }
    }

    printf("%u\n", dp.data[n + 1][m].second._v);

    free_vv(C);
    free(g);
    free(f);
    free_vv(dp);
    return 0;
}
