#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void multiply(long *a, long *b, int len_a, int len_b, int mod, long *ans) {
    long v = mod;
    v *= mod;
    int ans_len = len_a + len_b - 1;
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            ans[i + j] += a[i] * b[j];
            if (ans[i + j] >= v)
                ans[i + j] -= v;
        }
    }
    for (int i = 0; i < ans_len; i++)
        ans[i] %= mod;
}

void polynomial_multiply(long *a, long *b, int len_a, int len_b, int mod, long *ans) {
    int m = MAX(2, pow(2, ceil(log2(MAX(len_a, len_b) - 1))) + 2);
    long *fa = (long *)malloc(m * sizeof(long));
    long *fb = (a == b) ? fa : (long *)malloc(m * sizeof(long));
    for (int i = 0; i < len_a; i++)
        fa[i] = a[i];
    for (int i = len_a; i < m; i++)
        fa[i] = 0;
    for (int i = 0; i < len_b; i++)
        fb[i] = b[i];
    for (int i = len_b; i < m; i++)
        fb[i] = 0;
    multiply(fa, fb, m, m, mod, ans);
    free(fa);
    if (a != b)
        free(fb);
}

void polynomial_power(long *a, int len_a, int n, int mod, long *ans) {
    int m = MAX(2, pow(2, ceil(log2(len_a - 1))) + 2);
    long *fa = (long *)malloc(m * sizeof(long));
    for (int i = 0; i < len_a; i++)
        fa[i] = a[i];
    for (int i = len_a; i < m; i++)
        fa[i] = 0;
    for (int i = 0; i < n; i++)
        polynomial_multiply(fa, fa, m, m, mod, fa);
    for (int i = 0; i < len_a; i++)
        ans[i] = fa[i];
    free(fa);
}

void polynomial_inverse(long *a, int len_a, int mod, long *ans) {
    int n = len_a;
    long *v = (long *)malloc(n * sizeof(long));
    v[0] = a[0];
    for (int k = 1; k < n; k++) {
        long prod = 1;
        for (int i = 0; i < k; i++)
            prod = (prod * a[i]) % a[k];
        ans[k] = (prod == 0) ? 0 : ((prod == 1) ? 1 : (mod - (mod / a[k]) * ans[mod % a[k]] % mod));
        v[k] = (a[k] * ans[k]) % mod;
    }
    for (int k = 1; k < n; k++) {
        long temp = v[k - 1];
        for (int j = k - 2; j >= 0; j--)
            temp = (temp * a[j] + v[j]) % a[k];
        ans[k] = (v[k] - temp) * ans[k] % a[k];
        if (ans[k] < 0)
            ans[k] += a[k];
    }
    free(v);
}

void polynomial_mod(long *a, int len_a, int mod) {
    for (int i = 0; i < len_a; i++)
        a[i] %= mod;
}

void polynomial_print(long *a, int len_a) {
    for (int i = 0; i < len_a; i++)
        printf("%ld ", a[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    n /= 2;
    long b[10] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[x] = 1;
    }
    int mod = 998244353;
    long ans[101] = {1};
    while (n > 0) {
        if (n & 1) {
            long temp[101] = {0};
            polynomial_multiply(ans, b, 101, 10, mod, temp);
            for (int i = 0; i < 101; i++)
                ans[i] = temp[i];
            int sz = 100;
            while (sz > 0 && ans[sz] == 0)
                sz--;
            if (101 - sz > 100)
                polynomial_mod(ans, sz + 1, mod);
        }
        n >>= 1;
        long temp[10] = {0};
        polynomial_multiply(b, b, 10, 10, mod, temp);
        for (int i = 0; i < 10; i++)
            b[i] = temp[i];
        int sz = 9;
        while (sz > 0 && b[sz] == 0)
            sz--;
        if (10 - sz > 100)
            polynomial_mod(b, sz + 1, mod);
    }
    long res = 0;
    for (int i = 0; i < 101; i++) {
        res += ans[i] * ans[i];
        res %= mod;
    }
    printf("%ld\n", res);
    return 0;
}
