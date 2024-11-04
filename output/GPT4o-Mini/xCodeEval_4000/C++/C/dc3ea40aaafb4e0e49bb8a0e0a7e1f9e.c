#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define LL long long
#define MASK(a) (1<<(a))
#define BIT(a,b) (((a)>>(b))&1)
#define Inf ((int)0x3f3f3f3f)
#define INF ((long long)0x3f3f3f3f3f3f3f3f)

typedef struct {
    LL mat[77][77];
} matrix;

matrix ksmii(matrix x, int y) {
    if (y == 1) return x;
    matrix mat2 = ksmii(x, y / 2);
    for (int i = 0; i < 77; i++)
        for (int j = 0; j < 77; j++)
            mat2.mat[i][j] = INF;
    for (int i = 0; i < 77; i++)
        for (int j = 0; j < 77; j++)
            for (int k = 0; k < 77; k++)
                mat2.mat[i][k] = (mat2.mat[i][k] < mat2.mat[i][j] + x.mat[j][k]) ? mat2.mat[i][k] : (mat2.mat[i][j] + x.mat[j][k]);
    return mat2;
}

matrix multiply(matrix a, matrix b) {
    matrix result;
    for (int i = 0; i < 77; i++)
        for (int j = 0; j < 77; j++)
            result.mat[i][j] = INF;
    for (int i = 0; i < 77; i++)
        for (int j = 0; j < 77; j++)
            for (int k = 0; k < 77; k++)
                result.mat[i][k] = (result.mat[i][k] < a.mat[i][j] + b.mat[j][k]) ? result.mat[i][k] : (a.mat[i][j] + b.mat[j][k]);
    return result;
}

int main() {
    matrix zyj, zyj2;
    for (int i = 0; i < 77; i++)
        for (int j = 0; j < 77; j++)
            zyj.mat[i][j] = INF;
    zyj2.mat[0][0] = 0;

    int x, k, n, q;
    scanf("%d%d%d%d", &x, &k, &n, &q);

    int c[15];
    for (int i = 1; i <= k; i++)
        scanf("%d", &c[i]);

    int ws_[27][2];
    for (int i = 0; i < q; i++)
        scanf("%d%d", &ws_[i][0], &ws_[i][1]);

    // Sort ws_
    for (int i = 0; i < q - 1; i++)
        for (int j = 0; j < q - i - 1; j++)
            if (ws_[j][0] > ws_[j + 1][0]) {
                int temp0 = ws_[j][0], temp1 = ws_[j][1];
                ws_[j][0] = ws_[j + 1][0];
                ws_[j][1] = ws_[j + 1][1];
                ws_[j + 1][0] = temp0;
                ws_[j + 1][1] = temp1;
            }

    int p[27], wp[27];
    int wpp[1000] = {0}; // Assuming a reasonable size for the map
    for (int i = 0; i < q; i++) {
        p[i] = ws_[i][0];
        wp[i] = ws_[i][1];
        wpp[p[i]] = wp[i];
    }

    int yd[257], cntdy = 0;
    for (int i = 0; i < (1 << k); i++)
        if (__builtin_popcount(i) == x) {
            yd[cntdy] = i;
            cntdy++;
        }

    for (int ii = 0; ii < cntdy; ii++) {
        int j = yd[ii];
        if (j & 1) {
            for (int l = 1; l <= k; l++)
                if (!BIT(j, l))
                    zyj.mat[ii][j >> 1] = c[l];
        } else {
            zyj.mat[ii][j >> 1] = 0;
        }
    }

    int nowpos = 1;
    for (int i = 0; i < q; i++) {
        int to = (n - x + 1 < p[i] - k - 1) ? n - x + 1 : p[i] - k - 1;
        if (to - nowpos > 0) zyj2 = multiply(zyj2, ksmii(zyj, to - nowpos));

        matrix nm = zyj;
        for (int j = (nowpos < to) ? to : nowpos; j < (n - x + 1 < p[i]) ? n - x + 1 : p[i]; j++) {
            for (int ii = 0; ii < cntdy; ii++) {
                int jj = yd[ii];
                if (jj & 1) {
                    for (int l = 1; l <= k; l++)
                        if (!BIT(jj, l))
                            nm.mat[ii][(jj + MASK(l)) >> 1] += wpp[j + l];
                }
            }
            zyj2 = multiply(zyj2, nm);
            nm = zyj;
        }
        nowpos = (n - x + 1 < p[i]) ? n - x + 1 : p[i];
    }

    if (n - x + 1 - nowpos > 0) zyj2 = multiply(zyj2, ksmii(zyj, n - x + 1 - nowpos));

    printf("%lld\n", zyj2.mat[0][0]);
    return 0;
}
