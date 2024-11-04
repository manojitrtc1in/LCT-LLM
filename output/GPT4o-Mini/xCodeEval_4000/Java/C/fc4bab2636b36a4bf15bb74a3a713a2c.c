#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define MAX_N 20
#define USE 2

long f[MAX_N];
long g[1];
int NTTPrimes[10] = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
int NTTPrimitiveRoots[10] = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17};

long modh(long a, long M, int h, int mod) {
    long r = a - ((M * (a & ((1L << 31) - 1)) >> 31) + M * (a >> 31) >> h - 31) * mod);
    return r < mod ? r : r - mod;
}

long pow(long a, long n, long mod) {
    long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
        ret = ret * ret % mod;
        if (n << (63 - x) < 0)
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

long* nttmb(long* src, int n, int inverse, int P, int g) {
    long* dst = (long*)malloc(n * sizeof(long));
    memcpy(dst, src, n * sizeof(long));

    int h = __builtin_ctz(n);
    long K = (1L << (__builtin_clz(P) + 1));
    int H = __builtin_ctzll(K) * 2;
    long M = K * K / P;

    long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
    long* wws = (long*)malloc((1 << (h - 1)) * sizeof(long));
    long w = (1L << 32) % P;
    for (int k = 0; k < (1 << (h - 1)); k++) {
        wws[k] = w;
        w = modh(w * dw, M, H, P);
    }
    long J = invl(P, 1L << 32);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (1 << i); j++) {
            for (int k = 0, s = j << (h - i), t = s | (1 << (h - i - 1)); k < (1 << (h - i - 1)); k++, s++, t++) {
                long u = (dst[s] - dst[t] + 2 * P) * wws[k];
                dst[s] += dst[t];
                if (dst[s] >= 2 * P) dst[s] -= 2 * P;

                long Q = (u << 32) * J >> 32;
                dst[t] = (u >> 32) - (Q * P >> 32) + P;
            }
        }
        if (i < h - 1) {
            for (int k = 0; k < (1 << (h - i - 2)); k++) wws[k] = wws[k * 2];
        }
    }
    for (int i = 0; i < n; i++) {
        if (dst[i] >= P) dst[i] -= P;
    }
    for (int i = 0; i < n; i++) {
        int rev = __builtin_bswap32(i) >> -h;
        if (i < rev) {
            long d = dst[i]; dst[i] = dst[rev]; dst[rev] = d;
        }
    }

    if (inverse) {
        long in = invl(n, P);
        for (int i = 0; i < n; i++) dst[i] = modh(dst[i] * in, M, H, P);
    }

    free(wws);
    return dst;
}

long* convoluteSimply(long* a, long* b, int P, int g) {
    int m = 1 << (__builtin_clzll(MAX_N) + 1);
    long* fa = nttmb(a, m, 0, P, g);
    long* fb = a == b ? fa : nttmb(b, m, 0, P, g);
    for (int i = 0; i < m; i++) {
        fa[i] = fa[i] * fb[i] % P;
    }
    return nttmb(fa, m, 1, P, g);
}

void solve() {
    int n, K;
    scanf("%d %d", &n, &K);
    int* d = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        scanf("%d", &d[i]);
    }

    memset(f, 0, sizeof(f));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            f[10 + d[i] - d[j]]++;
        }
    }

    n /= 2;
    g[0] = 1;
    for (int D = 17; D >= 0; D--) {
        long* temp = convoluteSimply(g, g, MOD, 3);
        free(g);
        g = temp;
        if (n << ~D < 0) {
            long* temp2 = convoluteSimply(g, f, MOD, 3);
            free(g);
            g = temp2;
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
