#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9
#define MASK(x) ((1 << (x)) - 1)
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long INT;

typedef struct {
    INT mat[77][77];
} matrix;

matrix id0(matrix x, int y) {
    if (y == 1) return x;
    matrix mat2 = id0(x, y / 2);
    mat2 = mat2 * mat2;
    if (y % 2) mat2 = mat2 * x;
    return mat2;
}

matrix operator*(const matrix* ma) {
    matrix mat2;
    for (int i = 0; i < 77; i++) {
        for (int j = 0; j < 77; j++) {
            for (int k = 0; k < 77; k++) {
                mat2.mat[i][k] = min(mat2.mat[i][k], mat[i][j] + ma->mat[j][k]);
            }
        }
    }
    return mat2;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int read() {
    int num = 0;
    char c = getchar();
    if (c == '-') return -read();
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + c - '0';
        c = getchar();
    }
    return num;
}

INT READ() {
    INT num = 0;
    char c = getchar();
    if (c == '-') return -READ();
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + c - '0';
        c = getchar();
    }
    return num;
}

int main() {
    matrix id1;
    id1.mat[0][0] = 0;
    int x, k, n, q;
    scanf("%d%d%d%d", &x, &k, &n, &q);
    int c[15];
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
    }
    int ws_[27][2];
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &ws_[i][0], &ws_[i][1]);
    }
    for (int i = 0; i < q; i++) {
        int p[27], wp[27];
        for (int i = 0; i < q; i++) {
            p[i] = ws_[i][0];
            wp[i] = ws_[i][1];
        }
        int wpp[27];
        for (int i = 0; i < q; i++) {
            wpp[p[i]] = wp[i];
        }
    }
    int dy[257], cntdy = 0;
    int yd[77];
    for (int i = 0; i < MASK(k); i++) {
        if (__builtin_popcount(i) == x) {
            yd[cntdy] = i;
            dy[i] = cntdy++;
        }
    }
    matrix zyj;
    for (int ii = 0; ii < cntdy; ii++) {
        int j = yd[ii];
        if (j & 1) {
            for (int l = 1; l <= k; l++) {
                if (!BIT(j, l)) {
                    zyj.mat[ii][dy[(j + MASK(l)) >> 1]] = c[l];
                }
            }
        } else {
            zyj.mat[ii][dy[j >> 1]] = 0;
        }
    }
    int nowpos = 1;
    for (int i = 0; i < q; i++) {
        int to = min(n - x + 1, p[i] - k - 1);
        if (to - nowpos > 0) {
            id1 = id1 * id0(zyj, to - nowpos);
        }
        matrix nm = zyj;
        for (int j = max(nowpos, to); j < min(n - x + 1, p[i]); j++) {
            for (int ii = 0; ii < cntdy; ii++) {
                int jj = yd[ii];
                if (jj & 1) {
                    for (int l = 1; l <= k; l++) {
                        if (!BIT(jj, l)) {
                            nm.mat[ii][dy[(jj + MASK(l)) >> 1]] += wpp[j + l];
                        }
                    }
                }
            }
            id1 = id1 * nm;
            nm = zyj;
        }
        nowpos = min(n - x + 1, p[i]);
    }
    if (n - x + 1 - nowpos > 0) {
        id1 = id1 * id0(zyj, n - x + 1 - nowpos);
    }
    printf("%lld\n", id1.mat[0][0]);
    printf("%lld\n", id1.mat[0][0]);
    return 0;
}
