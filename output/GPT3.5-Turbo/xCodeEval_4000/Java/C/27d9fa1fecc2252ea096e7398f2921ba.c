#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NTTPrimesLength 10
#define NTTPrimitiveRootsLength 10

int NTTPrimes[NTTPrimesLength] = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
int NTTPrimitiveRoots[NTTPrimitiveRootsLength] = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17};

long long pow_mod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long invl(long long a, long long mod) {
    long long b = mod;
    long long p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        long long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

void nttmb(long long *src, int n, int inverse, int P, int g) {
    long long *dst = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }

    int h = __builtin_ctz(n);
    long long K = (1LL << (32 - __builtin_clz(P))) << 1;
    int H = __builtin_ctzll(K) * 2;
    long long M = K * K / P;

    int wwsLength = 1 << (h - 1);
    int *wws = (int *)malloc(wwsLength * sizeof(int));
    long long dw = inverse ? pow_mod(g, P - 1 - (P - 1) / n, P) : pow_mod(g, (P - 1) / n, P);
    long long w = (1LL << 32) % P;
    for (int k = 0; k < wwsLength; k++) {
        wws[k] = w;
        w = (w * dw) % P;
    }

    long long J = invl(P, 1LL << 32);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (1 << i); j++) {
            for (int k = 0, s = j << (h - i), t = s | (1 << (h - i - 1)); k < (1 << (h - i - 1)); k++, s++, t++) {
                long long u = (dst[s] - dst[t] + 2 * P) * wws[k];
                dst[s] += dst[t];
                if (dst[s] >= 2 * P) {
                    dst[s] -= 2 * P;
                }

                long long Q = (u << 32) * J >> 32;
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
        if (dst[i] >= P) {
            dst[i] -= P;
        }
    }
    for (int i = 0; i < n; i++) {
        int rev = __builtin_bitreverse32(i) >> (32 - h);
        if (i < rev) {
            long long d = dst[i];
            dst[i] = dst[rev];
            dst[rev] = d;
        }
    }

    if (inverse) {
        long long in = invl(n, P);
        for (int i = 0; i < n; i++) {
            dst[i] = (dst[i] * in) % P;
        }
    }

    for (int i = 0; i < n; i++) {
        src[i] = dst[i];
    }

    free(dst);
    free(wws);
}

void convoluteSimply(long long *a, long long *b, int P, int g, int n, long long *result) {
    int m = fmax(2, 1 << (32 - __builtin_clz(fmax(n, 1)) - 1) << 2);
    long long *fa = (long long *)malloc(m * sizeof(long long));
    long long *fb = (long long *)malloc(m * sizeof(long long));
    for (int i = 0; i < m; i++) {
        fa[i] = i < n ? a[i] : 0;
        fb[i] = i < n ? b[i] : 0;
    }

    nttmb(fa, m, 0, P, g);
    nttmb(fb, m, 0, P, g);
    for (int i = 0; i < m; i++) {
        fa[i] = (fa[i] * fb[i]) % P;
    }
    nttmb(fa, m, 1, P, g);

    for (int i = 0; i < n; i++) {
        result[i] = fa[i];
    }

    free(fa);
    free(fb);
}

void convolute(long long *a, long long *b, int n, long long *result) {
    int USE = 2;
    int m = fmax(2, 1 << (32 - __builtin_clz(fmax(n, 1)) - 1) << 2);
    long long **fs = (long long **)malloc(USE * sizeof(long long *));
    for (int k = 0; k < USE; k++) {
        int P = NTTPrimes[k];
        int g = NTTPrimitiveRoots[k];
        long long *fa = (long long *)malloc(m * sizeof(long long));
        long long *fb = (long long *)malloc(m * sizeof(long long));
        for (int i = 0; i < m; i++) {
            fa[i] = i < n ? a[i] : 0;
            fb[i] = i < n ? b[i] : 0;
        }

        nttmb(fa, m, 0, P, g);
        nttmb(fb, m, 0, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = (long long *)malloc(m * sizeof(long long));
        nttmb(fa, m, 1, P, g);

        free(fa);
        free(fb);
    }

    int *mods = (int *)malloc(USE * sizeof(int));
    for (int i = 0; i < USE; i++) {
        mods[i] = NTTPrimes[i];
    }
    long long *gammas = (long long *)malloc(USE * sizeof(long long));
    for (int i = 0; i < USE; i++) {
        int *m = (int *)malloc(i * sizeof(int));
        for (int j = 0; j < i; j++) {
            m[j] = NTTPrimes[j];
        }
        gammas[i] = garnerPrepare(m);
        free(m);
    }

    int *buf = (int *)malloc(USE * sizeof(int));
    for (int i = 0; i < fs[0].length; i++) {
        for (int j = 0; j < USE; j++) {
            buf[j] = (int)fs[j][i];
        }
        long long *res = garnerBatch(buf, mods, gammas);
        long long ret = 0;
        for (int j = res.length - 1; j >= 0; j--) {
            ret = (ret * mods[j] + res[j]) % mod;
        }
        fs[0][i] = ret;
    }

    for (int i = 0; i < n; i++) {
        result[i] = fs[0][i];
    }

    for (int i = 0; i < USE; i++) {
        free(fs[i]);
    }
    free(fs);
    free(mods);
    free(gammas);
    free(buf);
}

void multiply(long long *a, long long *b, int mod, int n, long long *result) {
    long long v = mod;
    v *= mod;
    for (int i = 0; i < n + m - 1; i++) {
        result[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i + j] += a[i] * b[j];
            if (result[i + j] >= v) {
                result[i + j] -= v;
            }
        }
    }
    for (int i = 0; i < n + m - 1; i++) {
        result[i] %= mod;
    }
}

void convolute1(long long *a, long long *b, int n, long long *result) {
    int m = fmax(2, 1 << (32 - __builtin_clz(fmax(n, 1)) - 1) << 2);
    int P = NTTPrimes[0];
    int g = NTTPrimitiveRoots[0];
    long long *fa = (long long *)malloc(m * sizeof(long long));
    long long *fb = (long long *)malloc(m * sizeof(long long));
    for (int i = 0; i < m; i++) {
        fa[i] = i < n ? a[i] : 0;
        fb[i] = i < n ? b[i] : 0;
    }

    nttmb(fa, m, 0, P, g);
    nttmb(fb, m, 0, P, g);
    for (int i = 0; i < m; i++) {
        fa[i] = (fa[i] * fb[i]) % P;
    }
    nttmb(fa, m, 1, P, g);

    for (int i = 0; i < n; i++) {
        result[i] = fa[i];
    }

    free(fa);
    free(fb);
}

void convolute(long long *a, long long *b, int USE, int mod, int n, long long *result) {
    if (n + m <= 200) {
        multiply(a, b, mod, n, result);
        return;
    }
    int m = fmax(2, 1 << (32 - __builtin_clz(fmax(n, 1)) - 1) << 2);
    long long **fs = (long long **)malloc(USE * sizeof(long long *));
    for (int k = 0; k < USE; k++) {
        int P = NTTPrimes[k];
        int g = NTTPrimitiveRoots[k];
        long long *fa = (long long *)malloc(m * sizeof(long long));
        long long *fb = (long long *)malloc(m * sizeof(long long));
        for (int i = 0; i < m; i++) {
            fa[i] = i < n ? a[i] : 0;
            fb[i] = i < n ? b[i] : 0;
        }

        nttmb(fa, m, 0, P, g);
        nttmb(fb, m, 0, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = (long long *)malloc(m * sizeof(long long));
        nttmb(fa, m, 1, P, g);

        free(fa);
        free(fb);
    }

    int *mods = (int *)malloc(USE * sizeof(int));
    for (int i = 0; i < USE; i++) {
        mods[i] = NTTPrimes[i];
    }
    long long *gammas = (long long *)malloc(USE * sizeof(long long));
    for (int i = 0; i < USE; i++) {
        int *m = (int *)malloc(i * sizeof(int));
        for (int j = 0; j < i; j++) {
            m[j] = NTTPrimes[j];
        }
        gammas[i] = garnerPrepare(m);
        free(m);
    }

    int *buf = (int *)malloc(USE * sizeof(int));
    for (int i = 0; i < fs[0].length; i++) {
        for (int j = 0; j < USE; j++) {
            buf[j] = (int)fs[j][i];
        }
        long long *res = garnerBatch(buf, mods, gammas);
        long long ret = 0;
        for (int j = res.length - 1; j >= 0; j--) {
            ret = (ret * mods[j] + res[j]) % mod;
        }
        fs[0][i] = ret;
    }

    for (int i = 0; i < n; i++) {
        result[i] = fs[0][i];
    }

    for (int i = 0; i < USE; i++) {
        free(fs[i]);
    }
    free(fs);
    free(mods);
    free(gammas);
    free(buf);
}

long long *garnerPrepare(int *m, int n) {
    long long *gamma = (long long *)malloc(n * sizeof(long long));
    for (int k = 1; k < n; k++) {
        long long prod = 1;
        for (int i = 0; i < k; i++) {
            prod = (prod * m[i]) % m[k];
        }
        gamma[k] = invl(prod, m[k]);
    }
    return gamma;
}

long long *garnerBatch(int *u, int *m, long long *gamma, int n) {
    long long *v = (long long *)malloc(n * sizeof(long long));
    v[0] = u[0];
    for (int k = 1; k < n; k++) {
        long long temp = v[k - 1];
        for (int j = k - 2; j >= 0; j--) {
            temp = (temp * m[j] + v[j]) % m[k];
        }
        v[k] = (u[k] - temp) * gamma[k] % m[k];
        if (v[k] < 0) {
            v[k] += m[k];
        }
    }
    return v;
}

void solve() {
    int n;
    scanf("%d", &n);
    long long b[10] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[x] = 1;
    }
    long long mod = 998244353;
    long long ans[1] = {1};
    while (n > 0) {
        if (n & 1) {
            convoluteSimply(ans, b, mod, 3, sizeof(ans) / sizeof(ans[0]), ans);
            int sz = sizeof(ans) / sizeof(ans[0]) - 1;
            while (sz > 0 && ans[sz] == 0) {
                sz--;
            }
            if (sizeof(ans) / sizeof(ans[0]) - sz > 100) {
                ans = (long long *)realloc(ans, (sz + 1) * sizeof(long long));
            }
        }
        n >>= 1;
        convoluteSimply(b, b, mod, 3, sizeof(b) / sizeof(b[0]), b);
        int sz = sizeof(b) / sizeof(b[0]) - 1;
        while (sz > 0 && b[sz] == 0) {
            sz--;
        }
        if (sizeof(b) / sizeof(b[0]) - sz > 100) {
            b = (long long *)realloc(b, (sz + 1) * sizeof(long long));
        }
    }
    long long res = 0;
    for (int i = 0; i < sizeof(ans) / sizeof(ans[0]); i++) {
        res += ans[i] * ans[i];
        res %= mod;
    }
    printf("%lld\n", res);
}

int main() {
    solve();
    return 0;
}
