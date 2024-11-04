#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int X, Y;
} PairInt;

typedef struct {
    int *tree;
    int maxVal;
} FenwickTree;

typedef struct {
    int *primes;
    int size;
} PrimeSieve;

typedef struct {
    int *level;
    int **jads;
    int n;
    int **adj;
} LCA;

typedef struct {
    int p;
    int q;
    int lambdaM;
    int M;
    int curX;
    int bitCnt;
} BlumBlumShub;

typedef struct {
    int nodeCount;
    int **dictionary;
    bool *end;
    int *pathTrough;
    int dicSize;
} SuffixTrie;

typedef struct {
    int *buf;
    int curChar;
    int numChars;
    FILE *stream;
} InputReader;

void initFenwickTree(FenwickTree *ft, int n) {
    ft->maxVal = n;
    ft->tree = (int *)calloc(n + 1, sizeof(int));
}

void updateFenwickTree(FenwickTree *ft, int idx, int val) {
    idx++;
    while (idx <= ft->maxVal) {
        ft->tree[idx] += val;
        idx += (idx & (-idx));
    }
}

int readFenwickTree(FenwickTree *ft, int idx) {
    idx++;
    int sum = 0;
    while (idx > 0) {
        sum += ft->tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void initInputReader(InputReader *reader, FILE *stream) {
    reader->stream = stream;
    reader->buf = (int *)malloc(1024 * sizeof(int));
    reader->curChar = 0;
    reader->numChars = 0;
}

int readInput(InputReader *reader) {
    if (reader->numChars == -1)
        return -1;
    if (reader->curChar >= reader->numChars) {
        reader->curChar = 0;
        reader->numChars = fread(reader->buf, sizeof(int), 1024, reader->stream);
        if (reader->numChars <= 0)
            return -1;
    }
    return reader->buf[reader->curChar++];
}

int nextInt(InputReader *reader) {
    int c = readInput(reader);
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t')
        c = readInput(reader);
    int sgn = 1;
    if (c == '-') {
        sgn = -1;
        c = readInput(reader);
    }
    int res = 0;
    do {
        if (c < '0' || c > '9')
            return -1; // Error
        res = res * 10 + (c - '0');
        c = readInput(reader);
    } while (c != ' ' && c != '\n' && c != '\r' && c != '\t');
    return res * sgn;
}

void solve(InputReader *in, FILE *out, int testCase) {
    int m = nextInt(in);
    int h1 = nextInt(in);
    int a1 = nextInt(in);
    int x1 = nextInt(in);
    int y1 = nextInt(in);

    int h2 = nextInt(in);
    int a2 = nextInt(in);
    int x2 = nextInt(in);
    int y2 = nextInt(in);

    int zone = 1;
    int r1 = cycleFinding(h1).Y;
    int mu1 = cycleFinding(h1).X;

    zone = 2;
    int r2 = cycleFinding(h2).Y;
    int mu2 = cycleFinding(h2).X;

    bool can = true;

    zone = 1;
    int len1 = 0;
    while (h1 != a1) {
        h1 = f(h1);
        len1++;
        if (len1 > m) {
            can = false;
            break;
        }
    }

    zone = 2;
    int len2 = 0;
    while (h2 != a2) {
        h2 = f(h2);
        len2++;
        if (len2 > m) {
            can = false;
            break;
        }
    }

    int ans = -2;
    if (mu1 > len1) {
        if (mu2 > len2) {
            if (len1 == len2) {
                ans = len1;
            } else {
                can = false;
            }
        } else {
            int temp = len1 - len2;
            if (temp % r2 == 0 && temp >= 0) {
                ans = len1;
            } else {
                can = false;
            }
        }
    } else {
        if (mu2 > len2) {
            int temp = len2 - len1;
            if (temp % r1 == 0 && temp >= 0) {
                ans = len2;
            } else {
                can = false;
            }
        }
    }

    if (ans != -2) {
        fprintf(out, "%d\n", ans);
        return;
    }

    int M = len2 - len1;
    int gcd = GCD(r1, r2);
    if (M % gcd != 0) {
        can = false;
    }

    if (can) {
        for (int k = 0; ; k++) {
            long kPrim = ((long)r1 * k - M) / r2;
            if (kPrim < 0) {
                continue;
            }
            if ((long)r1 * k - (long)r2 * kPrim == M) {
                fprintf(out, "%ld\n", ((long)r1 * k + len1));
                return;
            }
        }
    }

    fprintf(out, "-1\n");
}

PairInt cycleFinding(int a) {
    int mu;
    int lambda;

    int turtle = f(a);
    int hare = f(turtle);
    while (turtle != hare) {
        turtle = f(turtle);
        hare = f(f(hare));
    }
    mu = 0;
    turtle = a;
    while (turtle != hare) {
        turtle = f(turtle);
        hare = f(hare);
        mu++;
    }
    lambda = 1;

    hare = f(turtle);
    while (turtle != hare) {
        hare = f(hare);
        lambda++;
    }
    return (PairInt){mu, lambda};
}

int f(int h) {
    if (zone == 1) {
        return (add(mul(x1, h, m), y1, m));
    } else {
        return (add(mul(x2, h, m), y2, m));
    }
}

int main() {
    InputReader in;
    initInputReader(&in, stdin);
    FILE *out = stdout;

    int test = 1;
    while (true) {
        solve(&in, out, test++);
        fflush(out);
    }

    free(in.buf);
    return 0;
}
