#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MOD 998244353
#define BIG 8LL * MOD * MOD

typedef struct {
    char* buf;
    int len;
    int ptr;
} FastWriter;

FastWriter* newFastWriter() {
    FastWriter* fw = (FastWriter*)malloc(sizeof(FastWriter));
    fw->buf = (char*)malloc(BUF_SIZE * sizeof(char));
    fw->len = BUF_SIZE;
    fw->ptr = 0;
    return fw;
}

void writeByte(FastWriter* fw, char c) {
    fw->buf[fw->ptr++] = c;
    if (fw->ptr == fw->len) {
        fwrite(fw->buf, sizeof(char), fw->len, stdout);
        fw->ptr = 0;
    }
}

void writeString(FastWriter* fw, char* s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        writeByte(fw, s[i]);
    }
}

void writeInt(FastWriter* fw, int x) {
    if (x == 0) {
        writeByte(fw, '0');
        return;
    }
    if (x < 0) {
        writeByte(fw, '-');
        x = -x;
    }
    char digits[12];
    int len = 0;
    while (x > 0) {
        digits[len++] = '0' + (x % 10);
        x /= 10;
    }
    for (int i = len - 1; i >= 0; i--) {
        writeByte(fw, digits[i]);
    }
}

void writeLong(FastWriter* fw, long long x) {
    if (x == 0) {
        writeByte(fw, '0');
        return;
    }
    if (x < 0) {
        writeByte(fw, '-');
        x = -x;
    }
    char digits[21];
    int len = 0;
    while (x > 0) {
        digits[len++] = '0' + (x % 10);
        x /= 10;
    }
    for (int i = len - 1; i >= 0; i--) {
        writeByte(fw, digits[i]);
    }
}

void writeNewLine(FastWriter* fw) {
    writeByte(fw, '\n');
}

void flush(FastWriter* fw) {
    fwrite(fw->buf, sizeof(char), fw->ptr, stdout);
    fw->ptr = 0;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    char ss[n][m+1];
    char oss[n][m+1];
    for (int i = 0; i < n; i++) {
        scanf("%s", ss[i]);
        strcpy(oss[i], ss[i]);
    }
    int offset[n+1];
    offset[0] = 1;
    for (int i = 0; i < n; i++) {
        offset[i+1] = offset[i] + strlen(ss[i]) - 1;
    }
    int U = offset[n] - 1;

    const int D = 5;
    int M[(U+1)*D][(U+1)*D];
    memset(M, 0, sizeof(M));

    for (int i = 0; i < U+1; i++) {
        int lb, of;
        if (i == 0) {
            lb = 0;
            of = 0;
        } else {
            lb = lowerBound(offset, i+1, n+1) - 1;
            of = i - offset[lb] + 1;
        }

        if (i == 0) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k != j && strncmp(oss[k], oss[j], strlen(oss[j])) == 0) {
                        M[offset[k]+strlen(ss[j])-1][0+(U+1)*(strlen(ss[j])-1)] = 1;
                    }
                }
                M[0][0+(U+1)*(strlen(ss[j])-1)] += 1;
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (strncmp(oss[lb]+of, oss[j], strlen(oss[j])) == 0) {
                    M[0][i+(U+1)*(strlen(oss[j])-1)] += 2;
                } else if (strncmp(oss[lb]+of, oss[j], strlen(oss[j])) == 0) {
                    M[i+strlen(oss[j])][i+(U+1)*(strlen(oss[j])-1)] += 1;
                }
            }

            char* suf = oss[lb]+of;
            for (int j = 0; j < n; j++) {
                if (strncmp(oss[j], suf, strlen(suf)) == 0 && strcmp(oss[j], suf) != 0) {
                    M[offset[j]+strlen(suf)-1][i+(U+1)*(strlen(suf)-1)] += 1;
                }
            }
        }
    }

    for (int i = 0; i < U+1; i++) {
        for (int j = 0; j < D-1; j++) {
            M[i+(U+1)*(j+1)][i+(U+1)*j] = 1;
        }
    }

    int v[(U+1)*D];
    memset(v, 0, sizeof(v));
    v[0] = 1;
    pow(M, v, (U+1)*D, m);

    FastWriter* fw = newFastWriter();
    writeInt(fw, v[0]);
    writeNewLine(fw);
    flush(fw);
}

int lowerBound(int* a, int l, int r, int v) {
    int low = l - 1;
    int high = r;
    while (high - low > 1) {
        int h = (high + low) >> 1;
        if (a[h] >= v) {
            high = h;
        } else {
            low = h;
        }
    }
    return high;
}

void pow(int M[][25], int* v, int n, int e) {
    for (int i = 0; i < n; i++) {
        if (v[i] >= MOD) {
            v[i] %= MOD;
        }
    }
    int MUL[n][n];
    memcpy(MUL, M, sizeof(MUL));
    for (; e > 0; e >>= 1) {
        if (e & 1) {
            mul(MUL, v, n);
        }
        p2(MUL, n);
    }
}

void mul(int A[][25], int* v, int n) {
    int m = n / 5;
    int w[m];
    memset(w, 0, sizeof(w));
    for (int i = 0; i < m; i++) {
        long long sum = 0;
        for (int k = 0; k < n; k++) {
            sum += (long long)A[i][k] * v[k];
            if (sum >= BIG) {
                sum -= BIG;
            }
        }
        w[i] = sum % MOD;
    }
    memcpy(v, w, sizeof(w));
}

void p2(int A[][25], int n) {
    int C[n][n];
    memset(C, 0, sizeof(C));
    for (int i = 0; i < n; i++) {
        long long sum[n];
        memset(sum, 0, sizeof(sum));
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                sum[j] += (long long)A[i][k] * A[k][j];
                if (sum[j] >= BIG) {
                    sum[j] -= BIG;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            C[i][j] = sum[j] % MOD;
        }
    }
    memcpy(A, C, sizeof(C));
}

int main() {
    solve();
    return 0;
}
