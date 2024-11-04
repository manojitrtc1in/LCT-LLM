#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007
#define mod2 998244353

typedef struct FastReader {
    FILE* br;
    char* st;
} FastReader;

FastReader* inp;

void initFastReader() {
    inp = (FastReader*)malloc(sizeof(FastReader));
    inp->br = stdin;
    inp->st = NULL;
}

char* next() {
    size_t len = 0;
    ssize_t read;
    char* token = NULL;
    if (inp->st == NULL) {
        read = getline(&(inp->st), &len, inp->br);
        if (read == -1) {
            return NULL;
        }
    }
    token = strsep(&(inp->st), " \n");
    return token;
}

int nextInt() {
    char* token = next();
    return atoi(token);
}

long nextLong() {
    char* token = next();
    return atol(token);
}

double nextDouble() {
    char* token = next();
    return atof(token);
}

char* nextLine() {
    size_t len = 0;
    ssize_t read;
    char* line = NULL;
    if (inp->st != NULL) {
        line = inp->st;
        inp->st = NULL;
        return line;
    }
    read = getline(&line, &len, inp->br);
    if (read == -1) {
        return NULL;
    }
    return line;
}

void main() {
    initFastReader();
    FILE* out = stdout;

    int mod = 1000000007;
    int mod2 = 998244353;

    int n = nextInt();
    long* a = (long*)malloc(n * sizeof(long));
    int i;
    for (i = 0; i < n; i++) {
        a[i] = nextLong();
    }
    if (n > 66) {
        fprintf(out, "1\n");
        return;
    }
    long* pref = (long*)malloc((n + 1) * sizeof(long));
    pref[1] = a[0];
    for (i = 1; i < n; i++) {
        pref[i + 1] = pref[i] ^ a[i];
    }
    int gg = 34;
    int c;
    for (c = 0; c < n - 1; c++) {
        int left, right;
        for (left = c; left >= 0; left--) {
            for (right = c + 1; right < n; right++) {
                if (xor(left, c) > xor(c + 1, right)) {
                    gg = min(gg, right - left - 1);
                }
            }
        }
    }
    fprintf(out, gg == 34 ? "-1\n" : "%d\n", gg);
    fclose(out);
}

long xor(int i, int j, long* pref) {
    return pref[j + 1] ^ pref[i];
}

int min(int a, int b) {
    return a < b ? a : b;
}
