#include <stdio.h>
#include <math.h>
#include <limits.h>

#define checkMin(a, b) if (b < a) a = b;
#define checkMax(a, b) if (b > a) a = b;

int main() {
    long long a = -1, b = -1;
    int n;

    scanf("%d", &n);

    int tttt = sqrt(n);

    for (int i = 1; i <= tttt + 8; ++i) {
        if (n % i == 0) {
            int t = n / i;
            int zt = sqrt(t);

            for (int j = 1; j <= zt + 8; ++j) {
                if (t % j == 0) {
                    long long tt = t / j;
                    if (tt >= 1) {
                        long long ttt = (tt + 2) * (i + 1) * (j + 2);
                        if (a == -1) a = ttt;
                        else checkMin(a, ttt);
                        if (b == -1) b = ttt;
                        else checkMax(b, ttt);
                    }
                }
            }

            int zz = i;
            i = n / i;

            t = n / i;
            zt = sqrt(t);

            for (int j = 1; j <= zt + 8; ++j) {
                if (t % j == 0) {
                    long long tt = t / j;
                    if (tt >= 1) {
                        long long ttt = (tt + 2) * (i + 1) * (j + 2);
                        if (a == -1) a = ttt;
                        else checkMin(a, ttt);
                        if (b == -1) b = ttt;
                        else checkMax(b, ttt);
                    }
                }
            }

            i = zz;
        }
    }

    printf("%lld %lld\n", a - n, b - n);
    return 0;
}
