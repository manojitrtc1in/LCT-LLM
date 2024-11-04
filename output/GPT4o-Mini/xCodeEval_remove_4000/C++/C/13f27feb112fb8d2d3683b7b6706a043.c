#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); i++)
#define RST(A) memset(A, 0, sizeof(A))

struct matrix {
    int d[2][2];
    void init() { RST(d); }
    matrix() { init(); }
    int sum() {
        int res = 0; REP(i, 2) REP(j, 2) res += d[i][j];
        return res;
    }
};

matrix operator_multiply(const matrix* a, const matrix* b) {
    matrix c; REP(i, 2) REP(j, 2) {
        long long tmp = 0; REP(k, 2) tmp += (long long)(a->d[i][k]) * b->d[k][j];
        c.d[i][j] = tmp;
    }
    return c;
}

matrix pow_matrix(matrix a, int b) {
    matrix c; RST(c.d); REP(i, 2) c.d[i][i] = 1;

    while (b) {
        if (b & 1) c = operator_multiply(&c, &a);
        a = operator_multiply(&a, &a), b /= 2;
    }
    return c;
}

const int N = 1000009;

int solve() {
    int x, y, i, j, k = 0, res = 0;
    char ch = getchar();
    if (ch == '0') return 1 << 0;
    if (ch == '1') return 1 << 15;
    if (ch == '?') return (1 << 3) | (1 << 12);

    x = solve();
    ch = getchar();
    y = solve();

    for (i = 0; i < 16; i++) {
        if (~x & (1 << i)) continue;
        for (j = 0; j < 16; j++) {
            if (~y & (1 << j)) continue;
            if (ch == '^') k = i ^ j;
            if (ch == '&') k = i & j;
            if (ch == '|') k = i | j;
            res |= 1 << k;
        }
    }
    getchar();
    return res;
}

int main() {
    int N; scanf("%d\n", &N);
    puts(~0x8241 & solve() ? "YES" : "NO");
}
