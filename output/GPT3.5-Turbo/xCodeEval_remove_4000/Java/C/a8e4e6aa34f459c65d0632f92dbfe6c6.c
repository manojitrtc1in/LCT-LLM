#include <stdio.h>
#include <math.h>

#define MOD 998244353

int modular(int x) {
    x %= MOD;
    if (x < 0) {
        x += MOD;
    }
    return x;
}

int mul(int x, int y) {
    return modular((long long)x * y);
}

int plus(int x, int y) {
    return modular(x + y);
}

int pow_mod(int x, int n) {
    if (n == 0) {
        return 1;
    }
    long long r = pow_mod(x, n >> 1);
    r = modular(r * r);
    if (n & 1) {
        r = modular(r * x);
    }
    return r;
}

int inverse(int x) {
    return pow_mod(x, MOD - 2);
}

int composite(int m, int n) {
    if (n > m) {
        return 0;
    }
    int fact_m = 1;
    int fact_n = 1;
    int fact_mn = 1;
    for (int i = 1; i <= m; i++) {
        fact_m = mul(fact_m, i);
    }
    for (int i = 1; i <= n; i++) {
        fact_n = mul(fact_n, i);
    }
    for (int i = 1; i <= m - n; i++) {
        fact_mn = mul(fact_mn, i);
    }
    int inv_fact_n = inverse(fact_n);
    int inv_fact_mn = inverse(fact_mn);
    return mul(fact_m, mul(inv_fact_n, inv_fact_mn));
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int xk[k + 1];
    for (int i = 0; i <= k; i++) {
        xk[i] = pow_mod(i, k);
    }

    int ans = 0;
    for (int t = 0; t <= k; t++) {
        int p1 = composite(n, t);
        int p2 = 0;
        for (int i = 0; i <= t; i++) {
            int contrib = composite(t, i);
            contrib = mul(contrib, xk[t - i]);
            if (i % 2 == 1) {
                contrib = modular(-contrib);
            }
            p2 = plus(p2, contrib);
        }
        int p3 = inverse(t);

        int contrib = mul(p1, p2);
        contrib = mul(contrib, p3);
        ans = plus(ans, contrib);
    }

    printf("%d\n", ans);

    return 0;
}
