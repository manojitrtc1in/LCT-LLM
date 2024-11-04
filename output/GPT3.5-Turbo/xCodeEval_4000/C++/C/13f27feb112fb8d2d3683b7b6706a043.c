#include <stdio.h>

#define REP(i, n) for (int i=0;i<int(n);++i)
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)

typedef struct {
    int d[2][2];
} matrix;

void init(matrix *a) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a->d[i][j] = 0;
        }
    }
}

matrix multiply(const matrix *a, const matrix *b) {
    matrix c;
    init(&c);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int tmp = 0;
            for (int k = 0; k < 2; k++) {
                tmp += a->d[i][k] * b->d[k][j];
            }
            c.d[i][j] = tmp;
        }
    }
    return c;
}

matrix power(matrix a, int b) {
    matrix c;
    init(&c);
    for (int i = 0; i < 2; i++) {
        c.d[i][i] = 1;
    }

    while (b) {
        if (b & 1) {
            c = multiply(&c, &a);
        }
        a = multiply(&a, &a);
        b /= 2;
    }
    return c;
}

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
        if (~(x & (1 << i))) continue;
        for (j = 0; j < 16; j++) {
            if (~(y & (1 << j))) continue;
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
    int N;
    scanf("%d\n", &N);
    int e;
    puts(~0x8241 & solve() ? "YES" : "NO");
    return 0;
}
