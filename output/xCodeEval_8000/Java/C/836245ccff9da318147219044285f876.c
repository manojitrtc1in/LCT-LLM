#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007
#define mod2 998244353

typedef struct FastReader {
    FILE* br;
    char* st;
} FastReader;

FastReader* createFastReader() {
    FastReader* fr = (FastReader*)malloc(sizeof(FastReader));
    fr->br = stdin;
    fr->st = NULL;
    return fr;
}

char* next(FastReader* fr) {
    size_t len = 0;
    ssize_t read;
    if ((read = getline(&(fr->st), &len, fr->br)) != -1) {
        return fr->st;
    }
    return NULL;
}

int nextInt(FastReader* fr) {
    char* token = next(fr);
    return atoi(token);
}

long nextLong(FastReader* fr) {
    char* token = next(fr);
    return atol(token);
}

double nextDouble(FastReader* fr) {
    char* token = next(fr);
    return atof(token);
}

char* nextLine(FastReader* fr) {
    return next(fr);
}

void destroyFastReader(FastReader* fr) {
    free(fr->st);
    free(fr);
}

void main() {
    FastReader* inp = createFastReader();
    int n = nextInt(inp);
    long* a = (long*)malloc(n * sizeof(long));
    int i, j, c, left, right, gg;
    long* pref = (long*)malloc((n + 1) * sizeof(long));
    long temp;
    for (i = 0; i < n; i++) {
        a[i] = nextLong(inp);
    }
    if (n > 66) {
        printf("1\n");
        return;
    }
    pref[1] = a[0];
    for (i = 1; i < n; i++) {
        pref[i + 1] = pref[i] ^ a[i];
    }
    gg = 34;
    for (c = 0; c < n - 1; c++) {
        for (left = c; left >= 0; left--) {
            for (right = c + 1; right < n; right++) {
                if (xor(left, c, pref) > xor(c + 1, right, pref)) {
                    gg = min(gg, right - left - 1);
                }
            }
        }
    }
    printf("%d\n", gg == 34 ? -1 : gg);
    free(a);
    free(pref);
    destroyFastReader(inp);
}

long xor(int i, int j, long* pref) {
    return pref[j + 1] ^ pref[i];
}

int min(int a, int b) {
    return a < b ? a : b;
}
