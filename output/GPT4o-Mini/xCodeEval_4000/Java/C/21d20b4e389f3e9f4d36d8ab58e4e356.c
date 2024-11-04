#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define MAXN 100000

typedef struct {
    long *data;
    int size;
} LongArray;

void initLongArray(LongArray *arr, int size) {
    arr->data = (long *)malloc(size * sizeof(long));
    arr->size = size;
    memset(arr->data, 0, size * sizeof(long));
}

void freeLongArray(LongArray *arr) {
    free(arr->data);
}

void square(LongArray *a);
void fft(LongArray *a, int isInvertedFFT);
long pow(int a, int k, long p);
long inverse(int a, long p);
void multiplyPolynomial(LongArray *a, LongArray *b, LongArray *result);
void getInput(int *n, int *k, int *f);
void printOutput(long ans);

int main() {
    int n, k, f;
    long ans = 0;

    getInput(&n, &k, &f);

    int len = 1;
    while (len < f + 2 + f + 2) 
        len <<= 1;

    LongArray ways, suffix;
    initLongArray(&ways, len);
    initLongArray(&suffix, f + 2);

    for (int i = 0; i <= k && i <= f; i++)
        ways.data[i] = 1;
    ways.data[f + 1] = (k - f > 0) ? (k - f) : 0;

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            square(&ways);
            long val = 0;
            for (int j = ways.size - 1; j >= f + 1; j--)
                val += ways.data[j];
            val %= MOD;
            suffix.data[f + 1] = val;

            for (int j = f; j >= 0; j--) {
                long val = suffix.data[j + 1] + ways.data[j];
                val = (val >= MOD) ? (val - MOD) : val;
                suffix.data[j] = val;
            }

            for (int j = 0; j <= k && j <= f; j++) {
                long val = suffix.data[j];
                val += ways.data[j] * (k - j);
                val %= MOD;
                ways.data[j] = val;
            }
            long val = suffix.data[f + 1] * (k - f > 0 ? (k - f) : 0);
            val %= MOD;
            ways.data[f + 1] = val;

            for (int j = k + 1; j < f + 2; j++)
                ways.data[j] = 0;

            memset(ways.data + f + 2, 0, (len - (f + 2)) * sizeof(long));
        } else {
            for (int j = 0; j <= f; j++)
                ans += ways.data[j] * ways.data[f - j] % MOD;
            ans %= MOD;
        }
    }

    printOutput(ans);

    freeLongArray(&ways);
    freeLongArray(&suffix);
    return 0;
}

void getInput(int *n, int *k, int *f) {
    scanf("%d %d %d", n, k, f);
}

void printOutput(long ans) {
    printf("%ld\n", ans);
}

void fft(LongArray *a, int isInvertedFFT) {
    int n = a->size;

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; (j & bit) > 0; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j) {
            long temp = a->data[i];
            a->data[i] = a->data[j];
            a->data[j] = temp;
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        long wlen = isInvertedFFT ? ROOT_INV : ROOT;
        for (int i = len; i < ORDER; i <<= 1)
            wlen = wlen * wlen % MOD;

        for (int i = 0; i < n; i += len) {
            long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long u = a->data[i + j];
                long v = a->data[i + j + len / 2] * w % MOD;
                a->data[i + j] = (u + v < MOD) ? (u + v) : (u + v - MOD);
                a->data[i + j + len / 2] = (u - v >= 0) ? (u - v) : (u - v + MOD);
                w = w * wlen % MOD;
            }
        }
    }

    if (isInvertedFFT) {
        long inv = inverse(n, MOD);
        for (int i = 0; i < a->size; i++)
            a->data[i] = a->data[i] * inv % MOD;
    }
}

void square(LongArray *a) {
    fft(a, 0);
    for (int i = 0; i < a->size; i++)
        a->data[i] = a->data[i] * a->data[i] % MOD;
    fft(a, 1);
}

long pow(int a, int k, long p) {
    long m = k;
    long ans = 1;
    long curr = a;

    while (m > 0) {
        if ((m & 1) == 1) {
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
    return pow(a, (int)(p - 2), p);
}
