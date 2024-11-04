#include <stdio.h>
#include <stdlib.h>

#define mod 998244353

long pow(long a, long n, long mod) {
    long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
        ret = ret * ret % mod;
        if (n << 63 - x < 0)
            ret = ret * a % mod;
    }
    return ret;
}

long invl(long a, long mod) {
    long b = mod;
    long p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

long modh(long a, long M, int h, int mod) {
    long r = a - ((M * (a & ((1L << 31) - 1)) >> 31) + M * (a >> 31) >> h - 31) * mod;
    return r < mod ? r : r - mod;
}

void clean(long *a, int length) {
    for (int i = length - 1; i >= 0; i--) {
        if (a[i] != 0) {
            if (i == length - 1) return;
            for (int j = i + 1; j < length; j++) a[j] = 0;
            return;
        }
    }
}

void id5(long *a, long *b, long *c, int length) {
    long big = 8L * mod * mod;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= big) c[i + j] -= big;
        }
    }
    for (int i = 0; i < length; i++) c[i] %= mod;
}

void id6(long *a, long *b, long *c, int P, int g, int length) {
    int m = 2;
    while (m < length) m <<= 1;
    long *fa = malloc(m * sizeof(long));
    long *fb = malloc(m * sizeof(long));
    for (int i = 0; i < m; i++) {
        fa[i] = i < length ? a[i] : 0;
        fb[i] = i < length ? b[i] : 0;
    }
    free(a);
    free(b);
    long dw = pow(g, P - 1 - (P - 1) / m, P);
    long *wws = malloc((m / 2) * sizeof(long));
    long w = 1;
    for (int k = 0; k < m / 2; k++) {
        wws[k] = w;
        w = modh(w * dw, P * P, 2 * __builtin_ctz(P), P);
    }
    for (int i = 0; i < m; i++) {
        if (i < __builtin_ctz(m)) {
            int j = __builtin_ctz(m) - 1 - __builtin_ctz(i);
            int k = (i ^ m >> 1) >> j;
            long u = (fa[i] - fa[i ^ m >> 1]) * wws[k] % P;
            fa[i] += fa[i ^ m >> 1];
            if (fa[i] >= P) fa[i] -= P;
            fa[i ^ m >> 1] = u;
        }
    }
    free(wws);
    dw = pow(g, (P - 1) / m, P);
    w = 1;
    for (int k = 0; k < m / 2; k++) {
        wws[k] = w;
        w = modh(w * dw, P * P, 2 * __builtin_ctz(P), P);
    }
    for (int i = 0; i < m; i++) {
        if (i < __builtin_ctz(m)) {
            int j = __builtin_ctz(m) - 1 - __builtin_ctz(i);
            int k = (i ^ m >> 1) >> j;
            long u = (fb[i] - fb[i ^ m >> 1]) * wws[k] % P;
            fb[i] += fb[i ^ m >> 1];
            if (fb[i] >= P) fb[i] -= P;
            fb[i ^ m >> 1] = u;
        }
    }
    free(wws);
    dw = pow(g, (P - 1) / m, P);
    w = 1;
    for (int k = 0; k < m / 2; k++) {
        wws[k] = w;
        w = modh(w * dw, P * P, 2 * __builtin_ctz(P), P);
    }
    for (int i = 0; i < m; i++) {
        if (i < __builtin_ctz(m)) {
            int j = __builtin_ctz(m) - 1 - __builtin_ctz(i);
            int k = (i ^ m >> 1) >> j;
            long u = (fa[i] - fa[i ^ m >> 1]) * wws[k] % P;
            fa[i] += fa[i ^ m >> 1];
            if (fa[i] >= P) fa[i] -= P;
            fa[i ^ m >> 1] = u;
        }
    }
    free(wws);
    for (int i = 0; i < m; i++) {
        if (fa[i] >= P) fa[i] -= P;
    }
    for (int i = 0; i < m; i++) {
        int rev = __builtin_bitreverse32(i) >> -__builtin_ctz(m);
        if (i < rev) {
            long d = fa[i];
            fa[i] = fa[rev];
            fa[rev] = d;
        }
    }
    for (int i = 0; i < length; i++) c[i] = fa[i];
    free(fa);
    free(fb);
}

void id3(long *a, long *b, long *c, int USE, int mod, int length) {
    int m = 2;
    while (m < length) m <<= 1;
    long *fa = malloc(m * sizeof(long));
    long *fb = malloc(m * sizeof(long));
    for (int i = 0; i < m; i++) {
        fa[i] = i < length ? a[i] : 0;
        fb[i] = i < length ? b[i] : 0;
    }
    free(a);
    free(b);
    int *mods = malloc(USE * sizeof(int));
    long *gammas = malloc(USE * sizeof(long));
    for (int i = 0; i < USE; i++) {
        mods[i] = 1053818881;
        gammas[i] = 1051721729;
    }
    int *buf = malloc(USE * sizeof(int));
    for (int i = 0; i < m; i++) {
        if (i < __builtin_ctz(m)) {
            int j = __builtin_ctz(m) - 1 - __builtin_ctz(i);
            int k = (i ^ m >> 1) >> j;
            long u = (fa[i] - fa[i ^ m >> 1]) * gammas[k] % mods[k];
            fa[i] += fa[i ^ m >> 1];
            if (fa[i] >= mods[k]) fa[i] -= mods[k];
            fa[i ^ m >> 1] = u;
        }
    }
    for (int i = 0; i < m; i++) {
        if (fa[i] >= mods[0]) fa[i] -= mods[0];
    }
    for (int i = 0; i < m; i++) {
        int rev = __builtin_bitreverse32(i) >> -__builtin_ctz(m);
        if (i < rev) {
            long d = fa[i];
            fa[i] = fa[rev];
            fa[rev] = d;
        }
    }
    for (int i = 0; i < length; i++) {
        buf[0] = fa[i];
        long *res = id7(buf, mods, gammas, USE);
        long ret = 0;
        for (int j = USE - 1; j >= 0; j--) ret = ret * mods[j] + res[j];
        fa[i] = ret;
    }
    for (int i = 0; i < length; i++) c[i] = fa[i];
    free(fa);
    free(fb);
    free(mods);
    free(gammas);
    free(buf);
}

long *id7(int *u, int *m, long *gamma, int USE) {
    int n = USE;
    long *v = malloc(n * sizeof(long));
    v[0] = u[0];
    for (int k = 1; k < n; k++) {
        long temp = v[k - 1];
        for (int j = k - 2; j >= 0; j--) {
            temp = (temp * m[j] + v[j]) % m[k];
        }
        v[k] = (u[k] - temp) * gamma[k] % m[k];
        if (v[k] < 0) v[k] += m[k];
    }
    return v;
}

void solve() {
    int n, K;
    scanf("%d%d", &n, &K);
    int *d = malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) scanf("%d", &d[i]);
    long *f = calloc(20, sizeof(long));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            f[10 + d[i] - d[j]]++;
        }
    }
    n /= 2;
    long *g = calloc(1, sizeof(long));
    g[0] = 1;
    for (int D = 17; D >= 0; D--) {
        g = realloc(g, (n << ~D) * sizeof(long));
        if (n << ~D < 0) {
            long *temp = calloc((n << ~D) * sizeof(long), sizeof(long));
            id5(g, f, temp, (n << ~D) + 1);
            free(g);
            g = temp;
        }
    }
    printf("%ld\n", n * 10 < (n << 1) ? g[n * 10] : 0);
    free(d);
    free(f);
    free(g);
}

int main() {
    solve();
    return 0;
}
