#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

static const int id10[] = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
static const int id4[] = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17};

long* id7(long* a, long* b, int P, int g, int* size_a, int* size_b);
long* id3(long* a, long* b, int* size_a, int* size_b);
long* id11(long* a, long* b, int* size_a, int* size_b);
long* multiply(long a[], long b[], int mod, int size_a, int size_b);
long* id3_v2(long* a, long* b, int USE, int mod, int* size_a, int* size_b);
long* id13(long* src, int n, int inverse, int P, int g);
long modh(long a, long M, int h, int mod);
long* id2(int* m, int n);
long* id8(int* u, int* m, long* gamma, int n);
long pow(long a, long n, long mod);
long invl(long a, long mod);
void solve();

int main() {
    solve();
    return 0;
}

long* id7(long* a, long* b, int P, int g, int* size_a, int* size_b) {
    int m = 1 << (32 - __builtin_clz(*size_a > *size_b ? *size_a : *size_b) - 2);
    long* fa = id13(a, m, 0, P, g);
    long* fb = (a == b) ? fa : id13(b, m, 0, P, g);
    for (int i = 0; i < m; i++) {
        fa[i] = (fa[i] * fb[i]) % P;
    }
    return id13(fa, m, 1, P, g);
}

long* id3(long* a, long* b, int* size_a, int* size_b) {
    int USE = 2;
    int m = 1 << (32 - __builtin_clz(*size_a > *size_b ? *size_a : *size_b) - 2);
    long* fs[USE];
    for (int k = 0; k < USE; k++) {
        int P = id10[k], g = id4[k];
        long* fa = id13(a, m, 0, P, g);
        long* fb = (a == b) ? fa : id13(b, m, 0, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = id13(fa, m, 1, P, g);
    }

    int mods[USE];
    long* gammas = id2(mods);
    int buf[USE];
    for (int i = 0; i < fs[0][0]; i++) {
        for (int j = 0; j < USE; j++) {
            buf[j] = (int) fs[j][i];
        }
        long* res = id8(buf, mods, gammas, USE);
        long ret = 0;
        for (int j = res[0] - 1; j >= 0; j--) {
            ret = (ret * mods[j] + res[j]) % mods[0];
        }
        fs[0][i] = ret;
    }
    return fs[0];
}

long* id11(long* a, long* b, int* size_a, int* size_b) {
    int m = 1 << (32 - __builtin_clz(*size_a > *size_b ? *size_a : *size_b) - 2);
    int P = id10[0], g = id4[0];
    long* fa = id13(a, m, 0, P, g);
    long* fb = (a == b) ? fa : id13(b, m, 0, P, g);
    for (int i = 0; i < m; i++) {
        fa[i] = (fa[i] * fb[i]) % P;
    }
    return id13(fa, m, 1, P, g);
}

long* multiply(long a[], long b[], int mod, int size_a, int size_b) {
    long v = mod;
    v *= mod;
    long* ans = (long*)calloc(size_a + size_b - 1, sizeof(long));
    for (int i = 0; i < size_a; i++) {
        for (int j = 0; j < size_b; j++) {
            ans[i + j] += a[i] * b[j];
            if (ans[i + j] >= v) {
                ans[i + j] -= v;
            }
        }
    }
    for (int i = 0; i < size_a + size_b - 1; i++) {
        ans[i] %= mod;
    }
    return ans;
}

long* id3_v2(long* a, long* b, int USE, int mod, int* size_a, int* size_b) {
    if (*size_a + *size_b <= 200) {
        return multiply(a, b, mod, *size_a, *size_b);
    }
    int m = 1 << (32 - __builtin_clz(*size_a > *size_b ? *size_a : *size_b) - 2);
    long* fs[USE];
    for (int k = 0; k < USE; k++) {
        int P = id10[k], g = id4[k];
        long* fa = id13(a, m, 0, P, g);
        long* fb = (a == b) ? fa : id13(b, m, 0, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = id13(fa, m, 1, P, g);
    }

    int mods[USE];
    long* gammas = id2(mods);
    int buf[USE];
    for (int i = 0; i < fs[0][0]; i++) {
        for (int j = 0; j < USE; j++) {
            buf[j] = (int) fs[j][i];
        }
        long* res = id8(buf, mods, gammas, USE);
        long ret = 0;
        for (int j = res[0] - 1; j >= 0; j--) {
            ret = (ret * mods[j] + res[j]) % mod;
        }
        fs[0][i] = ret;
    }
    return fs[0];
}

long* id13(long* src, int n, int inverse, int P, int g) {
    long* dst = (long*)malloc(n * sizeof(long));
    memcpy(dst, src, n * sizeof(long));

    int h = __builtin_ctz(n);
    long K = 1L << (__builtin_clz(P) + 1);
    int H = __builtin_ctz(K) * 2;
    long M = K * K / P;

    int* wws = (int*)malloc((1 << (h - 1)) * sizeof(int));
    long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
    long w = (1L << 32) % P;
    for (int k = 0; k < (1 << (h - 1)); k++) {
        wws[k] = (int)w;
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
        int rev = __builtin_bswap32(i) >> (32 - h);
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

    free(wws);
    return dst;
}

long modh(long a, long M, int h, int mod) {
    long r = a - ((M * (a & ((1L << 31) - 1)) >> 31) + M * (a >> 31) >> (h - 31)) * mod);
    return r < mod ? r : r - mod;
}

long* id2(int* m, int n) {
    long* gamma = (long*)malloc(n * sizeof(long));
    for (int k = 1; k < n; k++) {
        long prod = 1;
        for (int i = 0; i < k; i++) {
            prod = prod * m[i] % m[k];
        }
        gamma[k] = invl(prod, m[k]);
    }
    return gamma;
}

long* id8(int* u, int* m, long* gamma, int n) {
    long* v = (long*)malloc(n * sizeof(long));
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
        long d = a;
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
        int temp;
        scanf("%d", &temp);
        b[temp] = 1;
    }
    long mod = 998244353;
    long* ans = (long*)malloc(sizeof(long));
    ans[0] = 1;
    while (n > 0) {
        if (n & 1) {
            int size_a = 1, size_b = 10;
            ans = id7(ans, b, (int)mod, 3, &size_a, &size_b);
            int sz = size_a - 1;
            while (sz > 0 && ans[sz] == 0) {
                sz--;
            }
            if (size_a - sz > 100) {
                ans = realloc(ans, (sz + 1) * sizeof(long));
            }
        }
        n >>= 1;
        int size_b = 10;
        b = id7(b, b, (int)mod, 3, &size_b, &size_b);
        int sz = size_b - 1;
        while (sz > 0 && b[sz] == 0) {
            sz--;
        }
        if (size_b - sz > 100) {
            b = realloc(b, (sz + 1) * sizeof(long));
        }
    }
    long res = 0;
    for (int i = 0; i < size_a; i++) {
        res += (ans[i] * ans[i]) % mod;
        res %= mod;
    }
    printf("%ld\n", res);
    free(ans);
}
