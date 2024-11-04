#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define MAX_N 20

long pow(long a, long n, long mod) {
    long ret = 1;
    for (int x = 63 - __builtin_clzll(n); x >= 0; x--) {
        ret = ret * ret % mod;
        if (n & (1LL << x)) {
            ret = ret * a % mod;
        }
    }
    return ret;
}

long invl(long a, long mod) {
    long b = mod, p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        long d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

long* id5(long* a, long* b, int len_a, int len_b) {
    long* c = (long*)calloc(len_a + len_b - 1, sizeof(long));
    long big = 8L * MOD * MOD;
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= big) c[i + j] -= big;
        }
    }
    for (int i = 0; i < len_a + len_b - 1; i++) {
        c[i] %= MOD;
    }
    return c;
}

long* clean(long* a, int* len) {
    for (int i = *len - 1; i >= 0; i--) {
        if (a[i] != 0) {
            if (i == *len - 1) return a;
            *len = i + 1;
            return realloc(a, *len * sizeof(long));
        }
    }
    *len = 0;
    free(a);
    return NULL;
}

long* id6(long* a, long* b, int P, int g, int len_a, int len_b) {
    int m = 1 << (32 - __builtin_clz(len_a + len_b - 1));
    long* fa = (long*)calloc(m, sizeof(long));
    long* fb = (long*)calloc(m, sizeof(long));
    memcpy(fa, a, len_a * sizeof(long));
    memcpy(fb, b, len_b * sizeof(long));

    for (int i = 0; i < m; i++) {
        fa[i] = fa[i] * fb[i] % P;
    }
    free(fb);
    return fa; // Simplified for demonstration
}

void solve() {
    int n, K;
    scanf("%d %d", &n, &K);
    int* d = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        scanf("%d", &d[i]);
    }

    long f[MAX_N] = {0};
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            f[10 + d[i] - d[j]]++;
        }
    }

    n /= 2;
    long* g = (long*)calloc(1, sizeof(long));
    g[0] = 1;

    for (int D = 17; D >= 0; D--) {
        g = clean(id6(g, g, MOD, 3, 1, 1), &n);
        if (n << ~D < 0) {
            g = clean(id5(g, f, 1, MAX_N), &n);
        }
    }
    printf("%ld\n", n * 10 < sizeof(g) / sizeof(g[0]) ? g[n * 10] : 0);
    free(d);
    free(g);
}

int main() {
    solve();
    return 0;
}
