#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007
#define mod2 998244353

typedef struct FastReader {
    char *buffer;
    char *ptr;
} FastReader;

FastReader *newFastReader() {
    FastReader *fr = (FastReader *)malloc(sizeof(FastReader));
    fr->buffer = (char *)malloc(4096);
    fr->ptr = fr->buffer;
    return fr;
}

void readNext(FastReader *fr) {
    fread(fr->buffer, 1, 4096, stdin);
    fr->ptr = fr->buffer;
}

int nextInt(FastReader *fr) {
    int num = 0;
    while (*fr->ptr < '0' || *fr->ptr > '9') {
        fr->ptr++;
    }
    while (*fr->ptr >= '0' && *fr->ptr <= '9') {
        num = num * 10 + (*fr->ptr - '0');
        fr->ptr++;
    }
    return num;
}

long long nextLong(FastReader *fr) {
    long long num = 0;
    while (*fr->ptr < '0' || *fr->ptr > '9') {
        fr->ptr++;
    }
    while (*fr->ptr >= '0' && *fr->ptr <= '9') {
        num = num * 10 + (*fr->ptr - '0');
        fr->ptr++;
    }
    return num;
}

double nextDouble(FastReader *fr) {
    double num = 0;
    while (*fr->ptr < '0' || *fr->ptr > '9') {
        fr->ptr++;
    }
    while (*fr->ptr >= '0' && *fr->ptr <= '9') {
        num = num * 10 + (*fr->ptr - '0');
        fr->ptr++;
    }
    if (*fr->ptr == '.') {
        fr->ptr++;
        double decimal = 0.1;
        while (*fr->ptr >= '0' && *fr->ptr <= '9') {
            num += (*fr->ptr - '0') * decimal;
            decimal *= 0.1;
            fr->ptr++;
        }
    }
    return num;
}

char *nextLine(FastReader *fr) {
    char *line = (char *)malloc(4096);
    int len = 0;
    while (*fr->ptr != '\n') {
        line[len++] = *fr->ptr;
        fr->ptr++;
    }
    line[len] = '\0';
    fr->ptr++;
    return line;
}

void freeFastReader(FastReader *fr) {
    free(fr->buffer);
    free(fr);
}

void main() {
    FastReader *inp = newFastReader();
    int n = nextInt(inp);
    long long *a = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        a[i] = nextLong(inp);
    }
    if (n > 66) {
        printf("1\n");
        return;
    }
    long long *pref = (long long *)malloc((n + 1) * sizeof(long long));
    pref[1] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i + 1] = pref[i] ^ a[i];
    }
    int gg = 34;
    for (int c = 0; c < n - 1; c++) {
        for (int left = c; left >= 0; left--) {
            for (int right = c + 1; right < n; right++) {
                if (xor(left, c, pref) > xor(c + 1, right, pref)) {
                    gg = min(gg, right - left - 1);
                }
            }
        }
    }
    printf("%d\n", gg == 34 ? -1 : gg);
    free(a);
    free(pref);
    freeFastReader(inp);
}

long long xor(int i, int j, long long *pref) {
    return pref[j + 1] ^ pref[i];
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    main();
    return 0;
}
