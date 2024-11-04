#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 998244353
#define ROOT 646108188
#define ROOT_INV 208611436
#define ORDER 8388608
#define W4 239943295
#define W4_INV 748683265

void swap(long *a, int i, int j) {
    long temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void fft(long *a, int n, int isInvertedFFT) {
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; (j & bit) > 0; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j) {
            swap(a, i, j);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        long wlen = isInvertedFFT ? ROOT_INV : ROOT;
        for (int i = len; i < ORDER; i <<= 1)
            wlen = wlen * wlen % MOD;

        for (int i = 0; i < n; i += len) {
            long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long u = a[i+j];
                long v = a[i+j+len/2] * w % MOD;
                a[i+j] =  u + v < MOD ? u + v : u + v - MOD;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
                w = w * wlen % MOD;
            }
        }
    }

    if (isInvertedFFT) {
        long inv = 8388608;
        for(int i=0; i<n; i++)
            a[i] = a[i]*inv%MOD;
    }
}

void square(long *a, int n) {
    fft(a, n, 0);
    for (int i = 0; i < n; i++)
        a[i] = a[i]*a[i] % MOD;
    fft(a, n, 1);
}

long* multiplyPolynomial(long *a, long *b, int n) {
    int len = 1;
    while (len < 2*n)
        len <<= 1;
    long *fa = (long*)malloc(len * sizeof(long));
    long *fb = (long*)malloc(len * sizeof(long));
    for (int i = 0; i < len; i++) {
        fa[i] = (i < n) ? a[i] : 0;
        fb[i] = (i < n) ? b[i] : 0;
    }

    fft(fa, len, 0);
    fft(fb, len, 0);
    for (int i = 0; i < len; i++)
        fa[i] = fa[i]*fb[i] % MOD;
    fft(fa, len, 1);

    return fa;
}

long pow(int a, int k, long p) {
    long m = k;
    long ans = 1;

    long curr = a;

    while(m > 0) {
        if( (m&1) == 1 ) {
            ans *= curr;
            ans %= p;
        }
        m >>= 1;
        curr *= curr;
        curr %= p;
    }
    return ans;
}

long inverse(int a, long p) {
    return pow(a, p-2, p);
}

int main() {
    int n, k, f;
    scanf("%d %d %d", &n, &k, &f);

    long ans = 0;

    int len = 1;
    while (len < f+2 + f+2)
        len <<= 1;
    long *ways = (long*)malloc(len * sizeof(long));
    long *suffix = (long*)malloc((f+2) * sizeof(long));

    for(int i=0; i<=k && i<=f; i++)
        ways[i] = 1;
    ways[f+1] = (k-f) > 0 ? (k-f) : 0;

    for(int i=0; i<n; i++) {
        if(i < n-1) {
            square(ways, len);
            long val = 0;
            for(int j=len-1; j>=f+1; j--)
                val += ways[j];
            val %= MOD;
            suffix[f+1] = val;
            for(int j=f; j>=0; j--){
                long val = suffix[j+1] + ways[j];
                val = val>=MOD? val-MOD: val;
                suffix[j] = val;
            }
            for(int j=0; j <= k && j<=f; j++) {
                long val = suffix[j];
                val += ways[j]*(k-j);
                val %= MOD;
                ways[j] = val;
            }
            long val = suffix[f+1]*(k-f);
            val %= MOD;
            ways[f+1] = val;
            for(int j=k+1; j<f+2; j++)
                ways[j] = 0;
            for(int j=f+2; j<len; j++)
                ways[j] = 0;
        }
        else {
            for(int j=0; j<=f; j++)
                ans += ways[j]*ways[f-j] % MOD;
            ans %= MOD;
        }
    }

    printf("%ld\n", ans);

    free(ways);
    free(suffix);

    return 0;
}
