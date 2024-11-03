#include <stdio.h>

typedef struct {
    int d[2][2];
} matrix;

void init(matrix *a) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            a->d[i][j] = 0;
        }
    }
}

matrix multiply(matrix a, matrix b) {
    matrix c;
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            c.d[i][j] = 0;
            for (k = 0; k < 2; k++) {
                c.d[i][j] += a.d[i][k] * b.d[k][j];
            }
        }
    }
    return c;
}

matrix power(matrix a, int b) {
    matrix c;
    int i, j;
    init(&c);
    for (i = 0; i < 2; i++) {
        c.d[i][i] = 1;
    }
    while (b > 0) {
        if (b & 1) {
            c = multiply(c, a);
        }
        a = multiply(a, a);
        b >>= 1;
    }
    return c;
}

int solve() {
    int x, y, i, j, k = 0, res = 0;
    char ch = getchar();
    if (ch == '0') {
        return 1 << 0;
    }
    if (ch == '1') {
        return 1 << 15;
    }
    if (ch == '?') {
        return (1 << 3) | (1 << 12);
    }

    x = solve();
    ch = getchar();
    y = solve();

    for (i = 0; i < 16; i++) {
        if (~(x & (1 << i))) {
            continue;
        }
        for (j = 0; j < 16; j++) {
            if (~(y & (1 << j))) {
                continue;
            }
            if (ch == '^') {
                k = i ^ j;
            }
            if (ch == '&') {
                k = i & j;
            }
            if (ch == '|') {
                k = i | j;
            }
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
