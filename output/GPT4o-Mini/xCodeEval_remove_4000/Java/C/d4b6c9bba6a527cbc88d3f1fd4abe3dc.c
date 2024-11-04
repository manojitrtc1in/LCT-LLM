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

typedef struct {
    FILE *input;
    FILE *output;
} IOHandler;

void initIO(IOHandler *io, bool onlineJudge) {
    if (!onlineJudge) {
        io->input = fopen("input.txt", "r");
        io->output = fopen("output.txt", "w");
    } else {
        io->input = stdin;
        io->output = stdout;
    }
}

void closeIO(IOHandler *io) {
    fclose(io->input);
    fclose(io->output);
}

int nextInt(FILE *input) {
    int value;
    fscanf(input, "%d", &value);
    return value;
}

void printAns(FILE *output, long ans) {
    fprintf(output, "%ld\n", ans);
}

void square(LongArray *a) {
    // FFT and squaring implementation goes here
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

void fft(LongArray *a, bool invert) {
    // FFT implementation goes here
}

void fft4(LongArray *a, bool invert) {
    // FFT4 implementation goes here
}

int solve(int n, int k, int f) {
    long ans = 0;
    LongArray ways = {malloc((f + 2) * sizeof(long)), f + 2};
    LongArray suffix = {malloc((f + 2) * sizeof(long)), f + 2};

    for (int i = 0; i <= k && i <= f; i++)
        ways.data[i] = 1;
    ways.data[f + 1] = (k - f > 0) ? (k - f) : 0;

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            square(&ways);
            long val = 0;
            for (int j = ways.size - 1; j >= f + 1; j--)
                val = (val + ways.data[j]) % MOD;
            suffix.data[f + 1] = val;

            for (int j = f; j >= 0; j--) {
                long val = (suffix.data[j + 1] + ways.data[j]) % MOD;
                suffix.data[j] = val;
            }

            for (int j = 0; j <= k && j <= f; j++) {
                long val = (suffix.data[j] + ways.data[j] * (k - j)) % MOD;
                ways.data[j] = val;
            }
            ways.data[f + 1] = (suffix.data[f + 1] * (k - f > 0 ? (k - f) : 0)) % MOD;

            for (int j = k + 1; j < f + 2; j++)
                ways.data[j] = 0;
            memset(ways.data + f + 2, 0, (ways.size - (f + 2)) * sizeof(long));
        } else {
            for (int j = 0; j <= f; j++)
                ans = (ans + ways.data[j] * ways.data[f - j]) % MOD;
        }
    }

    free(ways.data);
    free(suffix.data);
    return (int)ans;
}

int main() {
    IOHandler io;
    initIO(&io, getenv("ONLINE_JUDGE") == NULL);

    int t = 1; // Assuming single test case for simplicity
    for (int i = 1; i <= t; ++i) {
        int n = nextInt(io.input);
        int k = nextInt(io.input);
        int f = nextInt(io.input);
        
        int ans = solve(n, k, f);
        printAns(io.output, ans);
    }

    closeIO(&io);
    return 0;
}
