#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MOD 998244353
#define ROOT 646108188
#define ROOT_INV 208611436
#define ORDER 8388608
#define W4 875849102
#define id15 897581057
#define YES "YES"
#define NO "NO"

typedef struct {
    FILE* file;
    bool isFile;
} MyScanner;

typedef struct {
    FILE* file;
    bool isFile;
} id5;

void initIO(bool id8);
void getInput();
void printOutput();
void run();
void test();
void square(long* a, int len);
long powMod(int a, int k, long p);
long inverse(int a, long p);
void fft(long* a, bool id0);
void fft4(long* a, bool id0);
void swap(long* a, int i, int j);
long* multiplyPolynomial(long* a, long* b, int n);
void closeIO();

int n, k, f;
long* ways;
long* suffix;
int ans;

int main() {
    run();
    return 0;
}

void run() {
    bool isDebug = false;
    bool id8 = true;
    bool id2 = false;

    initIO(id8);

    int t = id2 ? in.nextInt() : 1;

    for (int i = 1; i <= t; ++i) {
        if (isDebug) {
            fprintf(out.file, "Test %d\n", i);
        }

        getInput();

        ans = solve();

        printOutput();
    }

    closeIO();
}

void initIO(bool id8) {
    if (id8) {
        in.file = fopen("input.txt", "r");
        out.file = fopen("output.txt", "w");
        in.isFile = true;
        out.isFile = true;
    } else {
        in.file = stdin;
        out.file = stdout;
        in.isFile = false;
        out.isFile = false;
    }
}

void closeIO() {
    if (in.isFile) {
        fclose(in.file);
    }
    if (out.isFile) {
        fclose(out.file);
    }
}

void getInput() {
    fscanf(in.file, "%d %d %d", &n, &k, &f);
}

void printOutput() {
    fprintf(out.file, "%d\n", ans);
}

int solve() {
    long ans = 0;

    int len = 1;
    while (len < f + 2 + f + 2)
        len <<= 1;
    ways = (long*)malloc(len * sizeof(long));
    suffix = (long*)malloc((f + 2) * sizeof(long));

    for (int i = 0; i <= k && i <= f; i++)
        ways[i] = 1;
    ways[f + 1] = fmax(0, k - f);

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            square(ways, len);
            {
                long val = 0;
                for (int j = len - 1; j >= f + 1; j--)
                    val += ways[j];
                val %= MOD;
                suffix[f + 1] = val;
            }
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
            {
                long val = suffix[f + 1] * fmax(0, k - f);
                val %= MOD;
                ways[f + 1] = val;
            }
            for (int j = k + 1; j < f + 2; j++)
                ways[j] = 0;
            for (int j = f + 2; j < len; j++)
                ways[j] = 0;
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

void square(long* a, int len) {
    fft4(a, false);
    for (int i = 0; i < len; i++)
        a[i] = a[i] * a[i] % MOD;
    fft4(a, true);
}

long powMod(int a, int k, long p) {
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
    return powMod(a, p - 2, p);
}

void fft(long* a, bool id0) {
    int n = ORDER;

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
        long wlen = id0 ? ROOT_INV : ROOT;
        for (int i = len; i < ORDER; i <<= 1)
            wlen = wlen * wlen % MOD;

        for (int i = 0; i < n; i += len) {
            long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long u = a[i + j];
                long v = a[i + j + len / 2] * w % MOD;
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = w * wlen % MOD;
            }
        }
    }

    if (id0) {
        long inv = inverse(n, MOD);
        for (int i = 0; i < n; i++)
            a[i] = a[i] * inv % MOD;
    }
}

void fft4(long* a, bool id0) {
    int n = ORDER;

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; (j & bit) > 0; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j) {
            swap(a, i, j);
        }
    }

    int parity = 0;
    for (int len = 2; len <= n; len <<= 1)
        parity++;

    int len;
    if (parity % 2 == 1) {
        len = 2;
        if (len <= n) {
            long wlen = id0 ? ROOT_INV : ROOT;
            for (int i = len; i < ORDER; i <<= 1)
                wlen = wlen * wlen % MOD;

            for (int i = 0; i < n; i += len) {
                long w = 1;
                for (int j = 0; j < len / 2; j++) {
                    long x0 = a[i + j];
                    long x1 = a[i + j + len / 2] * w % MOD;
                    long x2 = a[i + j + len / 4] * w % MOD;
                    x2 = x2 * w % MOD;
                    long x3 = a[i + j + len * 3 / 4] * w % MOD;
                    x3 = x3 * w % MOD;
                    x3 = x3 * w % MOD;

                    long y0 = x0 + x1 + x2 + x3;
                    a[i + j] = y0 % MOD;
                    long y1 = x0 + x1 * W4 - x2 - x3 * W4;
                    y1 %= MOD;
                    a[i + j + len * 3 / 4] = y1 < 0 ? y1 + MOD : y1;
                    long y2 = x0 - x1 + x2 - x3;
                    y2 %= MOD;
                    a[i + j + len / 2] = y2 < 0 ? y2 + MOD : y2;
                    long y3 = x0 - x1 * W4 - x2 + x3 * W4;
                    y3 %= MOD;
                    a[i + j + len / 4] = y3 < 0 ? y3 + MOD : y3;

                    w = w * wlen % MOD;
                }
            }
            len *= 4;
        }
    } else
        len = 4;

    for (; len <= n; len <<= 2) {
        long wlen = id0 ? ROOT_INV : ROOT;
        long w4 = id0 ? id15 : W4;
        for (int i = len; i < ORDER; i <<= 1)
            wlen = wlen * wlen % MOD;

        for (int i = 0; i < n; i += len) {
            long w = 1;
            for (int j = 0; j < len / 4; j++) {
                long x0 = a[i + j];
                long x1 = a[i + j + len / 2] * w % MOD;
                long x2 = a[i + j + len / 4] * w % MOD;
                x2 = x2 * w % MOD;
                long x3 = a[i + j + len * 3 / 4] * w % MOD;
                x3 = x3 * w % MOD;
                x3 = x3 * w % MOD;

                long y0 = x0 + x1 + x2 + x3;
                a[i + j] = y0 % MOD;
                long y1 = x0 + x1 * w4 - x2 - x3 * w4;
                y1 %= MOD;
                a[i + j + len * 3 / 4] = y1 < 0 ? y1 + MOD : y1;
                long y2 = x0 - x1 + x2 - x3;
                y2 %= MOD;
                a[i + j + len / 2] = y2 < 0 ? y2 + MOD : y2;
                long y3 = x0 - x1 * w4 - x2 + x3 * w4;
                y3 %= MOD;
                a[i + j + len / 4] = y3 < 0 ? y3 + MOD : y3;

                w = w * wlen % MOD;
            }
        }
    }

    if (id0) {
        long inv = inverse(n, MOD);
        for (int i = 0; i < n; i++)
            a[i] = a[i] * inv % MOD;
    }
}

void swap(long* a, int i, int j) {
    long temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

long* multiplyPolynomial(long* a, long* b, int n) {
    int len = 1;
    while (len < n + n)
        len <<= 1;
    long* fa = (long*)malloc(len * sizeof(long));
    long* fb = (long*)malloc(len * sizeof(long));

    for (int i = 0; i < n; i++) {
        fa[i] = a[i];
        fb[i] = b[i];
    }

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < len; i++)
        fa[i] = fa[i] * fb[i] % MOD;
    fft(fa, true);

    free(fb);

    return fa;
}

long powMod(int a, int k, long p) {
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
    return powMod(a, p - 2, p);
}
