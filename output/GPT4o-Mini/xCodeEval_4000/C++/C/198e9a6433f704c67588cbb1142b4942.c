#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 84

int n, a, b, c, d, e, g, h, l, p, f;
char s[N];

void mi(int a, int b) {
    a = (a < b) ? a : b;
}

int main() {
    scanf("%d%s", &n, s);
    int i, j, k, t;
    a = b = c = 0;
    for (i = 0; i < n; i++) {
        if (i != 0) {
            p = i - 1;
            h = i - 1;
            l = i - 1;
        }
        if (s[i] == 'V') {
            d++;
            a = i;
            h = i++;
        }
        if (s[i] == 'K') {
            e++;
            l = i++;
        }
        g++;
        c++;
    }
    memset(f, 0x3f, sizeof(f));
    for (i = 0; i <= a; i++) {
        for (j = 0; j <= b; j++) {
            for (k = 0; k <= c; k++) {
                int pos = i + j + k;
                for (t = 0; t <= 1; t++) {
                    if (i < a) {
                        mi(f[i + 1][j][k][t], f[i][j][k][t] + abs(l - d - i) + abs(p - d - i));
                    }
                    if (j < b && !t) {
                        mi(f[i][j + 1][k][t], f[i][j][k][0] + abs(h - e - j) + abs(p - e - j));
                    }
                    if (k < c) {
                        mi(f[i][j][k + 1][0], f[i][j][k][0] + abs(h - g - k) + abs(l - g - k));
                    }
                }
            }
        }
    }
    printf("%d\n", (f[a][b][c][0] < f[a][b][c][1]) ? f[a][b][c][0] : f[a][b][c][1]);
}
