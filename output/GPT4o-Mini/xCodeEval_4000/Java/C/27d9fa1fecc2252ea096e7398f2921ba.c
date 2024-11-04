#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NTT_PRIMES 10
#define MAX_SIZE 200

const long NTTPrimes[MAX_NTT_PRIMES] = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
const long NTTPrimitiveRoots[MAX_NTT_PRIMES] = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17};

long* convoluteSimply(long* a, long* b, int P, int g, int* resultSize);
long* convolute(long* a, long* b, int USE, int mod, int* resultSize);
long* multiply(long a[], long b[], int mod, int* resultSize);
long* nttmb(long* src, int n, int inverse, int P, int g, int* resultSize);
long modh(long a, long M, int h, int mod);
long* garnerPrepare(int* m, int n);
long* garnerBatch(int* u, int* m, long* gamma, int n);
long pow(long a, long n, long mod);
long invl(long a, long mod);
void solve();

int main() {
    solve();
    return 0;
}

long* convoluteSimply(long* a, long* b, int P, int g, int* resultSize) {
    int m = 1 << (32 - __builtin_clz(MAX(a[0], b[0]) - 1));
    long* fa = nttmb(a, m, 0, P, g, resultSize);
    long* fb = (a == b) ? fa : nttmb(b, m, 0, P, g, resultSize);
    for (int i = 0; i < m; i++) {
        fa[i] = (fa[i] * fb[i]) % P;
    }
    return nttmb(fa, m, 1, P, g, resultSize);
}

long* convolute(long* a, long* b, int USE, int mod, int* resultSize) {
    if (a[0] + b[0] <= 200) {
        return multiply(a, b, mod, resultSize);
    }
    int m = 1 << (32 - __builtin_clz(MAX(a[0], b[0]) - 1));
    long* fs[USE];
    for (int k = 0; k < USE; k++) {
        int P = NTTPrimes[k], g = NTTPrimitiveRoots[k];
        long* fa = nttmb(a, m, 0, P, g, resultSize);
        long* fb = (a == b) ? fa : nttmb(b, m, 0, P, g, resultSize);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = nttmb(fa, m, 1, P, g, resultSize);
    }

    int mods[USE];
    long* gammas = garnerPrepare(mods, USE);
    int buf[USE];
    for (int i = 0; i < fs[0][0]; i++) {
        for (int j = 0; j < USE; j++) {
            buf[j] = (int) fs[j][i];
        }
        long* res = garnerBatch(buf, mods, gammas, USE);
        long ret = 0;
        for (int j = res[0] - 1; j >= 0; j--) {
            ret = (ret * mods[j] + res[j]) % mod;
        }
        fs[0][i] = ret;
    }
    return fs[0];
}

long* multiply(long a[], long b[], int mod, int* resultSize) {
    long v = mod;
    v *= mod;
    long* ans = (long*)calloc(a[0] + b[0] - 1, sizeof(long));
    for (int i = 0; i < a[0]; i++) {
        for (int j = 0; j < b[0]; j++) {
            ans[i + j] += a[i] * b[j];
            if (ans[i + j] >= v) {
                ans[i + j] -= v;
            }
        }
    }
    for (int i = 0; i < ans[0]; i++) {
        ans[i] %= mod;
    }
    *resultSize = a[0] + b[0] - 1;
    return ans;
}

long* nttmb(long* src, int n, int inverse, int P, int g, int* resultSize) {
    long* dst = (long*)calloc(n, sizeof(long));
    memcpy(dst, src, sizeof(long) * n);

    int h = __builtin_ctz(n);
    long K = 1 << (__builtin_clz(P) + 1);
    int H = __builtin_ctz(K) * 2;
    long M = K * K / P;

    long* wws = (long*)calloc(1 << (h - 1), sizeof(long));
    long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
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
                if (dst[s] >= 2 * P) {
                    dst[s] -= 2 * P;
                }

                long Q = (u << 32) * J >> 32;
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
        int rev = __builtin_bitreverse32(i) >> -h;
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

    *resultSize = n;
    return dst;
}

long modh(long a, long M, int h, int mod) {
    long r = a - ((M * (a & ((1L << 31) - 1)) >> 31) + M * (a >> 31) >> (h - 31)) * mod);
    return r < mod ? r : r - mod;
}

long* garnerPrepare(int* m, int n) {
    long* gamma = (long*)calloc(n, sizeof(long));
    for (int k = 1; k < n; k++) {
        long prod = 1;
        for (int i = 0; i < k; i++) {
            prod = prod * m[i] % m[k];
        }
        gamma[k] = invl(prod, m[k]);
    }
    return gamma;
}

long* garnerBatch(int* u, int* m, long* gamma, int n) {
    long* v = (long*)calloc(n, sizeof(long));
    v[0] = u[0];
    for (int k = 1; k < n; k++) {
        long temp = v[k - 1];
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

long pow(long a, long n, long mod) {
    long ret = 1;
    int x = 63 - __builtin_clz(n);
    for (; x >= 0; x--) {
        ret = ret * ret % mod;
        if (n << (63 - x) < 0) {
            ret = ret * a % mod;
        }
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

void solve() {
    int n;
    scanf("%d", &n);
    n /= 2;
    long b[10] = {0};
    for (int i = scanf("%d", &n); n > 0; n--) {
        int x;
        scanf("%d", &x);
        b[x] = 1;
    }
    long mod = 998244353;
    long* ans = (long*)calloc(1, sizeof(long));
    ans[0] = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            int resultSize;
            ans = convoluteSimply(ans, b, (int)mod, 3, &resultSize);
            int sz = resultSize - 1;
            while (sz > 0 && ans[sz] == 0) {
                sz--;
            }
            if (resultSize - sz > 100) {
                ans = realloc(ans, (sz + 1) * sizeof(long));
            }
        }
        n >>= 1;
        int resultSize;
        b = convoluteSimply(b, b, (int)mod, 3, &resultSize);
        int sz = resultSize - 1;
        while (sz > 0 && b[sz] == 0) {
            sz--;
        }
        if (resultSize - sz > 100) {
            b = realloc(b, (sz + 1) * sizeof(long));
        }
    }
    long res = 0;
    for (int i = 0; i < ans[0]; i++) {
        res += (ans[i] * ans[i]);
        res %= mod;
    }
    printf("%ld\n", res);
}
