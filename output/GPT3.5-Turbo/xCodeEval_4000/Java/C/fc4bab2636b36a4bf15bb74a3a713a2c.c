#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    long r = a - ((M * (a & ((1L << 31) - 1))) >> 31) * mod;
    return r < mod ? r : r - mod;
}

void nttmb(long *src, int n, bool inverse, int P, int g) {
    long *dst = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }

    int h = __builtin_ctz(n);
    long K = 1L << (31 - __builtin_clz(P) + 1);
    int H = __builtin_ctzll(K) * 2;
    long M = K * K / P;

    long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
    long *wws = malloc((1 << (h - 1)) * sizeof(long));
    long w = 1;
    for (int k = 0; k < (1 << (h - 1)); k++) {
        wws[k] = (w << 32) / P;
        w = modh(w * dw, M, H, P);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (1 << i); j++) {
            for (int k = 0, s = j << (h - i), t = s | (1 << (h - i - 1)); k < (1 << (h - i - 1)); k++, s++, t++) {
                long u = (dst[s] - dst[t] + 2 * P) * wws[k];
                dst[s] += dst[t];
                if (dst[s] >= 2 * P) dst[s] -= 2 * P;

                long Q = (u << 32) * invl(P, 1L << 32) >> 32;
                dst[t] = (u >> 32) - (Q * P >> 32) + P;
            }
        }
        if (i < h - 1) {
            for (int k = 0; k < (1 << (h - i - 2)); k++) {
                wws[k] = wws[k * 2];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dst[i] >= P) dst[i] -= P;
    }
    for (int i = 0; i < n; i++) {
        int rev = __builtin_bitreverse32(i) >> (32 - h);
        if (i < rev) {
            long d = dst[i];
            dst[i] = dst[rev];
            dst[rev] = d;
        }
    }

    if (inverse) {
        long in = invl(n, P);
        for (int i = 0; i < n; i++) {
            dst[i] = modh(dst[i] * in, M, H, P);
        }
    }

    for (int i = 0; i < n; i++) {
        src[i] = dst[i];
    }

    free(dst);
    free(wws);
}

void convoluteSimply(long *a, long *b, int n, int P, int g) {
    int m = 2;
    while (m < n) {
        m <<= 1;
    }

    long *fa = malloc(m * sizeof(long));
    long *fb = malloc(m * sizeof(long));
    for (int i = 0; i < m; i++) {
        fa[i] = i < n ? a[i] : 0;
        fb[i] = i < n ? b[i] : 0;
    }

    nttmb(fa, m, false, P, g);
    nttmb(fb, m, false, P, g);

    for (int i = 0; i < m; i++) {
        fa[i] = fa[i] * fb[i] % P;
    }

    nttmb(fa, m, true, P, g);

    for (int i = 0; i < n; i++) {
        a[i] = fa[i];
    }

    free(fa);
    free(fb);
}

void convolute(long *a, long *b, int n, int P, int g) {
    int m = 2;
    while (m < n) {
        m <<= 1;
    }

    long **fs = malloc(2 * sizeof(long *));
    for (int k = 0; k < 2; k++) {
        int P = 998244353, g = 3;
        long *fa = malloc(m * sizeof(long));
        long *fb = malloc(m * sizeof(long));
        for (int i = 0; i < m; i++) {
            fa[i] = i < n ? a[i] : 0;
            fb[i] = i < n ? b[i] : 0;
        }

        nttmb(fa, m, false, P, g);
        nttmb(fb, m, false, P, g);

        for (int i = 0; i < m; i++) {
            fa[i] = fa[i] * fb[i] % P;
        }

        nttmb(fa, m, true, P, g);

        fs[k] = malloc(n * sizeof(long));
        for (int i = 0; i < n; i++) {
            fs[k][i] = fa[i];
        }

        free(fa);
        free(fb);
    }

    int mods[2] = {998244353, 985661441};
    long *gammas = malloc(2 * sizeof(long));
    gammas[0] = 1;
    gammas[1] = invl(mods[0], mods[1]);

    int buf[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            buf[j] = (int)fs[j][i];
        }
        long *res = garnerBatch(buf, mods, gammas);
        long ret = 0;
        for (int j = 1; j >= 0; j--) {
            ret = ret * mods[j] + res[j];
        }
        a[i] = ret;
    }

    for (int k = 0; k < 2; k++) {
        free(fs[k]);
    }
    free(fs);
    free(gammas);
}

long *garnerPrepare(int *m, int n) {
    long *gamma = malloc(n * sizeof(long));
    for (int k = 1; k < n; k++) {
        long prod = 1;
        for (int i = 0; i < k; i++) {
            prod = prod * m[i] % m[k];
        }
        gamma[k] = invl(prod, m[k]);
    }
    return gamma;
}

long *garnerBatch(int *u, int *m, long *gamma, int n) {
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

void mulnaive(long *a, long *b, int n) {
    long *c = calloc(2 * n - 1, sizeof(long));
    long big = 8L * mod * mod;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= big) c[i + j] -= big;
        }
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        c[i] %= mod;
    }

    for (int i = 0; i < n; i++) {
        a[i] = c[i];
    }

    free(c);
}

long *clean(long *a, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != 0) {
            if (i == n - 1) return a;
            long *res = malloc((i + 1) * sizeof(long));
            for (int j = 0; j <= i; j++) {
                res[j] = a[j];
            }
            return res;
        }
    }
    return calloc(1, sizeof(long));
}

void solve() {
    int n, K;
    scanf("%d%d", &n, &K);
    int *d = malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        scanf("%d", &d[i]);
    }

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
        g = clean(convoluteSimply(g, g, mod, 3), n * 10);
        if (n << ~D < 0) {
            g = clean(mulnaive(g, f, n * 10), n * 10);
        }
    }
    printf("%ld\n", n * 10 < g[0] ? g[0] : 0);

    free(d);
    free(f);
    free(g);
}

int main() {
    solve();
    return 0;
}
