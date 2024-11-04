#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef long long LL;

const int N = 100, M = 10;
int F[N][M], G[N][M];
int n;

void checkMin(LL *a, LL b) {
    if (b < *a) *a = b;
}

void checkMax(LL *b, LL a) {
    if (a > *b) *b = a;
}

int main() {
    scanf("%d", &n);

    LL a = -1, b = -1;

    int tttt = sqrt(n);

    for (int i = 1; i <= tttt + 9; i++) {
        if (n % i == 0) {
            int t = n / i;
            int zt = sqrt(t);

            for (int j = 1; j <= zt + 9; j++) {
                if (t % j == 0) {
                    LL tt = t / j;

                    if (tt >= 1) {
                        LL ttt = (LL)(tt + 2) * (i + 1) * (j + 2);

                        if (a == -1) a = ttt;
                        else checkMin(&a, ttt);

                        if (b == -1) b = ttt;
                        else checkMax(&b, ttt);
                    }
                }
            }

            int zz = i;
            i = n / i;

            t = n / i;
            zt = sqrt(t);

            for (int j = 1; j <= zt + 9; j++) {
                if (t % j == 0) {
                    LL tt = t / j;

                    if (tt >= 1) {
                        LL ttt = (LL)(tt + 2) * (i + 1) * (j + 2);

                        if (a == -1) a = ttt;
                        else checkMin(&a, ttt);

                        if (b == -1) b = ttt;
                        else checkMax(&b, ttt);
                    }
                }
            }

            i = zz;
        }
    }

    printf("%lld %lld\n", a - n, b - n);

    return 0;
}
