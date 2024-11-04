#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define ROOT 5832
#define ROOT_INV 996921667
#define ORDER 8388608

typedef struct {
    int *arr;
    int size;
    int capacity;
} IntArray;

typedef struct {
    long *arr;
    int size;
    int capacity;
} LongArray;

typedef struct {
    int n;
    int k;
    int f;
} Input;

typedef struct {
    int ans;
} Output;

void initIntArray(IntArray *array) {
    array->arr = malloc(10 * sizeof(int));
    array->size = 0;
    array->capacity = 10;
}

void addInt(IntArray *array, int value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = realloc(array->arr, array->capacity * sizeof(int));
    }
    array->arr[array->size++] = value;
}

void freeIntArray(IntArray *array) {
    free(array->arr);
}

void initLongArray(LongArray *array) {
    array->arr = malloc(10 * sizeof(long));
    array->size = 0;
    array->capacity = 10;
}

void addLong(LongArray *array, long value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = realloc(array->arr, array->capacity * sizeof(long));
    }
    array->arr[array->size++] = value;
}

void freeLongArray(LongArray *array) {
    free(array->arr);
}

void getInput(Input *input) {
    scanf("%d %d %d", &input->n, &input->k, &input->f);
}

void printOutput(Output output) {
    printf("%d\n", output.ans);
}

long powMod(int a, int k, long p) {
    long m = k;
    long ans = 1;
    long curr = a;

    while (m > 0) {
        if (m & 1) {
            ans = (ans * curr) % p;
        }
        m >>= 1;
        curr = (curr * curr) % p;
    }
    return ans;
}

long inverse(int a, long p) {
    return powMod(a, p - 2, p);
}

void swap(long *a, int i, int j) {
    long temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void fft(long *a, int isInvertedFFT) {
    int n = ORDER;

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; (j & bit) > 0; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;

        if (i < j) {
            swap(a, i, j);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        long wlen = isInvertedFFT ? ROOT_INV : ROOT;
        for (int i = len; i < ORDER; i <<= 1) {
            wlen = (wlen * wlen) % MOD;
        }

        for (int i = 0; i < n; i += len) {
            long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long u = a[i + j];
                long v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v) < MOD ? (u + v) : (u + v - MOD);
                a[i + j + len / 2] = (u - v) >= 0 ? (u - v) : (u - v + MOD);
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

void square(long *a) {
    fft(a, 0);
    for (int i = 0; i < ORDER; i++) {
        a[i] = (a[i] * a[i]) % MOD;
    }
    fft(a, 1);
}

long *multiplyPolynomial(long *a, long *b) {
    int n = ORDER;
    long *fa = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        fa[i] = a[i];
    }
    long *fb = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        fb[i] = b[i];
    }

    fft(fa, 0);
    fft(fb, 0);
    for (int i = 0; i < n; i++) {
        fa[i] = (fa[i] * fb[i]) % MOD;
    }
    fft(fa, 1);

    return fa;
}

Output solve(Input input) {
    Output output;
    long ans = 0;

    int len = 1;
    while (len < input.f + 2 + input.f + 2) {
        len <<= 1;
    }
    long *ways = malloc(len * sizeof(long));
    long *suffix = malloc((input.f + 2) * sizeof(long));

    for (int i = 0; i <= input.k && i <= input.f; i++) {
        ways[i] = 1;
    }
    ways[input.f + 1] = input.k - input.f > 0 ? input.k - input.f : 0;

    for (int i = 0; i < input.n; i++) {
        if (i < input.n - 1) {
            square(ways);

            long val = 0;
            for (int j = len - 1; j >= input.f + 1; j--) {
                val += ways[j];
            }
            val %= MOD;
            suffix[input.f + 1] = val;

            for (int j = input.f; j >= 0; j--) {
                long val = suffix[j + 1] + ways[j];
                val = val >= MOD ? val - MOD : val;
                suffix[j] = val;
            }

            for (int j = 0; j <= input.k && j <= input.f; j++) {
                long val = suffix[j];
                val += ways[j] * (input.k - j);
                val %= MOD;
                ways[j] = val;
            }

            long val = suffix[input.f + 1] * (input.k - input.f);
            val %= MOD;
            ways[input.f + 1] = val;

            for (int j = input.k + 1; j < input.f + 2; j++) {
                ways[j] = 0;
            }
            for (int j = f + 2; j < len; j++) {
                ways[j] = 0;
            }
        } else {
            for (int j = 0; j <= input.f; j++) {
                ans += ways[j] * ways[input.f - j] % MOD;
            }
            ans %= MOD;
        }
    }

    output.ans = (int) ans;
    free(ways);
    free(suffix);
    return output;
}

int main() {
    Input input;
    Output output;

    getInput(&input);
    output = solve(input);
    printOutput(output);

    return 0;
}
