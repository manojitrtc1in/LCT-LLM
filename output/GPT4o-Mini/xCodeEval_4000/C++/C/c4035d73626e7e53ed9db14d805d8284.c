#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MOD(x, m) ((x) % (m) >= 0 ? (x) % (m) : (x) % (m) + (m))
#define POPCOUNT(x) __builtin_popcount(x)

const long long mod = 1000000007;
const int inf = 1000000000;

int main() {
    long long n, p;
    scanf("%lld %lld", &n, &p);

    if (p == 0) {
        printf("%d\n", POPCOUNT(n));
        exit(0);
    }

    if (p > 0) {
        for (long long i = 1; i <= 35; i++) {
            n -= p;
            if (n < 0) {
                printf("-1\n");
                exit(0);
            }
            if (POPCOUNT(n) <= i && POPCOUNT(n) != 0) {
                if (POPCOUNT(n) == 1 && i > log(n) / log(2) + 1) {
                    printf("-1\n");
                    exit(0);
                }
                printf("%lld\n", i);
                exit(0);
            }
        }
        printf("-1\n");
        exit(0);
    }

    if (p < 0) {
        for (long long i = 1; i <= 35; i++) {
            n += -p;
            if (n < 0) {
                continue;
            }
            if (POPCOUNT(n) <= i && POPCOUNT(n) != 0) {
                if (POPCOUNT(n) == 1 && i > log(n) / log(2) + 1) {
                    printf("-1\n");
                    exit(0);
                }
                printf("%lld\n", i);
                exit(0);
            }
        }
        printf("-1\n");
        exit(0);
    }

    return 0;
}
