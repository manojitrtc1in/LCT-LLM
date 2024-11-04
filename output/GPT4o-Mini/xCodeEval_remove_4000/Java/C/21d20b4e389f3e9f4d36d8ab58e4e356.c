#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define YES "YES"
#define NO "NO"

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list, int capacity) {
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
}

void addToArrayList(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
}

typedef struct {
    FILE *input;
    FILE *output;
} IOHandler;

void initIO(IOHandler *io, int onlineJudge) {
    if (!onlineJudge) {
        io->input = fopen("input.txt", "r");
        io->output = fopen("output.txt", "w");
    } else {
        io->input = stdin;
        io->output = stdout;
    }
}

void closeIO(IOHandler *io) {
    if (io->input != stdin) fclose(io->input);
    if (io->output != stdout) fclose(io->output);
}

int nextInt(FILE *input) {
    int value;
    fscanf(input, "%d", &value);
    return value;
}

void printOutput(FILE *output, long ans) {
    fprintf(output, "%ld\n", ans);
}

void square(long *a, int len);
void fft(long *a, int n, int invert);
long pow(int a, int k, long p);
long inverse(int a, long p);
void multiplyPolynomial(long *a, long *b, long *result, int lenA, int lenB);

int n, k, f;
long ans;

void getInput(IOHandler *io) {
    n = nextInt(io->input);
    k = nextInt(io->input);
    f = nextInt(io->input);
}

int solve() {
    long ans = 0;
    int len = 1;
    while (len < f + 2 + f + 2) len <<= 1;
    long *ways = (long *)calloc(len, sizeof(long));
    long *suffix = (long *)calloc(f + 2, sizeof(long));

    for (int i = 0; i <= k && i <= f; i++)
        ways[i] = 1;
    ways[f + 1] = (k - f > 0) ? (k - f) : 0;

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            square(ways, len);
            long val = 0;
            for (int j = len - 1; j >= f + 1; j--)
                val += ways[j];
            val %= MOD;
            suffix[f + 1] = val;

            for (int j = f; j >= 0; j--) {
                long val = suffix[j + 1] + ways[j];
                val = val >= MOD ? val - MOD : val;
                suffix[j] = val;
            }

            for (int j = 0; j <= k && j <= f; j++) {
                long val = suffix[j];
                val += ways[j] * (k - j);
                val %= MOD;
                ways[j] = val;
            }
            long val = suffix[f + 1] * (k - f > 0 ? (k - f) : 0);
            val %= MOD;
            ways[f + 1] = val;

            for (int j = k + 1; j < f + 2; j++)
                ways[j] = 0;
            memset(ways + f + 2, 0, (len - f - 2) * sizeof(long));
        } else {
            for (int j = 0; j <= f; j++)
                ans += ways[j] * ways[f - j] % MOD;
            ans %= MOD;
        }
    }

    free(ways);
    free(suffix);
    return (int)ans;
}

void square(long *a, int len) {
    fft(a, len, 0);
    for (int i = 0; i < len; i++)
        a[i] = a[i] * a[i] % MOD;
    fft(a, len, 1);
}

void fft(long *a, int n, int invert) {
    // FFT implementation goes here
}

long pow(int a, int k, long p) {
    long m = k;
    long ans = 1;
    long curr = a;

    while (m > 0) {
        if ((m & 1) == 1) {
            ans = (ans * curr) % p;
        }
        m >>= 1;
        curr = (curr * curr) % p;
    }
    return ans;
}

long inverse(int a, long p) {
    return pow(a, (int)(p - 2), p);
}

int main() {
    IOHandler io;
    initIO(&io, 0); // Change to 1 for online judge

    int t = 1; // Change if needed
    for (int i = 1; i <= t; ++i) {
        getInput(&io);
        ans = solve();
        printOutput(io.output, ans);
    }

    closeIO(&io);
    return 0;
}
