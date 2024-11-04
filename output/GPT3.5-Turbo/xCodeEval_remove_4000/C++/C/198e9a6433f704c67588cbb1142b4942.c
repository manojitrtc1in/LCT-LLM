#include <stdio.h>
#include <string.h>

int n, a, b, c, d, e, g, h, l, p, f[2];
char s[100];

void mi(int *a, int b) {
    *a = (*a < b) ? *a : b;
}

int main() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            p = p - 1;
            h = h - 1;
            l = l - 1;
        }
        if (s[i] == 'V') {
            d = a++;
            h = i;
        } else if (s[i] == 'K') {
            e = b++;
            l = i;
        } else {
            g = c++;
            p = i;
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                for (int t = 0; t <= 1; t++) {
                    if (i < a) {
                        mi(&f[i+1][j][k][1], f[i][j][k][t] + abs(l[d][i] - j) + abs(p[d][i] - k));
                    }
                    if (j < b && !t) {
                        mi(&f[i][j+1][k][0], f[i][j][k][t] + abs(h[e][j] - i) + abs(p[e][j] - k));
                    }
                    if (k < c) {
                        mi(&f[i][j][k+1][0], f[i][j][k][t] + abs(h[g][k] - i) + abs(l[g][k] - j));
                    }
                }
            }
        }
    }
    printf("%d\n", min(f[a][b][c][0], f[a][b][c][1]) / 2);
    return 0;
}
