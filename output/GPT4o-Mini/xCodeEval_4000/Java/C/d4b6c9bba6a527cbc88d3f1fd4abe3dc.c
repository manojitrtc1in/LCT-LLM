#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 998244353
#define MAX_N 100000

typedef struct {
    long *data;
    int size;
} LongArray;

typedef struct {
    int *data;
    int size;
} IntArray;

void initIO(bool isFileIO) {
    if (!isFileIO) {
        // Standard input/output
    } else {
        // File input/output
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
}

void getInput(int *n, int *k, int *f) {
    scanf("%d %d %d", n, k, f);
}

void printOutput(long ans) {
    printf("%ld\n", ans);
}

long pow(int a, int k, long p) {
    long ans = 1;
    long curr = a;
    while (k > 0) {
        if (k & 1) {
            ans = (ans * curr) % p;
        }
        k >>= 1;
        curr = (curr * curr) % p;
    }
    return ans;
}

long inverse(int a, long p) {
    return pow(a, p - 2, p);
}

void fft(long *a, int n, bool isInvertedFFT) {
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; (j & bit) > 0; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        long wlen = isInvertedFFT ? inverse(3, MOD) : 3; // ROOT
        for (int i = len; i < MAX_N; i <<= 1) {
            wlen = (wlen * wlen) % MOD;
        }

        for (int i = 0; i < n; i += len) {
            long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long u = a[i + j];
                long v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = (w * wlen) % MOD;
            }
        }
    }

    if (isInvertedFFT) {
        long inv = inverse(n, MOD);
        for (int i = 0; i < n; i++) {
            a[i] = (a[i] * inv) % MOD;
        }
    }
}

void square(long *a, int n) {
    fft(a, n, false);
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] * a[i]) % MOD;
    }
    fft(a, n, true);
}

int solve(int n, int k, int f) {
    long ans = 0;
    int len = 1;
    while (len < f + 2 + f + 2) {
        len <<= 1;
    }
    long *ways = (long *)calloc(len, sizeof(long));
    long *suffix = (long *)calloc(f + 2, sizeof(long));

    for (int i = 0; i <= k && i <= f; i++) {
        ways[i] = 1;
    }
    ways[f + 1] = (k > f) ? (k - f) : 0;

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            square(ways, len);
            long val = 0;
            for (int j = len - 1; j >= f + 1; j--) {
                val = (val + ways[j]) % MOD;
            }
            suffix[f + 1] = val;

            for (int j = f; j >= 0; j--) {
                val = (suffix[j + 1] + ways[j]) % MOD;
                suffix[j] = val;
            }

            for (int j = 0; j <= k && j <= f; j++) {
                val = (suffix[j] + (ways[j] * (k - j)) % MOD) % MOD;
                ways[j] = val;
            }
            val = (suffix[f + 1] * (k > f ? (k - f) : 0)) % MOD;
            ways[f + 1] = val;

            for (int j = k + 1; j < f + 2; j++) {
                ways[j] = 0;
            }
            memset(ways + f + 2, 0, (len - (f + 2)) * sizeof(long));
        } else {
            for (int j = 0; j <= f; j++) {
                ans = (ans + (ways[j] * ways[f - j]) % MOD) % MOD;
            }
        }
    }

    free(ways);
    free(suffix);
    return (int)ans;
}

int main() {
    int n, k, f;
    bool isFileIO = true;
    initIO(isFileIO);
    getInput(&n, &k, &f);
    long ans = solve(n, k, f);
    printOutput(ans);
    return 0;
}
